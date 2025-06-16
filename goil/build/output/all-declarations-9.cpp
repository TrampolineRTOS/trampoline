#include "Compiler.h"
#include "C_galgas_io.h"
#include "C_galgas_CLI_Options.h"
#include "PrologueEpilogue.h"

//--------------------------------------------------------------------------------------------------

#include "all-declarations-9.h"

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString andOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2109)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString orOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2113)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString xorOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2117)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString slOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2121)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString srOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2125)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString neqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2133)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2132)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2130)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString eqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2145)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2144)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2142)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString gtOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2157)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2156)), GALGAS_bool (kIsStrictSup, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2154)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString geOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2169)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2168)), GALGAS_bool (kIsSupOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2166)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString ltOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2181)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2180)), GALGAS_bool (kIsStrictInf, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2178)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString leOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2193)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2192)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2190)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString embeddedType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlString::getter_embeddedType (Compiler */* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_string) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlString addMyValue'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlString::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                        Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 2207))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2207)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString performGetter'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                     const GALGAS_gtlDataList constinArgument_arguments,
                                                     const GALGAS_gtlContext constinArgument_context,
                                                     const GALGAS_library constinArgument_lib,
                                                     Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("string"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2221)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2221)) ;
      }
      result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2223)), this->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2222)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("charAtIndex"))).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2226)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2226)) ;
        }
        GALGAS_gtlInt temp_2 ;
        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)).isValid ()) {
          if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)).ptr ())) {
            temp_2 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)).ptr () ;
          }else{
            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)) ;
          }
        }
        GALGAS_uint var_index_68489 = temp_2.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)) ;
        result_result = GALGAS_gtlChar::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2229)), this->mProperty_value.getter_characterAtIndex (var_index_68489, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2229))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2228)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("indexOfChar"))).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_charArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2232)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2232)) ;
          }
          GALGAS_gtlChar temp_4 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2233)).isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2233)).ptr ())) {
              temp_4 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2233)).ptr () ;
            }else{
              inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2233)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2233)) ;
            }
          }
          GALGAS_char var_lookedUpChar_68785 = temp_4.readProperty_value () ;
          GALGAS_uint var_index_68857 = GALGAS_uint (uint32_t (0U)) ;
          GALGAS_uint var_length_68881 = this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2235)) ;
          GALGAS_bool var_found_68915 = GALGAS_bool (false) ;
          if (var_length_68881.isValid ()) {
            uint32_t variant_68933 = var_length_68881.uintValue () ;
            bool loop_68933 = true ;
            while (loop_68933) {
              GALGAS_bool test_5 = var_found_68915.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2238)) ;
              if (kBoolTrue == test_5.boolEnum ()) {
                test_5 = GALGAS_bool (kIsStrictInf, var_index_68857.objectCompare (var_length_68881)) ;
              }
              loop_68933 = test_5.isValid () ;
              if (loop_68933) {
                loop_68933 = test_5.boolValue () ;
              }
              if (loop_68933 && (0 == variant_68933)) {
                loop_68933 = false ;
                inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_data_types.galgas", 2237)) ;
              }
              if (loop_68933) {
                variant_68933 -- ;
                enumGalgasBool test_6 = kBoolTrue ;
                if (kBoolTrue == test_6) {
                  test_6 = GALGAS_bool (kIsEqual, this->mProperty_value.getter_characterAtIndex (var_index_68857, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2239)).objectCompare (var_lookedUpChar_68785)).boolEnum () ;
                  if (kBoolTrue == test_6) {
                    var_found_68915 = GALGAS_bool (true) ;
                  }
                }
                if (kBoolFalse == test_6) {
                  var_index_68857.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2242)) ;
                }
              }
            }
          }
          GALGAS_bigint temp_7 ;
          const enumGalgasBool test_8 = var_found_68915.boolEnum () ;
          if (kBoolTrue == test_8) {
            temp_7 = var_index_68857.getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2248)) ;
          }else if (kBoolFalse == test_8) {
            temp_7 = GALGAS_bigint ("-1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2248)) ;
          }
          result_result = GALGAS_gtlInt::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2247)), temp_7  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2245)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_9 = kBoolTrue ;
        if (kBoolTrue == test_9) {
          test_9 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("indexOfCharInRange"))).boolEnum () ;
          if (kBoolTrue == test_9) {
            {
            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_charCharArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2251)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2251)) ;
            }
            GALGAS_gtlChar temp_10 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2252)).isValid ()) {
              if (nullptr != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2252)).ptr ())) {
                temp_10 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2252)).ptr () ;
              }else{
                inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2252)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2252)) ;
              }
            }
            GALGAS_char var_minChar_69385 = temp_10.readProperty_value () ;
            GALGAS_gtlChar temp_11 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2253)).isValid ()) {
              if (nullptr != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2253)).ptr ())) {
                temp_11 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2253)).ptr () ;
              }else{
                inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2253)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2253)) ;
              }
            }
            GALGAS_char var_maxChar_69456 = temp_11.readProperty_value () ;
            GALGAS_uint var_index_69523 = GALGAS_uint (uint32_t (0U)) ;
            GALGAS_uint var_length_69547 = this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2255)) ;
            GALGAS_bool var_found_69581 = GALGAS_bool (false) ;
            if (var_length_69547.isValid ()) {
              uint32_t variant_69599 = var_length_69547.uintValue () ;
              bool loop_69599 = true ;
              while (loop_69599) {
                GALGAS_bool test_12 = var_found_69581.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2258)) ;
                if (kBoolTrue == test_12.boolEnum ()) {
                  test_12 = GALGAS_bool (kIsStrictInf, var_index_69523.objectCompare (var_length_69547)) ;
                }
                loop_69599 = test_12.isValid () ;
                if (loop_69599) {
                  loop_69599 = test_12.boolValue () ;
                }
                if (loop_69599 && (0 == variant_69599)) {
                  loop_69599 = false ;
                  inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_data_types.galgas", 2257)) ;
                }
                if (loop_69599) {
                  variant_69599 -- ;
                  GALGAS_char var_currentChar_69670 = this->mProperty_value.getter_characterAtIndex (var_index_69523, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2259)) ;
                  enumGalgasBool test_13 = kBoolTrue ;
                  if (kBoolTrue == test_13) {
                    GALGAS_bool test_14 = GALGAS_bool (kIsSupOrEqual, var_currentChar_69670.objectCompare (var_minChar_69385)) ;
                    if (kBoolTrue == test_14.boolEnum ()) {
                      test_14 = GALGAS_bool (kIsInfOrEqual, var_currentChar_69670.objectCompare (var_maxChar_69456)) ;
                    }
                    test_13 = test_14.boolEnum () ;
                    if (kBoolTrue == test_13) {
                      var_found_69581 = GALGAS_bool (true) ;
                    }
                  }
                  if (kBoolFalse == test_13) {
                    var_index_69523.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2263)) ;
                  }
                }
              }
            }
            GALGAS_bigint temp_15 ;
            const enumGalgasBool test_16 = var_found_69581.boolEnum () ;
            if (kBoolTrue == test_16) {
              temp_15 = var_index_69523.getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2269)) ;
            }else if (kBoolFalse == test_16) {
              temp_15 = GALGAS_bigint ("-1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2269)) ;
            }
            result_result = GALGAS_gtlInt::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2268)), temp_15  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2266)) ;
          }
        }
        if (kBoolFalse == test_9) {
          enumGalgasBool test_17 = kBoolTrue ;
          if (kBoolTrue == test_17) {
            test_17 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("containsChar"))).boolEnum () ;
            if (kBoolTrue == test_17) {
              {
              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_charArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2272)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2272)) ;
              }
              GALGAS_gtlChar temp_18 ;
              if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2273)).isValid ()) {
                if (nullptr != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2273)).ptr ())) {
                  temp_18 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2273)).ptr () ;
                }else{
                  inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2273)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2273)) ;
                }
              }
              GALGAS_char var_lookedUpChar_70101 = temp_18.readProperty_value () ;
              result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2276)), this->mProperty_value.getter_containsCharacter (var_lookedUpChar_70101 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2277))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2274)) ;
            }
          }
          if (kBoolFalse == test_17) {
            enumGalgasBool test_19 = kBoolTrue ;
            if (kBoolTrue == test_19) {
              test_19 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("containsCharInRange"))).boolEnum () ;
              if (kBoolTrue == test_19) {
                {
                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_charCharArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2280)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2280)) ;
                }
                GALGAS_gtlChar temp_20 ;
                if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2281)).isValid ()) {
                  if (nullptr != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2281)).ptr ())) {
                    temp_20 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2281)).ptr () ;
                  }else{
                    inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2281)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2281)) ;
                  }
                }
                GALGAS_char var_minChar_70433 = temp_20.readProperty_value () ;
                GALGAS_gtlChar temp_21 ;
                if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2282)).isValid ()) {
                  if (nullptr != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2282)).ptr ())) {
                    temp_21 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2282)).ptr () ;
                  }else{
                    inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2282)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2282)) ;
                  }
                }
                GALGAS_char var_maxChar_70504 = temp_21.readProperty_value () ;
                result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2285)), this->mProperty_value.getter_containsCharacterInRange (var_minChar_70433, var_maxChar_70504 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2286))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2283)) ;
              }
            }
            if (kBoolFalse == test_19) {
              enumGalgasBool test_22 = kBoolTrue ;
              if (kBoolTrue == test_22) {
                test_22 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("HTMLRepresentation"))).boolEnum () ;
                if (kBoolTrue == test_22) {
                  {
                  routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2289)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2289)) ;
                  }
                  result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2291)), this->mProperty_value.getter_HTMLRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 2291))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2290)) ;
                }
              }
              if (kBoolFalse == test_22) {
                enumGalgasBool test_23 = kBoolTrue ;
                if (kBoolTrue == test_23) {
                  test_23 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("identifierRepresentation"))).boolEnum () ;
                  if (kBoolTrue == test_23) {
                    {
                    routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2294)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2294)) ;
                    }
                    result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2296)), this->mProperty_value.getter_identifierRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 2296))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2295)) ;
                  }
                }
                if (kBoolFalse == test_23) {
                  enumGalgasBool test_24 = kBoolTrue ;
                  if (kBoolTrue == test_24) {
                    test_24 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("fileExists"))).boolEnum () ;
                    if (kBoolTrue == test_24) {
                      {
                      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2299)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2299)) ;
                      }
                      result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2301)), this->mProperty_value.getter_fileExists (SOURCE_FILE ("gtl_data_types.galgas", 2301))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2300)) ;
                    }
                  }
                  if (kBoolFalse == test_24) {
                    enumGalgasBool test_25 = kBoolTrue ;
                    if (kBoolTrue == test_25) {
                      test_25 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("lowercaseString"))).boolEnum () ;
                      if (kBoolTrue == test_25) {
                        {
                        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2304)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2304)) ;
                        }
                        result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2306)), this->mProperty_value.getter_lowercaseString (SOURCE_FILE ("gtl_data_types.galgas", 2306))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2305)) ;
                      }
                    }
                    if (kBoolFalse == test_25) {
                      enumGalgasBool test_26 = kBoolTrue ;
                      if (kBoolTrue == test_26) {
                        test_26 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("length"))).boolEnum () ;
                        if (kBoolTrue == test_26) {
                          {
                          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2309)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2309)) ;
                          }
                          result_result = GALGAS_gtlInt::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2311)), this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2311)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2311))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2310)) ;
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
                            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2315)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2315)) ;
                            }
                            result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2317)), this->mProperty_value.getter_stringByCapitalizingFirstCharacter (SOURCE_FILE ("gtl_data_types.galgas", 2317))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2316)) ;
                          }
                        }
                        if (kBoolFalse == test_27) {
                          enumGalgasBool test_29 = kBoolTrue ;
                          if (kBoolTrue == test_29) {
                            test_29 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("uppercaseString"))).boolEnum () ;
                            if (kBoolTrue == test_29) {
                              {
                              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2320)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2320)) ;
                              }
                              result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2322)), this->mProperty_value.getter_uppercaseString (SOURCE_FILE ("gtl_data_types.galgas", 2322))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2321)) ;
                            }
                          }
                          if (kBoolFalse == test_29) {
                            enumGalgasBool test_30 = kBoolTrue ;
                            if (kBoolTrue == test_30) {
                              test_30 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("unsigned"))).boolEnum () ;
                              if (kBoolTrue == test_30) {
                                {
                                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2325)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2325)) ;
                                }
                                result_result = GALGAS_gtlInt::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2327)), this->mProperty_value.getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2327)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2327))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2326)) ;
                              }
                            }
                            if (kBoolFalse == test_30) {
                              enumGalgasBool test_31 = kBoolTrue ;
                              if (kBoolTrue == test_31) {
                                test_31 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("subStringExists"))).boolEnum () ;
                                if (kBoolTrue == test_31) {
                                  {
                                  routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2330)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2330)) ;
                                  }
                                  GALGAS_gtlString temp_32 ;
                                  if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2331)).isValid ()) {
                                    if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2331)).ptr ())) {
                                      temp_32 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2331)).ptr () ;
                                    }else{
                                      inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2331)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2331)) ;
                                    }
                                  }
                                  GALGAS_string var_subString_72655 = temp_32.readProperty_value () ;
                                  GALGAS_uint var_subStringLength_72730 = var_subString_72655.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2332)) ;
                                  GALGAS_uint var_start_72777 = GALGAS_uint (uint32_t (0U)) ;
                                  GALGAS_uint var_stop_72801 = this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2334)).substract_operation (var_subStringLength_72730, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2334)) ;
                                  GALGAS_bool var_exists_72851 = GALGAS_bool (false) ;
                                  if (this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2336)).isValid ()) {
                                    uint32_t variant_72871 = this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2336)).uintValue () ;
                                    bool loop_72871 = true ;
                                    while (loop_72871) {
                                      GALGAS_bool test_33 = var_exists_72851.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2337)) ;
                                      if (kBoolTrue == test_33.boolEnum ()) {
                                        test_33 = GALGAS_bool (kIsInfOrEqual, var_start_72777.objectCompare (var_stop_72801)) ;
                                      }
                                      loop_72871 = test_33.isValid () ;
                                      if (loop_72871) {
                                        loop_72871 = test_33.boolValue () ;
                                      }
                                      if (loop_72871 && (0 == variant_72871)) {
                                        loop_72871 = false ;
                                        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_data_types.galgas", 2336)) ;
                                      }
                                      if (loop_72871) {
                                        variant_72871 -- ;
                                        enumGalgasBool test_34 = kBoolTrue ;
                                        if (kBoolTrue == test_34) {
                                          test_34 = GALGAS_bool (kIsEqual, this->mProperty_value.getter_subString (var_start_72777, var_subStringLength_72730 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2338)).objectCompare (var_subString_72655)).boolEnum () ;
                                          if (kBoolTrue == test_34) {
                                            var_exists_72851 = GALGAS_bool (true) ;
                                          }
                                        }
                                        var_start_72777.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2341)) ;
                                      }
                                    }
                                  }
                                  result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2344)), var_exists_72851  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2343)) ;
                                }
                              }
                              if (kBoolFalse == test_31) {
                                enumGalgasBool test_35 = kBoolTrue ;
                                if (kBoolTrue == test_35) {
                                  test_35 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("leftSubString"))).boolEnum () ;
                                  if (kBoolTrue == test_35) {
                                    {
                                    routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2347)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2347)) ;
                                    }
                                    GALGAS_gtlInt temp_36 ;
                                    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)).isValid ()) {
                                      if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)).ptr ())) {
                                        temp_36 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)).ptr () ;
                                      }else{
                                        inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)) ;
                                      }
                                    }
                                    GALGAS_uint var_index_73282 = temp_36.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)) ;
                                    result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2350)), this->mProperty_value.getter_leftSubString (var_index_73282 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2350))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2349)) ;
                                  }
                                }
                                if (kBoolFalse == test_35) {
                                  enumGalgasBool test_37 = kBoolTrue ;
                                  if (kBoolTrue == test_37) {
                                    test_37 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("rightSubString"))).boolEnum () ;
                                    if (kBoolTrue == test_37) {
                                      {
                                      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2353)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2353)) ;
                                      }
                                      GALGAS_gtlInt temp_38 ;
                                      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)).isValid ()) {
                                        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)).ptr ())) {
                                          temp_38 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)).ptr () ;
                                        }else{
                                          inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)) ;
                                        }
                                      }
                                      GALGAS_uint var_index_73579 = temp_38.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)) ;
                                      result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2356)), this->mProperty_value.getter_rightSubString (var_index_73579 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2356))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2355)) ;
                                    }
                                  }
                                  if (kBoolFalse == test_37) {
                                    enumGalgasBool test_39 = kBoolTrue ;
                                    if (kBoolTrue == test_39) {
                                      test_39 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("subString"))).boolEnum () ;
                                      if (kBoolTrue == test_39) {
                                        {
                                        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_intIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2359)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2359)) ;
                                        }
                                        GALGAS_gtlInt temp_40 ;
                                        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)).isValid ()) {
                                          if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)).ptr ())) {
                                            temp_40 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)).ptr () ;
                                          }else{
                                            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)) ;
                                          }
                                        }
                                        GALGAS_uint var_start_73876 = temp_40.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)) ;
                                        GALGAS_gtlInt temp_41 ;
                                        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)).isValid ()) {
                                          if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)).ptr ())) {
                                            temp_41 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)).ptr () ;
                                          }else{
                                            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)) ;
                                          }
                                        }
                                        GALGAS_uint var_length_73951 = temp_41.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)) ;
                                        result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2363)), this->mProperty_value.getter_subString (var_start_73876, var_length_73951 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2363))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2362)) ;
                                      }
                                    }
                                    if (kBoolFalse == test_39) {
                                      enumGalgasBool test_42 = kBoolTrue ;
                                      if (kBoolTrue == test_42) {
                                        test_42 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("reversedString"))).boolEnum () ;
                                        if (kBoolTrue == test_42) {
                                          {
                                          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2366)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2366)) ;
                                          }
                                          result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2368)), this->mProperty_value.getter_reversedString (SOURCE_FILE ("gtl_data_types.galgas", 2368))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2367)) ;
                                        }
                                      }
                                      if (kBoolFalse == test_42) {
                                        enumGalgasBool test_43 = kBoolTrue ;
                                        if (kBoolTrue == test_43) {
                                          test_43 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("componentsSeparatedByString"))).boolEnum () ;
                                          if (kBoolTrue == test_43) {
                                            {
                                            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2371)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2371)) ;
                                            }
                                            GALGAS_gtlString temp_44 ;
                                            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2372)).isValid ()) {
                                              if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2372)).ptr ())) {
                                                temp_44 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2372)).ptr () ;
                                              }else{
                                                inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2372)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2372)) ;
                                              }
                                            }
                                            GALGAS_string var_separator_74486 = temp_44.readProperty_value () ;
                                            GALGAS_stringlist var_stringlist_74567 = this->mProperty_value.getter_componentsSeparatedByString (var_separator_74486 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2373)) ;
                                            GALGAS_list var_components_74637 = GALGAS_list::class_func_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 2374)) ;
                                            cEnumerator_stringlist enumerator_74670 (var_stringlist_74567, kENUMERATION_UP) ;
                                            while (enumerator_74670.hasCurrentObject ()) {
                                              var_components_74637.addAssign_operation (GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2377)), enumerator_74670.current_mValue (HERE)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2376))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2376)) ;
                                              enumerator_74670.gotoNextObject () ;
                                            }
                                            result_result = GALGAS_gtlList::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2381)), var_components_74637  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2380)) ;
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
                                                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2387)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2387)) ;
                                                }
                                                GALGAS_gtlString temp_49 ;
                                                if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2388)).isValid ()) {
                                                  if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2388)).ptr ())) {
                                                    temp_49 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2388)).ptr () ;
                                                  }else{
                                                    inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2388)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2388)) ;
                                                  }
                                                }
                                                GALGAS_string var_prefix_75138 = temp_49.readProperty_value () ;
                                                result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2391)), var_prefix_75138.add_operation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2392)).getter_stringByReplacingStringByString (GALGAS_string ("\n"), GALGAS_string ("\n").add_operation (var_prefix_75138, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2392)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2392))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2389)) ;
                                              }
                                            }
                                            if (kBoolFalse == test_48) {
                                              enumGalgasBool test_50 = kBoolTrue ;
                                              if (kBoolTrue == test_50) {
                                                test_50 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("wrap"))).boolEnum () ;
                                                if (kBoolTrue == test_50) {
                                                  {
                                                  routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_intIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2395)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2395)) ;
                                                  }
                                                  GALGAS_gtlInt temp_51 ;
                                                  if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)).isValid ()) {
                                                    if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)).ptr ())) {
                                                      temp_51 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)).ptr () ;
                                                    }else{
                                                      inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)) ;
                                                    }
                                                  }
                                                  GALGAS_uint var_width_75480 = temp_51.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)) ;
                                                  GALGAS_gtlInt temp_52 ;
                                                  if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)).isValid ()) {
                                                    if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)).ptr ())) {
                                                      temp_52 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)).ptr () ;
                                                    }else{
                                                      inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)) ;
                                                    }
                                                  }
                                                  GALGAS_uint var_shift_75555 = temp_52.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)) ;
                                                  GALGAS_string var_stringShift_75632 = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), var_shift_75555  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2398)) ;
                                                  GALGAS_stringlist var_paragraphs_75714 = this->mProperty_value.getter_componentsSeparatedByString (GALGAS_string ("\n") COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2399)) ;
                                                  GALGAS_stringlist var_resultParagraphs_75789 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 2400)) ;
                                                  cEnumerator_stringlist enumerator_75830 (var_paragraphs_75714, kENUMERATION_UP) ;
                                                  while (enumerator_75830.hasCurrentObject ()) {
                                                    GALGAS_stringlist var_words_75880 = enumerator_75830.current_mValue (HERE).getter_componentsSeparatedByString (GALGAS_string (" ") COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2402)) ;
                                                    GALGAS_uint var_lineWidth_75945 = GALGAS_uint (uint32_t (0U)) ;
                                                    GALGAS_string var_line_75973 = GALGAS_string::makeEmptyString () ;
                                                    cEnumerator_stringlist enumerator_75994 (var_words_75880, kENUMERATION_UP) ;
                                                    while (enumerator_75994.hasCurrentObject ()) {
                                                      enumGalgasBool test_53 = kBoolTrue ;
                                                      if (kBoolTrue == test_53) {
                                                        test_53 = GALGAS_bool (kIsNotEqual, enumerator_75994.current_mValue (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
                                                        if (kBoolTrue == test_53) {
                                                          enumGalgasBool test_54 = kBoolTrue ;
                                                          if (kBoolTrue == test_54) {
                                                            test_54 = GALGAS_bool (kIsStrictSup, var_lineWidth_75945.add_operation (enumerator_75994.current_mValue (HERE).getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2407)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2407)).objectCompare (var_width_75480)).boolEnum () ;
                                                            if (kBoolTrue == test_54) {
                                                              var_line_75973.plusAssign_operation(GALGAS_string ("\n").add_operation (var_stringShift_75632, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2408)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2408)) ;
                                                              var_lineWidth_75945 = var_shift_75555 ;
                                                            }
                                                          }
                                                          var_lineWidth_75945.plusAssign_operation(enumerator_75994.current_mValue (HERE).getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2411)).add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2411)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2411)) ;
                                                          var_line_75973.plusAssign_operation(enumerator_75994.current_mValue (HERE).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2412)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2412)) ;
                                                        }
                                                      }
                                                      enumerator_75994.gotoNextObject () ;
                                                    }
                                                    var_resultParagraphs_75789.addAssign_operation (var_line_75973  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2415)) ;
                                                    enumerator_75830.gotoNextObject () ;
                                                  }
                                                  result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2419)), GALGAS_string::class_func_componentsJoinedByString (var_resultParagraphs_75789, GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2420))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2417)) ;
                                                }
                                              }
                                              if (kBoolFalse == test_50) {
                                                enumGalgasBool test_55 = kBoolTrue ;
                                                if (kBoolTrue == test_55) {
                                                  test_55 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("replaceString"))).boolEnum () ;
                                                  if (kBoolTrue == test_55) {
                                                    {
                                                    routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringStringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2423)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2423)) ;
                                                    }
                                                    GALGAS_gtlString temp_56 ;
                                                    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2424)).isValid ()) {
                                                      if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2424)).ptr ())) {
                                                        temp_56 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2424)).ptr () ;
                                                      }else{
                                                        inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2424)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2424)) ;
                                                      }
                                                    }
                                                    GALGAS_string var_find_76605 = temp_56.readProperty_value () ;
                                                    GALGAS_gtlString temp_57 ;
                                                    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2425)).isValid ()) {
                                                      if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2425)).ptr ())) {
                                                        temp_57 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2425)).ptr () ;
                                                      }else{
                                                        inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2425)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2425)) ;
                                                      }
                                                    }
                                                    GALGAS_string var_rep_76677 = temp_57.readProperty_value () ;
                                                    result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2428)), this->mProperty_value.getter_stringByReplacingStringByString (var_find_76605, var_rep_76677, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2429))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2426)) ;
                                                  }
                                                }
                                                if (kBoolFalse == test_55) {
                                                  enumGalgasBool test_58 = kBoolTrue ;
                                                  if (kBoolTrue == test_58) {
                                                    test_58 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("subStringExists"))).boolEnum () ;
                                                    if (kBoolTrue == test_58) {
                                                      {
                                                      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2432)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2432)) ;
                                                      }
                                                      GALGAS_gtlString temp_59 ;
                                                      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)).isValid ()) {
                                                        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)).ptr ())) {
                                                          temp_59 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)).ptr () ;
                                                        }else{
                                                          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)) ;
                                                        }
                                                      }
                                                      GALGAS_string var_subString_77010 = callExtensionGetter_string ((const cPtr_gtlString *) temp_59.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)) ;
                                                      GALGAS_uint var_subLength_77086 = var_subString_77010.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2434)) ;
                                                      GALGAS_uint var_start_77127 = GALGAS_uint (uint32_t (0U)) ;
                                                      GALGAS_uint var_stop_77151 = this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2436)).substract_operation (var_subLength_77086, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2436)) ;
                                                      GALGAS_bool var_exists_77195 = GALGAS_bool (false) ;
                                                      if (this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2438)).isValid ()) {
                                                        uint32_t variant_77214 = this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2438)).uintValue () ;
                                                        bool loop_77214 = true ;
                                                        while (loop_77214) {
                                                          loop_77214 = GALGAS_bool (kIsInfOrEqual, var_start_77127.objectCompare (var_stop_77151)).operator_and (var_exists_77195.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2439)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2439)).isValid () ;
                                                          if (loop_77214) {
                                                            loop_77214 = GALGAS_bool (kIsInfOrEqual, var_start_77127.objectCompare (var_stop_77151)).operator_and (var_exists_77195.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2439)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2439)).boolValue () ;
                                                          }
                                                          if (loop_77214 && (0 == variant_77214)) {
                                                            loop_77214 = false ;
                                                            inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_data_types.galgas", 2438)) ;
                                                          }
                                                          if (loop_77214) {
                                                            variant_77214 -- ;
                                                            enumGalgasBool test_60 = kBoolTrue ;
                                                            if (kBoolTrue == test_60) {
                                                              test_60 = GALGAS_bool (kIsEqual, this->mProperty_value.getter_subString (var_start_77127, var_subLength_77086 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2440)).objectCompare (var_subString_77010)).boolEnum () ;
                                                              if (kBoolTrue == test_60) {
                                                                var_exists_77195 = GALGAS_bool (true) ;
                                                              }
                                                            }
                                                            var_start_77127.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2443)) ;
                                                          }
                                                        }
                                                      }
                                                      result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2447)), var_exists_77195  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2445)) ;
                                                    }
                                                  }
                                                  if (kBoolFalse == test_58) {
                                                    enumGalgasBool test_61 = kBoolTrue ;
                                                    if (kBoolTrue == test_61) {
                                                      test_61 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("envVarExists"))).boolEnum () ;
                                                      if (kBoolTrue == test_61) {
                                                        {
                                                        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2451)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2451)) ;
                                                        }
                                                        result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2454)), this->mProperty_value.getter_doesEnvironmentVariableExist (SOURCE_FILE ("gtl_data_types.galgas", 2455))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2452)) ;
                                                      }
                                                    }
                                                    if (kBoolFalse == test_61) {
                                                      enumGalgasBool test_62 = kBoolTrue ;
                                                      if (kBoolTrue == test_62) {
                                                        test_62 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("envVar"))).boolEnum () ;
                                                        if (kBoolTrue == test_62) {
                                                          {
                                                          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2458)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2458)) ;
                                                          }
                                                          result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2461)), GALGAS_string::class_func_stringWithEnvironmentVariableOrEmpty (this->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2462))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2459)) ;
                                                        }
                                                      }
                                                      if (kBoolFalse == test_62) {
                                                        enumGalgasBool test_63 = kBoolTrue ;
                                                        if (kBoolTrue == test_63) {
                                                          test_63 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                          if (kBoolTrue == test_63) {
                                                            {
                                                            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2465)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2465)) ;
                                                            }
                                                            const GALGAS_gtlString temp_64 = this ;
                                                            result_result = GALGAS_gtlType::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2467)), temp_64.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 2467))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2466)) ;
                                                          }
                                                        }
                                                        if (kBoolFalse == test_63) {
                                                          enumGalgasBool test_65 = kBoolTrue ;
                                                          if (kBoolTrue == test_65) {
                                                            test_65 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                            if (kBoolTrue == test_65) {
                                                              {
                                                              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2470)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2470)) ;
                                                              }
                                                              result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2472)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2471)) ;
                                                            }
                                                          }
                                                          if (kBoolFalse == test_65) {
                                                            enumGalgasBool test_66 = kBoolTrue ;
                                                            if (kBoolTrue == test_66) {
                                                              test_66 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                              if (kBoolTrue == test_66) {
                                                                {
                                                                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2475)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2475)) ;
                                                                }
                                                                result_result = GALGAS_gtlString::class_func_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2477)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2476)) ;
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
                                                                    routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2488)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2488)) ;
                                                                    }
                                                                    result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2490)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2490))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2489)) ;
                                                                  }
                                                                }
                                                                if (kBoolFalse == test_69) {
                                                                  enumGalgasBool test_70 = kBoolTrue ;
                                                                  if (kBoolTrue == test_70) {
                                                                    test_70 = GALGAS_bool (kIsEqual, GALGAS_string ("files").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                                    if (kBoolTrue == test_70) {
                                                                      {
                                                                      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2493)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2493)) ;
                                                                      }
                                                                      GALGAS_stringlist var_fileList_79061 = this->mProperty_value.getter_regularFiles (GALGAS_bool (false) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2494)) ;
                                                                      GALGAS_lstringset var_files_79116 = GALGAS_lstringset::class_func_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 2495)) ;
                                                                      cEnumerator_stringlist enumerator_79143 (var_fileList_79061, kENUMERATION_UP) ;
                                                                      while (enumerator_79143.hasCurrentObject ()) {
                                                                        {
                                                                        var_files_79116.setter_put (GALGAS_lstring::class_func_new (enumerator_79143.current_mValue (HERE), constinArgument_methodName.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2497)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2497)) ;
                                                                        }
                                                                        enumerator_79143.gotoNextObject () ;
                                                                      }
                                                                      result_result = GALGAS_gtlSet::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2500)), var_files_79116  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2499)) ;
                                                                    }
                                                                  }
                                                                  if (kBoolFalse == test_70) {
                                                                    enumGalgasBool test_71 = kBoolTrue ;
                                                                    if (kBoolTrue == test_71) {
                                                                      test_71 = GALGAS_bool (kIsEqual, GALGAS_string ("filesWithExtensions").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                                      if (kBoolTrue == test_71) {
                                                                        {
                                                                        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_setArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2503)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2503)) ;
                                                                        }
                                                                        GALGAS_stringlist var_extensions_79448 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 2504)) ;
                                                                        GALGAS_gtlSet temp_72 ;
                                                                        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)).isValid ()) {
                                                                          if (nullptr != dynamic_cast <const cPtr_gtlSet *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)).ptr ())) {
                                                                            temp_72 = (cPtr_gtlSet *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)).ptr () ;
                                                                          }else{
                                                                            inCompiler->castError ("gtlSet", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)) ;
                                                                          }
                                                                        }
                                                                        cEnumerator_lstringset enumerator_79481 (temp_72.readProperty_value (), kENUMERATION_UP) ;
                                                                        while (enumerator_79481.hasCurrentObject ()) {
                                                                          var_extensions_79448.addAssign_operation (enumerator_79481.current_lkey (HERE).readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2506)) ;
                                                                          enumerator_79481.gotoNextObject () ;
                                                                        }
                                                                        GALGAS_stringlist var_fileList_79601 = this->mProperty_value.getter_regularFilesWithExtensions (GALGAS_bool (false), var_extensions_79448 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2508)) ;
                                                                        GALGAS_lstringset var_files_79682 = GALGAS_lstringset::class_func_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 2509)) ;
                                                                        cEnumerator_stringlist enumerator_79709 (var_fileList_79601, kENUMERATION_UP) ;
                                                                        while (enumerator_79709.hasCurrentObject ()) {
                                                                          {
                                                                          var_files_79682.setter_put (GALGAS_lstring::class_func_new (enumerator_79709.current_mValue (HERE), constinArgument_methodName.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2511)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2511)) ;
                                                                          }
                                                                          enumerator_79709.gotoNextObject () ;
                                                                        }
                                                                        result_result = GALGAS_gtlSet::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2514)), var_files_79682  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2513)) ;
                                                                      }
                                                                    }
                                                                    if (kBoolFalse == test_71) {
                                                                      enumGalgasBool test_73 = kBoolTrue ;
                                                                      if (kBoolTrue == test_73) {
                                                                        test_73 = GALGAS_bool (kIsEqual, GALGAS_string ("trimWhiteSpaces").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                                        if (kBoolTrue == test_73) {
                                                                          {
                                                                          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2517)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2517)) ;
                                                                          }
                                                                          result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2520)), this->mProperty_value.getter_stringByTrimmingWhiteSpaces (SOURCE_FILE ("gtl_data_types.galgas", 2521))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2518)) ;
                                                                        }
                                                                      }
                                                                      if (kBoolFalse == test_73) {
                                                                        result_result = function_customGtlStringGetter (constinArgument_methodName, constinArgument_arguments, constinArgument_context, constinArgument_lib, this->mProperty_value, this->mProperty_where, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2524)) ;
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
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlString performSetter'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlString_performSetter (cPtr_gtlData * inObject,
                                                     const GALGAS_lstring constinArgument_methodName,
                                                     const GALGAS_gtlDataList constinArgument_arguments,
                                                     const GALGAS_gtlContext constinArgument_context,
                                                     const GALGAS_library constinArgument_lib,
                                                     Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlString * object = (cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2544)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2544)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2545)).isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2545)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2545)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2545)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2545)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_80739 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_80739.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2546)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2546)) ;
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
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2549)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2549)) ;
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
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_charIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2552)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2552)) ;
          }
          GALGAS_gtlChar temp_4 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2553)).isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2553)).ptr ())) {
              temp_4 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2553)).ptr () ;
            }else{
              inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2553)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2553)) ;
            }
          }
          GALGAS_char var_charToSet_81106 = temp_4.readProperty_value () ;
          GALGAS_gtlInt temp_5 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2554)).isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2554)).ptr ())) {
              temp_5 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2554)).ptr () ;
            }else{
              inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2554)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2554)) ;
            }
          }
          GALGAS_uint var_index_81179 = temp_5.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2554)) ;
          {
          object->mProperty_value.setter_setCharacterAtIndex (var_charToSet_81106, var_index_81179, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2555)) ;
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
            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_charIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2558)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2558)) ;
            }
            GALGAS_gtlChar temp_7 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2559)).isValid ()) {
              if (nullptr != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2559)).ptr ())) {
                temp_7 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2559)).ptr () ;
              }else{
                inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2559)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2559)) ;
              }
            }
            GALGAS_char var_charToInsert_81439 = temp_7.readProperty_value () ;
            GALGAS_gtlInt temp_8 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2560)).isValid ()) {
              if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2560)).ptr ())) {
                temp_8 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2560)).ptr () ;
              }else{
                inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2560)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2560)) ;
              }
            }
            GALGAS_uint var_index_81515 = temp_8.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2560)) ;
            {
            object->mProperty_value.setter_insertCharacterAtIndex (var_charToInsert_81439, var_index_81515, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2561)) ;
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
              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2564)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2564)) ;
              }
              GALGAS_gtlInt temp_10 ;
              if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2565)).isValid ()) {
                if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2565)).ptr ())) {
                  temp_10 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2565)).ptr () ;
                }else{
                  inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2565)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2565)) ;
                }
              }
              GALGAS_uint var_index_81776 = temp_10.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2565)) ;
              {
              GALGAS_char joker_81873 ; // Joker input parameter
              object->mProperty_value.setter_removeCharacterAtIndex (joker_81873, var_index_81776, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2566)) ;
              }
              object->mProperty_where = constinArgument_methodName.readProperty_location () ;
            }
          }
          if (kBoolFalse == test_9) {
            enumGalgasBool test_11 = kBoolTrue ;
            if (kBoolTrue == test_11) {
              test_11 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("string"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2568)).boolEnum () ;
              if (kBoolTrue == test_11) {
                const GALGAS_gtlString temp_12 = object ;
                GALGAS_gtlData var_copy_81974 = temp_12 ;
                callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("string"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2570)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_81974, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2570)) ;
                GALGAS_gtlString temp_13 ;
                if (var_copy_81974.isValid ()) {
                  if (nullptr != dynamic_cast <const cPtr_gtlString *> (var_copy_81974.ptr ())) {
                    temp_13 = (cPtr_gtlString *) var_copy_81974.ptr () ;
                  }else{
                    inCompiler->castError ("gtlString", var_copy_81974.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2577)) ;
                  }
                }
                object->mProperty_value = temp_13.readProperty_value () ;
                object->mProperty_where = var_copy_81974.readProperty_where () ;
                object->mProperty_meta = var_copy_81974.readProperty_meta () ;
              }
            }
            if (kBoolFalse == test_11) {
              TC_Array <C_FixItDescription> fixItArray14 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2581)).add_operation (GALGAS_string ("' for string target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2581)), fixItArray14  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2581)) ;
            }
          }
        }
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlString_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                                      extensionSetter_gtlString_performSetter) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlString_performSetter (defineExtensionSetter_gtlString_performSetter, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool desc'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlBool::getter_desc (const GALGAS_uint constinArgument_tab,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2594)).add_operation (GALGAS_string ("boolean: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2594)).add_operation (this->mProperty_value.getter_cString (SOURCE_FILE ("gtl_data_types.galgas", 2595)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2595)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2595)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlBool::getter_string (Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value.getter_cString (SOURCE_FILE ("gtl_data_types.galgas", 2598)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool lstring'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlBool::getter_lstring (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::class_func_new (this->mProperty_value.getter_cString (SOURCE_FILE ("gtl_data_types.galgas", 2601)), this->mProperty_where, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2601)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool bool'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlBool::getter_bool (Compiler */* inCompiler */
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool int'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlBool::getter_int (Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  GALGAS_bigint temp_0 ;
  const enumGalgasBool test_1 = this->mProperty_value.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2609)) ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2609)) ;
  }
  result_result = temp_0 ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool float'
//
//--------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlBool::getter_float (Compiler */* inCompiler */
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool plusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_plusOp (Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2617)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool minusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_minusOp (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2621)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool notOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_notOp (Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2625)), this->mProperty_value.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2625))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2625)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool addOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2629)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool subOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2633)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool mulOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2637)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool divOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2641)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool modOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2645)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool andOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_andOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2653)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2652)), this->mProperty_value.operator_and (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2653))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2650)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool orOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_orOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2665)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2664)), this->mProperty_value.operator_or (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2665))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2662)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool xorOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_xorOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2677)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2676)), this->mProperty_value.operator_xor (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2677))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2674)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2680)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool slOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2685)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool srOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2689)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool neqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2697)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2696)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2694)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool eqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2709)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2708)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2706)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool gtOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2721)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2720)), GALGAS_bool (kIsStrictSup, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2718)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool geOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2733)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2732)), GALGAS_bool (kIsSupOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2730)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool ltOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2745)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2744)), GALGAS_bool (kIsStrictInf, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2742)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool leOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2757)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2756)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2754)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2760)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool embeddedType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlBool::getter_embeddedType (Compiler */* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_bool) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBool addMyValue'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlBool::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                      Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 2771))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2771)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool performGetter'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("trueOrFalse"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2785)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2785)) ;
      }
      GALGAS_string temp_1 ;
      const enumGalgasBool test_2 = this->mProperty_value.boolEnum () ;
      if (kBoolTrue == test_2) {
        temp_1 = GALGAS_string ("true") ;
      }else if (kBoolFalse == test_2) {
        temp_1 = GALGAS_string ("false") ;
      }
      result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2788)), temp_1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2786)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("string"))).boolEnum () ;
      if (kBoolTrue == test_3) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2792)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2792)) ;
        }
        const GALGAS_gtlBool temp_4 = this ;
        result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2795)), callExtensionGetter_string ((const cPtr_gtlBool *) temp_4.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2796))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2793)) ;
      }
    }
    if (kBoolFalse == test_3) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("yesOrNo"))).boolEnum () ;
        if (kBoolTrue == test_5) {
          {
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2799)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2799)) ;
          }
          GALGAS_string temp_6 ;
          const enumGalgasBool test_7 = this->mProperty_value.boolEnum () ;
          if (kBoolTrue == test_7) {
            temp_6 = GALGAS_string ("yes") ;
          }else if (kBoolFalse == test_7) {
            temp_6 = GALGAS_string ("no") ;
          }
          result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2802)), temp_6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2800)) ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_8 = kBoolTrue ;
        if (kBoolTrue == test_8) {
          test_8 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("TRUEOrFALSE"))).boolEnum () ;
          if (kBoolTrue == test_8) {
            {
            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2806)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2806)) ;
            }
            GALGAS_string temp_9 ;
            const enumGalgasBool test_10 = this->mProperty_value.boolEnum () ;
            if (kBoolTrue == test_10) {
              temp_9 = GALGAS_string ("TRUE") ;
            }else if (kBoolFalse == test_10) {
              temp_9 = GALGAS_string ("FALSE") ;
            }
            result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2809)), temp_9  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2807)) ;
          }
        }
        if (kBoolFalse == test_8) {
          enumGalgasBool test_11 = kBoolTrue ;
          if (kBoolTrue == test_11) {
            test_11 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("YESOrNO"))).boolEnum () ;
            if (kBoolTrue == test_11) {
              {
              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2813)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2813)) ;
              }
              GALGAS_string temp_12 ;
              const enumGalgasBool test_13 = this->mProperty_value.boolEnum () ;
              if (kBoolTrue == test_13) {
                temp_12 = GALGAS_string ("YES") ;
              }else if (kBoolFalse == test_13) {
                temp_12 = GALGAS_string ("NO") ;
              }
              result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2816)), temp_12  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2814)) ;
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
                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2820)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2820)) ;
                }
                GALGAS_bigint temp_16 ;
                const enumGalgasBool test_17 = this->mProperty_value.boolEnum () ;
                if (kBoolTrue == test_17) {
                  temp_16 = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2824)) ;
                }else if (kBoolFalse == test_17) {
                  temp_16 = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2824)) ;
                }
                result_result = GALGAS_gtlInt::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2823)), temp_16  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2821)) ;
              }
            }
            if (kBoolFalse == test_14) {
              enumGalgasBool test_18 = kBoolTrue ;
              if (kBoolTrue == test_18) {
                test_18 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                if (kBoolTrue == test_18) {
                  {
                  routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2827)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2827)) ;
                  }
                  const GALGAS_gtlBool temp_19 = this ;
                  result_result = GALGAS_gtlType::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2829)), temp_19.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 2829))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2828)) ;
                }
              }
              if (kBoolFalse == test_18) {
                enumGalgasBool test_20 = kBoolTrue ;
                if (kBoolTrue == test_20) {
                  test_20 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_20) {
                    {
                    routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2832)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2832)) ;
                    }
                    result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2834)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2833)) ;
                  }
                }
                if (kBoolFalse == test_20) {
                  enumGalgasBool test_21 = kBoolTrue ;
                  if (kBoolTrue == test_21) {
                    test_21 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                    if (kBoolTrue == test_21) {
                      {
                      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2837)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2837)) ;
                      }
                      result_result = GALGAS_gtlString::class_func_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2839)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2838)) ;
                    }
                  }
                  if (kBoolFalse == test_21) {
                    enumGalgasBool test_22 = kBoolTrue ;
                    if (kBoolTrue == test_22) {
                      test_22 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("bool"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2841)).boolEnum () ;
                      if (kBoolTrue == test_22) {
                        const GALGAS_gtlBool temp_23 = this ;
                        result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("bool"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2842)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_23, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2842)) ;
                      }
                    }
                    if (kBoolFalse == test_22) {
                      enumGalgasBool test_24 = kBoolTrue ;
                      if (kBoolTrue == test_24) {
                        test_24 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                        if (kBoolTrue == test_24) {
                          {
                          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2850)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2850)) ;
                          }
                          result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2852)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2852))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2851)) ;
                        }
                      }
                      if (kBoolFalse == test_24) {
                        TC_Array <C_FixItDescription> fixItArray25 ;
                        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2855)).add_operation (GALGAS_string ("' for boolean target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2855)), fixItArray25  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2855)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlBool performSetter'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlBool_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlBool * object = (cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2870)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2870)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2871)).isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2871)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2871)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2871)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2871)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_90395 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_90395.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2872)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2872)) ;
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
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2875)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2875)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("bool"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2877)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlBool temp_4 = object ;
          GALGAS_gtlData var_copy_90703 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("bool"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2879)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_90703, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2879)) ;
          GALGAS_gtlBool temp_5 ;
          if (var_copy_90703.isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlBool *> (var_copy_90703.ptr ())) {
              temp_5 = (cPtr_gtlBool *) var_copy_90703.ptr () ;
            }else{
              inCompiler->castError ("gtlBool", var_copy_90703.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2886)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_90703.readProperty_where () ;
          object->mProperty_meta = var_copy_90703.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2890)).add_operation (GALGAS_string ("' for boolean target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2890)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2890)) ;
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlBool_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                                      extensionSetter_gtlBool_performSetter) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlBool_performSetter (defineExtensionSetter_gtlBool_performSetter, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet desc'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlSet::getter_desc (const GALGAS_uint constinArgument_tab,
                                        Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2914)).add_operation (GALGAS_string ("set: @!\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2914)) ;
  cEnumerator_lstringset enumerator_91905 (this->mProperty_value, kENUMERATION_UP) ;
  const bool bool_0 = true ;
  if (enumerator_91905.hasCurrentObject () && bool_0) {
    result_result.plusAssign_operation(GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2918))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2918)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2918)) ;
    while (enumerator_91905.hasCurrentObject () && bool_0) {
      result_result.plusAssign_operation(enumerator_91905.current_lkey (HERE).readProperty_string (), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2920)) ;
      enumerator_91905.gotoNextObject () ;
      if (enumerator_91905.hasCurrentObject () && bool_0) {
        result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2922)) ;
      }
    }
    result_result.plusAssign_operation(GALGAS_string ("\n"), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2924)) ;
  }
  result_result.plusAssign_operation(GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2926)).add_operation (GALGAS_string ("!\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2926)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2926)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlSet::getter_string (Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a set to a string"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2930)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet lstring'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlSet::getter_lstring (Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a set to a lstring"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2934)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet bool'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlSet::getter_bool (Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a set to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2938)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet int'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlSet::getter_int (Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a set to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2942)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet float'
//
//--------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlSet::getter_float (Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a set to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2946)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet plusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_plusOp (Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2950)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet minusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_minusOp (Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2954)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet notOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_notOp (Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2958)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet addOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_addOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_lstringset var_set_93078 = this->mProperty_value ;
  GALGAS_lstring var_element_93105 = callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2963)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = var_set_93078.getter_hasKey (var_element_93105.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2964)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      var_set_93078.setter_del (var_element_93105, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2965)) ;
      }
    }
  }
  {
  var_set_93078.setter_put (callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2967)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2967)) ;
  }
  result_result = GALGAS_gtlSet::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2968)), var_set_93078  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2968)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet subOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_subOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstringset var_resultSet_93400 = this->mProperty_value ;
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2974)) ;
        }
      }
      cEnumerator_lstringset enumerator_93427 (temp_1.readProperty_value (), kENUMERATION_UP) ;
      while (enumerator_93427.hasCurrentObject ()) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = var_resultSet_93400.getter_hasKey (enumerator_93427.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2975)).boolEnum () ;
          if (kBoolTrue == test_2) {
            {
            var_resultSet_93400.setter_del (enumerator_93427.current_lkey (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2976)) ;
            }
          }
        }
        enumerator_93427.gotoNextObject () ;
      }
      result_result = GALGAS_gtlSet::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2980)), var_resultSet_93400  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2979)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2983)), GALGAS_string ("set expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2983)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet mulOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2988)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet divOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2992)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet modOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2996)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet andOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_andOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstringset var_resultSet_94167 = GALGAS_lstringset::class_func_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 3001)) ;
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3002)) ;
        }
      }
      cEnumerator_lstringset enumerator_94198 (temp_1.readProperty_value (), kENUMERATION_UP) ;
      while (enumerator_94198.hasCurrentObject ()) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = this->mProperty_value.getter_hasKey (enumerator_94198.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3003)).boolEnum () ;
          if (kBoolTrue == test_2) {
            {
            var_resultSet_94167.setter_put (enumerator_94198.current_lkey (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3004)) ;
            }
          }
        }
        enumerator_94198.gotoNextObject () ;
      }
      result_result = GALGAS_gtlSet::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3008)), var_resultSet_94167  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3007)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3011)), GALGAS_string ("set expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3011)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet orOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_orOp (const GALGAS_gtlData constinArgument_right,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3017)) ;
        }
      }
      GALGAS_lstringset var_resultSet_94579 = temp_1.readProperty_value () ;
      cEnumerator_lstringset enumerator_94625 (this->mProperty_value, kENUMERATION_UP) ;
      while (enumerator_94625.hasCurrentObject ()) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = var_resultSet_94579.getter_hasKey (enumerator_94625.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3019)).operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3019)).boolEnum () ;
          if (kBoolTrue == test_2) {
            {
            var_resultSet_94579.setter_put (enumerator_94625.current_lkey (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3020)) ;
            }
          }
        }
        enumerator_94625.gotoNextObject () ;
      }
      result_result = GALGAS_gtlSet::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3024)), var_resultSet_94579  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3023)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3027)), GALGAS_string ("set expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3027)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet xorOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3032)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet slOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3036)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet srOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3040)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet neqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3046)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3046)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3045)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3049)), GALGAS_string ("set expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3049)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet eqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3056)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3056)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3055)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3059)), GALGAS_string ("set expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3059)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet gtOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                         Compiler * inCompiler
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
          if (nullptr != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
            temp_2 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
          }else{
            inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3065)) ;
          }
        }
        test_1 = GALGAS_bool (kIsEqual, temp_2.readProperty_value ().objectCompare (this->mProperty_value)).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3066)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3066)) ;
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_bool var_included_95982 = GALGAS_bool (true) ;
        GALGAS_gtlSet temp_3 ;
        if (constinArgument_right.isValid ()) {
          if (nullptr != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
            temp_3 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
          }else{
            inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3069)) ;
          }
        }
        cEnumerator_lstringset enumerator_96009 (temp_3.readProperty_value (), kENUMERATION_UP) ;
        bool bool_4 = var_included_95982.isValidAndTrue () ;
        if (enumerator_96009.hasCurrentObject () && bool_4) {
          while (enumerator_96009.hasCurrentObject () && bool_4) {
            enumGalgasBool test_5 = kBoolTrue ;
            if (kBoolTrue == test_5) {
              test_5 = this->mProperty_value.getter_hasKey (enumerator_96009.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3070)).operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3070)).boolEnum () ;
              if (kBoolTrue == test_5) {
                var_included_95982 = GALGAS_bool (false) ;
              }
            }
            enumerator_96009.gotoNextObject () ;
            if (enumerator_96009.hasCurrentObject ()) {
              bool_4 = var_included_95982.isValidAndTrue () ;
            }
          }
        }
        result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3072)), var_included_95982  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3072)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray6 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3075)), GALGAS_string ("set expected"), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3075)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet geOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_bool var_included_96372 = GALGAS_bool (true) ;
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3082)) ;
        }
      }
      cEnumerator_lstringset enumerator_96397 (temp_1.readProperty_value (), kENUMERATION_UP) ;
      bool bool_2 = var_included_96372.isValidAndTrue () ;
      if (enumerator_96397.hasCurrentObject () && bool_2) {
        while (enumerator_96397.hasCurrentObject () && bool_2) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = this->mProperty_value.getter_hasKey (enumerator_96397.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3083)).operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3083)).boolEnum () ;
            if (kBoolTrue == test_3) {
              var_included_96372 = GALGAS_bool (false) ;
            }
          }
          enumerator_96397.gotoNextObject () ;
          if (enumerator_96397.hasCurrentObject ()) {
            bool_2 = var_included_96372.isValidAndTrue () ;
          }
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3085)), var_included_96372  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3085)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3087)), GALGAS_string ("set expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3087)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet ltOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                         Compiler * inCompiler
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
          if (nullptr != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
            temp_2 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
          }else{
            inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3093)) ;
          }
        }
        test_1 = GALGAS_bool (kIsEqual, temp_2.readProperty_value ().objectCompare (this->mProperty_value)).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3094)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3094)) ;
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_bool var_included_96865 = GALGAS_bool (true) ;
        cEnumerator_lstringset enumerator_96892 (this->mProperty_value, kENUMERATION_UP) ;
        bool bool_3 = var_included_96865.isValidAndTrue () ;
        if (enumerator_96892.hasCurrentObject () && bool_3) {
          while (enumerator_96892.hasCurrentObject () && bool_3) {
            enumGalgasBool test_4 = kBoolTrue ;
            if (kBoolTrue == test_4) {
              GALGAS_gtlSet temp_5 ;
              if (constinArgument_right.isValid ()) {
                if (nullptr != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
                  temp_5 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
                }else{
                  inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3098)) ;
                }
              }
              test_4 = temp_5.readProperty_value ().getter_hasKey (enumerator_96892.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3098)).operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3098)).boolEnum () ;
              if (kBoolTrue == test_4) {
                var_included_96865 = GALGAS_bool (false) ;
              }
            }
            enumerator_96892.gotoNextObject () ;
            if (enumerator_96892.hasCurrentObject ()) {
              bool_3 = var_included_96865.isValidAndTrue () ;
            }
          }
        }
        result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3100)), var_included_96865  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3100)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray6 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3103)), GALGAS_string ("set expected"), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3103)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet leOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_bool var_included_97255 = GALGAS_bool (true) ;
      cEnumerator_lstringset enumerator_97280 (this->mProperty_value, kENUMERATION_UP) ;
      bool bool_1 = var_included_97255.isValidAndTrue () ;
      if (enumerator_97280.hasCurrentObject () && bool_1) {
        while (enumerator_97280.hasCurrentObject () && bool_1) {
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            GALGAS_gtlSet temp_3 ;
            if (constinArgument_right.isValid ()) {
              if (nullptr != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
                temp_3 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
              }else{
                inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3111)) ;
              }
            }
            test_2 = temp_3.readProperty_value ().getter_hasKey (enumerator_97280.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3111)).operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3111)).boolEnum () ;
            if (kBoolTrue == test_2) {
              var_included_97255 = GALGAS_bool (false) ;
            }
          }
          enumerator_97280.gotoNextObject () ;
          if (enumerator_97280.hasCurrentObject ()) {
            bool_1 = var_included_97255.isValidAndTrue () ;
          }
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3113)), var_included_97255  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3113)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3115)), GALGAS_string ("set expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3115)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet embeddedType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlSet::getter_embeddedType (Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3121)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlSet addMyValue'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlSet::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                     Compiler * /* inCompiler */
                                     COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 3126))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3126)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet performGetter'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                  const GALGAS_gtlDataList constinArgument_arguments,
                                                  const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_library constinArgument_lib,
                                                  Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("length").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3140)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3140)) ;
      }
      result_result = GALGAS_gtlInt::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3143)), this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3144)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 3144))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3141)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("list").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3147)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3147)) ;
        }
        result_result = GALGAS_gtlList::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3149)), GALGAS_list::class_func_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 3149))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3148)) ;
        cEnumerator_lstringset enumerator_98552 (this->mProperty_value, kENUMERATION_UP) ;
        while (enumerator_98552.hasCurrentObject ()) {
          {
          result_result.insulate (HERE) ;
          cPtr_gtlData * ptr_98576 = (cPtr_gtlData *) result_result.ptr () ;
          callExtensionSetter_appendItem ((cPtr_gtlData *) ptr_98576, GALGAS_gtlString::class_func_new (enumerator_98552.current_lkey (HERE).readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3152)), enumerator_98552.current_lkey (HERE).readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3152)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3152)) ;
          }
          enumerator_98552.gotoNextObject () ;
        }
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("contains").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_2) {
          {
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_anyArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3155)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3155)) ;
          }
          GALGAS_string var_key_98777 = callExtensionGetter_string ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3156)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3156)) ;
          result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3158)), this->mProperty_value.getter_hasKey (var_key_98777 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3158))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3157)) ;
        }
      }
      if (kBoolFalse == test_2) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("elementNamed").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_3) {
            {
            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_anyArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3161)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3161)) ;
            }
            GALGAS_string var_key_99045 = callExtensionGetter_string ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3162)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3162)) ;
            GALGAS_location var_loc_99105 = this->mProperty_value.getter_locationForKey (var_key_99045, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3163)) ;
            result_result = GALGAS_gtlString::class_func_new (var_loc_99105, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3165)), var_key_99045  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3164)) ;
          }
        }
        if (kBoolFalse == test_3) {
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_4) {
              {
              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3168)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3168)) ;
              }
              result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3170)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3169)) ;
            }
          }
          if (kBoolFalse == test_4) {
            enumGalgasBool test_5 = kBoolTrue ;
            if (kBoolTrue == test_5) {
              test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_5) {
                {
                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3173)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3173)) ;
                }
                result_result = GALGAS_gtlString::class_func_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3175)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3174)) ;
              }
            }
            if (kBoolFalse == test_5) {
              enumGalgasBool test_6 = kBoolTrue ;
              if (kBoolTrue == test_6) {
                test_6 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("set"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3177)).boolEnum () ;
                if (kBoolTrue == test_6) {
                  const GALGAS_gtlSet temp_7 = this ;
                  result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("set"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3178)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_7, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3178)) ;
                }
              }
              if (kBoolFalse == test_6) {
                enumGalgasBool test_8 = kBoolTrue ;
                if (kBoolTrue == test_8) {
                  test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_8) {
                    {
                    routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3186)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3186)) ;
                    }
                    result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3188)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3188))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3187)) ;
                  }
                }
                if (kBoolFalse == test_8) {
                  TC_Array <C_FixItDescription> fixItArray9 ;
                  inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3191)).add_operation (GALGAS_string ("' for set target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3191)), fixItArray9  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3191)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlSet performSetter'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlSet_performSetter (cPtr_gtlData * inObject,
                                                  const GALGAS_lstring constinArgument_methodName,
                                                  const GALGAS_gtlDataList constinArgument_arguments,
                                                  const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_library constinArgument_lib,
                                                  Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlSet * object = (cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3206)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3206)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3207)).isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3207)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3207)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3207)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3207)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_100534 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_100534.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3208)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3208)) ;
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
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3211)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3211)) ;
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
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_anyArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3214)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3214)) ;
          }
          GALGAS_lstring var_key_100893 = callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3215)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3215)) ;
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = object->mProperty_value.getter_hasKey (var_key_100893.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3216)).boolEnum () ;
            if (kBoolTrue == test_4) {
              {
              object->mProperty_value.setter_del (var_key_100893, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3217)) ;
              }
            }
          }
          {
          object->mProperty_value.setter_put (var_key_100893, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3219)) ;
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
            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_anyArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3222)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3222)) ;
            }
            GALGAS_lstring var_key_101163 = callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3223)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3223)) ;
            enumGalgasBool test_6 = kBoolTrue ;
            if (kBoolTrue == test_6) {
              test_6 = object->mProperty_value.getter_hasKey (var_key_101163.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3224)).boolEnum () ;
              if (kBoolTrue == test_6) {
                {
                object->mProperty_value.setter_del (var_key_101163, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3225)) ;
                }
              }
            }
            object->mProperty_where = constinArgument_methodName.readProperty_location () ;
          }
        }
        if (kBoolFalse == test_5) {
          enumGalgasBool test_7 = kBoolTrue ;
          if (kBoolTrue == test_7) {
            test_7 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("set"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3228)).boolEnum () ;
            if (kBoolTrue == test_7) {
              const GALGAS_gtlSet temp_8 = object ;
              GALGAS_gtlData var_copy_101358 = temp_8 ;
              callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("set"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3230)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_101358, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3230)) ;
              GALGAS_gtlSet temp_9 ;
              if (var_copy_101358.isValid ()) {
                if (nullptr != dynamic_cast <const cPtr_gtlSet *> (var_copy_101358.ptr ())) {
                  temp_9 = (cPtr_gtlSet *) var_copy_101358.ptr () ;
                }else{
                  inCompiler->castError ("gtlSet", var_copy_101358.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3237)) ;
                }
              }
              object->mProperty_value = temp_9.readProperty_value () ;
              object->mProperty_where = var_copy_101358.readProperty_where () ;
              object->mProperty_meta = var_copy_101358.readProperty_meta () ;
            }
          }
          if (kBoolFalse == test_7) {
            TC_Array <C_FixItDescription> fixItArray10 ;
            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3241)).add_operation (GALGAS_string ("' for set target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3241)), fixItArray10  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3241)) ;
          }
        }
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlSet_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                                      extensionSetter_gtlSet_performSetter) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlSet_performSetter (defineExtensionSetter_gtlSet_performSetter, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct desc'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlStruct::getter_desc (const GALGAS_uint constinArgument_tab,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3254)).add_operation (GALGAS_string ("struct: @{\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3254)) ;
  cEnumerator_gtlVarMap enumerator_102098 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_102098.hasCurrentObject ()) {
    result_result.plusAssign_operation(GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3257))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3257)).add_operation (enumerator_102098.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3257)).add_operation (GALGAS_string (" :>\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3258)).add_operation (callExtensionGetter_desc ((const cPtr_gtlData *) enumerator_102098.current_value (HERE).ptr (), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (8U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3259)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3259)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3258)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3257)) ;
    enumerator_102098.gotoNextObject () ;
  }
  result_result.plusAssign_operation(GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3261)).add_operation (GALGAS_string ("}\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3261)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3261)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlStruct::getter_string (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3265)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct lstring'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlStruct::getter_lstring (Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3269)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct bool'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlStruct::getter_bool (Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a struct to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3273)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct int'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlStruct::getter_int (Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a struct to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3277)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct float'
//
//--------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlStruct::getter_float (Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a struct to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3281)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct plusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_plusOp (Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3285)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct minusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_minusOp (Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3289)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct notOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_notOp (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3293)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct addOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3297)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct subOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3301)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct mulOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3305)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct divOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3309)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct modOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3313)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct andOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3317)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct orOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3321)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct xorOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3325)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct slOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3329)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct srOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3333)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct neqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlStruct temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlStruct *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlStruct *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlStruct", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3338)) ;
        }
      }
      GALGAS_gtlVarMap var_rValue_104579 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_104626 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3340)).objectCompare (var_rValue_104579.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3340)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_104626 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_104626 = GALGAS_bool (true) ;
        cEnumerator_gtlVarMap enumerator_104740 (this->mProperty_value, kENUMERATION_UP) ;
        while (enumerator_104740.hasCurrentObject ()) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = var_rValue_104579.getter_hasKey (enumerator_104740.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3345)).boolEnum () ;
            if (kBoolTrue == test_3) {
              GALGAS_gtlData var_rData_104840 ;
              var_rValue_104579.method_get (enumerator_104740.current_lkey (HERE), var_rData_104840, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3346)) ;
              var_equal_104626 = var_equal_104626.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_104740.current_value (HERE).ptr (), var_rData_104840, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3347)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3347)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3347)) ;
            }
          }
          if (kBoolFalse == test_3) {
            var_equal_104626 = GALGAS_bool (false) ;
          }
          enumerator_104740.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3353)), var_equal_104626.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3353))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3353)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("struct expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3355)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct eqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlStruct temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlStruct *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlStruct *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlStruct", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3361)) ;
        }
      }
      GALGAS_gtlVarMap var_rValue_105219 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_105266 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3363)).objectCompare (var_rValue_105219.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3363)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_105266 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_105266 = GALGAS_bool (true) ;
        cEnumerator_gtlVarMap enumerator_105380 (this->mProperty_value, kENUMERATION_UP) ;
        while (enumerator_105380.hasCurrentObject ()) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = var_rValue_105219.getter_hasKey (enumerator_105380.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3368)).boolEnum () ;
            if (kBoolTrue == test_3) {
              GALGAS_gtlData var_rData_105480 ;
              var_rValue_105219.method_get (enumerator_105380.current_lkey (HERE), var_rData_105480, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3369)) ;
              var_equal_105266 = var_equal_105266.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_105380.current_value (HERE).ptr (), var_rData_105480, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3370)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3370)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3370)) ;
            }
          }
          if (kBoolFalse == test_3) {
            var_equal_105266 = GALGAS_bool (false) ;
          }
          enumerator_105380.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3376)), var_equal_105266  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3376)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("struct expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3378)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct gtOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_gtOp (const GALGAS_gtlData /* constinArgument_right */,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3383)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct geOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_geOp (const GALGAS_gtlData /* constinArgument_right */,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3386)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct ltOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_ltOp (const GALGAS_gtlData /* constinArgument_right */,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3389)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct leOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_leOp (const GALGAS_gtlData /* constinArgument_right */,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3392)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct embeddedType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlStruct::getter_embeddedType (Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3397)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlStruct addMyValue'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlStruct::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                        Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 3402))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3402)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct performGetter'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                     const GALGAS_gtlDataList constinArgument_arguments,
                                                     const GALGAS_gtlContext constinArgument_context,
                                                     const GALGAS_library constinArgument_lib,
                                                     Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("map").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3416)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3416)) ;
      }
      result_result = GALGAS_gtlMap::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3419)), this->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3417)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3423)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3423)) ;
        }
        const GALGAS_gtlStruct temp_2 = this ;
        result_result = GALGAS_gtlType::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3425)), temp_2.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 3425))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3424)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3428)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3428)) ;
          }
          result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3430)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3429)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3433)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3433)) ;
            }
            result_result = GALGAS_gtlString::class_func_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3435)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3434)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("struct"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3437)).boolEnum () ;
            if (kBoolTrue == test_5) {
              const GALGAS_gtlStruct temp_6 = this ;
              result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("struct"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3438)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_6, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3438)) ;
            }
          }
          if (kBoolFalse == test_5) {
            enumGalgasBool test_7 = kBoolTrue ;
            if (kBoolTrue == test_7) {
              test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_7) {
                {
                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3446)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3446)) ;
                }
                result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3448)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3448))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3447)) ;
              }
            }
            if (kBoolFalse == test_7) {
              TC_Array <C_FixItDescription> fixItArray8 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3451)).add_operation (GALGAS_string ("' for struct target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3451)), fixItArray8  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3451)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlStruct performSetter'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlStruct_performSetter (cPtr_gtlData * inObject,
                                                     const GALGAS_lstring constinArgument_methodName,
                                                     const GALGAS_gtlDataList constinArgument_arguments,
                                                     const GALGAS_gtlContext constinArgument_context,
                                                     const GALGAS_library constinArgument_lib,
                                                     Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlStruct * object = (cPtr_gtlStruct *) inObject ;
  macroValidSharedObject (object, cPtr_gtlStruct) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3466)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3466)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3467)).isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3467)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3467)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3467)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3467)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_108602 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_108602.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3468)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3468)) ;
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
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3471)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3471)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("struct"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3473)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlStruct temp_4 = object ;
          GALGAS_gtlData var_copy_108912 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("struct"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3475)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_108912, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3475)) ;
          GALGAS_gtlStruct temp_5 ;
          if (var_copy_108912.isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlStruct *> (var_copy_108912.ptr ())) {
              temp_5 = (cPtr_gtlStruct *) var_copy_108912.ptr () ;
            }else{
              inCompiler->castError ("gtlStruct", var_copy_108912.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3482)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_108912.readProperty_where () ;
          object->mProperty_meta = var_copy_108912.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3486)).add_operation (GALGAS_string ("' for struct target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3486)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3486)) ;
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlStruct_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlStruct.mSlotID,
                                      extensionSetter_gtlStruct_performSetter) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlStruct_performSetter (defineExtensionSetter_gtlStruct_performSetter, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlStruct structField'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlStruct::method_structField (const GALGAS_lstring constinArgument_name,
                                         GALGAS_gtlData & outArgument_result,
                                         GALGAS_bool & outArgument_found,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_value.getter_hasKey (constinArgument_name.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3498)).boolEnum () ;
    if (kBoolTrue == test_0) {
      this->mProperty_value.method_get (constinArgument_name, outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3499)) ;
      outArgument_found = GALGAS_bool (true) ;
    }
  }
  if (kBoolFalse == test_0) {
    outArgument_result = GALGAS_gtlUnconstructed::class_func_new (constinArgument_name.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3502))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3502)) ;
    outArgument_found = GALGAS_bool (false) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct resultField'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_resultField (const GALGAS_lstring constinArgument_name,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_value.getter_hasKey (constinArgument_name.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3511)).boolEnum () ;
    if (kBoolTrue == test_0) {
      this->mProperty_value.method_get (constinArgument_name, result_result, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3512)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_gtlUnconstructed::class_func_new (constinArgument_name.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3514))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3514)) ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct hasStructField'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlStruct::getter_hasStructField (const GALGAS_lstring constinArgument_name,
                                                   Compiler */* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = this->mProperty_value.getter_hasKey (constinArgument_name.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3525)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlStruct setStructField'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlStruct_setStructField (cPtr_gtlData * inObject,
                                                      const GALGAS_lstring constinArgument_name,
                                                      const GALGAS_gtlData constinArgument_data,
                                                      Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlStruct * object = (cPtr_gtlStruct *) inObject ;
  macroValidSharedObject (object, cPtr_gtlStruct) ;
  {
  extensionSetter_replaceOrCreate (object->mProperty_value, constinArgument_name, constinArgument_data, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3535)) ;
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlStruct_setStructField (void) {
  enterExtensionSetter_setStructField (kTypeDescriptor_GALGAS_gtlStruct.mSlotID,
                                       extensionSetter_gtlStruct_setStructField) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlStruct_setStructField (defineExtensionSetter_gtlStruct_setStructField, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlStruct setStructFieldAtLevel'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlStruct_setStructFieldAtLevel (cPtr_gtlData * inObject,
                                                             const GALGAS_lstring constinArgument_name,
                                                             const GALGAS_gtlData constinArgument_data,
                                                             const GALGAS_uint constinArgument_level,
                                                             Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlStruct * object = (cPtr_gtlStruct *) inObject ;
  macroValidSharedObject (object, cPtr_gtlStruct) ;
  {
  extensionSetter_replaceOrCreateAtLevel (object->mProperty_value, constinArgument_name, constinArgument_data, constinArgument_level, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3546)) ;
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlStruct_setStructFieldAtLevel (void) {
  enterExtensionSetter_setStructFieldAtLevel (kTypeDescriptor_GALGAS_gtlStruct.mSlotID,
                                              extensionSetter_gtlStruct_setStructFieldAtLevel) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlStruct_setStructFieldAtLevel (defineExtensionSetter_gtlStruct_setStructFieldAtLevel, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlStruct deleteStructField'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlStruct_deleteStructField (cPtr_gtlData * inObject,
                                                         const GALGAS_lstring constinArgument_name,
                                                         Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlStruct * object = (cPtr_gtlStruct *) inObject ;
  macroValidSharedObject (object, cPtr_gtlStruct) ;
  {
  GALGAS_gtlData joker_111224 ; // Joker input parameter
  object->mProperty_value.setter_del (constinArgument_name, joker_111224, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3555)) ;
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlStruct_deleteStructField (void) {
  enterExtensionSetter_deleteStructField (kTypeDescriptor_GALGAS_gtlStruct.mSlotID,
                                          extensionSetter_gtlStruct_deleteStructField) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlStruct_deleteStructField (defineExtensionSetter_gtlStruct_deleteStructField, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList desc'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlList::getter_desc (const GALGAS_uint constinArgument_tab,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3567)).add_operation (GALGAS_string ("list: @(\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3567)) ;
  cEnumerator_list enumerator_111628 (this->mProperty_value, kENUMERATION_UP) ;
  GALGAS_uint index_111624 ((uint32_t) 0) ;
  while (enumerator_111628.hasCurrentObject ()) {
    result_result.plusAssign_operation(GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3570))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3570)).add_operation (index_111624.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 3571)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3570)).add_operation (GALGAS_string (" :>\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3571)).add_operation (callExtensionGetter_desc ((const cPtr_gtlData *) enumerator_111628.current_value (HERE).ptr (), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (8U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3572)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3572)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3571)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3570)) ;
    enumerator_111628.gotoNextObject () ;
    index_111624.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3569)) ;
  }
  result_result.plusAssign_operation(GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3574)).add_operation (GALGAS_string (")\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3574)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3574)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlList::getter_string (Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3578)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList lstring'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlList::getter_lstring (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3582)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList bool'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlList::getter_bool (Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a list to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3586)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList int'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlList::getter_int (Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a list to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3590)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList float'
//
//--------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlList::getter_float (Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a list to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3594)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList plusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_plusOp (Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3598)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList minusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_minusOp (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3602)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList notOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_notOp (Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3606)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList addOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_addOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_list var_res_112755 = this->mProperty_value ;
  var_res_112755.addAssign_operation (constinArgument_right  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3611)) ;
  result_result = GALGAS_gtlList::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3612)), var_res_112755  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3612)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList subOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3616)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList mulOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3620)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList divOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3624)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList modOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3628)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList andOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3632)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList orOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_orOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlList).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlList temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlList *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlList *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlList", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3640)) ;
        }
      }
      result_result = GALGAS_gtlList::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3639)), this->mProperty_value.add_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3640))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3637)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("list expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3643)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList xorOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3648)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList slOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3652)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList srOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3656)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList neqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlList).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlList temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlList *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlList *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlList", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3661)) ;
        }
      }
      GALGAS_list var_rValue_114234 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_114279 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3663)).objectCompare (var_rValue_114234.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3663)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_114279 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_114279 = GALGAS_bool (true) ;
        cEnumerator_list enumerator_114390 (this->mProperty_value, kENUMERATION_UP) ;
        cEnumerator_list enumerator_114407 (var_rValue_114234, kENUMERATION_UP) ;
        while (enumerator_114390.hasCurrentObject () && enumerator_114407.hasCurrentObject ()) {
          var_equal_114279 = var_equal_114279.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_114390.current_value (HERE).ptr (), enumerator_114407.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3668)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3668)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3668)) ;
          enumerator_114390.gotoNextObject () ;
          enumerator_114407.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3671)), var_equal_114279.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3671))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3671)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("list expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3673)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList eqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlList).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlList temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlList *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlList *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlList", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3679)) ;
        }
      }
      GALGAS_list var_rValue_114735 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_114780 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3681)).objectCompare (var_rValue_114735.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3681)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_114780 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_114780 = GALGAS_bool (true) ;
        cEnumerator_list enumerator_114891 (this->mProperty_value, kENUMERATION_UP) ;
        cEnumerator_list enumerator_114908 (var_rValue_114735, kENUMERATION_UP) ;
        while (enumerator_114891.hasCurrentObject () && enumerator_114908.hasCurrentObject ()) {
          var_equal_114780 = var_equal_114780.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_114891.current_value (HERE).ptr (), enumerator_114908.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3686)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3686)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3686)) ;
          enumerator_114891.gotoNextObject () ;
          enumerator_114908.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3689)), var_equal_114780  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3689)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("list expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3691)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList gtOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_gtOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a list does not support the > operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3696)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList geOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_geOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a list does not support the >= operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3700)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList ltOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_ltOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a list does not support the < operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3704)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList leOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_leOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a list does not support the <= operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3708)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList embeddedType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlList::getter_embeddedType (Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3713)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlList addMyValue'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlList::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                      Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 3718))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3718)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList performGetter'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("length").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3732)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3732)) ;
      }
      result_result = GALGAS_gtlInt::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3735)), this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3736)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 3736))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3733)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("first").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3739)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3739)) ;
        }
        this->mProperty_value.method_first (result_result, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3740)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("last").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_2) {
          {
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3742)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3742)) ;
          }
          this->mProperty_value.method_last (result_result, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3743)) ;
        }
      }
      if (kBoolFalse == test_2) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("elementAtIndex").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_3) {
            {
            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3745)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3745)) ;
            }
            GALGAS_uint var_index_116932 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3746)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3746)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3746)) ;
            enumGalgasBool test_4 = kBoolTrue ;
            if (kBoolTrue == test_4) {
              test_4 = GALGAS_bool (kIsStrictInf, var_index_116932.objectCompare (this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3747)))).boolEnum () ;
              if (kBoolTrue == test_4) {
                result_result = this->mProperty_value.getter_valueAtIndex (var_index_116932, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3748)) ;
              }
            }
            if (kBoolFalse == test_4) {
              TC_Array <C_FixItDescription> fixItArray5 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("index out of bounds"), fixItArray5  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3750)) ;
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
              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3753)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3753)) ;
              }
              GALGAS_uint var_index_117248 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3754)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3754)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3754)) ;
              enumGalgasBool test_7 = kBoolTrue ;
              if (kBoolTrue == test_7) {
                test_7 = GALGAS_bool (kIsStrictInf, var_index_117248.objectCompare (this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3755)))).boolEnum () ;
                if (kBoolTrue == test_7) {
                  result_result = GALGAS_gtlList::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3758)), this->mProperty_value.getter_subListToIndex (var_index_117248, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3759))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3756)) ;
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
                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3765)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3765)) ;
                }
                GALGAS_uint var_index_117606 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3766)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3766)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3766)) ;
                enumGalgasBool test_10 = kBoolTrue ;
                if (kBoolTrue == test_10) {
                  test_10 = GALGAS_bool (kIsStrictInf, var_index_117606.objectCompare (this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3767)))).boolEnum () ;
                  if (kBoolTrue == test_10) {
                    result_result = GALGAS_gtlList::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3770)), this->mProperty_value.getter_subListFromIndex (var_index_117606, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3771))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3768)) ;
                  }
                }
                if (kBoolFalse == test_10) {
                  result_result = GALGAS_gtlList::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3776)), GALGAS_list::class_func_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 3777))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3774)) ;
                }
              }
            }
            if (kBoolFalse == test_9) {
              enumGalgasBool test_11 = kBoolTrue ;
              if (kBoolTrue == test_11) {
                test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("subList").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                if (kBoolTrue == test_11) {
                  {
                  routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_intIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3781)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3781)) ;
                  }
                  GALGAS_uint var_start_118052 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3782)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3782)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3782)) ;
                  GALGAS_uint var_length_118104 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3783)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3783)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3783)) ;
                  enumGalgasBool test_12 = kBoolTrue ;
                  if (kBoolTrue == test_12) {
                    test_12 = GALGAS_bool (kIsStrictInf, var_start_118052.objectCompare (this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3784)))).boolEnum () ;
                    if (kBoolTrue == test_12) {
                      enumGalgasBool test_13 = kBoolTrue ;
                      if (kBoolTrue == test_13) {
                        test_13 = GALGAS_bool (kIsStrictSup, var_start_118052.add_operation (var_length_118104, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3785)).objectCompare (this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3785)))).boolEnum () ;
                        if (kBoolTrue == test_13) {
                          var_length_118104 = this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3786)).substract_operation (var_start_118052, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3786)) ;
                        }
                      }
                      result_result = GALGAS_gtlList::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3790)), this->mProperty_value.getter_subListWithRange (GALGAS_range::class_func_new (var_start_118052, var_length_118104, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3791)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3791))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3788)) ;
                    }
                  }
                  if (kBoolFalse == test_12) {
                    result_result = GALGAS_gtlList::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3796)), GALGAS_list::class_func_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 3797))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3794)) ;
                  }
                }
              }
              if (kBoolFalse == test_11) {
                enumGalgasBool test_14 = kBoolTrue ;
                if (kBoolTrue == test_14) {
                  test_14 = GALGAS_bool (kIsEqual, GALGAS_string ("mapBy").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_14) {
                    {
                    routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_anyArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3801)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3801)) ;
                    }
                    GALGAS_lstring var_key_118670 = callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3802)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3802)) ;
                    GALGAS_gtlVarMap var_resultMap_118728 = GALGAS_gtlVarMap::class_func_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 3803)) ;
                    const GALGAS_gtlList temp_15 = this ;
                    cEnumerator_list enumerator_118759 (temp_15.readProperty_value (), kENUMERATION_UP) ;
                    GALGAS_uint index_118754 ((uint32_t) 0) ;
                    while (enumerator_118759.hasCurrentObject ()) {
                      if (enumerator_118759.current_value (HERE).isValid ()) {
                        if (enumerator_118759.current_value (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct) {
                          GALGAS_gtlStruct cast_118833_itemStruct ((cPtr_gtlStruct *) enumerator_118759.current_value (HERE).ptr ()) ;
                          enumGalgasBool test_16 = kBoolTrue ;
                          if (kBoolTrue == test_16) {
                            test_16 = cast_118833_itemStruct.readProperty_value ().getter_hasKey (var_key_118670.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3807)).boolEnum () ;
                            if (kBoolTrue == test_16) {
                              GALGAS_gtlData var_keyValue_118956 ;
                              cast_118833_itemStruct.readProperty_value ().method_get (var_key_118670, var_keyValue_118956, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3808)) ;
                              {
                              var_resultMap_118728.setter_put (callExtensionGetter_lstring ((const cPtr_gtlData *) var_keyValue_118956.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3810)), enumerator_118759.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3809)) ;
                              }
                            }
                          }
                          if (kBoolFalse == test_16) {
                            TC_Array <C_FixItDescription> fixItArray17 ;
                            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("item at index ").add_operation (index_118754.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 3814)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3814)).add_operation (GALGAS_string (" does not have field named "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3814)).add_operation (var_key_118670.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3815)), fixItArray17  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3814)) ;
                          }
                        }else if (enumerator_118759.current_value (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlMap) {
                          GALGAS_gtlMap cast_119206_itemMap ((cPtr_gtlMap *) enumerator_118759.current_value (HERE).ptr ()) ;
                          enumGalgasBool test_18 = kBoolTrue ;
                          if (kBoolTrue == test_18) {
                            test_18 = cast_119206_itemMap.readProperty_value ().getter_hasKey (var_key_118670.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3818)).boolEnum () ;
                            if (kBoolTrue == test_18) {
                              GALGAS_gtlData var_keyValue_119320 ;
                              cast_119206_itemMap.readProperty_value ().method_get (var_key_118670, var_keyValue_119320, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3819)) ;
                              {
                              var_resultMap_118728.setter_put (callExtensionGetter_lstring ((const cPtr_gtlData *) var_keyValue_119320.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3821)), enumerator_118759.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3820)) ;
                              }
                            }
                          }
                          if (kBoolFalse == test_18) {
                            TC_Array <C_FixItDescription> fixItArray19 ;
                            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("item at index ").add_operation (index_118754.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 3825)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3825)).add_operation (GALGAS_string (" does not have field named "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3825)).add_operation (var_key_118670.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3826)), fixItArray19  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3825)) ;
                          }
                        }else{
                          TC_Array <C_FixItDescription> fixItArray20 ;
                          inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("list of struct expected"), fixItArray20  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3829)) ;
                        }
                      }
                      enumerator_118759.gotoNextObject () ;
                      index_118754.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3804)) ;
                    }
                    result_result = GALGAS_gtlMap::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3832)), var_resultMap_118728  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3832)) ;
                  }
                }
                if (kBoolFalse == test_14) {
                  enumGalgasBool test_21 = kBoolTrue ;
                  if (kBoolTrue == test_21) {
                    test_21 = GALGAS_bool (kIsEqual, GALGAS_string ("set").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                    if (kBoolTrue == test_21) {
                      {
                      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3834)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3834)) ;
                      }
                      GALGAS_lstringset var_resultSet_119818 = GALGAS_lstringset::class_func_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 3835)) ;
                      cEnumerator_list enumerator_119849 (this->mProperty_value, kENUMERATION_UP) ;
                      while (enumerator_119849.hasCurrentObject ()) {
                        GALGAS_lstring var_itemKey_119886 = callExtensionGetter_lstring ((const cPtr_gtlData *) enumerator_119849.current_value (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3837)) ;
                        enumGalgasBool test_22 = kBoolTrue ;
                        if (kBoolTrue == test_22) {
                          test_22 = var_resultSet_119818.getter_hasKey (var_itemKey_119886.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3838)).boolEnum () ;
                          if (kBoolTrue == test_22) {
                            {
                            var_resultSet_119818.setter_del (var_itemKey_119886, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3839)) ;
                            }
                          }
                        }
                        {
                        var_resultSet_119818.setter_put (var_itemKey_119886, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3841)) ;
                        }
                        enumerator_119849.gotoNextObject () ;
                      }
                      result_result = GALGAS_gtlSet::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3844)), var_resultSet_119818  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3843)) ;
                    }
                  }
                  if (kBoolFalse == test_21) {
                    enumGalgasBool test_23 = kBoolTrue ;
                    if (kBoolTrue == test_23) {
                      test_23 = GALGAS_bool (kIsEqual, GALGAS_string ("setBy").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                      if (kBoolTrue == test_23) {
                        {
                        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3847)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3847)) ;
                        }
                        GALGAS_lstring var_key_120249 = callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3848)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3848)) ;
                        GALGAS_lstringset var_resultSet_120308 = GALGAS_lstringset::class_func_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 3849)) ;
                        cEnumerator_list enumerator_120339 (this->mProperty_value, kENUMERATION_UP) ;
                        while (enumerator_120339.hasCurrentObject ()) {
                          GALGAS_gtlData var_field_120400 ;
                          GALGAS_bool joker_120406 ; // Joker input parameter
                          callExtensionMethod_structField ((cPtr_gtlData *) enumerator_120339.current_value (HERE).ptr (), var_key_120249, var_field_120400, joker_120406, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3851)) ;
                          GALGAS_lstring var_resKey_120429 = callExtensionGetter_lstring ((const cPtr_gtlData *) var_field_120400.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3852)) ;
                          enumGalgasBool test_24 = kBoolTrue ;
                          if (kBoolTrue == test_24) {
                            test_24 = var_resultSet_120308.getter_hasKey (var_resKey_120429.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3853)).boolEnum () ;
                            if (kBoolTrue == test_24) {
                              {
                              var_resultSet_120308.setter_del (var_resKey_120429, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3854)) ;
                              }
                            }
                          }
                          {
                          var_resultSet_120308.setter_put (var_resKey_120429, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3856)) ;
                          }
                          enumerator_120339.gotoNextObject () ;
                        }
                        result_result = GALGAS_gtlSet::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3859)), var_resultSet_120308  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3858)) ;
                      }
                    }
                    if (kBoolFalse == test_23) {
                      enumGalgasBool test_25 = kBoolTrue ;
                      if (kBoolTrue == test_25) {
                        test_25 = GALGAS_bool (kIsEqual, GALGAS_string ("componentsJoinedByString").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                        if (kBoolTrue == test_25) {
                          {
                          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3862)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3862)) ;
                          }
                          GALGAS_string var_joiner_120788 = callExtensionGetter_string ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3863)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3863)) ;
                          GALGAS_string var_stringResult_120845 = GALGAS_string::makeEmptyString () ;
                          cEnumerator_list enumerator_120872 (this->mProperty_value, kENUMERATION_UP) ;
                          while (enumerator_120872.hasCurrentObject ()) {
                            var_stringResult_120845 = var_stringResult_120845.add_operation (callExtensionGetter_string ((const cPtr_gtlData *) enumerator_120872.current_value (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3867)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3867)) ;
                            if (enumerator_120872.hasNextObject ()) {
                              var_stringResult_120845 = var_stringResult_120845.add_operation (var_joiner_120788, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3869)) ;
                            }
                            enumerator_120872.gotoNextObject () ;
                          }
                          result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3872)), var_stringResult_120845  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3871)) ;
                        }
                      }
                      if (kBoolFalse == test_25) {
                        enumGalgasBool test_26 = kBoolTrue ;
                        if (kBoolTrue == test_26) {
                          test_26 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                          if (kBoolTrue == test_26) {
                            {
                            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3875)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3875)) ;
                            }
                            const GALGAS_gtlList temp_27 = this ;
                            result_result = GALGAS_gtlType::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3877)), temp_27.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 3877))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3876)) ;
                          }
                        }
                        if (kBoolFalse == test_26) {
                          enumGalgasBool test_28 = kBoolTrue ;
                          if (kBoolTrue == test_28) {
                            test_28 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                            if (kBoolTrue == test_28) {
                              {
                              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3880)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3880)) ;
                              }
                              result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3882)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3881)) ;
                            }
                          }
                          if (kBoolFalse == test_28) {
                            enumGalgasBool test_29 = kBoolTrue ;
                            if (kBoolTrue == test_29) {
                              test_29 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                              if (kBoolTrue == test_29) {
                                {
                                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3885)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3885)) ;
                                }
                                result_result = GALGAS_gtlString::class_func_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3887)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3886)) ;
                              }
                            }
                            if (kBoolFalse == test_29) {
                              enumGalgasBool test_30 = kBoolTrue ;
                              if (kBoolTrue == test_30) {
                                test_30 = GALGAS_bool (kIsEqual, GALGAS_string ("where").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                if (kBoolTrue == test_30) {
                                  enumGalgasBool test_31 = kBoolTrue ;
                                  if (kBoolTrue == test_31) {
                                    test_31 = GALGAS_bool (kIsStrictInf, constinArgument_arguments.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3890)).objectCompare (GALGAS_uint (uint32_t (1U)))).operator_or (GALGAS_bool (kIsStrictSup, constinArgument_arguments.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3890)).objectCompare (GALGAS_uint (uint32_t (2U)))) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3890)).boolEnum () ;
                                    if (kBoolTrue == test_31) {
                                      TC_Array <C_FixItDescription> fixItArray32 ;
                                      inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("where expects 1 ou 2 arguments. ").add_operation (constinArgument_arguments.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3892)).getter_string (SOURCE_FILE ("gtl_data_types.galgas", 3891)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3891)).add_operation (GALGAS_string (" arguments provided."), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3892)), fixItArray32  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3891)) ;
                                      result_result.drop () ; // Release error dropped variable
                                    }
                                  }
                                  if (kBoolFalse == test_31) {
                                    enumGalgasBool test_33 = kBoolTrue ;
                                    if (kBoolTrue == test_33) {
                                      test_33 = GALGAS_bool (kIsNotEqual, constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3894)).getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 3894)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlExpr))).boolEnum () ;
                                      if (kBoolTrue == test_33) {
                                        TC_Array <C_FixItDescription> fixItArray34 ;
                                        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("expression expected for argument 1"), fixItArray34  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3895)) ;
                                        result_result.drop () ; // Release error dropped variable
                                      }
                                    }
                                    if (kBoolFalse == test_33) {
                                      GALGAS_gtlStruct var_vars_122075 ;
                                      enumGalgasBool test_35 = kBoolTrue ;
                                      if (kBoolTrue == test_35) {
                                        test_35 = GALGAS_bool (kIsEqual, constinArgument_arguments.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3898)).objectCompare (GALGAS_uint (uint32_t (2U)))).boolEnum () ;
                                        if (kBoolTrue == test_35) {
                                          enumGalgasBool test_36 = kBoolTrue ;
                                          if (kBoolTrue == test_36) {
                                            test_36 = GALGAS_bool (kIsNotEqual, constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3899)).getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 3899)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct))).boolEnum () ;
                                            if (kBoolTrue == test_36) {
                                              TC_Array <C_FixItDescription> fixItArray37 ;
                                              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("struct expected for argument 1"), fixItArray37  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3900)) ;
                                              var_vars_122075.drop () ; // Release error dropped variable
                                            }
                                          }
                                          if (kBoolFalse == test_36) {
                                            GALGAS_gtlStruct temp_38 ;
                                            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3902)).isValid ()) {
                                              if (nullptr != dynamic_cast <const cPtr_gtlStruct *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3902)).ptr ())) {
                                                temp_38 = (cPtr_gtlStruct *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3902)).ptr () ;
                                              }else{
                                                inCompiler->castError ("gtlStruct", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3902)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3902)) ;
                                              }
                                            }
                                            var_vars_122075 = temp_38 ;
                                          }
                                        }
                                      }
                                      if (kBoolFalse == test_35) {
                                        var_vars_122075 = GALGAS_gtlStruct::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3905)), GALGAS_gtlVarMap::class_func_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 3905))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3905)) ;
                                      }
                                      GALGAS_gtlExpr temp_39 ;
                                      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3907)).isValid ()) {
                                        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3907)).ptr ())) {
                                          temp_39 = (cPtr_gtlExpr *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3907)).ptr () ;
                                        }else{
                                          inCompiler->castError ("gtlExpr", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3907)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3907)) ;
                                        }
                                      }
                                      GALGAS_gtlExpression var_expr_122466 = temp_39.readProperty_value () ;
                                      GALGAS_list var_resultList_122534 = GALGAS_list::class_func_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 3908)) ;
                                      cEnumerator_list enumerator_122571 (this->mProperty_value, kENUMERATION_UP) ;
                                      while (enumerator_122571.hasCurrentObject ()) {
                                        {
                                        var_vars_122075.insulate (HERE) ;
                                        cPtr_gtlStruct * ptr_122610 = (cPtr_gtlStruct *) var_vars_122075.ptr () ;
                                        callExtensionSetter_setStructField ((cPtr_gtlStruct *) ptr_122610, GALGAS_lstring::class_func_new (GALGAS_string ("__item__"), enumerator_122571.current_value (HERE).readProperty_where (), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3911)), enumerator_122571.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3911)) ;
                                        }
                                        GALGAS_gtlData var_evalResult_122702 = callExtensionGetter_eval ((const cPtr_gtlExpression *) var_expr_122466.ptr (), constinArgument_context, var_vars_122075, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3912)) ;
                                        enumGalgasBool test_40 = kBoolTrue ;
                                        if (kBoolTrue == test_40) {
                                          test_40 = callExtensionGetter_bool ((const cPtr_gtlData *) var_evalResult_122702.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3913)).boolEnum () ;
                                          if (kBoolTrue == test_40) {
                                            var_resultList_122534.addAssign_operation (enumerator_122571.current_value (HERE)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3914)) ;
                                          }
                                        }
                                        enumerator_122571.gotoNextObject () ;
                                      }
                                      result_result = GALGAS_gtlList::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3919)), var_resultList_122534  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3917)) ;
                                    }
                                  }
                                }
                              }
                              if (kBoolFalse == test_30) {
                                enumGalgasBool test_41 = kBoolTrue ;
                                if (kBoolTrue == test_41) {
                                  test_41 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("list"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3924)).boolEnum () ;
                                  if (kBoolTrue == test_41) {
                                    const GALGAS_gtlList temp_42 = this ;
                                    result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("list"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3925)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_42, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3925)) ;
                                  }
                                }
                                if (kBoolFalse == test_41) {
                                  enumGalgasBool test_43 = kBoolTrue ;
                                  if (kBoolTrue == test_43) {
                                    test_43 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                    if (kBoolTrue == test_43) {
                                      {
                                      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3933)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3933)) ;
                                      }
                                      result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3935)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3935))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3934)) ;
                                    }
                                  }
                                  if (kBoolFalse == test_43) {
                                    TC_Array <C_FixItDescription> fixItArray44 ;
                                    inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3938)).add_operation (GALGAS_string ("' for list target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3938)), fixItArray44  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3938)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlList performSetter'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlList_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlList * object = (cPtr_gtlList *) inObject ;
  macroValidSharedObject (object, cPtr_gtlList) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3953)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3953)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3954)).isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3954)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3954)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3954)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3954)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_123950 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_123950.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3955)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3955)) ;
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
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3958)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3958)) ;
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
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_intAnyArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3961)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3961)) ;
          }
          GALGAS_uint var_insertIndex_124310 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3962)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3962)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3962)) ;
          GALGAS_gtlData var_node_124374 = constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3963)) ;
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsStrictInf, var_insertIndex_124310.objectCompare (object->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3964)))).boolEnum () ;
            if (kBoolTrue == test_4) {
              {
              object->mProperty_value.setter_insertAtIndex (var_node_124374, var_insertIndex_124310, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3965)) ;
              }
            }
          }
          if (kBoolFalse == test_4) {
            object->mProperty_value.addAssign_operation (var_node_124374  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3967)) ;
          }
          object->mProperty_where = constinArgument_methodName.readProperty_location () ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_5 = kBoolTrue ;
        if (kBoolTrue == test_5) {
          test_5 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("list"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3970)).boolEnum () ;
          if (kBoolTrue == test_5) {
            const GALGAS_gtlList temp_6 = object ;
            GALGAS_gtlData var_copy_124624 = temp_6 ;
            callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("list"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3972)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_124624, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3972)) ;
            GALGAS_gtlList temp_7 ;
            if (var_copy_124624.isValid ()) {
              if (nullptr != dynamic_cast <const cPtr_gtlList *> (var_copy_124624.ptr ())) {
                temp_7 = (cPtr_gtlList *) var_copy_124624.ptr () ;
              }else{
                inCompiler->castError ("gtlList", var_copy_124624.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3979)) ;
              }
            }
            object->mProperty_value = temp_7.readProperty_value () ;
            object->mProperty_where = var_copy_124624.readProperty_where () ;
            object->mProperty_meta = var_copy_124624.readProperty_meta () ;
          }
        }
        if (kBoolFalse == test_5) {
          TC_Array <C_FixItDescription> fixItArray8 ;
          inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3983)).add_operation (GALGAS_string ("' for list target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3983)), fixItArray8  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3983)) ;
        }
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlList_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlList.mSlotID,
                                      extensionSetter_gtlList_performSetter) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlList_performSetter (defineExtensionSetter_gtlList_performSetter, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlList setItemAtIndex'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlList_setItemAtIndex (cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_data,
                                                    const GALGAS_gtlInt constinArgument_index,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlList * object = (cPtr_gtlList *) inObject ;
  macroValidSharedObject (object, cPtr_gtlList) ;
  {
  object->mProperty_value.setter_setValueAtIndex (constinArgument_data, constinArgument_index.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3991)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3991)) ;
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlList_setItemAtIndex (void) {
  enterExtensionSetter_setItemAtIndex (kTypeDescriptor_GALGAS_gtlList.mSlotID,
                                       extensionSetter_gtlList_setItemAtIndex) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlList_setItemAtIndex (defineExtensionSetter_gtlList_setItemAtIndex, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlList deleteItemAtIndex'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlList_deleteItemAtIndex (cPtr_gtlData * inObject,
                                                       const GALGAS_gtlInt constinArgument_index,
                                                       Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlList * object = (cPtr_gtlList *) inObject ;
  macroValidSharedObject (object, cPtr_gtlList) ;
  GALGAS_uint var_indexUint_125180 = constinArgument_index.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3997)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictInf, var_indexUint_125180.objectCompare (object->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3998)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, var_indexUint_125180.objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          object->mProperty_value = object->mProperty_value.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4000)) ;
        }
      }
      if (kBoolFalse == test_1) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = GALGAS_bool (kIsEqual, var_indexUint_125180.objectCompare (object->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4001)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4001)))).boolEnum () ;
          if (kBoolTrue == test_2) {
            object->mProperty_value = object->mProperty_value.getter_subListToIndex (var_indexUint_125180.substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4002)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4002)) ;
          }
        }
        if (kBoolFalse == test_2) {
          object->mProperty_value = object->mProperty_value.getter_subListToIndex (var_indexUint_125180.substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4004)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4004)).add_operation (object->mProperty_value.getter_subListFromIndex (var_indexUint_125180.add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4005)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4005)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4004)) ;
        }
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlList_deleteItemAtIndex (void) {
  enterExtensionSetter_deleteItemAtIndex (kTypeDescriptor_GALGAS_gtlList.mSlotID,
                                          extensionSetter_gtlList_deleteItemAtIndex) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlList_deleteItemAtIndex (defineExtensionSetter_gtlList_deleteItemAtIndex, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlList itemAtIndex'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlList::method_itemAtIndex (GALGAS_gtlData & outArgument_data,
                                       const GALGAS_gtlInt constinArgument_index,
                                       Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_data = this->mProperty_value.getter_valueAtIndex (constinArgument_index.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4014)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4014)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList hasItemAtIndex'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlList::getter_hasItemAtIndex (const GALGAS_gtlInt constinArgument_index,
                                                 Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (kIsStrictSup, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4021)).objectCompare (constinArgument_index.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4021)))) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlList appendItem'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlList_appendItem (cPtr_gtlData * inObject,
                                                const GALGAS_gtlData constinArgument_item,
                                                Compiler * /* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlList * object = (cPtr_gtlList *) inObject ;
  macroValidSharedObject (object, cPtr_gtlList) ;
  object->mProperty_value.addAssign_operation (constinArgument_item  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4027)) ;
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlList_appendItem (void) {
  enterExtensionSetter_appendItem (kTypeDescriptor_GALGAS_gtlList.mSlotID,
                                   extensionSetter_gtlList_appendItem) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlList_appendItem (defineExtensionSetter_gtlList_appendItem, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap desc'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlMap::getter_desc (const GALGAS_uint constinArgument_tab,
                                        Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4039)).add_operation (GALGAS_string ("map: @[\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4039)) ;
  cEnumerator_gtlVarMap enumerator_126297 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_126297.hasCurrentObject ()) {
    result_result.plusAssign_operation(GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4042))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4042)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4042)).add_operation (enumerator_126297.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4043)).add_operation (GALGAS_string ("\" :>\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4043)).add_operation (callExtensionGetter_desc ((const cPtr_gtlData *) enumerator_126297.current_value (HERE).ptr (), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (8U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4044)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4044)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4043)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4042)) ;
    enumerator_126297.gotoNextObject () ;
  }
  result_result.plusAssign_operation(GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4046)).add_operation (GALGAS_string ("]\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4046)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4046)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlMap::getter_string (Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4050)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap lstring'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlMap::getter_lstring (Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4054)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap bool'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlMap::getter_bool (Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a map to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4058)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap int'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlMap::getter_int (Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a map to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4062)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap float'
//
//--------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlMap::getter_float (Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a map to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4066)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap plusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_plusOp (Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4070)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap minusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_minusOp (Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4074)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap notOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_notOp (Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4078)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap addOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4082)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap subOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4086)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap mulOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4090)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap divOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4094)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap modOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4098)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap andOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4102)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap orOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4106)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap xorOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4110)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap slOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4114)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap srOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4118)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap neqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlMap).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlMap temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlMap *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlMap *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlMap", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4123)) ;
        }
      }
      GALGAS_gtlVarMap var_rValue_128675 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_128719 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4125)).objectCompare (var_rValue_128675.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4125)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_128719 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_128719 = GALGAS_bool (true) ;
        cEnumerator_gtlVarMap enumerator_128833 (this->mProperty_value, kENUMERATION_UP) ;
        while (enumerator_128833.hasCurrentObject ()) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = var_rValue_128675.getter_hasKey (enumerator_128833.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4130)).boolEnum () ;
            if (kBoolTrue == test_3) {
              GALGAS_gtlData var_rData_128933 ;
              var_rValue_128675.method_get (enumerator_128833.current_lkey (HERE), var_rData_128933, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4131)) ;
              var_equal_128719 = var_equal_128719.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_128833.current_value (HERE).ptr (), var_rData_128933, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4132)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4132)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4132)) ;
            }
          }
          if (kBoolFalse == test_3) {
            var_equal_128719 = GALGAS_bool (false) ;
          }
          enumerator_128833.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4138)), var_equal_128719.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 4138))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4138)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("struct expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4140)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap eqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlMap).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlMap temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlMap *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlMap *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlMap", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4146)) ;
        }
      }
      GALGAS_gtlVarMap var_rValue_129306 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_129350 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4148)).objectCompare (var_rValue_129306.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4148)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_129350 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_129350 = GALGAS_bool (true) ;
        cEnumerator_gtlVarMap enumerator_129464 (this->mProperty_value, kENUMERATION_UP) ;
        while (enumerator_129464.hasCurrentObject ()) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = var_rValue_129306.getter_hasKey (enumerator_129464.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4153)).boolEnum () ;
            if (kBoolTrue == test_3) {
              GALGAS_gtlData var_rData_129564 ;
              var_rValue_129306.method_get (enumerator_129464.current_lkey (HERE), var_rData_129564, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4154)) ;
              var_equal_129350 = var_equal_129350.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_129464.current_value (HERE).ptr (), var_rData_129564, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4155)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4155)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4155)) ;
            }
          }
          if (kBoolFalse == test_3) {
            var_equal_129350 = GALGAS_bool (false) ;
          }
          enumerator_129464.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4161)), var_equal_129350  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4161)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("struct expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4163)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap gtOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_gtOp (const GALGAS_gtlData /* constinArgument_right */,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a map does not support the > operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4168)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap geOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_geOp (const GALGAS_gtlData /* constinArgument_right */,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a map does not support the >= operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4172)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap ltOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_ltOp (const GALGAS_gtlData /* constinArgument_right */,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a map does not support the < operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4176)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap leOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_leOp (const GALGAS_gtlData /* constinArgument_right */,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a map does not support the <= operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4180)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap embeddedType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlMap::getter_embeddedType (Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4185)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlMap addMyValue'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlMap::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                     Compiler * /* inCompiler */
                                     COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 4190))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4190)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap performGetter'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                  const GALGAS_gtlDataList constinArgument_arguments,
                                                  const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_library constinArgument_lib,
                                                  Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("length").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4204)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4204)) ;
      }
      result_result = GALGAS_gtlInt::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4207)), this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4208)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 4208))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4205)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4211)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4211)) ;
        }
        const GALGAS_gtlMap temp_2 = this ;
        result_result = GALGAS_gtlType::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4213)), temp_2.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 4213))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4212)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4216)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4216)) ;
          }
          result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4218)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4217)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("list").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4221)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4221)) ;
            }
            GALGAS_list var_resultList_131728 = GALGAS_list::class_func_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 4222)) ;
            const GALGAS_gtlMap temp_5 = this ;
            cEnumerator_gtlVarMap enumerator_131772 (temp_5.readProperty_value (), kENUMERATION_UP) ;
            while (enumerator_131772.hasCurrentObject ()) {
              var_resultList_131728.addAssign_operation (enumerator_131772.current_value (HERE)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4224)) ;
              enumerator_131772.gotoNextObject () ;
            }
            result_result = GALGAS_gtlList::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4226)), var_resultList_131728  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4226)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_6 = kBoolTrue ;
          if (kBoolTrue == test_6) {
            test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("where").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_6) {
              enumGalgasBool test_7 = kBoolTrue ;
              if (kBoolTrue == test_7) {
                test_7 = GALGAS_bool (kIsStrictInf, constinArgument_arguments.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4228)).objectCompare (GALGAS_uint (uint32_t (1U)))).operator_or (GALGAS_bool (kIsStrictSup, constinArgument_arguments.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4228)).objectCompare (GALGAS_uint (uint32_t (2U)))) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4228)).boolEnum () ;
                if (kBoolTrue == test_7) {
                  TC_Array <C_FixItDescription> fixItArray8 ;
                  inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("where expects 1 ou 2 arguments. ").add_operation (constinArgument_arguments.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4230)).getter_string (SOURCE_FILE ("gtl_data_types.galgas", 4229)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4229)).add_operation (GALGAS_string (" arguments provided."), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4230)), fixItArray8  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4229)) ;
                  result_result.drop () ; // Release error dropped variable
                }
              }
              if (kBoolFalse == test_7) {
                enumGalgasBool test_9 = kBoolTrue ;
                if (kBoolTrue == test_9) {
                  test_9 = GALGAS_bool (kIsNotEqual, constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4232)).getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 4232)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlExpr))).boolEnum () ;
                  if (kBoolTrue == test_9) {
                    TC_Array <C_FixItDescription> fixItArray10 ;
                    inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("expression expected for argument 1"), fixItArray10  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4233)) ;
                    result_result.drop () ; // Release error dropped variable
                  }
                }
                if (kBoolFalse == test_9) {
                  GALGAS_gtlStruct var_vars_132311 ;
                  enumGalgasBool test_11 = kBoolTrue ;
                  if (kBoolTrue == test_11) {
                    test_11 = GALGAS_bool (kIsEqual, constinArgument_arguments.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4236)).objectCompare (GALGAS_uint (uint32_t (2U)))).boolEnum () ;
                    if (kBoolTrue == test_11) {
                      enumGalgasBool test_12 = kBoolTrue ;
                      if (kBoolTrue == test_12) {
                        test_12 = GALGAS_bool (kIsNotEqual, constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4237)).getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 4237)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct))).boolEnum () ;
                        if (kBoolTrue == test_12) {
                          TC_Array <C_FixItDescription> fixItArray13 ;
                          inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("struct expected for argument 1"), fixItArray13  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4238)) ;
                          var_vars_132311.drop () ; // Release error dropped variable
                        }
                      }
                      if (kBoolFalse == test_12) {
                        GALGAS_gtlStruct temp_14 ;
                        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4240)).isValid ()) {
                          if (nullptr != dynamic_cast <const cPtr_gtlStruct *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4240)).ptr ())) {
                            temp_14 = (cPtr_gtlStruct *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4240)).ptr () ;
                          }else{
                            inCompiler->castError ("gtlStruct", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4240)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4240)) ;
                          }
                        }
                        var_vars_132311 = temp_14 ;
                      }
                    }
                  }
                  if (kBoolFalse == test_11) {
                    var_vars_132311 = GALGAS_gtlStruct::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4243)), GALGAS_gtlVarMap::class_func_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 4243))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4243)) ;
                  }
                  GALGAS_gtlExpr temp_15 ;
                  if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4245)).isValid ()) {
                    if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4245)).ptr ())) {
                      temp_15 = (cPtr_gtlExpr *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4245)).ptr () ;
                    }else{
                      inCompiler->castError ("gtlExpr", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4245)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4245)) ;
                    }
                  }
                  GALGAS_gtlExpression var_expr_132702 = temp_15.readProperty_value () ;
                  GALGAS_gtlVarMap var_resultMap_132775 = GALGAS_gtlVarMap::class_func_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 4246)) ;
                  cEnumerator_gtlVarMap enumerator_132814 (this->mProperty_value, kENUMERATION_UP) ;
                  while (enumerator_132814.hasCurrentObject ()) {
                    {
                    var_vars_132311.insulate (HERE) ;
                    cPtr_gtlStruct * ptr_132853 = (cPtr_gtlStruct *) var_vars_132311.ptr () ;
                    callExtensionSetter_setStructField ((cPtr_gtlStruct *) ptr_132853, GALGAS_lstring::class_func_new (GALGAS_string ("__item__"), enumerator_132814.current_value (HERE).readProperty_where (), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4249)), enumerator_132814.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4249)) ;
                    }
                    GALGAS_gtlData var_evalResult_132945 = callExtensionGetter_eval ((const cPtr_gtlExpression *) var_expr_132702.ptr (), constinArgument_context, var_vars_132311, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4250)) ;
                    enumGalgasBool test_16 = kBoolTrue ;
                    if (kBoolTrue == test_16) {
                      test_16 = callExtensionGetter_bool ((const cPtr_gtlData *) var_evalResult_132945.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4251)).boolEnum () ;
                      if (kBoolTrue == test_16) {
                        {
                        var_resultMap_132775.setter_put (enumerator_132814.current_lkey (HERE), enumerator_132814.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4252)) ;
                        }
                      }
                    }
                    enumerator_132814.gotoNextObject () ;
                  }
                  result_result = GALGAS_gtlMap::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4257)), var_resultMap_132775  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4255)) ;
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
                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4263)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4263)) ;
                }
                result_result = GALGAS_gtlString::class_func_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4265)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4264)) ;
              }
            }
            if (kBoolFalse == test_17) {
              enumGalgasBool test_18 = kBoolTrue ;
              if (kBoolTrue == test_18) {
                test_18 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("map"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4267)).boolEnum () ;
                if (kBoolTrue == test_18) {
                  const GALGAS_gtlMap temp_19 = this ;
                  result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("map"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4268)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_19, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4268)) ;
                }
              }
              if (kBoolFalse == test_18) {
                enumGalgasBool test_20 = kBoolTrue ;
                if (kBoolTrue == test_20) {
                  test_20 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_20) {
                    {
                    routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4276)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4276)) ;
                    }
                    result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4278)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4278))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4277)) ;
                  }
                }
                if (kBoolFalse == test_20) {
                  TC_Array <C_FixItDescription> fixItArray21 ;
                  inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4281)).add_operation (GALGAS_string ("' for map target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4281)), fixItArray21  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4281)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlMap performSetter'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlMap_performSetter (cPtr_gtlData * inObject,
                                                  const GALGAS_lstring constinArgument_methodName,
                                                  const GALGAS_gtlDataList constinArgument_arguments,
                                                  const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_library constinArgument_lib,
                                                  Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlMap * object = (cPtr_gtlMap *) inObject ;
  macroValidSharedObject (object, cPtr_gtlMap) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4296)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4296)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4297)).isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4297)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4297)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4297)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4297)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_134363 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_134363.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4298)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4298)) ;
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
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4301)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4301)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("map"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4303)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlMap temp_4 = object ;
          GALGAS_gtlData var_copy_134670 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("map"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4305)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_134670, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4305)) ;
          GALGAS_gtlMap temp_5 ;
          if (var_copy_134670.isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlMap *> (var_copy_134670.ptr ())) {
              temp_5 = (cPtr_gtlMap *) var_copy_134670.ptr () ;
            }else{
              inCompiler->castError ("gtlMap", var_copy_134670.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4312)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_134670.readProperty_where () ;
          object->mProperty_meta = var_copy_134670.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4316)).add_operation (GALGAS_string ("' for map target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4316)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4316)) ;
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlMap_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlMap.mSlotID,
                                      extensionSetter_gtlMap_performSetter) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlMap_performSetter (defineExtensionSetter_gtlMap_performSetter, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlMap setMapItem'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlMap_setMapItem (cPtr_gtlData * inObject,
                                               const GALGAS_lstring constinArgument_name,
                                               const GALGAS_gtlData constinArgument_data,
                                               Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlMap * object = (cPtr_gtlMap *) inObject ;
  macroValidSharedObject (object, cPtr_gtlMap) ;
  {
  extensionSetter_replaceOrCreate (object->mProperty_value, constinArgument_name, constinArgument_data, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4327)) ;
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlMap_setMapItem (void) {
  enterExtensionSetter_setMapItem (kTypeDescriptor_GALGAS_gtlMap.mSlotID,
                                   extensionSetter_gtlMap_setMapItem) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlMap_setMapItem (defineExtensionSetter_gtlMap_setMapItem, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlMap deleteMapItem'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlMap_deleteMapItem (cPtr_gtlData * inObject,
                                                  const GALGAS_lstring constinArgument_name,
                                                  Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlMap * object = (cPtr_gtlMap *) inObject ;
  macroValidSharedObject (object, cPtr_gtlMap) ;
  {
  GALGAS_gtlData joker_135390 ; // Joker input parameter
  object->mProperty_value.setter_del (constinArgument_name, joker_135390, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4333)) ;
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlMap_deleteMapItem (void) {
  enterExtensionSetter_deleteMapItem (kTypeDescriptor_GALGAS_gtlMap.mSlotID,
                                      extensionSetter_gtlMap_deleteMapItem) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlMap_deleteMapItem (defineExtensionSetter_gtlMap_deleteMapItem, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlMap mapItem'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlMap::method_mapItem (const GALGAS_lstring constinArgument_name,
                                  GALGAS_gtlData & outArgument_result,
                                  Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_value.getter_hasKey (constinArgument_name.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4340)).boolEnum () ;
    if (kBoolTrue == test_0) {
      this->mProperty_value.method_get (constinArgument_name, outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4341)) ;
    }
  }
  if (kBoolFalse == test_0) {
    outArgument_result = GALGAS_gtlUnconstructed::class_func_new (constinArgument_name.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4343))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4343)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap hasMapItem'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlMap::getter_hasMapItem (const GALGAS_lstring constinArgument_name,
                                            Compiler */* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = this->mProperty_value.getter_hasKey (constinArgument_name.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4351)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr desc'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlExpr::getter_desc (const GALGAS_uint constinArgument_tab,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4363)).add_operation (GALGAS_string ("expression: @\? "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4363)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_value.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4364)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4364)).add_operation (GALGAS_string (" \?\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4364)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlExpr::getter_string (Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("expression forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4368)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr lstring'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlExpr::getter_lstring (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("expression forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4372)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr bool'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlExpr::getter_bool (Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an expression to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4376)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr int'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlExpr::getter_int (Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an expression to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4380)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr float'
//
//--------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlExpr::getter_float (Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an expression to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4384)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr plusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_plusOp (Compiler */* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  const GALGAS_gtlExpr temp_0 = this ;
  result_result = temp_0 ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr minusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_minusOp (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4394)), GALGAS_gtlMinusExpression::class_func_new (this->mProperty_where, this->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4395))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4392)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr notOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_notOp (Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4402)), GALGAS_gtlNotExpression::class_func_new (this->mProperty_where, this->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4403))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4400)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr addOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_addOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4412)) ;
        }
      }
      result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4411)), GALGAS_gtlAddExpression::class_func_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4412))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4409)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr subOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_subOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4424)) ;
        }
      }
      result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4423)), GALGAS_gtlSubstractExpression::class_func_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4424))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4421)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr mulOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_mulOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4436)) ;
        }
      }
      result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4435)), GALGAS_gtlMultiplyExpression::class_func_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4436))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4433)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr divOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_divOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4448)) ;
        }
      }
      result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4447)), GALGAS_gtlDivideExpression::class_func_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4448))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4445)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr modOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_modOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4460)) ;
        }
      }
      result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4459)), GALGAS_gtlModulusExpression::class_func_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4460))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4457)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr andOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_andOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4472)) ;
        }
      }
      result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4471)), GALGAS_gtlAndExpression::class_func_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4472))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4469)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr orOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_orOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4484)) ;
        }
      }
      result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4483)), GALGAS_gtlOrExpression::class_func_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4484))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4481)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr xorOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_xorOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4496)) ;
        }
      }
      result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4495)), GALGAS_gtlXorExpression::class_func_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4496))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4493)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr slOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_slOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4508)) ;
        }
      }
      result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4507)), GALGAS_gtlShiftLeftExpression::class_func_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4508))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4505)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr srOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_srOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4520)) ;
        }
      }
      result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4519)), GALGAS_gtlShiftRightExpression::class_func_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4520))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4517)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr neqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4532)) ;
        }
      }
      result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4531)), GALGAS_gtlNotEqualExpression::class_func_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4532))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4529)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr eqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4544)) ;
        }
      }
      result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4543)), GALGAS_gtlEqualExpression::class_func_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4544))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4541)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr gtOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4556)) ;
        }
      }
      result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4555)), GALGAS_gtlGreaterThanExpression::class_func_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4556))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4553)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr geOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4568)) ;
        }
      }
      result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4567)), GALGAS_gtlGreaterOrEqualExpression::class_func_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4568))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4565)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr ltOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4580)) ;
        }
      }
      result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4579)), GALGAS_gtlLowerThanExpression::class_func_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4580))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4577)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr leOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4592)) ;
        }
      }
      result_result = GALGAS_gtlExpr::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4591)), GALGAS_gtlLowerOrEqualExpression::class_func_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4592))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4589)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4595)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr embeddedType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlExpr::getter_embeddedType (Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("expression forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4601)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlExpr addMyValue'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlExpr::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                      Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 4606))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4606)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr performGetter'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("eval"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_structArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4620)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4620)) ;
      }
      GALGAS_gtlData var_vars_143038 = constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4621)) ;
      result_result = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_value.ptr (), constinArgument_context, var_vars_143038, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4622)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4624)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4624)) ;
        }
        const GALGAS_gtlExpr temp_2 = this ;
        result_result = GALGAS_gtlType::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4626)), temp_2.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 4626))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4625)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4629)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4629)) ;
          }
          result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4631)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4630)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4634)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4634)) ;
            }
            result_result = GALGAS_gtlString::class_func_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4636)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4635)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_5) {
              {
              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4639)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4639)) ;
              }
              result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4641)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4641))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4640)) ;
            }
          }
          if (kBoolFalse == test_5) {
            enumGalgasBool test_6 = kBoolTrue ;
            if (kBoolTrue == test_6) {
              test_6 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("expression"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4643)).boolEnum () ;
              if (kBoolTrue == test_6) {
                const GALGAS_gtlExpr temp_7 = this ;
                result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("expression"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4644)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_7, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4644)) ;
              }
            }
            if (kBoolFalse == test_6) {
              TC_Array <C_FixItDescription> fixItArray8 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4652)).add_operation (GALGAS_string ("' for expression target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4652)), fixItArray8  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4652)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlExpr performSetter'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlExpr_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlExpr * object = (cPtr_gtlExpr *) inObject ;
  macroValidSharedObject (object, cPtr_gtlExpr) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4667)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4667)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4668)).isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4668)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4668)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4668)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4668)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_144674 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_144674.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4669)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4669)) ;
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
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4672)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4672)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("expression"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4674)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlExpr temp_4 = object ;
          GALGAS_gtlData var_copy_144988 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("expression"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4676)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_144988, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4676)) ;
          GALGAS_gtlExpr temp_5 ;
          if (var_copy_144988.isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlExpr *> (var_copy_144988.ptr ())) {
              temp_5 = (cPtr_gtlExpr *) var_copy_144988.ptr () ;
            }else{
              inCompiler->castError ("gtlExpr", var_copy_144988.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4683)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_144988.readProperty_where () ;
          object->mProperty_meta = var_copy_144988.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4687)).add_operation (GALGAS_string ("' for expression target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4687)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4687)) ;
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlExpr_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlExpr.mSlotID,
                                      extensionSetter_gtlExpr_performSetter) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlExpr_performSetter (defineExtensionSetter_gtlExpr_performSetter, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetUnconstructedInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetUnconstructedInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                          GALGAS_gtlData & ioArgument_vars,
                                                          GALGAS_library & ioArgument_lib,
                                                          GALGAS_string & /* ioArgument_outputString */,
                                                          Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, GALGAS_gtlUnconstructed::class_func_new (callExtensionGetter_location ((const cPtr_gtlVarItem *) this->mProperty_lValue.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 126)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 126)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 126))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 125)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 125)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                             GALGAS_gtlData & ioArgument_vars,
                                             GALGAS_library & ioArgument_lib,
                                             GALGAS_string & /* ioArgument_outputString */,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 149)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 149)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetAddInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetAddInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                GALGAS_gtlData & ioArgument_vars,
                                                GALGAS_library & ioArgument_lib,
                                                GALGAS_string & /* ioArgument_outputString */,
                                                Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_addOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 167)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 168)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 167)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 163)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetSubstractInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetSubstractInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                      GALGAS_gtlData & ioArgument_vars,
                                                      GALGAS_library & ioArgument_lib,
                                                      GALGAS_string & /* ioArgument_outputString */,
                                                      Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_subOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 187)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 188)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 187)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 183)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetMultiplyInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetMultiplyInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                     GALGAS_gtlData & ioArgument_vars,
                                                     GALGAS_library & ioArgument_lib,
                                                     GALGAS_string & /* ioArgument_outputString */,
                                                     Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_mulOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 207)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 208)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 207)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 203)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetDivideInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetDivideInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                   GALGAS_gtlData & ioArgument_vars,
                                                   GALGAS_library & ioArgument_lib,
                                                   GALGAS_string & /* ioArgument_outputString */,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_divOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 227)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 228)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 227)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 223)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetModuloInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetModuloInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                   GALGAS_gtlData & ioArgument_vars,
                                                   GALGAS_library & ioArgument_lib,
                                                   GALGAS_string & /* ioArgument_outputString */,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_divOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 247)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 248)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 247)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 243)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetShiftLeftInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetShiftLeftInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                      GALGAS_gtlData & ioArgument_vars,
                                                      GALGAS_library & ioArgument_lib,
                                                      GALGAS_string & /* ioArgument_outputString */,
                                                      Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_slOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 267)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 268)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 267)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 263)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetShiftRightInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetShiftRightInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                       GALGAS_gtlData & ioArgument_vars,
                                                       GALGAS_library & ioArgument_lib,
                                                       GALGAS_string & /* ioArgument_outputString */,
                                                       Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_srOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 287)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 288)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 287)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 283)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetAndInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetAndInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                GALGAS_gtlData & ioArgument_vars,
                                                GALGAS_library & ioArgument_lib,
                                                GALGAS_string & /* ioArgument_outputString */,
                                                Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_andOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 307)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 308)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 307)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 303)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetOrInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetOrInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                               GALGAS_gtlData & ioArgument_vars,
                                               GALGAS_library & ioArgument_lib,
                                               GALGAS_string & /* ioArgument_outputString */,
                                               Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_orOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 327)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 328)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 327)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 323)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetXorInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetXorInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                GALGAS_gtlData & ioArgument_vars,
                                                GALGAS_library & ioArgument_lib,
                                                GALGAS_string & /* ioArgument_outputString */,
                                                Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_xorOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 347)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 348)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 347)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 343)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlUnletInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlUnletInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                               GALGAS_gtlData & ioArgument_vars,
                                               GALGAS_library & ioArgument_lib,
                                               GALGAS_string & /* ioArgument_outputString */,
                                               Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_delete (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 363)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlTemplateStringInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlTemplateStringInstruction::method_execute (GALGAS_gtlContext & /* ioArgument_context */,
                                                        GALGAS_gtlData & /* ioArgument_vars */,
                                                        GALGAS_library & /* ioArgument_lib */,
                                                        GALGAS_string & ioArgument_outputString,
                                                        Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_outputString.plusAssign_operation(this->mProperty_value, inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 383)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlEmitInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlEmitInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                              GALGAS_gtlData & ioArgument_vars,
                                              GALGAS_library & ioArgument_lib,
                                              GALGAS_string & ioArgument_outputString,
                                              Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_outputString.plusAssign_operation(callExtensionGetter_string ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 399)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 399)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 399)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWriteToInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlWriteToInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                 GALGAS_gtlData & ioArgument_vars,
                                                 GALGAS_library & ioArgument_lib,
                                                 GALGAS_string & /* ioArgument_outputString */,
                                                 Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint var_currentErrorCount_12226 = GALGAS_uint::class_func_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 418)) ;
  GALGAS_string var_fullFileName_12277 = callExtensionGetter_string ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_fileNameExpression.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 419)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 419)) ;
  GALGAS_gtlString var_fileName_12364 = GALGAS_gtlString::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 422)), var_fullFileName_12277.getter_lastPathComponent (SOURCE_FILE ("gtl_instructions.galgas", 423))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 420)) ;
  GALGAS_gtlString var_filePath_12471 = GALGAS_gtlString::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 427)), var_fullFileName_12277.getter_nativePathWithUnixPath (SOURCE_FILE ("gtl_instructions.galgas", 428))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 425)) ;
  GALGAS_string var_result_12578 = GALGAS_string::makeEmptyString () ;
  GALGAS_gtlData var_varsCopy_12601 = ioArgument_vars ;
  {
  var_varsCopy_12601.insulate (HERE) ;
  cPtr_gtlData * ptr_12703 = (cPtr_gtlData *) var_varsCopy_12601.ptr () ;
  callExtensionSetter_setStructFieldAtLevel ((cPtr_gtlData *) ptr_12703, GALGAS_lstring::class_func_new (GALGAS_string ("FILENAME"), this->mProperty_where, inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 435)), var_fileName_12364, GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 434)) ;
  }
  {
  var_varsCopy_12601.insulate (HERE) ;
  cPtr_gtlData * ptr_12802 = (cPtr_gtlData *) var_varsCopy_12601.ptr () ;
  callExtensionSetter_setStructFieldAtLevel ((cPtr_gtlData *) ptr_12802, GALGAS_lstring::class_func_new (GALGAS_string ("FILEPATH"), this->mProperty_where, inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 440)), var_filePath_12471, GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 439)) ;
  }
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, var_currentErrorCount_12226.objectCompare (GALGAS_uint::class_func_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 445)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      extensionMethod_execute (this->mProperty_instructions, ioArgument_context, var_varsCopy_12601, ioArgument_lib, var_result_12578, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 446)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, var_currentErrorCount_12226.objectCompare (GALGAS_uint::class_func_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 447)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            test_2 = this->mProperty_isExecutable.boolEnum () ;
            if (kBoolTrue == test_2) {
              GALGAS_string var_directory_13111 = var_fullFileName_12277.getter_stringByDeletingLastPathComponent (SOURCE_FILE ("gtl_instructions.galgas", 449)) ;
              enumGalgasBool test_3 = kBoolTrue ;
              if (kBoolTrue == test_3) {
                test_3 = GALGAS_bool (kIsNotEqual, var_directory_13111.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
                if (kBoolTrue == test_3) {
                  var_directory_13111.method_makeDirectory (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 450)) ;
                }
              }
              var_result_12578.method_writeToExecutableFile (var_fullFileName_12277, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 451)) ;
            }
          }
          if (kBoolFalse == test_2) {
            var_result_12578.method_makeDirectoryAndWriteToFile (var_fullFileName_12277, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 453)) ;
          }
        }
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlTemplateInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlTemplateInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                  GALGAS_gtlData & ioArgument_vars,
                                                  GALGAS_library & ioArgument_lib,
                                                  GALGAS_string & ioArgument_outputString,
                                                  Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlContext var_newContext_14000 = ioArgument_context ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, GALGAS_string::makeEmptyString ().objectCompare (this->mProperty_prefix.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      var_newContext_14000.setter_setPrefix (this->mProperty_prefix COMMA_SOURCE_FILE ("gtl_instructions.galgas", 480)) ;
      }
    }
  }
  GALGAS_gtlString temp_1 ;
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_fileName.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)).isValid ()) {
    if (nullptr != dynamic_cast <const cPtr_gtlString *> (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_fileName.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)).ptr ())) {
      temp_1 = (cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_fileName.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)).ptr () ;
    }else{
      inCompiler->castError ("gtlString", callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_fileName.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)) ;
    }
  }
  GALGAS_lstring var_templateFileName_14104 = callExtensionGetter_fullTemplateFileName ((const cPtr_gtlContext *) var_newContext_14000.ptr (), ioArgument_context, ioArgument_vars, callExtensionGetter_lstring ((const cPtr_gtlString *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 483)) ;
  GALGAS_gtlData var_localVars_14262 ;
  {
  var_newContext_14000.setter_setInputVars (GALGAS_gtlDataList::class_func_emptyList (SOURCE_FILE ("gtl_instructions.galgas", 490)) COMMA_SOURCE_FILE ("gtl_instructions.galgas", 490)) ;
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = this->mProperty_isGlobal.operator_not (SOURCE_FILE ("gtl_instructions.galgas", 491)).boolEnum () ;
    if (kBoolTrue == test_2) {
      var_localVars_14262 = GALGAS_gtlStruct::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 493)), GALGAS_gtlVarMap::class_func_emptyMap (SOURCE_FILE ("gtl_instructions.galgas", 493))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 493)) ;
      cEnumerator_gtlExpressionList enumerator_14461 (this->mProperty_arguments, kENUMERATION_UP) ;
      while (enumerator_14461.hasCurrentObject ()) {
        GALGAS_gtlData var_evaluedArg_14516 = callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_14461.current_expression (HERE).ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 495)) ;
        {
        var_newContext_14000.insulate (HERE) ;
        cPtr_gtlContext * ptr_14584 = (cPtr_gtlContext *) var_newContext_14000.ptr () ;
        callExtensionSetter_addInputVariable ((cPtr_gtlContext *) ptr_14584, var_evaluedArg_14516, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 496)) ;
        }
        enumerator_14461.gotoNextObject () ;
      }
    }
  }
  if (kBoolFalse == test_2) {
    var_localVars_14262 = ioArgument_vars ;
  }
  GALGAS_bool var_found_14775 ;
  GALGAS_gtlTemplate var_result_14803 ;
  {
  ioArgument_lib.insulate (HERE) ;
  cPtr_library * ptr_14675 = (cPtr_library *) ioArgument_lib.ptr () ;
  callExtensionSetter_getTemplate ((cPtr_library *) ptr_14675, var_newContext_14000, var_templateFileName_14104, this->mProperty_ifExists, ioArgument_lib, var_found_14775, var_result_14803, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 502)) ;
  }
  enumGalgasBool test_3 = kBoolTrue ;
  if (kBoolTrue == test_3) {
    test_3 = var_found_14775.boolEnum () ;
    if (kBoolTrue == test_3) {
      callExtensionMethod_execute ((cPtr_gtlTemplate *) var_result_14803.ptr (), var_newContext_14000, var_localVars_14262, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 512)) ;
    }
  }
  if (kBoolFalse == test_3) {
    enumGalgasBool test_4 = kBoolTrue ;
    if (kBoolTrue == test_4) {
      test_4 = this->mProperty_ifExists.boolEnum () ;
      if (kBoolTrue == test_4) {
        GALGAS_gtlData var_localMap_14943 = callExtensionGetter_overrideMap ((const cPtr_gtlData *) ioArgument_vars.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 515)) ;
        extensionMethod_execute (this->mProperty_instructionsIfNotFound, ioArgument_context, var_localMap_14943, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 516)) ;
        ioArgument_vars = callExtensionGetter_overriddenMap ((const cPtr_gtlData *) var_localMap_14943.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 517)) ;
      }
    }
  }
  {
  ioArgument_context.setter_setDebuggerContext (var_newContext_14000.readProperty_debuggerContext () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 521)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlGetColumnInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlGetColumnInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                   GALGAS_gtlData & ioArgument_vars,
                                                   GALGAS_library & ioArgument_lib,
                                                   GALGAS_string & ioArgument_outputString,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_value_15713 = GALGAS_string::makeEmptyString () ;
  GALGAS_bool var_searchEndOfLine_15732 = GALGAS_bool (true) ;
  GALGAS_uint var_index_15763 = ioArgument_outputString.getter_count (SOURCE_FILE ("gtl_instructions.galgas", 540)) ;
  if (ioArgument_outputString.getter_count (SOURCE_FILE ("gtl_instructions.galgas", 541)).isValid ()) {
    uint32_t variant_15795 = ioArgument_outputString.getter_count (SOURCE_FILE ("gtl_instructions.galgas", 541)).uintValue () ;
    bool loop_15795 = true ;
    while (loop_15795) {
      loop_15795 = GALGAS_bool (kIsStrictSup, var_index_15763.objectCompare (GALGAS_uint (uint32_t (0U)))).operator_and (var_searchEndOfLine_15732 COMMA_SOURCE_FILE ("gtl_instructions.galgas", 541)).isValid () ;
      if (loop_15795) {
        loop_15795 = GALGAS_bool (kIsStrictSup, var_index_15763.objectCompare (GALGAS_uint (uint32_t (0U)))).operator_and (var_searchEndOfLine_15732 COMMA_SOURCE_FILE ("gtl_instructions.galgas", 541)).boolValue () ;
      }
      if (loop_15795 && (0 == variant_15795)) {
        loop_15795 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_instructions.galgas", 541)) ;
      }
      if (loop_15795) {
        variant_15795 -- ;
        var_searchEndOfLine_15732 = GALGAS_bool (kIsNotEqual, ioArgument_outputString.getter_characterAtIndex (var_index_15763.substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 542)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 542)).objectCompare (GALGAS_char (TO_UNICODE (10)))) ;
        var_index_15763.decrement_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 543)) ;
        enumGalgasBool test_0 = kBoolTrue ;
        if (kBoolTrue == test_0) {
          test_0 = var_searchEndOfLine_15732.boolEnum () ;
          if (kBoolTrue == test_0) {
            var_value_15713.plusAssign_operation(GALGAS_string (" "), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 545)) ;
          }
        }
      }
    }
  }
  extensionMethod_set (this->mProperty_destVariable, ioArgument_context, ioArgument_vars, ioArgument_lib, GALGAS_gtlString::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 552)), var_value_15713  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 552)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 548)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlIfStatementInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlIfStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                     GALGAS_gtlData & ioArgument_vars,
                                                     GALGAS_library & ioArgument_lib,
                                                     GALGAS_string & ioArgument_outputString,
                                                     Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_localMap_16721 = callExtensionGetter_overrideMap ((const cPtr_gtlData *) ioArgument_vars.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 576)) ;
  GALGAS_bool var_noConditionMatching_16762 = GALGAS_bool (true) ;
  cEnumerator_gtlThenElsifStatementList enumerator_16795 (this->mProperty_thenElsifList, kENUMERATION_UP) ;
  bool bool_0 = var_noConditionMatching_16762.isValidAndTrue () ;
  if (enumerator_16795.hasCurrentObject () && bool_0) {
    while (enumerator_16795.hasCurrentObject () && bool_0) {
      GALGAS_gtlData var_dataCondition_16861 = callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_16795.current_condition (HERE).ptr (), ioArgument_context, var_localMap_16721, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 580)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (var_dataCondition_16861.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_gtlBool temp_2 ;
          if (var_dataCondition_16861.isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlBool *> (var_dataCondition_16861.ptr ())) {
              temp_2 = (cPtr_gtlBool *) var_dataCondition_16861.ptr () ;
            }else{
              inCompiler->castError ("gtlBool", var_dataCondition_16861.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 582)) ;
            }
          }
          GALGAS_bool var_boolCondition_16975 = temp_2.readProperty_value () ;
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = var_boolCondition_16975.boolEnum () ;
            if (kBoolTrue == test_3) {
              extensionMethod_execute (enumerator_16795.current_instructionList (HERE), ioArgument_context, var_localMap_16721, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 584)) ;
              var_noConditionMatching_16762 = GALGAS_bool (false) ;
            }
          }
        }
      }
      if (kBoolFalse == test_1) {
        TC_Array <C_FixItDescription> fixItArray4 ;
        inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) var_dataCondition_16861.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 588)), GALGAS_string ("bool expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 588)) ;
      }
      enumerator_16795.gotoNextObject () ;
      if (enumerator_16795.hasCurrentObject ()) {
        bool_0 = var_noConditionMatching_16762.isValidAndTrue () ;
      }
    }
  }
  enumGalgasBool test_5 = kBoolTrue ;
  if (kBoolTrue == test_5) {
    test_5 = var_noConditionMatching_16762.boolEnum () ;
    if (kBoolTrue == test_5) {
      extensionMethod_execute (this->mProperty_elseList, ioArgument_context, var_localMap_16721, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 592)) ;
    }
  }
  ioArgument_vars = callExtensionGetter_overriddenMap ((const cPtr_gtlData *) var_localMap_16721.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 595)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlForeachStatementInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlForeachStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                          GALGAS_gtlData & ioArgument_vars,
                                                          GALGAS_library & ioArgument_lib,
                                                          GALGAS_string & ioArgument_outputString,
                                                          Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_localMap_20558 = callExtensionGetter_overrideMap ((const cPtr_gtlData *) ioArgument_vars.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 706)) ;
  GALGAS_gtlData var_iterableData_20603 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_iterable.ptr (), ioArgument_context, var_localMap_20558, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 707)) ;
  if (var_iterableData_20603.isValid ()) {
    if (var_iterableData_20603.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlMap) {
      GALGAS_gtlMap cast_20697_iterableMap ((cPtr_gtlMap *) var_iterableData_20603.ptr ()) ;
      const GALGAS_gtlForeachStatementInstruction temp_0 = this ;
      callExtensionMethod_iterateOnMap ((cPtr_gtlForeachStatementInstruction *) temp_0.ptr (), ioArgument_context, var_localMap_20558, ioArgument_lib, ioArgument_outputString, cast_20697_iterableMap, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 710)) ;
    }else if (var_iterableData_20603.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlList) {
      GALGAS_gtlList cast_20808_iterableList ((cPtr_gtlList *) var_iterableData_20603.ptr ()) ;
      const GALGAS_gtlForeachStatementInstruction temp_1 = this ;
      callExtensionMethod_iterateOnList ((cPtr_gtlForeachStatementInstruction *) temp_1.ptr (), ioArgument_context, var_localMap_20558, ioArgument_lib, ioArgument_outputString, cast_20808_iterableList, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 712)) ;
    }else if (var_iterableData_20603.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet) {
      GALGAS_gtlSet cast_20922_iterableSet ((cPtr_gtlSet *) var_iterableData_20603.ptr ()) ;
      const GALGAS_gtlForeachStatementInstruction temp_2 = this ;
      callExtensionMethod_iterateOnSet ((cPtr_gtlForeachStatementInstruction *) temp_2.ptr (), ioArgument_context, var_localMap_20558, ioArgument_lib, ioArgument_outputString, cast_20922_iterableSet, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 714)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_iterable.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 716)), GALGAS_string ("Map, list or set expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 716)) ;
    }
  }
  ioArgument_vars = callExtensionGetter_overriddenMap ((const cPtr_gtlData *) var_localMap_20558.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 718)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlForStatementInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlForStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                      GALGAS_gtlData & ioArgument_vars,
                                                      GALGAS_library & ioArgument_lib,
                                                      GALGAS_string & ioArgument_outputString,
                                                      Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_indexName_21672 = GALGAS_lstring::class_func_new (GALGAS_string ("INDEX"), this->mProperty_where, inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 737)) ;
  GALGAS_gtlData var_localMap_21717 = callExtensionGetter_overrideMap ((const cPtr_gtlData *) ioArgument_vars.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 738)) ;
  cEnumerator_gtlExpressionList enumerator_21753 (this->mProperty_iterable, kENUMERATION_UP) ;
  GALGAS_uint index_21749 ((uint32_t) 0) ;
  while (enumerator_21753.hasCurrentObject ()) {
    GALGAS_gtlData var_value_21798 = callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_21753.current_expression (HERE).ptr (), ioArgument_context, var_localMap_21717, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 741)) ;
    {
    var_localMap_21717.insulate (HERE) ;
    cPtr_gtlData * ptr_21855 = (cPtr_gtlData *) var_localMap_21717.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_21855, this->mProperty_identifier, var_value_21798, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 742)) ;
    }
    {
    var_localMap_21717.insulate (HERE) ;
    cPtr_gtlData * ptr_21906 = (cPtr_gtlData *) var_localMap_21717.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_21906, var_indexName_21672, GALGAS_gtlInt::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 745)), index_21749.getter_bigint (SOURCE_FILE ("gtl_instructions.galgas", 745))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 745)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 743)) ;
    }
    extensionMethod_execute (this->mProperty_doList, ioArgument_context, var_localMap_21717, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 747)) ;
    if (enumerator_21753.hasNextObject ()) {
      extensionMethod_execute (this->mProperty_betweenList, ioArgument_context, var_localMap_21717, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 749)) ;
    }
    enumerator_21753.gotoNextObject () ;
    index_21749.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 739)) ;
  }
  ioArgument_vars = callExtensionGetter_overriddenMap ((const cPtr_gtlData *) var_localMap_21717.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 751)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLoopStatementInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLoopStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                       GALGAS_gtlData & ioArgument_vars,
                                                       GALGAS_library & ioArgument_lib,
                                                       GALGAS_string & ioArgument_outputString,
                                                       Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_localMap_22891 = callExtensionGetter_overrideMap ((const cPtr_gtlData *) ioArgument_vars.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 775)) ;
  GALGAS_gtlData var_startData_22936 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_start.ptr (), ioArgument_context, var_localMap_22891, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 776)) ;
  GALGAS_gtlData var_stopData_23000 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_stop.ptr (), ioArgument_context, var_localMap_22891, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 777)) ;
  GALGAS_gtlData var_stepData_23064 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_step.ptr (), ioArgument_context, var_localMap_22891, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 778)) ;
  GALGAS_bigint var_startVal_23123 ;
  GALGAS_bigint var_stopVal_23146 ;
  GALGAS_bigint var_stepVal_23168 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (var_startData_22936.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (var_startData_22936.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (var_startData_22936.ptr ())) {
          temp_1 = (cPtr_gtlInt *) var_startData_22936.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", var_startData_22936.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 783)) ;
        }
      }
      var_startVal_23123 = temp_1.readProperty_value () ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_start.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 785)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 785)) ;
    var_startVal_23123.drop () ; // Release error dropped variable
  }
  enumGalgasBool test_3 = kBoolTrue ;
  if (kBoolTrue == test_3) {
    test_3 = GALGAS_bool (var_stopData_23000.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_3) {
      GALGAS_gtlInt temp_4 ;
      if (var_stopData_23000.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (var_stopData_23000.ptr ())) {
          temp_4 = (cPtr_gtlInt *) var_stopData_23000.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", var_stopData_23000.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 788)) ;
        }
      }
      var_stopVal_23146 = temp_4.readProperty_value () ;
    }
  }
  if (kBoolFalse == test_3) {
    TC_Array <C_FixItDescription> fixItArray5 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_stop.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 790)), GALGAS_string ("int expected"), fixItArray5  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 790)) ;
    var_stopVal_23146.drop () ; // Release error dropped variable
  }
  enumGalgasBool test_6 = kBoolTrue ;
  if (kBoolTrue == test_6) {
    test_6 = GALGAS_bool (var_stepData_23064.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_6) {
      GALGAS_gtlInt temp_7 ;
      if (var_stepData_23064.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (var_stepData_23064.ptr ())) {
          temp_7 = (cPtr_gtlInt *) var_stepData_23064.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", var_stepData_23064.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 793)) ;
        }
      }
      var_stepVal_23168 = temp_7.readProperty_value ().multiply_operation (this->mProperty_upDown.getter_bigint (SOURCE_FILE ("gtl_instructions.galgas", 793)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 793)) ;
    }
  }
  if (kBoolFalse == test_6) {
    TC_Array <C_FixItDescription> fixItArray8 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_step.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 795)), GALGAS_string ("int expected"), fixItArray8  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 795)) ;
    var_stepVal_23168.drop () ; // Release error dropped variable
  }
  GALGAS_bigint var_direction_23628 = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 797)) ;
  enumGalgasBool test_9 = kBoolTrue ;
  if (kBoolTrue == test_9) {
    test_9 = GALGAS_bool (kIsStrictInf, var_stepVal_23168.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 798)))).boolEnum () ;
    if (kBoolTrue == test_9) {
      var_direction_23628 = GALGAS_bigint ("-1", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 798)) ;
    }
  }
  enumGalgasBool test_10 = kBoolTrue ;
  if (kBoolTrue == test_10) {
    test_10 = GALGAS_bool (kIsSupOrEqual, var_stopVal_23146.substract_operation (var_startVal_23123, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 799)).multiply_operation (var_direction_23628, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 799)).objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 799)))).boolEnum () ;
    if (kBoolTrue == test_10) {
      extensionMethod_execute (this->mProperty_beforeList, ioArgument_context, var_localMap_22891, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 800)) ;
      GALGAS_uint var_count_23812 = var_stopVal_23146.substract_operation (var_startVal_23123, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 801)).multiply_operation (var_direction_23628, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 801)).add_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 801)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 801)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 801)) ;
      if (var_count_23812.isValid ()) {
        uint32_t variant_23868 = var_count_23812.uintValue () ;
        bool loop_23868 = true ;
        while (loop_23868) {
            {
            var_localMap_22891.insulate (HERE) ;
            cPtr_gtlData * ptr_23890 = (cPtr_gtlData *) var_localMap_22891.ptr () ;
            callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_23890, this->mProperty_identifier, GALGAS_gtlInt::class_func_new (this->mProperty_identifier.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 805)), var_startVal_23123  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 805)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 803)) ;
            }
            extensionMethod_execute (this->mProperty_doList, ioArgument_context, var_localMap_22891, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 807)) ;
            var_startVal_23123 = var_startVal_23123.add_operation (var_stepVal_23168, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 808)) ;
          loop_23868 = GALGAS_bool (kIsSupOrEqual, var_stopVal_23146.substract_operation (var_startVal_23123, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 809)).multiply_operation (var_direction_23628, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 809)).objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 809)))).isValid () ;
          if (loop_23868) {
            loop_23868 = GALGAS_bool (kIsSupOrEqual, var_stopVal_23146.substract_operation (var_startVal_23123, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 809)).multiply_operation (var_direction_23628, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 809)).objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 809)))).boolValue () ;
          }
          if (loop_23868 && (0 == variant_23868)) {
            loop_23868 = false ;
            inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_instructions.galgas", 802)) ;
          }
          if (loop_23868) {
            variant_23868 -- ;
            extensionMethod_execute (this->mProperty_betweenList, ioArgument_context, var_localMap_22891, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 810)) ;
          }
        }
      }
      extensionMethod_execute (this->mProperty_afterList, ioArgument_context, var_localMap_22891, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 812)) ;
    }
  }
  ioArgument_vars = callExtensionGetter_overriddenMap ((const cPtr_gtlData *) var_localMap_22891.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 814)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlRepeatStatementInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlRepeatStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                         GALGAS_gtlData & ioArgument_vars,
                                                         GALGAS_library & ioArgument_lib,
                                                         GALGAS_string & ioArgument_outputString,
                                                         Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_localMap_24901 = callExtensionGetter_overrideMap ((const cPtr_gtlData *) ioArgument_vars.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 833)) ;
  GALGAS_bool var_boolCondition_24939 = GALGAS_bool (false) ;
  GALGAS_gtlData var_limitData_24976 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_limit.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 835)) ;
  GALGAS_uint var_limitVal_25033 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (var_limitData_24976.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (var_limitData_24976.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (var_limitData_24976.ptr ())) {
          temp_1 = (cPtr_gtlInt *) var_limitData_24976.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", var_limitData_24976.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 839)) ;
        }
      }
      var_limitVal_25033 = temp_1.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 839)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_limit.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 841)), GALGAS_string ("int exprected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 841)) ;
    var_limitVal_25033.drop () ; // Release error dropped variable
  }
  if (var_limitVal_25033.isValid ()) {
    uint32_t variant_25193 = var_limitVal_25033.uintValue () ;
    bool loop_25193 = true ;
    while (loop_25193) {
        extensionMethod_execute (this->mProperty_continueList, ioArgument_context, var_localMap_24901, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 845)) ;
        GALGAS_gtlData var_conditionData_25295 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_condition.ptr (), ioArgument_context, var_localMap_24901, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 846)) ;
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, var_conditionData_25295.getter_dynamicType (SOURCE_FILE ("gtl_instructions.galgas", 847)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool))).boolEnum () ;
          if (kBoolTrue == test_3) {
            GALGAS_gtlBool temp_4 ;
            if (var_conditionData_25295.isValid ()) {
              if (nullptr != dynamic_cast <const cPtr_gtlBool *> (var_conditionData_25295.ptr ())) {
                temp_4 = (cPtr_gtlBool *) var_conditionData_25295.ptr () ;
              }else{
                inCompiler->castError ("gtlBool", var_conditionData_25295.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 848)) ;
              }
            }
            var_boolCondition_24939 = temp_4.readProperty_value () ;
          }
        }
        if (kBoolFalse == test_3) {
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) var_conditionData_25295.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 850)), GALGAS_string ("bool expected"), fixItArray5  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 850)) ;
        }
      loop_25193 = var_boolCondition_24939.isValid () ;
      if (loop_25193) {
        loop_25193 = var_boolCondition_24939.boolValue () ;
      }
      if (loop_25193 && (0 == variant_25193)) {
        loop_25193 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_instructions.galgas", 844)) ;
      }
      if (loop_25193) {
        variant_25193 -- ;
        extensionMethod_execute (this->mProperty_doList, ioArgument_context, var_localMap_24901, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 853)) ;
      }
    }
  }
  ioArgument_vars = callExtensionGetter_overriddenMap ((const cPtr_gtlData *) var_localMap_24901.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 855)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlErrorStatementInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlErrorStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                        GALGAS_gtlData & ioArgument_vars,
                                                        GALGAS_library & ioArgument_lib,
                                                        GALGAS_string & /* ioArgument_outputString */,
                                                        Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location var_errorLocation_26180 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_hereInstead.boolEnum () ;
    if (kBoolTrue == test_0) {
      var_errorLocation_26180 = this->mProperty_where ;
    }
  }
  if (kBoolFalse == test_0) {
    var_errorLocation_26180 = extensionGetter_get (this->mProperty_identifier, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 877)).readProperty_where () ;
  }
  GALGAS_gtlData var_errorMessageData_26336 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_errorMessage.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 879)) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsEqual, var_errorMessageData_26336.getter_dynamicType (SOURCE_FILE ("gtl_instructions.galgas", 880)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlString))).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_gtlString temp_2 ;
      if (var_errorMessageData_26336.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (var_errorMessageData_26336.ptr ())) {
          temp_2 = (cPtr_gtlString *) var_errorMessageData_26336.ptr () ;
        }else{
          inCompiler->castError ("gtlString", var_errorMessageData_26336.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 881)) ;
        }
      }
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (var_errorLocation_26180, temp_2.readProperty_value (), fixItArray3  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 881)) ;
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWarningStatementInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlWarningStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                          GALGAS_gtlData & ioArgument_vars,
                                                          GALGAS_library & ioArgument_lib,
                                                          GALGAS_string & /* ioArgument_outputString */,
                                                          Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location var_warningLocation_27162 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_hereInstead.boolEnum () ;
    if (kBoolTrue == test_0) {
      var_warningLocation_27162 = this->mProperty_where ;
    }
  }
  if (kBoolFalse == test_0) {
    var_warningLocation_27162 = extensionGetter_get (this->mProperty_identifier, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 907)).readProperty_where () ;
  }
  GALGAS_gtlData var_warningMessageData_27324 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_warningMessage.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 909)) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsEqual, var_warningMessageData_27324.getter_dynamicType (SOURCE_FILE ("gtl_instructions.galgas", 910)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlString))).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_gtlString temp_2 ;
      if (var_warningMessageData_27324.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (var_warningMessageData_27324.ptr ())) {
          temp_2 = (cPtr_gtlString *) var_warningMessageData_27324.ptr () ;
        }else{
          inCompiler->castError ("gtlString", var_warningMessageData_27324.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 911)) ;
        }
      }
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticWarning (var_warningLocation_27162, temp_2.readProperty_value (), fixItArray3  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 911)) ;
    }
  }
  if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_warningMessage.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 913)), GALGAS_string ("string expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 913)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlPrintStatementInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlPrintStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                        GALGAS_gtlData & ioArgument_vars,
                                                        GALGAS_library & ioArgument_lib,
                                                        GALGAS_string & /* ioArgument_outputString */,
                                                        Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_messageToPrintString_28089 = callExtensionGetter_string ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_messageToPrint.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 932)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 932)) ;
  inCompiler->printMessage (var_messageToPrintString_28089  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 933)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_carriageReturn.boolEnum () ;
    if (kBoolTrue == test_0) {
      inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 934)) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDisplayStatementInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlDisplayStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                          GALGAS_gtlData & ioArgument_vars,
                                                          GALGAS_library & ioArgument_lib,
                                                          GALGAS_string & /* ioArgument_outputString */,
                                                          Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_variable_28714 = extensionGetter_get (this->mProperty_variablePath, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 950)) ;
  inCompiler->printMessage (extensionGetter_stringPath (this->mProperty_variablePath, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 951)).add_operation (GALGAS_string (" from "), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 951)).add_operation (this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 952)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 952)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 952)).add_operation (callExtensionGetter_desc ((const cPtr_gtlData *) var_variable_28714.ptr (), GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 953)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 952))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 951)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlAbstractSortInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlAbstractSortInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                      GALGAS_gtlData & ioArgument_vars,
                                                      GALGAS_library & ioArgument_lib,
                                                      GALGAS_string & /* ioArgument_outputString */,
                                                      Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_variable_30650 = extensionGetter_get (this->mProperty_variablePath, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1024)) ;
  if (var_variable_30650.isValid ()) {
    if (var_variable_30650.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlList) {
      GALGAS_gtlList cast_30735_variableList ((cPtr_gtlList *) var_variable_30650.ptr ()) ;
      GALGAS_list var_listToSort_30759 = cast_30735_variableList.readProperty_value () ;
      GALGAS_uint var_length_30807 = var_listToSort_30759.getter_count (SOURCE_FILE ("gtl_instructions.galgas", 1028)) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsStrictSup, var_length_30807.objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          const GALGAS_gtlAbstractSortInstruction temp_1 = this ;
          callExtensionMethod_sort ((cPtr_gtlAbstractSortInstruction *) temp_1.ptr (), var_listToSort_30759, GALGAS_uint (uint32_t (0U)), var_length_30807.substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1030)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1030)) ;
        }
      }
      extensionMethod_set (this->mProperty_variablePath, ioArgument_context, ioArgument_vars, ioArgument_lib, GALGAS_gtlList::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1036)), var_listToSort_30759  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1036)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1032)) ;
    }else{
      GALGAS_gtlVarItem var_lastComponent_31089 ;
      this->mProperty_variablePath.method_last (var_lastComponent_31089, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1039)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlVarItem *) var_lastComponent_31089.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1040)), GALGAS_string ("list expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1040)) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSortStatementStructInstruction compare'
//
//--------------------------------------------------------------------------------------------------

GALGAS_sint cPtr_gtlSortStatementStructInstruction::getter_compare (const GALGAS_gtlData constinArgument_s_31_,
                                                                    const GALGAS_gtlData constinArgument_s_32_,
                                                                    Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result_result ; // Returned variable
  const GALGAS_gtlSortStatementStructInstruction temp_0 = this ;
  result_result = callExtensionGetter_compareElements ((const cPtr_gtlSortStatementStructInstruction *) temp_0.ptr (), constinArgument_s_31_, constinArgument_s_32_, this->mProperty_sortingKey, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1054)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSortStatementInstruction compare'
//
//--------------------------------------------------------------------------------------------------

GALGAS_sint cPtr_gtlSortStatementInstruction::getter_compare (const GALGAS_gtlData constinArgument_s_31_,
                                                              const GALGAS_gtlData constinArgument_s_32_,
                                                              Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_ltOp ((const cPtr_gtlData *) constinArgument_s_31_.ptr (), constinArgument_s_32_, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1101)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1101)).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = GALGAS_bigint ("-1", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1102)).multiply_operation (this->mProperty_order.readProperty_sint ().getter_bigint (SOURCE_FILE ("gtl_instructions.galgas", 1102)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1102)).getter_sint (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1102)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_gtOp ((const cPtr_gtlData *) constinArgument_s_31_.ptr (), constinArgument_s_32_, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1104)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1104)).boolEnum () ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlTabStatementInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlTabStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                      GALGAS_gtlData & ioArgument_vars,
                                                      GALGAS_library & ioArgument_lib,
                                                      GALGAS_string & ioArgument_outputString,
                                                      Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_tabValueData_33422 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_tabValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1125)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (var_tabValueData_33422.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (var_tabValueData_33422.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (var_tabValueData_33422.ptr ())) {
          temp_1 = (cPtr_gtlInt *) var_tabValueData_33422.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", var_tabValueData_33422.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1127)) ;
        }
      }
      GALGAS_gtlInt var_tabValueInt_33526 = temp_1 ;
      GALGAS_uint var_currentColumn_33578 = ioArgument_outputString.getter_currentColumn (SOURCE_FILE ("gtl_instructions.galgas", 1128)) ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsSupOrEqual, var_tabValueInt_33526.readProperty_value ().objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1129)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          GALGAS_uint var_tabColumn_33676 = var_tabValueInt_33526.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1130)) ;
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = GALGAS_bool (kIsStrictSup, var_tabColumn_33676.objectCompare (var_currentColumn_33578)).boolEnum () ;
            if (kBoolTrue == test_3) {
              ioArgument_outputString.plusAssign_operation(GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), var_tabColumn_33676.substract_operation (var_currentColumn_33578, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1134)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1134))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1132)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1132)) ;
            }
          }
        }
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) var_tabValueData_33422.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1140)), GALGAS_string ("int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1140)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlVariablesInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlVariablesInstruction::method_execute (GALGAS_gtlContext & /* ioArgument_context */,
                                                   GALGAS_gtlData & ioArgument_vars,
                                                   GALGAS_library & /* ioArgument_lib */,
                                                   GALGAS_string & /* ioArgument_outputString */,
                                                   Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLibrariesInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLibrariesInstruction::method_execute (GALGAS_gtlContext & /* ioArgument_context */,
                                                   GALGAS_gtlData & /* ioArgument_vars */,
                                                   GALGAS_library & ioArgument_lib,
                                                   GALGAS_string & /* ioArgument_outputString */,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_delimitor_36074 = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (61)), GALGAS_uint (uint32_t (79U))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1215)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1215)) ;
  GALGAS_string var_varDelim_36157 = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (45)), GALGAS_uint (uint32_t (79U))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1216)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1216)) ;
  GALGAS_string var_separator_36240 = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (61)), GALGAS_uint (uint32_t (17U))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1217)) ;
  inCompiler->printMessage (var_separator_36240.add_operation (GALGAS_string (" Libraries "), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1218)).add_operation (var_separator_36240, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1218)).add_operation (GALGAS_string ("= Displayed from "), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1219)).add_operation (var_separator_36240, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1219)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1220))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1218)) ;
  inCompiler->printMessage (this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1221)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1221))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1221)) ;
  inCompiler->printMessage (var_delimitor_36074  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1222)) ;
  inCompiler->printMessage (GALGAS_string (" Functions \n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1223)) ;
  inCompiler->printMessage (var_varDelim_36157  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1224)) ;
  GALGAS_uint var_lineSize_36520 = GALGAS_uint (uint32_t (0U)) ;
  cEnumerator_gtlFuncMap enumerator_36545 (ioArgument_lib.readProperty_funcMap (), kENUMERATION_UP) ;
  const bool bool_0 = true ;
  if (enumerator_36545.hasCurrentObject () && bool_0) {
    while (enumerator_36545.hasCurrentObject () && bool_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsStrictSup, var_lineSize_36520.add_operation (enumerator_36545.current_lkey (HERE).readProperty_string ().getter_count (SOURCE_FILE ("gtl_instructions.galgas", 1227)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1227)).objectCompare (GALGAS_uint (uint32_t (75U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          var_lineSize_36520 = GALGAS_uint (uint32_t (0U)) ;
          inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1229)) ;
        }
      }
      inCompiler->printMessage (enumerator_36545.current_lkey (HERE).readProperty_string ()  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1231)) ;
      var_lineSize_36520.plusAssign_operation(enumerator_36545.current_lkey (HERE).readProperty_string ().getter_count (SOURCE_FILE ("gtl_instructions.galgas", 1232)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1232)) ;
      enumerator_36545.gotoNextObject () ;
      if (enumerator_36545.hasCurrentObject () && bool_0) {
        inCompiler->printMessage (GALGAS_string (", ")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1234)) ;
        var_lineSize_36520.plusAssign_operation(GALGAS_uint (uint32_t (2U)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1235)) ;
      }
    }
    inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1237)) ;
  }
  inCompiler->printMessage (var_delimitor_36074  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1239)) ;
  inCompiler->printMessage (GALGAS_string (" Getters \n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1240)) ;
  inCompiler->printMessage (var_varDelim_36157  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1241)) ;
  var_lineSize_36520 = GALGAS_uint (uint32_t (0U)) ;
  cEnumerator_gtlGetterMap enumerator_36896 (ioArgument_lib.readProperty_getterMap (), kENUMERATION_UP) ;
  const bool bool_2 = true ;
  if (enumerator_36896.hasCurrentObject () && bool_2) {
    while (enumerator_36896.hasCurrentObject () && bool_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsStrictSup, var_lineSize_36520.add_operation (enumerator_36896.current_lkey (HERE).readProperty_string ().getter_count (SOURCE_FILE ("gtl_instructions.galgas", 1244)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1244)).objectCompare (GALGAS_uint (uint32_t (75U)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          var_lineSize_36520 = GALGAS_uint (uint32_t (0U)) ;
          inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1246)) ;
        }
      }
      inCompiler->printMessage (enumerator_36896.current_lkey (HERE).readProperty_string ()  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1248)) ;
      var_lineSize_36520.plusAssign_operation(enumerator_36896.current_lkey (HERE).readProperty_string ().getter_count (SOURCE_FILE ("gtl_instructions.galgas", 1249)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1249)) ;
      enumerator_36896.gotoNextObject () ;
      if (enumerator_36896.hasCurrentObject () && bool_2) {
        inCompiler->printMessage (GALGAS_string (", ")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1251)) ;
        var_lineSize_36520.plusAssign_operation(GALGAS_uint (uint32_t (2U)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1252)) ;
      }
    }
    inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1254)) ;
  }
  inCompiler->printMessage (var_delimitor_36074  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1256)) ;
  inCompiler->printMessage (GALGAS_string (" Setters \n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1257)) ;
  inCompiler->printMessage (var_varDelim_36157  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1258)) ;
  var_lineSize_36520 = GALGAS_uint (uint32_t (0U)) ;
  cEnumerator_gtlSetterMap enumerator_37249 (ioArgument_lib.readProperty_setterMap (), kENUMERATION_UP) ;
  const bool bool_4 = true ;
  if (enumerator_37249.hasCurrentObject () && bool_4) {
    while (enumerator_37249.hasCurrentObject () && bool_4) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsStrictSup, var_lineSize_36520.add_operation (enumerator_37249.current_lkey (HERE).readProperty_string ().getter_count (SOURCE_FILE ("gtl_instructions.galgas", 1261)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1261)).objectCompare (GALGAS_uint (uint32_t (75U)))).boolEnum () ;
        if (kBoolTrue == test_5) {
          var_lineSize_36520 = GALGAS_uint (uint32_t (0U)) ;
          inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1263)) ;
        }
      }
      inCompiler->printMessage (enumerator_37249.current_lkey (HERE).readProperty_string ()  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1265)) ;
      var_lineSize_36520.plusAssign_operation(enumerator_37249.current_lkey (HERE).readProperty_string ().getter_count (SOURCE_FILE ("gtl_instructions.galgas", 1266)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1266)) ;
      enumerator_37249.gotoNextObject () ;
      if (enumerator_37249.hasCurrentObject () && bool_4) {
        inCompiler->printMessage (GALGAS_string (", ")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1268)) ;
        var_lineSize_36520.plusAssign_operation(GALGAS_uint (uint32_t (2U)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1269)) ;
      }
    }
    inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1271)) ;
  }
  inCompiler->printMessage (var_delimitor_36074  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1273)) ;
  inCompiler->printMessage (GALGAS_string (" Templates \n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1274)) ;
  inCompiler->printMessage (var_varDelim_36157  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1275)) ;
  var_lineSize_36520 = GALGAS_uint (uint32_t (0U)) ;
  cEnumerator_gtlTemplateMap enumerator_37604 (ioArgument_lib.readProperty_templateMap (), kENUMERATION_UP) ;
  const bool bool_6 = true ;
  if (enumerator_37604.hasCurrentObject () && bool_6) {
    while (enumerator_37604.hasCurrentObject () && bool_6) {
      enumGalgasBool test_7 = kBoolTrue ;
      if (kBoolTrue == test_7) {
        test_7 = GALGAS_bool (kIsStrictSup, var_lineSize_36520.add_operation (enumerator_37604.current_lkey (HERE).readProperty_string ().getter_count (SOURCE_FILE ("gtl_instructions.galgas", 1278)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1278)).objectCompare (GALGAS_uint (uint32_t (75U)))).boolEnum () ;
        if (kBoolTrue == test_7) {
          var_lineSize_36520 = GALGAS_uint (uint32_t (0U)) ;
          inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1280)) ;
        }
      }
      inCompiler->printMessage (enumerator_37604.current_lkey (HERE).readProperty_string ()  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1282)) ;
      var_lineSize_36520.plusAssign_operation(enumerator_37604.current_lkey (HERE).readProperty_string ().getter_count (SOURCE_FILE ("gtl_instructions.galgas", 1283)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1283)) ;
      enumerator_37604.gotoNextObject () ;
      if (enumerator_37604.hasCurrentObject () && bool_6) {
        inCompiler->printMessage (GALGAS_string (", ")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1285)) ;
        var_lineSize_36520.plusAssign_operation(GALGAS_uint (uint32_t (2U)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1286)) ;
      }
    }
    inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1288)) ;
  }
  inCompiler->printMessage (var_delimitor_36074  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1290)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlSetterCallInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlSetterCallInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                    GALGAS_gtlData & ioArgument_vars,
                                                    GALGAS_library & ioArgument_lib,
                                                    GALGAS_string & /* ioArgument_outputString */,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlDataList var_dataArguments_38432 = GALGAS_gtlDataList::class_func_emptyList (SOURCE_FILE ("gtl_instructions.galgas", 1308)) ;
  cEnumerator_gtlExpressionList enumerator_38465 (this->mProperty_arguments, kENUMERATION_UP) ;
  while (enumerator_38465.hasCurrentObject ()) {
    var_dataArguments_38432.addAssign_operation (callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_38465.current_expression (HERE).ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1310))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1310)) ;
    enumerator_38465.gotoNextObject () ;
  }
  GALGAS_gtlData var_targetData_38561 = extensionGetter_get (this->mProperty_target, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1312)) ;
  {
  var_targetData_38561.insulate (HERE) ;
  cPtr_gtlData * ptr_38612 = (cPtr_gtlData *) var_targetData_38561.ptr () ;
  callExtensionSetter_performSetter ((cPtr_gtlData *) ptr_38612, this->mProperty_setterName, var_dataArguments_38432, ioArgument_context, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1313)) ;
  }
  extensionMethod_set (this->mProperty_target, ioArgument_context, ioArgument_vars, ioArgument_lib, var_targetData_38561, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1314)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlInputStatementInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlInputStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                        GALGAS_gtlData & ioArgument_vars,
                                                        GALGAS_library & /* ioArgument_lib */,
                                                        GALGAS_string & /* ioArgument_outputString */,
                                                        Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_gtlArgumentList enumerator_39216 (this->mProperty_formalArguments, kENUMERATION_UP) ;
  while (enumerator_39216.hasCurrentObject ()) {
    GALGAS_gtlData var_arg_39296 ;
    {
    ioArgument_context.insulate (HERE) ;
    cPtr_gtlContext * ptr_39251 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
    callExtensionSetter_popFirstInputArg ((cPtr_gtlContext *) ptr_39251, enumerator_39216.current_name (HERE).readProperty_location (), var_arg_39296, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1331)) ;
    }
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = enumerator_39216.current_typed (HERE).boolEnum () ;
      if (kBoolTrue == test_0) {
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = GALGAS_bool (kIsNotEqual, enumerator_39216.current_type (HERE).objectCompare (var_arg_39296.getter_dynamicType (SOURCE_FILE ("gtl_instructions.galgas", 1333)))).boolEnum () ;
          if (kBoolTrue == test_1) {
            TC_Array <C_FixItDescription> fixItArray2 ;
            inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) var_arg_39296.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1334)), GALGAS_string ("mistyped argument, ").add_operation (extensionGetter_typeName (var_arg_39296.getter_dynamicType (SOURCE_FILE ("gtl_instructions.galgas", 1334)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1334)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1334)).add_operation (GALGAS_string (" provided"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1334)), fixItArray2  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1334)) ;
            TC_Array <C_FixItDescription> fixItArray3 ;
            inCompiler->emitSemanticError (enumerator_39216.current_name (HERE).readProperty_location (), extensionGetter_typeName (enumerator_39216.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1335)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1335)), fixItArray3  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1335)) ;
          }
        }
      }
    }
    {
    ioArgument_vars.insulate (HERE) ;
    cPtr_gtlData * ptr_39522 = (cPtr_gtlData *) ioArgument_vars.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_39522, enumerator_39216.current_name (HERE), var_arg_39296, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1338)) ;
    }
    enumerator_39216.gotoNextObject () ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Function 'trueFalse'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_trueFalse (const GALGAS_bool & constinArgument_inBool,
                                  Compiler *
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_trueFalse [2] = {
  & kTypeDescriptor_GALGAS_bool,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_trueFalse (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_trueFalse ("trueFalse",
                                                           functionWithGenericHeader_trueFalse,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_trueFalse) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'TrueFalse'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_TrueFalse (const GALGAS_bool & constinArgument_inBool,
                                  Compiler *
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_TrueFalse [2] = {
  & kTypeDescriptor_GALGAS_bool,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_TrueFalse (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_TrueFalse ("TrueFalse",
                                                           functionWithGenericHeader_TrueFalse,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_TrueFalse) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'yesNo'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_yesNo (const GALGAS_bool & constinArgument_inBool,
                              Compiler *
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_yesNo [2] = {
  & kTypeDescriptor_GALGAS_bool,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_yesNo (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_yesNo ("yesNo",
                                                       functionWithGenericHeader_yesNo,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       1,
                                                       functionArgs_yesNo) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'TRUEFALSE'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_TRUEFALSE (const GALGAS_bool & constinArgument_inBool,
                                  Compiler *
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_TRUEFALSE [2] = {
  & kTypeDescriptor_GALGAS_bool,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_TRUEFALSE (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_TRUEFALSE ("TRUEFALSE",
                                                           functionWithGenericHeader_TRUEFALSE,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_TRUEFALSE) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'listOfSize'
//
//--------------------------------------------------------------------------------------------------

GALGAS_list function_listOfSize (GALGAS_bigint inArgument_inSize,
                                 Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_list result_result ; // Returned variable
  result_result = GALGAS_list::class_func_emptyList (SOURCE_FILE ("gtl_functions.galgas", 84)) ;
  if (inArgument_inSize.getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 85)).isValid ()) {
    uint32_t variant_2584 = inArgument_inSize.getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 85)).uintValue () ;
    bool loop_2584 = true ;
    while (loop_2584) {
      loop_2584 = GALGAS_bool (kIsStrictSup, inArgument_inSize.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 86)))).isValid () ;
      if (loop_2584) {
        loop_2584 = GALGAS_bool (kIsStrictSup, inArgument_inSize.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 86)))).boolValue () ;
      }
      if (loop_2584 && (0 == variant_2584)) {
        loop_2584 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_functions.galgas", 85)) ;
      }
      if (loop_2584) {
        variant_2584 -- ;
        result_result.addAssign_operation (GALGAS_gtlUnconstructed::class_func_new (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 87)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 87))  COMMA_SOURCE_FILE ("gtl_functions.galgas", 87))  COMMA_SOURCE_FILE ("gtl_functions.galgas", 87)) ;
        inArgument_inSize.decrement_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 88)) ;
      }
    }
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_listOfSize [2] = {
  & kTypeDescriptor_GALGAS_bigint,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_listOfSize (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_listOfSize ("listOfSize",
                                                            functionWithGenericHeader_listOfSize,
                                                            & kTypeDescriptor_GALGAS_list,
                                                            1,
                                                            functionArgs_listOfSize) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'version'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_version (Compiler *
                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_application::class_func_projectVersionString (SOURCE_FILE ("gtl_functions.galgas", 97)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_version [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_version (Compiler * inCompiler,
                                                        const cObjectArray & /* inEffectiveParameterArray */,
                                                        const GALGAS_location & /* inErrorLocation */
                                                        COMMA_LOCATION_ARGS) {
  return function_version (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_version ("version",
                                                         functionWithGenericHeader_version,
                                                         & kTypeDescriptor_GALGAS_string,
                                                         0,
                                                         functionArgs_version) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'majorVersion'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint function_majorVersion (Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  GALGAS_string var_version_3232 = GALGAS_application::class_func_projectVersionString (SOURCE_FILE ("gtl_functions.galgas", 105)) ;
  GALGAS_stringlist var_versionComponents_3294 = var_version_3232.getter_componentsSeparatedByString (GALGAS_string (".") COMMA_SOURCE_FILE ("gtl_functions.galgas", 106)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_versionComponents_3294.getter_count (SOURCE_FILE ("gtl_functions.galgas", 107)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = var_versionComponents_3294.getter_mValueAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 109)).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 109)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 109)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 111)) ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_majorVersion [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_majorVersion (Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_majorVersion (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_majorVersion ("majorVersion",
                                                              functionWithGenericHeader_majorVersion,
                                                              & kTypeDescriptor_GALGAS_bigint,
                                                              0,
                                                              functionArgs_majorVersion) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'minorVersion'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint function_minorVersion (Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  GALGAS_string var_version_3766 = GALGAS_application::class_func_projectVersionString (SOURCE_FILE ("gtl_functions.galgas", 120)) ;
  GALGAS_stringlist var_versionComponents_3828 = var_version_3766.getter_componentsSeparatedByString (GALGAS_string (".") COMMA_SOURCE_FILE ("gtl_functions.galgas", 121)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_versionComponents_3828.getter_count (SOURCE_FILE ("gtl_functions.galgas", 122)).objectCompare (GALGAS_uint (uint32_t (1U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = var_versionComponents_3828.getter_mValueAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 124)).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 124)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 124)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 126)) ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_minorVersion [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_minorVersion (Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_minorVersion (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_minorVersion ("minorVersion",
                                                              functionWithGenericHeader_minorVersion,
                                                              & kTypeDescriptor_GALGAS_bigint,
                                                              0,
                                                              functionArgs_minorVersion) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'revision'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint function_revision (Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  GALGAS_string var_version_4291 = GALGAS_application::class_func_projectVersionString (SOURCE_FILE ("gtl_functions.galgas", 135)) ;
  GALGAS_stringlist var_versionComponents_4353 = var_version_4291.getter_componentsSeparatedByString (GALGAS_string (".") COMMA_SOURCE_FILE ("gtl_functions.galgas", 136)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_versionComponents_4353.getter_count (SOURCE_FILE ("gtl_functions.galgas", 137)).objectCompare (GALGAS_uint (uint32_t (2U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = var_versionComponents_4353.getter_mValueAtIndex (GALGAS_uint (uint32_t (2U)), inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 139)).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 139)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 139)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 141)) ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_revision [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_revision (Compiler * inCompiler,
                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  return function_revision (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_revision ("revision",
                                                          functionWithGenericHeader_revision,
                                                          & kTypeDescriptor_GALGAS_bigint,
                                                          0,
                                                          functionArgs_revision) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'currentDir'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_currentDir (Compiler *
                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::class_func_stringWithCurrentDirectory (SOURCE_FILE ("gtl_functions.galgas", 150)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_currentDir [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_currentDir (Compiler * inCompiler,
                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  return function_currentDir (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_currentDir ("currentDir",
                                                            functionWithGenericHeader_currentDir,
                                                            & kTypeDescriptor_GALGAS_string,
                                                            0,
                                                            functionArgs_currentDir) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'homeDir'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_homeDir (Compiler *
                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::class_func_homeDirectory (SOURCE_FILE ("gtl_functions.galgas", 158)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_homeDir [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_homeDir (Compiler * inCompiler,
                                                        const cObjectArray & /* inEffectiveParameterArray */,
                                                        const GALGAS_location & /* inErrorLocation */
                                                        COMMA_LOCATION_ARGS) {
  return function_homeDir (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_homeDir ("homeDir",
                                                         functionWithGenericHeader_homeDir,
                                                         & kTypeDescriptor_GALGAS_string,
                                                         0,
                                                         functionArgs_homeDir) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'currentDateTime'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_currentDateTime (Compiler *
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::class_func_stringWithCurrentDateTime (SOURCE_FILE ("gtl_functions.galgas", 166)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_currentDateTime [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_currentDateTime (Compiler * inCompiler,
                                                                const cObjectArray & /* inEffectiveParameterArray */,
                                                                const GALGAS_location & /* inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  return function_currentDateTime (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_currentDateTime ("currentDateTime",
                                                                 functionWithGenericHeader_currentDateTime,
                                                                 & kTypeDescriptor_GALGAS_string,
                                                                 0,
                                                                 functionArgs_currentDateTime) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'max8bitsUnsignedInt'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint function_max_38_bitsUnsignedInt (Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_bigint ("255", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 174)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_max_38_bitsUnsignedInt [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_max_38_bitsUnsignedInt (Compiler * inCompiler,
                                                                       const cObjectArray & /* inEffectiveParameterArray */,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  return function_max_38_bitsUnsignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_max_38_bitsUnsignedInt ("max8bitsUnsignedInt",
                                                                        functionWithGenericHeader_max_38_bitsUnsignedInt,
                                                                        & kTypeDescriptor_GALGAS_bigint,
                                                                        0,
                                                                        functionArgs_max_38_bitsUnsignedInt) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'max8bitsSignedInt'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint function_max_38_bitsSignedInt (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_bigint ("127", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 182)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_max_38_bitsSignedInt [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_max_38_bitsSignedInt (Compiler * inCompiler,
                                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  return function_max_38_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_max_38_bitsSignedInt ("max8bitsSignedInt",
                                                                      functionWithGenericHeader_max_38_bitsSignedInt,
                                                                      & kTypeDescriptor_GALGAS_bigint,
                                                                      0,
                                                                      functionArgs_max_38_bitsSignedInt) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'min8bitsSignedInt'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint function_min_38_bitsSignedInt (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_bigint ("-128", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 190)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_min_38_bitsSignedInt [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_min_38_bitsSignedInt (Compiler * inCompiler,
                                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  return function_min_38_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_min_38_bitsSignedInt ("min8bitsSignedInt",
                                                                      functionWithGenericHeader_min_38_bitsSignedInt,
                                                                      & kTypeDescriptor_GALGAS_bigint,
                                                                      0,
                                                                      functionArgs_min_38_bitsSignedInt) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'max16bitsUnsignedInt'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint function_max_31__36_bitsUnsignedInt (Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_bigint ("65535", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 198)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_max_31__36_bitsUnsignedInt [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_max_31__36_bitsUnsignedInt (Compiler * inCompiler,
                                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  return function_max_31__36_bitsUnsignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_max_31__36_bitsUnsignedInt ("max16bitsUnsignedInt",
                                                                            functionWithGenericHeader_max_31__36_bitsUnsignedInt,
                                                                            & kTypeDescriptor_GALGAS_bigint,
                                                                            0,
                                                                            functionArgs_max_31__36_bitsUnsignedInt) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'max16bitsSignedInt'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint function_max_31__36_bitsSignedInt (Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_bigint ("32767", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 206)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_max_31__36_bitsSignedInt [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_max_31__36_bitsSignedInt (Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_max_31__36_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_max_31__36_bitsSignedInt ("max16bitsSignedInt",
                                                                          functionWithGenericHeader_max_31__36_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_max_31__36_bitsSignedInt) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'min16bitsSignedInt'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint function_min_31__36_bitsSignedInt (Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_bigint ("-32768", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 214)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_min_31__36_bitsSignedInt [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_min_31__36_bitsSignedInt (Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_min_31__36_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_min_31__36_bitsSignedInt ("min16bitsSignedInt",
                                                                          functionWithGenericHeader_min_31__36_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_min_31__36_bitsSignedInt) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'max32bitsUnsignedInt'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint function_max_33__32_bitsUnsignedInt (Compiler *
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_uint::class_func_max (SOURCE_FILE ("gtl_functions.galgas", 222)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 222)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_max_33__32_bitsUnsignedInt [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_max_33__32_bitsUnsignedInt (Compiler * inCompiler,
                                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  return function_max_33__32_bitsUnsignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_max_33__32_bitsUnsignedInt ("max32bitsUnsignedInt",
                                                                            functionWithGenericHeader_max_33__32_bitsUnsignedInt,
                                                                            & kTypeDescriptor_GALGAS_bigint,
                                                                            0,
                                                                            functionArgs_max_33__32_bitsUnsignedInt) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'max32bitsSignedInt'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint function_max_33__32_bitsSignedInt (Compiler *
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_sint::class_func_max (SOURCE_FILE ("gtl_functions.galgas", 230)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 230)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_max_33__32_bitsSignedInt [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_max_33__32_bitsSignedInt (Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_max_33__32_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_max_33__32_bitsSignedInt ("max32bitsSignedInt",
                                                                          functionWithGenericHeader_max_33__32_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_max_33__32_bitsSignedInt) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'min32bitsSignedInt'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint function_min_33__32_bitsSignedInt (Compiler *
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_sint::class_func_min (SOURCE_FILE ("gtl_functions.galgas", 238)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 238)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_min_33__32_bitsSignedInt [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_min_33__32_bitsSignedInt (Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_min_33__32_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_min_33__32_bitsSignedInt ("min32bitsSignedInt",
                                                                          functionWithGenericHeader_min_33__32_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_min_33__32_bitsSignedInt) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'max64bitsUnsignedInt'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint function_max_36__34_bitsUnsignedInt (Compiler *
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_uint_36__34_::class_func_max (SOURCE_FILE ("gtl_functions.galgas", 246)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 246)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_max_36__34_bitsUnsignedInt [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_max_36__34_bitsUnsignedInt (Compiler * inCompiler,
                                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  return function_max_36__34_bitsUnsignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_max_36__34_bitsUnsignedInt ("max64bitsUnsignedInt",
                                                                            functionWithGenericHeader_max_36__34_bitsUnsignedInt,
                                                                            & kTypeDescriptor_GALGAS_bigint,
                                                                            0,
                                                                            functionArgs_max_36__34_bitsUnsignedInt) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'max64bitsSignedInt'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint function_max_36__34_bitsSignedInt (Compiler *
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_sint_36__34_::class_func_max (SOURCE_FILE ("gtl_functions.galgas", 254)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 254)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_max_36__34_bitsSignedInt [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_max_36__34_bitsSignedInt (Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_max_36__34_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_max_36__34_bitsSignedInt ("max64bitsSignedInt",
                                                                          functionWithGenericHeader_max_36__34_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_max_36__34_bitsSignedInt) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'min64bitsSignedInt'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint function_min_36__34_bitsSignedInt (Compiler *
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_sint_36__34_::class_func_min (SOURCE_FILE ("gtl_functions.galgas", 262)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 262)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_min_36__34_bitsSignedInt [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_min_36__34_bitsSignedInt (Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_min_36__34_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_min_36__34_bitsSignedInt ("min64bitsSignedInt",
                                                                          functionWithGenericHeader_min_36__34_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_min_36__34_bitsSignedInt) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'pi'
//
//--------------------------------------------------------------------------------------------------

GALGAS_double function_pi (Compiler *
                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  result_result = GALGAS_double::class_func_pi (SOURCE_FILE ("gtl_functions.galgas", 270)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_pi [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_pi (Compiler * inCompiler,
                                                   const cObjectArray & /* inEffectiveParameterArray */,
                                                   const GALGAS_location & /* inErrorLocation */
                                                   COMMA_LOCATION_ARGS) {
  return function_pi (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_pi ("pi",
                                                    functionWithGenericHeader_pi,
                                                    & kTypeDescriptor_GALGAS_double,
                                                    0,
                                                    functionArgs_pi) ;

//--------------------------------------------------------------------------------------------------
//
//                               Bool options                                                    
//
//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------
//
//                               UInt options                                                    
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//
//                              String options                                                   
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//
//                              String List options                                              
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//
//Function 'signature'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_signature (GALGAS_location inArgument_loc,
                                  Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (gOption_gtl_5F_options_debug.readProperty_value ()).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_string var_signatureString_779 = inArgument_loc.getter_file (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 33)).getter_lastPathComponent (SOURCE_FILE ("gtl_debugger.galgas", 33)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 33)).add_operation (inArgument_loc.getter_endLine (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 35)).getter_string (SOURCE_FILE ("gtl_debugger.galgas", 34)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 34)) ;
      result_result = var_signatureString_779.getter_md_35_ (SOURCE_FILE ("gtl_debugger.galgas", 36)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_signature [2] = {
  & kTypeDescriptor_GALGAS_location,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_signature (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_signature ("signature",
                                                           functionWithGenericHeader_signature,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_signature) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'bold'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_bold (Compiler *
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_bold ; // Returned variable
  result_bold = GALGAS_string ("[1m") ;
//---
  return result_bold ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_bold = false ;
static GALGAS_string gOnceFunctionResult_bold ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_bold (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_bold) {
    gOnceFunctionResult_bold = onceFunction_bold (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_bold = true ;
  }
  return gOnceFunctionResult_bold ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_bold (void) {
  gOnceFunctionResult_bold.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_bold (nullptr,
                                                releaseOnceFunctionResult_bold) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_bold [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_bold (Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_bold (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_bold ("bold",
                                                      functionWithGenericHeader_bold,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_bold) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'underline'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_underline (Compiler *
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_underline ; // Returned variable
  result_underline = GALGAS_string ("[4m") ;
//---
  return result_underline ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_underline = false ;
static GALGAS_string gOnceFunctionResult_underline ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_underline (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_underline) {
    gOnceFunctionResult_underline = onceFunction_underline (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_underline = true ;
  }
  return gOnceFunctionResult_underline ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_underline (void) {
  gOnceFunctionResult_underline.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_underline (nullptr,
                                                     releaseOnceFunctionResult_underline) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_underline [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_underline (Compiler * inCompiler,
                                                          const cObjectArray & /* inEffectiveParameterArray */,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  return function_underline (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_underline ("underline",
                                                           functionWithGenericHeader_underline,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           0,
                                                           functionArgs_underline) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'blink'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_blink (Compiler *
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_blink ; // Returned variable
  result_blink = GALGAS_string ("[5m") ;
//---
  return result_blink ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_blink = false ;
static GALGAS_string gOnceFunctionResult_blink ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_blink (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_blink) {
    gOnceFunctionResult_blink = onceFunction_blink (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_blink = true ;
  }
  return gOnceFunctionResult_blink ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_blink (void) {
  gOnceFunctionResult_blink.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_blink (nullptr,
                                                 releaseOnceFunctionResult_blink) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_blink [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_blink (Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_blink (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_blink ("blink",
                                                       functionWithGenericHeader_blink,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_blink) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'black'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_black (Compiler *
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_black ; // Returned variable
  result_black = GALGAS_string ("[90m") ;
//---
  return result_black ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_black = false ;
static GALGAS_string gOnceFunctionResult_black ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_black (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_black) {
    gOnceFunctionResult_black = onceFunction_black (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_black = true ;
  }
  return gOnceFunctionResult_black ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_black (void) {
  gOnceFunctionResult_black.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_black (nullptr,
                                                 releaseOnceFunctionResult_black) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_black [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_black (Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_black (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_black ("black",
                                                       functionWithGenericHeader_black,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_black) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'red'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_red (Compiler *
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_red ; // Returned variable
  result_red = GALGAS_string ("[91m") ;
//---
  return result_red ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_red = false ;
static GALGAS_string gOnceFunctionResult_red ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_red (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_red) {
    gOnceFunctionResult_red = onceFunction_red (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_red = true ;
  }
  return gOnceFunctionResult_red ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_red (void) {
  gOnceFunctionResult_red.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_red (nullptr,
                                               releaseOnceFunctionResult_red) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_red [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_red (Compiler * inCompiler,
                                                    const cObjectArray & /* inEffectiveParameterArray */,
                                                    const GALGAS_location & /* inErrorLocation */
                                                    COMMA_LOCATION_ARGS) {
  return function_red (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_red ("red",
                                                     functionWithGenericHeader_red,
                                                     & kTypeDescriptor_GALGAS_string,
                                                     0,
                                                     functionArgs_red) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'green'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_green (Compiler *
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_green ; // Returned variable
  result_green = GALGAS_string ("[92m") ;
//---
  return result_green ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_green = false ;
static GALGAS_string gOnceFunctionResult_green ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_green (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_green) {
    gOnceFunctionResult_green = onceFunction_green (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_green = true ;
  }
  return gOnceFunctionResult_green ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_green (void) {
  gOnceFunctionResult_green.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_green (nullptr,
                                                 releaseOnceFunctionResult_green) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_green [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_green (Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_green (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_green ("green",
                                                       functionWithGenericHeader_green,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_green) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'yellow'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_yellow (Compiler *
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_yellow ; // Returned variable
  result_yellow = GALGAS_string ("[93m") ;
//---
  return result_yellow ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_yellow = false ;
static GALGAS_string gOnceFunctionResult_yellow ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_yellow (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_yellow) {
    gOnceFunctionResult_yellow = onceFunction_yellow (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_yellow = true ;
  }
  return gOnceFunctionResult_yellow ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_yellow (void) {
  gOnceFunctionResult_yellow.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_yellow (nullptr,
                                                  releaseOnceFunctionResult_yellow) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_yellow [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_yellow (Compiler * inCompiler,
                                                       const cObjectArray & /* inEffectiveParameterArray */,
                                                       const GALGAS_location & /* inErrorLocation */
                                                       COMMA_LOCATION_ARGS) {
  return function_yellow (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_yellow ("yellow",
                                                        functionWithGenericHeader_yellow,
                                                        & kTypeDescriptor_GALGAS_string,
                                                        0,
                                                        functionArgs_yellow) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'blue'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_blue (Compiler *
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_blue ; // Returned variable
  result_blue = GALGAS_string ("[94m") ;
//---
  return result_blue ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_blue = false ;
static GALGAS_string gOnceFunctionResult_blue ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_blue (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_blue) {
    gOnceFunctionResult_blue = onceFunction_blue (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_blue = true ;
  }
  return gOnceFunctionResult_blue ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_blue (void) {
  gOnceFunctionResult_blue.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_blue (nullptr,
                                                releaseOnceFunctionResult_blue) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_blue [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_blue (Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_blue (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_blue ("blue",
                                                      functionWithGenericHeader_blue,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_blue) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'magenta'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_magenta (Compiler *
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_magenta ; // Returned variable
  result_magenta = GALGAS_string ("[95m") ;
//---
  return result_magenta ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_magenta = false ;
static GALGAS_string gOnceFunctionResult_magenta ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_magenta (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_magenta) {
    gOnceFunctionResult_magenta = onceFunction_magenta (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_magenta = true ;
  }
  return gOnceFunctionResult_magenta ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_magenta (void) {
  gOnceFunctionResult_magenta.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_magenta (nullptr,
                                                   releaseOnceFunctionResult_magenta) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_magenta [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_magenta (Compiler * inCompiler,
                                                        const cObjectArray & /* inEffectiveParameterArray */,
                                                        const GALGAS_location & /* inErrorLocation */
                                                        COMMA_LOCATION_ARGS) {
  return function_magenta (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_magenta ("magenta",
                                                         functionWithGenericHeader_magenta,
                                                         & kTypeDescriptor_GALGAS_string,
                                                         0,
                                                         functionArgs_magenta) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'cyan'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_cyan (Compiler *
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_cyan ; // Returned variable
  result_cyan = GALGAS_string ("[96m") ;
//---
  return result_cyan ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_cyan = false ;
static GALGAS_string gOnceFunctionResult_cyan ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_cyan (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_cyan) {
    gOnceFunctionResult_cyan = onceFunction_cyan (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_cyan = true ;
  }
  return gOnceFunctionResult_cyan ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_cyan (void) {
  gOnceFunctionResult_cyan.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_cyan (nullptr,
                                                releaseOnceFunctionResult_cyan) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_cyan [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_cyan (Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_cyan (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_cyan ("cyan",
                                                      functionWithGenericHeader_cyan,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_cyan) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'darkred'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_darkred (Compiler *
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_red ; // Returned variable
  result_red = GALGAS_string ("[31m") ;
//---
  return result_red ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_darkred = false ;
static GALGAS_string gOnceFunctionResult_darkred ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_darkred (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkred) {
    gOnceFunctionResult_darkred = onceFunction_darkred (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkred = true ;
  }
  return gOnceFunctionResult_darkred ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_darkred (void) {
  gOnceFunctionResult_darkred.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_darkred (nullptr,
                                                   releaseOnceFunctionResult_darkred) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkred [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_darkred (Compiler * inCompiler,
                                                        const cObjectArray & /* inEffectiveParameterArray */,
                                                        const GALGAS_location & /* inErrorLocation */
                                                        COMMA_LOCATION_ARGS) {
  return function_darkred (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_darkred ("darkred",
                                                         functionWithGenericHeader_darkred,
                                                         & kTypeDescriptor_GALGAS_string,
                                                         0,
                                                         functionArgs_darkred) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'darkgreen'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_darkgreen (Compiler *
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_green ; // Returned variable
  result_green = GALGAS_string ("[32m") ;
//---
  return result_green ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_darkgreen = false ;
static GALGAS_string gOnceFunctionResult_darkgreen ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_darkgreen (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkgreen) {
    gOnceFunctionResult_darkgreen = onceFunction_darkgreen (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkgreen = true ;
  }
  return gOnceFunctionResult_darkgreen ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_darkgreen (void) {
  gOnceFunctionResult_darkgreen.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_darkgreen (nullptr,
                                                     releaseOnceFunctionResult_darkgreen) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkgreen [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_darkgreen (Compiler * inCompiler,
                                                          const cObjectArray & /* inEffectiveParameterArray */,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  return function_darkgreen (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_darkgreen ("darkgreen",
                                                           functionWithGenericHeader_darkgreen,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           0,
                                                           functionArgs_darkgreen) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'darkyellow'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_darkyellow (Compiler *
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_yellow ; // Returned variable
  result_yellow = GALGAS_string ("[33m") ;
//---
  return result_yellow ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_darkyellow = false ;
static GALGAS_string gOnceFunctionResult_darkyellow ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_darkyellow (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkyellow) {
    gOnceFunctionResult_darkyellow = onceFunction_darkyellow (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkyellow = true ;
  }
  return gOnceFunctionResult_darkyellow ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_darkyellow (void) {
  gOnceFunctionResult_darkyellow.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_darkyellow (nullptr,
                                                      releaseOnceFunctionResult_darkyellow) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkyellow [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_darkyellow (Compiler * inCompiler,
                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  return function_darkyellow (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_darkyellow ("darkyellow",
                                                            functionWithGenericHeader_darkyellow,
                                                            & kTypeDescriptor_GALGAS_string,
                                                            0,
                                                            functionArgs_darkyellow) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'darkblue'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_darkblue (Compiler *
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_blue ; // Returned variable
  result_blue = GALGAS_string ("[34m") ;
//---
  return result_blue ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_darkblue = false ;
static GALGAS_string gOnceFunctionResult_darkblue ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_darkblue (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkblue) {
    gOnceFunctionResult_darkblue = onceFunction_darkblue (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkblue = true ;
  }
  return gOnceFunctionResult_darkblue ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_darkblue (void) {
  gOnceFunctionResult_darkblue.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_darkblue (nullptr,
                                                    releaseOnceFunctionResult_darkblue) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkblue [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_darkblue (Compiler * inCompiler,
                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  return function_darkblue (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_darkblue ("darkblue",
                                                          functionWithGenericHeader_darkblue,
                                                          & kTypeDescriptor_GALGAS_string,
                                                          0,
                                                          functionArgs_darkblue) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'darkmagenta'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_darkmagenta (Compiler *
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_magenta ; // Returned variable
  result_magenta = GALGAS_string ("[35m") ;
//---
  return result_magenta ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_darkmagenta = false ;
static GALGAS_string gOnceFunctionResult_darkmagenta ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_darkmagenta (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkmagenta) {
    gOnceFunctionResult_darkmagenta = onceFunction_darkmagenta (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkmagenta = true ;
  }
  return gOnceFunctionResult_darkmagenta ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_darkmagenta (void) {
  gOnceFunctionResult_darkmagenta.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_darkmagenta (nullptr,
                                                       releaseOnceFunctionResult_darkmagenta) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkmagenta [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_darkmagenta (Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_darkmagenta (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_darkmagenta ("darkmagenta",
                                                             functionWithGenericHeader_darkmagenta,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             0,
                                                             functionArgs_darkmagenta) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'darkcyan'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_darkcyan (Compiler *
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_cyan ; // Returned variable
  result_cyan = GALGAS_string ("[36m") ;
//---
  return result_cyan ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_darkcyan = false ;
static GALGAS_string gOnceFunctionResult_darkcyan ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_darkcyan (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkcyan) {
    gOnceFunctionResult_darkcyan = onceFunction_darkcyan (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkcyan = true ;
  }
  return gOnceFunctionResult_darkcyan ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_darkcyan (void) {
  gOnceFunctionResult_darkcyan.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_darkcyan (nullptr,
                                                    releaseOnceFunctionResult_darkcyan) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkcyan [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_darkcyan (Compiler * inCompiler,
                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  return function_darkcyan (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_darkcyan ("darkcyan",
                                                          functionWithGenericHeader_darkcyan,
                                                          & kTypeDescriptor_GALGAS_string,
                                                          0,
                                                          functionArgs_darkcyan) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'white'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_white (Compiler *
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_white ; // Returned variable
  result_white = GALGAS_string ("[97m") ;
//---
  return result_white ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_white = false ;
static GALGAS_string gOnceFunctionResult_white ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_white (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_white) {
    gOnceFunctionResult_white = onceFunction_white (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_white = true ;
  }
  return gOnceFunctionResult_white ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_white (void) {
  gOnceFunctionResult_white.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_white (nullptr,
                                                 releaseOnceFunctionResult_white) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_white [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_white (Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_white (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_white ("white",
                                                       functionWithGenericHeader_white,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_white) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'endc'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_endc (Compiler *
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_endc ; // Returned variable
  result_endc = GALGAS_string ("[0m") ;
//---
  return result_endc ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_endc = false ;
static GALGAS_string gOnceFunctionResult_endc ;

//--------------------------------------------------------------------------------------------------

GALGAS_string function_endc (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_endc) {
    gOnceFunctionResult_endc = onceFunction_endc (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_endc = true ;
  }
  return gOnceFunctionResult_endc ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_endc (void) {
  gOnceFunctionResult_endc.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_endc (nullptr,
                                                releaseOnceFunctionResult_endc) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_endc [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_endc (Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_endc (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_endc ("endc",
                                                      functionWithGenericHeader_endc,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_endc) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'defaultDebugSettings'
//
//--------------------------------------------------------------------------------------------------

GALGAS_debuggerContext function_defaultDebugSettings (Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_debuggerContext result_debugSettings ; // Returned variable
  result_debugSettings = GALGAS_debuggerContext::class_func_new (GALGAS_bool (gOption_gtl_5F_options_debug.readProperty_value ()), GALGAS_bool (gOption_gtl_5F_options_debug.readProperty_value ()), GALGAS_bool (false), function_red (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 404)), GALGAS_string::makeEmptyString (), function_blue (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 406)), function_bold (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 407)), function_darkgreen (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 408)), GALGAS_string::makeEmptyString (), function_darkyellow (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 410)), function_bold (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 411)), GALGAS_bool (false), GALGAS_gtlInstructionList::class_func_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 413)), GALGAS_gtlBreakpointList::class_func_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 414)), GALGAS_gtlExpressionList::class_func_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 415)), GALGAS_uint (uint32_t (0U)), GALGAS_gtlInstructionList::class_func_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 417)), GALGAS_gtlInstructionListContextStack::class_func_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 418)), GALGAS_debugCommandInput::class_func_new (GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 419))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 419))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 400)) ;
//---
  return result_debugSettings ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_defaultDebugSettings [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_defaultDebugSettings (Compiler * inCompiler,
                                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  return function_defaultDebugSettings (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_defaultDebugSettings ("defaultDebugSettings",
                                                                      functionWithGenericHeader_defaultDebugSettings,
                                                                      & kTypeDescriptor_GALGAS_debuggerContext,
                                                                      0,
                                                                      functionArgs_defaultDebugSettings) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemField stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlVarItemField::getter_stringRepresentation (const GALGAS_string constinArgument_concatString,
                                                                 Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = constinArgument_concatString.add_operation (this->mProperty_field.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 669)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemSubCollection stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlVarItemSubCollection::getter_stringRepresentation (const GALGAS_string /* constinArgument_concatString */,
                                                                         Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("[").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 677)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 677)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 677)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemCollection stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlVarItemCollection::getter_stringRepresentation (const GALGAS_string constinArgument_concatString,
                                                                      Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = constinArgument_concatString.add_operation (this->mProperty_field.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 685)).add_operation (GALGAS_char (TO_UNICODE (91)).getter_string (SOURCE_FILE ("gtl_debugger.galgas", 685)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 685)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 685)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 685)).add_operation (GALGAS_char (TO_UNICODE (93)).getter_string (SOURCE_FILE ("gtl_debugger.galgas", 685)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 685)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlAddExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlAddExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 696)).add_operation (GALGAS_string (" + "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 696)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 696)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 696)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlAndExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlAndExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 703)).add_operation (GALGAS_string (" & "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 703)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 703)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 703)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlDivideExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlDivideExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 710)).add_operation (GALGAS_string (" / "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 710)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 710)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 710)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEqualExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlEqualExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 717)).add_operation (GALGAS_string (" == "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 717)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 717)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 717)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlGreaterOrEqualExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlGreaterOrEqualExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 724)).add_operation (GALGAS_string (" >= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 724)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 724)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 724)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlGreaterThanExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlGreaterThanExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 731)).add_operation (GALGAS_string (" > "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 731)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 731)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 731)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLowerOrEqualExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlLowerOrEqualExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 738)).add_operation (GALGAS_string (" <= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 738)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 738)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 738)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLowerThanExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlLowerThanExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 745)).add_operation (GALGAS_string (" < "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 745)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 745)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 745)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlModulusExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlModulusExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 752)).add_operation (GALGAS_string (" mod "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 752)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 752)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 752)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMultiplyExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlMultiplyExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 759)).add_operation (GALGAS_string (" * "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 759)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 759)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 759)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlNotEqualExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlNotEqualExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 766)).add_operation (GALGAS_string (" != "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 766)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 766)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 766)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlOrExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlOrExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 773)).add_operation (GALGAS_string (" | "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 773)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 773)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 773)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlShiftLeftExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlShiftLeftExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 780)).add_operation (GALGAS_string (" << "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 780)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 780)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 780)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlShiftRightExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlShiftRightExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 787)).add_operation (GALGAS_string (" >> "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 787)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 787)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 787)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSubstractExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlSubstractExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 794)).add_operation (GALGAS_string (" - "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 794)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 794)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 794)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlXorExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlXorExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 801)).add_operation (GALGAS_string (" ^ "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 801)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 801)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 801)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExistsExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlExistsExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("exists ").add_operation (extensionGetter_stringRepresentation (this->mProperty_variable, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 808)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 808)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExistsDefaultExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlExistsDefaultExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("exists ").add_operation (extensionGetter_stringRepresentation (this->mProperty_variable, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 816)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 815)).add_operation (GALGAS_string (" default ( "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 816)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_defaultValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 818)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 817)).add_operation (GALGAS_string (" )"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 818)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFunctionCallExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlFunctionCallExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_functionName.readProperty_string ().add_operation (GALGAS_string ("("), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 826)).add_operation (extensionGetter_stringRepresentation (this->mProperty_functionArguments, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 826)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 826)).add_operation (GALGAS_string (")"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 826)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlGetterCallExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlGetterCallExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("[").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_target.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 833)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 833)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 833)).add_operation (this->mProperty_getterName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 833)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, this->mProperty_arguments.getter_count (SOURCE_FILE ("gtl_debugger.galgas", 834)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = result_result.add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 835)).add_operation (extensionGetter_stringRepresentation (this->mProperty_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 835)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 835)) ;
    }
  }
  result_result = result_result.add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 837)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlListOfExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlListOfExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("listof ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_expression.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 844)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 844)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLiteralListExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlLiteralListExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@( ").add_operation (extensionGetter_stringRepresentation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 851)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 851)).add_operation (GALGAS_string (" )"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 851)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLiteralMapExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlLiteralMapExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@[ ").add_operation (extensionGetter_mapRepresentation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 858)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 858)).add_operation (GALGAS_string (" ]"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 858)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLiteralSetExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlLiteralSetExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@! ").add_operation (extensionGetter_stringRepresentation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 865)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 865)).add_operation (GALGAS_string (" !"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 865)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLiteralStructExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlLiteralStructExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@{ ").add_operation (extensionGetter_structRepresentation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 872)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 872)).add_operation (GALGAS_string (" }"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 872)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMapOfStructExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlMapOfStructExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("mapof ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_expression.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 879)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 879)).add_operation (GALGAS_string (" end"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 879)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlTerminal stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlTerminal::getter_stringRepresentation (Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlData *) this->mProperty_value.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 886)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlTypeOfExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlTypeOfExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("typeof ").add_operation (extensionGetter_stringRepresentation (this->mProperty_variable, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 893)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 893)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMinusExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlMinusExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("-").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_son.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 900)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 900)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlNotExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlNotExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("not ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_son.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 907)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 907)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlParenthesizedExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlParenthesizedExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("(").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_son.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 914)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 914)).add_operation (GALGAS_string (")"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 914)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlPlusExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlPlusExpression::getter_stringRepresentation (Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("+").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_son.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 921)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 921)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarRef stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlVarRef::getter_stringRepresentation (Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = extensionGetter_stringRepresentation (this->mProperty_variableName, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 928)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlAllVarsRef stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlAllVarsRef::getter_stringRepresentation (Compiler */* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("__VARS__") ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlBool::getter_stringRepresentation (Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_gtlBool temp_0 = this ;
  result_result = callExtensionGetter_string ((const cPtr_gtlBool *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 946)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlChar::getter_stringRepresentation (Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_gtlChar temp_0 = this ;
  result_result = callExtensionGetter_string ((const cPtr_gtlChar *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 953)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlEnum::getter_stringRepresentation (Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_gtlEnum temp_0 = this ;
  result_result = GALGAS_string ("$").add_operation (callExtensionGetter_string ((const cPtr_gtlEnum *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 960)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 960)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlFloat::getter_stringRepresentation (Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_gtlFloat temp_0 = this ;
  result_result = callExtensionGetter_string ((const cPtr_gtlFloat *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 967)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlInt::getter_stringRepresentation (Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_gtlInt temp_0 = this ;
  result_result = callExtensionGetter_string ((const cPtr_gtlInt *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 974)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlString::getter_stringRepresentation (Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_gtlString temp_0 = this ;
  GALGAS_string var_literalString_30162 = callExtensionGetter_string ((const cPtr_gtlString *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 981)) ;
  var_literalString_30162 = var_literalString_30162.getter_stringByReplacingStringByString (GALGAS_string ("\n"), GALGAS_string ("\\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 982)) ;
  var_literalString_30162 = var_literalString_30162.getter_stringByReplacingStringByString (GALGAS_string ("	"), GALGAS_string ("\\t"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 983)) ;
  var_literalString_30162 = var_literalString_30162.getter_stringByReplacingStringByString (GALGAS_string (""), GALGAS_string ("\\f"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 984)) ;
  var_literalString_30162 = var_literalString_30162.getter_stringByReplacingStringByString (GALGAS_string ("\r"), GALGAS_string ("\\r"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 985)) ;
  var_literalString_30162 = var_literalString_30162.getter_stringByReplacingStringByString (GALGAS_string (""), GALGAS_string ("\\v"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 986)) ;
  var_literalString_30162 = var_literalString_30162.getter_stringByReplacingStringByString (GALGAS_string ("\\"), GALGAS_string ("\\\\"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 987)) ;
  var_literalString_30162 = var_literalString_30162.getter_stringByReplacingStringByString (GALGAS_string ("\""), GALGAS_string ("\\\""), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 988)) ;
  result_result = GALGAS_string ("\"").add_operation (var_literalString_30162, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 989)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 989)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlUnconstructed::getter_stringRepresentation (Compiler */* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("*UNCONSTRUCTED*") ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlType::getter_stringRepresentation (Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_gtlType temp_0 = this ;
  result_result = GALGAS_string ("@").add_operation (callExtensionGetter_string ((const cPtr_gtlType *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1003)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1003)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlList::getter_stringRepresentation (Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@( ") ;
  cEnumerator_list enumerator_31342 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_31342.hasCurrentObject ()) {
    result_result = result_result.add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlData *) enumerator_31342.current_value (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1012)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1012)) ;
    if (enumerator_31342.hasNextObject ()) {
      result_result = result_result.add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1014)) ;
    }
    enumerator_31342.gotoNextObject () ;
  }
  result_result = result_result.add_operation (GALGAS_string (" )"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1016)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlMap::getter_stringRepresentation (Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@[ ") ;
  cEnumerator_gtlVarMap enumerator_31655 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_31655.hasCurrentObject ()) {
    result_result = result_result.add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1025)).add_operation (enumerator_31655.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1025)).add_operation (GALGAS_string ("\": "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1025)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlData *) enumerator_31655.current_value (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1025)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1025)) ;
    if (enumerator_31655.hasNextObject ()) {
      result_result = result_result.add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1027)) ;
    }
    enumerator_31655.gotoNextObject () ;
  }
  result_result = result_result.add_operation (GALGAS_string (" ]"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1029)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlStruct::getter_stringRepresentation (Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@{ ") ;
  cEnumerator_gtlVarMap enumerator_31995 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_31995.hasCurrentObject ()) {
    result_result = result_result.add_operation (enumerator_31995.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1038)).add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1038)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlData *) enumerator_31995.current_value (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1038)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1038)) ;
    if (enumerator_31995.hasNextObject ()) {
      result_result = result_result.add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1040)) ;
    }
    enumerator_31995.gotoNextObject () ;
  }
  result_result = result_result.add_operation (GALGAS_string (" }"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1042)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlSet::getter_stringRepresentation (Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@! ") ;
  cEnumerator_lstringset enumerator_32319 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_32319.hasCurrentObject ()) {
    result_result = result_result.add_operation (enumerator_32319.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1051)) ;
    if (enumerator_32319.hasNextObject ()) {
      result_result = result_result.add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1053)) ;
    }
    enumerator_32319.gotoNextObject () ;
  }
  result_result = result_result.add_operation (GALGAS_string (" !"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1055)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlExpr::getter_stringRepresentation (Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@\? ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_value.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1062)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1062)).add_operation (GALGAS_string (" \?"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1062)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetUnconstructedInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetUnconstructedInstruction::method_display (Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1161)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1161))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1161)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetInstruction::method_display (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1168)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1167)).add_operation (GALGAS_string (" := "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1168)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1170)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1169))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1167)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetAddInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetAddInstruction::method_display (Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1177)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1176)).add_operation (GALGAS_string (" += "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1177)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1179)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1178))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1176)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetSubstractInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetSubstractInstruction::method_display (Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1186)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1185)).add_operation (GALGAS_string (" -= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1186)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1188)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1187))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1185)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetMultiplyInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetMultiplyInstruction::method_display (Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1195)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1194)).add_operation (GALGAS_string (" *= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1195)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1197)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1196))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1194)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetDivideInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetDivideInstruction::method_display (Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1204)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1203)).add_operation (GALGAS_string (" /= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1204)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1206)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1205))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1203)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetModuloInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetModuloInstruction::method_display (Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1213)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1212)).add_operation (GALGAS_string (" mod= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1213)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1215)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1214))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1212)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetShiftLeftInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetShiftLeftInstruction::method_display (Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1222)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1221)).add_operation (GALGAS_string (" <<= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1222)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1224)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1223))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1221)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetShiftRightInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetShiftRightInstruction::method_display (Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1231)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1230)).add_operation (GALGAS_string (" >>= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1231)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1233)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1232))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1230)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetAndInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetAndInstruction::method_display (Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1240)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1239)).add_operation (GALGAS_string (" &= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1240)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1242)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1241))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1239)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetOrInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetOrInstruction::method_display (Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1249)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1248)).add_operation (GALGAS_string (" |= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1249)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1251)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1250))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1248)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetXorInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLetXorInstruction::method_display (Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1258)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1257)).add_operation (GALGAS_string (" ^= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1258)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1260)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1259))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1257)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLoopStatementInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLoopStatementInstruction::method_display (Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWarningStatementInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlWarningStatementInstruction::method_display (Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlErrorStatementInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlErrorStatementInstruction::method_display (Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDisplayStatementInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlDisplayStatementInstruction::method_display (Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("display ").add_operation (extensionGetter_stringRepresentation (this->mProperty_variablePath, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1299)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1299))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1299)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlPrintStatementInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlPrintStatementInstruction::method_display (Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlTemplateStringInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlTemplateStringInstruction::method_display (Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("%").add_operation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1313)).add_operation (GALGAS_string ("%"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1313))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1313)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlInputStatementInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlInputStatementInstruction::method_display (Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("input ( ").add_operation (extensionGetter_stringRepresentation (this->mProperty_formalArguments, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1319)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1319)).add_operation (GALGAS_string (" )"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1319))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1319)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlSortStatementInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlSortStatementInstruction::method_display (Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("sort ").add_operation (extensionGetter_stringRepresentation (this->mProperty_variablePath, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1326)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1325)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1326)).add_operation (extensionGetter_stringRepresentation (this->mProperty_order, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1328)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1327))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1325)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlSortStatementStructInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlSortStatementStructInstruction::method_display (Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("sort ").add_operation (extensionGetter_stringRepresentation (this->mProperty_variablePath, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1335)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1334)).add_operation (GALGAS_string (" by "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1335)).add_operation (extensionGetter_stringRepresentation (this->mProperty_sortingKey, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1337)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1336))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1334)) ;
}

#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-10.h"

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'checkAndGetIntegerNumber'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_object_5F_t function_checkAndGetIntegerNumber (const GALGAS_lstring & constinArgument_oil_5F_desc,
                                                      const GALGAS_dataType & constinArgument_type,
                                                      const GALGAS_luint_36__34_ & constinArgument_number,
                                                      const GALGAS_bool & constinArgument_signed,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_value ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_signed.boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 845)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_value = GALGAS_sint_33__32__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location (), constinArgument_number.readProperty_uint_36__34_ ().getter_sint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 846)).multiply_operation (GALGAS_sint (int32_t (-1L)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 846))  COMMA_SOURCE_FILE ("implementation_types.galgas", 846)) ;
        }
      }
      if (kBoolFalse == test_1) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 847)))).boolEnum () ;
          if (kBoolTrue == test_2) {
            result_value = GALGAS_sint_36__34__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location (), constinArgument_number.readProperty_uint_36__34_ ().getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 848)).multiply_operation (GALGAS_sint_36__34_ (int64_t (-1LL)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 848))  COMMA_SOURCE_FILE ("implementation_types.galgas", 848)) ;
          }
        }
        if (kBoolFalse == test_2) {
          result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location ()  COMMA_SOURCE_FILE ("implementation_types.galgas", 850)) ;
          TC_Array <C_FixItDescription> fixItArray3 ;
          inCompiler->emitSemanticError (constinArgument_number.readProperty_location (), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 851)).add_operation (GALGAS_string (" expected, got a SINT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 851)), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 851)) ;
        }
      }
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_4 = kBoolTrue ;
    if (kBoolTrue == test_4) {
      test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 854)))).boolEnum () ;
      if (kBoolTrue == test_4) {
        result_value = GALGAS_sint_33__32__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location (), constinArgument_number.readProperty_uint_36__34_ ().getter_sint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 855))  COMMA_SOURCE_FILE ("implementation_types.galgas", 855)) ;
      }
    }
    if (kBoolFalse == test_4) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 856)))).boolEnum () ;
        if (kBoolTrue == test_5) {
          result_value = GALGAS_sint_36__34__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location (), constinArgument_number.readProperty_uint_36__34_ ().getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 857))  COMMA_SOURCE_FILE ("implementation_types.galgas", 857)) ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_6 = kBoolTrue ;
        if (kBoolTrue == test_6) {
          test_6 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 858)))).boolEnum () ;
          if (kBoolTrue == test_6) {
            result_value = GALGAS_uint_33__32__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location (), constinArgument_number.readProperty_uint_36__34_ ().getter_uint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 859))  COMMA_SOURCE_FILE ("implementation_types.galgas", 859)) ;
          }
        }
        if (kBoolFalse == test_6) {
          enumGalgasBool test_7 = kBoolTrue ;
          if (kBoolTrue == test_7) {
            test_7 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 860)))).boolEnum () ;
            if (kBoolTrue == test_7) {
              result_value = GALGAS_uint_36__34__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location (), constinArgument_number.readProperty_uint_36__34_ ()  COMMA_SOURCE_FILE ("implementation_types.galgas", 861)) ;
            }
          }
          if (kBoolFalse == test_7) {
            result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location ()  COMMA_SOURCE_FILE ("implementation_types.galgas", 863)) ;
            TC_Array <C_FixItDescription> fixItArray8 ;
            inCompiler->emitSemanticError (constinArgument_number.readProperty_location (), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 864)).add_operation (GALGAS_string (" expected, got a UINT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 864)), fixItArray8  COMMA_SOURCE_FILE ("implementation_types.galgas", 864)) ;
          }
        }
      }
    }
  }
//---
  return result_value ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_checkAndGetIntegerNumber [5] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_luint_36__34_,
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_checkAndGetIntegerNumber (C_Compiler * inCompiler,
                                                                         const cObjectArray & inEffectiveParameterArray,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_dataType operand1 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  const GALGAS_luint_36__34_ operand2 = GALGAS_luint_36__34_::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  const GALGAS_bool operand3 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (3 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_checkAndGetIntegerNumber (operand0,
                                            operand1,
                                            operand2,
                                            operand3,
                                            inCompiler
                                            COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_checkAndGetIntegerNumber ("checkAndGetIntegerNumber",
                                                                          functionWithGenericHeader_checkAndGetIntegerNumber,
                                                                          & kTypeDescriptor_GALGAS_object_5F_t,
                                                                          4,
                                                                          functionArgs_checkAndGetIntegerNumber) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'checkAndGetFloatNumber'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_object_5F_t function_checkAndGetFloatNumber (const GALGAS_lstring & constinArgument_oil_5F_desc,
                                                    const GALGAS_dataType & constinArgument_type,
                                                    const GALGAS_ldouble & constinArgument_number,
                                                    const GALGAS_bool & constinArgument_signed,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_value ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_signed.boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_types.galgas", 876)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_value = GALGAS_float_5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location (), constinArgument_number.readProperty_double ().multiply_operation (GALGAS_double (1).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 877)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 877))  COMMA_SOURCE_FILE ("implementation_types.galgas", 877)) ;
        }
      }
      if (kBoolFalse == test_1) {
        result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location ()  COMMA_SOURCE_FILE ("implementation_types.galgas", 879)) ;
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (constinArgument_number.readProperty_location (), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 880)).add_operation (GALGAS_string (" expected, got a FLOAT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 880)), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 880)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_types.galgas", 883)))).boolEnum () ;
      if (kBoolTrue == test_3) {
        result_value = GALGAS_float_5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location (), constinArgument_number.readProperty_double ()  COMMA_SOURCE_FILE ("implementation_types.galgas", 884)) ;
      }
    }
    if (kBoolFalse == test_3) {
      result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location ()  COMMA_SOURCE_FILE ("implementation_types.galgas", 886)) ;
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (constinArgument_number.readProperty_location (), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 887)).add_operation (GALGAS_string (" expected, got a FLOAT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 887)), fixItArray4  COMMA_SOURCE_FILE ("implementation_types.galgas", 887)) ;
    }
  }
//---
  return result_value ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_checkAndGetFloatNumber [5] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_ldouble,
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_checkAndGetFloatNumber (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_dataType operand1 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  const GALGAS_ldouble operand2 = GALGAS_ldouble::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_bool operand3 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (3 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_checkAndGetFloatNumber (operand0,
                                          operand1,
                                          operand2,
                                          operand3,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_checkAndGetFloatNumber ("checkAndGetFloatNumber",
                                                                        functionWithGenericHeader_checkAndGetFloatNumber,
                                                                        & kTypeDescriptor_GALGAS_object_5F_t,
                                                                        4,
                                                                        functionArgs_checkAndGetFloatNumber) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'checkTypeForAttribute'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_checkTypeForAttribute (const GALGAS_implementationObjectMap constinArgument_obj,
                                    const GALGAS_string constinArgument_attributeName,
                                    const GALGAS_dataType constinArgument_expectedType,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_obj.getter_hasKey (constinArgument_attributeName COMMA_SOURCE_FILE ("implementation_types.galgas", 896)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_impType var_type_25241 ;
      constinArgument_obj.method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 898)), var_type_25241, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 898)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsNotEqual, var_type_25241.readProperty_type ().objectCompare (constinArgument_expectedType)).boolEnum () ;
        if (kBoolTrue == test_1) {
          cEnumerator_locationList enumerator_25343 (var_type_25241.readProperty_locations (), kENUMERATION_UP) ;
          while (enumerator_25343.hasCurrentObject ()) {
            TC_Array <C_FixItDescription> fixItArray2 ;
            inCompiler->emitSemanticError (enumerator_25343.current_location (HERE), constinArgument_attributeName.add_operation (GALGAS_string (" is a "), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 901)).add_operation (extensionGetter_oilType (var_type_25241.readProperty_type (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 901)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 901)), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 901)) ;
            TC_Array <C_FixItDescription> fixItArray3 ;
            inCompiler->emitSemanticError (enumerator_25343.current_location (HERE), constinArgument_attributeName.add_operation (GALGAS_string (" should be a "), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 902)).add_operation (extensionGetter_oilType (constinArgument_expectedType, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 902)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 902)), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 902)) ;
            enumerator_25343.gotoNextObject () ;
          }
        }
      }
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Function 'boolSubAttributes'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap function_boolSubAttributes (const GALGAS_implementationObject & constinArgument_obj,
                                                           const GALGAS_string & constinArgument_attributeName,
                                                           const GALGAS_bool & constinArgument_boolValue,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result_subImplementation ; // Returned variable
  result_subImplementation = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 913)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_obj.readProperty_attributes ().getter_hasKey (constinArgument_attributeName COMMA_SOURCE_FILE ("implementation_types.galgas", 914)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_impType var_type_25826 ;
      constinArgument_obj.readProperty_attributes ().method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 916)), var_type_25826, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 916)) ;
      if (var_type_25826.isValid ()) {
        if (var_type_25826.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impBoolType) {
          GALGAS_impBoolType cast_25936_boolType ((cPtr_impBoolType *) var_type_25826.ptr ()) ;
          enumGalgasBool test_1 = kBoolTrue ;
          if (kBoolTrue == test_1) {
            test_1 = constinArgument_boolValue.boolEnum () ;
            if (kBoolTrue == test_1) {
              result_subImplementation = cast_25936_boolType.readProperty_trueSubAttributes () ;
            }
          }
          if (kBoolFalse == test_1) {
            result_subImplementation = cast_25936_boolType.readProperty_falseSubAttributes () ;
          }
        }
      }
    }
  }
//---
  return result_subImplementation ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_boolSubAttributes [4] = {
  & kTypeDescriptor_GALGAS_implementationObject,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_boolSubAttributes (C_Compiler * inCompiler,
                                                                  const cObjectArray & inEffectiveParameterArray,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  const GALGAS_implementationObject operand0 = GALGAS_implementationObject::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                           inCompiler
                                                                                           COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_bool operand2 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_boolSubAttributes (operand0,
                                     operand1,
                                     operand2,
                                     inCompiler
                                     COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_boolSubAttributes ("boolSubAttributes",
                                                                   functionWithGenericHeader_boolSubAttributes,
                                                                   & kTypeDescriptor_GALGAS_implementationObjectMap,
                                                                   3,
                                                                   functionArgs_boolSubAttributes) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'enumSubAttributes'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap function_enumSubAttributes (const GALGAS_implementationObject & constinArgument_obj,
                                                           const GALGAS_string & constinArgument_attributeName,
                                                           const GALGAS_string & constinArgument_enumValue,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result_subImplementation ; // Returned variable
  result_subImplementation = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 933)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_obj.readProperty_attributes ().getter_hasKey (constinArgument_attributeName COMMA_SOURCE_FILE ("implementation_types.galgas", 934)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_impType var_type_26409 ;
      constinArgument_obj.readProperty_attributes ().method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 936)), var_type_26409, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 936)) ;
      if (var_type_26409.isValid ()) {
        if (var_type_26409.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
          GALGAS_impEnumType cast_26519_enumType ((cPtr_impEnumType *) var_type_26409.ptr ()) ;
          enumGalgasBool test_1 = kBoolTrue ;
          if (kBoolTrue == test_1) {
            test_1 = cast_26519_enumType.readProperty_valuesMap ().getter_hasKey (constinArgument_enumValue COMMA_SOURCE_FILE ("implementation_types.galgas", 939)).boolEnum () ;
            if (kBoolTrue == test_1) {
              cast_26519_enumType.readProperty_valuesMap ().method_get (function_lstringWith (constinArgument_enumValue, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 940)), result_subImplementation, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 940)) ;
            }
          }
        }
      }
    }
  }
//---
  return result_subImplementation ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_enumSubAttributes [4] = {
  & kTypeDescriptor_GALGAS_implementationObject,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_enumSubAttributes (C_Compiler * inCompiler,
                                                                  const cObjectArray & inEffectiveParameterArray,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  const GALGAS_implementationObject operand0 = GALGAS_implementationObject::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                           inCompiler
                                                                                           COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand2 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_enumSubAttributes (operand0,
                                     operand1,
                                     operand2,
                                     inCompiler
                                     COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_enumSubAttributes ("enumSubAttributes",
                                                                   functionWithGenericHeader_enumSubAttributes,
                                                                   & kTypeDescriptor_GALGAS_implementationObjectMap,
                                                                   3,
                                                                   functionArgs_enumSubAttributes) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'checkFilters'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_checkFilters (const GALGAS_implementationObject constinArgument_messageProperty,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap var_filter_26805 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWEQUALSX"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 951)) ;
  {
  routine_checkTypeForAttribute (var_filter_26805, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 952)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 952)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_26805, GALGAS_string ("X"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 953)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 953)) ;
  }
  var_filter_26805 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWDIFFERSX"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 954)) ;
  {
  routine_checkTypeForAttribute (var_filter_26805, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 955)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 955)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_26805, GALGAS_string ("X"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 956)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 956)) ;
  }
  var_filter_26805 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWEQUALSMASKEDOLD"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 957)) ;
  {
  routine_checkTypeForAttribute (var_filter_26805, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 958)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 958)) ;
  }
  var_filter_26805 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("NEWISWITHIN"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 959)) ;
  {
  routine_checkTypeForAttribute (var_filter_26805, GALGAS_string ("MIN"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 960)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 960)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_26805, GALGAS_string ("MAX"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 961)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 961)) ;
  }
  var_filter_26805 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("NEWISOUTSIDE"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 962)) ;
  {
  routine_checkTypeForAttribute (var_filter_26805, GALGAS_string ("MIN"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 963)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 963)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_26805, GALGAS_string ("MAX"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 964)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 964)) ;
  }
  var_filter_26805 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("ONEEVERYN"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 965)) ;
  {
  routine_checkTypeForAttribute (var_filter_26805, GALGAS_string ("PERIOD"), GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 966)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 966)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_26805, GALGAS_string ("OFFSET"), GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 967)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 967)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@refType checkAttributeReferences'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_refType::method_checkAttributeReferences (const GALGAS_implementation constinArgument_imp,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasKey ((const cPtr_implementation *) constinArgument_imp.ptr (), this->mProperty_ref.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 982)).operator_not (SOURCE_FILE ("implementation_types.galgas", 982)).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (this->mProperty_ref.readProperty_location (), this->mProperty_ref.readProperty_string ().add_operation (GALGAS_string (" object kind does not exist"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 983)), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 983)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@impBoolType checkAttributeReferences'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_impBoolType::method_checkAttributeReferences (const GALGAS_implementation constinArgument_imp,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_implementationObjectMap enumerator_28673 (this->mProperty_trueSubAttributes, kENUMERATION_UP) ;
  while (enumerator_28673.hasCurrentObject ()) {
    callExtensionMethod_checkAttributeReferences ((cPtr_impType *) enumerator_28673.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 991)) ;
    enumerator_28673.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_28755 (this->mProperty_falseSubAttributes, kENUMERATION_UP) ;
  while (enumerator_28755.hasCurrentObject ()) {
    callExtensionMethod_checkAttributeReferences ((cPtr_impType *) enumerator_28755.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 994)) ;
    enumerator_28755.gotoNextObject () ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@impEnumType checkAttributeReferences'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_impEnumType::method_checkAttributeReferences (const GALGAS_implementation constinArgument_imp,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_enumValues enumerator_28924 (this->mProperty_valuesMap, kENUMERATION_UP) ;
  while (enumerator_28924.hasCurrentObject ()) {
    cEnumerator_implementationObjectMap enumerator_28952 (enumerator_28924.current_subAttributes (HERE), kENUMERATION_UP) ;
    while (enumerator_28952.hasCurrentObject ()) {
      callExtensionMethod_checkAttributeReferences ((cPtr_impType *) enumerator_28952.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1003)) ;
      enumerator_28952.gotoNextObject () ;
    }
    enumerator_28924.gotoNextObject () ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'setDefaultsForType'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_setDefaultsForType (const GALGAS_implementationObjectMap constinArgument_impObject,
                                 GALGAS_objectAttributes & ioArgument_objectParams,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_implementationObjectMap enumerator_29148 (constinArgument_impObject, kENUMERATION_UP) ;
  while (enumerator_29148.hasCurrentObject ()) {
    if (enumerator_29148.current_type (HERE).isValid ()) {
      if (NULL != dynamic_cast <const cPtr_impAutoDefaultType *> (enumerator_29148.current_type (HERE).ptr ())) {
        GALGAS_impAutoDefaultType cast_29223_defaultType ((cPtr_impAutoDefaultType *) enumerator_29148.current_type (HERE).ptr ()) ;
        callExtensionMethod_setDefault ((cPtr_impAutoDefaultType *) cast_29223_defaultType.ptr (), ioArgument_objectParams, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1015)) ;
      }
    }
    enumerator_29148.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@noRange contains'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_noRange::getter_contains (const GALGAS_object_5F_t /* constinArgument_obj */,
                                           C_Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_isInside ; // Returned variable
  result_isInside = GALGAS_bool (true) ;
//---
  return result_isInside ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@noRange string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_noRange::getter_string (C_Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = GALGAS_string ("\?") ;
//---
  return result_desc ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@uint32AttributeSet contains'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_uint_33__32_AttributeSet::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_isInside ; // Returned variable
  if (constinArgument_obj.isValid ()) {
    if (constinArgument_obj.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      GALGAS_uint_33__32__5F_class cast_31598_intVal ((cPtr_uint_33__32__5F_class *) constinArgument_obj.ptr ()) ;
      result_isInside = GALGAS_bool (false) ;
      cEnumerator_uint_33__32_List enumerator_31631 (this->mProperty_valueList, kENUMERATION_UP) ;
      while (enumerator_31631.hasCurrentObject ()) {
        result_isInside = result_isInside.operator_or (GALGAS_bool (kIsEqual, enumerator_31631.current_value (HERE).objectCompare (cast_31598_intVal.readProperty_value ())) COMMA_SOURCE_FILE ("implementation_types.galgas", 1103)) ;
        enumerator_31631.gotoNextObject () ;
      }
    }else{
      result_isInside = GALGAS_bool (false) ;
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_obj.readProperty_location (), GALGAS_string ("UINT32 expected"), fixItArray0  COMMA_SOURCE_FILE ("implementation_types.galgas", 1107)) ;
    }
  }
//---
  return result_isInside ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@uint32AttributeSet string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_uint_33__32_AttributeSet::getter_string (C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = GALGAS_string::makeEmptyString () ;
  cEnumerator_uint_33__32_List enumerator_31860 (this->mProperty_valueList, kENUMERATION_UP) ;
  while (enumerator_31860.hasCurrentObject ()) {
    result_desc.plusAssign_operation(enumerator_31860.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 1115)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1115)) ;
    if (enumerator_31860.hasNextObject ()) {
      result_desc.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1117)) ;
    }
    enumerator_31860.gotoNextObject () ;
  }
//---
  return result_desc ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@uint32AttributeMinMax contains'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_uint_33__32_AttributeMinMax::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_isInside ; // Returned variable
  if (constinArgument_obj.isValid ()) {
    if (constinArgument_obj.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      GALGAS_uint_33__32__5F_class cast_32074_intVal ((cPtr_uint_33__32__5F_class *) constinArgument_obj.ptr ()) ;
      GALGAS_bool test_0 = GALGAS_bool (kIsInfOrEqual, this->mProperty_min.objectCompare (cast_32074_intVal.readProperty_value ())) ;
      if (kBoolTrue == test_0.boolEnum ()) {
        test_0 = GALGAS_bool (kIsInfOrEqual, cast_32074_intVal.readProperty_value ().objectCompare (this->mProperty_max)) ;
      }
      result_isInside = test_0 ;
    }else{
      result_isInside = GALGAS_bool (false) ;
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_obj.readProperty_location (), GALGAS_string ("UINT32 expected"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 1130)) ;
    }
  }
//---
  return result_isInside ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@uint32AttributeMinMax string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_uint_33__32_AttributeMinMax::getter_string (C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = this->mProperty_min.getter_string (SOURCE_FILE ("implementation_types.galgas", 1136)).add_operation (GALGAS_string (".."), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1136)).add_operation (this->mProperty_max.getter_string (SOURCE_FILE ("implementation_types.galgas", 1136)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1136)) ;
//---
  return result_desc ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@sint32AttributeSet contains'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_sint_33__32_AttributeSet::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_isInside ; // Returned variable
  if (constinArgument_obj.isValid ()) {
    if (constinArgument_obj.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32__5F_class) {
      GALGAS_sint_33__32__5F_class cast_32449_intVal ((cPtr_sint_33__32__5F_class *) constinArgument_obj.ptr ()) ;
      result_isInside = GALGAS_bool (true) ;
      cEnumerator_sint_33__32_List enumerator_32481 (this->mProperty_valueList, kENUMERATION_UP) ;
      while (enumerator_32481.hasCurrentObject ()) {
        result_isInside = result_isInside.operator_and (GALGAS_bool (kIsEqual, enumerator_32481.current_value (HERE).objectCompare (cast_32449_intVal.readProperty_value ())) COMMA_SOURCE_FILE ("implementation_types.galgas", 1147)) ;
        enumerator_32481.gotoNextObject () ;
      }
    }else{
      result_isInside = GALGAS_bool (false) ;
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_obj.readProperty_location (), GALGAS_string ("SINT32 expected"), fixItArray0  COMMA_SOURCE_FILE ("implementation_types.galgas", 1151)) ;
    }
  }
//---
  return result_isInside ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@sint32AttributeSet string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_sint_33__32_AttributeSet::getter_string (C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = GALGAS_string::makeEmptyString () ;
  cEnumerator_sint_33__32_List enumerator_32710 (this->mProperty_valueList, kENUMERATION_UP) ;
  while (enumerator_32710.hasCurrentObject ()) {
    result_desc.plusAssign_operation(enumerator_32710.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 1159)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1159)) ;
    if (enumerator_32710.hasNextObject ()) {
      result_desc.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1161)) ;
    }
    enumerator_32710.gotoNextObject () ;
  }
//---
  return result_desc ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@sint32AttributeMinMax contains'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_sint_33__32_AttributeMinMax::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_isInside ; // Returned variable
  if (constinArgument_obj.isValid ()) {
    if (constinArgument_obj.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32__5F_class) {
      GALGAS_sint_33__32__5F_class cast_32924_intVal ((cPtr_sint_33__32__5F_class *) constinArgument_obj.ptr ()) ;
      GALGAS_bool test_0 = GALGAS_bool (kIsInfOrEqual, this->mProperty_min.objectCompare (cast_32924_intVal.readProperty_value ())) ;
      if (kBoolTrue == test_0.boolEnum ()) {
        test_0 = GALGAS_bool (kIsInfOrEqual, cast_32924_intVal.readProperty_value ().objectCompare (this->mProperty_max)) ;
      }
      result_isInside = test_0 ;
    }else{
      result_isInside = GALGAS_bool (false) ;
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_obj.readProperty_location (), GALGAS_string ("SINT32 expected"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 1174)) ;
    }
  }
//---
  return result_isInside ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@sint32AttributeMinMax string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_sint_33__32_AttributeMinMax::getter_string (C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = this->mProperty_min.getter_string (SOURCE_FILE ("implementation_types.galgas", 1180)).add_operation (GALGAS_string (".."), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1180)).add_operation (this->mProperty_max.getter_string (SOURCE_FILE ("implementation_types.galgas", 1180)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1180)) ;
//---
  return result_desc ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@uint64AttributeSet contains'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_uint_36__34_AttributeSet::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_isInside ; // Returned variable
  if (constinArgument_obj.isValid ()) {
    if (constinArgument_obj.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      GALGAS_uint_36__34__5F_class cast_33299_intVal ((cPtr_uint_36__34__5F_class *) constinArgument_obj.ptr ()) ;
      result_isInside = GALGAS_bool (true) ;
      cEnumerator_uint_36__34_List enumerator_33331 (this->mProperty_valueList, kENUMERATION_UP) ;
      while (enumerator_33331.hasCurrentObject ()) {
        result_isInside = result_isInside.operator_and (GALGAS_bool (kIsEqual, enumerator_33331.current_value (HERE).objectCompare (cast_33299_intVal.readProperty_value ())) COMMA_SOURCE_FILE ("implementation_types.galgas", 1191)) ;
        enumerator_33331.gotoNextObject () ;
      }
    }else{
      result_isInside = GALGAS_bool (false) ;
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_obj.readProperty_location (), GALGAS_string ("UINT64 expected"), fixItArray0  COMMA_SOURCE_FILE ("implementation_types.galgas", 1195)) ;
    }
  }
//---
  return result_isInside ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@uint64AttributeSet string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_uint_36__34_AttributeSet::getter_string (C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = GALGAS_string::makeEmptyString () ;
  cEnumerator_uint_36__34_List enumerator_33560 (this->mProperty_valueList, kENUMERATION_UP) ;
  while (enumerator_33560.hasCurrentObject ()) {
    result_desc.plusAssign_operation(enumerator_33560.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 1203)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1203)) ;
    if (enumerator_33560.hasNextObject ()) {
      result_desc.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1205)) ;
    }
    enumerator_33560.gotoNextObject () ;
  }
//---
  return result_desc ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@uint64AttributeMinMax contains'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_uint_36__34_AttributeMinMax::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_isInside ; // Returned variable
  if (constinArgument_obj.isValid ()) {
    if (constinArgument_obj.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      GALGAS_uint_36__34__5F_class cast_33774_intVal ((cPtr_uint_36__34__5F_class *) constinArgument_obj.ptr ()) ;
      GALGAS_bool test_0 = GALGAS_bool (kIsInfOrEqual, this->mProperty_min.objectCompare (cast_33774_intVal.readProperty_value ())) ;
      if (kBoolTrue == test_0.boolEnum ()) {
        test_0 = GALGAS_bool (kIsInfOrEqual, cast_33774_intVal.readProperty_value ().objectCompare (this->mProperty_max)) ;
      }
      result_isInside = test_0 ;
    }else{
      result_isInside = GALGAS_bool (false) ;
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_obj.readProperty_location (), GALGAS_string ("UINT64 expected"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 1218)) ;
    }
  }
//---
  return result_isInside ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@uint64AttributeMinMax string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_uint_36__34_AttributeMinMax::getter_string (C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = this->mProperty_min.getter_string (SOURCE_FILE ("implementation_types.galgas", 1224)).add_operation (GALGAS_string (".."), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1224)).add_operation (this->mProperty_max.getter_string (SOURCE_FILE ("implementation_types.galgas", 1224)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1224)) ;
//---
  return result_desc ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@sint64AttributeSet contains'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_sint_36__34_AttributeSet::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_isInside ; // Returned variable
  if (constinArgument_obj.isValid ()) {
    if (constinArgument_obj.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34__5F_class) {
      GALGAS_sint_36__34__5F_class cast_34149_intVal ((cPtr_sint_36__34__5F_class *) constinArgument_obj.ptr ()) ;
      result_isInside = GALGAS_bool (true) ;
      cEnumerator_sint_36__34_List enumerator_34181 (this->mProperty_valueList, kENUMERATION_UP) ;
      while (enumerator_34181.hasCurrentObject ()) {
        result_isInside = result_isInside.operator_and (GALGAS_bool (kIsEqual, enumerator_34181.current_value (HERE).objectCompare (cast_34149_intVal.readProperty_value ())) COMMA_SOURCE_FILE ("implementation_types.galgas", 1235)) ;
        enumerator_34181.gotoNextObject () ;
      }
    }else{
      result_isInside = GALGAS_bool (false) ;
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_obj.readProperty_location (), GALGAS_string ("SINT64 expected"), fixItArray0  COMMA_SOURCE_FILE ("implementation_types.galgas", 1239)) ;
    }
  }
//---
  return result_isInside ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@sint64AttributeSet string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_sint_36__34_AttributeSet::getter_string (C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = GALGAS_string::makeEmptyString () ;
  cEnumerator_sint_36__34_List enumerator_34410 (this->mProperty_valueList, kENUMERATION_UP) ;
  while (enumerator_34410.hasCurrentObject ()) {
    result_desc.plusAssign_operation(enumerator_34410.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 1247)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1247)) ;
    if (enumerator_34410.hasNextObject ()) {
      result_desc.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1249)) ;
    }
    enumerator_34410.gotoNextObject () ;
  }
//---
  return result_desc ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@sint64AttributeMinMax contains'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_sint_36__34_AttributeMinMax::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_isInside ; // Returned variable
  if (constinArgument_obj.isValid ()) {
    if (constinArgument_obj.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34__5F_class) {
      GALGAS_sint_36__34__5F_class cast_34625_intVal ((cPtr_sint_36__34__5F_class *) constinArgument_obj.ptr ()) ;
      GALGAS_bool test_0 = GALGAS_bool (kIsInfOrEqual, this->mProperty_min.objectCompare (cast_34625_intVal.readProperty_value ())) ;
      if (kBoolTrue == test_0.boolEnum ()) {
        test_0 = GALGAS_bool (kIsInfOrEqual, cast_34625_intVal.readProperty_value ().objectCompare (this->mProperty_max)) ;
      }
      result_isInside = test_0 ;
    }else{
      result_isInside = GALGAS_bool (false) ;
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_obj.readProperty_location (), GALGAS_string ("SINT64 expected"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 1263)) ;
    }
  }
//---
  return result_isInside ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@sint64AttributeMinMax string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_sint_36__34_AttributeMinMax::getter_string (C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = this->mProperty_min.getter_string (SOURCE_FILE ("implementation_types.galgas", 1269)).add_operation (GALGAS_string (".."), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1269)).add_operation (this->mProperty_max.getter_string (SOURCE_FILE ("implementation_types.galgas", 1269)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1269)) ;
//---
  return result_desc ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@floatAttributeSet contains'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_floatAttributeSet::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_isInside ; // Returned variable
  if (constinArgument_obj.isValid ()) {
    if (constinArgument_obj.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_float_5F_class) {
      GALGAS_float_5F_class cast_34998_intVal ((cPtr_float_5F_class *) constinArgument_obj.ptr ()) ;
      result_isInside = GALGAS_bool (true) ;
      cEnumerator_floatList enumerator_35030 (this->mProperty_valueList, kENUMERATION_UP) ;
      while (enumerator_35030.hasCurrentObject ()) {
        result_isInside = result_isInside.operator_and (GALGAS_bool (kIsEqual, enumerator_35030.current_value (HERE).objectCompare (cast_34998_intVal.readProperty_value ())) COMMA_SOURCE_FILE ("implementation_types.galgas", 1280)) ;
        enumerator_35030.gotoNextObject () ;
      }
    }else{
      result_isInside = GALGAS_bool (false) ;
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_obj.readProperty_location (), GALGAS_string ("FLOAT expected"), fixItArray0  COMMA_SOURCE_FILE ("implementation_types.galgas", 1284)) ;
    }
  }
//---
  return result_isInside ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@floatAttributeSet string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_floatAttributeSet::getter_string (C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = GALGAS_string::makeEmptyString () ;
  cEnumerator_floatList enumerator_35257 (this->mProperty_valueList, kENUMERATION_UP) ;
  while (enumerator_35257.hasCurrentObject ()) {
    result_desc.plusAssign_operation(enumerator_35257.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 1292)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1292)) ;
    if (enumerator_35257.hasNextObject ()) {
      result_desc.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1294)) ;
    }
    enumerator_35257.gotoNextObject () ;
  }
//---
  return result_desc ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@floatAttributeMinMax contains'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_floatAttributeMinMax::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_isInside ; // Returned variable
  if (constinArgument_obj.isValid ()) {
    if (constinArgument_obj.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_float_5F_class) {
      GALGAS_float_5F_class cast_35469_intVal ((cPtr_float_5F_class *) constinArgument_obj.ptr ()) ;
      GALGAS_bool test_0 = GALGAS_bool (kIsInfOrEqual, this->mProperty_min.objectCompare (cast_35469_intVal.readProperty_value ())) ;
      if (kBoolTrue == test_0.boolEnum ()) {
        test_0 = GALGAS_bool (kIsInfOrEqual, cast_35469_intVal.readProperty_value ().objectCompare (this->mProperty_max)) ;
      }
      result_isInside = test_0 ;
    }else{
      result_isInside = GALGAS_bool (false) ;
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_obj.readProperty_location (), GALGAS_string ("FLOAT expected"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 1307)) ;
    }
  }
//---
  return result_isInside ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@floatAttributeMinMax string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_floatAttributeMinMax::getter_string (C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = this->mProperty_min.getter_string (SOURCE_FILE ("implementation_types.galgas", 1313)).add_operation (GALGAS_string (".."), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1313)).add_operation (this->mProperty_max.getter_string (SOURCE_FILE ("implementation_types.galgas", 1313)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1313)) ;
//---
  return result_desc ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'emptyLString'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_lstring onceFunction_emptyLString (C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_ls ; // Returned variable
  result_ls = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 29))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 29)) ;
//---
  return result_ls ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_emptyLString = false ;
static GALGAS_lstring gOnceFunctionResult_emptyLString ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring function_emptyLString (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_emptyLString) {
    gOnceFunctionResult_emptyLString = onceFunction_emptyLString (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_emptyLString = true ;
  }
  return gOnceFunctionResult_emptyLString ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_emptyLString (void) {
  gOnceFunctionResult_emptyLString.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_emptyLString (NULL,
                                                          releaseOnceFunctionResult_emptyLString) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptyLString [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptyLString (C_Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_emptyLString (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptyLString ("emptyLString",
                                                              functionWithGenericHeader_emptyLString,
                                                              & kTypeDescriptor_GALGAS_lstring,
                                                              0,
                                                              functionArgs_emptyLString) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'emptyObject'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectAttributes function_emptyObject (C_Compiler *
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_result ; // Returned variable
  result_result = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_basic_types.galgas", 73))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 73)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptyObject [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptyObject (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_emptyObject (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptyObject ("emptyObject",
                                                             functionWithGenericHeader_emptyObject,
                                                             & kTypeDescriptor_GALGAS_objectAttributes,
                                                             0,
                                                             functionArgs_emptyObject) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@multipleAttribute mergeSubAttributes'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_multipleAttribute_mergeSubAttributes (cPtr_object_5F_t * inObject,
                                                                  GALGAS_object_5F_t inArgument_withObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_multipleAttribute * object = (cPtr_multipleAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_multipleAttribute) ;
  if (inArgument_withObject.isValid ()) {
    if (inArgument_withObject.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
      GALGAS_multipleAttribute cast_2247_multipleObject ((cPtr_multipleAttribute *) inArgument_withObject.ptr ()) ;
      object->mProperty_items.plusAssign_operation(cast_2247_multipleObject.readProperty_items (), inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 93)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_multipleAttribute_mergeSubAttributes (void) {
  enterExtensionSetter_mergeSubAttributes (kTypeDescriptor_GALGAS_multipleAttribute.mSlotID,
                                           extensionSetter_multipleAttribute_mergeSubAttributes) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_multipleAttribute_mergeSubAttributes (defineExtensionSetter_multipleAttribute_mergeSubAttributes, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'multipleAttributeOrError'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList function_multipleAttributeOrError (const GALGAS_object_5F_t & constinArgument_t,
                                                         const GALGAS_string & constinArgument_att,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierList result_v ; // Returned variable
  result_v = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("goil_basic_types.galgas", 101)) ;
  if (constinArgument_t.isValid ()) {
    if (constinArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
      GALGAS_multipleAttribute cast_2464_l ((cPtr_multipleAttribute *) constinArgument_t.ptr ()) ;
      result_v = cast_2464_l.readProperty_items () ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_t.readProperty_location (), GALGAS_string ("Internal error, ").add_operation (constinArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 106)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 106)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 106)) ;
    }
  }
//---
  return result_v ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_multipleAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_multipleAttributeOrError (C_Compiler * inCompiler,
                                                                         const cObjectArray & inEffectiveParameterArray,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_multipleAttributeOrError (operand0,
                                            operand1,
                                            inCompiler
                                            COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_multipleAttributeOrError ("multipleAttributeOrError",
                                                                          functionWithGenericHeader_multipleAttributeOrError,
                                                                          & kTypeDescriptor_GALGAS_identifierList,
                                                                          2,
                                                                          functionArgs_multipleAttributeOrError) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@boolAttribute mergeSubAttributes'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_boolAttribute_mergeSubAttributes (cPtr_object_5F_t * inObject,
                                                              GALGAS_object_5F_t inArgument_withObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_boolAttribute * object = (cPtr_boolAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_boolAttribute) ;
  if (inArgument_withObject.isValid ()) {
    if (inArgument_withObject.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_2787_boolObject ((cPtr_boolAttribute *) inArgument_withObject.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsEqual, object->mProperty_value.objectCompare (cast_2787_boolObject.readProperty_value ())).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          object->mProperty_subAttributes.insulate (HERE) ;
          cPtr_objectAttributes * ptr_2852 = (cPtr_objectAttributes *) object->mProperty_subAttributes.ptr () ;
          callExtensionSetter_mergeAttributes ((cPtr_objectAttributes *) ptr_2852, cast_2787_boolObject.readProperty_subAttributes (), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 120)) ;
          }
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_boolAttribute_mergeSubAttributes (void) {
  enterExtensionSetter_mergeSubAttributes (kTypeDescriptor_GALGAS_boolAttribute.mSlotID,
                                           extensionSetter_boolAttribute_mergeSubAttributes) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_boolAttribute_mergeSubAttributes (defineExtensionSetter_boolAttribute_mergeSubAttributes, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'boolAttributeOrError'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool function_boolAttributeOrError (GALGAS_object_5F_t inArgument_t,
                                           GALGAS_string inArgument_att,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_v ; // Returned variable
  result_v = GALGAS_bool (false) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_3054_attribute ((cPtr_boolAttribute *) inArgument_t.ptr ()) ;
      result_v = cast_3054_attribute.readProperty_value () ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.readProperty_location (), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 134)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 134)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 134)) ;
    }
  }
//---
  return result_v ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_boolAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_boolAttributeOrError (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_boolAttributeOrError (operand0,
                                        operand1,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_boolAttributeOrError ("boolAttributeOrError",
                                                                      functionWithGenericHeader_boolAttributeOrError,
                                                                      & kTypeDescriptor_GALGAS_bool,
                                                                      2,
                                                                      functionArgs_boolAttributeOrError) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@enumAttribute mergeSubAttributes'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_enumAttribute_mergeSubAttributes (cPtr_object_5F_t * inObject,
                                                              GALGAS_object_5F_t inArgument_withObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_enumAttribute * object = (cPtr_enumAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_enumAttribute) ;
  if (inArgument_withObject.isValid ()) {
    if (inArgument_withObject.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_enumAttribute) {
      GALGAS_enumAttribute cast_3386_enumObject ((cPtr_enumAttribute *) inArgument_withObject.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsEqual, object->mProperty_value.objectCompare (cast_3386_enumObject.readProperty_value ())).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          object->mProperty_subAttributes.insulate (HERE) ;
          cPtr_objectAttributes * ptr_3451 = (cPtr_objectAttributes *) object->mProperty_subAttributes.ptr () ;
          callExtensionSetter_mergeAttributes ((cPtr_objectAttributes *) ptr_3451, cast_3386_enumObject.readProperty_subAttributes (), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 148)) ;
          }
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_enumAttribute_mergeSubAttributes (void) {
  enterExtensionSetter_mergeSubAttributes (kTypeDescriptor_GALGAS_enumAttribute.mSlotID,
                                           extensionSetter_enumAttribute_mergeSubAttributes) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_enumAttribute_mergeSubAttributes (defineExtensionSetter_enumAttribute_mergeSubAttributes, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'uint32_or_error'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint function_uint_33__32__5F_or_5F_error (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint result_v ; // Returned variable
  result_v = GALGAS_uint (uint32_t (0U)) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      GALGAS_uint_33__32__5F_class cast_3836_ui ((cPtr_uint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_3836_ui.readProperty_value () ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.readProperty_location (), inArgument_att.add_operation (GALGAS_string (" is not defined"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 175)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 175)) ;
    }
  }
//---
  return result_v ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_uint_33__32__5F_or_5F_error [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_uint_33__32__5F_or_5F_error (C_Compiler * inCompiler,
                                                                            const cObjectArray & inEffectiveParameterArray,
                                                                            const GALGAS_location & /* inErrorLocation */
                                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_uint_33__32__5F_or_5F_error (operand0,
                                               operand1,
                                               inCompiler
                                               COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_uint_33__32__5F_or_5F_error ("uint32_or_error",
                                                                             functionWithGenericHeader_uint_33__32__5F_or_5F_error,
                                                                             & kTypeDescriptor_GALGAS_uint,
                                                                             2,
                                                                             functionArgs_uint_33__32__5F_or_5F_error) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'uint32OrError'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint function_uint_33__32_OrError (GALGAS_object_5F_t inArgument_t,
                                          GALGAS_string inArgument_att,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint result_v ; // Returned variable
  result_v = GALGAS_uint (uint32_t (0U)) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      GALGAS_uint_33__32__5F_class cast_4035_ui ((cPtr_uint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_4035_ui.readProperty_value () ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.readProperty_location (), inArgument_att.add_operation (GALGAS_string (" is not defined"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 188)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 188)) ;
    }
  }
//---
  return result_v ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_uint_33__32_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_uint_33__32_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_uint_33__32_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_uint_33__32_OrError ("uint32OrError",
                                                                     functionWithGenericHeader_uint_33__32_OrError,
                                                                     & kTypeDescriptor_GALGAS_uint,
                                                                     2,
                                                                     functionArgs_uint_33__32_OrError) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'sint32OrError'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint function_sint_33__32_OrError (GALGAS_object_5F_t inArgument_t,
                                          GALGAS_string inArgument_att,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint result_v ; // Returned variable
  result_v = GALGAS_sint (int32_t (0L)) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32__5F_class) {
      GALGAS_sint_33__32__5F_class cast_4372_ui ((cPtr_sint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_4372_ui.readProperty_value () ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.readProperty_location (), inArgument_att.add_operation (GALGAS_string (" is not defined"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 208)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 208)) ;
    }
  }
//---
  return result_v ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_sint_33__32_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_sint_33__32_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_sint_33__32_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_sint_33__32_OrError ("sint32OrError",
                                                                     functionWithGenericHeader_sint_33__32_OrError,
                                                                     & kTypeDescriptor_GALGAS_sint,
                                                                     2,
                                                                     functionArgs_sint_33__32_OrError) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'uint64OrError'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ function_uint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_36__34_ result_v ; // Returned variable
  result_v = GALGAS_uint_36__34_ (uint64_t (0ULL)) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      GALGAS_uint_36__34__5F_class cast_4709_ui ((cPtr_uint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_4709_ui.readProperty_value () ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.readProperty_location (), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 228)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 228)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 228)) ;
    }
  }
//---
  return result_v ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_uint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_uint_36__34_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_uint_36__34_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_uint_36__34_OrError ("uint64OrError",
                                                                     functionWithGenericHeader_uint_36__34_OrError,
                                                                     & kTypeDescriptor_GALGAS_uint_36__34_,
                                                                     2,
                                                                     functionArgs_uint_36__34_OrError) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'luint64OrError'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint_36__34_ function_luint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                    GALGAS_string inArgument_att,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_luint_36__34_ result_v ; // Returned variable
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      GALGAS_uint_36__34__5F_class cast_4927_ui ((cPtr_uint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = GALGAS_luint_36__34_::constructor_new (cast_4927_ui.readProperty_value (), cast_4927_ui.readProperty_location ()  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 238)) ;
    }else{
      result_v = GALGAS_luint_36__34_::constructor_new (GALGAS_uint_36__34_ (uint64_t (0ULL)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 240))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 240)) ;
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.readProperty_location (), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 241)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 241)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 241)) ;
    }
  }
//---
  return result_v ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_luint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_luint_36__34_OrError (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_luint_36__34_OrError (operand0,
                                        operand1,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_luint_36__34_OrError ("luint64OrError",
                                                                      functionWithGenericHeader_luint_36__34_OrError,
                                                                      & kTypeDescriptor_GALGAS_luint_36__34_,
                                                                      2,
                                                                      functionArgs_luint_36__34_OrError) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'sint64OrError'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ function_sint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_36__34_ result_v ; // Returned variable
  result_v = GALGAS_sint_36__34_ (int64_t (0LL)) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34__5F_class) {
      GALGAS_sint_36__34__5F_class cast_5366_ui ((cPtr_sint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_5366_ui.readProperty_value () ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.readProperty_location (), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 261)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 261)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 261)) ;
    }
  }
//---
  return result_v ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_sint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_sint_36__34_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_sint_36__34_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_sint_36__34_OrError ("sint64OrError",
                                                                     functionWithGenericHeader_sint_36__34_OrError,
                                                                     & kTypeDescriptor_GALGAS_sint_36__34_,
                                                                     2,
                                                                     functionArgs_sint_36__34_OrError) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'floatOrError'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double function_floatOrError (GALGAS_object_5F_t inArgument_t,
                                     GALGAS_string inArgument_att,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_v ; // Returned variable
  result_v = GALGAS_double (0) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_float_5F_class) {
      GALGAS_float_5F_class cast_5716_ui ((cPtr_float_5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_5716_ui.readProperty_value () ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.readProperty_location (), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 281)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 281)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 281)) ;
    }
  }
//---
  return result_v ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_floatOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_floatOrError (C_Compiler * inCompiler,
                                                             const cObjectArray & inEffectiveParameterArray,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_floatOrError (operand0,
                                operand1,
                                inCompiler
                                COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_floatOrError ("floatOrError",
                                                              functionWithGenericHeader_floatOrError,
                                                              & kTypeDescriptor_GALGAS_double,
                                                              2,
                                                              functionArgs_floatOrError) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stringAttributeOrError'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring function_stringAttributeOrError (const GALGAS_object_5F_t & constinArgument_attribute,
                                                const GALGAS_string & constinArgument_attributeName,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  result_result = function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 303)) ;
  if (constinArgument_attribute.isValid ()) {
    if (constinArgument_attribute.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_stringAttribute) {
      GALGAS_stringAttribute cast_6268_attribute ((cPtr_stringAttribute *) constinArgument_attribute.ptr ()) ;
      result_result = GALGAS_lstring::constructor_new (cast_6268_attribute.readProperty_value (), cast_6268_attribute.readProperty_location ()  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 306)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_attribute.readProperty_location (), GALGAS_string ("Internal error ").add_operation (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 308)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 308)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 308)) ;
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringAttributeOrError (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_stringAttributeOrError (operand0,
                                          operand1,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringAttributeOrError ("stringAttributeOrError",
                                                                        functionWithGenericHeader_stringAttributeOrError,
                                                                        & kTypeDescriptor_GALGAS_lstring,
                                                                        2,
                                                                        functionArgs_stringAttributeOrError) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@structAttribute mergeSubAttributes'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_structAttribute_mergeSubAttributes (cPtr_object_5F_t * inObject,
                                                                GALGAS_object_5F_t inArgument_withObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_structAttribute * object = (cPtr_structAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_structAttribute) ;
  if (inArgument_withObject.isValid ()) {
    if (inArgument_withObject.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_structAttribute) {
      GALGAS_structAttribute cast_6676_structObject ((cPtr_structAttribute *) inArgument_withObject.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsEqual, object->mProperty_structName.readProperty_string ().objectCompare (cast_6676_structObject.readProperty_structName ().readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          object->mProperty_subAttributes.insulate (HERE) ;
          cPtr_objectAttributes * ptr_6771 = (cPtr_objectAttributes *) object->mProperty_subAttributes.ptr () ;
          callExtensionSetter_mergeAttributes ((cPtr_objectAttributes *) ptr_6771, cast_6676_structObject.readProperty_subAttributes (), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 322)) ;
          }
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_structAttribute_mergeSubAttributes (void) {
  enterExtensionSetter_mergeSubAttributes (kTypeDescriptor_GALGAS_structAttribute.mSlotID,
                                           extensionSetter_structAttribute_mergeSubAttributes) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_structAttribute_mergeSubAttributes (defineExtensionSetter_structAttribute_mergeSubAttributes, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'empty_lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring function_empty_5F_lstring (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_ls ; // Returned variable
  result_ls = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 487))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 487)) ;
//---
  return result_ls ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_empty_5F_lstring [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_empty_5F_lstring (C_Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_empty_5F_lstring (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_empty_5F_lstring ("empty_lstring",
                                                                  functionWithGenericHeader_empty_5F_lstring,
                                                                  & kTypeDescriptor_GALGAS_lstring,
                                                                  0,
                                                                  functionArgs_empty_5F_lstring) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'void_obj'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_object_5F_t function_void_5F_obj (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_v ; // Returned variable
  result_v = GALGAS_void::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 492)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 492))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 492)) ;
//---
  return result_v ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_void_5F_obj [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_void_5F_obj (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_void_5F_obj (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_void_5F_obj ("void_obj",
                                                             functionWithGenericHeader_void_5F_obj,
                                                             & kTypeDescriptor_GALGAS_object_5F_t,
                                                             0,
                                                             functionArgs_void_5F_obj) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'luint64_value'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint_36__34_ function_luint_36__34__5F_value (const GALGAS_uint_36__34__5F_class & constinArgument_c,
                                                      C_Compiler *
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_luint_36__34_ result_v ; // Returned variable
  result_v = GALGAS_luint_36__34_::constructor_new (constinArgument_c.readProperty_value (), constinArgument_c.readProperty_location ()  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 686)) ;
//---
  return result_v ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_luint_36__34__5F_value [2] = {
  & kTypeDescriptor_GALGAS_uint_36__34__5F_class,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_luint_36__34__5F_value (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_uint_36__34__5F_class operand0 = GALGAS_uint_36__34__5F_class::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                             inCompiler
                                                                                             COMMA_THERE) ;
  return function_luint_36__34__5F_value (operand0,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_luint_36__34__5F_value ("luint64_value",
                                                                        functionWithGenericHeader_luint_36__34__5F_value,
                                                                        & kTypeDescriptor_GALGAS_luint_36__34_,
                                                                        1,
                                                                        functionArgs_luint_36__34__5F_value) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'projectName'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_projectName (C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_directory ; // Returned variable
  result_directory = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 30)).getter_stringByDeletingPathExtension (SOURCE_FILE ("goil_routines.galgas", 30)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, GALGAS_string (gOption_goil_5F_options_project_5F_dir.readProperty_value ()).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_directory = GALGAS_string (gOption_goil_5F_options_project_5F_dir.readProperty_value ()) ;
    }
  }
//---
  return result_directory ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_projectName [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_projectName (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_projectName (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_projectName ("projectName",
                                                             functionWithGenericHeader_projectName,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             0,
                                                             functionArgs_projectName) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'oil_dir'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_oil_5F_dir (C_Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_dir ; // Returned variable
  result_dir = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 37)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("goil_routines.galgas", 37)) ;
//---
  return result_dir ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_oil_5F_dir [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_oil_5F_dir (C_Compiler * inCompiler,
                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  return function_oil_5F_dir (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_oil_5F_dir ("oil_dir",
                                                            functionWithGenericHeader_oil_5F_dir,
                                                            & kTypeDescriptor_GALGAS_string,
                                                            0,
                                                            functionArgs_oil_5F_dir) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'arch'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_arch (C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_arch_5F_name ; // Returned variable
  GALGAS_stringlist var_components_1215 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 45)) ;
  var_components_1215.method_first (result_arch_5F_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 46)) ;
//---
  return result_arch_5F_name ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_arch [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_arch (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_arch (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_arch ("arch",
                                                      functionWithGenericHeader_arch,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_arch) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'chip'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_chip (C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_chip_5F_name ; // Returned variable
  GALGAS_stringlist var_components_1536 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 54)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_components_1536.getter_length (SOURCE_FILE ("goil_routines.galgas", 55)).objectCompare (GALGAS_uint (uint32_t (1U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_chip_5F_name = var_components_1536.getter_mValueAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 56)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_chip_5F_name = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_chip_5F_name ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_chip [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_chip (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_chip (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_chip ("chip",
                                                      functionWithGenericHeader_chip,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_chip) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'board'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_board (C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_board_5F_name ; // Returned variable
  GALGAS_stringlist var_components_1954 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 68)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_components_1954.getter_length (SOURCE_FILE ("goil_routines.galgas", 69)).objectCompare (GALGAS_uint (uint32_t (2U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      GALGAS_string joker_2098 ; // Joker input parameter
      var_components_1954.setter_popFirst (joker_2098, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 70)) ;
      }
      {
      GALGAS_string joker_2129 ; // Joker input parameter
      var_components_1954.setter_popFirst (joker_2129, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 71)) ;
      }
      result_board_5F_name = GALGAS_string::constructor_componentsJoinedByString (var_components_1954, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 72)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_board_5F_name = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_board_5F_name ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_board [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_board (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_board (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_board ("board",
                                                       functionWithGenericHeader_board,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_board) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'targetPathList'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_list function_targetPathList (C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_list result_pathList ; // Returned variable
  GALGAS_stringlist var_components_2372 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 82)) ;
  result_pathList = GALGAS_list::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 83)) ;
  cEnumerator_stringlist enumerator_2497 (var_components_2372, kENUMERATION_UP) ;
  while (enumerator_2497.hasCurrentObject ()) {
    GALGAS_gtlData var_cont_2537 = GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 85)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 85)), enumerator_2497.current_mValue (HERE)  COMMA_SOURCE_FILE ("goil_routines.galgas", 85)) ;
    result_pathList.addAssign_operation (var_cont_2537  COMMA_SOURCE_FILE ("goil_routines.galgas", 86)) ;
    enumerator_2497.gotoNextObject () ;
  }
//---
  return result_pathList ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_targetPathList [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_targetPathList (C_Compiler * inCompiler,
                                                               const cObjectArray & /* inEffectiveParameterArray */,
                                                               const GALGAS_location & /* inErrorLocation */
                                                               COMMA_LOCATION_ARGS) {
  return function_targetPathList (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_targetPathList ("targetPathList",
                                                                functionWithGenericHeader_targetPathList,
                                                                & kTypeDescriptor_GALGAS_list,
                                                                0,
                                                                functionArgs_targetPathList) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'add_path_component'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_add_5F_path_5F_component (GALGAS_string inArgument_path,
                                                 GALGAS_string inArgument_component,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_new_5F_path ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, inArgument_path.getter_characterAtIndex (inArgument_path.getter_length (SOURCE_FILE ("goil_routines.galgas", 97)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 97)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 97)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_new_5F_path = inArgument_path.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 98)).add_operation (inArgument_component, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 98)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_new_5F_path = inArgument_path.add_operation (inArgument_component, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 100)) ;
  }
//---
  return result_new_5F_path ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_add_5F_path_5F_component [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_add_5F_path_5F_component (C_Compiler * inCompiler,
                                                                         const cObjectArray & inEffectiveParameterArray,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_add_5F_path_5F_component (operand0,
                                            operand1,
                                            inCompiler
                                            COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_add_5F_path_5F_component ("add_path_component",
                                                                          functionWithGenericHeader_add_5F_path_5F_component,
                                                                          & kTypeDescriptor_GALGAS_string,
                                                                          2,
                                                                          functionArgs_add_5F_path_5F_component) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'rootTemplatesDirectory'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_rootTemplatesDirectory (C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_templateDirectory ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, GALGAS_string (gOption_goil_5F_options_template_5F_dir.readProperty_value ()).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_templateDirectory = GALGAS_string (gOption_goil_5F_options_template_5F_dir.readProperty_value ()) ;
    }
  }
  if (kBoolFalse == test_0) {
    GALGAS_string var_env_3106 = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("GOIL_TEMPLATES")  COMMA_SOURCE_FILE ("goil_routines.galgas", 110)) ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsNotEqual, var_env_3106.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        result_templateDirectory = var_env_3106 ;
      }
    }
    if (kBoolFalse == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 114)), GALGAS_string ("The templates path is not set. Use --templates option or set the GOIL_TEMPLATES environment variable"), fixItArray2  COMMA_SOURCE_FILE ("goil_routines.galgas", 114)) ;
      result_templateDirectory.drop () ; // Release error dropped variable
    }
  }
  result_templateDirectory = result_templateDirectory.getter_unixPathWithNativePath (SOURCE_FILE ("goil_routines.galgas", 118)) ;
  result_templateDirectory = result_templateDirectory.getter_stringByStandardizingPath (SOURCE_FILE ("goil_routines.galgas", 119)) ;
  enumGalgasBool test_3 = kBoolTrue ;
  if (kBoolTrue == test_3) {
    test_3 = GALGAS_bool (kIsNotEqual, result_templateDirectory.getter_characterAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 121)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
    if (kBoolTrue == test_3) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsEqual, result_templateDirectory.getter_characterAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 122)).objectCompare (GALGAS_char (TO_UNICODE (126)))).boolEnum () ;
        if (kBoolTrue == test_4) {
          GALGAS_string var_home_3675 = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("HOME")  COMMA_SOURCE_FILE ("goil_routines.galgas", 123)) ;
          GALGAS_string var_relativeToHome_3766 = result_templateDirectory.getter_rightSubString (result_templateDirectory.getter_length (SOURCE_FILE ("goil_routines.galgas", 124)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 124)) COMMA_SOURCE_FILE ("goil_routines.galgas", 124)) ;
          result_templateDirectory = var_home_3675.add_operation (var_relativeToHome_3766, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 125)) ;
        }
      }
      if (kBoolFalse == test_4) {
        GALGAS_string var_currentDirectory_3927 = GALGAS_string::constructor_stringWithCurrentDirectory (SOURCE_FILE ("goil_routines.galgas", 127)) ;
        result_templateDirectory = var_currentDirectory_3927.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 128)).add_operation (result_templateDirectory, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 128)) ;
      }
      result_templateDirectory = result_templateDirectory.getter_stringByStandardizingPath (SOURCE_FILE ("goil_routines.galgas", 130)) ;
    }
  }
//---
  return result_templateDirectory ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_rootTemplatesDirectory [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_rootTemplatesDirectory (C_Compiler * inCompiler,
                                                                       const cObjectArray & /* inEffectiveParameterArray */,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  return function_rootTemplatesDirectory (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_rootTemplatesDirectory ("rootTemplatesDirectory",
                                                                        functionWithGenericHeader_rootTemplatesDirectory,
                                                                        & kTypeDescriptor_GALGAS_string,
                                                                        0,
                                                                        functionArgs_rootTemplatesDirectory) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'templates_directory'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_templates_5F_directory (GALGAS_string inArgument_prefix,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_temp_5F_dir ; // Returned variable
  result_temp_5F_dir = function_rootTemplatesDirectory (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 135)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, result_temp_5F_dir.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_temp_5F_dir = function_add_5F_path_5F_component (result_temp_5F_dir, inArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 137)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsNotEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 139)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_string var_curdir_4438 = GALGAS_string::constructor_stringWithCurrentDirectory (SOURCE_FILE ("goil_routines.galgas", 140)) ;
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            test_2 = GALGAS_bool (kIsEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 141)).objectCompare (GALGAS_char (TO_UNICODE (46)))).operator_and (GALGAS_bool (kIsEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 141)).objectCompare (GALGAS_char (TO_UNICODE (47)))) COMMA_SOURCE_FILE ("goil_routines.galgas", 141)).boolEnum () ;
            if (kBoolTrue == test_2) {
              result_temp_5F_dir = result_temp_5F_dir.getter_stringByRemovingCharacterAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 142)).getter_stringByRemovingCharacterAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 142)) ;
            }
          }
          result_temp_5F_dir = var_curdir_4438.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 144)).add_operation (result_temp_5F_dir, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 144)) ;
        }
      }
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsNotEqual, result_temp_5F_dir.getter_characterAtIndex (result_temp_5F_dir.getter_length (SOURCE_FILE ("goil_routines.galgas", 146)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 146)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 146)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          result_temp_5F_dir.plusAssign_operation(GALGAS_string ("/"), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 147)) ;
        }
      }
    }
  }
//---
  return result_temp_5F_dir ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_templates_5F_directory [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_templates_5F_directory (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_templates_5F_directory (operand0,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_templates_5F_directory ("templates_directory",
                                                                        functionWithGenericHeader_templates_5F_directory,
                                                                        & kTypeDescriptor_GALGAS_string,
                                                                        1,
                                                                        functionArgs_templates_5F_directory) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'templateFilePath'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_templateFilePath (const GALGAS_string & constinArgument_prefix,
                                         const GALGAS_string & constinArgument_file,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_path ; // Returned variable
  GALGAS_stringlist var_components_5040 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 158)) ;
  GALGAS_string var_templateDir_5147 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 159)) ;
  GALGAS_bool var_notFound_5195 = GALGAS_bool (true) ;
  GALGAS_bool var_notOver_5218 = GALGAS_bool (true) ;
  result_path = GALGAS_string::makeEmptyString () ;
  if (var_components_5040.getter_length (SOURCE_FILE ("goil_routines.galgas", 164)).add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 164)).isValid ()) {
    uint32_t variant_5247 = var_components_5040.getter_length (SOURCE_FILE ("goil_routines.galgas", 164)).add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 164)).uintValue () ;
    bool loop_5247 = true ;
    while (loop_5247) {
      loop_5247 = var_notFound_5195.operator_and (var_notOver_5218 COMMA_SOURCE_FILE ("goil_routines.galgas", 165)).isValid () ;
      if (loop_5247) {
        loop_5247 = var_notFound_5195.operator_and (var_notOver_5218 COMMA_SOURCE_FILE ("goil_routines.galgas", 165)).boolValue () ;
      }
      if (loop_5247 && (0 == variant_5247)) {
        loop_5247 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 164)) ;
      }
      if (loop_5247) {
        variant_5247 -- ;
        GALGAS_string var_targetPath_5328 = var_templateDir_5147.add_operation (GALGAS_string::constructor_componentsJoinedByString (var_components_5040, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 166)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)) ;
        enumGalgasBool test_0 = kBoolTrue ;
        if (kBoolTrue == test_0) {
          test_0 = var_targetPath_5328.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 168)).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_notFound_5195 = GALGAS_bool (false) ;
            result_path = var_targetPath_5328 ;
          }
        }
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = GALGAS_bool (kIsStrictSup, var_components_5040.getter_length (SOURCE_FILE ("goil_routines.galgas", 172)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
          if (kBoolTrue == test_1) {
            {
            GALGAS_string joker_5604 ; // Joker input parameter
            var_components_5040.setter_popLast (joker_5604, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 173)) ;
            }
          }
        }
        if (kBoolFalse == test_1) {
          var_notOver_5218 = GALGAS_bool (false) ;
        }
      }
    }
  }
//---
  return result_path ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_templateFilePath [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_templateFilePath (C_Compiler * inCompiler,
                                                                 const cObjectArray & inEffectiveParameterArray,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_templateFilePath (operand0,
                                    operand1,
                                    inCompiler
                                    COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_templateFilePath ("templateFilePath",
                                                                  functionWithGenericHeader_templateFilePath,
                                                                  & kTypeDescriptor_GALGAS_string,
                                                                  2,
                                                                  functionArgs_templateFilePath) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'allTemplatePaths'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist function_allTemplatePaths (const GALGAS_string & constinArgument_prefix,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist result_paths ; // Returned variable
  GALGAS_stringlist var_components_5751 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 184)) ;
  GALGAS_string var_partialPath_5854 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 185)) ;
  result_paths = GALGAS_stringlist::constructor_listWithValue (var_partialPath_5854  COMMA_SOURCE_FILE ("goil_routines.galgas", 187)) ;
  cEnumerator_stringlist enumerator_5971 (var_components_5751, kENUMERATION_UP) ;
  while (enumerator_5971.hasCurrentObject ()) {
    var_partialPath_5854 = function_add_5F_path_5F_component (var_partialPath_5854, enumerator_5971.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 190)) ;
    {
    result_paths.setter_insertAtIndex (var_partialPath_5854, GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 191)) ;
    }
    enumerator_5971.gotoNextObject () ;
  }
//---
  return result_paths ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_allTemplatePaths [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_allTemplatePaths (C_Compiler * inCompiler,
                                                                 const cObjectArray & inEffectiveParameterArray,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_allTemplatePaths (operand0,
                                    inCompiler
                                    COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_allTemplatePaths ("allTemplatePaths",
                                                                  functionWithGenericHeader_allTemplatePaths,
                                                                  & kTypeDescriptor_GALGAS_stringlist,
                                                                  1,
                                                                  functionArgs_allTemplatePaths) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'checkTemplatesPath'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_checkTemplatesPath (C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_configDir_6154 = function_rootTemplatesDirectory (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 197)).add_operation (GALGAS_string ("/config"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 197)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = var_configDir_6154.getter_directoryExists (SOURCE_FILE ("goil_routines.galgas", 198)).operator_not (SOURCE_FILE ("goil_routines.galgas", 198)).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 199)), GALGAS_string ("The templates path '").add_operation (var_configDir_6154, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 199)).add_operation (GALGAS_string ("' is not set to the templates directory"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 199)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 199)) ;
    }
  }
  if (kBoolFalse == test_0) {
    GALGAS_string var_partialPath_6371 = var_configDir_6154 ;
    GALGAS_bool var_continueIt_6404 = GALGAS_bool (true) ;
    GALGAS_stringlist var_components_6442 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 203)) ;
    cEnumerator_stringlist enumerator_6545 (var_components_6442, kENUMERATION_UP) ;
    while (enumerator_6545.hasCurrentObject ()) {
      var_partialPath_6371 = var_partialPath_6371.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 205)).add_operation (enumerator_6545.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 205)) ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        GALGAS_bool test_3 = var_continueIt_6404 ;
        if (kBoolTrue == test_3.boolEnum ()) {
          test_3 = var_partialPath_6371.getter_directoryExists (SOURCE_FILE ("goil_routines.galgas", 206)).operator_not (SOURCE_FILE ("goil_routines.galgas", 206)) ;
        }
        test_2 = test_3.boolEnum () ;
        if (kBoolTrue == test_2) {
          TC_Array <C_FixItDescription> fixItArray4 ;
          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 207)), GALGAS_string ("The templates path '").add_operation (var_partialPath_6371, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 207)).add_operation (GALGAS_string ("' does not exist in the templates directory"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 207)), fixItArray4  COMMA_SOURCE_FILE ("goil_routines.galgas", 207)) ;
          var_continueIt_6404 = GALGAS_bool (false) ;
        }
      }
      enumerator_6545.gotoNextObject () ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Function 'allTemplateFilePaths'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist function_allTemplateFilePaths (const GALGAS_string & constinArgument_prefix,
                                                 const GALGAS_string & constinArgument_file,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist result_paths ; // Returned variable
  GALGAS_stringlist var_components_6957 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 220)) ;
  GALGAS_string var_templateDir_7064 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 221)) ;
  GALGAS_bool var_notOver_7111 = GALGAS_bool (true) ;
  result_paths = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 223)) ;
  if (var_components_6957.getter_length (SOURCE_FILE ("goil_routines.galgas", 225)).add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 225)).isValid ()) {
    uint32_t variant_7161 = var_components_6957.getter_length (SOURCE_FILE ("goil_routines.galgas", 225)).add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 225)).uintValue () ;
    bool loop_7161 = true ;
    while (loop_7161) {
      loop_7161 = var_notOver_7111.isValid () ;
      if (loop_7161) {
        loop_7161 = var_notOver_7111.boolValue () ;
      }
      if (loop_7161 && (0 == variant_7161)) {
        loop_7161 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 225)) ;
      }
      if (loop_7161) {
        variant_7161 -- ;
        GALGAS_string var_intermediatePath_7233 = GALGAS_string::constructor_componentsJoinedByString (var_components_6957, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 227)) ;
        enumGalgasBool test_0 = kBoolTrue ;
        if (kBoolTrue == test_0) {
          test_0 = GALGAS_bool (kIsNotEqual, var_intermediatePath_7233.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_intermediatePath_7233.plusAssign_operation(GALGAS_string ("/"), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 228)) ;
          }
        }
        GALGAS_string var_targetPath_7379 = var_templateDir_7064.add_operation (var_intermediatePath_7233, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 229)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 229)) ;
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = var_targetPath_7379.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 231)).boolEnum () ;
          if (kBoolTrue == test_1) {
            result_paths.addAssign_operation (var_targetPath_7379  COMMA_SOURCE_FILE ("goil_routines.galgas", 232)) ;
          }
        }
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = GALGAS_bool (kIsStrictSup, var_components_6957.getter_length (SOURCE_FILE ("goil_routines.galgas", 234)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
          if (kBoolTrue == test_2) {
            {
            GALGAS_string joker_7594 ; // Joker input parameter
            var_components_6957.setter_popLast (joker_7594, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 235)) ;
            }
          }
        }
        if (kBoolFalse == test_2) {
          var_notOver_7111 = GALGAS_bool (false) ;
        }
      }
    }
  }
//---
  return result_paths ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_allTemplateFilePaths [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_allTemplateFilePaths (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_allTemplateFilePaths (operand0,
                                        operand1,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_allTemplateFilePaths ("allTemplateFilePaths",
                                                                      functionWithGenericHeader_allTemplateFilePaths,
                                                                      & kTypeDescriptor_GALGAS_stringlist,
                                                                      2,
                                                                      functionArgs_allTemplateFilePaths) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'prefix'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_prefix (GALGAS_prefix_5F_map inArgument_p,
                     GALGAS_string inArgument_key,
                     GALGAS_string & outArgument_val,
                     C_Compiler * inCompiler
                     COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_val.drop () ; // Release 'out' argument
  GALGAS_lstring var_lkey_7721 = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 243))  COMMA_SOURCE_FILE ("goil_routines.galgas", 243)) ;
  GALGAS_string joker_7788 ; // Joker input parameter
  inArgument_p.method_prefix (var_lkey_7721, outArgument_val, joker_7788, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 244)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'performReplace'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_performReplace (GALGAS_prefix_5F_map inArgument_p,
                             GALGAS_string inArgument_key,
                             GALGAS_string inArgument_name,
                             GALGAS_string & ioArgument_res,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkey_7893 = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 248))  COMMA_SOURCE_FILE ("goil_routines.galgas", 248)) ;
  GALGAS_string var_prefix_7956 ;
  GALGAS_string var_tag_5F_to_5F_rep_7983 ;
  inArgument_p.method_prefix (var_lkey_7893, var_prefix_7956, var_tag_5F_to_5F_rep_7983, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 251)) ;
  ioArgument_res = ioArgument_res.getter_stringByReplacingStringByString (var_tag_5F_to_5F_rep_7983, var_prefix_7956.add_operation (inArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 252)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 252)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'doReplace'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_doReplace (GALGAS_string & ioArgument_s,
                        GALGAS_string inArgument_o,
                        GALGAS_string inArgument_n,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_s = ioArgument_s.getter_stringByReplacingStringByString (inArgument_o, inArgument_n, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 256)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'do_replace_default'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_do_5F_replace_5F_default (GALGAS_string & ioArgument_s,
                                       GALGAS_string inArgument_o,
                                       GALGAS_string inArgument_n,
                                       GALGAS_string inArgument_d,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, inArgument_n.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      ioArgument_s = ioArgument_s.getter_stringByReplacingStringByString (inArgument_o, inArgument_n, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 261)) ;
    }
  }
  if (kBoolFalse == test_0) {
    ioArgument_s = ioArgument_s.getter_stringByReplacingStringByString (inArgument_o, inArgument_d, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 263)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'replace_no_prefix'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_replace_5F_no_5F_prefix (GALGAS_prefix_5F_map inArgument_p,
                                      GALGAS_string inArgument_key,
                                      GALGAS_string inArgument_name,
                                      GALGAS_string & ioArgument_res,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkey_8510 = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 268))  COMMA_SOURCE_FILE ("goil_routines.galgas", 268)) ;
  GALGAS_string var_tag_5F_to_5F_rep_8599 ;
  GALGAS_string joker_8621 ; // Joker input parameter
  inArgument_p.method_prefix (var_lkey_8510, joker_8621, var_tag_5F_to_5F_rep_8599, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 271)) ;
  ioArgument_res = ioArgument_res.getter_stringByReplacingStringByString (var_tag_5F_to_5F_rep_8599, inArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 272)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'table_core'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_table_5F_core (GALGAS_string inArgument_typename,
                            GALGAS_string inArgument_varname,
                            GALGAS_string inArgument_obj_5F_prefix,
                            GALGAS_stringset inArgument_names,
                            GALGAS_string & ioArgument_header,
                            GALGAS_string & ioArgument_implementation,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint var_n_9050 = GALGAS_uint (uint32_t (0U)) ;
  cEnumerator_stringset enumerator_9076 (inArgument_names, kENUMERATION_UP) ;
  while (enumerator_9076.hasCurrentObject ()) {
    ioArgument_header = ioArgument_header.add_operation (GALGAS_string ("#define "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (inArgument_varname, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (GALGAS_string ("_id_of_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (enumerator_9076.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (GALGAS_string ("  "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (var_n_9050.getter_string (SOURCE_FILE ("goil_routines.galgas", 291)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)) ;
    ioArgument_header = ioArgument_header.add_operation (GALGAS_string ("#define "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (enumerator_9076.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (GALGAS_string ("  "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (inArgument_varname, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (GALGAS_string ("_id_of_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (enumerator_9076.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)) ;
    ioArgument_implementation = ioArgument_implementation.add_operation (GALGAS_string ("    (tpl_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (inArgument_typename, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (GALGAS_string (" *)&"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (inArgument_obj_5F_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (enumerator_9076.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)) ;
    var_n_9050.increment_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 301)) ;
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (kIsNotEqual, var_n_9050.objectCompare (inArgument_names.getter_count (SOURCE_FILE ("goil_routines.galgas", 302)))).boolEnum () ;
      if (kBoolTrue == test_0) {
        ioArgument_implementation = ioArgument_implementation.add_operation (GALGAS_string (",\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 303)) ;
      }
    }
    if (kBoolFalse == test_0) {
      ioArgument_implementation = ioArgument_implementation.add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 304)) ;
    }
    enumerator_9076.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'add_to_stringset'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_add_5F_to_5F_stringset (GALGAS_stringset & ioArgument_ss,
                                     GALGAS_string inArgument_new,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = ioArgument_ss.getter_hasKey (inArgument_new COMMA_SOURCE_FILE ("goil_routines.galgas", 409)).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 410)), GALGAS_string ("'").add_operation (inArgument_new, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 410)).add_operation (GALGAS_string ("' is already declared before"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 410)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 410)) ;
    }
  }
  if (kBoolFalse == test_0) {
    ioArgument_ss.addAssign_operation (inArgument_new  COMMA_SOURCE_FILE ("goil_routines.galgas", 412)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'file_in_path'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_file_5F_in_5F_path (GALGAS_lstring & ioArgument_file_5F_name,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_include_5F_path_12911 = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("GOIL_INCLUDE_PATH")  COMMA_SOURCE_FILE ("goil_routines.galgas", 418)) ;
  GALGAS_stringlist var_systemPaths_13130 = function_allTemplatePaths (GALGAS_string ("config"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 422)) ;
  GALGAS_stringlist var_includePathList_13196 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, var_include_5F_path_12911.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      var_includePathList_13196 = var_include_5F_path_12911.getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("goil_routines.galgas", 425)) ;
    }
  }
  if (kBoolFalse == test_0) {
    var_includePathList_13196 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 427)) ;
  }
  GALGAS_stringlist var_path_5F_list_13394 = var_includePathList_13196.add_operation (var_systemPaths_13130, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 429)) ;
  GALGAS_bool var_not_5F_found_13447 = GALGAS_bool (true) ;
  cEnumerator_stringlist enumerator_13476 (var_path_5F_list_13394, kENUMERATION_UP) ;
  while (enumerator_13476.hasCurrentObject ()) {
    GALGAS_string var_full_5F_file_5F_path_13525 = enumerator_13476.current_mValue (HERE) ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsNotEqual, var_full_5F_file_5F_path_13525.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = GALGAS_bool (kIsNotEqual, var_full_5F_file_5F_path_13525.getter_characterAtIndex (var_full_5F_file_5F_path_13525.getter_length (SOURCE_FILE ("goil_routines.galgas", 435)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 435)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 435)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
          if (kBoolTrue == test_2) {
            var_full_5F_file_5F_path_13525.plusAssign_operation(GALGAS_string ("/"), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 436)) ;
          }
        }
      }
    }
    var_full_5F_file_5F_path_13525.plusAssign_operation(ioArgument_file_5F_name.readProperty_string (), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 439)) ;
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = var_full_5F_file_5F_path_13525.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 440)).operator_and (var_not_5F_found_13447 COMMA_SOURCE_FILE ("goil_routines.galgas", 440)).boolEnum () ;
      if (kBoolTrue == test_3) {
        ioArgument_file_5F_name = GALGAS_lstring::constructor_new (var_full_5F_file_5F_path_13525, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 441))  COMMA_SOURCE_FILE ("goil_routines.galgas", 441)) ;
        var_not_5F_found_13447 = GALGAS_bool (false) ;
      }
    }
    enumerator_13476.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'is_in_lstringlist'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_is_5F_in_5F_lstringlist (GALGAS_lstringlist inArgument_l,
                                      GALGAS_lstring inArgument_e,
                                      GALGAS_lstring & outArgument_f,
                                      GALGAS_bool & outArgument_p,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_f.drop () ; // Release 'out' argument
  outArgument_p.drop () ; // Release 'out' argument
  outArgument_p = GALGAS_bool (false) ;
  outArgument_f = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 453))  COMMA_SOURCE_FILE ("goil_routines.galgas", 453)) ;
  cEnumerator_lstringlist enumerator_14127 (inArgument_l, kENUMERATION_UP) ;
  while (enumerator_14127.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (kIsEqual, enumerator_14127.current_mValue (HERE).readProperty_string ().objectCompare (inArgument_e.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_p = GALGAS_bool (true) ;
        outArgument_f = enumerator_14127.current_mValue (HERE) ;
      }
    }
    enumerator_14127.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Function 'isInLstringlist'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool function_isInLstringlist (GALGAS_lstringlist inArgument_l,
                                      GALGAS_lstring inArgument_e,
                                      C_Compiler *
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_p ; // Returned variable
  result_p = GALGAS_bool (false) ;
  cEnumerator_lstringlist enumerator_14325 (inArgument_l, kENUMERATION_UP) ;
  while (enumerator_14325.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (kIsEqual, enumerator_14325.current_mValue (HERE).readProperty_string ().objectCompare (inArgument_e.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_0) {
        result_p = GALGAS_bool (true) ;
      }
    }
    enumerator_14325.gotoNextObject () ;
  }
//---
  return result_p ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_isInLstringlist [3] = {
  & kTypeDescriptor_GALGAS_lstringlist,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_isInLstringlist (C_Compiler * inCompiler,
                                                                const cObjectArray & inEffectiveParameterArray,
                                                                const GALGAS_location & /* inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  const GALGAS_lstringlist operand0 = GALGAS_lstringlist::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_isInLstringlist (operand0,
                                   operand1,
                                   inCompiler
                                   COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_isInLstringlist ("isInLstringlist",
                                                                 functionWithGenericHeader_isInLstringlist,
                                                                 & kTypeDescriptor_GALGAS_bool,
                                                                 2,
                                                                 functionArgs_isInLstringlist) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'add_lstring_unique'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_add_5F_lstring_5F_unique (GALGAS_lstringlist & ioArgument_l,
                                       GALGAS_lstring inArgument_e,
                                       GALGAS_string inArgument_att,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool var_found_14496 ;
  GALGAS_lstring var_res_14515 ;
  {
  routine_is_5F_in_5F_lstringlist (ioArgument_l, inArgument_e, var_res_14515, var_found_14496, inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 480)) ;
  }
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = var_found_14496.boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (inArgument_e.readProperty_location (), inArgument_att.add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 482)).add_operation (inArgument_e.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 482)).add_operation (GALGAS_string (" has already be listed"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 482)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 482)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (var_res_14515.readProperty_location (), GALGAS_string ("was listed here"), fixItArray2  COMMA_SOURCE_FILE ("goil_routines.galgas", 483)) ;
    }
  }
  if (kBoolFalse == test_0) {
    ioArgument_l.addAssign_operation (inArgument_e  COMMA_SOURCE_FILE ("goil_routines.galgas", 485)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'set_lstring_if_empty'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_set_5F_lstring_5F_if_5F_empty (GALGAS_lstring & ioArgument_s,
                                            GALGAS_lstring inArgument_ns,
                                            GALGAS_string inArgument_att,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, ioArgument_s.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      ioArgument_s = inArgument_ns ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (inArgument_ns.readProperty_location (), inArgument_att.add_operation (GALGAS_string (" Redefinition"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 496)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 496)) ;
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (ioArgument_s.readProperty_location (), GALGAS_string ("was defined here"), fixItArray2  COMMA_SOURCE_FILE ("goil_routines.galgas", 497)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'add_makefile_flag_if_not_empty'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_add_5F_makefile_5F_flag_5F_if_5F_not_5F_empty (GALGAS_string & ioArgument_receiver,
                                                            GALGAS_string inArgument_flag_5F_name,
                                                            GALGAS_string inArgument_flag_5F_value,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, inArgument_flag_5F_value.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      ioArgument_receiver.plusAssign_operation(inArgument_flag_5F_name.add_operation (GALGAS_string ("="), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 506)).add_operation (inArgument_flag_5F_value, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 506)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 506)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 506)) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Function 'lstringWith'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring function_lstringWith (GALGAS_string inArgument_s,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_r ; // Returned variable
  result_r = GALGAS_lstring::constructor_new (inArgument_s, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 511))  COMMA_SOURCE_FILE ("goil_routines.galgas", 511)) ;
//---
  return result_r ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_lstringWith [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_lstringWith (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_lstringWith (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_lstringWith ("lstringWith",
                                                             functionWithGenericHeader_lstringWith,
                                                             & kTypeDescriptor_GALGAS_lstring,
                                                             1,
                                                             functionArgs_lstringWith) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stripString'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_stripString (GALGAS_string inArgument_s,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_r ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 515)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_uint var_first_15248 = GALGAS_uint (uint32_t (0U)) ;
      GALGAS_uint var_last_15267 = inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 517)) ;
      GALGAS_bool var_finished_15355 = GALGAS_bool (false) ;
      if (inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 520)).isValid ()) {
        uint32_t variant_15372 = inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 520)).uintValue () ;
        bool loop_15372 = true ;
        while (loop_15372) {
          loop_15372 = var_finished_15355.operator_not (SOURCE_FILE ("goil_routines.galgas", 521)).isValid () ;
          if (loop_15372) {
            loop_15372 = var_finished_15355.operator_not (SOURCE_FILE ("goil_routines.galgas", 521)).boolValue () ;
          }
          if (loop_15372 && (0 == variant_15372)) {
            loop_15372 = false ;
            inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 520)) ;
          }
          if (loop_15372) {
            variant_15372 -- ;
            enumGalgasBool test_1 = kBoolTrue ;
            if (kBoolTrue == test_1) {
              test_1 = GALGAS_bool (kIsEqual, inArgument_s.getter_characterAtIndex (var_first_15248, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 522)).objectCompare (GALGAS_char (TO_UNICODE (32)))).boolEnum () ;
              if (kBoolTrue == test_1) {
                var_first_15248.increment_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 523)) ;
                enumGalgasBool test_2 = kBoolTrue ;
                if (kBoolTrue == test_2) {
                  test_2 = GALGAS_bool (kIsEqual, var_first_15248.objectCompare (inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 524)))).boolEnum () ;
                  if (kBoolTrue == test_2) {
                    var_finished_15355 = GALGAS_bool (true) ;
                  }
                }
              }
            }
            if (kBoolFalse == test_1) {
              var_finished_15355 = GALGAS_bool (true) ;
            }
          }
        }
      }
      var_finished_15355 = GALGAS_bool (false) ;
      if (inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 529)).isValid ()) {
        uint32_t variant_15657 = inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 529)).uintValue () ;
        bool loop_15657 = true ;
        while (loop_15657) {
          loop_15657 = var_finished_15355.operator_not (SOURCE_FILE ("goil_routines.galgas", 530)).isValid () ;
          if (loop_15657) {
            loop_15657 = var_finished_15355.operator_not (SOURCE_FILE ("goil_routines.galgas", 530)).boolValue () ;
          }
          if (loop_15657 && (0 == variant_15657)) {
            loop_15657 = false ;
            inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 529)) ;
          }
          if (loop_15657) {
            variant_15657 -- ;
            enumGalgasBool test_3 = kBoolTrue ;
            if (kBoolTrue == test_3) {
              test_3 = GALGAS_bool (kIsEqual, inArgument_s.getter_characterAtIndex (var_last_15267.substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 531)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 531)).objectCompare (GALGAS_char (TO_UNICODE (32)))).boolEnum () ;
              if (kBoolTrue == test_3) {
                var_last_15267.decrement_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 532)) ;
                enumGalgasBool test_4 = kBoolTrue ;
                if (kBoolTrue == test_4) {
                  test_4 = GALGAS_bool (kIsEqual, var_last_15267.objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
                  if (kBoolTrue == test_4) {
                    var_finished_15355 = GALGAS_bool (true) ;
                  }
                }
              }
            }
            if (kBoolFalse == test_3) {
              var_finished_15355 = GALGAS_bool (true) ;
            }
          }
        }
      }
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsStrictInf, var_first_15248.objectCompare (var_last_15267)).boolEnum () ;
        if (kBoolTrue == test_5) {
          result_r = inArgument_s.getter_subString (var_first_15248, var_last_15267.substract_operation (var_first_15248, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 538)) COMMA_SOURCE_FILE ("goil_routines.galgas", 538)) ;
        }
      }
      if (kBoolFalse == test_5) {
        result_r = GALGAS_string::makeEmptyString () ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    result_r = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_r ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stripString [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stripString (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_stripString (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stripString ("stripString",
                                                             functionWithGenericHeader_stripString,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             1,
                                                             functionArgs_stripString) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'errorNoFileFound'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_errorNoFileFound (const GALGAS_stringlist constinArgument_searchedPaths,
                               const GALGAS_string constinArgument_kind,
                               const GALGAS_lstring constinArgument_file,
                               C_Compiler * inCompiler
                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_m_16123 = GALGAS_string ("cannot find a valid path for the '").add_operation (constinArgument_file.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 551)).add_operation (GALGAS_string ("' "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 551)).add_operation (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 551)).add_operation (GALGAS_string (" file. I have tried:"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 551)) ;
  cEnumerator_stringlist enumerator_16217 (constinArgument_searchedPaths, kENUMERATION_UP) ;
  while (enumerator_16217.hasCurrentObject ()) {
    var_m_16123.plusAssign_operation(GALGAS_string ("\n"
      "  - '").add_operation (enumerator_16217.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 553)).add_operation (GALGAS_string ("'"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 553)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 553)) ;
    enumerator_16217.gotoNextObject () ;
  }
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (constinArgument_file.readProperty_location (), var_m_16123, fixItArray0  COMMA_SOURCE_FILE ("goil_routines.galgas", 555)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stringLBool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_stringLBool (const GALGAS_lbool & constinArgument_boolValue,
                                    C_Compiler *
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_boolValue.readProperty_bool ().boolEnum () ;
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

static const C_galgas_type_descriptor * functionArgs_stringLBool [2] = {
  & kTypeDescriptor_GALGAS_lbool,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringLBool (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_lbool operand0 = GALGAS_lbool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                             inCompiler
                                                             COMMA_THERE) ;
  return function_stringLBool (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringLBool ("stringLBool",
                                                             functionWithGenericHeader_stringLBool,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             1,
                                                             functionArgs_stringLBool) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@structAttribute set'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_structAttribute::method_set (const GALGAS_lstring constinArgument_name,
                                       GALGAS_gtlData & ioArgument_result,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_subAttrs_935 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) this->mProperty_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 33)) ;
  {
  var_subAttrs_935.insulate (HERE) ;
  cPtr_gtlData * ptr_976 = (cPtr_gtlData *) var_subAttrs_935.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_976, GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), this->mProperty_structName.readProperty_location ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 35)), GALGAS_gtlString::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_structName.readProperty_string ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 36)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 34)) ;
  }
  {
  var_subAttrs_935.setter_setMeta (this->mProperty_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 38)) ;
  }
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_1129 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1129, constinArgument_name, var_subAttrs_935, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 39)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@boolAttribute set'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_boolAttribute::method_set (const GALGAS_lstring constinArgument_name,
                                     GALGAS_gtlData & ioArgument_result,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_1575 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1575, constinArgument_name, GALGAS_gtlBool::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 52)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 52)) ;
  }
  GALGAS_gtlData var_subAttrs_1662 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) this->mProperty_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 53)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlStruct temp_1 ;
    if (var_subAttrs_1662.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_1662.ptr ())) {
        temp_1 = (cPtr_gtlStruct *) var_subAttrs_1662.ptr () ;
      }else{
        inCompiler->castError ("gtlStruct", var_subAttrs_1662.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 54)) ;
      }
    }
    test_0 = GALGAS_bool (kIsStrictSup, temp_1.readProperty_value ().getter_count (SOURCE_FILE ("systemConfig.galgas", 54)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_structName_1770 = GALGAS_lstring::constructor_new (constinArgument_name.readProperty_string ().add_operation (GALGAS_string ("_S"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 55)), constinArgument_name.readProperty_location ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 55)) ;
      {
      var_subAttrs_1662.setter_setMeta (this->mProperty_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 56)) ;
      }
      {
      ioArgument_result.insulate (HERE) ;
      cPtr_gtlData * ptr_1876 = (cPtr_gtlData *) ioArgument_result.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1876, var_structName_1770, var_subAttrs_1662, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 57)) ;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@enumAttribute set'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_enumAttribute::method_set (const GALGAS_lstring constinArgument_name,
                                     GALGAS_gtlData & ioArgument_result,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_2195 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2195, constinArgument_name, GALGAS_gtlString::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 66)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 66)) ;
  }
  GALGAS_gtlData var_subAttrs_2284 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) this->mProperty_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 67)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlStruct temp_1 ;
    if (var_subAttrs_2284.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_2284.ptr ())) {
        temp_1 = (cPtr_gtlStruct *) var_subAttrs_2284.ptr () ;
      }else{
        inCompiler->castError ("gtlStruct", var_subAttrs_2284.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 68)) ;
      }
    }
    test_0 = GALGAS_bool (kIsStrictSup, temp_1.readProperty_value ().getter_count (SOURCE_FILE ("systemConfig.galgas", 68)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_structName_2392 = GALGAS_lstring::constructor_new (constinArgument_name.readProperty_string ().add_operation (GALGAS_string ("_S"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 69)), constinArgument_name.readProperty_location ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 69)) ;
      {
      var_subAttrs_2284.setter_setMeta (this->mProperty_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 70)) ;
      }
      {
      ioArgument_result.insulate (HERE) ;
      cPtr_gtlData * ptr_2498 = (cPtr_gtlData *) ioArgument_result.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2498, var_structName_2392, var_subAttrs_2284, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 71)) ;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@stringAttribute set'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_stringAttribute::method_set (const GALGAS_lstring constinArgument_name,
                                       GALGAS_gtlData & ioArgument_result,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_2633 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2633, constinArgument_name, GALGAS_gtlString::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 76)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 76)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@string_class set'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_string_5F_class::method_set (const GALGAS_lstring constinArgument_name,
                                       GALGAS_gtlData & ioArgument_result,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_2790 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2790, constinArgument_name, GALGAS_gtlString::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 80)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 80)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@objectRefAttribute set'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_objectRefAttribute::method_set (const GALGAS_lstring constinArgument_name,
                                          GALGAS_gtlData & ioArgument_result,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_2953 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2953, constinArgument_name, GALGAS_gtlString::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value.readProperty_string ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 84)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 84)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@multipleAttribute set'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_multipleAttribute::method_set (const GALGAS_lstring constinArgument_name,
                                         GALGAS_gtlData & ioArgument_result,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlList var_multiple_3123 = GALGAS_gtlList::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 88)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 88)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("systemConfig.galgas", 88))  COMMA_SOURCE_FILE ("systemConfig.galgas", 88)) ;
  cEnumerator_identifierList enumerator_3178 (this->mProperty_items, kENUMERATION_UP) ;
  while (enumerator_3178.hasCurrentObject ()) {
    GALGAS_gtlData var_multipleItem_3217 = GALGAS_gtlStruct::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 90))  COMMA_SOURCE_FILE ("systemConfig.galgas", 90)) ;
    if (enumerator_3178.current_item (HERE).isValid ()) {
      if (enumerator_3178.current_item (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_structAttribute) {
        GALGAS_structAttribute cast_3320_aStruct ((cPtr_structAttribute *) enumerator_3178.current_item (HERE).ptr ()) ;
        {
        var_multipleItem_3217.insulate (HERE) ;
        cPtr_gtlData * ptr_3344 = (cPtr_gtlData *) var_multipleItem_3217.ptr () ;
        callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3344, GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), cast_3320_aStruct.readProperty_location ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 94)), GALGAS_gtlString::constructor_new (cast_3320_aStruct.readProperty_location (), cast_3320_aStruct.readProperty_oil_5F_desc (), cast_3320_aStruct.readProperty_structName ().readProperty_string ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 95)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 93)) ;
        }
        GALGAS_gtlData var_subAttrs_3578 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) cast_3320_aStruct.readProperty_subAttributes ().ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 101)) ;
        enumGalgasBool test_0 = kBoolTrue ;
        if (kBoolTrue == test_0) {
          GALGAS_gtlStruct temp_1 ;
          if (var_subAttrs_3578.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_3578.ptr ())) {
              temp_1 = (cPtr_gtlStruct *) var_subAttrs_3578.ptr () ;
            }else{
              inCompiler->castError ("gtlStruct", var_subAttrs_3578.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 102)) ;
            }
          }
          test_0 = GALGAS_bool (kIsStrictSup, temp_1.readProperty_value ().getter_count (SOURCE_FILE ("systemConfig.galgas", 102)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
          if (kBoolTrue == test_0) {
            GALGAS_gtlStruct temp_2 ;
            if (var_subAttrs_3578.isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_3578.ptr ())) {
                temp_2 = (cPtr_gtlStruct *) var_subAttrs_3578.ptr () ;
              }else{
                inCompiler->castError ("gtlStruct", var_subAttrs_3578.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 103)) ;
              }
            }
            cEnumerator_gtlVarMap enumerator_3687 (temp_2.readProperty_value (), kENUMERATION_UP) ;
            while (enumerator_3687.hasCurrentObject ()) {
              {
              var_multipleItem_3217.insulate (HERE) ;
              cPtr_gtlData * ptr_3751 = (cPtr_gtlData *) var_multipleItem_3217.ptr () ;
              callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3751, enumerator_3687.current_lkey (HERE), enumerator_3687.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 104)) ;
              }
              enumerator_3687.gotoNextObject () ;
            }
          }
        }
      }else{
        callExtensionMethod_set ((cPtr_object_5F_t *) enumerator_3178.current_item (HERE).ptr (), GALGAS_lstring::constructor_new (GALGAS_string ("VALUE"), enumerator_3178.current_item (HERE).readProperty_location ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 108)), var_multipleItem_3217, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 108)) ;
      }
    }
    {
    var_multiple_3123.insulate (HERE) ;
    cPtr_gtlList * ptr_3911 = (cPtr_gtlList *) var_multiple_3123.ptr () ;
    callExtensionSetter_appendItem ((cPtr_gtlList *) ptr_3911, var_multipleItem_3217, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 110)) ;
    }
    enumerator_3178.gotoNextObject () ;
  }
  {
  var_multiple_3123.setter_setMeta (this->mProperty_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 112)) ;
  }
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_3988 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3988, constinArgument_name, var_multiple_3123, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 113)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@uint32_class set'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_uint_33__32__5F_class::method_set (const GALGAS_lstring constinArgument_name,
                                             GALGAS_gtlData & ioArgument_result,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4108 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4108, constinArgument_name, GALGAS_gtlInt::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 119))  COMMA_SOURCE_FILE ("systemConfig.galgas", 119)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 117)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@sint32_class set'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_sint_33__32__5F_class::method_set (const GALGAS_lstring constinArgument_name,
                                             GALGAS_gtlData & ioArgument_result,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4282 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4282, constinArgument_name, GALGAS_gtlInt::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 126))  COMMA_SOURCE_FILE ("systemConfig.galgas", 126)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 124)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@uint64_class set'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_uint_36__34__5F_class::method_set (const GALGAS_lstring constinArgument_name,
                                             GALGAS_gtlData & ioArgument_result,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4456 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4456, constinArgument_name, GALGAS_gtlInt::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 133))  COMMA_SOURCE_FILE ("systemConfig.galgas", 133)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 131)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@sint64_class set'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_sint_36__34__5F_class::method_set (const GALGAS_lstring constinArgument_name,
                                             GALGAS_gtlData & ioArgument_result,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4630 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4630, constinArgument_name, GALGAS_gtlInt::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 140))  COMMA_SOURCE_FILE ("systemConfig.galgas", 140)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 138)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@float_class set'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_float_5F_class::method_set (const GALGAS_lstring constinArgument_name,
                                      GALGAS_gtlData & ioArgument_result,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4803 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4803, constinArgument_name, GALGAS_gtlFloat::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 147)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 145)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@auto set'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_auto::method_set (const GALGAS_lstring constinArgument_name,
                            GALGAS_gtlData & ioArgument_result,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4962 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4962, constinArgument_name, GALGAS_gtlEnum::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, GALGAS_string ("auto")  COMMA_SOURCE_FILE ("systemConfig.galgas", 154)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 152)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'setDefaults'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_setDefaults (const GALGAS_implementation constinArgument_imp,
                          GALGAS_applicationDefinition & ioArgument_application,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectsMap var_objects_876 = ioArgument_application.readProperty_objects () ;
  cEnumerator_lstringlist enumerator_957 (var_objects_876.getter_keyList (SOURCE_FILE ("defaults.galgas", 35)), kENUMERATION_UP) ;
  while (enumerator_957.hasCurrentObject ()) {
    cMapElement_objectsMap * objectArray_992 = (cMapElement_objectsMap *) var_objects_876.readWriteAccessForWithInstructionWithErrorMessage (inCompiler, enumerator_957.current_mValue (HERE), kSearchErrorMessage_objectsMap_get  COMMA_SOURCE_FILE ("defaults.galgas", 36)) ;
    if (NULL != objectArray_992) {
      macroValidSharedObject (objectArray_992, cMapElement_objectsMap) ;
      GALGAS_objectKindMap var_objOfKind_1069 = objectArray_992->mProperty_objectsOfKind.readProperty_objects () ;
      cEnumerator_lstringlist enumerator_1126 (var_objOfKind_1069.getter_keyList (SOURCE_FILE ("defaults.galgas", 38)), kENUMERATION_UP) ;
      while (enumerator_1126.hasCurrentObject ()) {
        cMapElement_objectKindMap * objectArray_1167 = (cMapElement_objectKindMap *) var_objOfKind_1069.readWriteAccessForWithInstructionWithErrorMessage (inCompiler, enumerator_1126.current_mValue (HERE), kSearchErrorMessage_objectKindMap_get  COMMA_SOURCE_FILE ("defaults.galgas", 39)) ;
        if (NULL != objectArray_1167) {
          macroValidSharedObject (objectArray_1167, cMapElement_objectKindMap) ;
          GALGAS_implementationObject var_impObject_1261 = callExtensionGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), enumerator_957.current_mValue (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("defaults.galgas", 40)) ;
          {
          routine_setDefaultsForType (var_impObject_1261.readProperty_attributes (), objectArray_1167->mProperty_attributes, inCompiler  COMMA_SOURCE_FILE ("defaults.galgas", 41)) ;
          }
        }
        enumerator_1126.gotoNextObject () ;
      }
      {
      objectArray_992->mProperty_objectsOfKind.setter_setObjects (var_objOfKind_1069 COMMA_SOURCE_FILE ("defaults.galgas", 44)) ;
      }
    }
    enumerator_957.gotoNextObject () ;
  }
  {
  ioArgument_application.setter_setObjects (var_objects_876 COMMA_SOURCE_FILE ("defaults.galgas", 48)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@impStructType verifyType'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_impStructType::method_verifyType (const GALGAS_object_5F_t constinArgument_attr,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_structAttribute) {
      GALGAS_structAttribute cast_2383_sa ((cPtr_structAttribute *) constinArgument_attr.ptr ()) ;
      cEnumerator_implementationObjectMap enumerator_2396 (this->mProperty_structAttributes, kENUMERATION_UP) ;
      while (enumerator_2396.hasCurrentObject ()) {
        enumGalgasBool test_0 = kBoolTrue ;
        if (kBoolTrue == test_0) {
          test_0 = cast_2383_sa.readProperty_subAttributes ().readProperty_objectParams ().getter_hasKey (enumerator_2396.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("semantic_verification.galgas", 88)).boolEnum () ;
          if (kBoolTrue == test_0) {
            GALGAS_object_5F_t var_subAttr_2522 ;
            cast_2383_sa.readProperty_subAttributes ().readProperty_objectParams ().method_get (enumerator_2396.current_lkey (HERE), var_subAttr_2522, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 90)) ;
            callExtensionMethod_verifyMultipleType ((cPtr_impType *) enumerator_2396.current_type (HERE).ptr (), var_subAttr_2522, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 91)) ;
          }
        }
        enumerator_2396.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), GALGAS_string ("STRUCT expected"), fixItArray1  COMMA_SOURCE_FILE ("semantic_verification.galgas", 95)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@refType verifyType'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_refType::method_verifyType (const GALGAS_object_5F_t constinArgument_attr,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_objectRefAttribute) {
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), GALGAS_string ("object reference expected"), fixItArray0  COMMA_SOURCE_FILE ("semantic_verification.galgas", 105)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@impBoolType verifyType'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_impBoolType::method_verifyType (const GALGAS_object_5F_t constinArgument_attr,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_3144_b ((cPtr_boolAttribute *) constinArgument_attr.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = cast_3144_b.readProperty_value ().boolEnum () ;
        if (kBoolTrue == test_0) {
          cEnumerator_implementationObjectMap enumerator_3181 (this->mProperty_trueSubAttributes, kENUMERATION_UP) ;
          while (enumerator_3181.hasCurrentObject ()) {
            enumGalgasBool test_1 = kBoolTrue ;
            if (kBoolTrue == test_1) {
              test_1 = cast_3144_b.readProperty_subAttributes ().readProperty_objectParams ().getter_hasKey (enumerator_3181.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("semantic_verification.galgas", 116)).boolEnum () ;
              if (kBoolTrue == test_1) {
                GALGAS_object_5F_t var_subAttrs_3312 ;
                cast_3144_b.readProperty_subAttributes ().readProperty_objectParams ().method_get (enumerator_3181.current_lkey (HERE), var_subAttrs_3312, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 118)) ;
                callExtensionMethod_verifyMultipleType ((cPtr_impType *) enumerator_3181.current_type (HERE).ptr (), var_subAttrs_3312, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 119)) ;
              }
            }
            enumerator_3181.gotoNextObject () ;
          }
        }
      }
      if (kBoolFalse == test_0) {
        cEnumerator_implementationObjectMap enumerator_3467 (this->mProperty_falseSubAttributes, kENUMERATION_UP) ;
        while (enumerator_3467.hasCurrentObject ()) {
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            test_2 = cast_3144_b.readProperty_subAttributes ().readProperty_objectParams ().getter_hasKey (enumerator_3467.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("semantic_verification.galgas", 124)).boolEnum () ;
            if (kBoolTrue == test_2) {
              GALGAS_object_5F_t var_subAttrs_3599 ;
              cast_3144_b.readProperty_subAttributes ().readProperty_objectParams ().method_get (enumerator_3467.current_lkey (HERE), var_subAttrs_3599, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 126)) ;
              callExtensionMethod_verifyMultipleType ((cPtr_impType *) enumerator_3467.current_type (HERE).ptr (), var_subAttrs_3599, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 127)) ;
            }
          }
          enumerator_3467.gotoNextObject () ;
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), GALGAS_string ("BOOLEAN expected"), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 132)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@impEnumType verifyType'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_impEnumType::method_verifyType (const GALGAS_object_5F_t constinArgument_attr,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_enumAttribute) {
      GALGAS_enumAttribute cast_3985_e ((cPtr_enumAttribute *) constinArgument_attr.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = this->mProperty_valuesMap.getter_hasKey (cast_3985_e.readProperty_value () COMMA_SOURCE_FILE ("semantic_verification.galgas", 141)).boolEnum () ;
        if (kBoolTrue == test_0) {
          GALGAS_implementationObjectMap var_validVal_4073 ;
          this->mProperty_valuesMap.method_get (function_lstringWith (cast_3985_e.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 143)), var_validVal_4073, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 143)) ;
          cEnumerator_implementationObjectMap enumerator_4143 (var_validVal_4073, kENUMERATION_UP) ;
          while (enumerator_4143.hasCurrentObject ()) {
            enumGalgasBool test_1 = kBoolTrue ;
            if (kBoolTrue == test_1) {
              test_1 = cast_3985_e.readProperty_subAttributes ().readProperty_objectParams ().getter_hasKey (enumerator_4143.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("semantic_verification.galgas", 145)).boolEnum () ;
              if (kBoolTrue == test_1) {
                GALGAS_object_5F_t var_subAttrs_4265 ;
                cast_3985_e.readProperty_subAttributes ().readProperty_objectParams ().method_get (enumerator_4143.current_lkey (HERE), var_subAttrs_4265, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 147)) ;
                callExtensionMethod_verifyMultipleType ((cPtr_impType *) enumerator_4143.current_type (HERE).ptr (), var_subAttrs_4265, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 148)) ;
              }
            }
            enumerator_4143.gotoNextObject () ;
          }
        }
      }
      if (kBoolFalse == test_0) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (cast_3985_e.readProperty_location (), cast_3985_e.readProperty_value ().add_operation (GALGAS_string (" is not a valid enum value"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 152)), fixItArray2  COMMA_SOURCE_FILE ("semantic_verification.galgas", 152)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
    }else{
      inCompiler->printMessage (GALGAS_string ("**** @impEnumType ****\n")  COMMA_SOURCE_FILE ("semantic_verification.galgas", 156)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), GALGAS_string ("ENUM expected"), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 157)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@impAutoDefaultType verifyType'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_impAutoDefaultType::method_verifyType (const GALGAS_object_5F_t constinArgument_attr,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_stringAttribute) {
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (GALGAS_dataType::constructor_string (SOURCE_FILE ("semantic_verification.galgas", 167)))).operator_and (GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (GALGAS_dataType::constructor_identifier (SOURCE_FILE ("semantic_verification.galgas", 167)))) COMMA_SOURCE_FILE ("semantic_verification.galgas", 167)).boolEnum () ;
        if (kBoolTrue == test_0) {
          TC_Array <C_FixItDescription> fixItArray1 ;
          inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), GALGAS_string ("string of identifier expected"), fixItArray1  COMMA_SOURCE_FILE ("semantic_verification.galgas", 168)) ;
        }
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_string_5F_class) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (GALGAS_dataType::constructor_identifier (SOURCE_FILE ("semantic_verification.galgas", 171)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          TC_Array <C_FixItDescription> fixItArray3 ;
          inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), extensionGetter_oilType (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 172)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 172)), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 172)) ;
        }
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
    }else{
      inCompiler->printMessage (GALGAS_string ("*** @impAutoDefaultType ***\n")  COMMA_SOURCE_FILE ("semantic_verification.galgas", 176)) ;
      constinArgument_attr.log ("attr"  COMMA_SOURCE_FILE ("semantic_verification.galgas", 177)) ;
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), extensionGetter_oilType (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 178)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 178)), fixItArray4  COMMA_SOURCE_FILE ("semantic_verification.galgas", 178)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@impRangedType verifyType'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_impRangedType::method_verifyType (const GALGAS_object_5F_t constinArgument_attr,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("semantic_verification.galgas", 188)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          TC_Array <C_FixItDescription> fixItArray1 ;
          inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), extensionGetter_oilType (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)), fixItArray1  COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)) ;
        }
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32__5F_class) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("semantic_verification.galgas", 192)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          TC_Array <C_FixItDescription> fixItArray3 ;
          inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), extensionGetter_oilType (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)) ;
        }
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("semantic_verification.galgas", 196)))).boolEnum () ;
        if (kBoolTrue == test_4) {
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), extensionGetter_oilType (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)), fixItArray5  COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)) ;
        }
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34__5F_class) {
      enumGalgasBool test_6 = kBoolTrue ;
      if (kBoolTrue == test_6) {
        test_6 = GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("semantic_verification.galgas", 200)))).boolEnum () ;
        if (kBoolTrue == test_6) {
          TC_Array <C_FixItDescription> fixItArray7 ;
          inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), extensionGetter_oilType (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)), fixItArray7  COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)) ;
        }
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_float_5F_class) {
      enumGalgasBool test_8 = kBoolTrue ;
      if (kBoolTrue == test_8) {
        test_8 = GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("semantic_verification.galgas", 204)))).boolEnum () ;
        if (kBoolTrue == test_8) {
          TC_Array <C_FixItDescription> fixItArray9 ;
          inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), extensionGetter_oilType (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 205)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 205)), fixItArray9  COMMA_SOURCE_FILE ("semantic_verification.galgas", 205)) ;
        }
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
      enumGalgasBool test_10 = kBoolTrue ;
      if (kBoolTrue == test_10) {
        test_10 = GALGAS_bool (kIsEqual, this->mProperty_withAuto.objectCompare (GALGAS_bool (false))).boolEnum () ;
        if (kBoolTrue == test_10) {
          TC_Array <C_FixItDescription> fixItArray11 ;
          inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), GALGAS_string ("AUTO is not allowed for ").add_operation (this->mProperty_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 209)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 209)), fixItArray11  COMMA_SOURCE_FILE ("semantic_verification.galgas", 209)) ;
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray12 ;
      inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), extensionGetter_oilType (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 213)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 213)), fixItArray12  COMMA_SOURCE_FILE ("semantic_verification.galgas", 213)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Function 'attributeAllowsAuto'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool function_attributeAllowsAuto (const GALGAS_impType & constinArgument_type,
                                          C_Compiler *
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_allowsAuto ; // Returned variable
  result_allowsAuto = GALGAS_bool (true) ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impAutoDefaultType *> (constinArgument_type.ptr ())) {
      GALGAS_impAutoDefaultType cast_6586_autoType ((cPtr_impAutoDefaultType *) constinArgument_type.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = cast_6586_autoType.readProperty_withAuto ().operator_not (SOURCE_FILE ("semantic_verification.galgas", 225)).boolEnum () ;
        if (kBoolTrue == test_0) {
          result_allowsAuto = GALGAS_bool (false) ;
        }
      }
    }else{
      result_allowsAuto = GALGAS_bool (false) ;
    }
  }
//---
  return result_allowsAuto ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_attributeAllowsAuto [2] = {
  & kTypeDescriptor_GALGAS_impType,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_attributeAllowsAuto ("attributeAllowsAuto",
                                                                     functionWithGenericHeader_attributeAllowsAuto,
                                                                     & kTypeDescriptor_GALGAS_bool,
                                                                     1,
                                                                     functionArgs_attributeAllowsAuto) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'verifyAllAttributes'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_verifyAllAttributes (const GALGAS_implementation constinArgument_imp,
                                  const GALGAS_objectsMap constinArgument_objects,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_objectsMap enumerator_6886 (constinArgument_objects, kENUMERATION_UP) ;
  while (enumerator_6886.hasCurrentObject ()) {
    GALGAS_implementationObject var_impObj_6938 = callExtensionGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), enumerator_6886.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 242)) ;
    cEnumerator_objectKindMap enumerator_7042 (enumerator_6886.current_objectsOfKind (HERE).readProperty_objects (), kENUMERATION_UP) ;
    while (enumerator_7042.hasCurrentObject ()) {
      cEnumerator_implementationObjectMap enumerator_7091 (var_impObj_6938.readProperty_attributes (), kENUMERATION_UP) ;
      while (enumerator_7091.hasCurrentObject ()) {
        enumGalgasBool test_0 = kBoolTrue ;
        if (kBoolTrue == test_0) {
          test_0 = enumerator_7042.current_attributes (HERE).readProperty_objectParams ().getter_hasKey (enumerator_7091.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("semantic_verification.galgas", 246)).boolEnum () ;
          if (kBoolTrue == test_0) {
            GALGAS_object_5F_t var_value_7320 ;
            enumerator_7042.current_attributes (HERE).readProperty_objectParams ().method_get (enumerator_7091.current_lkey (HERE), var_value_7320, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 250)) ;
            if (var_value_7320.isValid ()) {
              if (var_value_7320.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
                enumGalgasBool test_1 = kBoolTrue ;
                if (kBoolTrue == test_1) {
                  test_1 = function_attributeAllowsAuto (enumerator_7091.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 254)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 254)).boolEnum () ;
                  if (kBoolTrue == test_1) {
                    TC_Array <C_FixItDescription> fixItArray2 ;
                    inCompiler->emitSemanticError (var_value_7320.readProperty_location (), GALGAS_string ("AUTO value is not allowed for the ").add_operation (enumerator_6886.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)), fixItArray2  COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)) ;
                  }
                }
              }
            }
          }
        }
        if (kBoolFalse == test_0) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = function_attributeAllowsAuto (enumerator_7091.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 260)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 260)).operator_and (enumerator_7091.current_type (HERE).readProperty_multiple ().operator_not (SOURCE_FILE ("semantic_verification.galgas", 260)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 260)).boolEnum () ;
            if (kBoolTrue == test_3) {
              TC_Array <C_FixItDescription> fixItArray4 ;
              inCompiler->emitSemanticError (enumerator_7042.current_lkey (HERE).readProperty_location (), GALGAS_string ("In ").add_operation (enumerator_6886.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (enumerator_7042.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (", attribute "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (enumerator_7091.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (" is not defined and is not AUTO"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)), fixItArray4  COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)) ;
            }
          }
        }
        if (enumerator_7091.current_type (HERE).isValid ()) {
          if (enumerator_7091.current_type (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impAutoDefaultType) {
          }
        }
        enumerator_7091.gotoNextObject () ;
      }
      enumerator_7042.gotoNextObject () ;
    }
    enumerator_6886.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@multipleAttribute verifyCrossReferences'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_multipleAttribute::method_verifyCrossReferences (const GALGAS_objectsMap constinArgument_allObjects,
                                                           const GALGAS_impType constinArgument_type,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_identifierList enumerator_19058 (this->mProperty_items, kENUMERATION_UP) ;
  while (enumerator_19058.hasCurrentObject ()) {
    callExtensionMethod_verifyCrossReferences ((cPtr_object_5F_t *) enumerator_19058.current_item (HERE).ptr (), constinArgument_allObjects, constinArgument_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 617)) ;
    enumerator_19058.gotoNextObject () ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@boolAttribute verifyCrossReferences'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_boolAttribute::method_verifyCrossReferences (const GALGAS_objectsMap constinArgument_allObjects,
                                                       const GALGAS_impType constinArgument_type,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impBoolType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impBoolType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impBoolType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impBoolType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 625)) ;
    }
  }
  GALGAS_impBoolType var_boolType_19266 = temp_0 ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = this->mProperty_value.boolEnum () ;
    if (kBoolTrue == test_1) {
      callExtensionMethod_verifyCrossReferences ((cPtr_objectAttributes *) this->mProperty_subAttributes.ptr (), constinArgument_allObjects, var_boolType_19266.readProperty_trueSubAttributes (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 627)) ;
    }
  }
  if (kBoolFalse == test_1) {
    callExtensionMethod_verifyCrossReferences ((cPtr_objectAttributes *) this->mProperty_subAttributes.ptr (), constinArgument_allObjects, var_boolType_19266.readProperty_falseSubAttributes (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 629)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@enumAttribute verifyCrossReferences'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_enumAttribute::method_verifyCrossReferences (const GALGAS_objectsMap constinArgument_allObjects,
                                                       const GALGAS_impType constinArgument_type,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impEnumType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impEnumType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impEnumType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impEnumType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 637)) ;
    }
  }
  GALGAS_impEnumType var_enumType_19626 = temp_0 ;
  GALGAS_lstring var_key_19668 = GALGAS_lstring::constructor_new (this->mProperty_value, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("semantic_verification.galgas", 638))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 638)) ;
  GALGAS_implementationObjectMap var_expectedAttributes_19781 ;
  var_enumType_19626.readProperty_valuesMap ().method_get (var_key_19668, var_expectedAttributes_19781, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 639)) ;
  callExtensionMethod_verifyCrossReferences ((cPtr_objectAttributes *) this->mProperty_subAttributes.ptr (), constinArgument_allObjects, var_expectedAttributes_19781, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 640)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@structAttribute verifyCrossReferences'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_structAttribute::method_verifyCrossReferences (const GALGAS_objectsMap constinArgument_allObjects,
                                                         const GALGAS_impType constinArgument_type,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impStructType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impStructType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impStructType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impStructType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 647)) ;
    }
  }
  GALGAS_impStructType var_structType_19999 = temp_0 ;
  callExtensionMethod_verifyCrossReferences ((cPtr_objectAttributes *) this->mProperty_subAttributes.ptr (), constinArgument_allObjects, var_structType_19999.readProperty_structAttributes (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 648)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@objectRefAttribute verifyCrossReferences'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_objectRefAttribute::method_verifyCrossReferences (const GALGAS_objectsMap constinArgument_allObjects,
                                                            const GALGAS_impType constinArgument_type,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_refType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_refType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_refType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("refType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 655)) ;
    }
  }
  GALGAS_refType var_refType_20246 = temp_0 ;
  GALGAS_objectKind var_kindMap_20373 ;
  constinArgument_allObjects.method_get (var_refType_20246.readProperty_ref (), var_kindMap_20373, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 657)) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = var_kindMap_20373.readProperty_objects ().getter_hasKey (this->mProperty_value.readProperty_string () COMMA_SOURCE_FILE ("semantic_verification.galgas", 658)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 658)).boolEnum () ;
    if (kBoolTrue == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (this->mProperty_value.readProperty_location (), GALGAS_string ("Referenced ").add_operation (var_refType_20246.readProperty_ref ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (this->mProperty_value.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (GALGAS_string (" does not exist"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)), fixItArray2  COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'verifyAll'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_verifyAll (const GALGAS_implementation constinArgument_imp,
                        const GALGAS_applicationDefinition constinArgument_application,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_verifyAllAttributes (constinArgument_imp, constinArgument_application.readProperty_objects (), inCompiler  COMMA_SOURCE_FILE ("semantic_verification.galgas", 681)) ;
  }
  callExtensionMethod_verifyApplication ((cPtr_implementation *) constinArgument_imp.ptr (), constinArgument_application, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 682)) ;
  callExtensionMethod_verifyCrossReferences ((cPtr_applicationDefinition *) constinArgument_application.ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 685)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Function 'emptyApplicationDefinition'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_applicationDefinition function_emptyApplicationDefinition (C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_applicationDefinition result_result ; // Returned variable
  result_result = GALGAS_applicationDefinition::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 56)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 57)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 58)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 59)), GALGAS_objectsMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 60))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 55)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptyApplicationDefinition [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptyApplicationDefinition (C_Compiler * inCompiler,
                                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  return function_emptyApplicationDefinition (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptyApplicationDefinition ("emptyApplicationDefinition",
                                                                            functionWithGenericHeader_emptyApplicationDefinition,
                                                                            & kTypeDescriptor_GALGAS_applicationDefinition,
                                                                            0,
                                                                            functionArgs_emptyApplicationDefinition) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'osObject'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectAttributes function_osObject (const GALGAS_objectsMap & constinArgument_objects,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_os ; // Returned variable
  GALGAS_objectKind var_objectsForKind_1585 ;
  constinArgument_objects.method_get (function_lstringWith (GALGAS_string ("OS"), inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 67)), var_objectsForKind_1585, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 67)) ;
  GALGAS_lstringlist var_names_1662 = var_objectsForKind_1585.readProperty_objects ().getter_keyList (SOURCE_FILE ("goil_types_root.galgas", 68)) ;
  GALGAS_lstring var_name_1719 ;
  var_names_1662.method_first (var_name_1719, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 70)) ;
  var_objectsForKind_1585.readProperty_objects ().method_get (var_name_1719, result_os, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 71)) ;
//---
  return result_os ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_osObject [2] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_osObject ("osObject",
                                                          functionWithGenericHeader_osObject,
                                                          & kTypeDescriptor_GALGAS_objectAttributes,
                                                          1,
                                                          functionArgs_osObject) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'objectForKindAndName'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectAttributes function_objectForKindAndName (const GALGAS_objectsMap & constinArgument_objects,
                                                       const GALGAS_string & constinArgument_kind,
                                                       const GALGAS_string & constinArgument_name,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_object ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 79)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_objectKind var_kindObj_1972 ;
      constinArgument_objects.method_get (function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 81)), var_kindObj_1972, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 81)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = var_kindObj_1972.readProperty_objects ().getter_hasKey (constinArgument_name COMMA_SOURCE_FILE ("goil_types_root.galgas", 82)).boolEnum () ;
        if (kBoolTrue == test_1) {
          var_kindObj_1972.readProperty_objects ().method_get (function_lstringWith (constinArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 83)), result_object, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 83)) ;
        }
      }
      if (kBoolFalse == test_1) {
        result_object = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 85))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 85)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    result_object = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 88))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 88)) ;
  }
//---
  return result_object ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_objectForKindAndName [4] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_objectForKindAndName ("objectForKindAndName",
                                                                      functionWithGenericHeader_objectForKindAndName,
                                                                      & kTypeDescriptor_GALGAS_objectAttributes,
                                                                      3,
                                                                      functionArgs_objectForKindAndName) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'setObjectForKindAndName'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_setObjectForKindAndName (GALGAS_objectsMap & ioArgument_objects,
                                      const GALGAS_string constinArgument_kind,
                                      const GALGAS_string constinArgument_name,
                                      const GALGAS_objectAttributes constinArgument_object,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkind_2435 = function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 97)) ;
  GALGAS_lstring var_lname_2477 = function_lstringWith (constinArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 98)) ;
  GALGAS_objectKind var_kindObj_2520 = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 99))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 99)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = ioArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 100)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      ioArgument_objects.setter_del (var_lkind_2435, var_kindObj_2520, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 101)) ;
      }
    }
  }
  GALGAS_objectKindMap var_kindMap_2668 = var_kindObj_2520.readProperty_objects () ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = var_kindMap_2668.getter_hasKey (constinArgument_name COMMA_SOURCE_FILE ("goil_types_root.galgas", 104)).boolEnum () ;
    if (kBoolTrue == test_1) {
      {
      GALGAS_objectAttributes joker_2749 ; // Joker input parameter
      var_kindMap_2668.setter_del (var_lname_2477, joker_2749, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 105)) ;
      }
    }
  }
  {
  var_kindMap_2668.setter_put (var_lname_2477, constinArgument_object, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 107)) ;
  }
  {
  var_kindObj_2520.setter_setObjects (var_kindMap_2668 COMMA_SOURCE_FILE ("goil_types_root.galgas", 108)) ;
  }
  {
  ioArgument_objects.setter_put (var_lkind_2435, var_kindObj_2520, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 109)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Function 'objectsForKind'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKind function_objectsForKind (const GALGAS_objectsMap & constinArgument_objects,
                                           const GALGAS_string & constinArgument_kind,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectKind result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 116)).boolEnum () ;
    if (kBoolTrue == test_0) {
      constinArgument_objects.method_get (function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 117)), result_result, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 117)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 119))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 119)) ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_objectsForKind [3] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_objectsForKind ("objectsForKind",
                                                                functionWithGenericHeader_objectsForKind,
                                                                & kTypeDescriptor_GALGAS_objectKind,
                                                                2,
                                                                functionArgs_objectsForKind) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'listInOS'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList function_listInOS (const GALGAS_objectsMap & constinArgument_objects,
                                         const GALGAS_string & constinArgument_attributeName,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierList result_items ; // Returned variable
  GALGAS_object_5F_t var_itemsContainer_3238 ;
  GALGAS_objectAttributes var_os_3265 = function_osObject (constinArgument_objects, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 128)) ;
  var_os_3265.readProperty_objectParams ().method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 129)), var_itemsContainer_3238, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 129)) ;
  result_items = function_multipleAttributeOrError (var_itemsContainer_3238, constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 130)) ;
//---
  return result_items ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_listInOS [3] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_listInOS ("listInOS",
                                                          functionWithGenericHeader_listInOS,
                                                          & kTypeDescriptor_GALGAS_identifierList,
                                                          2,
                                                          functionArgs_listInOS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'generate_signed_type'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_generate_5F_signed_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                         GALGAS_string inArgument_err,
                                         GALGAS_string & outArgument_type,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  GALGAS_uint_36__34_ var_max_5F_s_38__1053 = GALGAS_uint_36__34_ (uint64_t (128ULL)) ;
  GALGAS_uint_36__34_ var_max_5F_s_31__36__1085 = GALGAS_uint_36__34_ (uint64_t (32768ULL)) ;
  GALGAS_uint_36__34_ var_max_5F_s_33__32__1117 = GALGAS_uint_36__34_ (uint64_t (2147483648ULL)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_38__1053)).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_type = GALGAS_string ("s8") ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_31__36__1085)).boolEnum () ;
      if (kBoolTrue == test_1) {
        outArgument_type = GALGAS_string ("s16") ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_33__32__1117)).boolEnum () ;
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


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'generate_unsigned_type'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_generate_5F_unsigned_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                           GALGAS_string inArgument_err,
                                           GALGAS_string & outArgument_type,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  GALGAS_uint_36__34_ var_max_5F_u_38__1509 = GALGAS_uint_36__34_ (uint64_t (256ULL)) ;
  GALGAS_uint_36__34_ var_max_5F_u_31__36__1541 = GALGAS_uint_36__34_ (uint64_t (65536ULL)) ;
  GALGAS_uint_36__34_ var_max_5F_u_33__32__1573 = GALGAS_uint_36__34_ (uint64_t (4294967296ULL)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_38__1509)).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_type = GALGAS_string ("u8") ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_31__36__1541)).boolEnum () ;
      if (kBoolTrue == test_1) {
        outArgument_type = GALGAS_string ("u16") ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_33__32__1573)).boolEnum () ;
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


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'generate_mask_type'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_generate_5F_mask_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                       GALGAS_string inArgument_err,
                                       GALGAS_string & outArgument_type,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  GALGAS_uint_36__34_ var_max_5F_u_38__1959 = GALGAS_uint_36__34_ (uint64_t (8ULL)) ;
  GALGAS_uint_36__34_ var_max_5F_u_31__36__1986 = GALGAS_uint_36__34_ (uint64_t (16ULL)) ;
  GALGAS_uint_36__34_ var_max_5F_u_33__32__2013 = GALGAS_uint_36__34_ (uint64_t (32ULL)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_38__1959)).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_type = GALGAS_string ("u8") ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_31__36__1986)).boolEnum () ;
      if (kBoolTrue == test_1) {
        outArgument_type = GALGAS_string ("u16") ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_33__32__2013)).boolEnum () ;
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


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@goilContext fullPrefix'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_goilContext::getter_fullPrefix (const GALGAS_gtlData constinArgument_vars,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_full ; // Returned variable
  GALGAS_string var_stringPrefix_22332 = this->mProperty_prefix.readProperty_string () ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("compiler").objectCompare (var_stringPrefix_22332)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlData var_compiler_22445 ;
      GALGAS_bool joker_22447 ; // Joker input parameter
      callExtensionMethod_structField ((cPtr_gtlData *) constinArgument_vars.ptr (), function_lstring (GALGAS_string ("COMPILER"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 691)), var_compiler_22445, joker_22447, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 691)) ;
      GALGAS_gtlString temp_1 ;
      if (var_compiler_22445.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (var_compiler_22445.ptr ())) {
          temp_1 = (cPtr_gtlString *) var_compiler_22445.ptr () ;
        }else{
          inCompiler->castError ("gtlString", var_compiler_22445.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)) ;
        }
      }
      var_stringPrefix_22332.plusAssign_operation(GALGAS_string ("/").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)), inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("linker").objectCompare (var_stringPrefix_22332)).boolEnum () ;
      if (kBoolTrue == test_2) {
        GALGAS_gtlData var_linker_22601 ;
        GALGAS_bool joker_22603 ; // Joker input parameter
        callExtensionMethod_structField ((cPtr_gtlData *) constinArgument_vars.ptr (), function_lstring (GALGAS_string ("LINKER"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 694)), var_linker_22601, joker_22603, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 694)) ;
        GALGAS_gtlString temp_3 ;
        if (var_linker_22601.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlString *> (var_linker_22601.ptr ())) {
            temp_3 = (cPtr_gtlString *) var_linker_22601.ptr () ;
          }else{
            inCompiler->castError ("gtlString", var_linker_22601.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)) ;
          }
        }
        var_stringPrefix_22332.plusAssign_operation(GALGAS_string ("/").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) temp_3.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)), inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("assembler").objectCompare (var_stringPrefix_22332)).boolEnum () ;
        if (kBoolTrue == test_4) {
          GALGAS_gtlData var_assembler_22764 ;
          GALGAS_bool joker_22766 ; // Joker input parameter
          callExtensionMethod_structField ((cPtr_gtlData *) constinArgument_vars.ptr (), function_lstring (GALGAS_string ("ASSEMBLER"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 697)), var_assembler_22764, joker_22766, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 697)) ;
          GALGAS_gtlString temp_5 ;
          if (var_assembler_22764.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlString *> (var_assembler_22764.ptr ())) {
              temp_5 = (cPtr_gtlString *) var_assembler_22764.ptr () ;
            }else{
              inCompiler->castError ("gtlString", var_assembler_22764.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)) ;
            }
          }
          var_stringPrefix_22332.plusAssign_operation(GALGAS_string ("/").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) temp_5.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)), inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)) ;
        }
      }
      if (kBoolFalse == test_4) {
        enumGalgasBool test_6 = kBoolTrue ;
        if (kBoolTrue == test_6) {
          test_6 = GALGAS_bool (kIsEqual, var_stringPrefix_22332.objectCompare (GALGAS_string ("ROOT"))).boolEnum () ;
          if (kBoolTrue == test_6) {
            var_stringPrefix_22332 = GALGAS_string::makeEmptyString () ;
          }
        }
      }
    }
  }
  result_full = GALGAS_lstring::constructor_new (var_stringPrefix_22332, this->mProperty_prefix.readProperty_location ()  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 702)) ;
//---
  return result_full ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Function 'emptyGoilContext'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_goilContext function_emptyGoilContext (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_goilContext result_context ; // Returned variable
  result_context = GALGAS_goilContext::constructor_new (function_emptylstring (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 710)), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), GALGAS_string (".gtl"), GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_code_generation.galgas", 715)), GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("goil_code_generation.galgas", 716)), GALGAS_bool (true), function_defaultDebugSettings (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 718))  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 709)) ;
//---
  return result_context ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptyGoilContext [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptyGoilContext (C_Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_emptyGoilContext (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptyGoilContext ("emptyGoilContext",
                                                                  functionWithGenericHeader_emptyGoilContext,
                                                                  & kTypeDescriptor_GALGAS_goilContext,
                                                                  0,
                                                                  functionArgs_emptyGoilContext) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'generate_all'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_generate_5F_all (GALGAS_gtlData inArgument_cfg,
                              C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_temp_5F_dir_23454 = function_templates_5F_directory (GALGAS_string ("code"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 735)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, var_temp_5F_dir_23454.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_string var_target_23536 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsNotEqual, var_target_23536.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_gtlContext var_context_23640 = function_emptyGoilContext (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 741)) ;
          {
          var_context_23640.setter_setTemplateDirectory (function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 743)) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 742)) ;
          }
          {
          var_context_23640.setter_setUserTemplateDirectory (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 746)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("goil_code_generation.galgas", 746)).add_operation (GALGAS_string ("/templates"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 746)) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 745)) ;
          }
          {
          var_context_23640.setter_setTemplateExtension (GALGAS_string ("goilTemplate") COMMA_SOURCE_FILE ("goil_code_generation.galgas", 749)) ;
          }
          {
          var_context_23640.insulate (HERE) ;
          cPtr_gtlContext * ptr_24024 = (cPtr_gtlContext *) var_context_23640.ptr () ;
          callExtensionSetter_addModulePath ((cPtr_gtlContext *) ptr_24024, function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 753)), GALGAS_string ("lib"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 752)) ;
          }
          {
          var_context_23640.setter_setPath (GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 756)) ;
          }
          GALGAS_string var_goilLog_24257 = function_invokeGTL (GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 762)), function_lstring (GALGAS_string ("root template filename"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 763)), GALGAS_string (gOption_goil_5F_options_root.readProperty_value ())  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 761)), var_context_23640, inArgument_cfg, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 760)) ;
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            test_2 = GALGAS_bool (gOption_goil_5F_options_generate_5F_log.readProperty_value ()).boolEnum () ;
            if (kBoolTrue == test_2) {
              var_goilLog_24257.method_writeToFile (GALGAS_string ("goil.log"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 771)) ;
            }
          }
        }
      }
      if (kBoolFalse == test_1) {
        inCompiler->printMessage (GALGAS_string ("No target platform given, compiling aborted\n")  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 775)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    inCompiler->printMessage (GALGAS_string ("No template directory defined, compiling aborted\n")  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 778)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'getAutosarVersion'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_getAutosarVersion (GALGAS_arxmlNode inArgument_rootNode,
                                GALGAS_lstring & outArgument_iAutosarVersion,
                                GALGAS_lstring & outArgument_iAutosarDescription,
                                C_Compiler * inCompiler
                                COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_iAutosarVersion.drop () ; // Release 'out' argument
  outArgument_iAutosarDescription.drop () ; // Release 'out' argument
  GALGAS_lstring var_autosarVersion_7864 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 273)) ;
  GALGAS_lstring var_autosarDescription_7913 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 274)) ;
  GALGAS_arxmlElementList var_autosarNodes_8032 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 277)) ;
  callExtensionMethod_getSubElementsFromName ((cPtr_arxmlNode *) inArgument_rootNode.ptr (), GALGAS_string ("AUTOSAR"), var_autosarNodes_8032, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 278)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, var_autosarNodes_8032.getter_length (SOURCE_FILE ("arxml_parser.galgas", 279)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 280)), GALGAS_string ("[TPS_GST_00077] : Missing root AUTOSAR node."), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 280)) ;
    }
  }
  GALGAS_arxmlElementList var_adminDataNodes_8251 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 283)) ;
  extensionMethod_getSubElementsFromName (var_autosarNodes_8032, GALGAS_string ("ADMIN-DATA"), var_adminDataNodes_8251, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 284)) ;
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsEqual, var_adminDataNodes_8251.getter_length (SOURCE_FILE ("arxml_parser.galgas", 285)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 286)), GALGAS_string ("[TPS_ECUC_06004] : Missing AUTOSAR's ADMIN-DATA node."), fixItArray3  COMMA_SOURCE_FILE ("arxml_parser.galgas", 286)) ;
    }
  }
  GALGAS_arxmlElementList var_revisions_8485 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 289)) ;
  extensionMethod_getElementsFromName (var_adminDataNodes_8251, GALGAS_string ("DOC-REVISION"), var_revisions_8485, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 290)) ;
  enumGalgasBool test_4 = kBoolTrue ;
  if (kBoolTrue == test_4) {
    test_4 = GALGAS_bool (kIsEqual, var_adminDataNodes_8251.getter_length (SOURCE_FILE ("arxml_parser.galgas", 291)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_4) {
      TC_Array <C_FixItDescription> fixItArray5 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 292)), GALGAS_string ("Missing AUTOSAR'S ADMIN-DATA's DOC-REVISION NODE"), fixItArray5  COMMA_SOURCE_FILE ("arxml_parser.galgas", 292)) ;
    }
  }
  GALGAS_bool var_version_5F_found_8702 = GALGAS_bool (false) ;
  GALGAS_bool var_issued_5F_by_5F_found_8734 = GALGAS_bool (false) ;
  GALGAS_lstring var_issued_5F_by_8763 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 297)) ;
  cEnumerator_arxmlElementList enumerator_8817 (var_revisions_8485, kENUMERATION_UP) ;
  bool bool_6 = var_version_5F_found_8702.operator_not (SOURCE_FILE ("arxml_parser.galgas", 300)).isValidAndTrue () ;
  if (enumerator_8817.hasCurrentObject () && bool_6) {
    while (enumerator_8817.hasCurrentObject () && bool_6) {
      var_issued_5F_by_5F_found_8734 = GALGAS_bool (false) ;
      callExtensionMethod_getProperty ((cPtr_arxmlElementNode *) enumerator_8817.current_node (HERE).ptr (), GALGAS_string ("ISSUED-BY"), var_issued_5F_by_8763, var_issued_5F_by_5F_found_8734, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 302)) ;
      enumGalgasBool test_7 = kBoolTrue ;
      if (kBoolTrue == test_7) {
        GALGAS_bool test_8 = var_issued_5F_by_5F_found_8734 ;
        if (kBoolTrue == test_8.boolEnum ()) {
          test_8 = GALGAS_bool (kIsEqual, var_issued_5F_by_8763.readProperty_string ().objectCompare (GALGAS_string ("AUTOSAR"))) ;
        }
        test_7 = test_8.boolEnum () ;
        if (kBoolTrue == test_7) {
          GALGAS_bool var_description_5F_found_9049 = GALGAS_bool (false) ;
          callExtensionMethod_getProperty ((cPtr_arxmlElementNode *) enumerator_8817.current_node (HERE).ptr (), GALGAS_string ("REVISION-LABEL"), var_autosarVersion_7864, var_version_5F_found_8702, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 305)) ;
          callExtensionMethod_getProperty ((cPtr_arxmlElementNode *) enumerator_8817.current_node (HERE).ptr (), GALGAS_string ("DATE"), var_autosarDescription_7913, var_description_5F_found_9049, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 306)) ;
        }
      }
      enumerator_8817.gotoNextObject () ;
      if (enumerator_8817.hasCurrentObject ()) {
        bool_6 = var_version_5F_found_8702.operator_not (SOURCE_FILE ("arxml_parser.galgas", 300)).isValidAndTrue () ;
      }
    }
  }
  outArgument_iAutosarVersion = var_autosarVersion_7864 ;
  outArgument_iAutosarDescription = var_autosarDescription_7913 ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'includeConfigs'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_includeConfigs (GALGAS_implementation & ioArgument_imp,
                             GALGAS_applicationDefinition & ioArgument_application,
                             GALGAS_string & ioArgument_fileIncludeList,
                             GALGAS_lstring inArgument_version,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_config_5F_file_5F_name_9588 = GALGAS_string (gOption_goil_5F_options_config.readProperty_value ()) ;
  GALGAS_stringlist var_configFiles_9657 = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name_9588.add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 325)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 324)) ;
  cEnumerator_stringlist enumerator_9909 (var_configFiles_9657, kENUMERATION_DOWN) ;
  while (enumerator_9909.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_9909.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 330)), ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, GALGAS_bool (false)  COMMA_SOURCE_FILE ("arxml_parser.galgas", 330)) ;
    enumerator_9909.gotoNextObject () ;
  }
  GALGAS_stringlist var_configVersionFiles_10234 = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name_9588.add_operation (inArgument_version.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 337)).add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 337)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 336)) ;
  cEnumerator_stringlist enumerator_10372 (var_configVersionFiles_10234, kENUMERATION_DOWN) ;
  while (enumerator_10372.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_10372.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 340)), ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, GALGAS_bool (false)  COMMA_SOURCE_FILE ("arxml_parser.galgas", 340)) ;
    enumerator_10372.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'nodeToClass'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_nodeToClass (GALGAS_arxmlNode inArgument_rootNode,
                          GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                          GALGAS_arxmlElementValue & outArgument_rootValue,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_rootValue.drop () ; // Release 'out' argument
  GALGAS_arxmlElementList var_autosarNodes_10749 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 351)) ;
  callExtensionMethod_getSubElementsFromName ((cPtr_arxmlNode *) inArgument_rootNode.ptr (), GALGAS_string ("AUTOSAR"), var_autosarNodes_10749, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 352)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, var_autosarNodes_10749.getter_length (SOURCE_FILE ("arxml_parser.galgas", 353)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 354)), GALGAS_string ("[TPS_GST_00077] : Missing root AUTOSAR node."), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 354)) ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsStrictSup, var_autosarNodes_10749.getter_length (SOURCE_FILE ("arxml_parser.galgas", 356)).objectCompare (GALGAS_uint (uint32_t (1U)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 357)), GALGAS_string ("[TPS_GST_00077] : Too many AUTOSAR nodes."), fixItArray3  COMMA_SOURCE_FILE ("arxml_parser.galgas", 357)) ;
    }
  }
  GALGAS_arxmlElementNode var_autosarNode_11108 ;
  var_autosarNodes_10749.method_first (var_autosarNode_11108, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 362)) ;
  {
  routine_nodeToClassRes (var_autosarNode_11108, ioArgument_classMap, outArgument_rootValue, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 363)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'nodeToClassRes'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_nodeToClassRes (GALGAS_arxmlElementNode inArgument_currentElement,
                             GALGAS_arxmlMetaClassMap inArgument_classMap,
                             GALGAS_arxmlElementValue & outArgument_elementValue,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_elementValue.drop () ; // Release 'out' argument
  GALGAS_arxmlMetaClass var_currentClass_11383 ;
  inArgument_classMap.method_searchKey (inArgument_currentElement.readProperty_name (), var_currentClass_11383, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 373)) ;
  GALGAS_bool var_textFound_11489 = GALGAS_bool (false) ;
  GALGAS_lstring var_text_11513 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 377))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 377)) ;
  callExtensionMethod_getText ((cPtr_arxmlElementNode *) inArgument_currentElement.ptr (), var_text_11513, var_textFound_11489, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 378)) ;
  GALGAS_lstring var_type_11631 = var_currentClass_11383.readProperty_name () ;
  outArgument_elementValue = GALGAS_arxmlElementValue::constructor_new (var_type_11631, var_text_11513, GALGAS_arxmlElementValueMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 385)), inArgument_currentElement.readProperty_attributes ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 382)) ;
  GALGAS_arxmlElementList var_subElements_12044 ;
  callExtensionMethod_getSubElements ((cPtr_arxmlElementNode *) inArgument_currentElement.ptr (), var_subElements_12044, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 390)) ;
  cEnumerator_arxmlElementList enumerator_12081 (var_subElements_12044, kENUMERATION_UP) ;
  while (enumerator_12081.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlMetaClass *) var_currentClass_11383.ptr (), enumerator_12081.current_node (HERE).readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 392)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 392)).boolEnum () ;
      if (kBoolTrue == test_0) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (enumerator_12081.current_node (HERE).readProperty_name ().readProperty_location (), GALGAS_string ("The element ").add_operation (enumerator_12081.current_node (HERE).readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 393)).add_operation (GALGAS_string (" does not belong to the "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 393)).add_operation (inArgument_currentElement.readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 394)).add_operation (GALGAS_string (" element.\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 395)).add_operation (GALGAS_string ("Possible elements are :\n"
          " "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 395)).add_operation (extensionGetter_string (var_currentClass_11383.readProperty_lElementLegacy (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 396)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 396)), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 393)) ;
      }
    }
    enumerator_12081.gotoNextObject () ;
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsNotEqual, inArgument_currentElement.readProperty_name ().readProperty_string ().objectCompare (GALGAS_string ("AUTOSAR"))).boolEnum () ;
    if (kBoolTrue == test_2) {
      cEnumerator_arxmlAttributeMap enumerator_12604 (inArgument_currentElement.readProperty_attributes (), kENUMERATION_UP) ;
      while (enumerator_12604.hasCurrentObject ()) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = callExtensionGetter_hasAttribute ((const cPtr_arxmlMetaClass *) var_currentClass_11383.ptr (), enumerator_12604.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 404)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 404)).boolEnum () ;
          if (kBoolTrue == test_3) {
            TC_Array <C_FixItDescription> fixItArray4 ;
            inCompiler->emitSemanticError (enumerator_12604.current_lkey (HERE).readProperty_location (), GALGAS_string ("The attribute ").add_operation (enumerator_12604.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)).add_operation (GALGAS_string (" does not belong to the "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)).add_operation (inArgument_currentElement.readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)).add_operation (GALGAS_string (" element.\n"
              "Possible "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 406)).add_operation (GALGAS_string ("attributes are :\n"
              " "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 406)).add_operation (extensionGetter_string (var_currentClass_11383.readProperty_lAttributeLegacy (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 407)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 407)), fixItArray4  COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)) ;
          }
        }
        enumerator_12604.gotoNextObject () ;
      }
    }
  }
  cEnumerator_arxmlMetaElementList enumerator_13051 (var_currentClass_11383.readProperty_lElementLegacy (), kENUMERATION_UP) ;
  while (enumerator_13051.hasCurrentObject ()) {
    GALGAS_arxmlElementList var_subElements_13122 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 414)) ;
    callExtensionMethod_getSubElementsFromName ((cPtr_arxmlElementNode *) inArgument_currentElement.ptr (), enumerator_13051.current_lElement (HERE).readProperty_name ().readProperty_string (), var_subElements_13122, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 416)) ;
    GALGAS_uint var_minOccurs_13339 = GALGAS_uint (uint32_t (1U)) ;
    GALGAS_uint var_maxOccurs_13363 = GALGAS_uint (uint32_t (1U)) ;
    enumGalgasBool test_5 = kBoolTrue ;
    if (kBoolTrue == test_5) {
      GALGAS_bool test_6 = GALGAS_bool (kIsNotEqual, enumerator_13051.current_lElement (HERE).readProperty_minOccurs ().readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())) ;
      if (kBoolTrue == test_6.boolEnum ()) {
        test_6 = enumerator_13051.current_lElement (HERE).readProperty_minOccurs ().readProperty_string ().getter_isDecimalUnsignedNumber (SOURCE_FILE ("arxml_parser.galgas", 424)) ;
      }
      test_5 = test_6.boolEnum () ;
      if (kBoolTrue == test_5) {
        var_minOccurs_13339 = enumerator_13051.current_lElement (HERE).readProperty_minOccurs ().readProperty_string ().getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 425)) ;
      }
    }
    enumGalgasBool test_7 = kBoolTrue ;
    if (kBoolTrue == test_7) {
      test_7 = GALGAS_bool (kIsStrictInf, var_subElements_13122.getter_length (SOURCE_FILE ("arxml_parser.galgas", 428)).objectCompare (var_minOccurs_13339)).boolEnum () ;
      if (kBoolTrue == test_7) {
        TC_Array <C_FixItDescription> fixItArray8 ;
        inCompiler->emitSemanticError (inArgument_currentElement.readProperty_name ().readProperty_location (), GALGAS_string ("Missing element ").add_operation (enumerator_13051.current_lElement (HERE).readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 429)).add_operation (GALGAS_string (". Minimum : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 429)).add_operation (var_minOccurs_13339.getter_string (SOURCE_FILE ("arxml_parser.galgas", 430)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 430)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 430)).add_operation (GALGAS_string (" Found "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 430)).add_operation (var_subElements_13122.getter_length (SOURCE_FILE ("arxml_parser.galgas", 431)).getter_string (SOURCE_FILE ("arxml_parser.galgas", 431)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 431)), fixItArray8  COMMA_SOURCE_FILE ("arxml_parser.galgas", 429)) ;
      }
    }
    enumGalgasBool test_9 = kBoolTrue ;
    if (kBoolTrue == test_9) {
      GALGAS_bool test_10 = GALGAS_bool (kIsNotEqual, enumerator_13051.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ().objectCompare (GALGAS_string ("unbounded"))) ;
      if (kBoolTrue == test_10.boolEnum ()) {
        test_10 = GALGAS_bool (kIsNotEqual, enumerator_13051.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())) ;
      }
      test_9 = test_10.boolEnum () ;
      if (kBoolTrue == test_9) {
        enumGalgasBool test_11 = kBoolTrue ;
        if (kBoolTrue == test_11) {
          GALGAS_bool test_12 = GALGAS_bool (kIsNotEqual, enumerator_13051.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())) ;
          if (kBoolTrue == test_12.boolEnum ()) {
            test_12 = enumerator_13051.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ().getter_isDecimalUnsignedNumber (SOURCE_FILE ("arxml_parser.galgas", 439)) ;
          }
          test_11 = test_12.boolEnum () ;
          if (kBoolTrue == test_11) {
            var_maxOccurs_13363 = enumerator_13051.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ().getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 440)) ;
          }
        }
        enumGalgasBool test_13 = kBoolTrue ;
        if (kBoolTrue == test_13) {
          test_13 = GALGAS_bool (kIsStrictSup, var_subElements_13122.getter_length (SOURCE_FILE ("arxml_parser.galgas", 443)).objectCompare (var_maxOccurs_13363)).boolEnum () ;
          if (kBoolTrue == test_13) {
            TC_Array <C_FixItDescription> fixItArray14 ;
            inCompiler->emitSemanticError (inArgument_currentElement.readProperty_name ().readProperty_location (), GALGAS_string ("Too many node ").add_operation (enumerator_13051.current_lElement (HERE).readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 444)).add_operation (GALGAS_string (". Minimum : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 444)).add_operation (var_minOccurs_13339.getter_string (SOURCE_FILE ("arxml_parser.galgas", 445)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 445)).add_operation (GALGAS_string (" ; Maximum : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 445)).add_operation (var_maxOccurs_13363.getter_string (SOURCE_FILE ("arxml_parser.galgas", 445)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 445)).add_operation (GALGAS_string (". Found "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 445)).add_operation (var_subElements_13122.getter_length (SOURCE_FILE ("arxml_parser.galgas", 446)).getter_string (SOURCE_FILE ("arxml_parser.galgas", 446)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 446)), fixItArray14  COMMA_SOURCE_FILE ("arxml_parser.galgas", 444)) ;
          }
        }
      }
    }
    cEnumerator_arxmlElementList enumerator_14641 (var_subElements_13122, kENUMERATION_UP) ;
    while (enumerator_14641.hasCurrentObject ()) {
      GALGAS_arxmlElementValue var_subElementValue_14705 ;
      {
      routine_nodeToClassRes (enumerator_14641.current_node (HERE), inArgument_classMap, var_subElementValue_14705, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 453)) ;
      }
      {
      outArgument_elementValue.insulate (HERE) ;
      cPtr_arxmlElementValue * ptr_14788 = (cPtr_arxmlElementValue *) outArgument_elementValue.ptr () ;
      callExtensionSetter_insertElement ((cPtr_arxmlElementValue *) ptr_14788, enumerator_14641.current_node (HERE).readProperty_name (), var_subElementValue_14705, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 454)) ;
      }
      enumerator_14641.gotoNextObject () ;
    }
    enumerator_13051.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'addText'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_addText (GALGAS_arxmlNodeList & ioArgument_nodes,
                      const GALGAS_bool constinArgument_doNotCondenseWhiteSpaces,
                      C_Compiler * inCompiler
                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_s_14956 = GALGAS_string::constructor_retrieveAndResetTemplateString (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 463)) ;
  GALGAS_string var_trimmedString_15018 = var_s_14956.getter_stringByTrimmingWhiteSpaces (SOURCE_FILE ("arxml_parser.galgas", 464)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_trimmedString_15018.getter_length (SOURCE_FILE ("arxml_parser.galgas", 465)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_ls_15109 ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = constinArgument_doNotCondenseWhiteSpaces.boolEnum () ;
        if (kBoolTrue == test_1) {
          var_ls_15109 = GALGAS_lstring::constructor_new (var_s_14956, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 468))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 468)) ;
        }
      }
      if (kBoolFalse == test_1) {
        var_ls_15109 = GALGAS_lstring::constructor_new (var_trimmedString_15018, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 470))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 470)) ;
      }
      ioArgument_nodes.addAssign_operation (GALGAS_arxmlTextNode::constructor_new (var_ls_15109  COMMA_SOURCE_FILE ("arxml_parser.galgas", 473))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 473)) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'convertToOil'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_convertToOil (GALGAS_implementation & ioArgument_imp,
                           GALGAS_applicationDefinition & ioArgument_application,
                           GALGAS_arxmlElementValue inArgument_rootValue,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_emptyPath_15426 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 482))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 482)) ;
  GALGAS_arxmlElementValueList var_packages_15512 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 485)) ;
  GALGAS_stringlist var_packagesPath_15544 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 486)) ;
  var_packagesPath_15544.addAssign_operation (GALGAS_string ("AR-PACKAGES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 487)) ;
  var_packagesPath_15544.addAssign_operation (GALGAS_string ("AR-PACKAGE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 488)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_rootValue.ptr (), var_packagesPath_15544, var_packages_15512, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 489)) ;
  cEnumerator_arxmlElementValueList enumerator_15728 (var_packages_15512, kENUMERATION_UP) ;
  while (enumerator_15728.hasCurrentObject ()) {
    {
    routine_arxmlImplementationPackage (ioArgument_imp, enumerator_15728.current_value (HERE), var_emptyPath_15426, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 493)) ;
    }
    enumerator_15728.gotoNextObject () ;
  }
  cEnumerator_arxmlElementValueList enumerator_15862 (var_packages_15512, kENUMERATION_UP) ;
  while (enumerator_15862.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionPackage (ioArgument_imp, ioArgument_application, enumerator_15862.current_value (HERE), var_emptyPath_15426, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 498)) ;
    }
    enumerator_15862.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationPackage'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationPackage (GALGAS_implementation & ioArgument_imp,
                                         GALGAS_arxmlElementValue inArgument_packageElement,
                                         GALGAS_lstring inArgument_parentPath,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_packageName_16239 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 512)) ;
  GALGAS_lstring var_currentPath_16352 = GALGAS_lstring::constructor_new (inArgument_parentPath.readProperty_string ().add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 515)).add_operation (var_packageName_16239.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 515)), var_packageName_16239.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 515)) ;
  GALGAS_arxmlElementValueList var_definitions_16582 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 519)) ;
  GALGAS_stringlist var_definitionPath_16616 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 520)) ;
  var_definitionPath_16616.addAssign_operation (GALGAS_string ("ELEMENTS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 521)) ;
  var_definitionPath_16616.addAssign_operation (GALGAS_string ("ECUC-MODULE-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 522)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_definitionPath_16616, var_definitions_16582, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 523)) ;
  cEnumerator_arxmlElementValueList enumerator_16795 (var_definitions_16582, kENUMERATION_UP) ;
  while (enumerator_16795.hasCurrentObject ()) {
    {
    routine_arxmlImplementationRoot (ioArgument_imp, enumerator_16795.current_value (HERE), var_currentPath_16352, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 525)) ;
    }
    enumerator_16795.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_packages_16969 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 529)) ;
  GALGAS_stringlist var_packagesPath_17001 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 530)) ;
  var_packagesPath_17001.addAssign_operation (GALGAS_string ("AR-PACKAGES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 531)) ;
  var_packagesPath_17001.addAssign_operation (GALGAS_string ("AR-PACKAGE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 532)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_packagesPath_17001, var_packages_16969, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 533)) ;
  cEnumerator_arxmlElementValueList enumerator_17166 (var_packages_16969, kENUMERATION_UP) ;
  while (enumerator_17166.hasCurrentObject ()) {
    {
    routine_arxmlImplementationPackage (ioArgument_imp, enumerator_17166.current_value (HERE), var_currentPath_16352, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 535)) ;
    }
    enumerator_17166.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationRoot'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationRoot (GALGAS_implementation & ioArgument_implementation,
                                      GALGAS_arxmlElementValue inArgument_packageElement,
                                      GALGAS_lstring inArgument_parentPath,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_objectName_17431 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 545)) ;
  {
  routine_displayOil (GALGAS_string ("\n"
    "IMPLEMENTATION ").add_operation (var_objectName_17431.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 546)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 546)) ;
  }
  GALGAS_lstring var_currentPath_17591 = GALGAS_lstring::constructor_new (inArgument_parentPath.readProperty_string ().add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 549)).add_operation (var_objectName_17431.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 549)), inArgument_parentPath.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 549)) ;
  GALGAS_lstring var_oil_5F_desc_17794 ;
  {
  routine_arxmlGetDescription (inArgument_packageElement, var_oil_5F_desc_17794, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 553)) ;
  }
  GALGAS_arxmlElementValueList var_subDefs_17856 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 556)) ;
  GALGAS_stringlist var_subDefsPath_17887 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 557)) ;
  var_subDefsPath_17887.addAssign_operation (GALGAS_string ("CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 558)) ;
  var_subDefsPath_17887.addAssign_operation (GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 559)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_subDefsPath_17887, var_subDefs_17856, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 560)) ;
  {
  routine_displayOil (GALGAS_string ("\n"
    "{\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 562)) ;
  }
  cEnumerator_arxmlElementValueList enumerator_18133 (var_subDefs_17856, kENUMERATION_UP) ;
  while (enumerator_18133.hasCurrentObject ()) {
    {
    routine_arxmlImplementationObject (ioArgument_implementation, enumerator_18133.current_value (HERE), var_currentPath_17591, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 566)) ;
    }
    enumerator_18133.gotoNextObject () ;
  }
  {
  routine_displayOil (GALGAS_string ("}; /* END IMPLEMENTATION ").add_operation (var_objectName_17431.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 569)).add_operation (GALGAS_string (" : \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 569)).add_operation (var_oil_5F_desc_17794.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 570)).add_operation (GALGAS_string ("\" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 570)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 569)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationObject'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationObject (GALGAS_implementation & ioArgument_implementation,
                                        GALGAS_arxmlElementValue inArgument_packageElement,
                                        GALGAS_lstring inArgument_parentPath,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationMap var_imp_18499 = ioArgument_implementation.readProperty_imp () ;
  GALGAS_implementationObjectMap var_objectAttributes_18566 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 579)) ;
  GALGAS_lstring var_objectName_18722 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 583)) ;
  GALGAS_lstring var_currentPath_18834 = GALGAS_lstring::constructor_new (inArgument_parentPath.readProperty_string ().add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 586)).add_operation (var_objectName_18722.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 586)), inArgument_parentPath.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 586)) ;
  GALGAS_lstring var_objectKind_19082 = var_objectName_18722 ;
  var_objectKind_19082.setter_setString (var_objectName_18722.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 591)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 591)) ;
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (var_objectKind_19082.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 593)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 593)) ;
  }
  GALGAS_lbool var_multiple_19304 ;
  {
  routine_arxmlGetMultiplicity (inArgument_packageElement, var_objectName_18722, var_multiple_19304, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 596)) ;
  }
  {
  routine_displayOil (GALGAS_string ("\n"
    "  {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 597)) ;
  }
  GALGAS_lstring var_oil_5F_desc_19423 ;
  {
  routine_arxmlGetDescription (inArgument_packageElement, var_oil_5F_desc_19423, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 600)) ;
  }
  {
  routine_arxmlImplementationContainer (var_objectAttributes_18566, inArgument_packageElement, var_currentPath_18834, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 603)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  }; /* \"").add_operation (var_oil_5F_desc_19423.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 607)).add_operation (GALGAS_string ("\"*/\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 607)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 607)) ;
  }
  GALGAS_implementationObject var_newObject_19729 = GALGAS_implementationObject::constructor_new (var_multiple_19304, var_objectAttributes_18566  COMMA_SOURCE_FILE ("arxml_parser.galgas", 611)) ;
  GALGAS_implementationObject var_object_19899 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasKey ((const cPtr_implementation *) ioArgument_implementation.ptr (), var_objectName_18722.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 616)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      var_imp_18499.setter_del (var_objectName_18722, var_object_19899, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 617)) ;
      }
      var_object_19899 = callExtensionGetter_mergeImplementationObjectWith ((const cPtr_implementationObject *) var_object_19899.ptr (), var_newObject_19729, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 618)) ;
    }
  }
  if (kBoolFalse == test_0) {
    var_object_19899 = var_newObject_19729 ;
  }
  {
  var_imp_18499.setter_put (var_objectName_18722, var_object_19899, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 624)) ;
  }
  {
  ioArgument_implementation.setter_setImp (var_imp_18499 COMMA_SOURCE_FILE ("arxml_parser.galgas", 625)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainer'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainer (GALGAS_implementationObjectMap & ioArgument_objectAttributes,
                                           GALGAS_arxmlElementValue inArgument_currentElement,
                                           GALGAS_lstring inArgument_parentPath,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList var_intParameters_20558 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 636)) ;
  GALGAS_stringlist var_intParametersPath_20595 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 637)) ;
  var_intParametersPath_20595.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 638)) ;
  var_intParametersPath_20595.addAssign_operation (GALGAS_string ("ECUC-INTEGER-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 639)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_intParametersPath_20595, var_intParameters_20558, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 640)) ;
  cEnumerator_arxmlElementValueList enumerator_20794 (var_intParameters_20558, kENUMERATION_UP) ;
  while (enumerator_20794.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_20846 ;
    GALGAS_impType var_type_20868 ;
    {
    routine_arxmlImplementationContainerNumber (var_attributeName_20846, var_type_20868, GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 647)), enumerator_20794.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 645)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_20846, var_type_20868, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 650)) ;
    }
    enumerator_20794.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_floatParameters_21432 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 656)) ;
  GALGAS_stringlist var_floatParametersPath_21471 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 657)) ;
  var_floatParametersPath_21471.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 658)) ;
  var_floatParametersPath_21471.addAssign_operation (GALGAS_string ("ECUC-FLOAT-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 659)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_floatParametersPath_21471, var_floatParameters_21432, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 660)) ;
  cEnumerator_arxmlElementValueList enumerator_21676 (var_floatParameters_21432, kENUMERATION_UP) ;
  while (enumerator_21676.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_21730 ;
    GALGAS_impType var_type_21752 ;
    {
    routine_arxmlImplementationContainerNumber (var_attributeName_21730, var_type_21752, GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("arxml_parser.galgas", 667)), enumerator_21676.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 665)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_21730, var_type_21752, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 670)) ;
    }
    enumerator_21676.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_stringParameters_22304 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 676)) ;
  GALGAS_stringlist var_stringParametersPath_22344 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 677)) ;
  var_stringParametersPath_22344.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 678)) ;
  var_stringParametersPath_22344.addAssign_operation (GALGAS_string ("ECUC-STRING-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 679)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_stringParametersPath_22344, var_stringParameters_22304, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 680)) ;
  cEnumerator_arxmlElementValueList enumerator_22554 (var_stringParameters_22304, kENUMERATION_UP) ;
  while (enumerator_22554.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_22609 ;
    GALGAS_impType var_type_22631 ;
    {
    routine_arxmlImplementationContainerString (var_attributeName_22609, var_type_22631, GALGAS_dataType::constructor_string (SOURCE_FILE ("arxml_parser.galgas", 687)), enumerator_22554.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 685)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_22609, var_type_22631, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 690)) ;
    }
    enumerator_22554.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_booleanParameters_23180 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 696)) ;
  GALGAS_stringlist var_booleanParametersPath_23221 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 697)) ;
  var_booleanParametersPath_23221.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 698)) ;
  var_booleanParametersPath_23221.addAssign_operation (GALGAS_string ("ECUC-BOOLEAN-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 699)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_booleanParametersPath_23221, var_booleanParameters_23180, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 700)) ;
  cEnumerator_arxmlElementValueList enumerator_23436 (var_booleanParameters_23180, kENUMERATION_UP) ;
  while (enumerator_23436.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_23492 ;
    GALGAS_impType var_type_23514 ;
    {
    routine_arxmlImplementationContainerBoolean (var_attributeName_23492, var_type_23514, GALGAS_dataType::constructor_boolean (SOURCE_FILE ("arxml_parser.galgas", 707)), enumerator_23436.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 705)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_23492, var_type_23514, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 710)) ;
    }
    enumerator_23436.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_enumParameters_24063 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 716)) ;
  GALGAS_stringlist var_enumParametersPath_24101 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 717)) ;
  var_enumParametersPath_24101.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 718)) ;
  var_enumParametersPath_24101.addAssign_operation (GALGAS_string ("ECUC-ENUMERATION-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 719)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_enumParametersPath_24101, var_enumParameters_24063, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 720)) ;
  cEnumerator_arxmlElementValueList enumerator_24308 (var_enumParameters_24063, kENUMERATION_UP) ;
  while (enumerator_24308.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_24361 ;
    GALGAS_impType var_type_24383 ;
    {
    routine_arxmlImplementationContainerEnumeration (var_attributeName_24361, var_type_24383, GALGAS_dataType::constructor_enumeration (SOURCE_FILE ("arxml_parser.galgas", 727)), enumerator_24308.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 725)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_24361, var_type_24383, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 730)) ;
    }
    enumerator_24308.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_structParameters_24960 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 736)) ;
  GALGAS_stringlist var_structParametersPath_25000 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 737)) ;
  var_structParametersPath_25000.addAssign_operation (GALGAS_string ("SUB-CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 738)) ;
  var_structParametersPath_25000.addAssign_operation (GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 739)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_structParametersPath_25000, var_structParameters_24960, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 740)) ;
  cEnumerator_arxmlElementValueList enumerator_25222 (var_structParameters_24960, kENUMERATION_UP) ;
  while (enumerator_25222.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_25277 ;
    GALGAS_impType var_type_25299 ;
    {
    routine_arxmlImplementationContainerStructure (var_attributeName_25277, var_type_25299, GALGAS_dataType::constructor_structType (SOURCE_FILE ("arxml_parser.galgas", 747)), enumerator_25222.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 745)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_25277, var_type_25299, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 750)) ;
    }
    enumerator_25222.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_identParameters_25868 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 756)) ;
  GALGAS_stringlist var_identParametersPath_25907 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 757)) ;
  var_identParametersPath_25907.addAssign_operation (GALGAS_string ("REFERENCES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 758)) ;
  var_identParametersPath_25907.addAssign_operation (GALGAS_string ("TPL-IDENTIFIER-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 759)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_identParametersPath_25907, var_identParameters_25868, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 760)) ;
  cEnumerator_arxmlElementValueList enumerator_26110 (var_identParameters_25868, kENUMERATION_UP) ;
  while (enumerator_26110.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_26164 ;
    GALGAS_impType var_type_26186 ;
    {
    routine_arxmlImplementationContainerIdentifier (var_attributeName_26164, var_type_26186, GALGAS_dataType::constructor_identifier (SOURCE_FILE ("arxml_parser.galgas", 767)), enumerator_26110.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 765)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_26164, var_type_26186, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 770)) ;
    }
    enumerator_26110.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_refParameters_26757 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 776)) ;
  GALGAS_stringlist var_refParametersPath_26794 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 777)) ;
  var_refParametersPath_26794.addAssign_operation (GALGAS_string ("REFERENCES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 778)) ;
  var_refParametersPath_26794.addAssign_operation (GALGAS_string ("ECUC-REFERENCE-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 779)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_refParametersPath_26794, var_refParameters_26757, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 780)) ;
  cEnumerator_arxmlElementValueList enumerator_26989 (var_refParameters_26757, kENUMERATION_UP) ;
  while (enumerator_26989.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_27041 ;
    GALGAS_impType var_type_27063 ;
    {
    routine_arxmlImplementationContainerReference (var_attributeName_27041, var_type_27063, GALGAS_dataType::constructor_objectType (SOURCE_FILE ("arxml_parser.galgas", 787)), enumerator_26989.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 785)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_27041, var_type_27063, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 790)) ;
    }
    enumerator_26989.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerNumber'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerNumber (GALGAS_lstring & outArgument_objectName,
                                                 GALGAS_impType & outArgument_options,
                                                 const GALGAS_dataType constinArgument_iType,
                                                 GALGAS_arxmlElementValue inArgument_parameter,
                                                 GALGAS_lstring /* inArgument_parentPath */,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_dataType var_type_27688 = constinArgument_iType ;
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 806)) ;
  }
  GALGAS_lbool var_multiple_27846 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_27846, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 809)) ;
  }
  GALGAS_bool var_withAuto_27912 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_27912, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 812)) ;
  }
  GALGAS_lstring var_oil_5F_desc_28001 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_28001, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 815)) ;
  }
  GALGAS_attributeRange var_range_28155 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    GALGAS_bool test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MIN"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 821)) ;
    if (kBoolTrue == test_1.boolEnum ()) {
      test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MAX"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 821)) ;
    }
    test_0 = test_1.boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_min_28245 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MIN"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 822)) ;
      GALGAS_lstring var_max_28302 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MAX"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 823)) ;
      GALGAS_string var_minSignString_28368 = GALGAS_string::makeEmptyString () ;
      GALGAS_string var_maxSignString_28399 = GALGAS_string::makeEmptyString () ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, var_max_28302.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 827)).objectCompare (GALGAS_string ("INF"))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_max_28302.setter_setString (GALGAS_sint_36__34_::constructor_max (SOURCE_FILE ("arxml_parser.galgas", 828)).getter_string (SOURCE_FILE ("arxml_parser.galgas", 828)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 828)) ;
        }
      }
      GALGAS_bool var_minSign_28548 ;
      {
      routine_arxmlPopSign (var_min_28245, var_minSign_28548, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 831)) ;
      }
      GALGAS_bool var_maxSign_28591 ;
      {
      routine_arxmlPopSign (var_max_28302, var_maxSign_28591, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 832)) ;
      }
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = var_minSign_28548.boolEnum () ;
        if (kBoolTrue == test_3) {
          var_minSignString_28368 = GALGAS_string ("-") ;
          var_type_27688 = GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 837)) ;
        }
      }
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = var_maxSign_28591.boolEnum () ;
        if (kBoolTrue == test_4) {
          var_maxSignString_28399 = GALGAS_string ("-") ;
          var_type_27688 = GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 841)) ;
        }
      }
      {
      routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (var_type_27688, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 843)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 843)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 843)) ;
      }
      {
      routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 844)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 844)) ;
      }
      GALGAS_object_5F_t var_start_28938 ;
      GALGAS_object_5F_t var_stop_28961 ;
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        GALGAS_bool test_6 = GALGAS_bool (kIsEqual, var_type_27688.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 849)))) ;
        if (kBoolTrue != test_6.boolEnum ()) {
          test_6 = GALGAS_bool (kIsEqual, var_type_27688.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 849)))) ;
        }
        test_5 = test_6.boolEnum () ;
        if (kBoolTrue == test_5) {
          GALGAS_luint_36__34_ var_minVal_29065 = GALGAS_luint_36__34_::constructor_new (var_min_28245.readProperty_string ().getter_decimalUnsigned_36__34_Number (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 851)), var_min_28245.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 850)) ;
          GALGAS_luint_36__34_ var_maxVal_29247 = GALGAS_luint_36__34_::constructor_new (var_max_28302.readProperty_string ().getter_decimalUnsigned_36__34_Number (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 855)), var_max_28302.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 854)) ;
          {
          routine_displayOil (GALGAS_string ("[").add_operation (var_minSignString_28368, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 858)).add_operation (var_minVal_29065.readProperty_uint_36__34_ ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 858)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 858)).add_operation (GALGAS_string (" .. "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 858)).add_operation (var_maxSignString_28399, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 859)).add_operation (var_maxVal_29247.readProperty_uint_36__34_ ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 859)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 859)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 859)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 858)) ;
          }
          var_start_28938 = function_checkAndGetIntegerNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 860)), var_type_27688, var_minVal_29065, var_minSign_28548, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 860)) ;
          var_stop_28961 = function_checkAndGetIntegerNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 861)), var_type_27688, var_maxVal_29247, var_maxSign_28591, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 861)) ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_7 = kBoolTrue ;
        if (kBoolTrue == test_7) {
          test_7 = GALGAS_bool (kIsEqual, var_type_27688.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("arxml_parser.galgas", 862)))).boolEnum () ;
          if (kBoolTrue == test_7) {
            GALGAS_ldouble var_minVal_29753 = GALGAS_ldouble::constructor_new (var_min_28245.readProperty_string ().getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 864)), var_min_28245.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 863)) ;
            GALGAS_ldouble var_maxVal_29924 = GALGAS_ldouble::constructor_new (var_max_28302.readProperty_string ().getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 868)), var_max_28302.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 867)) ;
            {
            routine_displayOil (GALGAS_string ("[").add_operation (var_minVal_29753.readProperty_double ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 871)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 871)).add_operation (GALGAS_string (" .. "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 871)).add_operation (var_maxVal_29924.readProperty_double ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 871)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 871)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 871)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 871)) ;
            }
            var_start_28938 = function_checkAndGetFloatNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 872)), var_type_27688, var_minVal_29753, var_minSign_28548, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 872)) ;
            var_stop_28961 = function_checkAndGetFloatNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 873)), var_type_27688, var_maxVal_29924, var_maxSign_28591, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 873)) ;
          }
        }
        if (kBoolFalse == test_7) {
          TC_Array <C_FixItDescription> fixItArray8 ;
          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 875)), GALGAS_string ("Internal error"), fixItArray8  COMMA_SOURCE_FILE ("arxml_parser.galgas", 875)) ;
          var_start_28938.drop () ; // Release error dropped variable
          var_stop_28961.drop () ; // Release error dropped variable
        }
      }
      var_range_28155 = function_buildRange (var_type_27688, var_start_28938, var_stop_28961, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 877)) ;
    }
  }
  if (kBoolFalse == test_0) {
    {
    routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (var_type_27688, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 879)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 879)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 879)) ;
    }
    {
    routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 880)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 880)) ;
    }
    var_range_28155 = GALGAS_noRange::constructor_new (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 881)) ;
  }
  GALGAS_object_5F_t var_defaultValue_30601 ;
  enumGalgasBool test_9 = kBoolTrue ;
  if (kBoolTrue == test_9) {
    test_9 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 886)).boolEnum () ;
    if (kBoolTrue == test_9) {
      GALGAS_lstring var_value_30670 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 887)) ;
      GALGAS_bool var_sign_30791 ;
      {
      routine_arxmlPopSign (var_value_30670, var_sign_30791, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 890)) ;
      }
      enumGalgasBool test_10 = kBoolTrue ;
      if (kBoolTrue == test_10) {
        GALGAS_bool test_11 = GALGAS_bool (kIsEqual, var_type_27688.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 893)))) ;
        if (kBoolTrue != test_11.boolEnum ()) {
          test_11 = GALGAS_bool (kIsEqual, var_type_27688.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 893)))) ;
        }
        test_10 = test_11.boolEnum () ;
        if (kBoolTrue == test_10) {
          GALGAS_luint_36__34_ var_integerValue_30973 = GALGAS_luint_36__34_::constructor_new (var_value_30670.readProperty_string ().getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 895)).getter_uint_36__34_ (SOURCE_FILE ("arxml_parser.galgas", 895)), var_value_30670.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 894)) ;
          {
          routine_displayOil (GALGAS_string (" = ").add_operation (var_integerValue_30973.readProperty_uint_36__34_ ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 897)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 897)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 897)) ;
          }
          var_defaultValue_30601 = function_checkAndGetIntegerNumber (var_oil_5F_desc_28001, var_type_27688, var_integerValue_30973, var_sign_30791, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 898)) ;
        }
      }
      if (kBoolFalse == test_10) {
        enumGalgasBool test_12 = kBoolTrue ;
        if (kBoolTrue == test_12) {
          test_12 = GALGAS_bool (kIsEqual, var_type_27688.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("arxml_parser.galgas", 902)))).boolEnum () ;
          if (kBoolTrue == test_12) {
            GALGAS_ldouble var_floatValue_31452 = GALGAS_ldouble::constructor_new (var_value_30670.readProperty_string ().getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 904)), var_value_30670.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 903)) ;
            {
            routine_displayOil (GALGAS_string (" = ").add_operation (var_floatValue_31452.readProperty_double ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 906)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 906)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 906)) ;
            }
            var_defaultValue_30601 = function_checkAndGetFloatNumber (var_oil_5F_desc_28001, var_type_27688, var_floatValue_31452, var_sign_30791, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 907)) ;
          }
        }
        if (kBoolFalse == test_12) {
          TC_Array <C_FixItDescription> fixItArray13 ;
          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 912)), GALGAS_string ("Internal error"), fixItArray13  COMMA_SOURCE_FILE ("arxml_parser.galgas", 912)) ;
          var_defaultValue_30601.drop () ; // Release error dropped variable
        }
      }
    }
  }
  if (kBoolFalse == test_9) {
    enumGalgasBool test_14 = kBoolTrue ;
    if (kBoolTrue == test_14) {
      test_14 = var_withAuto_27912.boolEnum () ;
      if (kBoolTrue == test_14) {
        var_defaultValue_30601 = GALGAS_auto::constructor_new (var_oil_5F_desc_28001, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 915)) ;
      }
    }
    if (kBoolFalse == test_14) {
      var_defaultValue_30601 = GALGAS_void::constructor_new (var_oil_5F_desc_28001, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 917)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_28001.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 919)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 919)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 919)) ;
  }
  GALGAS_locationList temp_15 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 922)) ;
  temp_15.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 922)) ;
  GALGAS_lstringlist temp_16 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 926)) ;
  temp_16.addAssign_operation (var_oil_5F_desc_28001  COMMA_SOURCE_FILE ("arxml_parser.galgas", 926)) ;
  outArgument_options = GALGAS_impRangedType::constructor_new (temp_15, var_type_27688, outArgument_objectName, var_multiple_27846.readProperty_bool (), temp_16, var_withAuto_27912, var_defaultValue_30601, var_range_28155  COMMA_SOURCE_FILE ("arxml_parser.galgas", 922)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerString'
//
//----------------------------------------------------------------------------------------------------------------------

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
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 939)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 939)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 939)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 942)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 943)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 943)) ;
  }
  GALGAS_lbool var_multiple_32881 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_32881, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 946)) ;
  }
  GALGAS_bool var_withAuto_32947 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_32947, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 949)) ;
  }
  GALGAS_lstring var_oil_5F_desc_33036 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_33036, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 952)) ;
  }
  GALGAS_object_5F_t var_defaultValue_33086 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 957)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_value_33159 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 958)) ;
      {
      routine_displayOil (GALGAS_string (" = \"").add_operation (var_value_33159.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 959)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 959)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 959)) ;
      }
      var_defaultValue_33086 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_33036, var_value_33159.readProperty_location (), var_value_33159.readProperty_string ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 960)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_withAuto_32947.boolEnum () ;
      if (kBoolTrue == test_1) {
        var_defaultValue_33086 = GALGAS_auto::constructor_new (var_oil_5F_desc_33036, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 966)) ;
      }
    }
    if (kBoolFalse == test_1) {
      var_defaultValue_33086 = GALGAS_void::constructor_new (var_oil_5F_desc_33036, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 968)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_33036.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 970)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 970)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 970)) ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 974)) ;
  temp_2.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 974)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 978)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_33036  COMMA_SOURCE_FILE ("arxml_parser.galgas", 978)) ;
  outArgument_options = GALGAS_impAutoDefaultType::constructor_new (temp_2, constinArgument_type, outArgument_objectName, var_multiple_32881.readProperty_bool (), temp_3, var_withAuto_32947, var_defaultValue_33086  COMMA_SOURCE_FILE ("arxml_parser.galgas", 973)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerBoolean'
//
//----------------------------------------------------------------------------------------------------------------------

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
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 991)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 991)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 991)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 994)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 995)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 995)) ;
  }
  GALGAS_bool var_withAuto_34517 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_34517, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 998)) ;
  }
  GALGAS_lbool var_multiple_34611 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_34611, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1001)) ;
  }
  GALGAS_lstring var_oil_5F_desc_34700 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_34700, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1004)) ;
  }
  GALGAS_object_5F_t var_defaultValue_34749 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1008)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_value_34822 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1009)) ;
      GALGAS_bool var_booleanValue_34899 ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        GALGAS_bool test_2 = GALGAS_bool (kIsEqual, var_value_34822.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1011)).objectCompare (GALGAS_string ("TRUE"))) ;
        if (kBoolTrue != test_2.boolEnum ()) {
          test_2 = GALGAS_bool (kIsEqual, var_value_34822.readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
        }
        test_1 = test_2.boolEnum () ;
        if (kBoolTrue == test_1) {
          var_booleanValue_34899 = GALGAS_bool (true) ;
        }
      }
      if (kBoolFalse == test_1) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          GALGAS_bool test_4 = GALGAS_bool (kIsEqual, var_value_34822.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1014)).objectCompare (GALGAS_string ("FALSE"))) ;
          if (kBoolTrue != test_4.boolEnum ()) {
            test_4 = GALGAS_bool (kIsEqual, var_value_34822.readProperty_string ().objectCompare (GALGAS_string ("0"))) ;
          }
          test_3 = test_4.boolEnum () ;
          if (kBoolTrue == test_3) {
            var_booleanValue_34899 = GALGAS_bool (false) ;
          }
        }
        if (kBoolFalse == test_3) {
          var_booleanValue_34899 = GALGAS_bool (false) ;
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (var_value_34822.readProperty_location (), GALGAS_string ("A Boolean must be 'true', 'false', '0' or '1'"), fixItArray5  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1019)) ;
        }
      }
      {
      routine_displayOil (GALGAS_string (" = ").add_operation (var_booleanValue_34899.getter_cString (SOURCE_FILE ("arxml_parser.galgas", 1021)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1021)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1021)) ;
      }
      var_defaultValue_34749 = GALGAS_boolAttribute::constructor_new (var_oil_5F_desc_34700, var_value_34822.readProperty_location (), var_booleanValue_34899, GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1028))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1026))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1022)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_6 = kBoolTrue ;
    if (kBoolTrue == test_6) {
      test_6 = var_withAuto_34517.boolEnum () ;
      if (kBoolTrue == test_6) {
        var_defaultValue_34749 = GALGAS_auto::constructor_new (var_oil_5F_desc_34700, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1032)) ;
      }
    }
    if (kBoolFalse == test_6) {
      var_defaultValue_34749 = GALGAS_void::constructor_new (var_oil_5F_desc_34700, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1034)) ;
    }
  }
  GALGAS_implementationObjectMap var_structAttributes_36019 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1040)) ;
  enumGalgasBool test_7 = kBoolTrue ;
  if (kBoolTrue == test_7) {
    test_7 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SUB-CONTAINERS"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1041)).boolEnum () ;
    if (kBoolTrue == test_7) {
      {
      routine_displayOil (GALGAS_string ("\n"
        "    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1042)) ;
      }
      {
      routine_arxmlImplementationContainer (var_structAttributes_36019, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1043)) ;
      }
      {
      routine_displayOil (GALGAS_string ("\n"
        "    } : \"").add_operation (var_oil_5F_desc_34700.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1044)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1044)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1044)) ;
      }
    }
  }
  if (kBoolFalse == test_7) {
    {
    routine_displayOil (GALGAS_string (" : \"").add_operation (var_oil_5F_desc_34700.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1046)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1046)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1046)) ;
    }
  }
  GALGAS_locationList temp_8 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1051)) ;
  temp_8.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1051)) ;
  GALGAS_lstringlist temp_9 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1055)) ;
  temp_9.addAssign_operation (var_oil_5F_desc_34700  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1055)) ;
  outArgument_options = GALGAS_impBoolType::constructor_new (temp_8, constinArgument_type, outArgument_objectName, var_multiple_34611.readProperty_bool (), temp_9, var_withAuto_34517, var_defaultValue_34749, var_structAttributes_36019, var_structAttributes_36019  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1050)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerEnumeration'
//
//----------------------------------------------------------------------------------------------------------------------

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
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1070)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1070)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1070)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1073)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1074)).add_operation (GALGAS_string ("["), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1074)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1074)) ;
  }
  GALGAS_bool var_withAuto_37180 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_37180, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1077)) ;
  }
  GALGAS_lbool var_multiple_37274 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_37274, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1080)) ;
  }
  GALGAS_lstring var_oil_5F_desc_37363 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_37363, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1083)) ;
  }
  GALGAS_enumValues var_enumValues_37455 = GALGAS_enumValues::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1087)) ;
  GALGAS_arxmlElementValueList var_enumElementValues_37523 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1088)) ;
  GALGAS_stringlist var_enumElementValuesPath_37564 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1089)) ;
  var_enumElementValuesPath_37564.addAssign_operation (GALGAS_string ("LITERALS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1090)) ;
  var_enumElementValuesPath_37564.addAssign_operation (GALGAS_string ("ECUC-ENUMERATION-LITERAL-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1091)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_parameter.ptr (), var_enumElementValuesPath_37564, var_enumElementValues_37523, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1092)) ;
  cEnumerator_arxmlElementValueList enumerator_37778 (var_enumElementValues_37523, kENUMERATION_UP) ;
  while (enumerator_37778.hasCurrentObject ()) {
    GALGAS_lstring var_enumValueName_37834 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) enumerator_37778.current_value (HERE).ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1094)) ;
    {
    var_enumValues_37455.setter_put (var_enumValueName_37834, GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1095)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1095)) ;
    }
    {
    routine_displayOil (var_enumValueName_37834.readProperty_string (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1096)) ;
    }
    if (enumerator_37778.hasNextObject ()) {
      {
      routine_displayOil (GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1098)) ;
      }
    }
    enumerator_37778.gotoNextObject () ;
  }
  {
  routine_displayOil (GALGAS_string ("]"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1100)) ;
  }
  GALGAS_object_5F_t var_defaultValue_38101 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1104)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_value_38174 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1105)) ;
      {
      routine_displayOil (GALGAS_string (" = ").add_operation (var_value_38174.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1106)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1106)) ;
      }
      var_defaultValue_38101 = GALGAS_enumAttribute::constructor_new (var_oil_5F_desc_37363, var_value_38174.readProperty_location (), var_value_38174.readProperty_string (), GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1113))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1111))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1107)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_withAuto_37180.boolEnum () ;
      if (kBoolTrue == test_1) {
        var_defaultValue_38101 = GALGAS_auto::constructor_new (var_oil_5F_desc_37363, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1117)) ;
      }
    }
    if (kBoolFalse == test_1) {
      var_defaultValue_38101 = GALGAS_void::constructor_new (var_oil_5F_desc_37363, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1119)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string ("\n"
    " : \"").add_operation (var_oil_5F_desc_37363.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1122)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1122)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1122)) ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1126)) ;
  temp_2.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1126)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1130)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_37363  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1130)) ;
  outArgument_options = GALGAS_impEnumType::constructor_new (temp_2, constinArgument_type, outArgument_objectName, var_multiple_37274.readProperty_bool (), temp_3, var_withAuto_37180, var_defaultValue_38101, var_enumValues_37455  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1125)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerStructure'
//
//----------------------------------------------------------------------------------------------------------------------

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
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1145)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1145)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1145)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1148)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1149)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1149)) ;
  }
  GALGAS_lbool var_multiple_39731 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_39731, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1152)) ;
  }
  GALGAS_lstring var_oil_5F_desc_39820 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_39820, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1155)) ;
  }
  {
  routine_displayOil (GALGAS_string ("\n"
    "    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1157)) ;
  }
  GALGAS_implementationObjectMap var_structAttributes_39895 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1160)) ;
  {
  routine_arxmlImplementationContainer (var_structAttributes_39895, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1161)) ;
  }
  {
  routine_displayOil (GALGAS_string ("\n"
    "    } : \"").add_operation (var_oil_5F_desc_39820.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1163)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1163)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1163)) ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1167)) ;
  temp_0.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1167)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1171)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_39820  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1171)) ;
  outArgument_options = GALGAS_impStructType::constructor_new (temp_0, constinArgument_type, outArgument_objectName, var_multiple_39731.readProperty_bool (), temp_1, var_structAttributes_39895  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1166)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerIdentifier'
//
//----------------------------------------------------------------------------------------------------------------------

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
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1183)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1183)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1183)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1186)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1187)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1187)) ;
  }
  GALGAS_lbool var_multiple_40822 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_40822, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1190)) ;
  }
  GALGAS_bool var_withAuto_40888 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_40888, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1193)) ;
  }
  GALGAS_lstring var_oil_5F_desc_40977 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_40977, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1196)) ;
  }
  GALGAS_object_5F_t var_defaultValue_41026 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1200)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_value_41099 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1201)) ;
      {
      routine_displayOil (GALGAS_string (" = ").add_operation (var_value_41099.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1202)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1202)) ;
      }
      var_defaultValue_41026 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_40977, var_value_41099.readProperty_location (), var_value_41099.readProperty_string ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1203)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_withAuto_40888.boolEnum () ;
      if (kBoolTrue == test_1) {
        var_defaultValue_41026 = GALGAS_auto::constructor_new (var_oil_5F_desc_40977, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1209)) ;
      }
    }
    if (kBoolFalse == test_1) {
      var_defaultValue_41026 = GALGAS_void::constructor_new (var_oil_5F_desc_40977, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1211)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_40977.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1213)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1213)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1213)) ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1217)) ;
  temp_2.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1217)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1221)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_40977  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1221)) ;
  outArgument_options = GALGAS_impAutoDefaultType::constructor_new (temp_2, constinArgument_type, outArgument_objectName, var_multiple_40822.readProperty_bool (), temp_3, var_withAuto_40888, var_defaultValue_41026  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1216)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerReference'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerReference (GALGAS_lstring & outArgument_objectName,
                                                    GALGAS_impType & outArgument_options,
                                                    const GALGAS_dataType constinArgument_type,
                                                    GALGAS_arxmlElementValue inArgument_parameter,
                                                    GALGAS_lstring /* inArgument_parentPath */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_lstring var_objectType_42293 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DESTINATION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1235)) ;
  var_objectType_42293.setter_setString (var_objectType_42293.readProperty_string ().getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1237)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1237)) ;
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (var_objectType_42293.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1238)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1238)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1241)) ;
  }
  {
  routine_displayOil (GALGAS_string (" ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1242)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1242)) ;
  }
  GALGAS_lbool var_multiple_42715 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_42715, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1245)) ;
  }
  GALGAS_lstring var_oil_5F_desc_42804 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_42804, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1248)) ;
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_42804.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1250)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1250)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1250)) ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1254)) ;
  temp_0.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1254)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1258)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_42804  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1258)) ;
  outArgument_options = GALGAS_refType::constructor_new (temp_0, constinArgument_type, outArgument_objectName, var_multiple_42715.readProperty_bool (), temp_1, var_objectType_42293  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1253)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionPackage'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionPackage (GALGAS_implementation & ioArgument_imp,
                                     GALGAS_applicationDefinition & ioArgument_application,
                                     GALGAS_arxmlElementValue inArgument_packageElement,
                                     GALGAS_lstring inArgument_parentPath,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_packageName_43460 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1274)) ;
  GALGAS_lstring var_currentPath_43573 = GALGAS_lstring::constructor_new (inArgument_parentPath.readProperty_string ().add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1277)).add_operation (var_packageName_43460.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1277)), var_packageName_43460.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1277)) ;
  GALGAS_arxmlElementValueList var_definitions_43800 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1281)) ;
  GALGAS_stringlist var_definitionPath_43834 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1282)) ;
  var_definitionPath_43834.addAssign_operation (GALGAS_string ("ELEMENTS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1283)) ;
  var_definitionPath_43834.addAssign_operation (GALGAS_string ("ECUC-MODULE-CONFIGURATION-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1284)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_definitionPath_43834, var_definitions_43800, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1285)) ;
  cEnumerator_arxmlElementValueList enumerator_44030 (var_definitions_43800, kENUMERATION_UP) ;
  while (enumerator_44030.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionRoot (ioArgument_imp, ioArgument_application, enumerator_44030.current_value (HERE), var_currentPath_43573, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1287)) ;
    }
    enumerator_44030.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_packages_44214 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1291)) ;
  GALGAS_stringlist var_packagesPath_44246 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1292)) ;
  var_packagesPath_44246.addAssign_operation (GALGAS_string ("AR-PACKAGES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1293)) ;
  var_packagesPath_44246.addAssign_operation (GALGAS_string ("AR-PACKAGE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1294)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_packagesPath_44246, var_packages_44214, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1295)) ;
  cEnumerator_arxmlElementValueList enumerator_44411 (var_packages_44214, kENUMERATION_UP) ;
  while (enumerator_44411.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionPackage (ioArgument_imp, ioArgument_application, enumerator_44411.current_value (HERE), var_currentPath_43573, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1297)) ;
    }
    enumerator_44411.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionRoot'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionRoot (GALGAS_implementation & ioArgument_imp,
                                  GALGAS_applicationDefinition & ioArgument_application,
                                  GALGAS_arxmlElementValue inArgument_packageElement,
                                  GALGAS_lstring /* inArgument_parentPath */,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_cpuName_44703 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1308)) ;
  GALGAS_lstring var_currentPath_44817 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1311)) ;
  GALGAS_objectsMap var_objects_44932 = ioArgument_application.readProperty_objects () ;
  GALGAS_lstring var_oil_5F_desc_45049 ;
  {
  routine_arxmlGetDescription (inArgument_packageElement, var_oil_5F_desc_45049, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1317)) ;
  }
  GALGAS_arxmlElementValueList var_subDefs_45111 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1320)) ;
  GALGAS_stringlist var_subDefsPath_45142 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1321)) ;
  var_subDefsPath_45142.addAssign_operation (GALGAS_string ("CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1322)) ;
  var_subDefsPath_45142.addAssign_operation (GALGAS_string ("ECUC-CONTAINER-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1323)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_subDefsPath_45142, var_subDefs_45111, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1324)) ;
  {
  routine_displayOil (GALGAS_string ("\n"
    "CPU ").add_operation (var_cpuName_44703.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1326)).add_operation (GALGAS_string ("\n"
    "{\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1326)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1326)) ;
  }
  cEnumerator_arxmlElementValueList enumerator_45364 (var_subDefs_45111, kENUMERATION_UP) ;
  while (enumerator_45364.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionObject (ioArgument_imp, var_objects_44932, enumerator_45364.current_value (HERE), var_currentPath_44817, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1329)) ;
    }
    enumerator_45364.gotoNextObject () ;
  }
  {
  ioArgument_application.setter_setName (var_cpuName_44703 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1333)) ;
  }
  {
  ioArgument_application.setter_setObjects (var_objects_44932 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1334)) ;
  }
  {
  routine_displayOil (GALGAS_string ("}; /* END CPU ").add_operation (var_cpuName_44703.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1336)).add_operation (GALGAS_string (" : \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1336)).add_operation (var_oil_5F_desc_45049.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1337)).add_operation (GALGAS_string ("\" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1337)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1336)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionObject'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionObject (GALGAS_implementation & ioArgument_imp,
                                    GALGAS_objectsMap & ioArgument_objects,
                                    GALGAS_arxmlElementValue inArgument_currentElement,
                                    GALGAS_lstring inArgument_parentPath,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_currentPath_45852 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1347)) ;
  GALGAS_lstring var_objectKind_45978 ;
  {
  routine_oilEquivalentName (inArgument_parentPath, var_currentPath_45852, var_objectKind_45978, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1348)) ;
  }
  GALGAS_implementationObject var_impObjOfKind_46043 = callExtensionGetter_impObject ((const cPtr_implementation *) ioArgument_imp.ptr (), var_objectKind_45978.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1351)) ;
  GALGAS_objectKind var_objectsForKind_46111 = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1352))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1352)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = ioArgument_objects.getter_hasKey (var_objectKind_45978.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1353)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      ioArgument_objects.setter_del (var_objectKind_45978, var_objectsForKind_46111, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1354)) ;
      }
    }
  }
  GALGAS_lstring var_objectName_46304 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1358)) ;
  GALGAS_objectAttributes var_object_46416 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1361)) ;
  GALGAS_objectKindMap var_objectsKind_46461 = var_objectsForKind_46111.readProperty_objects () ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsEqual, var_impObjOfKind_46043.readProperty_multiple ().readProperty_bool ().objectCompare (GALGAS_bool (false))).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_objectName_46304 = var_objectKind_45978 ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = var_objectsKind_46461.getter_hasKey (var_objectName_46304.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1371)).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      var_objectsKind_46461.setter_del (var_objectName_46304, var_object_46416, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1372)) ;
      }
    }
  }
  GALGAS_lstring var_oil_5F_desc_47027 ;
  {
  routine_arxmlGetDescription (inArgument_currentElement, var_oil_5F_desc_47027, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1376)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (var_objectKind_45978.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1378)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1378)).add_operation (var_objectName_46304.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1378)).add_operation (GALGAS_string ("\n"
    "  {\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1378)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1378)) ;
  }
  {
  routine_arxmlDefinitionContainer (var_impObjOfKind_46043.readProperty_attributes (), var_object_46416, inArgument_currentElement, var_currentPath_45852, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1381)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  } : \"").add_operation (var_oil_5F_desc_47027.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1386)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1386)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1386)) ;
  }
  GALGAS_identifierMap var_attributes_47422 = var_object_46416.readProperty_objectParams () ;
  enumGalgasBool test_3 = kBoolTrue ;
  if (kBoolTrue == test_3) {
    test_3 = var_attributes_47422.getter_hasKey (GALGAS_string ("NAME") COMMA_SOURCE_FILE ("arxml_parser.galgas", 1390)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 1390)).boolEnum () ;
    if (kBoolTrue == test_3) {
      {
      var_attributes_47422.setter_put (GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), var_objectName_46304.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1391)), GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_47027, var_objectName_46304.readProperty_location (), var_objectName_46304.readProperty_string ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1392)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1391)) ;
      }
      {
      var_object_46416.setter_setObjectParams (var_attributes_47422 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1395)) ;
      }
    }
  }
  {
  var_objectsKind_46461.setter_put (var_objectName_46304, var_object_46416, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1397)) ;
  }
  {
  var_objectsForKind_46111.setter_setObjects (var_objectsKind_46461 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1398)) ;
  }
  {
  ioArgument_objects.setter_put (var_objectKind_45978, var_objectsForKind_46111, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1399)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionContainer'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionContainer (const GALGAS_implementationObjectMap constinArgument_types,
                                       GALGAS_objectAttributes & ioArgument_identifiers,
                                       GALGAS_arxmlElementValue inArgument_currentElement,
                                       GALGAS_lstring inArgument_currentPath,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList var_textParameters_48218 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1409)) ;
  GALGAS_stringlist var_textParametersPath_48256 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1410)) ;
  var_textParametersPath_48256.addAssign_operation (GALGAS_string ("PARAMETER-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1411)) ;
  var_textParametersPath_48256.addAssign_operation (GALGAS_string ("ECUC-TEXTUAL-PARAM-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1412)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_textParametersPath_48256, var_textParameters_48218, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1413)) ;
  GALGAS_arxmlElementValueList var_numParameters_48536 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1416)) ;
  GALGAS_stringlist var_numParametersPath_48573 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1417)) ;
  var_numParametersPath_48573.addAssign_operation (GALGAS_string ("PARAMETER-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1418)) ;
  var_numParametersPath_48573.addAssign_operation (GALGAS_string ("ECUC-NUMERICAL-PARAM-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1419)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_numParametersPath_48573, var_numParameters_48536, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1420)) ;
  GALGAS_arxmlElementValueList var_refParameters_48822 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1423)) ;
  GALGAS_stringlist var_refParametersPath_48859 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1424)) ;
  var_refParametersPath_48859.addAssign_operation (GALGAS_string ("REFERENCE-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1425)) ;
  var_refParametersPath_48859.addAssign_operation (GALGAS_string ("ECUC-REFERENCE-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1426)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_refParametersPath_48859, var_refParameters_48822, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1427)) ;
  GALGAS_arxmlElementValueList var_structParameters_49105 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1430)) ;
  GALGAS_stringlist var_structParametersPath_49145 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1431)) ;
  var_structParametersPath_49145.addAssign_operation (GALGAS_string ("SUB-CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1432)) ;
  var_structParametersPath_49145.addAssign_operation (GALGAS_string ("ECUC-CONTAINER-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1433)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_structParametersPath_49145, var_structParameters_49105, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1434)) ;
  GALGAS_arxmlElementValueList var_allParameters_49392 = var_numParameters_48536.add_operation (var_textParameters_48218, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1437)).add_operation (var_refParameters_48822, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1438)).add_operation (var_structParameters_49105, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1439)) ;
  cEnumerator_arxmlElementValueList enumerator_49652 (var_allParameters_49392, kENUMERATION_UP) ;
  while (enumerator_49652.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionParameter (constinArgument_types, ioArgument_identifiers, enumerator_49652.current_value (HERE), inArgument_currentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1444)) ;
    }
    enumerator_49652.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionParameter'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionParameter (const GALGAS_implementationObjectMap constinArgument_types,
                                       GALGAS_objectAttributes & ioArgument_identifiers,
                                       GALGAS_arxmlElementValue inArgument_parameter,
                                       GALGAS_lstring inArgument_parentPath,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t var_val_49955 ;
  GALGAS_lstring var_parameterPath_49984 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1456)) ;
  GALGAS_lstring var_parameterType_50106 ;
  {
  routine_oilEquivalentName (inArgument_parentPath, var_parameterPath_49984, var_parameterType_50106, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1457)) ;
  }
  GALGAS_bool var_typeOk_50147 = GALGAS_bool (false) ;
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1461)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1461))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1461)) ;
  GALGAS_impType var_type_50171 = GALGAS_impVoid::constructor_new (temp_0, GALGAS_dataType::constructor_void (SOURCE_FILE ("arxml_parser.galgas", 1463)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1463)), GALGAS_bool (false), GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1465))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1461)) ;
  GALGAS_lstring var_valueType_50447 = callExtensionGetter_getAttributeValueFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFINITION-REF"), GALGAS_string ("DEST"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1467)) ;
  GALGAS_lstring var_oil_5F_desc_50640 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1472))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1472)) ;
  GALGAS_bool var_isAuto_50796 = GALGAS_bool (false) ;
  GALGAS_lstring var_parameterValue_50830 ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1479)).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_parameterValue_50830 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1483)) ;
    }
  }
  if (kBoolFalse == test_1) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1484)).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_parameterValue_50830 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1488)) ;
        var_parameterValue_50830.setter_setString (var_parameterValue_50830.readProperty_string ().getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1490)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1490)) ;
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, var_parameterType_50106.readProperty_string ().getter_rightSubString (GALGAS_uint (uint32_t (3U)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1492)).objectCompare (GALGAS_string ("REF"))).boolEnum () ;
          if (kBoolTrue == test_3) {
            var_parameterType_50106.setter_setString (var_parameterType_50106.readProperty_string ().getter_leftSubString (var_parameterType_50106.readProperty_string ().getter_length (SOURCE_FILE ("arxml_parser.galgas", 1494)).substract_operation (GALGAS_uint (uint32_t (3U)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1494)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1493)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1493)) ;
          }
        }
        if (kBoolFalse == test_3) {
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsEqual, var_parameterType_50106.readProperty_string ().getter_rightSubString (GALGAS_uint (uint32_t (4U)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1495)).objectCompare (GALGAS_string ("REFS"))).boolEnum () ;
            if (kBoolTrue == test_4) {
              var_parameterType_50106.setter_setString (var_parameterType_50106.readProperty_string ().getter_leftSubString (var_parameterType_50106.readProperty_string ().getter_length (SOURCE_FILE ("arxml_parser.galgas", 1497)).substract_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1497)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1496)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1496)) ;
            }
          }
          if (kBoolFalse == test_4) {
            TC_Array <C_FixItDescription> fixItArray5 ;
            inCompiler->emitSemanticError (var_parameterType_50106.readProperty_location (), GALGAS_string ("An object reference must end with REF or REFS"), fixItArray5  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1499)) ;
          }
        }
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_6 = kBoolTrue ;
      if (kBoolTrue == test_6) {
        GALGAS_bool test_7 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("PARAMETER-VALUES"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1501)) ;
        if (kBoolTrue != test_7.boolEnum ()) {
          test_7 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("REFERENCE-VALUES"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1502)) ;
        }
        test_6 = test_7.boolEnum () ;
        if (kBoolTrue == test_6) {
          var_parameterValue_50830 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1506)) ;
        }
      }
      if (kBoolFalse == test_6) {
        enumGalgasBool test_8 = kBoolTrue ;
        if (kBoolTrue == test_8) {
          test_8 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("IS-AUTO-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1507)).boolEnum () ;
          if (kBoolTrue == test_8) {
            var_parameterValue_50830 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("IS-AUTO-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1511)) ;
            enumGalgasBool test_9 = kBoolTrue ;
            if (kBoolTrue == test_9) {
              GALGAS_bool test_10 = GALGAS_bool (kIsEqual, var_parameterValue_50830.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1512)).objectCompare (GALGAS_string ("TRUE"))) ;
              if (kBoolTrue != test_10.boolEnum ()) {
                test_10 = GALGAS_bool (kIsEqual, var_parameterValue_50830.readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
              }
              test_9 = test_10.boolEnum () ;
              if (kBoolTrue == test_9) {
                var_isAuto_50796 = GALGAS_bool (true) ;
              }
            }
          }
        }
        if (kBoolFalse == test_8) {
          TC_Array <C_FixItDescription> fixItArray11 ;
          inCompiler->emitSemanticError (var_parameterType_50106.readProperty_location (), GALGAS_string ("No value has been found."), fixItArray11  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1517)) ;
          var_parameterValue_50830.drop () ; // Release error dropped variable
        }
      }
    }
  }
  enumGalgasBool test_12 = kBoolTrue ;
  if (kBoolTrue == test_12) {
    test_12 = constinArgument_types.getter_hasKey (var_parameterType_50106.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1521)).boolEnum () ;
    if (kBoolTrue == test_12) {
      constinArgument_types.method_get (var_parameterType_50106, var_type_50171, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1522)) ;
      var_typeOk_50147 = GALGAS_bool (true) ;
      {
      routine_testTypeError (var_type_50171.readProperty_type (), var_valueType_50447, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1525)) ;
      }
    }
  }
  if (kBoolFalse == test_12) {
    TC_Array <C_FixItDescription> fixItArray13 ;
    inCompiler->emitSemanticError (var_parameterType_50106.readProperty_location (), var_parameterType_50106.readProperty_string ().add_operation (GALGAS_string (" is not declared in the "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1527)).add_operation (GALGAS_string ("IMPLEMENTATION."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1527)), fixItArray13  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1527)) ;
  }
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (var_parameterType_50106.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1531)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1531)) ;
  }
  GALGAS_implementationObjectMap var_subTypes_53416 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1533)) ;
  GALGAS_objectAttributes var_subAttributes_53489 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1534)) ;
  enumGalgasBool test_14 = kBoolTrue ;
  if (kBoolTrue == test_14) {
    test_14 = var_isAuto_50796.boolEnum () ;
    if (kBoolTrue == test_14) {
      {
      routine_displayOil (GALGAS_string (" = AUTO;"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1543)) ;
      }
      enumGalgasBool test_15 = kBoolTrue ;
      if (kBoolTrue == test_15) {
        test_15 = callExtensionGetter_autoAllowed ((const cPtr_impType *) var_type_50171.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1544)).boolEnum () ;
        if (kBoolTrue == test_15) {
          var_val_49955 = GALGAS_auto::constructor_new (var_oil_5F_desc_50640, var_parameterValue_50830.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1545)) ;
        }
      }
      if (kBoolFalse == test_15) {
        TC_Array <C_FixItDescription> fixItArray16 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1547)), GALGAS_string ("AUTO is not allowed"), fixItArray16  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1547)) ;
        var_val_49955.drop () ; // Release error dropped variable
      }
    }
  }
  if (kBoolFalse == test_14) {
    enumGalgasBool test_17 = kBoolTrue ;
    if (kBoolTrue == test_17) {
      test_17 = GALGAS_bool (kIsEqual, var_valueType_50447.readProperty_string ().objectCompare (GALGAS_string ("ECUC-ENUMERATION-PARAM-DEF"))).boolEnum () ;
      if (kBoolTrue == test_17) {
        GALGAS_impEnumType temp_18 ;
        if (var_type_50171.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_impEnumType *> (var_type_50171.ptr ())) {
            temp_18 = (cPtr_impEnumType *) var_type_50171.ptr () ;
          }else{
            inCompiler->castError ("impEnumType", var_type_50171.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1554)) ;
          }
        }
        GALGAS_impEnumType var_enumType_54296 = temp_18 ;
        enumGalgasBool test_19 = kBoolTrue ;
        if (kBoolTrue == test_19) {
          test_19 = var_enumType_54296.readProperty_valuesMap ().getter_hasKey (var_parameterValue_50830.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1555)).boolEnum () ;
          if (kBoolTrue == test_19) {
            var_enumType_54296.readProperty_valuesMap ().method_get (var_parameterValue_50830, var_subTypes_53416, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1556)) ;
          }
        }
        if (kBoolFalse == test_19) {
          TC_Array <C_FixItDescription> fixItArray20 ;
          inCompiler->emitSemanticError (var_parameterValue_50830.readProperty_location (), var_parameterValue_50830.readProperty_string ().add_operation (GALGAS_string (" ENUM value "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1558)).add_operation (GALGAS_string ("for "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1558)).add_operation (var_parameterType_50106.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1559)).add_operation (GALGAS_string (" undeclared.\n"
            "One of the following"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1559)).add_operation (GALGAS_string ("values are expected :\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1559)).add_operation (function_valueList (var_enumType_54296.readProperty_valuesMap (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1560)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1560)), fixItArray20  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1558)) ;
        }
        {
        routine_displayOil (GALGAS_string (" = ").add_operation (var_parameterValue_50830.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1563)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1563)) ;
        }
        enumGalgasBool test_21 = kBoolTrue ;
        if (kBoolTrue == test_21) {
          test_21 = GALGAS_bool (kIsNotEqual, var_subTypes_53416.getter_count (SOURCE_FILE ("arxml_parser.galgas", 1564)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
          if (kBoolTrue == test_21) {
            {
            routine_displayOil (GALGAS_string ("\n"
              "    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1565)) ;
            }
            {
            routine_arxmlDefinitionContainer (var_subTypes_53416, var_subAttributes_53489, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1566)) ;
            }
            {
            routine_displayOil (GALGAS_string ("    }"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1568)) ;
            }
          }
        }
        {
        routine_displayOil (GALGAS_string (";"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1570)) ;
        }
        var_val_49955 = GALGAS_enumAttribute::constructor_new (var_oil_5F_desc_50640, var_parameterValue_50830.readProperty_location (), var_parameterValue_50830.readProperty_string (), var_subAttributes_53489  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1572)) ;
      }
    }
    if (kBoolFalse == test_17) {
      enumGalgasBool test_22 = kBoolTrue ;
      if (kBoolTrue == test_22) {
        test_22 = GALGAS_bool (kIsEqual, var_valueType_50447.readProperty_string ().objectCompare (GALGAS_string ("ECUC-BOOLEAN-PARAM-DEF"))).boolEnum () ;
        if (kBoolTrue == test_22) {
          GALGAS_impBoolType temp_23 ;
          if (var_type_50171.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_impBoolType *> (var_type_50171.ptr ())) {
              temp_23 = (cPtr_impBoolType *) var_type_50171.ptr () ;
            }else{
              inCompiler->castError ("impBoolType", var_type_50171.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1581)) ;
            }
          }
          GALGAS_impBoolType var_boolType_55430 = temp_23 ;
          GALGAS_bool var_booleanValue_55480 ;
          enumGalgasBool test_24 = kBoolTrue ;
          if (kBoolTrue == test_24) {
            GALGAS_bool test_25 = GALGAS_bool (kIsEqual, var_parameterValue_50830.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1583)).objectCompare (GALGAS_string ("TRUE"))) ;
            if (kBoolTrue != test_25.boolEnum ()) {
              test_25 = GALGAS_bool (kIsEqual, var_parameterValue_50830.readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
            }
            test_24 = test_25.boolEnum () ;
            if (kBoolTrue == test_24) {
              var_subTypes_53416 = var_boolType_55430.readProperty_trueSubAttributes () ;
              var_booleanValue_55480 = GALGAS_bool (true) ;
            }
          }
          if (kBoolFalse == test_24) {
            enumGalgasBool test_26 = kBoolTrue ;
            if (kBoolTrue == test_26) {
              GALGAS_bool test_27 = GALGAS_bool (kIsEqual, var_parameterValue_50830.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1587)).objectCompare (GALGAS_string ("FALSE"))) ;
              if (kBoolTrue != test_27.boolEnum ()) {
                test_27 = GALGAS_bool (kIsEqual, var_parameterValue_50830.readProperty_string ().objectCompare (GALGAS_string ("0"))) ;
              }
              test_26 = test_27.boolEnum () ;
              if (kBoolTrue == test_26) {
                var_subTypes_53416 = var_boolType_55430.readProperty_falseSubAttributes () ;
                var_booleanValue_55480 = GALGAS_bool (false) ;
              }
            }
            if (kBoolFalse == test_26) {
              var_booleanValue_55480 = GALGAS_bool (false) ;
              TC_Array <C_FixItDescription> fixItArray28 ;
              inCompiler->emitSemanticError (var_parameterValue_50830.readProperty_location (), GALGAS_string ("A Boolean must be 'true', 'false', '0' or '1'"), fixItArray28  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1593)) ;
            }
          }
          {
          routine_displayOil (GALGAS_string (" = ").add_operation (var_booleanValue_55480.getter_cString (SOURCE_FILE ("arxml_parser.galgas", 1596)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1596)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1596)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1596)) ;
          }
          enumGalgasBool test_29 = kBoolTrue ;
          if (kBoolTrue == test_29) {
            test_29 = GALGAS_bool (kIsNotEqual, var_subTypes_53416.getter_count (SOURCE_FILE ("arxml_parser.galgas", 1597)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
            if (kBoolTrue == test_29) {
              {
              routine_displayOil (GALGAS_string ("\n"
                "    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1598)) ;
              }
              {
              routine_arxmlDefinitionContainer (var_subTypes_53416, var_subAttributes_53489, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1599)) ;
              }
              {
              routine_displayOil (GALGAS_string ("    }"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1601)) ;
              }
            }
          }
          {
          routine_displayOil (GALGAS_string (";"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1603)) ;
          }
          var_val_49955 = GALGAS_boolAttribute::constructor_new (var_oil_5F_desc_50640, var_parameterType_50106.readProperty_location (), var_booleanValue_55480, var_subAttributes_53489  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1605)) ;
        }
      }
      if (kBoolFalse == test_22) {
        enumGalgasBool test_30 = kBoolTrue ;
        if (kBoolTrue == test_30) {
          test_30 = GALGAS_bool (kIsEqual, var_valueType_50447.readProperty_string ().objectCompare (GALGAS_string ("ECUC-INTEGER-PARAM-DEF"))).boolEnum () ;
          if (kBoolTrue == test_30) {
            GALGAS_bool var_sign_56719 ;
            {
            routine_arxmlPopSign (var_parameterValue_50830, var_sign_56719, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1614)) ;
            }
            GALGAS_luint_36__34_ var_integerValue_56751 = GALGAS_luint_36__34_::constructor_new (var_parameterValue_50830.readProperty_string ().getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1617)).getter_uint_36__34_ (SOURCE_FILE ("arxml_parser.galgas", 1617)), var_parameterValue_50830.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1616)) ;
            {
            routine_displayOil (GALGAS_string (" = ").add_operation (var_integerValue_56751.readProperty_uint_36__34_ ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 1620)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1620)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1620)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1620)) ;
            }
            var_val_49955 = function_checkAndGetIntegerNumber (var_oil_5F_desc_50640, var_type_50171.readProperty_type (), var_integerValue_56751, var_sign_56719, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1622)) ;
          }
        }
        if (kBoolFalse == test_30) {
          enumGalgasBool test_31 = kBoolTrue ;
          if (kBoolTrue == test_31) {
            test_31 = GALGAS_bool (kIsEqual, var_valueType_50447.readProperty_string ().objectCompare (GALGAS_string ("ECUC-FLOAT-PARAM-DEF"))).boolEnum () ;
            if (kBoolTrue == test_31) {
              GALGAS_bool var_sign_57322 ;
              {
              routine_arxmlPopSign (var_parameterValue_50830, var_sign_57322, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1628)) ;
              }
              GALGAS_ldouble var_floatValue_57352 = GALGAS_ldouble::constructor_new (var_parameterValue_50830.readProperty_string ().getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1631)), var_parameterValue_50830.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1630)) ;
              {
              routine_displayOil (GALGAS_string (" = ").add_operation (var_floatValue_57352.readProperty_double ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 1634)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1634)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1634)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1634)) ;
              }
              var_val_49955 = function_checkAndGetFloatNumber (var_oil_5F_desc_50640, var_type_50171.readProperty_type (), var_floatValue_57352, var_sign_57322, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1636)) ;
            }
          }
          if (kBoolFalse == test_31) {
            enumGalgasBool test_32 = kBoolTrue ;
            if (kBoolTrue == test_32) {
              test_32 = GALGAS_bool (kIsEqual, var_valueType_50447.readProperty_string ().objectCompare (GALGAS_string ("ECUC-STRING-PARAM-DEF"))).boolEnum () ;
              if (kBoolTrue == test_32) {
                {
                routine_displayOil (GALGAS_string (" = \"").add_operation (var_parameterValue_50830.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1642)).add_operation (GALGAS_string ("\";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1642)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1642)) ;
                }
                var_val_49955 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_50640, var_parameterValue_50830.readProperty_location (), var_parameterValue_50830.readProperty_string ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1644)) ;
              }
            }
            if (kBoolFalse == test_32) {
              enumGalgasBool test_33 = kBoolTrue ;
              if (kBoolTrue == test_33) {
                test_33 = GALGAS_bool (kIsEqual, var_valueType_50447.readProperty_string ().objectCompare (GALGAS_string ("ECUC-REFERENCE-DEF"))).boolEnum () ;
                if (kBoolTrue == test_33) {
                  {
                  routine_displayOil (GALGAS_string (" = ").add_operation (var_parameterValue_50830.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1652)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1652)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1652)) ;
                  }
                  var_val_49955 = GALGAS_objectRefAttribute::constructor_new (var_oil_5F_desc_50640, var_parameterValue_50830.readProperty_location (), var_parameterValue_50830  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1654)) ;
                }
              }
              if (kBoolFalse == test_33) {
                enumGalgasBool test_34 = kBoolTrue ;
                if (kBoolTrue == test_34) {
                  test_34 = GALGAS_bool (kIsEqual, var_valueType_50447.readProperty_string ().objectCompare (GALGAS_string ("TPL-IDENTIFIER-DEF"))).boolEnum () ;
                  if (kBoolTrue == test_34) {
                    {
                    routine_displayOil (GALGAS_string (" = ").add_operation (var_parameterValue_50830.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1662)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1662)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1662)) ;
                    }
                    var_val_49955 = GALGAS_string_5F_class::constructor_new (var_oil_5F_desc_50640, var_parameterValue_50830.readProperty_location (), var_parameterValue_50830.readProperty_string ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1664)) ;
                  }
                }
                if (kBoolFalse == test_34) {
                  enumGalgasBool test_35 = kBoolTrue ;
                  if (kBoolTrue == test_35) {
                    test_35 = GALGAS_bool (kIsEqual, var_valueType_50447.readProperty_string ().objectCompare (GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF"))).boolEnum () ;
                    if (kBoolTrue == test_35) {
                      GALGAS_impStructType temp_36 ;
                      if (var_type_50171.isValid ()) {
                        if (NULL != dynamic_cast <const cPtr_impStructType *> (var_type_50171.ptr ())) {
                          temp_36 = (cPtr_impStructType *) var_type_50171.ptr () ;
                        }else{
                          inCompiler->castError ("impStructType", var_type_50171.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1672)) ;
                        }
                      }
                      GALGAS_impStructType var_structType_59245 = temp_36 ;
                      var_subTypes_53416 = var_structType_59245.readProperty_structAttributes () ;
                      {
                      routine_displayOil (GALGAS_string (" ").add_operation (var_parameterValue_50830.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1675)).add_operation (GALGAS_string ("\n"
                        "    {\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1675)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1675)) ;
                      }
                      {
                      routine_arxmlDefinitionContainer (var_subTypes_53416, var_subAttributes_53489, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1676)) ;
                      }
                      {
                      routine_displayOil (GALGAS_string ("    };"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1678)) ;
                      }
                      var_val_49955 = GALGAS_structAttribute::constructor_new (var_oil_5F_desc_50640, var_parameterValue_50830.readProperty_location (), var_parameterValue_50830, var_subAttributes_53489  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1680)) ;
                    }
                  }
                  if (kBoolFalse == test_35) {
                    TC_Array <C_FixItDescription> fixItArray37 ;
                    inCompiler->emitSemanticError (var_valueType_50447.readProperty_location (), GALGAS_string ("Undefined valueType ").add_operation (var_valueType_50447.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1688)), fixItArray37  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1688)) ;
                    var_val_49955.drop () ; // Release error dropped variable
                    var_typeOk_50147 = GALGAS_bool (false) ;
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
  routine_displayOil (GALGAS_string ("      /* ARXML Type :").add_operation (var_valueType_50447.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1692)).add_operation (GALGAS_string (" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1692)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1692)) ;
  }
  GALGAS_identifierMap var_idfs_60180 = ioArgument_identifiers.readProperty_objectParams () ;
  enumGalgasBool test_38 = kBoolTrue ;
  if (kBoolTrue == test_38) {
    test_38 = var_type_50171.readProperty_multiple ().boolEnum () ;
    if (kBoolTrue == test_38) {
      enumGalgasBool test_39 = kBoolTrue ;
      if (kBoolTrue == test_39) {
        test_39 = var_idfs_60180.getter_hasKey (var_parameterType_50106.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1699)).boolEnum () ;
        if (kBoolTrue == test_39) {
          GALGAS_object_5F_t var_attributeList_60318 ;
          {
          var_idfs_60180.setter_del (var_parameterType_50106, var_attributeList_60318, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1703)) ;
          }
          if (var_attributeList_60318.isValid ()) {
            if (var_attributeList_60318.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
              GALGAS_multipleAttribute cast_60522_multiAttribute ((cPtr_multipleAttribute *) var_attributeList_60318.ptr ()) ;
              GALGAS_identifierList var_aList_60554 = cast_60522_multiAttribute.readProperty_items () ;
              var_aList_60554.addAssign_operation (var_val_49955  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1707)) ;
              var_val_49955 = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1708)), cast_60522_multiAttribute.readProperty_location (), var_aList_60554  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1708)) ;
            }
          }
        }
      }
      if (kBoolFalse == test_39) {
        GALGAS_identifierList var_aList_60824 = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1713)) ;
        GALGAS_object_5F_t var_defaultValue_60907 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) var_type_50171.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1715)) ;
        if (var_defaultValue_60907.isValid ()) {
          if (var_defaultValue_60907.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
            GALGAS_multipleAttribute cast_61036_multiAttribute ((cPtr_multipleAttribute *) var_defaultValue_60907.ptr ()) ;
            var_aList_60824 = cast_61036_multiAttribute.readProperty_items () ;
          }
        }
        var_aList_60824.addAssign_operation (var_val_49955  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1725)) ;
        var_val_49955 = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1727)), var_val_49955.readProperty_location (), var_aList_60824  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1727)) ;
      }
      enumGalgasBool test_40 = kBoolTrue ;
      if (kBoolTrue == test_40) {
        test_40 = var_idfs_60180.getter_hasKey (var_parameterType_50106.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1729)).boolEnum () ;
        if (kBoolTrue == test_40) {
          GALGAS_object_5F_t var_existingObject_61527 ;
          {
          var_idfs_60180.setter_del (var_parameterType_50106, var_existingObject_61527, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1733)) ;
          }
          {
          var_val_49955.insulate (HERE) ;
          cPtr_object_5F_t * ptr_61594 = (cPtr_object_5F_t *) var_val_49955.ptr () ;
          callExtensionSetter_mergeSubAttributes ((cPtr_object_5F_t *) ptr_61594, var_existingObject_61527, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1734)) ;
          }
        }
      }
    }
  }
  enumGalgasBool test_41 = kBoolTrue ;
  if (kBoolTrue == test_41) {
    test_41 = var_typeOk_50147.boolEnum () ;
    if (kBoolTrue == test_41) {
      {
      var_idfs_60180.setter_put (var_parameterType_50106, var_val_49955, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1740)) ;
      }
    }
  }
  {
  ioArgument_identifiers.setter_setObjectParams (var_idfs_60180 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1742)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'testTypeError'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_testTypeError (GALGAS_dataType inArgument_type,
                            GALGAS_lstring inArgument_valueType,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, extensionGetter_arxmlType (inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1753)).objectCompare (inArgument_valueType.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (inArgument_valueType.readProperty_location (), GALGAS_string ("Expected oil type ").add_operation (extensionGetter_oilType (inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1754)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1754)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1754)).add_operation (GALGAS_string (" Found "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1754)).add_operation (inArgument_valueType.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1755)).add_operation (GALGAS_string (".\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1755)).add_operation (GALGAS_string (" Fix : Replace it with "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1755)).add_operation (extensionGetter_arxmlType (inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1756)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1756)), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1754)) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'oilEquivalentName'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_oilEquivalentName (GALGAS_lstring inArgument_parentPath,
                                GALGAS_lstring inArgument_currentPath,
                                GALGAS_lstring & outArgument_outName,
                                C_Compiler * inCompiler
                                COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outName.drop () ; // Release 'out' argument
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, inArgument_parentPath.readProperty_string ().objectCompare (inArgument_currentPath.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      inArgument_parentPath.setter_setString (inArgument_parentPath.readProperty_string ().getter_stringByDeletingLastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1766)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1766)) ;
    }
  }
  GALGAS_lstring var_objectKind_62460 = GALGAS_lstring::constructor_new (inArgument_currentPath.readProperty_string ().getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1769)), inArgument_currentPath.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1769)) ;
  GALGAS_string var_lastParent_62753 = inArgument_parentPath.readProperty_string ().getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1774)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1774)) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsEqual, var_lastParent_62753.objectCompare (GALGAS_string ("OSOS"))).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_lastParent_62753 = GALGAS_string ("OS") ;
    }
  }
  GALGAS_uint var_lastParentLength_63001 = var_lastParent_62753.getter_length (SOURCE_FILE ("arxml_parser.galgas", 1782)) ;
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsEqual, var_objectKind_62460.readProperty_string ().getter_leftSubString (var_lastParentLength_63001 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1783)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1783)).objectCompare (var_lastParent_62753)).boolEnum () ;
    if (kBoolTrue == test_2) {
      var_objectKind_62460.setter_setString (var_objectKind_62460.readProperty_string ().getter_subStringFromIndex (var_lastParentLength_63001 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1785)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1785)) ;
      var_objectKind_62460.setter_setString (var_objectKind_62460.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1786)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1786)) ;
      outArgument_outName = var_objectKind_62460 ;
    }
  }
  if (kBoolFalse == test_2) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (var_objectKind_62460.readProperty_location (), GALGAS_string ("An object must be named by its Parent.\n"
      " ").add_operation (GALGAS_string ("Ex : If Task object has Os parent, then the DEFINITION-REF must be "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1789)).add_operation (GALGAS_string ("(...)/Os/OsTask.\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1790)).add_operation (GALGAS_string ("Fix : Add \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1791)).add_operation (var_lastParent_62753, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1792)).add_operation (GALGAS_string ("\" to the name of your property."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1792)), fixItArray3  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1789)) ;
    outArgument_outName.drop () ; // Release error dropped variable
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlGetDescription'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlGetDescription (GALGAS_arxmlElementValue inArgument_packageElement,
                                  GALGAS_lstring & outArgument_description,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_description.drop () ; // Release 'out' argument
  outArgument_description = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1801))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1801)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DESC"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1804)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_arxmlElementValue var_desc_63874 ;
      callExtensionMethod_getElement ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DESC"), var_desc_63874, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1805)) ;
      callExtensionMethod_getAllTextsInSelf ((cPtr_arxmlElementValue *) var_desc_63874.ptr (), GALGAS_string (" "), outArgument_description, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1806)) ;
    }
  }
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("INTRODUCTION"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1808)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_arxmlElementValue var_desc_64059 ;
      callExtensionMethod_getElement ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("INTRODUCTION"), var_desc_64059, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1809)) ;
      callExtensionMethod_getAllTextsInSelf ((cPtr_arxmlElementValue *) var_desc_64059.ptr (), GALGAS_string (" "), outArgument_description, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1810)) ;
    }
  }
  outArgument_description.setter_setString (outArgument_description.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("\n"), GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1814)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1814)) ;
  outArgument_description.setter_setString (outArgument_description.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("\r"), GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1817)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1817)) ;
  outArgument_description.setter_setString (outArgument_description.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("\\"), GALGAS_string ("\\\\"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1820)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1820)) ;
  outArgument_description.setter_setString (outArgument_description.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("\""), GALGAS_string ("\\\""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1823)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1823)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'displayOil'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_displayOil (GALGAS_string inArgument_string,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (gOption_goil_5F_options_arxmlDisplayOil.readProperty_value ()).boolEnum () ;
    if (kBoolTrue == test_0) {
      inCompiler->printMessage (inArgument_string  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1832)) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlGetMultiplicity'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlGetMultiplicity (GALGAS_arxmlElementValue inArgument_element,
                                   GALGAS_lstring inArgument_objectName,
                                   GALGAS_lbool & outArgument_multiple,
                                   C_Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_multiple.drop () ; // Release 'out' argument
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_element.ptr (), GALGAS_string ("UPPER-MULTIPLICITY-INFINITE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1841)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_smultiple_65106 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_element.ptr (), GALGAS_string ("UPPER-MULTIPLICITY-INFINITE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1842)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        GALGAS_bool test_2 = GALGAS_bool (kIsEqual, var_smultiple_65106.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1844)).objectCompare (GALGAS_string ("TRUE"))) ;
        if (kBoolTrue != test_2.boolEnum ()) {
          test_2 = GALGAS_bool (kIsEqual, var_smultiple_65106.readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
        }
        test_1 = test_2.boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (true), var_smultiple_65106.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1846)) ;
          {
          routine_displayOil (GALGAS_string ("[]"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1847)) ;
          }
        }
      }
      if (kBoolFalse == test_1) {
        outArgument_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (false), var_smultiple_65106.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1849)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    outArgument_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (false), inArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1852)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlPopSign'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlPopSign (GALGAS_lstring & ioArgument_value,
                           GALGAS_bool & outArgument_sign,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_sign.drop () ; // Release 'out' argument
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, ioArgument_value.readProperty_string ().getter_characterAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1861)).objectCompare (GALGAS_char (TO_UNICODE (45)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_sign = GALGAS_bool (true) ;
      ioArgument_value.setter_setString (ioArgument_value.readProperty_string ().getter_subStringFromIndex (GALGAS_uint (uint32_t (1U)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1863)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1863)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, ioArgument_value.readProperty_string ().getter_characterAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1864)).objectCompare (GALGAS_char (TO_UNICODE (43)))).boolEnum () ;
      if (kBoolTrue == test_1) {
        outArgument_sign = GALGAS_bool (false) ;
        ioArgument_value.setter_setString (ioArgument_value.readProperty_string ().getter_subStringFromIndex (GALGAS_uint (uint32_t (1U)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1866)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1866)) ;
      }
    }
    if (kBoolFalse == test_1) {
      outArgument_sign = GALGAS_bool (false) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlGetWithAuto'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlGetWithAuto (GALGAS_arxmlElementValue inArgument_parameter,
                               GALGAS_bool & outArgument_withAuto,
                               C_Compiler * inCompiler
                               COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_withAuto.drop () ; // Release 'out' argument
  outArgument_withAuto = GALGAS_bool (false) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("WITH-AUTO"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1877)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_autoString_66015 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("WITH-AUTO"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1878)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        GALGAS_bool test_2 = GALGAS_bool (kIsEqual, var_autoString_66015.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1879)).objectCompare (GALGAS_string ("TRUE"))) ;
        if (kBoolTrue != test_2.boolEnum ()) {
          test_2 = GALGAS_bool (kIsEqual, var_autoString_66015.readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
        }
        test_1 = test_2.boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_withAuto = GALGAS_bool (true) ;
          {
          routine_displayOil (GALGAS_string (" WITH_AUTO"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1882)) ;
          }
        }
      }
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlGetName'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlGetName (GALGAS_arxmlElementValue inArgument_parameter,
                           GALGAS_lstring & outArgument_objectName,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_objectName = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1892)) ;
  outArgument_objectName.setter_setString (outArgument_objectName.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1893)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1893)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlInsertObjectAttribute'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlInsertObjectAttribute (GALGAS_implementationObjectMap & ioArgument_objectAttributes,
                                         GALGAS_lstring inArgument_attributeName,
                                         GALGAS_impType inArgument_type,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = ioArgument_objectAttributes.getter_hasKey (inArgument_attributeName.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1901)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_impType var_previousType_66654 ;
      ioArgument_objectAttributes.method_get (inArgument_attributeName, var_previousType_66654, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1903)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = var_previousType_66654.readProperty_multiple ().boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_object_5F_t var_previousDefaultValue_66996 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) var_previousType_66654.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1909)) ;
          GALGAS_object_5F_t var_defaultValue_67062 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) inArgument_type.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1910)) ;
          GALGAS_bool var_oneIsMultiple_67113 = GALGAS_bool (false) ;
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            test_2 = GALGAS_bool (var_previousDefaultValue_66996.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute).boolEnum () ;
            if (kBoolTrue == test_2) {
              var_oneIsMultiple_67113 = GALGAS_bool (true) ;
            }
          }
          if (kBoolFalse == test_2) {
            enumGalgasBool test_3 = kBoolTrue ;
            if (kBoolTrue == test_3) {
              test_3 = GALGAS_bool (var_defaultValue_67062.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute).boolEnum () ;
              if (kBoolTrue == test_3) {
                var_oneIsMultiple_67113 = GALGAS_bool (true) ;
              }
            }
          }
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = var_oneIsMultiple_67113.boolEnum () ;
            if (kBoolTrue == test_4) {
              GALGAS_identifierList var_aList_67516 = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1921)) ;
              GALGAS_lstring var_desc_67551 = function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1922)) ;
              GALGAS_location var_location_67595 = GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1923)) ;
              if (var_previousDefaultValue_66996.isValid ()) {
                if (var_previousDefaultValue_66996.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
                  GALGAS_multipleAttribute cast_67721_multiAttribute ((cPtr_multipleAttribute *) var_previousDefaultValue_66996.ptr ()) ;
                  var_aList_67516 = cast_67721_multiAttribute.readProperty_items () ;
                  var_desc_67551 = cast_67721_multiAttribute.readProperty_oil_5F_desc () ;
                  var_location_67595 = cast_67721_multiAttribute.readProperty_location () ;
                }
              }
              if (var_defaultValue_67062.isValid ()) {
                if (var_defaultValue_67062.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
                  GALGAS_multipleAttribute cast_67981_multiAttribute ((cPtr_multipleAttribute *) var_defaultValue_67062.ptr ()) ;
                  var_aList_67516.plusAssign_operation(cast_67981_multiAttribute.readProperty_items (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1936)) ;
                  enumGalgasBool test_5 = kBoolTrue ;
                  if (kBoolTrue == test_5) {
                    test_5 = GALGAS_bool (kIsEqual, var_desc_67551.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
                    if (kBoolTrue == test_5) {
                      var_desc_67551 = cast_67981_multiAttribute.readProperty_oil_5F_desc () ;
                    }
                  }
                  enumGalgasBool test_6 = kBoolTrue ;
                  if (kBoolTrue == test_6) {
                    test_6 = GALGAS_bool (kIsEqual, var_location_67595.objectCompare (GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1940)))).boolEnum () ;
                    if (kBoolTrue == test_6) {
                      var_location_67595 = cast_67981_multiAttribute.readProperty_location () ;
                    }
                  }
                }
              }
              GALGAS_object_5F_t var_newDefault_68314 = GALGAS_multipleAttribute::constructor_new (var_desc_67551, var_location_67595, var_aList_67516  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1946)) ;
              {
              inArgument_type.insulate (HERE) ;
              cPtr_impType * ptr_68416 = (cPtr_impType *) inArgument_type.ptr () ;
              callExtensionSetter_setDefValue ((cPtr_impType *) ptr_68416, var_newDefault_68314, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1949)) ;
              }
              {
              GALGAS_impType joker_68491 ; // Joker input parameter
              ioArgument_objectAttributes.setter_del (inArgument_attributeName, joker_68491, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1951)) ;
              }
              {
              ioArgument_objectAttributes.setter_put (inArgument_attributeName, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1952)) ;
              }
            }
          }
        }
      }
      enumGalgasBool test_7 = kBoolTrue ;
      if (kBoolTrue == test_7) {
        test_7 = function_checkNewTypeWithinPreviousType (inArgument_attributeName, var_previousType_66654, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1956)).boolEnum () ;
        if (kBoolTrue == test_7) {
          {
          GALGAS_impType joker_68775 ; // Joker input parameter
          ioArgument_objectAttributes.setter_del (inArgument_attributeName, joker_68775, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1959)) ;
          }
          {
          ioArgument_objectAttributes.setter_put (inArgument_attributeName, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1960)) ;
          }
        }
      }
    }
  }
  if (kBoolFalse == test_0) {
    {
    ioArgument_objectAttributes.setter_put (inArgument_attributeName, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1963)) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlElementNode print'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_print (const GALGAS_uint constinArgument_indentation,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_indent_3618 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 172)) ;
  inCompiler->printMessage (var_indent_3618  COMMA_SOURCE_FILE ("arxml_types.galgas", 173)) ;
  inCompiler->printMessage (GALGAS_string ("NODE \"").add_operation (this->mProperty_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 174)).add_operation (GALGAS_string ("\" "), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 174))  COMMA_SOURCE_FILE ("arxml_types.galgas", 174)) ;
  extensionMethod_print (this->mProperty_attributes, constinArgument_indentation, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 175)) ;
  inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("arxml_types.galgas", 176)) ;
  extensionMethod_print (this->mProperty_enclosedNodes, constinArgument_indentation, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 177)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlElementNode getElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_getElementsFromName (const GALGAS_string constinArgument_nodeName,
                                                        GALGAS_arxmlElementList & ioArgument_nodeList,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_nodeName.objectCompare (this->mProperty_name.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_arxmlElementNode temp_1 = this ;
      ioArgument_nodeList.addAssign_operation (temp_1  COMMA_SOURCE_FILE ("arxml_types.galgas", 185)) ;
    }
  }
  extensionMethod_getElementsFromName (this->mProperty_enclosedNodes, constinArgument_nodeName, ioArgument_nodeList, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 188)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlElementNode getSubElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_getSubElementsFromName (const GALGAS_string constinArgument_nodeName,
                                                           GALGAS_arxmlElementList & ioArgument_nodeList,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_arxmlNodeList enumerator_4188 (this->mProperty_enclosedNodes, kENUMERATION_UP) ;
  while (enumerator_4188.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (enumerator_4188.current_node (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_arxmlElementNode).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_arxmlElementNode temp_1 ;
        if (enumerator_4188.current_node (HERE).isValid ()) {
          if (NULL != dynamic_cast <const cPtr_arxmlElementNode *> (enumerator_4188.current_node (HERE).ptr ())) {
            temp_1 = (cPtr_arxmlElementNode *) enumerator_4188.current_node (HERE).ptr () ;
          }else{
            inCompiler->castError ("arxmlElementNode", enumerator_4188.current_node (HERE).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_types.galgas", 197)) ;
          }
        }
        GALGAS_arxmlElementNode var_currentElement_4300 = temp_1 ;
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = GALGAS_bool (kIsEqual, var_currentElement_4300.readProperty_name ().readProperty_string ().objectCompare (constinArgument_nodeName)).boolEnum () ;
          if (kBoolTrue == test_2) {
            ioArgument_nodeList.addAssign_operation (var_currentElement_4300  COMMA_SOURCE_FILE ("arxml_types.galgas", 199)) ;
          }
        }
      }
    }
    enumerator_4188.gotoNextObject () ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlElementNode getProperty'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_getProperty (const GALGAS_string constinArgument_nodeName,
                                                GALGAS_lstring & ioArgument_value,
                                                GALGAS_bool & ioArgument_found,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_nodeName.objectCompare (this->mProperty_name.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_arxmlElementNode temp_1 = this ;
      callExtensionMethod_getText ((cPtr_arxmlElementNode *) temp_1.ptr (), ioArgument_value, ioArgument_found, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 224)) ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 227)).boolEnum () ;
    if (kBoolTrue == test_2) {
      cEnumerator_arxmlNodeList enumerator_4983 (this->mProperty_enclosedNodes, kENUMERATION_UP) ;
      bool bool_3 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 229)).isValidAndTrue () ;
      if (enumerator_4983.hasCurrentObject () && bool_3) {
        while (enumerator_4983.hasCurrentObject () && bool_3) {
          callExtensionMethod_getProperty ((cPtr_arxmlNode *) enumerator_4983.current_node (HERE).ptr (), constinArgument_nodeName, ioArgument_value, ioArgument_found, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 231)) ;
          enumerator_4983.gotoNextObject () ;
          if (enumerator_4983.hasCurrentObject ()) {
            bool_3 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 229)).isValidAndTrue () ;
          }
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlCommentNode print'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlCommentNode::method_print (const GALGAS_uint constinArgument_indentation,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_indent_6004 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 281)) ;
  inCompiler->printMessage (var_indent_6004  COMMA_SOURCE_FILE ("arxml_types.galgas", 282)) ;
  inCompiler->printMessage (GALGAS_string ("COMMENT \"").add_operation (this->mProperty_comment.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 283)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 283))  COMMA_SOURCE_FILE ("arxml_types.galgas", 283)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlCommentNode getElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlCommentNode::method_getElementsFromName (const GALGAS_string /* constinArgument_nodeName */,
                                                        GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlCommentNode getSubElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlCommentNode::method_getSubElementsFromName (const GALGAS_string /* constinArgument_nodeName */,
                                                           GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlCommentNode getProperty'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlCommentNode::method_getProperty (const GALGAS_string /* constinArgument_nodeName */,
                                                GALGAS_lstring & /* ioArgument_value */,
                                                GALGAS_bool & /* ioArgument_found */,
                                                C_Compiler * /* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) {
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlTextNode print'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlTextNode::method_print (const GALGAS_uint constinArgument_indentation,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_indent_6761 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 316)) ;
  inCompiler->printMessage (var_indent_6761  COMMA_SOURCE_FILE ("arxml_types.galgas", 317)) ;
  inCompiler->printMessage (GALGAS_string ("TEXT \"").add_operation (this->mProperty_text.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 318)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 318))  COMMA_SOURCE_FILE ("arxml_types.galgas", 318)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlTextNode getElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlTextNode::method_getElementsFromName (const GALGAS_string /* constinArgument_nodeName */,
                                                     GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlTextNode getSubElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlTextNode::method_getSubElementsFromName (const GALGAS_string /* constinArgument_nodeName */,
                                                        GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlTextNode getProperty'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlTextNode::method_getProperty (const GALGAS_string /* constinArgument_nodeName */,
                                             GALGAS_lstring & /* ioArgument_value */,
                                             GALGAS_bool & /* ioArgument_found */,
                                             C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
}
//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'lstringhere'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_lstringhere (GALGAS_lstring & outArgument_string,
                          GALGAS_string inArgument_value,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_string.drop () ; // Release 'out' argument
  outArgument_string = GALGAS_lstring::constructor_new (inArgument_value, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1151))  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1151)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'fillLegacy'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_fillLegacy (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                         GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist var_sortedInfoList_32102 = ioArgument_classGraph.getter_keyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1158)) ;
  cEnumerator_stringlist enumerator_32152 (var_sortedInfoList_32102, kENUMERATION_UP) ;
  while (enumerator_32152.hasCurrentObject ()) {
    GALGAS_lstring var_lClassName_32215 ;
    {
    routine_lstringhere (var_lClassName_32215, enumerator_32152.current_mValue (HERE), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1161)) ;
    }
    GALGAS_arxmlMetaClass var_lClass_32255 ;
    ioArgument_classMap.method_searchKey (var_lClassName_32215, var_lClass_32255, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1163)) ;
    GALGAS_lstringlist var_fromList_32348 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1166)) ;
    {
    var_fromList_32348.setter_insertAtIndex (var_lClass_32255.readProperty_name (), GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1167)) ;
    }
    GALGAS_stringset var_empty_32427 = GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1168)) ;
    GALGAS_lstringlist var_successorList_32474 = ioArgument_classGraph.getter_accessibleNodesFrom (var_fromList_32348, var_empty_32427, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1169)) ;
    {
    var_lClass_32255.insulate (HERE) ;
    cPtr_arxmlMetaClass * ptr_32620 = (cPtr_arxmlMetaClass *) var_lClass_32255.ptr () ;
    callExtensionSetter_legacyAddParameters ((cPtr_arxmlMetaClass *) ptr_32620, ioArgument_classMap, var_successorList_32474, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1172)) ;
    }
    enumerator_32152.gotoNextObject () ;
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

//----------------------------------------------------------------------------------------------------------------------
//
//                      print_tool_help_message                                                  
//
//----------------------------------------------------------------------------------------------------------------------

static void print_tool_help_message (void) {
  co << "Compiled with GALGAS revision NUMERO_REVISION_GALGAS\n" ;
}

//----------------------------------------------------------------------------------------------------------------------

static const char * kSourceFileExtensions [] = {
  "oil",
  "OIL",
  "goilTemplate",
  "arxml",
  NULL
} ;    

//----------------------------------------------------------------------------------------------------------------------

static const char * kSourceFileHelpMessages [] = {
  "an '.oil' source file",
  "an '.OIL' source file",
  "a Goil template file",
  "an AUTOSAR arxml configuration file",
  NULL
} ;    

//----------------------------------------------------------------------------------------------------------------------

const char * projectVersionString (void) {
  return "3.1.12" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'before'
//
//----------------------------------------------------------------------------------------------------------------------

static void routine_before (C_Compiler * /* inCompiler */
                            COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'after'
//
//----------------------------------------------------------------------------------------------------------------------

static void routine_after (C_Compiler * /* inCompiler */
                           COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'programRule_0'
//
//----------------------------------------------------------------------------------------------------------------------

static void routine_programRule_5F__30_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 33)) ;
  }
  cGrammar_goil_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("goil_program.galgas", 34)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'programRule_1'
//
//----------------------------------------------------------------------------------------------------------------------

static void routine_programRule_5F__31_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 38)) ;
  }
  cGrammar_goil_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("goil_program.galgas", 39)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'programRule_2'
//
//----------------------------------------------------------------------------------------------------------------------

static void routine_programRule_5F__32_ (const GALGAS_lstring /* constinArgument_inSourceFile */,
                                         C_Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'programRule_3'
//
//----------------------------------------------------------------------------------------------------------------------

static void routine_programRule_5F__33_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 48)) ;
  }
  GALGAS_arxmlNode var_root_1357 ;
  var_root_1357.drop () ;
  cGrammar_arxml_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile, var_root_1357, GALGAS_bool (true), GALGAS_bool (true)  COMMA_SOURCE_FILE ("goil_program.galgas", 49)) ;
  callExtensionMethod_print ((cPtr_arxmlNode *) var_root_1357.ptr (), GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("goil_program.galgas", 53)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//                      M A I N    F O R    L I B P M                                            
//
//----------------------------------------------------------------------------------------------------------------------

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
    }catch (const ::std::exception & e) {
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


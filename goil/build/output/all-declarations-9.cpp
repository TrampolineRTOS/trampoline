#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-9.h"

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlEnum::getter_desc (const GALGAS_uint constinArgument_tab,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 744)).add_operation (GALGAS_string ("enum: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 744)).add_operation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 745)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 745)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlEnum::getter_string (C_Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlEnum::getter_lstring (C_Compiler */* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (this->mProperty_value, this->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 751)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlEnum::getter_bool (C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an enum to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 755)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlEnum::getter_int (C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an enum to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 759)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlEnum::getter_float (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an enum to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 763)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_plusOp (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 767)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_minusOp (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 770)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_notOp (C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 773)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 776)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 779)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 782)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 785)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 788)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 791)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 794)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 797)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 800)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 803)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlEnum).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlEnum temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlEnum *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlEnum *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlEnum", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 810)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 809)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 807)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("enum expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 813)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlEnum).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlEnum temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlEnum *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlEnum *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlEnum", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 821)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 820)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 818)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("enum expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 824)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_gtOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 828)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_geOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 831)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_ltOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 834)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_leOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 837)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlEnum::getter_embeddedType (C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 842)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlEnum addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlEnum::method_addMyValue (GALGAS_objectlist & /* ioArgument_objectList */,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 847)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 861)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 861)) ;
      }
      const GALGAS_gtlEnum temp_1 = this ;
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 863)), callExtensionGetter_string ((const cPtr_gtlEnum *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 863))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 862)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 866)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 866)) ;
        }
        const GALGAS_gtlEnum temp_3 = this ;
        result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 868)), temp_3.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 868))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 867)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_4) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 871)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 871)) ;
          }
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 873)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 872)) ;
        }
      }
      if (kBoolFalse == test_4) {
        enumGalgasBool test_5 = kBoolTrue ;
        if (kBoolTrue == test_5) {
          test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_5) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 876)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 876)) ;
            }
            result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 878)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 877)) ;
          }
        }
        if (kBoolFalse == test_5) {
          enumGalgasBool test_6 = kBoolTrue ;
          if (kBoolTrue == test_6) {
            test_6 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 880)).boolEnum () ;
            if (kBoolTrue == test_6) {
              const GALGAS_gtlEnum temp_7 = this ;
              result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 881)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_7, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 881)) ;
            }
          }
          if (kBoolFalse == test_6) {
            enumGalgasBool test_8 = kBoolTrue ;
            if (kBoolTrue == test_8) {
              test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_8) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 889)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 889)) ;
                }
                result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 891)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 891))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 890)) ;
              }
            }
            if (kBoolFalse == test_8) {
              TC_Array <C_FixItDescription> fixItArray9 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 894)).add_operation (GALGAS_string ("' for enum target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 894)), fixItArray9  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 894)) ;
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
//Overriding extension setter '@gtlEnum performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlEnum_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlEnum * object = (cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 908)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 908)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 909)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 909)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 909)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 909)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 909)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_29114 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_29114.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 910)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 910)) ;
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
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 913)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 913)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 915)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlEnum temp_4 = object ;
          GALGAS_gtlData var_copy_29422 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 917)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_29422, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 917)) ;
          GALGAS_gtlEnum temp_5 ;
          if (var_copy_29422.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlEnum *> (var_copy_29422.ptr ())) {
              temp_5 = (cPtr_gtlEnum *) var_copy_29422.ptr () ;
            }else{
              inCompiler->castError ("gtlEnum", var_copy_29422.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 924)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_29422.readProperty_where () ;
          object->mProperty_meta = var_copy_29422.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 928)).add_operation (GALGAS_string ("' for enum target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 928)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 928)) ;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlEnum_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                                      extensionSetter_gtlEnum_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlEnum_performSetter (defineExtensionSetter_gtlEnum_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlChar::getter_desc (const GALGAS_uint constinArgument_tab,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 941)).add_operation (GALGAS_string ("char: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 941)).add_operation (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 942)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 942)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 942)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlChar::getter_string (C_Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 945)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlChar::getter_lstring (C_Compiler */* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 948)), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 948)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlChar::getter_bool (C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a char to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 952)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlChar::getter_int (C_Compiler */* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  result_result = this->mProperty_value.getter_uint (SOURCE_FILE ("gtl_data_types.galgas", 956)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 956)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlChar::getter_float (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a char to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 960)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_plusOp (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 964)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_minusOp (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 968)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_notOp (C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 972)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 976)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 980)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 984)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 988)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 992)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 996)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1000)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1004)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1008)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1012)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1020)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1019)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1017)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1023)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1023)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1032)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1031)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1029)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1035)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1035)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1044)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1043)), GALGAS_bool (kIsStrictSup, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1041)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1047)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1047)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1056)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1055)), GALGAS_bool (kIsSupOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1053)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1059)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1068)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1067)), GALGAS_bool (kIsStrictInf, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1065)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1071)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1080)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1079)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1077)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1083)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlChar::getter_embeddedType (C_Compiler */* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_char) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlChar addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlChar::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                      C_Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 1094))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1094)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1108)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1108)) ;
      }
      const GALGAS_gtlChar temp_1 = this ;
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1110)), callExtensionGetter_string ((const cPtr_gtlChar *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1110))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1109)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("isAlnum").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1113)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1113)) ;
        }
        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1115)), this->mProperty_value.getter_isalnum (SOURCE_FILE ("gtl_data_types.galgas", 1115))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1114)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("isCntrl").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1118)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1118)) ;
          }
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1120)), this->mProperty_value.getter_iscntrl (SOURCE_FILE ("gtl_data_types.galgas", 1120))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1119)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isDigit").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1123)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1123)) ;
            }
            result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1125)), this->mProperty_value.getter_isdigit (SOURCE_FILE ("gtl_data_types.galgas", 1125))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1124)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("isAlpha").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_5) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1128)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1128)) ;
              }
              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1130)), this->mProperty_value.getter_isalpha (SOURCE_FILE ("gtl_data_types.galgas", 1130))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1129)) ;
            }
          }
          if (kBoolFalse == test_5) {
            enumGalgasBool test_6 = kBoolTrue ;
            if (kBoolTrue == test_6) {
              test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("isLower").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_6) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1133)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1133)) ;
                }
                result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1135)), this->mProperty_value.getter_islower (SOURCE_FILE ("gtl_data_types.galgas", 1135))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1134)) ;
              }
            }
            if (kBoolFalse == test_6) {
              enumGalgasBool test_7 = kBoolTrue ;
              if (kBoolTrue == test_7) {
                test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("isUpper").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                if (kBoolTrue == test_7) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1138)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1138)) ;
                  }
                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1140)), this->mProperty_value.getter_isupper (SOURCE_FILE ("gtl_data_types.galgas", 1140))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1139)) ;
                }
              }
              if (kBoolFalse == test_7) {
                enumGalgasBool test_8 = kBoolTrue ;
                if (kBoolTrue == test_8) {
                  test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("isXDigit").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_8) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1143)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1143)) ;
                    }
                    result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1145)), this->mProperty_value.getter_isxdigit (SOURCE_FILE ("gtl_data_types.galgas", 1145))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1144)) ;
                  }
                }
                if (kBoolFalse == test_8) {
                  enumGalgasBool test_9 = kBoolTrue ;
                  if (kBoolTrue == test_9) {
                    test_9 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                    if (kBoolTrue == test_9) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1148)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1148)) ;
                      }
                      const GALGAS_gtlChar temp_10 = this ;
                      result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1150)), temp_10.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 1150))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1149)) ;
                    }
                  }
                  if (kBoolFalse == test_9) {
                    enumGalgasBool test_11 = kBoolTrue ;
                    if (kBoolTrue == test_11) {
                      test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                      if (kBoolTrue == test_11) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1153)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1153)) ;
                        }
                        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1155)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1154)) ;
                      }
                    }
                    if (kBoolFalse == test_11) {
                      enumGalgasBool test_12 = kBoolTrue ;
                      if (kBoolTrue == test_12) {
                        test_12 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                        if (kBoolTrue == test_12) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1158)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1158)) ;
                          }
                          result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1160)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1159)) ;
                        }
                      }
                      if (kBoolFalse == test_12) {
                        enumGalgasBool test_13 = kBoolTrue ;
                        if (kBoolTrue == test_13) {
                          test_13 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1162)).boolEnum () ;
                          if (kBoolTrue == test_13) {
                            const GALGAS_gtlChar temp_14 = this ;
                            result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1163)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_14, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1163)) ;
                          }
                        }
                        if (kBoolFalse == test_13) {
                          enumGalgasBool test_15 = kBoolTrue ;
                          if (kBoolTrue == test_15) {
                            test_15 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                            if (kBoolTrue == test_15) {
                              {
                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1171)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1171)) ;
                              }
                              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1173)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1173))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1172)) ;
                            }
                          }
                          if (kBoolFalse == test_15) {
                            TC_Array <C_FixItDescription> fixItArray16 ;
                            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1176)).add_operation (GALGAS_string ("' for char target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1176)), fixItArray16  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1176)) ;
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
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlChar performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlChar_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlChar * object = (cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1190)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1190)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1191)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1191)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1191)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1191)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1191)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_37580 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_37580.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1192)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1192)) ;
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
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1195)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1195)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1197)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlChar temp_4 = object ;
          GALGAS_gtlData var_copy_37888 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1199)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_37888, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1199)) ;
          GALGAS_gtlChar temp_5 ;
          if (var_copy_37888.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlChar *> (var_copy_37888.ptr ())) {
              temp_5 = (cPtr_gtlChar *) var_copy_37888.ptr () ;
            }else{
              inCompiler->castError ("gtlChar", var_copy_37888.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1206)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_37888.readProperty_where () ;
          object->mProperty_meta = var_copy_37888.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1210)).add_operation (GALGAS_string ("' for char target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1210)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1210)) ;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlChar_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                                      extensionSetter_gtlChar_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlChar_performSetter (defineExtensionSetter_gtlChar_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlInt::getter_desc (const GALGAS_uint constinArgument_tab,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1223)).add_operation (GALGAS_string ("integer: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1223)).add_operation (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1224)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1224)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1224)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlInt::getter_string (C_Compiler */* inCompiler */
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1227)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlInt::getter_lstring (C_Compiler */* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1230)), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1230)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlInt::getter_bool (C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an int to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1234)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlInt::getter_int (C_Compiler */* inCompiler */
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlInt::getter_float (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  result_result = this->mProperty_value.getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1242)).getter_double (SOURCE_FILE ("gtl_data_types.galgas", 1242)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_plusOp (C_Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  const GALGAS_gtlInt temp_0 = this ;
  result_result = temp_0 ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_minusOp (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1248)), this->mProperty_value.operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1248))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1248)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_notOp (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1252)), this->mProperty_value.operator_tilde (SOURCE_FILE ("gtl_data_types.galgas", 1252))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1252)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_addOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1260)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1259)), this->mProperty_value.add_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1260))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1257)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("*int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1263)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_subOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1272)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1271)), this->mProperty_value.substract_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1272))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1269)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1275)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_mulOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1284)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1283)), this->mProperty_value.multiply_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1284))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1281)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1287)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_divOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1296)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1295)), this->mProperty_value.divide_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1296))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1293)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1299)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_modOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1308)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1307)), this->mProperty_value.modulo_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1308))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1305)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1311)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_andOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1320)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1319)), this->mProperty_value.operator_and (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1320))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1317)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1323)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_orOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1332)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1331)), this->mProperty_value.operator_or (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1332))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1329)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1335)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_xorOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1344)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1343)), this->mProperty_value.operator_xor (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1344))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1341)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1347)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_slOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1353)) ;
        }
      }
      GALGAS_bigint var_r_41727 = temp_1.readProperty_value () ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsSupOrEqual, var_r_41727.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1354)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          GALGAS_gtlInt temp_3 ;
          if (constinArgument_right.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
              temp_3 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
            }else{
              inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1358)) ;
            }
          }
          result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1357)), this->mProperty_value.left_shift_operation (temp_3.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1358)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1358))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1355)) ;
        }
      }
      if (kBoolFalse == test_2) {
        TC_Array <C_FixItDescription> fixItArray4 ;
        inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("positive int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1361)) ;
        result_result.drop () ; // Release error dropped variable
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray5 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray5  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1364)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_srOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1370)) ;
        }
      }
      GALGAS_bigint var_r_42163 = temp_1.readProperty_value () ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsSupOrEqual, var_r_42163.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1371)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1372)), this->mProperty_value.right_shift_operation (var_r_42163.getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1372)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1372))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1372)) ;
        }
      }
      if (kBoolFalse == test_2) {
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("positive int expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1374)) ;
        result_result.drop () ; // Release error dropped variable
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1377)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1386)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1385)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1383)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1389)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1398)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1397)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1395)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1401)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1410)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1409)), GALGAS_bool (kIsStrictSup, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1407)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1413)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1422)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1421)), GALGAS_bool (kIsSupOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1419)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1425)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1434)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1433)), GALGAS_bool (kIsStrictInf, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1431)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1437)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1446)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1445)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1443)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1449)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlInt::getter_embeddedType (C_Compiler */* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_bigint) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlInt addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlInt::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                     C_Compiler * /* inCompiler */
                                     COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 1460))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1460)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                  const GALGAS_gtlDataList constinArgument_arguments,
                                                  const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_library constinArgument_lib,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1474)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1474)) ;
      }
      const GALGAS_gtlInt temp_1 = this ;
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1476)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1476))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1475)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("padded").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1479)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1479)) ;
        }
        GALGAS_gtlInt temp_3 ;
        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)).isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)).ptr ())) {
            temp_3 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)).ptr () ;
          }else{
            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)) ;
          }
        }
        GALGAS_uint var_fieldSize_44977 = temp_3.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)) ;
        const GALGAS_gtlInt temp_4 = this ;
        result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1483)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_4.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1484)).getter_stringByLeftAndRightPadding (var_fieldSize_44977, GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1484))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1481)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("leftPadded").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_5) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1487)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1487)) ;
          }
          GALGAS_gtlInt temp_6 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)).ptr ())) {
              temp_6 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)).ptr () ;
            }else{
              inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)) ;
            }
          }
          GALGAS_uint var_fieldSize_45320 = temp_6.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)) ;
          const GALGAS_gtlInt temp_7 = this ;
          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1491)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_7.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1492)).getter_stringByLeftPadding (var_fieldSize_45320, GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1492))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1489)) ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_8 = kBoolTrue ;
        if (kBoolTrue == test_8) {
          test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("rightPadded").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_8) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1495)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1495)) ;
            }
            GALGAS_gtlInt temp_9 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)).isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)).ptr ())) {
                temp_9 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)).ptr () ;
              }else{
                inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)) ;
              }
            }
            GALGAS_uint var_fieldSize_45657 = temp_9.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)) ;
            const GALGAS_gtlInt temp_10 = this ;
            result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1499)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_10.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1500)).getter_stringByRightPadding (var_fieldSize_45657, GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1500))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1497)) ;
          }
        }
        if (kBoolFalse == test_8) {
          enumGalgasBool test_11 = kBoolTrue ;
          if (kBoolTrue == test_11) {
            test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("hexString").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_11) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1503)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1503)) ;
              }
              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1505)), this->mProperty_value.getter_hexString (SOURCE_FILE ("gtl_data_types.galgas", 1505))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1504)) ;
            }
          }
          if (kBoolFalse == test_11) {
            enumGalgasBool test_12 = kBoolTrue ;
            if (kBoolTrue == test_12) {
              test_12 = GALGAS_bool (kIsEqual, GALGAS_string ("xString").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_12) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1508)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1508)) ;
                }
                result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1510)), this->mProperty_value.getter_xString (SOURCE_FILE ("gtl_data_types.galgas", 1510))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1509)) ;
              }
            }
            if (kBoolFalse == test_12) {
              enumGalgasBool test_13 = kBoolTrue ;
              if (kBoolTrue == test_13) {
                test_13 = GALGAS_bool (kIsEqual, GALGAS_string ("numberOfBytes").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                if (kBoolTrue == test_13) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1513)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1513)) ;
                  }
                  result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1516)), this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1517)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1517)).substract_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517)).divide_operation (GALGAS_bigint ("8", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517)).add_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1514)) ;
                }
              }
              if (kBoolFalse == test_13) {
                enumGalgasBool test_14 = kBoolTrue ;
                if (kBoolTrue == test_14) {
                  test_14 = GALGAS_bool (kIsEqual, GALGAS_string ("signedNumberOfBytes").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_14) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1520)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1520)) ;
                    }
                    result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1523)), this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1524)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1524)).substract_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524)).divide_operation (GALGAS_bigint ("8", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524)).add_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1521)) ;
                  }
                }
                if (kBoolFalse == test_14) {
                  enumGalgasBool test_15 = kBoolTrue ;
                  if (kBoolTrue == test_15) {
                    test_15 = GALGAS_bool (kIsEqual, GALGAS_string ("numberOfBits").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                    if (kBoolTrue == test_15) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1527)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1527)) ;
                      }
                      result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1530)), this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1531)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1531))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1528)) ;
                    }
                  }
                  if (kBoolFalse == test_15) {
                    enumGalgasBool test_16 = kBoolTrue ;
                    if (kBoolTrue == test_16) {
                      test_16 = GALGAS_bool (kIsEqual, GALGAS_string ("signedNumberOfBits").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                      if (kBoolTrue == test_16) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1534)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1534)) ;
                        }
                        result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1537)), this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1538)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1538))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1535)) ;
                      }
                    }
                    if (kBoolFalse == test_16) {
                      enumGalgasBool test_17 = kBoolTrue ;
                      if (kBoolTrue == test_17) {
                        test_17 = GALGAS_bool (kIsEqual, GALGAS_string ("sign").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                        if (kBoolTrue == test_17) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1541)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1541)) ;
                          }
                          result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1544)), this->mProperty_value.getter_sign (SOURCE_FILE ("gtl_data_types.galgas", 1545)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1545))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1542)) ;
                        }
                      }
                      if (kBoolFalse == test_17) {
                        enumGalgasBool test_18 = kBoolTrue ;
                        if (kBoolTrue == test_18) {
                          test_18 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInByte").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                          if (kBoolTrue == test_18) {
                            {
                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1548)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1548)) ;
                            }
                            result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1551)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1552)).objectCompare (GALGAS_uint (uint32_t (8U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1549)) ;
                          }
                        }
                        if (kBoolFalse == test_18) {
                          enumGalgasBool test_19 = kBoolTrue ;
                          if (kBoolTrue == test_19) {
                            test_19 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInByte").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                            if (kBoolTrue == test_19) {
                              {
                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1555)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1555)) ;
                              }
                              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1558)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1559)).objectCompare (GALGAS_uint (uint32_t (8U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1556)) ;
                            }
                          }
                          if (kBoolFalse == test_19) {
                            enumGalgasBool test_20 = kBoolTrue ;
                            if (kBoolTrue == test_20) {
                              test_20 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInShort").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                              if (kBoolTrue == test_20) {
                                {
                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1562)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1562)) ;
                                }
                                result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1565)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1566)).objectCompare (GALGAS_uint (uint32_t (16U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1563)) ;
                              }
                            }
                            if (kBoolFalse == test_20) {
                              enumGalgasBool test_21 = kBoolTrue ;
                              if (kBoolTrue == test_21) {
                                test_21 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInShort").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                if (kBoolTrue == test_21) {
                                  {
                                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1569)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1569)) ;
                                  }
                                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1572)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1573)).objectCompare (GALGAS_uint (uint32_t (16U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1570)) ;
                                }
                              }
                              if (kBoolFalse == test_21) {
                                enumGalgasBool test_22 = kBoolTrue ;
                                if (kBoolTrue == test_22) {
                                  test_22 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInLong").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                  if (kBoolTrue == test_22) {
                                    {
                                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1576)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1576)) ;
                                    }
                                    result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1579)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1580)).objectCompare (GALGAS_uint (uint32_t (32U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1577)) ;
                                  }
                                }
                                if (kBoolFalse == test_22) {
                                  enumGalgasBool test_23 = kBoolTrue ;
                                  if (kBoolTrue == test_23) {
                                    test_23 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInLong").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                    if (kBoolTrue == test_23) {
                                      {
                                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1583)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1583)) ;
                                      }
                                      result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1586)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1587)).objectCompare (GALGAS_uint (uint32_t (32U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1584)) ;
                                    }
                                  }
                                  if (kBoolFalse == test_23) {
                                    enumGalgasBool test_24 = kBoolTrue ;
                                    if (kBoolTrue == test_24) {
                                      test_24 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInLongLong").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                      if (kBoolTrue == test_24) {
                                        {
                                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1590)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1590)) ;
                                        }
                                        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1593)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1594)).objectCompare (GALGAS_uint (uint32_t (64U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1591)) ;
                                      }
                                    }
                                    if (kBoolFalse == test_24) {
                                      enumGalgasBool test_25 = kBoolTrue ;
                                      if (kBoolTrue == test_25) {
                                        test_25 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInLongLong").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                        if (kBoolTrue == test_25) {
                                          {
                                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1597)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1597)) ;
                                          }
                                          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1600)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1601)).objectCompare (GALGAS_uint (uint32_t (64U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1598)) ;
                                        }
                                      }
                                      if (kBoolFalse == test_25) {
                                        enumGalgasBool test_26 = kBoolTrue ;
                                        if (kBoolTrue == test_26) {
                                          test_26 = GALGAS_bool (kIsEqual, GALGAS_string ("abs").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                          if (kBoolTrue == test_26) {
                                            {
                                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1604)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1604)) ;
                                            }
                                            result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1607)), this->mProperty_value.getter_abs (SOURCE_FILE ("gtl_data_types.galgas", 1608))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1605)) ;
                                          }
                                        }
                                        if (kBoolFalse == test_26) {
                                          enumGalgasBool test_27 = kBoolTrue ;
                                          if (kBoolTrue == test_27) {
                                            test_27 = GALGAS_bool (kIsEqual, GALGAS_string ("bitAtIndex").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                            if (kBoolTrue == test_27) {
                                              {
                                              routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1611)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1611)) ;
                                              }
                                              GALGAS_gtlInt temp_28 ;
                                              if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)).isValid ()) {
                                                if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)).ptr ())) {
                                                  temp_28 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)).ptr () ;
                                                }else{
                                                  inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)) ;
                                                }
                                              }
                                              GALGAS_uint var_index_49861 = temp_28.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)) ;
                                              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1615)), this->mProperty_value.getter_bitAtIndex (var_index_49861 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1616))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1613)) ;
                                            }
                                          }
                                          if (kBoolFalse == test_27) {
                                            enumGalgasBool test_29 = kBoolTrue ;
                                            if (kBoolTrue == test_29) {
                                              test_29 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                              if (kBoolTrue == test_29) {
                                                {
                                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1619)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1619)) ;
                                                }
                                                const GALGAS_gtlInt temp_30 = this ;
                                                result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1621)), temp_30.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 1621))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1620)) ;
                                              }
                                            }
                                            if (kBoolFalse == test_29) {
                                              enumGalgasBool test_31 = kBoolTrue ;
                                              if (kBoolTrue == test_31) {
                                                test_31 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                if (kBoolTrue == test_31) {
                                                  {
                                                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1624)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1624)) ;
                                                  }
                                                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1626)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1625)) ;
                                                }
                                              }
                                              if (kBoolFalse == test_31) {
                                                enumGalgasBool test_32 = kBoolTrue ;
                                                if (kBoolTrue == test_32) {
                                                  test_32 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                  if (kBoolTrue == test_32) {
                                                    {
                                                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1629)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1629)) ;
                                                    }
                                                    result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1631)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1630)) ;
                                                  }
                                                }
                                                if (kBoolFalse == test_32) {
                                                  enumGalgasBool test_33 = kBoolTrue ;
                                                  if (kBoolTrue == test_33) {
                                                    test_33 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1633)).boolEnum () ;
                                                    if (kBoolTrue == test_33) {
                                                      const GALGAS_gtlInt temp_34 = this ;
                                                      result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1634)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_34, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1634)) ;
                                                    }
                                                  }
                                                  if (kBoolFalse == test_33) {
                                                    enumGalgasBool test_35 = kBoolTrue ;
                                                    if (kBoolTrue == test_35) {
                                                      test_35 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                      if (kBoolTrue == test_35) {
                                                        {
                                                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1642)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1642)) ;
                                                        }
                                                        result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1644)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1644))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1643)) ;
                                                      }
                                                    }
                                                    if (kBoolFalse == test_35) {
                                                      TC_Array <C_FixItDescription> fixItArray36 ;
                                                      inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1647)).add_operation (GALGAS_string ("' for int target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1647)), fixItArray36  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1647)) ;
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
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlInt performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlInt_performSetter (cPtr_gtlData * inObject,
                                                  const GALGAS_lstring constinArgument_methodName,
                                                  const GALGAS_gtlDataList constinArgument_arguments,
                                                  const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_library constinArgument_lib,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlInt * object = (cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("setBitAtIndex"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_boolIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1661)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1661)) ;
      }
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)).ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)).ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)) ;
        }
      }
      GALGAS_bool var_bit_51573 = temp_1.readProperty_value () ;
      GALGAS_gtlInt temp_2 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)).ptr ())) {
          temp_2 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)).ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)) ;
        }
      }
      GALGAS_uint var_index_51640 = temp_2.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)) ;
      {
      object->mProperty_value.setter_setBitAtIndex (var_bit_51573, var_index_51640 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1664)) ;
      }
      object->mProperty_where = constinArgument_methodName.readProperty_location () ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("complementBitAtIndex"))).boolEnum () ;
      if (kBoolTrue == test_3) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1667)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1667)) ;
        }
        GALGAS_gtlInt temp_4 ;
        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)).isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)).ptr ())) {
            temp_4 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)).ptr () ;
          }else{
            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)) ;
          }
        }
        GALGAS_uint var_index_51895 = temp_4.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)) ;
        {
        object->mProperty_value.setter_complementBitAtIndex (var_index_51895 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1669)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_3) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_5) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1672)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1672)) ;
          }
          GALGAS_gtlString temp_6 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1673)).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1673)).ptr ())) {
              temp_6 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1673)).ptr () ;
            }else{
              inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1673)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1673)) ;
            }
          }
          GALGAS_gtlString var_descriptionToSet_52145 = temp_6 ;
          {
          object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_52145.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1674)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1674)) ;
          }
          object->mProperty_where = constinArgument_methodName.readProperty_location () ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_7 = kBoolTrue ;
        if (kBoolTrue == test_7) {
          test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_7) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1677)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1677)) ;
            }
            object->mProperty_where = constinArgument_methodName.readProperty_location () ;
          }
        }
        if (kBoolFalse == test_7) {
          enumGalgasBool test_8 = kBoolTrue ;
          if (kBoolTrue == test_8) {
            test_8 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1679)).boolEnum () ;
            if (kBoolTrue == test_8) {
              const GALGAS_gtlInt temp_9 = object ;
              GALGAS_gtlData var_copy_52452 = temp_9 ;
              callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1681)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_52452, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1681)) ;
              GALGAS_gtlInt temp_10 ;
              if (var_copy_52452.isValid ()) {
                if (NULL != dynamic_cast <const cPtr_gtlInt *> (var_copy_52452.ptr ())) {
                  temp_10 = (cPtr_gtlInt *) var_copy_52452.ptr () ;
                }else{
                  inCompiler->castError ("gtlInt", var_copy_52452.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1688)) ;
                }
              }
              object->mProperty_value = temp_10.readProperty_value () ;
              object->mProperty_where = var_copy_52452.readProperty_where () ;
              object->mProperty_meta = var_copy_52452.readProperty_meta () ;
            }
          }
          if (kBoolFalse == test_8) {
            TC_Array <C_FixItDescription> fixItArray11 ;
            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1692)).add_operation (GALGAS_string ("' for int target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1692)), fixItArray11  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1692)) ;
          }
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlInt_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                                      extensionSetter_gtlInt_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlInt_performSetter (defineExtensionSetter_gtlInt_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlFloat::getter_desc (const GALGAS_uint constinArgument_tab,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1705)).add_operation (GALGAS_string ("float: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1705)).add_operation (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1706)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1706)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1706)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlFloat::getter_string (C_Compiler */* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1709)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlFloat::getter_lstring (C_Compiler */* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1712)), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1712)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlFloat::getter_bool (C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a float to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1716)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlFloat::getter_int (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  result_result = this->mProperty_value.getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1720)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1720)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlFloat::getter_float (C_Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_plusOp (C_Compiler */* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  const GALGAS_gtlFloat temp_0 = this ;
  result_result = temp_0 ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_minusOp (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlFloat::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1730)), this->mProperty_value.operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1730))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1730)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_notOp (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1734)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_addOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1742)) ;
        }
      }
      result_result = GALGAS_gtlFloat::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1741)), this->mProperty_value.add_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1742))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1739)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1745)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_subOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1754)) ;
        }
      }
      result_result = GALGAS_gtlFloat::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1753)), this->mProperty_value.substract_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1754))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1751)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1757)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_mulOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1766)) ;
        }
      }
      result_result = GALGAS_gtlFloat::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1765)), this->mProperty_value.multiply_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1766))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1763)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1769)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_divOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1778)) ;
        }
      }
      result_result = GALGAS_gtlFloat::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1777)), this->mProperty_value.divide_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1778))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1775)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1781)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1786)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1790)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1794)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1798)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1802)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1806)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1814)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1813)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1811)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1817)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1826)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1825)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1823)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1829)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1838)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1837)), GALGAS_bool (kIsStrictSup, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1835)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1841)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1850)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1849)), GALGAS_bool (kIsSupOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1847)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1853)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1862)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1861)), GALGAS_bool (kIsStrictInf, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1859)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1865)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1874)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1873)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1871)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1877)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlFloat::getter_embeddedType (C_Compiler */* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_double) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlFloat addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlFloat::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                       C_Compiler * /* inCompiler */
                                       COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 1888))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1888)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                    const GALGAS_gtlDataList constinArgument_arguments,
                                                    const GALGAS_gtlContext constinArgument_context,
                                                    const GALGAS_library constinArgument_lib,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1902)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1902)) ;
      }
      const GALGAS_gtlFloat temp_1 = this ;
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1904)), callExtensionGetter_string ((const cPtr_gtlFloat *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1904))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1903)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("cos").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1907)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1907)) ;
        }
        result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1909)), this->mProperty_value.getter_cos (SOURCE_FILE ("gtl_data_types.galgas", 1909))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1908)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("sin").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1912)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1912)) ;
          }
          result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1914)), this->mProperty_value.getter_sin (SOURCE_FILE ("gtl_data_types.galgas", 1914))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1913)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("tan").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1917)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1917)) ;
            }
            result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1919)), this->mProperty_value.getter_tan (SOURCE_FILE ("gtl_data_types.galgas", 1919))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1918)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("cosDegree").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_5) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1922)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1922)) ;
              }
              result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1924)), this->mProperty_value.getter_cosDegree (SOURCE_FILE ("gtl_data_types.galgas", 1924))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1923)) ;
            }
          }
          if (kBoolFalse == test_5) {
            enumGalgasBool test_6 = kBoolTrue ;
            if (kBoolTrue == test_6) {
              test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("sinDegree").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_6) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1927)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1927)) ;
                }
                result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1929)), this->mProperty_value.getter_sinDegree (SOURCE_FILE ("gtl_data_types.galgas", 1929))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1928)) ;
              }
            }
            if (kBoolFalse == test_6) {
              enumGalgasBool test_7 = kBoolTrue ;
              if (kBoolTrue == test_7) {
                test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("tanDegree").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                if (kBoolTrue == test_7) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1932)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1932)) ;
                  }
                  result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1934)), this->mProperty_value.getter_tanDegree (SOURCE_FILE ("gtl_data_types.galgas", 1934))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1933)) ;
                }
              }
              if (kBoolFalse == test_7) {
                enumGalgasBool test_8 = kBoolTrue ;
                if (kBoolTrue == test_8) {
                  test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("exp").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_8) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1937)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1937)) ;
                    }
                    result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1939)), this->mProperty_value.getter_exp (SOURCE_FILE ("gtl_data_types.galgas", 1939))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1938)) ;
                  }
                }
                if (kBoolFalse == test_8) {
                  enumGalgasBool test_9 = kBoolTrue ;
                  if (kBoolTrue == test_9) {
                    test_9 = GALGAS_bool (kIsEqual, GALGAS_string ("logn").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                    if (kBoolTrue == test_9) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1942)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1942)) ;
                      }
                      result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1944)), this->mProperty_value.getter_logn (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1944))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1943)) ;
                    }
                  }
                  if (kBoolFalse == test_9) {
                    enumGalgasBool test_10 = kBoolTrue ;
                    if (kBoolTrue == test_10) {
                      test_10 = GALGAS_bool (kIsEqual, GALGAS_string ("log2").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                      if (kBoolTrue == test_10) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1947)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1947)) ;
                        }
                        result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1949)), this->mProperty_value.getter_log_32_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1949))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1948)) ;
                      }
                    }
                    if (kBoolFalse == test_10) {
                      enumGalgasBool test_11 = kBoolTrue ;
                      if (kBoolTrue == test_11) {
                        test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("log10").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                        if (kBoolTrue == test_11) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1952)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1952)) ;
                          }
                          result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1954)), this->mProperty_value.getter_log_31__30_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1954))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1953)) ;
                        }
                      }
                      if (kBoolFalse == test_11) {
                        enumGalgasBool test_12 = kBoolTrue ;
                        if (kBoolTrue == test_12) {
                          test_12 = GALGAS_bool (kIsEqual, GALGAS_string ("sqrt").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                          if (kBoolTrue == test_12) {
                            {
                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1957)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1957)) ;
                            }
                            result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1959)), this->mProperty_value.getter_sqrt (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1959))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1958)) ;
                          }
                        }
                        if (kBoolFalse == test_12) {
                          enumGalgasBool test_13 = kBoolTrue ;
                          if (kBoolTrue == test_13) {
                            test_13 = GALGAS_bool (kIsEqual, GALGAS_string ("power").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                            if (kBoolTrue == test_13) {
                              {
                              routine_argumentsCheck (constinArgument_methodName, function_floatArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1962)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1962)) ;
                              }
                              GALGAS_gtlFloat temp_14 ;
                              if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)).isValid ()) {
                                if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)).ptr ())) {
                                  temp_14 = (cPtr_gtlFloat *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)).ptr () ;
                                }else{
                                  inCompiler->castError ("gtlFloat", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)) ;
                                }
                              }
                              GALGAS_double var_power_60701 = temp_14.readProperty_value () ;
                              result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1965)), this->mProperty_value.getter_power (var_power_60701, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1965))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1964)) ;
                            }
                          }
                          if (kBoolFalse == test_13) {
                            enumGalgasBool test_15 = kBoolTrue ;
                            if (kBoolTrue == test_15) {
                              test_15 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                              if (kBoolTrue == test_15) {
                                {
                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1968)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1968)) ;
                                }
                                const GALGAS_gtlFloat temp_16 = this ;
                                result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1970)), temp_16.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 1970))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1969)) ;
                              }
                            }
                            if (kBoolFalse == test_15) {
                              enumGalgasBool test_17 = kBoolTrue ;
                              if (kBoolTrue == test_17) {
                                test_17 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                if (kBoolTrue == test_17) {
                                  {
                                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1973)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1973)) ;
                                  }
                                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1975)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1974)) ;
                                }
                              }
                              if (kBoolFalse == test_17) {
                                enumGalgasBool test_18 = kBoolTrue ;
                                if (kBoolTrue == test_18) {
                                  test_18 = GALGAS_bool (kIsEqual, GALGAS_string ("int").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                  if (kBoolTrue == test_18) {
                                    {
                                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1978)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1978)) ;
                                    }
                                    result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1980)), this->mProperty_value.getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1980)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1980))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1979)) ;
                                  }
                                }
                                if (kBoolFalse == test_18) {
                                  enumGalgasBool test_19 = kBoolTrue ;
                                  if (kBoolTrue == test_19) {
                                    test_19 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                    if (kBoolTrue == test_19) {
                                      {
                                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1983)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1983)) ;
                                      }
                                      result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1985)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1984)) ;
                                    }
                                  }
                                  if (kBoolFalse == test_19) {
                                    enumGalgasBool test_20 = kBoolTrue ;
                                    if (kBoolTrue == test_20) {
                                      test_20 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1987)).boolEnum () ;
                                      if (kBoolTrue == test_20) {
                                        const GALGAS_gtlFloat temp_21 = this ;
                                        result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1988)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_21, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1988)) ;
                                      }
                                    }
                                    if (kBoolFalse == test_20) {
                                      enumGalgasBool test_22 = kBoolTrue ;
                                      if (kBoolTrue == test_22) {
                                        test_22 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                        if (kBoolTrue == test_22) {
                                          {
                                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1996)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1996)) ;
                                          }
                                          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1998)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1998))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1997)) ;
                                        }
                                      }
                                      if (kBoolFalse == test_22) {
                                        TC_Array <C_FixItDescription> fixItArray23 ;
                                        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2001)).add_operation (GALGAS_string ("' for float target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2001)), fixItArray23  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2001)) ;
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
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlFloat performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlFloat_performSetter (cPtr_gtlData * inObject,
                                                    const GALGAS_lstring constinArgument_methodName,
                                                    const GALGAS_gtlDataList constinArgument_arguments,
                                                    const GALGAS_gtlContext constinArgument_context,
                                                    const GALGAS_library constinArgument_lib,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlFloat * object = (cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2015)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2015)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2016)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2016)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2016)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2016)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2016)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_62587 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_62587.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2017)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2017)) ;
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
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2020)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2020)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2022)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlFloat temp_4 = object ;
          GALGAS_gtlData var_copy_62896 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2024)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_62896, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2024)) ;
          GALGAS_gtlFloat temp_5 ;
          if (var_copy_62896.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlFloat *> (var_copy_62896.ptr ())) {
              temp_5 = (cPtr_gtlFloat *) var_copy_62896.ptr () ;
            }else{
              inCompiler->castError ("gtlFloat", var_copy_62896.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2031)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_62896.readProperty_where () ;
          object->mProperty_meta = var_copy_62896.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2035)).add_operation (GALGAS_string ("' for float target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2035)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2035)) ;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlFloat_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                                      extensionSetter_gtlFloat_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlFloat_performSetter (defineExtensionSetter_gtlFloat_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlString::getter_desc (const GALGAS_uint constinArgument_tab,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2048)).add_operation (GALGAS_string ("string: \""), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2048)).add_operation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2049)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2049)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlString::getter_string (C_Compiler */* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlString::getter_lstring (C_Compiler */* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (this->mProperty_value, this->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2054)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlString::getter_bool (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a string to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2057)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlString::getter_int (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  result_result = this->mProperty_value.getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2061)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2061)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlString::getter_float (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  result_result = this->mProperty_value.getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2065)).getter_double (SOURCE_FILE ("gtl_data_types.galgas", 2065)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_plusOp (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2069)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_minusOp (C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2073)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_notOp (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2077)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_addOp (const GALGAS_gtlData constinArgument_right,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2085)) ;
        }
      }
      result_result = GALGAS_gtlString::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2084)), this->mProperty_value.add_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2085))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2082)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("string expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2088)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2093)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2097)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2101)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2105)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2109)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2113)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2117)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2121)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2125)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2133)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2132)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2130)) ;
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


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2145)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2144)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2142)) ;
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


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2157)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2156)), GALGAS_bool (kIsStrictSup, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2154)) ;
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


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2169)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2168)), GALGAS_bool (kIsSupOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2166)) ;
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


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2181)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2180)), GALGAS_bool (kIsStrictInf, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2178)) ;
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


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2193)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2192)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2190)) ;
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


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlString::getter_embeddedType (C_Compiler */* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_string) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlString addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlString::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                        C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 2207))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2207)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                     const GALGAS_gtlDataList constinArgument_arguments,
                                                     const GALGAS_gtlContext constinArgument_context,
                                                     const GALGAS_library constinArgument_lib,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("string"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2221)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2221)) ;
      }
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2223)), this->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2222)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("charAtIndex"))).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2226)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2226)) ;
        }
        GALGAS_gtlInt temp_2 ;
        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)).isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)).ptr ())) {
            temp_2 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)).ptr () ;
          }else{
            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)) ;
          }
        }
        GALGAS_uint var_index_68505 = temp_2.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)) ;
        result_result = GALGAS_gtlChar::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2229)), this->mProperty_value.getter_characterAtIndex (var_index_68505, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2229))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2228)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("indexOfChar"))).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_charArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2232)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2232)) ;
          }
          GALGAS_gtlChar temp_4 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2233)).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2233)).ptr ())) {
              temp_4 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2233)).ptr () ;
            }else{
              inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2233)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2233)) ;
            }
          }
          GALGAS_char var_lookedUpChar_68801 = temp_4.readProperty_value () ;
          GALGAS_uint var_index_68873 = GALGAS_uint (uint32_t (0U)) ;
          GALGAS_uint var_length_68897 = this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2235)) ;
          GALGAS_bool var_found_68931 = GALGAS_bool (false) ;
          if (var_length_68897.isValid ()) {
            uint32_t variant_68949 = var_length_68897.uintValue () ;
            bool loop_68949 = true ;
            while (loop_68949) {
              GALGAS_bool test_5 = var_found_68931.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2238)) ;
              if (kBoolTrue == test_5.boolEnum ()) {
                test_5 = GALGAS_bool (kIsStrictInf, var_index_68873.objectCompare (var_length_68897)) ;
              }
              loop_68949 = test_5.isValid () ;
              if (loop_68949) {
                loop_68949 = test_5.boolValue () ;
              }
              if (loop_68949 && (0 == variant_68949)) {
                loop_68949 = false ;
                inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_data_types.galgas", 2237)) ;
              }
              if (loop_68949) {
                variant_68949 -- ;
                enumGalgasBool test_6 = kBoolTrue ;
                if (kBoolTrue == test_6) {
                  test_6 = GALGAS_bool (kIsEqual, this->mProperty_value.getter_characterAtIndex (var_index_68873, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2239)).objectCompare (var_lookedUpChar_68801)).boolEnum () ;
                  if (kBoolTrue == test_6) {
                    var_found_68931 = GALGAS_bool (true) ;
                  }
                }
                if (kBoolFalse == test_6) {
                  var_index_68873.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2242)) ;
                }
              }
            }
          }
          GALGAS_bigint temp_7 ;
          const enumGalgasBool test_8 = var_found_68931.boolEnum () ;
          if (kBoolTrue == test_8) {
            temp_7 = var_index_68873.getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2248)) ;
          }else if (kBoolFalse == test_8) {
            temp_7 = GALGAS_bigint ("-1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2248)) ;
          }
          result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2247)), temp_7  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2245)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_9 = kBoolTrue ;
        if (kBoolTrue == test_9) {
          test_9 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("indexOfCharInRange"))).boolEnum () ;
          if (kBoolTrue == test_9) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_charCharArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2251)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2251)) ;
            }
            GALGAS_gtlChar temp_10 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2252)).isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2252)).ptr ())) {
                temp_10 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2252)).ptr () ;
              }else{
                inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2252)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2252)) ;
              }
            }
            GALGAS_char var_minChar_69401 = temp_10.readProperty_value () ;
            GALGAS_gtlChar temp_11 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2253)).isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2253)).ptr ())) {
                temp_11 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2253)).ptr () ;
              }else{
                inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2253)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2253)) ;
              }
            }
            GALGAS_char var_maxChar_69472 = temp_11.readProperty_value () ;
            GALGAS_uint var_index_69539 = GALGAS_uint (uint32_t (0U)) ;
            GALGAS_uint var_length_69563 = this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2255)) ;
            GALGAS_bool var_found_69597 = GALGAS_bool (false) ;
            if (var_length_69563.isValid ()) {
              uint32_t variant_69615 = var_length_69563.uintValue () ;
              bool loop_69615 = true ;
              while (loop_69615) {
                GALGAS_bool test_12 = var_found_69597.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2258)) ;
                if (kBoolTrue == test_12.boolEnum ()) {
                  test_12 = GALGAS_bool (kIsStrictInf, var_index_69539.objectCompare (var_length_69563)) ;
                }
                loop_69615 = test_12.isValid () ;
                if (loop_69615) {
                  loop_69615 = test_12.boolValue () ;
                }
                if (loop_69615 && (0 == variant_69615)) {
                  loop_69615 = false ;
                  inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_data_types.galgas", 2257)) ;
                }
                if (loop_69615) {
                  variant_69615 -- ;
                  GALGAS_char var_currentChar_69686 = this->mProperty_value.getter_characterAtIndex (var_index_69539, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2259)) ;
                  enumGalgasBool test_13 = kBoolTrue ;
                  if (kBoolTrue == test_13) {
                    GALGAS_bool test_14 = GALGAS_bool (kIsSupOrEqual, var_currentChar_69686.objectCompare (var_minChar_69401)) ;
                    if (kBoolTrue == test_14.boolEnum ()) {
                      test_14 = GALGAS_bool (kIsInfOrEqual, var_currentChar_69686.objectCompare (var_maxChar_69472)) ;
                    }
                    test_13 = test_14.boolEnum () ;
                    if (kBoolTrue == test_13) {
                      var_found_69597 = GALGAS_bool (true) ;
                    }
                  }
                  if (kBoolFalse == test_13) {
                    var_index_69539.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2263)) ;
                  }
                }
              }
            }
            GALGAS_bigint temp_15 ;
            const enumGalgasBool test_16 = var_found_69597.boolEnum () ;
            if (kBoolTrue == test_16) {
              temp_15 = var_index_69539.getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2269)) ;
            }else if (kBoolFalse == test_16) {
              temp_15 = GALGAS_bigint ("-1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2269)) ;
            }
            result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2268)), temp_15  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2266)) ;
          }
        }
        if (kBoolFalse == test_9) {
          enumGalgasBool test_17 = kBoolTrue ;
          if (kBoolTrue == test_17) {
            test_17 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("containsChar"))).boolEnum () ;
            if (kBoolTrue == test_17) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_charArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2272)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2272)) ;
              }
              GALGAS_gtlChar temp_18 ;
              if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2273)).isValid ()) {
                if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2273)).ptr ())) {
                  temp_18 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2273)).ptr () ;
                }else{
                  inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2273)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2273)) ;
                }
              }
              GALGAS_char var_lookedUpChar_70117 = temp_18.readProperty_value () ;
              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2276)), this->mProperty_value.getter_containsCharacter (var_lookedUpChar_70117 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2277))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2274)) ;
            }
          }
          if (kBoolFalse == test_17) {
            enumGalgasBool test_19 = kBoolTrue ;
            if (kBoolTrue == test_19) {
              test_19 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("containsCharInRange"))).boolEnum () ;
              if (kBoolTrue == test_19) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_charCharArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2280)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2280)) ;
                }
                GALGAS_gtlChar temp_20 ;
                if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2281)).isValid ()) {
                  if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2281)).ptr ())) {
                    temp_20 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2281)).ptr () ;
                  }else{
                    inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2281)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2281)) ;
                  }
                }
                GALGAS_char var_minChar_70449 = temp_20.readProperty_value () ;
                GALGAS_gtlChar temp_21 ;
                if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2282)).isValid ()) {
                  if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2282)).ptr ())) {
                    temp_21 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2282)).ptr () ;
                  }else{
                    inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2282)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2282)) ;
                  }
                }
                GALGAS_char var_maxChar_70520 = temp_21.readProperty_value () ;
                result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2285)), this->mProperty_value.getter_containsCharacterInRange (var_minChar_70449, var_maxChar_70520 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2286))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2283)) ;
              }
            }
            if (kBoolFalse == test_19) {
              enumGalgasBool test_22 = kBoolTrue ;
              if (kBoolTrue == test_22) {
                test_22 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("HTMLRepresentation"))).boolEnum () ;
                if (kBoolTrue == test_22) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2289)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2289)) ;
                  }
                  result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2291)), this->mProperty_value.getter_HTMLRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 2291))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2290)) ;
                }
              }
              if (kBoolFalse == test_22) {
                enumGalgasBool test_23 = kBoolTrue ;
                if (kBoolTrue == test_23) {
                  test_23 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("identifierRepresentation"))).boolEnum () ;
                  if (kBoolTrue == test_23) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2294)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2294)) ;
                    }
                    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2296)), this->mProperty_value.getter_identifierRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 2296))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2295)) ;
                  }
                }
                if (kBoolFalse == test_23) {
                  enumGalgasBool test_24 = kBoolTrue ;
                  if (kBoolTrue == test_24) {
                    test_24 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("fileExists"))).boolEnum () ;
                    if (kBoolTrue == test_24) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2299)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2299)) ;
                      }
                      result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2301)), this->mProperty_value.getter_fileExists (SOURCE_FILE ("gtl_data_types.galgas", 2301))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2300)) ;
                    }
                  }
                  if (kBoolFalse == test_24) {
                    enumGalgasBool test_25 = kBoolTrue ;
                    if (kBoolTrue == test_25) {
                      test_25 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("lowercaseString"))).boolEnum () ;
                      if (kBoolTrue == test_25) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2304)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2304)) ;
                        }
                        result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2306)), this->mProperty_value.getter_lowercaseString (SOURCE_FILE ("gtl_data_types.galgas", 2306))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2305)) ;
                      }
                    }
                    if (kBoolFalse == test_25) {
                      enumGalgasBool test_26 = kBoolTrue ;
                      if (kBoolTrue == test_26) {
                        test_26 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("length"))).boolEnum () ;
                        if (kBoolTrue == test_26) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2309)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2309)) ;
                          }
                          result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2311)), this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2311)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2311))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2310)) ;
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
                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2315)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2315)) ;
                            }
                            result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2317)), this->mProperty_value.getter_stringByCapitalizingFirstCharacter (SOURCE_FILE ("gtl_data_types.galgas", 2317))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2316)) ;
                          }
                        }
                        if (kBoolFalse == test_27) {
                          enumGalgasBool test_29 = kBoolTrue ;
                          if (kBoolTrue == test_29) {
                            test_29 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("uppercaseString"))).boolEnum () ;
                            if (kBoolTrue == test_29) {
                              {
                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2320)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2320)) ;
                              }
                              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2322)), this->mProperty_value.getter_uppercaseString (SOURCE_FILE ("gtl_data_types.galgas", 2322))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2321)) ;
                            }
                          }
                          if (kBoolFalse == test_29) {
                            enumGalgasBool test_30 = kBoolTrue ;
                            if (kBoolTrue == test_30) {
                              test_30 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("unsigned"))).boolEnum () ;
                              if (kBoolTrue == test_30) {
                                {
                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2325)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2325)) ;
                                }
                                result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2327)), this->mProperty_value.getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2327)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2327))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2326)) ;
                              }
                            }
                            if (kBoolFalse == test_30) {
                              enumGalgasBool test_31 = kBoolTrue ;
                              if (kBoolTrue == test_31) {
                                test_31 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("subStringExists"))).boolEnum () ;
                                if (kBoolTrue == test_31) {
                                  {
                                  routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2330)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2330)) ;
                                  }
                                  GALGAS_gtlString temp_32 ;
                                  if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2331)).isValid ()) {
                                    if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2331)).ptr ())) {
                                      temp_32 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2331)).ptr () ;
                                    }else{
                                      inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2331)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2331)) ;
                                    }
                                  }
                                  GALGAS_string var_subString_72671 = temp_32.readProperty_value () ;
                                  GALGAS_uint var_subStringLength_72746 = var_subString_72671.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2332)) ;
                                  GALGAS_uint var_start_72793 = GALGAS_uint (uint32_t (0U)) ;
                                  GALGAS_uint var_stop_72817 = this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2334)).substract_operation (var_subStringLength_72746, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2334)) ;
                                  GALGAS_bool var_exists_72867 = GALGAS_bool (false) ;
                                  if (this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2336)).isValid ()) {
                                    uint32_t variant_72887 = this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2336)).uintValue () ;
                                    bool loop_72887 = true ;
                                    while (loop_72887) {
                                      GALGAS_bool test_33 = var_exists_72867.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2337)) ;
                                      if (kBoolTrue == test_33.boolEnum ()) {
                                        test_33 = GALGAS_bool (kIsInfOrEqual, var_start_72793.objectCompare (var_stop_72817)) ;
                                      }
                                      loop_72887 = test_33.isValid () ;
                                      if (loop_72887) {
                                        loop_72887 = test_33.boolValue () ;
                                      }
                                      if (loop_72887 && (0 == variant_72887)) {
                                        loop_72887 = false ;
                                        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_data_types.galgas", 2336)) ;
                                      }
                                      if (loop_72887) {
                                        variant_72887 -- ;
                                        enumGalgasBool test_34 = kBoolTrue ;
                                        if (kBoolTrue == test_34) {
                                          test_34 = GALGAS_bool (kIsEqual, this->mProperty_value.getter_subString (var_start_72793, var_subStringLength_72746 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2338)).objectCompare (var_subString_72671)).boolEnum () ;
                                          if (kBoolTrue == test_34) {
                                            var_exists_72867 = GALGAS_bool (true) ;
                                          }
                                        }
                                        var_start_72793.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2341)) ;
                                      }
                                    }
                                  }
                                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2344)), var_exists_72867  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2343)) ;
                                }
                              }
                              if (kBoolFalse == test_31) {
                                enumGalgasBool test_35 = kBoolTrue ;
                                if (kBoolTrue == test_35) {
                                  test_35 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("leftSubString"))).boolEnum () ;
                                  if (kBoolTrue == test_35) {
                                    {
                                    routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2347)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2347)) ;
                                    }
                                    GALGAS_gtlInt temp_36 ;
                                    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)).isValid ()) {
                                      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)).ptr ())) {
                                        temp_36 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)).ptr () ;
                                      }else{
                                        inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)) ;
                                      }
                                    }
                                    GALGAS_uint var_index_73298 = temp_36.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)) ;
                                    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2350)), this->mProperty_value.getter_leftSubString (var_index_73298 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2350))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2349)) ;
                                  }
                                }
                                if (kBoolFalse == test_35) {
                                  enumGalgasBool test_37 = kBoolTrue ;
                                  if (kBoolTrue == test_37) {
                                    test_37 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("rightSubString"))).boolEnum () ;
                                    if (kBoolTrue == test_37) {
                                      {
                                      routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2353)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2353)) ;
                                      }
                                      GALGAS_gtlInt temp_38 ;
                                      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)).isValid ()) {
                                        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)).ptr ())) {
                                          temp_38 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)).ptr () ;
                                        }else{
                                          inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)) ;
                                        }
                                      }
                                      GALGAS_uint var_index_73595 = temp_38.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)) ;
                                      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2356)), this->mProperty_value.getter_rightSubString (var_index_73595 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2356))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2355)) ;
                                    }
                                  }
                                  if (kBoolFalse == test_37) {
                                    enumGalgasBool test_39 = kBoolTrue ;
                                    if (kBoolTrue == test_39) {
                                      test_39 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("subString"))).boolEnum () ;
                                      if (kBoolTrue == test_39) {
                                        {
                                        routine_argumentsCheck (constinArgument_methodName, function_intIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2359)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2359)) ;
                                        }
                                        GALGAS_gtlInt temp_40 ;
                                        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)).isValid ()) {
                                          if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)).ptr ())) {
                                            temp_40 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)).ptr () ;
                                          }else{
                                            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)) ;
                                          }
                                        }
                                        GALGAS_uint var_start_73892 = temp_40.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)) ;
                                        GALGAS_gtlInt temp_41 ;
                                        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)).isValid ()) {
                                          if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)).ptr ())) {
                                            temp_41 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)).ptr () ;
                                          }else{
                                            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)) ;
                                          }
                                        }
                                        GALGAS_uint var_length_73967 = temp_41.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)) ;
                                        result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2363)), this->mProperty_value.getter_subString (var_start_73892, var_length_73967 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2363))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2362)) ;
                                      }
                                    }
                                    if (kBoolFalse == test_39) {
                                      enumGalgasBool test_42 = kBoolTrue ;
                                      if (kBoolTrue == test_42) {
                                        test_42 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("reversedString"))).boolEnum () ;
                                        if (kBoolTrue == test_42) {
                                          {
                                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2366)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2366)) ;
                                          }
                                          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2368)), this->mProperty_value.getter_reversedString (SOURCE_FILE ("gtl_data_types.galgas", 2368))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2367)) ;
                                        }
                                      }
                                      if (kBoolFalse == test_42) {
                                        enumGalgasBool test_43 = kBoolTrue ;
                                        if (kBoolTrue == test_43) {
                                          test_43 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("componentsSeparatedByString"))).boolEnum () ;
                                          if (kBoolTrue == test_43) {
                                            {
                                            routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2371)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2371)) ;
                                            }
                                            GALGAS_gtlString temp_44 ;
                                            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2372)).isValid ()) {
                                              if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2372)).ptr ())) {
                                                temp_44 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2372)).ptr () ;
                                              }else{
                                                inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2372)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2372)) ;
                                              }
                                            }
                                            GALGAS_string var_separator_74502 = temp_44.readProperty_value () ;
                                            GALGAS_stringlist var_stringlist_74583 = this->mProperty_value.getter_componentsSeparatedByString (var_separator_74502 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2373)) ;
                                            GALGAS_list var_components_74653 = GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 2374)) ;
                                            cEnumerator_stringlist enumerator_74686 (var_stringlist_74583, kENUMERATION_UP) ;
                                            while (enumerator_74686.hasCurrentObject ()) {
                                              var_components_74653.addAssign_operation (GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2377)), enumerator_74686.current_mValue (HERE)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2376))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2376)) ;
                                              enumerator_74686.gotoNextObject () ;
                                            }
                                            result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2381)), var_components_74653  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2380)) ;
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
                                                routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2387)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2387)) ;
                                                }
                                                GALGAS_gtlString temp_49 ;
                                                if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2388)).isValid ()) {
                                                  if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2388)).ptr ())) {
                                                    temp_49 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2388)).ptr () ;
                                                  }else{
                                                    inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2388)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2388)) ;
                                                  }
                                                }
                                                GALGAS_string var_prefix_75154 = temp_49.readProperty_value () ;
                                                result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2391)), var_prefix_75154.add_operation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2392)).getter_stringByReplacingStringByString (GALGAS_string ("\n"), GALGAS_string ("\n").add_operation (var_prefix_75154, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2392)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2392))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2389)) ;
                                              }
                                            }
                                            if (kBoolFalse == test_48) {
                                              enumGalgasBool test_50 = kBoolTrue ;
                                              if (kBoolTrue == test_50) {
                                                test_50 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("wrap"))).boolEnum () ;
                                                if (kBoolTrue == test_50) {
                                                  {
                                                  routine_argumentsCheck (constinArgument_methodName, function_intIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2395)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2395)) ;
                                                  }
                                                  GALGAS_gtlInt temp_51 ;
                                                  if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)).isValid ()) {
                                                    if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)).ptr ())) {
                                                      temp_51 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)).ptr () ;
                                                    }else{
                                                      inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)) ;
                                                    }
                                                  }
                                                  GALGAS_uint var_width_75496 = temp_51.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)) ;
                                                  GALGAS_gtlInt temp_52 ;
                                                  if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)).isValid ()) {
                                                    if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)).ptr ())) {
                                                      temp_52 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)).ptr () ;
                                                    }else{
                                                      inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)) ;
                                                    }
                                                  }
                                                  GALGAS_uint var_shift_75571 = temp_52.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)) ;
                                                  GALGAS_string var_stringShift_75648 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), var_shift_75571  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2398)) ;
                                                  GALGAS_stringlist var_paragraphs_75730 = this->mProperty_value.getter_componentsSeparatedByString (GALGAS_string ("\n") COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2399)) ;
                                                  GALGAS_stringlist var_resultParagraphs_75805 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 2400)) ;
                                                  cEnumerator_stringlist enumerator_75846 (var_paragraphs_75730, kENUMERATION_UP) ;
                                                  while (enumerator_75846.hasCurrentObject ()) {
                                                    GALGAS_stringlist var_words_75896 = enumerator_75846.current_mValue (HERE).getter_componentsSeparatedByString (GALGAS_string (" ") COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2402)) ;
                                                    GALGAS_uint var_lineWidth_75961 = GALGAS_uint (uint32_t (0U)) ;
                                                    GALGAS_string var_line_75989 = GALGAS_string::makeEmptyString () ;
                                                    cEnumerator_stringlist enumerator_76010 (var_words_75896, kENUMERATION_UP) ;
                                                    while (enumerator_76010.hasCurrentObject ()) {
                                                      enumGalgasBool test_53 = kBoolTrue ;
                                                      if (kBoolTrue == test_53) {
                                                        test_53 = GALGAS_bool (kIsNotEqual, enumerator_76010.current_mValue (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
                                                        if (kBoolTrue == test_53) {
                                                          enumGalgasBool test_54 = kBoolTrue ;
                                                          if (kBoolTrue == test_54) {
                                                            test_54 = GALGAS_bool (kIsStrictSup, var_lineWidth_75961.add_operation (enumerator_76010.current_mValue (HERE).getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2407)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2407)).objectCompare (var_width_75496)).boolEnum () ;
                                                            if (kBoolTrue == test_54) {
                                                              var_line_75989.plusAssign_operation(GALGAS_string ("\n").add_operation (var_stringShift_75648, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2408)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2408)) ;
                                                              var_lineWidth_75961 = var_shift_75571 ;
                                                            }
                                                          }
                                                          var_lineWidth_75961.plusAssign_operation(enumerator_76010.current_mValue (HERE).getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2411)).add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2411)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2411)) ;
                                                          var_line_75989.plusAssign_operation(enumerator_76010.current_mValue (HERE).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2412)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2412)) ;
                                                        }
                                                      }
                                                      enumerator_76010.gotoNextObject () ;
                                                    }
                                                    var_resultParagraphs_75805.addAssign_operation (var_line_75989  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2415)) ;
                                                    enumerator_75846.gotoNextObject () ;
                                                  }
                                                  result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2419)), GALGAS_string::constructor_componentsJoinedByString (var_resultParagraphs_75805, GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2420))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2417)) ;
                                                }
                                              }
                                              if (kBoolFalse == test_50) {
                                                enumGalgasBool test_55 = kBoolTrue ;
                                                if (kBoolTrue == test_55) {
                                                  test_55 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("replaceString"))).boolEnum () ;
                                                  if (kBoolTrue == test_55) {
                                                    {
                                                    routine_argumentsCheck (constinArgument_methodName, function_stringStringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2423)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2423)) ;
                                                    }
                                                    GALGAS_gtlString temp_56 ;
                                                    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2424)).isValid ()) {
                                                      if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2424)).ptr ())) {
                                                        temp_56 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2424)).ptr () ;
                                                      }else{
                                                        inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2424)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2424)) ;
                                                      }
                                                    }
                                                    GALGAS_string var_find_76621 = temp_56.readProperty_value () ;
                                                    GALGAS_gtlString temp_57 ;
                                                    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2425)).isValid ()) {
                                                      if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2425)).ptr ())) {
                                                        temp_57 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2425)).ptr () ;
                                                      }else{
                                                        inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2425)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2425)) ;
                                                      }
                                                    }
                                                    GALGAS_string var_rep_76693 = temp_57.readProperty_value () ;
                                                    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2428)), this->mProperty_value.getter_stringByReplacingStringByString (var_find_76621, var_rep_76693, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2429))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2426)) ;
                                                  }
                                                }
                                                if (kBoolFalse == test_55) {
                                                  enumGalgasBool test_58 = kBoolTrue ;
                                                  if (kBoolTrue == test_58) {
                                                    test_58 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("subStringExists"))).boolEnum () ;
                                                    if (kBoolTrue == test_58) {
                                                      {
                                                      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2432)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2432)) ;
                                                      }
                                                      GALGAS_gtlString temp_59 ;
                                                      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)).isValid ()) {
                                                        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)).ptr ())) {
                                                          temp_59 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)).ptr () ;
                                                        }else{
                                                          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)) ;
                                                        }
                                                      }
                                                      GALGAS_string var_subString_77026 = callExtensionGetter_string ((const cPtr_gtlString *) temp_59.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)) ;
                                                      GALGAS_uint var_subLength_77102 = var_subString_77026.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2434)) ;
                                                      GALGAS_uint var_start_77143 = GALGAS_uint (uint32_t (0U)) ;
                                                      GALGAS_uint var_stop_77167 = this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2436)).substract_operation (var_subLength_77102, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2436)) ;
                                                      GALGAS_bool var_exists_77211 = GALGAS_bool (false) ;
                                                      if (this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2438)).isValid ()) {
                                                        uint32_t variant_77230 = this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 2438)).uintValue () ;
                                                        bool loop_77230 = true ;
                                                        while (loop_77230) {
                                                          loop_77230 = GALGAS_bool (kIsInfOrEqual, var_start_77143.objectCompare (var_stop_77167)).operator_and (var_exists_77211.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2439)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2439)).isValid () ;
                                                          if (loop_77230) {
                                                            loop_77230 = GALGAS_bool (kIsInfOrEqual, var_start_77143.objectCompare (var_stop_77167)).operator_and (var_exists_77211.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2439)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2439)).boolValue () ;
                                                          }
                                                          if (loop_77230 && (0 == variant_77230)) {
                                                            loop_77230 = false ;
                                                            inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_data_types.galgas", 2438)) ;
                                                          }
                                                          if (loop_77230) {
                                                            variant_77230 -- ;
                                                            enumGalgasBool test_60 = kBoolTrue ;
                                                            if (kBoolTrue == test_60) {
                                                              test_60 = GALGAS_bool (kIsEqual, this->mProperty_value.getter_subString (var_start_77143, var_subLength_77102 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2440)).objectCompare (var_subString_77026)).boolEnum () ;
                                                              if (kBoolTrue == test_60) {
                                                                var_exists_77211 = GALGAS_bool (true) ;
                                                              }
                                                            }
                                                            var_start_77143.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2443)) ;
                                                          }
                                                        }
                                                      }
                                                      result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2447)), var_exists_77211  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2445)) ;
                                                    }
                                                  }
                                                  if (kBoolFalse == test_58) {
                                                    enumGalgasBool test_61 = kBoolTrue ;
                                                    if (kBoolTrue == test_61) {
                                                      test_61 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("envVarExists"))).boolEnum () ;
                                                      if (kBoolTrue == test_61) {
                                                        {
                                                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2451)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2451)) ;
                                                        }
                                                        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2454)), this->mProperty_value.getter_doesEnvironmentVariableExist (SOURCE_FILE ("gtl_data_types.galgas", 2455))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2452)) ;
                                                      }
                                                    }
                                                    if (kBoolFalse == test_61) {
                                                      enumGalgasBool test_62 = kBoolTrue ;
                                                      if (kBoolTrue == test_62) {
                                                        test_62 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("envVar"))).boolEnum () ;
                                                        if (kBoolTrue == test_62) {
                                                          {
                                                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2458)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2458)) ;
                                                          }
                                                          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2461)), GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (this->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2462))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2459)) ;
                                                        }
                                                      }
                                                      if (kBoolFalse == test_62) {
                                                        enumGalgasBool test_63 = kBoolTrue ;
                                                        if (kBoolTrue == test_63) {
                                                          test_63 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                          if (kBoolTrue == test_63) {
                                                            {
                                                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2465)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2465)) ;
                                                            }
                                                            const GALGAS_gtlString temp_64 = this ;
                                                            result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2467)), temp_64.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 2467))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2466)) ;
                                                          }
                                                        }
                                                        if (kBoolFalse == test_63) {
                                                          enumGalgasBool test_65 = kBoolTrue ;
                                                          if (kBoolTrue == test_65) {
                                                            test_65 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                            if (kBoolTrue == test_65) {
                                                              {
                                                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2470)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2470)) ;
                                                              }
                                                              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2472)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2471)) ;
                                                            }
                                                          }
                                                          if (kBoolFalse == test_65) {
                                                            enumGalgasBool test_66 = kBoolTrue ;
                                                            if (kBoolTrue == test_66) {
                                                              test_66 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                              if (kBoolTrue == test_66) {
                                                                {
                                                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2475)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2475)) ;
                                                                }
                                                                result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2477)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2476)) ;
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
                                                                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2488)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2488)) ;
                                                                    }
                                                                    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2490)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2490))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2489)) ;
                                                                  }
                                                                }
                                                                if (kBoolFalse == test_69) {
                                                                  enumGalgasBool test_70 = kBoolTrue ;
                                                                  if (kBoolTrue == test_70) {
                                                                    test_70 = GALGAS_bool (kIsEqual, GALGAS_string ("files").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                                    if (kBoolTrue == test_70) {
                                                                      {
                                                                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2493)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2493)) ;
                                                                      }
                                                                      GALGAS_stringlist var_fileList_79077 = this->mProperty_value.getter_regularFiles (GALGAS_bool (false) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2494)) ;
                                                                      GALGAS_lstringset var_files_79132 = GALGAS_lstringset::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 2495)) ;
                                                                      cEnumerator_stringlist enumerator_79159 (var_fileList_79077, kENUMERATION_UP) ;
                                                                      while (enumerator_79159.hasCurrentObject ()) {
                                                                        {
                                                                        var_files_79132.setter_put (GALGAS_lstring::constructor_new (enumerator_79159.current_mValue (HERE), constinArgument_methodName.readProperty_location ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2497)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2497)) ;
                                                                        }
                                                                        enumerator_79159.gotoNextObject () ;
                                                                      }
                                                                      result_result = GALGAS_gtlSet::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2500)), var_files_79132  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2499)) ;
                                                                    }
                                                                  }
                                                                  if (kBoolFalse == test_70) {
                                                                    enumGalgasBool test_71 = kBoolTrue ;
                                                                    if (kBoolTrue == test_71) {
                                                                      test_71 = GALGAS_bool (kIsEqual, GALGAS_string ("filesWithExtensions").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                                      if (kBoolTrue == test_71) {
                                                                        {
                                                                        routine_argumentsCheck (constinArgument_methodName, function_setArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2503)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2503)) ;
                                                                        }
                                                                        GALGAS_stringlist var_extensions_79464 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 2504)) ;
                                                                        GALGAS_gtlSet temp_72 ;
                                                                        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)).isValid ()) {
                                                                          if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)).ptr ())) {
                                                                            temp_72 = (cPtr_gtlSet *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)).ptr () ;
                                                                          }else{
                                                                            inCompiler->castError ("gtlSet", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)) ;
                                                                          }
                                                                        }
                                                                        cEnumerator_lstringset enumerator_79497 (temp_72.readProperty_value (), kENUMERATION_UP) ;
                                                                        while (enumerator_79497.hasCurrentObject ()) {
                                                                          var_extensions_79464.addAssign_operation (enumerator_79497.current_lkey (HERE).readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2506)) ;
                                                                          enumerator_79497.gotoNextObject () ;
                                                                        }
                                                                        GALGAS_stringlist var_fileList_79617 = this->mProperty_value.getter_regularFilesWithExtensions (GALGAS_bool (false), var_extensions_79464 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2508)) ;
                                                                        GALGAS_lstringset var_files_79698 = GALGAS_lstringset::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 2509)) ;
                                                                        cEnumerator_stringlist enumerator_79725 (var_fileList_79617, kENUMERATION_UP) ;
                                                                        while (enumerator_79725.hasCurrentObject ()) {
                                                                          {
                                                                          var_files_79698.setter_put (GALGAS_lstring::constructor_new (enumerator_79725.current_mValue (HERE), constinArgument_methodName.readProperty_location ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2511)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2511)) ;
                                                                          }
                                                                          enumerator_79725.gotoNextObject () ;
                                                                        }
                                                                        result_result = GALGAS_gtlSet::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2514)), var_files_79698  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2513)) ;
                                                                      }
                                                                    }
                                                                    if (kBoolFalse == test_71) {
                                                                      enumGalgasBool test_73 = kBoolTrue ;
                                                                      if (kBoolTrue == test_73) {
                                                                        test_73 = GALGAS_bool (kIsEqual, GALGAS_string ("parseOIL").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                                        if (kBoolTrue == test_73) {
                                                                          {
                                                                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2517)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2517)) ;
                                                                          }
                                                                          GALGAS_string var_rootTemplatesDir_80018 = function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2518)) ;
                                                                          GALGAS_implementation var_imp_80082 = GALGAS_implementation::constructor_new (GALGAS_implementationMap::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 2519))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2519)) ;
                                                                          GALGAS_applicationDefinition var_app_80168 = function_emptyApplicationDefinition (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2520)) ;
                                                                          GALGAS_lstring var_includeToParse_80220 = GALGAS_lstring::constructor_new (var_rootTemplatesDir_80018.add_operation (GALGAS_string ("libraries/config.oil"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2522)), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2521)) ;
                                                                          GALGAS_lstring var_fileToParse_80336 = GALGAS_lstring::constructor_new (var_rootTemplatesDir_80018.add_operation (GALGAS_string ("libraries/"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2526)).add_operation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2526)), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2525)) ;
                                                                          cGrammar_goil_5F_file_5F_level_5F_include_5F_without_5F_include::_performSourceFileParsing_ (inCompiler, var_includeToParse_80220, var_imp_80082, var_app_80168  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2529)) ;
                                                                          cGrammar_goil_5F_file_5F_level_5F_include_5F_without_5F_include::_performSourceFileParsing_ (inCompiler, var_fileToParse_80336, var_imp_80082, var_app_80168  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2532)) ;
                                                                          GALGAS_gtlData var_templateData_80632 = callExtensionGetter_templateData ((const cPtr_applicationDefinition *) var_app_80168.ptr (), var_imp_80082, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2535)) ;
                                                                          result_result = var_templateData_80632 ;
                                                                        }
                                                                      }
                                                                      if (kBoolFalse == test_73) {
                                                                        TC_Array <C_FixItDescription> fixItArray74 ;
                                                                        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2538)).add_operation (GALGAS_string ("' for string target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2538)), fixItArray74  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2538)) ;
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
//Overriding extension setter '@gtlString performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlString_performSetter (cPtr_gtlData * inObject,
                                                     const GALGAS_lstring constinArgument_methodName,
                                                     const GALGAS_gtlDataList constinArgument_arguments,
                                                     const GALGAS_gtlContext constinArgument_context,
                                                     const GALGAS_library constinArgument_lib,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlString * object = (cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2553)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2553)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2554)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2554)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2554)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2554)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2554)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_81281 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_81281.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2555)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2555)) ;
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
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2558)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2558)) ;
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
          routine_argumentsCheck (constinArgument_methodName, function_charIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2561)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2561)) ;
          }
          GALGAS_gtlChar temp_4 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2562)).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2562)).ptr ())) {
              temp_4 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2562)).ptr () ;
            }else{
              inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2562)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2562)) ;
            }
          }
          GALGAS_char var_charToSet_81648 = temp_4.readProperty_value () ;
          GALGAS_gtlInt temp_5 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2563)).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2563)).ptr ())) {
              temp_5 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2563)).ptr () ;
            }else{
              inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2563)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2563)) ;
            }
          }
          GALGAS_uint var_index_81721 = temp_5.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2563)) ;
          {
          object->mProperty_value.setter_setCharacterAtIndex (var_charToSet_81648, var_index_81721, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2564)) ;
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
            routine_argumentsCheck (constinArgument_methodName, function_charIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2567)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2567)) ;
            }
            GALGAS_gtlChar temp_7 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2568)).isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2568)).ptr ())) {
                temp_7 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2568)).ptr () ;
              }else{
                inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2568)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2568)) ;
              }
            }
            GALGAS_char var_charToInsert_81981 = temp_7.readProperty_value () ;
            GALGAS_gtlInt temp_8 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2569)).isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2569)).ptr ())) {
                temp_8 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2569)).ptr () ;
              }else{
                inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2569)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2569)) ;
              }
            }
            GALGAS_uint var_index_82057 = temp_8.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2569)) ;
            {
            object->mProperty_value.setter_insertCharacterAtIndex (var_charToInsert_81981, var_index_82057, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2570)) ;
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
              routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2573)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2573)) ;
              }
              GALGAS_gtlInt temp_10 ;
              if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2574)).isValid ()) {
                if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2574)).ptr ())) {
                  temp_10 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2574)).ptr () ;
                }else{
                  inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2574)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2574)) ;
                }
              }
              GALGAS_uint var_index_82318 = temp_10.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2574)) ;
              {
              GALGAS_char joker_82415 ; // Joker input parameter
              object->mProperty_value.setter_removeCharacterAtIndex (joker_82415, var_index_82318, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2575)) ;
              }
              object->mProperty_where = constinArgument_methodName.readProperty_location () ;
            }
          }
          if (kBoolFalse == test_9) {
            enumGalgasBool test_11 = kBoolTrue ;
            if (kBoolTrue == test_11) {
              test_11 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("string"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2577)).boolEnum () ;
              if (kBoolTrue == test_11) {
                const GALGAS_gtlString temp_12 = object ;
                GALGAS_gtlData var_copy_82516 = temp_12 ;
                callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("string"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2579)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_82516, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2579)) ;
                GALGAS_gtlString temp_13 ;
                if (var_copy_82516.isValid ()) {
                  if (NULL != dynamic_cast <const cPtr_gtlString *> (var_copy_82516.ptr ())) {
                    temp_13 = (cPtr_gtlString *) var_copy_82516.ptr () ;
                  }else{
                    inCompiler->castError ("gtlString", var_copy_82516.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2586)) ;
                  }
                }
                object->mProperty_value = temp_13.readProperty_value () ;
                object->mProperty_where = var_copy_82516.readProperty_where () ;
                object->mProperty_meta = var_copy_82516.readProperty_meta () ;
              }
            }
            if (kBoolFalse == test_11) {
              TC_Array <C_FixItDescription> fixItArray14 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2590)).add_operation (GALGAS_string ("' for string target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2590)), fixItArray14  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2590)) ;
            }
          }
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlString_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                                      extensionSetter_gtlString_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlString_performSetter (defineExtensionSetter_gtlString_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlBool::getter_desc (const GALGAS_uint constinArgument_tab,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2603)).add_operation (GALGAS_string ("boolean: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2603)).add_operation (this->mProperty_value.getter_cString (SOURCE_FILE ("gtl_data_types.galgas", 2604)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2604)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2604)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlBool::getter_string (C_Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value.getter_cString (SOURCE_FILE ("gtl_data_types.galgas", 2607)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlBool::getter_lstring (C_Compiler */* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (this->mProperty_value.getter_cString (SOURCE_FILE ("gtl_data_types.galgas", 2610)), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2610)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlBool::getter_bool (C_Compiler */* inCompiler */
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlBool::getter_int (C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  GALGAS_bigint temp_0 ;
  const enumGalgasBool test_1 = this->mProperty_value.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2618)) ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2618)) ;
  }
  result_result = temp_0 ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlBool::getter_float (C_Compiler */* inCompiler */
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


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_plusOp (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2626)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_minusOp (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2630)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_notOp (C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2634)), this->mProperty_value.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2634))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2634)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2638)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2642)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2646)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2650)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2654)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_andOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2662)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2661)), this->mProperty_value.operator_and (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2662))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2659)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2665)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_orOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2674)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2673)), this->mProperty_value.operator_or (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2674))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2671)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2677)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_xorOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2686)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2685)), this->mProperty_value.operator_xor (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2686))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2683)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2689)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2694)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2698)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2706)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2705)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2703)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2709)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2718)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2717)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2715)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2721)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2730)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2729)), GALGAS_bool (kIsStrictSup, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2727)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2733)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2742)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2741)), GALGAS_bool (kIsSupOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2739)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2745)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2754)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2753)), GALGAS_bool (kIsStrictInf, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2751)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2757)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2766)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2765)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2763)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2769)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlBool::getter_embeddedType (C_Compiler */* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_bool) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBool addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBool::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                      C_Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 2780))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2780)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("trueOrFalse"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2794)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2794)) ;
      }
      GALGAS_string temp_1 ;
      const enumGalgasBool test_2 = this->mProperty_value.boolEnum () ;
      if (kBoolTrue == test_2) {
        temp_1 = GALGAS_string ("true") ;
      }else if (kBoolFalse == test_2) {
        temp_1 = GALGAS_string ("false") ;
      }
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2797)), temp_1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2795)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("string"))).boolEnum () ;
      if (kBoolTrue == test_3) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2801)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2801)) ;
        }
        const GALGAS_gtlBool temp_4 = this ;
        result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2804)), callExtensionGetter_string ((const cPtr_gtlBool *) temp_4.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2805))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2802)) ;
      }
    }
    if (kBoolFalse == test_3) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("yesOrNo"))).boolEnum () ;
        if (kBoolTrue == test_5) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2808)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2808)) ;
          }
          GALGAS_string temp_6 ;
          const enumGalgasBool test_7 = this->mProperty_value.boolEnum () ;
          if (kBoolTrue == test_7) {
            temp_6 = GALGAS_string ("yes") ;
          }else if (kBoolFalse == test_7) {
            temp_6 = GALGAS_string ("no") ;
          }
          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2811)), temp_6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2809)) ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_8 = kBoolTrue ;
        if (kBoolTrue == test_8) {
          test_8 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("TRUEOrFALSE"))).boolEnum () ;
          if (kBoolTrue == test_8) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2815)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2815)) ;
            }
            GALGAS_string temp_9 ;
            const enumGalgasBool test_10 = this->mProperty_value.boolEnum () ;
            if (kBoolTrue == test_10) {
              temp_9 = GALGAS_string ("TRUE") ;
            }else if (kBoolFalse == test_10) {
              temp_9 = GALGAS_string ("FALSE") ;
            }
            result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2818)), temp_9  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2816)) ;
          }
        }
        if (kBoolFalse == test_8) {
          enumGalgasBool test_11 = kBoolTrue ;
          if (kBoolTrue == test_11) {
            test_11 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("YESOrNO"))).boolEnum () ;
            if (kBoolTrue == test_11) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2822)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2822)) ;
              }
              GALGAS_string temp_12 ;
              const enumGalgasBool test_13 = this->mProperty_value.boolEnum () ;
              if (kBoolTrue == test_13) {
                temp_12 = GALGAS_string ("YES") ;
              }else if (kBoolFalse == test_13) {
                temp_12 = GALGAS_string ("NO") ;
              }
              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2825)), temp_12  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2823)) ;
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
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2829)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2829)) ;
                }
                GALGAS_bigint temp_16 ;
                const enumGalgasBool test_17 = this->mProperty_value.boolEnum () ;
                if (kBoolTrue == test_17) {
                  temp_16 = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2833)) ;
                }else if (kBoolFalse == test_17) {
                  temp_16 = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2833)) ;
                }
                result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2832)), temp_16  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2830)) ;
              }
            }
            if (kBoolFalse == test_14) {
              enumGalgasBool test_18 = kBoolTrue ;
              if (kBoolTrue == test_18) {
                test_18 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                if (kBoolTrue == test_18) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2836)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2836)) ;
                  }
                  const GALGAS_gtlBool temp_19 = this ;
                  result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2838)), temp_19.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 2838))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2837)) ;
                }
              }
              if (kBoolFalse == test_18) {
                enumGalgasBool test_20 = kBoolTrue ;
                if (kBoolTrue == test_20) {
                  test_20 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_20) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2841)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2841)) ;
                    }
                    result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2843)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2842)) ;
                  }
                }
                if (kBoolFalse == test_20) {
                  enumGalgasBool test_21 = kBoolTrue ;
                  if (kBoolTrue == test_21) {
                    test_21 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                    if (kBoolTrue == test_21) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2846)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2846)) ;
                      }
                      result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2848)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2847)) ;
                    }
                  }
                  if (kBoolFalse == test_21) {
                    enumGalgasBool test_22 = kBoolTrue ;
                    if (kBoolTrue == test_22) {
                      test_22 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("bool"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2850)).boolEnum () ;
                      if (kBoolTrue == test_22) {
                        const GALGAS_gtlBool temp_23 = this ;
                        result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("bool"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2851)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_23, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2851)) ;
                      }
                    }
                    if (kBoolFalse == test_22) {
                      enumGalgasBool test_24 = kBoolTrue ;
                      if (kBoolTrue == test_24) {
                        test_24 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                        if (kBoolTrue == test_24) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2859)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2859)) ;
                          }
                          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2861)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2861))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2860)) ;
                        }
                      }
                      if (kBoolFalse == test_24) {
                        TC_Array <C_FixItDescription> fixItArray25 ;
                        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2864)).add_operation (GALGAS_string ("' for boolean target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2864)), fixItArray25  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2864)) ;
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


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlBool performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlBool_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlBool * object = (cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2879)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2879)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2880)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2880)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2880)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2880)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2880)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_90937 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_90937.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2881)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2881)) ;
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
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2884)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2884)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("bool"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2886)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlBool temp_4 = object ;
          GALGAS_gtlData var_copy_91245 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("bool"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2888)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_91245, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2888)) ;
          GALGAS_gtlBool temp_5 ;
          if (var_copy_91245.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlBool *> (var_copy_91245.ptr ())) {
              temp_5 = (cPtr_gtlBool *) var_copy_91245.ptr () ;
            }else{
              inCompiler->castError ("gtlBool", var_copy_91245.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2895)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_91245.readProperty_where () ;
          object->mProperty_meta = var_copy_91245.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2899)).add_operation (GALGAS_string ("' for boolean target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2899)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2899)) ;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlBool_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                                      extensionSetter_gtlBool_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlBool_performSetter (defineExtensionSetter_gtlBool_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlSet::getter_desc (const GALGAS_uint constinArgument_tab,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2923)).add_operation (GALGAS_string ("set: @!\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2923)) ;
  cEnumerator_lstringset enumerator_92447 (this->mProperty_value, kENUMERATION_UP) ;
  const bool bool_0 = true ;
  if (enumerator_92447.hasCurrentObject () && bool_0) {
    result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2927))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2927)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2927)) ;
    while (enumerator_92447.hasCurrentObject () && bool_0) {
      result_result.plusAssign_operation(enumerator_92447.current_lkey (HERE).readProperty_string (), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2929)) ;
      enumerator_92447.gotoNextObject () ;
      if (enumerator_92447.hasCurrentObject () && bool_0) {
        result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2931)) ;
      }
    }
    result_result.plusAssign_operation(GALGAS_string ("\n"), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2933)) ;
  }
  result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2935)).add_operation (GALGAS_string ("!\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2935)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2935)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlSet::getter_string (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a set to a string"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2939)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlSet::getter_lstring (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a set to a lstring"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2943)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlSet::getter_bool (C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a set to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2947)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlSet::getter_int (C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a set to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2951)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlSet::getter_float (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a set to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2955)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_plusOp (C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2959)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_minusOp (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2963)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_notOp (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2967)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_addOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_lstringset var_set_93620 = this->mProperty_value ;
  GALGAS_lstring var_element_93647 = callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2972)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = var_set_93620.getter_hasKey (var_element_93647.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2973)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      var_set_93620.setter_del (var_element_93647, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2974)) ;
      }
    }
  }
  {
  var_set_93620.setter_put (callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2976)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2976)) ;
  }
  result_result = GALGAS_gtlSet::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2977)), var_set_93620  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2977)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_subOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstringset var_resultSet_93942 = this->mProperty_value ;
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2983)) ;
        }
      }
      cEnumerator_lstringset enumerator_93969 (temp_1.readProperty_value (), kENUMERATION_UP) ;
      while (enumerator_93969.hasCurrentObject ()) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = var_resultSet_93942.getter_hasKey (enumerator_93969.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2984)).boolEnum () ;
          if (kBoolTrue == test_2) {
            {
            var_resultSet_93942.setter_del (enumerator_93969.current_lkey (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2985)) ;
            }
          }
        }
        enumerator_93969.gotoNextObject () ;
      }
      result_result = GALGAS_gtlSet::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2989)), var_resultSet_93942  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2988)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2992)), GALGAS_string ("set expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2992)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2997)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3001)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3005)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_andOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstringset var_resultSet_94709 = GALGAS_lstringset::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 3010)) ;
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3011)) ;
        }
      }
      cEnumerator_lstringset enumerator_94740 (temp_1.readProperty_value (), kENUMERATION_UP) ;
      while (enumerator_94740.hasCurrentObject ()) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = this->mProperty_value.getter_hasKey (enumerator_94740.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3012)).boolEnum () ;
          if (kBoolTrue == test_2) {
            {
            var_resultSet_94709.setter_put (enumerator_94740.current_lkey (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3013)) ;
            }
          }
        }
        enumerator_94740.gotoNextObject () ;
      }
      result_result = GALGAS_gtlSet::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3017)), var_resultSet_94709  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3016)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3020)), GALGAS_string ("set expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3020)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_orOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3026)) ;
        }
      }
      GALGAS_lstringset var_resultSet_95121 = temp_1.readProperty_value () ;
      cEnumerator_lstringset enumerator_95167 (this->mProperty_value, kENUMERATION_UP) ;
      while (enumerator_95167.hasCurrentObject ()) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = var_resultSet_95121.getter_hasKey (enumerator_95167.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3028)).operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3028)).boolEnum () ;
          if (kBoolTrue == test_2) {
            {
            var_resultSet_95121.setter_put (enumerator_95167.current_lkey (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3029)) ;
            }
          }
        }
        enumerator_95167.gotoNextObject () ;
      }
      result_result = GALGAS_gtlSet::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3033)), var_resultSet_95121  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3032)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3036)), GALGAS_string ("set expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3036)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3041)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3045)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3049)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3055)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3055)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3054)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3058)), GALGAS_string ("set expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3058)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3065)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3065)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3064)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3068)), GALGAS_string ("set expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3068)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_gtOp (const GALGAS_gtlData constinArgument_right,
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
            inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3074)) ;
          }
        }
        test_1 = GALGAS_bool (kIsEqual, temp_2.readProperty_value ().objectCompare (this->mProperty_value)).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3075)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3075)) ;
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_bool var_included_96524 = GALGAS_bool (true) ;
        GALGAS_gtlSet temp_3 ;
        if (constinArgument_right.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
            temp_3 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
          }else{
            inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3078)) ;
          }
        }
        cEnumerator_lstringset enumerator_96551 (temp_3.readProperty_value (), kENUMERATION_UP) ;
        bool bool_4 = var_included_96524.isValidAndTrue () ;
        if (enumerator_96551.hasCurrentObject () && bool_4) {
          while (enumerator_96551.hasCurrentObject () && bool_4) {
            enumGalgasBool test_5 = kBoolTrue ;
            if (kBoolTrue == test_5) {
              test_5 = this->mProperty_value.getter_hasKey (enumerator_96551.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3079)).operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3079)).boolEnum () ;
              if (kBoolTrue == test_5) {
                var_included_96524 = GALGAS_bool (false) ;
              }
            }
            enumerator_96551.gotoNextObject () ;
            if (enumerator_96551.hasCurrentObject ()) {
              bool_4 = var_included_96524.isValidAndTrue () ;
            }
          }
        }
        result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3081)), var_included_96524  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3081)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray6 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3084)), GALGAS_string ("set expected"), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3084)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


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
      GALGAS_bool var_included_96914 = GALGAS_bool (true) ;
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3091)) ;
        }
      }
      cEnumerator_lstringset enumerator_96939 (temp_1.readProperty_value (), kENUMERATION_UP) ;
      bool bool_2 = var_included_96914.isValidAndTrue () ;
      if (enumerator_96939.hasCurrentObject () && bool_2) {
        while (enumerator_96939.hasCurrentObject () && bool_2) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = this->mProperty_value.getter_hasKey (enumerator_96939.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3092)).operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3092)).boolEnum () ;
            if (kBoolTrue == test_3) {
              var_included_96914 = GALGAS_bool (false) ;
            }
          }
          enumerator_96939.gotoNextObject () ;
          if (enumerator_96939.hasCurrentObject ()) {
            bool_2 = var_included_96914.isValidAndTrue () ;
          }
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3094)), var_included_96914  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3094)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3096)), GALGAS_string ("set expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3096)) ;
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
            inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3102)) ;
          }
        }
        test_1 = GALGAS_bool (kIsEqual, temp_2.readProperty_value ().objectCompare (this->mProperty_value)).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3103)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3103)) ;
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_bool var_included_97407 = GALGAS_bool (true) ;
        cEnumerator_lstringset enumerator_97434 (this->mProperty_value, kENUMERATION_UP) ;
        bool bool_3 = var_included_97407.isValidAndTrue () ;
        if (enumerator_97434.hasCurrentObject () && bool_3) {
          while (enumerator_97434.hasCurrentObject () && bool_3) {
            enumGalgasBool test_4 = kBoolTrue ;
            if (kBoolTrue == test_4) {
              GALGAS_gtlSet temp_5 ;
              if (constinArgument_right.isValid ()) {
                if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
                  temp_5 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
                }else{
                  inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3107)) ;
                }
              }
              test_4 = temp_5.readProperty_value ().getter_hasKey (enumerator_97434.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3107)).operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3107)).boolEnum () ;
              if (kBoolTrue == test_4) {
                var_included_97407 = GALGAS_bool (false) ;
              }
            }
            enumerator_97434.gotoNextObject () ;
            if (enumerator_97434.hasCurrentObject ()) {
              bool_3 = var_included_97407.isValidAndTrue () ;
            }
          }
        }
        result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3109)), var_included_97407  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3109)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray6 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3112)), GALGAS_string ("set expected"), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3112)) ;
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
      GALGAS_bool var_included_97797 = GALGAS_bool (true) ;
      cEnumerator_lstringset enumerator_97822 (this->mProperty_value, kENUMERATION_UP) ;
      bool bool_1 = var_included_97797.isValidAndTrue () ;
      if (enumerator_97822.hasCurrentObject () && bool_1) {
        while (enumerator_97822.hasCurrentObject () && bool_1) {
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            GALGAS_gtlSet temp_3 ;
            if (constinArgument_right.isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
                temp_3 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
              }else{
                inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3120)) ;
              }
            }
            test_2 = temp_3.readProperty_value ().getter_hasKey (enumerator_97822.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3120)).operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3120)).boolEnum () ;
            if (kBoolTrue == test_2) {
              var_included_97797 = GALGAS_bool (false) ;
            }
          }
          enumerator_97822.gotoNextObject () ;
          if (enumerator_97822.hasCurrentObject ()) {
            bool_1 = var_included_97797.isValidAndTrue () ;
          }
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3122)), var_included_97797  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3122)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3124)), GALGAS_string ("set expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3124)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3130)) ;
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
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 3135))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3135)) ;
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
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3149)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3149)) ;
      }
      result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3152)), this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3153)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 3153))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3150)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("list").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3156)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3156)) ;
        }
        result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3158)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 3158))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3157)) ;
        cEnumerator_lstringset enumerator_99094 (this->mProperty_value, kENUMERATION_UP) ;
        while (enumerator_99094.hasCurrentObject ()) {
          {
          result_result.insulate (HERE) ;
          cPtr_gtlData * ptr_99118 = (cPtr_gtlData *) result_result.ptr () ;
          callExtensionSetter_appendItem ((cPtr_gtlData *) ptr_99118, GALGAS_gtlString::constructor_new (enumerator_99094.current_lkey (HERE).readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3161)), enumerator_99094.current_lkey (HERE).readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3161)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3161)) ;
          }
          enumerator_99094.gotoNextObject () ;
        }
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("contains").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_2) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_anyArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3164)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3164)) ;
          }
          GALGAS_string var_key_99319 = callExtensionGetter_string ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3165)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3165)) ;
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3167)), this->mProperty_value.getter_hasKey (var_key_99319 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3167))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3166)) ;
        }
      }
      if (kBoolFalse == test_2) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("elementNamed").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_3) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_anyArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3170)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3170)) ;
            }
            GALGAS_string var_key_99587 = callExtensionGetter_string ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3171)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3171)) ;
            GALGAS_location var_loc_99647 = this->mProperty_value.getter_locationForKey (var_key_99587, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3172)) ;
            result_result = GALGAS_gtlString::constructor_new (var_loc_99647, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3174)), var_key_99587  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3173)) ;
          }
        }
        if (kBoolFalse == test_3) {
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_4) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3177)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3177)) ;
              }
              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3179)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3178)) ;
            }
          }
          if (kBoolFalse == test_4) {
            enumGalgasBool test_5 = kBoolTrue ;
            if (kBoolTrue == test_5) {
              test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_5) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3182)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3182)) ;
                }
                result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3184)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3183)) ;
              }
            }
            if (kBoolFalse == test_5) {
              enumGalgasBool test_6 = kBoolTrue ;
              if (kBoolTrue == test_6) {
                test_6 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("set"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3186)).boolEnum () ;
                if (kBoolTrue == test_6) {
                  const GALGAS_gtlSet temp_7 = this ;
                  result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("set"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3187)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_7, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3187)) ;
                }
              }
              if (kBoolFalse == test_6) {
                enumGalgasBool test_8 = kBoolTrue ;
                if (kBoolTrue == test_8) {
                  test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_8) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3195)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3195)) ;
                    }
                    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3197)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3197))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3196)) ;
                  }
                }
                if (kBoolFalse == test_8) {
                  TC_Array <C_FixItDescription> fixItArray9 ;
                  inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3200)).add_operation (GALGAS_string ("' for set target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3200)), fixItArray9  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3200)) ;
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
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3215)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3215)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3216)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3216)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3216)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3216)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3216)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_101076 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_101076.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3217)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3217)) ;
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
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3220)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3220)) ;
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
          routine_argumentsCheck (constinArgument_methodName, function_anyArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3223)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3223)) ;
          }
          GALGAS_lstring var_key_101435 = callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3224)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3224)) ;
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = object->mProperty_value.getter_hasKey (var_key_101435.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3225)).boolEnum () ;
            if (kBoolTrue == test_4) {
              {
              object->mProperty_value.setter_del (var_key_101435, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3226)) ;
              }
            }
          }
          {
          object->mProperty_value.setter_put (var_key_101435, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3228)) ;
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
            routine_argumentsCheck (constinArgument_methodName, function_anyArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3231)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3231)) ;
            }
            GALGAS_lstring var_key_101705 = callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3232)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3232)) ;
            enumGalgasBool test_6 = kBoolTrue ;
            if (kBoolTrue == test_6) {
              test_6 = object->mProperty_value.getter_hasKey (var_key_101705.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3233)).boolEnum () ;
              if (kBoolTrue == test_6) {
                {
                object->mProperty_value.setter_del (var_key_101705, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3234)) ;
                }
              }
            }
            object->mProperty_where = constinArgument_methodName.readProperty_location () ;
          }
        }
        if (kBoolFalse == test_5) {
          enumGalgasBool test_7 = kBoolTrue ;
          if (kBoolTrue == test_7) {
            test_7 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("set"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3237)).boolEnum () ;
            if (kBoolTrue == test_7) {
              const GALGAS_gtlSet temp_8 = object ;
              GALGAS_gtlData var_copy_101900 = temp_8 ;
              callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("set"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3239)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_101900, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3239)) ;
              GALGAS_gtlSet temp_9 ;
              if (var_copy_101900.isValid ()) {
                if (NULL != dynamic_cast <const cPtr_gtlSet *> (var_copy_101900.ptr ())) {
                  temp_9 = (cPtr_gtlSet *) var_copy_101900.ptr () ;
                }else{
                  inCompiler->castError ("gtlSet", var_copy_101900.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3246)) ;
                }
              }
              object->mProperty_value = temp_9.readProperty_value () ;
              object->mProperty_where = var_copy_101900.readProperty_where () ;
              object->mProperty_meta = var_copy_101900.readProperty_meta () ;
            }
          }
          if (kBoolFalse == test_7) {
            TC_Array <C_FixItDescription> fixItArray10 ;
            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3250)).add_operation (GALGAS_string ("' for set target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3250)), fixItArray10  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3250)) ;
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
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3263)).add_operation (GALGAS_string ("struct: @{\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3263)) ;
  cEnumerator_gtlVarMap enumerator_102640 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_102640.hasCurrentObject ()) {
    result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3266))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3266)).add_operation (enumerator_102640.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3266)).add_operation (GALGAS_string (" :>\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3267)).add_operation (callExtensionGetter_desc ((const cPtr_gtlData *) enumerator_102640.current_value (HERE).ptr (), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (8U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3268)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3268)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3267)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3266)) ;
    enumerator_102640.gotoNextObject () ;
  }
  result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3270)).add_operation (GALGAS_string ("}\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3270)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3270)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3274)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3278)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a struct to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3282)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a struct to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3286)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a struct to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3290)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3294)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3298)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3302)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3306)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3310)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3314)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3318)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3322)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3326)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3330)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3334)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3338)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3342)) ;
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
          inCompiler->castError ("gtlStruct", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3347)) ;
        }
      }
      GALGAS_gtlVarMap var_rValue_105121 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_105168 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3349)).objectCompare (var_rValue_105121.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3349)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_105168 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_105168 = GALGAS_bool (true) ;
        cEnumerator_gtlVarMap enumerator_105282 (this->mProperty_value, kENUMERATION_UP) ;
        while (enumerator_105282.hasCurrentObject ()) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = var_rValue_105121.getter_hasKey (enumerator_105282.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3354)).boolEnum () ;
            if (kBoolTrue == test_3) {
              GALGAS_gtlData var_rData_105382 ;
              var_rValue_105121.method_get (enumerator_105282.current_lkey (HERE), var_rData_105382, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3355)) ;
              var_equal_105168 = var_equal_105168.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_105282.current_value (HERE).ptr (), var_rData_105382, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3356)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3356)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3356)) ;
            }
          }
          if (kBoolFalse == test_3) {
            var_equal_105168 = GALGAS_bool (false) ;
          }
          enumerator_105282.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3362)), var_equal_105168.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3362))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3362)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("struct expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3364)) ;
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
          inCompiler->castError ("gtlStruct", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3370)) ;
        }
      }
      GALGAS_gtlVarMap var_rValue_105761 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_105808 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3372)).objectCompare (var_rValue_105761.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3372)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_105808 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_105808 = GALGAS_bool (true) ;
        cEnumerator_gtlVarMap enumerator_105922 (this->mProperty_value, kENUMERATION_UP) ;
        while (enumerator_105922.hasCurrentObject ()) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = var_rValue_105761.getter_hasKey (enumerator_105922.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3377)).boolEnum () ;
            if (kBoolTrue == test_3) {
              GALGAS_gtlData var_rData_106022 ;
              var_rValue_105761.method_get (enumerator_105922.current_lkey (HERE), var_rData_106022, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3378)) ;
              var_equal_105808 = var_equal_105808.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_105922.current_value (HERE).ptr (), var_rData_106022, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3379)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3379)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3379)) ;
            }
          }
          if (kBoolFalse == test_3) {
            var_equal_105808 = GALGAS_bool (false) ;
          }
          enumerator_105922.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3385)), var_equal_105808  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3385)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("struct expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3387)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3392)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3395)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3398)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3401)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3406)) ;
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
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 3411))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3411)) ;
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
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3425)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3425)) ;
      }
      result_result = GALGAS_gtlMap::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3428)), this->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3426)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3432)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3432)) ;
        }
        const GALGAS_gtlStruct temp_2 = this ;
        result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3434)), temp_2.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 3434))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3433)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3437)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3437)) ;
          }
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3439)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3438)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3442)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3442)) ;
            }
            result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3444)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3443)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("struct"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3446)).boolEnum () ;
            if (kBoolTrue == test_5) {
              const GALGAS_gtlStruct temp_6 = this ;
              result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("struct"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3447)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_6, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3447)) ;
            }
          }
          if (kBoolFalse == test_5) {
            enumGalgasBool test_7 = kBoolTrue ;
            if (kBoolTrue == test_7) {
              test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_7) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3455)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3455)) ;
                }
                result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3457)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3457))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3456)) ;
              }
            }
            if (kBoolFalse == test_7) {
              TC_Array <C_FixItDescription> fixItArray8 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3460)).add_operation (GALGAS_string ("' for struct target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3460)), fixItArray8  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3460)) ;
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
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3475)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3475)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3476)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3476)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3476)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3476)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3476)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_109144 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_109144.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3477)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3477)) ;
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
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3480)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3480)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("struct"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3482)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlStruct temp_4 = object ;
          GALGAS_gtlData var_copy_109454 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("struct"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3484)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_109454, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3484)) ;
          GALGAS_gtlStruct temp_5 ;
          if (var_copy_109454.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_copy_109454.ptr ())) {
              temp_5 = (cPtr_gtlStruct *) var_copy_109454.ptr () ;
            }else{
              inCompiler->castError ("gtlStruct", var_copy_109454.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3491)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_109454.readProperty_where () ;
          object->mProperty_meta = var_copy_109454.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3495)).add_operation (GALGAS_string ("' for struct target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3495)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3495)) ;
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
    test_0 = this->mProperty_value.getter_hasKey (constinArgument_name.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3507)).boolEnum () ;
    if (kBoolTrue == test_0) {
      this->mProperty_value.method_get (constinArgument_name, outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3508)) ;
      outArgument_found = GALGAS_bool (true) ;
    }
  }
  if (kBoolFalse == test_0) {
    outArgument_result = GALGAS_gtlUnconstructed::constructor_new (constinArgument_name.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3511))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3511)) ;
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
    test_0 = this->mProperty_value.getter_hasKey (constinArgument_name.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3520)).boolEnum () ;
    if (kBoolTrue == test_0) {
      this->mProperty_value.method_get (constinArgument_name, result_result, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3521)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_gtlUnconstructed::constructor_new (constinArgument_name.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3523))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3523)) ;
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
  result_result = this->mProperty_value.getter_hasKey (constinArgument_name.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3534)) ;
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
  extensionSetter_replaceOrCreate (object->mProperty_value, constinArgument_name, constinArgument_data, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3544)) ;
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
  extensionSetter_replaceOrCreateAtLevel (object->mProperty_value, constinArgument_name, constinArgument_data, constinArgument_level, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3555)) ;
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
  GALGAS_gtlData joker_111766 ; // Joker input parameter
  object->mProperty_value.setter_del (constinArgument_name, joker_111766, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3564)) ;
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
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3576)).add_operation (GALGAS_string ("list: @(\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3576)) ;
  cEnumerator_list enumerator_112170 (this->mProperty_value, kENUMERATION_UP) ;
  GALGAS_uint index_112166 ((uint32_t) 0) ;
  while (enumerator_112170.hasCurrentObject ()) {
    result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3579))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3579)).add_operation (index_112166.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 3580)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3579)).add_operation (GALGAS_string (" :>\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3580)).add_operation (callExtensionGetter_desc ((const cPtr_gtlData *) enumerator_112170.current_value (HERE).ptr (), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (8U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3581)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3581)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3580)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3579)) ;
    enumerator_112170.gotoNextObject () ;
    index_112166.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3578)) ;
  }
  result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3583)).add_operation (GALGAS_string (")\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3583)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3583)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3587)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3591)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a list to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3595)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a list to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3599)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a list to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3603)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3607)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3611)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3615)) ;
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
  GALGAS_list var_res_113297 = this->mProperty_value ;
  var_res_113297.addAssign_operation (constinArgument_right  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3620)) ;
  result_result = GALGAS_gtlList::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3621)), var_res_113297  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3621)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3625)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3629)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3633)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3637)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3641)) ;
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
          inCompiler->castError ("gtlList", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3649)) ;
        }
      }
      result_result = GALGAS_gtlList::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3648)), this->mProperty_value.add_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3649))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3646)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("list expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3652)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3657)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3661)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3665)) ;
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
          inCompiler->castError ("gtlList", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3670)) ;
        }
      }
      GALGAS_list var_rValue_114776 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_114821 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3672)).objectCompare (var_rValue_114776.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3672)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_114821 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_114821 = GALGAS_bool (true) ;
        cEnumerator_list enumerator_114932 (this->mProperty_value, kENUMERATION_UP) ;
        cEnumerator_list enumerator_114949 (var_rValue_114776, kENUMERATION_UP) ;
        while (enumerator_114932.hasCurrentObject () && enumerator_114949.hasCurrentObject ()) {
          var_equal_114821 = var_equal_114821.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_114932.current_value (HERE).ptr (), enumerator_114949.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3677)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3677)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3677)) ;
          enumerator_114932.gotoNextObject () ;
          enumerator_114949.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3680)), var_equal_114821.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3680))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3680)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("list expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3682)) ;
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
          inCompiler->castError ("gtlList", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3688)) ;
        }
      }
      GALGAS_list var_rValue_115277 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_115322 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3690)).objectCompare (var_rValue_115277.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3690)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_115322 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_115322 = GALGAS_bool (true) ;
        cEnumerator_list enumerator_115433 (this->mProperty_value, kENUMERATION_UP) ;
        cEnumerator_list enumerator_115450 (var_rValue_115277, kENUMERATION_UP) ;
        while (enumerator_115433.hasCurrentObject () && enumerator_115450.hasCurrentObject ()) {
          var_equal_115322 = var_equal_115322.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_115433.current_value (HERE).ptr (), enumerator_115450.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3695)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3695)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3695)) ;
          enumerator_115433.gotoNextObject () ;
          enumerator_115450.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3698)), var_equal_115322  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3698)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("list expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3700)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a list does not support the > operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3705)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a list does not support the >= operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3709)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a list does not support the < operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3713)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a list does not support the <= operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3717)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3722)) ;
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
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 3727))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3727)) ;
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
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3741)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3741)) ;
      }
      result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3744)), this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3745)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 3745))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3742)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("first").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3748)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3748)) ;
        }
        this->mProperty_value.method_first (result_result, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3749)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("last").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_2) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3751)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3751)) ;
          }
          this->mProperty_value.method_last (result_result, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3752)) ;
        }
      }
      if (kBoolFalse == test_2) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("elementAtIndex").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_3) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3754)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3754)) ;
            }
            GALGAS_uint var_index_117474 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3755)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3755)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3755)) ;
            enumGalgasBool test_4 = kBoolTrue ;
            if (kBoolTrue == test_4) {
              test_4 = GALGAS_bool (kIsStrictInf, var_index_117474.objectCompare (this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3756)))).boolEnum () ;
              if (kBoolTrue == test_4) {
                result_result = this->mProperty_value.getter_valueAtIndex (var_index_117474, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3757)) ;
              }
            }
            if (kBoolFalse == test_4) {
              TC_Array <C_FixItDescription> fixItArray5 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("index out of bounds"), fixItArray5  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3759)) ;
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
              routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3762)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3762)) ;
              }
              GALGAS_uint var_index_117790 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3763)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3763)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3763)) ;
              enumGalgasBool test_7 = kBoolTrue ;
              if (kBoolTrue == test_7) {
                test_7 = GALGAS_bool (kIsStrictInf, var_index_117790.objectCompare (this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3764)))).boolEnum () ;
                if (kBoolTrue == test_7) {
                  result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3767)), this->mProperty_value.getter_subListToIndex (var_index_117790, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3768))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3765)) ;
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
                routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3774)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3774)) ;
                }
                GALGAS_uint var_index_118148 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3775)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3775)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3775)) ;
                enumGalgasBool test_10 = kBoolTrue ;
                if (kBoolTrue == test_10) {
                  test_10 = GALGAS_bool (kIsStrictInf, var_index_118148.objectCompare (this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3776)))).boolEnum () ;
                  if (kBoolTrue == test_10) {
                    result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3779)), this->mProperty_value.getter_subListFromIndex (var_index_118148, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3780))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3777)) ;
                  }
                }
                if (kBoolFalse == test_10) {
                  result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3785)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 3786))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3783)) ;
                }
              }
            }
            if (kBoolFalse == test_9) {
              enumGalgasBool test_11 = kBoolTrue ;
              if (kBoolTrue == test_11) {
                test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("subList").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                if (kBoolTrue == test_11) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_intIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3790)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3790)) ;
                  }
                  GALGAS_uint var_start_118594 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3791)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3791)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3791)) ;
                  GALGAS_uint var_length_118646 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3792)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3792)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3792)) ;
                  enumGalgasBool test_12 = kBoolTrue ;
                  if (kBoolTrue == test_12) {
                    test_12 = GALGAS_bool (kIsStrictInf, var_start_118594.objectCompare (this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3793)))).boolEnum () ;
                    if (kBoolTrue == test_12) {
                      enumGalgasBool test_13 = kBoolTrue ;
                      if (kBoolTrue == test_13) {
                        test_13 = GALGAS_bool (kIsStrictSup, var_start_118594.add_operation (var_length_118646, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3794)).objectCompare (this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3794)))).boolEnum () ;
                        if (kBoolTrue == test_13) {
                          var_length_118646 = this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3795)).substract_operation (var_start_118594, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3795)) ;
                        }
                      }
                      result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3799)), this->mProperty_value.getter_subListWithRange (GALGAS_range::constructor_new (var_start_118594, var_length_118646  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3800)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3800))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3797)) ;
                    }
                  }
                  if (kBoolFalse == test_12) {
                    result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3805)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 3806))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3803)) ;
                  }
                }
              }
              if (kBoolFalse == test_11) {
                enumGalgasBool test_14 = kBoolTrue ;
                if (kBoolTrue == test_14) {
                  test_14 = GALGAS_bool (kIsEqual, GALGAS_string ("mapBy").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_14) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_anyArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3810)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3810)) ;
                    }
                    GALGAS_lstring var_key_119212 = callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3811)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3811)) ;
                    GALGAS_gtlVarMap var_resultMap_119270 = GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 3812)) ;
                    const GALGAS_gtlList temp_15 = this ;
                    cEnumerator_list enumerator_119301 (temp_15.readProperty_value (), kENUMERATION_UP) ;
                    GALGAS_uint index_119296 ((uint32_t) 0) ;
                    while (enumerator_119301.hasCurrentObject ()) {
                      if (enumerator_119301.current_value (HERE).isValid ()) {
                        if (enumerator_119301.current_value (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct) {
                          GALGAS_gtlStruct cast_119375_itemStruct ((cPtr_gtlStruct *) enumerator_119301.current_value (HERE).ptr ()) ;
                          enumGalgasBool test_16 = kBoolTrue ;
                          if (kBoolTrue == test_16) {
                            test_16 = cast_119375_itemStruct.readProperty_value ().getter_hasKey (var_key_119212.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3816)).boolEnum () ;
                            if (kBoolTrue == test_16) {
                              GALGAS_gtlData var_keyValue_119498 ;
                              cast_119375_itemStruct.readProperty_value ().method_get (var_key_119212, var_keyValue_119498, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3817)) ;
                              {
                              var_resultMap_119270.setter_put (callExtensionGetter_lstring ((const cPtr_gtlData *) var_keyValue_119498.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3819)), enumerator_119301.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3818)) ;
                              }
                            }
                          }
                          if (kBoolFalse == test_16) {
                            TC_Array <C_FixItDescription> fixItArray17 ;
                            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("item at index ").add_operation (index_119296.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 3823)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3823)).add_operation (GALGAS_string (" does not have field named "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3823)).add_operation (var_key_119212.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3824)), fixItArray17  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3823)) ;
                          }
                        }else if (enumerator_119301.current_value (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlMap) {
                          GALGAS_gtlMap cast_119748_itemMap ((cPtr_gtlMap *) enumerator_119301.current_value (HERE).ptr ()) ;
                          enumGalgasBool test_18 = kBoolTrue ;
                          if (kBoolTrue == test_18) {
                            test_18 = cast_119748_itemMap.readProperty_value ().getter_hasKey (var_key_119212.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3827)).boolEnum () ;
                            if (kBoolTrue == test_18) {
                              GALGAS_gtlData var_keyValue_119862 ;
                              cast_119748_itemMap.readProperty_value ().method_get (var_key_119212, var_keyValue_119862, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3828)) ;
                              {
                              var_resultMap_119270.setter_put (callExtensionGetter_lstring ((const cPtr_gtlData *) var_keyValue_119862.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3830)), enumerator_119301.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3829)) ;
                              }
                            }
                          }
                          if (kBoolFalse == test_18) {
                            TC_Array <C_FixItDescription> fixItArray19 ;
                            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("item at index ").add_operation (index_119296.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 3834)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3834)).add_operation (GALGAS_string (" does not have field named "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3834)).add_operation (var_key_119212.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3835)), fixItArray19  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3834)) ;
                          }
                        }else{
                          TC_Array <C_FixItDescription> fixItArray20 ;
                          inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("list of struct expected"), fixItArray20  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3838)) ;
                        }
                      }
                      enumerator_119301.gotoNextObject () ;
                      index_119296.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3813)) ;
                    }
                    result_result = GALGAS_gtlMap::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3841)), var_resultMap_119270  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3841)) ;
                  }
                }
                if (kBoolFalse == test_14) {
                  enumGalgasBool test_21 = kBoolTrue ;
                  if (kBoolTrue == test_21) {
                    test_21 = GALGAS_bool (kIsEqual, GALGAS_string ("set").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                    if (kBoolTrue == test_21) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3843)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3843)) ;
                      }
                      GALGAS_lstringset var_resultSet_120360 = GALGAS_lstringset::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 3844)) ;
                      cEnumerator_list enumerator_120391 (this->mProperty_value, kENUMERATION_UP) ;
                      while (enumerator_120391.hasCurrentObject ()) {
                        GALGAS_lstring var_itemKey_120428 = callExtensionGetter_lstring ((const cPtr_gtlData *) enumerator_120391.current_value (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3846)) ;
                        enumGalgasBool test_22 = kBoolTrue ;
                        if (kBoolTrue == test_22) {
                          test_22 = var_resultSet_120360.getter_hasKey (var_itemKey_120428.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3847)).boolEnum () ;
                          if (kBoolTrue == test_22) {
                            {
                            var_resultSet_120360.setter_del (var_itemKey_120428, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3848)) ;
                            }
                          }
                        }
                        {
                        var_resultSet_120360.setter_put (var_itemKey_120428, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3850)) ;
                        }
                        enumerator_120391.gotoNextObject () ;
                      }
                      result_result = GALGAS_gtlSet::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3853)), var_resultSet_120360  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3852)) ;
                    }
                  }
                  if (kBoolFalse == test_21) {
                    enumGalgasBool test_23 = kBoolTrue ;
                    if (kBoolTrue == test_23) {
                      test_23 = GALGAS_bool (kIsEqual, GALGAS_string ("setBy").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                      if (kBoolTrue == test_23) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3856)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3856)) ;
                        }
                        GALGAS_lstring var_key_120791 = callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3857)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3857)) ;
                        GALGAS_lstringset var_resultSet_120850 = GALGAS_lstringset::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 3858)) ;
                        cEnumerator_list enumerator_120881 (this->mProperty_value, kENUMERATION_UP) ;
                        while (enumerator_120881.hasCurrentObject ()) {
                          GALGAS_gtlData var_field_120942 ;
                          GALGAS_bool joker_120948 ; // Joker input parameter
                          callExtensionMethod_structField ((cPtr_gtlData *) enumerator_120881.current_value (HERE).ptr (), var_key_120791, var_field_120942, joker_120948, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3860)) ;
                          GALGAS_lstring var_resKey_120971 = callExtensionGetter_lstring ((const cPtr_gtlData *) var_field_120942.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3861)) ;
                          enumGalgasBool test_24 = kBoolTrue ;
                          if (kBoolTrue == test_24) {
                            test_24 = var_resultSet_120850.getter_hasKey (var_resKey_120971.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3862)).boolEnum () ;
                            if (kBoolTrue == test_24) {
                              {
                              var_resultSet_120850.setter_del (var_resKey_120971, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3863)) ;
                              }
                            }
                          }
                          {
                          var_resultSet_120850.setter_put (var_resKey_120971, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3865)) ;
                          }
                          enumerator_120881.gotoNextObject () ;
                        }
                        result_result = GALGAS_gtlSet::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3868)), var_resultSet_120850  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3867)) ;
                      }
                    }
                    if (kBoolFalse == test_23) {
                      enumGalgasBool test_25 = kBoolTrue ;
                      if (kBoolTrue == test_25) {
                        test_25 = GALGAS_bool (kIsEqual, GALGAS_string ("componentsJoinedByString").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                        if (kBoolTrue == test_25) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3871)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3871)) ;
                          }
                          GALGAS_string var_joiner_121330 = callExtensionGetter_string ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3872)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3872)) ;
                          GALGAS_string var_stringResult_121387 = GALGAS_string::makeEmptyString () ;
                          cEnumerator_list enumerator_121414 (this->mProperty_value, kENUMERATION_UP) ;
                          while (enumerator_121414.hasCurrentObject ()) {
                            var_stringResult_121387 = var_stringResult_121387.add_operation (callExtensionGetter_string ((const cPtr_gtlData *) enumerator_121414.current_value (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3876)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3876)) ;
                            if (enumerator_121414.hasNextObject ()) {
                              var_stringResult_121387 = var_stringResult_121387.add_operation (var_joiner_121330, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3878)) ;
                            }
                            enumerator_121414.gotoNextObject () ;
                          }
                          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3881)), var_stringResult_121387  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3880)) ;
                        }
                      }
                      if (kBoolFalse == test_25) {
                        enumGalgasBool test_26 = kBoolTrue ;
                        if (kBoolTrue == test_26) {
                          test_26 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                          if (kBoolTrue == test_26) {
                            {
                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3884)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3884)) ;
                            }
                            const GALGAS_gtlList temp_27 = this ;
                            result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3886)), temp_27.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 3886))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3885)) ;
                          }
                        }
                        if (kBoolFalse == test_26) {
                          enumGalgasBool test_28 = kBoolTrue ;
                          if (kBoolTrue == test_28) {
                            test_28 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                            if (kBoolTrue == test_28) {
                              {
                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3889)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3889)) ;
                              }
                              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3891)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3890)) ;
                            }
                          }
                          if (kBoolFalse == test_28) {
                            enumGalgasBool test_29 = kBoolTrue ;
                            if (kBoolTrue == test_29) {
                              test_29 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                              if (kBoolTrue == test_29) {
                                {
                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3894)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3894)) ;
                                }
                                result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3896)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3895)) ;
                              }
                            }
                            if (kBoolFalse == test_29) {
                              enumGalgasBool test_30 = kBoolTrue ;
                              if (kBoolTrue == test_30) {
                                test_30 = GALGAS_bool (kIsEqual, GALGAS_string ("where").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                if (kBoolTrue == test_30) {
                                  enumGalgasBool test_31 = kBoolTrue ;
                                  if (kBoolTrue == test_31) {
                                    test_31 = GALGAS_bool (kIsStrictInf, constinArgument_arguments.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3899)).objectCompare (GALGAS_uint (uint32_t (1U)))).operator_or (GALGAS_bool (kIsStrictSup, constinArgument_arguments.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3899)).objectCompare (GALGAS_uint (uint32_t (2U)))) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3899)).boolEnum () ;
                                    if (kBoolTrue == test_31) {
                                      TC_Array <C_FixItDescription> fixItArray32 ;
                                      inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("where expects 1 ou 2 arguments. ").add_operation (constinArgument_arguments.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3901)).getter_string (SOURCE_FILE ("gtl_data_types.galgas", 3900)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3900)).add_operation (GALGAS_string (" arguments provided."), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3901)), fixItArray32  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3900)) ;
                                      result_result.drop () ; // Release error dropped variable
                                    }
                                  }
                                  if (kBoolFalse == test_31) {
                                    enumGalgasBool test_33 = kBoolTrue ;
                                    if (kBoolTrue == test_33) {
                                      test_33 = GALGAS_bool (kIsNotEqual, constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3903)).getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 3903)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlExpr))).boolEnum () ;
                                      if (kBoolTrue == test_33) {
                                        TC_Array <C_FixItDescription> fixItArray34 ;
                                        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("expression expected for argument 1"), fixItArray34  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3904)) ;
                                        result_result.drop () ; // Release error dropped variable
                                      }
                                    }
                                    if (kBoolFalse == test_33) {
                                      GALGAS_gtlStruct var_vars_122617 ;
                                      enumGalgasBool test_35 = kBoolTrue ;
                                      if (kBoolTrue == test_35) {
                                        test_35 = GALGAS_bool (kIsEqual, constinArgument_arguments.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3907)).objectCompare (GALGAS_uint (uint32_t (2U)))).boolEnum () ;
                                        if (kBoolTrue == test_35) {
                                          enumGalgasBool test_36 = kBoolTrue ;
                                          if (kBoolTrue == test_36) {
                                            test_36 = GALGAS_bool (kIsNotEqual, constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3908)).getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 3908)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct))).boolEnum () ;
                                            if (kBoolTrue == test_36) {
                                              TC_Array <C_FixItDescription> fixItArray37 ;
                                              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("struct expected for argument 1"), fixItArray37  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3909)) ;
                                              var_vars_122617.drop () ; // Release error dropped variable
                                            }
                                          }
                                          if (kBoolFalse == test_36) {
                                            GALGAS_gtlStruct temp_38 ;
                                            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3911)).isValid ()) {
                                              if (NULL != dynamic_cast <const cPtr_gtlStruct *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3911)).ptr ())) {
                                                temp_38 = (cPtr_gtlStruct *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3911)).ptr () ;
                                              }else{
                                                inCompiler->castError ("gtlStruct", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3911)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3911)) ;
                                              }
                                            }
                                            var_vars_122617 = temp_38 ;
                                          }
                                        }
                                      }
                                      if (kBoolFalse == test_35) {
                                        var_vars_122617 = GALGAS_gtlStruct::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3914)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 3914))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3914)) ;
                                      }
                                      GALGAS_gtlExpr temp_39 ;
                                      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3916)).isValid ()) {
                                        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3916)).ptr ())) {
                                          temp_39 = (cPtr_gtlExpr *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3916)).ptr () ;
                                        }else{
                                          inCompiler->castError ("gtlExpr", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3916)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3916)) ;
                                        }
                                      }
                                      GALGAS_gtlExpression var_expr_123008 = temp_39.readProperty_value () ;
                                      GALGAS_list var_resultList_123076 = GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 3917)) ;
                                      cEnumerator_list enumerator_123113 (this->mProperty_value, kENUMERATION_UP) ;
                                      while (enumerator_123113.hasCurrentObject ()) {
                                        {
                                        var_vars_122617.insulate (HERE) ;
                                        cPtr_gtlStruct * ptr_123152 = (cPtr_gtlStruct *) var_vars_122617.ptr () ;
                                        callExtensionSetter_setStructField ((cPtr_gtlStruct *) ptr_123152, GALGAS_lstring::constructor_new (GALGAS_string ("__item__"), enumerator_123113.current_value (HERE).readProperty_where ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3920)), enumerator_123113.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3920)) ;
                                        }
                                        GALGAS_gtlData var_evalResult_123244 = callExtensionGetter_eval ((const cPtr_gtlExpression *) var_expr_123008.ptr (), constinArgument_context, var_vars_122617, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3921)) ;
                                        enumGalgasBool test_40 = kBoolTrue ;
                                        if (kBoolTrue == test_40) {
                                          test_40 = callExtensionGetter_bool ((const cPtr_gtlData *) var_evalResult_123244.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3922)).boolEnum () ;
                                          if (kBoolTrue == test_40) {
                                            var_resultList_123076.addAssign_operation (enumerator_123113.current_value (HERE)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3923)) ;
                                          }
                                        }
                                        enumerator_123113.gotoNextObject () ;
                                      }
                                      result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3928)), var_resultList_123076  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3926)) ;
                                    }
                                  }
                                }
                              }
                              if (kBoolFalse == test_30) {
                                enumGalgasBool test_41 = kBoolTrue ;
                                if (kBoolTrue == test_41) {
                                  test_41 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("list"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3933)).boolEnum () ;
                                  if (kBoolTrue == test_41) {
                                    const GALGAS_gtlList temp_42 = this ;
                                    result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("list"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3934)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_42, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3934)) ;
                                  }
                                }
                                if (kBoolFalse == test_41) {
                                  enumGalgasBool test_43 = kBoolTrue ;
                                  if (kBoolTrue == test_43) {
                                    test_43 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                    if (kBoolTrue == test_43) {
                                      {
                                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3942)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3942)) ;
                                      }
                                      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3944)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3944))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3943)) ;
                                    }
                                  }
                                  if (kBoolFalse == test_43) {
                                    TC_Array <C_FixItDescription> fixItArray44 ;
                                    inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3947)).add_operation (GALGAS_string ("' for list target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3947)), fixItArray44  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3947)) ;
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
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3962)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3962)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3963)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3963)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3963)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3963)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3963)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_124492 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_124492.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3964)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3964)) ;
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
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3967)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3967)) ;
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
          routine_argumentsCheck (constinArgument_methodName, function_intAnyArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3970)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3970)) ;
          }
          GALGAS_uint var_insertIndex_124852 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3971)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3971)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3971)) ;
          GALGAS_gtlData var_node_124916 = constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3972)) ;
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsStrictInf, var_insertIndex_124852.objectCompare (object->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3973)))).boolEnum () ;
            if (kBoolTrue == test_4) {
              {
              object->mProperty_value.setter_insertAtIndex (var_node_124916, var_insertIndex_124852, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3974)) ;
              }
            }
          }
          if (kBoolFalse == test_4) {
            object->mProperty_value.addAssign_operation (var_node_124916  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3976)) ;
          }
          object->mProperty_where = constinArgument_methodName.readProperty_location () ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_5 = kBoolTrue ;
        if (kBoolTrue == test_5) {
          test_5 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("list"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3979)).boolEnum () ;
          if (kBoolTrue == test_5) {
            const GALGAS_gtlList temp_6 = object ;
            GALGAS_gtlData var_copy_125166 = temp_6 ;
            callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("list"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3981)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_125166, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3981)) ;
            GALGAS_gtlList temp_7 ;
            if (var_copy_125166.isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlList *> (var_copy_125166.ptr ())) {
                temp_7 = (cPtr_gtlList *) var_copy_125166.ptr () ;
              }else{
                inCompiler->castError ("gtlList", var_copy_125166.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3988)) ;
              }
            }
            object->mProperty_value = temp_7.readProperty_value () ;
            object->mProperty_where = var_copy_125166.readProperty_where () ;
            object->mProperty_meta = var_copy_125166.readProperty_meta () ;
          }
        }
        if (kBoolFalse == test_5) {
          TC_Array <C_FixItDescription> fixItArray8 ;
          inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3992)).add_operation (GALGAS_string ("' for list target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3992)), fixItArray8  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3992)) ;
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
  object->mProperty_value.setter_setValueAtIndex (constinArgument_data, constinArgument_index.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4000)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4000)) ;
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
  GALGAS_uint var_indexUint_125722 = constinArgument_index.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4006)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictInf, var_indexUint_125722.objectCompare (object->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4007)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, var_indexUint_125722.objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          object->mProperty_value = object->mProperty_value.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4009)) ;
        }
      }
      if (kBoolFalse == test_1) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = GALGAS_bool (kIsEqual, var_indexUint_125722.objectCompare (object->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4010)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4010)))).boolEnum () ;
          if (kBoolTrue == test_2) {
            object->mProperty_value = object->mProperty_value.getter_subListToIndex (var_indexUint_125722.substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4011)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4011)) ;
          }
        }
        if (kBoolFalse == test_2) {
          object->mProperty_value = object->mProperty_value.getter_subListToIndex (var_indexUint_125722.substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4013)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4013)).add_operation (object->mProperty_value.getter_subListFromIndex (var_indexUint_125722.add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4014)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4014)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4013)) ;
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
  outArgument_data = this->mProperty_value.getter_valueAtIndex (constinArgument_index.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4023)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4023)) ;
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
  result_result = GALGAS_bool (kIsStrictSup, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4030)).objectCompare (constinArgument_index.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4030)))) ;
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
  object->mProperty_value.addAssign_operation (constinArgument_item  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4036)) ;
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
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4048)).add_operation (GALGAS_string ("map: @[\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4048)) ;
  cEnumerator_gtlVarMap enumerator_126839 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_126839.hasCurrentObject ()) {
    result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4051))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4051)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4051)).add_operation (enumerator_126839.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4052)).add_operation (GALGAS_string ("\" :>\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4052)).add_operation (callExtensionGetter_desc ((const cPtr_gtlData *) enumerator_126839.current_value (HERE).ptr (), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (8U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4053)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4053)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4052)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4051)) ;
    enumerator_126839.gotoNextObject () ;
  }
  result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4055)).add_operation (GALGAS_string ("]\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4055)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4055)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4059)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4063)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a map to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4067)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a map to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4071)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a map to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4075)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4079)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4083)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4087)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4091)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4095)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4099)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4103)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4107)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4111)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4115)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4119)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4123)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4127)) ;
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
          inCompiler->castError ("gtlMap", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4132)) ;
        }
      }
      GALGAS_gtlVarMap var_rValue_129217 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_129261 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4134)).objectCompare (var_rValue_129217.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4134)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_129261 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_129261 = GALGAS_bool (true) ;
        cEnumerator_gtlVarMap enumerator_129375 (this->mProperty_value, kENUMERATION_UP) ;
        while (enumerator_129375.hasCurrentObject ()) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = var_rValue_129217.getter_hasKey (enumerator_129375.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4139)).boolEnum () ;
            if (kBoolTrue == test_3) {
              GALGAS_gtlData var_rData_129475 ;
              var_rValue_129217.method_get (enumerator_129375.current_lkey (HERE), var_rData_129475, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4140)) ;
              var_equal_129261 = var_equal_129261.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_129375.current_value (HERE).ptr (), var_rData_129475, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4141)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4141)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4141)) ;
            }
          }
          if (kBoolFalse == test_3) {
            var_equal_129261 = GALGAS_bool (false) ;
          }
          enumerator_129375.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4147)), var_equal_129261.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 4147))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4147)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("struct expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4149)) ;
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
          inCompiler->castError ("gtlMap", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4155)) ;
        }
      }
      GALGAS_gtlVarMap var_rValue_129848 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_129892 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4157)).objectCompare (var_rValue_129848.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4157)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_129892 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_129892 = GALGAS_bool (true) ;
        cEnumerator_gtlVarMap enumerator_130006 (this->mProperty_value, kENUMERATION_UP) ;
        while (enumerator_130006.hasCurrentObject ()) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = var_rValue_129848.getter_hasKey (enumerator_130006.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4162)).boolEnum () ;
            if (kBoolTrue == test_3) {
              GALGAS_gtlData var_rData_130106 ;
              var_rValue_129848.method_get (enumerator_130006.current_lkey (HERE), var_rData_130106, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4163)) ;
              var_equal_129892 = var_equal_129892.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_130006.current_value (HERE).ptr (), var_rData_130106, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4164)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4164)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4164)) ;
            }
          }
          if (kBoolFalse == test_3) {
            var_equal_129892 = GALGAS_bool (false) ;
          }
          enumerator_130006.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4170)), var_equal_129892  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4170)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("struct expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4172)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a map does not support the > operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4177)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a map does not support the >= operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4181)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a map does not support the < operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4185)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a map does not support the <= operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4189)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4194)) ;
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
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 4199))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4199)) ;
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
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4213)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4213)) ;
      }
      result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4216)), this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4217)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 4217))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4214)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4220)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4220)) ;
        }
        const GALGAS_gtlMap temp_2 = this ;
        result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4222)), temp_2.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 4222))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4221)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4225)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4225)) ;
          }
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4227)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4226)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("list").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4230)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4230)) ;
            }
            GALGAS_list var_resultList_132270 = GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 4231)) ;
            const GALGAS_gtlMap temp_5 = this ;
            cEnumerator_gtlVarMap enumerator_132314 (temp_5.readProperty_value (), kENUMERATION_UP) ;
            while (enumerator_132314.hasCurrentObject ()) {
              var_resultList_132270.addAssign_operation (enumerator_132314.current_value (HERE)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4233)) ;
              enumerator_132314.gotoNextObject () ;
            }
            result_result = GALGAS_gtlList::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4235)), var_resultList_132270  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4235)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_6 = kBoolTrue ;
          if (kBoolTrue == test_6) {
            test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("where").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_6) {
              enumGalgasBool test_7 = kBoolTrue ;
              if (kBoolTrue == test_7) {
                test_7 = GALGAS_bool (kIsStrictInf, constinArgument_arguments.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4237)).objectCompare (GALGAS_uint (uint32_t (1U)))).operator_or (GALGAS_bool (kIsStrictSup, constinArgument_arguments.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4237)).objectCompare (GALGAS_uint (uint32_t (2U)))) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4237)).boolEnum () ;
                if (kBoolTrue == test_7) {
                  TC_Array <C_FixItDescription> fixItArray8 ;
                  inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("where expects 1 ou 2 arguments. ").add_operation (constinArgument_arguments.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4239)).getter_string (SOURCE_FILE ("gtl_data_types.galgas", 4238)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4238)).add_operation (GALGAS_string (" arguments provided."), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4239)), fixItArray8  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4238)) ;
                  result_result.drop () ; // Release error dropped variable
                }
              }
              if (kBoolFalse == test_7) {
                enumGalgasBool test_9 = kBoolTrue ;
                if (kBoolTrue == test_9) {
                  test_9 = GALGAS_bool (kIsNotEqual, constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4241)).getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 4241)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlExpr))).boolEnum () ;
                  if (kBoolTrue == test_9) {
                    TC_Array <C_FixItDescription> fixItArray10 ;
                    inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("expression expected for argument 1"), fixItArray10  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4242)) ;
                    result_result.drop () ; // Release error dropped variable
                  }
                }
                if (kBoolFalse == test_9) {
                  GALGAS_gtlStruct var_vars_132853 ;
                  enumGalgasBool test_11 = kBoolTrue ;
                  if (kBoolTrue == test_11) {
                    test_11 = GALGAS_bool (kIsEqual, constinArgument_arguments.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4245)).objectCompare (GALGAS_uint (uint32_t (2U)))).boolEnum () ;
                    if (kBoolTrue == test_11) {
                      enumGalgasBool test_12 = kBoolTrue ;
                      if (kBoolTrue == test_12) {
                        test_12 = GALGAS_bool (kIsNotEqual, constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4246)).getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 4246)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct))).boolEnum () ;
                        if (kBoolTrue == test_12) {
                          TC_Array <C_FixItDescription> fixItArray13 ;
                          inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("struct expected for argument 1"), fixItArray13  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4247)) ;
                          var_vars_132853.drop () ; // Release error dropped variable
                        }
                      }
                      if (kBoolFalse == test_12) {
                        GALGAS_gtlStruct temp_14 ;
                        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4249)).isValid ()) {
                          if (NULL != dynamic_cast <const cPtr_gtlStruct *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4249)).ptr ())) {
                            temp_14 = (cPtr_gtlStruct *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4249)).ptr () ;
                          }else{
                            inCompiler->castError ("gtlStruct", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4249)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4249)) ;
                          }
                        }
                        var_vars_132853 = temp_14 ;
                      }
                    }
                  }
                  if (kBoolFalse == test_11) {
                    var_vars_132853 = GALGAS_gtlStruct::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4252)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 4252))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4252)) ;
                  }
                  GALGAS_gtlExpr temp_15 ;
                  if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4254)).isValid ()) {
                    if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4254)).ptr ())) {
                      temp_15 = (cPtr_gtlExpr *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4254)).ptr () ;
                    }else{
                      inCompiler->castError ("gtlExpr", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4254)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4254)) ;
                    }
                  }
                  GALGAS_gtlExpression var_expr_133244 = temp_15.readProperty_value () ;
                  GALGAS_gtlVarMap var_resultMap_133317 = GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 4255)) ;
                  cEnumerator_gtlVarMap enumerator_133356 (this->mProperty_value, kENUMERATION_UP) ;
                  while (enumerator_133356.hasCurrentObject ()) {
                    {
                    var_vars_132853.insulate (HERE) ;
                    cPtr_gtlStruct * ptr_133395 = (cPtr_gtlStruct *) var_vars_132853.ptr () ;
                    callExtensionSetter_setStructField ((cPtr_gtlStruct *) ptr_133395, GALGAS_lstring::constructor_new (GALGAS_string ("__item__"), enumerator_133356.current_value (HERE).readProperty_where ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4258)), enumerator_133356.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4258)) ;
                    }
                    GALGAS_gtlData var_evalResult_133487 = callExtensionGetter_eval ((const cPtr_gtlExpression *) var_expr_133244.ptr (), constinArgument_context, var_vars_132853, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4259)) ;
                    enumGalgasBool test_16 = kBoolTrue ;
                    if (kBoolTrue == test_16) {
                      test_16 = callExtensionGetter_bool ((const cPtr_gtlData *) var_evalResult_133487.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4260)).boolEnum () ;
                      if (kBoolTrue == test_16) {
                        {
                        var_resultMap_133317.setter_put (enumerator_133356.current_lkey (HERE), enumerator_133356.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4261)) ;
                        }
                      }
                    }
                    enumerator_133356.gotoNextObject () ;
                  }
                  result_result = GALGAS_gtlMap::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4266)), var_resultMap_133317  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4264)) ;
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
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4272)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4272)) ;
                }
                result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4274)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4273)) ;
              }
            }
            if (kBoolFalse == test_17) {
              enumGalgasBool test_18 = kBoolTrue ;
              if (kBoolTrue == test_18) {
                test_18 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("map"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4276)).boolEnum () ;
                if (kBoolTrue == test_18) {
                  const GALGAS_gtlMap temp_19 = this ;
                  result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("map"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4277)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_19, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4277)) ;
                }
              }
              if (kBoolFalse == test_18) {
                enumGalgasBool test_20 = kBoolTrue ;
                if (kBoolTrue == test_20) {
                  test_20 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_20) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4285)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4285)) ;
                    }
                    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4287)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4287))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4286)) ;
                  }
                }
                if (kBoolFalse == test_20) {
                  TC_Array <C_FixItDescription> fixItArray21 ;
                  inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4290)).add_operation (GALGAS_string ("' for map target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4290)), fixItArray21  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4290)) ;
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
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4305)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4305)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4306)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4306)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4306)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4306)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4306)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_134905 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_134905.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4307)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4307)) ;
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
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4310)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4310)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("map"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4312)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlMap temp_4 = object ;
          GALGAS_gtlData var_copy_135212 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("map"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4314)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_135212, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4314)) ;
          GALGAS_gtlMap temp_5 ;
          if (var_copy_135212.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlMap *> (var_copy_135212.ptr ())) {
              temp_5 = (cPtr_gtlMap *) var_copy_135212.ptr () ;
            }else{
              inCompiler->castError ("gtlMap", var_copy_135212.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4321)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_135212.readProperty_where () ;
          object->mProperty_meta = var_copy_135212.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4325)).add_operation (GALGAS_string ("' for map target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4325)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4325)) ;
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
  extensionSetter_replaceOrCreate (object->mProperty_value, constinArgument_name, constinArgument_data, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4336)) ;
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
  GALGAS_gtlData joker_135932 ; // Joker input parameter
  object->mProperty_value.setter_del (constinArgument_name, joker_135932, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4342)) ;
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
    test_0 = this->mProperty_value.getter_hasKey (constinArgument_name.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4349)).boolEnum () ;
    if (kBoolTrue == test_0) {
      this->mProperty_value.method_get (constinArgument_name, outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4350)) ;
    }
  }
  if (kBoolFalse == test_0) {
    outArgument_result = GALGAS_gtlUnconstructed::constructor_new (constinArgument_name.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4352))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4352)) ;
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
  result_result = this->mProperty_value.getter_hasKey (constinArgument_name.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4360)) ;
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
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4372)).add_operation (GALGAS_string ("expression: @\? "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4372)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_value.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4373)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4373)).add_operation (GALGAS_string (" \?\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4373)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("expression forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4377)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("expression forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4381)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an expression to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4385)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an expression to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4389)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an expression to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4393)) ;
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
  result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4403)), GALGAS_gtlMinusExpression::constructor_new (this->mProperty_where, this->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4404))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4401)) ;
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
  result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4411)), GALGAS_gtlNotExpression::constructor_new (this->mProperty_where, this->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4412))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4409)) ;
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
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4421)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4420)), GALGAS_gtlAddExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4421))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4418)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4424)) ;
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
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4433)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4432)), GALGAS_gtlSubstractExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4433))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4430)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4436)) ;
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
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4445)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4444)), GALGAS_gtlMultiplyExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4445))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4442)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4448)) ;
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
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4457)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4456)), GALGAS_gtlDivideExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4457))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4454)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4460)) ;
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
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4469)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4468)), GALGAS_gtlModulusExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4469))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4466)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4472)) ;
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
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4481)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4480)), GALGAS_gtlAndExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4481))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4478)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4484)) ;
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
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4493)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4492)), GALGAS_gtlOrExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4493))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4490)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4496)) ;
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
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4505)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4504)), GALGAS_gtlXorExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4505))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4502)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4508)) ;
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
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4517)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4516)), GALGAS_gtlShiftLeftExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4517))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4514)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4520)) ;
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
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4529)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4528)), GALGAS_gtlShiftRightExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4529))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4526)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4532)) ;
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
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4541)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4540)), GALGAS_gtlNotEqualExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4541))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4538)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4544)) ;
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
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4553)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4552)), GALGAS_gtlEqualExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4553))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4550)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4556)) ;
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
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4565)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4564)), GALGAS_gtlGreaterThanExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4565))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4562)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4568)) ;
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
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4577)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4576)), GALGAS_gtlGreaterOrEqualExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4577))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4574)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4580)) ;
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
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4589)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4588)), GALGAS_gtlLowerThanExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4589))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4586)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4592)) ;
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
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4601)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4600)), GALGAS_gtlLowerOrEqualExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4601))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4598)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4604)) ;
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
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("expression forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4610)) ;
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
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 4615))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4615)) ;
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
      routine_argumentsCheck (constinArgument_methodName, function_structArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4629)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4629)) ;
      }
      GALGAS_gtlData var_vars_143580 = constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4630)) ;
      result_result = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_value.ptr (), constinArgument_context, var_vars_143580, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4631)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4633)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4633)) ;
        }
        const GALGAS_gtlExpr temp_2 = this ;
        result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4635)), temp_2.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 4635))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4634)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4638)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4638)) ;
          }
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4640)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4639)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4643)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4643)) ;
            }
            result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4645)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4644)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_5) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4648)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4648)) ;
              }
              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4650)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4650))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4649)) ;
            }
          }
          if (kBoolFalse == test_5) {
            enumGalgasBool test_6 = kBoolTrue ;
            if (kBoolTrue == test_6) {
              test_6 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("expression"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4652)).boolEnum () ;
              if (kBoolTrue == test_6) {
                const GALGAS_gtlExpr temp_7 = this ;
                result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("expression"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4653)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_7, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4653)) ;
              }
            }
            if (kBoolFalse == test_6) {
              TC_Array <C_FixItDescription> fixItArray8 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4661)).add_operation (GALGAS_string ("' for expression target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4661)), fixItArray8  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4661)) ;
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
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4676)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4676)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4677)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4677)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4677)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4677)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4677)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_145216 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_145216.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4678)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4678)) ;
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
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4681)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4681)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("expression"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4683)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlExpr temp_4 = object ;
          GALGAS_gtlData var_copy_145530 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("expression"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4685)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_145530, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4685)) ;
          GALGAS_gtlExpr temp_5 ;
          if (var_copy_145530.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlExpr *> (var_copy_145530.ptr ())) {
              temp_5 = (cPtr_gtlExpr *) var_copy_145530.ptr () ;
            }else{
              inCompiler->castError ("gtlExpr", var_copy_145530.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4692)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_145530.readProperty_where () ;
          object->mProperty_meta = var_copy_145530.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4696)).add_operation (GALGAS_string ("' for expression target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4696)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4696)) ;
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
  GALGAS_uint var_currentErrorCount_12226 = GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 418)) ;
  GALGAS_string var_fullFileName_12277 = callExtensionGetter_string ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_fileNameExpression.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 419)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 419)) ;
  GALGAS_gtlString var_fileName_12364 = GALGAS_gtlString::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 422)), var_fullFileName_12277.getter_lastPathComponent (SOURCE_FILE ("gtl_instructions.galgas", 423))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 420)) ;
  GALGAS_gtlString var_filePath_12471 = GALGAS_gtlString::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 427)), var_fullFileName_12277.getter_nativePathWithUnixPath (SOURCE_FILE ("gtl_instructions.galgas", 428))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 425)) ;
  GALGAS_string var_result_12578 = GALGAS_string::makeEmptyString () ;
  GALGAS_gtlData var_varsCopy_12601 = ioArgument_vars ;
  {
  var_varsCopy_12601.insulate (HERE) ;
  cPtr_gtlData * ptr_12703 = (cPtr_gtlData *) var_varsCopy_12601.ptr () ;
  callExtensionSetter_setStructFieldAtLevel ((cPtr_gtlData *) ptr_12703, GALGAS_lstring::constructor_new (GALGAS_string ("FILENAME"), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 435)), var_fileName_12364, GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 434)) ;
  }
  {
  var_varsCopy_12601.insulate (HERE) ;
  cPtr_gtlData * ptr_12802 = (cPtr_gtlData *) var_varsCopy_12601.ptr () ;
  callExtensionSetter_setStructFieldAtLevel ((cPtr_gtlData *) ptr_12802, GALGAS_lstring::constructor_new (GALGAS_string ("FILEPATH"), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 440)), var_filePath_12471, GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 439)) ;
  }
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, var_currentErrorCount_12226.objectCompare (GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 445)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      extensionMethod_execute (this->mProperty_instructions, ioArgument_context, var_varsCopy_12601, ioArgument_lib, var_result_12578, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 446)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, var_currentErrorCount_12226.objectCompare (GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 447)))).boolEnum () ;
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
    if (NULL != dynamic_cast <const cPtr_gtlString *> (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_fileName.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)).ptr ())) {
      temp_1 = (cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_fileName.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)).ptr () ;
    }else{
      inCompiler->castError ("gtlString", callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_fileName.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)) ;
    }
  }
  GALGAS_lstring var_templateFileName_14104 = callExtensionGetter_fullTemplateFileName ((const cPtr_gtlContext *) var_newContext_14000.ptr (), ioArgument_context, ioArgument_vars, callExtensionGetter_lstring ((const cPtr_gtlString *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 483)) ;
  GALGAS_gtlData var_localVars_14262 ;
  {
  var_newContext_14000.setter_setInputVars (GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("gtl_instructions.galgas", 490)) COMMA_SOURCE_FILE ("gtl_instructions.galgas", 490)) ;
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = this->mProperty_isGlobal.operator_not (SOURCE_FILE ("gtl_instructions.galgas", 491)).boolEnum () ;
    if (kBoolTrue == test_2) {
      var_localVars_14262 = GALGAS_gtlStruct::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 493)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_instructions.galgas", 493))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 493)) ;
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
  extensionMethod_set (this->mProperty_destVariable, ioArgument_context, ioArgument_vars, ioArgument_lib, GALGAS_gtlString::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 552)), var_value_15713  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 552)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 548)) ;
}

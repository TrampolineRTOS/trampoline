#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-10.h"

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
  GALGAS_lstring var_indexName_21672 = GALGAS_lstring::constructor_new (GALGAS_string ("INDEX"), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 737)) ;
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
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_21906, var_indexName_21672, GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 745)), index_21749.getter_bigint (SOURCE_FILE ("gtl_instructions.galgas", 745))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 745)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 743)) ;
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
            callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_23890, this->mProperty_identifier, GALGAS_gtlInt::constructor_new (this->mProperty_identifier.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 805)), var_startVal_23123  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 805)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 803)) ;
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
  GALGAS_gtlData var_variable_28714 = extensionGetter_get (this->mProperty_variablePath, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 950)) ;
  inCompiler->printMessage (extensionGetter_stringPath (this->mProperty_variablePath, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 951)).add_operation (GALGAS_string (" from "), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 951)).add_operation (this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 952)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 952)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 952)).add_operation (callExtensionGetter_desc ((const cPtr_gtlData *) var_variable_28714.ptr (), GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 953)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 952))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 951)) ;
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
      extensionMethod_set (this->mProperty_variablePath, ioArgument_context, ioArgument_vars, ioArgument_lib, GALGAS_gtlList::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1036)), var_listToSort_30759  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1036)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1032)) ;
    }else{
      GALGAS_gtlVarItem var_lastComponent_31089 ;
      this->mProperty_variablePath.method_last (var_lastComponent_31089, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1039)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlVarItem *) var_lastComponent_31089.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1040)), GALGAS_string ("list expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1040)) ;
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
              ioArgument_outputString.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), var_tabColumn_33676.substract_operation (var_currentColumn_33578, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1134)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1134))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1132)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1132)) ;
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
  GALGAS_string var_delimitor_36074 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (61)), GALGAS_uint (uint32_t (79U))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1215)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1215)) ;
  GALGAS_string var_varDelim_36157 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (45)), GALGAS_uint (uint32_t (79U))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1216)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1216)) ;
  GALGAS_string var_separator_36240 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (61)), GALGAS_uint (uint32_t (17U))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1217)) ;
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
  GALGAS_gtlDataList var_dataArguments_38432 = GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("gtl_instructions.galgas", 1308)) ;
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  GALGAS_string var_version_3232 = GALGAS_application::constructor_projectVersionString (SOURCE_FILE ("gtl_functions.galgas", 105)) ;
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


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_majorVersion [1] = {
  nullptr
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
  GALGAS_string var_version_3766 = GALGAS_application::constructor_projectVersionString (SOURCE_FILE ("gtl_functions.galgas", 120)) ;
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


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_minorVersion [1] = {
  nullptr
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
  GALGAS_string var_version_4291 = GALGAS_application::constructor_projectVersionString (SOURCE_FILE ("gtl_functions.galgas", 135)) ;
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


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_revision [1] = {
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_signature [2] = {
  & kTypeDescriptor_GALGAS_location,
  nullptr
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
  result_bold = GALGAS_string ("[1m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_bold (nullptr,
                                                  releaseOnceFunctionResult_bold) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_bold [1] = {
  nullptr
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
  result_underline = GALGAS_string ("[4m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_underline (nullptr,
                                                       releaseOnceFunctionResult_underline) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_underline [1] = {
  nullptr
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
  result_blink = GALGAS_string ("[5m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_blink (nullptr,
                                                   releaseOnceFunctionResult_blink) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_blink [1] = {
  nullptr
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
  result_black = GALGAS_string ("[90m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_black (nullptr,
                                                   releaseOnceFunctionResult_black) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_black [1] = {
  nullptr
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
  result_red = GALGAS_string ("[91m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_red (nullptr,
                                                 releaseOnceFunctionResult_red) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_red [1] = {
  nullptr
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
  result_green = GALGAS_string ("[92m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_green (nullptr,
                                                   releaseOnceFunctionResult_green) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_green [1] = {
  nullptr
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
  result_yellow = GALGAS_string ("[93m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_yellow (nullptr,
                                                    releaseOnceFunctionResult_yellow) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_yellow [1] = {
  nullptr
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
  result_blue = GALGAS_string ("[94m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_blue (nullptr,
                                                  releaseOnceFunctionResult_blue) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_blue [1] = {
  nullptr
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
  result_magenta = GALGAS_string ("[95m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_magenta (nullptr,
                                                     releaseOnceFunctionResult_magenta) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_magenta [1] = {
  nullptr
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
  result_cyan = GALGAS_string ("[96m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_cyan (nullptr,
                                                  releaseOnceFunctionResult_cyan) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_cyan [1] = {
  nullptr
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
  result_red = GALGAS_string ("[31m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_darkred (nullptr,
                                                     releaseOnceFunctionResult_darkred) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkred [1] = {
  nullptr
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
  result_green = GALGAS_string ("[32m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_darkgreen (nullptr,
                                                       releaseOnceFunctionResult_darkgreen) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkgreen [1] = {
  nullptr
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
  result_yellow = GALGAS_string ("[33m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_darkyellow (nullptr,
                                                        releaseOnceFunctionResult_darkyellow) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkyellow [1] = {
  nullptr
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
  result_blue = GALGAS_string ("[34m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_darkblue (nullptr,
                                                      releaseOnceFunctionResult_darkblue) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkblue [1] = {
  nullptr
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
  result_magenta = GALGAS_string ("[35m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_darkmagenta (nullptr,
                                                         releaseOnceFunctionResult_darkmagenta) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkmagenta [1] = {
  nullptr
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
  result_cyan = GALGAS_string ("[36m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_darkcyan (nullptr,
                                                      releaseOnceFunctionResult_darkcyan) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkcyan [1] = {
  nullptr
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
  result_white = GALGAS_string ("[97m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_white (nullptr,
                                                   releaseOnceFunctionResult_white) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_white [1] = {
  nullptr
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
  result_endc = GALGAS_string ("[0m") ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_endc (nullptr,
                                                  releaseOnceFunctionResult_endc) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_endc [1] = {
  nullptr
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
  nullptr
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
    test_0 = GALGAS_bool (kIsStrictSup, this->mProperty_arguments.getter_count (SOURCE_FILE ("gtl_debugger.galgas", 834)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
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


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlMap::getter_stringRepresentation (C_Compiler * inCompiler
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


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlStruct::getter_stringRepresentation (C_Compiler * inCompiler
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


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlSet::getter_stringRepresentation (C_Compiler * inCompiler
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
  const enumGalgasBool test_7 = this->mProperty_ifExists.operator_and (GALGAS_bool (kIsStrictSup, this->mProperty_instructionsIfNotFound.getter_count (SOURCE_FILE ("gtl_debugger.galgas", 1348)).objectCompare (GALGAS_uint (uint32_t (0U)))) COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1348)).boolEnum () ;
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
      GALGAS_gtlTerminal cast_42105_term ((cPtr_gtlTerminal *) this->mProperty_limit.ptr ()) ;
      if (cast_42105_term.readProperty_value ().isValid ()) {
        if (cast_42105_term.readProperty_value ().dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
          GALGAS_gtlInt cast_42153_intLimit ((cPtr_gtlInt *) cast_42105_term.readProperty_value ().ptr ()) ;
          enumGalgasBool test_0 = kBoolTrue ;
          if (kBoolTrue == test_0) {
            test_0 = GALGAS_bool (kIsNotEqual, cast_42153_intLimit.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1406)).objectCompare (GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_debugger.galgas", 1406)))).boolEnum () ;
            if (kBoolTrue == test_0) {
              inCompiler->printMessage (GALGAS_string (" (").add_operation (callExtensionGetter_string ((const cPtr_gtlInt *) cast_42153_intLimit.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1407)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1407)).add_operation (GALGAS_string (")"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1407))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1407)) ;
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
  const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, this->mProperty_arguments.getter_count (SOURCE_FILE ("gtl_debugger.galgas", 1421)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
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
  cPtr_gtlContext * ptr_44266 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_setLoopOnCommand ((cPtr_gtlContext *) ptr_44266, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1482)) ;
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
  cPtr_gtlContext * ptr_44830 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_appendInstructionToStepDo ((cPtr_gtlContext *) ptr_44830, this->mProperty_instructionToDo, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1504)) ;
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
  cPtr_gtlContext * ptr_45425 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteStepDoInstruction ((cPtr_gtlContext *) ptr_45425, this->mProperty_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1527)) ;
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
  cPtr_gtlContext * ptr_45993 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteAllStepDoInstructions ((cPtr_gtlContext *) ptr_45993, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1548)) ;
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
  cPtr_gtlContext * ptr_47034 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_setBreakOnNext ((cPtr_gtlContext *) ptr_47034, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1590)) ;
  }
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_47070 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_setLoopOnCommand ((cPtr_gtlContext *) ptr_47070, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1591)) ;
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
  GALGAS_gtlInstructionList var_instructionList_47650 = ioArgument_context.readProperty_debuggerContext ().readProperty_instructionList () ;
  GALGAS_string var_localFileName_47722 = GALGAS_string::makeEmptyString () ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_instructionList_47650.getter_count (SOURCE_FILE ("gtl_debugger.galgas", 1616)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      var_localFileName_47722 = callExtensionGetter_location ((const cPtr_gtlInstruction *) var_instructionList_47650.getter_instructionAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1618)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1618)).getter_file (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1618)).getter_lastPathComponent (SOURCE_FILE ("gtl_debugger.galgas", 1619)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, this->mProperty_fileName.objectCompare (var_localFileName_47722)).operator_or (GALGAS_bool (kIsEqual, this->mProperty_fileName.objectCompare (GALGAS_string::makeEmptyString ())) COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1621)).boolEnum () ;
        if (kBoolTrue == test_1) {
          inCompiler->printMessage (GALGAS_string ("Setting breakpoint at ").add_operation (var_localFileName_47722, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1622)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1622)).add_operation (this->mProperty_lineNum.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1622)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1622)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1622))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1622)) ;
          {
          ioArgument_context.insulate (HERE) ;
          cPtr_gtlContext * ptr_48038 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
          callExtensionSetter_setBreakpoint ((cPtr_gtlContext *) ptr_48038, var_localFileName_47722, this->mProperty_lineNum, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1623)) ;
          }
        }
      }
      if (kBoolFalse == test_1) {
        inCompiler->printMessage (GALGAS_string ("Setting breakpoint at ").add_operation (this->mProperty_fileName, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1625)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1625)).add_operation (this->mProperty_lineNum.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1625)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1625)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1625))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1625)) ;
        {
        ioArgument_context.insulate (HERE) ;
        cPtr_gtlContext * ptr_48181 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
        callExtensionSetter_setBreakpoint ((cPtr_gtlContext *) ptr_48181, this->mProperty_fileName, this->mProperty_lineNum, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1626)) ;
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
  cPtr_gtlContext * ptr_49427 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteBreakpoint ((cPtr_gtlContext *) ptr_49427, this->mProperty_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1673)) ;
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
  cPtr_gtlContext * ptr_50035 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteAllBreakpoints ((cPtr_gtlContext *) ptr_50035, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1694)) ;
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
  cPtr_gtlContext * ptr_50627 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_setWatchpoint ((cPtr_gtlContext *) ptr_50627, this->mProperty_watchExpression, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1716)) ;
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
  cPtr_gtlContext * ptr_51813 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteWatchpoint ((cPtr_gtlContext *) ptr_51813, this->mProperty_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1759)) ;
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
  cPtr_gtlContext * ptr_52422 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteAllWatchpoints ((cPtr_gtlContext *) ptr_52422, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1780)) ;
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
  GALGAS_stringset var_newValues_16786 = constinArgument_newEnum.readProperty_valuesMap ().getter_keySet (SOURCE_FILE ("implementation_parser.galgas", 614)) ;
  GALGAS_stringset var_previousValues_16844 = constinArgument_previousEnum.readProperty_valuesMap ().getter_keySet (SOURCE_FILE ("implementation_parser.galgas", 615)) ;
  result_inside = GALGAS_bool (kIsEqual, var_newValues_16786.operator_and (var_previousValues_16844 COMMA_SOURCE_FILE ("implementation_parser.galgas", 616)).objectCompare (var_newValues_16786)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = result_inside.operator_not (SOURCE_FILE ("implementation_parser.galgas", 617)).boolEnum () ;
    if (kBoolTrue == test_0) {
      cEnumerator_locationList enumerator_16977 (constinArgument_newEnum.readProperty_locations (), kENUMERATION_UP) ;
      while (enumerator_16977.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (enumerator_16977.current_location (HERE), GALGAS_string ("ENUM is not within previous enum declaration"), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 619)) ;
        enumerator_16977.gotoNextObject () ;
      }
      cEnumerator_locationList enumerator_17091 (constinArgument_previousEnum.readProperty_locations (), kENUMERATION_UP) ;
      while (enumerator_17091.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (enumerator_17091.current_location (HERE), GALGAS_string ("previous ENUM declaration was here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_parser.galgas", 622)) ;
        enumerator_17091.gotoNextObject () ;
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
  nullptr
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
      cEnumerator_locationList enumerator_17457 (constinArgument_newRanged.readProperty_locations (), kENUMERATION_UP) ;
      while (enumerator_17457.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (enumerator_17457.current_location (HERE), GALGAS_string ("new range or set is not within previous range or set declaration"), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 638)) ;
        enumerator_17457.gotoNextObject () ;
      }
      cEnumerator_locationList enumerator_17593 (constinArgument_previousRanged.readProperty_locations (), kENUMERATION_UP) ;
      while (enumerator_17593.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (enumerator_17593.current_location (HERE), GALGAS_string ("previous range or set declaration was here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_parser.galgas", 641)) ;
        enumerator_17593.gotoNextObject () ;
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
  nullptr
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
      cEnumerator_locationList enumerator_17915 (constinArgument_newType.readProperty_locations (), kENUMERATION_UP) ;
      while (enumerator_17915.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (enumerator_17915.current_location (HERE), constinArgument_name.readProperty_string ().add_operation (GALGAS_string (" should be a "), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 654)).add_operation (extensionGetter_oilType (constinArgument_previousType.readProperty_type (), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 654)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 654)), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 654)) ;
        enumerator_17915.gotoNextObject () ;
      }
      cEnumerator_locationList enumerator_18042 (constinArgument_previousType.readProperty_locations (), kENUMERATION_UP) ;
      while (enumerator_18042.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (enumerator_18042.current_location (HERE), constinArgument_name.readProperty_string ().add_operation (GALGAS_string (" was previouly defined here"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 657)), fixItArray2  COMMA_SOURCE_FILE ("implementation_parser.galgas", 657)) ;
        enumerator_18042.gotoNextObject () ;
      }
      result_result = GALGAS_bool (false) ;
    }
  }
  if (kBoolFalse == test_0) {
    if (constinArgument_previousType.isValid ()) {
      if (constinArgument_previousType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
        GALGAS_impEnumType cast_18223_previousEnum ((cPtr_impEnumType *) constinArgument_previousType.ptr ()) ;
        if (constinArgument_newType.isValid ()) {
          if (constinArgument_newType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
            GALGAS_impEnumType cast_18284_newEnum ((cPtr_impEnumType *) constinArgument_newType.ptr ()) ;
            result_result = function_checkEnums (cast_18223_previousEnum, cast_18284_newEnum, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 665)) ;
          }
        }
      }else if (constinArgument_previousType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impRangedType) {
        GALGAS_impRangedType cast_18388_previousRanged ((cPtr_impRangedType *) constinArgument_previousType.ptr ()) ;
        if (constinArgument_newType.isValid ()) {
          if (constinArgument_newType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impRangedType) {
            GALGAS_impRangedType cast_18453_newRanged ((cPtr_impRangedType *) constinArgument_newType.ptr ()) ;
            result_result = function_checkRanged (cast_18388_previousRanged, cast_18453_newRanged, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 670)) ;
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
  nullptr
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
  nullptr
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
  cEnumerator_uint_33__32_List enumerator_2571 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_2571.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2571.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 85)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 85)) ;
    if (enumerator_2571.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 85)) ;
    }
    enumerator_2571.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringWithUInt_33__32_List [2] = {
  & kTypeDescriptor_GALGAS_uint_33__32_List,
  nullptr
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
  cEnumerator_uint_36__34_List enumerator_2733 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_2733.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2733.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 90)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 90)) ;
    if (enumerator_2733.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 90)) ;
    }
    enumerator_2733.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringWithUInt_36__34_List [2] = {
  & kTypeDescriptor_GALGAS_uint_36__34_List,
  nullptr
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
  cEnumerator_sint_33__32_List enumerator_2895 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_2895.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2895.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 95)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 95)) ;
    if (enumerator_2895.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 95)) ;
    }
    enumerator_2895.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringWithSInt_33__32_List [2] = {
  & kTypeDescriptor_GALGAS_sint_33__32_List,
  nullptr
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
  cEnumerator_sint_36__34_List enumerator_3057 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_3057.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_3057.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 100)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 100)) ;
    if (enumerator_3057.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 100)) ;
    }
    enumerator_3057.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringWithSInt_36__34_List [2] = {
  & kTypeDescriptor_GALGAS_sint_36__34_List,
  nullptr
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
  cEnumerator_floatList enumerator_3217 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_3217.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_3217.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 105)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 105)) ;
    if (enumerator_3217.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 105)) ;
    }
    enumerator_3217.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringWithFloatList [2] = {
  & kTypeDescriptor_GALGAS_floatList,
  nullptr
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
  cEnumerator_numberList enumerator_3408 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_3408.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3408.current_location (HERE), function_uint_33__32_OrError (enumerator_3408.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 111))  COMMA_SOURCE_FILE ("implementation_types.galgas", 111)) ;
    enumerator_3408.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_uint_33__32_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  nullptr
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
  cEnumerator_numberList enumerator_3606 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_3606.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3606.current_location (HERE), function_sint_33__32_OrError (enumerator_3606.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 118))  COMMA_SOURCE_FILE ("implementation_types.galgas", 118)) ;
    enumerator_3606.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_sint_33__32_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  nullptr
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
  cEnumerator_numberList enumerator_3804 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_3804.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3804.current_location (HERE), function_uint_36__34_OrError (enumerator_3804.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 125))  COMMA_SOURCE_FILE ("implementation_types.galgas", 125)) ;
    enumerator_3804.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_uint_36__34_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  nullptr
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
  cEnumerator_numberList enumerator_4002 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_4002.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_4002.current_location (HERE), function_sint_36__34_OrError (enumerator_4002.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 132))  COMMA_SOURCE_FILE ("implementation_types.galgas", 132)) ;
    enumerator_4002.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_sint_36__34_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  nullptr
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
  cEnumerator_numberList enumerator_4197 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_4197.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_4197.current_location (HERE), function_floatOrError (enumerator_4197.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 139))  COMMA_SOURCE_FILE ("implementation_types.galgas", 139)) ;
    enumerator_4197.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_floatListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  nullptr
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
      GALGAS_uint_33__32_AttributeSet cast_4955_set ((cPtr_uint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_uint_33__32_List enumerator_4969 (cast_4955_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_4969.hasCurrentObject ()) {
        GALGAS_bool var_ok_5012 = GALGAS_bool (false) ;
        cEnumerator_uint_33__32_List enumerator_5033 (this->mProperty_valueList, kENUMERATION_UP) ;
        while (enumerator_5033.hasCurrentObject ()) {
          enumGalgasBool test_0 = kBoolTrue ;
          if (kBoolTrue == test_0) {
            test_0 = GALGAS_bool (kIsEqual, enumerator_4969.current_value (HERE).objectCompare (enumerator_5033.current_value (HERE))).boolEnum () ;
            if (kBoolTrue == test_0) {
              var_ok_5012 = GALGAS_bool (true) ;
            }
          }
          enumerator_5033.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_5012 COMMA_SOURCE_FILE ("implementation_types.galgas", 177)) ;
        enumerator_4969.gotoNextObject () ;
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
      GALGAS_uint_36__34_AttributeSet cast_5566_set ((cPtr_uint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_uint_36__34_List enumerator_5580 (cast_5566_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_5580.hasCurrentObject ()) {
        GALGAS_bool var_ok_5623 = GALGAS_bool (false) ;
        cEnumerator_uint_36__34_List enumerator_5644 (this->mProperty_valueList, kENUMERATION_UP) ;
        while (enumerator_5644.hasCurrentObject ()) {
          enumGalgasBool test_0 = kBoolTrue ;
          if (kBoolTrue == test_0) {
            test_0 = GALGAS_bool (kIsEqual, enumerator_5580.current_value (HERE).objectCompare (enumerator_5644.current_value (HERE))).boolEnum () ;
            if (kBoolTrue == test_0) {
              var_ok_5623 = GALGAS_bool (true) ;
            }
          }
          enumerator_5644.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_5623 COMMA_SOURCE_FILE ("implementation_types.galgas", 201)) ;
        enumerator_5580.gotoNextObject () ;
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
      GALGAS_sint_33__32_AttributeSet cast_6177_set ((cPtr_sint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_sint_33__32_List enumerator_6191 (cast_6177_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_6191.hasCurrentObject ()) {
        GALGAS_bool var_ok_6234 = GALGAS_bool (false) ;
        cEnumerator_sint_33__32_List enumerator_6255 (this->mProperty_valueList, kENUMERATION_UP) ;
        while (enumerator_6255.hasCurrentObject ()) {
          enumGalgasBool test_0 = kBoolTrue ;
          if (kBoolTrue == test_0) {
            test_0 = GALGAS_bool (kIsEqual, enumerator_6191.current_value (HERE).objectCompare (enumerator_6255.current_value (HERE))).boolEnum () ;
            if (kBoolTrue == test_0) {
              var_ok_6234 = GALGAS_bool (true) ;
            }
          }
          enumerator_6255.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_6234 COMMA_SOURCE_FILE ("implementation_types.galgas", 225)) ;
        enumerator_6191.gotoNextObject () ;
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
      GALGAS_sint_36__34_AttributeSet cast_6787_set ((cPtr_sint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_sint_36__34_List enumerator_6801 (cast_6787_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_6801.hasCurrentObject ()) {
        GALGAS_bool var_ok_6844 = GALGAS_bool (false) ;
        cEnumerator_sint_36__34_List enumerator_6865 (this->mProperty_valueList, kENUMERATION_UP) ;
        while (enumerator_6865.hasCurrentObject ()) {
          enumGalgasBool test_0 = kBoolTrue ;
          if (kBoolTrue == test_0) {
            test_0 = GALGAS_bool (kIsEqual, enumerator_6801.current_value (HERE).objectCompare (enumerator_6865.current_value (HERE))).boolEnum () ;
            if (kBoolTrue == test_0) {
              var_ok_6844 = GALGAS_bool (true) ;
            }
          }
          enumerator_6865.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_6844 COMMA_SOURCE_FILE ("implementation_types.galgas", 249)) ;
        enumerator_6801.gotoNextObject () ;
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
      GALGAS_floatAttributeSet cast_7395_set ((cPtr_floatAttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_floatList enumerator_7409 (cast_7395_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_7409.hasCurrentObject ()) {
        GALGAS_bool var_ok_7452 = GALGAS_bool (false) ;
        cEnumerator_floatList enumerator_7473 (this->mProperty_valueList, kENUMERATION_UP) ;
        while (enumerator_7473.hasCurrentObject ()) {
          enumGalgasBool test_0 = kBoolTrue ;
          if (kBoolTrue == test_0) {
            test_0 = GALGAS_bool (kIsEqual, enumerator_7409.current_value (HERE).objectCompare (enumerator_7473.current_value (HERE))).boolEnum () ;
            if (kBoolTrue == test_0) {
              var_ok_7452 = GALGAS_bool (true) ;
            }
          }
          enumerator_7473.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_7452 COMMA_SOURCE_FILE ("implementation_types.galgas", 273)) ;
        enumerator_7409.gotoNextObject () ;
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
      GALGAS_uint_33__32_AttributeMinMax cast_8015_minmax ((cPtr_uint_33__32_AttributeMinMax *) constinArgument_value.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsSupOrEqual, cast_8015_minmax.readProperty_min ().objectCompare (this->mProperty_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_8015_minmax.readProperty_max ().objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 291)).boolEnum () ;
        if (kBoolTrue == test_0) {
          outArgument_isWithin = GALGAS_bool (true) ;
        }
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet) {
      GALGAS_uint_33__32_AttributeSet cast_8138_set ((cPtr_uint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_uint_33__32_List enumerator_8172 (cast_8138_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_8172.hasCurrentObject ()) {
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = GALGAS_bool (kIsStrictInf, enumerator_8172.current_value (HERE).objectCompare (this->mProperty_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_8172.current_value (HERE).objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 297)).boolEnum () ;
          if (kBoolTrue == test_1) {
            outArgument_isWithin = GALGAS_bool (false) ;
          }
        }
        enumerator_8172.gotoNextObject () ;
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
      GALGAS_uint_36__34_AttributeMinMax cast_8674_minmax ((cPtr_uint_36__34_AttributeMinMax *) constinArgument_value.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsSupOrEqual, cast_8674_minmax.readProperty_min ().objectCompare (this->mProperty_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_8674_minmax.readProperty_max ().objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 316)).boolEnum () ;
        if (kBoolTrue == test_0) {
          outArgument_isWithin = GALGAS_bool (true) ;
        }
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet) {
      GALGAS_uint_36__34_AttributeSet cast_8797_set ((cPtr_uint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_uint_36__34_List enumerator_8831 (cast_8797_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_8831.hasCurrentObject ()) {
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = GALGAS_bool (kIsStrictInf, enumerator_8831.current_value (HERE).objectCompare (this->mProperty_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_8831.current_value (HERE).objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 322)).boolEnum () ;
          if (kBoolTrue == test_1) {
            outArgument_isWithin = GALGAS_bool (false) ;
          }
        }
        enumerator_8831.gotoNextObject () ;
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
      GALGAS_sint_33__32_AttributeMinMax cast_9329_minmax ((cPtr_sint_33__32_AttributeMinMax *) constinArgument_value.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsSupOrEqual, cast_9329_minmax.readProperty_min ().objectCompare (this->mProperty_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_9329_minmax.readProperty_max ().objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 341)).boolEnum () ;
        if (kBoolTrue == test_0) {
          outArgument_isWithin = GALGAS_bool (true) ;
        }
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet) {
      GALGAS_sint_33__32_AttributeSet cast_9452_set ((cPtr_sint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_sint_33__32_List enumerator_9486 (cast_9452_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_9486.hasCurrentObject ()) {
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = GALGAS_bool (kIsStrictInf, enumerator_9486.current_value (HERE).objectCompare (this->mProperty_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_9486.current_value (HERE).objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 347)).boolEnum () ;
          if (kBoolTrue == test_1) {
            outArgument_isWithin = GALGAS_bool (false) ;
          }
        }
        enumerator_9486.gotoNextObject () ;
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
      GALGAS_sint_36__34_AttributeMinMax cast_9986_minmax ((cPtr_sint_36__34_AttributeMinMax *) constinArgument_value.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsSupOrEqual, cast_9986_minmax.readProperty_min ().objectCompare (this->mProperty_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_9986_minmax.readProperty_max ().objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 366)).boolEnum () ;
        if (kBoolTrue == test_0) {
          outArgument_isWithin = GALGAS_bool (true) ;
        }
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet) {
      GALGAS_sint_36__34_AttributeSet cast_10109_set ((cPtr_sint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_sint_36__34_List enumerator_10143 (cast_10109_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_10143.hasCurrentObject ()) {
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = GALGAS_bool (kIsStrictInf, enumerator_10143.current_value (HERE).objectCompare (this->mProperty_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_10143.current_value (HERE).objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 372)).boolEnum () ;
          if (kBoolTrue == test_1) {
            outArgument_isWithin = GALGAS_bool (false) ;
          }
        }
        enumerator_10143.gotoNextObject () ;
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
      GALGAS_floatAttributeMinMax cast_10641_minmax ((cPtr_floatAttributeMinMax *) constinArgument_value.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsSupOrEqual, cast_10641_minmax.readProperty_min ().objectCompare (this->mProperty_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_10641_minmax.readProperty_max ().objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 391)).boolEnum () ;
        if (kBoolTrue == test_0) {
          outArgument_isWithin = GALGAS_bool (true) ;
        }
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_floatAttributeSet) {
      GALGAS_floatAttributeSet cast_10763_set ((cPtr_floatAttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_floatList enumerator_10797 (cast_10763_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_10797.hasCurrentObject ()) {
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = GALGAS_bool (kIsStrictInf, enumerator_10797.current_value (HERE).objectCompare (this->mProperty_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_10797.current_value (HERE).objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 397)).boolEnum () ;
          if (kBoolTrue == test_1) {
            outArgument_isWithin = GALGAS_bool (false) ;
          }
        }
        enumerator_10797.gotoNextObject () ;
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
  nullptr
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
    if (nullptr != dynamic_cast <const cPtr_impStructType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impStructType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impStructType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 467)) ;
    }
  }
  GALGAS_impStructType var_castTypeToMerge_12884 = temp_0 ;
  GALGAS_implementationObjectMap var_mergedAttributes_12959 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 468)) ;
  cEnumerator_implementationObjectMap enumerator_12994 (this->mProperty_structAttributes, kENUMERATION_UP) ;
  while (enumerator_12994.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_13033 = enumerator_12994.current_type (HERE) ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_castTypeToMerge_12884.readProperty_structAttributes ().getter_hasKey (enumerator_12994.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 471)).boolEnum () ;
      if (kBoolTrue == test_1) {
        GALGAS_impType var_subTypeToMerge_13188 ;
        var_castTypeToMerge_12884.readProperty_structAttributes ().method_get (enumerator_12994.current_lkey (HERE), var_subTypeToMerge_13188, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 472)) ;
        var_mergedAttr_13033 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_12994.current_type (HERE).ptr (), var_subTypeToMerge_13188, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 473)) ;
      }
    }
    {
    var_mergedAttributes_12959.setter_put (enumerator_12994.current_lkey (HERE), var_mergedAttr_13033, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 475)) ;
    }
    enumerator_12994.gotoNextObject () ;
  }
  result_mergedType = GALGAS_impStructType::constructor_new (this->mProperty_locations.add_operation (inArgument_typeToMerge.readProperty_locations (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 478)), this->mProperty_type, this->mProperty_name, this->mProperty_multiple, this->mProperty_descs.add_operation (inArgument_typeToMerge.readProperty_descs (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 482)), var_mergedAttributes_12959  COMMA_SOURCE_FILE ("implementation_types.galgas", 477)) ;
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

C_PrologueEpilogue gSetter_impAutoDefaultType_setDefValue (defineExtensionSetter_impAutoDefaultType_setDefValue, nullptr) ;

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
  cEnumerator_locationList enumerator_14829 (inArgument_locations, kENUMERATION_UP) ;
  while (enumerator_14829.hasCurrentObject ()) {
    TC_Array <C_FixItDescription> fixItArray0 ;
    inCompiler->emitSemanticError (enumerator_14829.current_location (HERE), inArgument_errorMessage, fixItArray0  COMMA_SOURCE_FILE ("implementation_types.galgas", 546)) ;
    enumerator_14829.gotoNextObject () ;
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
    if (nullptr != dynamic_cast <const cPtr_refType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_refType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("refType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 558)) ;
    }
  }
  GALGAS_refType var_castTypeToMerge_15066 = temp_0 ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsNotEqual, this->mProperty_ref.readProperty_string ().objectCompare (var_castTypeToMerge_15066.readProperty_ref ().readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      this->mProperty_ref.log ("ref"  COMMA_SOURCE_FILE ("implementation_types.galgas", 560)) ;
      GALGAS_lstring var_csatRef_15194 = var_castTypeToMerge_15066.readProperty_ref () ;
      var_csatRef_15194.log ("csatRef"  COMMA_SOURCE_FILE ("implementation_types.galgas", 562)) ;
      {
      routine_multiError (inArgument_typeToMerge.readProperty_locations (), GALGAS_string ("Redefinition of ").add_operation (this->mProperty_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 563)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 563)) ;
      }
      {
      routine_multiError (this->mProperty_locations, GALGAS_string ("Was defined here"), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 564)) ;
      }
    }
  }
  result_mergedType = GALGAS_refType::constructor_new (this->mProperty_locations.add_operation (inArgument_typeToMerge.readProperty_locations (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 567)), this->mProperty_type, this->mProperty_name, this->mProperty_multiple, this->mProperty_descs.add_operation (inArgument_typeToMerge.readProperty_descs (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 571)), var_castTypeToMerge_15066.readProperty_ref ()  COMMA_SOURCE_FILE ("implementation_types.galgas", 566)) ;
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
  cEnumerator_enumValues enumerator_16168 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_16168.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_16168.current_lkey (HERE).readProperty_string (), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 600)) ;
    if (enumerator_16168.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 602)) ;
    }
    enumerator_16168.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_valueList [2] = {
  & kTypeDescriptor_GALGAS_enumValues,
  nullptr
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
    if (nullptr != dynamic_cast <const cPtr_impRangedType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impRangedType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impRangedType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 614)) ;
    }
  }
  GALGAS_impRangedType var_castTypeToMerge_16444 = temp_0 ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    const GALGAS_impRangedType temp_2 = this ;
    test_1 = function_checkRanged (temp_2, var_castTypeToMerge_16444, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 615)).boolEnum () ;
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
    if (nullptr != dynamic_cast <const cPtr_impBoolType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impBoolType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impBoolType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 631)) ;
    }
  }
  GALGAS_impBoolType var_castTypeToMerge_16854 = temp_0 ;
  GALGAS_implementationObjectMap var_mergedTrueAttributes_16927 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 632)) ;
  GALGAS_implementationObjectMap var_mergedFalseAttributes_16987 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 633)) ;
  cEnumerator_implementationObjectMap enumerator_17027 (this->mProperty_trueSubAttributes, kENUMERATION_UP) ;
  while (enumerator_17027.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_17067 = enumerator_17027.current_type (HERE) ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_castTypeToMerge_16854.readProperty_trueSubAttributes ().getter_hasKey (enumerator_17027.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 636)).boolEnum () ;
      if (kBoolTrue == test_1) {
        GALGAS_impType var_subTypeToMerge_17224 ;
        var_castTypeToMerge_16854.readProperty_trueSubAttributes ().method_get (enumerator_17027.current_lkey (HERE), var_subTypeToMerge_17224, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 637)) ;
        var_mergedAttr_17067 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_17027.current_type (HERE).ptr (), var_subTypeToMerge_17224, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 638)) ;
      }
    }
    {
    var_mergedTrueAttributes_16927.setter_put (enumerator_17027.current_lkey (HERE), var_mergedAttr_17067, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 640)) ;
    }
    enumerator_17027.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_17406 (var_castTypeToMerge_16854.readProperty_trueSubAttributes (), kENUMERATION_UP) ;
  while (enumerator_17406.hasCurrentObject ()) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = this->mProperty_trueSubAttributes.getter_hasKey (enumerator_17406.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 644)).operator_not (SOURCE_FILE ("implementation_types.galgas", 644)).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        var_mergedTrueAttributes_16927.setter_put (enumerator_17406.current_lkey (HERE), enumerator_17406.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 645)) ;
        }
      }
    }
    enumerator_17406.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_17579 (this->mProperty_falseSubAttributes, kENUMERATION_UP) ;
  while (enumerator_17579.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_17620 = enumerator_17579.current_type (HERE) ;
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = var_castTypeToMerge_16854.readProperty_falseSubAttributes ().getter_hasKey (enumerator_17579.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 651)).boolEnum () ;
      if (kBoolTrue == test_3) {
        GALGAS_impType var_subTypeToMerge_17779 ;
        var_castTypeToMerge_16854.readProperty_falseSubAttributes ().method_get (enumerator_17579.current_lkey (HERE), var_subTypeToMerge_17779, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 652)) ;
        var_mergedAttr_17620 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_17579.current_type (HERE).ptr (), var_subTypeToMerge_17779, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 653)) ;
      }
    }
    {
    var_mergedFalseAttributes_16987.setter_put (enumerator_17579.current_lkey (HERE), var_mergedAttr_17620, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 655)) ;
    }
    enumerator_17579.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_17962 (var_castTypeToMerge_16854.readProperty_falseSubAttributes (), kENUMERATION_UP) ;
  while (enumerator_17962.hasCurrentObject ()) {
    enumGalgasBool test_4 = kBoolTrue ;
    if (kBoolTrue == test_4) {
      test_4 = this->mProperty_falseSubAttributes.getter_hasKey (enumerator_17962.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 659)).operator_not (SOURCE_FILE ("implementation_types.galgas", 659)).boolEnum () ;
      if (kBoolTrue == test_4) {
        {
        var_mergedTrueAttributes_16927.setter_put (enumerator_17962.current_lkey (HERE), enumerator_17962.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 660)) ;
        }
      }
    }
    enumerator_17962.gotoNextObject () ;
  }
  result_mergedType = GALGAS_impBoolType::constructor_new (this->mProperty_locations.add_operation (inArgument_typeToMerge.readProperty_locations (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 665)), this->mProperty_type, this->mProperty_name, this->mProperty_multiple, this->mProperty_descs.add_operation (inArgument_typeToMerge.readProperty_descs (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 669)), this->mProperty_withAuto, var_castTypeToMerge_16854.readProperty_defaultValue (), var_mergedTrueAttributes_16927, var_mergedFalseAttributes_16987  COMMA_SOURCE_FILE ("implementation_types.galgas", 664)) ;
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
          GALGAS_identifierMap var_userAttributes_18874 = ioArgument_attributes.readProperty_objectParams () ;
          GALGAS_object_5F_t var_value_18939 ;
          var_userAttributes_18874.method_get (this->mProperty_name, var_value_18939, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 690)) ;
          if (var_value_18939.isValid ()) {
            if (var_value_18939.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
              GALGAS_boolAttribute cast_19037_boolValue ((cPtr_boolAttribute *) var_value_18939.ptr ()) ;
              GALGAS_implementationObjectMap var_subImpAttributes_19088 ;
              enumGalgasBool test_1 = kBoolTrue ;
              if (kBoolTrue == test_1) {
                test_1 = cast_19037_boolValue.readProperty_value ().boolEnum () ;
                if (kBoolTrue == test_1) {
                  var_subImpAttributes_19088 = this->mProperty_trueSubAttributes ;
                }
              }
              if (kBoolFalse == test_1) {
                var_subImpAttributes_19088 = this->mProperty_falseSubAttributes ;
              }
              GALGAS_objectAttributes var_subAttributes_19297 = cast_19037_boolValue.readProperty_subAttributes () ;
              {
              routine_setDefaultsForType (var_subImpAttributes_19088, var_subAttributes_19297, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 700)) ;
              }
              GALGAS_boolAttribute var_bv_19463 = cast_19037_boolValue ;
              {
              var_bv_19463.setter_setSubAttributes (var_subAttributes_19297 COMMA_SOURCE_FILE ("implementation_types.galgas", 703)) ;
              }
              {
              var_userAttributes_18874.setter_setValueForKey (var_bv_19463, this->mProperty_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 704)) ;
              }
              {
              ioArgument_attributes.setter_setObjectParams (var_userAttributes_18874 COMMA_SOURCE_FILE ("implementation_types.galgas", 705)) ;
              }
            }
          }
        }
      }
      if (kBoolFalse == test_0) {
        GALGAS_implementationObjectMap var_subImpAttributes_19712 ;
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = cast_18611_b.readProperty_value ().boolEnum () ;
          if (kBoolTrue == test_2) {
            var_subImpAttributes_19712 = this->mProperty_trueSubAttributes ;
          }
        }
        if (kBoolFalse == test_2) {
          var_subImpAttributes_19712 = this->mProperty_falseSubAttributes ;
        }
        GALGAS_objectAttributes var_subAttributes_19901 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 714)) ;
        {
        routine_setDefaultsForType (var_subImpAttributes_19712, var_subAttributes_19901, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 715)) ;
        }
        GALGAS_boolAttribute var_defaults_20022 = GALGAS_boolAttribute::constructor_new (cast_18611_b.readProperty_oil_5F_desc (), cast_18611_b.readProperty_location (), cast_18611_b.readProperty_value (), var_subAttributes_19901  COMMA_SOURCE_FILE ("implementation_types.galgas", 716)) ;
        GALGAS_identifierMap var_attr_20133 = ioArgument_attributes.readProperty_objectParams () ;
        {
        var_attr_20133.setter_put (this->mProperty_name, var_defaults_20022, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 718)) ;
        }
        {
        ioArgument_attributes.setter_setObjectParams (var_attr_20133 COMMA_SOURCE_FILE ("implementation_types.galgas", 719)) ;
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
    if (nullptr != dynamic_cast <const cPtr_impEnumType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impEnumType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impEnumType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 754)) ;
    }
  }
  GALGAS_impEnumType var_castTypeToMerge_21072 = temp_0 ;
  result_mergedType = GALGAS_impEnumType::constructor_new (this->mProperty_locations.add_operation (inArgument_typeToMerge.readProperty_locations (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 756)), this->mProperty_type, this->mProperty_name, this->mProperty_multiple, this->mProperty_descs.add_operation (inArgument_typeToMerge.readProperty_descs (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 760)), this->mProperty_withAuto, var_castTypeToMerge_21072.readProperty_defaultValue (), extensionGetter_mergeWithEnum (this->mProperty_valuesMap, var_castTypeToMerge_21072.readProperty_valuesMap (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 763))  COMMA_SOURCE_FILE ("implementation_types.galgas", 755)) ;
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
      GALGAS_impEnumType cast_21545_realEnum ((cPtr_impEnumType *) constinArgument_anEnum.ptr ()) ;
      if (cast_21545_realEnum.readProperty_defaultValue ().isValid ()) {
        if (cast_21545_realEnum.readProperty_defaultValue ().dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_string_5F_class) {
          GALGAS_string_5F_class cast_21615_defaultValue ((cPtr_string_5F_class *) cast_21545_realEnum.readProperty_defaultValue ().ptr ()) ;
          enumGalgasBool test_0 = kBoolTrue ;
          if (kBoolTrue == test_0) {
            test_0 = cast_21545_realEnum.readProperty_valuesMap ().getter_hasKey (cast_21615_defaultValue.readProperty_value () COMMA_SOURCE_FILE ("implementation_types.galgas", 777)).operator_not (SOURCE_FILE ("implementation_types.galgas", 777)).boolEnum () ;
            if (kBoolTrue == test_0) {
              TC_Array <C_FixItDescription> fixItArray1 ;
              inCompiler->emitSemanticError (cast_21615_defaultValue.readProperty_location (), GALGAS_string ("Default enum value does not match any enum value"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 778)) ;
            }
          }
        }
      }
    }else{
      cEnumerator_locationList enumerator_21828 (constinArgument_anEnum.readProperty_locations (), kENUMERATION_UP) ;
      while (enumerator_21828.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (enumerator_21828.current_location (HERE), GALGAS_string ("Internal, not an @impEnumType"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 783)) ;
        enumerator_21828.gotoNextObject () ;
      }
    }
  }
}


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
  nullptr
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
  nullptr
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
      GALGAS_impType var_type_25238 ;
      constinArgument_obj.method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 898)), var_type_25238, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 898)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsNotEqual, var_type_25238.readProperty_type ().objectCompare (constinArgument_expectedType)).boolEnum () ;
        if (kBoolTrue == test_1) {
          cEnumerator_locationList enumerator_25342 (var_type_25238.readProperty_locations (), kENUMERATION_UP) ;
          while (enumerator_25342.hasCurrentObject ()) {
            TC_Array <C_FixItDescription> fixItArray2 ;
            inCompiler->emitSemanticError (enumerator_25342.current_location (HERE), constinArgument_attributeName.add_operation (GALGAS_string (" is a "), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 901)).add_operation (extensionGetter_oilType (var_type_25238.readProperty_type (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 901)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 901)), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 901)) ;
            TC_Array <C_FixItDescription> fixItArray3 ;
            inCompiler->emitSemanticError (enumerator_25342.current_location (HERE), constinArgument_attributeName.add_operation (GALGAS_string (" should be a "), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 902)).add_operation (extensionGetter_oilType (constinArgument_expectedType, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 902)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 902)), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 902)) ;
            enumerator_25342.gotoNextObject () ;
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
      GALGAS_impType var_type_25823 ;
      constinArgument_obj.readProperty_attributes ().method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 916)), var_type_25823, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 916)) ;
      if (var_type_25823.isValid ()) {
        if (var_type_25823.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impBoolType) {
          GALGAS_impBoolType cast_25929_boolType ((cPtr_impBoolType *) var_type_25823.ptr ()) ;
          enumGalgasBool test_1 = kBoolTrue ;
          if (kBoolTrue == test_1) {
            test_1 = constinArgument_boolValue.boolEnum () ;
            if (kBoolTrue == test_1) {
              result_subImplementation = cast_25929_boolType.readProperty_trueSubAttributes () ;
            }
          }
          if (kBoolFalse == test_1) {
            result_subImplementation = cast_25929_boolType.readProperty_falseSubAttributes () ;
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
  nullptr
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
      GALGAS_impType var_type_26406 ;
      constinArgument_obj.readProperty_attributes ().method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 936)), var_type_26406, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 936)) ;
      if (var_type_26406.isValid ()) {
        if (var_type_26406.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
          GALGAS_impEnumType cast_26512_enumType ((cPtr_impEnumType *) var_type_26406.ptr ()) ;
          enumGalgasBool test_1 = kBoolTrue ;
          if (kBoolTrue == test_1) {
            test_1 = cast_26512_enumType.readProperty_valuesMap ().getter_hasKey (constinArgument_enumValue COMMA_SOURCE_FILE ("implementation_types.galgas", 939)).boolEnum () ;
            if (kBoolTrue == test_1) {
              cast_26512_enumType.readProperty_valuesMap ().method_get (function_lstringWith (constinArgument_enumValue, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 940)), result_subImplementation, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 940)) ;
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
  nullptr
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
  GALGAS_implementationObjectMap var_filter_26800 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWEQUALSX"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 951)) ;
  {
  routine_checkTypeForAttribute (var_filter_26800, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 952)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 952)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_26800, GALGAS_string ("X"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 953)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 953)) ;
  }
  var_filter_26800 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWDIFFERSX"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 954)) ;
  {
  routine_checkTypeForAttribute (var_filter_26800, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 955)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 955)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_26800, GALGAS_string ("X"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 956)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 956)) ;
  }
  var_filter_26800 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWEQUALSMASKEDOLD"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 957)) ;
  {
  routine_checkTypeForAttribute (var_filter_26800, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 958)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 958)) ;
  }
  var_filter_26800 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("NEWISWITHIN"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 959)) ;
  {
  routine_checkTypeForAttribute (var_filter_26800, GALGAS_string ("MIN"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 960)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 960)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_26800, GALGAS_string ("MAX"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 961)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 961)) ;
  }
  var_filter_26800 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("NEWISOUTSIDE"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 962)) ;
  {
  routine_checkTypeForAttribute (var_filter_26800, GALGAS_string ("MIN"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 963)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 963)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_26800, GALGAS_string ("MAX"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 964)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 964)) ;
  }
  var_filter_26800 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("ONEEVERYN"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 965)) ;
  {
  routine_checkTypeForAttribute (var_filter_26800, GALGAS_string ("PERIOD"), GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 966)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 966)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_26800, GALGAS_string ("OFFSET"), GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 967)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 967)) ;
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
  cEnumerator_implementationObjectMap enumerator_28672 (this->mProperty_trueSubAttributes, kENUMERATION_UP) ;
  while (enumerator_28672.hasCurrentObject ()) {
    callExtensionMethod_checkAttributeReferences ((cPtr_impType *) enumerator_28672.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 991)) ;
    enumerator_28672.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_28754 (this->mProperty_falseSubAttributes, kENUMERATION_UP) ;
  while (enumerator_28754.hasCurrentObject ()) {
    callExtensionMethod_checkAttributeReferences ((cPtr_impType *) enumerator_28754.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 994)) ;
    enumerator_28754.gotoNextObject () ;
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
  cEnumerator_enumValues enumerator_28923 (this->mProperty_valuesMap, kENUMERATION_UP) ;
  while (enumerator_28923.hasCurrentObject ()) {
    cEnumerator_implementationObjectMap enumerator_28951 (enumerator_28923.current_subAttributes (HERE), kENUMERATION_UP) ;
    while (enumerator_28951.hasCurrentObject ()) {
      callExtensionMethod_checkAttributeReferences ((cPtr_impType *) enumerator_28951.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1003)) ;
      enumerator_28951.gotoNextObject () ;
    }
    enumerator_28923.gotoNextObject () ;
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
  cEnumerator_implementationObjectMap enumerator_29147 (constinArgument_impObject, kENUMERATION_UP) ;
  while (enumerator_29147.hasCurrentObject ()) {
    if (enumerator_29147.current_type (HERE).isValid ()) {
      if (nullptr != dynamic_cast <const cPtr_impAutoDefaultType *> (enumerator_29147.current_type (HERE).ptr ())) {
        GALGAS_impAutoDefaultType cast_29213_defaultType ((cPtr_impAutoDefaultType *) enumerator_29147.current_type (HERE).ptr ()) ;
        callExtensionMethod_setDefault ((cPtr_impAutoDefaultType *) cast_29213_defaultType.ptr (), ioArgument_objectParams, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1015)) ;
      }
    }
    enumerator_29147.gotoNextObject () ;
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
      GALGAS_uint_33__32__5F_class cast_31592_intVal ((cPtr_uint_33__32__5F_class *) constinArgument_obj.ptr ()) ;
      result_isInside = GALGAS_bool (false) ;
      cEnumerator_uint_33__32_List enumerator_31629 (this->mProperty_valueList, kENUMERATION_UP) ;
      while (enumerator_31629.hasCurrentObject ()) {
        result_isInside = result_isInside.operator_or (GALGAS_bool (kIsEqual, enumerator_31629.current_value (HERE).objectCompare (cast_31592_intVal.readProperty_value ())) COMMA_SOURCE_FILE ("implementation_types.galgas", 1103)) ;
        enumerator_31629.gotoNextObject () ;
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
  cEnumerator_uint_33__32_List enumerator_31858 (this->mProperty_valueList, kENUMERATION_UP) ;
  while (enumerator_31858.hasCurrentObject ()) {
    result_desc.plusAssign_operation(enumerator_31858.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 1115)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1115)) ;
    if (enumerator_31858.hasNextObject ()) {
      result_desc.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1117)) ;
    }
    enumerator_31858.gotoNextObject () ;
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
      GALGAS_uint_33__32__5F_class cast_32068_intVal ((cPtr_uint_33__32__5F_class *) constinArgument_obj.ptr ()) ;
      GALGAS_bool test_0 = GALGAS_bool (kIsInfOrEqual, this->mProperty_min.objectCompare (cast_32068_intVal.readProperty_value ())) ;
      if (kBoolTrue == test_0.boolEnum ()) {
        test_0 = GALGAS_bool (kIsInfOrEqual, cast_32068_intVal.readProperty_value ().objectCompare (this->mProperty_max)) ;
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
      GALGAS_sint_33__32__5F_class cast_32443_intVal ((cPtr_sint_33__32__5F_class *) constinArgument_obj.ptr ()) ;
      result_isInside = GALGAS_bool (true) ;
      cEnumerator_sint_33__32_List enumerator_32479 (this->mProperty_valueList, kENUMERATION_UP) ;
      while (enumerator_32479.hasCurrentObject ()) {
        result_isInside = result_isInside.operator_and (GALGAS_bool (kIsEqual, enumerator_32479.current_value (HERE).objectCompare (cast_32443_intVal.readProperty_value ())) COMMA_SOURCE_FILE ("implementation_types.galgas", 1147)) ;
        enumerator_32479.gotoNextObject () ;
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
  cEnumerator_sint_33__32_List enumerator_32708 (this->mProperty_valueList, kENUMERATION_UP) ;
  while (enumerator_32708.hasCurrentObject ()) {
    result_desc.plusAssign_operation(enumerator_32708.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 1159)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1159)) ;
    if (enumerator_32708.hasNextObject ()) {
      result_desc.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1161)) ;
    }
    enumerator_32708.gotoNextObject () ;
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
      GALGAS_sint_33__32__5F_class cast_32918_intVal ((cPtr_sint_33__32__5F_class *) constinArgument_obj.ptr ()) ;
      GALGAS_bool test_0 = GALGAS_bool (kIsInfOrEqual, this->mProperty_min.objectCompare (cast_32918_intVal.readProperty_value ())) ;
      if (kBoolTrue == test_0.boolEnum ()) {
        test_0 = GALGAS_bool (kIsInfOrEqual, cast_32918_intVal.readProperty_value ().objectCompare (this->mProperty_max)) ;
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
      GALGAS_uint_36__34__5F_class cast_33293_intVal ((cPtr_uint_36__34__5F_class *) constinArgument_obj.ptr ()) ;
      result_isInside = GALGAS_bool (true) ;
      cEnumerator_uint_36__34_List enumerator_33329 (this->mProperty_valueList, kENUMERATION_UP) ;
      while (enumerator_33329.hasCurrentObject ()) {
        result_isInside = result_isInside.operator_and (GALGAS_bool (kIsEqual, enumerator_33329.current_value (HERE).objectCompare (cast_33293_intVal.readProperty_value ())) COMMA_SOURCE_FILE ("implementation_types.galgas", 1191)) ;
        enumerator_33329.gotoNextObject () ;
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
  cEnumerator_uint_36__34_List enumerator_33558 (this->mProperty_valueList, kENUMERATION_UP) ;
  while (enumerator_33558.hasCurrentObject ()) {
    result_desc.plusAssign_operation(enumerator_33558.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 1203)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1203)) ;
    if (enumerator_33558.hasNextObject ()) {
      result_desc.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1205)) ;
    }
    enumerator_33558.gotoNextObject () ;
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
      GALGAS_uint_36__34__5F_class cast_33768_intVal ((cPtr_uint_36__34__5F_class *) constinArgument_obj.ptr ()) ;
      GALGAS_bool test_0 = GALGAS_bool (kIsInfOrEqual, this->mProperty_min.objectCompare (cast_33768_intVal.readProperty_value ())) ;
      if (kBoolTrue == test_0.boolEnum ()) {
        test_0 = GALGAS_bool (kIsInfOrEqual, cast_33768_intVal.readProperty_value ().objectCompare (this->mProperty_max)) ;
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
      GALGAS_sint_36__34__5F_class cast_34143_intVal ((cPtr_sint_36__34__5F_class *) constinArgument_obj.ptr ()) ;
      result_isInside = GALGAS_bool (true) ;
      cEnumerator_sint_36__34_List enumerator_34179 (this->mProperty_valueList, kENUMERATION_UP) ;
      while (enumerator_34179.hasCurrentObject ()) {
        result_isInside = result_isInside.operator_and (GALGAS_bool (kIsEqual, enumerator_34179.current_value (HERE).objectCompare (cast_34143_intVal.readProperty_value ())) COMMA_SOURCE_FILE ("implementation_types.galgas", 1235)) ;
        enumerator_34179.gotoNextObject () ;
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
  cEnumerator_sint_36__34_List enumerator_34408 (this->mProperty_valueList, kENUMERATION_UP) ;
  while (enumerator_34408.hasCurrentObject ()) {
    result_desc.plusAssign_operation(enumerator_34408.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 1247)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1247)) ;
    if (enumerator_34408.hasNextObject ()) {
      result_desc.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1249)) ;
    }
    enumerator_34408.gotoNextObject () ;
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
      GALGAS_sint_36__34__5F_class cast_34619_intVal ((cPtr_sint_36__34__5F_class *) constinArgument_obj.ptr ()) ;
      GALGAS_bool test_0 = GALGAS_bool (kIsInfOrEqual, this->mProperty_min.objectCompare (cast_34619_intVal.readProperty_value ())) ;
      if (kBoolTrue == test_0.boolEnum ()) {
        test_0 = GALGAS_bool (kIsInfOrEqual, cast_34619_intVal.readProperty_value ().objectCompare (this->mProperty_max)) ;
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
      GALGAS_float_5F_class cast_34992_intVal ((cPtr_float_5F_class *) constinArgument_obj.ptr ()) ;
      result_isInside = GALGAS_bool (true) ;
      cEnumerator_floatList enumerator_35028 (this->mProperty_valueList, kENUMERATION_UP) ;
      while (enumerator_35028.hasCurrentObject ()) {
        result_isInside = result_isInside.operator_and (GALGAS_bool (kIsEqual, enumerator_35028.current_value (HERE).objectCompare (cast_34992_intVal.readProperty_value ())) COMMA_SOURCE_FILE ("implementation_types.galgas", 1280)) ;
        enumerator_35028.gotoNextObject () ;
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
  cEnumerator_floatList enumerator_35255 (this->mProperty_valueList, kENUMERATION_UP) ;
  while (enumerator_35255.hasCurrentObject ()) {
    result_desc.plusAssign_operation(enumerator_35255.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 1292)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1292)) ;
    if (enumerator_35255.hasNextObject ()) {
      result_desc.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 1294)) ;
    }
    enumerator_35255.gotoNextObject () ;
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
      GALGAS_float_5F_class cast_35463_intVal ((cPtr_float_5F_class *) constinArgument_obj.ptr ()) ;
      GALGAS_bool test_0 = GALGAS_bool (kIsInfOrEqual, this->mProperty_min.objectCompare (cast_35463_intVal.readProperty_value ())) ;
      if (kBoolTrue == test_0.boolEnum ()) {
        test_0 = GALGAS_bool (kIsInfOrEqual, cast_35463_intVal.readProperty_value ().objectCompare (this->mProperty_max)) ;
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

C_PrologueEpilogue gEpilogueForOnceFunction_emptyLString (nullptr,
                                                          releaseOnceFunctionResult_emptyLString) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptyLString [1] = {
  nullptr
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
  nullptr
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
      GALGAS_multipleAttribute cast_2234_multipleObject ((cPtr_multipleAttribute *) inArgument_withObject.ptr ()) ;
      object->mProperty_items.plusAssign_operation(cast_2234_multipleObject.readProperty_items (), inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 93)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_multipleAttribute_mergeSubAttributes (void) {
  enterExtensionSetter_mergeSubAttributes (kTypeDescriptor_GALGAS_multipleAttribute.mSlotID,
                                           extensionSetter_multipleAttribute_mergeSubAttributes) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_multipleAttribute_mergeSubAttributes (defineExtensionSetter_multipleAttribute_mergeSubAttributes, nullptr) ;

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
  nullptr
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
      GALGAS_boolAttribute cast_2778_boolObject ((cPtr_boolAttribute *) inArgument_withObject.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsEqual, object->mProperty_value.objectCompare (cast_2778_boolObject.readProperty_value ())).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          object->mProperty_subAttributes.insulate (HERE) ;
          cPtr_objectAttributes * ptr_2840 = (cPtr_objectAttributes *) object->mProperty_subAttributes.ptr () ;
          callExtensionSetter_mergeAttributes ((cPtr_objectAttributes *) ptr_2840, cast_2778_boolObject.readProperty_subAttributes (), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 120)) ;
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

C_PrologueEpilogue gSetter_boolAttribute_mergeSubAttributes (defineExtensionSetter_boolAttribute_mergeSubAttributes, nullptr) ;

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
      GALGAS_boolAttribute cast_3046_attribute ((cPtr_boolAttribute *) inArgument_t.ptr ()) ;
      result_v = cast_3046_attribute.readProperty_value () ;
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
  nullptr
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
      GALGAS_enumAttribute cast_3377_enumObject ((cPtr_enumAttribute *) inArgument_withObject.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsEqual, object->mProperty_value.objectCompare (cast_3377_enumObject.readProperty_value ())).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          object->mProperty_subAttributes.insulate (HERE) ;
          cPtr_objectAttributes * ptr_3439 = (cPtr_objectAttributes *) object->mProperty_subAttributes.ptr () ;
          callExtensionSetter_mergeAttributes ((cPtr_objectAttributes *) ptr_3439, cast_3377_enumObject.readProperty_subAttributes (), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 148)) ;
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

C_PrologueEpilogue gSetter_enumAttribute_mergeSubAttributes (defineExtensionSetter_enumAttribute_mergeSubAttributes, nullptr) ;

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
      GALGAS_uint_33__32__5F_class cast_3835_ui ((cPtr_uint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_3835_ui.readProperty_value () ;
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
  nullptr
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
      GALGAS_uint_33__32__5F_class cast_4034_ui ((cPtr_uint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_4034_ui.readProperty_value () ;
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
  nullptr
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
      GALGAS_sint_33__32__5F_class cast_4371_ui ((cPtr_sint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_4371_ui.readProperty_value () ;
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
  nullptr
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
      GALGAS_uint_36__34__5F_class cast_4708_ui ((cPtr_uint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_4708_ui.readProperty_value () ;
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
  nullptr
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
      GALGAS_uint_36__34__5F_class cast_4926_ui ((cPtr_uint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = GALGAS_luint_36__34_::constructor_new (cast_4926_ui.readProperty_value (), cast_4926_ui.readProperty_location ()  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 238)) ;
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
  nullptr
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
      GALGAS_sint_36__34__5F_class cast_5365_ui ((cPtr_sint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_5365_ui.readProperty_value () ;
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
  nullptr
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
      GALGAS_float_5F_class cast_5715_ui ((cPtr_float_5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_5715_ui.readProperty_value () ;
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
  nullptr
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
      GALGAS_stringAttribute cast_6260_attribute ((cPtr_stringAttribute *) constinArgument_attribute.ptr ()) ;
      result_result = GALGAS_lstring::constructor_new (cast_6260_attribute.readProperty_value (), cast_6260_attribute.readProperty_location ()  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 306)) ;
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
  nullptr
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
      GALGAS_structAttribute cast_6665_structObject ((cPtr_structAttribute *) inArgument_withObject.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsEqual, object->mProperty_structName.readProperty_string ().objectCompare (cast_6665_structObject.readProperty_structName ().readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          object->mProperty_subAttributes.insulate (HERE) ;
          cPtr_objectAttributes * ptr_6759 = (cPtr_objectAttributes *) object->mProperty_subAttributes.ptr () ;
          callExtensionSetter_mergeAttributes ((cPtr_objectAttributes *) ptr_6759, cast_6665_structObject.readProperty_subAttributes (), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 322)) ;
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

C_PrologueEpilogue gSetter_structAttribute_mergeSubAttributes (defineExtensionSetter_structAttribute_mergeSubAttributes, nullptr) ;

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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  nullptr
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
  GALGAS_stringlist var_components_1206 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 45)) ;
  var_components_1206.method_first (result_arch_5F_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 46)) ;
//---
  return result_arch_5F_name ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_arch [1] = {
  nullptr
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
  GALGAS_stringlist var_components_1527 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 54)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_components_1527.getter_count (SOURCE_FILE ("goil_routines.galgas", 55)).objectCompare (GALGAS_uint (uint32_t (1U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_chip_5F_name = var_components_1527.getter_mValueAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 56)) ;
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
  nullptr
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
  GALGAS_stringlist var_components_1945 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 68)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_components_1945.getter_count (SOURCE_FILE ("goil_routines.galgas", 69)).objectCompare (GALGAS_uint (uint32_t (2U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      GALGAS_string joker_2098 ; // Joker input parameter
      var_components_1945.setter_popFirst (joker_2098, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 70)) ;
      }
      {
      GALGAS_string joker_2129 ; // Joker input parameter
      var_components_1945.setter_popFirst (joker_2129, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 71)) ;
      }
      result_board_5F_name = GALGAS_string::constructor_componentsJoinedByString (var_components_1945, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 72)) ;
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
  nullptr
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
  GALGAS_stringlist var_components_2363 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 82)) ;
  result_pathList = GALGAS_list::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 83)) ;
  cEnumerator_stringlist enumerator_2494 (var_components_2363, kENUMERATION_UP) ;
  while (enumerator_2494.hasCurrentObject ()) {
    GALGAS_gtlData var_cont_2534 = GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 85)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 85)), enumerator_2494.current_mValue (HERE)  COMMA_SOURCE_FILE ("goil_routines.galgas", 85)) ;
    result_pathList.addAssign_operation (var_cont_2534  COMMA_SOURCE_FILE ("goil_routines.galgas", 86)) ;
    enumerator_2494.gotoNextObject () ;
  }
//---
  return result_pathList ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_targetPathList [1] = {
  nullptr
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
    test_0 = GALGAS_bool (kIsNotEqual, inArgument_path.getter_characterAtIndex (inArgument_path.getter_count (SOURCE_FILE ("goil_routines.galgas", 97)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 97)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 97)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
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
  nullptr
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
    GALGAS_string var_env_3104 = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("GOIL_TEMPLATES")  COMMA_SOURCE_FILE ("goil_routines.galgas", 110)) ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsNotEqual, var_env_3104.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        result_templateDirectory = var_env_3104 ;
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
          GALGAS_string var_home_3672 = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("HOME")  COMMA_SOURCE_FILE ("goil_routines.galgas", 123)) ;
          GALGAS_string var_relativeToHome_3753 = result_templateDirectory.getter_rightSubString (result_templateDirectory.getter_count (SOURCE_FILE ("goil_routines.galgas", 124)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 124)) COMMA_SOURCE_FILE ("goil_routines.galgas", 124)) ;
          result_templateDirectory = var_home_3672.add_operation (var_relativeToHome_3753, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 125)) ;
        }
      }
      if (kBoolFalse == test_4) {
        GALGAS_string var_currentDirectory_3912 = GALGAS_string::constructor_stringWithCurrentDirectory (SOURCE_FILE ("goil_routines.galgas", 127)) ;
        result_templateDirectory = var_currentDirectory_3912.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 128)).add_operation (result_templateDirectory, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 128)) ;
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
  nullptr
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
          GALGAS_string var_curdir_4433 = GALGAS_string::constructor_stringWithCurrentDirectory (SOURCE_FILE ("goil_routines.galgas", 140)) ;
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            test_2 = GALGAS_bool (kIsEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 141)).objectCompare (GALGAS_char (TO_UNICODE (46)))).operator_and (GALGAS_bool (kIsEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 141)).objectCompare (GALGAS_char (TO_UNICODE (47)))) COMMA_SOURCE_FILE ("goil_routines.galgas", 141)).boolEnum () ;
            if (kBoolTrue == test_2) {
              result_temp_5F_dir = result_temp_5F_dir.getter_stringByRemovingCharacterAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 142)).getter_stringByRemovingCharacterAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 142)) ;
            }
          }
          result_temp_5F_dir = var_curdir_4433.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 144)).add_operation (result_temp_5F_dir, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 144)) ;
        }
      }
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsNotEqual, result_temp_5F_dir.getter_characterAtIndex (result_temp_5F_dir.getter_count (SOURCE_FILE ("goil_routines.galgas", 146)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 146)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 146)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
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
  nullptr
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
  GALGAS_stringlist var_components_5031 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 158)) ;
  GALGAS_string var_templateDir_5137 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 159)) ;
  GALGAS_bool var_notFound_5188 = GALGAS_bool (true) ;
  GALGAS_bool var_notOver_5212 = GALGAS_bool (true) ;
  result_path = GALGAS_string::makeEmptyString () ;
  if (var_components_5031.getter_count (SOURCE_FILE ("goil_routines.galgas", 164)).add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 164)).isValid ()) {
    uint32_t variant_5244 = var_components_5031.getter_count (SOURCE_FILE ("goil_routines.galgas", 164)).add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 164)).uintValue () ;
    bool loop_5244 = true ;
    while (loop_5244) {
      loop_5244 = var_notFound_5188.operator_and (var_notOver_5212 COMMA_SOURCE_FILE ("goil_routines.galgas", 165)).isValid () ;
      if (loop_5244) {
        loop_5244 = var_notFound_5188.operator_and (var_notOver_5212 COMMA_SOURCE_FILE ("goil_routines.galgas", 165)).boolValue () ;
      }
      if (loop_5244 && (0 == variant_5244)) {
        loop_5244 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 164)) ;
      }
      if (loop_5244) {
        variant_5244 -- ;
        GALGAS_string var_targetPath_5319 = var_templateDir_5137.add_operation (GALGAS_string::constructor_componentsJoinedByString (var_components_5031, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 166)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)) ;
        enumGalgasBool test_0 = kBoolTrue ;
        if (kBoolTrue == test_0) {
          test_0 = var_targetPath_5319.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 168)).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_notFound_5188 = GALGAS_bool (false) ;
            result_path = var_targetPath_5319 ;
          }
        }
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = GALGAS_bool (kIsStrictSup, var_components_5031.getter_count (SOURCE_FILE ("goil_routines.galgas", 172)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
          if (kBoolTrue == test_1) {
            {
            GALGAS_string joker_5604 ; // Joker input parameter
            var_components_5031.setter_popLast (joker_5604, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 173)) ;
            }
          }
        }
        if (kBoolFalse == test_1) {
          var_notOver_5212 = GALGAS_bool (false) ;
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
  nullptr
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
  GALGAS_stringlist var_components_5742 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 184)) ;
  GALGAS_string var_partialPath_5844 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 185)) ;
  result_paths = GALGAS_stringlist::constructor_listWithValue (var_partialPath_5844  COMMA_SOURCE_FILE ("goil_routines.galgas", 187)) ;
  cEnumerator_stringlist enumerator_5963 (var_components_5742, kENUMERATION_UP) ;
  while (enumerator_5963.hasCurrentObject ()) {
    var_partialPath_5844 = function_add_5F_path_5F_component (var_partialPath_5844, enumerator_5963.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 190)) ;
    {
    result_paths.setter_insertAtIndex (var_partialPath_5844, GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 191)) ;
    }
    enumerator_5963.gotoNextObject () ;
  }
//---
  return result_paths ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_allTemplatePaths [2] = {
  & kTypeDescriptor_GALGAS_string,
  nullptr
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
  GALGAS_string var_configDir_6146 = function_rootTemplatesDirectory (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 197)).add_operation (GALGAS_string ("/config"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 197)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = var_configDir_6146.getter_directoryExists (SOURCE_FILE ("goil_routines.galgas", 198)).operator_not (SOURCE_FILE ("goil_routines.galgas", 198)).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 199)), GALGAS_string ("The templates path '").add_operation (var_configDir_6146, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 199)).add_operation (GALGAS_string ("' is not set to the templates directory"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 199)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 199)) ;
    }
  }
  if (kBoolFalse == test_0) {
    GALGAS_string var_partialPath_6361 = var_configDir_6146 ;
    GALGAS_bool var_continueIt_6395 = GALGAS_bool (true) ;
    GALGAS_stringlist var_components_6433 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 203)) ;
    cEnumerator_stringlist enumerator_6542 (var_components_6433, kENUMERATION_UP) ;
    while (enumerator_6542.hasCurrentObject ()) {
      var_partialPath_6361 = var_partialPath_6361.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 205)).add_operation (enumerator_6542.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 205)) ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        GALGAS_bool test_3 = var_continueIt_6395 ;
        if (kBoolTrue == test_3.boolEnum ()) {
          test_3 = var_partialPath_6361.getter_directoryExists (SOURCE_FILE ("goil_routines.galgas", 206)).operator_not (SOURCE_FILE ("goil_routines.galgas", 206)) ;
        }
        test_2 = test_3.boolEnum () ;
        if (kBoolTrue == test_2) {
          TC_Array <C_FixItDescription> fixItArray4 ;
          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 207)), GALGAS_string ("The templates path '").add_operation (var_partialPath_6361, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 207)).add_operation (GALGAS_string ("' does not exist in the templates directory"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 207)), fixItArray4  COMMA_SOURCE_FILE ("goil_routines.galgas", 207)) ;
          var_continueIt_6395 = GALGAS_bool (false) ;
        }
      }
      enumerator_6542.gotoNextObject () ;
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
  GALGAS_stringlist var_components_6948 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 220)) ;
  GALGAS_string var_templateDir_7054 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 221)) ;
  GALGAS_bool var_notOver_7105 = GALGAS_bool (true) ;
  result_paths = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 223)) ;
  if (var_components_6948.getter_count (SOURCE_FILE ("goil_routines.galgas", 225)).add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 225)).isValid ()) {
    uint32_t variant_7158 = var_components_6948.getter_count (SOURCE_FILE ("goil_routines.galgas", 225)).add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 225)).uintValue () ;
    bool loop_7158 = true ;
    while (loop_7158) {
      loop_7158 = var_notOver_7105.isValid () ;
      if (loop_7158) {
        loop_7158 = var_notOver_7105.boolValue () ;
      }
      if (loop_7158 && (0 == variant_7158)) {
        loop_7158 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 225)) ;
      }
      if (loop_7158) {
        variant_7158 -- ;
        GALGAS_string var_intermediatePath_7218 = GALGAS_string::constructor_componentsJoinedByString (var_components_6948, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 227)) ;
        enumGalgasBool test_0 = kBoolTrue ;
        if (kBoolTrue == test_0) {
          test_0 = GALGAS_bool (kIsNotEqual, var_intermediatePath_7218.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_intermediatePath_7218.plusAssign_operation(GALGAS_string ("/"), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 228)) ;
          }
        }
        GALGAS_string var_targetPath_7370 = var_templateDir_7054.add_operation (var_intermediatePath_7218, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 229)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 229)) ;
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = var_targetPath_7370.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 231)).boolEnum () ;
          if (kBoolTrue == test_1) {
            result_paths.addAssign_operation (var_targetPath_7370  COMMA_SOURCE_FILE ("goil_routines.galgas", 232)) ;
          }
        }
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = GALGAS_bool (kIsStrictSup, var_components_6948.getter_count (SOURCE_FILE ("goil_routines.galgas", 234)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
          if (kBoolTrue == test_2) {
            {
            GALGAS_string joker_7594 ; // Joker input parameter
            var_components_6948.setter_popLast (joker_7594, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 235)) ;
            }
          }
        }
        if (kBoolFalse == test_2) {
          var_notOver_7105 = GALGAS_bool (false) ;
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
  nullptr
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
  GALGAS_lstring var_lkey_7718 = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 243))  COMMA_SOURCE_FILE ("goil_routines.galgas", 243)) ;
  GALGAS_string joker_7788 ; // Joker input parameter
  inArgument_p.method_prefix (var_lkey_7718, outArgument_val, joker_7788, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 244)) ;
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
  GALGAS_lstring var_lkey_7890 = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 248))  COMMA_SOURCE_FILE ("goil_routines.galgas", 248)) ;
  GALGAS_string var_prefix_7951 ;
  GALGAS_string var_tag_5F_to_5F_rep_7974 ;
  inArgument_p.method_prefix (var_lkey_7890, var_prefix_7951, var_tag_5F_to_5F_rep_7974, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 251)) ;
  ioArgument_res = ioArgument_res.getter_stringByReplacingStringByString (var_tag_5F_to_5F_rep_7974, var_prefix_7951.add_operation (inArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 252)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 252)) ;
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
  GALGAS_lstring var_lkey_8507 = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 268))  COMMA_SOURCE_FILE ("goil_routines.galgas", 268)) ;
  GALGAS_string var_tag_5F_to_5F_rep_8590 ;
  GALGAS_string joker_8621 ; // Joker input parameter
  inArgument_p.method_prefix (var_lkey_8507, joker_8621, var_tag_5F_to_5F_rep_8590, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 271)) ;
  ioArgument_res = ioArgument_res.getter_stringByReplacingStringByString (var_tag_5F_to_5F_rep_8590, inArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 272)) ;
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
  cEnumerator_stringset enumerator_9073 (inArgument_names, kENUMERATION_UP) ;
  while (enumerator_9073.hasCurrentObject ()) {
    ioArgument_header = ioArgument_header.add_operation (GALGAS_string ("#define "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (inArgument_varname, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (GALGAS_string ("_id_of_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (enumerator_9073.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (GALGAS_string ("  "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (var_n_9050.getter_string (SOURCE_FILE ("goil_routines.galgas", 291)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)) ;
    ioArgument_header = ioArgument_header.add_operation (GALGAS_string ("#define "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (enumerator_9073.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (GALGAS_string ("  "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (inArgument_varname, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (GALGAS_string ("_id_of_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (enumerator_9073.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)) ;
    ioArgument_implementation = ioArgument_implementation.add_operation (GALGAS_string ("    (tpl_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (inArgument_typename, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (GALGAS_string (" *)&"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (inArgument_obj_5F_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (enumerator_9073.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)) ;
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
    enumerator_9073.gotoNextObject () ;
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
  GALGAS_string var_include_5F_path_12900 = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("GOIL_INCLUDE_PATH")  COMMA_SOURCE_FILE ("goil_routines.galgas", 418)) ;
  GALGAS_stringlist var_systemPaths_13120 = function_allTemplatePaths (GALGAS_string ("config"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 422)) ;
  GALGAS_stringlist var_includePathList_13182 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, var_include_5F_path_12900.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      var_includePathList_13182 = var_include_5F_path_12900.getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("goil_routines.galgas", 425)) ;
    }
  }
  if (kBoolFalse == test_0) {
    var_includePathList_13182 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 427)) ;
  }
  GALGAS_stringlist var_path_5F_list_13386 = var_includePathList_13182.add_operation (var_systemPaths_13120, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 429)) ;
  GALGAS_bool var_not_5F_found_13439 = GALGAS_bool (true) ;
  cEnumerator_stringlist enumerator_13473 (var_path_5F_list_13386, kENUMERATION_UP) ;
  while (enumerator_13473.hasCurrentObject ()) {
    GALGAS_string var_full_5F_file_5F_path_13512 = enumerator_13473.current_mValue (HERE) ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsNotEqual, var_full_5F_file_5F_path_13512.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = GALGAS_bool (kIsNotEqual, var_full_5F_file_5F_path_13512.getter_characterAtIndex (var_full_5F_file_5F_path_13512.getter_count (SOURCE_FILE ("goil_routines.galgas", 435)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 435)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 435)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
          if (kBoolTrue == test_2) {
            var_full_5F_file_5F_path_13512.plusAssign_operation(GALGAS_string ("/"), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 436)) ;
          }
        }
      }
    }
    var_full_5F_file_5F_path_13512.plusAssign_operation(ioArgument_file_5F_name.readProperty_string (), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 439)) ;
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = var_full_5F_file_5F_path_13512.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 440)).operator_and (var_not_5F_found_13439 COMMA_SOURCE_FILE ("goil_routines.galgas", 440)).boolEnum () ;
      if (kBoolTrue == test_3) {
        ioArgument_file_5F_name = GALGAS_lstring::constructor_new (var_full_5F_file_5F_path_13512, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 441))  COMMA_SOURCE_FILE ("goil_routines.galgas", 441)) ;
        var_not_5F_found_13439 = GALGAS_bool (false) ;
      }
    }
    enumerator_13473.gotoNextObject () ;
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
  nullptr
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
  GALGAS_bool var_found_14492 ;
  GALGAS_lstring var_res_14513 ;
  {
  routine_is_5F_in_5F_lstringlist (ioArgument_l, inArgument_e, var_res_14513, var_found_14492, inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 480)) ;
  }
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = var_found_14492.boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (inArgument_e.readProperty_location (), inArgument_att.add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 482)).add_operation (inArgument_e.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 482)).add_operation (GALGAS_string (" has already be listed"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 482)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 482)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (var_res_14513.readProperty_location (), GALGAS_string ("was listed here"), fixItArray2  COMMA_SOURCE_FILE ("goil_routines.galgas", 483)) ;
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
  nullptr
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
    test_0 = GALGAS_bool (kIsStrictSup, inArgument_s.getter_count (SOURCE_FILE ("goil_routines.galgas", 515)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_uint var_first_15244 = GALGAS_uint (uint32_t (0U)) ;
      GALGAS_uint var_last_15264 = inArgument_s.getter_count (SOURCE_FILE ("goil_routines.galgas", 517)) ;
      GALGAS_bool var_finished_15348 = GALGAS_bool (false) ;
      if (inArgument_s.getter_count (SOURCE_FILE ("goil_routines.galgas", 520)).isValid ()) {
        uint32_t variant_15369 = inArgument_s.getter_count (SOURCE_FILE ("goil_routines.galgas", 520)).uintValue () ;
        bool loop_15369 = true ;
        while (loop_15369) {
          loop_15369 = var_finished_15348.operator_not (SOURCE_FILE ("goil_routines.galgas", 521)).isValid () ;
          if (loop_15369) {
            loop_15369 = var_finished_15348.operator_not (SOURCE_FILE ("goil_routines.galgas", 521)).boolValue () ;
          }
          if (loop_15369 && (0 == variant_15369)) {
            loop_15369 = false ;
            inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 520)) ;
          }
          if (loop_15369) {
            variant_15369 -- ;
            enumGalgasBool test_1 = kBoolTrue ;
            if (kBoolTrue == test_1) {
              test_1 = GALGAS_bool (kIsEqual, inArgument_s.getter_characterAtIndex (var_first_15244, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 522)).objectCompare (GALGAS_char (TO_UNICODE (32)))).boolEnum () ;
              if (kBoolTrue == test_1) {
                var_first_15244.increment_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 523)) ;
                enumGalgasBool test_2 = kBoolTrue ;
                if (kBoolTrue == test_2) {
                  test_2 = GALGAS_bool (kIsEqual, var_first_15244.objectCompare (inArgument_s.getter_count (SOURCE_FILE ("goil_routines.galgas", 524)))).boolEnum () ;
                  if (kBoolTrue == test_2) {
                    var_finished_15348 = GALGAS_bool (true) ;
                  }
                }
              }
            }
            if (kBoolFalse == test_1) {
              var_finished_15348 = GALGAS_bool (true) ;
            }
          }
        }
      }
      var_finished_15348 = GALGAS_bool (false) ;
      if (inArgument_s.getter_count (SOURCE_FILE ("goil_routines.galgas", 529)).isValid ()) {
        uint32_t variant_15654 = inArgument_s.getter_count (SOURCE_FILE ("goil_routines.galgas", 529)).uintValue () ;
        bool loop_15654 = true ;
        while (loop_15654) {
          loop_15654 = var_finished_15348.operator_not (SOURCE_FILE ("goil_routines.galgas", 530)).isValid () ;
          if (loop_15654) {
            loop_15654 = var_finished_15348.operator_not (SOURCE_FILE ("goil_routines.galgas", 530)).boolValue () ;
          }
          if (loop_15654 && (0 == variant_15654)) {
            loop_15654 = false ;
            inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 529)) ;
          }
          if (loop_15654) {
            variant_15654 -- ;
            enumGalgasBool test_3 = kBoolTrue ;
            if (kBoolTrue == test_3) {
              test_3 = GALGAS_bool (kIsEqual, inArgument_s.getter_characterAtIndex (var_last_15264.substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 531)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 531)).objectCompare (GALGAS_char (TO_UNICODE (32)))).boolEnum () ;
              if (kBoolTrue == test_3) {
                var_last_15264.decrement_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 532)) ;
                enumGalgasBool test_4 = kBoolTrue ;
                if (kBoolTrue == test_4) {
                  test_4 = GALGAS_bool (kIsEqual, var_last_15264.objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
                  if (kBoolTrue == test_4) {
                    var_finished_15348 = GALGAS_bool (true) ;
                  }
                }
              }
            }
            if (kBoolFalse == test_3) {
              var_finished_15348 = GALGAS_bool (true) ;
            }
          }
        }
      }
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsStrictInf, var_first_15244.objectCompare (var_last_15264)).boolEnum () ;
        if (kBoolTrue == test_5) {
          result_r = inArgument_s.getter_subString (var_first_15244, var_last_15264.substract_operation (var_first_15244, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 538)) COMMA_SOURCE_FILE ("goil_routines.galgas", 538)) ;
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
  nullptr
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
  cEnumerator_stringlist enumerator_16216 (constinArgument_searchedPaths, kENUMERATION_UP) ;
  while (enumerator_16216.hasCurrentObject ()) {
    var_m_16123.plusAssign_operation(GALGAS_string ("\n  - '").add_operation (enumerator_16216.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 553)).add_operation (GALGAS_string ("'"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 553)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 553)) ;
    enumerator_16216.gotoNextObject () ;
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
  nullptr
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
  GALGAS_gtlData var_subAttrs_928 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) this->mProperty_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 33)) ;
  {
  var_subAttrs_928.insulate (HERE) ;
  cPtr_gtlData * ptr_969 = (cPtr_gtlData *) var_subAttrs_928.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_969, GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), this->mProperty_structName.readProperty_location ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 35)), GALGAS_gtlString::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_structName.readProperty_string ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 36)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 34)) ;
  }
  {
  var_subAttrs_928.setter_setMeta (this->mProperty_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 38)) ;
  }
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_1124 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1124, constinArgument_name, var_subAttrs_928, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 39)) ;
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
  cPtr_gtlData * ptr_1570 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1570, constinArgument_name, GALGAS_gtlBool::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 52)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 52)) ;
  }
  GALGAS_gtlData var_subAttrs_1655 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) this->mProperty_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 53)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlStruct temp_1 ;
    if (var_subAttrs_1655.isValid ()) {
      if (nullptr != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_1655.ptr ())) {
        temp_1 = (cPtr_gtlStruct *) var_subAttrs_1655.ptr () ;
      }else{
        inCompiler->castError ("gtlStruct", var_subAttrs_1655.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 54)) ;
      }
    }
    test_0 = GALGAS_bool (kIsStrictSup, temp_1.readProperty_value ().getter_count (SOURCE_FILE ("systemConfig.galgas", 54)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_structName_1761 = GALGAS_lstring::constructor_new (constinArgument_name.readProperty_string ().add_operation (GALGAS_string ("_S"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 55)), constinArgument_name.readProperty_location ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 55)) ;
      {
      var_subAttrs_1655.setter_setMeta (this->mProperty_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 56)) ;
      }
      {
      ioArgument_result.insulate (HERE) ;
      cPtr_gtlData * ptr_1871 = (cPtr_gtlData *) ioArgument_result.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1871, var_structName_1761, var_subAttrs_1655, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 57)) ;
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
  cPtr_gtlData * ptr_2190 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2190, constinArgument_name, GALGAS_gtlString::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 66)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 66)) ;
  }
  GALGAS_gtlData var_subAttrs_2277 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) this->mProperty_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 67)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlStruct temp_1 ;
    if (var_subAttrs_2277.isValid ()) {
      if (nullptr != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_2277.ptr ())) {
        temp_1 = (cPtr_gtlStruct *) var_subAttrs_2277.ptr () ;
      }else{
        inCompiler->castError ("gtlStruct", var_subAttrs_2277.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 68)) ;
      }
    }
    test_0 = GALGAS_bool (kIsStrictSup, temp_1.readProperty_value ().getter_count (SOURCE_FILE ("systemConfig.galgas", 68)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_structName_2383 = GALGAS_lstring::constructor_new (constinArgument_name.readProperty_string ().add_operation (GALGAS_string ("_S"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 69)), constinArgument_name.readProperty_location ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 69)) ;
      {
      var_subAttrs_2277.setter_setMeta (this->mProperty_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 70)) ;
      }
      {
      ioArgument_result.insulate (HERE) ;
      cPtr_gtlData * ptr_2493 = (cPtr_gtlData *) ioArgument_result.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2493, var_structName_2383, var_subAttrs_2277, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 71)) ;
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
  cPtr_gtlData * ptr_2628 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2628, constinArgument_name, GALGAS_gtlString::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 76)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 76)) ;
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
  cPtr_gtlData * ptr_2785 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2785, constinArgument_name, GALGAS_gtlString::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 80)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 80)) ;
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
  cPtr_gtlData * ptr_2948 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2948, constinArgument_name, GALGAS_gtlString::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value.readProperty_string ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 84)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 84)) ;
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
  GALGAS_gtlList var_multiple_3116 = GALGAS_gtlList::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 88)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 88)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("systemConfig.galgas", 88))  COMMA_SOURCE_FILE ("systemConfig.galgas", 88)) ;
  cEnumerator_identifierList enumerator_3177 (this->mProperty_items, kENUMERATION_UP) ;
  while (enumerator_3177.hasCurrentObject ()) {
    GALGAS_gtlData var_multipleItem_3206 = GALGAS_gtlStruct::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 90))  COMMA_SOURCE_FILE ("systemConfig.galgas", 90)) ;
    if (enumerator_3177.current_item (HERE).isValid ()) {
      if (enumerator_3177.current_item (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_structAttribute) {
        GALGAS_structAttribute cast_3314_aStruct ((cPtr_structAttribute *) enumerator_3177.current_item (HERE).ptr ()) ;
        {
        var_multipleItem_3206.insulate (HERE) ;
        cPtr_gtlData * ptr_3333 = (cPtr_gtlData *) var_multipleItem_3206.ptr () ;
        callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3333, GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), cast_3314_aStruct.readProperty_location ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 94)), GALGAS_gtlString::constructor_new (cast_3314_aStruct.readProperty_location (), cast_3314_aStruct.readProperty_oil_5F_desc (), cast_3314_aStruct.readProperty_structName ().readProperty_string ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 95)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 93)) ;
        }
        GALGAS_gtlData var_subAttrs_3571 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) cast_3314_aStruct.readProperty_subAttributes ().ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 101)) ;
        enumGalgasBool test_0 = kBoolTrue ;
        if (kBoolTrue == test_0) {
          GALGAS_gtlStruct temp_1 ;
          if (var_subAttrs_3571.isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_3571.ptr ())) {
              temp_1 = (cPtr_gtlStruct *) var_subAttrs_3571.ptr () ;
            }else{
              inCompiler->castError ("gtlStruct", var_subAttrs_3571.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 102)) ;
            }
          }
          test_0 = GALGAS_bool (kIsStrictSup, temp_1.readProperty_value ().getter_count (SOURCE_FILE ("systemConfig.galgas", 102)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
          if (kBoolTrue == test_0) {
            GALGAS_gtlStruct temp_2 ;
            if (var_subAttrs_3571.isValid ()) {
              if (nullptr != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_3571.ptr ())) {
                temp_2 = (cPtr_gtlStruct *) var_subAttrs_3571.ptr () ;
              }else{
                inCompiler->castError ("gtlStruct", var_subAttrs_3571.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 103)) ;
              }
            }
            cEnumerator_gtlVarMap enumerator_3686 (temp_2.readProperty_value (), kENUMERATION_UP) ;
            while (enumerator_3686.hasCurrentObject ()) {
              {
              var_multipleItem_3206.insulate (HERE) ;
              cPtr_gtlData * ptr_3740 = (cPtr_gtlData *) var_multipleItem_3206.ptr () ;
              callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3740, enumerator_3686.current_lkey (HERE), enumerator_3686.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 104)) ;
              }
              enumerator_3686.gotoNextObject () ;
            }
          }
        }
      }else{
        callExtensionMethod_set ((cPtr_object_5F_t *) enumerator_3177.current_item (HERE).ptr (), GALGAS_lstring::constructor_new (GALGAS_string ("VALUE"), enumerator_3177.current_item (HERE).readProperty_location ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 108)), var_multipleItem_3206, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 108)) ;
      }
    }
    {
    var_multiple_3116.insulate (HERE) ;
    cPtr_gtlList * ptr_3904 = (cPtr_gtlList *) var_multiple_3116.ptr () ;
    callExtensionSetter_appendItem ((cPtr_gtlList *) ptr_3904, var_multipleItem_3206, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 110)) ;
    }
    enumerator_3177.gotoNextObject () ;
  }
  {
  var_multiple_3116.setter_setMeta (this->mProperty_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 112)) ;
  }
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_3983 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3983, constinArgument_name, var_multiple_3116, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 113)) ;
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
  cPtr_gtlData * ptr_4103 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4103, constinArgument_name, GALGAS_gtlInt::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 119))  COMMA_SOURCE_FILE ("systemConfig.galgas", 119)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 117)) ;
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
  cPtr_gtlData * ptr_4277 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4277, constinArgument_name, GALGAS_gtlInt::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 126))  COMMA_SOURCE_FILE ("systemConfig.galgas", 126)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 124)) ;
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
  cPtr_gtlData * ptr_4451 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4451, constinArgument_name, GALGAS_gtlInt::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 133))  COMMA_SOURCE_FILE ("systemConfig.galgas", 133)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 131)) ;
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
  cPtr_gtlData * ptr_4625 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4625, constinArgument_name, GALGAS_gtlInt::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 140))  COMMA_SOURCE_FILE ("systemConfig.galgas", 140)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 138)) ;
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
  cPtr_gtlData * ptr_4798 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4798, constinArgument_name, GALGAS_gtlFloat::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 147)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 145)) ;
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
  cPtr_gtlData * ptr_4957 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4957, constinArgument_name, GALGAS_gtlEnum::constructor_new (this->mProperty_location, this->mProperty_oil_5F_desc, GALGAS_string ("auto")  COMMA_SOURCE_FILE ("systemConfig.galgas", 154)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 152)) ;
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
  GALGAS_objectsMap var_objects_870 = ioArgument_application.readProperty_objects () ;
  cEnumerator_lstringlist enumerator_948 (var_objects_870.getter_keyList (SOURCE_FILE ("defaults.galgas", 35)), kENUMERATION_UP) ;
  while (enumerator_948.hasCurrentObject ()) {
    cMapElement_objectsMap * objectArray_989 = (cMapElement_objectsMap *) var_objects_870.readWriteAccessForWithInstructionWithErrorMessage (inCompiler, enumerator_948.current_mValue (HERE), kSearchErrorMessage_objectsMap_get  COMMA_SOURCE_FILE ("defaults.galgas", 36)) ;
    if (nullptr != objectArray_989) {
      macroValidSharedObject (objectArray_989, cMapElement_objectsMap) ;
      GALGAS_objectKindMap var_objOfKind_1061 = objectArray_989->mProperty_objectsOfKind.readProperty_objects () ;
      cEnumerator_lstringlist enumerator_1117 (var_objOfKind_1061.getter_keyList (SOURCE_FILE ("defaults.galgas", 38)), kENUMERATION_UP) ;
      while (enumerator_1117.hasCurrentObject ()) {
        cMapElement_objectKindMap * objectArray_1164 = (cMapElement_objectKindMap *) var_objOfKind_1061.readWriteAccessForWithInstructionWithErrorMessage (inCompiler, enumerator_1117.current_mValue (HERE), kSearchErrorMessage_objectKindMap_get  COMMA_SOURCE_FILE ("defaults.galgas", 39)) ;
        if (nullptr != objectArray_1164) {
          macroValidSharedObject (objectArray_1164, cMapElement_objectKindMap) ;
          GALGAS_implementationObject var_impObject_1253 = callExtensionGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), enumerator_948.current_mValue (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("defaults.galgas", 40)) ;
          {
          routine_setDefaultsForType (var_impObject_1253.readProperty_attributes (), objectArray_1164->mProperty_attributes, inCompiler  COMMA_SOURCE_FILE ("defaults.galgas", 41)) ;
          }
        }
        enumerator_1117.gotoNextObject () ;
      }
      {
      objectArray_989->mProperty_objectsOfKind.setter_setObjects (var_objOfKind_1061 COMMA_SOURCE_FILE ("defaults.galgas", 44)) ;
      }
    }
    enumerator_948.gotoNextObject () ;
  }
  {
  ioArgument_application.setter_setObjects (var_objects_870 COMMA_SOURCE_FILE ("defaults.galgas", 48)) ;
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
      GALGAS_structAttribute cast_2382_sa ((cPtr_structAttribute *) constinArgument_attr.ptr ()) ;
      cEnumerator_implementationObjectMap enumerator_2395 (this->mProperty_structAttributes, kENUMERATION_UP) ;
      while (enumerator_2395.hasCurrentObject ()) {
        enumGalgasBool test_0 = kBoolTrue ;
        if (kBoolTrue == test_0) {
          test_0 = cast_2382_sa.readProperty_subAttributes ().readProperty_objectParams ().getter_hasKey (enumerator_2395.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("semantic_verification.galgas", 88)).boolEnum () ;
          if (kBoolTrue == test_0) {
            GALGAS_object_5F_t var_subAttr_2516 ;
            cast_2382_sa.readProperty_subAttributes ().readProperty_objectParams ().method_get (enumerator_2395.current_lkey (HERE), var_subAttr_2516, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 90)) ;
            callExtensionMethod_verifyMultipleType ((cPtr_impType *) enumerator_2395.current_type (HERE).ptr (), var_subAttr_2516, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 91)) ;
          }
        }
        enumerator_2395.gotoNextObject () ;
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
          cEnumerator_implementationObjectMap enumerator_3180 (this->mProperty_trueSubAttributes, kENUMERATION_UP) ;
          while (enumerator_3180.hasCurrentObject ()) {
            enumGalgasBool test_1 = kBoolTrue ;
            if (kBoolTrue == test_1) {
              test_1 = cast_3144_b.readProperty_subAttributes ().readProperty_objectParams ().getter_hasKey (enumerator_3180.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("semantic_verification.galgas", 116)).boolEnum () ;
              if (kBoolTrue == test_1) {
                GALGAS_object_5F_t var_subAttrs_3305 ;
                cast_3144_b.readProperty_subAttributes ().readProperty_objectParams ().method_get (enumerator_3180.current_lkey (HERE), var_subAttrs_3305, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 118)) ;
                callExtensionMethod_verifyMultipleType ((cPtr_impType *) enumerator_3180.current_type (HERE).ptr (), var_subAttrs_3305, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 119)) ;
              }
            }
            enumerator_3180.gotoNextObject () ;
          }
        }
      }
      if (kBoolFalse == test_0) {
        cEnumerator_implementationObjectMap enumerator_3466 (this->mProperty_falseSubAttributes, kENUMERATION_UP) ;
        while (enumerator_3466.hasCurrentObject ()) {
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            test_2 = cast_3144_b.readProperty_subAttributes ().readProperty_objectParams ().getter_hasKey (enumerator_3466.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("semantic_verification.galgas", 124)).boolEnum () ;
            if (kBoolTrue == test_2) {
              GALGAS_object_5F_t var_subAttrs_3592 ;
              cast_3144_b.readProperty_subAttributes ().readProperty_objectParams ().method_get (enumerator_3466.current_lkey (HERE), var_subAttrs_3592, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 126)) ;
              callExtensionMethod_verifyMultipleType ((cPtr_impType *) enumerator_3466.current_type (HERE).ptr (), var_subAttrs_3592, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 127)) ;
            }
          }
          enumerator_3466.gotoNextObject () ;
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
          GALGAS_implementationObjectMap var_validVal_4066 ;
          this->mProperty_valuesMap.method_get (function_lstringWith (cast_3985_e.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 143)), var_validVal_4066, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 143)) ;
          cEnumerator_implementationObjectMap enumerator_4142 (var_validVal_4066, kENUMERATION_UP) ;
          while (enumerator_4142.hasCurrentObject ()) {
            enumGalgasBool test_1 = kBoolTrue ;
            if (kBoolTrue == test_1) {
              test_1 = cast_3985_e.readProperty_subAttributes ().readProperty_objectParams ().getter_hasKey (enumerator_4142.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("semantic_verification.galgas", 145)).boolEnum () ;
              if (kBoolTrue == test_1) {
                GALGAS_object_5F_t var_subAttrs_4258 ;
                cast_3985_e.readProperty_subAttributes ().readProperty_objectParams ().method_get (enumerator_4142.current_lkey (HERE), var_subAttrs_4258, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 147)) ;
                callExtensionMethod_verifyMultipleType ((cPtr_impType *) enumerator_4142.current_type (HERE).ptr (), var_subAttrs_4258, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 148)) ;
              }
            }
            enumerator_4142.gotoNextObject () ;
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
    if (nullptr != dynamic_cast <const cPtr_impAutoDefaultType *> (constinArgument_type.ptr ())) {
      GALGAS_impAutoDefaultType cast_6579_autoType ((cPtr_impAutoDefaultType *) constinArgument_type.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = cast_6579_autoType.readProperty_withAuto ().operator_not (SOURCE_FILE ("semantic_verification.galgas", 225)).boolEnum () ;
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
  nullptr
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
  cEnumerator_objectsMap enumerator_6885 (constinArgument_objects, kENUMERATION_UP) ;
  while (enumerator_6885.hasCurrentObject ()) {
    GALGAS_implementationObject var_impObj_6933 = callExtensionGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), enumerator_6885.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 242)) ;
    cEnumerator_objectKindMap enumerator_7036 (enumerator_6885.current_objectsOfKind (HERE).readProperty_objects (), kENUMERATION_UP) ;
    while (enumerator_7036.hasCurrentObject ()) {
      cEnumerator_implementationObjectMap enumerator_7085 (var_impObj_6933.readProperty_attributes (), kENUMERATION_UP) ;
      while (enumerator_7085.hasCurrentObject ()) {
        enumGalgasBool test_0 = kBoolTrue ;
        if (kBoolTrue == test_0) {
          test_0 = enumerator_7036.current_attributes (HERE).readProperty_objectParams ().getter_hasKey (enumerator_7085.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("semantic_verification.galgas", 246)).boolEnum () ;
          if (kBoolTrue == test_0) {
            GALGAS_object_5F_t var_value_7316 ;
            enumerator_7036.current_attributes (HERE).readProperty_objectParams ().method_get (enumerator_7085.current_lkey (HERE), var_value_7316, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 250)) ;
            if (var_value_7316.isValid ()) {
              if (var_value_7316.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
                enumGalgasBool test_1 = kBoolTrue ;
                if (kBoolTrue == test_1) {
                  test_1 = function_attributeAllowsAuto (enumerator_7085.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 254)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 254)).boolEnum () ;
                  if (kBoolTrue == test_1) {
                    TC_Array <C_FixItDescription> fixItArray2 ;
                    inCompiler->emitSemanticError (var_value_7316.readProperty_location (), GALGAS_string ("AUTO value is not allowed for the ").add_operation (enumerator_6885.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)), fixItArray2  COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)) ;
                  }
                }
              }
            }
          }
        }
        if (kBoolFalse == test_0) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = function_attributeAllowsAuto (enumerator_7085.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 260)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 260)).operator_and (enumerator_7085.current_type (HERE).readProperty_multiple ().operator_not (SOURCE_FILE ("semantic_verification.galgas", 260)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 260)).boolEnum () ;
            if (kBoolTrue == test_3) {
              TC_Array <C_FixItDescription> fixItArray4 ;
              inCompiler->emitSemanticError (enumerator_7036.current_lkey (HERE).readProperty_location (), GALGAS_string ("In ").add_operation (enumerator_6885.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (enumerator_7036.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (", attribute "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (enumerator_7085.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (" is not defined and is not AUTO"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)), fixItArray4  COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)) ;
            }
          }
        }
        if (enumerator_7085.current_type (HERE).isValid ()) {
          if (enumerator_7085.current_type (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impAutoDefaultType) {
          }
        }
        enumerator_7085.gotoNextObject () ;
      }
      enumerator_7036.gotoNextObject () ;
    }
    enumerator_6885.gotoNextObject () ;
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
  cEnumerator_identifierList enumerator_19057 (this->mProperty_items, kENUMERATION_UP) ;
  while (enumerator_19057.hasCurrentObject ()) {
    callExtensionMethod_verifyCrossReferences ((cPtr_object_5F_t *) enumerator_19057.current_item (HERE).ptr (), constinArgument_allObjects, constinArgument_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 617)) ;
    enumerator_19057.gotoNextObject () ;
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
    if (nullptr != dynamic_cast <const cPtr_impBoolType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impBoolType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impBoolType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 625)) ;
    }
  }
  GALGAS_impBoolType var_boolType_19259 = temp_0 ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = this->mProperty_value.boolEnum () ;
    if (kBoolTrue == test_1) {
      callExtensionMethod_verifyCrossReferences ((cPtr_objectAttributes *) this->mProperty_subAttributes.ptr (), constinArgument_allObjects, var_boolType_19259.readProperty_trueSubAttributes (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 627)) ;
    }
  }
  if (kBoolFalse == test_1) {
    callExtensionMethod_verifyCrossReferences ((cPtr_objectAttributes *) this->mProperty_subAttributes.ptr (), constinArgument_allObjects, var_boolType_19259.readProperty_falseSubAttributes (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 629)) ;
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
    if (nullptr != dynamic_cast <const cPtr_impEnumType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impEnumType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impEnumType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 637)) ;
    }
  }
  GALGAS_impEnumType var_enumType_19619 = temp_0 ;
  GALGAS_lstring var_key_19666 = GALGAS_lstring::constructor_new (this->mProperty_value, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("semantic_verification.galgas", 638))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 638)) ;
  GALGAS_implementationObjectMap var_expectedAttributes_19764 ;
  var_enumType_19619.readProperty_valuesMap ().method_get (var_key_19666, var_expectedAttributes_19764, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 639)) ;
  callExtensionMethod_verifyCrossReferences ((cPtr_objectAttributes *) this->mProperty_subAttributes.ptr (), constinArgument_allObjects, var_expectedAttributes_19764, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 640)) ;
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
    if (nullptr != dynamic_cast <const cPtr_impStructType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impStructType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impStructType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 647)) ;
    }
  }
  GALGAS_impStructType var_structType_19990 = temp_0 ;
  callExtensionMethod_verifyCrossReferences ((cPtr_objectAttributes *) this->mProperty_subAttributes.ptr (), constinArgument_allObjects, var_structType_19990.readProperty_structAttributes (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 648)) ;
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
    if (nullptr != dynamic_cast <const cPtr_refType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_refType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("refType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 655)) ;
    }
  }
  GALGAS_refType var_refType_20240 = temp_0 ;
  GALGAS_objectKind var_kindMap_20367 ;
  constinArgument_allObjects.method_get (var_refType_20240.readProperty_ref (), var_kindMap_20367, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 657)) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = var_kindMap_20367.readProperty_objects ().getter_hasKey (this->mProperty_value.readProperty_string () COMMA_SOURCE_FILE ("semantic_verification.galgas", 658)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 658)).boolEnum () ;
    if (kBoolTrue == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (this->mProperty_value.readProperty_location (), GALGAS_string ("Referenced ").add_operation (var_refType_20240.readProperty_ref ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (this->mProperty_value.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (GALGAS_string (" does not exist"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)), fixItArray2  COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)) ;
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
  nullptr
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
  GALGAS_objectKind var_objectsForKind_1572 ;
  constinArgument_objects.method_get (function_lstringWith (GALGAS_string ("OS"), inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 67)), var_objectsForKind_1572, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 67)) ;
  GALGAS_lstringlist var_names_1658 = var_objectsForKind_1572.readProperty_objects ().getter_keyList (SOURCE_FILE ("goil_types_root.galgas", 68)) ;
  GALGAS_lstring var_name_1716 ;
  var_names_1658.method_first (var_name_1716, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 70)) ;
  var_objectsForKind_1572.readProperty_objects ().method_get (var_name_1716, result_os, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 71)) ;
//---
  return result_os ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_osObject [2] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  nullptr
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
      GALGAS_objectKind var_kindObj_1966 ;
      constinArgument_objects.method_get (function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 81)), var_kindObj_1966, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 81)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = var_kindObj_1966.readProperty_objects ().getter_hasKey (constinArgument_name COMMA_SOURCE_FILE ("goil_types_root.galgas", 82)).boolEnum () ;
        if (kBoolTrue == test_1) {
          var_kindObj_1966.readProperty_objects ().method_get (function_lstringWith (constinArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 83)), result_object, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 83)) ;
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
  nullptr
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
  GALGAS_lstring var_lkind_2431 = function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 97)) ;
  GALGAS_lstring var_lname_2473 = function_lstringWith (constinArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 98)) ;
  GALGAS_objectKind var_kindObj_2514 = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 99))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 99)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = ioArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 100)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      ioArgument_objects.setter_del (var_lkind_2431, var_kindObj_2514, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 101)) ;
      }
    }
  }
  GALGAS_objectKindMap var_kindMap_2662 = var_kindObj_2514.readProperty_objects () ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = var_kindMap_2662.getter_hasKey (constinArgument_name COMMA_SOURCE_FILE ("goil_types_root.galgas", 104)).boolEnum () ;
    if (kBoolTrue == test_1) {
      {
      GALGAS_objectAttributes joker_2749 ; // Joker input parameter
      var_kindMap_2662.setter_del (var_lname_2473, joker_2749, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 105)) ;
      }
    }
  }
  {
  var_kindMap_2662.setter_put (var_lname_2473, constinArgument_object, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 107)) ;
  }
  {
  var_kindObj_2514.setter_setObjects (var_kindMap_2662 COMMA_SOURCE_FILE ("goil_types_root.galgas", 108)) ;
  }
  {
  ioArgument_objects.setter_put (var_lkind_2431, var_kindObj_2514, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 109)) ;
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
  nullptr
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
  GALGAS_object_5F_t var_itemsContainer_3225 ;
  GALGAS_objectAttributes var_os_3264 = function_osObject (constinArgument_objects, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 128)) ;
  var_os_3264.readProperty_objectParams ().method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 129)), var_itemsContainer_3225, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 129)) ;
  result_items = function_multipleAttributeOrError (var_itemsContainer_3225, constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 130)) ;
//---
  return result_items ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_listInOS [3] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  nullptr
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
//Function 'customGtlStringGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData function_customGtlStringGetter (const GALGAS_lstring & constinArgument_methodName,
                                               const GALGAS_gtlDataList & constinArgument_arguments,
                                               const GALGAS_gtlContext &,
                                               const GALGAS_library &,
                                               const GALGAS_string & constinArgument_value,
                                               const GALGAS_location & constinArgument_where,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("parseOIL").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 11)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 11)) ;
      }
      GALGAS_string var_rootTemplatesDir_343 = function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 12)) ;
      GALGAS_implementation var_imp_407 = GALGAS_implementation::constructor_new (GALGAS_implementationMap::constructor_emptyMap (SOURCE_FILE ("goil_gtl_extension.galgas", 13))  COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 13)) ;
      GALGAS_applicationDefinition var_app_493 = function_emptyApplicationDefinition (inCompiler COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 14)) ;
      GALGAS_lstring var_includeToParse_545 = GALGAS_lstring::constructor_new (var_rootTemplatesDir_343.add_operation (GALGAS_string ("libraries/config.oil"), inCompiler COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 16)), constinArgument_where  COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 15)) ;
      GALGAS_lstring var_fileToParse_661 = GALGAS_lstring::constructor_new (var_rootTemplatesDir_343.add_operation (GALGAS_string ("libraries/"), inCompiler COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 20)).add_operation (constinArgument_value, inCompiler COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 20)), constinArgument_where  COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 19)) ;
      cGrammar_goil_5F_file_5F_level_5F_include_5F_without_5F_include::_performSourceFileParsing_ (inCompiler, var_includeToParse_545, var_imp_407, var_app_493  COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 23)) ;
      cGrammar_goil_5F_file_5F_level_5F_include_5F_without_5F_include::_performSourceFileParsing_ (inCompiler, var_fileToParse_661, var_imp_407, var_app_493  COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 26)) ;
      GALGAS_gtlData var_templateData_957 = callExtensionGetter_templateData ((const cPtr_applicationDefinition *) var_app_493.ptr (), var_imp_407, inCompiler COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 29)) ;
      result_result = var_templateData_957 ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 32)).add_operation (GALGAS_string ("' for string target"), inCompiler COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 32)), fixItArray1  COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 32)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_customGtlStringGetter [7] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_gtlDataList,
  & kTypeDescriptor_GALGAS_gtlContext,
  & kTypeDescriptor_GALGAS_library,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_location,
  nullptr
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_customGtlStringGetter (C_Compiler * inCompiler,
                                                                      const cObjectArray & inEffectiveParameterArray,
                                                                      const GALGAS_location & /* inErrorLocation */
                                                                      COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_gtlDataList operand1 = GALGAS_gtlDataList::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_gtlContext operand2 = GALGAS_gtlContext::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_library operand3 = GALGAS_library::extractObject (inEffectiveParameterArray.objectAtIndex (3 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_string operand4 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (4 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_location operand5 = GALGAS_location::extractObject (inEffectiveParameterArray.objectAtIndex (5 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  return function_customGtlStringGetter (operand0,
                                         operand1,
                                         operand2,
                                         operand3,
                                         operand4,
                                         operand5,
                                         inCompiler
                                         COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_customGtlStringGetter ("customGtlStringGetter",
                                                                       functionWithGenericHeader_customGtlStringGetter,
                                                                       & kTypeDescriptor_GALGAS_gtlData,
                                                                       6,
                                                                       functionArgs_customGtlStringGetter) ;

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
  GALGAS_uint_36__34_ var_max_5F_s_38__1048 = GALGAS_uint_36__34_ (uint64_t (128ULL)) ;
  GALGAS_uint_36__34_ var_max_5F_s_31__36__1079 = GALGAS_uint_36__34_ (uint64_t (32768ULL)) ;
  GALGAS_uint_36__34_ var_max_5F_s_33__32__1111 = GALGAS_uint_36__34_ (uint64_t (2147483648ULL)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_38__1048)).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_type = GALGAS_string ("s8") ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_31__36__1079)).boolEnum () ;
      if (kBoolTrue == test_1) {
        outArgument_type = GALGAS_string ("s16") ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_33__32__1111)).boolEnum () ;
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
  GALGAS_uint_36__34_ var_max_5F_u_38__1504 = GALGAS_uint_36__34_ (uint64_t (256ULL)) ;
  GALGAS_uint_36__34_ var_max_5F_u_31__36__1535 = GALGAS_uint_36__34_ (uint64_t (65536ULL)) ;
  GALGAS_uint_36__34_ var_max_5F_u_33__32__1567 = GALGAS_uint_36__34_ (uint64_t (4294967296ULL)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_38__1504)).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_type = GALGAS_string ("u8") ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_31__36__1535)).boolEnum () ;
      if (kBoolTrue == test_1) {
        outArgument_type = GALGAS_string ("u16") ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_33__32__1567)).boolEnum () ;
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
  GALGAS_uint_36__34_ var_max_5F_u_38__1954 = GALGAS_uint_36__34_ (uint64_t (8ULL)) ;
  GALGAS_uint_36__34_ var_max_5F_u_31__36__1980 = GALGAS_uint_36__34_ (uint64_t (16ULL)) ;
  GALGAS_uint_36__34_ var_max_5F_u_33__32__2007 = GALGAS_uint_36__34_ (uint64_t (32ULL)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_38__1954)).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_type = GALGAS_string ("u8") ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_31__36__1980)).boolEnum () ;
      if (kBoolTrue == test_1) {
        outArgument_type = GALGAS_string ("u16") ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_33__32__2007)).boolEnum () ;
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
  GALGAS_string var_stringPrefix_22321 = this->mProperty_prefix.readProperty_string () ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("compiler").objectCompare (var_stringPrefix_22321)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlData var_compiler_22438 ;
      GALGAS_bool joker_22447 ; // Joker input parameter
      callExtensionMethod_structField ((cPtr_gtlData *) constinArgument_vars.ptr (), function_lstring (GALGAS_string ("COMPILER"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 691)), var_compiler_22438, joker_22447, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 691)) ;
      GALGAS_gtlString temp_1 ;
      if (var_compiler_22438.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (var_compiler_22438.ptr ())) {
          temp_1 = (cPtr_gtlString *) var_compiler_22438.ptr () ;
        }else{
          inCompiler->castError ("gtlString", var_compiler_22438.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)) ;
        }
      }
      var_stringPrefix_22321.plusAssign_operation(GALGAS_string ("/").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)), inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("linker").objectCompare (var_stringPrefix_22321)).boolEnum () ;
      if (kBoolTrue == test_2) {
        GALGAS_gtlData var_linker_22596 ;
        GALGAS_bool joker_22603 ; // Joker input parameter
        callExtensionMethod_structField ((cPtr_gtlData *) constinArgument_vars.ptr (), function_lstring (GALGAS_string ("LINKER"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 694)), var_linker_22596, joker_22603, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 694)) ;
        GALGAS_gtlString temp_3 ;
        if (var_linker_22596.isValid ()) {
          if (nullptr != dynamic_cast <const cPtr_gtlString *> (var_linker_22596.ptr ())) {
            temp_3 = (cPtr_gtlString *) var_linker_22596.ptr () ;
          }else{
            inCompiler->castError ("gtlString", var_linker_22596.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)) ;
          }
        }
        var_stringPrefix_22321.plusAssign_operation(GALGAS_string ("/").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) temp_3.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)), inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("assembler").objectCompare (var_stringPrefix_22321)).boolEnum () ;
        if (kBoolTrue == test_4) {
          GALGAS_gtlData var_assembler_22756 ;
          GALGAS_bool joker_22766 ; // Joker input parameter
          callExtensionMethod_structField ((cPtr_gtlData *) constinArgument_vars.ptr (), function_lstring (GALGAS_string ("ASSEMBLER"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 697)), var_assembler_22756, joker_22766, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 697)) ;
          GALGAS_gtlString temp_5 ;
          if (var_assembler_22756.isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlString *> (var_assembler_22756.ptr ())) {
              temp_5 = (cPtr_gtlString *) var_assembler_22756.ptr () ;
            }else{
              inCompiler->castError ("gtlString", var_assembler_22756.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)) ;
            }
          }
          var_stringPrefix_22321.plusAssign_operation(GALGAS_string ("/").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) temp_5.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)), inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)) ;
        }
      }
      if (kBoolFalse == test_4) {
        enumGalgasBool test_6 = kBoolTrue ;
        if (kBoolTrue == test_6) {
          test_6 = GALGAS_bool (kIsEqual, var_stringPrefix_22321.objectCompare (GALGAS_string ("ROOT"))).boolEnum () ;
          if (kBoolTrue == test_6) {
            var_stringPrefix_22321 = GALGAS_string::makeEmptyString () ;
          }
        }
      }
    }
  }
  result_full = GALGAS_lstring::constructor_new (var_stringPrefix_22321, this->mProperty_prefix.readProperty_location ()  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 702)) ;
//---
  return result_full ;
}



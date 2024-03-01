#include "Compiler.h"
#include "C_galgas_io.h"
#include "C_galgas_CLI_Options.h"
#include "PrologueEpilogue.h"

//--------------------------------------------------------------------------------------------------

#include "all-declarations-10.h"

//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlTemplateInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlTemplateInstruction::method_display (Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlEmitInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlEmitInstruction::method_display (Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("! ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1354)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1354))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1354)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlIfStatementInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlIfStatementInstruction::method_display (Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("if ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_thenElsifList.getter_conditionAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1361)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1361)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1360)).add_operation (GALGAS_string (" then"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1361))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1360)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlForStatementInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlForStatementInstruction::method_display (Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("for ").add_operation (this->mProperty_identifier.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1368)).add_operation (GALGAS_string (" in "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1369)).add_operation (extensionGetter_stringRepresentation (this->mProperty_iterable, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1371)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1370)).add_operation (GALGAS_string (" do"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1371))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1368)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlForeachStatementInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlForeachStatementInstruction::method_display (Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlGetColumnInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlGetColumnInstruction::method_display (Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("\? ").add_operation (extensionGetter_stringRepresentation (this->mProperty_destVariable, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1389)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1389))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1389)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLibrariesInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLibrariesInstruction::method_display (Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("libraries")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1395)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlRepeatStatementInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlRepeatStatementInstruction::method_display (Compiler * inCompiler
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
            test_0 = GALGAS_bool (kIsNotEqual, cast_42153_intLimit.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1406)).objectCompare (GALGAS_uint::class_func_max (SOURCE_FILE ("gtl_debugger.galgas", 1406)))).boolEnum () ;
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlSetterCallInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlSetterCallInstruction::method_display (Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlVariablesInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlVariablesInstruction::method_display (Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("variables")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1431)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWriteToInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlWriteToInstruction::method_display (Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlTabStatementInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlTabStatementInstruction::method_display (Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("tab ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_tabValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1447)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1447))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1447)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlDisplayStatementInstruction mayExecuteWithoutError'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlDisplayStatementInstruction::getter_mayExecuteWithoutError (const GALGAS_gtlContext constinArgument_exeContext,
                                                                                const GALGAS_gtlData constinArgument_context,
                                                                                const GALGAS_library constinArgument_lib,
                                                                                Compiler * inCompiler
                                                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_may ; // Returned variable
  result_may = extensionGetter_exists (this->mProperty_variablePath, constinArgument_exeContext, constinArgument_context, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1468)) ;
//---
  return result_may ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlStepInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlStepInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                              GALGAS_gtlData & /* ioArgument_vars */,
                                              GALGAS_library & /* ioArgument_lib */,
                                              GALGAS_string & /* ioArgument_outputString */,
                                              Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_44266 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_setLoopOnCommand ((cPtr_gtlContext *) ptr_44266, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1482)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlStepInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlStepInstruction::method_display (Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("step")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1487)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDoInstInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlDoInstInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                GALGAS_gtlData & /* ioArgument_vars */,
                                                GALGAS_library & /* ioArgument_lib */,
                                                GALGAS_string & /* ioArgument_outputString */,
                                                Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_44830 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_appendInstructionToStepDo ((cPtr_gtlContext *) ptr_44830, this->mProperty_instructionToDo, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1504)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDoInstInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlDoInstInstruction::method_display (Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("do ")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1509)) ;
  callExtensionMethod_display ((cPtr_gtlInstruction *) this->mProperty_instructionToDo.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1510)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDoNotInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlDoNotInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                               GALGAS_gtlData & /* ioArgument_vars */,
                                               GALGAS_library & /* ioArgument_lib */,
                                               GALGAS_string & /* ioArgument_outputString */,
                                               Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_45425 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteStepDoInstruction ((cPtr_gtlContext *) ptr_45425, this->mProperty_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1527)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDoNotInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlDoNotInstruction::method_display (Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("do not ").add_operation (this->mProperty_numToDelete.readProperty_bigint ().getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1532)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1532))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1532)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDoNotAllInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlDoNotAllInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                  GALGAS_gtlData & /* ioArgument_vars */,
                                                  GALGAS_library & /* ioArgument_lib */,
                                                  GALGAS_string & /* ioArgument_outputString */,
                                                  Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_45993 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteAllStepDoInstructions ((cPtr_gtlContext *) ptr_45993, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1548)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDoNotAllInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlDoNotAllInstruction::method_display (Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("do not all")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1553)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDoInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlDoInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                            GALGAS_gtlData & /* ioArgument_vars */,
                                            GALGAS_library & /* ioArgument_lib */,
                                            GALGAS_string & /* ioArgument_outputString */,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  callExtensionMethod_listStepDoInstructions ((cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1569)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDoInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlDoInstruction::method_display (Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("do")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1574)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlContinueInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlContinueInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                  GALGAS_gtlData & /* ioArgument_vars */,
                                                  GALGAS_library & /* ioArgument_lib */,
                                                  GALGAS_string & /* ioArgument_outputString */,
                                                  Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlContinueInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlContinueInstruction::method_display (Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("cont")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1596)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBreakpointInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                    GALGAS_gtlData & /* ioArgument_vars */,
                                                    GALGAS_library & /* ioArgument_lib */,
                                                    GALGAS_string & /* ioArgument_outputString */,
                                                    Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBreakpointInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointInstruction::method_display (Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("break ").add_operation (this->mProperty_fileName, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1635)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1635)).add_operation (this->mProperty_lineNum.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1635)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1635))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1635)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBreakpointListInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointListInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                        GALGAS_gtlData & /* ioArgument_vars */,
                                                        GALGAS_library & /* ioArgument_lib */,
                                                        GALGAS_string & /* ioArgument_outputString */,
                                                        Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  callExtensionMethod_listBreakpoints ((cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1651)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBreakpointListInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointListInstruction::method_display (Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("break")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1656)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBreakpointDeleteInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointDeleteInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                          GALGAS_gtlData & /* ioArgument_vars */,
                                                          GALGAS_library & /* ioArgument_lib */,
                                                          GALGAS_string & /* ioArgument_outputString */,
                                                          Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_49427 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteBreakpoint ((cPtr_gtlContext *) ptr_49427, this->mProperty_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1673)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBreakpointDeleteInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointDeleteInstruction::method_display (Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("break not ").add_operation (this->mProperty_numToDelete.readProperty_bigint ().getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1678)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1678))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1678)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBreakpointDeleteAllInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointDeleteAllInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                             GALGAS_gtlData & /* ioArgument_vars */,
                                                             GALGAS_library & /* ioArgument_lib */,
                                                             GALGAS_string & /* ioArgument_outputString */,
                                                             Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_50035 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteAllBreakpoints ((cPtr_gtlContext *) ptr_50035, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1694)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBreakpointDeleteAllInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointDeleteAllInstruction::method_display (Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("break not all")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1699)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWatchpointInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                    GALGAS_gtlData & /* ioArgument_vars */,
                                                    GALGAS_library & /* ioArgument_lib */,
                                                    GALGAS_string & /* ioArgument_outputString */,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_50627 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_setWatchpoint ((cPtr_gtlContext *) ptr_50627, this->mProperty_watchExpression, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1716)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWatchpointInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointInstruction::method_display (Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("watch ( ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_watchExpression.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1721)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1721)).add_operation (GALGAS_string (" )"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1721))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1721)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWatchpointListInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointListInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                        GALGAS_gtlData & /* ioArgument_vars */,
                                                        GALGAS_library & /* ioArgument_lib */,
                                                        GALGAS_string & /* ioArgument_outputString */,
                                                        Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  callExtensionMethod_listWatchpoints ((cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1737)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWatchpointListInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointListInstruction::method_display (Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("watch")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1742)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWatchpointDeleteInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointDeleteInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                          GALGAS_gtlData & /* ioArgument_vars */,
                                                          GALGAS_library & /* ioArgument_lib */,
                                                          GALGAS_string & /* ioArgument_outputString */,
                                                          Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_51813 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteWatchpoint ((cPtr_gtlContext *) ptr_51813, this->mProperty_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1759)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWatchpointDeleteInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointDeleteInstruction::method_display (Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("watch not ").add_operation (this->mProperty_numToDelete.readProperty_bigint ().getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1764)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1764))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1764)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWatchpointDeleteAllInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointDeleteAllInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                             GALGAS_gtlData & /* ioArgument_vars */,
                                                             GALGAS_library & /* ioArgument_lib */,
                                                             GALGAS_string & /* ioArgument_outputString */,
                                                             Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_52422 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteAllWatchpoints ((cPtr_gtlContext *) ptr_52422, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1780)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWatchpointDeleteAllInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointDeleteAllInstruction::method_display (Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("watch not all")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1785)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlListInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlListInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                              GALGAS_gtlData & /* ioArgument_vars */,
                                              GALGAS_library & /* ioArgument_lib */,
                                              GALGAS_string & /* ioArgument_outputString */,
                                              Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  callExtensionMethod_hereWeAre ((cPtr_gtlContext *) ioArgument_context.ptr (), this->mProperty_window, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1802)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlListInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlListInstruction::method_display (Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("list ").add_operation (this->mProperty_window.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1807)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1807))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1807)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlHistoryInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlHistoryInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                 GALGAS_gtlData & /* ioArgument_vars */,
                                                 GALGAS_library & /* ioArgument_lib */,
                                                 GALGAS_string & /* ioArgument_outputString */,
                                                 Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  callExtensionMethod_listHistory ((cPtr_debugCommandInput *) ioArgument_context.readProperty_debuggerContext ().readProperty_commandInput ().ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1823)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlHistoryInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlHistoryInstruction::method_display (Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("hist")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1828)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLoadInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLoadInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                              GALGAS_gtlData & ioArgument_vars,
                                              GALGAS_library & ioArgument_lib,
                                              GALGAS_string & /* ioArgument_outputString */,
                                              Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_loadCommandFile (this->mProperty_fileName, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1845)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLoadInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlLoadInstruction::method_display (Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("load \"").add_operation (this->mProperty_fileName, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1850)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1850))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1850)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlHelpInstruction execute'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlHelpInstruction::method_execute (GALGAS_gtlContext & /* ioArgument_context */,
                                              GALGAS_gtlData & /* ioArgument_vars */,
                                              GALGAS_library & /* ioArgument_lib */,
                                              GALGAS_string & /* ioArgument_outputString */,
                                              Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlHelpInstruction display'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlHelpInstruction::method_display (Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("help")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1897)) ;
}
//--------------------------------------------------------------------------------------------------
//
//                               Bool options                                                    
//
//--------------------------------------------------------------------------------------------------

C_BoolCommandLineOption gOption_goil_5F_options_arxmlDisplayOil ("goil_options",
                                         "arxmlDisplayOil",
                                         0,
                                         "arxmlPrintOil",
                                         "Display an Oil version while parsing an arxml file") ;

C_BoolCommandLineOption gOption_goil_5F_options_warnMultiple ("goil_options",
                                         "warnMultiple",
                                         0,
                                         "warn-multiple",
                                         "Emit a warning if an object not defined for the first time in the implementation does not have the same multiple attribute as in the first definition") ;

C_BoolCommandLineOption gOption_goil_5F_options_pierreOption ("goil_options",
                                         "pierreOption",
                                         0,
                                         "pierre",
                                         "Special option to pass a galgas bug to Pierre") ;

C_BoolCommandLineOption gOption_goil_5F_options_generate_5F_log ("goil_options",
                                         "generate_log",
                                         108,
                                         "logfile",
                                         "generate a goil.log file containing the a log of the compilation") ;

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

C_StringCommandLineOption gOption_goil_5F_options_config ("goil_options",
                                         "config",
                                         99,
                                         "config",
                                         "Specifies the OIL config file used by goil",
                                         "config") ;

C_StringCommandLineOption gOption_goil_5F_options_root ("goil_options",
                                         "root",
                                         114,
                                         "root",
                                         "Specifies the root template file to use to generate the output files",
                                         "root") ;

//--------------------------------------------------------------------------------------------------
//
//                              String List options                                              
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//
//Function 'checkEnums'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool function_checkEnums (const GALGAS_impEnumType & constinArgument_previousEnum,
                                 const GALGAS_impEnumType & constinArgument_newEnum,
                                 Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_checkEnums [3] = {
  & kTypeDescriptor_GALGAS_impEnumType,
  & kTypeDescriptor_GALGAS_impEnumType,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_checkEnums (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_checkEnums ("checkEnums",
                                                            functionWithGenericHeader_checkEnums,
                                                            & kTypeDescriptor_GALGAS_bool,
                                                            2,
                                                            functionArgs_checkEnums) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'checkRanged'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool function_checkRanged (const GALGAS_impRangedType & constinArgument_previousRanged,
                                  const GALGAS_impRangedType & constinArgument_newRanged,
                                  Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_checkRanged [3] = {
  & kTypeDescriptor_GALGAS_impRangedType,
  & kTypeDescriptor_GALGAS_impRangedType,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_checkRanged (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_checkRanged ("checkRanged",
                                                             functionWithGenericHeader_checkRanged,
                                                             & kTypeDescriptor_GALGAS_bool,
                                                             2,
                                                             functionArgs_checkRanged) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'checkNewTypeWithinPreviousType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool function_checkNewTypeWithinPreviousType (const GALGAS_lstring & constinArgument_name,
                                                     const GALGAS_impType & constinArgument_previousType,
                                                     const GALGAS_impType & constinArgument_newType,
                                                     Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_checkNewTypeWithinPreviousType [4] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_impType,
  & kTypeDescriptor_GALGAS_impType,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_checkNewTypeWithinPreviousType (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_checkNewTypeWithinPreviousType ("checkNewTypeWithinPreviousType",
                                                                                functionWithGenericHeader_checkNewTypeWithinPreviousType,
                                                                                & kTypeDescriptor_GALGAS_bool,
                                                                                3,
                                                                                functionArgs_checkNewTypeWithinPreviousType) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'buildRange'
//
//--------------------------------------------------------------------------------------------------

GALGAS_attributeRange function_buildRange (const GALGAS_dataType & constinArgument_type,
                                           const GALGAS_object_5F_t & constinArgument_start,
                                           const GALGAS_object_5F_t & constinArgument_stop,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_attributeRange result_range ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_uint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 683)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_range = GALGAS_uint_33__32_AttributeMinMax::class_func_new (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 684)), function_uint_33__32_OrError (constinArgument_start, GALGAS_string ("UINT32 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 684)), function_uint_33__32_OrError (constinArgument_stop, GALGAS_string ("UINT32 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 684))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 684)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_sint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 685)))).boolEnum () ;
      if (kBoolTrue == test_1) {
        result_range = GALGAS_sint_33__32_AttributeMinMax::class_func_new (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 686)), function_sint_33__32_OrError (constinArgument_start, GALGAS_string ("SINT32 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 686)), function_sint_33__32_OrError (constinArgument_stop, GALGAS_string ("SINT32 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 686))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 686)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_uint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 687)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          result_range = GALGAS_uint_36__34_AttributeMinMax::class_func_new (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 688)), function_uint_36__34_OrError (constinArgument_start, GALGAS_string ("UINT64 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 688)), function_uint_36__34_OrError (constinArgument_stop, GALGAS_string ("UINT64 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 688))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 688)) ;
        }
      }
      if (kBoolFalse == test_2) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_sint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 689)))).boolEnum () ;
          if (kBoolTrue == test_3) {
            result_range = GALGAS_sint_36__34_AttributeMinMax::class_func_new (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 690)), function_sint_36__34_OrError (constinArgument_start, GALGAS_string ("SINT64 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 690)), function_sint_36__34_OrError (constinArgument_stop, GALGAS_string ("SINT64 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 690))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 690)) ;
          }
        }
        if (kBoolFalse == test_3) {
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_floatNumber (SOURCE_FILE ("implementation_parser.galgas", 691)))).boolEnum () ;
            if (kBoolTrue == test_4) {
              result_range = GALGAS_floatAttributeMinMax::class_func_new (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 692)), function_floatOrError (constinArgument_start, GALGAS_string ("FLOAT Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 692)), function_floatOrError (constinArgument_stop, GALGAS_string ("FLOAT Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 692))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 692)) ;
            }
          }
          if (kBoolFalse == test_4) {
            TC_Array <C_FixItDescription> fixItArray5 ;
            inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 694)), GALGAS_string ("internal. Unknown number type"), fixItArray5  COMMA_SOURCE_FILE ("implementation_parser.galgas", 694)) ;
            result_range.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_range ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_buildRange [4] = {
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_object_5F_t,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_buildRange (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_buildRange ("buildRange",
                                                            functionWithGenericHeader_buildRange,
                                                            & kTypeDescriptor_GALGAS_attributeRange,
                                                            3,
                                                            functionArgs_buildRange) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'stringWithUInt32List'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_stringWithUInt_33__32_List (const GALGAS_uint_33__32_List & constinArgument_values,
                                                   Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringWithUInt_33__32_List [2] = {
  & kTypeDescriptor_GALGAS_uint_33__32_List,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringWithUInt_33__32_List (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringWithUInt_33__32_List ("stringWithUInt32List",
                                                                            functionWithGenericHeader_stringWithUInt_33__32_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithUInt_33__32_List) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'stringWithUInt64List'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_stringWithUInt_36__34_List (const GALGAS_uint_36__34_List & constinArgument_values,
                                                   Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringWithUInt_36__34_List [2] = {
  & kTypeDescriptor_GALGAS_uint_36__34_List,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringWithUInt_36__34_List (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringWithUInt_36__34_List ("stringWithUInt64List",
                                                                            functionWithGenericHeader_stringWithUInt_36__34_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithUInt_36__34_List) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'stringWithSInt32List'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_stringWithSInt_33__32_List (const GALGAS_sint_33__32_List & constinArgument_values,
                                                   Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringWithSInt_33__32_List [2] = {
  & kTypeDescriptor_GALGAS_sint_33__32_List,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringWithSInt_33__32_List (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringWithSInt_33__32_List ("stringWithSInt32List",
                                                                            functionWithGenericHeader_stringWithSInt_33__32_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithSInt_33__32_List) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'stringWithSInt64List'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_stringWithSInt_36__34_List (const GALGAS_sint_36__34_List & constinArgument_values,
                                                   Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringWithSInt_36__34_List [2] = {
  & kTypeDescriptor_GALGAS_sint_36__34_List,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringWithSInt_36__34_List (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringWithSInt_36__34_List ("stringWithSInt64List",
                                                                            functionWithGenericHeader_stringWithSInt_36__34_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithSInt_36__34_List) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'stringWithFloatList'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_stringWithFloatList (const GALGAS_floatList & constinArgument_values,
                                            Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringWithFloatList [2] = {
  & kTypeDescriptor_GALGAS_floatList,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringWithFloatList (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringWithFloatList ("stringWithFloatList",
                                                                     functionWithGenericHeader_stringWithFloatList,
                                                                     & kTypeDescriptor_GALGAS_string,
                                                                     1,
                                                                     functionArgs_stringWithFloatList) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'uint32ListWithNumberList'
//
//--------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List function_uint_33__32_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_33__32_List result_result ; // Returned variable
  result_result = GALGAS_uint_33__32_List::class_func_emptyList (SOURCE_FILE ("implementation_types.galgas", 109)) ;
  cEnumerator_numberList enumerator_3408 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_3408.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3408.current_location (HERE), function_uint_33__32_OrError (enumerator_3408.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 111))  COMMA_SOURCE_FILE ("implementation_types.galgas", 111)) ;
    enumerator_3408.gotoNextObject () ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_uint_33__32_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_uint_33__32_ListWithNumberList (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_uint_33__32_ListWithNumberList ("uint32ListWithNumberList",
                                                                                functionWithGenericHeader_uint_33__32_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_uint_33__32_List,
                                                                                1,
                                                                                functionArgs_uint_33__32_ListWithNumberList) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'sint32ListWithNumberList'
//
//--------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List function_sint_33__32_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_33__32_List result_result ; // Returned variable
  result_result = GALGAS_sint_33__32_List::class_func_emptyList (SOURCE_FILE ("implementation_types.galgas", 116)) ;
  cEnumerator_numberList enumerator_3606 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_3606.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3606.current_location (HERE), function_sint_33__32_OrError (enumerator_3606.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 118))  COMMA_SOURCE_FILE ("implementation_types.galgas", 118)) ;
    enumerator_3606.gotoNextObject () ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_sint_33__32_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_sint_33__32_ListWithNumberList (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_sint_33__32_ListWithNumberList ("sint32ListWithNumberList",
                                                                                functionWithGenericHeader_sint_33__32_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_sint_33__32_List,
                                                                                1,
                                                                                functionArgs_sint_33__32_ListWithNumberList) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'uint64ListWithNumberList'
//
//--------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List function_uint_36__34_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_36__34_List result_result ; // Returned variable
  result_result = GALGAS_uint_36__34_List::class_func_emptyList (SOURCE_FILE ("implementation_types.galgas", 123)) ;
  cEnumerator_numberList enumerator_3804 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_3804.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3804.current_location (HERE), function_uint_36__34_OrError (enumerator_3804.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 125))  COMMA_SOURCE_FILE ("implementation_types.galgas", 125)) ;
    enumerator_3804.gotoNextObject () ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_uint_36__34_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_uint_36__34_ListWithNumberList (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_uint_36__34_ListWithNumberList ("uint64ListWithNumberList",
                                                                                functionWithGenericHeader_uint_36__34_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_uint_36__34_List,
                                                                                1,
                                                                                functionArgs_uint_36__34_ListWithNumberList) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'sint64ListWithNumberList'
//
//--------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List function_sint_36__34_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_36__34_List result_result ; // Returned variable
  result_result = GALGAS_sint_36__34_List::class_func_emptyList (SOURCE_FILE ("implementation_types.galgas", 130)) ;
  cEnumerator_numberList enumerator_4002 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_4002.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_4002.current_location (HERE), function_sint_36__34_OrError (enumerator_4002.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 132))  COMMA_SOURCE_FILE ("implementation_types.galgas", 132)) ;
    enumerator_4002.gotoNextObject () ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_sint_36__34_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_sint_36__34_ListWithNumberList (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_sint_36__34_ListWithNumberList ("sint64ListWithNumberList",
                                                                                functionWithGenericHeader_sint_36__34_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_sint_36__34_List,
                                                                                1,
                                                                                functionArgs_sint_36__34_ListWithNumberList) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'floatListWithNumberList'
//
//--------------------------------------------------------------------------------------------------

GALGAS_floatList function_floatListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_floatList result_result ; // Returned variable
  result_result = GALGAS_floatList::class_func_emptyList (SOURCE_FILE ("implementation_types.galgas", 137)) ;
  cEnumerator_numberList enumerator_4197 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_4197.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_4197.current_location (HERE), function_floatOrError (enumerator_4197.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 139))  COMMA_SOURCE_FILE ("implementation_types.galgas", 139)) ;
    enumerator_4197.gotoNextObject () ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_floatListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_floatListWithNumberList (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_floatListWithNumberList ("floatListWithNumberList",
                                                                         functionWithGenericHeader_floatListWithNumberList,
                                                                         & kTypeDescriptor_GALGAS_floatList,
                                                                         1,
                                                                         functionArgs_floatListWithNumberList) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@noRange enclose'
//
//--------------------------------------------------------------------------------------------------

void cPtr_noRange::method_enclose (GALGAS_bool & outArgument_isWithin,
                                   const GALGAS_attributeRange /* constinArgument_value */,
                                   Compiler * /* inCompiler */
                                   COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_isWithin = GALGAS_bool (true) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@uint32AttributeSet enclose'
//
//--------------------------------------------------------------------------------------------------

void cPtr_uint_33__32_AttributeSet::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                    const GALGAS_attributeRange constinArgument_value,
                                                    Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@uint64AttributeSet enclose'
//
//--------------------------------------------------------------------------------------------------

void cPtr_uint_36__34_AttributeSet::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                    const GALGAS_attributeRange constinArgument_value,
                                                    Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@sint32AttributeSet enclose'
//
//--------------------------------------------------------------------------------------------------

void cPtr_sint_33__32_AttributeSet::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                    const GALGAS_attributeRange constinArgument_value,
                                                    Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@sint64AttributeSet enclose'
//
//--------------------------------------------------------------------------------------------------

void cPtr_sint_36__34_AttributeSet::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                    const GALGAS_attributeRange constinArgument_value,
                                                    Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@floatAttributeSet enclose'
//
//--------------------------------------------------------------------------------------------------

void cPtr_floatAttributeSet::method_enclose (GALGAS_bool & outArgument_isWithin,
                                             const GALGAS_attributeRange constinArgument_value,
                                             Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@uint32AttributeMinMax enclose'
//
//--------------------------------------------------------------------------------------------------

void cPtr_uint_33__32_AttributeMinMax::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                       const GALGAS_attributeRange constinArgument_value,
                                                       Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@uint64AttributeMinMax enclose'
//
//--------------------------------------------------------------------------------------------------

void cPtr_uint_36__34_AttributeMinMax::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                       const GALGAS_attributeRange constinArgument_value,
                                                       Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@sint32AttributeMinMax enclose'
//
//--------------------------------------------------------------------------------------------------

void cPtr_sint_33__32_AttributeMinMax::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                       const GALGAS_attributeRange constinArgument_value,
                                                       Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@sint64AttributeMinMax enclose'
//
//--------------------------------------------------------------------------------------------------

void cPtr_sint_36__34_AttributeMinMax::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                       const GALGAS_attributeRange constinArgument_value,
                                                       Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@floatAttributeMinMax enclose'
//
//--------------------------------------------------------------------------------------------------

void cPtr_floatAttributeMinMax::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                const GALGAS_attributeRange constinArgument_value,
                                                Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Function 'attributeRangeWithNumberList'
//
//--------------------------------------------------------------------------------------------------

GALGAS_attributeRange function_attributeRangeWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                             const GALGAS_dataType & constinArgument_type,
                                                             Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_attributeRange result_range ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 412)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_range = GALGAS_uint_33__32_AttributeSet::class_func_new (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 413)), function_uint_33__32_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 413))  COMMA_SOURCE_FILE ("implementation_types.galgas", 413)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 414)))).boolEnum () ;
      if (kBoolTrue == test_1) {
        result_range = GALGAS_sint_33__32_AttributeSet::class_func_new (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 415)), function_sint_33__32_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 415))  COMMA_SOURCE_FILE ("implementation_types.galgas", 415)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 416)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          result_range = GALGAS_uint_36__34_AttributeSet::class_func_new (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 417)), function_uint_36__34_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 417))  COMMA_SOURCE_FILE ("implementation_types.galgas", 417)) ;
        }
      }
      if (kBoolFalse == test_2) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 418)))).boolEnum () ;
          if (kBoolTrue == test_3) {
            result_range = GALGAS_sint_36__34_AttributeSet::class_func_new (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 419)), function_sint_36__34_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 419))  COMMA_SOURCE_FILE ("implementation_types.galgas", 419)) ;
          }
        }
        if (kBoolFalse == test_3) {
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_floatNumber (SOURCE_FILE ("implementation_types.galgas", 420)))).boolEnum () ;
            if (kBoolTrue == test_4) {
              result_range = GALGAS_floatAttributeSet::class_func_new (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 421)), function_floatListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 421))  COMMA_SOURCE_FILE ("implementation_types.galgas", 421)) ;
            }
          }
          if (kBoolFalse == test_4) {
            TC_Array <C_FixItDescription> fixItArray5 ;
            inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 423)), GALGAS_string ("internal. Unknown number type"), fixItArray5  COMMA_SOURCE_FILE ("implementation_types.galgas", 423)) ;
            result_range.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_range ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_attributeRangeWithNumberList [3] = {
  & kTypeDescriptor_GALGAS_numberList,
  & kTypeDescriptor_GALGAS_dataType,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_attributeRangeWithNumberList (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_attributeRangeWithNumberList ("attributeRangeWithNumberList",
                                                                              functionWithGenericHeader_attributeRangeWithNumberList,
                                                                              & kTypeDescriptor_GALGAS_attributeRange,
                                                                              2,
                                                                              functionArgs_attributeRangeWithNumberList) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@impStructType mergeWithType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_impType cPtr_impStructType::getter_mergeWithType (GALGAS_impType inArgument_typeToMerge,
                                                         Compiler * inCompiler
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
  GALGAS_implementationObjectMap var_mergedAttributes_12959 = GALGAS_implementationObjectMap::class_func_emptyMap (SOURCE_FILE ("implementation_types.galgas", 468)) ;
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
  result_mergedType = GALGAS_impStructType::class_func_new (this->mProperty_locations.add_operation (inArgument_typeToMerge.readProperty_locations (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 478)), this->mProperty_type, this->mProperty_name, this->mProperty_multiple, this->mProperty_descs.add_operation (inArgument_typeToMerge.readProperty_descs (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 482)), var_mergedAttributes_12959  COMMA_SOURCE_FILE ("implementation_types.galgas", 477)) ;
//---
  return result_mergedType ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@impVoid mergeWithType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_impType cPtr_impVoid::getter_mergeWithType (GALGAS_impType inArgument_typeToMerge,
                                                   Compiler */* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_impType result_mergedType ; // Returned variable
  result_mergedType = inArgument_typeToMerge ;
//---
  return result_mergedType ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@impAutoDefaultType getDefaultValue'
//
//--------------------------------------------------------------------------------------------------

GALGAS_object_5F_t cPtr_impAutoDefaultType::getter_getDefaultValue (Compiler */* inCompiler */
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_object_5F_t result_outDefaultValue ; // Returned variable
  result_outDefaultValue = this->mProperty_defaultValue ;
//---
  return result_outDefaultValue ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@impAutoDefaultType setDefValue'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_impAutoDefaultType_setDefValue (cPtr_impType * inObject,
                                                            GALGAS_object_5F_t inArgument_inDefaultValue,
                                                            Compiler * /* inCompiler */
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_impAutoDefaultType * object = (cPtr_impAutoDefaultType *) inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  object->mProperty_defaultValue = inArgument_inDefaultValue ;
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_impAutoDefaultType_setDefValue (void) {
  enterExtensionSetter_setDefValue (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                    extensionSetter_impAutoDefaultType_setDefValue) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_impAutoDefaultType_setDefValue (defineExtensionSetter_impAutoDefaultType_setDefValue, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@impAutoDefaultType mergeWithType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_impType cPtr_impAutoDefaultType::getter_mergeWithType (GALGAS_impType inArgument_typeToMerge,
                                                              Compiler */* inCompiler */
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_impType result_mergedType ; // Returned variable
  result_mergedType = inArgument_typeToMerge ;
//---
  return result_mergedType ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@impAutoDefaultType autoAllowed'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_impAutoDefaultType::getter_autoAllowed (Compiler */* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = this->mProperty_withAuto ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'multiError??'
//
//--------------------------------------------------------------------------------------------------

void routine_multiError_3F__3F_ (GALGAS_locationList inArgument_locations,
                                 GALGAS_string inArgument_errorMessage,
                                 Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_locationList enumerator_14829 (inArgument_locations, kENUMERATION_UP) ;
  while (enumerator_14829.hasCurrentObject ()) {
    TC_Array <C_FixItDescription> fixItArray0 ;
    inCompiler->emitSemanticError (enumerator_14829.current_location (HERE), inArgument_errorMessage, fixItArray0  COMMA_SOURCE_FILE ("implementation_types.galgas", 546)) ;
    enumerator_14829.gotoNextObject () ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@refType mergeWithType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_impType cPtr_refType::getter_mergeWithType (GALGAS_impType inArgument_typeToMerge,
                                                   Compiler * inCompiler
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
      routine_multiError_3F__3F_ (inArgument_typeToMerge.readProperty_locations (), GALGAS_string ("Redefinition of ").add_operation (this->mProperty_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 563)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 563)) ;
      }
      {
      routine_multiError_3F__3F_ (this->mProperty_locations, GALGAS_string ("Was defined here"), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 564)) ;
      }
    }
  }
  result_mergedType = GALGAS_refType::class_func_new (this->mProperty_locations.add_operation (inArgument_typeToMerge.readProperty_locations (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 567)), this->mProperty_type, this->mProperty_name, this->mProperty_multiple, this->mProperty_descs.add_operation (inArgument_typeToMerge.readProperty_descs (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 571)), var_castTypeToMerge_15066.readProperty_ref ()  COMMA_SOURCE_FILE ("implementation_types.galgas", 566)) ;
//---
  return result_mergedType ;
}


//--------------------------------------------------------------------------------------------------
//
//Function 'valueList'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_valueList (const GALGAS_enumValues & constinArgument_values,
                                  Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_valueList [2] = {
  & kTypeDescriptor_GALGAS_enumValues,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_valueList (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_valueList ("valueList",
                                                           functionWithGenericHeader_valueList,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_valueList) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@impRangedType mergeWithType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_impType cPtr_impRangedType::getter_mergeWithType (GALGAS_impType inArgument_typeToMerge,
                                                         Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@impBoolType mergeWithType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_impType cPtr_impBoolType::getter_mergeWithType (GALGAS_impType inArgument_typeToMerge,
                                                       Compiler * inCompiler
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
  GALGAS_implementationObjectMap var_mergedTrueAttributes_16927 = GALGAS_implementationObjectMap::class_func_emptyMap (SOURCE_FILE ("implementation_types.galgas", 632)) ;
  GALGAS_implementationObjectMap var_mergedFalseAttributes_16987 = GALGAS_implementationObjectMap::class_func_emptyMap (SOURCE_FILE ("implementation_types.galgas", 633)) ;
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
  result_mergedType = GALGAS_impBoolType::class_func_new (this->mProperty_locations.add_operation (inArgument_typeToMerge.readProperty_locations (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 665)), this->mProperty_type, this->mProperty_name, this->mProperty_multiple, this->mProperty_descs.add_operation (inArgument_typeToMerge.readProperty_descs (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 669)), this->mProperty_withAuto, var_castTypeToMerge_16854.readProperty_defaultValue (), var_mergedTrueAttributes_16927, var_mergedFalseAttributes_16987  COMMA_SOURCE_FILE ("implementation_types.galgas", 664)) ;
//---
  return result_mergedType ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@impBoolType setDefault'
//
//--------------------------------------------------------------------------------------------------

void cPtr_impBoolType::method_setDefault (GALGAS_objectAttributes & ioArgument_attributes,
                                          Compiler * inCompiler
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
              routine_setDefaultsForType_3F__26_ (var_subImpAttributes_19088, var_subAttributes_19297, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 700)) ;
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
        routine_setDefaultsForType_3F__26_ (var_subImpAttributes_19712, var_subAttributes_19901, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 715)) ;
        }
        GALGAS_boolAttribute var_defaults_20022 = GALGAS_boolAttribute::class_func_new (cast_18611_b.readProperty_oil_5F_desc (), cast_18611_b.readProperty_location (), cast_18611_b.readProperty_value (), var_subAttributes_19901  COMMA_SOURCE_FILE ("implementation_types.galgas", 716)) ;
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@impEnumType mergeWithType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_impType cPtr_impEnumType::getter_mergeWithType (GALGAS_impType inArgument_typeToMerge,
                                                       Compiler * inCompiler
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
  result_mergedType = GALGAS_impEnumType::class_func_new (this->mProperty_locations.add_operation (inArgument_typeToMerge.readProperty_locations (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 756)), this->mProperty_type, this->mProperty_name, this->mProperty_multiple, this->mProperty_descs.add_operation (inArgument_typeToMerge.readProperty_descs (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 760)), this->mProperty_withAuto, var_castTypeToMerge_21072.readProperty_defaultValue (), extensionGetter_mergeWithEnum (this->mProperty_valuesMap, var_castTypeToMerge_21072.readProperty_valuesMap (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 763))  COMMA_SOURCE_FILE ("implementation_types.galgas", 755)) ;
//---
  return result_mergedType ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'verifyEnum?'
//
//--------------------------------------------------------------------------------------------------

void routine_verifyEnum_3F_ (const GALGAS_impType constinArgument_anEnum,
                             Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Function 'checkAndGetIntegerNumber'
//
//--------------------------------------------------------------------------------------------------

GALGAS_object_5F_t function_checkAndGetIntegerNumber (const GALGAS_lstring & constinArgument_oil_5F_desc,
                                                      const GALGAS_dataType & constinArgument_type,
                                                      const GALGAS_luint_36__34_ & constinArgument_number,
                                                      const GALGAS_bool & constinArgument_signed,
                                                      Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_value ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_signed.boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 845)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_value = GALGAS_sint_33__32__5F_class::class_func_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location (), constinArgument_number.readProperty_uint_36__34_ ().getter_sint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 846)).multiply_operation (GALGAS_sint (int32_t (-1L)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 846))  COMMA_SOURCE_FILE ("implementation_types.galgas", 846)) ;
        }
      }
      if (kBoolFalse == test_1) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 847)))).boolEnum () ;
          if (kBoolTrue == test_2) {
            result_value = GALGAS_sint_36__34__5F_class::class_func_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location (), constinArgument_number.readProperty_uint_36__34_ ().getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 848)).multiply_operation (GALGAS_sint_36__34_ (int64_t (-1LL)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 848))  COMMA_SOURCE_FILE ("implementation_types.galgas", 848)) ;
          }
        }
        if (kBoolFalse == test_2) {
          result_value = GALGAS_void::class_func_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location ()  COMMA_SOURCE_FILE ("implementation_types.galgas", 850)) ;
          TC_Array <C_FixItDescription> fixItArray3 ;
          inCompiler->emitSemanticError (constinArgument_number.readProperty_location (), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 851)).add_operation (GALGAS_string (" expected, got a SINT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 851)), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 851)) ;
        }
      }
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_4 = kBoolTrue ;
    if (kBoolTrue == test_4) {
      test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 854)))).boolEnum () ;
      if (kBoolTrue == test_4) {
        result_value = GALGAS_sint_33__32__5F_class::class_func_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location (), constinArgument_number.readProperty_uint_36__34_ ().getter_sint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 855))  COMMA_SOURCE_FILE ("implementation_types.galgas", 855)) ;
      }
    }
    if (kBoolFalse == test_4) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 856)))).boolEnum () ;
        if (kBoolTrue == test_5) {
          result_value = GALGAS_sint_36__34__5F_class::class_func_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location (), constinArgument_number.readProperty_uint_36__34_ ().getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 857))  COMMA_SOURCE_FILE ("implementation_types.galgas", 857)) ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_6 = kBoolTrue ;
        if (kBoolTrue == test_6) {
          test_6 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 858)))).boolEnum () ;
          if (kBoolTrue == test_6) {
            result_value = GALGAS_uint_33__32__5F_class::class_func_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location (), constinArgument_number.readProperty_uint_36__34_ ().getter_uint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 859))  COMMA_SOURCE_FILE ("implementation_types.galgas", 859)) ;
          }
        }
        if (kBoolFalse == test_6) {
          enumGalgasBool test_7 = kBoolTrue ;
          if (kBoolTrue == test_7) {
            test_7 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 860)))).boolEnum () ;
            if (kBoolTrue == test_7) {
              result_value = GALGAS_uint_36__34__5F_class::class_func_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location (), constinArgument_number.readProperty_uint_36__34_ ()  COMMA_SOURCE_FILE ("implementation_types.galgas", 861)) ;
            }
          }
          if (kBoolFalse == test_7) {
            result_value = GALGAS_void::class_func_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location ()  COMMA_SOURCE_FILE ("implementation_types.galgas", 863)) ;
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_checkAndGetIntegerNumber [5] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_luint_36__34_,
  & kTypeDescriptor_GALGAS_bool,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_checkAndGetIntegerNumber (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_checkAndGetIntegerNumber ("checkAndGetIntegerNumber",
                                                                          functionWithGenericHeader_checkAndGetIntegerNumber,
                                                                          & kTypeDescriptor_GALGAS_object_5F_t,
                                                                          4,
                                                                          functionArgs_checkAndGetIntegerNumber) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'checkAndGetFloatNumber'
//
//--------------------------------------------------------------------------------------------------

GALGAS_object_5F_t function_checkAndGetFloatNumber (const GALGAS_lstring & constinArgument_oil_5F_desc,
                                                    const GALGAS_dataType & constinArgument_type,
                                                    const GALGAS_ldouble & constinArgument_number,
                                                    const GALGAS_bool & constinArgument_signed,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_value ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_signed.boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_floatNumber (SOURCE_FILE ("implementation_types.galgas", 876)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_value = GALGAS_float_5F_class::class_func_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location (), constinArgument_number.readProperty_double ().multiply_operation (GALGAS_double (1).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 877)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 877))  COMMA_SOURCE_FILE ("implementation_types.galgas", 877)) ;
        }
      }
      if (kBoolFalse == test_1) {
        result_value = GALGAS_void::class_func_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location ()  COMMA_SOURCE_FILE ("implementation_types.galgas", 879)) ;
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (constinArgument_number.readProperty_location (), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 880)).add_operation (GALGAS_string (" expected, got a FLOAT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 880)), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 880)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::class_func_floatNumber (SOURCE_FILE ("implementation_types.galgas", 883)))).boolEnum () ;
      if (kBoolTrue == test_3) {
        result_value = GALGAS_float_5F_class::class_func_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location (), constinArgument_number.readProperty_double ()  COMMA_SOURCE_FILE ("implementation_types.galgas", 884)) ;
      }
    }
    if (kBoolFalse == test_3) {
      result_value = GALGAS_void::class_func_new (constinArgument_oil_5F_desc, constinArgument_number.readProperty_location ()  COMMA_SOURCE_FILE ("implementation_types.galgas", 886)) ;
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (constinArgument_number.readProperty_location (), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 887)).add_operation (GALGAS_string (" expected, got a FLOAT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 887)), fixItArray4  COMMA_SOURCE_FILE ("implementation_types.galgas", 887)) ;
    }
  }
//---
  return result_value ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_checkAndGetFloatNumber [5] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_ldouble,
  & kTypeDescriptor_GALGAS_bool,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_checkAndGetFloatNumber (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_checkAndGetFloatNumber ("checkAndGetFloatNumber",
                                                                        functionWithGenericHeader_checkAndGetFloatNumber,
                                                                        & kTypeDescriptor_GALGAS_object_5F_t,
                                                                        4,
                                                                        functionArgs_checkAndGetFloatNumber) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'checkTypeForAttribute???'
//
//--------------------------------------------------------------------------------------------------

void routine_checkTypeForAttribute_3F__3F__3F_ (const GALGAS_implementationObjectMap constinArgument_obj,
                                                const GALGAS_string constinArgument_attributeName,
                                                const GALGAS_dataType constinArgument_expectedType,
                                                Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Function 'boolSubAttributes'
//
//--------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap function_boolSubAttributes (const GALGAS_implementationObject & constinArgument_obj,
                                                           const GALGAS_string & constinArgument_attributeName,
                                                           const GALGAS_bool & constinArgument_boolValue,
                                                           Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result_subImplementation ; // Returned variable
  result_subImplementation = GALGAS_implementationObjectMap::class_func_emptyMap (SOURCE_FILE ("implementation_types.galgas", 913)) ;
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_boolSubAttributes [4] = {
  & kTypeDescriptor_GALGAS_implementationObject,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_bool,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_boolSubAttributes (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_boolSubAttributes ("boolSubAttributes",
                                                                   functionWithGenericHeader_boolSubAttributes,
                                                                   & kTypeDescriptor_GALGAS_implementationObjectMap,
                                                                   3,
                                                                   functionArgs_boolSubAttributes) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'enumSubAttributes'
//
//--------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap function_enumSubAttributes (const GALGAS_implementationObject & constinArgument_obj,
                                                           const GALGAS_string & constinArgument_attributeName,
                                                           const GALGAS_string & constinArgument_enumValue,
                                                           Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result_subImplementation ; // Returned variable
  result_subImplementation = GALGAS_implementationObjectMap::class_func_emptyMap (SOURCE_FILE ("implementation_types.galgas", 933)) ;
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_enumSubAttributes [4] = {
  & kTypeDescriptor_GALGAS_implementationObject,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_enumSubAttributes (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_enumSubAttributes ("enumSubAttributes",
                                                                   functionWithGenericHeader_enumSubAttributes,
                                                                   & kTypeDescriptor_GALGAS_implementationObjectMap,
                                                                   3,
                                                                   functionArgs_enumSubAttributes) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'checkFilters?'
//
//--------------------------------------------------------------------------------------------------

void routine_checkFilters_3F_ (const GALGAS_implementationObject constinArgument_messageProperty,
                               Compiler * inCompiler
                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap var_filter_26800 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWEQUALSX"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 951)) ;
  {
  routine_checkTypeForAttribute_3F__3F__3F_ (var_filter_26800, GALGAS_string ("MASK"), GALGAS_dataType::class_func_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 952)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 952)) ;
  }
  {
  routine_checkTypeForAttribute_3F__3F__3F_ (var_filter_26800, GALGAS_string ("X"), GALGAS_dataType::class_func_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 953)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 953)) ;
  }
  var_filter_26800 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWDIFFERSX"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 954)) ;
  {
  routine_checkTypeForAttribute_3F__3F__3F_ (var_filter_26800, GALGAS_string ("MASK"), GALGAS_dataType::class_func_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 955)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 955)) ;
  }
  {
  routine_checkTypeForAttribute_3F__3F__3F_ (var_filter_26800, GALGAS_string ("X"), GALGAS_dataType::class_func_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 956)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 956)) ;
  }
  var_filter_26800 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWEQUALSMASKEDOLD"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 957)) ;
  {
  routine_checkTypeForAttribute_3F__3F__3F_ (var_filter_26800, GALGAS_string ("MASK"), GALGAS_dataType::class_func_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 958)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 958)) ;
  }
  var_filter_26800 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("NEWISWITHIN"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 959)) ;
  {
  routine_checkTypeForAttribute_3F__3F__3F_ (var_filter_26800, GALGAS_string ("MIN"), GALGAS_dataType::class_func_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 960)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 960)) ;
  }
  {
  routine_checkTypeForAttribute_3F__3F__3F_ (var_filter_26800, GALGAS_string ("MAX"), GALGAS_dataType::class_func_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 961)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 961)) ;
  }
  var_filter_26800 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("NEWISOUTSIDE"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 962)) ;
  {
  routine_checkTypeForAttribute_3F__3F__3F_ (var_filter_26800, GALGAS_string ("MIN"), GALGAS_dataType::class_func_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 963)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 963)) ;
  }
  {
  routine_checkTypeForAttribute_3F__3F__3F_ (var_filter_26800, GALGAS_string ("MAX"), GALGAS_dataType::class_func_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 964)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 964)) ;
  }
  var_filter_26800 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("ONEEVERYN"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 965)) ;
  {
  routine_checkTypeForAttribute_3F__3F__3F_ (var_filter_26800, GALGAS_string ("PERIOD"), GALGAS_dataType::class_func_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 966)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 966)) ;
  }
  {
  routine_checkTypeForAttribute_3F__3F__3F_ (var_filter_26800, GALGAS_string ("OFFSET"), GALGAS_dataType::class_func_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 967)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 967)) ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@refType checkAttributeReferences'
//
//--------------------------------------------------------------------------------------------------

void cPtr_refType::method_checkAttributeReferences (const GALGAS_implementation constinArgument_imp,
                                                    Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@impBoolType checkAttributeReferences'
//
//--------------------------------------------------------------------------------------------------

void cPtr_impBoolType::method_checkAttributeReferences (const GALGAS_implementation constinArgument_imp,
                                                        Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@impEnumType checkAttributeReferences'
//
//--------------------------------------------------------------------------------------------------

void cPtr_impEnumType::method_checkAttributeReferences (const GALGAS_implementation constinArgument_imp,
                                                        Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Routine 'setDefaultsForType?&'
//
//--------------------------------------------------------------------------------------------------

void routine_setDefaultsForType_3F__26_ (const GALGAS_implementationObjectMap constinArgument_impObject,
                                         GALGAS_objectAttributes & ioArgument_objectParams,
                                         Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@noRange contains'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_noRange::getter_contains (const GALGAS_object_5F_t /* constinArgument_obj */,
                                           Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_isInside ; // Returned variable
  result_isInside = GALGAS_bool (true) ;
//---
  return result_isInside ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@noRange string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_noRange::getter_string (Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = GALGAS_string ("\?") ;
//---
  return result_desc ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@uint32AttributeSet contains'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_uint_33__32_AttributeSet::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                            Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@uint32AttributeSet string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_uint_33__32_AttributeSet::getter_string (Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@uint32AttributeMinMax contains'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_uint_33__32_AttributeMinMax::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                               Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@uint32AttributeMinMax string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_uint_33__32_AttributeMinMax::getter_string (Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = this->mProperty_min.getter_string (SOURCE_FILE ("implementation_types.galgas", 1136)).add_operation (GALGAS_string (".."), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1136)).add_operation (this->mProperty_max.getter_string (SOURCE_FILE ("implementation_types.galgas", 1136)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1136)) ;
//---
  return result_desc ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@sint32AttributeSet contains'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_sint_33__32_AttributeSet::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                            Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@sint32AttributeSet string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_sint_33__32_AttributeSet::getter_string (Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@sint32AttributeMinMax contains'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_sint_33__32_AttributeMinMax::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                               Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@sint32AttributeMinMax string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_sint_33__32_AttributeMinMax::getter_string (Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = this->mProperty_min.getter_string (SOURCE_FILE ("implementation_types.galgas", 1180)).add_operation (GALGAS_string (".."), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1180)).add_operation (this->mProperty_max.getter_string (SOURCE_FILE ("implementation_types.galgas", 1180)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1180)) ;
//---
  return result_desc ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@uint64AttributeSet contains'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_uint_36__34_AttributeSet::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                            Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@uint64AttributeSet string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_uint_36__34_AttributeSet::getter_string (Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@uint64AttributeMinMax contains'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_uint_36__34_AttributeMinMax::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                               Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@uint64AttributeMinMax string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_uint_36__34_AttributeMinMax::getter_string (Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = this->mProperty_min.getter_string (SOURCE_FILE ("implementation_types.galgas", 1224)).add_operation (GALGAS_string (".."), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1224)).add_operation (this->mProperty_max.getter_string (SOURCE_FILE ("implementation_types.galgas", 1224)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1224)) ;
//---
  return result_desc ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@sint64AttributeSet contains'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_sint_36__34_AttributeSet::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                            Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@sint64AttributeSet string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_sint_36__34_AttributeSet::getter_string (Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@sint64AttributeMinMax contains'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_sint_36__34_AttributeMinMax::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                               Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@sint64AttributeMinMax string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_sint_36__34_AttributeMinMax::getter_string (Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = this->mProperty_min.getter_string (SOURCE_FILE ("implementation_types.galgas", 1269)).add_operation (GALGAS_string (".."), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1269)).add_operation (this->mProperty_max.getter_string (SOURCE_FILE ("implementation_types.galgas", 1269)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1269)) ;
//---
  return result_desc ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@floatAttributeSet contains'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_floatAttributeSet::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                     Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@floatAttributeSet string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_floatAttributeSet::getter_string (Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@floatAttributeMinMax contains'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_floatAttributeMinMax::getter_contains (const GALGAS_object_5F_t constinArgument_obj,
                                                        Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@floatAttributeMinMax string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_floatAttributeMinMax::getter_string (Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_desc ; // Returned variable
  result_desc = this->mProperty_min.getter_string (SOURCE_FILE ("implementation_types.galgas", 1313)).add_operation (GALGAS_string (".."), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1313)).add_operation (this->mProperty_max.getter_string (SOURCE_FILE ("implementation_types.galgas", 1313)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1313)) ;
//---
  return result_desc ;
}


//--------------------------------------------------------------------------------------------------
//
//Once function 'emptyLString'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_lstring onceFunction_emptyLString (Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_ls ; // Returned variable
  result_ls = GALGAS_lstring::class_func_new (GALGAS_string::makeEmptyString (), GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 29)), inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 29)) ;
//---
  return result_ls ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_emptyLString = false ;
static GALGAS_lstring gOnceFunctionResult_emptyLString ;

//--------------------------------------------------------------------------------------------------

GALGAS_lstring function_emptyLString (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_emptyLString) {
    gOnceFunctionResult_emptyLString = onceFunction_emptyLString (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_emptyLString = true ;
  }
  return gOnceFunctionResult_emptyLString ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_emptyLString (void) {
  gOnceFunctionResult_emptyLString.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_emptyLString (nullptr,
                                                        releaseOnceFunctionResult_emptyLString) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptyLString [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptyLString (Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_emptyLString (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptyLString ("emptyLString",
                                                              functionWithGenericHeader_emptyLString,
                                                              & kTypeDescriptor_GALGAS_lstring,
                                                              0,
                                                              functionArgs_emptyLString) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'emptyObject'
//
//--------------------------------------------------------------------------------------------------

GALGAS_objectAttributes function_emptyObject (Compiler *
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_result ; // Returned variable
  result_result = GALGAS_objectAttributes::class_func_new (GALGAS_identifierMap::class_func_emptyMap (SOURCE_FILE ("goil_basic_types.galgas", 73))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 73)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptyObject [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptyObject (Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_emptyObject (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptyObject ("emptyObject",
                                                             functionWithGenericHeader_emptyObject,
                                                             & kTypeDescriptor_GALGAS_objectAttributes,
                                                             0,
                                                             functionArgs_emptyObject) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@multipleAttribute mergeSubAttributes'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_multipleAttribute_mergeSubAttributes (cPtr_object_5F_t * inObject,
                                                                  GALGAS_object_5F_t inArgument_withObject,
                                                                  Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_multipleAttribute_mergeSubAttributes (void) {
  enterExtensionSetter_mergeSubAttributes (kTypeDescriptor_GALGAS_multipleAttribute.mSlotID,
                                           extensionSetter_multipleAttribute_mergeSubAttributes) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_multipleAttribute_mergeSubAttributes (defineExtensionSetter_multipleAttribute_mergeSubAttributes, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'multipleAttributeOrError'
//
//--------------------------------------------------------------------------------------------------

GALGAS_identifierList function_multipleAttributeOrError (const GALGAS_object_5F_t & constinArgument_t,
                                                         const GALGAS_string & constinArgument_att,
                                                         Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierList result_v ; // Returned variable
  result_v = GALGAS_identifierList::class_func_emptyList (SOURCE_FILE ("goil_basic_types.galgas", 101)) ;
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_multipleAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_multipleAttributeOrError (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_multipleAttributeOrError ("multipleAttributeOrError",
                                                                          functionWithGenericHeader_multipleAttributeOrError,
                                                                          & kTypeDescriptor_GALGAS_identifierList,
                                                                          2,
                                                                          functionArgs_multipleAttributeOrError) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@boolAttribute mergeSubAttributes'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_boolAttribute_mergeSubAttributes (cPtr_object_5F_t * inObject,
                                                              GALGAS_object_5F_t inArgument_withObject,
                                                              Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_boolAttribute_mergeSubAttributes (void) {
  enterExtensionSetter_mergeSubAttributes (kTypeDescriptor_GALGAS_boolAttribute.mSlotID,
                                           extensionSetter_boolAttribute_mergeSubAttributes) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_boolAttribute_mergeSubAttributes (defineExtensionSetter_boolAttribute_mergeSubAttributes, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'boolAttributeOrError'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool function_boolAttributeOrError (GALGAS_object_5F_t inArgument_t,
                                           GALGAS_string inArgument_att,
                                           Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_boolAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_boolAttributeOrError (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_boolAttributeOrError ("boolAttributeOrError",
                                                                      functionWithGenericHeader_boolAttributeOrError,
                                                                      & kTypeDescriptor_GALGAS_bool,
                                                                      2,
                                                                      functionArgs_boolAttributeOrError) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@enumAttribute mergeSubAttributes'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_enumAttribute_mergeSubAttributes (cPtr_object_5F_t * inObject,
                                                              GALGAS_object_5F_t inArgument_withObject,
                                                              Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_enumAttribute_mergeSubAttributes (void) {
  enterExtensionSetter_mergeSubAttributes (kTypeDescriptor_GALGAS_enumAttribute.mSlotID,
                                           extensionSetter_enumAttribute_mergeSubAttributes) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_enumAttribute_mergeSubAttributes (defineExtensionSetter_enumAttribute_mergeSubAttributes, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'uint32_or_error'
//
//--------------------------------------------------------------------------------------------------

GALGAS_uint function_uint_33__32__5F_or_5F_error (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_uint_33__32__5F_or_5F_error [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_uint_33__32__5F_or_5F_error (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_uint_33__32__5F_or_5F_error ("uint32_or_error",
                                                                             functionWithGenericHeader_uint_33__32__5F_or_5F_error,
                                                                             & kTypeDescriptor_GALGAS_uint,
                                                                             2,
                                                                             functionArgs_uint_33__32__5F_or_5F_error) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'uint32OrError'
//
//--------------------------------------------------------------------------------------------------

GALGAS_uint function_uint_33__32_OrError (GALGAS_object_5F_t inArgument_t,
                                          GALGAS_string inArgument_att,
                                          Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_uint_33__32_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_uint_33__32_OrError (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_uint_33__32_OrError ("uint32OrError",
                                                                     functionWithGenericHeader_uint_33__32_OrError,
                                                                     & kTypeDescriptor_GALGAS_uint,
                                                                     2,
                                                                     functionArgs_uint_33__32_OrError) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'sint32OrError'
//
//--------------------------------------------------------------------------------------------------

GALGAS_sint function_sint_33__32_OrError (GALGAS_object_5F_t inArgument_t,
                                          GALGAS_string inArgument_att,
                                          Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_sint_33__32_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_sint_33__32_OrError (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_sint_33__32_OrError ("sint32OrError",
                                                                     functionWithGenericHeader_sint_33__32_OrError,
                                                                     & kTypeDescriptor_GALGAS_sint,
                                                                     2,
                                                                     functionArgs_sint_33__32_OrError) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'uint64OrError'
//
//--------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ function_uint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_uint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_uint_36__34_OrError (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_uint_36__34_OrError ("uint64OrError",
                                                                     functionWithGenericHeader_uint_36__34_OrError,
                                                                     & kTypeDescriptor_GALGAS_uint_36__34_,
                                                                     2,
                                                                     functionArgs_uint_36__34_OrError) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'luint64OrError'
//
//--------------------------------------------------------------------------------------------------

GALGAS_luint_36__34_ function_luint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                    GALGAS_string inArgument_att,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_luint_36__34_ result_v ; // Returned variable
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      GALGAS_uint_36__34__5F_class cast_4926_ui ((cPtr_uint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = GALGAS_luint_36__34_::class_func_new (cast_4926_ui.readProperty_value (), cast_4926_ui.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 238)) ;
    }else{
      result_v = GALGAS_luint_36__34_::class_func_new (GALGAS_uint_36__34_ (uint64_t (0ULL)), GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 240)), inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 240)) ;
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.readProperty_location (), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 241)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 241)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 241)) ;
    }
  }
//---
  return result_v ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_luint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_luint_36__34_OrError (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_luint_36__34_OrError ("luint64OrError",
                                                                      functionWithGenericHeader_luint_36__34_OrError,
                                                                      & kTypeDescriptor_GALGAS_luint_36__34_,
                                                                      2,
                                                                      functionArgs_luint_36__34_OrError) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'sint64OrError'
//
//--------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ function_sint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_sint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_sint_36__34_OrError (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_sint_36__34_OrError ("sint64OrError",
                                                                     functionWithGenericHeader_sint_36__34_OrError,
                                                                     & kTypeDescriptor_GALGAS_sint_36__34_,
                                                                     2,
                                                                     functionArgs_sint_36__34_OrError) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'floatOrError'
//
//--------------------------------------------------------------------------------------------------

GALGAS_double function_floatOrError (GALGAS_object_5F_t inArgument_t,
                                     GALGAS_string inArgument_att,
                                     Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_floatOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_floatOrError (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_floatOrError ("floatOrError",
                                                              functionWithGenericHeader_floatOrError,
                                                              & kTypeDescriptor_GALGAS_double,
                                                              2,
                                                              functionArgs_floatOrError) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'stringAttributeOrError'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring function_stringAttributeOrError (const GALGAS_object_5F_t & constinArgument_attribute,
                                                const GALGAS_string & constinArgument_attributeName,
                                                Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  result_result = function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 303)) ;
  if (constinArgument_attribute.isValid ()) {
    if (constinArgument_attribute.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_stringAttribute) {
      GALGAS_stringAttribute cast_6260_attribute ((cPtr_stringAttribute *) constinArgument_attribute.ptr ()) ;
      result_result = GALGAS_lstring::class_func_new (cast_6260_attribute.readProperty_value (), cast_6260_attribute.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 306)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_attribute.readProperty_location (), GALGAS_string ("Internal error ").add_operation (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 308)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 308)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 308)) ;
    }
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringAttributeOrError (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringAttributeOrError ("stringAttributeOrError",
                                                                        functionWithGenericHeader_stringAttributeOrError,
                                                                        & kTypeDescriptor_GALGAS_lstring,
                                                                        2,
                                                                        functionArgs_stringAttributeOrError) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@structAttribute mergeSubAttributes'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_structAttribute_mergeSubAttributes (cPtr_object_5F_t * inObject,
                                                                GALGAS_object_5F_t inArgument_withObject,
                                                                Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_structAttribute_mergeSubAttributes (void) {
  enterExtensionSetter_mergeSubAttributes (kTypeDescriptor_GALGAS_structAttribute.mSlotID,
                                           extensionSetter_structAttribute_mergeSubAttributes) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_structAttribute_mergeSubAttributes (defineExtensionSetter_structAttribute_mergeSubAttributes, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'empty_lstring'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring function_empty_5F_lstring (Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_ls ; // Returned variable
  result_ls = GALGAS_lstring::class_func_new (GALGAS_string::makeEmptyString (), GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 487)), inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 487)) ;
//---
  return result_ls ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_empty_5F_lstring [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_empty_5F_lstring (Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_empty_5F_lstring (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_empty_5F_lstring ("empty_lstring",
                                                                  functionWithGenericHeader_empty_5F_lstring,
                                                                  & kTypeDescriptor_GALGAS_lstring,
                                                                  0,
                                                                  functionArgs_empty_5F_lstring) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'void_obj'
//
//--------------------------------------------------------------------------------------------------

GALGAS_object_5F_t function_void_5F_obj (Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_v ; // Returned variable
  result_v = GALGAS_void::class_func_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 492)), GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 492))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 492)) ;
//---
  return result_v ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_void_5F_obj [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_void_5F_obj (Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_void_5F_obj (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_void_5F_obj ("void_obj",
                                                             functionWithGenericHeader_void_5F_obj,
                                                             & kTypeDescriptor_GALGAS_object_5F_t,
                                                             0,
                                                             functionArgs_void_5F_obj) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'luint64_value'
//
//--------------------------------------------------------------------------------------------------

GALGAS_luint_36__34_ function_luint_36__34__5F_value (const GALGAS_uint_36__34__5F_class & constinArgument_c,
                                                      Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_luint_36__34_ result_v ; // Returned variable
  result_v = GALGAS_luint_36__34_::class_func_new (constinArgument_c.readProperty_value (), constinArgument_c.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 686)) ;
//---
  return result_v ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_luint_36__34__5F_value [2] = {
  & kTypeDescriptor_GALGAS_uint_36__34__5F_class,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_luint_36__34__5F_value (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_luint_36__34__5F_value ("luint64_value",
                                                                        functionWithGenericHeader_luint_36__34__5F_value,
                                                                        & kTypeDescriptor_GALGAS_luint_36__34_,
                                                                        1,
                                                                        functionArgs_luint_36__34__5F_value) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'projectName'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_projectName (Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_directory ; // Returned variable
  result_directory = GALGAS_string::class_func_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 30)).getter_stringByDeletingPathExtension (SOURCE_FILE ("goil_routines.galgas", 30)) ;
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_projectName [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_projectName (Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_projectName (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_projectName ("projectName",
                                                             functionWithGenericHeader_projectName,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             0,
                                                             functionArgs_projectName) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'oil_dir'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_oil_5F_dir (Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_dir ; // Returned variable
  result_dir = GALGAS_string::class_func_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 37)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("goil_routines.galgas", 37)) ;
//---
  return result_dir ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_oil_5F_dir [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_oil_5F_dir (Compiler * inCompiler,
                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  return function_oil_5F_dir (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_oil_5F_dir ("oil_dir",
                                                            functionWithGenericHeader_oil_5F_dir,
                                                            & kTypeDescriptor_GALGAS_string,
                                                            0,
                                                            functionArgs_oil_5F_dir) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'arch'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_arch (Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_arch_5F_name ; // Returned variable
  GALGAS_stringlist var_components_1206 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 45)) ;
  var_components_1206.method_first (result_arch_5F_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 46)) ;
//---
  return result_arch_5F_name ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_arch [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_arch (Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_arch (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_arch ("arch",
                                                      functionWithGenericHeader_arch,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_arch) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'chip'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_chip (Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_chip [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_chip (Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_chip (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_chip ("chip",
                                                      functionWithGenericHeader_chip,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_chip) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'board'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_board (Compiler * inCompiler
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
      result_board_5F_name = GALGAS_string::class_func_componentsJoinedByString (var_components_1945, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 72)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_board_5F_name = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_board_5F_name ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_board [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_board (Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_board (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_board ("board",
                                                       functionWithGenericHeader_board,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_board) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'targetPathList'
//
//--------------------------------------------------------------------------------------------------

GALGAS_list function_targetPathList (Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_list result_pathList ; // Returned variable
  GALGAS_stringlist var_components_2363 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 82)) ;
  result_pathList = GALGAS_list::class_func_emptyList (SOURCE_FILE ("goil_routines.galgas", 83)) ;
  cEnumerator_stringlist enumerator_2494 (var_components_2363, kENUMERATION_UP) ;
  while (enumerator_2494.hasCurrentObject ()) {
    GALGAS_gtlData var_cont_2534 = GALGAS_gtlString::class_func_new (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 85)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 85)), enumerator_2494.current_mValue (HERE)  COMMA_SOURCE_FILE ("goil_routines.galgas", 85)) ;
    result_pathList.addAssign_operation (var_cont_2534  COMMA_SOURCE_FILE ("goil_routines.galgas", 86)) ;
    enumerator_2494.gotoNextObject () ;
  }
//---
  return result_pathList ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_targetPathList [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_targetPathList (Compiler * inCompiler,
                                                               const cObjectArray & /* inEffectiveParameterArray */,
                                                               const GALGAS_location & /* inErrorLocation */
                                                               COMMA_LOCATION_ARGS) {
  return function_targetPathList (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_targetPathList ("targetPathList",
                                                                functionWithGenericHeader_targetPathList,
                                                                & kTypeDescriptor_GALGAS_list,
                                                                0,
                                                                functionArgs_targetPathList) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'add_path_component'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_add_5F_path_5F_component (GALGAS_string inArgument_path,
                                                 GALGAS_string inArgument_component,
                                                 Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_add_5F_path_5F_component [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_add_5F_path_5F_component (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_add_5F_path_5F_component ("add_path_component",
                                                                          functionWithGenericHeader_add_5F_path_5F_component,
                                                                          & kTypeDescriptor_GALGAS_string,
                                                                          2,
                                                                          functionArgs_add_5F_path_5F_component) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'rootTemplatesDirectory'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_rootTemplatesDirectory (Compiler * inCompiler
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
    GALGAS_string var_env_3104 = GALGAS_string::class_func_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("GOIL_TEMPLATES")  COMMA_SOURCE_FILE ("goil_routines.galgas", 110)) ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsNotEqual, var_env_3104.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        result_templateDirectory = var_env_3104 ;
      }
    }
    if (kBoolFalse == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 114)), GALGAS_string ("The templates path is not set. Use --templates option or set the GOIL_TEMPLATES environment variable"), fixItArray2  COMMA_SOURCE_FILE ("goil_routines.galgas", 114)) ;
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
          GALGAS_string var_home_3672 = GALGAS_string::class_func_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("HOME")  COMMA_SOURCE_FILE ("goil_routines.galgas", 123)) ;
          GALGAS_string var_relativeToHome_3753 = result_templateDirectory.getter_rightSubString (result_templateDirectory.getter_count (SOURCE_FILE ("goil_routines.galgas", 124)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 124)) COMMA_SOURCE_FILE ("goil_routines.galgas", 124)) ;
          result_templateDirectory = var_home_3672.add_operation (var_relativeToHome_3753, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 125)) ;
        }
      }
      if (kBoolFalse == test_4) {
        GALGAS_string var_currentDirectory_3912 = GALGAS_string::class_func_stringWithCurrentDirectory (SOURCE_FILE ("goil_routines.galgas", 127)) ;
        result_templateDirectory = var_currentDirectory_3912.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 128)).add_operation (result_templateDirectory, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 128)) ;
      }
      result_templateDirectory = result_templateDirectory.getter_stringByStandardizingPath (SOURCE_FILE ("goil_routines.galgas", 130)) ;
    }
  }
//---
  return result_templateDirectory ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_rootTemplatesDirectory [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_rootTemplatesDirectory (Compiler * inCompiler,
                                                                       const cObjectArray & /* inEffectiveParameterArray */,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  return function_rootTemplatesDirectory (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_rootTemplatesDirectory ("rootTemplatesDirectory",
                                                                        functionWithGenericHeader_rootTemplatesDirectory,
                                                                        & kTypeDescriptor_GALGAS_string,
                                                                        0,
                                                                        functionArgs_rootTemplatesDirectory) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'templates_directory'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_templates_5F_directory (GALGAS_string inArgument_prefix,
                                               Compiler * inCompiler
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
          GALGAS_string var_curdir_4433 = GALGAS_string::class_func_stringWithCurrentDirectory (SOURCE_FILE ("goil_routines.galgas", 140)) ;
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_templates_5F_directory [2] = {
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_templates_5F_directory (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_templates_5F_directory ("templates_directory",
                                                                        functionWithGenericHeader_templates_5F_directory,
                                                                        & kTypeDescriptor_GALGAS_string,
                                                                        1,
                                                                        functionArgs_templates_5F_directory) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'templateFilePath'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_templateFilePath (const GALGAS_string & constinArgument_prefix,
                                         const GALGAS_string & constinArgument_file,
                                         Compiler * inCompiler
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
        GALGAS_string var_targetPath_5319 = var_templateDir_5137.add_operation (GALGAS_string::class_func_componentsJoinedByString (var_components_5031, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 166)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)) ;
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_templateFilePath [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_templateFilePath (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_templateFilePath ("templateFilePath",
                                                                  functionWithGenericHeader_templateFilePath,
                                                                  & kTypeDescriptor_GALGAS_string,
                                                                  2,
                                                                  functionArgs_templateFilePath) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'allTemplatePaths'
//
//--------------------------------------------------------------------------------------------------

GALGAS_stringlist function_allTemplatePaths (const GALGAS_string & constinArgument_prefix,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist result_paths ; // Returned variable
  GALGAS_stringlist var_components_5742 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 184)) ;
  GALGAS_string var_partialPath_5844 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 185)) ;
  result_paths = GALGAS_stringlist::class_func_listWithValue (var_partialPath_5844  COMMA_SOURCE_FILE ("goil_routines.galgas", 187)) ;
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_allTemplatePaths [2] = {
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_allTemplatePaths (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_allTemplatePaths ("allTemplatePaths",
                                                                  functionWithGenericHeader_allTemplatePaths,
                                                                  & kTypeDescriptor_GALGAS_stringlist,
                                                                  1,
                                                                  functionArgs_allTemplatePaths) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'checkTemplatesPath'
//
//--------------------------------------------------------------------------------------------------

void routine_checkTemplatesPath (Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_configDir_6146 = function_rootTemplatesDirectory (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 197)).add_operation (GALGAS_string ("/config"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 197)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = var_configDir_6146.getter_directoryExists (SOURCE_FILE ("goil_routines.galgas", 198)).operator_not (SOURCE_FILE ("goil_routines.galgas", 198)).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 199)), GALGAS_string ("The templates path '").add_operation (var_configDir_6146, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 199)).add_operation (GALGAS_string ("' is not set to the templates directory"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 199)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 199)) ;
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
          inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 207)), GALGAS_string ("The templates path '").add_operation (var_partialPath_6361, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 207)).add_operation (GALGAS_string ("' does not exist in the templates directory"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 207)), fixItArray4  COMMA_SOURCE_FILE ("goil_routines.galgas", 207)) ;
          var_continueIt_6395 = GALGAS_bool (false) ;
        }
      }
      enumerator_6542.gotoNextObject () ;
    }
  }
}


//--------------------------------------------------------------------------------------------------
//
//Function 'allTemplateFilePaths'
//
//--------------------------------------------------------------------------------------------------

GALGAS_stringlist function_allTemplateFilePaths (const GALGAS_string & constinArgument_prefix,
                                                 const GALGAS_string & constinArgument_file,
                                                 Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist result_paths ; // Returned variable
  GALGAS_stringlist var_components_6948 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 220)) ;
  GALGAS_string var_templateDir_7054 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 221)) ;
  GALGAS_bool var_notOver_7105 = GALGAS_bool (true) ;
  result_paths = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("goil_routines.galgas", 223)) ;
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
        GALGAS_string var_intermediatePath_7218 = GALGAS_string::class_func_componentsJoinedByString (var_components_6948, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 227)) ;
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_allTemplateFilePaths [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_allTemplateFilePaths (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_allTemplateFilePaths ("allTemplateFilePaths",
                                                                      functionWithGenericHeader_allTemplateFilePaths,
                                                                      & kTypeDescriptor_GALGAS_stringlist,
                                                                      2,
                                                                      functionArgs_allTemplateFilePaths) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'prefix??!'
//
//--------------------------------------------------------------------------------------------------

void routine_prefix_3F__3F__21_ (GALGAS_prefix_5F_map inArgument_p,
                                 GALGAS_string inArgument_key,
                                 GALGAS_string & outArgument_val,
                                 Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_val.drop () ; // Release 'out' argument
  GALGAS_lstring var_lkey_7718 = GALGAS_lstring::class_func_new (inArgument_key, GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 243)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 243)) ;
  GALGAS_string joker_7788 ; // Joker input parameter
  inArgument_p.method_prefix (var_lkey_7718, outArgument_val, joker_7788, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 244)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'performReplace???&'
//
//--------------------------------------------------------------------------------------------------

void routine_performReplace_3F__3F__3F__26_ (GALGAS_prefix_5F_map inArgument_p,
                                             GALGAS_string inArgument_key,
                                             GALGAS_string inArgument_name,
                                             GALGAS_string & ioArgument_res,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkey_7890 = GALGAS_lstring::class_func_new (inArgument_key, GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 248)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 248)) ;
  GALGAS_string var_prefix_7951 ;
  GALGAS_string var_tag_5F_to_5F_rep_7974 ;
  inArgument_p.method_prefix (var_lkey_7890, var_prefix_7951, var_tag_5F_to_5F_rep_7974, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 251)) ;
  ioArgument_res = ioArgument_res.getter_stringByReplacingStringByString (var_tag_5F_to_5F_rep_7974, var_prefix_7951.add_operation (inArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 252)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 252)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'doReplace&??'
//
//--------------------------------------------------------------------------------------------------

void routine_doReplace_26__3F__3F_ (GALGAS_string & ioArgument_s,
                                    GALGAS_string inArgument_o,
                                    GALGAS_string inArgument_n,
                                    Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_s = ioArgument_s.getter_stringByReplacingStringByString (inArgument_o, inArgument_n, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 256)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'do_replace_default&???'
//
//--------------------------------------------------------------------------------------------------

void routine_do_5F_replace_5F_default_26__3F__3F__3F_ (GALGAS_string & ioArgument_s,
                                                       GALGAS_string inArgument_o,
                                                       GALGAS_string inArgument_n,
                                                       GALGAS_string inArgument_d,
                                                       Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Routine 'replace_no_prefix???&'
//
//--------------------------------------------------------------------------------------------------

void routine_replace_5F_no_5F_prefix_3F__3F__3F__26_ (GALGAS_prefix_5F_map inArgument_p,
                                                      GALGAS_string inArgument_key,
                                                      GALGAS_string inArgument_name,
                                                      GALGAS_string & ioArgument_res,
                                                      Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkey_8507 = GALGAS_lstring::class_func_new (inArgument_key, GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 268)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 268)) ;
  GALGAS_string var_tag_5F_to_5F_rep_8590 ;
  GALGAS_string joker_8621 ; // Joker input parameter
  inArgument_p.method_prefix (var_lkey_8507, joker_8621, var_tag_5F_to_5F_rep_8590, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 271)) ;
  ioArgument_res = ioArgument_res.getter_stringByReplacingStringByString (var_tag_5F_to_5F_rep_8590, inArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 272)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'table_core????&&'
//
//--------------------------------------------------------------------------------------------------

void routine_table_5F_core_3F__3F__3F__3F__26__26_ (GALGAS_string inArgument_typename,
                                                    GALGAS_string inArgument_varname,
                                                    GALGAS_string inArgument_obj_5F_prefix,
                                                    GALGAS_stringset inArgument_names,
                                                    GALGAS_string & ioArgument_header,
                                                    GALGAS_string & ioArgument_implementation,
                                                    Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Routine 'add_to_stringset&?'
//
//--------------------------------------------------------------------------------------------------

void routine_add_5F_to_5F_stringset_26__3F_ (GALGAS_stringset & ioArgument_ss,
                                             GALGAS_string inArgument_new,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = ioArgument_ss.getter_hasKey (inArgument_new COMMA_SOURCE_FILE ("goil_routines.galgas", 409)).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 410)), GALGAS_string ("'").add_operation (inArgument_new, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 410)).add_operation (GALGAS_string ("' is already declared before"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 410)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 410)) ;
    }
  }
  if (kBoolFalse == test_0) {
    ioArgument_ss.addAssign_operation (inArgument_new  COMMA_SOURCE_FILE ("goil_routines.galgas", 412)) ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'file_in_path&'
//
//--------------------------------------------------------------------------------------------------

void routine_file_5F_in_5F_path_26_ (GALGAS_lstring & ioArgument_file_5F_name,
                                     Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_include_5F_path_12900 = GALGAS_string::class_func_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("GOIL_INCLUDE_PATH")  COMMA_SOURCE_FILE ("goil_routines.galgas", 418)) ;
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
    var_includePathList_13182 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("goil_routines.galgas", 427)) ;
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
        ioArgument_file_5F_name = GALGAS_lstring::class_func_new (var_full_5F_file_5F_path_13512, GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 441)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 441)) ;
        var_not_5F_found_13439 = GALGAS_bool (false) ;
      }
    }
    enumerator_13473.gotoNextObject () ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'is_in_lstringlist??!!'
//
//--------------------------------------------------------------------------------------------------

void routine_is_5F_in_5F_lstringlist_3F__3F__21__21_ (GALGAS_lstringlist inArgument_l,
                                                      GALGAS_lstring inArgument_e,
                                                      GALGAS_lstring & outArgument_f,
                                                      GALGAS_bool & outArgument_p,
                                                      Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_f.drop () ; // Release 'out' argument
  outArgument_p.drop () ; // Release 'out' argument
  outArgument_p = GALGAS_bool (false) ;
  outArgument_f = GALGAS_lstring::class_func_new (GALGAS_string::makeEmptyString (), GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 453)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 453)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Function 'isInLstringlist'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool function_isInLstringlist (GALGAS_lstringlist inArgument_l,
                                      GALGAS_lstring inArgument_e,
                                      Compiler *
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_isInLstringlist [3] = {
  & kTypeDescriptor_GALGAS_lstringlist,
  & kTypeDescriptor_GALGAS_lstring,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_isInLstringlist (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_isInLstringlist ("isInLstringlist",
                                                                 functionWithGenericHeader_isInLstringlist,
                                                                 & kTypeDescriptor_GALGAS_bool,
                                                                 2,
                                                                 functionArgs_isInLstringlist) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'add_lstring_unique&??'
//
//--------------------------------------------------------------------------------------------------

void routine_add_5F_lstring_5F_unique_26__3F__3F_ (GALGAS_lstringlist & ioArgument_l,
                                                   GALGAS_lstring inArgument_e,
                                                   GALGAS_string inArgument_att,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool var_found_14492 ;
  GALGAS_lstring var_res_14513 ;
  {
  routine_is_5F_in_5F_lstringlist_3F__3F__21__21_ (ioArgument_l, inArgument_e, var_res_14513, var_found_14492, inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 480)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Routine 'set_lstring_if_empty&??'
//
//--------------------------------------------------------------------------------------------------

void routine_set_5F_lstring_5F_if_5F_empty_26__3F__3F_ (GALGAS_lstring & ioArgument_s,
                                                        GALGAS_lstring inArgument_ns,
                                                        GALGAS_string inArgument_att,
                                                        Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Routine 'add_makefile_flag_if_not_empty&??'
//
//--------------------------------------------------------------------------------------------------

void routine_add_5F_makefile_5F_flag_5F_if_5F_not_5F_empty_26__3F__3F_ (GALGAS_string & ioArgument_receiver,
                                                                        GALGAS_string inArgument_flag_5F_name,
                                                                        GALGAS_string inArgument_flag_5F_value,
                                                                        Compiler * inCompiler
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, inArgument_flag_5F_value.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      ioArgument_receiver.plusAssign_operation(inArgument_flag_5F_name.add_operation (GALGAS_string ("="), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 506)).add_operation (inArgument_flag_5F_value, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 506)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 506)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 506)) ;
    }
  }
}


//--------------------------------------------------------------------------------------------------
//
//Function 'lstringWith'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring function_lstringWith (GALGAS_string inArgument_s,
                                     Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_r ; // Returned variable
  result_r = GALGAS_lstring::class_func_new (inArgument_s, GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 511)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 511)) ;
//---
  return result_r ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_lstringWith [2] = {
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_lstringWith (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_lstringWith ("lstringWith",
                                                             functionWithGenericHeader_lstringWith,
                                                             & kTypeDescriptor_GALGAS_lstring,
                                                             1,
                                                             functionArgs_lstringWith) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'stripString'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_stripString (GALGAS_string inArgument_s,
                                    Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stripString [2] = {
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stripString (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stripString ("stripString",
                                                             functionWithGenericHeader_stripString,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             1,
                                                             functionArgs_stripString) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'errorNoFileFound???'
//
//--------------------------------------------------------------------------------------------------

void routine_errorNoFileFound_3F__3F__3F_ (const GALGAS_stringlist constinArgument_searchedPaths,
                                           const GALGAS_string constinArgument_kind,
                                           const GALGAS_lstring constinArgument_file,
                                           Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Function 'stringLBool'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_stringLBool (const GALGAS_lbool & constinArgument_boolValue,
                                    Compiler *
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringLBool [2] = {
  & kTypeDescriptor_GALGAS_lbool,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringLBool (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringLBool ("stringLBool",
                                                             functionWithGenericHeader_stringLBool,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             1,
                                                             functionArgs_stringLBool) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@structAttribute set'
//
//--------------------------------------------------------------------------------------------------

void cPtr_structAttribute::method_set (const GALGAS_lstring constinArgument_name,
                                       GALGAS_gtlData & ioArgument_result,
                                       Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_subAttrs_928 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) this->mProperty_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 33)) ;
  {
  var_subAttrs_928.insulate (HERE) ;
  cPtr_gtlData * ptr_969 = (cPtr_gtlData *) var_subAttrs_928.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_969, GALGAS_lstring::class_func_new (GALGAS_string ("NAME"), this->mProperty_structName.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 35)), GALGAS_gtlString::class_func_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_structName.readProperty_string ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 36)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 34)) ;
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@boolAttribute set'
//
//--------------------------------------------------------------------------------------------------

void cPtr_boolAttribute::method_set (const GALGAS_lstring constinArgument_name,
                                     GALGAS_gtlData & ioArgument_result,
                                     Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_1570 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1570, constinArgument_name, GALGAS_gtlBool::class_func_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 52)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 52)) ;
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
      GALGAS_lstring var_structName_1761 = GALGAS_lstring::class_func_new (constinArgument_name.readProperty_string ().add_operation (GALGAS_string ("_S"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 55)), constinArgument_name.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 55)) ;
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@enumAttribute set'
//
//--------------------------------------------------------------------------------------------------

void cPtr_enumAttribute::method_set (const GALGAS_lstring constinArgument_name,
                                     GALGAS_gtlData & ioArgument_result,
                                     Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_2190 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2190, constinArgument_name, GALGAS_gtlString::class_func_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 66)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 66)) ;
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
      GALGAS_lstring var_structName_2383 = GALGAS_lstring::class_func_new (constinArgument_name.readProperty_string ().add_operation (GALGAS_string ("_S"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 69)), constinArgument_name.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 69)) ;
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@stringAttribute set'
//
//--------------------------------------------------------------------------------------------------

void cPtr_stringAttribute::method_set (const GALGAS_lstring constinArgument_name,
                                       GALGAS_gtlData & ioArgument_result,
                                       Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_2628 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2628, constinArgument_name, GALGAS_gtlString::class_func_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 76)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 76)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@string_class set'
//
//--------------------------------------------------------------------------------------------------

void cPtr_string_5F_class::method_set (const GALGAS_lstring constinArgument_name,
                                       GALGAS_gtlData & ioArgument_result,
                                       Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_2785 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2785, constinArgument_name, GALGAS_gtlString::class_func_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 80)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 80)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@objectRefAttribute set'
//
//--------------------------------------------------------------------------------------------------

void cPtr_objectRefAttribute::method_set (const GALGAS_lstring constinArgument_name,
                                          GALGAS_gtlData & ioArgument_result,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_2948 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2948, constinArgument_name, GALGAS_gtlString::class_func_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value.readProperty_string ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 84)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 84)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@multipleAttribute set'
//
//--------------------------------------------------------------------------------------------------

void cPtr_multipleAttribute::method_set (const GALGAS_lstring constinArgument_name,
                                         GALGAS_gtlData & ioArgument_result,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlList var_multiple_3116 = GALGAS_gtlList::class_func_new (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 88)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 88)), GALGAS_list::class_func_emptyList (SOURCE_FILE ("systemConfig.galgas", 88))  COMMA_SOURCE_FILE ("systemConfig.galgas", 88)) ;
  cEnumerator_identifierList enumerator_3177 (this->mProperty_items, kENUMERATION_UP) ;
  while (enumerator_3177.hasCurrentObject ()) {
    GALGAS_gtlData var_multipleItem_3206 = GALGAS_gtlStruct::class_func_new (this->mProperty_location, this->mProperty_oil_5F_desc, GALGAS_gtlVarMap::class_func_emptyMap (SOURCE_FILE ("systemConfig.galgas", 90))  COMMA_SOURCE_FILE ("systemConfig.galgas", 90)) ;
    if (enumerator_3177.current_item (HERE).isValid ()) {
      if (enumerator_3177.current_item (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_structAttribute) {
        GALGAS_structAttribute cast_3314_aStruct ((cPtr_structAttribute *) enumerator_3177.current_item (HERE).ptr ()) ;
        {
        var_multipleItem_3206.insulate (HERE) ;
        cPtr_gtlData * ptr_3333 = (cPtr_gtlData *) var_multipleItem_3206.ptr () ;
        callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3333, GALGAS_lstring::class_func_new (GALGAS_string ("NAME"), cast_3314_aStruct.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 94)), GALGAS_gtlString::class_func_new (cast_3314_aStruct.readProperty_location (), cast_3314_aStruct.readProperty_oil_5F_desc (), cast_3314_aStruct.readProperty_structName ().readProperty_string ()  COMMA_SOURCE_FILE ("systemConfig.galgas", 95)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 93)) ;
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
        callExtensionMethod_set ((cPtr_object_5F_t *) enumerator_3177.current_item (HERE).ptr (), GALGAS_lstring::class_func_new (GALGAS_string ("VALUE"), enumerator_3177.current_item (HERE).readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 108)), var_multipleItem_3206, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 108)) ;
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@uint32_class set'
//
//--------------------------------------------------------------------------------------------------

void cPtr_uint_33__32__5F_class::method_set (const GALGAS_lstring constinArgument_name,
                                             GALGAS_gtlData & ioArgument_result,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4103 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4103, constinArgument_name, GALGAS_gtlInt::class_func_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 119))  COMMA_SOURCE_FILE ("systemConfig.galgas", 119)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 117)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@sint32_class set'
//
//--------------------------------------------------------------------------------------------------

void cPtr_sint_33__32__5F_class::method_set (const GALGAS_lstring constinArgument_name,
                                             GALGAS_gtlData & ioArgument_result,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4277 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4277, constinArgument_name, GALGAS_gtlInt::class_func_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 126))  COMMA_SOURCE_FILE ("systemConfig.galgas", 126)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 124)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@uint64_class set'
//
//--------------------------------------------------------------------------------------------------

void cPtr_uint_36__34__5F_class::method_set (const GALGAS_lstring constinArgument_name,
                                             GALGAS_gtlData & ioArgument_result,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4451 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4451, constinArgument_name, GALGAS_gtlInt::class_func_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 133))  COMMA_SOURCE_FILE ("systemConfig.galgas", 133)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 131)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@sint64_class set'
//
//--------------------------------------------------------------------------------------------------

void cPtr_sint_36__34__5F_class::method_set (const GALGAS_lstring constinArgument_name,
                                             GALGAS_gtlData & ioArgument_result,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4625 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4625, constinArgument_name, GALGAS_gtlInt::class_func_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 140))  COMMA_SOURCE_FILE ("systemConfig.galgas", 140)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 138)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@float_class set'
//
//--------------------------------------------------------------------------------------------------

void cPtr_float_5F_class::method_set (const GALGAS_lstring constinArgument_name,
                                      GALGAS_gtlData & ioArgument_result,
                                      Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4798 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4798, constinArgument_name, GALGAS_gtlFloat::class_func_new (this->mProperty_location, this->mProperty_oil_5F_desc, this->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 147)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 145)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@auto set'
//
//--------------------------------------------------------------------------------------------------

void cPtr_auto::method_set (const GALGAS_lstring constinArgument_name,
                            GALGAS_gtlData & ioArgument_result,
                            Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4957 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4957, constinArgument_name, GALGAS_gtlEnum::class_func_new (this->mProperty_location, this->mProperty_oil_5F_desc, GALGAS_string ("auto")  COMMA_SOURCE_FILE ("systemConfig.galgas", 154)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 152)) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Routine 'setDefaults?&'
//
//--------------------------------------------------------------------------------------------------

void routine_setDefaults_3F__26_ (const GALGAS_implementation constinArgument_imp,
                                  GALGAS_applicationDefinition & ioArgument_application,
                                  Compiler * inCompiler
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
          routine_setDefaultsForType_3F__26_ (var_impObject_1253.readProperty_attributes (), objectArray_1164->mProperty_attributes, inCompiler  COMMA_SOURCE_FILE ("defaults.galgas", 41)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@impStructType verifyType'
//
//--------------------------------------------------------------------------------------------------

void cPtr_impStructType::method_verifyType (const GALGAS_object_5F_t constinArgument_attr,
                                            Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@refType verifyType'
//
//--------------------------------------------------------------------------------------------------

void cPtr_refType::method_verifyType (const GALGAS_object_5F_t constinArgument_attr,
                                      Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_objectRefAttribute) {
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), GALGAS_string ("object reference expected"), fixItArray0  COMMA_SOURCE_FILE ("semantic_verification.galgas", 105)) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@impBoolType verifyType'
//
//--------------------------------------------------------------------------------------------------

void cPtr_impBoolType::method_verifyType (const GALGAS_object_5F_t constinArgument_attr,
                                          Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@impEnumType verifyType'
//
//--------------------------------------------------------------------------------------------------

void cPtr_impEnumType::method_verifyType (const GALGAS_object_5F_t constinArgument_attr,
                                          Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@impAutoDefaultType verifyType'
//
//--------------------------------------------------------------------------------------------------

void cPtr_impAutoDefaultType::method_verifyType (const GALGAS_object_5F_t constinArgument_attr,
                                                 Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_stringAttribute) {
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (GALGAS_dataType::class_func_string (SOURCE_FILE ("semantic_verification.galgas", 167)))).operator_and (GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (GALGAS_dataType::class_func_identifier (SOURCE_FILE ("semantic_verification.galgas", 167)))) COMMA_SOURCE_FILE ("semantic_verification.galgas", 167)).boolEnum () ;
        if (kBoolTrue == test_0) {
          TC_Array <C_FixItDescription> fixItArray1 ;
          inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), GALGAS_string ("string of identifier expected"), fixItArray1  COMMA_SOURCE_FILE ("semantic_verification.galgas", 168)) ;
        }
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_string_5F_class) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (GALGAS_dataType::class_func_identifier (SOURCE_FILE ("semantic_verification.galgas", 171)))).boolEnum () ;
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@impRangedType verifyType'
//
//--------------------------------------------------------------------------------------------------

void cPtr_impRangedType::method_verifyType (const GALGAS_object_5F_t constinArgument_attr,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (GALGAS_dataType::class_func_uint_33__32_Number (SOURCE_FILE ("semantic_verification.galgas", 188)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          TC_Array <C_FixItDescription> fixItArray1 ;
          inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), extensionGetter_oilType (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)), fixItArray1  COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)) ;
        }
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32__5F_class) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (GALGAS_dataType::class_func_sint_33__32_Number (SOURCE_FILE ("semantic_verification.galgas", 192)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          TC_Array <C_FixItDescription> fixItArray3 ;
          inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), extensionGetter_oilType (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)) ;
        }
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (GALGAS_dataType::class_func_uint_36__34_Number (SOURCE_FILE ("semantic_verification.galgas", 196)))).boolEnum () ;
        if (kBoolTrue == test_4) {
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), extensionGetter_oilType (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)), fixItArray5  COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)) ;
        }
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34__5F_class) {
      enumGalgasBool test_6 = kBoolTrue ;
      if (kBoolTrue == test_6) {
        test_6 = GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (GALGAS_dataType::class_func_sint_36__34_Number (SOURCE_FILE ("semantic_verification.galgas", 200)))).boolEnum () ;
        if (kBoolTrue == test_6) {
          TC_Array <C_FixItDescription> fixItArray7 ;
          inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), extensionGetter_oilType (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)), fixItArray7  COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)) ;
        }
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_float_5F_class) {
      enumGalgasBool test_8 = kBoolTrue ;
      if (kBoolTrue == test_8) {
        test_8 = GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (GALGAS_dataType::class_func_floatNumber (SOURCE_FILE ("semantic_verification.galgas", 204)))).boolEnum () ;
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
//--------------------------------------------------------------------------------------------------
//
//Function 'attributeAllowsAuto'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool function_attributeAllowsAuto (const GALGAS_impType & constinArgument_type,
                                          Compiler *
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_attributeAllowsAuto [2] = {
  & kTypeDescriptor_GALGAS_impType,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_attributeAllowsAuto (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_attributeAllowsAuto ("attributeAllowsAuto",
                                                                     functionWithGenericHeader_attributeAllowsAuto,
                                                                     & kTypeDescriptor_GALGAS_bool,
                                                                     1,
                                                                     functionArgs_attributeAllowsAuto) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'verifyAllAttributes??'
//
//--------------------------------------------------------------------------------------------------

void routine_verifyAllAttributes_3F__3F_ (const GALGAS_implementation constinArgument_imp,
                                          const GALGAS_objectsMap constinArgument_objects,
                                          Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@multipleAttribute verifyCrossReferences'
//
//--------------------------------------------------------------------------------------------------

void cPtr_multipleAttribute::method_verifyCrossReferences (const GALGAS_objectsMap constinArgument_allObjects,
                                                           const GALGAS_impType constinArgument_type,
                                                           Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_identifierList enumerator_19057 (this->mProperty_items, kENUMERATION_UP) ;
  while (enumerator_19057.hasCurrentObject ()) {
    callExtensionMethod_verifyCrossReferences ((cPtr_object_5F_t *) enumerator_19057.current_item (HERE).ptr (), constinArgument_allObjects, constinArgument_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 617)) ;
    enumerator_19057.gotoNextObject () ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@boolAttribute verifyCrossReferences'
//
//--------------------------------------------------------------------------------------------------

void cPtr_boolAttribute::method_verifyCrossReferences (const GALGAS_objectsMap constinArgument_allObjects,
                                                       const GALGAS_impType constinArgument_type,
                                                       Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@enumAttribute verifyCrossReferences'
//
//--------------------------------------------------------------------------------------------------

void cPtr_enumAttribute::method_verifyCrossReferences (const GALGAS_objectsMap constinArgument_allObjects,
                                                       const GALGAS_impType constinArgument_type,
                                                       Compiler * inCompiler
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
  GALGAS_lstring var_key_19666 = GALGAS_lstring::class_func_new (this->mProperty_value, GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("semantic_verification.galgas", 638)), inCompiler  COMMA_SOURCE_FILE ("semantic_verification.galgas", 638)) ;
  GALGAS_implementationObjectMap var_expectedAttributes_19764 ;
  var_enumType_19619.readProperty_valuesMap ().method_get (var_key_19666, var_expectedAttributes_19764, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 639)) ;
  callExtensionMethod_verifyCrossReferences ((cPtr_objectAttributes *) this->mProperty_subAttributes.ptr (), constinArgument_allObjects, var_expectedAttributes_19764, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 640)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@structAttribute verifyCrossReferences'
//
//--------------------------------------------------------------------------------------------------

void cPtr_structAttribute::method_verifyCrossReferences (const GALGAS_objectsMap constinArgument_allObjects,
                                                         const GALGAS_impType constinArgument_type,
                                                         Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@objectRefAttribute verifyCrossReferences'
//
//--------------------------------------------------------------------------------------------------

void cPtr_objectRefAttribute::method_verifyCrossReferences (const GALGAS_objectsMap constinArgument_allObjects,
                                                            const GALGAS_impType constinArgument_type,
                                                            Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Routine 'verifyAll??'
//
//--------------------------------------------------------------------------------------------------

void routine_verifyAll_3F__3F_ (const GALGAS_implementation constinArgument_imp,
                                const GALGAS_applicationDefinition constinArgument_application,
                                Compiler * inCompiler
                                COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_verifyAllAttributes_3F__3F_ (constinArgument_imp, constinArgument_application.readProperty_objects (), inCompiler  COMMA_SOURCE_FILE ("semantic_verification.galgas", 681)) ;
  }
  callExtensionMethod_verifyApplication ((cPtr_implementation *) constinArgument_imp.ptr (), constinArgument_application, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 682)) ;
  callExtensionMethod_verifyCrossReferences ((cPtr_applicationDefinition *) constinArgument_application.ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 685)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Function 'emptyApplicationDefinition'
//
//--------------------------------------------------------------------------------------------------

GALGAS_applicationDefinition function_emptyApplicationDefinition (Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_applicationDefinition result_result ; // Returned variable
  result_result = GALGAS_applicationDefinition::class_func_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 56)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 57)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 58)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 59)), GALGAS_objectsMap::class_func_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 60))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 55)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptyApplicationDefinition [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptyApplicationDefinition (Compiler * inCompiler,
                                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  return function_emptyApplicationDefinition (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptyApplicationDefinition ("emptyApplicationDefinition",
                                                                            functionWithGenericHeader_emptyApplicationDefinition,
                                                                            & kTypeDescriptor_GALGAS_applicationDefinition,
                                                                            0,
                                                                            functionArgs_emptyApplicationDefinition) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'osObject'
//
//--------------------------------------------------------------------------------------------------

GALGAS_objectAttributes function_osObject (const GALGAS_objectsMap & constinArgument_objects,
                                           Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_osObject [2] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_osObject (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_osObject ("osObject",
                                                          functionWithGenericHeader_osObject,
                                                          & kTypeDescriptor_GALGAS_objectAttributes,
                                                          1,
                                                          functionArgs_osObject) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'objectForKindAndName'
//
//--------------------------------------------------------------------------------------------------

GALGAS_objectAttributes function_objectForKindAndName (const GALGAS_objectsMap & constinArgument_objects,
                                                       const GALGAS_string & constinArgument_kind,
                                                       const GALGAS_string & constinArgument_name,
                                                       Compiler * inCompiler
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
        result_object = GALGAS_objectAttributes::class_func_new (GALGAS_identifierMap::class_func_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 85))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 85)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    result_object = GALGAS_objectAttributes::class_func_new (GALGAS_identifierMap::class_func_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 88))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 88)) ;
  }
//---
  return result_object ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_objectForKindAndName [4] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_objectForKindAndName (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_objectForKindAndName ("objectForKindAndName",
                                                                      functionWithGenericHeader_objectForKindAndName,
                                                                      & kTypeDescriptor_GALGAS_objectAttributes,
                                                                      3,
                                                                      functionArgs_objectForKindAndName) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'setObjectForKindAndName&???'
//
//--------------------------------------------------------------------------------------------------

void routine_setObjectForKindAndName_26__3F__3F__3F_ (GALGAS_objectsMap & ioArgument_objects,
                                                      const GALGAS_string constinArgument_kind,
                                                      const GALGAS_string constinArgument_name,
                                                      const GALGAS_objectAttributes constinArgument_object,
                                                      Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkind_2431 = function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 97)) ;
  GALGAS_lstring var_lname_2473 = function_lstringWith (constinArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 98)) ;
  GALGAS_objectKind var_kindObj_2514 = GALGAS_objectKind::class_func_new (GALGAS_objectKindMap::class_func_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 99))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 99)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Function 'objectsForKind'
//
//--------------------------------------------------------------------------------------------------

GALGAS_objectKind function_objectsForKind (const GALGAS_objectsMap & constinArgument_objects,
                                           const GALGAS_string & constinArgument_kind,
                                           Compiler * inCompiler
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
    result_result = GALGAS_objectKind::class_func_new (GALGAS_objectKindMap::class_func_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 119))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 119)) ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_objectsForKind [3] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_objectsForKind (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_objectsForKind ("objectsForKind",
                                                                functionWithGenericHeader_objectsForKind,
                                                                & kTypeDescriptor_GALGAS_objectKind,
                                                                2,
                                                                functionArgs_objectsForKind) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'listInOS'
//
//--------------------------------------------------------------------------------------------------

GALGAS_identifierList function_listInOS (const GALGAS_objectsMap & constinArgument_objects,
                                         const GALGAS_string & constinArgument_attributeName,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierList result_items ; // Returned variable
  GALGAS_object_5F_t var_itemsContainer_3225 ;
  GALGAS_objectAttributes var_os_3264 = function_osObject (constinArgument_objects, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 128)) ;
  var_os_3264.readProperty_objectParams ().method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 129)), var_itemsContainer_3225, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 129)) ;
  result_items = function_multipleAttributeOrError (var_itemsContainer_3225, constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 130)) ;
//---
  return result_items ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_listInOS [3] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_listInOS (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_listInOS ("listInOS",
                                                          functionWithGenericHeader_listInOS,
                                                          & kTypeDescriptor_GALGAS_identifierList,
                                                          2,
                                                          functionArgs_listInOS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'customGtlStringGetter'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData function_customGtlStringGetter (const GALGAS_lstring & constinArgument_methodName,
                                               const GALGAS_gtlDataList & constinArgument_arguments,
                                               const GALGAS_gtlContext &,
                                               const GALGAS_library &,
                                               const GALGAS_string & constinArgument_value,
                                               const GALGAS_location & constinArgument_where,
                                               Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("parseOIL").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 11)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 11)) ;
      }
      GALGAS_string var_rootTemplatesDir_343 = function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 12)) ;
      GALGAS_implementation var_imp_407 = GALGAS_implementation::class_func_new (GALGAS_implementationMap::class_func_emptyMap (SOURCE_FILE ("goil_gtl_extension.galgas", 13))  COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 13)) ;
      GALGAS_applicationDefinition var_app_493 = function_emptyApplicationDefinition (inCompiler COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 14)) ;
      GALGAS_lstring var_includeToParse_545 = GALGAS_lstring::class_func_new (var_rootTemplatesDir_343.add_operation (GALGAS_string ("libraries/config.oil"), inCompiler COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 16)), constinArgument_where, inCompiler  COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 15)) ;
      GALGAS_lstring var_fileToParse_661 = GALGAS_lstring::class_func_new (var_rootTemplatesDir_343.add_operation (GALGAS_string ("libraries/"), inCompiler COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 20)).add_operation (constinArgument_value, inCompiler COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 20)), constinArgument_where, inCompiler  COMMA_SOURCE_FILE ("goil_gtl_extension.galgas", 19)) ;
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


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_customGtlStringGetter [7] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_gtlDataList,
  & kTypeDescriptor_GALGAS_gtlContext,
  & kTypeDescriptor_GALGAS_library,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_location,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_customGtlStringGetter (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_customGtlStringGetter ("customGtlStringGetter",
                                                                       functionWithGenericHeader_customGtlStringGetter,
                                                                       & kTypeDescriptor_GALGAS_gtlData,
                                                                       6,
                                                                       functionArgs_customGtlStringGetter) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'generate_signed_type??!'
//
//--------------------------------------------------------------------------------------------------

void routine_generate_5F_signed_5F_type_3F__3F__21_ (GALGAS_uint_36__34_ inArgument_count,
                                                     GALGAS_string inArgument_err,
                                                     GALGAS_string & outArgument_type,
                                                     Compiler * inCompiler
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
        inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 51)), inArgument_err, fixItArray3  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 51)) ;
      }
    }
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'generate_unsigned_type??!'
//
//--------------------------------------------------------------------------------------------------

void routine_generate_5F_unsigned_5F_type_3F__3F__21_ (GALGAS_uint_36__34_ inArgument_count,
                                                       GALGAS_string inArgument_err,
                                                       GALGAS_string & outArgument_type,
                                                       Compiler * inCompiler
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
        inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 76)), inArgument_err, fixItArray3  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 76)) ;
      }
    }
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'generate_mask_type??!'
//
//--------------------------------------------------------------------------------------------------

void routine_generate_5F_mask_5F_type_3F__3F__21_ (GALGAS_uint_36__34_ inArgument_count,
                                                   GALGAS_string inArgument_err,
                                                   GALGAS_string & outArgument_type,
                                                   Compiler * inCompiler
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
        inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 101)), inArgument_err, fixItArray3  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 101)) ;
      }
    }
  }
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@goilContext fullPrefix'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_goilContext::getter_fullPrefix (const GALGAS_gtlData constinArgument_vars,
                                                    Compiler * inCompiler
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
  result_full = GALGAS_lstring::class_func_new (var_stringPrefix_22321, this->mProperty_prefix.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 702)) ;
//---
  return result_full ;
}


//--------------------------------------------------------------------------------------------------
//
//Function 'emptyGoilContext'
//
//--------------------------------------------------------------------------------------------------

GALGAS_goilContext function_emptyGoilContext (Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_goilContext result_context ; // Returned variable
  result_context = GALGAS_goilContext::class_func_new (function_emptylstring (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 710)), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), GALGAS_string (".gtl"), GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("goil_code_generation.galgas", 715)), GALGAS_gtlDataList::class_func_emptyList (SOURCE_FILE ("goil_code_generation.galgas", 716)), GALGAS_bool (true), function_defaultDebugSettings (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 718))  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 709)) ;
//---
  return result_context ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptyGoilContext [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptyGoilContext (Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_emptyGoilContext (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptyGoilContext ("emptyGoilContext",
                                                                  functionWithGenericHeader_emptyGoilContext,
                                                                  & kTypeDescriptor_GALGAS_goilContext,
                                                                  0,
                                                                  functionArgs_emptyGoilContext) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'generate_all?'
//
//--------------------------------------------------------------------------------------------------

void routine_generate_5F_all_3F_ (GALGAS_gtlData inArgument_cfg,
                                  Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_temp_5F_dir_23447 = function_templates_5F_directory (GALGAS_string ("code"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 735)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, var_temp_5F_dir_23447.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_string var_target_23531 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsNotEqual, var_target_23531.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_gtlContext var_context_23634 = function_emptyGoilContext (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 741)) ;
          {
          var_context_23634.setter_setTemplateDirectory (function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 743)) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 742)) ;
          }
          {
          var_context_23634.setter_setUserTemplateDirectory (GALGAS_string::class_func_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 746)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("goil_code_generation.galgas", 746)).add_operation (GALGAS_string ("/templates"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 746)) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 745)) ;
          }
          {
          var_context_23634.setter_setTemplateExtension (GALGAS_string ("goilTemplate") COMMA_SOURCE_FILE ("goil_code_generation.galgas", 749)) ;
          }
          {
          var_context_23634.insulate (HERE) ;
          cPtr_gtlContext * ptr_24018 = (cPtr_gtlContext *) var_context_23634.ptr () ;
          callExtensionSetter_addModulePath ((cPtr_gtlContext *) ptr_24018, function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 753)), GALGAS_string ("lib"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 752)) ;
          }
          {
          var_context_23634.setter_setPath (GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 756)) ;
          }
          GALGAS_string var_goilLog_24251 = function_invokeGTL (GALGAS_gtlString::class_func_new (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 762)), function_lstring (GALGAS_string ("root template filename"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 763)), GALGAS_string (gOption_goil_5F_options_root.readProperty_value ())  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 761)), var_context_23634, inArgument_cfg, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 760)) ;
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            test_2 = GALGAS_bool (gOption_goil_5F_options_generate_5F_log.readProperty_value ()).boolEnum () ;
            if (kBoolTrue == test_2) {
              var_goilLog_24251.method_writeToFile (GALGAS_string ("goil.log"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 771)) ;
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


//--------------------------------------------------------------------------------------------------
//
//Routine 'getAutosarVersion?!!'
//
//--------------------------------------------------------------------------------------------------

void routine_getAutosarVersion_3F__21__21_ (GALGAS_arxmlNode inArgument_rootNode,
                                            GALGAS_lstring & outArgument_iAutosarVersion,
                                            GALGAS_lstring & outArgument_iAutosarDescription,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_iAutosarVersion.drop () ; // Release 'out' argument
  outArgument_iAutosarDescription.drop () ; // Release 'out' argument
  GALGAS_lstring var_autosarVersion_7851 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 273)) ;
  GALGAS_lstring var_autosarDescription_7896 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 274)) ;
  GALGAS_arxmlElementList var_autosarNodes_8021 = GALGAS_arxmlElementList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 277)) ;
  callExtensionMethod_getSubElementsFromName ((cPtr_arxmlNode *) inArgument_rootNode.ptr (), GALGAS_string ("AUTOSAR"), var_autosarNodes_8021, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 278)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, var_autosarNodes_8021.getter_count (SOURCE_FILE ("arxml_parser.galgas", 279)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 280)), GALGAS_string ("[TPS_GST_00077] : Missing root AUTOSAR node."), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 280)) ;
    }
  }
  GALGAS_arxmlElementList var_adminDataNodes_8238 = GALGAS_arxmlElementList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 283)) ;
  extensionMethod_getSubElementsFromName (var_autosarNodes_8021, GALGAS_string ("ADMIN-DATA"), var_adminDataNodes_8238, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 284)) ;
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsEqual, var_adminDataNodes_8238.getter_count (SOURCE_FILE ("arxml_parser.galgas", 285)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 286)), GALGAS_string ("[TPS_ECUC_06004] : Missing AUTOSAR's ADMIN-DATA node."), fixItArray3  COMMA_SOURCE_FILE ("arxml_parser.galgas", 286)) ;
    }
  }
  GALGAS_arxmlElementList var_revisions_8477 = GALGAS_arxmlElementList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 289)) ;
  extensionMethod_getElementsFromName (var_adminDataNodes_8238, GALGAS_string ("DOC-REVISION"), var_revisions_8477, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 290)) ;
  enumGalgasBool test_4 = kBoolTrue ;
  if (kBoolTrue == test_4) {
    test_4 = GALGAS_bool (kIsEqual, var_adminDataNodes_8238.getter_count (SOURCE_FILE ("arxml_parser.galgas", 291)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_4) {
      TC_Array <C_FixItDescription> fixItArray5 ;
      inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 292)), GALGAS_string ("Missing AUTOSAR'S ADMIN-DATA's DOC-REVISION NODE"), fixItArray5  COMMA_SOURCE_FILE ("arxml_parser.galgas", 292)) ;
    }
  }
  GALGAS_bool var_version_5F_found_8690 = GALGAS_bool (false) ;
  GALGAS_bool var_issued_5F_by_5F_found_8720 = GALGAS_bool (false) ;
  GALGAS_lstring var_issued_5F_by_8755 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 297)) ;
  cEnumerator_arxmlElementList enumerator_8810 (var_revisions_8477, kENUMERATION_UP) ;
  bool bool_6 = var_version_5F_found_8690.operator_not (SOURCE_FILE ("arxml_parser.galgas", 300)).isValidAndTrue () ;
  if (enumerator_8810.hasCurrentObject () && bool_6) {
    while (enumerator_8810.hasCurrentObject () && bool_6) {
      var_issued_5F_by_5F_found_8720 = GALGAS_bool (false) ;
      callExtensionMethod_getProperty ((cPtr_arxmlElementNode *) enumerator_8810.current_node (HERE).ptr (), GALGAS_string ("ISSUED-BY"), var_issued_5F_by_8755, var_issued_5F_by_5F_found_8720, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 302)) ;
      enumGalgasBool test_7 = kBoolTrue ;
      if (kBoolTrue == test_7) {
        GALGAS_bool test_8 = var_issued_5F_by_5F_found_8720 ;
        if (kBoolTrue == test_8.boolEnum ()) {
          test_8 = GALGAS_bool (kIsEqual, var_issued_5F_by_8755.readProperty_string ().objectCompare (GALGAS_string ("AUTOSAR"))) ;
        }
        test_7 = test_8.boolEnum () ;
        if (kBoolTrue == test_7) {
          GALGAS_bool var_description_5F_found_9033 = GALGAS_bool (false) ;
          callExtensionMethod_getProperty ((cPtr_arxmlElementNode *) enumerator_8810.current_node (HERE).ptr (), GALGAS_string ("REVISION-LABEL"), var_autosarVersion_7851, var_version_5F_found_8690, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 305)) ;
          callExtensionMethod_getProperty ((cPtr_arxmlElementNode *) enumerator_8810.current_node (HERE).ptr (), GALGAS_string ("DATE"), var_autosarDescription_7896, var_description_5F_found_9033, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 306)) ;
        }
      }
      enumerator_8810.gotoNextObject () ;
      if (enumerator_8810.hasCurrentObject ()) {
        bool_6 = var_version_5F_found_8690.operator_not (SOURCE_FILE ("arxml_parser.galgas", 300)).isValidAndTrue () ;
      }
    }
  }
  outArgument_iAutosarVersion = var_autosarVersion_7851 ;
  outArgument_iAutosarDescription = var_autosarDescription_7896 ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'includeConfigs&&&?'
//
//--------------------------------------------------------------------------------------------------

void routine_includeConfigs_26__26__26__3F_ (GALGAS_implementation & ioArgument_imp,
                                             GALGAS_applicationDefinition & ioArgument_application,
                                             GALGAS_string & ioArgument_fileIncludeList,
                                             GALGAS_lstring inArgument_version,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_config_5F_file_5F_name_9573 = GALGAS_string (gOption_goil_5F_options_config.readProperty_value ()) ;
  GALGAS_stringlist var_configFiles_9647 = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name_9573.add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 325)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 324)) ;
  cEnumerator_stringlist enumerator_9906 (var_configFiles_9647, kENUMERATION_DOWN) ;
  while (enumerator_9906.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_9906.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 330)), ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, GALGAS_bool (false)  COMMA_SOURCE_FILE ("arxml_parser.galgas", 330)) ;
    enumerator_9906.gotoNextObject () ;
  }
  GALGAS_stringlist var_configVersionFiles_10217 = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name_9573.add_operation (inArgument_version.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 337)).add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 337)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 336)) ;
  cEnumerator_stringlist enumerator_10369 (var_configVersionFiles_10217, kENUMERATION_DOWN) ;
  while (enumerator_10369.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_10369.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 340)), ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, GALGAS_bool (false)  COMMA_SOURCE_FILE ("arxml_parser.galgas", 340)) ;
    enumerator_10369.gotoNextObject () ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'nodeToClass?&!'
//
//--------------------------------------------------------------------------------------------------

void routine_nodeToClass_3F__26__21_ (GALGAS_arxmlNode inArgument_rootNode,
                                      GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                      GALGAS_arxmlElementValue & outArgument_rootValue,
                                      Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_rootValue.drop () ; // Release 'out' argument
  GALGAS_arxmlElementList var_autosarNodes_10738 = GALGAS_arxmlElementList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 351)) ;
  callExtensionMethod_getSubElementsFromName ((cPtr_arxmlNode *) inArgument_rootNode.ptr (), GALGAS_string ("AUTOSAR"), var_autosarNodes_10738, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 352)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, var_autosarNodes_10738.getter_count (SOURCE_FILE ("arxml_parser.galgas", 353)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 354)), GALGAS_string ("[TPS_GST_00077] : Missing root AUTOSAR node."), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 354)) ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsStrictSup, var_autosarNodes_10738.getter_count (SOURCE_FILE ("arxml_parser.galgas", 356)).objectCompare (GALGAS_uint (uint32_t (1U)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 357)), GALGAS_string ("[TPS_GST_00077] : Too many AUTOSAR nodes."), fixItArray3  COMMA_SOURCE_FILE ("arxml_parser.galgas", 357)) ;
    }
  }
  GALGAS_arxmlElementNode var_autosarNode_11098 ;
  var_autosarNodes_10738.method_first (var_autosarNode_11098, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 362)) ;
  {
  routine_nodeToClassRes_3F__3F__21_ (var_autosarNode_11098, ioArgument_classMap, outArgument_rootValue, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 363)) ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'nodeToClassRes??!'
//
//--------------------------------------------------------------------------------------------------

void routine_nodeToClassRes_3F__3F__21_ (GALGAS_arxmlElementNode inArgument_currentElement,
                                         GALGAS_arxmlMetaClassMap inArgument_classMap,
                                         GALGAS_arxmlElementValue & outArgument_elementValue,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_elementValue.drop () ; // Release 'out' argument
  GALGAS_arxmlMetaClass var_currentClass_11372 ;
  inArgument_classMap.method_searchKey (inArgument_currentElement.readProperty_name (), var_currentClass_11372, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 373)) ;
  GALGAS_bool var_textFound_11481 = GALGAS_bool (false) ;
  GALGAS_lstring var_text_11510 = GALGAS_lstring::class_func_new (GALGAS_string::makeEmptyString (), GALGAS_location::class_func_nowhere (SOURCE_FILE ("arxml_parser.galgas", 377)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 377)) ;
  callExtensionMethod_getText ((cPtr_arxmlElementNode *) inArgument_currentElement.ptr (), var_text_11510, var_textFound_11481, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 378)) ;
  GALGAS_lstring var_type_11628 = var_currentClass_11372.readProperty_name () ;
  outArgument_elementValue = GALGAS_arxmlElementValue::class_func_new (var_type_11628, var_text_11510, GALGAS_arxmlElementValueMap::class_func_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 385)), inArgument_currentElement.readProperty_attributes ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 382)) ;
  GALGAS_arxmlElementList var_subElements_12034 ;
  callExtensionMethod_getSubElements ((cPtr_arxmlElementNode *) inArgument_currentElement.ptr (), var_subElements_12034, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 390)) ;
  cEnumerator_arxmlElementList enumerator_12072 (var_subElements_12034, kENUMERATION_UP) ;
  while (enumerator_12072.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlMetaClass *) var_currentClass_11372.ptr (), enumerator_12072.current_node (HERE).readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 392)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 392)).boolEnum () ;
      if (kBoolTrue == test_0) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (enumerator_12072.current_node (HERE).readProperty_name ().readProperty_location (), GALGAS_string ("The element ").add_operation (enumerator_12072.current_node (HERE).readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 393)).add_operation (GALGAS_string (" does not belong to the "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 393)).add_operation (inArgument_currentElement.readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 394)).add_operation (GALGAS_string (" element.\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 395)).add_operation (GALGAS_string ("Possible elements are :\n "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 395)).add_operation (extensionGetter_string (var_currentClass_11372.readProperty_lElementLegacy (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 396)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 396)), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 393)) ;
      }
    }
    enumerator_12072.gotoNextObject () ;
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsNotEqual, inArgument_currentElement.readProperty_name ().readProperty_string ().objectCompare (GALGAS_string ("AUTOSAR"))).boolEnum () ;
    if (kBoolTrue == test_2) {
      cEnumerator_arxmlAttributeMap enumerator_12603 (inArgument_currentElement.readProperty_attributes (), kENUMERATION_UP) ;
      while (enumerator_12603.hasCurrentObject ()) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = callExtensionGetter_hasAttribute ((const cPtr_arxmlMetaClass *) var_currentClass_11372.ptr (), enumerator_12603.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 404)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 404)).boolEnum () ;
          if (kBoolTrue == test_3) {
            TC_Array <C_FixItDescription> fixItArray4 ;
            inCompiler->emitSemanticError (enumerator_12603.current_lkey (HERE).readProperty_location (), GALGAS_string ("The attribute ").add_operation (enumerator_12603.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)).add_operation (GALGAS_string (" does not belong to the "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)).add_operation (inArgument_currentElement.readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)).add_operation (GALGAS_string (" element.\nPossible "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 406)).add_operation (GALGAS_string ("attributes are :\n "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 406)).add_operation (extensionGetter_string (var_currentClass_11372.readProperty_lAttributeLegacy (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 407)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 407)), fixItArray4  COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)) ;
          }
        }
        enumerator_12603.gotoNextObject () ;
      }
    }
  }
  cEnumerator_arxmlMetaElementList enumerator_13044 (var_currentClass_11372.readProperty_lElementLegacy (), kENUMERATION_UP) ;
  while (enumerator_13044.hasCurrentObject ()) {
    GALGAS_arxmlElementList var_subElements_13112 = GALGAS_arxmlElementList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 414)) ;
    callExtensionMethod_getSubElementsFromName ((cPtr_arxmlElementNode *) inArgument_currentElement.ptr (), enumerator_13044.current_lElement (HERE).readProperty_name ().readProperty_string (), var_subElements_13112, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 416)) ;
    GALGAS_uint var_minOccurs_13331 = GALGAS_uint (uint32_t (1U)) ;
    GALGAS_uint var_maxOccurs_13355 = GALGAS_uint (uint32_t (1U)) ;
    enumGalgasBool test_5 = kBoolTrue ;
    if (kBoolTrue == test_5) {
      GALGAS_bool test_6 = GALGAS_bool (kIsNotEqual, enumerator_13044.current_lElement (HERE).readProperty_minOccurs ().readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())) ;
      if (kBoolTrue == test_6.boolEnum ()) {
        test_6 = enumerator_13044.current_lElement (HERE).readProperty_minOccurs ().readProperty_string ().getter_isDecimalUnsignedNumber (SOURCE_FILE ("arxml_parser.galgas", 424)) ;
      }
      test_5 = test_6.boolEnum () ;
      if (kBoolTrue == test_5) {
        var_minOccurs_13331 = enumerator_13044.current_lElement (HERE).readProperty_minOccurs ().readProperty_string ().getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 425)) ;
      }
    }
    enumGalgasBool test_7 = kBoolTrue ;
    if (kBoolTrue == test_7) {
      test_7 = GALGAS_bool (kIsStrictInf, var_subElements_13112.getter_count (SOURCE_FILE ("arxml_parser.galgas", 428)).objectCompare (var_minOccurs_13331)).boolEnum () ;
      if (kBoolTrue == test_7) {
        TC_Array <C_FixItDescription> fixItArray8 ;
        inCompiler->emitSemanticError (inArgument_currentElement.readProperty_name ().readProperty_location (), GALGAS_string ("Missing element ").add_operation (enumerator_13044.current_lElement (HERE).readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 429)).add_operation (GALGAS_string (". Minimum : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 429)).add_operation (var_minOccurs_13331.getter_string (SOURCE_FILE ("arxml_parser.galgas", 430)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 430)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 430)).add_operation (GALGAS_string (" Found "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 430)).add_operation (var_subElements_13112.getter_count (SOURCE_FILE ("arxml_parser.galgas", 431)).getter_string (SOURCE_FILE ("arxml_parser.galgas", 431)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 431)), fixItArray8  COMMA_SOURCE_FILE ("arxml_parser.galgas", 429)) ;
      }
    }
    enumGalgasBool test_9 = kBoolTrue ;
    if (kBoolTrue == test_9) {
      GALGAS_bool test_10 = GALGAS_bool (kIsNotEqual, enumerator_13044.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ().objectCompare (GALGAS_string ("unbounded"))) ;
      if (kBoolTrue == test_10.boolEnum ()) {
        test_10 = GALGAS_bool (kIsNotEqual, enumerator_13044.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())) ;
      }
      test_9 = test_10.boolEnum () ;
      if (kBoolTrue == test_9) {
        enumGalgasBool test_11 = kBoolTrue ;
        if (kBoolTrue == test_11) {
          GALGAS_bool test_12 = GALGAS_bool (kIsNotEqual, enumerator_13044.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())) ;
          if (kBoolTrue == test_12.boolEnum ()) {
            test_12 = enumerator_13044.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ().getter_isDecimalUnsignedNumber (SOURCE_FILE ("arxml_parser.galgas", 439)) ;
          }
          test_11 = test_12.boolEnum () ;
          if (kBoolTrue == test_11) {
            var_maxOccurs_13355 = enumerator_13044.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ().getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 440)) ;
          }
        }
        enumGalgasBool test_13 = kBoolTrue ;
        if (kBoolTrue == test_13) {
          test_13 = GALGAS_bool (kIsStrictSup, var_subElements_13112.getter_count (SOURCE_FILE ("arxml_parser.galgas", 443)).objectCompare (var_maxOccurs_13355)).boolEnum () ;
          if (kBoolTrue == test_13) {
            TC_Array <C_FixItDescription> fixItArray14 ;
            inCompiler->emitSemanticError (inArgument_currentElement.readProperty_name ().readProperty_location (), GALGAS_string ("Too many node ").add_operation (enumerator_13044.current_lElement (HERE).readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 444)).add_operation (GALGAS_string (". Minimum : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 444)).add_operation (var_minOccurs_13331.getter_string (SOURCE_FILE ("arxml_parser.galgas", 445)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 445)).add_operation (GALGAS_string (" ; Maximum : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 445)).add_operation (var_maxOccurs_13355.getter_string (SOURCE_FILE ("arxml_parser.galgas", 445)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 445)).add_operation (GALGAS_string (". Found "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 445)).add_operation (var_subElements_13112.getter_count (SOURCE_FILE ("arxml_parser.galgas", 446)).getter_string (SOURCE_FILE ("arxml_parser.galgas", 446)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 446)), fixItArray14  COMMA_SOURCE_FILE ("arxml_parser.galgas", 444)) ;
          }
        }
      }
    }
    cEnumerator_arxmlElementList enumerator_14632 (var_subElements_13112, kENUMERATION_UP) ;
    while (enumerator_14632.hasCurrentObject ()) {
      GALGAS_arxmlElementValue var_subElementValue_14691 ;
      {
      routine_nodeToClassRes_3F__3F__21_ (enumerator_14632.current_node (HERE), inArgument_classMap, var_subElementValue_14691, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 453)) ;
      }
      {
      outArgument_elementValue.insulate (HERE) ;
      cPtr_arxmlElementValue * ptr_14777 = (cPtr_arxmlElementValue *) outArgument_elementValue.ptr () ;
      callExtensionSetter_insertElement ((cPtr_arxmlElementValue *) ptr_14777, enumerator_14632.current_node (HERE).readProperty_name (), var_subElementValue_14691, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 454)) ;
      }
      enumerator_14632.gotoNextObject () ;
    }
    enumerator_13044.gotoNextObject () ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'addText&?'
//
//--------------------------------------------------------------------------------------------------

void routine_addText_26__3F_ (GALGAS_arxmlNodeList & ioArgument_nodes,
                              const GALGAS_bool constinArgument_doNotCondenseWhiteSpaces,
                              Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_s_14956 = GALGAS_string::class_func_retrieveAndResetTemplateString (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 463)) ;
  GALGAS_string var_trimmedString_15006 = var_s_14956.getter_stringByTrimmingWhiteSpaces (SOURCE_FILE ("arxml_parser.galgas", 464)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_trimmedString_15006.getter_count (SOURCE_FILE ("arxml_parser.galgas", 465)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_ls_15108 ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = constinArgument_doNotCondenseWhiteSpaces.boolEnum () ;
        if (kBoolTrue == test_1) {
          var_ls_15108 = GALGAS_lstring::class_func_new (var_s_14956, GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 468)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 468)) ;
        }
      }
      if (kBoolFalse == test_1) {
        var_ls_15108 = GALGAS_lstring::class_func_new (var_trimmedString_15006, GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 470)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 470)) ;
      }
      ioArgument_nodes.addAssign_operation (GALGAS_arxmlTextNode::class_func_new (var_ls_15108  COMMA_SOURCE_FILE ("arxml_parser.galgas", 473))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 473)) ;
    }
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'convertToOil&&?'
//
//--------------------------------------------------------------------------------------------------

void routine_convertToOil_26__26__3F_ (GALGAS_implementation & ioArgument_imp,
                                       GALGAS_applicationDefinition & ioArgument_application,
                                       GALGAS_arxmlElementValue inArgument_rootValue,
                                       Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_emptyPath_15418 = GALGAS_lstring::class_func_new (GALGAS_string::makeEmptyString (), GALGAS_location::class_func_nowhere (SOURCE_FILE ("arxml_parser.galgas", 482)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 482)) ;
  GALGAS_arxmlElementValueList var_packages_15505 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 485)) ;
  GALGAS_stringlist var_packagesPath_15533 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 486)) ;
  var_packagesPath_15533.addAssign_operation (GALGAS_string ("AR-PACKAGES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 487)) ;
  var_packagesPath_15533.addAssign_operation (GALGAS_string ("AR-PACKAGE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 488)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_rootValue.ptr (), var_packagesPath_15533, var_packages_15505, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 489)) ;
  cEnumerator_arxmlElementValueList enumerator_15722 (var_packages_15505, kENUMERATION_UP) ;
  while (enumerator_15722.hasCurrentObject ()) {
    {
    routine_arxmlImplementationPackage_26__3F__3F_ (ioArgument_imp, enumerator_15722.current_value (HERE), var_emptyPath_15418, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 493)) ;
    }
    enumerator_15722.gotoNextObject () ;
  }
  cEnumerator_arxmlElementValueList enumerator_15856 (var_packages_15505, kENUMERATION_UP) ;
  while (enumerator_15856.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionPackage_26__26__3F__3F_ (ioArgument_imp, ioArgument_application, enumerator_15856.current_value (HERE), var_emptyPath_15418, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 498)) ;
    }
    enumerator_15856.gotoNextObject () ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationPackage&??'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlImplementationPackage_26__3F__3F_ (GALGAS_implementation & ioArgument_imp,
                                                     GALGAS_arxmlElementValue inArgument_packageElement,
                                                     GALGAS_lstring inArgument_parentPath,
                                                     Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_packageName_16229 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 512)) ;
  GALGAS_lstring var_currentPath_16342 = GALGAS_lstring::class_func_new (inArgument_parentPath.readProperty_string ().add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 515)).add_operation (var_packageName_16229.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 515)), var_packageName_16229.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 515)) ;
  GALGAS_arxmlElementValueList var_definitions_16572 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 519)) ;
  GALGAS_stringlist var_definitionPath_16603 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 520)) ;
  var_definitionPath_16603.addAssign_operation (GALGAS_string ("ELEMENTS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 521)) ;
  var_definitionPath_16603.addAssign_operation (GALGAS_string ("ECUC-MODULE-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 522)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_definitionPath_16603, var_definitions_16572, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 523)) ;
  cEnumerator_arxmlElementValueList enumerator_16786 (var_definitions_16572, kENUMERATION_UP) ;
  while (enumerator_16786.hasCurrentObject ()) {
    {
    routine_arxmlImplementationRoot_26__3F__3F_ (ioArgument_imp, enumerator_16786.current_value (HERE), var_currentPath_16342, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 525)) ;
    }
    enumerator_16786.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_packages_16962 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 529)) ;
  GALGAS_stringlist var_packagesPath_16990 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 530)) ;
  var_packagesPath_16990.addAssign_operation (GALGAS_string ("AR-PACKAGES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 531)) ;
  var_packagesPath_16990.addAssign_operation (GALGAS_string ("AR-PACKAGE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 532)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_packagesPath_16990, var_packages_16962, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 533)) ;
  cEnumerator_arxmlElementValueList enumerator_17160 (var_packages_16962, kENUMERATION_UP) ;
  while (enumerator_17160.hasCurrentObject ()) {
    {
    routine_arxmlImplementationPackage_26__3F__3F_ (ioArgument_imp, enumerator_17160.current_value (HERE), var_currentPath_16342, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 535)) ;
    }
    enumerator_17160.gotoNextObject () ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationRoot&??'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlImplementationRoot_26__3F__3F_ (GALGAS_implementation & ioArgument_implementation,
                                                  GALGAS_arxmlElementValue inArgument_packageElement,
                                                  GALGAS_lstring inArgument_parentPath,
                                                  Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_objectName_17422 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 545)) ;
  {
  routine_displayOil_3F_ (GALGAS_string ("\nIMPLEMENTATION ").add_operation (var_objectName_17422.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 546)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 546)) ;
  }
  GALGAS_lstring var_currentPath_17581 = GALGAS_lstring::class_func_new (inArgument_parentPath.readProperty_string ().add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 549)).add_operation (var_objectName_17422.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 549)), inArgument_parentPath.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 549)) ;
  GALGAS_lstring var_oil_5F_desc_17787 ;
  {
  routine_arxmlGetDescription_3F__21_ (inArgument_packageElement, var_oil_5F_desc_17787, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 553)) ;
  }
  GALGAS_arxmlElementValueList var_subDefs_17850 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 556)) ;
  GALGAS_stringlist var_subDefsPath_17877 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 557)) ;
  var_subDefsPath_17877.addAssign_operation (GALGAS_string ("CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 558)) ;
  var_subDefsPath_17877.addAssign_operation (GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 559)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_subDefsPath_17877, var_subDefs_17850, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 560)) ;
  {
  routine_displayOil_3F_ (GALGAS_string ("\n{\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 562)) ;
  }
  cEnumerator_arxmlElementValueList enumerator_18121 (var_subDefs_17850, kENUMERATION_UP) ;
  while (enumerator_18121.hasCurrentObject ()) {
    {
    routine_arxmlImplementationObject_26__3F__3F_ (ioArgument_implementation, enumerator_18121.current_value (HERE), var_currentPath_17581, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 566)) ;
    }
    enumerator_18121.gotoNextObject () ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string ("}; /* END IMPLEMENTATION ").add_operation (var_objectName_17422.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 569)).add_operation (GALGAS_string (" : \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 569)).add_operation (var_oil_5F_desc_17787.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 570)).add_operation (GALGAS_string ("\" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 570)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 569)) ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationObject&??'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlImplementationObject_26__3F__3F_ (GALGAS_implementation & ioArgument_implementation,
                                                    GALGAS_arxmlElementValue inArgument_packageElement,
                                                    GALGAS_lstring inArgument_parentPath,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationMap var_imp_18497 = ioArgument_implementation.readProperty_imp () ;
  GALGAS_implementationObjectMap var_objectAttributes_18551 = GALGAS_implementationObjectMap::class_func_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 579)) ;
  GALGAS_lstring var_objectName_18713 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 583)) ;
  GALGAS_lstring var_currentPath_18824 = GALGAS_lstring::class_func_new (inArgument_parentPath.readProperty_string ().add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 586)).add_operation (var_objectName_18713.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 586)), inArgument_parentPath.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 586)) ;
  GALGAS_lstring var_objectKind_19073 = var_objectName_18713 ;
  var_objectKind_19073.setter_setString (var_objectName_18713.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 591)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 591)) ;
  {
  routine_displayOil_3F_ (GALGAS_string ("  ").add_operation (var_objectKind_19073.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 593)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 593)) ;
  }
  GALGAS_lbool var_multiple_19297 ;
  {
  routine_arxmlGetMultiplicity_3F__3F__21_ (inArgument_packageElement, var_objectName_18713, var_multiple_19297, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 596)) ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string ("\n  {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 597)) ;
  }
  GALGAS_lstring var_oil_5F_desc_19416 ;
  {
  routine_arxmlGetDescription_3F__21_ (inArgument_packageElement, var_oil_5F_desc_19416, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 600)) ;
  }
  {
  routine_arxmlImplementationContainer_26__3F__3F_ (var_objectAttributes_18551, inArgument_packageElement, var_currentPath_18824, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 603)) ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string ("  }; /* \"").add_operation (var_oil_5F_desc_19416.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 607)).add_operation (GALGAS_string ("\"*/\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 607)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 607)) ;
  }
  GALGAS_implementationObject var_newObject_19721 = GALGAS_implementationObject::class_func_new (var_multiple_19297, var_objectAttributes_18551  COMMA_SOURCE_FILE ("arxml_parser.galgas", 611)) ;
  GALGAS_implementationObject var_object_19894 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasKey ((const cPtr_implementation *) ioArgument_implementation.ptr (), var_objectName_18713.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 616)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      var_imp_18497.setter_del (var_objectName_18713, var_object_19894, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 617)) ;
      }
      var_object_19894 = callExtensionGetter_mergeImplementationObjectWith ((const cPtr_implementationObject *) var_object_19894.ptr (), var_newObject_19721, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 618)) ;
    }
  }
  if (kBoolFalse == test_0) {
    var_object_19894 = var_newObject_19721 ;
  }
  {
  var_imp_18497.setter_put (var_objectName_18713, var_object_19894, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 624)) ;
  }
  {
  ioArgument_implementation.setter_setImp (var_imp_18497 COMMA_SOURCE_FILE ("arxml_parser.galgas", 625)) ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainer&??'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainer_26__3F__3F_ (GALGAS_implementationObjectMap & ioArgument_objectAttributes,
                                                       GALGAS_arxmlElementValue inArgument_currentElement,
                                                       GALGAS_lstring inArgument_parentPath,
                                                       Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList var_intParameters_20546 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 636)) ;
  GALGAS_stringlist var_intParametersPath_20579 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 637)) ;
  var_intParametersPath_20579.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 638)) ;
  var_intParametersPath_20579.addAssign_operation (GALGAS_string ("ECUC-INTEGER-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 639)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_intParametersPath_20579, var_intParameters_20546, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 640)) ;
  cEnumerator_arxmlElementValueList enumerator_20786 (var_intParameters_20546, kENUMERATION_UP) ;
  while (enumerator_20786.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_20834 ;
    GALGAS_impType var_type_20865 ;
    {
    routine_arxmlImplementationContainerNumber_21__21__3F__3F__3F_ (var_attributeName_20834, var_type_20865, GALGAS_dataType::class_func_uint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 647)), enumerator_20786.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 645)) ;
    }
    {
    routine_arxmlInsertObjectAttribute_26__3F__3F_ (ioArgument_objectAttributes, var_attributeName_20834, var_type_20865, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 650)) ;
    }
    enumerator_20786.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_floatParameters_21418 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 656)) ;
  GALGAS_stringlist var_floatParametersPath_21453 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 657)) ;
  var_floatParametersPath_21453.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 658)) ;
  var_floatParametersPath_21453.addAssign_operation (GALGAS_string ("ECUC-FLOAT-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 659)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_floatParametersPath_21453, var_floatParameters_21418, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 660)) ;
  cEnumerator_arxmlElementValueList enumerator_21668 (var_floatParameters_21418, kENUMERATION_UP) ;
  while (enumerator_21668.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_21718 ;
    GALGAS_impType var_type_21749 ;
    {
    routine_arxmlImplementationContainerNumber_21__21__3F__3F__3F_ (var_attributeName_21718, var_type_21749, GALGAS_dataType::class_func_floatNumber (SOURCE_FILE ("arxml_parser.galgas", 667)), enumerator_21668.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 665)) ;
    }
    {
    routine_arxmlInsertObjectAttribute_26__3F__3F_ (ioArgument_objectAttributes, var_attributeName_21718, var_type_21749, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 670)) ;
    }
    enumerator_21668.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_stringParameters_22289 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 676)) ;
  GALGAS_stringlist var_stringParametersPath_22325 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 677)) ;
  var_stringParametersPath_22325.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 678)) ;
  var_stringParametersPath_22325.addAssign_operation (GALGAS_string ("ECUC-STRING-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 679)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_stringParametersPath_22325, var_stringParameters_22289, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 680)) ;
  cEnumerator_arxmlElementValueList enumerator_22546 (var_stringParameters_22289, kENUMERATION_UP) ;
  while (enumerator_22546.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_22597 ;
    GALGAS_impType var_type_22628 ;
    {
    routine_arxmlImplementationContainerString_21__21__3F__3F__3F_ (var_attributeName_22597, var_type_22628, GALGAS_dataType::class_func_string (SOURCE_FILE ("arxml_parser.galgas", 687)), enumerator_22546.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 685)) ;
    }
    {
    routine_arxmlInsertObjectAttribute_26__3F__3F_ (ioArgument_objectAttributes, var_attributeName_22597, var_type_22628, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 690)) ;
    }
    enumerator_22546.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_booleanParameters_23164 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 696)) ;
  GALGAS_stringlist var_booleanParametersPath_23201 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 697)) ;
  var_booleanParametersPath_23201.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 698)) ;
  var_booleanParametersPath_23201.addAssign_operation (GALGAS_string ("ECUC-BOOLEAN-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 699)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_booleanParametersPath_23201, var_booleanParameters_23164, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 700)) ;
  cEnumerator_arxmlElementValueList enumerator_23428 (var_booleanParameters_23164, kENUMERATION_UP) ;
  while (enumerator_23428.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_23480 ;
    GALGAS_impType var_type_23511 ;
    {
    routine_arxmlImplementationContainerBoolean_21__21__3F__3F__3F_ (var_attributeName_23480, var_type_23511, GALGAS_dataType::class_func_boolean (SOURCE_FILE ("arxml_parser.galgas", 707)), enumerator_23428.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 705)) ;
    }
    {
    routine_arxmlInsertObjectAttribute_26__3F__3F_ (ioArgument_objectAttributes, var_attributeName_23480, var_type_23511, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 710)) ;
    }
    enumerator_23428.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_enumParameters_24050 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 716)) ;
  GALGAS_stringlist var_enumParametersPath_24084 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 717)) ;
  var_enumParametersPath_24084.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 718)) ;
  var_enumParametersPath_24084.addAssign_operation (GALGAS_string ("ECUC-ENUMERATION-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 719)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_enumParametersPath_24084, var_enumParameters_24050, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 720)) ;
  cEnumerator_arxmlElementValueList enumerator_24300 (var_enumParameters_24050, kENUMERATION_UP) ;
  while (enumerator_24300.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_24349 ;
    GALGAS_impType var_type_24380 ;
    {
    routine_arxmlImplementationContainerEnumeration_21__21__3F__3F__3F_ (var_attributeName_24349, var_type_24380, GALGAS_dataType::class_func_enumeration (SOURCE_FILE ("arxml_parser.galgas", 727)), enumerator_24300.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 725)) ;
    }
    {
    routine_arxmlInsertObjectAttribute_26__3F__3F_ (ioArgument_objectAttributes, var_attributeName_24349, var_type_24380, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 730)) ;
    }
    enumerator_24300.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_structParameters_24945 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 736)) ;
  GALGAS_stringlist var_structParametersPath_24981 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 737)) ;
  var_structParametersPath_24981.addAssign_operation (GALGAS_string ("SUB-CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 738)) ;
  var_structParametersPath_24981.addAssign_operation (GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 739)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_structParametersPath_24981, var_structParameters_24945, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 740)) ;
  cEnumerator_arxmlElementValueList enumerator_25214 (var_structParameters_24945, kENUMERATION_UP) ;
  while (enumerator_25214.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_25265 ;
    GALGAS_impType var_type_25296 ;
    {
    routine_arxmlImplementationContainerStructure_21__21__3F__3F__3F_ (var_attributeName_25265, var_type_25296, GALGAS_dataType::class_func_structType (SOURCE_FILE ("arxml_parser.galgas", 747)), enumerator_25214.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 745)) ;
    }
    {
    routine_arxmlInsertObjectAttribute_26__3F__3F_ (ioArgument_objectAttributes, var_attributeName_25265, var_type_25296, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 750)) ;
    }
    enumerator_25214.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_identParameters_25854 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 756)) ;
  GALGAS_stringlist var_identParametersPath_25889 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 757)) ;
  var_identParametersPath_25889.addAssign_operation (GALGAS_string ("REFERENCES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 758)) ;
  var_identParametersPath_25889.addAssign_operation (GALGAS_string ("TPL-IDENTIFIER-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 759)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_identParametersPath_25889, var_identParameters_25854, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 760)) ;
  cEnumerator_arxmlElementValueList enumerator_26102 (var_identParameters_25854, kENUMERATION_UP) ;
  while (enumerator_26102.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_26152 ;
    GALGAS_impType var_type_26183 ;
    {
    routine_arxmlImplementationContainerIdentifier_21__21__3F__3F__3F_ (var_attributeName_26152, var_type_26183, GALGAS_dataType::class_func_identifier (SOURCE_FILE ("arxml_parser.galgas", 767)), enumerator_26102.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 765)) ;
    }
    {
    routine_arxmlInsertObjectAttribute_26__3F__3F_ (ioArgument_objectAttributes, var_attributeName_26152, var_type_26183, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 770)) ;
    }
    enumerator_26102.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_refParameters_26745 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 776)) ;
  GALGAS_stringlist var_refParametersPath_26778 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 777)) ;
  var_refParametersPath_26778.addAssign_operation (GALGAS_string ("REFERENCES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 778)) ;
  var_refParametersPath_26778.addAssign_operation (GALGAS_string ("ECUC-REFERENCE-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 779)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_refParametersPath_26778, var_refParameters_26745, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 780)) ;
  cEnumerator_arxmlElementValueList enumerator_26981 (var_refParameters_26745, kENUMERATION_UP) ;
  while (enumerator_26981.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_27029 ;
    GALGAS_impType var_type_27060 ;
    {
    routine_arxmlImplementationContainerReference_21__21__3F__3F__3F_ (var_attributeName_27029, var_type_27060, GALGAS_dataType::class_func_objectType (SOURCE_FILE ("arxml_parser.galgas", 787)), enumerator_26981.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 785)) ;
    }
    {
    routine_arxmlInsertObjectAttribute_26__3F__3F_ (ioArgument_objectAttributes, var_attributeName_27029, var_type_27060, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 790)) ;
    }
    enumerator_26981.gotoNextObject () ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerNumber!!???'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerNumber_21__21__3F__3F__3F_ (GALGAS_lstring & outArgument_objectName,
                                                                     GALGAS_impType & outArgument_options,
                                                                     const GALGAS_dataType constinArgument_iType,
                                                                     GALGAS_arxmlElementValue inArgument_parameter,
                                                                     GALGAS_lstring /* inArgument_parentPath */,
                                                                     Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_dataType var_type_27685 = constinArgument_iType ;
  {
  routine_arxmlGetName_3F__21_ (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 806)) ;
  }
  GALGAS_lbool var_multiple_27839 ;
  {
  routine_arxmlGetMultiplicity_3F__3F__21_ (inArgument_parameter, outArgument_objectName, var_multiple_27839, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 809)) ;
  }
  GALGAS_bool var_withAuto_27905 ;
  {
  routine_arxmlGetWithAuto_3F__21_ (inArgument_parameter, var_withAuto_27905, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 812)) ;
  }
  GALGAS_lstring var_oil_5F_desc_27994 ;
  {
  routine_arxmlGetDescription_3F__21_ (inArgument_parameter, var_oil_5F_desc_27994, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 815)) ;
  }
  GALGAS_attributeRange var_range_28151 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    GALGAS_bool test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MIN"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 821)) ;
    if (kBoolTrue == test_1.boolEnum ()) {
      test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MAX"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 821)) ;
    }
    test_0 = test_1.boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_min_28243 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MIN"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 822)) ;
      GALGAS_lstring var_max_28300 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MAX"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 823)) ;
      GALGAS_string var_minSignString_28356 = GALGAS_string::makeEmptyString () ;
      GALGAS_string var_maxSignString_28387 = GALGAS_string::makeEmptyString () ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, var_max_28300.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 827)).objectCompare (GALGAS_string ("INF"))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_max_28300.setter_setString (GALGAS_sint_36__34_::class_func_max (SOURCE_FILE ("arxml_parser.galgas", 828)).getter_string (SOURCE_FILE ("arxml_parser.galgas", 828)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 828)) ;
        }
      }
      GALGAS_bool var_minSign_28542 ;
      {
      routine_arxmlPopSign_26__21_ (var_min_28243, var_minSign_28542, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 831)) ;
      }
      GALGAS_bool var_maxSign_28585 ;
      {
      routine_arxmlPopSign_26__21_ (var_max_28300, var_maxSign_28585, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 832)) ;
      }
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = var_minSign_28542.boolEnum () ;
        if (kBoolTrue == test_3) {
          var_minSignString_28356 = GALGAS_string ("-") ;
          var_type_27685 = GALGAS_dataType::class_func_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 837)) ;
        }
      }
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = var_maxSign_28585.boolEnum () ;
        if (kBoolTrue == test_4) {
          var_maxSignString_28387 = GALGAS_string ("-") ;
          var_type_27685 = GALGAS_dataType::class_func_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 841)) ;
        }
      }
      {
      routine_displayOil_3F_ (GALGAS_string ("    ").add_operation (extensionGetter_oilType (var_type_27685, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 843)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 843)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 843)) ;
      }
      {
      routine_displayOil_3F_ (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 844)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 844)) ;
      }
      GALGAS_object_5F_t var_start_28934 ;
      GALGAS_object_5F_t var_stop_28958 ;
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        GALGAS_bool test_6 = GALGAS_bool (kIsEqual, var_type_27685.objectCompare (GALGAS_dataType::class_func_uint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 849)))) ;
        if (kBoolTrue != test_6.boolEnum ()) {
          test_6 = GALGAS_bool (kIsEqual, var_type_27685.objectCompare (GALGAS_dataType::class_func_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 849)))) ;
        }
        test_5 = test_6.boolEnum () ;
        if (kBoolTrue == test_5) {
          GALGAS_luint_36__34_ var_minVal_29060 = GALGAS_luint_36__34_::class_func_new (var_min_28243.readProperty_string ().getter_decimalUnsigned_36__34_Number (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 851)), var_min_28243.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 850)) ;
          GALGAS_luint_36__34_ var_maxVal_29242 = GALGAS_luint_36__34_::class_func_new (var_max_28300.readProperty_string ().getter_decimalUnsigned_36__34_Number (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 855)), var_max_28300.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 854)) ;
          {
          routine_displayOil_3F_ (GALGAS_string ("[").add_operation (var_minSignString_28356, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 858)).add_operation (var_minVal_29060.readProperty_uint_36__34_ ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 858)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 858)).add_operation (GALGAS_string (" .. "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 858)).add_operation (var_maxSignString_28387, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 859)).add_operation (var_maxVal_29242.readProperty_uint_36__34_ ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 859)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 859)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 859)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 858)) ;
          }
          var_start_28934 = function_checkAndGetIntegerNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 860)), var_type_27685, var_minVal_29060, var_minSign_28542, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 860)) ;
          var_stop_28958 = function_checkAndGetIntegerNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 861)), var_type_27685, var_maxVal_29242, var_maxSign_28585, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 861)) ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_7 = kBoolTrue ;
        if (kBoolTrue == test_7) {
          test_7 = GALGAS_bool (kIsEqual, var_type_27685.objectCompare (GALGAS_dataType::class_func_floatNumber (SOURCE_FILE ("arxml_parser.galgas", 862)))).boolEnum () ;
          if (kBoolTrue == test_7) {
            GALGAS_ldouble var_minVal_29748 = GALGAS_ldouble::class_func_new (var_min_28243.readProperty_string ().getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 864)), var_min_28243.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 863)) ;
            GALGAS_ldouble var_maxVal_29919 = GALGAS_ldouble::class_func_new (var_max_28300.readProperty_string ().getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 868)), var_max_28300.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 867)) ;
            {
            routine_displayOil_3F_ (GALGAS_string ("[").add_operation (var_minVal_29748.readProperty_double ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 871)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 871)).add_operation (GALGAS_string (" .. "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 871)).add_operation (var_maxVal_29919.readProperty_double ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 871)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 871)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 871)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 871)) ;
            }
            var_start_28934 = function_checkAndGetFloatNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 872)), var_type_27685, var_minVal_29748, var_minSign_28542, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 872)) ;
            var_stop_28958 = function_checkAndGetFloatNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 873)), var_type_27685, var_maxVal_29919, var_maxSign_28585, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 873)) ;
          }
        }
        if (kBoolFalse == test_7) {
          TC_Array <C_FixItDescription> fixItArray8 ;
          inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 875)), GALGAS_string ("Internal error"), fixItArray8  COMMA_SOURCE_FILE ("arxml_parser.galgas", 875)) ;
          var_start_28934.drop () ; // Release error dropped variable
          var_stop_28958.drop () ; // Release error dropped variable
        }
      }
      var_range_28151 = function_buildRange (var_type_27685, var_start_28934, var_stop_28958, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 877)) ;
    }
  }
  if (kBoolFalse == test_0) {
    {
    routine_displayOil_3F_ (GALGAS_string ("    ").add_operation (extensionGetter_oilType (var_type_27685, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 879)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 879)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 879)) ;
    }
    {
    routine_displayOil_3F_ (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 880)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 880)) ;
    }
    var_range_28151 = GALGAS_noRange::class_func_new (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 881)) ;
  }
  GALGAS_object_5F_t var_defaultValue_30590 ;
  enumGalgasBool test_9 = kBoolTrue ;
  if (kBoolTrue == test_9) {
    test_9 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 886)).boolEnum () ;
    if (kBoolTrue == test_9) {
      GALGAS_lstring var_value_30666 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 887)) ;
      GALGAS_bool var_sign_30788 ;
      {
      routine_arxmlPopSign_26__21_ (var_value_30666, var_sign_30788, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 890)) ;
      }
      enumGalgasBool test_10 = kBoolTrue ;
      if (kBoolTrue == test_10) {
        GALGAS_bool test_11 = GALGAS_bool (kIsEqual, var_type_27685.objectCompare (GALGAS_dataType::class_func_uint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 893)))) ;
        if (kBoolTrue != test_11.boolEnum ()) {
          test_11 = GALGAS_bool (kIsEqual, var_type_27685.objectCompare (GALGAS_dataType::class_func_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 893)))) ;
        }
        test_10 = test_11.boolEnum () ;
        if (kBoolTrue == test_10) {
          GALGAS_luint_36__34_ var_integerValue_30962 = GALGAS_luint_36__34_::class_func_new (var_value_30666.readProperty_string ().getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 895)).getter_uint_36__34_ (SOURCE_FILE ("arxml_parser.galgas", 895)), var_value_30666.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 894)) ;
          {
          routine_displayOil_3F_ (GALGAS_string (" = ").add_operation (var_integerValue_30962.readProperty_uint_36__34_ ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 897)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 897)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 897)) ;
          }
          var_defaultValue_30590 = function_checkAndGetIntegerNumber (var_oil_5F_desc_27994, var_type_27685, var_integerValue_30962, var_sign_30788, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 898)) ;
        }
      }
      if (kBoolFalse == test_10) {
        enumGalgasBool test_12 = kBoolTrue ;
        if (kBoolTrue == test_12) {
          test_12 = GALGAS_bool (kIsEqual, var_type_27685.objectCompare (GALGAS_dataType::class_func_floatNumber (SOURCE_FILE ("arxml_parser.galgas", 902)))).boolEnum () ;
          if (kBoolTrue == test_12) {
            GALGAS_ldouble var_floatValue_31443 = GALGAS_ldouble::class_func_new (var_value_30666.readProperty_string ().getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 904)), var_value_30666.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 903)) ;
            {
            routine_displayOil_3F_ (GALGAS_string (" = ").add_operation (var_floatValue_31443.readProperty_double ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 906)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 906)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 906)) ;
            }
            var_defaultValue_30590 = function_checkAndGetFloatNumber (var_oil_5F_desc_27994, var_type_27685, var_floatValue_31443, var_sign_30788, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 907)) ;
          }
        }
        if (kBoolFalse == test_12) {
          TC_Array <C_FixItDescription> fixItArray13 ;
          inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 912)), GALGAS_string ("Internal error"), fixItArray13  COMMA_SOURCE_FILE ("arxml_parser.galgas", 912)) ;
          var_defaultValue_30590.drop () ; // Release error dropped variable
        }
      }
    }
  }
  if (kBoolFalse == test_9) {
    enumGalgasBool test_14 = kBoolTrue ;
    if (kBoolTrue == test_14) {
      test_14 = var_withAuto_27905.boolEnum () ;
      if (kBoolTrue == test_14) {
        var_defaultValue_30590 = GALGAS_auto::class_func_new (var_oil_5F_desc_27994, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 915)) ;
      }
    }
    if (kBoolFalse == test_14) {
      var_defaultValue_30590 = GALGAS_void::class_func_new (var_oil_5F_desc_27994, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 917)) ;
    }
  }
  {
  routine_displayOil_3F_ (GALGAS_string (": \"").add_operation (var_oil_5F_desc_27994.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 919)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 919)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 919)) ;
  }
  GALGAS_locationList temp_15 = GALGAS_locationList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 922)) ;
  temp_15.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 922)) ;
  GALGAS_lstringlist temp_16 = GALGAS_lstringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 926)) ;
  temp_16.addAssign_operation (var_oil_5F_desc_27994  COMMA_SOURCE_FILE ("arxml_parser.galgas", 926)) ;
  outArgument_options = GALGAS_impRangedType::class_func_new (temp_15, var_type_27685, outArgument_objectName, var_multiple_27839.readProperty_bool (), temp_16, var_withAuto_27905, var_defaultValue_30590, var_range_28151  COMMA_SOURCE_FILE ("arxml_parser.galgas", 922)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerString!!???'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerString_21__21__3F__3F__3F_ (GALGAS_lstring & outArgument_objectName,
                                                                     GALGAS_impType & outArgument_options,
                                                                     const GALGAS_dataType constinArgument_type,
                                                                     GALGAS_arxmlElementValue inArgument_parameter,
                                                                     GALGAS_lstring /* inArgument_parentPath */,
                                                                     Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil_3F_ (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 939)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 939)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 939)) ;
  }
  {
  routine_arxmlGetName_3F__21_ (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 942)) ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 943)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 943)) ;
  }
  GALGAS_lbool var_multiple_32874 ;
  {
  routine_arxmlGetMultiplicity_3F__3F__21_ (inArgument_parameter, outArgument_objectName, var_multiple_32874, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 946)) ;
  }
  GALGAS_bool var_withAuto_32940 ;
  {
  routine_arxmlGetWithAuto_3F__21_ (inArgument_parameter, var_withAuto_32940, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 949)) ;
  }
  GALGAS_lstring var_oil_5F_desc_33029 ;
  {
  routine_arxmlGetDescription_3F__21_ (inArgument_parameter, var_oil_5F_desc_33029, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 952)) ;
  }
  GALGAS_object_5F_t var_defaultValue_33075 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 957)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_value_33155 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 958)) ;
      {
      routine_displayOil_3F_ (GALGAS_string (" = \"").add_operation (var_value_33155.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 959)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 959)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 959)) ;
      }
      var_defaultValue_33075 = GALGAS_stringAttribute::class_func_new (var_oil_5F_desc_33029, var_value_33155.readProperty_location (), var_value_33155.readProperty_string ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 960)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_withAuto_32940.boolEnum () ;
      if (kBoolTrue == test_1) {
        var_defaultValue_33075 = GALGAS_auto::class_func_new (var_oil_5F_desc_33029, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 966)) ;
      }
    }
    if (kBoolFalse == test_1) {
      var_defaultValue_33075 = GALGAS_void::class_func_new (var_oil_5F_desc_33029, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 968)) ;
    }
  }
  {
  routine_displayOil_3F_ (GALGAS_string (": \"").add_operation (var_oil_5F_desc_33029.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 970)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 970)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 970)) ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 974)) ;
  temp_2.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 974)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 978)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_33029  COMMA_SOURCE_FILE ("arxml_parser.galgas", 978)) ;
  outArgument_options = GALGAS_impAutoDefaultType::class_func_new (temp_2, constinArgument_type, outArgument_objectName, var_multiple_32874.readProperty_bool (), temp_3, var_withAuto_32940, var_defaultValue_33075  COMMA_SOURCE_FILE ("arxml_parser.galgas", 973)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerBoolean!!???'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerBoolean_21__21__3F__3F__3F_ (GALGAS_lstring & outArgument_objectName,
                                                                      GALGAS_impType & outArgument_options,
                                                                      const GALGAS_dataType constinArgument_type,
                                                                      GALGAS_arxmlElementValue inArgument_parameter,
                                                                      GALGAS_lstring inArgument_parentPath,
                                                                      Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil_3F_ (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 991)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 991)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 991)) ;
  }
  {
  routine_arxmlGetName_3F__21_ (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 994)) ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 995)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 995)) ;
  }
  GALGAS_bool var_withAuto_34510 ;
  {
  routine_arxmlGetWithAuto_3F__21_ (inArgument_parameter, var_withAuto_34510, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 998)) ;
  }
  GALGAS_lbool var_multiple_34604 ;
  {
  routine_arxmlGetMultiplicity_3F__3F__21_ (inArgument_parameter, outArgument_objectName, var_multiple_34604, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1001)) ;
  }
  GALGAS_lstring var_oil_5F_desc_34693 ;
  {
  routine_arxmlGetDescription_3F__21_ (inArgument_parameter, var_oil_5F_desc_34693, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1004)) ;
  }
  GALGAS_object_5F_t var_defaultValue_34738 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1008)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_value_34818 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1009)) ;
      GALGAS_bool var_booleanValue_34888 ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        GALGAS_bool test_2 = GALGAS_bool (kIsEqual, var_value_34818.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1011)).objectCompare (GALGAS_string ("TRUE"))) ;
        if (kBoolTrue != test_2.boolEnum ()) {
          test_2 = GALGAS_bool (kIsEqual, var_value_34818.readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
        }
        test_1 = test_2.boolEnum () ;
        if (kBoolTrue == test_1) {
          var_booleanValue_34888 = GALGAS_bool (true) ;
        }
      }
      if (kBoolFalse == test_1) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          GALGAS_bool test_4 = GALGAS_bool (kIsEqual, var_value_34818.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1014)).objectCompare (GALGAS_string ("FALSE"))) ;
          if (kBoolTrue != test_4.boolEnum ()) {
            test_4 = GALGAS_bool (kIsEqual, var_value_34818.readProperty_string ().objectCompare (GALGAS_string ("0"))) ;
          }
          test_3 = test_4.boolEnum () ;
          if (kBoolTrue == test_3) {
            var_booleanValue_34888 = GALGAS_bool (false) ;
          }
        }
        if (kBoolFalse == test_3) {
          var_booleanValue_34888 = GALGAS_bool (false) ;
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (var_value_34818.readProperty_location (), GALGAS_string ("A Boolean must be 'true', 'false', '0' or '1'"), fixItArray5  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1019)) ;
        }
      }
      {
      routine_displayOil_3F_ (GALGAS_string (" = ").add_operation (var_booleanValue_34888.getter_cString (SOURCE_FILE ("arxml_parser.galgas", 1021)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1021)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1021)) ;
      }
      var_defaultValue_34738 = GALGAS_boolAttribute::class_func_new (var_oil_5F_desc_34693, var_value_34818.readProperty_location (), var_booleanValue_34888, GALGAS_objectAttributes::class_func_new (GALGAS_identifierMap::class_func_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1028))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1026))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1022)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_6 = kBoolTrue ;
    if (kBoolTrue == test_6) {
      test_6 = var_withAuto_34510.boolEnum () ;
      if (kBoolTrue == test_6) {
        var_defaultValue_34738 = GALGAS_auto::class_func_new (var_oil_5F_desc_34693, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1032)) ;
      }
    }
    if (kBoolFalse == test_6) {
      var_defaultValue_34738 = GALGAS_void::class_func_new (var_oil_5F_desc_34693, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1034)) ;
    }
  }
  GALGAS_implementationObjectMap var_structAttributes_36004 = GALGAS_implementationObjectMap::class_func_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1040)) ;
  enumGalgasBool test_7 = kBoolTrue ;
  if (kBoolTrue == test_7) {
    test_7 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SUB-CONTAINERS"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1041)).boolEnum () ;
    if (kBoolTrue == test_7) {
      {
      routine_displayOil_3F_ (GALGAS_string ("\n    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1042)) ;
      }
      {
      routine_arxmlImplementationContainer_26__3F__3F_ (var_structAttributes_36004, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1043)) ;
      }
      {
      routine_displayOil_3F_ (GALGAS_string ("\n    } : \"").add_operation (var_oil_5F_desc_34693.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1044)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1044)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1044)) ;
      }
    }
  }
  if (kBoolFalse == test_7) {
    {
    routine_displayOil_3F_ (GALGAS_string (" : \"").add_operation (var_oil_5F_desc_34693.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1046)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1046)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1046)) ;
    }
  }
  GALGAS_locationList temp_8 = GALGAS_locationList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1051)) ;
  temp_8.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1051)) ;
  GALGAS_lstringlist temp_9 = GALGAS_lstringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1055)) ;
  temp_9.addAssign_operation (var_oil_5F_desc_34693  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1055)) ;
  outArgument_options = GALGAS_impBoolType::class_func_new (temp_8, constinArgument_type, outArgument_objectName, var_multiple_34604.readProperty_bool (), temp_9, var_withAuto_34510, var_defaultValue_34738, var_structAttributes_36004, var_structAttributes_36004  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1050)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerEnumeration!!???'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerEnumeration_21__21__3F__3F__3F_ (GALGAS_lstring & outArgument_objectName,
                                                                          GALGAS_impType & outArgument_options,
                                                                          const GALGAS_dataType constinArgument_type,
                                                                          GALGAS_arxmlElementValue inArgument_parameter,
                                                                          GALGAS_lstring /* inArgument_parentPath */,
                                                                          Compiler * inCompiler
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil_3F_ (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1070)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1070)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1070)) ;
  }
  {
  routine_arxmlGetName_3F__21_ (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1073)) ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1074)).add_operation (GALGAS_string ("["), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1074)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1074)) ;
  }
  GALGAS_bool var_withAuto_37173 ;
  {
  routine_arxmlGetWithAuto_3F__21_ (inArgument_parameter, var_withAuto_37173, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1077)) ;
  }
  GALGAS_lbool var_multiple_37267 ;
  {
  routine_arxmlGetMultiplicity_3F__3F__21_ (inArgument_parameter, outArgument_objectName, var_multiple_37267, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1080)) ;
  }
  GALGAS_lstring var_oil_5F_desc_37356 ;
  {
  routine_arxmlGetDescription_3F__21_ (inArgument_parameter, var_oil_5F_desc_37356, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1083)) ;
  }
  GALGAS_enumValues var_enumValues_37446 = GALGAS_enumValues::class_func_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1087)) ;
  GALGAS_arxmlElementValueList var_enumElementValues_37507 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1088)) ;
  GALGAS_stringlist var_enumElementValuesPath_37544 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1089)) ;
  var_enumElementValuesPath_37544.addAssign_operation (GALGAS_string ("LITERALS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1090)) ;
  var_enumElementValuesPath_37544.addAssign_operation (GALGAS_string ("ECUC-ENUMERATION-LITERAL-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1091)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_parameter.ptr (), var_enumElementValuesPath_37544, var_enumElementValues_37507, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1092)) ;
  cEnumerator_arxmlElementValueList enumerator_37770 (var_enumElementValues_37507, kENUMERATION_UP) ;
  while (enumerator_37770.hasCurrentObject ()) {
    GALGAS_lstring var_enumValueName_37822 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) enumerator_37770.current_value (HERE).ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1094)) ;
    {
    var_enumValues_37446.setter_put (var_enumValueName_37822, GALGAS_implementationObjectMap::class_func_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1095)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1095)) ;
    }
    {
    routine_displayOil_3F_ (var_enumValueName_37822.readProperty_string (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1096)) ;
    }
    if (enumerator_37770.hasNextObject ()) {
      {
      routine_displayOil_3F_ (GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1098)) ;
      }
    }
    enumerator_37770.gotoNextObject () ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string ("]"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1100)) ;
  }
  GALGAS_object_5F_t var_defaultValue_38090 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1104)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_value_38170 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1105)) ;
      {
      routine_displayOil_3F_ (GALGAS_string (" = ").add_operation (var_value_38170.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1106)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1106)) ;
      }
      var_defaultValue_38090 = GALGAS_enumAttribute::class_func_new (var_oil_5F_desc_37356, var_value_38170.readProperty_location (), var_value_38170.readProperty_string (), GALGAS_objectAttributes::class_func_new (GALGAS_identifierMap::class_func_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1113))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1111))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1107)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_withAuto_37173.boolEnum () ;
      if (kBoolTrue == test_1) {
        var_defaultValue_38090 = GALGAS_auto::class_func_new (var_oil_5F_desc_37356, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1117)) ;
      }
    }
    if (kBoolFalse == test_1) {
      var_defaultValue_38090 = GALGAS_void::class_func_new (var_oil_5F_desc_37356, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1119)) ;
    }
  }
  {
  routine_displayOil_3F_ (GALGAS_string ("\n : \"").add_operation (var_oil_5F_desc_37356.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1122)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1122)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1122)) ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1126)) ;
  temp_2.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1126)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1130)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_37356  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1130)) ;
  outArgument_options = GALGAS_impEnumType::class_func_new (temp_2, constinArgument_type, outArgument_objectName, var_multiple_37267.readProperty_bool (), temp_3, var_withAuto_37173, var_defaultValue_38090, var_enumValues_37446  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1125)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerStructure!!???'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerStructure_21__21__3F__3F__3F_ (GALGAS_lstring & outArgument_objectName,
                                                                        GALGAS_impType & outArgument_options,
                                                                        const GALGAS_dataType constinArgument_type,
                                                                        GALGAS_arxmlElementValue inArgument_parameter,
                                                                        GALGAS_lstring inArgument_parentPath,
                                                                        Compiler * inCompiler
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil_3F_ (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1145)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1145)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1145)) ;
  }
  {
  routine_arxmlGetName_3F__21_ (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1148)) ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1149)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1149)) ;
  }
  GALGAS_lbool var_multiple_39724 ;
  {
  routine_arxmlGetMultiplicity_3F__3F__21_ (inArgument_parameter, outArgument_objectName, var_multiple_39724, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1152)) ;
  }
  GALGAS_lstring var_oil_5F_desc_39813 ;
  {
  routine_arxmlGetDescription_3F__21_ (inArgument_parameter, var_oil_5F_desc_39813, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1155)) ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string ("\n    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1157)) ;
  }
  GALGAS_implementationObjectMap var_structAttributes_39880 = GALGAS_implementationObjectMap::class_func_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1160)) ;
  {
  routine_arxmlImplementationContainer_26__3F__3F_ (var_structAttributes_39880, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1161)) ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string ("\n    } : \"").add_operation (var_oil_5F_desc_39813.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1163)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1163)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1163)) ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1167)) ;
  temp_0.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1167)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1171)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_39813  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1171)) ;
  outArgument_options = GALGAS_impStructType::class_func_new (temp_0, constinArgument_type, outArgument_objectName, var_multiple_39724.readProperty_bool (), temp_1, var_structAttributes_39880  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1166)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerIdentifier!!???'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerIdentifier_21__21__3F__3F__3F_ (GALGAS_lstring & outArgument_objectName,
                                                                         GALGAS_impType & outArgument_options,
                                                                         const GALGAS_dataType constinArgument_type,
                                                                         GALGAS_arxmlElementValue inArgument_parameter,
                                                                         GALGAS_lstring /* inArgument_parentPath */,
                                                                         Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil_3F_ (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1183)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1183)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1183)) ;
  }
  {
  routine_arxmlGetName_3F__21_ (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1186)) ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1187)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1187)) ;
  }
  GALGAS_lbool var_multiple_40815 ;
  {
  routine_arxmlGetMultiplicity_3F__3F__21_ (inArgument_parameter, outArgument_objectName, var_multiple_40815, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1190)) ;
  }
  GALGAS_bool var_withAuto_40881 ;
  {
  routine_arxmlGetWithAuto_3F__21_ (inArgument_parameter, var_withAuto_40881, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1193)) ;
  }
  GALGAS_lstring var_oil_5F_desc_40970 ;
  {
  routine_arxmlGetDescription_3F__21_ (inArgument_parameter, var_oil_5F_desc_40970, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1196)) ;
  }
  GALGAS_object_5F_t var_defaultValue_41015 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1200)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_value_41095 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1201)) ;
      {
      routine_displayOil_3F_ (GALGAS_string (" = ").add_operation (var_value_41095.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1202)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1202)) ;
      }
      var_defaultValue_41015 = GALGAS_stringAttribute::class_func_new (var_oil_5F_desc_40970, var_value_41095.readProperty_location (), var_value_41095.readProperty_string ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1203)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_withAuto_40881.boolEnum () ;
      if (kBoolTrue == test_1) {
        var_defaultValue_41015 = GALGAS_auto::class_func_new (var_oil_5F_desc_40970, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1209)) ;
      }
    }
    if (kBoolFalse == test_1) {
      var_defaultValue_41015 = GALGAS_void::class_func_new (var_oil_5F_desc_40970, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1211)) ;
    }
  }
  {
  routine_displayOil_3F_ (GALGAS_string (": \"").add_operation (var_oil_5F_desc_40970.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1213)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1213)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1213)) ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1217)) ;
  temp_2.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1217)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1221)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_40970  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1221)) ;
  outArgument_options = GALGAS_impAutoDefaultType::class_func_new (temp_2, constinArgument_type, outArgument_objectName, var_multiple_40815.readProperty_bool (), temp_3, var_withAuto_40881, var_defaultValue_41015  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1216)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerReference!!???'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerReference_21__21__3F__3F__3F_ (GALGAS_lstring & outArgument_objectName,
                                                                        GALGAS_impType & outArgument_options,
                                                                        const GALGAS_dataType constinArgument_type,
                                                                        GALGAS_arxmlElementValue inArgument_parameter,
                                                                        GALGAS_lstring /* inArgument_parentPath */,
                                                                        Compiler * inCompiler
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_lstring var_objectType_42284 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DESTINATION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1235)) ;
  var_objectType_42284.setter_setString (var_objectType_42284.readProperty_string ().getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1237)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1237)) ;
  {
  routine_displayOil_3F_ (GALGAS_string ("    ").add_operation (var_objectType_42284.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1238)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1238)) ;
  }
  {
  routine_arxmlGetName_3F__21_ (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1241)) ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string (" ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1242)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1242)) ;
  }
  GALGAS_lbool var_multiple_42708 ;
  {
  routine_arxmlGetMultiplicity_3F__3F__21_ (inArgument_parameter, outArgument_objectName, var_multiple_42708, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1245)) ;
  }
  GALGAS_lstring var_oil_5F_desc_42797 ;
  {
  routine_arxmlGetDescription_3F__21_ (inArgument_parameter, var_oil_5F_desc_42797, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1248)) ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string (": \"").add_operation (var_oil_5F_desc_42797.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1250)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1250)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1250)) ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1254)) ;
  temp_0.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1254)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1258)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_42797  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1258)) ;
  outArgument_options = GALGAS_refType::class_func_new (temp_0, constinArgument_type, outArgument_objectName, var_multiple_42708.readProperty_bool (), temp_1, var_objectType_42284  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1253)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionPackage&&??'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionPackage_26__26__3F__3F_ (GALGAS_implementation & ioArgument_imp,
                                                     GALGAS_applicationDefinition & ioArgument_application,
                                                     GALGAS_arxmlElementValue inArgument_packageElement,
                                                     GALGAS_lstring inArgument_parentPath,
                                                     Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_packageName_43450 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1274)) ;
  GALGAS_lstring var_currentPath_43563 = GALGAS_lstring::class_func_new (inArgument_parentPath.readProperty_string ().add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1277)).add_operation (var_packageName_43450.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1277)), var_packageName_43450.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1277)) ;
  GALGAS_arxmlElementValueList var_definitions_43790 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1281)) ;
  GALGAS_stringlist var_definitionPath_43821 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1282)) ;
  var_definitionPath_43821.addAssign_operation (GALGAS_string ("ELEMENTS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1283)) ;
  var_definitionPath_43821.addAssign_operation (GALGAS_string ("ECUC-MODULE-CONFIGURATION-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1284)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_definitionPath_43821, var_definitions_43790, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1285)) ;
  cEnumerator_arxmlElementValueList enumerator_44021 (var_definitions_43790, kENUMERATION_UP) ;
  while (enumerator_44021.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionRoot_26__26__3F__3F_ (ioArgument_imp, ioArgument_application, enumerator_44021.current_value (HERE), var_currentPath_43563, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1287)) ;
    }
    enumerator_44021.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_packages_44207 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1291)) ;
  GALGAS_stringlist var_packagesPath_44235 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1292)) ;
  var_packagesPath_44235.addAssign_operation (GALGAS_string ("AR-PACKAGES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1293)) ;
  var_packagesPath_44235.addAssign_operation (GALGAS_string ("AR-PACKAGE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1294)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_packagesPath_44235, var_packages_44207, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1295)) ;
  cEnumerator_arxmlElementValueList enumerator_44405 (var_packages_44207, kENUMERATION_UP) ;
  while (enumerator_44405.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionPackage_26__26__3F__3F_ (ioArgument_imp, ioArgument_application, enumerator_44405.current_value (HERE), var_currentPath_43563, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1297)) ;
    }
    enumerator_44405.gotoNextObject () ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionRoot&&??'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionRoot_26__26__3F__3F_ (GALGAS_implementation & ioArgument_imp,
                                                  GALGAS_applicationDefinition & ioArgument_application,
                                                  GALGAS_arxmlElementValue inArgument_packageElement,
                                                  GALGAS_lstring /* inArgument_parentPath */,
                                                  Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_cpuName_44697 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1308)) ;
  GALGAS_lstring var_currentPath_44807 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1311)) ;
  GALGAS_objectsMap var_objects_44926 = ioArgument_application.readProperty_objects () ;
  GALGAS_lstring var_oil_5F_desc_45042 ;
  {
  routine_arxmlGetDescription_3F__21_ (inArgument_packageElement, var_oil_5F_desc_45042, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1317)) ;
  }
  GALGAS_arxmlElementValueList var_subDefs_45105 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1320)) ;
  GALGAS_stringlist var_subDefsPath_45132 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1321)) ;
  var_subDefsPath_45132.addAssign_operation (GALGAS_string ("CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1322)) ;
  var_subDefsPath_45132.addAssign_operation (GALGAS_string ("ECUC-CONTAINER-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1323)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_subDefsPath_45132, var_subDefs_45105, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1324)) ;
  {
  routine_displayOil_3F_ (GALGAS_string ("\nCPU ").add_operation (var_cpuName_44697.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1326)).add_operation (GALGAS_string ("\n{\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1326)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1326)) ;
  }
  cEnumerator_arxmlElementValueList enumerator_45352 (var_subDefs_45105, kENUMERATION_UP) ;
  while (enumerator_45352.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionObject_26__26__3F__3F_ (ioArgument_imp, var_objects_44926, enumerator_45352.current_value (HERE), var_currentPath_44807, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1329)) ;
    }
    enumerator_45352.gotoNextObject () ;
  }
  {
  ioArgument_application.setter_setName (var_cpuName_44697 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1333)) ;
  }
  {
  ioArgument_application.setter_setObjects (var_objects_44926 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1334)) ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string ("}; /* END CPU ").add_operation (var_cpuName_44697.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1336)).add_operation (GALGAS_string (" : \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1336)).add_operation (var_oil_5F_desc_45042.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1337)).add_operation (GALGAS_string ("\" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1337)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1336)) ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionObject&&??'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionObject_26__26__3F__3F_ (GALGAS_implementation & ioArgument_imp,
                                                    GALGAS_objectsMap & ioArgument_objects,
                                                    GALGAS_arxmlElementValue inArgument_currentElement,
                                                    GALGAS_lstring inArgument_parentPath,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_currentPath_45842 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1347)) ;
  GALGAS_lstring var_objectKind_45969 ;
  {
  routine_oilEquivalentName_3F__3F__21_ (inArgument_parentPath, var_currentPath_45842, var_objectKind_45969, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1348)) ;
  }
  GALGAS_implementationObject var_impObjOfKind_46032 = callExtensionGetter_impObject ((const cPtr_implementation *) ioArgument_imp.ptr (), var_objectKind_45969.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1351)) ;
  GALGAS_objectKind var_objectsForKind_46098 = GALGAS_objectKind::class_func_new (GALGAS_objectKindMap::class_func_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1352))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1352)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = ioArgument_objects.getter_hasKey (var_objectKind_45969.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1353)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      ioArgument_objects.setter_del (var_objectKind_45969, var_objectsForKind_46098, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1354)) ;
      }
    }
  }
  GALGAS_lstring var_objectName_46295 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1358)) ;
  GALGAS_objectAttributes var_object_46411 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1361)) ;
  GALGAS_objectKindMap var_objectsKind_46451 = var_objectsForKind_46098.readProperty_objects () ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsEqual, var_impObjOfKind_46032.readProperty_multiple ().readProperty_bool ().objectCompare (GALGAS_bool (false))).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_objectName_46295 = var_objectKind_45969 ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = var_objectsKind_46451.getter_hasKey (var_objectName_46295.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1371)).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      var_objectsKind_46451.setter_del (var_objectName_46295, var_object_46411, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1372)) ;
      }
    }
  }
  GALGAS_lstring var_oil_5F_desc_47020 ;
  {
  routine_arxmlGetDescription_3F__21_ (inArgument_currentElement, var_oil_5F_desc_47020, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1376)) ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string ("  ").add_operation (var_objectKind_45969.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1378)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1378)).add_operation (var_objectName_46295.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1378)).add_operation (GALGAS_string ("\n  {\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1378)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1378)) ;
  }
  {
  routine_arxmlDefinitionContainer_3F__26__3F__3F_ (var_impObjOfKind_46032.readProperty_attributes (), var_object_46411, inArgument_currentElement, var_currentPath_45842, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1381)) ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string ("  } : \"").add_operation (var_oil_5F_desc_47020.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1386)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1386)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1386)) ;
  }
  GALGAS_identifierMap var_attributes_47413 = var_object_46411.readProperty_objectParams () ;
  enumGalgasBool test_3 = kBoolTrue ;
  if (kBoolTrue == test_3) {
    test_3 = var_attributes_47413.getter_hasKey (GALGAS_string ("NAME") COMMA_SOURCE_FILE ("arxml_parser.galgas", 1390)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 1390)).boolEnum () ;
    if (kBoolTrue == test_3) {
      {
      var_attributes_47413.setter_put (GALGAS_lstring::class_func_new (GALGAS_string ("NAME"), var_objectName_46295.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1391)), GALGAS_stringAttribute::class_func_new (var_oil_5F_desc_47020, var_objectName_46295.readProperty_location (), var_objectName_46295.readProperty_string ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1392)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1391)) ;
      }
      {
      var_object_46411.setter_setObjectParams (var_attributes_47413 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1395)) ;
      }
    }
  }
  {
  var_objectsKind_46451.setter_put (var_objectName_46295, var_object_46411, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1397)) ;
  }
  {
  var_objectsForKind_46098.setter_setObjects (var_objectsKind_46451 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1398)) ;
  }
  {
  ioArgument_objects.setter_put (var_objectKind_45969, var_objectsForKind_46098, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1399)) ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionContainer?&??'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionContainer_3F__26__3F__3F_ (const GALGAS_implementationObjectMap constinArgument_types,
                                                       GALGAS_objectAttributes & ioArgument_identifiers,
                                                       GALGAS_arxmlElementValue inArgument_currentElement,
                                                       GALGAS_lstring inArgument_currentPath,
                                                       Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList var_textParameters_48205 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1409)) ;
  GALGAS_stringlist var_textParametersPath_48239 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1410)) ;
  var_textParametersPath_48239.addAssign_operation (GALGAS_string ("PARAMETER-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1411)) ;
  var_textParametersPath_48239.addAssign_operation (GALGAS_string ("ECUC-TEXTUAL-PARAM-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1412)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_textParametersPath_48239, var_textParameters_48205, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1413)) ;
  GALGAS_arxmlElementValueList var_numParameters_48524 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1416)) ;
  GALGAS_stringlist var_numParametersPath_48557 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1417)) ;
  var_numParametersPath_48557.addAssign_operation (GALGAS_string ("PARAMETER-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1418)) ;
  var_numParametersPath_48557.addAssign_operation (GALGAS_string ("ECUC-NUMERICAL-PARAM-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1419)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_numParametersPath_48557, var_numParameters_48524, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1420)) ;
  GALGAS_arxmlElementValueList var_refParameters_48810 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1423)) ;
  GALGAS_stringlist var_refParametersPath_48843 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1424)) ;
  var_refParametersPath_48843.addAssign_operation (GALGAS_string ("REFERENCE-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1425)) ;
  var_refParametersPath_48843.addAssign_operation (GALGAS_string ("ECUC-REFERENCE-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1426)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_refParametersPath_48843, var_refParameters_48810, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1427)) ;
  GALGAS_arxmlElementValueList var_structParameters_49090 = GALGAS_arxmlElementValueList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1430)) ;
  GALGAS_stringlist var_structParametersPath_49126 = GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1431)) ;
  var_structParametersPath_49126.addAssign_operation (GALGAS_string ("SUB-CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1432)) ;
  var_structParametersPath_49126.addAssign_operation (GALGAS_string ("ECUC-CONTAINER-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1433)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_structParametersPath_49126, var_structParameters_49090, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1434)) ;
  GALGAS_arxmlElementValueList var_allParameters_49380 = var_numParameters_48524.add_operation (var_textParameters_48205, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1437)).add_operation (var_refParameters_48810, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1438)).add_operation (var_structParameters_49090, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1439)) ;
  cEnumerator_arxmlElementValueList enumerator_49644 (var_allParameters_49380, kENUMERATION_UP) ;
  while (enumerator_49644.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionParameter_3F__26__3F__3F_ (constinArgument_types, ioArgument_identifiers, enumerator_49644.current_value (HERE), inArgument_currentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1444)) ;
    }
    enumerator_49644.gotoNextObject () ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionParameter?&??'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionParameter_3F__26__3F__3F_ (const GALGAS_implementationObjectMap constinArgument_types,
                                                       GALGAS_objectAttributes & ioArgument_identifiers,
                                                       GALGAS_arxmlElementValue inArgument_parameter,
                                                       GALGAS_lstring inArgument_parentPath,
                                                       Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t var_val_49953 ;
  GALGAS_lstring var_parameterPath_49972 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1456)) ;
  GALGAS_lstring var_parameterType_50094 ;
  {
  routine_oilEquivalentName_3F__3F__21_ (inArgument_parentPath, var_parameterPath_49972, var_parameterType_50094, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1457)) ;
  }
  GALGAS_bool var_typeOk_50142 = GALGAS_bool (false) ;
  GALGAS_locationList temp_0 = GALGAS_locationList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1461)) ;
  temp_0.addAssign_operation (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1461))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1461)) ;
  GALGAS_impType var_type_50168 = GALGAS_impVoid::class_func_new (temp_0, GALGAS_dataType::class_func_void (SOURCE_FILE ("arxml_parser.galgas", 1463)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1463)), GALGAS_bool (false), GALGAS_lstringlist::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1465))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1461)) ;
  GALGAS_lstring var_valueType_50439 = callExtensionGetter_getAttributeValueFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFINITION-REF"), GALGAS_string ("DEST"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1467)) ;
  GALGAS_lstring var_oil_5F_desc_50633 = GALGAS_lstring::class_func_new (GALGAS_string::makeEmptyString (), GALGAS_location::class_func_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1472)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1472)) ;
  GALGAS_bool var_isAuto_50791 = GALGAS_bool (false) ;
  GALGAS_lstring var_parameterValue_50817 ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1479)).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_parameterValue_50817 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1483)) ;
    }
  }
  if (kBoolFalse == test_1) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1484)).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_parameterValue_50817 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1488)) ;
        var_parameterValue_50817.setter_setString (var_parameterValue_50817.readProperty_string ().getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1490)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1490)) ;
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, var_parameterType_50094.readProperty_string ().getter_rightSubString (GALGAS_uint (uint32_t (3U)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1492)).objectCompare (GALGAS_string ("REF"))).boolEnum () ;
          if (kBoolTrue == test_3) {
            var_parameterType_50094.setter_setString (var_parameterType_50094.readProperty_string ().getter_leftSubString (var_parameterType_50094.readProperty_string ().getter_count (SOURCE_FILE ("arxml_parser.galgas", 1494)).substract_operation (GALGAS_uint (uint32_t (3U)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1494)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1493)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1493)) ;
          }
        }
        if (kBoolFalse == test_3) {
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsEqual, var_parameterType_50094.readProperty_string ().getter_rightSubString (GALGAS_uint (uint32_t (4U)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1495)).objectCompare (GALGAS_string ("REFS"))).boolEnum () ;
            if (kBoolTrue == test_4) {
              var_parameterType_50094.setter_setString (var_parameterType_50094.readProperty_string ().getter_leftSubString (var_parameterType_50094.readProperty_string ().getter_count (SOURCE_FILE ("arxml_parser.galgas", 1497)).substract_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1497)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1496)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1496)) ;
            }
          }
          if (kBoolFalse == test_4) {
            TC_Array <C_FixItDescription> fixItArray5 ;
            inCompiler->emitSemanticError (var_parameterType_50094.readProperty_location (), GALGAS_string ("An object reference must end with REF or REFS"), fixItArray5  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1499)) ;
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
          var_parameterValue_50817 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1506)) ;
        }
      }
      if (kBoolFalse == test_6) {
        enumGalgasBool test_8 = kBoolTrue ;
        if (kBoolTrue == test_8) {
          test_8 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("IS-AUTO-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1507)).boolEnum () ;
          if (kBoolTrue == test_8) {
            var_parameterValue_50817 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("IS-AUTO-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1511)) ;
            enumGalgasBool test_9 = kBoolTrue ;
            if (kBoolTrue == test_9) {
              GALGAS_bool test_10 = GALGAS_bool (kIsEqual, var_parameterValue_50817.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1512)).objectCompare (GALGAS_string ("TRUE"))) ;
              if (kBoolTrue != test_10.boolEnum ()) {
                test_10 = GALGAS_bool (kIsEqual, var_parameterValue_50817.readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
              }
              test_9 = test_10.boolEnum () ;
              if (kBoolTrue == test_9) {
                var_isAuto_50791 = GALGAS_bool (true) ;
              }
            }
          }
        }
        if (kBoolFalse == test_8) {
          TC_Array <C_FixItDescription> fixItArray11 ;
          inCompiler->emitSemanticError (var_parameterType_50094.readProperty_location (), GALGAS_string ("No value has been found."), fixItArray11  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1517)) ;
          var_parameterValue_50817.drop () ; // Release error dropped variable
        }
      }
    }
  }
  enumGalgasBool test_12 = kBoolTrue ;
  if (kBoolTrue == test_12) {
    test_12 = constinArgument_types.getter_hasKey (var_parameterType_50094.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1521)).boolEnum () ;
    if (kBoolTrue == test_12) {
      constinArgument_types.method_get (var_parameterType_50094, var_type_50168, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1522)) ;
      var_typeOk_50142 = GALGAS_bool (true) ;
      {
      routine_testTypeError_3F__3F_ (var_type_50168.readProperty_type (), var_valueType_50439, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1525)) ;
      }
    }
  }
  if (kBoolFalse == test_12) {
    TC_Array <C_FixItDescription> fixItArray13 ;
    inCompiler->emitSemanticError (var_parameterType_50094.readProperty_location (), var_parameterType_50094.readProperty_string ().add_operation (GALGAS_string (" is not declared in the "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1527)).add_operation (GALGAS_string ("IMPLEMENTATION."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1527)), fixItArray13  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1527)) ;
  }
  {
  routine_displayOil_3F_ (GALGAS_string ("    ").add_operation (var_parameterType_50094.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1531)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1531)) ;
  }
  GALGAS_implementationObjectMap var_subTypes_53409 = GALGAS_implementationObjectMap::class_func_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1533)) ;
  GALGAS_objectAttributes var_subAttributes_53477 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1534)) ;
  enumGalgasBool test_14 = kBoolTrue ;
  if (kBoolTrue == test_14) {
    test_14 = var_isAuto_50791.boolEnum () ;
    if (kBoolTrue == test_14) {
      {
      routine_displayOil_3F_ (GALGAS_string (" = AUTO;"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1543)) ;
      }
      enumGalgasBool test_15 = kBoolTrue ;
      if (kBoolTrue == test_15) {
        test_15 = callExtensionGetter_autoAllowed ((const cPtr_impType *) var_type_50168.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1544)).boolEnum () ;
        if (kBoolTrue == test_15) {
          var_val_49953 = GALGAS_auto::class_func_new (var_oil_5F_desc_50633, var_parameterValue_50817.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1545)) ;
        }
      }
      if (kBoolFalse == test_15) {
        TC_Array <C_FixItDescription> fixItArray16 ;
        inCompiler->emitSemanticError (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1547)), GALGAS_string ("AUTO is not allowed"), fixItArray16  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1547)) ;
        var_val_49953.drop () ; // Release error dropped variable
      }
    }
  }
  if (kBoolFalse == test_14) {
    enumGalgasBool test_17 = kBoolTrue ;
    if (kBoolTrue == test_17) {
      test_17 = GALGAS_bool (kIsEqual, var_valueType_50439.readProperty_string ().objectCompare (GALGAS_string ("ECUC-ENUMERATION-PARAM-DEF"))).boolEnum () ;
      if (kBoolTrue == test_17) {
        GALGAS_impEnumType temp_18 ;
        if (var_type_50168.isValid ()) {
          if (nullptr != dynamic_cast <const cPtr_impEnumType *> (var_type_50168.ptr ())) {
            temp_18 = (cPtr_impEnumType *) var_type_50168.ptr () ;
          }else{
            inCompiler->castError ("impEnumType", var_type_50168.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1554)) ;
          }
        }
        GALGAS_impEnumType var_enumType_54289 = temp_18 ;
        enumGalgasBool test_19 = kBoolTrue ;
        if (kBoolTrue == test_19) {
          test_19 = var_enumType_54289.readProperty_valuesMap ().getter_hasKey (var_parameterValue_50817.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1555)).boolEnum () ;
          if (kBoolTrue == test_19) {
            var_enumType_54289.readProperty_valuesMap ().method_get (var_parameterValue_50817, var_subTypes_53409, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1556)) ;
          }
        }
        if (kBoolFalse == test_19) {
          TC_Array <C_FixItDescription> fixItArray20 ;
          inCompiler->emitSemanticError (var_parameterValue_50817.readProperty_location (), var_parameterValue_50817.readProperty_string ().add_operation (GALGAS_string (" ENUM value "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1558)).add_operation (GALGAS_string ("for "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1558)).add_operation (var_parameterType_50094.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1559)).add_operation (GALGAS_string (" undeclared.\nOne of the following"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1559)).add_operation (GALGAS_string ("values are expected :\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1559)).add_operation (function_valueList (var_enumType_54289.readProperty_valuesMap (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1560)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1560)), fixItArray20  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1558)) ;
        }
        {
        routine_displayOil_3F_ (GALGAS_string (" = ").add_operation (var_parameterValue_50817.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1563)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1563)) ;
        }
        enumGalgasBool test_21 = kBoolTrue ;
        if (kBoolTrue == test_21) {
          test_21 = GALGAS_bool (kIsNotEqual, var_subTypes_53409.getter_count (SOURCE_FILE ("arxml_parser.galgas", 1564)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
          if (kBoolTrue == test_21) {
            {
            routine_displayOil_3F_ (GALGAS_string ("\n    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1565)) ;
            }
            {
            routine_arxmlDefinitionContainer_3F__26__3F__3F_ (var_subTypes_53409, var_subAttributes_53477, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1566)) ;
            }
            {
            routine_displayOil_3F_ (GALGAS_string ("    }"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1568)) ;
            }
          }
        }
        {
        routine_displayOil_3F_ (GALGAS_string (";"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1570)) ;
        }
        var_val_49953 = GALGAS_enumAttribute::class_func_new (var_oil_5F_desc_50633, var_parameterValue_50817.readProperty_location (), var_parameterValue_50817.readProperty_string (), var_subAttributes_53477  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1572)) ;
      }
    }
    if (kBoolFalse == test_17) {
      enumGalgasBool test_22 = kBoolTrue ;
      if (kBoolTrue == test_22) {
        test_22 = GALGAS_bool (kIsEqual, var_valueType_50439.readProperty_string ().objectCompare (GALGAS_string ("ECUC-BOOLEAN-PARAM-DEF"))).boolEnum () ;
        if (kBoolTrue == test_22) {
          GALGAS_impBoolType temp_23 ;
          if (var_type_50168.isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_impBoolType *> (var_type_50168.ptr ())) {
              temp_23 = (cPtr_impBoolType *) var_type_50168.ptr () ;
            }else{
              inCompiler->castError ("impBoolType", var_type_50168.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1581)) ;
            }
          }
          GALGAS_impBoolType var_boolType_55423 = temp_23 ;
          GALGAS_bool var_booleanValue_55469 ;
          enumGalgasBool test_24 = kBoolTrue ;
          if (kBoolTrue == test_24) {
            GALGAS_bool test_25 = GALGAS_bool (kIsEqual, var_parameterValue_50817.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1583)).objectCompare (GALGAS_string ("TRUE"))) ;
            if (kBoolTrue != test_25.boolEnum ()) {
              test_25 = GALGAS_bool (kIsEqual, var_parameterValue_50817.readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
            }
            test_24 = test_25.boolEnum () ;
            if (kBoolTrue == test_24) {
              var_subTypes_53409 = var_boolType_55423.readProperty_trueSubAttributes () ;
              var_booleanValue_55469 = GALGAS_bool (true) ;
            }
          }
          if (kBoolFalse == test_24) {
            enumGalgasBool test_26 = kBoolTrue ;
            if (kBoolTrue == test_26) {
              GALGAS_bool test_27 = GALGAS_bool (kIsEqual, var_parameterValue_50817.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1587)).objectCompare (GALGAS_string ("FALSE"))) ;
              if (kBoolTrue != test_27.boolEnum ()) {
                test_27 = GALGAS_bool (kIsEqual, var_parameterValue_50817.readProperty_string ().objectCompare (GALGAS_string ("0"))) ;
              }
              test_26 = test_27.boolEnum () ;
              if (kBoolTrue == test_26) {
                var_subTypes_53409 = var_boolType_55423.readProperty_falseSubAttributes () ;
                var_booleanValue_55469 = GALGAS_bool (false) ;
              }
            }
            if (kBoolFalse == test_26) {
              var_booleanValue_55469 = GALGAS_bool (false) ;
              TC_Array <C_FixItDescription> fixItArray28 ;
              inCompiler->emitSemanticError (var_parameterValue_50817.readProperty_location (), GALGAS_string ("A Boolean must be 'true', 'false', '0' or '1'"), fixItArray28  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1593)) ;
            }
          }
          {
          routine_displayOil_3F_ (GALGAS_string (" = ").add_operation (var_booleanValue_55469.getter_cString (SOURCE_FILE ("arxml_parser.galgas", 1596)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1596)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1596)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1596)) ;
          }
          enumGalgasBool test_29 = kBoolTrue ;
          if (kBoolTrue == test_29) {
            test_29 = GALGAS_bool (kIsNotEqual, var_subTypes_53409.getter_count (SOURCE_FILE ("arxml_parser.galgas", 1597)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
            if (kBoolTrue == test_29) {
              {
              routine_displayOil_3F_ (GALGAS_string ("\n    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1598)) ;
              }
              {
              routine_arxmlDefinitionContainer_3F__26__3F__3F_ (var_subTypes_53409, var_subAttributes_53477, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1599)) ;
              }
              {
              routine_displayOil_3F_ (GALGAS_string ("    }"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1601)) ;
              }
            }
          }
          {
          routine_displayOil_3F_ (GALGAS_string (";"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1603)) ;
          }
          var_val_49953 = GALGAS_boolAttribute::class_func_new (var_oil_5F_desc_50633, var_parameterType_50094.readProperty_location (), var_booleanValue_55469, var_subAttributes_53477  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1605)) ;
        }
      }
      if (kBoolFalse == test_22) {
        enumGalgasBool test_30 = kBoolTrue ;
        if (kBoolTrue == test_30) {
          test_30 = GALGAS_bool (kIsEqual, var_valueType_50439.readProperty_string ().objectCompare (GALGAS_string ("ECUC-INTEGER-PARAM-DEF"))).boolEnum () ;
          if (kBoolTrue == test_30) {
            GALGAS_bool var_sign_56716 ;
            {
            routine_arxmlPopSign_26__21_ (var_parameterValue_50817, var_sign_56716, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1614)) ;
            }
            GALGAS_luint_36__34_ var_integerValue_56740 = GALGAS_luint_36__34_::class_func_new (var_parameterValue_50817.readProperty_string ().getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1617)).getter_uint_36__34_ (SOURCE_FILE ("arxml_parser.galgas", 1617)), var_parameterValue_50817.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1616)) ;
            {
            routine_displayOil_3F_ (GALGAS_string (" = ").add_operation (var_integerValue_56740.readProperty_uint_36__34_ ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 1620)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1620)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1620)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1620)) ;
            }
            var_val_49953 = function_checkAndGetIntegerNumber (var_oil_5F_desc_50633, var_type_50168.readProperty_type (), var_integerValue_56740, var_sign_56716, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1622)) ;
          }
        }
        if (kBoolFalse == test_30) {
          enumGalgasBool test_31 = kBoolTrue ;
          if (kBoolTrue == test_31) {
            test_31 = GALGAS_bool (kIsEqual, var_valueType_50439.readProperty_string ().objectCompare (GALGAS_string ("ECUC-FLOAT-PARAM-DEF"))).boolEnum () ;
            if (kBoolTrue == test_31) {
              GALGAS_bool var_sign_57319 ;
              {
              routine_arxmlPopSign_26__21_ (var_parameterValue_50817, var_sign_57319, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1628)) ;
              }
              GALGAS_ldouble var_floatValue_57343 = GALGAS_ldouble::class_func_new (var_parameterValue_50817.readProperty_string ().getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1631)), var_parameterValue_50817.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1630)) ;
              {
              routine_displayOil_3F_ (GALGAS_string (" = ").add_operation (var_floatValue_57343.readProperty_double ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 1634)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1634)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1634)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1634)) ;
              }
              var_val_49953 = function_checkAndGetFloatNumber (var_oil_5F_desc_50633, var_type_50168.readProperty_type (), var_floatValue_57343, var_sign_57319, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1636)) ;
            }
          }
          if (kBoolFalse == test_31) {
            enumGalgasBool test_32 = kBoolTrue ;
            if (kBoolTrue == test_32) {
              test_32 = GALGAS_bool (kIsEqual, var_valueType_50439.readProperty_string ().objectCompare (GALGAS_string ("ECUC-STRING-PARAM-DEF"))).boolEnum () ;
              if (kBoolTrue == test_32) {
                {
                routine_displayOil_3F_ (GALGAS_string (" = \"").add_operation (var_parameterValue_50817.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1642)).add_operation (GALGAS_string ("\";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1642)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1642)) ;
                }
                var_val_49953 = GALGAS_stringAttribute::class_func_new (var_oil_5F_desc_50633, var_parameterValue_50817.readProperty_location (), var_parameterValue_50817.readProperty_string ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1644)) ;
              }
            }
            if (kBoolFalse == test_32) {
              enumGalgasBool test_33 = kBoolTrue ;
              if (kBoolTrue == test_33) {
                test_33 = GALGAS_bool (kIsEqual, var_valueType_50439.readProperty_string ().objectCompare (GALGAS_string ("ECUC-REFERENCE-DEF"))).boolEnum () ;
                if (kBoolTrue == test_33) {
                  {
                  routine_displayOil_3F_ (GALGAS_string (" = ").add_operation (var_parameterValue_50817.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1652)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1652)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1652)) ;
                  }
                  var_val_49953 = GALGAS_objectRefAttribute::class_func_new (var_oil_5F_desc_50633, var_parameterValue_50817.readProperty_location (), var_parameterValue_50817  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1654)) ;
                }
              }
              if (kBoolFalse == test_33) {
                enumGalgasBool test_34 = kBoolTrue ;
                if (kBoolTrue == test_34) {
                  test_34 = GALGAS_bool (kIsEqual, var_valueType_50439.readProperty_string ().objectCompare (GALGAS_string ("TPL-IDENTIFIER-DEF"))).boolEnum () ;
                  if (kBoolTrue == test_34) {
                    {
                    routine_displayOil_3F_ (GALGAS_string (" = ").add_operation (var_parameterValue_50817.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1662)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1662)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1662)) ;
                    }
                    var_val_49953 = GALGAS_string_5F_class::class_func_new (var_oil_5F_desc_50633, var_parameterValue_50817.readProperty_location (), var_parameterValue_50817.readProperty_string ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1664)) ;
                  }
                }
                if (kBoolFalse == test_34) {
                  enumGalgasBool test_35 = kBoolTrue ;
                  if (kBoolTrue == test_35) {
                    test_35 = GALGAS_bool (kIsEqual, var_valueType_50439.readProperty_string ().objectCompare (GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF"))).boolEnum () ;
                    if (kBoolTrue == test_35) {
                      GALGAS_impStructType temp_36 ;
                      if (var_type_50168.isValid ()) {
                        if (nullptr != dynamic_cast <const cPtr_impStructType *> (var_type_50168.ptr ())) {
                          temp_36 = (cPtr_impStructType *) var_type_50168.ptr () ;
                        }else{
                          inCompiler->castError ("impStructType", var_type_50168.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1672)) ;
                        }
                      }
                      GALGAS_impStructType var_structType_59236 = temp_36 ;
                      var_subTypes_53409 = var_structType_59236.readProperty_structAttributes () ;
                      {
                      routine_displayOil_3F_ (GALGAS_string (" ").add_operation (var_parameterValue_50817.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1675)).add_operation (GALGAS_string ("\n    {\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1675)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1675)) ;
                      }
                      {
                      routine_arxmlDefinitionContainer_3F__26__3F__3F_ (var_subTypes_53409, var_subAttributes_53477, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1676)) ;
                      }
                      {
                      routine_displayOil_3F_ (GALGAS_string ("    };"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1678)) ;
                      }
                      var_val_49953 = GALGAS_structAttribute::class_func_new (var_oil_5F_desc_50633, var_parameterValue_50817.readProperty_location (), var_parameterValue_50817, var_subAttributes_53477  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1680)) ;
                    }
                  }
                  if (kBoolFalse == test_35) {
                    TC_Array <C_FixItDescription> fixItArray37 ;
                    inCompiler->emitSemanticError (var_valueType_50439.readProperty_location (), GALGAS_string ("Undefined valueType ").add_operation (var_valueType_50439.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1688)), fixItArray37  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1688)) ;
                    var_val_49953.drop () ; // Release error dropped variable
                    var_typeOk_50142 = GALGAS_bool (false) ;
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
  routine_displayOil_3F_ (GALGAS_string ("      /* ARXML Type :").add_operation (var_valueType_50439.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1692)).add_operation (GALGAS_string (" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1692)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1692)) ;
  }
  GALGAS_identifierMap var_idfs_60177 = ioArgument_identifiers.readProperty_objectParams () ;
  enumGalgasBool test_38 = kBoolTrue ;
  if (kBoolTrue == test_38) {
    test_38 = var_type_50168.readProperty_multiple ().boolEnum () ;
    if (kBoolTrue == test_38) {
      enumGalgasBool test_39 = kBoolTrue ;
      if (kBoolTrue == test_39) {
        test_39 = var_idfs_60177.getter_hasKey (var_parameterType_50094.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1699)).boolEnum () ;
        if (kBoolTrue == test_39) {
          GALGAS_object_5F_t var_attributeList_60306 ;
          {
          var_idfs_60177.setter_del (var_parameterType_50094, var_attributeList_60306, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1703)) ;
          }
          if (var_attributeList_60306.isValid ()) {
            if (var_attributeList_60306.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
              GALGAS_multipleAttribute cast_60509_multiAttribute ((cPtr_multipleAttribute *) var_attributeList_60306.ptr ()) ;
              GALGAS_identifierList var_aList_60550 = cast_60509_multiAttribute.readProperty_items () ;
              var_aList_60550.addAssign_operation (var_val_49953  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1707)) ;
              var_val_49953 = GALGAS_multipleAttribute::class_func_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1708)), cast_60509_multiAttribute.readProperty_location (), var_aList_60550  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1708)) ;
            }
          }
        }
      }
      if (kBoolFalse == test_39) {
        GALGAS_identifierList var_aList_60820 = GALGAS_identifierList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1713)) ;
        GALGAS_object_5F_t var_defaultValue_60896 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) var_type_50168.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1715)) ;
        if (var_defaultValue_60896.isValid ()) {
          if (var_defaultValue_60896.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
            GALGAS_multipleAttribute cast_61023_multiAttribute ((cPtr_multipleAttribute *) var_defaultValue_60896.ptr ()) ;
            var_aList_60820 = cast_61023_multiAttribute.readProperty_items () ;
          }
        }
        var_aList_60820.addAssign_operation (var_val_49953  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1725)) ;
        var_val_49953 = GALGAS_multipleAttribute::class_func_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1727)), var_val_49953.readProperty_location (), var_aList_60820  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1727)) ;
      }
      enumGalgasBool test_40 = kBoolTrue ;
      if (kBoolTrue == test_40) {
        test_40 = var_idfs_60177.getter_hasKey (var_parameterType_50094.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1729)).boolEnum () ;
        if (kBoolTrue == test_40) {
          GALGAS_object_5F_t var_existingObject_61514 ;
          {
          var_idfs_60177.setter_del (var_parameterType_50094, var_existingObject_61514, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1733)) ;
          }
          {
          var_val_49953.insulate (HERE) ;
          cPtr_object_5F_t * ptr_61592 = (cPtr_object_5F_t *) var_val_49953.ptr () ;
          callExtensionSetter_mergeSubAttributes ((cPtr_object_5F_t *) ptr_61592, var_existingObject_61514, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1734)) ;
          }
        }
      }
    }
  }
  enumGalgasBool test_41 = kBoolTrue ;
  if (kBoolTrue == test_41) {
    test_41 = var_typeOk_50142.boolEnum () ;
    if (kBoolTrue == test_41) {
      {
      var_idfs_60177.setter_put (var_parameterType_50094, var_val_49953, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1740)) ;
      }
    }
  }
  {
  ioArgument_identifiers.setter_setObjectParams (var_idfs_60177 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1742)) ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'testTypeError??'
//
//--------------------------------------------------------------------------------------------------

void routine_testTypeError_3F__3F_ (GALGAS_dataType inArgument_type,
                                    GALGAS_lstring inArgument_valueType,
                                    Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Routine 'oilEquivalentName??!'
//
//--------------------------------------------------------------------------------------------------

void routine_oilEquivalentName_3F__3F__21_ (GALGAS_lstring inArgument_parentPath,
                                            GALGAS_lstring inArgument_currentPath,
                                            GALGAS_lstring & outArgument_outName,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outName.drop () ; // Release 'out' argument
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, inArgument_parentPath.readProperty_string ().objectCompare (inArgument_currentPath.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      inArgument_parentPath.setter_setString (inArgument_parentPath.readProperty_string ().getter_stringByDeletingLastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1766)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1766)) ;
    }
  }
  GALGAS_lstring var_objectKind_62451 = GALGAS_lstring::class_func_new (inArgument_currentPath.readProperty_string ().getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1769)), inArgument_currentPath.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1769)) ;
  GALGAS_string var_lastParent_62744 = inArgument_parentPath.readProperty_string ().getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1774)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1774)) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsEqual, var_lastParent_62744.objectCompare (GALGAS_string ("OSOS"))).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_lastParent_62744 = GALGAS_string ("OS") ;
    }
  }
  GALGAS_uint var_lastParentLength_62986 = var_lastParent_62744.getter_count (SOURCE_FILE ("arxml_parser.galgas", 1782)) ;
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsEqual, var_objectKind_62451.readProperty_string ().getter_leftSubString (var_lastParentLength_62986 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1783)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1783)).objectCompare (var_lastParent_62744)).boolEnum () ;
    if (kBoolTrue == test_2) {
      var_objectKind_62451.setter_setString (var_objectKind_62451.readProperty_string ().getter_subStringFromIndex (var_lastParentLength_62986 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1785)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1785)) ;
      var_objectKind_62451.setter_setString (var_objectKind_62451.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1786)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1786)) ;
      outArgument_outName = var_objectKind_62451 ;
    }
  }
  if (kBoolFalse == test_2) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (var_objectKind_62451.readProperty_location (), GALGAS_string ("An object must be named by its Parent.\n ").add_operation (GALGAS_string ("Ex : If Task object has Os parent, then the DEFINITION-REF must be "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1789)).add_operation (GALGAS_string ("(...)/Os/OsTask.\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1790)).add_operation (GALGAS_string ("Fix : Add \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1791)).add_operation (var_lastParent_62744, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1792)).add_operation (GALGAS_string ("\" to the name of your property."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1792)), fixItArray3  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1789)) ;
    outArgument_outName.drop () ; // Release error dropped variable
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlGetDescription?!'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlGetDescription_3F__21_ (GALGAS_arxmlElementValue inArgument_packageElement,
                                          GALGAS_lstring & outArgument_description,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_description.drop () ; // Release 'out' argument
  outArgument_description = GALGAS_lstring::class_func_new (GALGAS_string::makeEmptyString (), GALGAS_location::class_func_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1801)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1801)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DESC"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1804)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_arxmlElementValue var_desc_63871 ;
      callExtensionMethod_getElement ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DESC"), var_desc_63871, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1805)) ;
      callExtensionMethod_getAllTextsInSelf ((cPtr_arxmlElementValue *) var_desc_63871.ptr (), GALGAS_string (" "), outArgument_description, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1806)) ;
    }
  }
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("INTRODUCTION"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1808)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_arxmlElementValue var_desc_64056 ;
      callExtensionMethod_getElement ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("INTRODUCTION"), var_desc_64056, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1809)) ;
      callExtensionMethod_getAllTextsInSelf ((cPtr_arxmlElementValue *) var_desc_64056.ptr (), GALGAS_string (" "), outArgument_description, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1810)) ;
    }
  }
  outArgument_description.setter_setString (outArgument_description.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("\n"), GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1814)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1814)) ;
  outArgument_description.setter_setString (outArgument_description.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("\r"), GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1817)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1817)) ;
  outArgument_description.setter_setString (outArgument_description.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("\\"), GALGAS_string ("\\\\"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1820)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1820)) ;
  outArgument_description.setter_setString (outArgument_description.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("\""), GALGAS_string ("\\\""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1823)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1823)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'displayOil?'
//
//--------------------------------------------------------------------------------------------------

void routine_displayOil_3F_ (GALGAS_string inArgument_string,
                             Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (gOption_goil_5F_options_arxmlDisplayOil.readProperty_value ()).boolEnum () ;
    if (kBoolTrue == test_0) {
      inCompiler->printMessage (inArgument_string  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1832)) ;
    }
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlGetMultiplicity??!'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlGetMultiplicity_3F__3F__21_ (GALGAS_arxmlElementValue inArgument_element,
                                               GALGAS_lstring inArgument_objectName,
                                               GALGAS_lbool & outArgument_multiple,
                                               Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_multiple.drop () ; // Release 'out' argument
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_element.ptr (), GALGAS_string ("UPPER-MULTIPLICITY-INFINITE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1841)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_smultiple_65098 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_element.ptr (), GALGAS_string ("UPPER-MULTIPLICITY-INFINITE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1842)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        GALGAS_bool test_2 = GALGAS_bool (kIsEqual, var_smultiple_65098.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1844)).objectCompare (GALGAS_string ("TRUE"))) ;
        if (kBoolTrue != test_2.boolEnum ()) {
          test_2 = GALGAS_bool (kIsEqual, var_smultiple_65098.readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
        }
        test_1 = test_2.boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_multiple = GALGAS_lbool::class_func_new (GALGAS_bool (true), var_smultiple_65098.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1846)) ;
          {
          routine_displayOil_3F_ (GALGAS_string ("[]"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1847)) ;
          }
        }
      }
      if (kBoolFalse == test_1) {
        outArgument_multiple = GALGAS_lbool::class_func_new (GALGAS_bool (false), var_smultiple_65098.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1849)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    outArgument_multiple = GALGAS_lbool::class_func_new (GALGAS_bool (false), inArgument_objectName.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1852)) ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlPopSign&!'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlPopSign_26__21_ (GALGAS_lstring & ioArgument_value,
                                   GALGAS_bool & outArgument_sign,
                                   Compiler * inCompiler
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


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlGetWithAuto?!'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlGetWithAuto_3F__21_ (GALGAS_arxmlElementValue inArgument_parameter,
                                       GALGAS_bool & outArgument_withAuto,
                                       Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_withAuto.drop () ; // Release 'out' argument
  outArgument_withAuto = GALGAS_bool (false) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("WITH-AUTO"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1877)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_autoString_66006 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("WITH-AUTO"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1878)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        GALGAS_bool test_2 = GALGAS_bool (kIsEqual, var_autoString_66006.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1879)).objectCompare (GALGAS_string ("TRUE"))) ;
        if (kBoolTrue != test_2.boolEnum ()) {
          test_2 = GALGAS_bool (kIsEqual, var_autoString_66006.readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
        }
        test_1 = test_2.boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_withAuto = GALGAS_bool (true) ;
          {
          routine_displayOil_3F_ (GALGAS_string (" WITH_AUTO"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1882)) ;
          }
        }
      }
    }
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlGetName?!'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlGetName_3F__21_ (GALGAS_arxmlElementValue inArgument_parameter,
                                   GALGAS_lstring & outArgument_objectName,
                                   Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_objectName = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1892)) ;
  outArgument_objectName.setter_setString (outArgument_objectName.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1893)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1893)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'arxmlInsertObjectAttribute&??'
//
//--------------------------------------------------------------------------------------------------

void routine_arxmlInsertObjectAttribute_26__3F__3F_ (GALGAS_implementationObjectMap & ioArgument_objectAttributes,
                                                     GALGAS_lstring inArgument_attributeName,
                                                     GALGAS_impType inArgument_type,
                                                     Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = ioArgument_objectAttributes.getter_hasKey (inArgument_attributeName.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1901)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_impType var_previousType_66643 ;
      ioArgument_objectAttributes.method_get (inArgument_attributeName, var_previousType_66643, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1903)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = var_previousType_66643.readProperty_multiple ().boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_object_5F_t var_previousDefaultValue_66977 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) var_previousType_66643.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1909)) ;
          GALGAS_object_5F_t var_defaultValue_67051 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) inArgument_type.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1910)) ;
          GALGAS_bool var_oneIsMultiple_67101 = GALGAS_bool (false) ;
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            test_2 = GALGAS_bool (var_previousDefaultValue_66977.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute).boolEnum () ;
            if (kBoolTrue == test_2) {
              var_oneIsMultiple_67101 = GALGAS_bool (true) ;
            }
          }
          if (kBoolFalse == test_2) {
            enumGalgasBool test_3 = kBoolTrue ;
            if (kBoolTrue == test_3) {
              test_3 = GALGAS_bool (var_defaultValue_67051.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute).boolEnum () ;
              if (kBoolTrue == test_3) {
                var_oneIsMultiple_67101 = GALGAS_bool (true) ;
              }
            }
          }
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = var_oneIsMultiple_67101.boolEnum () ;
            if (kBoolTrue == test_4) {
              GALGAS_identifierList var_aList_67512 = GALGAS_identifierList::class_func_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1921)) ;
              GALGAS_lstring var_desc_67548 = function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1922)) ;
              GALGAS_location var_location_67588 = GALGAS_location::class_func_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1923)) ;
              if (var_previousDefaultValue_66977.isValid ()) {
                if (var_previousDefaultValue_66977.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
                  GALGAS_multipleAttribute cast_67708_multiAttribute ((cPtr_multipleAttribute *) var_previousDefaultValue_66977.ptr ()) ;
                  var_aList_67512 = cast_67708_multiAttribute.readProperty_items () ;
                  var_desc_67548 = cast_67708_multiAttribute.readProperty_oil_5F_desc () ;
                  var_location_67588 = cast_67708_multiAttribute.readProperty_location () ;
                }
              }
              if (var_defaultValue_67051.isValid ()) {
                if (var_defaultValue_67051.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
                  GALGAS_multipleAttribute cast_67968_multiAttribute ((cPtr_multipleAttribute *) var_defaultValue_67051.ptr ()) ;
                  var_aList_67512.plusAssign_operation(cast_67968_multiAttribute.readProperty_items (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1936)) ;
                  enumGalgasBool test_5 = kBoolTrue ;
                  if (kBoolTrue == test_5) {
                    test_5 = GALGAS_bool (kIsEqual, var_desc_67548.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
                    if (kBoolTrue == test_5) {
                      var_desc_67548 = cast_67968_multiAttribute.readProperty_oil_5F_desc () ;
                    }
                  }
                  enumGalgasBool test_6 = kBoolTrue ;
                  if (kBoolTrue == test_6) {
                    test_6 = GALGAS_bool (kIsEqual, var_location_67588.objectCompare (GALGAS_location::class_func_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1940)))).boolEnum () ;
                    if (kBoolTrue == test_6) {
                      var_location_67588 = cast_67968_multiAttribute.readProperty_location () ;
                    }
                  }
                }
              }
              GALGAS_object_5F_t var_newDefault_68305 = GALGAS_multipleAttribute::class_func_new (var_desc_67548, var_location_67588, var_aList_67512  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1946)) ;
              {
              inArgument_type.insulate (HERE) ;
              cPtr_impType * ptr_68413 = (cPtr_impType *) inArgument_type.ptr () ;
              callExtensionSetter_setDefValue ((cPtr_impType *) ptr_68413, var_newDefault_68305, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1949)) ;
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
        test_7 = function_checkNewTypeWithinPreviousType (inArgument_attributeName, var_previousType_66643, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1956)).boolEnum () ;
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


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlElementNode print'
//
//--------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_print (const GALGAS_uint constinArgument_indentation,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_indent_3613 = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 172)) ;
  inCompiler->printMessage (var_indent_3613  COMMA_SOURCE_FILE ("arxml_types.galgas", 173)) ;
  inCompiler->printMessage (GALGAS_string ("NODE \"").add_operation (this->mProperty_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 174)).add_operation (GALGAS_string ("\" "), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 174))  COMMA_SOURCE_FILE ("arxml_types.galgas", 174)) ;
  extensionMethod_print (this->mProperty_attributes, constinArgument_indentation, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 175)) ;
  inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("arxml_types.galgas", 176)) ;
  extensionMethod_print (this->mProperty_enclosedNodes, constinArgument_indentation, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 177)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlElementNode getElementsFromName'
//
//--------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_getElementsFromName (const GALGAS_string constinArgument_nodeName,
                                                        GALGAS_arxmlElementList & ioArgument_nodeList,
                                                        Compiler * inCompiler
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
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlElementNode getSubElementsFromName'
//
//--------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_getSubElementsFromName (const GALGAS_string constinArgument_nodeName,
                                                           GALGAS_arxmlElementList & ioArgument_nodeList,
                                                           Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_arxmlNodeList enumerator_4178 (this->mProperty_enclosedNodes, kENUMERATION_UP) ;
  while (enumerator_4178.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (enumerator_4178.current_node (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_arxmlElementNode).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_arxmlElementNode temp_1 ;
        if (enumerator_4178.current_node (HERE).isValid ()) {
          if (nullptr != dynamic_cast <const cPtr_arxmlElementNode *> (enumerator_4178.current_node (HERE).ptr ())) {
            temp_1 = (cPtr_arxmlElementNode *) enumerator_4178.current_node (HERE).ptr () ;
          }else{
            inCompiler->castError ("arxmlElementNode", enumerator_4178.current_node (HERE).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_types.galgas", 197)) ;
          }
        }
        GALGAS_arxmlElementNode var_currentElement_4287 = temp_1 ;
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = GALGAS_bool (kIsEqual, var_currentElement_4287.readProperty_name ().readProperty_string ().objectCompare (constinArgument_nodeName)).boolEnum () ;
          if (kBoolTrue == test_2) {
            ioArgument_nodeList.addAssign_operation (var_currentElement_4287  COMMA_SOURCE_FILE ("arxml_types.galgas", 199)) ;
          }
        }
      }
    }
    enumerator_4178.gotoNextObject () ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlElementNode getProperty'
//
//--------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_getProperty (const GALGAS_string constinArgument_nodeName,
                                                GALGAS_lstring & ioArgument_value,
                                                GALGAS_bool & ioArgument_found,
                                                Compiler * inCompiler
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
      cEnumerator_arxmlNodeList enumerator_4977 (this->mProperty_enclosedNodes, kENUMERATION_UP) ;
      bool bool_3 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 229)).isValidAndTrue () ;
      if (enumerator_4977.hasCurrentObject () && bool_3) {
        while (enumerator_4977.hasCurrentObject () && bool_3) {
          callExtensionMethod_getProperty ((cPtr_arxmlNode *) enumerator_4977.current_node (HERE).ptr (), constinArgument_nodeName, ioArgument_value, ioArgument_found, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 231)) ;
          enumerator_4977.gotoNextObject () ;
          if (enumerator_4977.hasCurrentObject ()) {
            bool_3 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 229)).isValidAndTrue () ;
          }
        }
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlCommentNode print'
//
//--------------------------------------------------------------------------------------------------

void cPtr_arxmlCommentNode::method_print (const GALGAS_uint constinArgument_indentation,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_indent_5999 = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 281)) ;
  inCompiler->printMessage (var_indent_5999  COMMA_SOURCE_FILE ("arxml_types.galgas", 282)) ;
  inCompiler->printMessage (GALGAS_string ("COMMENT \"").add_operation (this->mProperty_comment.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 283)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 283))  COMMA_SOURCE_FILE ("arxml_types.galgas", 283)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlCommentNode getElementsFromName'
//
//--------------------------------------------------------------------------------------------------

void cPtr_arxmlCommentNode::method_getElementsFromName (const GALGAS_string /* constinArgument_nodeName */,
                                                        GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                        Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlCommentNode getSubElementsFromName'
//
//--------------------------------------------------------------------------------------------------

void cPtr_arxmlCommentNode::method_getSubElementsFromName (const GALGAS_string /* constinArgument_nodeName */,
                                                           GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                           Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlCommentNode getProperty'
//
//--------------------------------------------------------------------------------------------------

void cPtr_arxmlCommentNode::method_getProperty (const GALGAS_string /* constinArgument_nodeName */,
                                                GALGAS_lstring & /* ioArgument_value */,
                                                GALGAS_bool & /* ioArgument_found */,
                                                Compiler * /* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) {
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlTextNode print'
//
//--------------------------------------------------------------------------------------------------

void cPtr_arxmlTextNode::method_print (const GALGAS_uint constinArgument_indentation,
                                       Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_indent_6756 = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 316)) ;
  inCompiler->printMessage (var_indent_6756  COMMA_SOURCE_FILE ("arxml_types.galgas", 317)) ;
  inCompiler->printMessage (GALGAS_string ("TEXT \"").add_operation (this->mProperty_text.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 318)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 318))  COMMA_SOURCE_FILE ("arxml_types.galgas", 318)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlTextNode getElementsFromName'
//
//--------------------------------------------------------------------------------------------------

void cPtr_arxmlTextNode::method_getElementsFromName (const GALGAS_string /* constinArgument_nodeName */,
                                                     GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                     Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlTextNode getSubElementsFromName'
//
//--------------------------------------------------------------------------------------------------

void cPtr_arxmlTextNode::method_getSubElementsFromName (const GALGAS_string /* constinArgument_nodeName */,
                                                        GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                        Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlTextNode getProperty'
//
//--------------------------------------------------------------------------------------------------

void cPtr_arxmlTextNode::method_getProperty (const GALGAS_string /* constinArgument_nodeName */,
                                             GALGAS_lstring & /* ioArgument_value */,
                                             GALGAS_bool & /* ioArgument_found */,
                                             Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
}
//--------------------------------------------------------------------------------------------------
//
//Routine 'lstringhere!?'
//
//--------------------------------------------------------------------------------------------------

void routine_lstringhere_21__3F_ (GALGAS_lstring & outArgument_string,
                                  GALGAS_string inArgument_value,
                                  Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_string.drop () ; // Release 'out' argument
  outArgument_string = GALGAS_lstring::class_func_new (inArgument_value, GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1148)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1148)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'fillLegacy&&'
//
//--------------------------------------------------------------------------------------------------

void routine_fillLegacy_26__26_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                 GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                 Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist var_sortedInfoList_32029 = ioArgument_classGraph.getter_keyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1155)) ;
  cEnumerator_stringlist enumerator_32083 (var_sortedInfoList_32029, kENUMERATION_UP) ;
  while (enumerator_32083.hasCurrentObject ()) {
    GALGAS_lstring var_lClassName_32146 ;
    {
    routine_lstringhere_21__3F_ (var_lClassName_32146, enumerator_32083.current_mValue (HERE), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1158)) ;
    }
    GALGAS_arxmlMetaClass var_lClass_32190 ;
    ioArgument_classMap.method_searchKey (var_lClassName_32146, var_lClass_32190, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1160)) ;
    GALGAS_lstringlist var_fromList_32281 = GALGAS_lstringlist::class_func_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1163)) ;
    {
    var_fromList_32281.setter_insertAtIndex (var_lClass_32190.readProperty_name (), GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1164)) ;
    }
    GALGAS_stringset var_empty_32363 = GALGAS_stringset::class_func_emptySet (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1165)) ;
    GALGAS_lstringlist var_successorList_32402 = ioArgument_classGraph.getter_accessibleNodesFrom (var_fromList_32281, var_empty_32363, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1166)) ;
    {
    var_lClass_32190.insulate (HERE) ;
    cPtr_arxmlMetaClass * ptr_32555 = (cPtr_arxmlMetaClass *) var_lClass_32190.ptr () ;
    callExtensionSetter_legacyAddParameters ((cPtr_arxmlMetaClass *) ptr_32555, ioArgument_classMap, var_successorList_32402, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1169)) ;
    }
    enumerator_32083.gotoNextObject () ;
  }
}


#include "project_header.h"
#include "F_mainForLIBPM.h"
#include "F_Analyze_CLI_Options.h"
#include "C_builtin_CLI_Options.h"
#include "C_galgas_CLI_Options.h"
#include "F_verbose_output.h"
#include "cLexiqueIntrospection.h"
#include "F_DisplayException.h"

//--------------------------------------------------------------------------------------------------
//
//                      print_tool_help_message                                                  
//
//--------------------------------------------------------------------------------------------------

static void print_tool_help_message (void) {
  gCout.appendCString ("Compiled with GALGAS revision NUMERO_REVISION_GALGAS\n") ;
}

//--------------------------------------------------------------------------------------------------

static const char * kSourceFileExtensions [] = {
  "oil",
  "OIL",
  "goilTemplate",
  "arxml",
  nullptr
} ;    

//--------------------------------------------------------------------------------------------------

static const char * kSourceFileHelpMessages [] = {
  "an '.oil' source file",
  "an '.OIL' source file",
  "a Goil template file",
  "an AUTOSAR arxml configuration file",
  nullptr
} ;    

//--------------------------------------------------------------------------------------------------

const char * projectVersionString (void) {
  return "3.1.16" ;
}

//--------------------------------------------------------------------------------------------------
//
//Routine 'before'
//
//--------------------------------------------------------------------------------------------------

static void routine_before (Compiler * /* inCompiler */
                            COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'after'
//
//--------------------------------------------------------------------------------------------------

static void routine_after (Compiler * /* inCompiler */
                           COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'programRule_0'
//
//--------------------------------------------------------------------------------------------------

static void routine_programRule_5F__30_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 33)) ;
  }
  cGrammar_goil_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("goil_program.galgas", 34)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'programRule_1'
//
//--------------------------------------------------------------------------------------------------

static void routine_programRule_5F__31_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 38)) ;
  }
  cGrammar_goil_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("goil_program.galgas", 39)) ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'programRule_2'
//
//--------------------------------------------------------------------------------------------------

static void routine_programRule_5F__32_ (const GALGAS_lstring /* constinArgument_inSourceFile */,
                                         Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'programRule_3'
//
//--------------------------------------------------------------------------------------------------

static void routine_programRule_5F__33_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 48)) ;
  }
  GALGAS_arxmlNode var_root_1354 ;
  var_root_1354.drop () ;
  cGrammar_arxml_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile, var_root_1354, GALGAS_bool (true), GALGAS_bool (true)  COMMA_SOURCE_FILE ("goil_program.galgas", 49)) ;
  callExtensionMethod_print ((cPtr_arxmlNode *) var_root_1354.ptr (), GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("goil_program.galgas", 53)) ;
}


//--------------------------------------------------------------------------------------------------
//
//                      M A I N    F O R    L I B P M                                            
//
//--------------------------------------------------------------------------------------------------

int mainForLIBPM (int inArgc, const char * inArgv []) {
//--- Analyze Command Line Options
  TC_UniqueArray <String> sourceFilesArray ;
  F_Analyze_CLI_Options (inArgc, inArgv,
                         sourceFilesArray,
                         kSourceFileExtensions,
                         kSourceFileHelpMessages,
                         print_tool_help_message) ;
//---
  int returnCode = 0 ; // No error
//--- Set Execution mode
  String executionModeOptionErrorMessage ;
  setExecutionMode (executionModeOptionErrorMessage) ;
  if (executionModeOptionErrorMessage.length () > 0) {
    gCout.appendString (executionModeOptionErrorMessage) ;
    returnCode = 1 ;
  }else{
  //--- Common lexique object
    Compiler * commonCompiler = nullptr ;
    macroMyNew (commonCompiler, Compiler (nullptr COMMA_HERE)) ;
    try{
      routine_before (commonCompiler COMMA_HERE) ;
      cLexiqueIntrospection::handleGetKeywordListOption (commonCompiler) ;
      const bool verboseOptionOn = verboseOutput () ;
      for (int32_t i=0 ; i<sourceFilesArray.count () ; i++) {
        const String fileExtension = sourceFilesArray (i COMMA_HERE).pathExtension () ;
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
          printf ("*** Error: unhandled extension for file '%s' ***\n", sourceFilesArray (i COMMA_HERE).cString ()) ;
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
        String message ;
        if (totalWarningCount () == 0) {
          message.appendCString ("No warning") ;
        }else if (totalWarningCount () == 1) {
          message.appendCString ("1 warning") ;
        }else{
          message.appendSigned (totalWarningCount ()) ;
          message.appendCString (" warnings") ;
        }
        message.appendCString (", ") ;
        if (totalErrorCount () == 0) {
          message.appendCString ("no error") ;
        }else if (totalErrorCount () == 1) {
          message.appendCString ("1 error") ;
        }else{
          message.appendSigned (totalErrorCount ()) ;
          message.appendCString (" errors") ;
        }
        message.appendCString (".\n") ;
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


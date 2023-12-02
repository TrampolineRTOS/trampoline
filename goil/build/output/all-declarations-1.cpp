#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-1.h"

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_debugCommandInput::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_debugCommandInput * p = (const cPtr_debugCommandInput *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_debugCommandInput) ;
  if (kOperandEqual == result) {
    result = mProperty_history.objectCompare (p->mProperty_history) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_debugCommandInput::objectCompare (const GALGAS_debugCommandInput & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_debugCommandInput::GALGAS_debugCommandInput (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_debugCommandInput GALGAS_debugCommandInput::constructor_default (LOCATION_ARGS) {
  return GALGAS_debugCommandInput::constructor_new (GALGAS_stringlist::constructor_emptyList (HERE)
                                                    COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_debugCommandInput::GALGAS_debugCommandInput (const cPtr_debugCommandInput * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_debugCommandInput) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_debugCommandInput GALGAS_debugCommandInput::constructor_new (const GALGAS_stringlist & inAttribute_history
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_debugCommandInput result ;
  if (inAttribute_history.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_debugCommandInput (inAttribute_history COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist GALGAS_debugCommandInput::readProperty_history (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_stringlist () ;
  }else{
    const cPtr_debugCommandInput * p = (const cPtr_debugCommandInput *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debugCommandInput) ;
    return p->mProperty_history ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist cPtr_debugCommandInput::getter_history (UNUSED_LOCATION_ARGS) const {
  return mProperty_history ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debugCommandInput::setter_setHistory (GALGAS_stringlist inValue
                                                  COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debugCommandInput * p = (cPtr_debugCommandInput *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debugCommandInput) ;
    p->mProperty_history = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debugCommandInput::setter_setHistory (GALGAS_stringlist inValue
                                                COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_history = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @debugCommandInput class
//----------------------------------------------------------------------------------------------------------------------

cPtr_debugCommandInput::cPtr_debugCommandInput (const GALGAS_stringlist & in_history
                                                COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_history (in_history) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_debugCommandInput::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_debugCommandInput ;
}

void cPtr_debugCommandInput::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@debugCommandInput:" ;
  mProperty_history.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_debugCommandInput::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_debugCommandInput (mProperty_history COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @debugCommandInput generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_debugCommandInput ("debugCommandInput",
                                          nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_debugCommandInput::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_debugCommandInput ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_debugCommandInput::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_debugCommandInput (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_debugCommandInput GALGAS_debugCommandInput::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_debugCommandInput result ;
  const GALGAS_debugCommandInput * p = (const GALGAS_debugCommandInput *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_debugCommandInput *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("debugCommandInput", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlBreakpoint::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlBreakpoint * p = (const cPtr_gtlBreakpoint *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlBreakpoint) ;
  if (kOperandEqual == result) {
    result = mProperty_fileName.objectCompare (p->mProperty_fileName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lineNum.objectCompare (p->mProperty_lineNum) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlBreakpoint::objectCompare (const GALGAS_gtlBreakpoint & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpoint::GALGAS_gtlBreakpoint (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpoint GALGAS_gtlBreakpoint::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlBreakpoint::constructor_new (GALGAS_string::constructor_default (HERE),
                                                GALGAS_uint::constructor_default (HERE),
                                                GALGAS_string::constructor_default (HERE)
                                                COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpoint::GALGAS_gtlBreakpoint (const cPtr_gtlBreakpoint * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlBreakpoint) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpoint GALGAS_gtlBreakpoint::constructor_new (const GALGAS_string & inAttribute_fileName,
                                                            const GALGAS_uint & inAttribute_lineNum,
                                                            const GALGAS_string & inAttribute_signature
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpoint result ;
  if (inAttribute_fileName.isValid () && inAttribute_lineNum.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlBreakpoint (inAttribute_fileName, inAttribute_lineNum, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_gtlBreakpoint::readProperty_fileName (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_gtlBreakpoint * p = (const cPtr_gtlBreakpoint *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpoint) ;
    return p->mProperty_fileName ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlBreakpoint::getter_fileName (UNUSED_LOCATION_ARGS) const {
  return mProperty_fileName ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_gtlBreakpoint::readProperty_lineNum (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    const cPtr_gtlBreakpoint * p = (const cPtr_gtlBreakpoint *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpoint) ;
    return p->mProperty_lineNum ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_gtlBreakpoint::getter_lineNum (UNUSED_LOCATION_ARGS) const {
  return mProperty_lineNum ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_gtlBreakpoint::readProperty_signature (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_gtlBreakpoint * p = (const cPtr_gtlBreakpoint *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpoint) ;
    return p->mProperty_signature ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlBreakpoint::getter_signature (UNUSED_LOCATION_ARGS) const {
  return mProperty_signature ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpoint::setter_setFileName (GALGAS_string inValue
                                               COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlBreakpoint * p = (cPtr_gtlBreakpoint *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpoint) ;
    p->mProperty_fileName = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpoint::setter_setFileName (GALGAS_string inValue
                                             COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_fileName = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpoint::setter_setLineNum (GALGAS_uint inValue
                                              COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlBreakpoint * p = (cPtr_gtlBreakpoint *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpoint) ;
    p->mProperty_lineNum = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpoint::setter_setLineNum (GALGAS_uint inValue
                                            COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_lineNum = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpoint::setter_setSignature (GALGAS_string inValue
                                                COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlBreakpoint * p = (cPtr_gtlBreakpoint *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpoint) ;
    p->mProperty_signature = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpoint::setter_setSignature (GALGAS_string inValue
                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_signature = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlBreakpoint class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlBreakpoint::cPtr_gtlBreakpoint (const GALGAS_string & in_fileName,
                                        const GALGAS_uint & in_lineNum,
                                        const GALGAS_string & in_signature
                                        COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_fileName (in_fileName),
mProperty_lineNum (in_lineNum),
mProperty_signature (in_signature) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlBreakpoint::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpoint ;
}

void cPtr_gtlBreakpoint::description (C_String & ioString,
                                      const int32_t inIndentation) const {
  ioString << "[@gtlBreakpoint:" ;
  mProperty_fileName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lineNum.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlBreakpoint::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlBreakpoint (mProperty_fileName, mProperty_lineNum, mProperty_signature COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlBreakpoint generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlBreakpoint ("gtlBreakpoint",
                                      nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlBreakpoint::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpoint ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlBreakpoint::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlBreakpoint (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpoint GALGAS_gtlBreakpoint::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpoint result ;
  const GALGAS_gtlBreakpoint * p = (const GALGAS_gtlBreakpoint *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlBreakpoint *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlBreakpoint", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@gtlVarPath stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_stringRepresentation (const GALGAS_gtlVarPath & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_gtlVarPath temp_0 = inObject ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlVarItem *) temp_0.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 653)).ptr (), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 653)) ;
  const GALGAS_gtlVarPath temp_1 = inObject ;
  cEnumerator_gtlVarPath enumerator_19873 (temp_1.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 654)), kENUMERATION_UP) ;
  while (enumerator_19873.hasCurrentObject ()) {
    result_result.plusAssign_operation(callExtensionGetter_stringRepresentation ((const cPtr_gtlVarItem *) enumerator_19873.current_item (HERE).ptr (), GALGAS_string ("::"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 655)), inCompiler  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 655)) ;
    enumerator_19873.gotoNextObject () ;
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlVarItem stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string callExtensionGetter_stringRepresentation (const cPtr_gtlVarItem * inObject,
                                                        const GALGAS_string in_concatString,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (nullptr != inObject) {
    result = inObject->getter_stringRepresentation (in_concatString, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@gtlExpressionList stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_stringRepresentation (const GALGAS_gtlExpressionList & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  const GALGAS_gtlExpressionList temp_0 = inObject ;
  cEnumerator_gtlExpressionList enumerator_32813 (temp_0, kENUMERATION_UP) ;
  while (enumerator_32813.hasCurrentObject ()) {
    result_result = result_result.add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) enumerator_32813.current_expression (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1071)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1071)) ;
    if (enumerator_32813.hasNextObject ()) {
      result_result = result_result.add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1073)) ;
    }
    enumerator_32813.gotoNextObject () ;
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@gtlExpressionMap mapRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_mapRepresentation (const GALGAS_gtlExpressionMap & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  const GALGAS_gtlExpressionMap temp_0 = inObject ;
  cEnumerator_gtlExpressionMap enumerator_33107 (temp_0, kENUMERATION_UP) ;
  while (enumerator_33107.hasCurrentObject ()) {
    result_result = result_result.add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1083)).add_operation (enumerator_33107.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1083)).add_operation (GALGAS_string ("\": "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1083)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) enumerator_33107.current_expression (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1083)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1083)) ;
    if (enumerator_33107.hasNextObject ()) {
      result_result = result_result.add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1085)) ;
    }
    enumerator_33107.gotoNextObject () ;
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@gtlExpressionMap structRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_structRepresentation (const GALGAS_gtlExpressionMap & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  const GALGAS_gtlExpressionMap temp_0 = inObject ;
  cEnumerator_gtlExpressionMap enumerator_33426 (temp_0, kENUMERATION_UP) ;
  while (enumerator_33426.hasCurrentObject ()) {
    result_result = result_result.add_operation (enumerator_33426.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1095)).add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1095)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) enumerator_33426.current_expression (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1095)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1095)) ;
    if (enumerator_33426.hasNextObject ()) {
      result_result = result_result.add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1097)) ;
    }
    enumerator_33426.gotoNextObject () ;
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@gtlArgumentList stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_stringRepresentation (const GALGAS_gtlArgumentList & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  const GALGAS_gtlArgumentList temp_0 = inObject ;
  cEnumerator_gtlArgumentList enumerator_33742 (temp_0, kENUMERATION_UP) ;
  while (enumerator_33742.hasCurrentObject ()) {
    result_result = result_result.add_operation (enumerator_33742.current_name (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1107)) ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = enumerator_33742.current_typed (HERE).boolEnum () ;
      if (kBoolTrue == test_1) {
        result_result = result_result.add_operation (GALGAS_string (" : @"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1109)).add_operation (extensionGetter_typeName (enumerator_33742.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1109)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1109)) ;
      }
    }
    if (enumerator_33742.hasNextObject ()) {
      result_result = result_result.add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1112)) ;
    }
    enumerator_33742.gotoNextObject () ;
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@sortingKeyList stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_stringRepresentation (const GALGAS_sortingKeyList & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  const GALGAS_sortingKeyList temp_0 = inObject ;
  cEnumerator_sortingKeyList enumerator_34272 (temp_0, kENUMERATION_UP) ;
  while (enumerator_34272.hasCurrentObject ()) {
    result_result = result_result.add_operation (enumerator_34272.current_key (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1129)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1129)).add_operation (extensionGetter_stringRepresentation (enumerator_34272.current_order (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1129)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1129)) ;
    if (enumerator_34272.hasNextObject ()) {
      result_result = GALGAS_string (", ") ;
    }
    enumerator_34272.gotoNextObject () ;
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlInstruction shortLocation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlInstruction::getter_shortLocation (C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_where.getter_file (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1139)).getter_lastPathComponent (SOURCE_FILE ("gtl_debugger.galgas", 1139)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1139)).add_operation (this->mProperty_where.getter_endLine (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1139)).getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1139)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1139)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_string callExtensionGetter_shortLocation (const cPtr_gtlInstruction * inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (nullptr != inObject) {
    result = inObject->getter_shortLocation (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlInstruction displayWithLocation'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlInstruction::method_displayWithLocation (const GALGAS_debuggerContext constinArgument_context,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_gtlInstruction temp_0 = this ;
  inCompiler->printMessage (callExtensionGetter_shortLocation ((const cPtr_gtlInstruction *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1146)).add_operation (GALGAS_string (" > "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1146))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1146)) ;
  inCompiler->printMessage (constinArgument_context.readProperty_instructionColor ().add_operation (constinArgument_context.readProperty_instructionFace (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1147))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1147)) ;
  const GALGAS_gtlInstruction temp_1 = this ;
  callExtensionMethod_display ((cPtr_gtlInstruction *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1148)) ;
  inCompiler->printMessage (function_endc (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1149)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1149))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1149)) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_displayWithLocation (cPtr_gtlInstruction * inObject,
                                              const GALGAS_debuggerContext constin_context,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlInstruction) ;
    inObject->method_displayWithLocation  (constin_context, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension method '@gtlInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_display (cPtr_gtlInstruction * inObject,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlInstruction) ;
    inObject->method_display (inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlInstruction mayExecuteWithoutError'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlInstruction::getter_mayExecuteWithoutError (const GALGAS_gtlContext /* constinArgument_exeContext */,
                                                                const GALGAS_gtlData /* constinArgument_context */,
                                                                const GALGAS_library /* constinArgument_lib */,
                                                                C_Compiler */* inCompiler */
                                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_may ; // Returned variable
  result_may = GALGAS_bool (true) ;
//---
  return result_may ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_mayExecuteWithoutError (const cPtr_gtlInstruction * inObject,
                                                        const GALGAS_gtlContext in_exeContext,
                                                        const GALGAS_gtlData in_context,
                                                        const GALGAS_library in_lib,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_mayExecuteWithoutError (in_exeContext, in_context, in_lib, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlStepInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlStepInstruction * p = (const cPtr_gtlStepInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlStepInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlStepInstruction::objectCompare (const GALGAS_gtlStepInstruction & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlStepInstruction::GALGAS_gtlStepInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlStepInstruction GALGAS_gtlStepInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlStepInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                     GALGAS_string::constructor_default (HERE)
                                                     COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlStepInstruction::GALGAS_gtlStepInstruction (const cPtr_gtlStepInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlStepInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlStepInstruction GALGAS_gtlStepInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                      const GALGAS_string & inAttribute_signature
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlStepInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlStepInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlStepInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlStepInstruction::cPtr_gtlStepInstruction (const GALGAS_location & in_where,
                                                  const GALGAS_string & in_signature
                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlStepInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlStepInstruction ;
}

void cPtr_gtlStepInstruction::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@gtlStepInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlStepInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlStepInstruction (mProperty_where, mProperty_signature COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlStepInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlStepInstruction ("gtlStepInstruction",
                                           & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlStepInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlStepInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlStepInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlStepInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlStepInstruction GALGAS_gtlStepInstruction::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlStepInstruction result ;
  const GALGAS_gtlStepInstruction * p = (const GALGAS_gtlStepInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlStepInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlStepInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlDoInstInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlDoInstInstruction * p = (const cPtr_gtlDoInstInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlDoInstInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_instructionToDo.objectCompare (p->mProperty_instructionToDo) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlDoInstInstruction::objectCompare (const GALGAS_gtlDoInstInstruction & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDoInstInstruction::GALGAS_gtlDoInstInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDoInstInstruction::GALGAS_gtlDoInstInstruction (const cPtr_gtlDoInstInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlDoInstInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDoInstInstruction GALGAS_gtlDoInstInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                          const GALGAS_string & inAttribute_signature,
                                                                          const GALGAS_gtlInstruction & inAttribute_instructionToDo
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlDoInstInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_instructionToDo.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlDoInstInstruction (inAttribute_where, inAttribute_signature, inAttribute_instructionToDo COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstruction GALGAS_gtlDoInstInstruction::readProperty_instructionToDo (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlInstruction () ;
  }else{
    const cPtr_gtlDoInstInstruction * p = (const cPtr_gtlDoInstInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlDoInstInstruction) ;
    return p->mProperty_instructionToDo ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstruction cPtr_gtlDoInstInstruction::getter_instructionToDo (UNUSED_LOCATION_ARGS) const {
  return mProperty_instructionToDo ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlDoInstInstruction::setter_setInstructionToDo (GALGAS_gtlInstruction inValue
                                                             COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlDoInstInstruction * p = (cPtr_gtlDoInstInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlDoInstInstruction) ;
    p->mProperty_instructionToDo = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlDoInstInstruction::setter_setInstructionToDo (GALGAS_gtlInstruction inValue
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_instructionToDo = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlDoInstInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlDoInstInstruction::cPtr_gtlDoInstInstruction (const GALGAS_location & in_where,
                                                      const GALGAS_string & in_signature,
                                                      const GALGAS_gtlInstruction & in_instructionToDo
                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_instructionToDo (in_instructionToDo) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlDoInstInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDoInstInstruction ;
}

void cPtr_gtlDoInstInstruction::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@gtlDoInstInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_instructionToDo.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlDoInstInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlDoInstInstruction (mProperty_where, mProperty_signature, mProperty_instructionToDo COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlDoInstInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlDoInstInstruction ("gtlDoInstInstruction",
                                             & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlDoInstInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDoInstInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlDoInstInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlDoInstInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDoInstInstruction GALGAS_gtlDoInstInstruction::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlDoInstInstruction result ;
  const GALGAS_gtlDoInstInstruction * p = (const GALGAS_gtlDoInstInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlDoInstInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlDoInstInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlDoNotAllInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlDoNotAllInstruction * p = (const cPtr_gtlDoNotAllInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlDoNotAllInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlDoNotAllInstruction::objectCompare (const GALGAS_gtlDoNotAllInstruction & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDoNotAllInstruction::GALGAS_gtlDoNotAllInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDoNotAllInstruction GALGAS_gtlDoNotAllInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlDoNotAllInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                         GALGAS_string::constructor_default (HERE)
                                                         COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDoNotAllInstruction::GALGAS_gtlDoNotAllInstruction (const cPtr_gtlDoNotAllInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlDoNotAllInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDoNotAllInstruction GALGAS_gtlDoNotAllInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                              const GALGAS_string & inAttribute_signature
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlDoNotAllInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlDoNotAllInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlDoNotAllInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlDoNotAllInstruction::cPtr_gtlDoNotAllInstruction (const GALGAS_location & in_where,
                                                          const GALGAS_string & in_signature
                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlDoNotAllInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDoNotAllInstruction ;
}

void cPtr_gtlDoNotAllInstruction::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@gtlDoNotAllInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlDoNotAllInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlDoNotAllInstruction (mProperty_where, mProperty_signature COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlDoNotAllInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlDoNotAllInstruction ("gtlDoNotAllInstruction",
                                               & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlDoNotAllInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDoNotAllInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlDoNotAllInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlDoNotAllInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDoNotAllInstruction GALGAS_gtlDoNotAllInstruction::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlDoNotAllInstruction result ;
  const GALGAS_gtlDoNotAllInstruction * p = (const GALGAS_gtlDoNotAllInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlDoNotAllInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlDoNotAllInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlDoInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlDoInstruction * p = (const cPtr_gtlDoInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlDoInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlDoInstruction::objectCompare (const GALGAS_gtlDoInstruction & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDoInstruction::GALGAS_gtlDoInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDoInstruction GALGAS_gtlDoInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlDoInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                   GALGAS_string::constructor_default (HERE)
                                                   COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDoInstruction::GALGAS_gtlDoInstruction (const cPtr_gtlDoInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlDoInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDoInstruction GALGAS_gtlDoInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                  const GALGAS_string & inAttribute_signature
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlDoInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlDoInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlDoInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlDoInstruction::cPtr_gtlDoInstruction (const GALGAS_location & in_where,
                                              const GALGAS_string & in_signature
                                              COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlDoInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDoInstruction ;
}

void cPtr_gtlDoInstruction::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@gtlDoInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlDoInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlDoInstruction (mProperty_where, mProperty_signature COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlDoInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlDoInstruction ("gtlDoInstruction",
                                         & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlDoInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDoInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlDoInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlDoInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDoInstruction GALGAS_gtlDoInstruction::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlDoInstruction result ;
  const GALGAS_gtlDoInstruction * p = (const GALGAS_gtlDoInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlDoInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlDoInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlContinueInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlContinueInstruction * p = (const cPtr_gtlContinueInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlContinueInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlContinueInstruction::objectCompare (const GALGAS_gtlContinueInstruction & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlContinueInstruction::GALGAS_gtlContinueInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlContinueInstruction GALGAS_gtlContinueInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlContinueInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                         GALGAS_string::constructor_default (HERE)
                                                         COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlContinueInstruction::GALGAS_gtlContinueInstruction (const cPtr_gtlContinueInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlContinueInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlContinueInstruction GALGAS_gtlContinueInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                              const GALGAS_string & inAttribute_signature
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlContinueInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlContinueInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlContinueInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlContinueInstruction::cPtr_gtlContinueInstruction (const GALGAS_location & in_where,
                                                          const GALGAS_string & in_signature
                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlContinueInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlContinueInstruction ;
}

void cPtr_gtlContinueInstruction::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@gtlContinueInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlContinueInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlContinueInstruction (mProperty_where, mProperty_signature COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlContinueInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlContinueInstruction ("gtlContinueInstruction",
                                               & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlContinueInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlContinueInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlContinueInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlContinueInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlContinueInstruction GALGAS_gtlContinueInstruction::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlContinueInstruction result ;
  const GALGAS_gtlContinueInstruction * p = (const GALGAS_gtlContinueInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlContinueInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlContinueInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlBreakpointInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlBreakpointInstruction * p = (const cPtr_gtlBreakpointInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlBreakpointInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_fileName.objectCompare (p->mProperty_fileName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lineNum.objectCompare (p->mProperty_lineNum) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlBreakpointInstruction::objectCompare (const GALGAS_gtlBreakpointInstruction & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointInstruction::GALGAS_gtlBreakpointInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointInstruction GALGAS_gtlBreakpointInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlBreakpointInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_string::constructor_default (HERE),
                                                           GALGAS_string::constructor_default (HERE),
                                                           GALGAS_uint::constructor_default (HERE)
                                                           COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointInstruction::GALGAS_gtlBreakpointInstruction (const cPtr_gtlBreakpointInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlBreakpointInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointInstruction GALGAS_gtlBreakpointInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                  const GALGAS_string & inAttribute_signature,
                                                                                  const GALGAS_string & inAttribute_fileName,
                                                                                  const GALGAS_uint & inAttribute_lineNum
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_fileName.isValid () && inAttribute_lineNum.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlBreakpointInstruction (inAttribute_where, inAttribute_signature, inAttribute_fileName, inAttribute_lineNum COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_gtlBreakpointInstruction::readProperty_fileName (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_gtlBreakpointInstruction * p = (const cPtr_gtlBreakpointInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpointInstruction) ;
    return p->mProperty_fileName ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlBreakpointInstruction::getter_fileName (UNUSED_LOCATION_ARGS) const {
  return mProperty_fileName ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_gtlBreakpointInstruction::readProperty_lineNum (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    const cPtr_gtlBreakpointInstruction * p = (const cPtr_gtlBreakpointInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpointInstruction) ;
    return p->mProperty_lineNum ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_gtlBreakpointInstruction::getter_lineNum (UNUSED_LOCATION_ARGS) const {
  return mProperty_lineNum ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpointInstruction::setter_setFileName (GALGAS_string inValue
                                                          COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlBreakpointInstruction * p = (cPtr_gtlBreakpointInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpointInstruction) ;
    p->mProperty_fileName = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointInstruction::setter_setFileName (GALGAS_string inValue
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_fileName = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpointInstruction::setter_setLineNum (GALGAS_uint inValue
                                                         COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlBreakpointInstruction * p = (cPtr_gtlBreakpointInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpointInstruction) ;
    p->mProperty_lineNum = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointInstruction::setter_setLineNum (GALGAS_uint inValue
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_lineNum = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlBreakpointInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlBreakpointInstruction::cPtr_gtlBreakpointInstruction (const GALGAS_location & in_where,
                                                              const GALGAS_string & in_signature,
                                                              const GALGAS_string & in_fileName,
                                                              const GALGAS_uint & in_lineNum
                                                              COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_fileName (in_fileName),
mProperty_lineNum (in_lineNum) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlBreakpointInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointInstruction ;
}

void cPtr_gtlBreakpointInstruction::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@gtlBreakpointInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_fileName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lineNum.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlBreakpointInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlBreakpointInstruction (mProperty_where, mProperty_signature, mProperty_fileName, mProperty_lineNum COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlBreakpointInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlBreakpointInstruction ("gtlBreakpointInstruction",
                                                 & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlBreakpointInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlBreakpointInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlBreakpointInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointInstruction GALGAS_gtlBreakpointInstruction::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointInstruction result ;
  const GALGAS_gtlBreakpointInstruction * p = (const GALGAS_gtlBreakpointInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlBreakpointInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlBreakpointInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlBreakpointListInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlBreakpointListInstruction * p = (const cPtr_gtlBreakpointListInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlBreakpointListInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlBreakpointListInstruction::objectCompare (const GALGAS_gtlBreakpointListInstruction & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointListInstruction::GALGAS_gtlBreakpointListInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointListInstruction GALGAS_gtlBreakpointListInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlBreakpointListInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                               GALGAS_string::constructor_default (HERE)
                                                               COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointListInstruction::GALGAS_gtlBreakpointListInstruction (const cPtr_gtlBreakpointListInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlBreakpointListInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointListInstruction GALGAS_gtlBreakpointListInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                          const GALGAS_string & inAttribute_signature
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointListInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlBreakpointListInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlBreakpointListInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlBreakpointListInstruction::cPtr_gtlBreakpointListInstruction (const GALGAS_location & in_where,
                                                                      const GALGAS_string & in_signature
                                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlBreakpointListInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointListInstruction ;
}

void cPtr_gtlBreakpointListInstruction::description (C_String & ioString,
                                                     const int32_t inIndentation) const {
  ioString << "[@gtlBreakpointListInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlBreakpointListInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlBreakpointListInstruction (mProperty_where, mProperty_signature COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlBreakpointListInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlBreakpointListInstruction ("gtlBreakpointListInstruction",
                                                     & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlBreakpointListInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointListInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlBreakpointListInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlBreakpointListInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointListInstruction GALGAS_gtlBreakpointListInstruction::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointListInstruction result ;
  const GALGAS_gtlBreakpointListInstruction * p = (const GALGAS_gtlBreakpointListInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlBreakpointListInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlBreakpointListInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlBreakpointDeleteInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlBreakpointDeleteInstruction * p = (const cPtr_gtlBreakpointDeleteInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlBreakpointDeleteInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_numToDelete.objectCompare (p->mProperty_numToDelete) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlBreakpointDeleteInstruction::objectCompare (const GALGAS_gtlBreakpointDeleteInstruction & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointDeleteInstruction::GALGAS_gtlBreakpointDeleteInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointDeleteInstruction GALGAS_gtlBreakpointDeleteInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlBreakpointDeleteInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                                 GALGAS_string::constructor_default (HERE),
                                                                 GALGAS_lbigint::constructor_default (HERE)
                                                                 COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointDeleteInstruction::GALGAS_gtlBreakpointDeleteInstruction (const cPtr_gtlBreakpointDeleteInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlBreakpointDeleteInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointDeleteInstruction GALGAS_gtlBreakpointDeleteInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                              const GALGAS_string & inAttribute_signature,
                                                                                              const GALGAS_lbigint & inAttribute_numToDelete
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointDeleteInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_numToDelete.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlBreakpointDeleteInstruction (inAttribute_where, inAttribute_signature, inAttribute_numToDelete COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigint GALGAS_gtlBreakpointDeleteInstruction::readProperty_numToDelete (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lbigint () ;
  }else{
    const cPtr_gtlBreakpointDeleteInstruction * p = (const cPtr_gtlBreakpointDeleteInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpointDeleteInstruction) ;
    return p->mProperty_numToDelete ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigint cPtr_gtlBreakpointDeleteInstruction::getter_numToDelete (UNUSED_LOCATION_ARGS) const {
  return mProperty_numToDelete ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpointDeleteInstruction::setter_setNumToDelete (GALGAS_lbigint inValue
                                                                   COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlBreakpointDeleteInstruction * p = (cPtr_gtlBreakpointDeleteInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpointDeleteInstruction) ;
    p->mProperty_numToDelete = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointDeleteInstruction::setter_setNumToDelete (GALGAS_lbigint inValue
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_numToDelete = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlBreakpointDeleteInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlBreakpointDeleteInstruction::cPtr_gtlBreakpointDeleteInstruction (const GALGAS_location & in_where,
                                                                          const GALGAS_string & in_signature,
                                                                          const GALGAS_lbigint & in_numToDelete
                                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_numToDelete (in_numToDelete) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlBreakpointDeleteInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointDeleteInstruction ;
}

void cPtr_gtlBreakpointDeleteInstruction::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "[@gtlBreakpointDeleteInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_numToDelete.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlBreakpointDeleteInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlBreakpointDeleteInstruction (mProperty_where, mProperty_signature, mProperty_numToDelete COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlBreakpointDeleteInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlBreakpointDeleteInstruction ("gtlBreakpointDeleteInstruction",
                                                       & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlBreakpointDeleteInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointDeleteInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlBreakpointDeleteInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlBreakpointDeleteInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointDeleteInstruction GALGAS_gtlBreakpointDeleteInstruction::extractObject (const GALGAS_object & inObject,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointDeleteInstruction result ;
  const GALGAS_gtlBreakpointDeleteInstruction * p = (const GALGAS_gtlBreakpointDeleteInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlBreakpointDeleteInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlBreakpointDeleteInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlBreakpointDeleteAllInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlBreakpointDeleteAllInstruction * p = (const cPtr_gtlBreakpointDeleteAllInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlBreakpointDeleteAllInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlBreakpointDeleteAllInstruction::objectCompare (const GALGAS_gtlBreakpointDeleteAllInstruction & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointDeleteAllInstruction::GALGAS_gtlBreakpointDeleteAllInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointDeleteAllInstruction GALGAS_gtlBreakpointDeleteAllInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlBreakpointDeleteAllInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                                    GALGAS_string::constructor_default (HERE)
                                                                    COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointDeleteAllInstruction::GALGAS_gtlBreakpointDeleteAllInstruction (const cPtr_gtlBreakpointDeleteAllInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlBreakpointDeleteAllInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointDeleteAllInstruction GALGAS_gtlBreakpointDeleteAllInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                                    const GALGAS_string & inAttribute_signature
                                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointDeleteAllInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlBreakpointDeleteAllInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlBreakpointDeleteAllInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlBreakpointDeleteAllInstruction::cPtr_gtlBreakpointDeleteAllInstruction (const GALGAS_location & in_where,
                                                                                const GALGAS_string & in_signature
                                                                                COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlBreakpointDeleteAllInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointDeleteAllInstruction ;
}

void cPtr_gtlBreakpointDeleteAllInstruction::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "[@gtlBreakpointDeleteAllInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlBreakpointDeleteAllInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlBreakpointDeleteAllInstruction (mProperty_where, mProperty_signature COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlBreakpointDeleteAllInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlBreakpointDeleteAllInstruction ("gtlBreakpointDeleteAllInstruction",
                                                          & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlBreakpointDeleteAllInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointDeleteAllInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlBreakpointDeleteAllInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlBreakpointDeleteAllInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointDeleteAllInstruction GALGAS_gtlBreakpointDeleteAllInstruction::extractObject (const GALGAS_object & inObject,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointDeleteAllInstruction result ;
  const GALGAS_gtlBreakpointDeleteAllInstruction * p = (const GALGAS_gtlBreakpointDeleteAllInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlBreakpointDeleteAllInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlBreakpointDeleteAllInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlWatchpointListInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlWatchpointListInstruction * p = (const cPtr_gtlWatchpointListInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlWatchpointListInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlWatchpointListInstruction::objectCompare (const GALGAS_gtlWatchpointListInstruction & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointListInstruction::GALGAS_gtlWatchpointListInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointListInstruction GALGAS_gtlWatchpointListInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlWatchpointListInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                               GALGAS_string::constructor_default (HERE)
                                                               COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointListInstruction::GALGAS_gtlWatchpointListInstruction (const cPtr_gtlWatchpointListInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlWatchpointListInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointListInstruction GALGAS_gtlWatchpointListInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                          const GALGAS_string & inAttribute_signature
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlWatchpointListInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlWatchpointListInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlWatchpointListInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlWatchpointListInstruction::cPtr_gtlWatchpointListInstruction (const GALGAS_location & in_where,
                                                                      const GALGAS_string & in_signature
                                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlWatchpointListInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlWatchpointListInstruction ;
}

void cPtr_gtlWatchpointListInstruction::description (C_String & ioString,
                                                     const int32_t inIndentation) const {
  ioString << "[@gtlWatchpointListInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlWatchpointListInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlWatchpointListInstruction (mProperty_where, mProperty_signature COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlWatchpointListInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlWatchpointListInstruction ("gtlWatchpointListInstruction",
                                                     & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlWatchpointListInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlWatchpointListInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlWatchpointListInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlWatchpointListInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointListInstruction GALGAS_gtlWatchpointListInstruction::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlWatchpointListInstruction result ;
  const GALGAS_gtlWatchpointListInstruction * p = (const GALGAS_gtlWatchpointListInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlWatchpointListInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlWatchpointListInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlWatchpointDeleteInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlWatchpointDeleteInstruction * p = (const cPtr_gtlWatchpointDeleteInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlWatchpointDeleteInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_numToDelete.objectCompare (p->mProperty_numToDelete) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlWatchpointDeleteInstruction::objectCompare (const GALGAS_gtlWatchpointDeleteInstruction & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointDeleteInstruction::GALGAS_gtlWatchpointDeleteInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointDeleteInstruction GALGAS_gtlWatchpointDeleteInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlWatchpointDeleteInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                                 GALGAS_string::constructor_default (HERE),
                                                                 GALGAS_lbigint::constructor_default (HERE)
                                                                 COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointDeleteInstruction::GALGAS_gtlWatchpointDeleteInstruction (const cPtr_gtlWatchpointDeleteInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlWatchpointDeleteInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointDeleteInstruction GALGAS_gtlWatchpointDeleteInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                              const GALGAS_string & inAttribute_signature,
                                                                                              const GALGAS_lbigint & inAttribute_numToDelete
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlWatchpointDeleteInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_numToDelete.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlWatchpointDeleteInstruction (inAttribute_where, inAttribute_signature, inAttribute_numToDelete COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigint GALGAS_gtlWatchpointDeleteInstruction::readProperty_numToDelete (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lbigint () ;
  }else{
    const cPtr_gtlWatchpointDeleteInstruction * p = (const cPtr_gtlWatchpointDeleteInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWatchpointDeleteInstruction) ;
    return p->mProperty_numToDelete ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigint cPtr_gtlWatchpointDeleteInstruction::getter_numToDelete (UNUSED_LOCATION_ARGS) const {
  return mProperty_numToDelete ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlWatchpointDeleteInstruction::setter_setNumToDelete (GALGAS_lbigint inValue
                                                                   COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlWatchpointDeleteInstruction * p = (cPtr_gtlWatchpointDeleteInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWatchpointDeleteInstruction) ;
    p->mProperty_numToDelete = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointDeleteInstruction::setter_setNumToDelete (GALGAS_lbigint inValue
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_numToDelete = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlWatchpointDeleteInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlWatchpointDeleteInstruction::cPtr_gtlWatchpointDeleteInstruction (const GALGAS_location & in_where,
                                                                          const GALGAS_string & in_signature,
                                                                          const GALGAS_lbigint & in_numToDelete
                                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_numToDelete (in_numToDelete) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlWatchpointDeleteInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlWatchpointDeleteInstruction ;
}

void cPtr_gtlWatchpointDeleteInstruction::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "[@gtlWatchpointDeleteInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_numToDelete.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlWatchpointDeleteInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlWatchpointDeleteInstruction (mProperty_where, mProperty_signature, mProperty_numToDelete COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlWatchpointDeleteInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlWatchpointDeleteInstruction ("gtlWatchpointDeleteInstruction",
                                                       & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlWatchpointDeleteInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlWatchpointDeleteInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlWatchpointDeleteInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlWatchpointDeleteInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointDeleteInstruction GALGAS_gtlWatchpointDeleteInstruction::extractObject (const GALGAS_object & inObject,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlWatchpointDeleteInstruction result ;
  const GALGAS_gtlWatchpointDeleteInstruction * p = (const GALGAS_gtlWatchpointDeleteInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlWatchpointDeleteInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlWatchpointDeleteInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlWatchpointDeleteAllInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlWatchpointDeleteAllInstruction * p = (const cPtr_gtlWatchpointDeleteAllInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlWatchpointDeleteAllInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlWatchpointDeleteAllInstruction::objectCompare (const GALGAS_gtlWatchpointDeleteAllInstruction & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointDeleteAllInstruction::GALGAS_gtlWatchpointDeleteAllInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointDeleteAllInstruction GALGAS_gtlWatchpointDeleteAllInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlWatchpointDeleteAllInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                                    GALGAS_string::constructor_default (HERE)
                                                                    COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointDeleteAllInstruction::GALGAS_gtlWatchpointDeleteAllInstruction (const cPtr_gtlWatchpointDeleteAllInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlWatchpointDeleteAllInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointDeleteAllInstruction GALGAS_gtlWatchpointDeleteAllInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                                    const GALGAS_string & inAttribute_signature
                                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlWatchpointDeleteAllInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlWatchpointDeleteAllInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlWatchpointDeleteAllInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlWatchpointDeleteAllInstruction::cPtr_gtlWatchpointDeleteAllInstruction (const GALGAS_location & in_where,
                                                                                const GALGAS_string & in_signature
                                                                                COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlWatchpointDeleteAllInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlWatchpointDeleteAllInstruction ;
}

void cPtr_gtlWatchpointDeleteAllInstruction::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "[@gtlWatchpointDeleteAllInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlWatchpointDeleteAllInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlWatchpointDeleteAllInstruction (mProperty_where, mProperty_signature COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlWatchpointDeleteAllInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlWatchpointDeleteAllInstruction ("gtlWatchpointDeleteAllInstruction",
                                                          & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlWatchpointDeleteAllInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlWatchpointDeleteAllInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlWatchpointDeleteAllInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlWatchpointDeleteAllInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointDeleteAllInstruction GALGAS_gtlWatchpointDeleteAllInstruction::extractObject (const GALGAS_object & inObject,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlWatchpointDeleteAllInstruction result ;
  const GALGAS_gtlWatchpointDeleteAllInstruction * p = (const GALGAS_gtlWatchpointDeleteAllInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlWatchpointDeleteAllInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlWatchpointDeleteAllInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlListInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlListInstruction * p = (const cPtr_gtlListInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlListInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_window.objectCompare (p->mProperty_window) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlListInstruction::objectCompare (const GALGAS_gtlListInstruction & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlListInstruction::GALGAS_gtlListInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlListInstruction GALGAS_gtlListInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlListInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                     GALGAS_string::constructor_default (HERE),
                                                     GALGAS_uint::constructor_default (HERE)
                                                     COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlListInstruction::GALGAS_gtlListInstruction (const cPtr_gtlListInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlListInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlListInstruction GALGAS_gtlListInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                      const GALGAS_string & inAttribute_signature,
                                                                      const GALGAS_uint & inAttribute_window
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlListInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_window.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlListInstruction (inAttribute_where, inAttribute_signature, inAttribute_window COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_gtlListInstruction::readProperty_window (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    const cPtr_gtlListInstruction * p = (const cPtr_gtlListInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlListInstruction) ;
    return p->mProperty_window ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_gtlListInstruction::getter_window (UNUSED_LOCATION_ARGS) const {
  return mProperty_window ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlListInstruction::setter_setWindow (GALGAS_uint inValue
                                                  COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlListInstruction * p = (cPtr_gtlListInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlListInstruction) ;
    p->mProperty_window = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlListInstruction::setter_setWindow (GALGAS_uint inValue
                                                COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_window = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlListInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlListInstruction::cPtr_gtlListInstruction (const GALGAS_location & in_where,
                                                  const GALGAS_string & in_signature,
                                                  const GALGAS_uint & in_window
                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_window (in_window) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlListInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlListInstruction ;
}

void cPtr_gtlListInstruction::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@gtlListInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_window.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlListInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlListInstruction (mProperty_where, mProperty_signature, mProperty_window COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlListInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlListInstruction ("gtlListInstruction",
                                           & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlListInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlListInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlListInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlListInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlListInstruction GALGAS_gtlListInstruction::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlListInstruction result ;
  const GALGAS_gtlListInstruction * p = (const GALGAS_gtlListInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlListInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlListInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlHistoryInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlHistoryInstruction * p = (const cPtr_gtlHistoryInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlHistoryInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlHistoryInstruction::objectCompare (const GALGAS_gtlHistoryInstruction & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlHistoryInstruction::GALGAS_gtlHistoryInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlHistoryInstruction GALGAS_gtlHistoryInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlHistoryInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                        GALGAS_string::constructor_default (HERE)
                                                        COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlHistoryInstruction::GALGAS_gtlHistoryInstruction (const cPtr_gtlHistoryInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlHistoryInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlHistoryInstruction GALGAS_gtlHistoryInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                            const GALGAS_string & inAttribute_signature
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlHistoryInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlHistoryInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlHistoryInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlHistoryInstruction::cPtr_gtlHistoryInstruction (const GALGAS_location & in_where,
                                                        const GALGAS_string & in_signature
                                                        COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlHistoryInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlHistoryInstruction ;
}

void cPtr_gtlHistoryInstruction::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@gtlHistoryInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlHistoryInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlHistoryInstruction (mProperty_where, mProperty_signature COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlHistoryInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlHistoryInstruction ("gtlHistoryInstruction",
                                              & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlHistoryInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlHistoryInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlHistoryInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlHistoryInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlHistoryInstruction GALGAS_gtlHistoryInstruction::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlHistoryInstruction result ;
  const GALGAS_gtlHistoryInstruction * p = (const GALGAS_gtlHistoryInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlHistoryInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlHistoryInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLoadInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLoadInstruction * p = (const cPtr_gtlLoadInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLoadInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_fileName.objectCompare (p->mProperty_fileName) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlLoadInstruction::objectCompare (const GALGAS_gtlLoadInstruction & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLoadInstruction::GALGAS_gtlLoadInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLoadInstruction GALGAS_gtlLoadInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlLoadInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                     GALGAS_string::constructor_default (HERE),
                                                     GALGAS_string::constructor_default (HERE)
                                                     COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLoadInstruction::GALGAS_gtlLoadInstruction (const cPtr_gtlLoadInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLoadInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLoadInstruction GALGAS_gtlLoadInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                      const GALGAS_string & inAttribute_signature,
                                                                      const GALGAS_string & inAttribute_fileName
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlLoadInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_fileName.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLoadInstruction (inAttribute_where, inAttribute_signature, inAttribute_fileName COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_gtlLoadInstruction::readProperty_fileName (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_gtlLoadInstruction * p = (const cPtr_gtlLoadInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoadInstruction) ;
    return p->mProperty_fileName ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlLoadInstruction::getter_fileName (UNUSED_LOCATION_ARGS) const {
  return mProperty_fileName ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlLoadInstruction::setter_setFileName (GALGAS_string inValue
                                                    COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlLoadInstruction * p = (cPtr_gtlLoadInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoadInstruction) ;
    p->mProperty_fileName = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLoadInstruction::setter_setFileName (GALGAS_string inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_fileName = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlLoadInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlLoadInstruction::cPtr_gtlLoadInstruction (const GALGAS_location & in_where,
                                                  const GALGAS_string & in_signature,
                                                  const GALGAS_string & in_fileName
                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_fileName (in_fileName) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLoadInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLoadInstruction ;
}

void cPtr_gtlLoadInstruction::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@gtlLoadInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_fileName.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLoadInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlLoadInstruction (mProperty_where, mProperty_signature, mProperty_fileName COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlLoadInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLoadInstruction ("gtlLoadInstruction",
                                           & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLoadInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLoadInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLoadInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLoadInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLoadInstruction GALGAS_gtlLoadInstruction::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlLoadInstruction result ;
  const GALGAS_gtlLoadInstruction * p = (const GALGAS_gtlLoadInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlLoadInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLoadInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlHelpInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlHelpInstruction * p = (const cPtr_gtlHelpInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlHelpInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlHelpInstruction::objectCompare (const GALGAS_gtlHelpInstruction & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlHelpInstruction::GALGAS_gtlHelpInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlHelpInstruction GALGAS_gtlHelpInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlHelpInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                     GALGAS_string::constructor_default (HERE)
                                                     COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlHelpInstruction::GALGAS_gtlHelpInstruction (const cPtr_gtlHelpInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlHelpInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlHelpInstruction GALGAS_gtlHelpInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                      const GALGAS_string & inAttribute_signature
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlHelpInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlHelpInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlHelpInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlHelpInstruction::cPtr_gtlHelpInstruction (const GALGAS_location & in_where,
                                                  const GALGAS_string & in_signature
                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlHelpInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlHelpInstruction ;
}

void cPtr_gtlHelpInstruction::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@gtlHelpInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlHelpInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlHelpInstruction (mProperty_where, mProperty_signature COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlHelpInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlHelpInstruction ("gtlHelpInstruction",
                                           & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlHelpInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlHelpInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlHelpInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlHelpInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlHelpInstruction GALGAS_gtlHelpInstruction::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlHelpInstruction result ;
  const GALGAS_gtlHelpInstruction * p = (const GALGAS_gtlHelpInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlHelpInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlHelpInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@debugCommandInput getCommand'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_debugCommandInput_getCommand> gExtensionModifierTable_debugCommandInput_getCommand ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_getCommand (const int32_t inClassIndex,
                                      extensionSetterSignature_debugCommandInput_getCommand inModifier) {
  gExtensionModifierTable_debugCommandInput_getCommand.forceObjectAtIndex (inClassIndex, inModifier, nullptr COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_getCommand (cPtr_debugCommandInput * inObject,
                                     GALGAS_string & out_command,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
//--- Drop output arguments
  out_command.drop () ;
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debugCommandInput) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_debugCommandInput_getCommand f = nullptr ;
    if (classIndex < gExtensionModifierTable_debugCommandInput_getCommand.count ()) {
      f = gExtensionModifierTable_debugCommandInput_getCommand (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_debugCommandInput_getCommand.count ()) {
           f = gExtensionModifierTable_debugCommandInput_getCommand (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_debugCommandInput_getCommand.forceObjectAtIndex (classIndex, f, nullptr COMMA_HERE) ;
    }
    f (inObject, out_command, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_debugCommandInput_getCommand (cPtr_debugCommandInput * inObject,
                                                          GALGAS_string & outArgument_command,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_debugCommandInput * object = inObject ;
  macroValidSharedObject (object, cPtr_debugCommandInput) ;
  outArgument_command = GALGAS_string::makeEmptyString () ;
  GALGAS_string var_savedCommand_833 = GALGAS_string::makeEmptyString () ;
  GALGAS_uint var_historyIndex_859 = GALGAS_uint (uint32_t (0U)) ;
  GALGAS_char var_inputChar_884 = GALGAS_char (TO_UNICODE (13)) ;
  GALGAS_uint var_cursorPos_909 = GALGAS_uint (uint32_t (0U)) ;
  GALGAS_uint var_escapeState_931 = GALGAS_uint (uint32_t (0U)) ;
  if (GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_debugger_input.galgas", 42)).isValid ()) {
    uint32_t variant_952 = GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_debugger_input.galgas", 42)).uintValue () ;
    bool loop_952 = true ;
    while (loop_952) {
        var_inputChar_884 = GALGAS_char::constructor_unicodeCharacterFromRawKeyboard (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 43)) ;
      loop_952 = GALGAS_bool (kIsNotEqual, var_inputChar_884.objectCompare (GALGAS_char (TO_UNICODE (13)))).isValid () ;
      if (loop_952) {
        loop_952 = GALGAS_bool (kIsNotEqual, var_inputChar_884.objectCompare (GALGAS_char (TO_UNICODE (13)))).boolValue () ;
      }
      if (loop_952 && (0 == variant_952)) {
        loop_952 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_debugger_input.galgas", 42)) ;
      }
      if (loop_952) {
        variant_952 -- ;
        enumGalgasBool test_0 = kBoolTrue ;
        if (kBoolTrue == test_0) {
          test_0 = GALGAS_bool (kIsEqual, var_escapeState_931.objectCompare (GALGAS_uint (uint32_t (1U)))).operator_and (GALGAS_bool (kIsEqual, var_inputChar_884.getter_uint (SOURCE_FILE ("gtl_debugger_input.galgas", 45)).objectCompare (GALGAS_uint (uint32_t (91U)))) COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 45)).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_escapeState_931 = GALGAS_uint (uint32_t (2U)) ;
          }
        }
        if (kBoolFalse == test_0) {
          enumGalgasBool test_1 = kBoolTrue ;
          if (kBoolTrue == test_1) {
            test_1 = GALGAS_bool (kIsEqual, var_escapeState_931.objectCompare (GALGAS_uint (uint32_t (2U)))).boolEnum () ;
            if (kBoolTrue == test_1) {
              enumGalgasBool test_2 = kBoolTrue ;
              if (kBoolTrue == test_2) {
                test_2 = GALGAS_bool (kIsEqual, var_inputChar_884.getter_uint (SOURCE_FILE ("gtl_debugger_input.galgas", 49)).objectCompare (GALGAS_uint (uint32_t (68U)))).boolEnum () ;
                if (kBoolTrue == test_2) {
                  enumGalgasBool test_3 = kBoolTrue ;
                  if (kBoolTrue == test_3) {
                    test_3 = GALGAS_bool (kIsStrictSup, var_cursorPos_909.objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
                    if (kBoolTrue == test_3) {
                      var_cursorPos_909.decrement_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 52)) ;
                      inCompiler->printMessage (GALGAS_string ("[1D")  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 53)) ;
                    }
                  }
                }
              }
              if (kBoolFalse == test_2) {
                enumGalgasBool test_4 = kBoolTrue ;
                if (kBoolTrue == test_4) {
                  test_4 = GALGAS_bool (kIsEqual, var_inputChar_884.getter_uint (SOURCE_FILE ("gtl_debugger_input.galgas", 55)).objectCompare (GALGAS_uint (uint32_t (67U)))).boolEnum () ;
                  if (kBoolTrue == test_4) {
                    enumGalgasBool test_5 = kBoolTrue ;
                    if (kBoolTrue == test_5) {
                      test_5 = GALGAS_bool (kIsStrictInf, var_cursorPos_909.objectCompare (outArgument_command.getter_count (SOURCE_FILE ("gtl_debugger_input.galgas", 57)))).boolEnum () ;
                      if (kBoolTrue == test_5) {
                        var_cursorPos_909.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 58)) ;
                        inCompiler->printMessage (GALGAS_string ("[1C")  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 59)) ;
                      }
                    }
                  }
                }
                if (kBoolFalse == test_4) {
                  enumGalgasBool test_6 = kBoolTrue ;
                  if (kBoolTrue == test_6) {
                    test_6 = GALGAS_bool (kIsEqual, var_inputChar_884.getter_uint (SOURCE_FILE ("gtl_debugger_input.galgas", 61)).objectCompare (GALGAS_uint (uint32_t (65U)))).boolEnum () ;
                    if (kBoolTrue == test_6) {
                      enumGalgasBool test_7 = kBoolTrue ;
                      if (kBoolTrue == test_7) {
                        test_7 = GALGAS_bool (kIsEqual, var_historyIndex_859.objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
                        if (kBoolTrue == test_7) {
                          var_savedCommand_833 = outArgument_command ;
                        }
                      }
                      enumGalgasBool test_8 = kBoolTrue ;
                      if (kBoolTrue == test_8) {
                        test_8 = GALGAS_bool (kIsStrictInf, var_historyIndex_859.objectCompare (object->mProperty_history.getter_count (SOURCE_FILE ("gtl_debugger_input.galgas", 66)))).boolEnum () ;
                        if (kBoolTrue == test_8) {
                          enumGalgasBool test_9 = kBoolTrue ;
                          if (kBoolTrue == test_9) {
                            test_9 = GALGAS_bool (kIsStrictSup, var_cursorPos_909.objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
                            if (kBoolTrue == test_9) {
                              inCompiler->printMessage (GALGAS_string ("[").add_operation (var_cursorPos_909.getter_string (SOURCE_FILE ("gtl_debugger_input.galgas", 68)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 68)).add_operation (GALGAS_string ("D"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 68))  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 68)) ;
                            }
                          }
                          inCompiler->printMessage (GALGAS_string ("[K")  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 70)) ;
                          outArgument_command = object->mProperty_history.getter_mValueAtIndex (var_historyIndex_859, inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 71)) ;
                          inCompiler->printMessage (outArgument_command  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 72)) ;
                          var_cursorPos_909 = outArgument_command.getter_count (SOURCE_FILE ("gtl_debugger_input.galgas", 73)) ;
                          var_historyIndex_859.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 74)) ;
                        }
                      }
                    }
                  }
                  if (kBoolFalse == test_6) {
                    enumGalgasBool test_10 = kBoolTrue ;
                    if (kBoolTrue == test_10) {
                      test_10 = GALGAS_bool (kIsEqual, var_inputChar_884.getter_uint (SOURCE_FILE ("gtl_debugger_input.galgas", 76)).objectCompare (GALGAS_uint (uint32_t (66U)))).boolEnum () ;
                      if (kBoolTrue == test_10) {
                        enumGalgasBool test_11 = kBoolTrue ;
                        if (kBoolTrue == test_11) {
                          test_11 = GALGAS_bool (kIsStrictSup, var_historyIndex_859.objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
                          if (kBoolTrue == test_11) {
                            enumGalgasBool test_12 = kBoolTrue ;
                            if (kBoolTrue == test_12) {
                              test_12 = GALGAS_bool (kIsStrictSup, var_cursorPos_909.objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
                              if (kBoolTrue == test_12) {
                                inCompiler->printMessage (GALGAS_string ("[").add_operation (var_cursorPos_909.getter_string (SOURCE_FILE ("gtl_debugger_input.galgas", 80)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 80)).add_operation (GALGAS_string ("D"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 80))  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 80)) ;
                              }
                            }
                            inCompiler->printMessage (GALGAS_string ("[K")  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 82)) ;
                            var_historyIndex_859.decrement_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 83)) ;
                            enumGalgasBool test_13 = kBoolTrue ;
                            if (kBoolTrue == test_13) {
                              test_13 = GALGAS_bool (kIsEqual, var_historyIndex_859.objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
                              if (kBoolTrue == test_13) {
                                outArgument_command = var_savedCommand_833 ;
                              }
                            }
                            if (kBoolFalse == test_13) {
                              outArgument_command = object->mProperty_history.getter_mValueAtIndex (var_historyIndex_859.substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 87)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 87)) ;
                            }
                            inCompiler->printMessage (outArgument_command  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 89)) ;
                            var_cursorPos_909 = outArgument_command.getter_count (SOURCE_FILE ("gtl_debugger_input.galgas", 90)) ;
                          }
                        }
                      }
                    }
                  }
                }
              }
              var_escapeState_931 = GALGAS_uint (uint32_t (0U)) ;
            }
          }
          if (kBoolFalse == test_1) {
            enumGalgasBool test_14 = kBoolTrue ;
            if (kBoolTrue == test_14) {
              test_14 = GALGAS_bool (kIsEqual, var_inputChar_884.getter_uint (SOURCE_FILE ("gtl_debugger_input.galgas", 95)).objectCompare (GALGAS_uint (uint32_t (127U)))).boolEnum () ;
              if (kBoolTrue == test_14) {
                enumGalgasBool test_15 = kBoolTrue ;
                if (kBoolTrue == test_15) {
                  test_15 = GALGAS_bool (kIsStrictSup, var_cursorPos_909.objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
                  if (kBoolTrue == test_15) {
                    var_cursorPos_909.decrement_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 98)) ;
                    {
                    GALGAS_char joker_2684 ; // Joker input parameter
                    outArgument_command.setter_removeCharacterAtIndex (joker_2684, var_cursorPos_909, inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 99)) ;
                    }
                    inCompiler->printMessage (GALGAS_string ("[1D[K")  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 100)) ;
                    GALGAS_uint var_remainingChars_2757 = outArgument_command.getter_count (SOURCE_FILE ("gtl_debugger_input.galgas", 101)).substract_operation (var_cursorPos_909, inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 101)) ;
                    enumGalgasBool test_16 = kBoolTrue ;
                    if (kBoolTrue == test_16) {
                      test_16 = GALGAS_bool (kIsStrictSup, var_remainingChars_2757.objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
                      if (kBoolTrue == test_16) {
                        inCompiler->printMessage (outArgument_command.getter_rightSubString (var_remainingChars_2757 COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 103))  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 103)) ;
                        inCompiler->printMessage (GALGAS_string ("[").add_operation (var_remainingChars_2757.getter_string (SOURCE_FILE ("gtl_debugger_input.galgas", 104)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 104)).add_operation (GALGAS_string ("D"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 104))  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 104)) ;
                      }
                    }
                  }
                }
                inCompiler->printMessage (var_inputChar_884.getter_string (SOURCE_FILE ("gtl_debugger_input.galgas", 107))  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 107)) ;
              }
            }
            if (kBoolFalse == test_14) {
              enumGalgasBool test_17 = kBoolTrue ;
              if (kBoolTrue == test_17) {
                test_17 = GALGAS_bool (kIsEqual, var_inputChar_884.getter_uint (SOURCE_FILE ("gtl_debugger_input.galgas", 108)).objectCompare (GALGAS_uint (uint32_t (27U)))).boolEnum () ;
                if (kBoolTrue == test_17) {
                  var_escapeState_931 = GALGAS_uint (uint32_t (1U)) ;
                }
              }
              if (kBoolFalse == test_17) {
                enumGalgasBool test_18 = kBoolTrue ;
                if (kBoolTrue == test_18) {
                  test_18 = GALGAS_bool (kIsNotEqual, var_inputChar_884.objectCompare (GALGAS_char (TO_UNICODE (0)))).boolEnum () ;
                  if (kBoolTrue == test_18) {
                    enumGalgasBool test_19 = kBoolTrue ;
                    if (kBoolTrue == test_19) {
                      test_19 = GALGAS_bool (kIsEqual, var_cursorPos_909.objectCompare (outArgument_command.getter_count (SOURCE_FILE ("gtl_debugger_input.galgas", 112)))).boolEnum () ;
                      if (kBoolTrue == test_19) {
                        outArgument_command = outArgument_command.add_operation (var_inputChar_884.getter_string (SOURCE_FILE ("gtl_debugger_input.galgas", 113)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 113)) ;
                        inCompiler->printMessage (var_inputChar_884.getter_string (SOURCE_FILE ("gtl_debugger_input.galgas", 114))  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 114)) ;
                        var_cursorPos_909.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 115)) ;
                      }
                    }
                    if (kBoolFalse == test_19) {
                      {
                      outArgument_command.setter_insertCharacterAtIndex (var_inputChar_884, var_cursorPos_909, inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 117)) ;
                      }
                      inCompiler->printMessage (var_inputChar_884.getter_string (SOURCE_FILE ("gtl_debugger_input.galgas", 118))  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 118)) ;
                      var_cursorPos_909.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 119)) ;
                      GALGAS_uint var_remainingChars_3441 = outArgument_command.getter_count (SOURCE_FILE ("gtl_debugger_input.galgas", 120)).substract_operation (var_cursorPos_909, inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 120)) ;
                      enumGalgasBool test_20 = kBoolTrue ;
                      if (kBoolTrue == test_20) {
                        test_20 = GALGAS_bool (kIsStrictSup, var_remainingChars_3441.objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
                        if (kBoolTrue == test_20) {
                          inCompiler->printMessage (outArgument_command.getter_rightSubString (var_remainingChars_3441 COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 122))  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 122)) ;
                          inCompiler->printMessage (GALGAS_string ("[").add_operation (var_remainingChars_3441.getter_string (SOURCE_FILE ("gtl_debugger_input.galgas", 123)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 123)).add_operation (GALGAS_string ("D"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 123))  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 123)) ;
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
  inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 143)) ;
  enumGalgasBool test_21 = kBoolTrue ;
  if (kBoolTrue == test_21) {
    test_21 = GALGAS_bool (kIsNotEqual, outArgument_command.getter_stringByTrimmingWhiteSpaces (SOURCE_FILE ("gtl_debugger_input.galgas", 144)).objectCompare (GALGAS_string ("hist"))).boolEnum () ;
    if (kBoolTrue == test_21) {
      {
      object->mProperty_history.setter_insertAtIndex (outArgument_command, GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 145)) ;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_debugCommandInput_getCommand (void) {
  enterExtensionSetter_getCommand (kTypeDescriptor_GALGAS_debugCommandInput.mSlotID,
                                   extensionSetter_debugCommandInput_getCommand) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_debugCommandInput_getCommand (void) {
  gExtensionModifierTable_debugCommandInput_getCommand.removeAll () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_debugCommandInput_getCommand (defineExtensionSetter_debugCommandInput_getCommand,
                                                         freeExtensionModifier_debugCommandInput_getCommand) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@debugCommandInput listHistory'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_debugCommandInput::method_listHistory (C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, this->mProperty_history.getter_count (SOURCE_FILE ("gtl_debugger_input.galgas", 151)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      inCompiler->printMessage (GALGAS_string ("Command history:\n")  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 152)) ;
      cEnumerator_stringlist enumerator_4325 (this->mProperty_history, kENUMERATION_UP) ;
      GALGAS_uint index_4320 ((uint32_t) 0) ;
      while (enumerator_4325.hasCurrentObject ()) {
        inCompiler->printMessage (index_4320.getter_string (SOURCE_FILE ("gtl_debugger_input.galgas", 154)).getter_stringByLeftPadding (GALGAS_uint (uint32_t (4U)), GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 154)).add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 154)).add_operation (enumerator_4325.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 154)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 154))  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 154)) ;
        enumerator_4325.gotoNextObject () ;
        index_4320.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 153)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    inCompiler->printMessage (GALGAS_string ("Command history empty.\n")  COMMA_SOURCE_FILE ("gtl_debugger_input.galgas", 157)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_listHistory (cPtr_debugCommandInput * inObject,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debugCommandInput) ;
    inObject->method_listHistory  (inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//     L E X I Q U E                                                                             
//
//----------------------------------------------------------------------------------------------------------------------

#include "strings/unicode_character_cpp.h"
#include "galgas2/scanner_actions.h"
#include "galgas2/cLexiqueIntrospection.h"

//----------------------------------------------------------------------------------------------------------------------

cTokenFor_gtl_5F_debugger_5F_scanner::cTokenFor_gtl_5F_debugger_5F_scanner (void) :
mLexicalAttribute_a_5F_string (),
mLexicalAttribute_charValue (),
mLexicalAttribute_floatValue (),
mLexicalAttribute_functionContent (),
mLexicalAttribute_identifierString (),
mLexicalAttribute_intValue (),
mLexicalAttribute_tokenString (),
mLexicalAttribute_uint_33__32_value () {
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique_gtl_5F_debugger_5F_scanner::C_Lexique_gtl_5F_debugger_5F_scanner (C_Compiler * inCallerCompiler,
                                                                            const C_String & inSourceFileName
                                                                            COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceFileName COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique_gtl_5F_debugger_5F_scanner::C_Lexique_gtl_5F_debugger_5F_scanner (C_Compiler * inCallerCompiler,
                                                                            const C_String & inSourceString,
                                                                            const C_String & inStringForError
                                                                            COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------
//                        Lexical error message list                                             
//----------------------------------------------------------------------------------------------------------------------

static const char * gLexicalMessage_gtl_5F_debugger_5F_scanner_floatNumberConversionError = "invalid float number" ;

static const char * gLexicalMessage_gtl_5F_debugger_5F_scanner_incorrectCharConstant = "incorrect literal character" ;

static const char * gLexicalMessage_gtl_5F_debugger_5F_scanner_incorrectHTMLescapeSequence = "Invalid HTML sequence, should be '&...;'" ;

static const char * gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError = "internal error" ;

static const char * gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition4 = "\\u should be followed by exactly four hexadecimal digits" ;

static const char * gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 = "\\U should be followed by exactly eight hexadecimal digits" ;

static const char * gLexicalMessage_gtl_5F_debugger_5F_scanner_unassignedUnicodeValue = "this value does not correspond to an assigned Unicode point" ;

static const char * gLexicalMessage_gtl_5F_debugger_5F_scanner_unknownHTMLescapeSequence = "Invalid &...; HTML sequence" ;

static const char * gLexicalMessage_gtl_5F_debugger_5F_scanner_unterminatedLitteralString = "Unterminated literal string" ;

//----------------------------------------------------------------------------------------------------------------------
//                getMessageForTerminal                                                          
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_gtl_5F_debugger_5F_scanner::getMessageForTerminal (const int32_t inTerminalIndex) const {
  C_String result = "<unknown>" ;
  if ((inTerminalIndex >= 0) && (inTerminalIndex < 96)) {
    static const char * syntaxErrorMessageArray [96] = {kEndOfSourceLexicalErrorMessage,
        "an identifier",
        "a literal enum value",
        "a float number",
        "a bigint decimal number",
        "the - delimitor",
        "the '.' delimitor",
        "the '.=' delimitor",
        "the '...' delimitor",
        "a character constant",
        "literal string",
        "a comment",
        "the 'default' keyword",
        "the 'display' keyword",
        "the 'do' keyword",
        "the 'emptylist' keyword",
        "the 'emptymap' keyword",
        "the 'exists' keyword",
        "the 'false' keyword",
        "the 'list' keyword",
        "the 'import' keyword",
        "the 'listof' keyword",
        "the 'let' keyword",
        "the 'mapof' keyword",
        "the 'mod' keyword",
        "the 'no' keyword",
        "the 'not' keyword",
        "the 'or' keyword",
        "the 'print' keyword",
        "the 'sort' keyword",
        "the 'step' keyword",
        "the 'true' keyword",
        "the 'typeof' keyword",
        "the 'yes' keyword",
        "the 'variables' keyword",
        "the 'unlet' keyword",
        "the 'libraries' keyword",
        "the 'break' keyword",
        "the 'watch' keyword",
        "the 'by' keyword",
        "the 'end' keyword",
        "the 'cont' keyword",
        "the 'continue' keyword",
        "the 'help' keyword",
        "the 'if' keyword",
        "the 'then' keyword",
        "the 'else' keyword",
        "the 'elsif' keyword",
        "the 'hist' keyword",
        "the 'all' keyword",
        "the 'load' keyword",
        "the '*' delimitor",
        "the '|' delimitor",
        "the ',' delimitor",
        "the '+' delimitor",
        "the '::' delimitor",
        "the '>' delimitor",
        "the ':' delimitor",
        "the '(' delimitor",
        "the ')' delimitor",
        "the '->' delimitor",
        "the '\?' delimitor",
        "the '==' delimitor",
        "the '!' delimitor",
        "the ':=' delimitor",
        "the '[' delimitor",
        "the ']' delimitor",
        "the '+=' delimitor",
        "the '-=' delimitor",
        "the '/' delimitor",
        "the '!=' delimitor",
        "the '>=' delimitor",
        "the '&' delimitor",
        "the '<=' delimitor",
        "the '{' delimitor",
        "the '}' delimitor",
        "the '<' delimitor",
        "the '^' delimitor",
        "the '>>' delimitor",
        "the '~' delimitor",
        "the '<-' delimitor",
        "the '<<' delimitor",
        "the '@' delimitor",
        "the '*=' delimitor",
        "the '/=' delimitor",
        "the '&=' delimitor",
        "the '|=' delimitor",
        "the '<<=' delimitor",
        "the '>>=' delimitor",
        "the 'mod=' delimitor",
        "the '^=' delimitor",
        "the '@[' delimitor",
        "the '@(' delimitor",
        "the '@{' delimitor",
        "the '[!' delimitor",
        "the '@!' delimitor"
    } ;
    result = syntaxErrorMessageArray [inTerminalIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                      U N I C O D E    S T R I N G S                                           
//----------------------------------------------------------------------------------------------------------------------

//--- Unicode string for '$_21_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__21_ [] = {
  TO_UNICODE ('!'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_21__3D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__21__3D_ [] = {
  TO_UNICODE ('!'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__26_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26__3D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__26__3D_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_28_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__28_ [] = {
  TO_UNICODE ('('),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_29_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__29_ [] = {
  TO_UNICODE (')'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2A_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__2A_ [] = {
  TO_UNICODE ('*'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2A__3D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__2A__3D_ [] = {
  TO_UNICODE ('*'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2B_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__2B_ [] = {
  TO_UNICODE ('+'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2B__3D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__2B__3D_ [] = {
  TO_UNICODE ('+'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2C_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__2C_ [] = {
  TO_UNICODE (','),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D__3D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__2D__3D_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D__3E_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__2D__3E_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2E__2E_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__2E__2E_ [] = {
  TO_UNICODE ('.'),
  TO_UNICODE ('.'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2F_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__2F_ [] = {
  TO_UNICODE ('/'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2F__3D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__2F__3D_ [] = {
  TO_UNICODE ('/'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_30_X$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__30_X [] = {
  TO_UNICODE ('0'),
  TO_UNICODE ('X'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_30_x$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__30_x [] = {
  TO_UNICODE ('0'),
  TO_UNICODE ('x'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3A_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__3A_ [] = {
  TO_UNICODE (':'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3A__3A_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__3A__3A_ [] = {
  TO_UNICODE (':'),
  TO_UNICODE (':'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3A__3D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__3A__3D_ [] = {
  TO_UNICODE (':'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3B_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__3B_ [] = {
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__3C_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__2D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__3C__2D_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('-'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__3C_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__3C__3C_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('<'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__3C__3D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__3C__3C__3D_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('<'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__3D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__3C__3D_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__3D_ [] = {
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3D__3D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__3D__3D_ [] = {
  TO_UNICODE ('='),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__3E_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E__3D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__3E__3D_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E__3E_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__3E__3E_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E__3E__3D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__3E__3E__3D_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE ('>'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3F_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__3F_ [] = {
  TO_UNICODE ('\?'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_40_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__40_ [] = {
  TO_UNICODE ('@'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_40__21_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__40__21_ [] = {
  TO_UNICODE ('@'),
  TO_UNICODE ('!'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_40__28_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__40__28_ [] = {
  TO_UNICODE ('@'),
  TO_UNICODE ('('),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_40__5B_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__40__5B_ [] = {
  TO_UNICODE ('@'),
  TO_UNICODE ('['),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_40__7B_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__40__7B_ [] = {
  TO_UNICODE ('@'),
  TO_UNICODE ('{'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5B_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__5B_ [] = {
  TO_UNICODE ('['),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5B__21_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__5B__21_ [] = {
  TO_UNICODE ('['),
  TO_UNICODE ('!'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__5D_ [] = {
  TO_UNICODE (']'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5E_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__5E_ [] = {
  TO_UNICODE ('^'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5E__3D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__5E__3D_ [] = {
  TO_UNICODE ('^'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$all$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_all [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('l'),
  TO_UNICODE ('l'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$break$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_break [] = {
  TO_UNICODE ('b'),
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('a'),
  TO_UNICODE ('k'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$by$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_by [] = {
  TO_UNICODE ('b'),
  TO_UNICODE ('y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$cont$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_cont [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$continue$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_continue [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('u'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$default$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_default [] = {
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE ('f'),
  TO_UNICODE ('a'),
  TO_UNICODE ('u'),
  TO_UNICODE ('l'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$display$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_display [] = {
  TO_UNICODE ('d'),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('p'),
  TO_UNICODE ('l'),
  TO_UNICODE ('a'),
  TO_UNICODE ('y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$do$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_do [] = {
  TO_UNICODE ('d'),
  TO_UNICODE ('o'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$else$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_else [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$elsif$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_elsif [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('s'),
  TO_UNICODE ('i'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$emptylist$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_emptylist [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$emptymap$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_emptymap [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE ('m'),
  TO_UNICODE ('a'),
  TO_UNICODE ('p'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$end$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_end [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$exists$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_exists [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('x'),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$false$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_false [] = {
  TO_UNICODE ('f'),
  TO_UNICODE ('a'),
  TO_UNICODE ('l'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$help$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_help [] = {
  TO_UNICODE ('h'),
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('p'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$hist$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_hist [] = {
  TO_UNICODE ('h'),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$if$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_if [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$import$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_import [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$let$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_let [] = {
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$libraries$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_libraries [] = {
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('b'),
  TO_UNICODE ('r'),
  TO_UNICODE ('a'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$list$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_list [] = {
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$listof$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_listof [] = {
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('o'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$load$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_load [] = {
  TO_UNICODE ('l'),
  TO_UNICODE ('o'),
  TO_UNICODE ('a'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$mapof$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_mapof [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('a'),
  TO_UNICODE ('p'),
  TO_UNICODE ('o'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$mod$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_mod [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('o'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$mod_3D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_mod_3D_ [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('o'),
  TO_UNICODE ('d'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$no$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_no [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('o'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$not$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_not [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('o'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$or$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_or [] = {
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$print$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_print [] = {
  TO_UNICODE ('p'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$sort$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_sort [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$step$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_step [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('p'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$then$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_then [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('h'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$true$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_true [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('u'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$typeof$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_typeof [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE ('o'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$unlet$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_unlet [] = {
  TO_UNICODE ('u'),
  TO_UNICODE ('n'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$variables$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_variables [] = {
  TO_UNICODE ('v'),
  TO_UNICODE ('a'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('a'),
  TO_UNICODE ('b'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$watch$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_watch [] = {
  TO_UNICODE ('w'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('c'),
  TO_UNICODE ('h'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$yes$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner_yes [] = {
  TO_UNICODE ('y'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7B_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__7B_ [] = {
  TO_UNICODE ('{'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7C_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__7C_ [] = {
  TO_UNICODE ('|'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7C__3D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__7C__3D_ [] = {
  TO_UNICODE ('|'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7D_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__7D_ [] = {
  TO_UNICODE ('}'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7E_$'
static const utf32 kUnicodeString_gtl_5F_debugger_5F_scanner__7E_ [] = {
  TO_UNICODE ('~'),
  TO_UNICODE (0)
} ;

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'galgasDelimitorsList'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_gtl_5F_debugger_5F_scanner_galgasDelimitorsList = 45 ;

static const C_unicode_lexique_table_entry ktable_for_gtl_5F_debugger_5F_scanner_galgasDelimitorsList [ktable_size_gtl_5F_debugger_5F_scanner_galgasDelimitorsList] = {
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__21_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__21_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__26_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__26_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__28_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__28_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__29_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__29_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__2A_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2A_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__2B_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__2C_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__2F_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2F_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__3A_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__3C_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__3E_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__3F_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3F_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__40_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__5B_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__5D_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__5E_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5E_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__7B_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__7C_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7C_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__7D_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__7E_, 1, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7E_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__21__3D_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__21__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__26__3D_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__26__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__2A__3D_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2A__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__2B__3D_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2B__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__2D__3D_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2D__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__2D__3E_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2D__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__2F__3D_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2F__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__3A__3A_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3A_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__3A__3D_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__3C__2D_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__2D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__3C__3C_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__3C__3D_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__3D__3D_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3D__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__3E__3D_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__3E__3E_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__40__21_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40__21_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__40__28_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40__28_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__40__5B_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40__5B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__40__7B_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40__7B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__5B__21_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5B__21_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__5E__3D_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5E__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__7C__3D_, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7C__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__3C__3C__3D_, 3, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner__3E__3E__3D_, 3, C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_mod_3D_, 4, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_mod_3D_)
} ;

int32_t C_Lexique_gtl_5F_debugger_5F_scanner::search_into_galgasDelimitorsList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_gtl_5F_debugger_5F_scanner_galgasDelimitorsList, ktable_size_gtl_5F_debugger_5F_scanner_galgasDelimitorsList) ;
}

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'goilTemplateKeyWordList'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_gtl_5F_debugger_5F_scanner_goilTemplateKeyWordList = 39 ;

static const C_unicode_lexique_table_entry ktable_for_gtl_5F_debugger_5F_scanner_goilTemplateKeyWordList [ktable_size_gtl_5F_debugger_5F_scanner_goilTemplateKeyWordList] = {
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_by, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_by),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_do, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_do),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_if, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_if),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_no, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_no),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_or, 2, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_or),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_all, 3, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_all),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_end, 3, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_end),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_let, 3, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_let),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_mod, 3, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_mod),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_not, 3, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_not),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_yes, 3, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_yes),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_cont, 4, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_cont),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_else, 4, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_else),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_help, 4, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_help),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_hist, 4, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_hist),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_list, 4, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_list),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_load, 4, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_load),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_sort, 4, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_sort),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_step, 4, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_step),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_then, 4, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_then),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_true, 4, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_true),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_break, 5, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_break),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_elsif, 5, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_false, 5, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_false),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_mapof, 5, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_mapof),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_print, 5, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_print),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_unlet, 5, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_unlet),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_watch, 5, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_watch),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_exists, 6, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_exists),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_import, 6, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_import),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_listof, 6, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_listof),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_typeof, 6, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_typeof),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_default, 7, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_default),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_display, 7, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_display),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_continue, 8, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_continue),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_emptymap, 8, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_emptymap),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_emptylist, 9, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_emptylist),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_libraries, 9, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_libraries),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_debugger_5F_scanner_variables, 9, C_Lexique_gtl_5F_debugger_5F_scanner::kToken_variables)
} ;

int32_t C_Lexique_gtl_5F_debugger_5F_scanner::search_into_goilTemplateKeyWordList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_gtl_5F_debugger_5F_scanner_goilTemplateKeyWordList, ktable_size_gtl_5F_debugger_5F_scanner_goilTemplateKeyWordList) ;
}


//----------------------------------------------------------------------------------------------------------------------
//                          getCurrentTokenString                                                
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_gtl_5F_debugger_5F_scanner::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (const cTokenFor_gtl_5F_debugger_5F_scanner *) inTokenPtr ;
  C_String s ;
  if (ptr == nullptr) {
    s.appendCString("$$") ;
  }else{
    switch (ptr->mTokenCode) {
    case kToken_:
      s.appendCString("$$") ;
      break ;
    case kToken_identifier:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("identifier") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_literal_5F_enum:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("literal_enum") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_literal_5F_double:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("literal_double") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendDouble (ptr->mLexicalAttribute_floatValue) ;
      break ;
    case kToken_signed_5F_literal_5F_integer_5F_bigint:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("signed_literal_integer_bigint") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_intValue.decimalString ()) ;
      break ;
    case kToken__2D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("-") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (".") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2E__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (".=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2E__2E__2E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("...") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_literal_5F_char:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("literal_char") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendUnicodeCharacter (ptr->mLexicalAttribute_charValue COMMA_HERE) ;
      break ;
    case kToken_string:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("string") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_a_5F_string) ;
      break ;
    case kToken_comment:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("comment") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_default:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("default") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_display:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("display") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_do:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("do") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_emptylist:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("emptylist") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_emptymap:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("emptymap") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_exists:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("exists") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_false:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("false") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_list:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("list") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_import:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("import") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_listof:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("listof") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_let:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("let") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_mapof:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("mapof") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_mod:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("mod") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_no:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("no") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_not:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("not") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_or:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("or") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_print:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("print") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_sort:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("sort") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_step:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("step") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_true:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("true") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_typeof:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("typeof") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_yes:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("yes") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_variables:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("variables") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_unlet:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("unlet") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_libraries:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("libraries") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_break:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("break") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_watch:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("watch") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_by:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("by") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_end:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("end") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_cont:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("cont") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_continue:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("continue") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_help:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("help") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_if:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("if") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_then:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("then") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_else:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("else") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_elsif:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("elsif") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_hist:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("hist") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_all:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("all") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_load:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("load") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2A_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("*") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("|") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (",") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("+") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3A__3A_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("::") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (">") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3A_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (":") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__28_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("(") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__29_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (")") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2D__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("->") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3F_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("\?") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3D__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("==") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__21_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("!") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3A__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (":=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("[") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("]") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2B__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("+=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2D__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("-=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2F_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("/") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__21__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("!=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3E__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (">=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__26_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("&") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("{") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("}") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("^") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3E__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (">>") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("~") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__2D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<-") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__3C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<<") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__40_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("@") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2A__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("*=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2F__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("/=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__26__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("&=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7C__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("|=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__3C__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<<=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3E__3E__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (">>=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_mod_3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("mod=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5E__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("^=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__40__5B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("@[") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__40__28_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("@(") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__40__7B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("@{") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5B__21_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("[!") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__40__21_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("@!") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    default:
      break ;
    }
  }
  return s ;
}

//----------------------------------------------------------------------------------------------------------------------
//                           Template Delimiters                                                 
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//                           Template Replacements                                               
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//            Terminal Symbols as end of script in template mark                                 
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//               INTERNAL PARSE LEXICAL TOKEN                                         
//----------------------------------------------------------------------------------------------------------------------

void C_Lexique_gtl_5F_debugger_5F_scanner::internalParseLexicalToken (cTokenFor_gtl_5F_debugger_5F_scanner & token) {
  bool loop = true ;
  token.mLexicalAttribute_a_5F_string.setLengthToZero () ;
  token.mLexicalAttribute_charValue = TO_UNICODE (0) ;
  token.mLexicalAttribute_floatValue = 0.0 ;
  token.mLexicalAttribute_functionContent.setLengthToZero () ;
  token.mLexicalAttribute_identifierString.setLengthToZero () ;
  token.mLexicalAttribute_intValue.setToZero () ;
  token.mLexicalAttribute_tokenString.setLengthToZero () ;
  token.mLexicalAttribute_uint_33__32_value = 0 ;
  mTokenStartLocation = mCurrentLocation ;
  try{
    if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z'))) {
      do {
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_identifierString, previousChar ()) ;
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32Char (TO_UNICODE ('_')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (token.mTokenCode == -1) {
        token.mTokenCode = search_into_goilTemplateKeyWordList (token.mLexicalAttribute_identifierString) ;
      }
      if (token.mTokenCode == -1) {
        token.mTokenCode = kToken_identifier ;
      }
      enterToken (token) ;
    }else if (testForInputUTF32Char (TO_UNICODE ('$'))) {
      do {
        if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32Char (TO_UNICODE ('_')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      token.mTokenCode = kToken_literal_5F_enum ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner_mod_3D_, 4, true)) {
      token.mTokenCode = kToken_mod_3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3E__3E__3D_, 3, true)) {
      token.mTokenCode = kToken__3E__3E__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3C__3C__3D_, 3, true)) {
      token.mTokenCode = kToken__3C__3C__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__7C__3D_, 2, true)) {
      token.mTokenCode = kToken__7C__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__5E__3D_, 2, true)) {
      token.mTokenCode = kToken__5E__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__5B__21_, 2, true)) {
      token.mTokenCode = kToken__5B__21_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__40__7B_, 2, true)) {
      token.mTokenCode = kToken__40__7B_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__40__5B_, 2, true)) {
      token.mTokenCode = kToken__40__5B_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__40__28_, 2, true)) {
      token.mTokenCode = kToken__40__28_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__40__21_, 2, true)) {
      token.mTokenCode = kToken__40__21_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3E__3E_, 2, true)) {
      token.mTokenCode = kToken__3E__3E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3E__3D_, 2, true)) {
      token.mTokenCode = kToken__3E__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3D__3D_, 2, true)) {
      token.mTokenCode = kToken__3D__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3C__3D_, 2, true)) {
      token.mTokenCode = kToken__3C__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3C__3C_, 2, true)) {
      token.mTokenCode = kToken__3C__3C_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3C__2D_, 2, true)) {
      token.mTokenCode = kToken__3C__2D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3A__3D_, 2, true)) {
      token.mTokenCode = kToken__3A__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3A__3A_, 2, true)) {
      token.mTokenCode = kToken__3A__3A_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__2F__3D_, 2, true)) {
      token.mTokenCode = kToken__2F__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__2D__3E_, 2, true)) {
      token.mTokenCode = kToken__2D__3E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__2D__3D_, 2, true)) {
      token.mTokenCode = kToken__2D__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__2B__3D_, 2, true)) {
      token.mTokenCode = kToken__2B__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__2A__3D_, 2, true)) {
      token.mTokenCode = kToken__2A__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__26__3D_, 2, true)) {
      token.mTokenCode = kToken__26__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__21__3D_, 2, true)) {
      token.mTokenCode = kToken__21__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__7E_, 1, true)) {
      token.mTokenCode = kToken__7E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__7D_, 1, true)) {
      token.mTokenCode = kToken__7D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__7C_, 1, true)) {
      token.mTokenCode = kToken__7C_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__7B_, 1, true)) {
      token.mTokenCode = kToken__7B_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__5E_, 1, true)) {
      token.mTokenCode = kToken__5E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__5D_, 1, true)) {
      token.mTokenCode = kToken__5D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__5B_, 1, true)) {
      token.mTokenCode = kToken__5B_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__40_, 1, true)) {
      token.mTokenCode = kToken__40_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3F_, 1, true)) {
      token.mTokenCode = kToken__3F_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3E_, 1, true)) {
      token.mTokenCode = kToken__3E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3C_, 1, true)) {
      token.mTokenCode = kToken__3C_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3A_, 1, true)) {
      token.mTokenCode = kToken__3A_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__2F_, 1, true)) {
      token.mTokenCode = kToken__2F_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__2C_, 1, true)) {
      token.mTokenCode = kToken__2C_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__2B_, 1, true)) {
      token.mTokenCode = kToken__2B_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__2A_, 1, true)) {
      token.mTokenCode = kToken__2A_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__29_, 1, true)) {
      token.mTokenCode = kToken__29_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__28_, 1, true)) {
      token.mTokenCode = kToken__28_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__26_, 1, true)) {
      token.mTokenCode = kToken__26_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__21_, 1, true)) {
      token.mTokenCode = kToken__21_ ;
      enterToken (token) ;
    }else if (testForInputUTF32Char (TO_UNICODE ('-'))) {
      if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('-')) ;
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        do {
          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
          }else{
            loop = false ;
          }
        }while (loop) ;
        loop = true ;
        if (testForInputUTF32Char (TO_UNICODE ('.'))) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('.')) ;
          do {
            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
              ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
            }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
            }else{
              loop = false ;
            }
          }while (loop) ;
          loop = true ;
          ::scanner_routine_convertStringToDouble (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_floatValue, gLexicalMessage_gtl_5F_debugger_5F_scanner_floatNumberConversionError) ;
          token.mTokenCode = kToken_literal_5F_double ;
          enterToken (token) ;
        }else{
          ::scanner_routine_convertDecimalStringIntoBigInt (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_intValue, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
          token.mTokenCode = kToken_signed_5F_literal_5F_integer_5F_bigint ;
          enterToken (token) ;
        }
      }else{
        token.mTokenCode = kToken__2D_ ;
        enterToken (token) ;
      }
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__30_x, 2, true) || testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__30_X, 2, true)) {
      do {
        if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      ::scanner_routine_convertHexStringIntoBigInt (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_intValue, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
      token.mTokenCode = kToken_signed_5F_literal_5F_integer_5F_bigint ;
      enterToken (token) ;
    }else if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
      ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
      do {
        if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (testForInputUTF32Char (TO_UNICODE ('.'))) {
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('.')) ;
        do {
          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
          }else{
            loop = false ;
          }
        }while (loop) ;
        loop = true ;
        ::scanner_routine_convertStringToDouble (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_floatValue, gLexicalMessage_gtl_5F_debugger_5F_scanner_floatNumberConversionError) ;
        token.mTokenCode = kToken_literal_5F_double ;
        enterToken (token) ;
      }else{
        ::scanner_routine_convertDecimalStringIntoBigInt (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_intValue, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
        token.mTokenCode = kToken_signed_5F_literal_5F_integer_5F_bigint ;
        enterToken (token) ;
      }
    }else if (testForInputUTF32Char (TO_UNICODE ('.'))) {
      if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('0')) ;
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('.')) ;
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        do {
          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
          }else{
            loop = false ;
          }
        }while (loop) ;
        loop = true ;
        ::scanner_routine_convertStringToDouble (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_floatValue, gLexicalMessage_gtl_5F_debugger_5F_scanner_floatNumberConversionError) ;
        token.mTokenCode = kToken_literal_5F_double ;
        enterToken (token) ;
      }else{
        if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__2E__2E_, 2, true)) {
          token.mTokenCode = kToken__2E__2E__2E_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3D_, 1, true)) {
          token.mTokenCode = kToken__2E__3D_ ;
          enterToken (token) ;
        }else{
          token.mTokenCode = kToken__2E_ ;
          enterToken (token) ;
        }
      }
    }else if (testForInputUTF32Char (TO_UNICODE ('\''))) {
      if (testForInputUTF32Char (TO_UNICODE ('\\'))) {
        if (testForInputUTF32Char (TO_UNICODE ('f'))) {
          ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, TO_UNICODE ('\f')) ;
        }else if (testForInputUTF32Char (TO_UNICODE ('n'))) {
          ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, TO_UNICODE ('\n')) ;
        }else if (testForInputUTF32Char (TO_UNICODE ('r'))) {
          ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, TO_UNICODE ('\r')) ;
        }else if (testForInputUTF32Char (TO_UNICODE ('t'))) {
          ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, TO_UNICODE ('\t')) ;
        }else if (testForInputUTF32Char (TO_UNICODE ('v'))) {
          ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, TO_UNICODE ('\v')) ;
        }else if (testForInputUTF32Char (TO_UNICODE ('\\'))) {
          ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, TO_UNICODE ('\\')) ;
        }else if (testForInputUTF32Char (TO_UNICODE ('0'))) {
          ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, TO_UNICODE ('\0')) ;
        }else if (testForInputUTF32Char (TO_UNICODE ('\''))) {
          ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, TO_UNICODE ('\'')) ;
        }else if (testForInputUTF32Char (TO_UNICODE ('u'))) {
          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
            ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
              ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
              if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                  ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                  ::scanner_routine_convertUnsignedNumberToUnicodeChar (*this, token.mLexicalAttribute_uint_33__32_value, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_debugger_5F_scanner_unassignedUnicodeValue) ;
                }else{
                  lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                }
              }else{
                lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
              }
            }else{
              lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
            }
          }else{
            lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
          }
        }else if (testForInputUTF32Char (TO_UNICODE ('U'))) {
          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
            ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
              ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
              if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                  ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                  if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                    ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                    if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                      ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                      if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                        ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                        if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                          ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                          ::scanner_routine_convertUnsignedNumberToUnicodeChar (*this, token.mLexicalAttribute_uint_33__32_value, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_debugger_5F_scanner_unassignedUnicodeValue) ;
                        }else{
                          lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                        }
                      }else{
                        lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                      }
                    }else{
                      lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                    }
                  }else{
                    lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                  }
                }else{
                  lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                }
              }else{
                lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
              }
            }else{
              lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
            }
          }else{
            lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
          }
        }else if (testForInputUTF32Char (TO_UNICODE ('&'))) {
          do {
            if (notTestForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3B_, 1, gLexicalMessage_gtl_5F_debugger_5F_scanner_incorrectHTMLescapeSequence COMMA_LINE_AND_SOURCE_FILE)) {
              ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
            }else{
              loop = false ;
            }
          }while (loop) ;
          loop = true ;
          ::scanner_routine_convertHTMLSequenceToUnicodeCharacter (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_debugger_5F_scanner_unknownHTMLescapeSequence) ;
        }else{
          lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_incorrectCharConstant COMMA_LINE_AND_SOURCE_FILE) ;
        }
      }else if (testForInputUTF32CharRange (TO_UNICODE (' '), TO_UNICODE (65533))) {
        ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, previousChar ()) ;
      }else{
        lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_incorrectCharConstant COMMA_LINE_AND_SOURCE_FILE) ;
      }
      if (testForInputUTF32Char (TO_UNICODE ('\''))) {
        token.mTokenCode = kToken_literal_5F_char ;
        enterToken (token) ;
      }else{
        lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_incorrectCharConstant COMMA_LINE_AND_SOURCE_FILE) ;
      }
    }else if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
      do {
        if (testForInputUTF32Char (TO_UNICODE ('\\'))) {
          if (testForInputUTF32Char (TO_UNICODE ('f'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\f')) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('n'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\n')) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('r'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\r')) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('t'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\t')) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('v'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\v')) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('\\'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\\')) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\"')) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('\''))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\'')) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('\?'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\?')) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('&'))) {
            do {
              if (notTestForInputUTF32String (kUnicodeString_gtl_5F_debugger_5F_scanner__3B_, 1, gLexicalMessage_gtl_5F_debugger_5F_scanner_incorrectHTMLescapeSequence COMMA_LINE_AND_SOURCE_FILE)) {
                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_identifierString, previousChar ()) ;
              }else{
                loop = false ;
              }
            }while (loop) ;
            loop = true ;
            ::scanner_routine_convertHTMLSequenceToUnicodeCharacter (*this, token.mLexicalAttribute_identifierString, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_debugger_5F_scanner_unknownHTMLescapeSequence) ;
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, token.mLexicalAttribute_charValue) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('u'))) {
            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
              ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
              if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                  ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                  if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                    ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                    ::scanner_routine_convertUnsignedNumberToUnicodeChar (*this, token.mLexicalAttribute_uint_33__32_value, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_debugger_5F_scanner_unassignedUnicodeValue) ;
                    ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, token.mLexicalAttribute_charValue) ;
                  }else{
                    lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                  }
                }else{
                  lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                }
              }else{
                lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
              }
            }else{
              lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
            }
          }else if (testForInputUTF32Char (TO_UNICODE ('U'))) {
            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
              ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
              if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                  ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                  if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                    ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                    if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                      ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                      if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                        ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                        if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                          ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                            ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError, gLexicalMessage_gtl_5F_debugger_5F_scanner_internalError) ;
                            ::scanner_routine_convertUnsignedNumberToUnicodeChar (*this, token.mLexicalAttribute_uint_33__32_value, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_debugger_5F_scanner_unassignedUnicodeValue) ;
                            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, token.mLexicalAttribute_charValue) ;
                          }else{
                            lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                          }
                        }else{
                          lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                        }
                      }else{
                        lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                      }
                    }else{
                      lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                    }
                  }else{
                    lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                  }
                }else{
                  lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                }
              }else{
                lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
              }
            }else{
              lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
            }
          }else{
            lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_incorrectCharConstant COMMA_LINE_AND_SOURCE_FILE) ;
          }
        }else if (testForInputUTF32Char (TO_UNICODE (' ')) || testForInputUTF32Char (TO_UNICODE ('!')) || testForInputUTF32CharRange (TO_UNICODE ('#'), TO_UNICODE (65533))) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, previousChar ()) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
        token.mTokenCode = kToken_string ;
        enterToken (token) ;
      }else{
        lexicalError (gLexicalMessage_gtl_5F_debugger_5F_scanner_unterminatedLitteralString COMMA_LINE_AND_SOURCE_FILE) ;
      }
    }else if (testForInputUTF32Char (TO_UNICODE ('#'))) {
      do {
        if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE ('\t')) || testForInputUTF32Char (TO_UNICODE ('\v')) || testForInputUTF32Char (TO_UNICODE ('\f')) || testForInputUTF32CharRange (TO_UNICODE (14), TO_UNICODE (65533))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      enterDroppedTerminal (kToken_comment) ;
    }else if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (' '))) {
    }else if (testForInputUTF32Char (TO_UNICODE ('\0'))) { // End of source text ? 
      token.mTokenCode = kToken_ ; // Empty string code
    }else{ // Unknown input character
      unknownCharacterLexicalError (LINE_AND_SOURCE_FILE) ;
      token.mTokenCode = -1 ; // No token
      advance () ; // ... go throught unknown character
    }
  }catch (const C_lexicalErrorException &) {
    token.mTokenCode = -1 ; // No token
    advance () ; // ... go throught unknown character
  }
}

//----------------------------------------------------------------------------------------------------------------------
//               P A R S E    L E X I C A L    T O K E N                                         
//----------------------------------------------------------------------------------------------------------------------

bool C_Lexique_gtl_5F_debugger_5F_scanner::parseLexicalToken (void) {
  cTokenFor_gtl_5F_debugger_5F_scanner token ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
    internalParseLexicalToken (token) ;
  }
  if (UNICODE_VALUE (mCurrentChar) == '\0') {
    token.mTokenCode = 0 ;
    enterToken (token) ;
  }
  return token.mTokenCode > 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
//                         E N T E R    T O K E N                                                
//----------------------------------------------------------------------------------------------------------------------

void C_Lexique_gtl_5F_debugger_5F_scanner::enterToken (cTokenFor_gtl_5F_debugger_5F_scanner & ioToken) {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = nullptr ;
  macroMyNew (ptr, cTokenFor_gtl_5F_debugger_5F_scanner ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
  // ptr->mIsOptional = ioToken.mIsOptional ;
  ptr->mStartLocation = mTokenStartLocation ;
  ptr->mEndLocation = mTokenEndLocation ;
  ptr->mTemplateStringBeforeToken = ioToken.mTemplateStringBeforeToken ;
  ioToken.mTemplateStringBeforeToken = "" ;
  ptr->mLexicalAttribute_a_5F_string = ioToken.mLexicalAttribute_a_5F_string ;
  ptr->mLexicalAttribute_charValue = ioToken.mLexicalAttribute_charValue ;
  ptr->mLexicalAttribute_floatValue = ioToken.mLexicalAttribute_floatValue ;
  ptr->mLexicalAttribute_functionContent = ioToken.mLexicalAttribute_functionContent ;
  ptr->mLexicalAttribute_identifierString = ioToken.mLexicalAttribute_identifierString ;
  ptr->mLexicalAttribute_intValue = ioToken.mLexicalAttribute_intValue ;
  ptr->mLexicalAttribute_tokenString = ioToken.mLexicalAttribute_tokenString ;
  ptr->mLexicalAttribute_uint_33__32_value = ioToken.mLexicalAttribute_uint_33__32_value ;
  enterTokenFromPointer (ptr) ;
}

//----------------------------------------------------------------------------------------------------------------------
//               A T T R I B U T E   A C C E S S                                                 
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_gtl_5F_debugger_5F_scanner::attributeValue_a_5F_string (void) const {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (cTokenFor_gtl_5F_debugger_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_a_5F_string ;
}

//----------------------------------------------------------------------------------------------------------------------

utf32 C_Lexique_gtl_5F_debugger_5F_scanner::attributeValue_charValue (void) const {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (cTokenFor_gtl_5F_debugger_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_charValue ;
}

//----------------------------------------------------------------------------------------------------------------------

double C_Lexique_gtl_5F_debugger_5F_scanner::attributeValue_floatValue (void) const {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (cTokenFor_gtl_5F_debugger_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_floatValue ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_gtl_5F_debugger_5F_scanner::attributeValue_functionContent (void) const {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (cTokenFor_gtl_5F_debugger_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_functionContent ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_gtl_5F_debugger_5F_scanner::attributeValue_identifierString (void) const {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (cTokenFor_gtl_5F_debugger_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_identifierString ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_Lexique_gtl_5F_debugger_5F_scanner::attributeValue_intValue (void) const {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (cTokenFor_gtl_5F_debugger_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_intValue ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_gtl_5F_debugger_5F_scanner::attributeValue_tokenString (void) const {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (cTokenFor_gtl_5F_debugger_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_tokenString ;
}

//----------------------------------------------------------------------------------------------------------------------

uint32_t C_Lexique_gtl_5F_debugger_5F_scanner::attributeValue_uint_33__32_value (void) const {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (cTokenFor_gtl_5F_debugger_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_uint_33__32_value ;
}

//----------------------------------------------------------------------------------------------------------------------
//         A S S I G N    F R O M    A T T R I B U T E                                           
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_gtl_5F_debugger_5F_scanner::synthetizedAttribute_a_5F_string (void) const {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (cTokenFor_gtl_5F_debugger_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_debugger_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_a_5F_string) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lchar C_Lexique_gtl_5F_debugger_5F_scanner::synthetizedAttribute_charValue (void) const {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (cTokenFor_gtl_5F_debugger_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_debugger_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_char value (ptr->mLexicalAttribute_charValue) ;
  GALGAS_lchar result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ldouble C_Lexique_gtl_5F_debugger_5F_scanner::synthetizedAttribute_floatValue (void) const {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (cTokenFor_gtl_5F_debugger_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_debugger_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_double value (ptr->mLexicalAttribute_floatValue) ;
  GALGAS_ldouble result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_gtl_5F_debugger_5F_scanner::synthetizedAttribute_functionContent (void) const {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (cTokenFor_gtl_5F_debugger_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_debugger_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_functionContent) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_gtl_5F_debugger_5F_scanner::synthetizedAttribute_identifierString (void) const {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (cTokenFor_gtl_5F_debugger_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_debugger_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_identifierString) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigint C_Lexique_gtl_5F_debugger_5F_scanner::synthetizedAttribute_intValue (void) const {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (cTokenFor_gtl_5F_debugger_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_debugger_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_bigint value (ptr->mLexicalAttribute_intValue) ;
  GALGAS_lbigint result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_gtl_5F_debugger_5F_scanner::synthetizedAttribute_tokenString (void) const {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (cTokenFor_gtl_5F_debugger_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_debugger_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_tokenString) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint C_Lexique_gtl_5F_debugger_5F_scanner::synthetizedAttribute_uint_33__32_value (void) const {
  cTokenFor_gtl_5F_debugger_5F_scanner * ptr = (cTokenFor_gtl_5F_debugger_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_debugger_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_uint value (ptr->mLexicalAttribute_uint_33__32_value) ;
  GALGAS_luint result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                         I N T R O S P E C T I O N                                             
//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist C_Lexique_gtl_5F_debugger_5F_scanner::symbols (LOCATION_ARGS) {
  GALGAS_stringlist result = GALGAS_stringlist::constructor_emptyList (THERE) ;
  result.addAssign_operation (GALGAS_string ("identifier") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("literal_enum") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("literal_double") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("signed_literal_integer_bigint") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("-") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (".") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (".=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("...") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("literal_char") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("string") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("comment") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("default") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("display") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("do") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("emptylist") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("emptymap") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("exists") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("false") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("list") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("import") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("listof") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("let") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("mapof") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("mod") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("no") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("not") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("or") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("print") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("sort") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("step") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("true") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("typeof") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("yes") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("variables") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("unlet") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("libraries") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("break") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("watch") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("by") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("end") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("cont") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("continue") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("help") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("if") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("then") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("else") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("elsif") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("hist") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("all") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("load") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("*") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("|") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (",") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("+") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("::") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (">") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (":") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("(") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (")") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("->") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("\?") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("==") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("!") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (":=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("[") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("]") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("+=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("-=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("/") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("!=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (">=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("&") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("{") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("}") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("^") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (">>") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("~") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<-") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<<") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("@") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("*=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("/=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("&=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("|=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<<=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (">>=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("mod=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("^=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("@[") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("@(") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("@{") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("[!") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("@!") COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

static void getKeywordLists_gtl_5F_debugger_5F_scanner (TC_UniqueArray <C_String> & ioList) {
  ioList.appendObject ("gtl_debugger_scanner:galgasDelimitorsList") ;
  ioList.appendObject ("gtl_debugger_scanner:goilTemplateKeyWordList") ;
}

//----------------------------------------------------------------------------------------------------------------------

static void getKeywordsForIdentifier_gtl_5F_debugger_5F_scanner (const C_String & inIdentifier,
                                                                 bool & ioFound,
                                                                 TC_UniqueArray <C_String> & ioList) {
  if (inIdentifier == "gtl_debugger_scanner:galgasDelimitorsList") {
    ioFound = true ;
    ioList.appendObject ("!") ;
    ioList.appendObject ("&") ;
    ioList.appendObject ("(") ;
    ioList.appendObject (")") ;
    ioList.appendObject ("*") ;
    ioList.appendObject ("+") ;
    ioList.appendObject (",") ;
    ioList.appendObject ("/") ;
    ioList.appendObject (":") ;
    ioList.appendObject ("<") ;
    ioList.appendObject (">") ;
    ioList.appendObject ("\?") ;
    ioList.appendObject ("@") ;
    ioList.appendObject ("[") ;
    ioList.appendObject ("]") ;
    ioList.appendObject ("^") ;
    ioList.appendObject ("{") ;
    ioList.appendObject ("|") ;
    ioList.appendObject ("}") ;
    ioList.appendObject ("~") ;
    ioList.appendObject ("!=") ;
    ioList.appendObject ("&=") ;
    ioList.appendObject ("*=") ;
    ioList.appendObject ("+=") ;
    ioList.appendObject ("-=") ;
    ioList.appendObject ("->") ;
    ioList.appendObject ("/=") ;
    ioList.appendObject ("::") ;
    ioList.appendObject (":=") ;
    ioList.appendObject ("<-") ;
    ioList.appendObject ("<<") ;
    ioList.appendObject ("<=") ;
    ioList.appendObject ("==") ;
    ioList.appendObject (">=") ;
    ioList.appendObject (">>") ;
    ioList.appendObject ("@!") ;
    ioList.appendObject ("@(") ;
    ioList.appendObject ("@[") ;
    ioList.appendObject ("@{") ;
    ioList.appendObject ("[!") ;
    ioList.appendObject ("^=") ;
    ioList.appendObject ("|=") ;
    ioList.appendObject ("<<=") ;
    ioList.appendObject (">>=") ;
    ioList.appendObject ("mod=") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "gtl_debugger_scanner:goilTemplateKeyWordList") {
    ioFound = true ;
    ioList.appendObject ("by") ;
    ioList.appendObject ("do") ;
    ioList.appendObject ("if") ;
    ioList.appendObject ("no") ;
    ioList.appendObject ("or") ;
    ioList.appendObject ("all") ;
    ioList.appendObject ("end") ;
    ioList.appendObject ("let") ;
    ioList.appendObject ("mod") ;
    ioList.appendObject ("not") ;
    ioList.appendObject ("yes") ;
    ioList.appendObject ("cont") ;
    ioList.appendObject ("else") ;
    ioList.appendObject ("help") ;
    ioList.appendObject ("hist") ;
    ioList.appendObject ("list") ;
    ioList.appendObject ("load") ;
    ioList.appendObject ("sort") ;
    ioList.appendObject ("step") ;
    ioList.appendObject ("then") ;
    ioList.appendObject ("true") ;
    ioList.appendObject ("break") ;
    ioList.appendObject ("elsif") ;
    ioList.appendObject ("false") ;
    ioList.appendObject ("mapof") ;
    ioList.appendObject ("print") ;
    ioList.appendObject ("unlet") ;
    ioList.appendObject ("watch") ;
    ioList.appendObject ("exists") ;
    ioList.appendObject ("import") ;
    ioList.appendObject ("listof") ;
    ioList.appendObject ("typeof") ;
    ioList.appendObject ("default") ;
    ioList.appendObject ("display") ;
    ioList.appendObject ("continue") ;
    ioList.appendObject ("emptymap") ;
    ioList.appendObject ("emptylist") ;
    ioList.appendObject ("libraries") ;
    ioList.appendObject ("variables") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static cLexiqueIntrospection lexiqueIntrospection_gtl_5F_debugger_5F_scanner
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_gtl_5F_debugger_5F_scanner, getKeywordsForIdentifier_gtl_5F_debugger_5F_scanner) ;

//----------------------------------------------------------------------------------------------------------------------
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                           
//----------------------------------------------------------------------------------------------------------------------

uint32_t C_Lexique_gtl_5F_debugger_5F_scanner::styleIndexForTerminal (const int32_t inTerminalIndex) const {
  static const uint32_t kTerminalSymbolStyles [96] = {0,
    0 /* gtl_debugger_scanner_1_identifier */,
    0 /* gtl_debugger_scanner_1_literal_5F_enum */,
    5 /* gtl_debugger_scanner_1_literal_5F_double */,
    4 /* gtl_debugger_scanner_1_signed_5F_literal_5F_integer_5F_bigint */,
    2 /* gtl_debugger_scanner_1__2D_ */,
    2 /* gtl_debugger_scanner_1__2E_ */,
    2 /* gtl_debugger_scanner_1__2E__3D_ */,
    2 /* gtl_debugger_scanner_1__2E__2E__2E_ */,
    8 /* gtl_debugger_scanner_1_literal_5F_char */,
    6 /* gtl_debugger_scanner_1_string */,
    7 /* gtl_debugger_scanner_1_comment */,
    1 /* gtl_debugger_scanner_1_default */,
    1 /* gtl_debugger_scanner_1_display */,
    1 /* gtl_debugger_scanner_1_do */,
    1 /* gtl_debugger_scanner_1_emptylist */,
    1 /* gtl_debugger_scanner_1_emptymap */,
    1 /* gtl_debugger_scanner_1_exists */,
    1 /* gtl_debugger_scanner_1_false */,
    1 /* gtl_debugger_scanner_1_list */,
    1 /* gtl_debugger_scanner_1_import */,
    1 /* gtl_debugger_scanner_1_listof */,
    1 /* gtl_debugger_scanner_1_let */,
    1 /* gtl_debugger_scanner_1_mapof */,
    1 /* gtl_debugger_scanner_1_mod */,
    1 /* gtl_debugger_scanner_1_no */,
    1 /* gtl_debugger_scanner_1_not */,
    1 /* gtl_debugger_scanner_1_or */,
    1 /* gtl_debugger_scanner_1_print */,
    1 /* gtl_debugger_scanner_1_sort */,
    1 /* gtl_debugger_scanner_1_step */,
    1 /* gtl_debugger_scanner_1_true */,
    1 /* gtl_debugger_scanner_1_typeof */,
    1 /* gtl_debugger_scanner_1_yes */,
    1 /* gtl_debugger_scanner_1_variables */,
    1 /* gtl_debugger_scanner_1_unlet */,
    1 /* gtl_debugger_scanner_1_libraries */,
    1 /* gtl_debugger_scanner_1_break */,
    1 /* gtl_debugger_scanner_1_watch */,
    1 /* gtl_debugger_scanner_1_by */,
    1 /* gtl_debugger_scanner_1_end */,
    1 /* gtl_debugger_scanner_1_cont */,
    1 /* gtl_debugger_scanner_1_continue */,
    1 /* gtl_debugger_scanner_1_help */,
    1 /* gtl_debugger_scanner_1_if */,
    1 /* gtl_debugger_scanner_1_then */,
    1 /* gtl_debugger_scanner_1_else */,
    1 /* gtl_debugger_scanner_1_elsif */,
    1 /* gtl_debugger_scanner_1_hist */,
    1 /* gtl_debugger_scanner_1_all */,
    1 /* gtl_debugger_scanner_1_load */,
    2 /* gtl_debugger_scanner_1__2A_ */,
    2 /* gtl_debugger_scanner_1__7C_ */,
    2 /* gtl_debugger_scanner_1__2C_ */,
    2 /* gtl_debugger_scanner_1__2B_ */,
    2 /* gtl_debugger_scanner_1__3A__3A_ */,
    2 /* gtl_debugger_scanner_1__3E_ */,
    2 /* gtl_debugger_scanner_1__3A_ */,
    2 /* gtl_debugger_scanner_1__28_ */,
    2 /* gtl_debugger_scanner_1__29_ */,
    2 /* gtl_debugger_scanner_1__2D__3E_ */,
    2 /* gtl_debugger_scanner_1__3F_ */,
    2 /* gtl_debugger_scanner_1__3D__3D_ */,
    2 /* gtl_debugger_scanner_1__21_ */,
    2 /* gtl_debugger_scanner_1__3A__3D_ */,
    2 /* gtl_debugger_scanner_1__5B_ */,
    2 /* gtl_debugger_scanner_1__5D_ */,
    2 /* gtl_debugger_scanner_1__2B__3D_ */,
    2 /* gtl_debugger_scanner_1__2D__3D_ */,
    2 /* gtl_debugger_scanner_1__2F_ */,
    2 /* gtl_debugger_scanner_1__21__3D_ */,
    2 /* gtl_debugger_scanner_1__3E__3D_ */,
    2 /* gtl_debugger_scanner_1__26_ */,
    2 /* gtl_debugger_scanner_1__3C__3D_ */,
    2 /* gtl_debugger_scanner_1__7B_ */,
    2 /* gtl_debugger_scanner_1__7D_ */,
    2 /* gtl_debugger_scanner_1__3C_ */,
    2 /* gtl_debugger_scanner_1__5E_ */,
    2 /* gtl_debugger_scanner_1__3E__3E_ */,
    2 /* gtl_debugger_scanner_1__7E_ */,
    2 /* gtl_debugger_scanner_1__3C__2D_ */,
    2 /* gtl_debugger_scanner_1__3C__3C_ */,
    2 /* gtl_debugger_scanner_1__40_ */,
    2 /* gtl_debugger_scanner_1__2A__3D_ */,
    2 /* gtl_debugger_scanner_1__2F__3D_ */,
    2 /* gtl_debugger_scanner_1__26__3D_ */,
    2 /* gtl_debugger_scanner_1__7C__3D_ */,
    2 /* gtl_debugger_scanner_1__3C__3C__3D_ */,
    2 /* gtl_debugger_scanner_1__3E__3E__3D_ */,
    2 /* gtl_debugger_scanner_1_mod_3D_ */,
    2 /* gtl_debugger_scanner_1__5E__3D_ */,
    2 /* gtl_debugger_scanner_1__40__5B_ */,
    2 /* gtl_debugger_scanner_1__40__28_ */,
    2 /* gtl_debugger_scanner_1__40__7B_ */,
    2 /* gtl_debugger_scanner_1__5B__21_ */,
    2 /* gtl_debugger_scanner_1__40__21_ */
  } ;
  return (inTerminalIndex >= 0) ? kTerminalSymbolStyles [inTerminalIndex] : 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                      
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_gtl_5F_debugger_5F_scanner::styleNameForIndex (const uint32_t inStyleIndex) const {
  C_String result ;
  if (inStyleIndex < 9) {
    static const char * kStyleArray [9] = {
      "",
      "keywordsStyle",
      "delimitersStyle",
      "nonTerminalStyle",
      "integerStyle",
      "floatCsts",
      "stringStyle",
      "commentStyle",
      "characterStyle"
    } ;
    result = kStyleArray [inStyleIndex] ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i0_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  switch (select_gtl_5F_debugger_5F_parser_0 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_cont COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 41)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_continue COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 43)) ;
  } break ;
  default:
    break ;
  }
  outArgument_instruction = GALGAS_gtlContinueInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 46)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 45)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i0_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  switch (select_gtl_5F_debugger_5F_parser_0 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_cont COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 41)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_continue COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 43)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i0_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  switch (select_gtl_5F_debugger_5F_parser_0 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_cont COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 41)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_continue COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 43)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i1_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_help COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 55)) ;
  outArgument_instruction = GALGAS_gtlHelpInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 57)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 56)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i1_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_help COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 55)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i1_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_help COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 55)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i2_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_step COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 66)) ;
  outArgument_instruction = GALGAS_gtlStepInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 68)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 67)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i2_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_step COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 66)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i2_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_step COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 66)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i3_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_load COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 77)) ;
  GALGAS_lstring var_fileName_1771 ;
  switch (select_gtl_5F_debugger_5F_parser_1 (inCompiler)) {
  case 1: {
    var_fileName_1771 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 80)) ;
  } break ;
  case 2: {
    var_fileName_1771 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 82)) ;
  } break ;
  default:
    break ;
  }
  outArgument_instruction = GALGAS_gtlLoadInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 85)), GALGAS_string::makeEmptyString (), var_fileName_1771.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 84)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i3_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_load COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 77)) ;
  switch (select_gtl_5F_debugger_5F_parser_1 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 80)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 82)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i3_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_load COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 77)) ;
  switch (select_gtl_5F_debugger_5F_parser_1 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 80)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 82)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i4_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_hist COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 95)) ;
  outArgument_instruction = GALGAS_gtlHistoryInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 97)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 96)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i4_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_hist COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 95)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i4_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_hist COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 95)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i5_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_break COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 106)) ;
  switch (select_gtl_5F_debugger_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_not COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 108)) ;
    switch (select_gtl_5F_debugger_5F_parser_3 (inCompiler)) {
    case 1: {
      GALGAS_lbigint var_index_2386 = inCompiler->synthetizedAttribute_intValue () ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 110)) ;
      outArgument_instruction = GALGAS_gtlBreakpointDeleteInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 112)), GALGAS_string::makeEmptyString (), var_index_2386  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 111)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_all COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 117)) ;
      outArgument_instruction = GALGAS_gtlBreakpointDeleteAllInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 119)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 118)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    switch (select_gtl_5F_debugger_5F_parser_4 (inCompiler)) {
    case 1: {
      GALGAS_lstring var_fileName_2679 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 125)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2E_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 126)) ;
      GALGAS_lstring var_fileExtension_2731 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 127)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 128)) ;
      GALGAS_lbigint var_lineNum_2807 = inCompiler->synthetizedAttribute_intValue () ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 129)) ;
      outArgument_instruction = GALGAS_gtlBreakpointInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 131)), GALGAS_string::makeEmptyString (), var_fileName_2679.readProperty_string ().add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 133)).add_operation (var_fileExtension_2731.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 133)), var_lineNum_2807.readProperty_bigint ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 134))  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 130)) ;
    } break ;
    case 2: {
      GALGAS_lbigint var_lineNum_3036 = inCompiler->synthetizedAttribute_intValue () ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 137)) ;
      outArgument_instruction = GALGAS_gtlBreakpointInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 139)), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), var_lineNum_3036.readProperty_bigint ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 142))  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 138)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 3: {
    GALGAS_lstring var_fileNameAndLineNum_3209 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 146)) ;
    GALGAS_stringlist var_components_3248 = var_fileNameAndLineNum_3209.readProperty_string ().getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 147)) ;
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (kIsEqual, var_components_3248.getter_count (SOURCE_FILE ("gtl_debugger_parser.galgas", 148)).objectCompare (GALGAS_uint (uint32_t (2U)))).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_string var_fileName_3379 = var_components_3248.getter_mValueAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 149)) ;
        GALGAS_string var_lineNum_3438 = var_components_3248.getter_mValueAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 150)) ;
        outArgument_instruction = GALGAS_gtlBreakpointInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 152)), GALGAS_string::makeEmptyString (), var_fileName_3379, var_lineNum_3438.getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 155))  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 151)) ;
      }
    }
    if (kBoolFalse == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 158)), GALGAS_string ("Illegal breakpoint location"), fixItArray1  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 158)) ;
      outArgument_instruction.drop () ; // Release error dropped variable
    }
  } break ;
  case 4: {
    outArgument_instruction = GALGAS_gtlBreakpointListInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 162)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 161)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i5_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_break COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 106)) ;
  switch (select_gtl_5F_debugger_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_not COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 108)) ;
    switch (select_gtl_5F_debugger_5F_parser_3 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 110)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_all COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 117)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    switch (select_gtl_5F_debugger_5F_parser_4 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 125)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2E_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 126)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 127)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 128)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 129)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 137)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 146)) ;
  } break ;
  case 4: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i5_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_break COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 106)) ;
  switch (select_gtl_5F_debugger_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_not COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 108)) ;
    switch (select_gtl_5F_debugger_5F_parser_3 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 110)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_all COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 117)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    switch (select_gtl_5F_debugger_5F_parser_4 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 125)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2E_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 126)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 127)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 128)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 129)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 137)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 146)) ;
  } break ;
  case 4: {
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i6_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_watch COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 172)) ;
  switch (select_gtl_5F_debugger_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_not COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 174)) ;
    switch (select_gtl_5F_debugger_5F_parser_6 (inCompiler)) {
    case 1: {
      GALGAS_lbigint var_index_4037 = inCompiler->synthetizedAttribute_intValue () ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 176)) ;
      outArgument_instruction = GALGAS_gtlWatchpointDeleteInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 178)), GALGAS_string::makeEmptyString (), var_index_4037  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 177)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_all COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 183)) ;
      outArgument_instruction = GALGAS_gtlWatchpointDeleteAllInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 185)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 184)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 190)) ;
    GALGAS_gtlExpression var_watchExpression_4334 ;
    nt_gtl_5F_expression_ (var_watchExpression_4334, inCompiler) ;
    outArgument_instruction = GALGAS_gtlWatchpointInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 193)), GALGAS_string::makeEmptyString (), var_watchExpression_4334  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 192)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 197)) ;
  } break ;
  case 3: {
    outArgument_instruction = GALGAS_gtlWatchpointListInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 200)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 199)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i6_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_watch COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 172)) ;
  switch (select_gtl_5F_debugger_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_not COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 174)) ;
    switch (select_gtl_5F_debugger_5F_parser_6 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 176)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_all COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 183)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 190)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 197)) ;
  } break ;
  case 3: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i6_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_watch COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 172)) ;
  switch (select_gtl_5F_debugger_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_not COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 174)) ;
    switch (select_gtl_5F_debugger_5F_parser_6 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 176)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_all COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 183)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 190)) ;
    nt_gtl_5F_expression_indexing (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 197)) ;
  } break ;
  case 3: {
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i7_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 211)) ;
  switch (select_gtl_5F_debugger_5F_parser_7 (inCompiler)) {
  case 1: {
    GALGAS_gtlInstruction var_instructionToStepDo_4766 ;
    nt_gtl_5F_step_5F_do_5F_command_ (var_instructionToStepDo_4766, inCompiler) ;
    outArgument_instruction = GALGAS_gtlDoInstInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 215)), GALGAS_string::makeEmptyString (), var_instructionToStepDo_4766  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 214)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_not COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 220)) ;
    switch (select_gtl_5F_debugger_5F_parser_8 (inCompiler)) {
    case 1: {
      GALGAS_lbigint var_num_4966 = inCompiler->synthetizedAttribute_intValue () ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 222)) ;
      outArgument_instruction = GALGAS_gtlDoNotInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 224)), GALGAS_string::makeEmptyString (), var_num_4966  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 223)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_all COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 229)) ;
      outArgument_instruction = GALGAS_gtlDoNotAllInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 231)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 230)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 3: {
    outArgument_instruction = GALGAS_gtlDoInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 237)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 236)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i7_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 211)) ;
  switch (select_gtl_5F_debugger_5F_parser_7 (inCompiler)) {
  case 1: {
    nt_gtl_5F_step_5F_do_5F_command_parse (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_not COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 220)) ;
    switch (select_gtl_5F_debugger_5F_parser_8 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 222)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_all COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 229)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 3: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i7_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 211)) ;
  switch (select_gtl_5F_debugger_5F_parser_7 (inCompiler)) {
  case 1: {
    nt_gtl_5F_step_5F_do_5F_command_indexing (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_not COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 220)) ;
    switch (select_gtl_5F_debugger_5F_parser_8 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 222)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_all COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 229)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 3: {
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i8_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  outArgument_instruction = GALGAS_gtlStepInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 248)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 247)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i8_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i8_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * /* inCompiler */) {
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i9_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_let COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 257)) ;
  GALGAS_gtlVarPath var_variable_5664 ;
  nt_gtl_5F_variable_ (var_variable_5664, inCompiler) ;
  switch (select_gtl_5F_debugger_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 260)) ;
    GALGAS_gtlExpression var_expression_5732 ;
    nt_gtl_5F_expression_ (var_expression_5732, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 263)), GALGAS_string::makeEmptyString (), var_variable_5664, var_expression_5732  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 262)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2B__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 269)) ;
    GALGAS_gtlExpression var_expression_5906 ;
    nt_gtl_5F_expression_ (var_expression_5906, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetAddInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 272)), GALGAS_string::makeEmptyString (), var_variable_5664, var_expression_5906  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 271)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2D__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 278)) ;
    GALGAS_gtlExpression var_expression_6082 ;
    nt_gtl_5F_expression_ (var_expression_6082, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetSubstractInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 281)), GALGAS_string::makeEmptyString (), var_variable_5664, var_expression_6082  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 280)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2A__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 287)) ;
    GALGAS_gtlExpression var_expression_6264 ;
    nt_gtl_5F_expression_ (var_expression_6264, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetMultiplyInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 290)), GALGAS_string::makeEmptyString (), var_variable_5664, var_expression_6264  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 289)) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2F__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 296)) ;
    GALGAS_gtlExpression var_expression_6445 ;
    nt_gtl_5F_expression_ (var_expression_6445, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetDivideInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 299)), GALGAS_string::makeEmptyString (), var_variable_5664, var_expression_6445  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 298)) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_mod_3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 305)) ;
    GALGAS_gtlExpression var_expression_6626 ;
    nt_gtl_5F_expression_ (var_expression_6626, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetModuloInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 308)), GALGAS_string::makeEmptyString (), var_variable_5664, var_expression_6626  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 307)) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 314)) ;
    GALGAS_gtlExpression var_expression_6806 ;
    nt_gtl_5F_expression_ (var_expression_6806, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetShiftLeftInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 317)), GALGAS_string::makeEmptyString (), var_variable_5664, var_expression_6806  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 316)) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 323)) ;
    GALGAS_gtlExpression var_expression_6989 ;
    nt_gtl_5F_expression_ (var_expression_6989, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetShiftRightInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 326)), GALGAS_string::makeEmptyString (), var_variable_5664, var_expression_6989  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 325)) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__26__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 332)) ;
    GALGAS_gtlExpression var_expression_7172 ;
    nt_gtl_5F_expression_ (var_expression_7172, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetAndInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 335)), GALGAS_string::makeEmptyString (), var_variable_5664, var_expression_7172  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 334)) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7C__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 341)) ;
    GALGAS_gtlExpression var_expression_7348 ;
    nt_gtl_5F_expression_ (var_expression_7348, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetOrInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 344)), GALGAS_string::makeEmptyString (), var_variable_5664, var_expression_7348  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 343)) ;
  } break ;
  case 11: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5E__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 350)) ;
    GALGAS_gtlExpression var_expression_7523 ;
    nt_gtl_5F_expression_ (var_expression_7523, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetXorInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 353)), GALGAS_string::makeEmptyString (), var_variable_5664, var_expression_7523  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 352)) ;
  } break ;
  case 12: {
    outArgument_instruction = GALGAS_gtlLetUnconstructedInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 360)), GALGAS_string::makeEmptyString (), var_variable_5664  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 359)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i9_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_let COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 257)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  switch (select_gtl_5F_debugger_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 260)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2B__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 269)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2D__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 278)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2A__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 287)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2F__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 296)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_mod_3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 305)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 314)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 323)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__26__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 332)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7C__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 341)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 11: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5E__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 350)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 12: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i9_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_let COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 257)) ;
  nt_gtl_5F_variable_indexing (inCompiler) ;
  switch (select_gtl_5F_debugger_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 260)) ;
    nt_gtl_5F_expression_indexing (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2B__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 269)) ;
    nt_gtl_5F_expression_indexing (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2D__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 278)) ;
    nt_gtl_5F_expression_indexing (inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2A__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 287)) ;
    nt_gtl_5F_expression_indexing (inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2F__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 296)) ;
    nt_gtl_5F_expression_indexing (inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_mod_3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 305)) ;
    nt_gtl_5F_expression_indexing (inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 314)) ;
    nt_gtl_5F_expression_indexing (inCompiler) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 323)) ;
    nt_gtl_5F_expression_indexing (inCompiler) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__26__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 332)) ;
    nt_gtl_5F_expression_indexing (inCompiler) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7C__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 341)) ;
    nt_gtl_5F_expression_indexing (inCompiler) ;
  } break ;
  case 11: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5E__3D_ COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 350)) ;
    nt_gtl_5F_expression_indexing (inCompiler) ;
  } break ;
  case 12: {
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i10_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                        C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_unlet COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 371)) ;
  GALGAS_gtlVarPath var_variable_7943 ;
  nt_gtl_5F_variable_ (var_variable_7943, inCompiler) ;
  outArgument_instruction = GALGAS_gtlUnletInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 374)), GALGAS_string::makeEmptyString (), var_variable_7943  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 373)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i10_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_unlet COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 371)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i10_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_unlet COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 371)) ;
  nt_gtl_5F_variable_indexing (inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i11_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                        C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  nt_gtl_5F_step_5F_do_5F_command_ (outArgument_instruction, inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i11_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  nt_gtl_5F_step_5F_do_5F_command_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i11_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  nt_gtl_5F_step_5F_do_5F_command_indexing (inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i12_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                          C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_variables COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 391)) ;
  outArgument_instruction = GALGAS_gtlVariablesInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 393)), GALGAS_string::makeEmptyString (), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 392)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i12_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_variables COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 391)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i12_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_variables COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 391)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i13_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                          C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_display COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 403)) ;
  GALGAS_gtlVarPath var_variable_8639 ;
  nt_gtl_5F_variable_ (var_variable_8639, inCompiler) ;
  outArgument_instruction = GALGAS_gtlDisplayStatementInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 406)), GALGAS_string::makeEmptyString (), var_variable_8639  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 405)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i13_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_display COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 403)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i13_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_display COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 403)) ;
  nt_gtl_5F_variable_indexing (inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i14_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                          C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_print COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 416)) ;
  GALGAS_gtlExpression var_expression_8934 ;
  nt_gtl_5F_expression_ (var_expression_8934, inCompiler) ;
  outArgument_instruction = GALGAS_gtlPrintStatementInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 419)), GALGAS_string::makeEmptyString (), GALGAS_bool (true), var_expression_8934  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 418)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i14_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_print COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 416)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i14_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_print COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 416)) ;
  nt_gtl_5F_expression_indexing (inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i15_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                          C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_list COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 430)) ;
  GALGAS_uint var_window_9206 = GALGAS_uint (uint32_t (5U)) ;
  switch (select_gtl_5F_debugger_5F_parser_10 (inCompiler)) {
  case 1: {
    GALGAS_lbigint var_num_9277 = inCompiler->synthetizedAttribute_intValue () ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 433)) ;
    var_window_9206 = var_num_9277.readProperty_bigint ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 434)) ;
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (kIsStrictSup, var_window_9206.objectCompare (GALGAS_uint (uint32_t (10U)))).boolEnum () ;
      if (kBoolTrue == test_0) {
        var_window_9206 = GALGAS_uint (uint32_t (10U)) ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  outArgument_instruction = GALGAS_gtlListInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 439)), GALGAS_string::makeEmptyString (), var_window_9206  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 438)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i15_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_list COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 430)) ;
  switch (select_gtl_5F_debugger_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 433)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i15_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_list COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 430)) ;
  switch (select_gtl_5F_debugger_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 433)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i16_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                          C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlThenElsifStatementList var_thenElsifList_9753 = GALGAS_gtlThenElsifStatementList::constructor_emptyList (SOURCE_FILE ("gtl_debugger_parser.galgas", 451)) ;
  GALGAS_gtlInstructionList var_elseList_9802 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_debugger_parser.galgas", 452)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_if COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 454)) ;
  GALGAS_location var_where_9850 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 454)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_gtlExpression var_condition_9914 ;
    nt_gtl_5F_expression_ (var_condition_9914, inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_then COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 457)) ;
    GALGAS_gtlInstructionList var_instructionList_9991 ;
    nt_gtl_5F_step_5F_do_5F_command_5F_list_ (var_instructionList_9991, inCompiler) ;
    var_thenElsifList_9753.addAssign_operation (var_condition_9914, var_instructionList_9991  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 460)) ;
    if (select_gtl_5F_debugger_5F_parser_11 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 462)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  switch (select_gtl_5F_debugger_5F_parser_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_else COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 466)) ;
    nt_gtl_5F_step_5F_do_5F_command_5F_list_ (var_elseList_9802, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 470)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_if COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 471)) ;
  outArgument_instruction = GALGAS_gtlIfStatementInstruction::constructor_new (var_where_9850, function_signature (var_where_9850, inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 474)), var_thenElsifList_9753, var_elseList_9802  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 473)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i16_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_if COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 454)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_then COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 457)) ;
    nt_gtl_5F_step_5F_do_5F_command_5F_list_parse (inCompiler) ;
    if (select_gtl_5F_debugger_5F_parser_11 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 462)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  switch (select_gtl_5F_debugger_5F_parser_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_else COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 466)) ;
    nt_gtl_5F_step_5F_do_5F_command_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 470)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_if COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 471)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i16_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_if COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 454)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_gtl_5F_expression_indexing (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_then COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 457)) ;
    nt_gtl_5F_step_5F_do_5F_command_5F_list_indexing (inCompiler) ;
    if (select_gtl_5F_debugger_5F_parser_11 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 462)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  switch (select_gtl_5F_debugger_5F_parser_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_else COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 466)) ;
    nt_gtl_5F_step_5F_do_5F_command_5F_list_indexing (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 470)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_if COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 471)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_5F_list_i17_ (GALGAS_gtlInstructionList & outArgument_instructionList,
                                                                                                                  C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_instructionList.drop () ; // Release 'out' argument
  outArgument_instructionList = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_debugger_parser.galgas", 484)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_gtl_5F_debugger_5F_parser_13 (inCompiler) == 2) {
      GALGAS_gtlInstruction var_instruction_10708 ;
      nt_gtl_5F_step_5F_do_5F_command_ (var_instruction_10708, inCompiler) ;
      outArgument_instructionList.addAssign_operation (var_instruction_10708  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 489)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_5F_list_i17_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_gtl_5F_debugger_5F_parser_13 (inCompiler) == 2) {
      nt_gtl_5F_step_5F_do_5F_command_parse (inCompiler) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_5F_list_i17_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_gtl_5F_debugger_5F_parser_13 (inCompiler) == 2) {
      nt_gtl_5F_step_5F_do_5F_command_indexing (inCompiler) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_expression_i0_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                          C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  nt_gtl_5F_relation_5F_term_ (outArgument_expression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_debugger_5F_expression_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 39)) ;
      GALGAS_location var_opLocation_1114 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 39)) ;
      GALGAS_gtlExpression var_rightSon_1177 ;
      nt_gtl_5F_relation_5F_term_ (var_rightSon_1177, inCompiler) ;
      outArgument_expression = GALGAS_gtlOrExpression::constructor_new (var_opLocation_1114, outArgument_expression, var_rightSon_1177  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 41)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5E_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 43)) ;
      GALGAS_location var_opLocation_1294 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 43)) ;
      GALGAS_gtlExpression var_rightSon_1357 ;
      nt_gtl_5F_relation_5F_term_ (var_rightSon_1357, inCompiler) ;
      outArgument_expression = GALGAS_gtlXorExpression::constructor_new (var_opLocation_1294, outArgument_expression, var_rightSon_1357  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 45)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_expression_i0_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  nt_gtl_5F_relation_5F_term_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_debugger_5F_expression_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 39)) ;
      nt_gtl_5F_relation_5F_term_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5E_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 43)) ;
      nt_gtl_5F_relation_5F_term_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_expression_i0_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  nt_gtl_5F_relation_5F_term_indexing (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_debugger_5F_expression_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 39)) ;
      nt_gtl_5F_relation_5F_term_indexing (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5E_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 43)) ;
      nt_gtl_5F_relation_5F_term_indexing (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                                C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  nt_gtl_5F_relation_5F_factor_ (outArgument_expression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_gtl_5F_debugger_5F_expression_5F_parser_1 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__26_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 59)) ;
      GALGAS_location var_opLocation_1829 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 59)) ;
      GALGAS_gtlExpression var_rightSon_1894 ;
      nt_gtl_5F_relation_5F_factor_ (var_rightSon_1894, inCompiler) ;
      outArgument_expression = GALGAS_gtlAndExpression::constructor_new (var_opLocation_1829, outArgument_expression, var_rightSon_1894  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 61)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  nt_gtl_5F_relation_5F_factor_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_gtl_5F_debugger_5F_expression_5F_parser_1 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__26_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 59)) ;
      nt_gtl_5F_relation_5F_factor_parse (inCompiler) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  nt_gtl_5F_relation_5F_factor_indexing (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_gtl_5F_debugger_5F_expression_5F_parser_1 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__26_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 59)) ;
      nt_gtl_5F_relation_5F_factor_indexing (inCompiler) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                                  C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  nt_gtl_5F_simple_5F_expression_ (outArgument_expression, inCompiler) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_2 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3D__3D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 75)) ;
    GALGAS_location var_opLocation_2368 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 75)) ;
    GALGAS_gtlExpression var_rightSon_2435 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_2435, inCompiler) ;
    outArgument_expression = GALGAS_gtlEqualExpression::constructor_new (var_opLocation_2368, outArgument_expression, var_rightSon_2435  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 77)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__21__3D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 81)) ;
    GALGAS_location var_opLocation_2563 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 81)) ;
    GALGAS_gtlExpression var_rightSon_2630 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_2630, inCompiler) ;
    outArgument_expression = GALGAS_gtlNotEqualExpression::constructor_new (var_opLocation_2563, outArgument_expression, var_rightSon_2630  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 83)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 87)) ;
    GALGAS_location var_opLocation_2761 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 87)) ;
    GALGAS_gtlExpression var_rightSon_2828 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_2828, inCompiler) ;
    outArgument_expression = GALGAS_gtlLowerOrEqualExpression::constructor_new (var_opLocation_2761, outArgument_expression, var_rightSon_2828  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 89)) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 93)) ;
    GALGAS_location var_opLocation_2963 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 93)) ;
    GALGAS_gtlExpression var_rightSon_3030 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_3030, inCompiler) ;
    outArgument_expression = GALGAS_gtlGreaterOrEqualExpression::constructor_new (var_opLocation_2963, outArgument_expression, var_rightSon_3030  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 95)) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 99)) ;
    GALGAS_location var_opLocation_3166 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 99)) ;
    GALGAS_gtlExpression var_rightSon_3233 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_3233, inCompiler) ;
    outArgument_expression = GALGAS_gtlGreaterThanExpression::constructor_new (var_opLocation_3166, outArgument_expression, var_rightSon_3233  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 101)) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 105)) ;
    GALGAS_location var_opLocation_3366 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 105)) ;
    GALGAS_gtlExpression var_rightSon_3433 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_3433, inCompiler) ;
    outArgument_expression = GALGAS_gtlLowerThanExpression::constructor_new (var_opLocation_3366, outArgument_expression, var_rightSon_3433  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 107)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_2 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3D__3D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 75)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__21__3D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 81)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 87)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 93)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 99)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 105)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  nt_gtl_5F_simple_5F_expression_indexing (inCompiler) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_2 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3D__3D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 75)) ;
    nt_gtl_5F_simple_5F_expression_indexing (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__21__3D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 81)) ;
    nt_gtl_5F_simple_5F_expression_indexing (inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 87)) ;
    nt_gtl_5F_simple_5F_expression_indexing (inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 93)) ;
    nt_gtl_5F_simple_5F_expression_indexing (inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 99)) ;
    nt_gtl_5F_simple_5F_expression_indexing (inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 105)) ;
    nt_gtl_5F_simple_5F_expression_indexing (inCompiler) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                                    C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  nt_gtl_5F_term_ (outArgument_expression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_debugger_5F_expression_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 123)) ;
      GALGAS_location var_opLocation_3916 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 123)) ;
      GALGAS_gtlExpression var_rightSon_3970 ;
      nt_gtl_5F_term_ (var_rightSon_3970, inCompiler) ;
      outArgument_expression = GALGAS_gtlShiftLeftExpression::constructor_new (var_opLocation_3916, outArgument_expression, var_rightSon_3970  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 125)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 129)) ;
      GALGAS_location var_opLocation_4106 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 129)) ;
      GALGAS_gtlExpression var_rightSon_4160 ;
      nt_gtl_5F_term_ (var_rightSon_4160, inCompiler) ;
      outArgument_expression = GALGAS_gtlShiftRightExpression::constructor_new (var_opLocation_4106, outArgument_expression, var_rightSon_4160  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 131)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 135)) ;
      GALGAS_location var_opLocation_4296 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 135)) ;
      GALGAS_gtlExpression var_rightSon_4350 ;
      nt_gtl_5F_term_ (var_rightSon_4350, inCompiler) ;
      outArgument_expression = GALGAS_gtlAddExpression::constructor_new (var_opLocation_4296, outArgument_expression, var_rightSon_4350  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 137)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2E_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 141)) ;
      GALGAS_location var_opLocation_4479 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 141)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.readProperty_value ()).boolEnum () ;
        if (kBoolTrue == test_1) {
          TC_Array <C_FixItDescription> fixItArray2 ;
          appendFixItActions (fixItArray2, kFixItReplace, GALGAS_string ("+")) ;
          inCompiler->emitSemanticWarning (var_opLocation_4479, GALGAS_string ("'.' operator is deprecated"), fixItArray2  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 143)) ;
        }
      }
      GALGAS_gtlExpression var_rightSon_4673 ;
      nt_gtl_5F_term_ (var_rightSon_4673, inCompiler) ;
      outArgument_expression = GALGAS_gtlAddExpression::constructor_new (var_opLocation_4479, outArgument_expression, var_rightSon_4673  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 146)) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 150)) ;
      GALGAS_location var_opLocation_4802 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 150)) ;
      GALGAS_gtlExpression var_rightSon_4856 ;
      nt_gtl_5F_term_ (var_rightSon_4856, inCompiler) ;
      outArgument_expression = GALGAS_gtlSubstractExpression::constructor_new (var_opLocation_4802, outArgument_expression, var_rightSon_4856  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 152)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  nt_gtl_5F_term_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_debugger_5F_expression_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 123)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 129)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 135)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2E_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 141)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 150)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  nt_gtl_5F_term_indexing (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_debugger_5F_expression_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 123)) ;
      nt_gtl_5F_term_indexing (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 129)) ;
      nt_gtl_5F_term_indexing (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 135)) ;
      nt_gtl_5F_term_indexing (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2E_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 141)) ;
      nt_gtl_5F_term_indexing (inCompiler) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 150)) ;
      nt_gtl_5F_term_indexing (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_term_i4_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                    C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  nt_gtl_5F_factor_ (outArgument_expression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_debugger_5F_expression_5F_parser_4 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2A_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 168)) ;
      GALGAS_location var_opLocation_5327 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 168)) ;
      GALGAS_gtlExpression var_rightSon_5383 ;
      nt_gtl_5F_factor_ (var_rightSon_5383, inCompiler) ;
      outArgument_expression = GALGAS_gtlMultiplyExpression::constructor_new (var_opLocation_5327, outArgument_expression, var_rightSon_5383  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 170)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2F_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 174)) ;
      GALGAS_location var_opLocation_5517 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 174)) ;
      GALGAS_gtlExpression var_rightSon_5573 ;
      nt_gtl_5F_factor_ (var_rightSon_5573, inCompiler) ;
      outArgument_expression = GALGAS_gtlDivideExpression::constructor_new (var_opLocation_5517, outArgument_expression, var_rightSon_5573  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 176)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_mod COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 180)) ;
      GALGAS_location var_opLocation_5707 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 180)) ;
      GALGAS_gtlExpression var_rightSon_5763 ;
      nt_gtl_5F_factor_ (var_rightSon_5763, inCompiler) ;
      outArgument_expression = GALGAS_gtlModulusExpression::constructor_new (var_opLocation_5707, outArgument_expression, var_rightSon_5763  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 182)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_term_i4_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  nt_gtl_5F_factor_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_debugger_5F_expression_5F_parser_4 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2A_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 168)) ;
      nt_gtl_5F_factor_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2F_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 174)) ;
      nt_gtl_5F_factor_parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_mod COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 180)) ;
      nt_gtl_5F_factor_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_term_i4_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  nt_gtl_5F_factor_indexing (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_debugger_5F_expression_5F_parser_4 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2A_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 168)) ;
      nt_gtl_5F_factor_indexing (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2F_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 174)) ;
      nt_gtl_5F_factor_indexing (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_mod COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 180)) ;
      nt_gtl_5F_factor_indexing (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i5_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                      C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 195)) ;
  GALGAS_location var_opLocation_6187 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 195)) ;
  GALGAS_gtlExpression var_factorExpression_6245 ;
  nt_gtl_5F_expression_ (var_factorExpression_6245, inCompiler) ;
  outArgument_expression = GALGAS_gtlParenthesizedExpression::constructor_new (var_opLocation_6187, var_factorExpression_6245  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 197)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 201)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i5_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 195)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 201)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i5_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 195)) ;
  nt_gtl_5F_expression_indexing (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 201)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i6_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                      C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_not COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 211)) ;
  GALGAS_location var_opLocation_6679 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 211)) ;
  GALGAS_gtlExpression var_notExpression_6733 ;
  nt_gtl_5F_factor_ (var_notExpression_6733, inCompiler) ;
  outArgument_expression = GALGAS_gtlNotExpression::constructor_new (var_opLocation_6679, var_notExpression_6733  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 213)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i6_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_not COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 211)) ;
  nt_gtl_5F_factor_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i6_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_not COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 211)) ;
  nt_gtl_5F_factor_indexing (inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i7_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                      C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7E_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 223)) ;
  GALGAS_location var_opLocation_7133 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 223)) ;
  GALGAS_gtlExpression var_notExpression_7187 ;
  nt_gtl_5F_factor_ (var_notExpression_7187, inCompiler) ;
  outArgument_expression = GALGAS_gtlNotExpression::constructor_new (var_opLocation_7133, var_notExpression_7187  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 225)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i7_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7E_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 223)) ;
  nt_gtl_5F_factor_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i7_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7E_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 223)) ;
  nt_gtl_5F_factor_indexing (inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i8_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                      C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 235)) ;
  GALGAS_location var_opLocation_7587 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 235)) ;
  GALGAS_gtlExpression var_minusExpression_7641 ;
  nt_gtl_5F_factor_ (var_minusExpression_7641, inCompiler) ;
  outArgument_expression = GALGAS_gtlMinusExpression::constructor_new (var_opLocation_7587, var_minusExpression_7641  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 237)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i8_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 235)) ;
  nt_gtl_5F_factor_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i8_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 235)) ;
  nt_gtl_5F_factor_indexing (inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i9_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                      C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 247)) ;
  GALGAS_location var_opLocation_8047 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 247)) ;
  GALGAS_gtlExpression var_plusExpression_8101 ;
  nt_gtl_5F_factor_ (var_plusExpression_8101, inCompiler) ;
  outArgument_expression = GALGAS_gtlPlusExpression::constructor_new (var_opLocation_8047, var_plusExpression_8101  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 249)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i9_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 247)) ;
  nt_gtl_5F_factor_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i9_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 247)) ;
  nt_gtl_5F_factor_indexing (inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i10_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_yes COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 259)) ;
  GALGAS_location var_opLocation_8506 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 259)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (var_opLocation_8506, GALGAS_gtlBool::constructor_new (var_opLocation_8506, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 261)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 261))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 260)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i10_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_yes COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 259)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i10_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_yes COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 259)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i11_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_no COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 272)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 274)), GALGAS_gtlBool::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 274)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 274)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 274))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 273)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i11_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_no COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 272)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i11_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_no COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 272)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i12_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_lbigint var_literalInteger_9373 = inCompiler->synthetizedAttribute_intValue () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 285)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 287)), GALGAS_gtlInt::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 287)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 287)), var_literalInteger_9373.readProperty_bigint ()  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 287))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 286)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i12_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 285)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i12_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 285)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i13_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_ldouble var_literalFloat_9830 = inCompiler->synthetizedAttribute_floatValue () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_double COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 298)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 300)), GALGAS_gtlFloat::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 300)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 300)), var_literalFloat_9830.readProperty_double ()  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 300))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 299)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i13_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_double COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 298)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i13_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_double COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 298)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i14_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_lstring var_literalString_10277 = inCompiler->synthetizedAttribute_a_5F_string () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 311)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 313)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 313)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 313)), var_literalString_10277.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 313))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 312)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i14_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 311)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i14_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 311)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i15_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_lchar var_literalChar_10729 = inCompiler->synthetizedAttribute_charValue () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_char COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 324)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 326)), GALGAS_gtlChar::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 326)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 326)), var_literalChar_10729.readProperty_char ()  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 326))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 325)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i15_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_char COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 324)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i15_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_char COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 324)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i16_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 338)) ;
  GALGAS_gtlExpression var_target_11272 ;
  nt_gtl_5F_expression_ (var_target_11272, inCompiler) ;
  GALGAS_lstring var_getterName_11308 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 340)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.readProperty_value ()).boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("stringByCapitalizingFirstCharacter").objectCompare (var_getterName_11308.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_1) {
          TC_Array <C_FixItDescription> fixItArray2 ;
          appendFixItActions (fixItArray2, kFixItReplace, GALGAS_string ("capitalized")) ;
          inCompiler->emitSemanticWarning (var_getterName_11308.readProperty_location (), GALGAS_string ("stringByCapitalizingFirstCharacter is deprecated"), fixItArray2  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 343)) ;
        }
      }
    }
  }
  GALGAS_gtlExpressionList var_argumentList_11587 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 347)) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_5 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 350)) ;
    bool repeatFlag_3 = true ;
    while (repeatFlag_3) {
      GALGAS_gtlExpression var_argument_11689 ;
      nt_gtl_5F_expression_ (var_argument_11689, inCompiler) ;
      var_argumentList_11587.addAssign_operation (var_argument_11689  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 353)) ;
      if (select_gtl_5F_debugger_5F_expression_5F_parser_6 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 355)) ;
      }else{
        repeatFlag_3 = false ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 358)) ;
  outArgument_expression = GALGAS_gtlGetterCallExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 360)), var_target_11272, var_getterName_11308, var_argumentList_11587  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 359)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i16_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 338)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 340)) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_5 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 350)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_parse (inCompiler) ;
      if (select_gtl_5F_debugger_5F_expression_5F_parser_6 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 355)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 358)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i16_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 338)) ;
  nt_gtl_5F_expression_indexing (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 340)) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_5 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 350)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_indexing (inCompiler) ;
      if (select_gtl_5F_debugger_5F_expression_5F_parser_6 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 355)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 358)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i17_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_gtlVarPath var_path_12045 ;
  nt_gtl_5F_variable_ (var_path_12045, inCompiler) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_7 (inCompiler)) {
  case 1: {
    outArgument_expression = GALGAS_gtlVarRef::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 374)), var_path_12045  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 374)) ;
  } break ;
  case 2: {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (kIsStrictSup, var_path_12045.getter_count (SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 376)).objectCompare (GALGAS_uint (uint32_t (1U)))).boolEnum () ;
      if (kBoolTrue == test_0) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 377)), GALGAS_string ("illegal function name"), fixItArray1  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 377)) ;
      }
    }
    GALGAS_gtlExpressionList var_functionArguments_12218 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 379)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 380)) ;
    switch (select_gtl_5F_debugger_5F_expression_5F_parser_8 (inCompiler)) {
    case 1: {
      bool repeatFlag_2 = true ;
      while (repeatFlag_2) {
        GALGAS_gtlExpression var_expression_12326 ;
        nt_gtl_5F_expression_ (var_expression_12326, inCompiler) ;
        var_functionArguments_12218.addAssign_operation (var_expression_12326  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 384)) ;
        if (select_gtl_5F_debugger_5F_expression_5F_parser_9 (inCompiler) == 2) {
          inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 386)) ;
        }else{
          repeatFlag_2 = false ;
        }
      }
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 389)) ;
    GALGAS_lstring var_functionName_12448 = extensionGetter_pathAsFunctionName (var_path_12045, inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 390)) ;
    outArgument_expression = GALGAS_gtlFunctionCallExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 392)), var_functionName_12448, var_functionArguments_12218  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 391)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i17_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  nt_gtl_5F_variable_parse (inCompiler) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_7 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 380)) ;
    switch (select_gtl_5F_debugger_5F_expression_5F_parser_8 (inCompiler)) {
    case 1: {
      bool repeatFlag_0 = true ;
      while (repeatFlag_0) {
        nt_gtl_5F_expression_parse (inCompiler) ;
        if (select_gtl_5F_debugger_5F_expression_5F_parser_9 (inCompiler) == 2) {
          inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 386)) ;
        }else{
          repeatFlag_0 = false ;
        }
      }
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 389)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i17_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  nt_gtl_5F_variable_indexing (inCompiler) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_7 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 380)) ;
    switch (select_gtl_5F_debugger_5F_expression_5F_parser_8 (inCompiler)) {
    case 1: {
      bool repeatFlag_0 = true ;
      while (repeatFlag_0) {
        nt_gtl_5F_expression_indexing (inCompiler) ;
        if (select_gtl_5F_debugger_5F_expression_5F_parser_9 (inCompiler) == 2) {
          inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 386)) ;
        }else{
          repeatFlag_0 = false ;
        }
      }
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 389)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i18_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_exists COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 404)) ;
  GALGAS_gtlVarPath var_path_12788 ;
  nt_gtl_5F_variable_ (var_path_12788, inCompiler) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_default COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 406)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 407)) ;
    GALGAS_gtlExpression var_defaultExpression_12865 ;
    nt_gtl_5F_expression_ (var_defaultExpression_12865, inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 409)) ;
    outArgument_expression = GALGAS_gtlExistsDefaultExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 411)), var_path_12788, var_defaultExpression_12865  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 410)) ;
  } break ;
  case 2: {
    outArgument_expression = GALGAS_gtlExistsExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 414)), var_path_12788  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 414)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i18_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_exists COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 404)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_default COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 406)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 407)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 409)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i18_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_exists COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 404)) ;
  nt_gtl_5F_variable_indexing (inCompiler) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_default COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 406)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 407)) ;
    nt_gtl_5F_expression_indexing (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 409)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i19_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_typeof COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 423)) ;
  GALGAS_gtlVarPath var_path_13235 ;
  nt_gtl_5F_variable_ (var_path_13235, inCompiler) ;
  outArgument_expression = GALGAS_gtlTypeOfExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 424)), var_path_13235  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 424)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i19_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_typeof COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 423)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i19_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_typeof COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 423)) ;
  nt_gtl_5F_variable_indexing (inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i20_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_true COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 432)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 434)), GALGAS_gtlBool::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 436)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 437)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 435))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 433)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i20_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_true COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 432)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i20_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_true COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 432)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i21_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_false COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 448)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 450)), GALGAS_gtlBool::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 452)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 453)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 451))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 449)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i21_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_false COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 448)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i21_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_false COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 448)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i22_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_lstring var_enumValue_13996 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_enum COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 464)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 466)), GALGAS_gtlEnum::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 468)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 469)), var_enumValue_13996.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 467))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 465)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i22_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_enum COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 464)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i22_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_enum COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 464)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i23_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 480)) ;
  GALGAS_lstring var_typeName_14303 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 480)) ;
  GALGAS_string var_name_14326 = var_typeName_14303.readProperty_string () ;
  GALGAS_gtlType var_type_14366 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, var_name_14326.objectCompare (GALGAS_string ("int"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      var_type_14366 = GALGAS_gtlType::constructor_new (var_typeName_14303.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 484)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 484)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, var_name_14326.objectCompare (GALGAS_string ("float"))).boolEnum () ;
      if (kBoolTrue == test_1) {
        var_type_14366 = GALGAS_gtlType::constructor_new (var_typeName_14303.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 486)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlFloat)  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 486)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, var_name_14326.objectCompare (GALGAS_string ("string"))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_type_14366 = GALGAS_gtlType::constructor_new (var_typeName_14303.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 488)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlString)  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 488)) ;
        }
      }
      if (kBoolFalse == test_2) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, var_name_14326.objectCompare (GALGAS_string ("bool"))).boolEnum () ;
          if (kBoolTrue == test_3) {
            var_type_14366 = GALGAS_gtlType::constructor_new (var_typeName_14303.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 490)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool)  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 490)) ;
          }
        }
        if (kBoolFalse == test_3) {
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsEqual, var_name_14326.objectCompare (GALGAS_string ("struct"))).boolEnum () ;
            if (kBoolTrue == test_4) {
              var_type_14366 = GALGAS_gtlType::constructor_new (var_typeName_14303.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 492)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct)  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 492)) ;
            }
          }
          if (kBoolFalse == test_4) {
            enumGalgasBool test_5 = kBoolTrue ;
            if (kBoolTrue == test_5) {
              test_5 = GALGAS_bool (kIsEqual, var_name_14326.objectCompare (GALGAS_string ("list"))).boolEnum () ;
              if (kBoolTrue == test_5) {
                var_type_14366 = GALGAS_gtlType::constructor_new (var_typeName_14303.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 494)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlList)  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 494)) ;
              }
            }
            if (kBoolFalse == test_5) {
              enumGalgasBool test_6 = kBoolTrue ;
              if (kBoolTrue == test_6) {
                test_6 = GALGAS_bool (kIsEqual, var_name_14326.objectCompare (GALGAS_string ("map"))).boolEnum () ;
                if (kBoolTrue == test_6) {
                  var_type_14366 = GALGAS_gtlType::constructor_new (var_typeName_14303.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 496)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlMap)  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 496)) ;
                }
              }
              if (kBoolFalse == test_6) {
                enumGalgasBool test_7 = kBoolTrue ;
                if (kBoolTrue == test_7) {
                  test_7 = GALGAS_bool (kIsEqual, var_name_14326.objectCompare (GALGAS_string ("enum"))).boolEnum () ;
                  if (kBoolTrue == test_7) {
                    var_type_14366 = GALGAS_gtlType::constructor_new (var_typeName_14303.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 498)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlEnum)  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 498)) ;
                  }
                }
                if (kBoolFalse == test_7) {
                  enumGalgasBool test_8 = kBoolTrue ;
                  if (kBoolTrue == test_8) {
                    test_8 = GALGAS_bool (kIsEqual, var_name_14326.objectCompare (GALGAS_string ("type"))).boolEnum () ;
                    if (kBoolTrue == test_8) {
                      var_type_14366 = GALGAS_gtlType::constructor_new (var_typeName_14303.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 500)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlType)  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 500)) ;
                    }
                  }
                  if (kBoolFalse == test_8) {
                    enumGalgasBool test_9 = kBoolTrue ;
                    if (kBoolTrue == test_9) {
                      test_9 = GALGAS_bool (kIsEqual, var_name_14326.objectCompare (GALGAS_string ("set"))).boolEnum () ;
                      if (kBoolTrue == test_9) {
                        var_type_14366 = GALGAS_gtlType::constructor_new (var_typeName_14303.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 502)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlSet)  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 502)) ;
                      }
                    }
                    if (kBoolFalse == test_9) {
                      enumGalgasBool test_10 = kBoolTrue ;
                      if (kBoolTrue == test_10) {
                        test_10 = GALGAS_bool (kIsEqual, var_name_14326.objectCompare (GALGAS_string ("char"))).boolEnum () ;
                        if (kBoolTrue == test_10) {
                          var_type_14366 = GALGAS_gtlType::constructor_new (var_typeName_14303.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 504)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar)  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 504)) ;
                        }
                      }
                      if (kBoolFalse == test_10) {
                        enumGalgasBool test_11 = kBoolTrue ;
                        if (kBoolTrue == test_11) {
                          test_11 = GALGAS_bool (kIsEqual, var_name_14326.objectCompare (GALGAS_string ("unconstructed"))).boolEnum () ;
                          if (kBoolTrue == test_11) {
                            var_type_14366 = GALGAS_gtlType::constructor_new (var_typeName_14303.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 506)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlUnconstructed)  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 506)) ;
                          }
                        }
                        if (kBoolFalse == test_11) {
                          TC_Array <C_FixItDescription> fixItArray12 ;
                          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 507)), var_name_14326.add_operation (GALGAS_string (" does not name a type"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 507)), fixItArray12  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 507)) ;
                          var_type_14366.drop () ; // Release error dropped variable
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
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (var_typeName_14303.readProperty_location (), var_type_14366  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 509)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i23_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 480)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 480)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i23_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 480)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 480)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i24_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_emptylist COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 517)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.readProperty_value ()).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      appendFixItActions (fixItArray1, kFixItReplace, GALGAS_string ("@( )")) ;
      inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 519)), GALGAS_string ("emptylist is deprecated"), fixItArray1  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 519)) ;
    }
  }
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 522)), GALGAS_gtlList::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 524)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 525)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 526))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 523))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 521)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i24_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_emptylist COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 517)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i24_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_emptylist COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 517)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i25_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_emptymap COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 536)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.readProperty_value ()).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      appendFixItActions (fixItArray1, kFixItReplace, GALGAS_string ("@[ ]")) ;
      inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 538)), GALGAS_string ("emptymap is deprecated"), fixItArray1  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 538)) ;
    }
  }
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 541)), GALGAS_gtlMap::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 543)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 544)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 545))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 542))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 540)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i25_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_emptymap COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 536)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i25_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_emptymap COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 536)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i26_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_mapof COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 555)) ;
  GALGAS_gtlExpression var_data_16685 ;
  nt_gtl_5F_expression_ (var_data_16685, inCompiler) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_by COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 558)) ;
    GALGAS_lstring var_key_16739 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 559)) ;
    outArgument_expression = GALGAS_gtlMapOfListExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 561)), var_data_16685, var_key_16739  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 560)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 566)) ;
    outArgument_expression = GALGAS_gtlMapOfStructExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 568)), var_data_16685  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 567)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i26_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_mapof COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 555)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_by COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 558)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 559)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 566)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i26_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_mapof COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 555)) ;
  nt_gtl_5F_expression_indexing (inCompiler) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_by COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 558)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 559)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 566)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i27_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_listof COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 579)) ;
  GALGAS_gtlExpression var_data_17118 ;
  nt_gtl_5F_expression_ (var_data_17118, inCompiler) ;
  outArgument_expression = GALGAS_gtlListOfExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 581)), var_data_17118  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 581)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 582)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i27_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_listof COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 579)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 582)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i27_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_listof COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 579)) ;
  nt_gtl_5F_expression_indexing (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 582)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i28_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40__28_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 590)) ;
  GALGAS_gtlExpressionList var_expressionList_17350 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 591)) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_12 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_gtlExpression var_listItem_17441 ;
      nt_gtl_5F_expression_ (var_listItem_17441, inCompiler) ;
      var_expressionList_17350.addAssign_operation (var_listItem_17441  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 595)) ;
      if (select_gtl_5F_debugger_5F_expression_5F_parser_13 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 596)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 600)) ;
  outArgument_expression = GALGAS_gtlLiteralListExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 601)), var_expressionList_17350  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 601)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i28_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40__28_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 590)) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_12 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_parse (inCompiler) ;
      if (select_gtl_5F_debugger_5F_expression_5F_parser_13 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 596)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 600)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i28_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40__28_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 590)) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_12 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_indexing (inCompiler) ;
      if (select_gtl_5F_debugger_5F_expression_5F_parser_13 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 596)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 600)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i29_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40__5B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 609)) ;
  GALGAS_gtlExpressionMap var_expressionMap_17756 = GALGAS_gtlExpressionMap::constructor_emptyMap (SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 610)) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_14 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_lstring var_key_17832 = inCompiler->synthetizedAttribute_a_5F_string () ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 613)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 614)) ;
      GALGAS_gtlExpression var_mapItem_17889 ;
      nt_gtl_5F_expression_ (var_mapItem_17889, inCompiler) ;
      {
      var_expressionMap_17756.setter_put (var_key_17832, var_mapItem_17889, inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 616)) ;
      }
      if (select_gtl_5F_debugger_5F_expression_5F_parser_15 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 617)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 621)) ;
  outArgument_expression = GALGAS_gtlLiteralMapExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 622)), var_expressionMap_17756  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 622)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i29_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40__5B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 609)) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_14 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 613)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 614)) ;
      nt_gtl_5F_expression_parse (inCompiler) ;
      if (select_gtl_5F_debugger_5F_expression_5F_parser_15 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 617)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 621)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i29_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40__5B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 609)) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_14 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 613)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 614)) ;
      nt_gtl_5F_expression_indexing (inCompiler) ;
      if (select_gtl_5F_debugger_5F_expression_5F_parser_15 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 617)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 621)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i30_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40__7B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 630)) ;
  GALGAS_gtlExpressionMap var_expressionMap_18209 = GALGAS_gtlExpressionMap::constructor_emptyMap (SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 631)) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_16 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_lstring var_fieldName_18288 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 634)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 635)) ;
      GALGAS_gtlExpression var_structField_18351 ;
      nt_gtl_5F_expression_ (var_structField_18351, inCompiler) ;
      {
      var_expressionMap_18209.setter_put (var_fieldName_18288, var_structField_18351, inCompiler COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 637)) ;
      }
      if (select_gtl_5F_debugger_5F_expression_5F_parser_17 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 638)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 642)) ;
  outArgument_expression = GALGAS_gtlLiteralStructExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 643)), var_expressionMap_18209  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 643)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i30_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40__7B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 630)) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_16 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 634)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 635)) ;
      nt_gtl_5F_expression_parse (inCompiler) ;
      if (select_gtl_5F_debugger_5F_expression_5F_parser_17 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 638)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 642)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i30_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40__7B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 630)) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_16 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 634)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 635)) ;
      nt_gtl_5F_expression_indexing (inCompiler) ;
      if (select_gtl_5F_debugger_5F_expression_5F_parser_17 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 638)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 642)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i31_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40__21_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 651)) ;
  GALGAS_gtlExpressionList var_expressionList_18689 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 652)) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_18 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_gtlExpression var_setElement_18780 ;
      nt_gtl_5F_expression_ (var_setElement_18780, inCompiler) ;
      var_expressionList_18689.addAssign_operation (var_setElement_18780  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 656)) ;
      if (select_gtl_5F_debugger_5F_expression_5F_parser_19 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 657)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__21_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 661)) ;
  outArgument_expression = GALGAS_gtlLiteralSetExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 662)), var_expressionList_18689  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 662)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i31_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40__21_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 651)) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_18 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_parse (inCompiler) ;
      if (select_gtl_5F_debugger_5F_expression_5F_parser_19 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 657)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__21_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 661)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i31_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__40__21_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 651)) ;
  switch (select_gtl_5F_debugger_5F_expression_5F_parser_18 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_indexing (inCompiler) ;
      if (select_gtl_5F_debugger_5F_expression_5F_parser_19 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 657)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__21_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 661)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_variable_i32_ (GALGAS_gtlVarPath & outArgument_path,
                                                                                                                         C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  outArgument_path.drop () ; // Release 'out' argument
  outArgument_path = GALGAS_gtlVarPath::constructor_emptyList (SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 670)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_lstring var_variableName_19124 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 672)) ;
    switch (select_gtl_5F_debugger_5F_expression_5F_parser_21 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 674)) ;
      GALGAS_gtlExpression var_expression_19201 ;
      nt_gtl_5F_expression_ (var_expression_19201, inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 676)) ;
      outArgument_path.addAssign_operation (GALGAS_gtlVarItemCollection::constructor_new (var_variableName_19124, var_expression_19201  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 677))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 677)) ;
      switch (select_gtl_5F_debugger_5F_expression_5F_parser_22 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 679)) ;
        GALGAS_gtlExpression var_expression_19363 ;
        nt_gtl_5F_expression_ (var_expression_19363, inCompiler) ;
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 681)) ;
        outArgument_path.addAssign_operation (GALGAS_gtlVarItemSubCollection::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 682)), var_expression_19363  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 682))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 682)) ;
        bool repeatFlag_1 = true ;
        while (repeatFlag_1) {
          if (select_gtl_5F_debugger_5F_expression_5F_parser_23 (inCompiler) == 2) {
            inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 685)) ;
            GALGAS_gtlExpression var_expression_19545 ;
            nt_gtl_5F_expression_ (var_expression_19545, inCompiler) ;
            inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 687)) ;
            outArgument_path.addAssign_operation (GALGAS_gtlVarItemSubCollection::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 688)), var_expression_19545  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 688))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 688)) ;
          }else{
            repeatFlag_1 = false ;
          }
        }
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
    } break ;
    case 2: {
      outArgument_path.addAssign_operation (GALGAS_gtlVarItemField::constructor_new (var_variableName_19124  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 693))  COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 693)) ;
    } break ;
    default:
      break ;
    }
    if (select_gtl_5F_debugger_5F_expression_5F_parser_20 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3A_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 696)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_variable_i32_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 672)) ;
    switch (select_gtl_5F_debugger_5F_expression_5F_parser_21 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 674)) ;
      nt_gtl_5F_expression_parse (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 676)) ;
      switch (select_gtl_5F_debugger_5F_expression_5F_parser_22 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 679)) ;
        nt_gtl_5F_expression_parse (inCompiler) ;
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 681)) ;
        bool repeatFlag_1 = true ;
        while (repeatFlag_1) {
          if (select_gtl_5F_debugger_5F_expression_5F_parser_23 (inCompiler) == 2) {
            inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 685)) ;
            nt_gtl_5F_expression_parse (inCompiler) ;
            inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 687)) ;
          }else{
            repeatFlag_1 = false ;
          }
        }
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    if (select_gtl_5F_debugger_5F_expression_5F_parser_20 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3A_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 696)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_expression_5F_parser::rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_variable_i32_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 672)) ;
    switch (select_gtl_5F_debugger_5F_expression_5F_parser_21 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 674)) ;
      nt_gtl_5F_expression_indexing (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 676)) ;
      switch (select_gtl_5F_debugger_5F_expression_5F_parser_22 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 679)) ;
        nt_gtl_5F_expression_indexing (inCompiler) ;
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 681)) ;
        bool repeatFlag_1 = true ;
        while (repeatFlag_1) {
          if (select_gtl_5F_debugger_5F_expression_5F_parser_23 (inCompiler) == 2) {
            inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 685)) ;
            nt_gtl_5F_expression_indexing (inCompiler) ;
            inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 687)) ;
          }else{
            repeatFlag_1 = false ;
          }
        }
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    if (select_gtl_5F_debugger_5F_expression_5F_parser_20 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3A_ COMMA_SOURCE_FILE ("gtl_debugger_expression_parser.galgas", 696)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//     L E X I Q U E                                                                             
//
//----------------------------------------------------------------------------------------------------------------------

#include "strings/unicode_character_cpp.h"
#include "galgas2/scanner_actions.h"
#include "galgas2/cLexiqueIntrospection.h"

//----------------------------------------------------------------------------------------------------------------------

cTokenFor_goil_5F_lexique::cTokenFor_goil_5F_lexique (void) :
mLexicalAttribute_a_5F_string (),
mLexicalAttribute_att_5F_token (),
mLexicalAttribute_floatNumber (),
mLexicalAttribute_integerNumber (),
mLexicalAttribute_number () {
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique_goil_5F_lexique::C_Lexique_goil_5F_lexique (C_Compiler * inCallerCompiler,
                                                      const C_String & inSourceFileName
                                                      COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceFileName COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique_goil_5F_lexique::C_Lexique_goil_5F_lexique (C_Compiler * inCallerCompiler,
                                                      const C_String & inSourceString,
                                                      const C_String & inStringForError
                                                      COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------
//                        Lexical error message list                                             
//----------------------------------------------------------------------------------------------------------------------

static const char * gLexicalMessage_goil_5F_lexique_decimalNumberTooLarge = "decimal number too large" ;

static const char * gLexicalMessage_goil_5F_lexique_illegalEscape = "Illegal escaped character" ;

static const char * gLexicalMessage_goil_5F_lexique_internalError = "internal error" ;

static const char * gLexicalMessage_goil_5F_lexique_unableToConvertToDouble = "Unable to convert the string to double" ;

static const char * gLexicalMessage_goil_5F_lexique_unterminatedLitteralString = "Unterminated literal string" ;

static const char * gLexicalMessage_goil_5F_lexique_unterminated_comment_error = "unterminated comment" ;

//----------------------------------------------------------------------------------------------------------------------
//                getMessageForTerminal                                                          
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_goil_5F_lexique::getMessageForTerminal (const int32_t inTerminalIndex) const {
  C_String result = "<unknown>" ;
  if ((inTerminalIndex >= 0) && (inTerminalIndex < 41)) {
    static const char * syntaxErrorMessageArray [41] = {kEndOfSourceLexicalErrorMessage,
        "a comment",
        "identifier",
        "literal string",
        "in search path",
        "literal unsigned 64 bits integer",
        "literal float",
        "literal unsigned 64 bits integer",
        "command",
        "OIL version",
        "OIL implementation definition",
        "OIL implementation definition",
        "type 'UINT32'",
        "type 'INT32'",
        "type 'UINT64'",
        "type 'INT64'",
        "type 'FLOAT'",
        "type 'ENUM'",
        "type 'STRING'",
        "type 'BOOLEAN'",
        "type 'IDENTIFIER'",
        "type 'STRUCT'",
        "specifier 'WITH_AUTO'",
        "specifier 'NO_DEFAULT'",
        "specifier 'AUTO'",
        "boolean 'FALSE'",
        "boolean 'TRUE'",
        "';' delimiter",
        "':' delimiter",
        "'=' delimiter",
        "'{' delimiter",
        "'}' delimiter",
        "'..' delimiter",
        "'[' delimiter",
        "']' delimiter",
        "',' delimiter",
        "'.' delimiter",
        "'+' delimiter",
        "'-' delimiter",
        "command 'include'",
        "command 'includeifexists'"
    } ;
    result = syntaxErrorMessageArray [inTerminalIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                      U N I C O D E    S T R I N G S                                           
//----------------------------------------------------------------------------------------------------------------------

//--- Unicode string for '$_2A__2F_$'
static const utf32 kUnicodeString_goil_5F_lexique__2A__2F_ [] = {
  TO_UNICODE ('*'),
  TO_UNICODE ('/'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2B_$'
static const utf32 kUnicodeString_goil_5F_lexique__2B_ [] = {
  TO_UNICODE ('+'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2C_$'
static const utf32 kUnicodeString_goil_5F_lexique__2C_ [] = {
  TO_UNICODE (','),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D_$'
static const utf32 kUnicodeString_goil_5F_lexique__2D_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2E_$'
static const utf32 kUnicodeString_goil_5F_lexique__2E_ [] = {
  TO_UNICODE ('.'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2E__2E_$'
static const utf32 kUnicodeString_goil_5F_lexique__2E__2E_ [] = {
  TO_UNICODE ('.'),
  TO_UNICODE ('.'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2F__2A_$'
static const utf32 kUnicodeString_goil_5F_lexique__2F__2A_ [] = {
  TO_UNICODE ('/'),
  TO_UNICODE ('*'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2F__2F_$'
static const utf32 kUnicodeString_goil_5F_lexique__2F__2F_ [] = {
  TO_UNICODE ('/'),
  TO_UNICODE ('/'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_30_X$'
static const utf32 kUnicodeString_goil_5F_lexique__30_X [] = {
  TO_UNICODE ('0'),
  TO_UNICODE ('X'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_30_x$'
static const utf32 kUnicodeString_goil_5F_lexique__30_x [] = {
  TO_UNICODE ('0'),
  TO_UNICODE ('x'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3A_$'
static const utf32 kUnicodeString_goil_5F_lexique__3A_ [] = {
  TO_UNICODE (':'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3B_$'
static const utf32 kUnicodeString_goil_5F_lexique__3B_ [] = {
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3D_$'
static const utf32 kUnicodeString_goil_5F_lexique__3D_ [] = {
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$AUTO$'
static const utf32 kUnicodeString_goil_5F_lexique_AUTO [] = {
  TO_UNICODE ('A'),
  TO_UNICODE ('U'),
  TO_UNICODE ('T'),
  TO_UNICODE ('O'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$BOOLEAN$'
static const utf32 kUnicodeString_goil_5F_lexique_BOOLEAN [] = {
  TO_UNICODE ('B'),
  TO_UNICODE ('O'),
  TO_UNICODE ('O'),
  TO_UNICODE ('L'),
  TO_UNICODE ('E'),
  TO_UNICODE ('A'),
  TO_UNICODE ('N'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$CPU$'
static const utf32 kUnicodeString_goil_5F_lexique_CPU [] = {
  TO_UNICODE ('C'),
  TO_UNICODE ('P'),
  TO_UNICODE ('U'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$ENUM$'
static const utf32 kUnicodeString_goil_5F_lexique_ENUM [] = {
  TO_UNICODE ('E'),
  TO_UNICODE ('N'),
  TO_UNICODE ('U'),
  TO_UNICODE ('M'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$FALSE$'
static const utf32 kUnicodeString_goil_5F_lexique_FALSE [] = {
  TO_UNICODE ('F'),
  TO_UNICODE ('A'),
  TO_UNICODE ('L'),
  TO_UNICODE ('S'),
  TO_UNICODE ('E'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$FLOAT$'
static const utf32 kUnicodeString_goil_5F_lexique_FLOAT [] = {
  TO_UNICODE ('F'),
  TO_UNICODE ('L'),
  TO_UNICODE ('O'),
  TO_UNICODE ('A'),
  TO_UNICODE ('T'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$IDENTIFIER$'
static const utf32 kUnicodeString_goil_5F_lexique_IDENTIFIER [] = {
  TO_UNICODE ('I'),
  TO_UNICODE ('D'),
  TO_UNICODE ('E'),
  TO_UNICODE ('N'),
  TO_UNICODE ('T'),
  TO_UNICODE ('I'),
  TO_UNICODE ('F'),
  TO_UNICODE ('I'),
  TO_UNICODE ('E'),
  TO_UNICODE ('R'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$IMPLEMENTATION$'
static const utf32 kUnicodeString_goil_5F_lexique_IMPLEMENTATION [] = {
  TO_UNICODE ('I'),
  TO_UNICODE ('M'),
  TO_UNICODE ('P'),
  TO_UNICODE ('L'),
  TO_UNICODE ('E'),
  TO_UNICODE ('M'),
  TO_UNICODE ('E'),
  TO_UNICODE ('N'),
  TO_UNICODE ('T'),
  TO_UNICODE ('A'),
  TO_UNICODE ('T'),
  TO_UNICODE ('I'),
  TO_UNICODE ('O'),
  TO_UNICODE ('N'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$INT_33__32_$'
static const utf32 kUnicodeString_goil_5F_lexique_INT_33__32_ [] = {
  TO_UNICODE ('I'),
  TO_UNICODE ('N'),
  TO_UNICODE ('T'),
  TO_UNICODE ('3'),
  TO_UNICODE ('2'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$INT_36__34_$'
static const utf32 kUnicodeString_goil_5F_lexique_INT_36__34_ [] = {
  TO_UNICODE ('I'),
  TO_UNICODE ('N'),
  TO_UNICODE ('T'),
  TO_UNICODE ('6'),
  TO_UNICODE ('4'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$NO_5F_DEFAULT$'
static const utf32 kUnicodeString_goil_5F_lexique_NO_5F_DEFAULT [] = {
  TO_UNICODE ('N'),
  TO_UNICODE ('O'),
  TO_UNICODE ('_'),
  TO_UNICODE ('D'),
  TO_UNICODE ('E'),
  TO_UNICODE ('F'),
  TO_UNICODE ('A'),
  TO_UNICODE ('U'),
  TO_UNICODE ('L'),
  TO_UNICODE ('T'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$OIL_5F_VERSION$'
static const utf32 kUnicodeString_goil_5F_lexique_OIL_5F_VERSION [] = {
  TO_UNICODE ('O'),
  TO_UNICODE ('I'),
  TO_UNICODE ('L'),
  TO_UNICODE ('_'),
  TO_UNICODE ('V'),
  TO_UNICODE ('E'),
  TO_UNICODE ('R'),
  TO_UNICODE ('S'),
  TO_UNICODE ('I'),
  TO_UNICODE ('O'),
  TO_UNICODE ('N'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$STRING$'
static const utf32 kUnicodeString_goil_5F_lexique_STRING [] = {
  TO_UNICODE ('S'),
  TO_UNICODE ('T'),
  TO_UNICODE ('R'),
  TO_UNICODE ('I'),
  TO_UNICODE ('N'),
  TO_UNICODE ('G'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$STRUCT$'
static const utf32 kUnicodeString_goil_5F_lexique_STRUCT [] = {
  TO_UNICODE ('S'),
  TO_UNICODE ('T'),
  TO_UNICODE ('R'),
  TO_UNICODE ('U'),
  TO_UNICODE ('C'),
  TO_UNICODE ('T'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$TRUE$'
static const utf32 kUnicodeString_goil_5F_lexique_TRUE [] = {
  TO_UNICODE ('T'),
  TO_UNICODE ('R'),
  TO_UNICODE ('U'),
  TO_UNICODE ('E'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$UINT_33__32_$'
static const utf32 kUnicodeString_goil_5F_lexique_UINT_33__32_ [] = {
  TO_UNICODE ('U'),
  TO_UNICODE ('I'),
  TO_UNICODE ('N'),
  TO_UNICODE ('T'),
  TO_UNICODE ('3'),
  TO_UNICODE ('2'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$UINT_36__34_$'
static const utf32 kUnicodeString_goil_5F_lexique_UINT_36__34_ [] = {
  TO_UNICODE ('U'),
  TO_UNICODE ('I'),
  TO_UNICODE ('N'),
  TO_UNICODE ('T'),
  TO_UNICODE ('6'),
  TO_UNICODE ('4'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$WITH_5F_AUTO$'
static const utf32 kUnicodeString_goil_5F_lexique_WITH_5F_AUTO [] = {
  TO_UNICODE ('W'),
  TO_UNICODE ('I'),
  TO_UNICODE ('T'),
  TO_UNICODE ('H'),
  TO_UNICODE ('_'),
  TO_UNICODE ('A'),
  TO_UNICODE ('U'),
  TO_UNICODE ('T'),
  TO_UNICODE ('O'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5B_$'
static const utf32 kUnicodeString_goil_5F_lexique__5B_ [] = {
  TO_UNICODE ('['),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5D_$'
static const utf32 kUnicodeString_goil_5F_lexique__5D_ [] = {
  TO_UNICODE (']'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$include$'
static const utf32 kUnicodeString_goil_5F_lexique_include [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('c'),
  TO_UNICODE ('l'),
  TO_UNICODE ('u'),
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$includeifexists$'
static const utf32 kUnicodeString_goil_5F_lexique_includeifexists [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('c'),
  TO_UNICODE ('l'),
  TO_UNICODE ('u'),
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE ('i'),
  TO_UNICODE ('f'),
  TO_UNICODE ('e'),
  TO_UNICODE ('x'),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7B_$'
static const utf32 kUnicodeString_goil_5F_lexique__7B_ [] = {
  TO_UNICODE ('{'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7D_$'
static const utf32 kUnicodeString_goil_5F_lexique__7D_ [] = {
  TO_UNICODE ('}'),
  TO_UNICODE (0)
} ;

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'OILDelimiters'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_goil_5F_lexique_OILDelimiters = 12 ;

static const C_unicode_lexique_table_entry ktable_for_goil_5F_lexique_OILDelimiters [ktable_size_goil_5F_lexique_OILDelimiters] = {
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique__2B_, 1, C_Lexique_goil_5F_lexique::kToken__2B_),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique__2C_, 1, C_Lexique_goil_5F_lexique::kToken__2C_),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique__2D_, 1, C_Lexique_goil_5F_lexique::kToken__2D_),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique__2E_, 1, C_Lexique_goil_5F_lexique::kToken__2E_),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique__3A_, 1, C_Lexique_goil_5F_lexique::kToken__3A_),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique__3B_, 1, C_Lexique_goil_5F_lexique::kToken__3B_),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique__3D_, 1, C_Lexique_goil_5F_lexique::kToken__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique__5B_, 1, C_Lexique_goil_5F_lexique::kToken__5B_),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique__5D_, 1, C_Lexique_goil_5F_lexique::kToken__5D_),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique__7B_, 1, C_Lexique_goil_5F_lexique::kToken__7B_),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique__7D_, 1, C_Lexique_goil_5F_lexique::kToken__7D_),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique__2E__2E_, 2, C_Lexique_goil_5F_lexique::kToken__2E__2E_)
} ;

int32_t C_Lexique_goil_5F_lexique::search_into_OILDelimiters (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_goil_5F_lexique_OILDelimiters, ktable_size_goil_5F_lexique_OILDelimiters) ;
}

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'boolean'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_goil_5F_lexique_boolean = 2 ;

static const C_unicode_lexique_table_entry ktable_for_goil_5F_lexique_boolean [ktable_size_goil_5F_lexique_boolean] = {
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_TRUE, 4, C_Lexique_goil_5F_lexique::kToken_TRUE),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_FALSE, 5, C_Lexique_goil_5F_lexique::kToken_FALSE)
} ;

int32_t C_Lexique_goil_5F_lexique::search_into_boolean (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_goil_5F_lexique_boolean, ktable_size_goil_5F_lexique_boolean) ;
}

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'commands'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_goil_5F_lexique_commands = 2 ;

static const C_unicode_lexique_table_entry ktable_for_goil_5F_lexique_commands [ktable_size_goil_5F_lexique_commands] = {
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_include, 7, C_Lexique_goil_5F_lexique::kToken_include),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_includeifexists, 15, C_Lexique_goil_5F_lexique::kToken_includeifexists)
} ;

int32_t C_Lexique_goil_5F_lexique::search_into_commands (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_goil_5F_lexique_commands, ktable_size_goil_5F_lexique_commands) ;
}

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'dataTypes'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_goil_5F_lexique_dataTypes = 10 ;

static const C_unicode_lexique_table_entry ktable_for_goil_5F_lexique_dataTypes [ktable_size_goil_5F_lexique_dataTypes] = {
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_ENUM, 4, C_Lexique_goil_5F_lexique::kToken_ENUM),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_FLOAT, 5, C_Lexique_goil_5F_lexique::kToken_FLOAT),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_INT_33__32_, 5, C_Lexique_goil_5F_lexique::kToken_INT_33__32_),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_INT_36__34_, 5, C_Lexique_goil_5F_lexique::kToken_INT_36__34_),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_STRING, 6, C_Lexique_goil_5F_lexique::kToken_STRING),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_STRUCT, 6, C_Lexique_goil_5F_lexique::kToken_STRUCT),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_UINT_33__32_, 6, C_Lexique_goil_5F_lexique::kToken_UINT_33__32_),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_UINT_36__34_, 6, C_Lexique_goil_5F_lexique::kToken_UINT_36__34_),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_BOOLEAN, 7, C_Lexique_goil_5F_lexique::kToken_BOOLEAN),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_IDENTIFIER, 10, C_Lexique_goil_5F_lexique::kToken_IDENTIFIER)
} ;

int32_t C_Lexique_goil_5F_lexique::search_into_dataTypes (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_goil_5F_lexique_dataTypes, ktable_size_goil_5F_lexique_dataTypes) ;
}

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'miscSpecifiers'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_goil_5F_lexique_miscSpecifiers = 3 ;

static const C_unicode_lexique_table_entry ktable_for_goil_5F_lexique_miscSpecifiers [ktable_size_goil_5F_lexique_miscSpecifiers] = {
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_AUTO, 4, C_Lexique_goil_5F_lexique::kToken_AUTO),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_WITH_5F_AUTO, 9, C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_NO_5F_DEFAULT, 10, C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT)
} ;

int32_t C_Lexique_goil_5F_lexique::search_into_miscSpecifiers (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_goil_5F_lexique_miscSpecifiers, ktable_size_goil_5F_lexique_miscSpecifiers) ;
}

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'oilDefinitions'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_goil_5F_lexique_oilDefinitions = 2 ;

static const C_unicode_lexique_table_entry ktable_for_goil_5F_lexique_oilDefinitions [ktable_size_goil_5F_lexique_oilDefinitions] = {
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_CPU, 3, C_Lexique_goil_5F_lexique::kToken_CPU),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_IMPLEMENTATION, 14, C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION)
} ;

int32_t C_Lexique_goil_5F_lexique::search_into_oilDefinitions (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_goil_5F_lexique_oilDefinitions, ktable_size_goil_5F_lexique_oilDefinitions) ;
}

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'oilVersion'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_goil_5F_lexique_oilVersion = 1 ;

static const C_unicode_lexique_table_entry ktable_for_goil_5F_lexique_oilVersion [ktable_size_goil_5F_lexique_oilVersion] = {
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_OIL_5F_VERSION, 11, C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION)
} ;

int32_t C_Lexique_goil_5F_lexique::search_into_oilVersion (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_goil_5F_lexique_oilVersion, ktable_size_goil_5F_lexique_oilVersion) ;
}


//----------------------------------------------------------------------------------------------------------------------
//                          getCurrentTokenString                                                
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_goil_5F_lexique::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_goil_5F_lexique * ptr = (const cTokenFor_goil_5F_lexique *) inTokenPtr ;
  C_String s ;
  if (ptr == nullptr) {
    s.appendCString("$$") ;
  }else{
    switch (ptr->mTokenCode) {
    case kToken_:
      s.appendCString("$$") ;
      break ;
    case kToken_comment:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("comment") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_idf:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("idf") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_att_5F_token) ;
      break ;
    case kToken_string:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("string") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_a_5F_string) ;
      break ;
    case kToken_g_5F_string:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("g_string") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_a_5F_string) ;
      break ;
    case kToken_uint_5F_number:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("uint_number") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendUnsigned (ptr->mLexicalAttribute_integerNumber) ;
      break ;
    case kToken_float_5F_number:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("float_number") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendDouble (ptr->mLexicalAttribute_floatNumber) ;
      break ;
    case kToken_set_5F_start_5F_uint_5F_number:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("set_start_uint_number") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendUnsigned (ptr->mLexicalAttribute_integerNumber) ;
      break ;
    case kToken_command:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("command") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_att_5F_token) ;
      break ;
    case kToken_OIL_5F_VERSION:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("OIL_VERSION") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_IMPLEMENTATION:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("IMPLEMENTATION") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_CPU:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("CPU") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_UINT_33__32_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("UINT32") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_INT_33__32_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("INT32") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_UINT_36__34_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("UINT64") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_INT_36__34_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("INT64") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_FLOAT:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("FLOAT") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_ENUM:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("ENUM") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_STRING:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("STRING") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_BOOLEAN:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("BOOLEAN") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_IDENTIFIER:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("IDENTIFIER") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_STRUCT:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("STRUCT") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_WITH_5F_AUTO:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("WITH_AUTO") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_NO_5F_DEFAULT:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("NO_DEFAULT") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_AUTO:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("AUTO") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_FALSE:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("FALSE") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_TRUE:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("TRUE") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (";") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3A_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (":") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("{") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("}") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2E__2E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("..") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("[") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("]") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (",") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (".") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("+") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("-") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_include:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("include") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_includeifexists:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("includeifexists") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    default:
      break ;
    }
  }
  return s ;
}

//----------------------------------------------------------------------------------------------------------------------
//                           Template Delimiters                                                 
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//                           Template Replacements                                               
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//            Terminal Symbols as end of script in template mark                                 
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//               INTERNAL PARSE LEXICAL TOKEN                                         
//----------------------------------------------------------------------------------------------------------------------

void C_Lexique_goil_5F_lexique::internalParseLexicalToken (cTokenFor_goil_5F_lexique & token) {
  bool loop = true ;
  token.mLexicalAttribute_a_5F_string.setLengthToZero () ;
  token.mLexicalAttribute_att_5F_token.setLengthToZero () ;
  token.mLexicalAttribute_floatNumber = 0.0 ;
  token.mLexicalAttribute_integerNumber = 0 ;
  token.mLexicalAttribute_number.setLengthToZero () ;
  mTokenStartLocation = mCurrentLocation ;
  try{
    if (testForInputUTF32String (kUnicodeString_goil_5F_lexique__2F__2F_, 2, true)) {
      do {
        if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE ('\t')) || testForInputUTF32Char (TO_UNICODE ('\v')) || testForInputUTF32Char (TO_UNICODE ('\f')) || testForInputUTF32CharRange (TO_UNICODE (14), TO_UNICODE (65533))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      enterDroppedTerminal (kToken_comment) ;
    }else if (testForInputUTF32String (kUnicodeString_goil_5F_lexique__2F__2A_, 2, true)) {
      do {
        if (notTestForInputUTF32String (kUnicodeString_goil_5F_lexique__2A__2F_, 2, gLexicalMessage_goil_5F_lexique_unterminated_comment_error COMMA_LINE_AND_SOURCE_FILE)) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      enterDroppedTerminal (kToken_comment) ;
    }else if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z'))) {
      do {
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_att_5F_token, previousChar ()) ;
        if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32Char (TO_UNICODE ('_')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (token.mTokenCode == -1) {
        token.mTokenCode = search_into_oilVersion (token.mLexicalAttribute_att_5F_token) ;
      }
      if (token.mTokenCode == -1) {
        token.mTokenCode = search_into_oilDefinitions (token.mLexicalAttribute_att_5F_token) ;
      }
      if (token.mTokenCode == -1) {
        token.mTokenCode = search_into_dataTypes (token.mLexicalAttribute_att_5F_token) ;
      }
      if (token.mTokenCode == -1) {
        token.mTokenCode = search_into_miscSpecifiers (token.mLexicalAttribute_att_5F_token) ;
      }
      if (token.mTokenCode == -1) {
        token.mTokenCode = search_into_boolean (token.mLexicalAttribute_att_5F_token) ;
      }
      if (token.mTokenCode == -1) {
        token.mTokenCode = kToken_idf ;
      }
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_goil_5F_lexique__2E__2E_, 2, true)) {
      token.mTokenCode = kToken__2E__2E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_goil_5F_lexique__7D_, 1, true)) {
      token.mTokenCode = kToken__7D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_goil_5F_lexique__7B_, 1, true)) {
      token.mTokenCode = kToken__7B_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_goil_5F_lexique__5D_, 1, true)) {
      token.mTokenCode = kToken__5D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_goil_5F_lexique__5B_, 1, true)) {
      token.mTokenCode = kToken__5B_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_goil_5F_lexique__3D_, 1, true)) {
      token.mTokenCode = kToken__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_goil_5F_lexique__3B_, 1, true)) {
      token.mTokenCode = kToken__3B_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_goil_5F_lexique__3A_, 1, true)) {
      token.mTokenCode = kToken__3A_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_goil_5F_lexique__2E_, 1, true)) {
      token.mTokenCode = kToken__2E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_goil_5F_lexique__2D_, 1, true)) {
      token.mTokenCode = kToken__2D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_goil_5F_lexique__2C_, 1, true)) {
      token.mTokenCode = kToken__2C_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_goil_5F_lexique__2B_, 1, true)) {
      token.mTokenCode = kToken__2B_ ;
      enterToken (token) ;
    }else if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (' '))) {
    }else if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
      do {
        if (testForInputUTF32Char (TO_UNICODE ('\\'))) {
          if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\"')) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('\\'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\\')) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('n'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\n')) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('r'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\r')) ;
          }else{
            lexicalError (gLexicalMessage_goil_5F_lexique_illegalEscape COMMA_LINE_AND_SOURCE_FILE) ;
          }
        }else if (testForInputUTF32CharRange (TO_UNICODE (' '), TO_UNICODE ('!')) || testForInputUTF32CharRange (TO_UNICODE ('#'), TO_UNICODE (65533))) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, previousChar ()) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
        token.mTokenCode = kToken_string ;
        enterToken (token) ;
      }else{
        lexicalError (gLexicalMessage_goil_5F_lexique_unterminatedLitteralString COMMA_LINE_AND_SOURCE_FILE) ;
      }
    }else if (testForInputUTF32Char (TO_UNICODE ('\''))) {
      do {
        if (testForInputUTF32CharRange (TO_UNICODE (' '), TO_UNICODE ('&')) || testForInputUTF32CharRange (TO_UNICODE ('('), TO_UNICODE (65533))) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, previousChar ()) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (testForInputUTF32Char (TO_UNICODE ('\''))) {
        token.mTokenCode = kToken_string ;
        enterToken (token) ;
      }else{
        lexicalError (gLexicalMessage_goil_5F_lexique_unterminatedLitteralString COMMA_LINE_AND_SOURCE_FILE) ;
      }
    }else if (testForInputUTF32Char (TO_UNICODE ('<'))) {
      do {
        if (testForInputUTF32CharRange (TO_UNICODE (' '), TO_UNICODE ('=')) || testForInputUTF32CharRange (TO_UNICODE ('\?'), TO_UNICODE (65533))) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, previousChar ()) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (testForInputUTF32Char (TO_UNICODE ('>'))) {
        token.mTokenCode = kToken_g_5F_string ;
        enterToken (token) ;
      }else{
        lexicalError (gLexicalMessage_goil_5F_lexique_unterminatedLitteralString COMMA_LINE_AND_SOURCE_FILE) ;
      }
    }else if (testForInputUTF32String (kUnicodeString_goil_5F_lexique__30_x, 2, true) || testForInputUTF32String (kUnicodeString_goil_5F_lexique__30_X, 2, true)) {
      do {
        if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
          ::scanner_routine_enterHexDigitIntoUInt64 (*this, previousChar (), token.mLexicalAttribute_integerNumber, gLexicalMessage_goil_5F_lexique_decimalNumberTooLarge, gLexicalMessage_goil_5F_lexique_internalError) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      token.mTokenCode = kToken_uint_5F_number ;
      enterToken (token) ;
    }else if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
      do {
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_number, previousChar ()) ;
        ::scanner_routine_enterDigitIntoUInt64 (*this, previousChar (), token.mLexicalAttribute_integerNumber, gLexicalMessage_goil_5F_lexique_decimalNumberTooLarge, gLexicalMessage_goil_5F_lexique_internalError) ;
        if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (testForInputUTF32Char (TO_UNICODE ('.'))) {
        if (testForInputUTF32Char (TO_UNICODE ('.'))) {
          token.mTokenCode = kToken_set_5F_start_5F_uint_5F_number ;
          enterToken (token) ;
        }else{
          do {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_number, previousChar ()) ;
            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
            }else{
              loop = false ;
            }
          }while (loop) ;
          loop = true ;
          ::scanner_routine_convertStringToDouble (*this, token.mLexicalAttribute_number, token.mLexicalAttribute_floatNumber, gLexicalMessage_goil_5F_lexique_unableToConvertToDouble) ;
          token.mTokenCode = kToken_float_5F_number ;
          enterToken (token) ;
        }
      }else{
        token.mTokenCode = kToken_uint_5F_number ;
        enterToken (token) ;
      }
    }else if (testForInputUTF32Char (TO_UNICODE ('#'))) {
      do {
        if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z'))) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_att_5F_token, previousChar ()) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (token.mTokenCode == -1) {
        token.mTokenCode = search_into_commands (token.mLexicalAttribute_att_5F_token) ;
      }
      if (token.mTokenCode == -1) {
        token.mTokenCode = kToken_command ;
      }
      enterToken (token) ;
    }else if (testForInputUTF32Char (TO_UNICODE ('\0'))) { // End of source text ? 
      token.mTokenCode = kToken_ ; // Empty string code
    }else{ // Unknown input character
      unknownCharacterLexicalError (LINE_AND_SOURCE_FILE) ;
      token.mTokenCode = -1 ; // No token
      advance () ; // ... go throught unknown character
    }
  }catch (const C_lexicalErrorException &) {
    token.mTokenCode = -1 ; // No token
    advance () ; // ... go throught unknown character
  }
}

//----------------------------------------------------------------------------------------------------------------------
//               P A R S E    L E X I C A L    T O K E N                                         
//----------------------------------------------------------------------------------------------------------------------

bool C_Lexique_goil_5F_lexique::parseLexicalToken (void) {
  cTokenFor_goil_5F_lexique token ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
    internalParseLexicalToken (token) ;
  }
  if (UNICODE_VALUE (mCurrentChar) == '\0') {
    token.mTokenCode = 0 ;
    enterToken (token) ;
  }
  return token.mTokenCode > 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
//                         E N T E R    T O K E N                                                
//----------------------------------------------------------------------------------------------------------------------

void C_Lexique_goil_5F_lexique::enterToken (cTokenFor_goil_5F_lexique & ioToken) {
  cTokenFor_goil_5F_lexique * ptr = nullptr ;
  macroMyNew (ptr, cTokenFor_goil_5F_lexique ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
  // ptr->mIsOptional = ioToken.mIsOptional ;
  ptr->mStartLocation = mTokenStartLocation ;
  ptr->mEndLocation = mTokenEndLocation ;
  ptr->mTemplateStringBeforeToken = ioToken.mTemplateStringBeforeToken ;
  ioToken.mTemplateStringBeforeToken = "" ;
  ptr->mLexicalAttribute_a_5F_string = ioToken.mLexicalAttribute_a_5F_string ;
  ptr->mLexicalAttribute_att_5F_token = ioToken.mLexicalAttribute_att_5F_token ;
  ptr->mLexicalAttribute_floatNumber = ioToken.mLexicalAttribute_floatNumber ;
  ptr->mLexicalAttribute_integerNumber = ioToken.mLexicalAttribute_integerNumber ;
  ptr->mLexicalAttribute_number = ioToken.mLexicalAttribute_number ;
  enterTokenFromPointer (ptr) ;
}

//----------------------------------------------------------------------------------------------------------------------
//               A T T R I B U T E   A C C E S S                                                 
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_goil_5F_lexique::attributeValue_a_5F_string (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_a_5F_string ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_goil_5F_lexique::attributeValue_att_5F_token (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_att_5F_token ;
}

//----------------------------------------------------------------------------------------------------------------------

double C_Lexique_goil_5F_lexique::attributeValue_floatNumber (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_floatNumber ;
}

//----------------------------------------------------------------------------------------------------------------------

uint64_t C_Lexique_goil_5F_lexique::attributeValue_integerNumber (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_integerNumber ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_goil_5F_lexique::attributeValue_number (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_number ;
}

//----------------------------------------------------------------------------------------------------------------------
//         A S S I G N    F R O M    A T T R I B U T E                                           
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_goil_5F_lexique::synthetizedAttribute_a_5F_string (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_goil_5F_lexique) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_a_5F_string) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_goil_5F_lexique::synthetizedAttribute_att_5F_token (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_goil_5F_lexique) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_att_5F_token) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ldouble C_Lexique_goil_5F_lexique::synthetizedAttribute_floatNumber (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_goil_5F_lexique) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_double value (ptr->mLexicalAttribute_floatNumber) ;
  GALGAS_ldouble result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint_36__34_ C_Lexique_goil_5F_lexique::synthetizedAttribute_integerNumber (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_goil_5F_lexique) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_uint_36__34_ value (ptr->mLexicalAttribute_integerNumber) ;
  GALGAS_luint_36__34_ result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_goil_5F_lexique::synthetizedAttribute_number (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_goil_5F_lexique) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_number) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                         I N T R O S P E C T I O N                                             
//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist C_Lexique_goil_5F_lexique::symbols (LOCATION_ARGS) {
  GALGAS_stringlist result = GALGAS_stringlist::constructor_emptyList (THERE) ;
  result.addAssign_operation (GALGAS_string ("comment") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("idf") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("string") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("g_string") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("uint_number") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("float_number") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("set_start_uint_number") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("command") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("OIL_VERSION") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("IMPLEMENTATION") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("CPU") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("UINT32") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("INT32") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("UINT64") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("INT64") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("FLOAT") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("ENUM") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("STRING") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("BOOLEAN") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("IDENTIFIER") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("STRUCT") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("WITH_AUTO") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("NO_DEFAULT") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("AUTO") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("FALSE") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("TRUE") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (";") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (":") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("{") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("}") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("..") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("[") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("]") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (",") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (".") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("+") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("-") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("include") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("includeifexists") COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

static void getKeywordLists_goil_5F_lexique (TC_UniqueArray <C_String> & ioList) {
  ioList.appendObject ("goil_lexique:OILDelimiters") ;
  ioList.appendObject ("goil_lexique:boolean") ;
  ioList.appendObject ("goil_lexique:commands") ;
  ioList.appendObject ("goil_lexique:dataTypes") ;
  ioList.appendObject ("goil_lexique:miscSpecifiers") ;
  ioList.appendObject ("goil_lexique:oilDefinitions") ;
  ioList.appendObject ("goil_lexique:oilVersion") ;
}

//----------------------------------------------------------------------------------------------------------------------

static void getKeywordsForIdentifier_goil_5F_lexique (const C_String & inIdentifier,
                                                      bool & ioFound,
                                                      TC_UniqueArray <C_String> & ioList) {
  if (inIdentifier == "goil_lexique:OILDelimiters") {
    ioFound = true ;
    ioList.appendObject ("+") ;
    ioList.appendObject (",") ;
    ioList.appendObject ("-") ;
    ioList.appendObject (".") ;
    ioList.appendObject (":") ;
    ioList.appendObject (";") ;
    ioList.appendObject ("=") ;
    ioList.appendObject ("[") ;
    ioList.appendObject ("]") ;
    ioList.appendObject ("{") ;
    ioList.appendObject ("}") ;
    ioList.appendObject ("..") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "goil_lexique:boolean") {
    ioFound = true ;
    ioList.appendObject ("TRUE") ;
    ioList.appendObject ("FALSE") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "goil_lexique:commands") {
    ioFound = true ;
    ioList.appendObject ("include") ;
    ioList.appendObject ("includeifexists") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "goil_lexique:dataTypes") {
    ioFound = true ;
    ioList.appendObject ("ENUM") ;
    ioList.appendObject ("FLOAT") ;
    ioList.appendObject ("INT32") ;
    ioList.appendObject ("INT64") ;
    ioList.appendObject ("STRING") ;
    ioList.appendObject ("STRUCT") ;
    ioList.appendObject ("UINT32") ;
    ioList.appendObject ("UINT64") ;
    ioList.appendObject ("BOOLEAN") ;
    ioList.appendObject ("IDENTIFIER") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "goil_lexique:miscSpecifiers") {
    ioFound = true ;
    ioList.appendObject ("AUTO") ;
    ioList.appendObject ("WITH_AUTO") ;
    ioList.appendObject ("NO_DEFAULT") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "goil_lexique:oilDefinitions") {
    ioFound = true ;
    ioList.appendObject ("CPU") ;
    ioList.appendObject ("IMPLEMENTATION") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "goil_lexique:oilVersion") {
    ioFound = true ;
    ioList.appendObject ("OIL_VERSION") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static cLexiqueIntrospection lexiqueIntrospection_goil_5F_lexique
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_goil_5F_lexique, getKeywordsForIdentifier_goil_5F_lexique) ;

//----------------------------------------------------------------------------------------------------------------------
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                           
//----------------------------------------------------------------------------------------------------------------------

uint32_t C_Lexique_goil_5F_lexique::styleIndexForTerminal (const int32_t inTerminalIndex) const {
  static const uint32_t kTerminalSymbolStyles [41] = {0,
    9 /* goil_lexique_1_comment */,
    2 /* goil_lexique_1_idf */,
    4 /* goil_lexique_1_string */,
    5 /* goil_lexique_1_g_5F_string */,
    6 /* goil_lexique_1_uint_5F_number */,
    7 /* goil_lexique_1_float_5F_number */,
    6 /* goil_lexique_1_set_5F_start_5F_uint_5F_number */,
    8 /* goil_lexique_1_command */,
    1 /* goil_lexique_1_OIL_5F_VERSION */,
    1 /* goil_lexique_1_IMPLEMENTATION */,
    1 /* goil_lexique_1_CPU */,
    1 /* goil_lexique_1_UINT_33__32_ */,
    1 /* goil_lexique_1_INT_33__32_ */,
    1 /* goil_lexique_1_UINT_36__34_ */,
    1 /* goil_lexique_1_INT_36__34_ */,
    1 /* goil_lexique_1_FLOAT */,
    1 /* goil_lexique_1_ENUM */,
    1 /* goil_lexique_1_STRING */,
    1 /* goil_lexique_1_BOOLEAN */,
    1 /* goil_lexique_1_IDENTIFIER */,
    1 /* goil_lexique_1_STRUCT */,
    1 /* goil_lexique_1_WITH_5F_AUTO */,
    1 /* goil_lexique_1_NO_5F_DEFAULT */,
    1 /* goil_lexique_1_AUTO */,
    1 /* goil_lexique_1_FALSE */,
    1 /* goil_lexique_1_TRUE */,
    3 /* goil_lexique_1__3B_ */,
    3 /* goil_lexique_1__3A_ */,
    3 /* goil_lexique_1__3D_ */,
    3 /* goil_lexique_1__7B_ */,
    3 /* goil_lexique_1__7D_ */,
    3 /* goil_lexique_1__2E__2E_ */,
    3 /* goil_lexique_1__5B_ */,
    3 /* goil_lexique_1__5D_ */,
    3 /* goil_lexique_1__2C_ */,
    3 /* goil_lexique_1__2E_ */,
    3 /* goil_lexique_1__2B_ */,
    3 /* goil_lexique_1__2D_ */,
    1 /* goil_lexique_1_include */,
    1 /* goil_lexique_1_includeifexists */
  } ;
  return (inTerminalIndex >= 0) ? kTerminalSymbolStyles [inTerminalIndex] : 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                      
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_goil_5F_lexique::styleNameForIndex (const uint32_t inStyleIndex) const {
  C_String result ;
  if (inStyleIndex < 10) {
    static const char * kStyleArray [10] = {
      "",
      "keywordsStyle",
      "identifierStyle",
      "delimitersStyle",
      "stringStyle",
      "pathStyle",
      "integerStyle",
      "floatStyle",
      "commandStyle",
      "commentStyle"
    } ;
    result = kStyleArray [inStyleIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_dataType::GALGAS_dataType (void) :
mEnum (kNotBuilt) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_dataType GALGAS_dataType::constructor_void (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_void ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_dataType GALGAS_dataType::constructor_uint_33__32_Number (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_uint_33__32_Number ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_dataType GALGAS_dataType::constructor_sint_33__32_Number (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_sint_33__32_Number ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_dataType GALGAS_dataType::constructor_uint_36__34_Number (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_uint_36__34_Number ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_dataType GALGAS_dataType::constructor_sint_36__34_Number (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_sint_36__34_Number ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_dataType GALGAS_dataType::constructor_floatNumber (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_floatNumber ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_dataType GALGAS_dataType::constructor_string (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_string ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_dataType GALGAS_dataType::constructor_enumeration (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_enumeration ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_dataType GALGAS_dataType::constructor_boolean (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_boolean ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_dataType GALGAS_dataType::constructor_identifier (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_identifier ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_dataType GALGAS_dataType::constructor_objectType (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_objectType ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_dataType GALGAS_dataType::constructor_structType (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_structType ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_dataType::optional_void () const {
  const bool ok = mEnum == kEnum_void ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_dataType::optional_uint_33__32_Number () const {
  const bool ok = mEnum == kEnum_uint_33__32_Number ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_dataType::optional_sint_33__32_Number () const {
  const bool ok = mEnum == kEnum_sint_33__32_Number ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_dataType::optional_uint_36__34_Number () const {
  const bool ok = mEnum == kEnum_uint_36__34_Number ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_dataType::optional_sint_36__34_Number () const {
  const bool ok = mEnum == kEnum_sint_36__34_Number ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_dataType::optional_floatNumber () const {
  const bool ok = mEnum == kEnum_floatNumber ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_dataType::optional_string () const {
  const bool ok = mEnum == kEnum_string ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_dataType::optional_enumeration () const {
  const bool ok = mEnum == kEnum_enumeration ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_dataType::optional_boolean () const {
  const bool ok = mEnum == kEnum_boolean ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_dataType::optional_identifier () const {
  const bool ok = mEnum == kEnum_identifier ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_dataType::optional_objectType () const {
  const bool ok = mEnum == kEnum_objectType ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_dataType::optional_structType () const {
  const bool ok = mEnum == kEnum_structType ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

static const char * gEnumNameArrayFor_dataType [13] = {
  "(not built)",
  "void",
  "uint32Number",
  "sint32Number",
  "uint64Number",
  "sint64Number",
  "floatNumber",
  "string",
  "enumeration",
  "boolean",
  "identifier",
  "objectType",
  "structType"
} ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_dataType::getter_isVoid (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_void == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_dataType::getter_isUint_33__32_Number (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_uint_33__32_Number == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_dataType::getter_isSint_33__32_Number (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_sint_33__32_Number == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_dataType::getter_isUint_36__34_Number (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_uint_36__34_Number == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_dataType::getter_isSint_36__34_Number (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_sint_36__34_Number == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_dataType::getter_isFloatNumber (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_floatNumber == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_dataType::getter_isString (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_string == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_dataType::getter_isEnumeration (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_enumeration == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_dataType::getter_isBoolean (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_boolean == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_dataType::getter_isIdentifier (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_identifier == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_dataType::getter_isObjectType (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_objectType == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_dataType::getter_isStructType (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_structType == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_dataType::description (C_String & ioString,
                                   const int32_t /* inIndentation */) const {
  ioString << "<enum @dataType: " << gEnumNameArrayFor_dataType [mEnum] ;
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_dataType::objectCompare (const GALGAS_dataType & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mEnum < inOperand.mEnum) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mEnum > inOperand.mEnum) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @dataType generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_dataType ("dataType",
                                 nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_dataType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_dataType ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_dataType::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_dataType (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_dataType GALGAS_dataType::extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_dataType result ;
  const GALGAS_dataType * p = (const GALGAS_dataType *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_dataType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("dataType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@dataType oilType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_oilType (const GALGAS_dataType & inObject,
                                       C_Compiler *
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_dataType temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_dataType::kNotBuilt:
    break ;
  case GALGAS_dataType::kEnum_void:
    {
      result_result = GALGAS_string ("VOID") ;
    }
    break ;
  case GALGAS_dataType::kEnum_uint_33__32_Number:
    {
      result_result = GALGAS_string ("UINT32") ;
    }
    break ;
  case GALGAS_dataType::kEnum_sint_33__32_Number:
    {
      result_result = GALGAS_string ("INT32") ;
    }
    break ;
  case GALGAS_dataType::kEnum_uint_36__34_Number:
    {
      result_result = GALGAS_string ("UINT64") ;
    }
    break ;
  case GALGAS_dataType::kEnum_sint_36__34_Number:
    {
      result_result = GALGAS_string ("INT64") ;
    }
    break ;
  case GALGAS_dataType::kEnum_floatNumber:
    {
      result_result = GALGAS_string ("FLOAT") ;
    }
    break ;
  case GALGAS_dataType::kEnum_string:
    {
      result_result = GALGAS_string ("STRING") ;
    }
    break ;
  case GALGAS_dataType::kEnum_enumeration:
    {
      result_result = GALGAS_string ("ENUM") ;
    }
    break ;
  case GALGAS_dataType::kEnum_boolean:
    {
      result_result = GALGAS_string ("BOOLEAN") ;
    }
    break ;
  case GALGAS_dataType::kEnum_identifier:
    {
      result_result = GALGAS_string ("IDENTIFIER") ;
    }
    break ;
  case GALGAS_dataType::kEnum_objectType:
    {
      result_result = GALGAS_string ("OBJECT_TYPE") ;
    }
    break ;
  case GALGAS_dataType::kEnum_structType:
    {
      result_result = GALGAS_string ("STRUCT") ;
    }
    break ;
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@dataType arxmlType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_arxmlType (const GALGAS_dataType & inObject,
                                         C_Compiler *
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_dataType temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_dataType::kNotBuilt:
    break ;
  case GALGAS_dataType::kEnum_void:
    {
      result_result = GALGAS_string ("TPL-VOID-DEF") ;
    }
    break ;
  case GALGAS_dataType::kEnum_uint_33__32_Number:
    {
      result_result = GALGAS_string ("ECUC-INTEGER-PARAM-DEF") ;
    }
    break ;
  case GALGAS_dataType::kEnum_sint_33__32_Number:
    {
      result_result = GALGAS_string ("ECUC-INTEGER-PARAM-DEF") ;
    }
    break ;
  case GALGAS_dataType::kEnum_uint_36__34_Number:
    {
      result_result = GALGAS_string ("ECUC-INTEGER-PARAM-DEF") ;
    }
    break ;
  case GALGAS_dataType::kEnum_sint_36__34_Number:
    {
      result_result = GALGAS_string ("ECUC-INTEGER-PARAM-DEF") ;
    }
    break ;
  case GALGAS_dataType::kEnum_floatNumber:
    {
      result_result = GALGAS_string ("ECUC-FLOAT-PARAM-DEF") ;
    }
    break ;
  case GALGAS_dataType::kEnum_string:
    {
      result_result = GALGAS_string ("ECUC-STRING-PARAM-DEF") ;
    }
    break ;
  case GALGAS_dataType::kEnum_enumeration:
    {
      result_result = GALGAS_string ("ECUC-ENUMERATION-PARAM-DEF") ;
    }
    break ;
  case GALGAS_dataType::kEnum_boolean:
    {
      result_result = GALGAS_string ("ECUC-BOOLEAN-PARAM-DEF") ;
    }
    break ;
  case GALGAS_dataType::kEnum_identifier:
    {
      result_result = GALGAS_string ("TPL-IDENTIFIER-DEF") ;
    }
    break ;
  case GALGAS_dataType::kEnum_objectType:
    {
      result_result = GALGAS_string ("ECUC-REFERENCE-DEF") ;
    }
    break ;
  case GALGAS_dataType::kEnum_structType:
    {
      result_result = GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF") ;
    }
    break ;
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@uint_33__32_List' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_uint_33__32_List : public cCollectionElement {
  public: GALGAS_uint_33__32_List_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_uint_33__32_List (const GALGAS_location & in_location,
                                               const GALGAS_uint & in_value
                                               COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_uint_33__32_List (const GALGAS_uint_33__32_List_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;

//--- Description
  public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_uint_33__32_List::cCollectionElement_uint_33__32_List (const GALGAS_location & in_location,
                                                                          const GALGAS_uint & in_value
                                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_location, in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_uint_33__32_List::cCollectionElement_uint_33__32_List (const GALGAS_uint_33__32_List_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_location, inElement.mProperty_value) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_uint_33__32_List::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_uint_33__32_List::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_uint_33__32_List (mObject.mProperty_location, mObject.mProperty_value COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_uint_33__32_List::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "location" ":" ;
  mObject.mProperty_location.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mProperty_value.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_uint_33__32_List::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_uint_33__32_List * operand = (cCollectionElement_uint_33__32_List *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_uint_33__32_List) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List::GALGAS_uint_33__32_List (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List::GALGAS_uint_33__32_List (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List GALGAS_uint_33__32_List::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint_33__32_List  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List GALGAS_uint_33__32_List::constructor_listWithValue (const GALGAS_location & inOperand0,
                                                                            const GALGAS_uint & inOperand1
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_List result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_uint_33__32_List (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_uint_33__32_List::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_List::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                         const GALGAS_location & in_location,
                                                         const GALGAS_uint & in_value
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_uint_33__32_List * p = nullptr ;
  macroMyNew (p, cCollectionElement_uint_33__32_List (in_location,
                                                      in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_List::addAssign_operation (const GALGAS_location & inOperand0,
                                                   const GALGAS_uint & inOperand1
                                                   COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_uint_33__32_List (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_List::setter_append (const GALGAS_location inOperand0,
                                             const GALGAS_uint inOperand1,
                                             C_Compiler * /* inCompiler */
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_uint_33__32_List (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_List::setter_insertAtIndex (const GALGAS_location inOperand0,
                                                    const GALGAS_uint inOperand1,
                                                    const GALGAS_uint inInsertionIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_uint_33__32_List (inOperand0, inOperand1 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_List::setter_removeAtIndex (GALGAS_location & outOperand0,
                                                    GALGAS_uint & outOperand1,
                                                    const GALGAS_uint inRemoveIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_uint_33__32_List * p = (cCollectionElement_uint_33__32_List *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        outOperand1.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
        outOperand0 = p->mObject.mProperty_location ;
        outOperand1 = p->mObject.mProperty_value ;
      }
    }else{
      outOperand0.drop () ;
      outOperand1.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_List::setter_popFirst (GALGAS_location & outOperand0,
                                               GALGAS_uint & outOperand1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_33__32_List * p = (cCollectionElement_uint_33__32_List *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_List::setter_popLast (GALGAS_location & outOperand0,
                                              GALGAS_uint & outOperand1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_33__32_List * p = (cCollectionElement_uint_33__32_List *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_List::method_first (GALGAS_location & outOperand0,
                                            GALGAS_uint & outOperand1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_33__32_List * p = (cCollectionElement_uint_33__32_List *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_List::method_last (GALGAS_location & outOperand0,
                                           GALGAS_uint & outOperand1,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_33__32_List * p = (cCollectionElement_uint_33__32_List *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List GALGAS_uint_33__32_List::add_operation (const GALGAS_uint_33__32_List & inOperand,
                                                                C_Compiler * /* inCompiler */
                                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_33__32_List result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List GALGAS_uint_33__32_List::getter_subListWithRange (const GALGAS_range & inRange,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_uint_33__32_List result = GALGAS_uint_33__32_List::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List GALGAS_uint_33__32_List::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_uint_33__32_List result = GALGAS_uint_33__32_List::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List GALGAS_uint_33__32_List::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_uint_33__32_List result = GALGAS_uint_33__32_List::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_List::plusAssign_operation (const GALGAS_uint_33__32_List inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_List::setter_setLocationAtIndex (GALGAS_location inOperand,
                                                         GALGAS_uint inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_uint_33__32_List * p = (cCollectionElement_uint_33__32_List *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_location = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_uint_33__32_List::getter_locationAtIndex (const GALGAS_uint & inIndex,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_33__32_List * p = (cCollectionElement_uint_33__32_List *) attributes.ptr () ;
  GALGAS_location result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
    result = p->mObject.mProperty_location ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_List::setter_setValueAtIndex (GALGAS_uint inOperand,
                                                      GALGAS_uint inIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  cCollectionElement_uint_33__32_List * p = (cCollectionElement_uint_33__32_List *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_value = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_uint_33__32_List::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_33__32_List * p = (cCollectionElement_uint_33__32_List *) attributes.ptr () ;
  GALGAS_uint result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
    result = p->mObject.mProperty_value ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_uint_33__32_List::cEnumerator_uint_33__32_List (const GALGAS_uint_33__32_List & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List_2D_element cEnumerator_uint_33__32_List::current (LOCATION_ARGS) const {
  const cCollectionElement_uint_33__32_List * p = (const cCollectionElement_uint_33__32_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cEnumerator_uint_33__32_List::current_location (LOCATION_ARGS) const {
  const cCollectionElement_uint_33__32_List * p = (const cCollectionElement_uint_33__32_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
  return p->mObject.mProperty_location ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cEnumerator_uint_33__32_List::current_value (LOCATION_ARGS) const {
  const cCollectionElement_uint_33__32_List * p = (const cCollectionElement_uint_33__32_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
  return p->mObject.mProperty_value ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @uint32List generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_33__32_List ("uint32List",
                                         nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_33__32_List::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_List ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_33__32_List::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_33__32_List (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List GALGAS_uint_33__32_List::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_List result ;
  const GALGAS_uint_33__32_List * p = (const GALGAS_uint_33__32_List *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_uint_33__32_List *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint32List", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@uint_36__34_List' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_uint_36__34_List : public cCollectionElement {
  public: GALGAS_uint_36__34_List_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_uint_36__34_List (const GALGAS_location & in_location,
                                               const GALGAS_uint_36__34_ & in_value
                                               COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_uint_36__34_List (const GALGAS_uint_36__34_List_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;

//--- Description
  public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_uint_36__34_List::cCollectionElement_uint_36__34_List (const GALGAS_location & in_location,
                                                                          const GALGAS_uint_36__34_ & in_value
                                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_location, in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_uint_36__34_List::cCollectionElement_uint_36__34_List (const GALGAS_uint_36__34_List_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_location, inElement.mProperty_value) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_uint_36__34_List::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_uint_36__34_List::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_uint_36__34_List (mObject.mProperty_location, mObject.mProperty_value COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_uint_36__34_List::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "location" ":" ;
  mObject.mProperty_location.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mProperty_value.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_uint_36__34_List::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_uint_36__34_List * operand = (cCollectionElement_uint_36__34_List *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_uint_36__34_List) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List::GALGAS_uint_36__34_List (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List::GALGAS_uint_36__34_List (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List GALGAS_uint_36__34_List::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint_36__34_List  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List GALGAS_uint_36__34_List::constructor_listWithValue (const GALGAS_location & inOperand0,
                                                                            const GALGAS_uint_36__34_ & inOperand1
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_List result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_uint_36__34_List (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_uint_36__34_List::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_List::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                         const GALGAS_location & in_location,
                                                         const GALGAS_uint_36__34_ & in_value
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_uint_36__34_List * p = nullptr ;
  macroMyNew (p, cCollectionElement_uint_36__34_List (in_location,
                                                      in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_List::addAssign_operation (const GALGAS_location & inOperand0,
                                                   const GALGAS_uint_36__34_ & inOperand1
                                                   COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_uint_36__34_List (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_List::setter_append (const GALGAS_location inOperand0,
                                             const GALGAS_uint_36__34_ inOperand1,
                                             C_Compiler * /* inCompiler */
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_uint_36__34_List (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_List::setter_insertAtIndex (const GALGAS_location inOperand0,
                                                    const GALGAS_uint_36__34_ inOperand1,
                                                    const GALGAS_uint inInsertionIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_uint_36__34_List (inOperand0, inOperand1 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_List::setter_removeAtIndex (GALGAS_location & outOperand0,
                                                    GALGAS_uint_36__34_ & outOperand1,
                                                    const GALGAS_uint inRemoveIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_uint_36__34_List * p = (cCollectionElement_uint_36__34_List *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        outOperand1.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
        outOperand0 = p->mObject.mProperty_location ;
        outOperand1 = p->mObject.mProperty_value ;
      }
    }else{
      outOperand0.drop () ;
      outOperand1.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_List::setter_popFirst (GALGAS_location & outOperand0,
                                               GALGAS_uint_36__34_ & outOperand1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_List * p = (cCollectionElement_uint_36__34_List *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_List::setter_popLast (GALGAS_location & outOperand0,
                                              GALGAS_uint_36__34_ & outOperand1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_List * p = (cCollectionElement_uint_36__34_List *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_List::method_first (GALGAS_location & outOperand0,
                                            GALGAS_uint_36__34_ & outOperand1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_List * p = (cCollectionElement_uint_36__34_List *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_List::method_last (GALGAS_location & outOperand0,
                                           GALGAS_uint_36__34_ & outOperand1,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_List * p = (cCollectionElement_uint_36__34_List *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List GALGAS_uint_36__34_List::add_operation (const GALGAS_uint_36__34_List & inOperand,
                                                                C_Compiler * /* inCompiler */
                                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_List result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List GALGAS_uint_36__34_List::getter_subListWithRange (const GALGAS_range & inRange,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_List result = GALGAS_uint_36__34_List::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List GALGAS_uint_36__34_List::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_List result = GALGAS_uint_36__34_List::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List GALGAS_uint_36__34_List::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_List result = GALGAS_uint_36__34_List::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_List::plusAssign_operation (const GALGAS_uint_36__34_List inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_List::setter_setLocationAtIndex (GALGAS_location inOperand,
                                                         GALGAS_uint inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_uint_36__34_List * p = (cCollectionElement_uint_36__34_List *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_location = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_uint_36__34_List::getter_locationAtIndex (const GALGAS_uint & inIndex,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_List * p = (cCollectionElement_uint_36__34_List *) attributes.ptr () ;
  GALGAS_location result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
    result = p->mObject.mProperty_location ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_List::setter_setValueAtIndex (GALGAS_uint_36__34_ inOperand,
                                                      GALGAS_uint inIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  cCollectionElement_uint_36__34_List * p = (cCollectionElement_uint_36__34_List *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_value = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ GALGAS_uint_36__34_List::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_List * p = (cCollectionElement_uint_36__34_List *) attributes.ptr () ;
  GALGAS_uint_36__34_ result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
    result = p->mObject.mProperty_value ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_uint_36__34_List::cEnumerator_uint_36__34_List (const GALGAS_uint_36__34_List & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List_2D_element cEnumerator_uint_36__34_List::current (LOCATION_ARGS) const {
  const cCollectionElement_uint_36__34_List * p = (const cCollectionElement_uint_36__34_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cEnumerator_uint_36__34_List::current_location (LOCATION_ARGS) const {
  const cCollectionElement_uint_36__34_List * p = (const cCollectionElement_uint_36__34_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
  return p->mObject.mProperty_location ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ cEnumerator_uint_36__34_List::current_value (LOCATION_ARGS) const {
  const cCollectionElement_uint_36__34_List * p = (const cCollectionElement_uint_36__34_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
  return p->mObject.mProperty_value ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @uint64List generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34_List ("uint64List",
                                         nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_36__34_List::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_List ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_36__34_List::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34_List (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List GALGAS_uint_36__34_List::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_List result ;
  const GALGAS_uint_36__34_List * p = (const GALGAS_uint_36__34_List *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_uint_36__34_List *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64List", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@sint_33__32_List' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_sint_33__32_List : public cCollectionElement {
  public: GALGAS_sint_33__32_List_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_sint_33__32_List (const GALGAS_location & in_location,
                                               const GALGAS_sint & in_value
                                               COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_sint_33__32_List (const GALGAS_sint_33__32_List_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;

//--- Description
  public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_sint_33__32_List::cCollectionElement_sint_33__32_List (const GALGAS_location & in_location,
                                                                          const GALGAS_sint & in_value
                                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_location, in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_sint_33__32_List::cCollectionElement_sint_33__32_List (const GALGAS_sint_33__32_List_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_location, inElement.mProperty_value) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_sint_33__32_List::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_sint_33__32_List::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_sint_33__32_List (mObject.mProperty_location, mObject.mProperty_value COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_sint_33__32_List::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "location" ":" ;
  mObject.mProperty_location.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mProperty_value.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_sint_33__32_List::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_sint_33__32_List * operand = (cCollectionElement_sint_33__32_List *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_sint_33__32_List) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List::GALGAS_sint_33__32_List (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List::GALGAS_sint_33__32_List (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List GALGAS_sint_33__32_List::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint_33__32_List  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List GALGAS_sint_33__32_List::constructor_listWithValue (const GALGAS_location & inOperand0,
                                                                            const GALGAS_sint & inOperand1
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_List result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_sint_33__32_List (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_sint_33__32_List::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_List::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                         const GALGAS_location & in_location,
                                                         const GALGAS_sint & in_value
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_sint_33__32_List * p = nullptr ;
  macroMyNew (p, cCollectionElement_sint_33__32_List (in_location,
                                                      in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_List::addAssign_operation (const GALGAS_location & inOperand0,
                                                   const GALGAS_sint & inOperand1
                                                   COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_sint_33__32_List (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_List::setter_append (const GALGAS_location inOperand0,
                                             const GALGAS_sint inOperand1,
                                             C_Compiler * /* inCompiler */
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_sint_33__32_List (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_List::setter_insertAtIndex (const GALGAS_location inOperand0,
                                                    const GALGAS_sint inOperand1,
                                                    const GALGAS_uint inInsertionIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_sint_33__32_List (inOperand0, inOperand1 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_List::setter_removeAtIndex (GALGAS_location & outOperand0,
                                                    GALGAS_sint & outOperand1,
                                                    const GALGAS_uint inRemoveIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_sint_33__32_List * p = (cCollectionElement_sint_33__32_List *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        outOperand1.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
        outOperand0 = p->mObject.mProperty_location ;
        outOperand1 = p->mObject.mProperty_value ;
      }
    }else{
      outOperand0.drop () ;
      outOperand1.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_List::setter_popFirst (GALGAS_location & outOperand0,
                                               GALGAS_sint & outOperand1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_33__32_List * p = (cCollectionElement_sint_33__32_List *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_List::setter_popLast (GALGAS_location & outOperand0,
                                              GALGAS_sint & outOperand1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_33__32_List * p = (cCollectionElement_sint_33__32_List *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_List::method_first (GALGAS_location & outOperand0,
                                            GALGAS_sint & outOperand1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_33__32_List * p = (cCollectionElement_sint_33__32_List *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_List::method_last (GALGAS_location & outOperand0,
                                           GALGAS_sint & outOperand1,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_33__32_List * p = (cCollectionElement_sint_33__32_List *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List GALGAS_sint_33__32_List::add_operation (const GALGAS_sint_33__32_List & inOperand,
                                                                C_Compiler * /* inCompiler */
                                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_33__32_List result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List GALGAS_sint_33__32_List::getter_subListWithRange (const GALGAS_range & inRange,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_sint_33__32_List result = GALGAS_sint_33__32_List::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List GALGAS_sint_33__32_List::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_sint_33__32_List result = GALGAS_sint_33__32_List::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List GALGAS_sint_33__32_List::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_sint_33__32_List result = GALGAS_sint_33__32_List::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_List::plusAssign_operation (const GALGAS_sint_33__32_List inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_List::setter_setLocationAtIndex (GALGAS_location inOperand,
                                                         GALGAS_uint inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_sint_33__32_List * p = (cCollectionElement_sint_33__32_List *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_location = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_sint_33__32_List::getter_locationAtIndex (const GALGAS_uint & inIndex,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_33__32_List * p = (cCollectionElement_sint_33__32_List *) attributes.ptr () ;
  GALGAS_location result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
    result = p->mObject.mProperty_location ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_List::setter_setValueAtIndex (GALGAS_sint inOperand,
                                                      GALGAS_uint inIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  cCollectionElement_sint_33__32_List * p = (cCollectionElement_sint_33__32_List *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_value = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint_33__32_List::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_33__32_List * p = (cCollectionElement_sint_33__32_List *) attributes.ptr () ;
  GALGAS_sint result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
    result = p->mObject.mProperty_value ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_sint_33__32_List::cEnumerator_sint_33__32_List (const GALGAS_sint_33__32_List & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List_2D_element cEnumerator_sint_33__32_List::current (LOCATION_ARGS) const {
  const cCollectionElement_sint_33__32_List * p = (const cCollectionElement_sint_33__32_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cEnumerator_sint_33__32_List::current_location (LOCATION_ARGS) const {
  const cCollectionElement_sint_33__32_List * p = (const cCollectionElement_sint_33__32_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
  return p->mObject.mProperty_location ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint cEnumerator_sint_33__32_List::current_value (LOCATION_ARGS) const {
  const cCollectionElement_sint_33__32_List * p = (const cCollectionElement_sint_33__32_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
  return p->mObject.mProperty_value ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @sint32List generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_33__32_List ("sint32List",
                                         nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sint_33__32_List::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_List ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sint_33__32_List::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_33__32_List (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List GALGAS_sint_33__32_List::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_List result ;
  const GALGAS_sint_33__32_List * p = (const GALGAS_sint_33__32_List *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_sint_33__32_List *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint32List", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@sint_36__34_List' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_sint_36__34_List : public cCollectionElement {
  public: GALGAS_sint_36__34_List_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_sint_36__34_List (const GALGAS_location & in_location,
                                               const GALGAS_sint_36__34_ & in_value
                                               COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_sint_36__34_List (const GALGAS_sint_36__34_List_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;

//--- Description
  public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_sint_36__34_List::cCollectionElement_sint_36__34_List (const GALGAS_location & in_location,
                                                                          const GALGAS_sint_36__34_ & in_value
                                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_location, in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_sint_36__34_List::cCollectionElement_sint_36__34_List (const GALGAS_sint_36__34_List_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_location, inElement.mProperty_value) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_sint_36__34_List::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_sint_36__34_List::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_sint_36__34_List (mObject.mProperty_location, mObject.mProperty_value COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_sint_36__34_List::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "location" ":" ;
  mObject.mProperty_location.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mProperty_value.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_sint_36__34_List::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_sint_36__34_List * operand = (cCollectionElement_sint_36__34_List *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_sint_36__34_List) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List::GALGAS_sint_36__34_List (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List::GALGAS_sint_36__34_List (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List GALGAS_sint_36__34_List::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint_36__34_List  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List GALGAS_sint_36__34_List::constructor_listWithValue (const GALGAS_location & inOperand0,
                                                                            const GALGAS_sint_36__34_ & inOperand1
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_List result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_sint_36__34_List (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_sint_36__34_List::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_List::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                         const GALGAS_location & in_location,
                                                         const GALGAS_sint_36__34_ & in_value
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_sint_36__34_List * p = nullptr ;
  macroMyNew (p, cCollectionElement_sint_36__34_List (in_location,
                                                      in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_List::addAssign_operation (const GALGAS_location & inOperand0,
                                                   const GALGAS_sint_36__34_ & inOperand1
                                                   COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_sint_36__34_List (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_List::setter_append (const GALGAS_location inOperand0,
                                             const GALGAS_sint_36__34_ inOperand1,
                                             C_Compiler * /* inCompiler */
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_sint_36__34_List (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_List::setter_insertAtIndex (const GALGAS_location inOperand0,
                                                    const GALGAS_sint_36__34_ inOperand1,
                                                    const GALGAS_uint inInsertionIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_sint_36__34_List (inOperand0, inOperand1 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_List::setter_removeAtIndex (GALGAS_location & outOperand0,
                                                    GALGAS_sint_36__34_ & outOperand1,
                                                    const GALGAS_uint inRemoveIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_sint_36__34_List * p = (cCollectionElement_sint_36__34_List *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        outOperand1.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
        outOperand0 = p->mObject.mProperty_location ;
        outOperand1 = p->mObject.mProperty_value ;
      }
    }else{
      outOperand0.drop () ;
      outOperand1.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_List::setter_popFirst (GALGAS_location & outOperand0,
                                               GALGAS_sint_36__34_ & outOperand1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_36__34_List * p = (cCollectionElement_sint_36__34_List *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_List::setter_popLast (GALGAS_location & outOperand0,
                                              GALGAS_sint_36__34_ & outOperand1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_36__34_List * p = (cCollectionElement_sint_36__34_List *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_List::method_first (GALGAS_location & outOperand0,
                                            GALGAS_sint_36__34_ & outOperand1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_36__34_List * p = (cCollectionElement_sint_36__34_List *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_List::method_last (GALGAS_location & outOperand0,
                                           GALGAS_sint_36__34_ & outOperand1,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_36__34_List * p = (cCollectionElement_sint_36__34_List *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List GALGAS_sint_36__34_List::add_operation (const GALGAS_sint_36__34_List & inOperand,
                                                                C_Compiler * /* inCompiler */
                                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_List result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List GALGAS_sint_36__34_List::getter_subListWithRange (const GALGAS_range & inRange,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_List result = GALGAS_sint_36__34_List::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List GALGAS_sint_36__34_List::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_List result = GALGAS_sint_36__34_List::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List GALGAS_sint_36__34_List::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_List result = GALGAS_sint_36__34_List::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_List::plusAssign_operation (const GALGAS_sint_36__34_List inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_List::setter_setLocationAtIndex (GALGAS_location inOperand,
                                                         GALGAS_uint inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_sint_36__34_List * p = (cCollectionElement_sint_36__34_List *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_location = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_sint_36__34_List::getter_locationAtIndex (const GALGAS_uint & inIndex,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_36__34_List * p = (cCollectionElement_sint_36__34_List *) attributes.ptr () ;
  GALGAS_location result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
    result = p->mObject.mProperty_location ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_List::setter_setValueAtIndex (GALGAS_sint_36__34_ inOperand,
                                                      GALGAS_uint inIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  cCollectionElement_sint_36__34_List * p = (cCollectionElement_sint_36__34_List *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_value = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_List::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_36__34_List * p = (cCollectionElement_sint_36__34_List *) attributes.ptr () ;
  GALGAS_sint_36__34_ result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
    result = p->mObject.mProperty_value ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_sint_36__34_List::cEnumerator_sint_36__34_List (const GALGAS_sint_36__34_List & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List_2D_element cEnumerator_sint_36__34_List::current (LOCATION_ARGS) const {
  const cCollectionElement_sint_36__34_List * p = (const cCollectionElement_sint_36__34_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cEnumerator_sint_36__34_List::current_location (LOCATION_ARGS) const {
  const cCollectionElement_sint_36__34_List * p = (const cCollectionElement_sint_36__34_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
  return p->mObject.mProperty_location ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ cEnumerator_sint_36__34_List::current_value (LOCATION_ARGS) const {
  const cCollectionElement_sint_36__34_List * p = (const cCollectionElement_sint_36__34_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
  return p->mObject.mProperty_value ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @sint64List generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_36__34_List ("sint64List",
                                         nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sint_36__34_List::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_List ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sint_36__34_List::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_36__34_List (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List GALGAS_sint_36__34_List::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_List result ;
  const GALGAS_sint_36__34_List * p = (const GALGAS_sint_36__34_List *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_sint_36__34_List *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint64List", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@floatList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_floatList : public cCollectionElement {
  public: GALGAS_floatList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_floatList (const GALGAS_location & in_location,
                                        const GALGAS_double & in_value
                                        COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_floatList (const GALGAS_floatList_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;

//--- Description
  public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_floatList::cCollectionElement_floatList (const GALGAS_location & in_location,
                                                            const GALGAS_double & in_value
                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_location, in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_floatList::cCollectionElement_floatList (const GALGAS_floatList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_location, inElement.mProperty_value) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_floatList::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_floatList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_floatList (mObject.mProperty_location, mObject.mProperty_value COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_floatList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "location" ":" ;
  mObject.mProperty_location.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mProperty_value.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_floatList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_floatList * operand = (cCollectionElement_floatList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_floatList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList::GALGAS_floatList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList::GALGAS_floatList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList GALGAS_floatList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_floatList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList GALGAS_floatList::constructor_listWithValue (const GALGAS_location & inOperand0,
                                                              const GALGAS_double & inOperand1
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_floatList result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_floatList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_floatList::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const GALGAS_location & in_location,
                                                  const GALGAS_double & in_value
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_floatList * p = nullptr ;
  macroMyNew (p, cCollectionElement_floatList (in_location,
                                               in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatList::addAssign_operation (const GALGAS_location & inOperand0,
                                            const GALGAS_double & inOperand1
                                            COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_floatList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatList::setter_append (const GALGAS_location inOperand0,
                                      const GALGAS_double inOperand1,
                                      C_Compiler * /* inCompiler */
                                      COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_floatList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatList::setter_insertAtIndex (const GALGAS_location inOperand0,
                                             const GALGAS_double inOperand1,
                                             const GALGAS_uint inInsertionIndex,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_floatList (inOperand0, inOperand1 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatList::setter_removeAtIndex (GALGAS_location & outOperand0,
                                             GALGAS_double & outOperand1,
                                             const GALGAS_uint inRemoveIndex,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_floatList * p = (cCollectionElement_floatList *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        outOperand1.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_floatList) ;
        outOperand0 = p->mObject.mProperty_location ;
        outOperand1 = p->mObject.mProperty_value ;
      }
    }else{
      outOperand0.drop () ;
      outOperand1.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatList::setter_popFirst (GALGAS_location & outOperand0,
                                        GALGAS_double & outOperand1,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_floatList * p = (cCollectionElement_floatList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_floatList) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatList::setter_popLast (GALGAS_location & outOperand0,
                                       GALGAS_double & outOperand1,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_floatList * p = (cCollectionElement_floatList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_floatList) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatList::method_first (GALGAS_location & outOperand0,
                                     GALGAS_double & outOperand1,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_floatList * p = (cCollectionElement_floatList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_floatList) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatList::method_last (GALGAS_location & outOperand0,
                                    GALGAS_double & outOperand1,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_floatList * p = (cCollectionElement_floatList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_floatList) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList GALGAS_floatList::add_operation (const GALGAS_floatList & inOperand,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_floatList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList GALGAS_floatList::getter_subListWithRange (const GALGAS_range & inRange,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_floatList result = GALGAS_floatList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList GALGAS_floatList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_floatList result = GALGAS_floatList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList GALGAS_floatList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_floatList result = GALGAS_floatList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatList::plusAssign_operation (const GALGAS_floatList inOperand,
                                             C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatList::setter_setLocationAtIndex (GALGAS_location inOperand,
                                                  GALGAS_uint inIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_floatList * p = (cCollectionElement_floatList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_floatList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_location = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_floatList::getter_locationAtIndex (const GALGAS_uint & inIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_floatList * p = (cCollectionElement_floatList *) attributes.ptr () ;
  GALGAS_location result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_floatList) ;
    result = p->mObject.mProperty_location ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatList::setter_setValueAtIndex (GALGAS_double inOperand,
                                               GALGAS_uint inIndex,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cCollectionElement_floatList * p = (cCollectionElement_floatList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_floatList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_value = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_floatList::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_floatList * p = (cCollectionElement_floatList *) attributes.ptr () ;
  GALGAS_double result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_floatList) ;
    result = p->mObject.mProperty_value ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_floatList::cEnumerator_floatList (const GALGAS_floatList & inEnumeratedObject,
                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList_2D_element cEnumerator_floatList::current (LOCATION_ARGS) const {
  const cCollectionElement_floatList * p = (const cCollectionElement_floatList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_floatList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cEnumerator_floatList::current_location (LOCATION_ARGS) const {
  const cCollectionElement_floatList * p = (const cCollectionElement_floatList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_floatList) ;
  return p->mObject.mProperty_location ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cEnumerator_floatList::current_value (LOCATION_ARGS) const {
  const cCollectionElement_floatList * p = (const cCollectionElement_floatList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_floatList) ;
  return p->mObject.mProperty_value ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @floatList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_floatList ("floatList",
                                  nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_floatList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_floatList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_floatList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList GALGAS_floatList::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_floatList result ;
  const GALGAS_floatList * p = (const GALGAS_floatList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_floatList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("floatList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@numberList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_numberList : public cCollectionElement {
  public: GALGAS_numberList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_numberList (const GALGAS_location & in_location,
                                         const GALGAS_object_5F_t & in_value
                                         COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_numberList (const GALGAS_numberList_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;

//--- Description
  public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_numberList::cCollectionElement_numberList (const GALGAS_location & in_location,
                                                              const GALGAS_object_5F_t & in_value
                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_location, in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_numberList::cCollectionElement_numberList (const GALGAS_numberList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_location, inElement.mProperty_value) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_numberList::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_numberList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_numberList (mObject.mProperty_location, mObject.mProperty_value COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_numberList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "location" ":" ;
  mObject.mProperty_location.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mProperty_value.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_numberList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_numberList * operand = (cCollectionElement_numberList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_numberList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList::GALGAS_numberList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList::GALGAS_numberList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList GALGAS_numberList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_numberList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList GALGAS_numberList::constructor_listWithValue (const GALGAS_location & inOperand0,
                                                                const GALGAS_object_5F_t & inOperand1
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_numberList result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_numberList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_numberList::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_numberList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                   const GALGAS_location & in_location,
                                                   const GALGAS_object_5F_t & in_value
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement_numberList * p = nullptr ;
  macroMyNew (p, cCollectionElement_numberList (in_location,
                                                in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_numberList::addAssign_operation (const GALGAS_location & inOperand0,
                                             const GALGAS_object_5F_t & inOperand1
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_numberList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_numberList::setter_append (const GALGAS_location inOperand0,
                                       const GALGAS_object_5F_t inOperand1,
                                       C_Compiler * /* inCompiler */
                                       COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_numberList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_numberList::setter_insertAtIndex (const GALGAS_location inOperand0,
                                              const GALGAS_object_5F_t inOperand1,
                                              const GALGAS_uint inInsertionIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_numberList (inOperand0, inOperand1 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_numberList::setter_removeAtIndex (GALGAS_location & outOperand0,
                                              GALGAS_object_5F_t & outOperand1,
                                              const GALGAS_uint inRemoveIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_numberList * p = (cCollectionElement_numberList *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        outOperand1.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_numberList) ;
        outOperand0 = p->mObject.mProperty_location ;
        outOperand1 = p->mObject.mProperty_value ;
      }
    }else{
      outOperand0.drop () ;
      outOperand1.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_numberList::setter_popFirst (GALGAS_location & outOperand0,
                                         GALGAS_object_5F_t & outOperand1,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_numberList * p = (cCollectionElement_numberList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_numberList) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_numberList::setter_popLast (GALGAS_location & outOperand0,
                                        GALGAS_object_5F_t & outOperand1,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_numberList * p = (cCollectionElement_numberList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_numberList) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_numberList::method_first (GALGAS_location & outOperand0,
                                      GALGAS_object_5F_t & outOperand1,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_numberList * p = (cCollectionElement_numberList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_numberList) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_numberList::method_last (GALGAS_location & outOperand0,
                                     GALGAS_object_5F_t & outOperand1,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_numberList * p = (cCollectionElement_numberList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_numberList) ;
    outOperand0 = p->mObject.mProperty_location ;
    outOperand1 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList GALGAS_numberList::add_operation (const GALGAS_numberList & inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_numberList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList GALGAS_numberList::getter_subListWithRange (const GALGAS_range & inRange,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_numberList result = GALGAS_numberList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList GALGAS_numberList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_numberList result = GALGAS_numberList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList GALGAS_numberList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_numberList result = GALGAS_numberList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_numberList::plusAssign_operation (const GALGAS_numberList inOperand,
                                              C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_numberList::setter_setLocationAtIndex (GALGAS_location inOperand,
                                                   GALGAS_uint inIndex,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement_numberList * p = (cCollectionElement_numberList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_numberList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_location = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_numberList::getter_locationAtIndex (const GALGAS_uint & inIndex,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_numberList * p = (cCollectionElement_numberList *) attributes.ptr () ;
  GALGAS_location result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_numberList) ;
    result = p->mObject.mProperty_location ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_numberList::setter_setValueAtIndex (GALGAS_object_5F_t inOperand,
                                                GALGAS_uint inIndex,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cCollectionElement_numberList * p = (cCollectionElement_numberList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_numberList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_value = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_object_5F_t GALGAS_numberList::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_numberList * p = (cCollectionElement_numberList *) attributes.ptr () ;
  GALGAS_object_5F_t result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_numberList) ;
    result = p->mObject.mProperty_value ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_numberList::cEnumerator_numberList (const GALGAS_numberList & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList_2D_element cEnumerator_numberList::current (LOCATION_ARGS) const {
  const cCollectionElement_numberList * p = (const cCollectionElement_numberList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_numberList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cEnumerator_numberList::current_location (LOCATION_ARGS) const {
  const cCollectionElement_numberList * p = (const cCollectionElement_numberList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_numberList) ;
  return p->mObject.mProperty_location ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_object_5F_t cEnumerator_numberList::current_value (LOCATION_ARGS) const {
  const cCollectionElement_numberList * p = (const cCollectionElement_numberList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_numberList) ;
  return p->mObject.mProperty_value ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @numberList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_numberList ("numberList",
                                   nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_numberList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_numberList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_numberList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_numberList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList GALGAS_numberList::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_numberList result ;
  const GALGAS_numberList * p = (const GALGAS_numberList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_numberList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("numberList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------



typeComparisonResult GALGAS_attributeRange::objectCompare (const GALGAS_attributeRange & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_attributeRange::GALGAS_attributeRange (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_attributeRange::GALGAS_attributeRange (const cPtr_attributeRange * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_attributeRange) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_attributeRange::readProperty_location (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_location () ;
  }else{
    const cPtr_attributeRange * p = (const cPtr_attributeRange *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_attributeRange) ;
    return p->mProperty_location ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cPtr_attributeRange::getter_location (UNUSED_LOCATION_ARGS) const {
  return mProperty_location ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_attributeRange::setter_setLocation (GALGAS_location inValue
                                                COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_attributeRange * p = (cPtr_attributeRange *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_attributeRange) ;
    p->mProperty_location = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_attributeRange::setter_setLocation (GALGAS_location inValue
                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_location = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @attributeRange class
//----------------------------------------------------------------------------------------------------------------------

cPtr_attributeRange::cPtr_attributeRange (const GALGAS_location & in_location
                                          COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_location (in_location) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @attributeRange generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_attributeRange ("attributeRange",
                                       nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_attributeRange::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_attributeRange ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_attributeRange::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_attributeRange (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_attributeRange GALGAS_attributeRange::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_attributeRange result ;
  const GALGAS_attributeRange * p = (const GALGAS_attributeRange *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_attributeRange *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("attributeRange", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension method '@attributeRange enclose'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_enclose (cPtr_attributeRange * inObject,
                                  GALGAS_bool & out_isWithin,
                                  const GALGAS_attributeRange constin_value,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
//--- Drop output arguments
  out_isWithin.drop () ;
//--- Find method
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_attributeRange) ;
    inObject->method_enclose (out_isWithin, constin_value, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_noRange::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_noRange * p = (const cPtr_noRange *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_noRange) ;
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_noRange::objectCompare (const GALGAS_noRange & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_noRange::GALGAS_noRange (void) :
GALGAS_attributeRange () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_noRange GALGAS_noRange::constructor_default (LOCATION_ARGS) {
  return GALGAS_noRange::constructor_new (GALGAS_location::constructor_nowhere (HERE)
                                          COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_noRange::GALGAS_noRange (const cPtr_noRange * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_noRange) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_noRange GALGAS_noRange::constructor_new (const GALGAS_location & inAttribute_location
                                                COMMA_LOCATION_ARGS) {
  GALGAS_noRange result ;
  if (inAttribute_location.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_noRange (inAttribute_location COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @noRange class
//----------------------------------------------------------------------------------------------------------------------

cPtr_noRange::cPtr_noRange (const GALGAS_location & in_location
                            COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_noRange::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_noRange ;
}

void cPtr_noRange::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "[@noRange:" ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_noRange::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_noRange (mProperty_location COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @noRange generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_noRange ("noRange",
                                & kTypeDescriptor_GALGAS_attributeRange) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_noRange::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_noRange ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_noRange::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_noRange (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_noRange GALGAS_noRange::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_noRange result ;
  const GALGAS_noRange * p = (const GALGAS_noRange *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_noRange *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("noRange", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_uint_33__32_AttributeSet::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_33__32_AttributeSet * p = (const cPtr_uint_33__32_AttributeSet *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_33__32_AttributeSet) ;
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_valueList.objectCompare (p->mProperty_valueList) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_uint_33__32_AttributeSet::objectCompare (const GALGAS_uint_33__32_AttributeSet & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_AttributeSet::GALGAS_uint_33__32_AttributeSet (void) :
GALGAS_attributeRange () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_AttributeSet GALGAS_uint_33__32_AttributeSet::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_33__32_AttributeSet::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_uint_33__32_List::constructor_emptyList (HERE)
                                                           COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_AttributeSet::GALGAS_uint_33__32_AttributeSet (const cPtr_uint_33__32_AttributeSet * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_33__32_AttributeSet) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_AttributeSet GALGAS_uint_33__32_AttributeSet::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                  const GALGAS_uint_33__32_List & inAttribute_valueList
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_AttributeSet result ;
  if (inAttribute_location.isValid () && inAttribute_valueList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_33__32_AttributeSet (inAttribute_location, inAttribute_valueList COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List GALGAS_uint_33__32_AttributeSet::readProperty_valueList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint_33__32_List () ;
  }else{
    const cPtr_uint_33__32_AttributeSet * p = (const cPtr_uint_33__32_AttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32_AttributeSet) ;
    return p->mProperty_valueList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List cPtr_uint_33__32_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  return mProperty_valueList ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_AttributeSet::setter_setValueList (GALGAS_uint_33__32_List inValue
                                                           COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_uint_33__32_AttributeSet * p = (cPtr_uint_33__32_AttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32_AttributeSet) ;
    p->mProperty_valueList = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_uint_33__32_AttributeSet::setter_setValueList (GALGAS_uint_33__32_List inValue
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_valueList = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @uint32AttributeSet class
//----------------------------------------------------------------------------------------------------------------------

cPtr_uint_33__32_AttributeSet::cPtr_uint_33__32_AttributeSet (const GALGAS_location & in_location,
                                                              const GALGAS_uint_33__32_List & in_valueList
                                                              COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mProperty_valueList (in_valueList) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_uint_33__32_AttributeSet::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet ;
}

void cPtr_uint_33__32_AttributeSet::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@uint32AttributeSet:" ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_valueList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_uint_33__32_AttributeSet::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_uint_33__32_AttributeSet (mProperty_location, mProperty_valueList COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @uint32AttributeSet generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_33__32_AttributeSet ("uint32AttributeSet",
                                                 & kTypeDescriptor_GALGAS_attributeRange) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_33__32_AttributeSet::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_33__32_AttributeSet::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_33__32_AttributeSet (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_AttributeSet GALGAS_uint_33__32_AttributeSet::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_AttributeSet result ;
  const GALGAS_uint_33__32_AttributeSet * p = (const GALGAS_uint_33__32_AttributeSet *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_uint_33__32_AttributeSet *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint32AttributeSet", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_uint_36__34_AttributeSet::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_36__34_AttributeSet * p = (const cPtr_uint_36__34_AttributeSet *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_36__34_AttributeSet) ;
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_valueList.objectCompare (p->mProperty_valueList) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_uint_36__34_AttributeSet::objectCompare (const GALGAS_uint_36__34_AttributeSet & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_AttributeSet::GALGAS_uint_36__34_AttributeSet (void) :
GALGAS_attributeRange () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_AttributeSet GALGAS_uint_36__34_AttributeSet::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_36__34_AttributeSet::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_uint_36__34_List::constructor_emptyList (HERE)
                                                           COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_AttributeSet::GALGAS_uint_36__34_AttributeSet (const cPtr_uint_36__34_AttributeSet * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_36__34_AttributeSet) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_AttributeSet GALGAS_uint_36__34_AttributeSet::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                  const GALGAS_uint_36__34_List & inAttribute_valueList
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_AttributeSet result ;
  if (inAttribute_location.isValid () && inAttribute_valueList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_36__34_AttributeSet (inAttribute_location, inAttribute_valueList COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List GALGAS_uint_36__34_AttributeSet::readProperty_valueList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint_36__34_List () ;
  }else{
    const cPtr_uint_36__34_AttributeSet * p = (const cPtr_uint_36__34_AttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34_AttributeSet) ;
    return p->mProperty_valueList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List cPtr_uint_36__34_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  return mProperty_valueList ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_AttributeSet::setter_setValueList (GALGAS_uint_36__34_List inValue
                                                           COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_uint_36__34_AttributeSet * p = (cPtr_uint_36__34_AttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34_AttributeSet) ;
    p->mProperty_valueList = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_uint_36__34_AttributeSet::setter_setValueList (GALGAS_uint_36__34_List inValue
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_valueList = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @uint64AttributeSet class
//----------------------------------------------------------------------------------------------------------------------

cPtr_uint_36__34_AttributeSet::cPtr_uint_36__34_AttributeSet (const GALGAS_location & in_location,
                                                              const GALGAS_uint_36__34_List & in_valueList
                                                              COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mProperty_valueList (in_valueList) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_uint_36__34_AttributeSet::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet ;
}

void cPtr_uint_36__34_AttributeSet::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@uint64AttributeSet:" ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_valueList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_uint_36__34_AttributeSet::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_uint_36__34_AttributeSet (mProperty_location, mProperty_valueList COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @uint64AttributeSet generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34_AttributeSet ("uint64AttributeSet",
                                                 & kTypeDescriptor_GALGAS_attributeRange) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_36__34_AttributeSet::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_36__34_AttributeSet::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34_AttributeSet (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_AttributeSet GALGAS_uint_36__34_AttributeSet::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_AttributeSet result ;
  const GALGAS_uint_36__34_AttributeSet * p = (const GALGAS_uint_36__34_AttributeSet *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_uint_36__34_AttributeSet *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64AttributeSet", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_sint_33__32_AttributeSet::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_33__32_AttributeSet * p = (const cPtr_sint_33__32_AttributeSet *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_33__32_AttributeSet) ;
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_valueList.objectCompare (p->mProperty_valueList) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_sint_33__32_AttributeSet::objectCompare (const GALGAS_sint_33__32_AttributeSet & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_AttributeSet::GALGAS_sint_33__32_AttributeSet (void) :
GALGAS_attributeRange () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_AttributeSet GALGAS_sint_33__32_AttributeSet::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_33__32_AttributeSet::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_sint_33__32_List::constructor_emptyList (HERE)
                                                           COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_AttributeSet::GALGAS_sint_33__32_AttributeSet (const cPtr_sint_33__32_AttributeSet * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_33__32_AttributeSet) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_AttributeSet GALGAS_sint_33__32_AttributeSet::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                  const GALGAS_sint_33__32_List & inAttribute_valueList
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_AttributeSet result ;
  if (inAttribute_location.isValid () && inAttribute_valueList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sint_33__32_AttributeSet (inAttribute_location, inAttribute_valueList COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List GALGAS_sint_33__32_AttributeSet::readProperty_valueList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_sint_33__32_List () ;
  }else{
    const cPtr_sint_33__32_AttributeSet * p = (const cPtr_sint_33__32_AttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32_AttributeSet) ;
    return p->mProperty_valueList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List cPtr_sint_33__32_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  return mProperty_valueList ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_AttributeSet::setter_setValueList (GALGAS_sint_33__32_List inValue
                                                           COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_sint_33__32_AttributeSet * p = (cPtr_sint_33__32_AttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32_AttributeSet) ;
    p->mProperty_valueList = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_sint_33__32_AttributeSet::setter_setValueList (GALGAS_sint_33__32_List inValue
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_valueList = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @sint32AttributeSet class
//----------------------------------------------------------------------------------------------------------------------

cPtr_sint_33__32_AttributeSet::cPtr_sint_33__32_AttributeSet (const GALGAS_location & in_location,
                                                              const GALGAS_sint_33__32_List & in_valueList
                                                              COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mProperty_valueList (in_valueList) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_sint_33__32_AttributeSet::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet ;
}

void cPtr_sint_33__32_AttributeSet::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@sint32AttributeSet:" ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_valueList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_sint_33__32_AttributeSet::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_sint_33__32_AttributeSet (mProperty_location, mProperty_valueList COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @sint32AttributeSet generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_33__32_AttributeSet ("sint32AttributeSet",
                                                 & kTypeDescriptor_GALGAS_attributeRange) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sint_33__32_AttributeSet::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sint_33__32_AttributeSet::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_33__32_AttributeSet (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_AttributeSet GALGAS_sint_33__32_AttributeSet::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_AttributeSet result ;
  const GALGAS_sint_33__32_AttributeSet * p = (const GALGAS_sint_33__32_AttributeSet *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_sint_33__32_AttributeSet *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint32AttributeSet", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_sint_36__34_AttributeSet::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_36__34_AttributeSet * p = (const cPtr_sint_36__34_AttributeSet *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_36__34_AttributeSet) ;
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_valueList.objectCompare (p->mProperty_valueList) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_sint_36__34_AttributeSet::objectCompare (const GALGAS_sint_36__34_AttributeSet & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_AttributeSet::GALGAS_sint_36__34_AttributeSet (void) :
GALGAS_attributeRange () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_AttributeSet GALGAS_sint_36__34_AttributeSet::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_36__34_AttributeSet::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_sint_36__34_List::constructor_emptyList (HERE)
                                                           COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_AttributeSet::GALGAS_sint_36__34_AttributeSet (const cPtr_sint_36__34_AttributeSet * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_36__34_AttributeSet) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_AttributeSet GALGAS_sint_36__34_AttributeSet::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                  const GALGAS_sint_36__34_List & inAttribute_valueList
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_AttributeSet result ;
  if (inAttribute_location.isValid () && inAttribute_valueList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sint_36__34_AttributeSet (inAttribute_location, inAttribute_valueList COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List GALGAS_sint_36__34_AttributeSet::readProperty_valueList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_sint_36__34_List () ;
  }else{
    const cPtr_sint_36__34_AttributeSet * p = (const cPtr_sint_36__34_AttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34_AttributeSet) ;
    return p->mProperty_valueList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List cPtr_sint_36__34_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  return mProperty_valueList ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_AttributeSet::setter_setValueList (GALGAS_sint_36__34_List inValue
                                                           COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_sint_36__34_AttributeSet * p = (cPtr_sint_36__34_AttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34_AttributeSet) ;
    p->mProperty_valueList = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_sint_36__34_AttributeSet::setter_setValueList (GALGAS_sint_36__34_List inValue
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_valueList = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @sint64AttributeSet class
//----------------------------------------------------------------------------------------------------------------------

cPtr_sint_36__34_AttributeSet::cPtr_sint_36__34_AttributeSet (const GALGAS_location & in_location,
                                                              const GALGAS_sint_36__34_List & in_valueList
                                                              COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mProperty_valueList (in_valueList) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_sint_36__34_AttributeSet::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet ;
}

void cPtr_sint_36__34_AttributeSet::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@sint64AttributeSet:" ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_valueList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_sint_36__34_AttributeSet::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_sint_36__34_AttributeSet (mProperty_location, mProperty_valueList COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @sint64AttributeSet generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_36__34_AttributeSet ("sint64AttributeSet",
                                                 & kTypeDescriptor_GALGAS_attributeRange) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sint_36__34_AttributeSet::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sint_36__34_AttributeSet::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_36__34_AttributeSet (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_AttributeSet GALGAS_sint_36__34_AttributeSet::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_AttributeSet result ;
  const GALGAS_sint_36__34_AttributeSet * p = (const GALGAS_sint_36__34_AttributeSet *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_sint_36__34_AttributeSet *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint64AttributeSet", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_floatAttributeSet::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_floatAttributeSet * p = (const cPtr_floatAttributeSet *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_floatAttributeSet) ;
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_valueList.objectCompare (p->mProperty_valueList) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_floatAttributeSet::objectCompare (const GALGAS_floatAttributeSet & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatAttributeSet::GALGAS_floatAttributeSet (void) :
GALGAS_attributeRange () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatAttributeSet GALGAS_floatAttributeSet::constructor_default (LOCATION_ARGS) {
  return GALGAS_floatAttributeSet::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                    GALGAS_floatList::constructor_emptyList (HERE)
                                                    COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatAttributeSet::GALGAS_floatAttributeSet (const cPtr_floatAttributeSet * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_floatAttributeSet) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatAttributeSet GALGAS_floatAttributeSet::constructor_new (const GALGAS_location & inAttribute_location,
                                                                    const GALGAS_floatList & inAttribute_valueList
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_floatAttributeSet result ;
  if (inAttribute_location.isValid () && inAttribute_valueList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_floatAttributeSet (inAttribute_location, inAttribute_valueList COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList GALGAS_floatAttributeSet::readProperty_valueList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_floatList () ;
  }else{
    const cPtr_floatAttributeSet * p = (const cPtr_floatAttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_floatAttributeSet) ;
    return p->mProperty_valueList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList cPtr_floatAttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  return mProperty_valueList ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatAttributeSet::setter_setValueList (GALGAS_floatList inValue
                                                    COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_floatAttributeSet * p = (cPtr_floatAttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_floatAttributeSet) ;
    p->mProperty_valueList = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_floatAttributeSet::setter_setValueList (GALGAS_floatList inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_valueList = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @floatAttributeSet class
//----------------------------------------------------------------------------------------------------------------------

cPtr_floatAttributeSet::cPtr_floatAttributeSet (const GALGAS_location & in_location,
                                                const GALGAS_floatList & in_valueList
                                                COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mProperty_valueList (in_valueList) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_floatAttributeSet::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatAttributeSet ;
}

void cPtr_floatAttributeSet::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@floatAttributeSet:" ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_valueList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_floatAttributeSet::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_floatAttributeSet (mProperty_location, mProperty_valueList COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @floatAttributeSet generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_floatAttributeSet ("floatAttributeSet",
                                          & kTypeDescriptor_GALGAS_attributeRange) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_floatAttributeSet::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatAttributeSet ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_floatAttributeSet::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_floatAttributeSet (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatAttributeSet GALGAS_floatAttributeSet::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_floatAttributeSet result ;
  const GALGAS_floatAttributeSet * p = (const GALGAS_floatAttributeSet *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_floatAttributeSet *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("floatAttributeSet", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_uint_33__32_AttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_33__32_AttributeMinMax * p = (const cPtr_uint_33__32_AttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_33__32_AttributeMinMax) ;
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_min.objectCompare (p->mProperty_min) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_max.objectCompare (p->mProperty_max) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_uint_33__32_AttributeMinMax::objectCompare (const GALGAS_uint_33__32_AttributeMinMax & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_AttributeMinMax::GALGAS_uint_33__32_AttributeMinMax (void) :
GALGAS_attributeRange () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_AttributeMinMax GALGAS_uint_33__32_AttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                              GALGAS_uint::constructor_default (HERE),
                                                              GALGAS_uint::constructor_default (HERE)
                                                              COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_AttributeMinMax::GALGAS_uint_33__32_AttributeMinMax (const cPtr_uint_33__32_AttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_33__32_AttributeMinMax) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_AttributeMinMax GALGAS_uint_33__32_AttributeMinMax::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                        const GALGAS_uint & inAttribute_min,
                                                                                        const GALGAS_uint & inAttribute_max
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_AttributeMinMax result ;
  if (inAttribute_location.isValid () && inAttribute_min.isValid () && inAttribute_max.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_33__32_AttributeMinMax (inAttribute_location, inAttribute_min, inAttribute_max COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_uint_33__32_AttributeMinMax::readProperty_min (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    const cPtr_uint_33__32_AttributeMinMax * p = (const cPtr_uint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32_AttributeMinMax) ;
    return p->mProperty_min ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_uint_33__32_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mProperty_min ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_uint_33__32_AttributeMinMax::readProperty_max (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    const cPtr_uint_33__32_AttributeMinMax * p = (const cPtr_uint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32_AttributeMinMax) ;
    return p->mProperty_max ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_uint_33__32_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mProperty_max ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_AttributeMinMax::setter_setMin (GALGAS_uint inValue
                                                        COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_uint_33__32_AttributeMinMax * p = (cPtr_uint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32_AttributeMinMax) ;
    p->mProperty_min = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_uint_33__32_AttributeMinMax::setter_setMin (GALGAS_uint inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_min = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_AttributeMinMax::setter_setMax (GALGAS_uint inValue
                                                        COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_uint_33__32_AttributeMinMax * p = (cPtr_uint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32_AttributeMinMax) ;
    p->mProperty_max = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_uint_33__32_AttributeMinMax::setter_setMax (GALGAS_uint inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_max = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @uint32AttributeMinMax class
//----------------------------------------------------------------------------------------------------------------------

cPtr_uint_33__32_AttributeMinMax::cPtr_uint_33__32_AttributeMinMax (const GALGAS_location & in_location,
                                                                    const GALGAS_uint & in_min,
                                                                    const GALGAS_uint & in_max
                                                                    COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mProperty_min (in_min),
mProperty_max (in_max) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_uint_33__32_AttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax ;
}

void cPtr_uint_33__32_AttributeMinMax::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@uint32AttributeMinMax:" ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_uint_33__32_AttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_uint_33__32_AttributeMinMax (mProperty_location, mProperty_min, mProperty_max COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @uint32AttributeMinMax generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax ("uint32AttributeMinMax",
                                                    & kTypeDescriptor_GALGAS_attributeRange) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_33__32_AttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_33__32_AttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_33__32_AttributeMinMax (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_AttributeMinMax GALGAS_uint_33__32_AttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_AttributeMinMax result ;
  const GALGAS_uint_33__32_AttributeMinMax * p = (const GALGAS_uint_33__32_AttributeMinMax *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_uint_33__32_AttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint32AttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}


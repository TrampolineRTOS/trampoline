#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-5.h"


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlForeachStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_keyName.objectCompare (p->mAttribute_keyName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_variableName.objectCompare (p->mAttribute_variableName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_indexName.objectCompare (p->mAttribute_indexName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_iterable.objectCompare (p->mAttribute_iterable) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_beforeList.objectCompare (p->mAttribute_beforeList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_betweenList.objectCompare (p->mAttribute_betweenList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_afterList.objectCompare (p->mAttribute_afterList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_doList.objectCompare (p->mAttribute_doList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlForeachStatementInstruction::objectCompare (const GALGAS_gtlForeachStatementInstruction & inOperand) const {
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

GALGAS_gtlForeachStatementInstruction::GALGAS_gtlForeachStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlForeachStatementInstruction::GALGAS_gtlForeachStatementInstruction (const cPtr_gtlForeachStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlForeachStatementInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlForeachStatementInstruction GALGAS_gtlForeachStatementInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                              const GALGAS_string & inAttribute_signature,
                                                                                              const GALGAS_lstring & inAttribute_keyName,
                                                                                              const GALGAS_lstring & inAttribute_variableName,
                                                                                              const GALGAS_lstring & inAttribute_indexName,
                                                                                              const GALGAS_gtlExpression & inAttribute_iterable,
                                                                                              const GALGAS_gtlInstructionList & inAttribute_beforeList,
                                                                                              const GALGAS_gtlInstructionList & inAttribute_betweenList,
                                                                                              const GALGAS_gtlInstructionList & inAttribute_afterList,
                                                                                              const GALGAS_gtlInstructionList & inAttribute_doList
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlForeachStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_keyName.isValid () && inAttribute_variableName.isValid () && inAttribute_indexName.isValid () && inAttribute_iterable.isValid () && inAttribute_beforeList.isValid () && inAttribute_betweenList.isValid () && inAttribute_afterList.isValid () && inAttribute_doList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlForeachStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_keyName, inAttribute_variableName, inAttribute_indexName, inAttribute_iterable, inAttribute_beforeList, inAttribute_betweenList, inAttribute_afterList, inAttribute_doList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlForeachStatementInstruction::getter_keyName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    result = p->mAttribute_keyName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlForeachStatementInstruction::getter_keyName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_keyName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlForeachStatementInstruction::getter_variableName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    result = p->mAttribute_variableName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlForeachStatementInstruction::getter_variableName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_variableName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlForeachStatementInstruction::getter_indexName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    result = p->mAttribute_indexName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlForeachStatementInstruction::getter_indexName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_indexName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlForeachStatementInstruction::getter_iterable (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    result = p->mAttribute_iterable ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlForeachStatementInstruction::getter_iterable (UNUSED_LOCATION_ARGS) const {
  return mAttribute_iterable ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlForeachStatementInstruction::getter_beforeList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    result = p->mAttribute_beforeList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlForeachStatementInstruction::getter_beforeList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_beforeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlForeachStatementInstruction::getter_betweenList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    result = p->mAttribute_betweenList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlForeachStatementInstruction::getter_betweenList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_betweenList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlForeachStatementInstruction::getter_afterList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    result = p->mAttribute_afterList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlForeachStatementInstruction::getter_afterList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_afterList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlForeachStatementInstruction::getter_doList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    result = p->mAttribute_doList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlForeachStatementInstruction::getter_doList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_doList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                               Pointer class for @gtlForeachStatementInstruction class                               *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlForeachStatementInstruction::cPtr_gtlForeachStatementInstruction (const GALGAS_location & in_where,
                                                                          const GALGAS_string & in_signature,
                                                                          const GALGAS_lstring & in_keyName,
                                                                          const GALGAS_lstring & in_variableName,
                                                                          const GALGAS_lstring & in_indexName,
                                                                          const GALGAS_gtlExpression & in_iterable,
                                                                          const GALGAS_gtlInstructionList & in_beforeList,
                                                                          const GALGAS_gtlInstructionList & in_betweenList,
                                                                          const GALGAS_gtlInstructionList & in_afterList,
                                                                          const GALGAS_gtlInstructionList & in_doList
                                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_keyName (in_keyName),
mAttribute_variableName (in_variableName),
mAttribute_indexName (in_indexName),
mAttribute_iterable (in_iterable),
mAttribute_beforeList (in_beforeList),
mAttribute_betweenList (in_betweenList),
mAttribute_afterList (in_afterList),
mAttribute_doList (in_doList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlForeachStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlForeachStatementInstruction ;
}

void cPtr_gtlForeachStatementInstruction::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "[@gtlForeachStatementInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_keyName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_variableName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_indexName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_iterable.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_beforeList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_betweenList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_afterList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_doList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlForeachStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlForeachStatementInstruction (mAttribute_where, mAttribute_signature, mAttribute_keyName, mAttribute_variableName, mAttribute_indexName, mAttribute_iterable, mAttribute_beforeList, mAttribute_betweenList, mAttribute_afterList, mAttribute_doList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @gtlForeachStatementInstruction type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlForeachStatementInstruction ("gtlForeachStatementInstruction",
                                                       & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlForeachStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlForeachStatementInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlForeachStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlForeachStatementInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlForeachStatementInstruction GALGAS_gtlForeachStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlForeachStatementInstruction result ;
  const GALGAS_gtlForeachStatementInstruction * p = (const GALGAS_gtlForeachStatementInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlForeachStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlForeachStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlGetColumnInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlGetColumnInstruction * p = (const cPtr_gtlGetColumnInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlGetColumnInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_destVariable.objectCompare (p->mAttribute_destVariable) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlGetColumnInstruction::objectCompare (const GALGAS_gtlGetColumnInstruction & inOperand) const {
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

GALGAS_gtlGetColumnInstruction::GALGAS_gtlGetColumnInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetColumnInstruction GALGAS_gtlGetColumnInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlGetColumnInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                          GALGAS_string::constructor_default (HERE),
                                                          GALGAS_gtlVarPath::constructor_emptyList (HERE)
                                                          COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetColumnInstruction::GALGAS_gtlGetColumnInstruction (const cPtr_gtlGetColumnInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlGetColumnInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetColumnInstruction GALGAS_gtlGetColumnInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                const GALGAS_string & inAttribute_signature,
                                                                                const GALGAS_gtlVarPath & inAttribute_destVariable
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetColumnInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_destVariable.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlGetColumnInstruction (inAttribute_where, inAttribute_signature, inAttribute_destVariable COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlGetColumnInstruction::getter_destVariable (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlGetColumnInstruction * p = (const cPtr_gtlGetColumnInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlGetColumnInstruction) ;
    result = p->mAttribute_destVariable ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath cPtr_gtlGetColumnInstruction::getter_destVariable (UNUSED_LOCATION_ARGS) const {
  return mAttribute_destVariable ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @gtlGetColumnInstruction class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlGetColumnInstruction::cPtr_gtlGetColumnInstruction (const GALGAS_location & in_where,
                                                            const GALGAS_string & in_signature,
                                                            const GALGAS_gtlVarPath & in_destVariable
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_destVariable (in_destVariable) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlGetColumnInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGetColumnInstruction ;
}

void cPtr_gtlGetColumnInstruction::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlGetColumnInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_destVariable.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlGetColumnInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlGetColumnInstruction (mAttribute_where, mAttribute_signature, mAttribute_destVariable COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlGetColumnInstruction type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlGetColumnInstruction ("gtlGetColumnInstruction",
                                                & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlGetColumnInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGetColumnInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlGetColumnInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlGetColumnInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetColumnInstruction GALGAS_gtlGetColumnInstruction::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetColumnInstruction result ;
  const GALGAS_gtlGetColumnInstruction * p = (const GALGAS_gtlGetColumnInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlGetColumnInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlGetColumnInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlHelpInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlHelpInstruction * p = (const cPtr_gtlHelpInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlHelpInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlHelpInstruction::GALGAS_gtlHelpInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlHelpInstruction GALGAS_gtlHelpInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlHelpInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                     GALGAS_string::constructor_default (HERE)
                                                     COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlHelpInstruction::GALGAS_gtlHelpInstruction (const cPtr_gtlHelpInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlHelpInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlHelpInstruction GALGAS_gtlHelpInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                      const GALGAS_string & inAttribute_signature
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlHelpInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlHelpInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @gtlHelpInstruction class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlHelpInstruction::cPtr_gtlHelpInstruction (const GALGAS_location & in_where,
                                                  const GALGAS_string & in_signature
                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlHelpInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlHelpInstruction ;
}

void cPtr_gtlHelpInstruction::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@gtlHelpInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlHelpInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlHelpInstruction (mAttribute_where, mAttribute_signature COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlHelpInstruction type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlHelpInstruction ("gtlHelpInstruction",
                                           & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlHelpInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlHelpInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlHelpInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlHelpInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlHelpInstruction GALGAS_gtlHelpInstruction::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlHelpInstruction result ;
  const GALGAS_gtlHelpInstruction * p = (const GALGAS_gtlHelpInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlHelpInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlHelpInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlHereInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlHereInstruction * p = (const cPtr_gtlHereInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlHereInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlHereInstruction::objectCompare (const GALGAS_gtlHereInstruction & inOperand) const {
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

GALGAS_gtlHereInstruction::GALGAS_gtlHereInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlHereInstruction GALGAS_gtlHereInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlHereInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                     GALGAS_string::constructor_default (HERE)
                                                     COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlHereInstruction::GALGAS_gtlHereInstruction (const cPtr_gtlHereInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlHereInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlHereInstruction GALGAS_gtlHereInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                      const GALGAS_string & inAttribute_signature
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlHereInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlHereInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @gtlHereInstruction class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlHereInstruction::cPtr_gtlHereInstruction (const GALGAS_location & in_where,
                                                  const GALGAS_string & in_signature
                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlHereInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlHereInstruction ;
}

void cPtr_gtlHereInstruction::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@gtlHereInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlHereInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlHereInstruction (mAttribute_where, mAttribute_signature COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlHereInstruction type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlHereInstruction ("gtlHereInstruction",
                                           & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlHereInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlHereInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlHereInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlHereInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlHereInstruction GALGAS_gtlHereInstruction::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlHereInstruction result ;
  const GALGAS_gtlHereInstruction * p = (const GALGAS_gtlHereInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlHereInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlHereInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlIfStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlIfStatementInstruction * p = (const cPtr_gtlIfStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlIfStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_thenElsifList.objectCompare (p->mAttribute_thenElsifList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_elseList.objectCompare (p->mAttribute_elseList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlIfStatementInstruction::objectCompare (const GALGAS_gtlIfStatementInstruction & inOperand) const {
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

GALGAS_gtlIfStatementInstruction::GALGAS_gtlIfStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlIfStatementInstruction GALGAS_gtlIfStatementInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlIfStatementInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                            GALGAS_string::constructor_default (HERE),
                                                            GALGAS_gtlThenElsifStatementList::constructor_emptyList (HERE),
                                                            GALGAS_gtlInstructionList::constructor_emptyList (HERE)
                                                            COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlIfStatementInstruction::GALGAS_gtlIfStatementInstruction (const cPtr_gtlIfStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlIfStatementInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlIfStatementInstruction GALGAS_gtlIfStatementInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                    const GALGAS_string & inAttribute_signature,
                                                                                    const GALGAS_gtlThenElsifStatementList & inAttribute_thenElsifList,
                                                                                    const GALGAS_gtlInstructionList & inAttribute_elseList
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlIfStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_thenElsifList.isValid () && inAttribute_elseList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlIfStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_thenElsifList, inAttribute_elseList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList GALGAS_gtlIfStatementInstruction::getter_thenElsifList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlThenElsifStatementList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlIfStatementInstruction * p = (const cPtr_gtlIfStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlIfStatementInstruction) ;
    result = p->mAttribute_thenElsifList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList cPtr_gtlIfStatementInstruction::getter_thenElsifList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_thenElsifList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlIfStatementInstruction::getter_elseList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlIfStatementInstruction * p = (const cPtr_gtlIfStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlIfStatementInstruction) ;
    result = p->mAttribute_elseList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlIfStatementInstruction::getter_elseList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_elseList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @gtlIfStatementInstruction class                                  *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlIfStatementInstruction::cPtr_gtlIfStatementInstruction (const GALGAS_location & in_where,
                                                                const GALGAS_string & in_signature,
                                                                const GALGAS_gtlThenElsifStatementList & in_thenElsifList,
                                                                const GALGAS_gtlInstructionList & in_elseList
                                                                COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_thenElsifList (in_thenElsifList),
mAttribute_elseList (in_elseList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlIfStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlIfStatementInstruction ;
}

void cPtr_gtlIfStatementInstruction::description (C_String & ioString,
                                                  const int32_t inIndentation) const {
  ioString << "[@gtlIfStatementInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_thenElsifList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_elseList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlIfStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlIfStatementInstruction (mAttribute_where, mAttribute_signature, mAttribute_thenElsifList, mAttribute_elseList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlIfStatementInstruction type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlIfStatementInstruction ("gtlIfStatementInstruction",
                                                  & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlIfStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlIfStatementInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlIfStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlIfStatementInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlIfStatementInstruction GALGAS_gtlIfStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlIfStatementInstruction result ;
  const GALGAS_gtlIfStatementInstruction * p = (const GALGAS_gtlIfStatementInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlIfStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlIfStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlInputStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlInputStatementInstruction * p = (const cPtr_gtlInputStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlInputStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_formalArguments.objectCompare (p->mAttribute_formalArguments) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlInputStatementInstruction::objectCompare (const GALGAS_gtlInputStatementInstruction & inOperand) const {
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

GALGAS_gtlInputStatementInstruction::GALGAS_gtlInputStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInputStatementInstruction GALGAS_gtlInputStatementInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlInputStatementInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                               GALGAS_string::constructor_default (HERE),
                                                               GALGAS_gtlArgumentList::constructor_emptyList (HERE)
                                                               COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInputStatementInstruction::GALGAS_gtlInputStatementInstruction (const cPtr_gtlInputStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlInputStatementInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInputStatementInstruction GALGAS_gtlInputStatementInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                          const GALGAS_string & inAttribute_signature,
                                                                                          const GALGAS_gtlArgumentList & inAttribute_formalArguments
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlInputStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_formalArguments.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlInputStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_formalArguments COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList GALGAS_gtlInputStatementInstruction::getter_formalArguments (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlArgumentList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlInputStatementInstruction * p = (const cPtr_gtlInputStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlInputStatementInstruction) ;
    result = p->mAttribute_formalArguments ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList cPtr_gtlInputStatementInstruction::getter_formalArguments (UNUSED_LOCATION_ARGS) const {
  return mAttribute_formalArguments ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                Pointer class for @gtlInputStatementInstruction class                                *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlInputStatementInstruction::cPtr_gtlInputStatementInstruction (const GALGAS_location & in_where,
                                                                      const GALGAS_string & in_signature,
                                                                      const GALGAS_gtlArgumentList & in_formalArguments
                                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_formalArguments (in_formalArguments) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlInputStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInputStatementInstruction ;
}

void cPtr_gtlInputStatementInstruction::description (C_String & ioString,
                                                     const int32_t inIndentation) const {
  ioString << "[@gtlInputStatementInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_formalArguments.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlInputStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlInputStatementInstruction (mAttribute_where, mAttribute_signature, mAttribute_formalArguments COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @gtlInputStatementInstruction type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlInputStatementInstruction ("gtlInputStatementInstruction",
                                                     & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlInputStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInputStatementInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlInputStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlInputStatementInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInputStatementInstruction GALGAS_gtlInputStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlInputStatementInstruction result ;
  const GALGAS_gtlInputStatementInstruction * p = (const GALGAS_gtlInputStatementInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlInputStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlInputStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLetUnconstructedInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetUnconstructedInstruction * p = (const cPtr_gtlLetUnconstructedInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetUnconstructedInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lValue.objectCompare (p->mAttribute_lValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlLetUnconstructedInstruction::objectCompare (const GALGAS_gtlLetUnconstructedInstruction & inOperand) const {
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

GALGAS_gtlLetUnconstructedInstruction::GALGAS_gtlLetUnconstructedInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetUnconstructedInstruction GALGAS_gtlLetUnconstructedInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlLetUnconstructedInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                                 GALGAS_string::constructor_default (HERE),
                                                                 GALGAS_gtlVarPath::constructor_emptyList (HERE)
                                                                 COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetUnconstructedInstruction::GALGAS_gtlLetUnconstructedInstruction (const cPtr_gtlLetUnconstructedInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetUnconstructedInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetUnconstructedInstruction GALGAS_gtlLetUnconstructedInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                              const GALGAS_string & inAttribute_signature,
                                                                                              const GALGAS_gtlVarPath & inAttribute_lValue
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetUnconstructedInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_lValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLetUnconstructedInstruction (inAttribute_where, inAttribute_signature, inAttribute_lValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlLetUnconstructedInstruction::getter_lValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlLetUnconstructedInstruction * p = (const cPtr_gtlLetUnconstructedInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLetUnconstructedInstruction) ;
    result = p->mAttribute_lValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath cPtr_gtlLetUnconstructedInstruction::getter_lValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                               Pointer class for @gtlLetUnconstructedInstruction class                               *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLetUnconstructedInstruction::cPtr_gtlLetUnconstructedInstruction (const GALGAS_location & in_where,
                                                                          const GALGAS_string & in_signature,
                                                                          const GALGAS_gtlVarPath & in_lValue
                                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_lValue (in_lValue) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLetUnconstructedInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetUnconstructedInstruction ;
}

void cPtr_gtlLetUnconstructedInstruction::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "[@gtlLetUnconstructedInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlLetUnconstructedInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLetUnconstructedInstruction (mAttribute_where, mAttribute_signature, mAttribute_lValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @gtlLetUnconstructedInstruction type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLetUnconstructedInstruction ("gtlLetUnconstructedInstruction",
                                                       & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLetUnconstructedInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetUnconstructedInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLetUnconstructedInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetUnconstructedInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetUnconstructedInstruction GALGAS_gtlLetUnconstructedInstruction::extractObject (const GALGAS_object & inObject,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetUnconstructedInstruction result ;
  const GALGAS_gtlLetUnconstructedInstruction * p = (const GALGAS_gtlLetUnconstructedInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLetUnconstructedInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetUnconstructedInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
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

typeComparisonResult cPtr_gtlLetAndInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetAndInstruction * p = (const cPtr_gtlLetAndInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetAndInstruction) ;
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


typeComparisonResult GALGAS_gtlLetAndInstruction::objectCompare (const GALGAS_gtlLetAndInstruction & inOperand) const {
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

GALGAS_gtlLetAndInstruction::GALGAS_gtlLetAndInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetAndInstruction::GALGAS_gtlLetAndInstruction (const cPtr_gtlLetAndInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetAndInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetAndInstruction GALGAS_gtlLetAndInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                          const GALGAS_string & inAttribute_signature,
                                                                          const GALGAS_gtlVarPath & inAttribute_lValue,
                                                                          const GALGAS_gtlExpression & inAttribute_rValue
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetAndInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_lValue.isValid () && inAttribute_rValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLetAndInstruction (inAttribute_where, inAttribute_signature, inAttribute_lValue, inAttribute_rValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @gtlLetAndInstruction class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLetAndInstruction::cPtr_gtlLetAndInstruction (const GALGAS_location & in_where,
                                                      const GALGAS_string & in_signature,
                                                      const GALGAS_gtlVarPath & in_lValue,
                                                      const GALGAS_gtlExpression & in_rValue
                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLetAndInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetAndInstruction ;
}

void cPtr_gtlLetAndInstruction::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@gtlLetAndInstruction:" ;
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

acPtr_class * cPtr_gtlLetAndInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLetAndInstruction (mAttribute_where, mAttribute_signature, mAttribute_lValue, mAttribute_rValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @gtlLetAndInstruction type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLetAndInstruction ("gtlLetAndInstruction",
                                             & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLetAndInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetAndInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLetAndInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetAndInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetAndInstruction GALGAS_gtlLetAndInstruction::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetAndInstruction result ;
  const GALGAS_gtlLetAndInstruction * p = (const GALGAS_gtlLetAndInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLetAndInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetAndInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
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

typeComparisonResult cPtr_gtlLetOrInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetOrInstruction * p = (const cPtr_gtlLetOrInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetOrInstruction) ;
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


typeComparisonResult GALGAS_gtlLetOrInstruction::objectCompare (const GALGAS_gtlLetOrInstruction & inOperand) const {
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

GALGAS_gtlLetOrInstruction::GALGAS_gtlLetOrInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetOrInstruction::GALGAS_gtlLetOrInstruction (const cPtr_gtlLetOrInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetOrInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetOrInstruction GALGAS_gtlLetOrInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                        const GALGAS_string & inAttribute_signature,
                                                                        const GALGAS_gtlVarPath & inAttribute_lValue,
                                                                        const GALGAS_gtlExpression & inAttribute_rValue
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetOrInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_lValue.isValid () && inAttribute_rValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLetOrInstruction (inAttribute_where, inAttribute_signature, inAttribute_lValue, inAttribute_rValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @gtlLetOrInstruction class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLetOrInstruction::cPtr_gtlLetOrInstruction (const GALGAS_location & in_where,
                                                    const GALGAS_string & in_signature,
                                                    const GALGAS_gtlVarPath & in_lValue,
                                                    const GALGAS_gtlExpression & in_rValue
                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLetOrInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetOrInstruction ;
}

void cPtr_gtlLetOrInstruction::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@gtlLetOrInstruction:" ;
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

acPtr_class * cPtr_gtlLetOrInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLetOrInstruction (mAttribute_where, mAttribute_signature, mAttribute_lValue, mAttribute_rValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlLetOrInstruction type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLetOrInstruction ("gtlLetOrInstruction",
                                            & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLetOrInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetOrInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLetOrInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetOrInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetOrInstruction GALGAS_gtlLetOrInstruction::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetOrInstruction result ;
  const GALGAS_gtlLetOrInstruction * p = (const GALGAS_gtlLetOrInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLetOrInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetOrInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLetShiftLeftInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetShiftLeftInstruction * p = (const cPtr_gtlLetShiftLeftInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetShiftLeftInstruction) ;
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


typeComparisonResult GALGAS_gtlLetShiftLeftInstruction::objectCompare (const GALGAS_gtlLetShiftLeftInstruction & inOperand) const {
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

GALGAS_gtlLetShiftLeftInstruction::GALGAS_gtlLetShiftLeftInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetShiftLeftInstruction::GALGAS_gtlLetShiftLeftInstruction (const cPtr_gtlLetShiftLeftInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetShiftLeftInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetShiftLeftInstruction GALGAS_gtlLetShiftLeftInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                      const GALGAS_string & inAttribute_signature,
                                                                                      const GALGAS_gtlVarPath & inAttribute_lValue,
                                                                                      const GALGAS_gtlExpression & inAttribute_rValue
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetShiftLeftInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_lValue.isValid () && inAttribute_rValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLetShiftLeftInstruction (inAttribute_where, inAttribute_signature, inAttribute_lValue, inAttribute_rValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @gtlLetShiftLeftInstruction class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLetShiftLeftInstruction::cPtr_gtlLetShiftLeftInstruction (const GALGAS_location & in_where,
                                                                  const GALGAS_string & in_signature,
                                                                  const GALGAS_gtlVarPath & in_lValue,
                                                                  const GALGAS_gtlExpression & in_rValue
                                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLetShiftLeftInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetShiftLeftInstruction ;
}

void cPtr_gtlLetShiftLeftInstruction::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@gtlLetShiftLeftInstruction:" ;
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

acPtr_class * cPtr_gtlLetShiftLeftInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLetShiftLeftInstruction (mAttribute_where, mAttribute_signature, mAttribute_lValue, mAttribute_rValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlLetShiftLeftInstruction type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLetShiftLeftInstruction ("gtlLetShiftLeftInstruction",
                                                   & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLetShiftLeftInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetShiftLeftInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLetShiftLeftInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetShiftLeftInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetShiftLeftInstruction GALGAS_gtlLetShiftLeftInstruction::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetShiftLeftInstruction result ;
  const GALGAS_gtlLetShiftLeftInstruction * p = (const GALGAS_gtlLetShiftLeftInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLetShiftLeftInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetShiftLeftInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLetShiftRightInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetShiftRightInstruction * p = (const cPtr_gtlLetShiftRightInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetShiftRightInstruction) ;
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


typeComparisonResult GALGAS_gtlLetShiftRightInstruction::objectCompare (const GALGAS_gtlLetShiftRightInstruction & inOperand) const {
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

GALGAS_gtlLetShiftRightInstruction::GALGAS_gtlLetShiftRightInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetShiftRightInstruction::GALGAS_gtlLetShiftRightInstruction (const cPtr_gtlLetShiftRightInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetShiftRightInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetShiftRightInstruction GALGAS_gtlLetShiftRightInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                        const GALGAS_string & inAttribute_signature,
                                                                                        const GALGAS_gtlVarPath & inAttribute_lValue,
                                                                                        const GALGAS_gtlExpression & inAttribute_rValue
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetShiftRightInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_lValue.isValid () && inAttribute_rValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLetShiftRightInstruction (inAttribute_where, inAttribute_signature, inAttribute_lValue, inAttribute_rValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                Pointer class for @gtlLetShiftRightInstruction class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLetShiftRightInstruction::cPtr_gtlLetShiftRightInstruction (const GALGAS_location & in_where,
                                                                    const GALGAS_string & in_signature,
                                                                    const GALGAS_gtlVarPath & in_lValue,
                                                                    const GALGAS_gtlExpression & in_rValue
                                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLetShiftRightInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetShiftRightInstruction ;
}

void cPtr_gtlLetShiftRightInstruction::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@gtlLetShiftRightInstruction:" ;
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

acPtr_class * cPtr_gtlLetShiftRightInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLetShiftRightInstruction (mAttribute_where, mAttribute_signature, mAttribute_lValue, mAttribute_rValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlLetShiftRightInstruction type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLetShiftRightInstruction ("gtlLetShiftRightInstruction",
                                                    & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLetShiftRightInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetShiftRightInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLetShiftRightInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetShiftRightInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetShiftRightInstruction GALGAS_gtlLetShiftRightInstruction::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetShiftRightInstruction result ;
  const GALGAS_gtlLetShiftRightInstruction * p = (const GALGAS_gtlLetShiftRightInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLetShiftRightInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetShiftRightInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
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

typeComparisonResult cPtr_gtlLetXorInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetXorInstruction * p = (const cPtr_gtlLetXorInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetXorInstruction) ;
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


typeComparisonResult GALGAS_gtlLetXorInstruction::objectCompare (const GALGAS_gtlLetXorInstruction & inOperand) const {
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

GALGAS_gtlLetXorInstruction::GALGAS_gtlLetXorInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetXorInstruction::GALGAS_gtlLetXorInstruction (const cPtr_gtlLetXorInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetXorInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetXorInstruction GALGAS_gtlLetXorInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                          const GALGAS_string & inAttribute_signature,
                                                                          const GALGAS_gtlVarPath & inAttribute_lValue,
                                                                          const GALGAS_gtlExpression & inAttribute_rValue
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetXorInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_lValue.isValid () && inAttribute_rValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLetXorInstruction (inAttribute_where, inAttribute_signature, inAttribute_lValue, inAttribute_rValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @gtlLetXorInstruction class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLetXorInstruction::cPtr_gtlLetXorInstruction (const GALGAS_location & in_where,
                                                      const GALGAS_string & in_signature,
                                                      const GALGAS_gtlVarPath & in_lValue,
                                                      const GALGAS_gtlExpression & in_rValue
                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLetXorInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetXorInstruction ;
}

void cPtr_gtlLetXorInstruction::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@gtlLetXorInstruction:" ;
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

acPtr_class * cPtr_gtlLetXorInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLetXorInstruction (mAttribute_where, mAttribute_signature, mAttribute_lValue, mAttribute_rValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @gtlLetXorInstruction type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLetXorInstruction ("gtlLetXorInstruction",
                                             & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLetXorInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetXorInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLetXorInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetXorInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetXorInstruction GALGAS_gtlLetXorInstruction::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetXorInstruction result ;
  const GALGAS_gtlLetXorInstruction * p = (const GALGAS_gtlLetXorInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLetXorInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetXorInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlUnletInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlUnletInstruction * p = (const cPtr_gtlUnletInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlUnletInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lValue.objectCompare (p->mAttribute_lValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlUnletInstruction::objectCompare (const GALGAS_gtlUnletInstruction & inOperand) const {
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

GALGAS_gtlUnletInstruction::GALGAS_gtlUnletInstruction (void) :
GALGAS_gtlLetUnconstructedInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlUnletInstruction GALGAS_gtlUnletInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlUnletInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                      GALGAS_string::constructor_default (HERE),
                                                      GALGAS_gtlVarPath::constructor_emptyList (HERE)
                                                      COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlUnletInstruction::GALGAS_gtlUnletInstruction (const cPtr_gtlUnletInstruction * inSourcePtr) :
GALGAS_gtlLetUnconstructedInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlUnletInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlUnletInstruction GALGAS_gtlUnletInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                        const GALGAS_string & inAttribute_signature,
                                                                        const GALGAS_gtlVarPath & inAttribute_lValue
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlUnletInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_lValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlUnletInstruction (inAttribute_where, inAttribute_signature, inAttribute_lValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @gtlUnletInstruction class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlUnletInstruction::cPtr_gtlUnletInstruction (const GALGAS_location & in_where,
                                                    const GALGAS_string & in_signature,
                                                    const GALGAS_gtlVarPath & in_lValue
                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlLetUnconstructedInstruction (in_where, in_signature, in_lValue COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlUnletInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlUnletInstruction ;
}

void cPtr_gtlUnletInstruction::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@gtlUnletInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlUnletInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlUnletInstruction (mAttribute_where, mAttribute_signature, mAttribute_lValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlUnletInstruction type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlUnletInstruction ("gtlUnletInstruction",
                                            & kTypeDescriptor_GALGAS_gtlLetUnconstructedInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlUnletInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlUnletInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlUnletInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlUnletInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlUnletInstruction GALGAS_gtlUnletInstruction::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlUnletInstruction result ;
  const GALGAS_gtlUnletInstruction * p = (const GALGAS_gtlUnletInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlUnletInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlUnletInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLibrariesInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLibrariesInstruction * p = (const cPtr_gtlLibrariesInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLibrariesInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlLibrariesInstruction::objectCompare (const GALGAS_gtlLibrariesInstruction & inOperand) const {
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

GALGAS_gtlLibrariesInstruction::GALGAS_gtlLibrariesInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLibrariesInstruction GALGAS_gtlLibrariesInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlLibrariesInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                          GALGAS_string::constructor_default (HERE)
                                                          COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLibrariesInstruction::GALGAS_gtlLibrariesInstruction (const cPtr_gtlLibrariesInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLibrariesInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLibrariesInstruction GALGAS_gtlLibrariesInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                const GALGAS_string & inAttribute_signature
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlLibrariesInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLibrariesInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @gtlLibrariesInstruction class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLibrariesInstruction::cPtr_gtlLibrariesInstruction (const GALGAS_location & in_where,
                                                            const GALGAS_string & in_signature
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLibrariesInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLibrariesInstruction ;
}

void cPtr_gtlLibrariesInstruction::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlLibrariesInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlLibrariesInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLibrariesInstruction (mAttribute_where, mAttribute_signature COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlLibrariesInstruction type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLibrariesInstruction ("gtlLibrariesInstruction",
                                                & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLibrariesInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLibrariesInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLibrariesInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLibrariesInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLibrariesInstruction GALGAS_gtlLibrariesInstruction::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlLibrariesInstruction result ;
  const GALGAS_gtlLibrariesInstruction * p = (const GALGAS_gtlLibrariesInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLibrariesInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLibrariesInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLoopStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_identifier.objectCompare (p->mAttribute_identifier) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_start.objectCompare (p->mAttribute_start) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_stop.objectCompare (p->mAttribute_stop) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_step.objectCompare (p->mAttribute_step) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_upDown.objectCompare (p->mAttribute_upDown) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_beforeList.objectCompare (p->mAttribute_beforeList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_betweenList.objectCompare (p->mAttribute_betweenList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_afterList.objectCompare (p->mAttribute_afterList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_doList.objectCompare (p->mAttribute_doList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlLoopStatementInstruction::objectCompare (const GALGAS_gtlLoopStatementInstruction & inOperand) const {
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

GALGAS_gtlLoopStatementInstruction::GALGAS_gtlLoopStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLoopStatementInstruction::GALGAS_gtlLoopStatementInstruction (const cPtr_gtlLoopStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLoopStatementInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLoopStatementInstruction GALGAS_gtlLoopStatementInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                        const GALGAS_string & inAttribute_signature,
                                                                                        const GALGAS_lstring & inAttribute_identifier,
                                                                                        const GALGAS_gtlExpression & inAttribute_start,
                                                                                        const GALGAS_gtlExpression & inAttribute_stop,
                                                                                        const GALGAS_gtlExpression & inAttribute_step,
                                                                                        const GALGAS_sint_36__34_ & inAttribute_upDown,
                                                                                        const GALGAS_gtlInstructionList & inAttribute_beforeList,
                                                                                        const GALGAS_gtlInstructionList & inAttribute_betweenList,
                                                                                        const GALGAS_gtlInstructionList & inAttribute_afterList,
                                                                                        const GALGAS_gtlInstructionList & inAttribute_doList
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlLoopStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_identifier.isValid () && inAttribute_start.isValid () && inAttribute_stop.isValid () && inAttribute_step.isValid () && inAttribute_upDown.isValid () && inAttribute_beforeList.isValid () && inAttribute_betweenList.isValid () && inAttribute_afterList.isValid () && inAttribute_doList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLoopStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_identifier, inAttribute_start, inAttribute_stop, inAttribute_step, inAttribute_upDown, inAttribute_beforeList, inAttribute_betweenList, inAttribute_afterList, inAttribute_doList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlLoopStatementInstruction::getter_identifier (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    result = p->mAttribute_identifier ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlLoopStatementInstruction::getter_identifier (UNUSED_LOCATION_ARGS) const {
  return mAttribute_identifier ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlLoopStatementInstruction::getter_start (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    result = p->mAttribute_start ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlLoopStatementInstruction::getter_start (UNUSED_LOCATION_ARGS) const {
  return mAttribute_start ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlLoopStatementInstruction::getter_stop (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    result = p->mAttribute_stop ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlLoopStatementInstruction::getter_stop (UNUSED_LOCATION_ARGS) const {
  return mAttribute_stop ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlLoopStatementInstruction::getter_step (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    result = p->mAttribute_step ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlLoopStatementInstruction::getter_step (UNUSED_LOCATION_ARGS) const {
  return mAttribute_step ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_gtlLoopStatementInstruction::getter_upDown (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    result = p->mAttribute_upDown ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ cPtr_gtlLoopStatementInstruction::getter_upDown (UNUSED_LOCATION_ARGS) const {
  return mAttribute_upDown ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlLoopStatementInstruction::getter_beforeList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    result = p->mAttribute_beforeList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlLoopStatementInstruction::getter_beforeList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_beforeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlLoopStatementInstruction::getter_betweenList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    result = p->mAttribute_betweenList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlLoopStatementInstruction::getter_betweenList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_betweenList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlLoopStatementInstruction::getter_afterList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    result = p->mAttribute_afterList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlLoopStatementInstruction::getter_afterList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_afterList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlLoopStatementInstruction::getter_doList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    result = p->mAttribute_doList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlLoopStatementInstruction::getter_doList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_doList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                Pointer class for @gtlLoopStatementInstruction class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLoopStatementInstruction::cPtr_gtlLoopStatementInstruction (const GALGAS_location & in_where,
                                                                    const GALGAS_string & in_signature,
                                                                    const GALGAS_lstring & in_identifier,
                                                                    const GALGAS_gtlExpression & in_start,
                                                                    const GALGAS_gtlExpression & in_stop,
                                                                    const GALGAS_gtlExpression & in_step,
                                                                    const GALGAS_sint_36__34_ & in_upDown,
                                                                    const GALGAS_gtlInstructionList & in_beforeList,
                                                                    const GALGAS_gtlInstructionList & in_betweenList,
                                                                    const GALGAS_gtlInstructionList & in_afterList,
                                                                    const GALGAS_gtlInstructionList & in_doList
                                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_identifier (in_identifier),
mAttribute_start (in_start),
mAttribute_stop (in_stop),
mAttribute_step (in_step),
mAttribute_upDown (in_upDown),
mAttribute_beforeList (in_beforeList),
mAttribute_betweenList (in_betweenList),
mAttribute_afterList (in_afterList),
mAttribute_doList (in_doList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLoopStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLoopStatementInstruction ;
}

void cPtr_gtlLoopStatementInstruction::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@gtlLoopStatementInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_identifier.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_start.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_stop.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_step.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_upDown.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_beforeList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_betweenList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_afterList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_doList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlLoopStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLoopStatementInstruction (mAttribute_where, mAttribute_signature, mAttribute_identifier, mAttribute_start, mAttribute_stop, mAttribute_step, mAttribute_upDown, mAttribute_beforeList, mAttribute_betweenList, mAttribute_afterList, mAttribute_doList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlLoopStatementInstruction type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLoopStatementInstruction ("gtlLoopStatementInstruction",
                                                    & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLoopStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLoopStatementInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLoopStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLoopStatementInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLoopStatementInstruction GALGAS_gtlLoopStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlLoopStatementInstruction result ;
  const GALGAS_gtlLoopStatementInstruction * p = (const GALGAS_gtlLoopStatementInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLoopStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLoopStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlPrintStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlPrintStatementInstruction * p = (const cPtr_gtlPrintStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlPrintStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_carriageReturn.objectCompare (p->mAttribute_carriageReturn) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_messageToPrint.objectCompare (p->mAttribute_messageToPrint) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlPrintStatementInstruction::objectCompare (const GALGAS_gtlPrintStatementInstruction & inOperand) const {
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

GALGAS_gtlPrintStatementInstruction::GALGAS_gtlPrintStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlPrintStatementInstruction::GALGAS_gtlPrintStatementInstruction (const cPtr_gtlPrintStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlPrintStatementInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlPrintStatementInstruction GALGAS_gtlPrintStatementInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                          const GALGAS_string & inAttribute_signature,
                                                                                          const GALGAS_bool & inAttribute_carriageReturn,
                                                                                          const GALGAS_gtlExpression & inAttribute_messageToPrint
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlPrintStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_carriageReturn.isValid () && inAttribute_messageToPrint.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlPrintStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_carriageReturn, inAttribute_messageToPrint COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_gtlPrintStatementInstruction::getter_carriageReturn (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlPrintStatementInstruction * p = (const cPtr_gtlPrintStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlPrintStatementInstruction) ;
    result = p->mAttribute_carriageReturn ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_gtlPrintStatementInstruction::getter_carriageReturn (UNUSED_LOCATION_ARGS) const {
  return mAttribute_carriageReturn ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlPrintStatementInstruction::getter_messageToPrint (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlPrintStatementInstruction * p = (const cPtr_gtlPrintStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlPrintStatementInstruction) ;
    result = p->mAttribute_messageToPrint ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlPrintStatementInstruction::getter_messageToPrint (UNUSED_LOCATION_ARGS) const {
  return mAttribute_messageToPrint ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                Pointer class for @gtlPrintStatementInstruction class                                *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlPrintStatementInstruction::cPtr_gtlPrintStatementInstruction (const GALGAS_location & in_where,
                                                                      const GALGAS_string & in_signature,
                                                                      const GALGAS_bool & in_carriageReturn,
                                                                      const GALGAS_gtlExpression & in_messageToPrint
                                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_carriageReturn (in_carriageReturn),
mAttribute_messageToPrint (in_messageToPrint) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlPrintStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlPrintStatementInstruction ;
}

void cPtr_gtlPrintStatementInstruction::description (C_String & ioString,
                                                     const int32_t inIndentation) const {
  ioString << "[@gtlPrintStatementInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_carriageReturn.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_messageToPrint.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlPrintStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlPrintStatementInstruction (mAttribute_where, mAttribute_signature, mAttribute_carriageReturn, mAttribute_messageToPrint COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @gtlPrintStatementInstruction type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlPrintStatementInstruction ("gtlPrintStatementInstruction",
                                                     & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlPrintStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlPrintStatementInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlPrintStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlPrintStatementInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlPrintStatementInstruction GALGAS_gtlPrintStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlPrintStatementInstruction result ;
  const GALGAS_gtlPrintStatementInstruction * p = (const GALGAS_gtlPrintStatementInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlPrintStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlPrintStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlRepeatStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlRepeatStatementInstruction * p = (const cPtr_gtlRepeatStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlRepeatStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_limit.objectCompare (p->mAttribute_limit) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_condition.objectCompare (p->mAttribute_condition) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_continueList.objectCompare (p->mAttribute_continueList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_doList.objectCompare (p->mAttribute_doList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlRepeatStatementInstruction::objectCompare (const GALGAS_gtlRepeatStatementInstruction & inOperand) const {
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

GALGAS_gtlRepeatStatementInstruction::GALGAS_gtlRepeatStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlRepeatStatementInstruction::GALGAS_gtlRepeatStatementInstruction (const cPtr_gtlRepeatStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlRepeatStatementInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlRepeatStatementInstruction GALGAS_gtlRepeatStatementInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                            const GALGAS_string & inAttribute_signature,
                                                                                            const GALGAS_gtlExpression & inAttribute_limit,
                                                                                            const GALGAS_gtlExpression & inAttribute_condition,
                                                                                            const GALGAS_gtlInstructionList & inAttribute_continueList,
                                                                                            const GALGAS_gtlInstructionList & inAttribute_doList
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlRepeatStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_limit.isValid () && inAttribute_condition.isValid () && inAttribute_continueList.isValid () && inAttribute_doList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlRepeatStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_limit, inAttribute_condition, inAttribute_continueList, inAttribute_doList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlRepeatStatementInstruction::getter_limit (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlRepeatStatementInstruction * p = (const cPtr_gtlRepeatStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlRepeatStatementInstruction) ;
    result = p->mAttribute_limit ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlRepeatStatementInstruction::getter_limit (UNUSED_LOCATION_ARGS) const {
  return mAttribute_limit ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlRepeatStatementInstruction::getter_condition (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlRepeatStatementInstruction * p = (const cPtr_gtlRepeatStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlRepeatStatementInstruction) ;
    result = p->mAttribute_condition ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlRepeatStatementInstruction::getter_condition (UNUSED_LOCATION_ARGS) const {
  return mAttribute_condition ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlRepeatStatementInstruction::getter_continueList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlRepeatStatementInstruction * p = (const cPtr_gtlRepeatStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlRepeatStatementInstruction) ;
    result = p->mAttribute_continueList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlRepeatStatementInstruction::getter_continueList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_continueList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlRepeatStatementInstruction::getter_doList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlRepeatStatementInstruction * p = (const cPtr_gtlRepeatStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlRepeatStatementInstruction) ;
    result = p->mAttribute_doList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlRepeatStatementInstruction::getter_doList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_doList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                               Pointer class for @gtlRepeatStatementInstruction class                                *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlRepeatStatementInstruction::cPtr_gtlRepeatStatementInstruction (const GALGAS_location & in_where,
                                                                        const GALGAS_string & in_signature,
                                                                        const GALGAS_gtlExpression & in_limit,
                                                                        const GALGAS_gtlExpression & in_condition,
                                                                        const GALGAS_gtlInstructionList & in_continueList,
                                                                        const GALGAS_gtlInstructionList & in_doList
                                                                        COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_limit (in_limit),
mAttribute_condition (in_condition),
mAttribute_continueList (in_continueList),
mAttribute_doList (in_doList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlRepeatStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlRepeatStatementInstruction ;
}

void cPtr_gtlRepeatStatementInstruction::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "[@gtlRepeatStatementInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_limit.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_condition.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_continueList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_doList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlRepeatStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlRepeatStatementInstruction (mAttribute_where, mAttribute_signature, mAttribute_limit, mAttribute_condition, mAttribute_continueList, mAttribute_doList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @gtlRepeatStatementInstruction type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlRepeatStatementInstruction ("gtlRepeatStatementInstruction",
                                                      & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlRepeatStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlRepeatStatementInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlRepeatStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlRepeatStatementInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlRepeatStatementInstruction GALGAS_gtlRepeatStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlRepeatStatementInstruction result ;
  const GALGAS_gtlRepeatStatementInstruction * p = (const GALGAS_gtlRepeatStatementInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlRepeatStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlRepeatStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlSetterCallInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlSetterCallInstruction * p = (const cPtr_gtlSetterCallInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlSetterCallInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_target.objectCompare (p->mAttribute_target) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_setterName.objectCompare (p->mAttribute_setterName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_arguments.objectCompare (p->mAttribute_arguments) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlSetterCallInstruction::objectCompare (const GALGAS_gtlSetterCallInstruction & inOperand) const {
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

GALGAS_gtlSetterCallInstruction::GALGAS_gtlSetterCallInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterCallInstruction GALGAS_gtlSetterCallInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlSetterCallInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_string::constructor_default (HERE),
                                                           GALGAS_gtlVarPath::constructor_emptyList (HERE),
                                                           GALGAS_lstring::constructor_default (HERE),
                                                           GALGAS_gtlExpressionList::constructor_emptyList (HERE)
                                                           COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterCallInstruction::GALGAS_gtlSetterCallInstruction (const cPtr_gtlSetterCallInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlSetterCallInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterCallInstruction GALGAS_gtlSetterCallInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                  const GALGAS_string & inAttribute_signature,
                                                                                  const GALGAS_gtlVarPath & inAttribute_target,
                                                                                  const GALGAS_lstring & inAttribute_setterName,
                                                                                  const GALGAS_gtlExpressionList & inAttribute_arguments
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlSetterCallInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_target.isValid () && inAttribute_setterName.isValid () && inAttribute_arguments.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlSetterCallInstruction (inAttribute_where, inAttribute_signature, inAttribute_target, inAttribute_setterName, inAttribute_arguments COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlSetterCallInstruction::getter_target (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlSetterCallInstruction * p = (const cPtr_gtlSetterCallInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSetterCallInstruction) ;
    result = p->mAttribute_target ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath cPtr_gtlSetterCallInstruction::getter_target (UNUSED_LOCATION_ARGS) const {
  return mAttribute_target ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlSetterCallInstruction::getter_setterName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlSetterCallInstruction * p = (const cPtr_gtlSetterCallInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSetterCallInstruction) ;
    result = p->mAttribute_setterName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlSetterCallInstruction::getter_setterName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_setterName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlSetterCallInstruction::getter_arguments (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlSetterCallInstruction * p = (const cPtr_gtlSetterCallInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSetterCallInstruction) ;
    result = p->mAttribute_arguments ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList cPtr_gtlSetterCallInstruction::getter_arguments (UNUSED_LOCATION_ARGS) const {
  return mAttribute_arguments ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @gtlSetterCallInstruction class                                  *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlSetterCallInstruction::cPtr_gtlSetterCallInstruction (const GALGAS_location & in_where,
                                                              const GALGAS_string & in_signature,
                                                              const GALGAS_gtlVarPath & in_target,
                                                              const GALGAS_lstring & in_setterName,
                                                              const GALGAS_gtlExpressionList & in_arguments
                                                              COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_target (in_target),
mAttribute_setterName (in_setterName),
mAttribute_arguments (in_arguments) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlSetterCallInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSetterCallInstruction ;
}

void cPtr_gtlSetterCallInstruction::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@gtlSetterCallInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_target.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_setterName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_arguments.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlSetterCallInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlSetterCallInstruction (mAttribute_where, mAttribute_signature, mAttribute_target, mAttribute_setterName, mAttribute_arguments COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlSetterCallInstruction type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlSetterCallInstruction ("gtlSetterCallInstruction",
                                                 & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlSetterCallInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSetterCallInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlSetterCallInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlSetterCallInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterCallInstruction GALGAS_gtlSetterCallInstruction::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlSetterCallInstruction result ;
  const GALGAS_gtlSetterCallInstruction * p = (const GALGAS_gtlSetterCallInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlSetterCallInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlSetterCallInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlStepInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlStepInstruction * p = (const cPtr_gtlStepInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlStepInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlStepInstruction::GALGAS_gtlStepInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlStepInstruction GALGAS_gtlStepInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlStepInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                     GALGAS_string::constructor_default (HERE)
                                                     COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlStepInstruction::GALGAS_gtlStepInstruction (const cPtr_gtlStepInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlStepInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlStepInstruction GALGAS_gtlStepInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                      const GALGAS_string & inAttribute_signature
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlStepInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlStepInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @gtlStepInstruction class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlStepInstruction::cPtr_gtlStepInstruction (const GALGAS_location & in_where,
                                                  const GALGAS_string & in_signature
                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlStepInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlStepInstruction ;
}

void cPtr_gtlStepInstruction::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@gtlStepInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlStepInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlStepInstruction (mAttribute_where, mAttribute_signature COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlStepInstruction type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlStepInstruction ("gtlStepInstruction",
                                           & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlStepInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlStepInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlStepInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlStepInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlStepInstruction GALGAS_gtlStepInstruction::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlStepInstruction result ;
  const GALGAS_gtlStepInstruction * p = (const GALGAS_gtlStepInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlStepInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlStepInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlTabStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlTabStatementInstruction * p = (const cPtr_gtlTabStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlTabStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_tabValue.objectCompare (p->mAttribute_tabValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlTabStatementInstruction::objectCompare (const GALGAS_gtlTabStatementInstruction & inOperand) const {
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

GALGAS_gtlTabStatementInstruction::GALGAS_gtlTabStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTabStatementInstruction::GALGAS_gtlTabStatementInstruction (const cPtr_gtlTabStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlTabStatementInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTabStatementInstruction GALGAS_gtlTabStatementInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                      const GALGAS_string & inAttribute_signature,
                                                                                      const GALGAS_gtlExpression & inAttribute_tabValue
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlTabStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_tabValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlTabStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_tabValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlTabStatementInstruction::getter_tabValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlTabStatementInstruction * p = (const cPtr_gtlTabStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTabStatementInstruction) ;
    result = p->mAttribute_tabValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlTabStatementInstruction::getter_tabValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_tabValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @gtlTabStatementInstruction class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlTabStatementInstruction::cPtr_gtlTabStatementInstruction (const GALGAS_location & in_where,
                                                                  const GALGAS_string & in_signature,
                                                                  const GALGAS_gtlExpression & in_tabValue
                                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_tabValue (in_tabValue) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlTabStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTabStatementInstruction ;
}

void cPtr_gtlTabStatementInstruction::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@gtlTabStatementInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_tabValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlTabStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlTabStatementInstruction (mAttribute_where, mAttribute_signature, mAttribute_tabValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlTabStatementInstruction type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTabStatementInstruction ("gtlTabStatementInstruction",
                                                   & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlTabStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTabStatementInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlTabStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTabStatementInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTabStatementInstruction GALGAS_gtlTabStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlTabStatementInstruction result ;
  const GALGAS_gtlTabStatementInstruction * p = (const GALGAS_gtlTabStatementInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlTabStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTabStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlTemplateInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlTemplateInstruction * p = (const cPtr_gtlTemplateInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_prefix.objectCompare (p->mAttribute_prefix) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_fileName.objectCompare (p->mAttribute_fileName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_ifExists.objectCompare (p->mAttribute_ifExists) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_isGlobal.objectCompare (p->mAttribute_isGlobal) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_arguments.objectCompare (p->mAttribute_arguments) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_instructionsIfNotFound.objectCompare (p->mAttribute_instructionsIfNotFound) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlTemplateInstruction::objectCompare (const GALGAS_gtlTemplateInstruction & inOperand) const {
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

GALGAS_gtlTemplateInstruction::GALGAS_gtlTemplateInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateInstruction::GALGAS_gtlTemplateInstruction (const cPtr_gtlTemplateInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlTemplateInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateInstruction GALGAS_gtlTemplateInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                              const GALGAS_string & inAttribute_signature,
                                                                              const GALGAS_lstring & inAttribute_prefix,
                                                                              const GALGAS_gtlExpression & inAttribute_fileName,
                                                                              const GALGAS_bool & inAttribute_ifExists,
                                                                              const GALGAS_bool & inAttribute_isGlobal,
                                                                              const GALGAS_gtlExpressionList & inAttribute_arguments,
                                                                              const GALGAS_gtlInstructionList & inAttribute_instructionsIfNotFound
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplateInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_prefix.isValid () && inAttribute_fileName.isValid () && inAttribute_ifExists.isValid () && inAttribute_isGlobal.isValid () && inAttribute_arguments.isValid () && inAttribute_instructionsIfNotFound.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlTemplateInstruction (inAttribute_where, inAttribute_signature, inAttribute_prefix, inAttribute_fileName, inAttribute_ifExists, inAttribute_isGlobal, inAttribute_arguments, inAttribute_instructionsIfNotFound COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlTemplateInstruction::getter_prefix (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlTemplateInstruction * p = (const cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    result = p->mAttribute_prefix ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlTemplateInstruction::getter_prefix (UNUSED_LOCATION_ARGS) const {
  return mAttribute_prefix ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlTemplateInstruction::getter_fileName (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlTemplateInstruction * p = (const cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    result = p->mAttribute_fileName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlTemplateInstruction::getter_fileName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_fileName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_gtlTemplateInstruction::getter_ifExists (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlTemplateInstruction * p = (const cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    result = p->mAttribute_ifExists ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_gtlTemplateInstruction::getter_ifExists (UNUSED_LOCATION_ARGS) const {
  return mAttribute_ifExists ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_gtlTemplateInstruction::getter_isGlobal (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlTemplateInstruction * p = (const cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    result = p->mAttribute_isGlobal ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_gtlTemplateInstruction::getter_isGlobal (UNUSED_LOCATION_ARGS) const {
  return mAttribute_isGlobal ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlTemplateInstruction::getter_arguments (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlTemplateInstruction * p = (const cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    result = p->mAttribute_arguments ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList cPtr_gtlTemplateInstruction::getter_arguments (UNUSED_LOCATION_ARGS) const {
  return mAttribute_arguments ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlTemplateInstruction::getter_instructionsIfNotFound (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlTemplateInstruction * p = (const cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    result = p->mAttribute_instructionsIfNotFound ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlTemplateInstruction::getter_instructionsIfNotFound (UNUSED_LOCATION_ARGS) const {
  return mAttribute_instructionsIfNotFound ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @gtlTemplateInstruction class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlTemplateInstruction::cPtr_gtlTemplateInstruction (const GALGAS_location & in_where,
                                                          const GALGAS_string & in_signature,
                                                          const GALGAS_lstring & in_prefix,
                                                          const GALGAS_gtlExpression & in_fileName,
                                                          const GALGAS_bool & in_ifExists,
                                                          const GALGAS_bool & in_isGlobal,
                                                          const GALGAS_gtlExpressionList & in_arguments,
                                                          const GALGAS_gtlInstructionList & in_instructionsIfNotFound
                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_prefix (in_prefix),
mAttribute_fileName (in_fileName),
mAttribute_ifExists (in_ifExists),
mAttribute_isGlobal (in_isGlobal),
mAttribute_arguments (in_arguments),
mAttribute_instructionsIfNotFound (in_instructionsIfNotFound) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlTemplateInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplateInstruction ;
}

void cPtr_gtlTemplateInstruction::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@gtlTemplateInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_prefix.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_fileName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_ifExists.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_isGlobal.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_arguments.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_instructionsIfNotFound.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlTemplateInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlTemplateInstruction (mAttribute_where, mAttribute_signature, mAttribute_prefix, mAttribute_fileName, mAttribute_ifExists, mAttribute_isGlobal, mAttribute_arguments, mAttribute_instructionsIfNotFound COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlTemplateInstruction type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTemplateInstruction ("gtlTemplateInstruction",
                                               & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlTemplateInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplateInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlTemplateInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTemplateInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateInstruction GALGAS_gtlTemplateInstruction::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplateInstruction result ;
  const GALGAS_gtlTemplateInstruction * p = (const GALGAS_gtlTemplateInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlTemplateInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTemplateInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlTemplateStringInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlTemplateStringInstruction * p = (const cPtr_gtlTemplateStringInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlTemplateStringInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlTemplateStringInstruction::objectCompare (const GALGAS_gtlTemplateStringInstruction & inOperand) const {
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

GALGAS_gtlTemplateStringInstruction::GALGAS_gtlTemplateStringInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateStringInstruction GALGAS_gtlTemplateStringInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlTemplateStringInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                               GALGAS_string::constructor_default (HERE),
                                                               GALGAS_string::constructor_default (HERE)
                                                               COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateStringInstruction::GALGAS_gtlTemplateStringInstruction (const cPtr_gtlTemplateStringInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlTemplateStringInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateStringInstruction GALGAS_gtlTemplateStringInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                          const GALGAS_string & inAttribute_signature,
                                                                                          const GALGAS_string & inAttribute_value
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplateStringInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlTemplateStringInstruction (inAttribute_where, inAttribute_signature, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_gtlTemplateStringInstruction::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlTemplateStringInstruction * p = (const cPtr_gtlTemplateStringInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateStringInstruction) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_gtlTemplateStringInstruction::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                Pointer class for @gtlTemplateStringInstruction class                                *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlTemplateStringInstruction::cPtr_gtlTemplateStringInstruction (const GALGAS_location & in_where,
                                                                      const GALGAS_string & in_signature,
                                                                      const GALGAS_string & in_value
                                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlTemplateStringInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplateStringInstruction ;
}

void cPtr_gtlTemplateStringInstruction::description (C_String & ioString,
                                                     const int32_t inIndentation) const {
  ioString << "[@gtlTemplateStringInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlTemplateStringInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlTemplateStringInstruction (mAttribute_where, mAttribute_signature, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @gtlTemplateStringInstruction type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTemplateStringInstruction ("gtlTemplateStringInstruction",
                                                     & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlTemplateStringInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplateStringInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlTemplateStringInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTemplateStringInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateStringInstruction GALGAS_gtlTemplateStringInstruction::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplateStringInstruction result ;
  const GALGAS_gtlTemplateStringInstruction * p = (const GALGAS_gtlTemplateStringInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlTemplateStringInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTemplateStringInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlVariablesInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlVariablesInstruction * p = (const cPtr_gtlVariablesInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlVariablesInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_shortDisplay.objectCompare (p->mAttribute_shortDisplay) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlVariablesInstruction::objectCompare (const GALGAS_gtlVariablesInstruction & inOperand) const {
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

GALGAS_gtlVariablesInstruction::GALGAS_gtlVariablesInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVariablesInstruction GALGAS_gtlVariablesInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlVariablesInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                          GALGAS_string::constructor_default (HERE),
                                                          GALGAS_bool::constructor_default (HERE)
                                                          COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVariablesInstruction::GALGAS_gtlVariablesInstruction (const cPtr_gtlVariablesInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlVariablesInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVariablesInstruction GALGAS_gtlVariablesInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                const GALGAS_string & inAttribute_signature,
                                                                                const GALGAS_bool & inAttribute_shortDisplay
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlVariablesInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_shortDisplay.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlVariablesInstruction (inAttribute_where, inAttribute_signature, inAttribute_shortDisplay COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_gtlVariablesInstruction::getter_shortDisplay (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlVariablesInstruction * p = (const cPtr_gtlVariablesInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVariablesInstruction) ;
    result = p->mAttribute_shortDisplay ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_gtlVariablesInstruction::getter_shortDisplay (UNUSED_LOCATION_ARGS) const {
  return mAttribute_shortDisplay ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @gtlVariablesInstruction class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlVariablesInstruction::cPtr_gtlVariablesInstruction (const GALGAS_location & in_where,
                                                            const GALGAS_string & in_signature,
                                                            const GALGAS_bool & in_shortDisplay
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_shortDisplay (in_shortDisplay) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlVariablesInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVariablesInstruction ;
}

void cPtr_gtlVariablesInstruction::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlVariablesInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_shortDisplay.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlVariablesInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlVariablesInstruction (mAttribute_where, mAttribute_signature, mAttribute_shortDisplay COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlVariablesInstruction type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVariablesInstruction ("gtlVariablesInstruction",
                                                & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlVariablesInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVariablesInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlVariablesInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVariablesInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVariablesInstruction GALGAS_gtlVariablesInstruction::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlVariablesInstruction result ;
  const GALGAS_gtlVariablesInstruction * p = (const GALGAS_gtlVariablesInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVariablesInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVariablesInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlWarningStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlWarningStatementInstruction * p = (const cPtr_gtlWarningStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlWarningStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_identifier.objectCompare (p->mAttribute_identifier) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_hereInstead.objectCompare (p->mAttribute_hereInstead) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_warningMessage.objectCompare (p->mAttribute_warningMessage) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlWarningStatementInstruction::objectCompare (const GALGAS_gtlWarningStatementInstruction & inOperand) const {
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

GALGAS_gtlWarningStatementInstruction::GALGAS_gtlWarningStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlWarningStatementInstruction::GALGAS_gtlWarningStatementInstruction (const cPtr_gtlWarningStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlWarningStatementInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlWarningStatementInstruction GALGAS_gtlWarningStatementInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                              const GALGAS_string & inAttribute_signature,
                                                                                              const GALGAS_gtlVarPath & inAttribute_identifier,
                                                                                              const GALGAS_bool & inAttribute_hereInstead,
                                                                                              const GALGAS_gtlExpression & inAttribute_warningMessage
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlWarningStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_identifier.isValid () && inAttribute_hereInstead.isValid () && inAttribute_warningMessage.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlWarningStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_identifier, inAttribute_hereInstead, inAttribute_warningMessage COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlWarningStatementInstruction::getter_identifier (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlWarningStatementInstruction * p = (const cPtr_gtlWarningStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWarningStatementInstruction) ;
    result = p->mAttribute_identifier ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath cPtr_gtlWarningStatementInstruction::getter_identifier (UNUSED_LOCATION_ARGS) const {
  return mAttribute_identifier ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_gtlWarningStatementInstruction::getter_hereInstead (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlWarningStatementInstruction * p = (const cPtr_gtlWarningStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWarningStatementInstruction) ;
    result = p->mAttribute_hereInstead ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_gtlWarningStatementInstruction::getter_hereInstead (UNUSED_LOCATION_ARGS) const {
  return mAttribute_hereInstead ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlWarningStatementInstruction::getter_warningMessage (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlWarningStatementInstruction * p = (const cPtr_gtlWarningStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWarningStatementInstruction) ;
    result = p->mAttribute_warningMessage ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlWarningStatementInstruction::getter_warningMessage (UNUSED_LOCATION_ARGS) const {
  return mAttribute_warningMessage ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                               Pointer class for @gtlWarningStatementInstruction class                               *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlWarningStatementInstruction::cPtr_gtlWarningStatementInstruction (const GALGAS_location & in_where,
                                                                          const GALGAS_string & in_signature,
                                                                          const GALGAS_gtlVarPath & in_identifier,
                                                                          const GALGAS_bool & in_hereInstead,
                                                                          const GALGAS_gtlExpression & in_warningMessage
                                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_identifier (in_identifier),
mAttribute_hereInstead (in_hereInstead),
mAttribute_warningMessage (in_warningMessage) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlWarningStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlWarningStatementInstruction ;
}

void cPtr_gtlWarningStatementInstruction::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "[@gtlWarningStatementInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_identifier.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_hereInstead.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_warningMessage.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlWarningStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlWarningStatementInstruction (mAttribute_where, mAttribute_signature, mAttribute_identifier, mAttribute_hereInstead, mAttribute_warningMessage COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @gtlWarningStatementInstruction type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlWarningStatementInstruction ("gtlWarningStatementInstruction",
                                                       & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlWarningStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlWarningStatementInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlWarningStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlWarningStatementInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlWarningStatementInstruction GALGAS_gtlWarningStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlWarningStatementInstruction result ;
  const GALGAS_gtlWarningStatementInstruction * p = (const GALGAS_gtlWarningStatementInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlWarningStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlWarningStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlWriteToInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlWriteToInstruction * p = (const cPtr_gtlWriteToInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlWriteToInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_fileNameExpression.objectCompare (p->mAttribute_fileNameExpression) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_isExecutable.objectCompare (p->mAttribute_isExecutable) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_instructions.objectCompare (p->mAttribute_instructions) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlWriteToInstruction::objectCompare (const GALGAS_gtlWriteToInstruction & inOperand) const {
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

GALGAS_gtlWriteToInstruction::GALGAS_gtlWriteToInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlWriteToInstruction::GALGAS_gtlWriteToInstruction (const cPtr_gtlWriteToInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlWriteToInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlWriteToInstruction GALGAS_gtlWriteToInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                            const GALGAS_string & inAttribute_signature,
                                                                            const GALGAS_gtlExpression & inAttribute_fileNameExpression,
                                                                            const GALGAS_bool & inAttribute_isExecutable,
                                                                            const GALGAS_gtlInstructionList & inAttribute_instructions
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlWriteToInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_fileNameExpression.isValid () && inAttribute_isExecutable.isValid () && inAttribute_instructions.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlWriteToInstruction (inAttribute_where, inAttribute_signature, inAttribute_fileNameExpression, inAttribute_isExecutable, inAttribute_instructions COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlWriteToInstruction::getter_fileNameExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlWriteToInstruction * p = (const cPtr_gtlWriteToInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWriteToInstruction) ;
    result = p->mAttribute_fileNameExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlWriteToInstruction::getter_fileNameExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_fileNameExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_gtlWriteToInstruction::getter_isExecutable (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlWriteToInstruction * p = (const cPtr_gtlWriteToInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWriteToInstruction) ;
    result = p->mAttribute_isExecutable ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_gtlWriteToInstruction::getter_isExecutable (UNUSED_LOCATION_ARGS) const {
  return mAttribute_isExecutable ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlWriteToInstruction::getter_instructions (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlWriteToInstruction * p = (const cPtr_gtlWriteToInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWriteToInstruction) ;
    result = p->mAttribute_instructions ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlWriteToInstruction::getter_instructions (UNUSED_LOCATION_ARGS) const {
  return mAttribute_instructions ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @gtlWriteToInstruction class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlWriteToInstruction::cPtr_gtlWriteToInstruction (const GALGAS_location & in_where,
                                                        const GALGAS_string & in_signature,
                                                        const GALGAS_gtlExpression & in_fileNameExpression,
                                                        const GALGAS_bool & in_isExecutable,
                                                        const GALGAS_gtlInstructionList & in_instructions
                                                        COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_fileNameExpression (in_fileNameExpression),
mAttribute_isExecutable (in_isExecutable),
mAttribute_instructions (in_instructions) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlWriteToInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlWriteToInstruction ;
}

void cPtr_gtlWriteToInstruction::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@gtlWriteToInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_fileNameExpression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_isExecutable.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_instructions.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlWriteToInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlWriteToInstruction (mAttribute_where, mAttribute_signature, mAttribute_fileNameExpression, mAttribute_isExecutable, mAttribute_instructions COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @gtlWriteToInstruction type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlWriteToInstruction ("gtlWriteToInstruction",
                                              & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlWriteToInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlWriteToInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlWriteToInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlWriteToInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlWriteToInstruction GALGAS_gtlWriteToInstruction::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlWriteToInstruction result ;
  const GALGAS_gtlWriteToInstruction * p = (const GALGAS_gtlWriteToInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlWriteToInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlWriteToInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

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

typeComparisonResult cPtr_gtlTemplate::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlTemplate * p = (const cPtr_gtlTemplate *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlTemplate) ;
  if (kOperandEqual == result) {
    result = mAttribute_path.objectCompare (p->mAttribute_path) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_program.objectCompare (p->mAttribute_program) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlTemplate::objectCompare (const GALGAS_gtlTemplate & inOperand) const {
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

GALGAS_gtlTemplate::GALGAS_gtlTemplate (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplate GALGAS_gtlTemplate::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlTemplate::constructor_new (GALGAS_string::constructor_default (HERE),
                                              GALGAS_gtlInstructionList::constructor_emptyList (HERE)
                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplate::GALGAS_gtlTemplate (const cPtr_gtlTemplate * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlTemplate) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplate GALGAS_gtlTemplate::constructor_new (const GALGAS_string & inAttribute_path,
                                                        const GALGAS_gtlInstructionList & inAttribute_program
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplate result ;
  if (inAttribute_path.isValid () && inAttribute_program.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlTemplate (inAttribute_path, inAttribute_program COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_gtlTemplate::getter_path (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlTemplate * p = (const cPtr_gtlTemplate *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplate) ;
    result = p->mAttribute_path ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_gtlTemplate::getter_path (UNUSED_LOCATION_ARGS) const {
  return mAttribute_path ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlTemplate::getter_program (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlTemplate * p = (const cPtr_gtlTemplate *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplate) ;
    result = p->mAttribute_program ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlTemplate::getter_program (UNUSED_LOCATION_ARGS) const {
  return mAttribute_program ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @gtlTemplate class                                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlTemplate::cPtr_gtlTemplate (const GALGAS_string & in_path,
                                    const GALGAS_gtlInstructionList & in_program
                                    COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_path (in_path),
mAttribute_program (in_program) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlTemplate::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplate ;
}

void cPtr_gtlTemplate::description (C_String & ioString,
                                    const int32_t inIndentation) const {
  ioString << "[@gtlTemplate:" ;
  mAttribute_path.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_program.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlTemplate::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlTemplate (mAttribute_path, mAttribute_program COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlTemplate type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTemplate ("gtlTemplate",
                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlTemplate::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplate ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlTemplate::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTemplate (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplate GALGAS_gtlTemplate::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplate result ;
  const GALGAS_gtlTemplate * p = (const GALGAS_gtlTemplate *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlTemplate *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTemplate", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_gtlVarItem::objectCompare (const GALGAS_gtlVarItem & inOperand) const {
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

GALGAS_gtlVarItem::GALGAS_gtlVarItem (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItem::GALGAS_gtlVarItem (const cPtr_gtlVarItem * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlVarItem) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                         Pointer class for @gtlVarItem class                                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlVarItem::cPtr_gtlVarItem (LOCATION_ARGS) :
acPtr_class (THERE) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlVarItem type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarItem ("gtlVarItem",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlVarItem::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarItem ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlVarItem::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarItem (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItem GALGAS_gtlVarItem::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarItem result ;
  const GALGAS_gtlVarItem * p = (const GALGAS_gtlVarItem *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVarItem *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarItem", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

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
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_impType::objectCompare (const GALGAS_impType & inOperand) const {
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

GALGAS_impType::GALGAS_impType (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impType::GALGAS_impType (const cPtr_impType * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList GALGAS_impType::getter_locations (UNUSED_LOCATION_ARGS) const {
  GALGAS_locationList result ;
  if (NULL != mObjectPtr) {
    const cPtr_impType * p = (const cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    result = p->mAttribute_locations ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList cPtr_impType::getter_locations (UNUSED_LOCATION_ARGS) const {
  return mAttribute_locations ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType GALGAS_impType::getter_type (UNUSED_LOCATION_ARGS) const {
  GALGAS_dataType result ;
  if (NULL != mObjectPtr) {
    const cPtr_impType * p = (const cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    result = p->mAttribute_type ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType cPtr_impType::getter_type (UNUSED_LOCATION_ARGS) const {
  return mAttribute_type ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_impType::getter_name (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_impType * p = (const cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    result = p->mAttribute_name ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_impType::getter_name (UNUSED_LOCATION_ARGS) const {
  return mAttribute_name ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_impType::getter_multiple (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_impType * p = (const cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    result = p->mAttribute_multiple ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_impType::getter_multiple (UNUSED_LOCATION_ARGS) const {
  return mAttribute_multiple ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_impType::getter_descs (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstringlist result ;
  if (NULL != mObjectPtr) {
    const cPtr_impType * p = (const cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    result = p->mAttribute_descs ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cPtr_impType::getter_descs (UNUSED_LOCATION_ARGS) const {
  return mAttribute_descs ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @impType class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_impType::cPtr_impType (const GALGAS_locationList & in_locations,
                            const GALGAS_dataType & in_type,
                            const GALGAS_lstring & in_name,
                            const GALGAS_bool & in_multiple,
                            const GALGAS_lstringlist & in_descs
                            COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_locations (in_locations),
mAttribute_type (in_type),
mAttribute_name (in_name),
mAttribute_multiple (in_multiple),
mAttribute_descs (in_descs) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @impType type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_impType ("impType",
                                NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_impType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impType ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_impType::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impType (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impType GALGAS_impType::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_impType result ;
  const GALGAS_impType * p = (const GALGAS_impType *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_impType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_impAutoDefaultType::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_impAutoDefaultType * p = (const cPtr_impAutoDefaultType *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_impAutoDefaultType) ;
  if (kOperandEqual == result) {
    result = mAttribute_locations.objectCompare (p->mAttribute_locations) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_type.objectCompare (p->mAttribute_type) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_multiple.objectCompare (p->mAttribute_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_descs.objectCompare (p->mAttribute_descs) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_withAuto.objectCompare (p->mAttribute_withAuto) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_defaultValue.objectCompare (p->mAttribute_defaultValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_impAutoDefaultType::objectCompare (const GALGAS_impAutoDefaultType & inOperand) const {
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

GALGAS_impAutoDefaultType::GALGAS_impAutoDefaultType (void) :
GALGAS_impType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impAutoDefaultType::GALGAS_impAutoDefaultType (const cPtr_impAutoDefaultType * inSourcePtr) :
GALGAS_impType (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impAutoDefaultType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impAutoDefaultType GALGAS_impAutoDefaultType::constructor_new (const GALGAS_locationList & inAttribute_locations,
                                                                      const GALGAS_dataType & inAttribute_type,
                                                                      const GALGAS_lstring & inAttribute_name,
                                                                      const GALGAS_bool & inAttribute_multiple,
                                                                      const GALGAS_lstringlist & inAttribute_descs,
                                                                      const GALGAS_bool & inAttribute_withAuto,
                                                                      const GALGAS_object_5F_t & inAttribute_defaultValue
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_impAutoDefaultType result ;
  if (inAttribute_locations.isValid () && inAttribute_type.isValid () && inAttribute_name.isValid () && inAttribute_multiple.isValid () && inAttribute_descs.isValid () && inAttribute_withAuto.isValid () && inAttribute_defaultValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_impAutoDefaultType (inAttribute_locations, inAttribute_type, inAttribute_name, inAttribute_multiple, inAttribute_descs, inAttribute_withAuto, inAttribute_defaultValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_impAutoDefaultType::getter_withAuto (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_impAutoDefaultType * p = (const cPtr_impAutoDefaultType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impAutoDefaultType) ;
    result = p->mAttribute_withAuto ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_impAutoDefaultType::getter_withAuto (UNUSED_LOCATION_ARGS) const {
  return mAttribute_withAuto ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t GALGAS_impAutoDefaultType::getter_defaultValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_object_5F_t result ;
  if (NULL != mObjectPtr) {
    const cPtr_impAutoDefaultType * p = (const cPtr_impAutoDefaultType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impAutoDefaultType) ;
    result = p->mAttribute_defaultValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t cPtr_impAutoDefaultType::getter_defaultValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_defaultValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @impAutoDefaultType class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_impAutoDefaultType::cPtr_impAutoDefaultType (const GALGAS_locationList & in_locations,
                                                  const GALGAS_dataType & in_type,
                                                  const GALGAS_lstring & in_name,
                                                  const GALGAS_bool & in_multiple,
                                                  const GALGAS_lstringlist & in_descs,
                                                  const GALGAS_bool & in_withAuto,
                                                  const GALGAS_object_5F_t & in_defaultValue
                                                  COMMA_LOCATION_ARGS) :
cPtr_impType (in_locations, in_type, in_name, in_multiple, in_descs COMMA_THERE),
mAttribute_withAuto (in_withAuto),
mAttribute_defaultValue (in_defaultValue) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_impAutoDefaultType::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impAutoDefaultType ;
}

void cPtr_impAutoDefaultType::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@impAutoDefaultType:" ;
  mAttribute_locations.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_type.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_multiple.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_descs.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_withAuto.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_defaultValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_impAutoDefaultType::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_impAutoDefaultType (mAttribute_locations, mAttribute_type, mAttribute_name, mAttribute_multiple, mAttribute_descs, mAttribute_withAuto, mAttribute_defaultValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @impAutoDefaultType type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_impAutoDefaultType ("impAutoDefaultType",
                                           & kTypeDescriptor_GALGAS_impType) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_impAutoDefaultType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impAutoDefaultType ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_impAutoDefaultType::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impAutoDefaultType (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impAutoDefaultType GALGAS_impAutoDefaultType::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_impAutoDefaultType result ;
  const GALGAS_impAutoDefaultType * p = (const GALGAS_impAutoDefaultType *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_impAutoDefaultType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impAutoDefaultType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_impBoolType::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_impBoolType * p = (const cPtr_impBoolType *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_impBoolType) ;
  if (kOperandEqual == result) {
    result = mAttribute_locations.objectCompare (p->mAttribute_locations) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_type.objectCompare (p->mAttribute_type) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_multiple.objectCompare (p->mAttribute_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_descs.objectCompare (p->mAttribute_descs) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_withAuto.objectCompare (p->mAttribute_withAuto) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_defaultValue.objectCompare (p->mAttribute_defaultValue) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_trueSubAttributes.objectCompare (p->mAttribute_trueSubAttributes) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_falseSubAttributes.objectCompare (p->mAttribute_falseSubAttributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_impBoolType::objectCompare (const GALGAS_impBoolType & inOperand) const {
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

GALGAS_impBoolType::GALGAS_impBoolType (void) :
GALGAS_impAutoDefaultType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impBoolType::GALGAS_impBoolType (const cPtr_impBoolType * inSourcePtr) :
GALGAS_impAutoDefaultType (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impBoolType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impBoolType GALGAS_impBoolType::constructor_new (const GALGAS_locationList & inAttribute_locations,
                                                        const GALGAS_dataType & inAttribute_type,
                                                        const GALGAS_lstring & inAttribute_name,
                                                        const GALGAS_bool & inAttribute_multiple,
                                                        const GALGAS_lstringlist & inAttribute_descs,
                                                        const GALGAS_bool & inAttribute_withAuto,
                                                        const GALGAS_object_5F_t & inAttribute_defaultValue,
                                                        const GALGAS_implementationObjectMap & inAttribute_trueSubAttributes,
                                                        const GALGAS_implementationObjectMap & inAttribute_falseSubAttributes
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_impBoolType result ;
  if (inAttribute_locations.isValid () && inAttribute_type.isValid () && inAttribute_name.isValid () && inAttribute_multiple.isValid () && inAttribute_descs.isValid () && inAttribute_withAuto.isValid () && inAttribute_defaultValue.isValid () && inAttribute_trueSubAttributes.isValid () && inAttribute_falseSubAttributes.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_impBoolType (inAttribute_locations, inAttribute_type, inAttribute_name, inAttribute_multiple, inAttribute_descs, inAttribute_withAuto, inAttribute_defaultValue, inAttribute_trueSubAttributes, inAttribute_falseSubAttributes COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap GALGAS_impBoolType::getter_trueSubAttributes (UNUSED_LOCATION_ARGS) const {
  GALGAS_implementationObjectMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_impBoolType * p = (const cPtr_impBoolType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impBoolType) ;
    result = p->mAttribute_trueSubAttributes ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap cPtr_impBoolType::getter_trueSubAttributes (UNUSED_LOCATION_ARGS) const {
  return mAttribute_trueSubAttributes ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap GALGAS_impBoolType::getter_falseSubAttributes (UNUSED_LOCATION_ARGS) const {
  GALGAS_implementationObjectMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_impBoolType * p = (const cPtr_impBoolType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impBoolType) ;
    result = p->mAttribute_falseSubAttributes ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap cPtr_impBoolType::getter_falseSubAttributes (UNUSED_LOCATION_ARGS) const {
  return mAttribute_falseSubAttributes ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @impBoolType class                                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_impBoolType::cPtr_impBoolType (const GALGAS_locationList & in_locations,
                                    const GALGAS_dataType & in_type,
                                    const GALGAS_lstring & in_name,
                                    const GALGAS_bool & in_multiple,
                                    const GALGAS_lstringlist & in_descs,
                                    const GALGAS_bool & in_withAuto,
                                    const GALGAS_object_5F_t & in_defaultValue,
                                    const GALGAS_implementationObjectMap & in_trueSubAttributes,
                                    const GALGAS_implementationObjectMap & in_falseSubAttributes
                                    COMMA_LOCATION_ARGS) :
cPtr_impAutoDefaultType (in_locations, in_type, in_name, in_multiple, in_descs, in_withAuto, in_defaultValue COMMA_THERE),
mAttribute_trueSubAttributes (in_trueSubAttributes),
mAttribute_falseSubAttributes (in_falseSubAttributes) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_impBoolType::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impBoolType ;
}

void cPtr_impBoolType::description (C_String & ioString,
                                    const int32_t inIndentation) const {
  ioString << "[@impBoolType:" ;
  mAttribute_locations.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_type.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_multiple.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_descs.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_withAuto.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_defaultValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_trueSubAttributes.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_falseSubAttributes.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_impBoolType::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_impBoolType (mAttribute_locations, mAttribute_type, mAttribute_name, mAttribute_multiple, mAttribute_descs, mAttribute_withAuto, mAttribute_defaultValue, mAttribute_trueSubAttributes, mAttribute_falseSubAttributes COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @impBoolType type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_impBoolType ("impBoolType",
                                    & kTypeDescriptor_GALGAS_impAutoDefaultType) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_impBoolType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impBoolType ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_impBoolType::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impBoolType (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impBoolType GALGAS_impBoolType::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_impBoolType result ;
  const GALGAS_impBoolType * p = (const GALGAS_impBoolType *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_impBoolType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impBoolType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_impEnumType::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_impEnumType * p = (const cPtr_impEnumType *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_impEnumType) ;
  if (kOperandEqual == result) {
    result = mAttribute_locations.objectCompare (p->mAttribute_locations) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_type.objectCompare (p->mAttribute_type) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_multiple.objectCompare (p->mAttribute_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_descs.objectCompare (p->mAttribute_descs) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_withAuto.objectCompare (p->mAttribute_withAuto) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_defaultValue.objectCompare (p->mAttribute_defaultValue) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_valuesMap.objectCompare (p->mAttribute_valuesMap) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_impEnumType::objectCompare (const GALGAS_impEnumType & inOperand) const {
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

GALGAS_impEnumType::GALGAS_impEnumType (void) :
GALGAS_impAutoDefaultType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impEnumType::GALGAS_impEnumType (const cPtr_impEnumType * inSourcePtr) :
GALGAS_impAutoDefaultType (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impEnumType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impEnumType GALGAS_impEnumType::constructor_new (const GALGAS_locationList & inAttribute_locations,
                                                        const GALGAS_dataType & inAttribute_type,
                                                        const GALGAS_lstring & inAttribute_name,
                                                        const GALGAS_bool & inAttribute_multiple,
                                                        const GALGAS_lstringlist & inAttribute_descs,
                                                        const GALGAS_bool & inAttribute_withAuto,
                                                        const GALGAS_object_5F_t & inAttribute_defaultValue,
                                                        const GALGAS_enumValues & inAttribute_valuesMap
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_impEnumType result ;
  if (inAttribute_locations.isValid () && inAttribute_type.isValid () && inAttribute_name.isValid () && inAttribute_multiple.isValid () && inAttribute_descs.isValid () && inAttribute_withAuto.isValid () && inAttribute_defaultValue.isValid () && inAttribute_valuesMap.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_impEnumType (inAttribute_locations, inAttribute_type, inAttribute_name, inAttribute_multiple, inAttribute_descs, inAttribute_withAuto, inAttribute_defaultValue, inAttribute_valuesMap COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumValues GALGAS_impEnumType::getter_valuesMap (UNUSED_LOCATION_ARGS) const {
  GALGAS_enumValues result ;
  if (NULL != mObjectPtr) {
    const cPtr_impEnumType * p = (const cPtr_impEnumType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impEnumType) ;
    result = p->mAttribute_valuesMap ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumValues cPtr_impEnumType::getter_valuesMap (UNUSED_LOCATION_ARGS) const {
  return mAttribute_valuesMap ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @impEnumType class                                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_impEnumType::cPtr_impEnumType (const GALGAS_locationList & in_locations,
                                    const GALGAS_dataType & in_type,
                                    const GALGAS_lstring & in_name,
                                    const GALGAS_bool & in_multiple,
                                    const GALGAS_lstringlist & in_descs,
                                    const GALGAS_bool & in_withAuto,
                                    const GALGAS_object_5F_t & in_defaultValue,
                                    const GALGAS_enumValues & in_valuesMap
                                    COMMA_LOCATION_ARGS) :
cPtr_impAutoDefaultType (in_locations, in_type, in_name, in_multiple, in_descs, in_withAuto, in_defaultValue COMMA_THERE),
mAttribute_valuesMap (in_valuesMap) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_impEnumType::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impEnumType ;
}

void cPtr_impEnumType::description (C_String & ioString,
                                    const int32_t inIndentation) const {
  ioString << "[@impEnumType:" ;
  mAttribute_locations.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_type.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_multiple.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_descs.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_withAuto.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_defaultValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_valuesMap.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_impEnumType::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_impEnumType (mAttribute_locations, mAttribute_type, mAttribute_name, mAttribute_multiple, mAttribute_descs, mAttribute_withAuto, mAttribute_defaultValue, mAttribute_valuesMap COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @impEnumType type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_impEnumType ("impEnumType",
                                    & kTypeDescriptor_GALGAS_impAutoDefaultType) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_impEnumType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impEnumType ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_impEnumType::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impEnumType (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impEnumType GALGAS_impEnumType::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_impEnumType result ;
  const GALGAS_impEnumType * p = (const GALGAS_impEnumType *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_impEnumType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impEnumType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_impRangedType::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_impRangedType * p = (const cPtr_impRangedType *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_impRangedType) ;
  if (kOperandEqual == result) {
    result = mAttribute_locations.objectCompare (p->mAttribute_locations) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_type.objectCompare (p->mAttribute_type) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_multiple.objectCompare (p->mAttribute_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_descs.objectCompare (p->mAttribute_descs) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_withAuto.objectCompare (p->mAttribute_withAuto) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_defaultValue.objectCompare (p->mAttribute_defaultValue) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_setOrRange.objectCompare (p->mAttribute_setOrRange) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_impRangedType::objectCompare (const GALGAS_impRangedType & inOperand) const {
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

GALGAS_impRangedType::GALGAS_impRangedType (void) :
GALGAS_impAutoDefaultType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impRangedType::GALGAS_impRangedType (const cPtr_impRangedType * inSourcePtr) :
GALGAS_impAutoDefaultType (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impRangedType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impRangedType GALGAS_impRangedType::constructor_new (const GALGAS_locationList & inAttribute_locations,
                                                            const GALGAS_dataType & inAttribute_type,
                                                            const GALGAS_lstring & inAttribute_name,
                                                            const GALGAS_bool & inAttribute_multiple,
                                                            const GALGAS_lstringlist & inAttribute_descs,
                                                            const GALGAS_bool & inAttribute_withAuto,
                                                            const GALGAS_object_5F_t & inAttribute_defaultValue,
                                                            const GALGAS_attributeRange & inAttribute_setOrRange
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_impRangedType result ;
  if (inAttribute_locations.isValid () && inAttribute_type.isValid () && inAttribute_name.isValid () && inAttribute_multiple.isValid () && inAttribute_descs.isValid () && inAttribute_withAuto.isValid () && inAttribute_defaultValue.isValid () && inAttribute_setOrRange.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_impRangedType (inAttribute_locations, inAttribute_type, inAttribute_name, inAttribute_multiple, inAttribute_descs, inAttribute_withAuto, inAttribute_defaultValue, inAttribute_setOrRange COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_attributeRange GALGAS_impRangedType::getter_setOrRange (UNUSED_LOCATION_ARGS) const {
  GALGAS_attributeRange result ;
  if (NULL != mObjectPtr) {
    const cPtr_impRangedType * p = (const cPtr_impRangedType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impRangedType) ;
    result = p->mAttribute_setOrRange ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_attributeRange cPtr_impRangedType::getter_setOrRange (UNUSED_LOCATION_ARGS) const {
  return mAttribute_setOrRange ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @impRangedType class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_impRangedType::cPtr_impRangedType (const GALGAS_locationList & in_locations,
                                        const GALGAS_dataType & in_type,
                                        const GALGAS_lstring & in_name,
                                        const GALGAS_bool & in_multiple,
                                        const GALGAS_lstringlist & in_descs,
                                        const GALGAS_bool & in_withAuto,
                                        const GALGAS_object_5F_t & in_defaultValue,
                                        const GALGAS_attributeRange & in_setOrRange
                                        COMMA_LOCATION_ARGS) :
cPtr_impAutoDefaultType (in_locations, in_type, in_name, in_multiple, in_descs, in_withAuto, in_defaultValue COMMA_THERE),
mAttribute_setOrRange (in_setOrRange) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_impRangedType::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impRangedType ;
}

void cPtr_impRangedType::description (C_String & ioString,
                                      const int32_t inIndentation) const {
  ioString << "[@impRangedType:" ;
  mAttribute_locations.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_type.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_multiple.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_descs.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_withAuto.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_defaultValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_setOrRange.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_impRangedType::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_impRangedType (mAttribute_locations, mAttribute_type, mAttribute_name, mAttribute_multiple, mAttribute_descs, mAttribute_withAuto, mAttribute_defaultValue, mAttribute_setOrRange COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @impRangedType type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_impRangedType ("impRangedType",
                                      & kTypeDescriptor_GALGAS_impAutoDefaultType) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_impRangedType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impRangedType ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_impRangedType::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impRangedType (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impRangedType GALGAS_impRangedType::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_impRangedType result ;
  const GALGAS_impRangedType * p = (const GALGAS_impRangedType *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_impRangedType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impRangedType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_impStructType::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_impStructType * p = (const cPtr_impStructType *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_impStructType) ;
  if (kOperandEqual == result) {
    result = mAttribute_locations.objectCompare (p->mAttribute_locations) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_type.objectCompare (p->mAttribute_type) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_multiple.objectCompare (p->mAttribute_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_descs.objectCompare (p->mAttribute_descs) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_structAttributes.objectCompare (p->mAttribute_structAttributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_impStructType::objectCompare (const GALGAS_impStructType & inOperand) const {
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

GALGAS_impStructType::GALGAS_impStructType (void) :
GALGAS_impType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impStructType::GALGAS_impStructType (const cPtr_impStructType * inSourcePtr) :
GALGAS_impType (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impStructType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impStructType GALGAS_impStructType::constructor_new (const GALGAS_locationList & inAttribute_locations,
                                                            const GALGAS_dataType & inAttribute_type,
                                                            const GALGAS_lstring & inAttribute_name,
                                                            const GALGAS_bool & inAttribute_multiple,
                                                            const GALGAS_lstringlist & inAttribute_descs,
                                                            const GALGAS_implementationObjectMap & inAttribute_structAttributes
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_impStructType result ;
  if (inAttribute_locations.isValid () && inAttribute_type.isValid () && inAttribute_name.isValid () && inAttribute_multiple.isValid () && inAttribute_descs.isValid () && inAttribute_structAttributes.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_impStructType (inAttribute_locations, inAttribute_type, inAttribute_name, inAttribute_multiple, inAttribute_descs, inAttribute_structAttributes COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap GALGAS_impStructType::getter_structAttributes (UNUSED_LOCATION_ARGS) const {
  GALGAS_implementationObjectMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_impStructType * p = (const cPtr_impStructType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impStructType) ;
    result = p->mAttribute_structAttributes ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap cPtr_impStructType::getter_structAttributes (UNUSED_LOCATION_ARGS) const {
  return mAttribute_structAttributes ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @impStructType class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_impStructType::cPtr_impStructType (const GALGAS_locationList & in_locations,
                                        const GALGAS_dataType & in_type,
                                        const GALGAS_lstring & in_name,
                                        const GALGAS_bool & in_multiple,
                                        const GALGAS_lstringlist & in_descs,
                                        const GALGAS_implementationObjectMap & in_structAttributes
                                        COMMA_LOCATION_ARGS) :
cPtr_impType (in_locations, in_type, in_name, in_multiple, in_descs COMMA_THERE),
mAttribute_structAttributes (in_structAttributes) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_impStructType::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impStructType ;
}

void cPtr_impStructType::description (C_String & ioString,
                                      const int32_t inIndentation) const {
  ioString << "[@impStructType:" ;
  mAttribute_locations.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_type.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_multiple.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_descs.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_structAttributes.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_impStructType::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_impStructType (mAttribute_locations, mAttribute_type, mAttribute_name, mAttribute_multiple, mAttribute_descs, mAttribute_structAttributes COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @impStructType type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_impStructType ("impStructType",
                                      & kTypeDescriptor_GALGAS_impType) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_impStructType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impStructType ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_impStructType::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impStructType (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impStructType GALGAS_impStructType::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_impStructType result ;
  const GALGAS_impStructType * p = (const GALGAS_impStructType *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_impStructType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impStructType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_impVoid::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_impVoid * p = (const cPtr_impVoid *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_impVoid) ;
  if (kOperandEqual == result) {
    result = mAttribute_locations.objectCompare (p->mAttribute_locations) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_type.objectCompare (p->mAttribute_type) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_multiple.objectCompare (p->mAttribute_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_descs.objectCompare (p->mAttribute_descs) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_impVoid::objectCompare (const GALGAS_impVoid & inOperand) const {
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

GALGAS_impVoid::GALGAS_impVoid (void) :
GALGAS_impType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impVoid::GALGAS_impVoid (const cPtr_impVoid * inSourcePtr) :
GALGAS_impType (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impVoid) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impVoid GALGAS_impVoid::constructor_new (const GALGAS_locationList & inAttribute_locations,
                                                const GALGAS_dataType & inAttribute_type,
                                                const GALGAS_lstring & inAttribute_name,
                                                const GALGAS_bool & inAttribute_multiple,
                                                const GALGAS_lstringlist & inAttribute_descs
                                                COMMA_LOCATION_ARGS) {
  GALGAS_impVoid result ;
  if (inAttribute_locations.isValid () && inAttribute_type.isValid () && inAttribute_name.isValid () && inAttribute_multiple.isValid () && inAttribute_descs.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_impVoid (inAttribute_locations, inAttribute_type, inAttribute_name, inAttribute_multiple, inAttribute_descs COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @impVoid class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_impVoid::cPtr_impVoid (const GALGAS_locationList & in_locations,
                            const GALGAS_dataType & in_type,
                            const GALGAS_lstring & in_name,
                            const GALGAS_bool & in_multiple,
                            const GALGAS_lstringlist & in_descs
                            COMMA_LOCATION_ARGS) :
cPtr_impType (in_locations, in_type, in_name, in_multiple, in_descs COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_impVoid::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impVoid ;
}

void cPtr_impVoid::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "[@impVoid:" ;
  mAttribute_locations.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_type.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_multiple.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_descs.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_impVoid::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_impVoid (mAttribute_locations, mAttribute_type, mAttribute_name, mAttribute_multiple, mAttribute_descs COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @impVoid type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_impVoid ("impVoid",
                                & kTypeDescriptor_GALGAS_impType) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_impVoid::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impVoid ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_impVoid::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impVoid (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impVoid GALGAS_impVoid::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_impVoid result ;
  const GALGAS_impVoid * p = (const GALGAS_impVoid *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_impVoid *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impVoid", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_refType::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_refType * p = (const cPtr_refType *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_refType) ;
  if (kOperandEqual == result) {
    result = mAttribute_locations.objectCompare (p->mAttribute_locations) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_type.objectCompare (p->mAttribute_type) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_multiple.objectCompare (p->mAttribute_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_descs.objectCompare (p->mAttribute_descs) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_ref.objectCompare (p->mAttribute_ref) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_refType::objectCompare (const GALGAS_refType & inOperand) const {
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

GALGAS_refType::GALGAS_refType (void) :
GALGAS_impType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_refType::GALGAS_refType (const cPtr_refType * inSourcePtr) :
GALGAS_impType (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_refType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_refType GALGAS_refType::constructor_new (const GALGAS_locationList & inAttribute_locations,
                                                const GALGAS_dataType & inAttribute_type,
                                                const GALGAS_lstring & inAttribute_name,
                                                const GALGAS_bool & inAttribute_multiple,
                                                const GALGAS_lstringlist & inAttribute_descs,
                                                const GALGAS_lstring & inAttribute_ref
                                                COMMA_LOCATION_ARGS) {
  GALGAS_refType result ;
  if (inAttribute_locations.isValid () && inAttribute_type.isValid () && inAttribute_name.isValid () && inAttribute_multiple.isValid () && inAttribute_descs.isValid () && inAttribute_ref.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_refType (inAttribute_locations, inAttribute_type, inAttribute_name, inAttribute_multiple, inAttribute_descs, inAttribute_ref COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_refType::getter_ref (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_refType * p = (const cPtr_refType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_refType) ;
    result = p->mAttribute_ref ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_refType::getter_ref (UNUSED_LOCATION_ARGS) const {
  return mAttribute_ref ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @refType class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_refType::cPtr_refType (const GALGAS_locationList & in_locations,
                            const GALGAS_dataType & in_type,
                            const GALGAS_lstring & in_name,
                            const GALGAS_bool & in_multiple,
                            const GALGAS_lstringlist & in_descs,
                            const GALGAS_lstring & in_ref
                            COMMA_LOCATION_ARGS) :
cPtr_impType (in_locations, in_type, in_name, in_multiple, in_descs COMMA_THERE),
mAttribute_ref (in_ref) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_refType::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_refType ;
}

void cPtr_refType::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "[@refType:" ;
  mAttribute_locations.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_type.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_multiple.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_descs.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_ref.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_refType::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_refType (mAttribute_locations, mAttribute_type, mAttribute_name, mAttribute_multiple, mAttribute_descs, mAttribute_ref COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @refType type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_refType ("refType",
                                & kTypeDescriptor_GALGAS_impType) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_refType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_refType ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_refType::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_refType (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_refType GALGAS_refType::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_refType result ;
  const GALGAS_refType * p = (const GALGAS_refType *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_refType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("refType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_implementation::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_implementation * p = (const cPtr_implementation *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_implementation) ;
  if (kOperandEqual == result) {
    result = mAttribute_imp.objectCompare (p->mAttribute_imp) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_implementation::objectCompare (const GALGAS_implementation & inOperand) const {
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

GALGAS_implementation::GALGAS_implementation (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementation GALGAS_implementation::constructor_default (LOCATION_ARGS) {
  return GALGAS_implementation::constructor_new (GALGAS_implementationMap::constructor_emptyMap (HERE)
                                                 COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementation::GALGAS_implementation (const cPtr_implementation * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_implementation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementation GALGAS_implementation::constructor_new (const GALGAS_implementationMap & inAttribute_imp
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_implementation result ;
  if (inAttribute_imp.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_implementation (inAttribute_imp COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap GALGAS_implementation::getter_imp (UNUSED_LOCATION_ARGS) const {
  GALGAS_implementationMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_implementation * p = (const cPtr_implementation *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_implementation) ;
    result = p->mAttribute_imp ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap cPtr_implementation::getter_imp (UNUSED_LOCATION_ARGS) const {
  return mAttribute_imp ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementation::setter_setImp (GALGAS_implementationMap inValue
                                           COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_implementation * p = (cPtr_implementation *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_implementation) ;
    p->mAttribute_imp = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_implementation::setter_setImp (GALGAS_implementationMap inValue
                                         COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_imp = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @implementation class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_implementation::cPtr_implementation (const GALGAS_implementationMap & in_imp
                                          COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_imp (in_imp) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_implementation::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementation ;
}

void cPtr_implementation::description (C_String & ioString,
                                       const int32_t inIndentation) const {
  ioString << "[@implementation:" ;
  mAttribute_imp.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_implementation::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_implementation (mAttribute_imp COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @implementation type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_implementation ("implementation",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_implementation::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementation ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_implementation::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_implementation (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementation GALGAS_implementation::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_implementation result ;
  const GALGAS_implementation * p = (const GALGAS_implementation *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_implementation *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("implementation", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_implementationObject::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_implementationObject * p = (const cPtr_implementationObject *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_implementationObject) ;
  if (kOperandEqual == result) {
    result = mAttribute_multiple.objectCompare (p->mAttribute_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_attributes.objectCompare (p->mAttribute_attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_implementationObject::objectCompare (const GALGAS_implementationObject & inOperand) const {
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

GALGAS_implementationObject::GALGAS_implementationObject (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObject GALGAS_implementationObject::constructor_default (LOCATION_ARGS) {
  return GALGAS_implementationObject::constructor_new (GALGAS_lbool::constructor_default (HERE),
                                                       GALGAS_implementationObjectMap::constructor_emptyMap (HERE)
                                                       COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObject::GALGAS_implementationObject (const cPtr_implementationObject * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_implementationObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObject GALGAS_implementationObject::constructor_new (const GALGAS_lbool & inAttribute_multiple,
                                                                          const GALGAS_implementationObjectMap & inAttribute_attributes
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_implementationObject result ;
  if (inAttribute_multiple.isValid () && inAttribute_attributes.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_implementationObject (inAttribute_multiple, inAttribute_attributes COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbool GALGAS_implementationObject::getter_multiple (UNUSED_LOCATION_ARGS) const {
  GALGAS_lbool result ;
  if (NULL != mObjectPtr) {
    const cPtr_implementationObject * p = (const cPtr_implementationObject *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_implementationObject) ;
    result = p->mAttribute_multiple ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbool cPtr_implementationObject::getter_multiple (UNUSED_LOCATION_ARGS) const {
  return mAttribute_multiple ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap GALGAS_implementationObject::getter_attributes (UNUSED_LOCATION_ARGS) const {
  GALGAS_implementationObjectMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_implementationObject * p = (const cPtr_implementationObject *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_implementationObject) ;
    result = p->mAttribute_attributes ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap cPtr_implementationObject::getter_attributes (UNUSED_LOCATION_ARGS) const {
  return mAttribute_attributes ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationObject::setter_setMultiple (GALGAS_lbool inValue
                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_implementationObject * p = (cPtr_implementationObject *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_implementationObject) ;
    p->mAttribute_multiple = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_implementationObject::setter_setMultiple (GALGAS_lbool inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_multiple = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationObject::setter_setAttributes (GALGAS_implementationObjectMap inValue
                                                        COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_implementationObject * p = (cPtr_implementationObject *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_implementationObject) ;
    p->mAttribute_attributes = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_implementationObject::setter_setAttributes (GALGAS_implementationObjectMap inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_attributes = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @implementationObject class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_implementationObject::cPtr_implementationObject (const GALGAS_lbool & in_multiple,
                                                      const GALGAS_implementationObjectMap & in_attributes
                                                      COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_multiple (in_multiple),
mAttribute_attributes (in_attributes) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_implementationObject::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementationObject ;
}

void cPtr_implementationObject::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@implementationObject:" ;
  mAttribute_multiple.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_attributes.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_implementationObject::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_implementationObject (mAttribute_multiple, mAttribute_attributes COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @implementationObject type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_implementationObject ("implementationObject",
                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_implementationObject::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementationObject ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_implementationObject::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_implementationObject (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObject GALGAS_implementationObject::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_implementationObject result ;
  const GALGAS_implementationObject * p = (const GALGAS_implementationObject *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_implementationObject *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("implementationObject", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_library::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_library * p = (const cPtr_library *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_library) ;
  if (kOperandEqual == result) {
    result = mAttribute_funcMap.objectCompare (p->mAttribute_funcMap) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_getterMap.objectCompare (p->mAttribute_getterMap) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_setterMap.objectCompare (p->mAttribute_setterMap) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_templateMap.objectCompare (p->mAttribute_templateMap) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_doneImports.objectCompare (p->mAttribute_doneImports) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_library::objectCompare (const GALGAS_library & inOperand) const {
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

GALGAS_library::GALGAS_library (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_library GALGAS_library::constructor_default (LOCATION_ARGS) {
  return GALGAS_library::constructor_new (GALGAS_gtlFuncMap::constructor_emptyMap (HERE),
                                          GALGAS_gtlGetterMap::constructor_emptyMap (HERE),
                                          GALGAS_gtlSetterMap::constructor_emptyMap (HERE),
                                          GALGAS_gtlTemplateMap::constructor_emptyMap (HERE),
                                          GALGAS_stringset::constructor_emptySet (HERE)
                                          COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_library::GALGAS_library (const cPtr_library * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_library) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_library GALGAS_library::constructor_new (const GALGAS_gtlFuncMap & inAttribute_funcMap,
                                                const GALGAS_gtlGetterMap & inAttribute_getterMap,
                                                const GALGAS_gtlSetterMap & inAttribute_setterMap,
                                                const GALGAS_gtlTemplateMap & inAttribute_templateMap,
                                                const GALGAS_stringset & inAttribute_doneImports
                                                COMMA_LOCATION_ARGS) {
  GALGAS_library result ;
  if (inAttribute_funcMap.isValid () && inAttribute_getterMap.isValid () && inAttribute_setterMap.isValid () && inAttribute_templateMap.isValid () && inAttribute_doneImports.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_library (inAttribute_funcMap, inAttribute_getterMap, inAttribute_setterMap, inAttribute_templateMap, inAttribute_doneImports COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap GALGAS_library::getter_funcMap (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlFuncMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_library * p = (const cPtr_library *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_library) ;
    result = p->mAttribute_funcMap ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap cPtr_library::getter_funcMap (UNUSED_LOCATION_ARGS) const {
  return mAttribute_funcMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap GALGAS_library::getter_getterMap (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlGetterMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_library * p = (const cPtr_library *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_library) ;
    result = p->mAttribute_getterMap ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap cPtr_library::getter_getterMap (UNUSED_LOCATION_ARGS) const {
  return mAttribute_getterMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap GALGAS_library::getter_setterMap (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlSetterMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_library * p = (const cPtr_library *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_library) ;
    result = p->mAttribute_setterMap ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap cPtr_library::getter_setterMap (UNUSED_LOCATION_ARGS) const {
  return mAttribute_setterMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap GALGAS_library::getter_templateMap (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlTemplateMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_library * p = (const cPtr_library *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_library) ;
    result = p->mAttribute_templateMap ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap cPtr_library::getter_templateMap (UNUSED_LOCATION_ARGS) const {
  return mAttribute_templateMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset GALGAS_library::getter_doneImports (UNUSED_LOCATION_ARGS) const {
  GALGAS_stringset result ;
  if (NULL != mObjectPtr) {
    const cPtr_library * p = (const cPtr_library *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_library) ;
    result = p->mAttribute_doneImports ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset cPtr_library::getter_doneImports (UNUSED_LOCATION_ARGS) const {
  return mAttribute_doneImports ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @library class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_library::cPtr_library (const GALGAS_gtlFuncMap & in_funcMap,
                            const GALGAS_gtlGetterMap & in_getterMap,
                            const GALGAS_gtlSetterMap & in_setterMap,
                            const GALGAS_gtlTemplateMap & in_templateMap,
                            const GALGAS_stringset & in_doneImports
                            COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_funcMap (in_funcMap),
mAttribute_getterMap (in_getterMap),
mAttribute_setterMap (in_setterMap),
mAttribute_templateMap (in_templateMap),
mAttribute_doneImports (in_doneImports) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_library::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_library ;
}

void cPtr_library::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "[@library:" ;
  mAttribute_funcMap.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_getterMap.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_setterMap.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_templateMap.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_doneImports.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_library::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_library (mAttribute_funcMap, mAttribute_getterMap, mAttribute_setterMap, mAttribute_templateMap, mAttribute_doneImports COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @library type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_library ("library",
                                NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_library::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_library ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_library::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_library (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_library GALGAS_library::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_library result ;
  const GALGAS_library * p = (const GALGAS_library *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_library *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("library", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_objectAttributes::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_objectAttributes * p = (const cPtr_objectAttributes *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_objectAttributes) ;
  if (kOperandEqual == result) {
    result = mAttribute_objectParams.objectCompare (p->mAttribute_objectParams) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_objectAttributes::objectCompare (const GALGAS_objectAttributes & inOperand) const {
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

GALGAS_objectAttributes::GALGAS_objectAttributes (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes GALGAS_objectAttributes::constructor_default (LOCATION_ARGS) {
  return GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (HERE)
                                                   COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes::GALGAS_objectAttributes (const cPtr_objectAttributes * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_objectAttributes) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes GALGAS_objectAttributes::constructor_new (const GALGAS_identifierMap & inAttribute_objectParams
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_objectAttributes result ;
  if (inAttribute_objectParams.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_objectAttributes (inAttribute_objectParams COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap GALGAS_objectAttributes::getter_objectParams (UNUSED_LOCATION_ARGS) const {
  GALGAS_identifierMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_objectAttributes * p = (const cPtr_objectAttributes *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_objectAttributes) ;
    result = p->mAttribute_objectParams ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap cPtr_objectAttributes::getter_objectParams (UNUSED_LOCATION_ARGS) const {
  return mAttribute_objectParams ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectAttributes::setter_setObjectParams (GALGAS_identifierMap inValue
                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_objectAttributes * p = (cPtr_objectAttributes *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_objectAttributes) ;
    p->mAttribute_objectParams = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_objectAttributes::setter_setObjectParams (GALGAS_identifierMap inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_objectParams = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @objectAttributes class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_objectAttributes::cPtr_objectAttributes (const GALGAS_identifierMap & in_objectParams
                                              COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_objectParams (in_objectParams) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_objectAttributes::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectAttributes ;
}

void cPtr_objectAttributes::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@objectAttributes:" ;
  mAttribute_objectParams.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_objectAttributes::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_objectAttributes (mAttribute_objectParams COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @objectAttributes type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectAttributes ("objectAttributes",
                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_objectAttributes::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectAttributes ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_objectAttributes::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectAttributes (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes GALGAS_objectAttributes::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_objectAttributes result ;
  const GALGAS_objectAttributes * p = (const GALGAS_objectAttributes *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_objectAttributes *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectAttributes", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_objectKind::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_objectKind * p = (const cPtr_objectKind *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_objectKind) ;
  if (kOperandEqual == result) {
    result = mAttribute_objects.objectCompare (p->mAttribute_objects) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_objectKind::objectCompare (const GALGAS_objectKind & inOperand) const {
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

GALGAS_objectKind::GALGAS_objectKind (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKind GALGAS_objectKind::constructor_default (LOCATION_ARGS) {
  return GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (HERE)
                                             COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKind::GALGAS_objectKind (const cPtr_objectKind * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_objectKind) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKind GALGAS_objectKind::constructor_new (const GALGAS_objectKindMap & inAttribute_objects
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_objectKind result ;
  if (inAttribute_objects.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_objectKind (inAttribute_objects COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap GALGAS_objectKind::getter_objects (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectKindMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_objectKind * p = (const cPtr_objectKind *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_objectKind) ;
    result = p->mAttribute_objects ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap cPtr_objectKind::getter_objects (UNUSED_LOCATION_ARGS) const {
  return mAttribute_objects ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectKind::setter_setObjects (GALGAS_objectKindMap inValue
                                           COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_objectKind * p = (cPtr_objectKind *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_objectKind) ;
    p->mAttribute_objects = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_objectKind::setter_setObjects (GALGAS_objectKindMap inValue
                                         COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_objects = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                         Pointer class for @objectKind class                                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_objectKind::cPtr_objectKind (const GALGAS_objectKindMap & in_objects
                                  COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_objects (in_objects) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_objectKind::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectKind ;
}

void cPtr_objectKind::description (C_String & ioString,
                                   const int32_t inIndentation) const {
  ioString << "[@objectKind:" ;
  mAttribute_objects.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_objectKind::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_objectKind (mAttribute_objects COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @objectKind type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectKind ("objectKind",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_objectKind::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectKind ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_objectKind::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectKind (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKind GALGAS_objectKind::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_objectKind result ;
  const GALGAS_objectKind * p = (const GALGAS_objectKind *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_objectKind *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectKind", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_object_5F_t::objectCompare (const GALGAS_object_5F_t & inOperand) const {
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

GALGAS_object_5F_t::GALGAS_object_5F_t (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t::GALGAS_object_5F_t (const cPtr_object_5F_t * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_object_5F_t) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_object_5F_t::getter_oil_5F_desc (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_object_5F_t * p = (const cPtr_object_5F_t *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_object_5F_t) ;
    result = p->mAttribute_oil_5F_desc ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_object_5F_t::getter_oil_5F_desc (UNUSED_LOCATION_ARGS) const {
  return mAttribute_oil_5F_desc ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_object_5F_t::getter_location (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_object_5F_t * p = (const cPtr_object_5F_t *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_object_5F_t) ;
    result = p->mAttribute_location ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_object_5F_t::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @object_t class                                          *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_object_5F_t::cPtr_object_5F_t (const GALGAS_lstring & in_oil_5F_desc,
                                    const GALGAS_location & in_location
                                    COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_oil_5F_desc (in_oil_5F_desc),
mAttribute_location (in_location) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @object_t type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_object_5F_t ("object_t",
                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_object_5F_t::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_object_5F_t ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_object_5F_t::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_object_5F_t (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t GALGAS_object_5F_t::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_object_5F_t result ;
  const GALGAS_object_5F_t * p = (const GALGAS_object_5F_t *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_object_5F_t *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("object_t", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_auto::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_auto * p = (const cPtr_auto *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_auto) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_auto::objectCompare (const GALGAS_auto & inOperand) const {
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

GALGAS_auto::GALGAS_auto (void) :
GALGAS_object_5F_t () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_auto GALGAS_auto::constructor_default (LOCATION_ARGS) {
  return GALGAS_auto::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_location::constructor_nowhere (HERE)
                                       COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_auto::GALGAS_auto (const cPtr_auto * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_auto) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_auto GALGAS_auto::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                          const GALGAS_location & inAttribute_location
                                          COMMA_LOCATION_ARGS) {
  GALGAS_auto result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_auto (inAttribute_oil_5F_desc, inAttribute_location COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                            Pointer class for @auto class                                            *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_auto::cPtr_auto (const GALGAS_lstring & in_oil_5F_desc,
                      const GALGAS_location & in_location
                      COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_auto::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_auto ;
}

void cPtr_auto::description (C_String & ioString,
                             const int32_t inIndentation) const {
  ioString << "[@auto:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_auto::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_auto (mAttribute_oil_5F_desc, mAttribute_location COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                     @auto type                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_auto ("auto",
                             & kTypeDescriptor_GALGAS_object_5F_t) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_auto::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_auto ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_auto::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_auto (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_auto GALGAS_auto::extractObject (const GALGAS_object & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_auto result ;
  const GALGAS_auto * p = (const GALGAS_auto *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_auto *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("auto", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_boolAttribute::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_boolAttribute * p = (const cPtr_boolAttribute *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_boolAttribute) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_subAttributes.objectCompare (p->mAttribute_subAttributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_boolAttribute::objectCompare (const GALGAS_boolAttribute & inOperand) const {
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

GALGAS_boolAttribute::GALGAS_boolAttribute (void) :
GALGAS_object_5F_t () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_boolAttribute GALGAS_boolAttribute::constructor_default (LOCATION_ARGS) {
  return GALGAS_boolAttribute::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                GALGAS_location::constructor_nowhere (HERE),
                                                GALGAS_bool::constructor_default (HERE),
                                                GALGAS_objectAttributes::constructor_default (HERE)
                                                COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_boolAttribute::GALGAS_boolAttribute (const cPtr_boolAttribute * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_boolAttribute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_boolAttribute GALGAS_boolAttribute::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                            const GALGAS_location & inAttribute_location,
                                                            const GALGAS_bool & inAttribute_value,
                                                            const GALGAS_objectAttributes & inAttribute_subAttributes
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_boolAttribute result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid () && inAttribute_subAttributes.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_boolAttribute (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value, inAttribute_subAttributes COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_boolAttribute::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_boolAttribute * p = (const cPtr_boolAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_boolAttribute) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_boolAttribute::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes GALGAS_boolAttribute::getter_subAttributes (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectAttributes result ;
  if (NULL != mObjectPtr) {
    const cPtr_boolAttribute * p = (const cPtr_boolAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_boolAttribute) ;
    result = p->mAttribute_subAttributes ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes cPtr_boolAttribute::getter_subAttributes (UNUSED_LOCATION_ARGS) const {
  return mAttribute_subAttributes ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_boolAttribute::setter_setSubAttributes (GALGAS_objectAttributes inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_boolAttribute * p = (cPtr_boolAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_boolAttribute) ;
    p->mAttribute_subAttributes = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_boolAttribute::setter_setSubAttributes (GALGAS_objectAttributes inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_subAttributes = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @boolAttribute class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_boolAttribute::cPtr_boolAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                        const GALGAS_location & in_location,
                                        const GALGAS_bool & in_value,
                                        const GALGAS_objectAttributes & in_subAttributes
                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mAttribute_value (in_value),
mAttribute_subAttributes (in_subAttributes) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_boolAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_boolAttribute ;
}

void cPtr_boolAttribute::description (C_String & ioString,
                                      const int32_t inIndentation) const {
  ioString << "[@boolAttribute:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_subAttributes.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_boolAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_boolAttribute (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value, mAttribute_subAttributes COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @boolAttribute type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_boolAttribute ("boolAttribute",
                                      & kTypeDescriptor_GALGAS_object_5F_t) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_boolAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_boolAttribute ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_boolAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_boolAttribute (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_boolAttribute GALGAS_boolAttribute::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_boolAttribute result ;
  const GALGAS_boolAttribute * p = (const GALGAS_boolAttribute *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_boolAttribute *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("boolAttribute", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_bool_5F_t::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_bool_5F_t * p = (const cPtr_bool_5F_t *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_bool_5F_t) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_bool_5F_t::objectCompare (const GALGAS_bool_5F_t & inOperand) const {
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

GALGAS_bool_5F_t::GALGAS_bool_5F_t (void) :
GALGAS_object_5F_t () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool_5F_t GALGAS_bool_5F_t::constructor_default (LOCATION_ARGS) {
  return GALGAS_bool_5F_t::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                            GALGAS_location::constructor_nowhere (HERE),
                                            GALGAS_bool::constructor_default (HERE)
                                            COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool_5F_t::GALGAS_bool_5F_t (const cPtr_bool_5F_t * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_bool_5F_t) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool_5F_t GALGAS_bool_5F_t::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                    const GALGAS_location & inAttribute_location,
                                                    const GALGAS_bool & inAttribute_value
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_bool_5F_t result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_bool_5F_t (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_bool_5F_t::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_bool_5F_t * p = (const cPtr_bool_5F_t *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_bool_5F_t) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_bool_5F_t::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                           Pointer class for @bool_t class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_bool_5F_t::cPtr_bool_5F_t (const GALGAS_lstring & in_oil_5F_desc,
                                const GALGAS_location & in_location,
                                const GALGAS_bool & in_value
                                COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_bool_5F_t::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_bool_5F_t ;
}

void cPtr_bool_5F_t::description (C_String & ioString,
                                  const int32_t inIndentation) const {
  ioString << "[@bool_t:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_bool_5F_t::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_bool_5F_t (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @bool_t type                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_bool_5F_t ("bool_t",
                                  & kTypeDescriptor_GALGAS_object_5F_t) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_bool_5F_t::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_bool_5F_t ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_bool_5F_t::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_bool_5F_t (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool_5F_t GALGAS_bool_5F_t::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_bool_5F_t result ;
  const GALGAS_bool_5F_t * p = (const GALGAS_bool_5F_t *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_bool_5F_t *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("bool_t", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_void_5F_bool_5F_t::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void_5F_bool_5F_t * p = (const cPtr_void_5F_bool_5F_t *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void_5F_bool_5F_t) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_void_5F_bool_5F_t::objectCompare (const GALGAS_void_5F_bool_5F_t & inOperand) const {
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

GALGAS_void_5F_bool_5F_t::GALGAS_void_5F_bool_5F_t (void) :
GALGAS_bool_5F_t () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_bool_5F_t GALGAS_void_5F_bool_5F_t::constructor_default (LOCATION_ARGS) {
  return GALGAS_void_5F_bool_5F_t::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                    GALGAS_location::constructor_nowhere (HERE),
                                                    GALGAS_bool::constructor_default (HERE)
                                                    COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_bool_5F_t::GALGAS_void_5F_bool_5F_t (const cPtr_void_5F_bool_5F_t * inSourcePtr) :
GALGAS_bool_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_bool_5F_t) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_bool_5F_t GALGAS_void_5F_bool_5F_t::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                    const GALGAS_location & inAttribute_location,
                                                                    const GALGAS_bool & inAttribute_value
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_bool_5F_t result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_void_5F_bool_5F_t (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @void_bool_t class                                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_void_5F_bool_5F_t::cPtr_void_5F_bool_5F_t (const GALGAS_lstring & in_oil_5F_desc,
                                                const GALGAS_location & in_location,
                                                const GALGAS_bool & in_value
                                                COMMA_LOCATION_ARGS) :
cPtr_bool_5F_t (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_void_5F_bool_5F_t::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_bool_5F_t ;
}

void cPtr_void_5F_bool_5F_t::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@void_bool_t:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_void_5F_bool_5F_t::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void_5F_bool_5F_t (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @void_bool_t type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void_5F_bool_5F_t ("void_bool_t",
                                          & kTypeDescriptor_GALGAS_bool_5F_t) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_void_5F_bool_5F_t::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_bool_5F_t ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_void_5F_bool_5F_t::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_bool_5F_t (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_bool_5F_t GALGAS_void_5F_bool_5F_t::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_bool_5F_t result ;
  const GALGAS_void_5F_bool_5F_t * p = (const GALGAS_void_5F_bool_5F_t *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_void_5F_bool_5F_t *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("void_bool_t", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_enumAttribute::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_enumAttribute * p = (const cPtr_enumAttribute *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_enumAttribute) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_subAttributes.objectCompare (p->mAttribute_subAttributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_enumAttribute::objectCompare (const GALGAS_enumAttribute & inOperand) const {
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

GALGAS_enumAttribute::GALGAS_enumAttribute (void) :
GALGAS_object_5F_t () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumAttribute GALGAS_enumAttribute::constructor_default (LOCATION_ARGS) {
  return GALGAS_enumAttribute::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                GALGAS_location::constructor_nowhere (HERE),
                                                GALGAS_string::constructor_default (HERE),
                                                GALGAS_objectAttributes::constructor_default (HERE)
                                                COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumAttribute::GALGAS_enumAttribute (const cPtr_enumAttribute * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_enumAttribute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumAttribute GALGAS_enumAttribute::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                            const GALGAS_location & inAttribute_location,
                                                            const GALGAS_string & inAttribute_value,
                                                            const GALGAS_objectAttributes & inAttribute_subAttributes
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_enumAttribute result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid () && inAttribute_subAttributes.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_enumAttribute (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value, inAttribute_subAttributes COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_enumAttribute::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_enumAttribute * p = (const cPtr_enumAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_enumAttribute) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_enumAttribute::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes GALGAS_enumAttribute::getter_subAttributes (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectAttributes result ;
  if (NULL != mObjectPtr) {
    const cPtr_enumAttribute * p = (const cPtr_enumAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_enumAttribute) ;
    result = p->mAttribute_subAttributes ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes cPtr_enumAttribute::getter_subAttributes (UNUSED_LOCATION_ARGS) const {
  return mAttribute_subAttributes ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @enumAttribute class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_enumAttribute::cPtr_enumAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                        const GALGAS_location & in_location,
                                        const GALGAS_string & in_value,
                                        const GALGAS_objectAttributes & in_subAttributes
                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mAttribute_value (in_value),
mAttribute_subAttributes (in_subAttributes) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_enumAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_enumAttribute ;
}

void cPtr_enumAttribute::description (C_String & ioString,
                                      const int32_t inIndentation) const {
  ioString << "[@enumAttribute:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_subAttributes.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_enumAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_enumAttribute (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value, mAttribute_subAttributes COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @enumAttribute type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_enumAttribute ("enumAttribute",
                                      & kTypeDescriptor_GALGAS_object_5F_t) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_enumAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_enumAttribute ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_enumAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_enumAttribute (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumAttribute GALGAS_enumAttribute::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_enumAttribute result ;
  const GALGAS_enumAttribute * p = (const GALGAS_enumAttribute *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_enumAttribute *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("enumAttribute", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_float_5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_float_5F_class * p = (const cPtr_float_5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_float_5F_class) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_float_5F_class::objectCompare (const GALGAS_float_5F_class & inOperand) const {
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

GALGAS_float_5F_class::GALGAS_float_5F_class (void) :
GALGAS_object_5F_t () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_float_5F_class GALGAS_float_5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_float_5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                 GALGAS_location::constructor_nowhere (HERE),
                                                 GALGAS_double::constructor_default (HERE)
                                                 COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_float_5F_class::GALGAS_float_5F_class (const cPtr_float_5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_float_5F_class) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_float_5F_class GALGAS_float_5F_class::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                              const GALGAS_location & inAttribute_location,
                                                              const GALGAS_double & inAttribute_value
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_float_5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_float_5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_float_5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (NULL != mObjectPtr) {
    const cPtr_float_5F_class * p = (const cPtr_float_5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_float_5F_class) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double cPtr_float_5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @float_class class                                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_float_5F_class::cPtr_float_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                          const GALGAS_location & in_location,
                                          const GALGAS_double & in_value
                                          COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_float_5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_float_5F_class ;
}

void cPtr_float_5F_class::description (C_String & ioString,
                                       const int32_t inIndentation) const {
  ioString << "[@float_class:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_float_5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_float_5F_class (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @float_class type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_float_5F_class ("float_class",
                                       & kTypeDescriptor_GALGAS_object_5F_t) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_float_5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_float_5F_class ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_float_5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_float_5F_class (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_float_5F_class GALGAS_float_5F_class::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_float_5F_class result ;
  const GALGAS_float_5F_class * p = (const GALGAS_float_5F_class *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_float_5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("float_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_void_5F_float_5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void_5F_float_5F_class * p = (const cPtr_void_5F_float_5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void_5F_float_5F_class) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_void_5F_float_5F_class::objectCompare (const GALGAS_void_5F_float_5F_class & inOperand) const {
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

GALGAS_void_5F_float_5F_class::GALGAS_void_5F_float_5F_class (void) :
GALGAS_float_5F_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_float_5F_class GALGAS_void_5F_float_5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_void_5F_float_5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                         GALGAS_location::constructor_nowhere (HERE),
                                                         GALGAS_double::constructor_default (HERE)
                                                         COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_float_5F_class::GALGAS_void_5F_float_5F_class (const cPtr_void_5F_float_5F_class * inSourcePtr) :
GALGAS_float_5F_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_float_5F_class) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_float_5F_class GALGAS_void_5F_float_5F_class::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                              const GALGAS_location & inAttribute_location,
                                                                              const GALGAS_double & inAttribute_value
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_float_5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_void_5F_float_5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @void_float_class class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_void_5F_float_5F_class::cPtr_void_5F_float_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                          const GALGAS_location & in_location,
                                                          const GALGAS_double & in_value
                                                          COMMA_LOCATION_ARGS) :
cPtr_float_5F_class (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_void_5F_float_5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_float_5F_class ;
}

void cPtr_void_5F_float_5F_class::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@void_float_class:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_void_5F_float_5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void_5F_float_5F_class (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @void_float_class type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void_5F_float_5F_class ("void_float_class",
                                               & kTypeDescriptor_GALGAS_float_5F_class) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_void_5F_float_5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_float_5F_class ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_void_5F_float_5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_float_5F_class (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_float_5F_class GALGAS_void_5F_float_5F_class::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_float_5F_class result ;
  const GALGAS_void_5F_float_5F_class * p = (const GALGAS_void_5F_float_5F_class *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_void_5F_float_5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("void_float_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_multipleAttribute::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_multipleAttribute * p = (const cPtr_multipleAttribute *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_multipleAttribute) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_items.objectCompare (p->mAttribute_items) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_multipleAttribute::objectCompare (const GALGAS_multipleAttribute & inOperand) const {
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

GALGAS_multipleAttribute::GALGAS_multipleAttribute (void) :
GALGAS_object_5F_t () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_multipleAttribute GALGAS_multipleAttribute::constructor_default (LOCATION_ARGS) {
  return GALGAS_multipleAttribute::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                    GALGAS_location::constructor_nowhere (HERE),
                                                    GALGAS_identifierList::constructor_emptyList (HERE)
                                                    COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_multipleAttribute::GALGAS_multipleAttribute (const cPtr_multipleAttribute * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_multipleAttribute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_multipleAttribute GALGAS_multipleAttribute::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                    const GALGAS_location & inAttribute_location,
                                                                    const GALGAS_identifierList & inAttribute_items
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_multipleAttribute result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_items.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_multipleAttribute (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_items COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList GALGAS_multipleAttribute::getter_items (UNUSED_LOCATION_ARGS) const {
  GALGAS_identifierList result ;
  if (NULL != mObjectPtr) {
    const cPtr_multipleAttribute * p = (const cPtr_multipleAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_multipleAttribute) ;
    result = p->mAttribute_items ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList cPtr_multipleAttribute::getter_items (UNUSED_LOCATION_ARGS) const {
  return mAttribute_items ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @multipleAttribute class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_multipleAttribute::cPtr_multipleAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                                const GALGAS_location & in_location,
                                                const GALGAS_identifierList & in_items
                                                COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mAttribute_items (in_items) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_multipleAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_multipleAttribute ;
}

void cPtr_multipleAttribute::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@multipleAttribute:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_items.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_multipleAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_multipleAttribute (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_items COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @multipleAttribute type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_multipleAttribute ("multipleAttribute",
                                          & kTypeDescriptor_GALGAS_object_5F_t) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_multipleAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_multipleAttribute ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_multipleAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_multipleAttribute (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_multipleAttribute GALGAS_multipleAttribute::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_multipleAttribute result ;
  const GALGAS_multipleAttribute * p = (const GALGAS_multipleAttribute *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_multipleAttribute *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("multipleAttribute", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_objectRefAttribute::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_objectRefAttribute * p = (const cPtr_objectRefAttribute *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_objectRefAttribute) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_objectRefAttribute::objectCompare (const GALGAS_objectRefAttribute & inOperand) const {
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

GALGAS_objectRefAttribute::GALGAS_objectRefAttribute (void) :
GALGAS_object_5F_t () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectRefAttribute GALGAS_objectRefAttribute::constructor_default (LOCATION_ARGS) {
  return GALGAS_objectRefAttribute::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                     GALGAS_location::constructor_nowhere (HERE),
                                                     GALGAS_lstring::constructor_default (HERE)
                                                     COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectRefAttribute::GALGAS_objectRefAttribute (const cPtr_objectRefAttribute * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_objectRefAttribute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectRefAttribute GALGAS_objectRefAttribute::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                      const GALGAS_location & inAttribute_location,
                                                                      const GALGAS_lstring & inAttribute_value
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_objectRefAttribute result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_objectRefAttribute (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_objectRefAttribute::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_objectRefAttribute * p = (const cPtr_objectRefAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_objectRefAttribute) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_objectRefAttribute::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @objectRefAttribute class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_objectRefAttribute::cPtr_objectRefAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                                  const GALGAS_location & in_location,
                                                  const GALGAS_lstring & in_value
                                                  COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_objectRefAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectRefAttribute ;
}

void cPtr_objectRefAttribute::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@objectRefAttribute:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_objectRefAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_objectRefAttribute (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @objectRefAttribute type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectRefAttribute ("objectRefAttribute",
                                           & kTypeDescriptor_GALGAS_object_5F_t) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_objectRefAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectRefAttribute ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_objectRefAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectRefAttribute (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectRefAttribute GALGAS_objectRefAttribute::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_objectRefAttribute result ;
  const GALGAS_objectRefAttribute * p = (const GALGAS_objectRefAttribute *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_objectRefAttribute *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectRefAttribute", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_sint_33__32__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_33__32__5F_class * p = (const cPtr_sint_33__32__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_33__32__5F_class) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_sint_33__32__5F_class::objectCompare (const GALGAS_sint_33__32__5F_class & inOperand) const {
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

GALGAS_sint_33__32__5F_class::GALGAS_sint_33__32__5F_class (void) :
GALGAS_object_5F_t () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32__5F_class GALGAS_sint_33__32__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_33__32__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_location::constructor_nowhere (HERE),
                                                        GALGAS_sint::constructor_default (HERE)
                                                        COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32__5F_class::GALGAS_sint_33__32__5F_class (const cPtr_sint_33__32__5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_33__32__5F_class) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32__5F_class GALGAS_sint_33__32__5F_class::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                            const GALGAS_location & inAttribute_location,
                                                                            const GALGAS_sint & inAttribute_value
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sint_33__32__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint_33__32__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_33__32__5F_class * p = (const cPtr_sint_33__32__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32__5F_class) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint cPtr_sint_33__32__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @sint32_class class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_sint_33__32__5F_class::cPtr_sint_33__32__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                        const GALGAS_location & in_location,
                                                        const GALGAS_sint & in_value
                                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_sint_33__32__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32__5F_class ;
}

void cPtr_sint_33__32__5F_class::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@sint32_class:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_sint_33__32__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_sint_33__32__5F_class (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @sint32_class type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_33__32__5F_class ("sint32_class",
                                              & kTypeDescriptor_GALGAS_object_5F_t) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sint_33__32__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32__5F_class ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sint_33__32__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_33__32__5F_class (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32__5F_class GALGAS_sint_33__32__5F_class::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32__5F_class result ;
  const GALGAS_sint_33__32__5F_class * p = (const GALGAS_sint_33__32__5F_class *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_33__32__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint32_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_void_5F_sint_33__32__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void_5F_sint_33__32__5F_class * p = (const cPtr_void_5F_sint_33__32__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void_5F_sint_33__32__5F_class) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_void_5F_sint_33__32__5F_class::objectCompare (const GALGAS_void_5F_sint_33__32__5F_class & inOperand) const {
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

GALGAS_void_5F_sint_33__32__5F_class::GALGAS_void_5F_sint_33__32__5F_class (void) :
GALGAS_sint_33__32__5F_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_sint_33__32__5F_class GALGAS_void_5F_sint_33__32__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_void_5F_sint_33__32__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                                GALGAS_location::constructor_nowhere (HERE),
                                                                GALGAS_sint::constructor_default (HERE)
                                                                COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_sint_33__32__5F_class::GALGAS_void_5F_sint_33__32__5F_class (const cPtr_void_5F_sint_33__32__5F_class * inSourcePtr) :
GALGAS_sint_33__32__5F_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_sint_33__32__5F_class) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_sint_33__32__5F_class GALGAS_void_5F_sint_33__32__5F_class::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                                            const GALGAS_location & inAttribute_location,
                                                                                            const GALGAS_sint & inAttribute_value
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_sint_33__32__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_void_5F_sint_33__32__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @void_sint32_class class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_void_5F_sint_33__32__5F_class::cPtr_void_5F_sint_33__32__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                                        const GALGAS_location & in_location,
                                                                        const GALGAS_sint & in_value
                                                                        COMMA_LOCATION_ARGS) :
cPtr_sint_33__32__5F_class (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_void_5F_sint_33__32__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_sint_33__32__5F_class ;
}

void cPtr_void_5F_sint_33__32__5F_class::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "[@void_sint32_class:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_void_5F_sint_33__32__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void_5F_sint_33__32__5F_class (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @void_sint32_class type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void_5F_sint_33__32__5F_class ("void_sint32_class",
                                                      & kTypeDescriptor_GALGAS_sint_33__32__5F_class) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_void_5F_sint_33__32__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_sint_33__32__5F_class ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_void_5F_sint_33__32__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_sint_33__32__5F_class (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_sint_33__32__5F_class GALGAS_void_5F_sint_33__32__5F_class::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_sint_33__32__5F_class result ;
  const GALGAS_void_5F_sint_33__32__5F_class * p = (const GALGAS_void_5F_sint_33__32__5F_class *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_void_5F_sint_33__32__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("void_sint32_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_sint_36__34__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_36__34__5F_class * p = (const cPtr_sint_36__34__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_36__34__5F_class) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_sint_36__34__5F_class::objectCompare (const GALGAS_sint_36__34__5F_class & inOperand) const {
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

GALGAS_sint_36__34__5F_class::GALGAS_sint_36__34__5F_class (void) :
GALGAS_object_5F_t () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34__5F_class GALGAS_sint_36__34__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_36__34__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_location::constructor_nowhere (HERE),
                                                        GALGAS_sint_36__34_::constructor_default (HERE)
                                                        COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34__5F_class::GALGAS_sint_36__34__5F_class (const cPtr_sint_36__34__5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_36__34__5F_class) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34__5F_class GALGAS_sint_36__34__5F_class::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                            const GALGAS_location & inAttribute_location,
                                                                            const GALGAS_sint_36__34_ & inAttribute_value
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sint_36__34__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_36__34__5F_class * p = (const cPtr_sint_36__34__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34__5F_class) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ cPtr_sint_36__34__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @sint64_class class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_sint_36__34__5F_class::cPtr_sint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                        const GALGAS_location & in_location,
                                                        const GALGAS_sint_36__34_ & in_value
                                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_sint_36__34__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34__5F_class ;
}

void cPtr_sint_36__34__5F_class::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@sint64_class:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_sint_36__34__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_sint_36__34__5F_class (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @sint64_class type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_36__34__5F_class ("sint64_class",
                                              & kTypeDescriptor_GALGAS_object_5F_t) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sint_36__34__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34__5F_class ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sint_36__34__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_36__34__5F_class (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34__5F_class GALGAS_sint_36__34__5F_class::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34__5F_class result ;
  const GALGAS_sint_36__34__5F_class * p = (const GALGAS_sint_36__34__5F_class *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_36__34__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint64_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_void_5F_sint_36__34__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void_5F_sint_36__34__5F_class * p = (const cPtr_void_5F_sint_36__34__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void_5F_sint_36__34__5F_class) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_void_5F_sint_36__34__5F_class::objectCompare (const GALGAS_void_5F_sint_36__34__5F_class & inOperand) const {
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

GALGAS_void_5F_sint_36__34__5F_class::GALGAS_void_5F_sint_36__34__5F_class (void) :
GALGAS_sint_36__34__5F_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_sint_36__34__5F_class GALGAS_void_5F_sint_36__34__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_void_5F_sint_36__34__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                                GALGAS_location::constructor_nowhere (HERE),
                                                                GALGAS_sint_36__34_::constructor_default (HERE)
                                                                COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_sint_36__34__5F_class::GALGAS_void_5F_sint_36__34__5F_class (const cPtr_void_5F_sint_36__34__5F_class * inSourcePtr) :
GALGAS_sint_36__34__5F_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_sint_36__34__5F_class) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_sint_36__34__5F_class GALGAS_void_5F_sint_36__34__5F_class::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                                            const GALGAS_location & inAttribute_location,
                                                                                            const GALGAS_sint_36__34_ & inAttribute_value
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_sint_36__34__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_void_5F_sint_36__34__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @void_sint64_class class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_void_5F_sint_36__34__5F_class::cPtr_void_5F_sint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                                        const GALGAS_location & in_location,
                                                                        const GALGAS_sint_36__34_ & in_value
                                                                        COMMA_LOCATION_ARGS) :
cPtr_sint_36__34__5F_class (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_void_5F_sint_36__34__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_sint_36__34__5F_class ;
}

void cPtr_void_5F_sint_36__34__5F_class::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "[@void_sint64_class:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_void_5F_sint_36__34__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void_5F_sint_36__34__5F_class (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @void_sint64_class type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void_5F_sint_36__34__5F_class ("void_sint64_class",
                                                      & kTypeDescriptor_GALGAS_sint_36__34__5F_class) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_void_5F_sint_36__34__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_sint_36__34__5F_class ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_void_5F_sint_36__34__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_sint_36__34__5F_class (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_sint_36__34__5F_class GALGAS_void_5F_sint_36__34__5F_class::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_sint_36__34__5F_class result ;
  const GALGAS_void_5F_sint_36__34__5F_class * p = (const GALGAS_void_5F_sint_36__34__5F_class *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_void_5F_sint_36__34__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("void_sint64_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_stringAttribute::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_stringAttribute * p = (const cPtr_stringAttribute *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_stringAttribute) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_stringAttribute::objectCompare (const GALGAS_stringAttribute & inOperand) const {
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

GALGAS_stringAttribute::GALGAS_stringAttribute (void) :
GALGAS_object_5F_t () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringAttribute GALGAS_stringAttribute::constructor_default (LOCATION_ARGS) {
  return GALGAS_stringAttribute::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                  GALGAS_location::constructor_nowhere (HERE),
                                                  GALGAS_string::constructor_default (HERE)
                                                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringAttribute::GALGAS_stringAttribute (const cPtr_stringAttribute * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_stringAttribute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringAttribute GALGAS_stringAttribute::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                const GALGAS_location & inAttribute_location,
                                                                const GALGAS_string & inAttribute_value
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_stringAttribute result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_stringAttribute (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_stringAttribute::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_stringAttribute * p = (const cPtr_stringAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_stringAttribute) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_stringAttribute::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @stringAttribute class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_stringAttribute::cPtr_stringAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                            const GALGAS_location & in_location,
                                            const GALGAS_string & in_value
                                            COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_stringAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringAttribute ;
}

void cPtr_stringAttribute::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@stringAttribute:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_stringAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_stringAttribute (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @stringAttribute type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringAttribute ("stringAttribute",
                                        & kTypeDescriptor_GALGAS_object_5F_t) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_stringAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringAttribute ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_stringAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringAttribute (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringAttribute GALGAS_stringAttribute::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_stringAttribute result ;
  const GALGAS_stringAttribute * p = (const GALGAS_stringAttribute *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_stringAttribute *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringAttribute", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_string_5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_string_5F_class * p = (const cPtr_string_5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_string_5F_class) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_string_5F_class::objectCompare (const GALGAS_string_5F_class & inOperand) const {
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

GALGAS_string_5F_class::GALGAS_string_5F_class (void) :
GALGAS_object_5F_t () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string_5F_class GALGAS_string_5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_string_5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                  GALGAS_location::constructor_nowhere (HERE),
                                                  GALGAS_string::constructor_default (HERE)
                                                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string_5F_class::GALGAS_string_5F_class (const cPtr_string_5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_string_5F_class) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string_5F_class GALGAS_string_5F_class::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                const GALGAS_location & inAttribute_location,
                                                                const GALGAS_string & inAttribute_value
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_string_5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_string_5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string_5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_string_5F_class * p = (const cPtr_string_5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_string_5F_class) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_string_5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @string_class class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_string_5F_class::cPtr_string_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                            const GALGAS_location & in_location,
                                            const GALGAS_string & in_value
                                            COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_string_5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_string_5F_class ;
}

void cPtr_string_5F_class::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@string_class:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_string_5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_string_5F_class (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @string_class type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_string_5F_class ("string_class",
                                        & kTypeDescriptor_GALGAS_object_5F_t) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_string_5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_string_5F_class ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_string_5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_string_5F_class (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string_5F_class GALGAS_string_5F_class::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_string_5F_class result ;
  const GALGAS_string_5F_class * p = (const GALGAS_string_5F_class *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_string_5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("string_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_void_5F_string_5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void_5F_string_5F_class * p = (const cPtr_void_5F_string_5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void_5F_string_5F_class) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_void_5F_string_5F_class::objectCompare (const GALGAS_void_5F_string_5F_class & inOperand) const {
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

GALGAS_void_5F_string_5F_class::GALGAS_void_5F_string_5F_class (void) :
GALGAS_string_5F_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_string_5F_class GALGAS_void_5F_string_5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_void_5F_string_5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                          GALGAS_location::constructor_nowhere (HERE),
                                                          GALGAS_string::constructor_default (HERE)
                                                          COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_string_5F_class::GALGAS_void_5F_string_5F_class (const cPtr_void_5F_string_5F_class * inSourcePtr) :
GALGAS_string_5F_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_string_5F_class) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_string_5F_class GALGAS_void_5F_string_5F_class::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                                const GALGAS_location & inAttribute_location,
                                                                                const GALGAS_string & inAttribute_value
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_string_5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_void_5F_string_5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @void_string_class class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_void_5F_string_5F_class::cPtr_void_5F_string_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                            const GALGAS_location & in_location,
                                                            const GALGAS_string & in_value
                                                            COMMA_LOCATION_ARGS) :
cPtr_string_5F_class (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_void_5F_string_5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_string_5F_class ;
}

void cPtr_void_5F_string_5F_class::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@void_string_class:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_void_5F_string_5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void_5F_string_5F_class (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @void_string_class type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void_5F_string_5F_class ("void_string_class",
                                                & kTypeDescriptor_GALGAS_string_5F_class) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_void_5F_string_5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_string_5F_class ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_void_5F_string_5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_string_5F_class (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_string_5F_class GALGAS_void_5F_string_5F_class::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_string_5F_class result ;
  const GALGAS_void_5F_string_5F_class * p = (const GALGAS_void_5F_string_5F_class *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_void_5F_string_5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("void_string_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_structAttribute::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_structAttribute * p = (const cPtr_structAttribute *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_structAttribute) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_structName.objectCompare (p->mAttribute_structName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_subAttributes.objectCompare (p->mAttribute_subAttributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_structAttribute::objectCompare (const GALGAS_structAttribute & inOperand) const {
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

GALGAS_structAttribute::GALGAS_structAttribute (void) :
GALGAS_object_5F_t () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structAttribute GALGAS_structAttribute::constructor_default (LOCATION_ARGS) {
  return GALGAS_structAttribute::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                  GALGAS_location::constructor_nowhere (HERE),
                                                  GALGAS_lstring::constructor_default (HERE),
                                                  GALGAS_objectAttributes::constructor_default (HERE)
                                                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structAttribute::GALGAS_structAttribute (const cPtr_structAttribute * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_structAttribute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structAttribute GALGAS_structAttribute::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                const GALGAS_location & inAttribute_location,
                                                                const GALGAS_lstring & inAttribute_structName,
                                                                const GALGAS_objectAttributes & inAttribute_subAttributes
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_structAttribute result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_structName.isValid () && inAttribute_subAttributes.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_structAttribute (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_structName, inAttribute_subAttributes COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_structAttribute::getter_structName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_structAttribute * p = (const cPtr_structAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_structAttribute) ;
    result = p->mAttribute_structName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_structAttribute::getter_structName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_structName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes GALGAS_structAttribute::getter_subAttributes (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectAttributes result ;
  if (NULL != mObjectPtr) {
    const cPtr_structAttribute * p = (const cPtr_structAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_structAttribute) ;
    result = p->mAttribute_subAttributes ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes cPtr_structAttribute::getter_subAttributes (UNUSED_LOCATION_ARGS) const {
  return mAttribute_subAttributes ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @structAttribute class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_structAttribute::cPtr_structAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                            const GALGAS_location & in_location,
                                            const GALGAS_lstring & in_structName,
                                            const GALGAS_objectAttributes & in_subAttributes
                                            COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mAttribute_structName (in_structName),
mAttribute_subAttributes (in_subAttributes) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_structAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_structAttribute ;
}

void cPtr_structAttribute::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@structAttribute:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_structName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_subAttributes.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_structAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_structAttribute (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_structName, mAttribute_subAttributes COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @structAttribute type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_structAttribute ("structAttribute",
                                        & kTypeDescriptor_GALGAS_object_5F_t) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_structAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_structAttribute ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_structAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_structAttribute (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structAttribute GALGAS_structAttribute::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_structAttribute result ;
  const GALGAS_structAttribute * p = (const GALGAS_structAttribute *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_structAttribute *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("structAttribute", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_uint_33__32__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_33__32__5F_class * p = (const cPtr_uint_33__32__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_33__32__5F_class) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_uint_33__32__5F_class::objectCompare (const GALGAS_uint_33__32__5F_class & inOperand) const {
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

GALGAS_uint_33__32__5F_class::GALGAS_uint_33__32__5F_class (void) :
GALGAS_object_5F_t () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32__5F_class GALGAS_uint_33__32__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_33__32__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_location::constructor_nowhere (HERE),
                                                        GALGAS_uint::constructor_default (HERE)
                                                        COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32__5F_class::GALGAS_uint_33__32__5F_class (const cPtr_uint_33__32__5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_33__32__5F_class) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32__5F_class GALGAS_uint_33__32__5F_class::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                            const GALGAS_location & inAttribute_location,
                                                                            const GALGAS_uint & inAttribute_value
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_33__32__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint_33__32__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_uint_33__32__5F_class * p = (const cPtr_uint_33__32__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32__5F_class) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cPtr_uint_33__32__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @uint32_class class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_uint_33__32__5F_class::cPtr_uint_33__32__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                        const GALGAS_location & in_location,
                                                        const GALGAS_uint & in_value
                                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_uint_33__32__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32__5F_class ;
}

void cPtr_uint_33__32__5F_class::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@uint32_class:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_uint_33__32__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_uint_33__32__5F_class (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @uint32_class type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_33__32__5F_class ("uint32_class",
                                              & kTypeDescriptor_GALGAS_object_5F_t) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_uint_33__32__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32__5F_class ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_uint_33__32__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_33__32__5F_class (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32__5F_class GALGAS_uint_33__32__5F_class::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32__5F_class result ;
  const GALGAS_uint_33__32__5F_class * p = (const GALGAS_uint_33__32__5F_class *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_33__32__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint32_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_void_5F_uint_33__32__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void_5F_uint_33__32__5F_class * p = (const cPtr_void_5F_uint_33__32__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void_5F_uint_33__32__5F_class) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_void_5F_uint_33__32__5F_class::objectCompare (const GALGAS_void_5F_uint_33__32__5F_class & inOperand) const {
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

GALGAS_void_5F_uint_33__32__5F_class::GALGAS_void_5F_uint_33__32__5F_class (void) :
GALGAS_uint_33__32__5F_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_uint_33__32__5F_class GALGAS_void_5F_uint_33__32__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_void_5F_uint_33__32__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                                GALGAS_location::constructor_nowhere (HERE),
                                                                GALGAS_uint::constructor_default (HERE)
                                                                COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_uint_33__32__5F_class::GALGAS_void_5F_uint_33__32__5F_class (const cPtr_void_5F_uint_33__32__5F_class * inSourcePtr) :
GALGAS_uint_33__32__5F_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_uint_33__32__5F_class) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_uint_33__32__5F_class GALGAS_void_5F_uint_33__32__5F_class::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                                            const GALGAS_location & inAttribute_location,
                                                                                            const GALGAS_uint & inAttribute_value
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_uint_33__32__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_void_5F_uint_33__32__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @void_uint32_class class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_void_5F_uint_33__32__5F_class::cPtr_void_5F_uint_33__32__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                                        const GALGAS_location & in_location,
                                                                        const GALGAS_uint & in_value
                                                                        COMMA_LOCATION_ARGS) :
cPtr_uint_33__32__5F_class (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_void_5F_uint_33__32__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_uint_33__32__5F_class ;
}

void cPtr_void_5F_uint_33__32__5F_class::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "[@void_uint32_class:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_void_5F_uint_33__32__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void_5F_uint_33__32__5F_class (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @void_uint32_class type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void_5F_uint_33__32__5F_class ("void_uint32_class",
                                                      & kTypeDescriptor_GALGAS_uint_33__32__5F_class) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_void_5F_uint_33__32__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_uint_33__32__5F_class ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_void_5F_uint_33__32__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_uint_33__32__5F_class (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_uint_33__32__5F_class GALGAS_void_5F_uint_33__32__5F_class::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_uint_33__32__5F_class result ;
  const GALGAS_void_5F_uint_33__32__5F_class * p = (const GALGAS_void_5F_uint_33__32__5F_class *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_void_5F_uint_33__32__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("void_uint32_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_uint_36__34__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_36__34__5F_class * p = (const cPtr_uint_36__34__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_36__34__5F_class) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_uint_36__34__5F_class::objectCompare (const GALGAS_uint_36__34__5F_class & inOperand) const {
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

GALGAS_uint_36__34__5F_class::GALGAS_uint_36__34__5F_class (void) :
GALGAS_object_5F_t () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34__5F_class GALGAS_uint_36__34__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_36__34__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_location::constructor_nowhere (HERE),
                                                        GALGAS_uint_36__34_::constructor_default (HERE)
                                                        COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34__5F_class::GALGAS_uint_36__34__5F_class (const cPtr_uint_36__34__5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_36__34__5F_class) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34__5F_class GALGAS_uint_36__34__5F_class::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                            const GALGAS_location & inAttribute_location,
                                                                            const GALGAS_uint_36__34_ & inAttribute_value
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_36__34__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (NULL != mObjectPtr) {
    const cPtr_uint_36__34__5F_class * p = (const cPtr_uint_36__34__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34__5F_class) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ cPtr_uint_36__34__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @uint64_class class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_uint_36__34__5F_class::cPtr_uint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                        const GALGAS_location & in_location,
                                                        const GALGAS_uint_36__34_ & in_value
                                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_uint_36__34__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34__5F_class ;
}

void cPtr_uint_36__34__5F_class::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@uint64_class:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_uint_36__34__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_uint_36__34__5F_class (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @uint64_class type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34__5F_class ("uint64_class",
                                              & kTypeDescriptor_GALGAS_object_5F_t) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_uint_36__34__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34__5F_class ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_uint_36__34__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34__5F_class (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34__5F_class GALGAS_uint_36__34__5F_class::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34__5F_class result ;
  const GALGAS_uint_36__34__5F_class * p = (const GALGAS_uint_36__34__5F_class *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_36__34__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_void_5F_uint_36__34__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void_5F_uint_36__34__5F_class * p = (const cPtr_void_5F_uint_36__34__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void_5F_uint_36__34__5F_class) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_void_5F_uint_36__34__5F_class::objectCompare (const GALGAS_void_5F_uint_36__34__5F_class & inOperand) const {
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

GALGAS_void_5F_uint_36__34__5F_class::GALGAS_void_5F_uint_36__34__5F_class (void) :
GALGAS_uint_36__34__5F_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_uint_36__34__5F_class GALGAS_void_5F_uint_36__34__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_void_5F_uint_36__34__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                                GALGAS_location::constructor_nowhere (HERE),
                                                                GALGAS_uint_36__34_::constructor_default (HERE)
                                                                COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_uint_36__34__5F_class::GALGAS_void_5F_uint_36__34__5F_class (const cPtr_void_5F_uint_36__34__5F_class * inSourcePtr) :
GALGAS_uint_36__34__5F_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_uint_36__34__5F_class) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_uint_36__34__5F_class GALGAS_void_5F_uint_36__34__5F_class::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                                            const GALGAS_location & inAttribute_location,
                                                                                            const GALGAS_uint_36__34_ & inAttribute_value
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_uint_36__34__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_void_5F_uint_36__34__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @void_uint64_class class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_void_5F_uint_36__34__5F_class::cPtr_void_5F_uint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                                        const GALGAS_location & in_location,
                                                                        const GALGAS_uint_36__34_ & in_value
                                                                        COMMA_LOCATION_ARGS) :
cPtr_uint_36__34__5F_class (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_void_5F_uint_36__34__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_uint_36__34__5F_class ;
}

void cPtr_void_5F_uint_36__34__5F_class::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "[@void_uint64_class:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_void_5F_uint_36__34__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void_5F_uint_36__34__5F_class (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @void_uint64_class type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void_5F_uint_36__34__5F_class ("void_uint64_class",
                                                      & kTypeDescriptor_GALGAS_uint_36__34__5F_class) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_void_5F_uint_36__34__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_uint_36__34__5F_class ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_void_5F_uint_36__34__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_uint_36__34__5F_class (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void_5F_uint_36__34__5F_class GALGAS_void_5F_uint_36__34__5F_class::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_uint_36__34__5F_class result ;
  const GALGAS_void_5F_uint_36__34__5F_class * p = (const GALGAS_void_5F_uint_36__34__5F_class *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_void_5F_uint_36__34__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("void_uint64_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_void::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void * p = (const cPtr_void *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_void::objectCompare (const GALGAS_void & inOperand) const {
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

GALGAS_void::GALGAS_void (void) :
GALGAS_object_5F_t () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void GALGAS_void::constructor_default (LOCATION_ARGS) {
  return GALGAS_void::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_location::constructor_nowhere (HERE)
                                       COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void::GALGAS_void (const cPtr_void * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void GALGAS_void::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                          const GALGAS_location & inAttribute_location
                                          COMMA_LOCATION_ARGS) {
  GALGAS_void result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_void (inAttribute_oil_5F_desc, inAttribute_location COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                            Pointer class for @void class                                            *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_void::cPtr_void (const GALGAS_lstring & in_oil_5F_desc,
                      const GALGAS_location & in_location
                      COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_void::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void ;
}

void cPtr_void::description (C_String & ioString,
                             const int32_t inIndentation) const {
  ioString << "[@void:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_void::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void (mAttribute_oil_5F_desc, mAttribute_location COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                     @void type                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void ("void",
                             & kTypeDescriptor_GALGAS_object_5F_t) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_void::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_void::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_void GALGAS_void::extractObject (const GALGAS_object & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_void result ;
  const GALGAS_void * p = (const GALGAS_void *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_void *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("void", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_oil_5F_obj::objectCompare (const GALGAS_oil_5F_obj & inOperand) const {
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

GALGAS_oil_5F_obj::GALGAS_oil_5F_obj (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_oil_5F_obj::GALGAS_oil_5F_obj (const cPtr_oil_5F_obj * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_oil_5F_obj) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_oil_5F_obj::getter_desc (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_oil_5F_obj * p = (const cPtr_oil_5F_obj *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_oil_5F_obj) ;
    result = p->mAttribute_desc ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_oil_5F_obj::getter_desc (UNUSED_LOCATION_ARGS) const {
  return mAttribute_desc ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @oil_obj class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_oil_5F_obj::cPtr_oil_5F_obj (const GALGAS_lstring & in_desc
                                  COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_desc (in_desc) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @oil_obj type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_oil_5F_obj ("oil_obj",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_oil_5F_obj::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_oil_5F_obj ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_oil_5F_obj::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_oil_5F_obj (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_oil_5F_obj GALGAS_oil_5F_obj::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_oil_5F_obj result ;
  const GALGAS_oil_5F_obj * p = (const GALGAS_oil_5F_obj *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_oil_5F_obj *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("oil_obj", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
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
  return "3.0.4" ;
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

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension Getter '@string stringByAppendingPath'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_stringByAppendingPath (const GALGAS_string & inObject,
                                                     const GALGAS_string & constinArgument_pathToAppend,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_string temp_0 = inObject ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, temp_0.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_1) {
    result_result = constinArgument_pathToAppend ;
  }else if (kBoolFalse == test_1) {
    const GALGAS_string temp_2 = inObject ;
    const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, temp_2.getter_lastCharacter (inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 149)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
    if (kBoolTrue == test_3) {
      const GALGAS_string temp_4 = inObject ;
      result_result = temp_4.add_operation (constinArgument_pathToAppend, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 150)) ;
    }else if (kBoolFalse == test_3) {
      const GALGAS_string temp_5 = inObject ;
      result_result = temp_5.add_operation (GALGAS_char (TO_UNICODE (47)).getter_string (SOURCE_FILE ("gtl_types.galgas", 152)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 152)).add_operation (constinArgument_pathToAppend, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 152)) ;
    }
  }
//---
  return result_result ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension method '@gtlVarMap replaceOrCreate'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_replaceOrCreate (GALGAS_gtlVarMap & ioObject,
                                      const GALGAS_lstring constinArgument_key,
                                      const GALGAS_gtlData constinArgument_data,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_gtlVarMap temp_0 = ioObject ;
  const enumGalgasBool test_1 = temp_0.getter_hasKey (constinArgument_key.getter_string (SOURCE_FILE ("gtl_types.galgas", 181)) COMMA_SOURCE_FILE ("gtl_types.galgas", 181)).boolEnum () ;
  if (kBoolTrue == test_1) {
    {
    ioObject.setter_setValueForKey (constinArgument_data, constinArgument_key.getter_string (SOURCE_FILE ("gtl_types.galgas", 182)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 182)) ;
    }
  }else if (kBoolFalse == test_1) {
    {
    ioObject.setter_put (constinArgument_key, constinArgument_data, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 184)) ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Extension method '@gtlVarMap replaceOrCreateAtLevel'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_replaceOrCreateAtLevel (GALGAS_gtlVarMap & ioObject,
                                             const GALGAS_lstring constinArgument_key,
                                             const GALGAS_gtlData constinArgument_data,
                                             const GALGAS_uint constinArgument_level,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_gtlVarMap temp_0 = ioObject ;
  const enumGalgasBool test_1 = temp_0.getter_hasKeyAtLevel (constinArgument_key.getter_string (SOURCE_FILE ("gtl_types.galgas", 193)), constinArgument_level COMMA_SOURCE_FILE ("gtl_types.galgas", 193)).boolEnum () ;
  if (kBoolTrue == test_1) {
    {
    GALGAS_gtlData joker_4995 ; // Joker input parameter
    ioObject.setter_del (constinArgument_key, joker_4995, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 194)) ;
    }
  }
  {
  ioObject.setter_put (constinArgument_key, constinArgument_data, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 196)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension method '@gtlTemplateMap getTemplate'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_getTemplate (GALGAS_gtlTemplateMap & ioObject,
                                  const GALGAS_gtlContext constinArgument_context,
                                  GALGAS_lstring inArgument_path,
                                  GALGAS_bool inArgument_ifExists,
                                  GALGAS_library & ioArgument_lib,
                                  GALGAS_bool & outArgument_found,
                                  GALGAS_gtlTemplate & outArgument_result,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_found.drop () ; // Release 'out' argument
  outArgument_result.drop () ; // Release 'out' argument
  const GALGAS_gtlTemplateMap temp_0 = ioObject ;
  const enumGalgasBool test_1 = temp_0.getter_hasKey (inArgument_path.getter_string (SOURCE_FILE ("gtl_types.galgas", 242)) COMMA_SOURCE_FILE ("gtl_types.galgas", 242)).boolEnum () ;
  if (kBoolTrue == test_1) {
    outArgument_found = GALGAS_bool (true) ;
    const GALGAS_gtlTemplateMap temp_2 = ioObject ;
    temp_2.method_get (inArgument_path, outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 244)) ;
  }else if (kBoolFalse == test_1) {
    const enumGalgasBool test_3 = inArgument_path.mAttribute_string.getter_fileExists (SOURCE_FILE ("gtl_types.galgas", 246)).boolEnum () ;
    if (kBoolTrue == test_3) {
      outArgument_found = GALGAS_bool (true) ;
      GALGAS_gtlInstructionList var_program_6732 ;
      var_program_6732.drop () ;
      cGrammar_gtl_5F_grammar::_performSourceFileParsing_ (inCompiler, inArgument_path, constinArgument_context, ioArgument_lib, var_program_6732  COMMA_SOURCE_FILE ("gtl_types.galgas", 248)) ;
      outArgument_result = GALGAS_gtlTemplate::constructor_new (inArgument_path.getter_string (SOURCE_FILE ("gtl_types.galgas", 252)), var_program_6732  COMMA_SOURCE_FILE ("gtl_types.galgas", 252)) ;
      {
      ioObject.setter_put (inArgument_path, outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 253)) ;
      }
    }else if (kBoolFalse == test_3) {
      outArgument_found = GALGAS_bool (false) ;
      const enumGalgasBool test_4 = inArgument_ifExists.boolEnum () ;
      if (kBoolTrue == test_4) {
        outArgument_result = GALGAS_gtlTemplate::constructor_new (inArgument_path.getter_string (SOURCE_FILE ("gtl_types.galgas", 257)), GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_types.galgas", 257))  COMMA_SOURCE_FILE ("gtl_types.galgas", 257)) ;
      }else if (kBoolFalse == test_4) {
        TC_Array <C_FixItDescription> fixItArray5 ;
        inCompiler->emitSemanticError (inArgument_path.getter_location (SOURCE_FILE ("gtl_types.galgas", 259)), GALGAS_string ("template file not found at \"").add_operation (inArgument_path.getter_string (SOURCE_FILE ("gtl_types.galgas", 259)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 259)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 259)), fixItArray5  COMMA_SOURCE_FILE ("gtl_types.galgas", 259)) ;
        outArgument_result.drop () ; // Release error dropped variable
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Abstract extension getter '@gtlVarItem stringPath'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlVarItem_stringPath> gExtensionGetterTable_gtlVarItem_stringPath ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_stringPath (const int32_t inClassIndex,
                                      enterExtensionGetter_gtlVarItem_stringPath inGetter) {
  gExtensionGetterTable_gtlVarItem_stringPath.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlVarItem_stringPath (void) {
  gExtensionGetterTable_gtlVarItem_stringPath.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItem_stringPath (NULL,
                                                  freeExtensionGetter_gtlVarItem_stringPath) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string callExtensionGetter_stringPath (const cPtr_gtlVarItem * inObject,
                                              const GALGAS_gtlData & in_vars,
                                              const GALGAS_library & in_lib,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlVarItem) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlVarItem_stringPath f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlVarItem_stringPath.count ()) {
      f = gExtensionGetterTable_gtlVarItem_stringPath (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlVarItem_stringPath.count ()) {
           f = gExtensionGetterTable_gtlVarItem_stringPath (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlVarItem_stringPath.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_vars, in_lib, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Abstract extension getter '@gtlVarItem location'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlVarItem_location> gExtensionGetterTable_gtlVarItem_location ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_location (const int32_t inClassIndex,
                                    enterExtensionGetter_gtlVarItem_location inGetter) {
  gExtensionGetterTable_gtlVarItem_location.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlVarItem_location (void) {
  gExtensionGetterTable_gtlVarItem_location.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItem_location (NULL,
                                                freeExtensionGetter_gtlVarItem_location) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location callExtensionGetter_location (const cPtr_gtlVarItem * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_location result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlVarItem) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlVarItem_location f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlVarItem_location.count ()) {
      f = gExtensionGetterTable_gtlVarItem_location (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlVarItem_location.count ()) {
           f = gExtensionGetterTable_gtlVarItem_location (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlVarItem_location.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                Abstract extension method '@gtlVarItem setInContext'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlVarItem_setInContext> gExtensionMethodTable_gtlVarItem_setInContext ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_setInContext (const int32_t inClassIndex,
                                        extensionMethodSignature_gtlVarItem_setInContext inMethod) {
  gExtensionMethodTable_gtlVarItem_setInContext.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlVarItem_setInContext (void) {
  gExtensionMethodTable_gtlVarItem_setInContext.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlVarItem_setInContext (NULL,
                                                    freeExtensionMethod_gtlVarItem_setInContext) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_setInContext (const cPtr_gtlVarItem * inObject,
                                       GALGAS_gtlData & io_context,
                                       const GALGAS_gtlData constin_vars,
                                       const GALGAS_library constin_lib,
                                       const GALGAS_gtlVarPath constin_path,
                                       const GALGAS_gtlData constin_newData,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlVarItem) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlVarItem_setInContext f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlVarItem_setInContext.count ()) {
      f = gExtensionMethodTable_gtlVarItem_setInContext (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
      const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
      while ((NULL == f) && (NULL != p)) {
        if (p->mSlotID < gExtensionMethodTable_gtlVarItem_setInContext.count ()) {
          f = gExtensionMethodTable_gtlVarItem_setInContext (p->mSlotID COMMA_HERE) ;
        }
        p = p->mSuperclassDescriptor ;
      }
      gExtensionMethodTable_gtlVarItem_setInContext.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_context, constin_vars, constin_lib, constin_path, constin_newData, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Abstract extension getter '@gtlVarItem getInContext'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlVarItem_getInContext> gExtensionGetterTable_gtlVarItem_getInContext ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_getInContext (const int32_t inClassIndex,
                                        enterExtensionGetter_gtlVarItem_getInContext inGetter) {
  gExtensionGetterTable_gtlVarItem_getInContext.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlVarItem_getInContext (void) {
  gExtensionGetterTable_gtlVarItem_getInContext.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItem_getInContext (NULL,
                                                    freeExtensionGetter_gtlVarItem_getInContext) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_getInContext (const cPtr_gtlVarItem * inObject,
                                                 const GALGAS_gtlData & in_context,
                                                 const GALGAS_gtlData & in_vars,
                                                 const GALGAS_library & in_lib,
                                                 const GALGAS_gtlVarPath & in_path,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlVarItem) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlVarItem_getInContext f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlVarItem_getInContext.count ()) {
      f = gExtensionGetterTable_gtlVarItem_getInContext (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlVarItem_getInContext.count ()) {
           f = gExtensionGetterTable_gtlVarItem_getInContext (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlVarItem_getInContext.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_context, in_vars, in_lib, in_path, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Abstract extension getter '@gtlVarItem existsInContext'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlVarItem_existsInContext> gExtensionGetterTable_gtlVarItem_existsInContext ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_existsInContext (const int32_t inClassIndex,
                                           enterExtensionGetter_gtlVarItem_existsInContext inGetter) {
  gExtensionGetterTable_gtlVarItem_existsInContext.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlVarItem_existsInContext (void) {
  gExtensionGetterTable_gtlVarItem_existsInContext.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItem_existsInContext (NULL,
                                                       freeExtensionGetter_gtlVarItem_existsInContext) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_existsInContext (const cPtr_gtlVarItem * inObject,
                                                 const GALGAS_gtlData & in_context,
                                                 const GALGAS_gtlData & in_vars,
                                                 const GALGAS_library & in_lib,
                                                 const GALGAS_gtlVarPath & in_path,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlVarItem) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlVarItem_existsInContext f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlVarItem_existsInContext.count ()) {
      f = gExtensionGetterTable_gtlVarItem_existsInContext (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlVarItem_existsInContext.count ()) {
           f = gExtensionGetterTable_gtlVarItem_existsInContext (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlVarItem_existsInContext.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_context, in_vars, in_lib, in_path, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Abstract extension method '@gtlVarItem deleteInContext'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlVarItem_deleteInContext> gExtensionMethodTable_gtlVarItem_deleteInContext ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_deleteInContext (const int32_t inClassIndex,
                                           extensionMethodSignature_gtlVarItem_deleteInContext inMethod) {
  gExtensionMethodTable_gtlVarItem_deleteInContext.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlVarItem_deleteInContext (void) {
  gExtensionMethodTable_gtlVarItem_deleteInContext.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlVarItem_deleteInContext (NULL,
                                                       freeExtensionMethod_gtlVarItem_deleteInContext) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_deleteInContext (const cPtr_gtlVarItem * inObject,
                                          GALGAS_gtlData & io_context,
                                          const GALGAS_gtlData constin_vars,
                                          const GALGAS_library constin_lib,
                                          const GALGAS_gtlVarPath constin_path,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlVarItem) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlVarItem_deleteInContext f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlVarItem_deleteInContext.count ()) {
      f = gExtensionMethodTable_gtlVarItem_deleteInContext (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
      const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
      while ((NULL == f) && (NULL != p)) {
        if (p->mSlotID < gExtensionMethodTable_gtlVarItem_deleteInContext.count ()) {
          f = gExtensionMethodTable_gtlVarItem_deleteInContext (p->mSlotID COMMA_HERE) ;
        }
        p = p->mSuperclassDescriptor ;
      }
      gExtensionMethodTable_gtlVarItem_deleteInContext.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_context, constin_vars, constin_lib, constin_path, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension Getter '@gtlVarPath pathAsFunctionName'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring extensionGetter_pathAsFunctionName (const GALGAS_gtlVarPath & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const GALGAS_gtlVarPath temp_0 = inObject ;
  GALGAS_gtlVarItem var_firstItem_20776 = temp_0.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 714)) ;
  if (var_firstItem_20776.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_gtlVarItemField *> (var_firstItem_20776.ptr ())) {
      GALGAS_gtlVarItemField cast_20855_namedField ((cPtr_gtlVarItemField *) var_firstItem_20776.ptr ()) ;
      result_result = cast_20855_namedField.getter_field (SOURCE_FILE ("gtl_expressions.galgas", 717)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlVarItem *) var_firstItem_20776.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 719)), GALGAS_string ("INTERNAL ERROR. A @gtlVarPath should not begin with a subcollection"), fixItArray1  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 719)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension Getter '@gtlVarPath stringPath'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_stringPath (const GALGAS_gtlVarPath & inObject,
                                          const GALGAS_gtlData & constinArgument_vars,
                                          const GALGAS_library & constinArgument_lib,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  const GALGAS_gtlVarPath temp_0 = inObject ;
  cEnumerator_gtlVarPath enumerator_21322 (temp_0, kEnumeration_up) ;
  while (enumerator_21322.hasCurrentObject ()) {
    result_result.plusAssign_operation(callExtensionGetter_stringPath ((const cPtr_gtlVarItem *) enumerator_21322.current_item (HERE).ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 733)), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 733)) ;
    if (enumerator_21322.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string ("::"), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 735)) ;
    }
    enumerator_21322.gotoNextObject () ;
  }
//---
  return result_result ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Extension method '@gtlVarPath set'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_set (const GALGAS_gtlVarPath inObject,
                          GALGAS_gtlData & ioArgument_vars,
                          const GALGAS_library constinArgument_lib,
                          const GALGAS_gtlData constinArgument_data,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_gtlVarPath temp_0 = inObject ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, temp_0.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 747)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    const GALGAS_gtlVarPath temp_2 = inObject ;
    GALGAS_gtlVarItem var_item_21728 = temp_2.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 748)) ;
    if (var_item_21728.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlVarItemField *> (var_item_21728.ptr ())) {
        GALGAS_gtlVarItemField cast_21805_itemField ((cPtr_gtlVarItemField *) var_item_21728.ptr ()) ;
        const GALGAS_gtlVarPath temp_3 = inObject ;
        callExtensionMethod_setInContext ((const cPtr_gtlVarItemField *) cast_21805_itemField.ptr (), ioArgument_vars, ioArgument_vars, constinArgument_lib, temp_3.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 755)), constinArgument_data, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 751)) ;
      }else{
        TC_Array <C_FixItDescription> fixItArray4 ;
        inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlVarItem *) var_item_21728.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 759)), GALGAS_string ("INTERNAL ERROR. A @gtlVarPath may not begin with a subcollection"), fixItArray4  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 759)) ;
      }
    }
  }else if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray5 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 762)), GALGAS_string ("INTERNAL ERROR. A @gtlVarPath should not be an empty list"), fixItArray5  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 762)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Extension Getter '@gtlVarPath get'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData extensionGetter_get (const GALGAS_gtlVarPath & inObject,
                                    const GALGAS_gtlData & constinArgument_context,
                                    const GALGAS_library & constinArgument_lib,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_variableValue ; // Returned variable
  const GALGAS_gtlVarPath temp_0 = inObject ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, temp_0.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 774)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    const GALGAS_gtlVarPath temp_2 = inObject ;
    GALGAS_gtlVarItem var_item_22470 = temp_2.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 775)) ;
    const GALGAS_gtlVarPath temp_3 = inObject ;
    result_variableValue = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) var_item_22470.ptr (), constinArgument_context, constinArgument_context, constinArgument_lib, temp_3.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 776)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 776)) ;
  }else if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 778)), GALGAS_string ("INTERNAL ERROR. A @gtlVarPath should not be an empty list"), fixItArray4  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 778)) ;
    result_variableValue.drop () ; // Release error dropped variable
  }
//---
  return result_variableValue ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension Getter '@gtlVarPath exists'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool extensionGetter_exists (const GALGAS_gtlVarPath & inObject,
                                    const GALGAS_gtlData & constinArgument_context,
                                    const GALGAS_library & constinArgument_lib,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const GALGAS_gtlVarPath temp_0 = inObject ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, temp_0.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 791)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    const GALGAS_gtlVarPath temp_2 = inObject ;
    GALGAS_gtlVarItem var_item_23029 = temp_2.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 792)) ;
    const GALGAS_gtlVarPath temp_3 = inObject ;
    result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) var_item_23029.ptr (), constinArgument_context, constinArgument_context, constinArgument_lib, temp_3.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 793)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 793)) ;
  }else if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 795)), GALGAS_string ("INTERNAL ERROR. A @gtlVarPath should not be an empty list"), fixItArray4  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 795)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension method '@gtlVarPath delete'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_delete (const GALGAS_gtlVarPath inObject,
                             GALGAS_gtlData & ioArgument_vars,
                             const GALGAS_library constinArgument_lib,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_gtlVarPath temp_0 = inObject ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, temp_0.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 807)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    const GALGAS_gtlVarPath temp_2 = inObject ;
    GALGAS_gtlVarItem var_item_23550 = temp_2.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 808)) ;
    const GALGAS_gtlVarPath temp_3 = inObject ;
    callExtensionMethod_deleteInContext ((const cPtr_gtlVarItem *) var_item_23550.ptr (), ioArgument_vars, ioArgument_vars, constinArgument_lib, temp_3.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 813)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 809)) ;
  }else if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 816)), GALGAS_string ("INTERNAL ERROR. A @gtlVarPath should not be an empty list"), fixItArray4  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 816)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension Getter '@gtlVarPath location'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location extensionGetter_location (const GALGAS_gtlVarPath & inObject,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location result_where ; // Returned variable
  GALGAS_gtlVarItem var_lastOne_24074 ;
  const GALGAS_gtlVarPath temp_0 = inObject ;
  temp_0.method_last (var_lastOne_24074, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 825)) ;
  result_where = callExtensionGetter_location ((const cPtr_gtlVarItem *) var_lastOne_24074.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 826)) ;
//---
  return result_where ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Extension Getter '@string gtlType'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type extensionGetter_gtlType (const GALGAS_string & inObject,
                                     const GALGAS_location & constinArgument_location,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_type ; // Returned variable
  const GALGAS_string temp_0 = inObject ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, temp_0.objectCompare (GALGAS_string ("int"))).boolEnum () ;
  if (kBoolTrue == test_1) {
    result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt) ;
  }else if (kBoolFalse == test_1) {
    const GALGAS_string temp_2 = inObject ;
    const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, temp_2.objectCompare (GALGAS_string ("char"))).boolEnum () ;
    if (kBoolTrue == test_3) {
      result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar) ;
    }else if (kBoolFalse == test_3) {
      const GALGAS_string temp_4 = inObject ;
      const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, temp_4.objectCompare (GALGAS_string ("float"))).boolEnum () ;
      if (kBoolTrue == test_5) {
        result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlFloat) ;
      }else if (kBoolFalse == test_5) {
        const GALGAS_string temp_6 = inObject ;
        const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, temp_6.objectCompare (GALGAS_string ("string"))).boolEnum () ;
        if (kBoolTrue == test_7) {
          result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlString) ;
        }else if (kBoolFalse == test_7) {
          const GALGAS_string temp_8 = inObject ;
          const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, temp_8.objectCompare (GALGAS_string ("bool"))).boolEnum () ;
          if (kBoolTrue == test_9) {
            result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool) ;
          }else if (kBoolFalse == test_9) {
            const GALGAS_string temp_10 = inObject ;
            const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, temp_10.objectCompare (GALGAS_string ("struct"))).boolEnum () ;
            if (kBoolTrue == test_11) {
              result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct) ;
            }else if (kBoolFalse == test_11) {
              const GALGAS_string temp_12 = inObject ;
              const enumGalgasBool test_13 = GALGAS_bool (kIsEqual, temp_12.objectCompare (GALGAS_string ("list"))).boolEnum () ;
              if (kBoolTrue == test_13) {
                result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlList) ;
              }else if (kBoolFalse == test_13) {
                const GALGAS_string temp_14 = inObject ;
                const enumGalgasBool test_15 = GALGAS_bool (kIsEqual, temp_14.objectCompare (GALGAS_string ("map"))).boolEnum () ;
                if (kBoolTrue == test_15) {
                  result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlMap) ;
                }else if (kBoolFalse == test_15) {
                  const GALGAS_string temp_16 = inObject ;
                  const enumGalgasBool test_17 = GALGAS_bool (kIsEqual, temp_16.objectCompare (GALGAS_string ("type"))).boolEnum () ;
                  if (kBoolTrue == test_17) {
                    result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlType) ;
                  }else if (kBoolFalse == test_17) {
                    const GALGAS_string temp_18 = inObject ;
                    const enumGalgasBool test_19 = GALGAS_bool (kIsEqual, temp_18.objectCompare (GALGAS_string ("enum"))).boolEnum () ;
                    if (kBoolTrue == test_19) {
                      result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlEnum) ;
                    }else if (kBoolFalse == test_19) {
                      const GALGAS_string temp_20 = inObject ;
                      const enumGalgasBool test_21 = GALGAS_bool (kIsEqual, temp_20.objectCompare (GALGAS_string ("set"))).boolEnum () ;
                      if (kBoolTrue == test_21) {
                        result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlSet) ;
                      }else if (kBoolFalse == test_21) {
                        const GALGAS_string temp_22 = inObject ;
                        const enumGalgasBool test_23 = GALGAS_bool (kIsEqual, temp_22.objectCompare (GALGAS_string ("unconstructed"))).boolEnum () ;
                        if (kBoolTrue == test_23) {
                          result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlUnconstructed) ;
                        }else if (kBoolFalse == test_23) {
                          TC_Array <C_FixItDescription> fixItArray24 ;
                          inCompiler->emitSemanticError (constinArgument_location, GALGAS_string ("unknown type"), fixItArray24  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 61)) ;
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
//                                     Extension getter '@gtlInstruction location'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlInstruction_location> gExtensionGetterTable_gtlInstruction_location ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_location (const int32_t inClassIndex,
                                    enterExtensionGetter_gtlInstruction_location inGetter) {
  gExtensionGetterTable_gtlInstruction_location.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location callExtensionGetter_location (const cPtr_gtlInstruction * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_location result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlInstruction) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlInstruction_location f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlInstruction_location.count ()) {
      f = gExtensionGetterTable_gtlInstruction_location (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlInstruction_location.count ()) {
           f = gExtensionGetterTable_gtlInstruction_location (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlInstruction_location.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_location extensionGetter_gtlInstruction_location (const cPtr_gtlInstruction * inObject,
                                                                C_Compiler * /* inCompiler */
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location result_result ; // Returned variable
  const cPtr_gtlInstruction * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlInstruction) ;
  result_result = object->mAttribute_where ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInstruction_location (void) {
  enterExtensionGetter_location (kTypeDescriptor_GALGAS_gtlInstruction.mSlotID,
                                 extensionGetter_gtlInstruction_location) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlInstruction_location (void) {
  gExtensionGetterTable_gtlInstruction_location.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInstruction_location (defineExtensionGetter_gtlInstruction_location,
                                                    freeExtensionGetter_gtlInstruction_location) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Abstract extension method '@gtlInstruction execute'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlInstruction_execute> gExtensionMethodTable_gtlInstruction_execute ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_execute (const int32_t inClassIndex,
                                   extensionMethodSignature_gtlInstruction_execute inMethod) {
  gExtensionMethodTable_gtlInstruction_execute.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlInstruction_execute (void) {
  gExtensionMethodTable_gtlInstruction_execute.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlInstruction_execute (NULL,
                                                   freeExtensionMethod_gtlInstruction_execute) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_execute (const cPtr_gtlInstruction * inObject,
                                  GALGAS_gtlContext & io_context,
                                  GALGAS_gtlData & io_vars,
                                  GALGAS_library & io_lib,
                                  GALGAS_string & io_outputString,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlInstruction) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlInstruction_execute f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlInstruction_execute.count ()) {
      f = gExtensionMethodTable_gtlInstruction_execute (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
      const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
      while ((NULL == f) && (NULL != p)) {
        if (p->mSlotID < gExtensionMethodTable_gtlInstruction_execute.count ()) {
          f = gExtensionMethodTable_gtlInstruction_execute (p->mSlotID COMMA_HERE) ;
        }
        p = p->mSuperclassDescriptor ;
      }
      gExtensionMethodTable_gtlInstruction_execute.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_context, io_vars, io_lib, io_outputString, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension method '@gtlInstructionList execute'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_execute (const GALGAS_gtlInstructionList inObject,
                              GALGAS_gtlContext & ioArgument_context,
                              GALGAS_gtlData & ioArgument_vars,
                              GALGAS_library & ioArgument_lib,
                              GALGAS_string & ioArgument_outputString,
                              C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = callExtensionGetter_debugActive ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 60)).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    const GALGAS_gtlInstructionList temp_1 = inObject ;
    ioArgument_context.insulate (HERE) ;
    cPtr_gtlContext * ptr_1584 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
    callExtensionSetter_pushInstructionList ((cPtr_gtlContext *) ptr_1584, temp_1, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 61)) ;
    }
    GALGAS_uint var_lastErrorCount_1636 = GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 62)) ;
    const GALGAS_gtlInstructionList temp_2 = inObject ;
    cEnumerator_gtlInstructionList enumerator_1669 (temp_2, kEnumeration_up) ;
    GALGAS_uint index_1658 ((uint32_t) 0) ;
    while (enumerator_1669.hasCurrentObject ()) {
      GALGAS_bool var_errorCountIncreased_1712 = GALGAS_bool (kIsStrictSup, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 64)).substract_operation (var_lastErrorCount_1636, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 64)).objectCompare (GALGAS_uint ((uint32_t) 0U))) ;
      const enumGalgasBool test_3 = callExtensionGetter_breakOnNext ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 65)).operator_or (callExtensionGetter_breakOn ((const cPtr_gtlContext *) ioArgument_context.ptr (), enumerator_1669.current_instruction (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 65)) COMMA_SOURCE_FILE ("gtl_instructions.galgas", 65)).operator_or (var_errorCountIncreased_1712 COMMA_SOURCE_FILE ("gtl_instructions.galgas", 65)).boolEnum () ;
      if (kBoolTrue == test_3) {
        {
        ioArgument_context.insulate (HERE) ;
        cPtr_gtlContext * ptr_1864 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
        callExtensionSetter_setBreakOnNext ((cPtr_gtlContext *) ptr_1864, GALGAS_bool (true), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 66)) ;
        }
        {
        ioArgument_context.insulate (HERE) ;
        cPtr_gtlContext * ptr_1905 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
        callExtensionSetter_setNextInstructionIndex ((cPtr_gtlContext *) ptr_1905, index_1658, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 67)) ;
        }
        callExtensionMethod_executeStepDoList ((const cPtr_gtlContext *) ioArgument_context.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 69)) ;
        {
        ioArgument_context.insulate (HERE) ;
        cPtr_gtlContext * ptr_2100 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
        callExtensionSetter_setLoopOnCommand ((cPtr_gtlContext *) ptr_2100, GALGAS_bool (true), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 70)) ;
        }
        if (GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_instructions.galgas", 71)).isValid ()) {
          uint32_t variant_2137 = GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_instructions.galgas", 71)).uintValue () ;
          bool loop_2137 = true ;
          while (loop_2137) {
              inCompiler->printMessage (callExtensionGetter_promptStyle ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 72)).add_operation (GALGAS_string ("gtl> "), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 72)).add_operation (function_endc (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 72)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 72))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 72)) ;
              GALGAS_string var_input_2232 = GALGAS_string::constructor_newWithStdIn (SOURCE_FILE ("gtl_instructions.galgas", 73)) ;
              GALGAS_gtlInstruction var_command_2291 ;
              GALGAS_uint var_currentErrorCount_2325 = GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 75)) ;
              const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, var_input_2232.getter_stringByTrimmingWhiteSpaces (SOURCE_FILE ("gtl_instructions.galgas", 76)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
              if (kBoolTrue == test_4) {
                var_command_2291 = GALGAS_gtlStepInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 77)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 77)) ;
              }else if (kBoolFalse == test_4) {
                var_command_2291.drop () ;
                cGrammar_gtl_5F_debugger_5F_grammar::_performSourceStringParsing_ (inCompiler, GALGAS_string ("%").add_operation (var_input_2232, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 79)), GALGAS_string ("Debugger command"), var_command_2291  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 79)) ;
              }
              const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 82)).objectCompare (var_currentErrorCount_2325)).boolEnum () ;
              if (kBoolTrue == test_5) {
                const enumGalgasBool test_6 = callExtensionGetter_mayExecuteWithoutError ((const cPtr_gtlInstruction *) var_command_2291.ptr (), ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 83)).boolEnum () ;
                if (kBoolTrue == test_6) {
                  inCompiler->printMessage (callExtensionGetter_outputStyle ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 84))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 84)) ;
                  callExtensionMethod_execute ((const cPtr_gtlInstruction *) var_command_2291.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 85)) ;
                  inCompiler->printMessage (function_endc (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 86))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 86)) ;
                }
              }
            loop_2137 = callExtensionGetter_loopOnCommand ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 89)).isValid () ;
            if (loop_2137) {
              loop_2137 = callExtensionGetter_loopOnCommand ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 89)).boolValue () ;
            }
            if (loop_2137 && (0 == variant_2137)) {
              loop_2137 = false ;
              inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_instructions.galgas", 71)) ;
            }
            if (loop_2137) {
              variant_2137 -- ;
            }
          }
        }
      }
      var_lastErrorCount_1636 = GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 92)) ;
      callExtensionMethod_execute ((const cPtr_gtlInstruction *) enumerator_1669.current_instruction (HERE).ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 93)) ;
      enumerator_1669.gotoNextObject () ;
      index_1658.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 63)) ;
    }
    {
    ioArgument_context.insulate (HERE) ;
    cPtr_gtlContext * ptr_3075 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
    callExtensionSetter_popInstructionList ((cPtr_gtlContext *) ptr_3075, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 95)) ;
    }
  }else if (kBoolFalse == test_0) {
    const GALGAS_gtlInstructionList temp_7 = inObject ;
    cEnumerator_gtlInstructionList enumerator_3121 (temp_7, kEnumeration_up) ;
    while (enumerator_3121.hasCurrentObject ()) {
      const enumGalgasBool test_8 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 98)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_8) {
        callExtensionMethod_execute ((const cPtr_gtlInstruction *) enumerator_3121.current_instruction (HERE).ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 99)) ;
        const enumGalgasBool test_9 = GALGAS_bool (kIsNotEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 100)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_9) {
          TC_Array <C_FixItDescription> fixItArray10 ;
          inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlInstruction *) enumerator_3121.current_instruction (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 101)), GALGAS_string ("runtime error"), fixItArray10  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 101)) ;
        }
      }
      enumerator_3121.gotoNextObject () ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Abstract extension getter '@gtlAbstractSortInstruction compare'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlAbstractSortInstruction_compare> gExtensionGetterTable_gtlAbstractSortInstruction_compare ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_compare (const int32_t inClassIndex,
                                   enterExtensionGetter_gtlAbstractSortInstruction_compare inGetter) {
  gExtensionGetterTable_gtlAbstractSortInstruction_compare.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlAbstractSortInstruction_compare (void) {
  gExtensionGetterTable_gtlAbstractSortInstruction_compare.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlAbstractSortInstruction_compare (NULL,
                                                               freeExtensionGetter_gtlAbstractSortInstruction_compare) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint callExtensionGetter_compare (const cPtr_gtlAbstractSortInstruction * inObject,
                                         const GALGAS_gtlData & in_s_31_,
                                         const GALGAS_gtlData & in_s_32_,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_sint result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlAbstractSortInstruction) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlAbstractSortInstruction_compare f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlAbstractSortInstruction_compare.count ()) {
      f = gExtensionGetterTable_gtlAbstractSortInstruction_compare (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlAbstractSortInstruction_compare.count ()) {
           f = gExtensionGetterTable_gtlAbstractSortInstruction_compare (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlAbstractSortInstruction_compare.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_s_31_, in_s_32_, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@gtlAbstractSortInstruction swap'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlAbstractSortInstruction_swap> gExtensionMethodTable_gtlAbstractSortInstruction_swap ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_swap (const int32_t inClassIndex,
                                extensionMethodSignature_gtlAbstractSortInstruction_swap inMethod) {
  gExtensionMethodTable_gtlAbstractSortInstruction_swap.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_swap (const cPtr_gtlAbstractSortInstruction * inObject,
                               GALGAS_list & io_aList,
                               const GALGAS_uint constin_index_31_,
                               const GALGAS_uint constin_index_32_,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlAbstractSortInstruction) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlAbstractSortInstruction_swap f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlAbstractSortInstruction_swap.count ()) {
      f = gExtensionMethodTable_gtlAbstractSortInstruction_swap (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlAbstractSortInstruction_swap.count ()) {
           f = gExtensionMethodTable_gtlAbstractSortInstruction_swap (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlAbstractSortInstruction_swap.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_aList, constin_index_31_, constin_index_32_, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlAbstractSortInstruction_swap (const cPtr_gtlAbstractSortInstruction * /* inObject */,
                                                             GALGAS_list & ioArgument_aList,
                                                             const GALGAS_uint constinArgument_index_31_,
                                                             const GALGAS_uint constinArgument_index_32_,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_temp_28962 = ioArgument_aList.getter_valueAtIndex (constinArgument_index_31_, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 957)) ;
  {
  ioArgument_aList.setter_setValueAtIndex (ioArgument_aList.getter_valueAtIndex (constinArgument_index_32_, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 958)), constinArgument_index_31_, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 958)) ;
  }
  {
  ioArgument_aList.setter_setValueAtIndex (var_temp_28962, constinArgument_index_32_, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 959)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlAbstractSortInstruction_swap (void) {
  enterExtensionMethod_swap (kTypeDescriptor_GALGAS_gtlAbstractSortInstruction.mSlotID,
                             extensionMethod_gtlAbstractSortInstruction_swap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlAbstractSortInstruction_swap (void) {
  gExtensionMethodTable_gtlAbstractSortInstruction_swap.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlAbstractSortInstruction_swap (defineExtensionMethod_gtlAbstractSortInstruction_swap,
                                                            freeExtensionMethod_gtlAbstractSortInstruction_swap) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension method '@gtlAbstractSortInstruction partition'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlAbstractSortInstruction_partition> gExtensionMethodTable_gtlAbstractSortInstruction_partition ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_partition (const int32_t inClassIndex,
                                     extensionMethodSignature_gtlAbstractSortInstruction_partition inMethod) {
  gExtensionMethodTable_gtlAbstractSortInstruction_partition.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_partition (const cPtr_gtlAbstractSortInstruction * inObject,
                                    GALGAS_list & io_aList,
                                    const GALGAS_uint constin_min,
                                    const GALGAS_uint constin_max,
                                    GALGAS_uint & io_pivotIndex,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlAbstractSortInstruction) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlAbstractSortInstruction_partition f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlAbstractSortInstruction_partition.count ()) {
      f = gExtensionMethodTable_gtlAbstractSortInstruction_partition (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlAbstractSortInstruction_partition.count ()) {
           f = gExtensionMethodTable_gtlAbstractSortInstruction_partition (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlAbstractSortInstruction_partition.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_aList, constin_min, constin_max, io_pivotIndex, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlAbstractSortInstruction_partition (const cPtr_gtlAbstractSortInstruction * inObject,
                                                                  GALGAS_list & ioArgument_aList,
                                                                  const GALGAS_uint constinArgument_min,
                                                                  const GALGAS_uint constinArgument_max,
                                                                  GALGAS_uint & ioArgument_pivotIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlAbstractSortInstruction * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlAbstractSortInstruction) ;
  GALGAS_gtlData var_pivot_29245 = ioArgument_aList.getter_valueAtIndex (ioArgument_pivotIndex, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 968)) ;
  const GALGAS_gtlAbstractSortInstruction temp_0 = object ;
  callExtensionMethod_swap ((const cPtr_gtlAbstractSortInstruction *) temp_0.ptr (), ioArgument_aList, ioArgument_pivotIndex, constinArgument_max, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 969)) ;
  GALGAS_uint var_storeIndex_29338 = constinArgument_min ;
  GALGAS_uint var_i_29354 = constinArgument_min ;
  if (constinArgument_max.substract_operation (constinArgument_min, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 972)).isValid ()) {
    uint32_t variant_29367 = constinArgument_max.substract_operation (constinArgument_min, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 972)).uintValue () ;
    bool loop_29367 = true ;
    while (loop_29367) {
      loop_29367 = GALGAS_bool (kIsStrictInf, var_i_29354.objectCompare (constinArgument_max)).isValid () ;
      if (loop_29367) {
        loop_29367 = GALGAS_bool (kIsStrictInf, var_i_29354.objectCompare (constinArgument_max)).boolValue () ;
      }
      if (loop_29367 && (0 == variant_29367)) {
        loop_29367 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_instructions.galgas", 972)) ;
      }
      if (loop_29367) {
        variant_29367 -- ;
        const GALGAS_gtlAbstractSortInstruction temp_1 = object ;
        const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, callExtensionGetter_compare ((const cPtr_gtlAbstractSortInstruction *) temp_1.ptr (), ioArgument_aList.getter_valueAtIndex (var_i_29354, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 974)), var_pivot_29245, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 974)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 974)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          const GALGAS_gtlAbstractSortInstruction temp_3 = object ;
          callExtensionMethod_swap ((const cPtr_gtlAbstractSortInstruction *) temp_3.ptr (), ioArgument_aList, var_i_29354, var_storeIndex_29338, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 975)) ;
          var_storeIndex_29338.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 976)) ;
        }
        var_i_29354.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 978)) ;
      }
    }
  }
  const GALGAS_gtlAbstractSortInstruction temp_4 = object ;
  callExtensionMethod_swap ((const cPtr_gtlAbstractSortInstruction *) temp_4.ptr (), ioArgument_aList, var_storeIndex_29338, constinArgument_max, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 980)) ;
  ioArgument_pivotIndex = var_storeIndex_29338 ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlAbstractSortInstruction_partition (void) {
  enterExtensionMethod_partition (kTypeDescriptor_GALGAS_gtlAbstractSortInstruction.mSlotID,
                                  extensionMethod_gtlAbstractSortInstruction_partition) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlAbstractSortInstruction_partition (void) {
  gExtensionMethodTable_gtlAbstractSortInstruction_partition.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlAbstractSortInstruction_partition (defineExtensionMethod_gtlAbstractSortInstruction_partition,
                                                                 freeExtensionMethod_gtlAbstractSortInstruction_partition) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@gtlAbstractSortInstruction sort'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlAbstractSortInstruction_sort> gExtensionMethodTable_gtlAbstractSortInstruction_sort ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_sort (const int32_t inClassIndex,
                                extensionMethodSignature_gtlAbstractSortInstruction_sort inMethod) {
  gExtensionMethodTable_gtlAbstractSortInstruction_sort.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_sort (const cPtr_gtlAbstractSortInstruction * inObject,
                               GALGAS_list & io_aList,
                               const GALGAS_uint constin_min,
                               const GALGAS_uint constin_max,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlAbstractSortInstruction) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlAbstractSortInstruction_sort f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlAbstractSortInstruction_sort.count ()) {
      f = gExtensionMethodTable_gtlAbstractSortInstruction_sort (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlAbstractSortInstruction_sort.count ()) {
           f = gExtensionMethodTable_gtlAbstractSortInstruction_sort (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlAbstractSortInstruction_sort.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_aList, constin_min, constin_max, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlAbstractSortInstruction_sort (const cPtr_gtlAbstractSortInstruction * inObject,
                                                             GALGAS_list & ioArgument_aList,
                                                             const GALGAS_uint constinArgument_min,
                                                             const GALGAS_uint constinArgument_max,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlAbstractSortInstruction * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlAbstractSortInstruction) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictInf, constinArgument_min.objectCompare (constinArgument_max)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_uint var_pivotIndex_29750 = constinArgument_max.add_operation (constinArgument_min, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 990)).divide_operation (GALGAS_uint ((uint32_t) 2U), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 990)) ;
    const GALGAS_gtlAbstractSortInstruction temp_1 = object ;
    callExtensionMethod_partition ((const cPtr_gtlAbstractSortInstruction *) temp_1.ptr (), ioArgument_aList, constinArgument_min, constinArgument_max, var_pivotIndex_29750, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 991)) ;
    const GALGAS_gtlAbstractSortInstruction temp_2 = object ;
    callExtensionMethod_sort ((const cPtr_gtlAbstractSortInstruction *) temp_2.ptr (), ioArgument_aList, constinArgument_min, var_pivotIndex_29750, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 992)) ;
    const GALGAS_gtlAbstractSortInstruction temp_3 = object ;
    callExtensionMethod_sort ((const cPtr_gtlAbstractSortInstruction *) temp_3.ptr (), ioArgument_aList, var_pivotIndex_29750.add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 993)), constinArgument_max, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 993)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlAbstractSortInstruction_sort (void) {
  enterExtensionMethod_sort (kTypeDescriptor_GALGAS_gtlAbstractSortInstruction.mSlotID,
                             extensionMethod_gtlAbstractSortInstruction_sort) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlAbstractSortInstruction_sort (void) {
  gExtensionMethodTable_gtlAbstractSortInstruction_sort.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlAbstractSortInstruction_sort (defineExtensionMethod_gtlAbstractSortInstruction_sort,
                                                            freeExtensionMethod_gtlAbstractSortInstruction_sort) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Extension getter '@gtlSortStatementStructInstruction compareElements'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlSortStatementStructInstruction_compareElements> gExtensionGetterTable_gtlSortStatementStructInstruction_compareElements ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_compareElements (const int32_t inClassIndex,
                                           enterExtensionGetter_gtlSortStatementStructInstruction_compareElements inGetter) {
  gExtensionGetterTable_gtlSortStatementStructInstruction_compareElements.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint callExtensionGetter_compareElements (const cPtr_gtlSortStatementStructInstruction * inObject,
                                                 const GALGAS_gtlData & in_s_31_,
                                                 const GALGAS_gtlData & in_s_32_,
                                                 GALGAS_sortingKeyList in_keyList,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  GALGAS_sint result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlSortStatementStructInstruction) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlSortStatementStructInstruction_compareElements f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlSortStatementStructInstruction_compareElements.count ()) {
      f = gExtensionGetterTable_gtlSortStatementStructInstruction_compareElements (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlSortStatementStructInstruction_compareElements.count ()) {
           f = gExtensionGetterTable_gtlSortStatementStructInstruction_compareElements (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlSortStatementStructInstruction_compareElements.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_s_31_, in_s_32_, in_keyList, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_sint extensionGetter_gtlSortStatementStructInstruction_compareElements (const cPtr_gtlSortStatementStructInstruction * inObject,
                                                                                      const GALGAS_gtlData & constinArgument_s_31_,
                                                                                      const GALGAS_gtlData & constinArgument_s_32_,
                                                                                      GALGAS_sortingKeyList inArgument_keyList,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint result_result ; // Returned variable
  const cPtr_gtlSortStatementStructInstruction * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlSortStatementStructInstruction) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, inArgument_keyList.getter_length (SOURCE_FILE ("gtl_instructions.galgas", 1041)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (constinArgument_s_31_.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct).boolEnum () ;
    if (kBoolTrue == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (constinArgument_s_32_.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct).boolEnum () ;
      if (kBoolTrue == test_2) {
        GALGAS_gtlStruct temp_3 ;
        if (constinArgument_s_31_.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlStruct *> (constinArgument_s_31_.ptr ())) {
            temp_3 = (cPtr_gtlStruct *) constinArgument_s_31_.ptr () ;
          }else{
            inCompiler->castError ("gtlStruct", constinArgument_s_31_.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1044)) ;
          }
        }
        GALGAS_gtlStruct var_s_31_Struct_31228 = temp_3 ;
        GALGAS_gtlStruct temp_4 ;
        if (constinArgument_s_32_.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlStruct *> (constinArgument_s_32_.ptr ())) {
            temp_4 = (cPtr_gtlStruct *) constinArgument_s_32_.ptr () ;
          }else{
            inCompiler->castError ("gtlStruct", constinArgument_s_32_.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1045)) ;
          }
        }
        GALGAS_gtlStruct var_s_32_Struct_31275 = temp_4 ;
        GALGAS_lstring var_field_31338 ;
        GALGAS_lsint var_order_31352 ;
        {
        inArgument_keyList.setter_popFirst (var_field_31338, var_order_31352, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1046)) ;
        }
        GALGAS_gtlData var_s_31_Field_31408 ;
        var_s_31_Struct_31228.getter_value (SOURCE_FILE ("gtl_instructions.galgas", 1047)).method_get (var_field_31338, var_s_31_Field_31408, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1047)) ;
        GALGAS_gtlData var_s_32_Field_31464 ;
        var_s_32_Struct_31275.getter_value (SOURCE_FILE ("gtl_instructions.galgas", 1048)).method_get (var_field_31338, var_s_32_Field_31464, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1048)) ;
        const enumGalgasBool test_5 = callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_ltOp ((const cPtr_gtlData *) var_s_31_Field_31408.ptr (), var_s_32_Field_31464, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1049)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1056)).boolEnum () ;
        if (kBoolTrue == test_5) {
          result_result = GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1050)).multiply_operation (var_order_31352.getter_sint (SOURCE_FILE ("gtl_instructions.galgas", 1050)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1050)) ;
        }else if (kBoolFalse == test_5) {
          const enumGalgasBool test_6 = callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_gtOp ((const cPtr_gtlData *) var_s_31_Field_31408.ptr (), var_s_32_Field_31464, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1052)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1055)).boolEnum () ;
          if (kBoolTrue == test_6) {
            result_result = GALGAS_sint ((int32_t) 1L).multiply_operation (var_order_31352.getter_sint (SOURCE_FILE ("gtl_instructions.galgas", 1053)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1053)) ;
          }else if (kBoolFalse == test_6) {
            const GALGAS_gtlSortStatementStructInstruction temp_7 = object ;
            result_result = callExtensionGetter_compareElements ((const cPtr_gtlSortStatementStructInstruction *) temp_7.ptr (), constinArgument_s_31_, constinArgument_s_32_, inArgument_keyList, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1055)) ;
          }
        }
      }else if (kBoolFalse == test_2) {
        TC_Array <C_FixItDescription> fixItArray8 ;
        inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_s_32_.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1059)), GALGAS_string ("struct expected"), fixItArray8  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1059)) ;
        result_result.drop () ; // Release error dropped variable
      }
    }else if (kBoolFalse == test_1) {
      TC_Array <C_FixItDescription> fixItArray9 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_s_31_.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1062)), GALGAS_string ("struct expected"), fixItArray9  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1062)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_sint ((int32_t) 0L) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlSortStatementStructInstruction_compareElements (void) {
  enterExtensionGetter_compareElements (kTypeDescriptor_GALGAS_gtlSortStatementStructInstruction.mSlotID,
                                        extensionGetter_gtlSortStatementStructInstruction_compareElements) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlSortStatementStructInstruction_compareElements (void) {
  gExtensionGetterTable_gtlSortStatementStructInstruction_compareElements.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlSortStatementStructInstruction_compareElements (defineExtensionGetter_gtlSortStatementStructInstruction_compareElements,
                                                                              freeExtensionGetter_gtlSortStatementStructInstruction_compareElements) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension method '@gtlVariablesInstruction displayShort'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlVariablesInstruction_displayShort> gExtensionMethodTable_gtlVariablesInstruction_displayShort ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_displayShort (const int32_t inClassIndex,
                                        extensionMethodSignature_gtlVariablesInstruction_displayShort inMethod) {
  gExtensionMethodTable_gtlVariablesInstruction_displayShort.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_displayShort (const cPtr_gtlVariablesInstruction * inObject,
                                       const GALGAS_gtlData constin_vars,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlVariablesInstruction) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlVariablesInstruction_displayShort f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlVariablesInstruction_displayShort.count ()) {
      f = gExtensionMethodTable_gtlVariablesInstruction_displayShort (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlVariablesInstruction_displayShort.count ()) {
           f = gExtensionMethodTable_gtlVariablesInstruction_displayShort (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlVariablesInstruction_displayShort.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_vars, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlVariablesInstruction_displayShort (const cPtr_gtlVariablesInstruction * inObject,
                                                                  const GALGAS_gtlData constinArgument_vars,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlVariablesInstruction * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlVariablesInstruction) ;
  if (constinArgument_vars.isValid ()) {
    if (constinArgument_vars.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct) {
      GALGAS_gtlStruct cast_33716_variableMap ((cPtr_gtlStruct *) constinArgument_vars.ptr ()) ;
      cEnumerator_gtlVarMap enumerator_33764 (cast_33716_variableMap.getter_value (SOURCE_FILE ("gtl_instructions.galgas", 1135)), kEnumeration_up) ;
      while (enumerator_33764.hasCurrentObject ()) {
        inCompiler->printMessage (enumerator_33764.current_lkey (HERE).getter_string (SOURCE_FILE ("gtl_instructions.galgas", 1136)).add_operation (GALGAS_string (" >\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1136))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1136)) ;
        inCompiler->printMessage (callExtensionGetter_desc ((const cPtr_gtlData *) enumerator_33764.current_value (HERE).ptr (), GALGAS_uint ((uint32_t) 4U), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1137))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1137)) ;
        enumerator_33764.gotoNextObject () ;
      }
    }else{
      const GALGAS_gtlVariablesInstruction temp_0 = object ;
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlVariablesInstruction *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1140)), GALGAS_string ("INTERNAL ERROR. a variable map should be a @gtlStruct"), fixItArray1  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1140)) ;
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlVariablesInstruction_displayShort (void) {
  enterExtensionMethod_displayShort (kTypeDescriptor_GALGAS_gtlVariablesInstruction.mSlotID,
                                     extensionMethod_gtlVariablesInstruction_displayShort) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlVariablesInstruction_displayShort (void) {
  gExtensionMethodTable_gtlVariablesInstruction_displayShort.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlVariablesInstruction_displayShort (defineExtensionMethod_gtlVariablesInstruction_displayShort,
                                                                 freeExtensionMethod_gtlVariablesInstruction_displayShort) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension method '@gtlVariablesInstruction displayLong'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlVariablesInstruction_displayLong> gExtensionMethodTable_gtlVariablesInstruction_displayLong ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_displayLong (const int32_t inClassIndex,
                                       extensionMethodSignature_gtlVariablesInstruction_displayLong inMethod) {
  gExtensionMethodTable_gtlVariablesInstruction_displayLong.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_displayLong (const cPtr_gtlVariablesInstruction * inObject,
                                      const GALGAS_gtlData constin_vars,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlVariablesInstruction) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlVariablesInstruction_displayLong f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlVariablesInstruction_displayLong.count ()) {
      f = gExtensionMethodTable_gtlVariablesInstruction_displayLong (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlVariablesInstruction_displayLong.count ()) {
           f = gExtensionMethodTable_gtlVariablesInstruction_displayLong (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlVariablesInstruction_displayLong.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_vars, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlVariablesInstruction_displayLong (const cPtr_gtlVariablesInstruction * inObject,
                                                                 const GALGAS_gtlData constinArgument_vars,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlVariablesInstruction * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlVariablesInstruction) ;
  GALGAS_string var_delimitor_34021 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (61)), GALGAS_uint ((uint32_t) 79U)  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1147)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1147)) ;
  GALGAS_string var_varDelim_34099 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (45)), GALGAS_uint ((uint32_t) 79U)  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1148)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1148)) ;
  GALGAS_string var_separator_34179 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (61)), GALGAS_uint ((uint32_t) 17U)  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1149)) ;
  inCompiler->printMessage (var_separator_34179.add_operation (GALGAS_string (" Variables "), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1150)).add_operation (var_separator_34179, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1150)).add_operation (GALGAS_string ("= Displayed from "), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1151)).add_operation (var_separator_34179, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1151)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1152))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1150)) ;
  inCompiler->printMessage (object->mAttribute_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1153)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1153))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1153)) ;
  inCompiler->printMessage (var_delimitor_34021  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1154)) ;
  if (constinArgument_vars.isValid ()) {
    if (constinArgument_vars.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct) {
      GALGAS_gtlStruct cast_34441_variableMap ((cPtr_gtlStruct *) constinArgument_vars.ptr ()) ;
      cEnumerator_gtlVarMap enumerator_34489 (cast_34441_variableMap.getter_value (SOURCE_FILE ("gtl_instructions.galgas", 1157)), kEnumeration_up) ;
      while (enumerator_34489.hasCurrentObject ()) {
        inCompiler->printMessage (var_varDelim_34099  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1158)) ;
        inCompiler->printMessage (enumerator_34489.current_lkey (HERE).getter_string (SOURCE_FILE ("gtl_instructions.galgas", 1159)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1159))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1159)) ;
        inCompiler->printMessage (var_varDelim_34099  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1160)) ;
        inCompiler->printMessage (callExtensionGetter_desc ((const cPtr_gtlData *) enumerator_34489.current_value (HERE).ptr (), GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1161))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1161)) ;
        enumerator_34489.gotoNextObject () ;
      }
    }else{
      const GALGAS_gtlVariablesInstruction temp_0 = object ;
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlVariablesInstruction *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1164)), GALGAS_string ("INTERNAL ERROR. a variable map should be a @gtlStruct"), fixItArray1  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1164)) ;
    }
  }
  inCompiler->printMessage (var_delimitor_34021  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1166)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlVariablesInstruction_displayLong (void) {
  enterExtensionMethod_displayLong (kTypeDescriptor_GALGAS_gtlVariablesInstruction.mSlotID,
                                    extensionMethod_gtlVariablesInstruction_displayLong) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlVariablesInstruction_displayLong (void) {
  gExtensionMethodTable_gtlVariablesInstruction_displayLong.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlVariablesInstruction_displayLong (defineExtensionMethod_gtlVariablesInstruction_displayLong,
                                                                freeExtensionMethod_gtlVariablesInstruction_displayLong) ;


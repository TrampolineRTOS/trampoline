#include "Compiler.h"
#include "C_galgas_io.h"
#include "C_galgas_CLI_Options.h"
#include "PrologueEpilogue.h"

//--------------------------------------------------------------------------------------------------

#include "all-declarations-4.h"

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLetSubstractInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetSubstractInstruction * p = (const cPtr_gtlLetSubstractInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetSubstractInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lValue.objectCompare (p->mProperty_lValue) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rValue.objectCompare (p->mProperty_rValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetSubstractInstruction::GALGAS_gtlLetSubstractInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetSubstractInstruction::GALGAS_gtlLetSubstractInstruction (const cPtr_gtlLetSubstractInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetSubstractInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetSubstractInstruction GALGAS_gtlLetSubstractInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlLetSubstractInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlLetSubstractInstruction::cPtr_gtlLetSubstractInstruction (const GALGAS_location & in_where,
                                                                  const GALGAS_string & in_signature,
                                                                  const GALGAS_gtlVarPath & in_lValue,
                                                                  const GALGAS_gtlExpression & in_rValue
                                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLetSubstractInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetSubstractInstruction ;
}

void cPtr_gtlLetSubstractInstruction::description (String & ioString,
                                                   const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlLetSubstractInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_lValue.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_rValue.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLetSubstractInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlLetSubstractInstruction (mProperty_where, mProperty_signature, mProperty_lValue, mProperty_rValue COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlLetSubstractInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLetSubstractInstruction ("gtlLetSubstractInstruction",
                                                                                  & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLetSubstractInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetSubstractInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLetSubstractInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetSubstractInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetSubstractInstruction GALGAS_gtlLetSubstractInstruction::extractObject (const GALGAS_object & inObject,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetSubstractInstruction result ;
  const GALGAS_gtlLetSubstractInstruction * p = (const GALGAS_gtlLetSubstractInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlLetSubstractInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetSubstractInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLetMultiplyInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetMultiplyInstruction * p = (const cPtr_gtlLetMultiplyInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetMultiplyInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lValue.objectCompare (p->mProperty_lValue) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rValue.objectCompare (p->mProperty_rValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetMultiplyInstruction::GALGAS_gtlLetMultiplyInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetMultiplyInstruction::GALGAS_gtlLetMultiplyInstruction (const cPtr_gtlLetMultiplyInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetMultiplyInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetMultiplyInstruction GALGAS_gtlLetMultiplyInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlLetMultiplyInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlLetMultiplyInstruction::cPtr_gtlLetMultiplyInstruction (const GALGAS_location & in_where,
                                                                const GALGAS_string & in_signature,
                                                                const GALGAS_gtlVarPath & in_lValue,
                                                                const GALGAS_gtlExpression & in_rValue
                                                                COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLetMultiplyInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetMultiplyInstruction ;
}

void cPtr_gtlLetMultiplyInstruction::description (String & ioString,
                                                  const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlLetMultiplyInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_lValue.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_rValue.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLetMultiplyInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlLetMultiplyInstruction (mProperty_where, mProperty_signature, mProperty_lValue, mProperty_rValue COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlLetMultiplyInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLetMultiplyInstruction ("gtlLetMultiplyInstruction",
                                                                                 & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLetMultiplyInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetMultiplyInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLetMultiplyInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetMultiplyInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetMultiplyInstruction GALGAS_gtlLetMultiplyInstruction::extractObject (const GALGAS_object & inObject,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetMultiplyInstruction result ;
  const GALGAS_gtlLetMultiplyInstruction * p = (const GALGAS_gtlLetMultiplyInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlLetMultiplyInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetMultiplyInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLetDivideInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetDivideInstruction * p = (const cPtr_gtlLetDivideInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetDivideInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lValue.objectCompare (p->mProperty_lValue) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rValue.objectCompare (p->mProperty_rValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetDivideInstruction::GALGAS_gtlLetDivideInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetDivideInstruction::GALGAS_gtlLetDivideInstruction (const cPtr_gtlLetDivideInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetDivideInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetDivideInstruction GALGAS_gtlLetDivideInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlLetDivideInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlLetDivideInstruction::cPtr_gtlLetDivideInstruction (const GALGAS_location & in_where,
                                                            const GALGAS_string & in_signature,
                                                            const GALGAS_gtlVarPath & in_lValue,
                                                            const GALGAS_gtlExpression & in_rValue
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLetDivideInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetDivideInstruction ;
}

void cPtr_gtlLetDivideInstruction::description (String & ioString,
                                                const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlLetDivideInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_lValue.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_rValue.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLetDivideInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlLetDivideInstruction (mProperty_where, mProperty_signature, mProperty_lValue, mProperty_rValue COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlLetDivideInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLetDivideInstruction ("gtlLetDivideInstruction",
                                                                               & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLetDivideInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetDivideInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLetDivideInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetDivideInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetDivideInstruction GALGAS_gtlLetDivideInstruction::extractObject (const GALGAS_object & inObject,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetDivideInstruction result ;
  const GALGAS_gtlLetDivideInstruction * p = (const GALGAS_gtlLetDivideInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlLetDivideInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetDivideInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLetModuloInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetModuloInstruction * p = (const cPtr_gtlLetModuloInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetModuloInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lValue.objectCompare (p->mProperty_lValue) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rValue.objectCompare (p->mProperty_rValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetModuloInstruction::GALGAS_gtlLetModuloInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetModuloInstruction::GALGAS_gtlLetModuloInstruction (const cPtr_gtlLetModuloInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetModuloInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetModuloInstruction GALGAS_gtlLetModuloInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlLetModuloInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlLetModuloInstruction::cPtr_gtlLetModuloInstruction (const GALGAS_location & in_where,
                                                            const GALGAS_string & in_signature,
                                                            const GALGAS_gtlVarPath & in_lValue,
                                                            const GALGAS_gtlExpression & in_rValue
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLetModuloInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetModuloInstruction ;
}

void cPtr_gtlLetModuloInstruction::description (String & ioString,
                                                const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlLetModuloInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_lValue.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_rValue.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLetModuloInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlLetModuloInstruction (mProperty_where, mProperty_signature, mProperty_lValue, mProperty_rValue COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlLetModuloInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLetModuloInstruction ("gtlLetModuloInstruction",
                                                                               & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLetModuloInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetModuloInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLetModuloInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetModuloInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetModuloInstruction GALGAS_gtlLetModuloInstruction::extractObject (const GALGAS_object & inObject,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetModuloInstruction result ;
  const GALGAS_gtlLetModuloInstruction * p = (const GALGAS_gtlLetModuloInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlLetModuloInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetModuloInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLetShiftLeftInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetShiftLeftInstruction * p = (const cPtr_gtlLetShiftLeftInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetShiftLeftInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lValue.objectCompare (p->mProperty_lValue) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rValue.objectCompare (p->mProperty_rValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetShiftLeftInstruction::GALGAS_gtlLetShiftLeftInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetShiftLeftInstruction::GALGAS_gtlLetShiftLeftInstruction (const cPtr_gtlLetShiftLeftInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetShiftLeftInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetShiftLeftInstruction GALGAS_gtlLetShiftLeftInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlLetShiftLeftInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlLetShiftLeftInstruction::cPtr_gtlLetShiftLeftInstruction (const GALGAS_location & in_where,
                                                                  const GALGAS_string & in_signature,
                                                                  const GALGAS_gtlVarPath & in_lValue,
                                                                  const GALGAS_gtlExpression & in_rValue
                                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLetShiftLeftInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetShiftLeftInstruction ;
}

void cPtr_gtlLetShiftLeftInstruction::description (String & ioString,
                                                   const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlLetShiftLeftInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_lValue.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_rValue.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLetShiftLeftInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlLetShiftLeftInstruction (mProperty_where, mProperty_signature, mProperty_lValue, mProperty_rValue COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlLetShiftLeftInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLetShiftLeftInstruction ("gtlLetShiftLeftInstruction",
                                                                                  & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLetShiftLeftInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetShiftLeftInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLetShiftLeftInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetShiftLeftInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetShiftLeftInstruction GALGAS_gtlLetShiftLeftInstruction::extractObject (const GALGAS_object & inObject,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetShiftLeftInstruction result ;
  const GALGAS_gtlLetShiftLeftInstruction * p = (const GALGAS_gtlLetShiftLeftInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlLetShiftLeftInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetShiftLeftInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLetShiftRightInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetShiftRightInstruction * p = (const cPtr_gtlLetShiftRightInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetShiftRightInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lValue.objectCompare (p->mProperty_lValue) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rValue.objectCompare (p->mProperty_rValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetShiftRightInstruction::GALGAS_gtlLetShiftRightInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetShiftRightInstruction::GALGAS_gtlLetShiftRightInstruction (const cPtr_gtlLetShiftRightInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetShiftRightInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetShiftRightInstruction GALGAS_gtlLetShiftRightInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlLetShiftRightInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlLetShiftRightInstruction::cPtr_gtlLetShiftRightInstruction (const GALGAS_location & in_where,
                                                                    const GALGAS_string & in_signature,
                                                                    const GALGAS_gtlVarPath & in_lValue,
                                                                    const GALGAS_gtlExpression & in_rValue
                                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLetShiftRightInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetShiftRightInstruction ;
}

void cPtr_gtlLetShiftRightInstruction::description (String & ioString,
                                                    const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlLetShiftRightInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_lValue.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_rValue.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLetShiftRightInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlLetShiftRightInstruction (mProperty_where, mProperty_signature, mProperty_lValue, mProperty_rValue COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlLetShiftRightInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLetShiftRightInstruction ("gtlLetShiftRightInstruction",
                                                                                   & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLetShiftRightInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetShiftRightInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLetShiftRightInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetShiftRightInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetShiftRightInstruction GALGAS_gtlLetShiftRightInstruction::extractObject (const GALGAS_object & inObject,
                                                                                      Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetShiftRightInstruction result ;
  const GALGAS_gtlLetShiftRightInstruction * p = (const GALGAS_gtlLetShiftRightInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlLetShiftRightInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetShiftRightInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLetAndInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetAndInstruction * p = (const cPtr_gtlLetAndInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetAndInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lValue.objectCompare (p->mProperty_lValue) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rValue.objectCompare (p->mProperty_rValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetAndInstruction::GALGAS_gtlLetAndInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetAndInstruction::GALGAS_gtlLetAndInstruction (const cPtr_gtlLetAndInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetAndInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetAndInstruction GALGAS_gtlLetAndInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlLetAndInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlLetAndInstruction::cPtr_gtlLetAndInstruction (const GALGAS_location & in_where,
                                                      const GALGAS_string & in_signature,
                                                      const GALGAS_gtlVarPath & in_lValue,
                                                      const GALGAS_gtlExpression & in_rValue
                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLetAndInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetAndInstruction ;
}

void cPtr_gtlLetAndInstruction::description (String & ioString,
                                             const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlLetAndInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_lValue.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_rValue.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLetAndInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlLetAndInstruction (mProperty_where, mProperty_signature, mProperty_lValue, mProperty_rValue COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlLetAndInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLetAndInstruction ("gtlLetAndInstruction",
                                                                            & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLetAndInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetAndInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLetAndInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetAndInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetAndInstruction GALGAS_gtlLetAndInstruction::extractObject (const GALGAS_object & inObject,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetAndInstruction result ;
  const GALGAS_gtlLetAndInstruction * p = (const GALGAS_gtlLetAndInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlLetAndInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetAndInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLetOrInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetOrInstruction * p = (const cPtr_gtlLetOrInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetOrInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lValue.objectCompare (p->mProperty_lValue) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rValue.objectCompare (p->mProperty_rValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetOrInstruction::GALGAS_gtlLetOrInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetOrInstruction::GALGAS_gtlLetOrInstruction (const cPtr_gtlLetOrInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetOrInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetOrInstruction GALGAS_gtlLetOrInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlLetOrInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlLetOrInstruction::cPtr_gtlLetOrInstruction (const GALGAS_location & in_where,
                                                    const GALGAS_string & in_signature,
                                                    const GALGAS_gtlVarPath & in_lValue,
                                                    const GALGAS_gtlExpression & in_rValue
                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLetOrInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetOrInstruction ;
}

void cPtr_gtlLetOrInstruction::description (String & ioString,
                                            const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlLetOrInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_lValue.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_rValue.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLetOrInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlLetOrInstruction (mProperty_where, mProperty_signature, mProperty_lValue, mProperty_rValue COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlLetOrInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLetOrInstruction ("gtlLetOrInstruction",
                                                                           & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLetOrInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetOrInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLetOrInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetOrInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetOrInstruction GALGAS_gtlLetOrInstruction::extractObject (const GALGAS_object & inObject,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetOrInstruction result ;
  const GALGAS_gtlLetOrInstruction * p = (const GALGAS_gtlLetOrInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlLetOrInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetOrInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLetXorInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetXorInstruction * p = (const cPtr_gtlLetXorInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetXorInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lValue.objectCompare (p->mProperty_lValue) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rValue.objectCompare (p->mProperty_rValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetXorInstruction::GALGAS_gtlLetXorInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetXorInstruction::GALGAS_gtlLetXorInstruction (const cPtr_gtlLetXorInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetXorInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetXorInstruction GALGAS_gtlLetXorInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlLetXorInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlLetXorInstruction::cPtr_gtlLetXorInstruction (const GALGAS_location & in_where,
                                                      const GALGAS_string & in_signature,
                                                      const GALGAS_gtlVarPath & in_lValue,
                                                      const GALGAS_gtlExpression & in_rValue
                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLetXorInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetXorInstruction ;
}

void cPtr_gtlLetXorInstruction::description (String & ioString,
                                             const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlLetXorInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_lValue.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_rValue.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLetXorInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlLetXorInstruction (mProperty_where, mProperty_signature, mProperty_lValue, mProperty_rValue COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlLetXorInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLetXorInstruction ("gtlLetXorInstruction",
                                                                            & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLetXorInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetXorInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLetXorInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetXorInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLetXorInstruction GALGAS_gtlLetXorInstruction::extractObject (const GALGAS_object & inObject,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetXorInstruction result ;
  const GALGAS_gtlLetXorInstruction * p = (const GALGAS_gtlLetXorInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlLetXorInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetXorInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlEmitInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlEmitInstruction * p = (const cPtr_gtlEmitInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlEmitInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rValue.objectCompare (p->mProperty_rValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlEmitInstruction::objectCompare (const GALGAS_gtlEmitInstruction & inOperand) const {
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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlEmitInstruction::GALGAS_gtlEmitInstruction (void) :
GALGAS_gtlInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlEmitInstruction::GALGAS_gtlEmitInstruction (const cPtr_gtlEmitInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlEmitInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlEmitInstruction GALGAS_gtlEmitInstruction::class_func_new (const GALGAS_location & inAttribute_where,
                                                                     const GALGAS_string & inAttribute_signature,
                                                                     const GALGAS_gtlExpression & inAttribute_rValue
                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_gtlEmitInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_rValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlEmitInstruction (inAttribute_where, inAttribute_signature, inAttribute_rValue COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlEmitInstruction::readProperty_rValue (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlEmitInstruction * p = (const cPtr_gtlEmitInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlEmitInstruction) ;
    return p->mProperty_rValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlEmitInstruction::getter_rValue (UNUSED_LOCATION_ARGS) const {
  return mProperty_rValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlEmitInstruction::setter_setRValue (GALGAS_gtlExpression inValue
                                                  COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlEmitInstruction * p = (cPtr_gtlEmitInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlEmitInstruction) ;
    p->mProperty_rValue = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlEmitInstruction::setter_setRValue (GALGAS_gtlExpression inValue
                                                COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_rValue = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlEmitInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlEmitInstruction::cPtr_gtlEmitInstruction (const GALGAS_location & in_where,
                                                  const GALGAS_string & in_signature,
                                                  const GALGAS_gtlExpression & in_rValue
                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_rValue (in_rValue) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlEmitInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlEmitInstruction ;
}

void cPtr_gtlEmitInstruction::description (String & ioString,
                                           const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlEmitInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_rValue.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlEmitInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlEmitInstruction (mProperty_where, mProperty_signature, mProperty_rValue COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlEmitInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlEmitInstruction ("gtlEmitInstruction",
                                                                          & kTypeDescriptor_GALGAS_gtlInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlEmitInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlEmitInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlEmitInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlEmitInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlEmitInstruction GALGAS_gtlEmitInstruction::extractObject (const GALGAS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlEmitInstruction result ;
  const GALGAS_gtlEmitInstruction * p = (const GALGAS_gtlEmitInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlEmitInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlEmitInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlWriteToInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlWriteToInstruction * p = (const cPtr_gtlWriteToInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlWriteToInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_fileNameExpression.objectCompare (p->mProperty_fileNameExpression) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_isExecutable.objectCompare (p->mProperty_isExecutable) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_instructions.objectCompare (p->mProperty_instructions) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlWriteToInstruction::GALGAS_gtlWriteToInstruction (void) :
GALGAS_gtlInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlWriteToInstruction::GALGAS_gtlWriteToInstruction (const cPtr_gtlWriteToInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlWriteToInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlWriteToInstruction GALGAS_gtlWriteToInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlWriteToInstruction::readProperty_fileNameExpression (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlWriteToInstruction * p = (const cPtr_gtlWriteToInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWriteToInstruction) ;
    return p->mProperty_fileNameExpression ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlWriteToInstruction::getter_fileNameExpression (UNUSED_LOCATION_ARGS) const {
  return mProperty_fileNameExpression ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_gtlWriteToInstruction::readProperty_isExecutable (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_gtlWriteToInstruction * p = (const cPtr_gtlWriteToInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWriteToInstruction) ;
    return p->mProperty_isExecutable ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlWriteToInstruction::getter_isExecutable (UNUSED_LOCATION_ARGS) const {
  return mProperty_isExecutable ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlWriteToInstruction::readProperty_instructions (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_gtlWriteToInstruction * p = (const cPtr_gtlWriteToInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWriteToInstruction) ;
    return p->mProperty_instructions ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_gtlWriteToInstruction::getter_instructions (UNUSED_LOCATION_ARGS) const {
  return mProperty_instructions ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlWriteToInstruction::setter_setFileNameExpression (GALGAS_gtlExpression inValue
                                                                 COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlWriteToInstruction * p = (cPtr_gtlWriteToInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWriteToInstruction) ;
    p->mProperty_fileNameExpression = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlWriteToInstruction::setter_setFileNameExpression (GALGAS_gtlExpression inValue
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_fileNameExpression = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlWriteToInstruction::setter_setIsExecutable (GALGAS_bool inValue
                                                           COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlWriteToInstruction * p = (cPtr_gtlWriteToInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWriteToInstruction) ;
    p->mProperty_isExecutable = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlWriteToInstruction::setter_setIsExecutable (GALGAS_bool inValue
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_isExecutable = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlWriteToInstruction::setter_setInstructions (GALGAS_gtlInstructionList inValue
                                                           COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlWriteToInstruction * p = (cPtr_gtlWriteToInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWriteToInstruction) ;
    p->mProperty_instructions = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlWriteToInstruction::setter_setInstructions (GALGAS_gtlInstructionList inValue
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_instructions = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlWriteToInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlWriteToInstruction::cPtr_gtlWriteToInstruction (const GALGAS_location & in_where,
                                                        const GALGAS_string & in_signature,
                                                        const GALGAS_gtlExpression & in_fileNameExpression,
                                                        const GALGAS_bool & in_isExecutable,
                                                        const GALGAS_gtlInstructionList & in_instructions
                                                        COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_fileNameExpression (in_fileNameExpression),
mProperty_isExecutable (in_isExecutable),
mProperty_instructions (in_instructions) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlWriteToInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlWriteToInstruction ;
}

void cPtr_gtlWriteToInstruction::description (String & ioString,
                                              const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlWriteToInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_fileNameExpression.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_isExecutable.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_instructions.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlWriteToInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlWriteToInstruction (mProperty_where, mProperty_signature, mProperty_fileNameExpression, mProperty_isExecutable, mProperty_instructions COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlWriteToInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlWriteToInstruction ("gtlWriteToInstruction",
                                                                             & kTypeDescriptor_GALGAS_gtlInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlWriteToInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlWriteToInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlWriteToInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlWriteToInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlWriteToInstruction GALGAS_gtlWriteToInstruction::extractObject (const GALGAS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlWriteToInstruction result ;
  const GALGAS_gtlWriteToInstruction * p = (const GALGAS_gtlWriteToInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlWriteToInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlWriteToInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlTemplateInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlTemplateInstruction * p = (const cPtr_gtlTemplateInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_prefix.objectCompare (p->mProperty_prefix) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_fileName.objectCompare (p->mProperty_fileName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_ifExists.objectCompare (p->mProperty_ifExists) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_isGlobal.objectCompare (p->mProperty_isGlobal) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_arguments.objectCompare (p->mProperty_arguments) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_instructionsIfNotFound.objectCompare (p->mProperty_instructionsIfNotFound) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateInstruction::GALGAS_gtlTemplateInstruction (void) :
GALGAS_gtlInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateInstruction::GALGAS_gtlTemplateInstruction (const cPtr_gtlTemplateInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlTemplateInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateInstruction GALGAS_gtlTemplateInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_gtlTemplateInstruction::readProperty_prefix (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_gtlTemplateInstruction * p = (const cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    return p->mProperty_prefix ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlTemplateInstruction::getter_prefix (UNUSED_LOCATION_ARGS) const {
  return mProperty_prefix ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlTemplateInstruction::readProperty_fileName (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlTemplateInstruction * p = (const cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    return p->mProperty_fileName ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlTemplateInstruction::getter_fileName (UNUSED_LOCATION_ARGS) const {
  return mProperty_fileName ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_gtlTemplateInstruction::readProperty_ifExists (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_gtlTemplateInstruction * p = (const cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    return p->mProperty_ifExists ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlTemplateInstruction::getter_ifExists (UNUSED_LOCATION_ARGS) const {
  return mProperty_ifExists ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_gtlTemplateInstruction::readProperty_isGlobal (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_gtlTemplateInstruction * p = (const cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    return p->mProperty_isGlobal ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlTemplateInstruction::getter_isGlobal (UNUSED_LOCATION_ARGS) const {
  return mProperty_isGlobal ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList GALGAS_gtlTemplateInstruction::readProperty_arguments (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpressionList () ;
  }else{
    const cPtr_gtlTemplateInstruction * p = (const cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    return p->mProperty_arguments ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList cPtr_gtlTemplateInstruction::getter_arguments (UNUSED_LOCATION_ARGS) const {
  return mProperty_arguments ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlTemplateInstruction::readProperty_instructionsIfNotFound (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_gtlTemplateInstruction * p = (const cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    return p->mProperty_instructionsIfNotFound ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_gtlTemplateInstruction::getter_instructionsIfNotFound (UNUSED_LOCATION_ARGS) const {
  return mProperty_instructionsIfNotFound ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlTemplateInstruction::setter_setPrefix (GALGAS_lstring inValue
                                                      COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlTemplateInstruction * p = (cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    p->mProperty_prefix = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlTemplateInstruction::setter_setPrefix (GALGAS_lstring inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_prefix = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlTemplateInstruction::setter_setFileName (GALGAS_gtlExpression inValue
                                                        COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlTemplateInstruction * p = (cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    p->mProperty_fileName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlTemplateInstruction::setter_setFileName (GALGAS_gtlExpression inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_fileName = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlTemplateInstruction::setter_setIfExists (GALGAS_bool inValue
                                                        COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlTemplateInstruction * p = (cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    p->mProperty_ifExists = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlTemplateInstruction::setter_setIfExists (GALGAS_bool inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_ifExists = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlTemplateInstruction::setter_setIsGlobal (GALGAS_bool inValue
                                                        COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlTemplateInstruction * p = (cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    p->mProperty_isGlobal = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlTemplateInstruction::setter_setIsGlobal (GALGAS_bool inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_isGlobal = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlTemplateInstruction::setter_setArguments (GALGAS_gtlExpressionList inValue
                                                         COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlTemplateInstruction * p = (cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    p->mProperty_arguments = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlTemplateInstruction::setter_setArguments (GALGAS_gtlExpressionList inValue
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_arguments = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlTemplateInstruction::setter_setInstructionsIfNotFound (GALGAS_gtlInstructionList inValue
                                                                      COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlTemplateInstruction * p = (cPtr_gtlTemplateInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateInstruction) ;
    p->mProperty_instructionsIfNotFound = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlTemplateInstruction::setter_setInstructionsIfNotFound (GALGAS_gtlInstructionList inValue
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_instructionsIfNotFound = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlTemplateInstruction class
//--------------------------------------------------------------------------------------------------

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
mProperty_prefix (in_prefix),
mProperty_fileName (in_fileName),
mProperty_ifExists (in_ifExists),
mProperty_isGlobal (in_isGlobal),
mProperty_arguments (in_arguments),
mProperty_instructionsIfNotFound (in_instructionsIfNotFound) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlTemplateInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplateInstruction ;
}

void cPtr_gtlTemplateInstruction::description (String & ioString,
                                               const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlTemplateInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_prefix.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_fileName.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_ifExists.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_isGlobal.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_arguments.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_instructionsIfNotFound.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlTemplateInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlTemplateInstruction (mProperty_where, mProperty_signature, mProperty_prefix, mProperty_fileName, mProperty_ifExists, mProperty_isGlobal, mProperty_arguments, mProperty_instructionsIfNotFound COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlTemplateInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTemplateInstruction ("gtlTemplateInstruction",
                                                                              & kTypeDescriptor_GALGAS_gtlInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlTemplateInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplateInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlTemplateInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTemplateInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateInstruction GALGAS_gtlTemplateInstruction::extractObject (const GALGAS_object & inObject,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplateInstruction result ;
  const GALGAS_gtlTemplateInstruction * p = (const GALGAS_gtlTemplateInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlTemplateInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTemplateInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlForeachStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_keyName.objectCompare (p->mProperty_keyName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_variableName.objectCompare (p->mProperty_variableName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_indexName.objectCompare (p->mProperty_indexName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_iterable.objectCompare (p->mProperty_iterable) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_beforeList.objectCompare (p->mProperty_beforeList) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_betweenList.objectCompare (p->mProperty_betweenList) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_afterList.objectCompare (p->mProperty_afterList) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_doList.objectCompare (p->mProperty_doList) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlForeachStatementInstruction::GALGAS_gtlForeachStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlForeachStatementInstruction::GALGAS_gtlForeachStatementInstruction (const cPtr_gtlForeachStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlForeachStatementInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlForeachStatementInstruction GALGAS_gtlForeachStatementInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_gtlForeachStatementInstruction::readProperty_keyName (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    return p->mProperty_keyName ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlForeachStatementInstruction::getter_keyName (UNUSED_LOCATION_ARGS) const {
  return mProperty_keyName ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_gtlForeachStatementInstruction::readProperty_variableName (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    return p->mProperty_variableName ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlForeachStatementInstruction::getter_variableName (UNUSED_LOCATION_ARGS) const {
  return mProperty_variableName ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_gtlForeachStatementInstruction::readProperty_indexName (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    return p->mProperty_indexName ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlForeachStatementInstruction::getter_indexName (UNUSED_LOCATION_ARGS) const {
  return mProperty_indexName ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlForeachStatementInstruction::readProperty_iterable (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    return p->mProperty_iterable ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlForeachStatementInstruction::getter_iterable (UNUSED_LOCATION_ARGS) const {
  return mProperty_iterable ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlForeachStatementInstruction::readProperty_beforeList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    return p->mProperty_beforeList ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_gtlForeachStatementInstruction::getter_beforeList (UNUSED_LOCATION_ARGS) const {
  return mProperty_beforeList ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlForeachStatementInstruction::readProperty_betweenList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    return p->mProperty_betweenList ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_gtlForeachStatementInstruction::getter_betweenList (UNUSED_LOCATION_ARGS) const {
  return mProperty_betweenList ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlForeachStatementInstruction::readProperty_afterList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    return p->mProperty_afterList ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_gtlForeachStatementInstruction::getter_afterList (UNUSED_LOCATION_ARGS) const {
  return mProperty_afterList ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlForeachStatementInstruction::readProperty_doList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_gtlForeachStatementInstruction * p = (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    return p->mProperty_doList ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_gtlForeachStatementInstruction::getter_doList (UNUSED_LOCATION_ARGS) const {
  return mProperty_doList ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlForeachStatementInstruction::setter_setKeyName (GALGAS_lstring inValue
                                                               COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlForeachStatementInstruction * p = (cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    p->mProperty_keyName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlForeachStatementInstruction::setter_setKeyName (GALGAS_lstring inValue
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_keyName = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlForeachStatementInstruction::setter_setVariableName (GALGAS_lstring inValue
                                                                    COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlForeachStatementInstruction * p = (cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    p->mProperty_variableName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlForeachStatementInstruction::setter_setVariableName (GALGAS_lstring inValue
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_variableName = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlForeachStatementInstruction::setter_setIndexName (GALGAS_lstring inValue
                                                                 COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlForeachStatementInstruction * p = (cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    p->mProperty_indexName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlForeachStatementInstruction::setter_setIndexName (GALGAS_lstring inValue
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_indexName = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlForeachStatementInstruction::setter_setIterable (GALGAS_gtlExpression inValue
                                                                COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlForeachStatementInstruction * p = (cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    p->mProperty_iterable = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlForeachStatementInstruction::setter_setIterable (GALGAS_gtlExpression inValue
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_iterable = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlForeachStatementInstruction::setter_setBeforeList (GALGAS_gtlInstructionList inValue
                                                                  COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlForeachStatementInstruction * p = (cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    p->mProperty_beforeList = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlForeachStatementInstruction::setter_setBeforeList (GALGAS_gtlInstructionList inValue
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_beforeList = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlForeachStatementInstruction::setter_setBetweenList (GALGAS_gtlInstructionList inValue
                                                                   COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlForeachStatementInstruction * p = (cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    p->mProperty_betweenList = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlForeachStatementInstruction::setter_setBetweenList (GALGAS_gtlInstructionList inValue
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_betweenList = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlForeachStatementInstruction::setter_setAfterList (GALGAS_gtlInstructionList inValue
                                                                 COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlForeachStatementInstruction * p = (cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    p->mProperty_afterList = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlForeachStatementInstruction::setter_setAfterList (GALGAS_gtlInstructionList inValue
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_afterList = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlForeachStatementInstruction::setter_setDoList (GALGAS_gtlInstructionList inValue
                                                              COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlForeachStatementInstruction * p = (cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForeachStatementInstruction) ;
    p->mProperty_doList = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlForeachStatementInstruction::setter_setDoList (GALGAS_gtlInstructionList inValue
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_doList = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlForeachStatementInstruction class
//--------------------------------------------------------------------------------------------------

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
mProperty_keyName (in_keyName),
mProperty_variableName (in_variableName),
mProperty_indexName (in_indexName),
mProperty_iterable (in_iterable),
mProperty_beforeList (in_beforeList),
mProperty_betweenList (in_betweenList),
mProperty_afterList (in_afterList),
mProperty_doList (in_doList) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlForeachStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlForeachStatementInstruction ;
}

void cPtr_gtlForeachStatementInstruction::description (String & ioString,
                                                       const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlForeachStatementInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_keyName.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_variableName.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_indexName.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_iterable.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_beforeList.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_betweenList.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_afterList.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_doList.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlForeachStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlForeachStatementInstruction (mProperty_where, mProperty_signature, mProperty_keyName, mProperty_variableName, mProperty_indexName, mProperty_iterable, mProperty_beforeList, mProperty_betweenList, mProperty_afterList, mProperty_doList COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlForeachStatementInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlForeachStatementInstruction ("gtlForeachStatementInstruction",
                                                                                      & kTypeDescriptor_GALGAS_gtlInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlForeachStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlForeachStatementInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlForeachStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlForeachStatementInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlForeachStatementInstruction GALGAS_gtlForeachStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                            Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlForeachStatementInstruction result ;
  const GALGAS_gtlForeachStatementInstruction * p = (const GALGAS_gtlForeachStatementInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlForeachStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlForeachStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//Extension method '@gtlForeachStatementInstruction iterateOnMap'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlForeachStatementInstruction::method_iterateOnMap (GALGAS_gtlContext & ioArgument_context,
                                                               GALGAS_gtlData & ioArgument_vars,
                                                               GALGAS_library & ioArgument_lib,
                                                               GALGAS_string & ioArgument_outputString,
                                                               const GALGAS_gtlMap constinArgument_iterableMap,
                                                               Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, GALGAS_string::makeEmptyString ().objectCompare (this->mProperty_keyName.readProperty_string ())).boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_lstring::class_func_new (GALGAS_string ("KEY"), this->mProperty_keyName.readProperty_location (), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 620)) ;
  }else if (kBoolFalse == test_1) {
    temp_0 = this->mProperty_keyName ;
  }
  GALGAS_lstring var_actualKeyName_18094 = temp_0 ;
  cEnumerator_gtlVarMap enumerator_18195 (constinArgument_iterableMap.readProperty_value (), kENUMERATION_UP) ;
  GALGAS_uint index_18191 ((uint32_t) 0) ;
  const bool bool_2 = true ;
  if (enumerator_18195.hasCurrentObject () && bool_2) {
    extensionMethod_execute (this->mProperty_beforeList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 627)) ;
    while (enumerator_18195.hasCurrentObject () && bool_2) {
      {
      ioArgument_vars.insulate (HERE) ;
      cPtr_gtlData * ptr_18313 = (cPtr_gtlData *) ioArgument_vars.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_18313, this->mProperty_variableName, enumerator_18195.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 629)) ;
      }
      {
      ioArgument_vars.insulate (HERE) ;
      cPtr_gtlData * ptr_18362 = (cPtr_gtlData *) ioArgument_vars.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_18362, var_actualKeyName_18094, GALGAS_gtlString::class_func_new (this->mProperty_keyName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 631)), enumerator_18195.current_lkey (HERE).readProperty_string ()  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 631)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 630)) ;
      }
      {
      ioArgument_vars.insulate (HERE) ;
      cPtr_gtlData * ptr_18476 = (cPtr_gtlData *) ioArgument_vars.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_18476, this->mProperty_indexName, GALGAS_gtlInt::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 634)), index_18191.getter_bigint (SOURCE_FILE ("gtl_instructions.galgas", 634))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 634)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 633)) ;
      }
      extensionMethod_execute (this->mProperty_doList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 636)) ;
      enumerator_18195.gotoNextObject () ;
      index_18191.increment () ;
      if (enumerator_18195.hasCurrentObject () && bool_2) {
        extensionMethod_execute (this->mProperty_betweenList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 638)) ;
      }
    }
    extensionMethod_execute (this->mProperty_afterList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 640)) ;
  }
}

//--------------------------------------------------------------------------------------------------

void callExtensionMethod_iterateOnMap (cPtr_gtlForeachStatementInstruction * inObject,
                                       GALGAS_gtlContext & io_context,
                                       GALGAS_gtlData & io_vars,
                                       GALGAS_library & io_lib,
                                       GALGAS_string & io_outputString,
                                       const GALGAS_gtlMap constin_iterableMap,
                                       Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlForeachStatementInstruction) ;
    inObject->method_iterateOnMap  (io_context, io_vars, io_lib, io_outputString, constin_iterableMap, inCompiler COMMA_THERE) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Extension method '@gtlForeachStatementInstruction iterateOnList'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlForeachStatementInstruction::method_iterateOnList (GALGAS_gtlContext & ioArgument_context,
                                                                GALGAS_gtlData & ioArgument_vars,
                                                                GALGAS_library & ioArgument_lib,
                                                                GALGAS_string & ioArgument_outputString,
                                                                const GALGAS_gtlList constinArgument_iterableList,
                                                                Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, GALGAS_string::makeEmptyString ().objectCompare (this->mProperty_keyName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticWarning (this->mProperty_keyName.readProperty_location (), GALGAS_string ("a key variable cannot be define when iterating on a list"), fixItArray1  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 652)) ;
    }
  }
  cEnumerator_list enumerator_19087 (constinArgument_iterableList.readProperty_value (), kENUMERATION_UP) ;
  GALGAS_uint index_19083 ((uint32_t) 0) ;
  const bool bool_2 = true ;
  if (enumerator_19087.hasCurrentObject () && bool_2) {
    extensionMethod_execute (this->mProperty_beforeList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 656)) ;
    while (enumerator_19087.hasCurrentObject () && bool_2) {
      {
      ioArgument_vars.insulate (HERE) ;
      cPtr_gtlData * ptr_19206 = (cPtr_gtlData *) ioArgument_vars.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_19206, this->mProperty_variableName, enumerator_19087.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 658)) ;
      }
      {
      ioArgument_vars.insulate (HERE) ;
      cPtr_gtlData * ptr_19255 = (cPtr_gtlData *) ioArgument_vars.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_19255, this->mProperty_indexName, GALGAS_gtlInt::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 660)), index_19083.getter_bigint (SOURCE_FILE ("gtl_instructions.galgas", 660))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 660)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 659)) ;
      }
      extensionMethod_execute (this->mProperty_doList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 662)) ;
      enumerator_19087.gotoNextObject () ;
      index_19083.increment () ;
      if (enumerator_19087.hasCurrentObject () && bool_2) {
        extensionMethod_execute (this->mProperty_betweenList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 664)) ;
      }
    }
    extensionMethod_execute (this->mProperty_afterList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 666)) ;
  }
}

//--------------------------------------------------------------------------------------------------

void callExtensionMethod_iterateOnList (cPtr_gtlForeachStatementInstruction * inObject,
                                        GALGAS_gtlContext & io_context,
                                        GALGAS_gtlData & io_vars,
                                        GALGAS_library & io_lib,
                                        GALGAS_string & io_outputString,
                                        const GALGAS_gtlList constin_iterableList,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlForeachStatementInstruction) ;
    inObject->method_iterateOnList  (io_context, io_vars, io_lib, io_outputString, constin_iterableList, inCompiler COMMA_THERE) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Extension method '@gtlForeachStatementInstruction iterateOnSet'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlForeachStatementInstruction::method_iterateOnSet (GALGAS_gtlContext & ioArgument_context,
                                                               GALGAS_gtlData & ioArgument_vars,
                                                               GALGAS_library & ioArgument_lib,
                                                               GALGAS_string & ioArgument_outputString,
                                                               const GALGAS_gtlSet constinArgument_iterableSet,
                                                               Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, GALGAS_string::makeEmptyString ().objectCompare (this->mProperty_keyName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticWarning (this->mProperty_keyName.readProperty_location (), GALGAS_string ("a key variable cannot be define when iterating on a set"), fixItArray1  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 678)) ;
    }
  }
  cEnumerator_lstringset enumerator_19858 (constinArgument_iterableSet.readProperty_value (), kENUMERATION_UP) ;
  GALGAS_uint index_19854 ((uint32_t) 0) ;
  const bool bool_2 = true ;
  if (enumerator_19858.hasCurrentObject () && bool_2) {
    extensionMethod_execute (this->mProperty_beforeList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 682)) ;
    while (enumerator_19858.hasCurrentObject () && bool_2) {
      {
      ioArgument_vars.insulate (HERE) ;
      cPtr_gtlData * ptr_19976 = (cPtr_gtlData *) ioArgument_vars.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_19976, this->mProperty_variableName, GALGAS_gtlString::class_func_new (enumerator_19858.current_lkey (HERE).readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 686)), enumerator_19858.current_lkey (HERE).readProperty_string ()  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 686)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 684)) ;
      }
      {
      ioArgument_vars.insulate (HERE) ;
      cPtr_gtlData * ptr_20083 = (cPtr_gtlData *) ioArgument_vars.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_20083, this->mProperty_indexName, GALGAS_gtlInt::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 689)), index_19854.getter_bigint (SOURCE_FILE ("gtl_instructions.galgas", 689))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 689)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 688)) ;
      }
      extensionMethod_execute (this->mProperty_doList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 691)) ;
      enumerator_19858.gotoNextObject () ;
      index_19854.increment () ;
      if (enumerator_19858.hasCurrentObject () && bool_2) {
        extensionMethod_execute (this->mProperty_betweenList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 693)) ;
      }
    }
    extensionMethod_execute (this->mProperty_afterList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 695)) ;
  }
}

//--------------------------------------------------------------------------------------------------

void callExtensionMethod_iterateOnSet (cPtr_gtlForeachStatementInstruction * inObject,
                                       GALGAS_gtlContext & io_context,
                                       GALGAS_gtlData & io_vars,
                                       GALGAS_library & io_lib,
                                       GALGAS_string & io_outputString,
                                       const GALGAS_gtlSet constin_iterableSet,
                                       Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlForeachStatementInstruction) ;
    inObject->method_iterateOnSet  (io_context, io_vars, io_lib, io_outputString, constin_iterableSet, inCompiler COMMA_THERE) ;
  }
}
//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlForStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlForStatementInstruction * p = (const cPtr_gtlForStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlForStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_identifier.objectCompare (p->mProperty_identifier) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_iterable.objectCompare (p->mProperty_iterable) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_betweenList.objectCompare (p->mProperty_betweenList) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_doList.objectCompare (p->mProperty_doList) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlForStatementInstruction::objectCompare (const GALGAS_gtlForStatementInstruction & inOperand) const {
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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlForStatementInstruction::GALGAS_gtlForStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlForStatementInstruction::GALGAS_gtlForStatementInstruction (const cPtr_gtlForStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlForStatementInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlForStatementInstruction GALGAS_gtlForStatementInstruction::class_func_new (const GALGAS_location & inAttribute_where,
                                                                                     const GALGAS_string & inAttribute_signature,
                                                                                     const GALGAS_lstring & inAttribute_identifier,
                                                                                     const GALGAS_gtlExpressionList & inAttribute_iterable,
                                                                                     const GALGAS_gtlInstructionList & inAttribute_betweenList,
                                                                                     const GALGAS_gtlInstructionList & inAttribute_doList
                                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_gtlForStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_identifier.isValid () && inAttribute_iterable.isValid () && inAttribute_betweenList.isValid () && inAttribute_doList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlForStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_identifier, inAttribute_iterable, inAttribute_betweenList, inAttribute_doList COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_gtlForStatementInstruction::readProperty_identifier (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_gtlForStatementInstruction * p = (const cPtr_gtlForStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForStatementInstruction) ;
    return p->mProperty_identifier ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlForStatementInstruction::getter_identifier (UNUSED_LOCATION_ARGS) const {
  return mProperty_identifier ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList GALGAS_gtlForStatementInstruction::readProperty_iterable (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpressionList () ;
  }else{
    const cPtr_gtlForStatementInstruction * p = (const cPtr_gtlForStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForStatementInstruction) ;
    return p->mProperty_iterable ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList cPtr_gtlForStatementInstruction::getter_iterable (UNUSED_LOCATION_ARGS) const {
  return mProperty_iterable ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlForStatementInstruction::readProperty_betweenList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_gtlForStatementInstruction * p = (const cPtr_gtlForStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForStatementInstruction) ;
    return p->mProperty_betweenList ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_gtlForStatementInstruction::getter_betweenList (UNUSED_LOCATION_ARGS) const {
  return mProperty_betweenList ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlForStatementInstruction::readProperty_doList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_gtlForStatementInstruction * p = (const cPtr_gtlForStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForStatementInstruction) ;
    return p->mProperty_doList ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_gtlForStatementInstruction::getter_doList (UNUSED_LOCATION_ARGS) const {
  return mProperty_doList ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlForStatementInstruction::setter_setIdentifier (GALGAS_lstring inValue
                                                              COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlForStatementInstruction * p = (cPtr_gtlForStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForStatementInstruction) ;
    p->mProperty_identifier = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlForStatementInstruction::setter_setIdentifier (GALGAS_lstring inValue
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_identifier = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlForStatementInstruction::setter_setIterable (GALGAS_gtlExpressionList inValue
                                                            COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlForStatementInstruction * p = (cPtr_gtlForStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForStatementInstruction) ;
    p->mProperty_iterable = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlForStatementInstruction::setter_setIterable (GALGAS_gtlExpressionList inValue
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_iterable = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlForStatementInstruction::setter_setBetweenList (GALGAS_gtlInstructionList inValue
                                                               COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlForStatementInstruction * p = (cPtr_gtlForStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForStatementInstruction) ;
    p->mProperty_betweenList = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlForStatementInstruction::setter_setBetweenList (GALGAS_gtlInstructionList inValue
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_betweenList = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlForStatementInstruction::setter_setDoList (GALGAS_gtlInstructionList inValue
                                                          COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlForStatementInstruction * p = (cPtr_gtlForStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForStatementInstruction) ;
    p->mProperty_doList = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlForStatementInstruction::setter_setDoList (GALGAS_gtlInstructionList inValue
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_doList = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlForStatementInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlForStatementInstruction::cPtr_gtlForStatementInstruction (const GALGAS_location & in_where,
                                                                  const GALGAS_string & in_signature,
                                                                  const GALGAS_lstring & in_identifier,
                                                                  const GALGAS_gtlExpressionList & in_iterable,
                                                                  const GALGAS_gtlInstructionList & in_betweenList,
                                                                  const GALGAS_gtlInstructionList & in_doList
                                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_identifier (in_identifier),
mProperty_iterable (in_iterable),
mProperty_betweenList (in_betweenList),
mProperty_doList (in_doList) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlForStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlForStatementInstruction ;
}

void cPtr_gtlForStatementInstruction::description (String & ioString,
                                                   const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlForStatementInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_identifier.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_iterable.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_betweenList.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_doList.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlForStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlForStatementInstruction (mProperty_where, mProperty_signature, mProperty_identifier, mProperty_iterable, mProperty_betweenList, mProperty_doList COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlForStatementInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlForStatementInstruction ("gtlForStatementInstruction",
                                                                                  & kTypeDescriptor_GALGAS_gtlInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlForStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlForStatementInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlForStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlForStatementInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlForStatementInstruction GALGAS_gtlForStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlForStatementInstruction result ;
  const GALGAS_gtlForStatementInstruction * p = (const GALGAS_gtlForStatementInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlForStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlForStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLoopStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_identifier.objectCompare (p->mProperty_identifier) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_start.objectCompare (p->mProperty_start) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_stop.objectCompare (p->mProperty_stop) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_step.objectCompare (p->mProperty_step) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_upDown.objectCompare (p->mProperty_upDown) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_beforeList.objectCompare (p->mProperty_beforeList) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_betweenList.objectCompare (p->mProperty_betweenList) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_afterList.objectCompare (p->mProperty_afterList) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_doList.objectCompare (p->mProperty_doList) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLoopStatementInstruction::GALGAS_gtlLoopStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLoopStatementInstruction::GALGAS_gtlLoopStatementInstruction (const cPtr_gtlLoopStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLoopStatementInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlLoopStatementInstruction GALGAS_gtlLoopStatementInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_gtlLoopStatementInstruction::readProperty_identifier (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    return p->mProperty_identifier ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlLoopStatementInstruction::getter_identifier (UNUSED_LOCATION_ARGS) const {
  return mProperty_identifier ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlLoopStatementInstruction::readProperty_start (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    return p->mProperty_start ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlLoopStatementInstruction::getter_start (UNUSED_LOCATION_ARGS) const {
  return mProperty_start ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlLoopStatementInstruction::readProperty_stop (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    return p->mProperty_stop ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlLoopStatementInstruction::getter_stop (UNUSED_LOCATION_ARGS) const {
  return mProperty_stop ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlLoopStatementInstruction::readProperty_step (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    return p->mProperty_step ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlLoopStatementInstruction::getter_step (UNUSED_LOCATION_ARGS) const {
  return mProperty_step ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_gtlLoopStatementInstruction::readProperty_upDown (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_sint_36__34_ () ;
  }else{
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    return p->mProperty_upDown ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ cPtr_gtlLoopStatementInstruction::getter_upDown (UNUSED_LOCATION_ARGS) const {
  return mProperty_upDown ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlLoopStatementInstruction::readProperty_beforeList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    return p->mProperty_beforeList ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_gtlLoopStatementInstruction::getter_beforeList (UNUSED_LOCATION_ARGS) const {
  return mProperty_beforeList ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlLoopStatementInstruction::readProperty_betweenList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    return p->mProperty_betweenList ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_gtlLoopStatementInstruction::getter_betweenList (UNUSED_LOCATION_ARGS) const {
  return mProperty_betweenList ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlLoopStatementInstruction::readProperty_afterList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    return p->mProperty_afterList ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_gtlLoopStatementInstruction::getter_afterList (UNUSED_LOCATION_ARGS) const {
  return mProperty_afterList ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlLoopStatementInstruction::readProperty_doList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_gtlLoopStatementInstruction * p = (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    return p->mProperty_doList ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_gtlLoopStatementInstruction::getter_doList (UNUSED_LOCATION_ARGS) const {
  return mProperty_doList ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlLoopStatementInstruction::setter_setIdentifier (GALGAS_lstring inValue
                                                               COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlLoopStatementInstruction * p = (cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    p->mProperty_identifier = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlLoopStatementInstruction::setter_setIdentifier (GALGAS_lstring inValue
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_identifier = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlLoopStatementInstruction::setter_setStart (GALGAS_gtlExpression inValue
                                                          COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlLoopStatementInstruction * p = (cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    p->mProperty_start = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlLoopStatementInstruction::setter_setStart (GALGAS_gtlExpression inValue
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_start = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlLoopStatementInstruction::setter_setStop (GALGAS_gtlExpression inValue
                                                         COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlLoopStatementInstruction * p = (cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    p->mProperty_stop = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlLoopStatementInstruction::setter_setStop (GALGAS_gtlExpression inValue
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_stop = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlLoopStatementInstruction::setter_setStep (GALGAS_gtlExpression inValue
                                                         COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlLoopStatementInstruction * p = (cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    p->mProperty_step = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlLoopStatementInstruction::setter_setStep (GALGAS_gtlExpression inValue
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_step = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlLoopStatementInstruction::setter_setUpDown (GALGAS_sint_36__34_ inValue
                                                           COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlLoopStatementInstruction * p = (cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    p->mProperty_upDown = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlLoopStatementInstruction::setter_setUpDown (GALGAS_sint_36__34_ inValue
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_upDown = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlLoopStatementInstruction::setter_setBeforeList (GALGAS_gtlInstructionList inValue
                                                               COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlLoopStatementInstruction * p = (cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    p->mProperty_beforeList = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlLoopStatementInstruction::setter_setBeforeList (GALGAS_gtlInstructionList inValue
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_beforeList = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlLoopStatementInstruction::setter_setBetweenList (GALGAS_gtlInstructionList inValue
                                                                COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlLoopStatementInstruction * p = (cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    p->mProperty_betweenList = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlLoopStatementInstruction::setter_setBetweenList (GALGAS_gtlInstructionList inValue
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_betweenList = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlLoopStatementInstruction::setter_setAfterList (GALGAS_gtlInstructionList inValue
                                                              COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlLoopStatementInstruction * p = (cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    p->mProperty_afterList = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlLoopStatementInstruction::setter_setAfterList (GALGAS_gtlInstructionList inValue
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_afterList = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlLoopStatementInstruction::setter_setDoList (GALGAS_gtlInstructionList inValue
                                                           COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlLoopStatementInstruction * p = (cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLoopStatementInstruction) ;
    p->mProperty_doList = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlLoopStatementInstruction::setter_setDoList (GALGAS_gtlInstructionList inValue
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_doList = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlLoopStatementInstruction class
//--------------------------------------------------------------------------------------------------

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
mProperty_identifier (in_identifier),
mProperty_start (in_start),
mProperty_stop (in_stop),
mProperty_step (in_step),
mProperty_upDown (in_upDown),
mProperty_beforeList (in_beforeList),
mProperty_betweenList (in_betweenList),
mProperty_afterList (in_afterList),
mProperty_doList (in_doList) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLoopStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLoopStatementInstruction ;
}

void cPtr_gtlLoopStatementInstruction::description (String & ioString,
                                                    const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlLoopStatementInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_identifier.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_start.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_stop.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_step.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_upDown.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_beforeList.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_betweenList.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_afterList.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_doList.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLoopStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlLoopStatementInstruction (mProperty_where, mProperty_signature, mProperty_identifier, mProperty_start, mProperty_stop, mProperty_step, mProperty_upDown, mProperty_beforeList, mProperty_betweenList, mProperty_afterList, mProperty_doList COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlLoopStatementInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLoopStatementInstruction ("gtlLoopStatementInstruction",
                                                                                   & kTypeDescriptor_GALGAS_gtlInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLoopStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLoopStatementInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLoopStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLoopStatementInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlLoopStatementInstruction GALGAS_gtlLoopStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                      Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlLoopStatementInstruction result ;
  const GALGAS_gtlLoopStatementInstruction * p = (const GALGAS_gtlLoopStatementInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlLoopStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLoopStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlRepeatStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlRepeatStatementInstruction * p = (const cPtr_gtlRepeatStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlRepeatStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_limit.objectCompare (p->mProperty_limit) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_condition.objectCompare (p->mProperty_condition) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_continueList.objectCompare (p->mProperty_continueList) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_doList.objectCompare (p->mProperty_doList) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlRepeatStatementInstruction::GALGAS_gtlRepeatStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlRepeatStatementInstruction::GALGAS_gtlRepeatStatementInstruction (const cPtr_gtlRepeatStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlRepeatStatementInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlRepeatStatementInstruction GALGAS_gtlRepeatStatementInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlRepeatStatementInstruction::readProperty_limit (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlRepeatStatementInstruction * p = (const cPtr_gtlRepeatStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlRepeatStatementInstruction) ;
    return p->mProperty_limit ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlRepeatStatementInstruction::getter_limit (UNUSED_LOCATION_ARGS) const {
  return mProperty_limit ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlRepeatStatementInstruction::readProperty_condition (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlRepeatStatementInstruction * p = (const cPtr_gtlRepeatStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlRepeatStatementInstruction) ;
    return p->mProperty_condition ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlRepeatStatementInstruction::getter_condition (UNUSED_LOCATION_ARGS) const {
  return mProperty_condition ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlRepeatStatementInstruction::readProperty_continueList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_gtlRepeatStatementInstruction * p = (const cPtr_gtlRepeatStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlRepeatStatementInstruction) ;
    return p->mProperty_continueList ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_gtlRepeatStatementInstruction::getter_continueList (UNUSED_LOCATION_ARGS) const {
  return mProperty_continueList ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlRepeatStatementInstruction::readProperty_doList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_gtlRepeatStatementInstruction * p = (const cPtr_gtlRepeatStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlRepeatStatementInstruction) ;
    return p->mProperty_doList ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_gtlRepeatStatementInstruction::getter_doList (UNUSED_LOCATION_ARGS) const {
  return mProperty_doList ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlRepeatStatementInstruction::setter_setLimit (GALGAS_gtlExpression inValue
                                                            COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlRepeatStatementInstruction * p = (cPtr_gtlRepeatStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlRepeatStatementInstruction) ;
    p->mProperty_limit = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlRepeatStatementInstruction::setter_setLimit (GALGAS_gtlExpression inValue
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_limit = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlRepeatStatementInstruction::setter_setCondition (GALGAS_gtlExpression inValue
                                                                COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlRepeatStatementInstruction * p = (cPtr_gtlRepeatStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlRepeatStatementInstruction) ;
    p->mProperty_condition = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlRepeatStatementInstruction::setter_setCondition (GALGAS_gtlExpression inValue
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_condition = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlRepeatStatementInstruction::setter_setContinueList (GALGAS_gtlInstructionList inValue
                                                                   COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlRepeatStatementInstruction * p = (cPtr_gtlRepeatStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlRepeatStatementInstruction) ;
    p->mProperty_continueList = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlRepeatStatementInstruction::setter_setContinueList (GALGAS_gtlInstructionList inValue
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_continueList = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlRepeatStatementInstruction::setter_setDoList (GALGAS_gtlInstructionList inValue
                                                             COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlRepeatStatementInstruction * p = (cPtr_gtlRepeatStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlRepeatStatementInstruction) ;
    p->mProperty_doList = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlRepeatStatementInstruction::setter_setDoList (GALGAS_gtlInstructionList inValue
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_doList = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlRepeatStatementInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlRepeatStatementInstruction::cPtr_gtlRepeatStatementInstruction (const GALGAS_location & in_where,
                                                                        const GALGAS_string & in_signature,
                                                                        const GALGAS_gtlExpression & in_limit,
                                                                        const GALGAS_gtlExpression & in_condition,
                                                                        const GALGAS_gtlInstructionList & in_continueList,
                                                                        const GALGAS_gtlInstructionList & in_doList
                                                                        COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_limit (in_limit),
mProperty_condition (in_condition),
mProperty_continueList (in_continueList),
mProperty_doList (in_doList) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlRepeatStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlRepeatStatementInstruction ;
}

void cPtr_gtlRepeatStatementInstruction::description (String & ioString,
                                                      const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlRepeatStatementInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_limit.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_condition.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_continueList.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_doList.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlRepeatStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlRepeatStatementInstruction (mProperty_where, mProperty_signature, mProperty_limit, mProperty_condition, mProperty_continueList, mProperty_doList COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlRepeatStatementInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlRepeatStatementInstruction ("gtlRepeatStatementInstruction",
                                                                                     & kTypeDescriptor_GALGAS_gtlInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlRepeatStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlRepeatStatementInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlRepeatStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlRepeatStatementInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlRepeatStatementInstruction GALGAS_gtlRepeatStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                          Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlRepeatStatementInstruction result ;
  const GALGAS_gtlRepeatStatementInstruction * p = (const GALGAS_gtlRepeatStatementInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlRepeatStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlRepeatStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlErrorStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlErrorStatementInstruction * p = (const cPtr_gtlErrorStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlErrorStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_identifier.objectCompare (p->mProperty_identifier) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_hereInstead.objectCompare (p->mProperty_hereInstead) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_errorMessage.objectCompare (p->mProperty_errorMessage) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlErrorStatementInstruction::objectCompare (const GALGAS_gtlErrorStatementInstruction & inOperand) const {
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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlErrorStatementInstruction::GALGAS_gtlErrorStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlErrorStatementInstruction::GALGAS_gtlErrorStatementInstruction (const cPtr_gtlErrorStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlErrorStatementInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlErrorStatementInstruction GALGAS_gtlErrorStatementInstruction::class_func_new (const GALGAS_location & inAttribute_where,
                                                                                         const GALGAS_string & inAttribute_signature,
                                                                                         const GALGAS_gtlVarPath & inAttribute_identifier,
                                                                                         const GALGAS_bool & inAttribute_hereInstead,
                                                                                         const GALGAS_gtlExpression & inAttribute_errorMessage
                                                                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlErrorStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_identifier.isValid () && inAttribute_hereInstead.isValid () && inAttribute_errorMessage.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlErrorStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_identifier, inAttribute_hereInstead, inAttribute_errorMessage COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath GALGAS_gtlErrorStatementInstruction::readProperty_identifier (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlVarPath () ;
  }else{
    const cPtr_gtlErrorStatementInstruction * p = (const cPtr_gtlErrorStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlErrorStatementInstruction) ;
    return p->mProperty_identifier ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath cPtr_gtlErrorStatementInstruction::getter_identifier (UNUSED_LOCATION_ARGS) const {
  return mProperty_identifier ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_gtlErrorStatementInstruction::readProperty_hereInstead (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_gtlErrorStatementInstruction * p = (const cPtr_gtlErrorStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlErrorStatementInstruction) ;
    return p->mProperty_hereInstead ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlErrorStatementInstruction::getter_hereInstead (UNUSED_LOCATION_ARGS) const {
  return mProperty_hereInstead ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlErrorStatementInstruction::readProperty_errorMessage (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlErrorStatementInstruction * p = (const cPtr_gtlErrorStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlErrorStatementInstruction) ;
    return p->mProperty_errorMessage ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlErrorStatementInstruction::getter_errorMessage (UNUSED_LOCATION_ARGS) const {
  return mProperty_errorMessage ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlErrorStatementInstruction::setter_setIdentifier (GALGAS_gtlVarPath inValue
                                                                COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlErrorStatementInstruction * p = (cPtr_gtlErrorStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlErrorStatementInstruction) ;
    p->mProperty_identifier = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlErrorStatementInstruction::setter_setIdentifier (GALGAS_gtlVarPath inValue
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_identifier = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlErrorStatementInstruction::setter_setHereInstead (GALGAS_bool inValue
                                                                 COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlErrorStatementInstruction * p = (cPtr_gtlErrorStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlErrorStatementInstruction) ;
    p->mProperty_hereInstead = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlErrorStatementInstruction::setter_setHereInstead (GALGAS_bool inValue
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_hereInstead = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlErrorStatementInstruction::setter_setErrorMessage (GALGAS_gtlExpression inValue
                                                                  COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlErrorStatementInstruction * p = (cPtr_gtlErrorStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlErrorStatementInstruction) ;
    p->mProperty_errorMessage = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlErrorStatementInstruction::setter_setErrorMessage (GALGAS_gtlExpression inValue
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_errorMessage = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlErrorStatementInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlErrorStatementInstruction::cPtr_gtlErrorStatementInstruction (const GALGAS_location & in_where,
                                                                      const GALGAS_string & in_signature,
                                                                      const GALGAS_gtlVarPath & in_identifier,
                                                                      const GALGAS_bool & in_hereInstead,
                                                                      const GALGAS_gtlExpression & in_errorMessage
                                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_identifier (in_identifier),
mProperty_hereInstead (in_hereInstead),
mProperty_errorMessage (in_errorMessage) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlErrorStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlErrorStatementInstruction ;
}

void cPtr_gtlErrorStatementInstruction::description (String & ioString,
                                                     const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlErrorStatementInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_identifier.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_hereInstead.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_errorMessage.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlErrorStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlErrorStatementInstruction (mProperty_where, mProperty_signature, mProperty_identifier, mProperty_hereInstead, mProperty_errorMessage COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlErrorStatementInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlErrorStatementInstruction ("gtlErrorStatementInstruction",
                                                                                    & kTypeDescriptor_GALGAS_gtlInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlErrorStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlErrorStatementInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlErrorStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlErrorStatementInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlErrorStatementInstruction GALGAS_gtlErrorStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                        Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlErrorStatementInstruction result ;
  const GALGAS_gtlErrorStatementInstruction * p = (const GALGAS_gtlErrorStatementInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlErrorStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlErrorStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlWarningStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlWarningStatementInstruction * p = (const cPtr_gtlWarningStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlWarningStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_identifier.objectCompare (p->mProperty_identifier) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_hereInstead.objectCompare (p->mProperty_hereInstead) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_warningMessage.objectCompare (p->mProperty_warningMessage) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlWarningStatementInstruction::GALGAS_gtlWarningStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlWarningStatementInstruction::GALGAS_gtlWarningStatementInstruction (const cPtr_gtlWarningStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlWarningStatementInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlWarningStatementInstruction GALGAS_gtlWarningStatementInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath GALGAS_gtlWarningStatementInstruction::readProperty_identifier (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlVarPath () ;
  }else{
    const cPtr_gtlWarningStatementInstruction * p = (const cPtr_gtlWarningStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWarningStatementInstruction) ;
    return p->mProperty_identifier ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath cPtr_gtlWarningStatementInstruction::getter_identifier (UNUSED_LOCATION_ARGS) const {
  return mProperty_identifier ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_gtlWarningStatementInstruction::readProperty_hereInstead (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_gtlWarningStatementInstruction * p = (const cPtr_gtlWarningStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWarningStatementInstruction) ;
    return p->mProperty_hereInstead ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlWarningStatementInstruction::getter_hereInstead (UNUSED_LOCATION_ARGS) const {
  return mProperty_hereInstead ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlWarningStatementInstruction::readProperty_warningMessage (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlWarningStatementInstruction * p = (const cPtr_gtlWarningStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWarningStatementInstruction) ;
    return p->mProperty_warningMessage ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlWarningStatementInstruction::getter_warningMessage (UNUSED_LOCATION_ARGS) const {
  return mProperty_warningMessage ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlWarningStatementInstruction::setter_setIdentifier (GALGAS_gtlVarPath inValue
                                                                  COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlWarningStatementInstruction * p = (cPtr_gtlWarningStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWarningStatementInstruction) ;
    p->mProperty_identifier = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlWarningStatementInstruction::setter_setIdentifier (GALGAS_gtlVarPath inValue
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_identifier = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlWarningStatementInstruction::setter_setHereInstead (GALGAS_bool inValue
                                                                   COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlWarningStatementInstruction * p = (cPtr_gtlWarningStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWarningStatementInstruction) ;
    p->mProperty_hereInstead = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlWarningStatementInstruction::setter_setHereInstead (GALGAS_bool inValue
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_hereInstead = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlWarningStatementInstruction::setter_setWarningMessage (GALGAS_gtlExpression inValue
                                                                      COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlWarningStatementInstruction * p = (cPtr_gtlWarningStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWarningStatementInstruction) ;
    p->mProperty_warningMessage = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlWarningStatementInstruction::setter_setWarningMessage (GALGAS_gtlExpression inValue
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_warningMessage = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlWarningStatementInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlWarningStatementInstruction::cPtr_gtlWarningStatementInstruction (const GALGAS_location & in_where,
                                                                          const GALGAS_string & in_signature,
                                                                          const GALGAS_gtlVarPath & in_identifier,
                                                                          const GALGAS_bool & in_hereInstead,
                                                                          const GALGAS_gtlExpression & in_warningMessage
                                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_identifier (in_identifier),
mProperty_hereInstead (in_hereInstead),
mProperty_warningMessage (in_warningMessage) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlWarningStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlWarningStatementInstruction ;
}

void cPtr_gtlWarningStatementInstruction::description (String & ioString,
                                                       const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlWarningStatementInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_identifier.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_hereInstead.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_warningMessage.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlWarningStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlWarningStatementInstruction (mProperty_where, mProperty_signature, mProperty_identifier, mProperty_hereInstead, mProperty_warningMessage COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlWarningStatementInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlWarningStatementInstruction ("gtlWarningStatementInstruction",
                                                                                      & kTypeDescriptor_GALGAS_gtlInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlWarningStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlWarningStatementInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlWarningStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlWarningStatementInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlWarningStatementInstruction GALGAS_gtlWarningStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                            Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlWarningStatementInstruction result ;
  const GALGAS_gtlWarningStatementInstruction * p = (const GALGAS_gtlWarningStatementInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlWarningStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlWarningStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlPrintStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlPrintStatementInstruction * p = (const cPtr_gtlPrintStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlPrintStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_carriageReturn.objectCompare (p->mProperty_carriageReturn) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_messageToPrint.objectCompare (p->mProperty_messageToPrint) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlPrintStatementInstruction::GALGAS_gtlPrintStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlPrintStatementInstruction::GALGAS_gtlPrintStatementInstruction (const cPtr_gtlPrintStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlPrintStatementInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlPrintStatementInstruction GALGAS_gtlPrintStatementInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_gtlPrintStatementInstruction::readProperty_carriageReturn (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_gtlPrintStatementInstruction * p = (const cPtr_gtlPrintStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlPrintStatementInstruction) ;
    return p->mProperty_carriageReturn ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlPrintStatementInstruction::getter_carriageReturn (UNUSED_LOCATION_ARGS) const {
  return mProperty_carriageReturn ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlPrintStatementInstruction::readProperty_messageToPrint (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlPrintStatementInstruction * p = (const cPtr_gtlPrintStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlPrintStatementInstruction) ;
    return p->mProperty_messageToPrint ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlPrintStatementInstruction::getter_messageToPrint (UNUSED_LOCATION_ARGS) const {
  return mProperty_messageToPrint ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlPrintStatementInstruction::setter_setCarriageReturn (GALGAS_bool inValue
                                                                    COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlPrintStatementInstruction * p = (cPtr_gtlPrintStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlPrintStatementInstruction) ;
    p->mProperty_carriageReturn = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlPrintStatementInstruction::setter_setCarriageReturn (GALGAS_bool inValue
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_carriageReturn = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlPrintStatementInstruction::setter_setMessageToPrint (GALGAS_gtlExpression inValue
                                                                    COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlPrintStatementInstruction * p = (cPtr_gtlPrintStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlPrintStatementInstruction) ;
    p->mProperty_messageToPrint = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlPrintStatementInstruction::setter_setMessageToPrint (GALGAS_gtlExpression inValue
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_messageToPrint = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlPrintStatementInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlPrintStatementInstruction::cPtr_gtlPrintStatementInstruction (const GALGAS_location & in_where,
                                                                      const GALGAS_string & in_signature,
                                                                      const GALGAS_bool & in_carriageReturn,
                                                                      const GALGAS_gtlExpression & in_messageToPrint
                                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_carriageReturn (in_carriageReturn),
mProperty_messageToPrint (in_messageToPrint) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlPrintStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlPrintStatementInstruction ;
}

void cPtr_gtlPrintStatementInstruction::description (String & ioString,
                                                     const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlPrintStatementInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_carriageReturn.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_messageToPrint.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlPrintStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlPrintStatementInstruction (mProperty_where, mProperty_signature, mProperty_carriageReturn, mProperty_messageToPrint COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlPrintStatementInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlPrintStatementInstruction ("gtlPrintStatementInstruction",
                                                                                    & kTypeDescriptor_GALGAS_gtlInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlPrintStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlPrintStatementInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlPrintStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlPrintStatementInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlPrintStatementInstruction GALGAS_gtlPrintStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                        Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlPrintStatementInstruction result ;
  const GALGAS_gtlPrintStatementInstruction * p = (const GALGAS_gtlPrintStatementInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlPrintStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlPrintStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlSortStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlSortStatementInstruction * p = (const cPtr_gtlSortStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlSortStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_variablePath.objectCompare (p->mProperty_variablePath) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_order.objectCompare (p->mProperty_order) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlSortStatementInstruction::objectCompare (const GALGAS_gtlSortStatementInstruction & inOperand) const {
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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlSortStatementInstruction::GALGAS_gtlSortStatementInstruction (void) :
GALGAS_gtlAbstractSortInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlSortStatementInstruction::GALGAS_gtlSortStatementInstruction (const cPtr_gtlSortStatementInstruction * inSourcePtr) :
GALGAS_gtlAbstractSortInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlSortStatementInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlSortStatementInstruction GALGAS_gtlSortStatementInstruction::class_func_new (const GALGAS_location & inAttribute_where,
                                                                                       const GALGAS_string & inAttribute_signature,
                                                                                       const GALGAS_gtlVarPath & inAttribute_variablePath,
                                                                                       const GALGAS_lsint & inAttribute_order
                                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_gtlSortStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_variablePath.isValid () && inAttribute_order.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlSortStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_variablePath, inAttribute_order COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lsint GALGAS_gtlSortStatementInstruction::readProperty_order (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lsint () ;
  }else{
    const cPtr_gtlSortStatementInstruction * p = (const cPtr_gtlSortStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSortStatementInstruction) ;
    return p->mProperty_order ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lsint cPtr_gtlSortStatementInstruction::getter_order (UNUSED_LOCATION_ARGS) const {
  return mProperty_order ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlSortStatementInstruction::setter_setOrder (GALGAS_lsint inValue
                                                          COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlSortStatementInstruction * p = (cPtr_gtlSortStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSortStatementInstruction) ;
    p->mProperty_order = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlSortStatementInstruction::setter_setOrder (GALGAS_lsint inValue
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_order = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlSortStatementInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlSortStatementInstruction::cPtr_gtlSortStatementInstruction (const GALGAS_location & in_where,
                                                                    const GALGAS_string & in_signature,
                                                                    const GALGAS_gtlVarPath & in_variablePath,
                                                                    const GALGAS_lsint & in_order
                                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlAbstractSortInstruction (in_where, in_signature, in_variablePath COMMA_THERE),
mProperty_order (in_order) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlSortStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSortStatementInstruction ;
}

void cPtr_gtlSortStatementInstruction::description (String & ioString,
                                                    const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlSortStatementInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_variablePath.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_order.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlSortStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlSortStatementInstruction (mProperty_where, mProperty_signature, mProperty_variablePath, mProperty_order COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlSortStatementInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlSortStatementInstruction ("gtlSortStatementInstruction",
                                                                                   & kTypeDescriptor_GALGAS_gtlAbstractSortInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlSortStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSortStatementInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlSortStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlSortStatementInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlSortStatementInstruction GALGAS_gtlSortStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                      Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlSortStatementInstruction result ;
  const GALGAS_gtlSortStatementInstruction * p = (const GALGAS_gtlSortStatementInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlSortStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlSortStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlTabStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlTabStatementInstruction * p = (const cPtr_gtlTabStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlTabStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_tabValue.objectCompare (p->mProperty_tabValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTabStatementInstruction::GALGAS_gtlTabStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTabStatementInstruction::GALGAS_gtlTabStatementInstruction (const cPtr_gtlTabStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlTabStatementInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlTabStatementInstruction GALGAS_gtlTabStatementInstruction::class_func_new (const GALGAS_location & inAttribute_where,
                                                                                     const GALGAS_string & inAttribute_signature,
                                                                                     const GALGAS_gtlExpression & inAttribute_tabValue
                                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_gtlTabStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_tabValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlTabStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_tabValue COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlTabStatementInstruction::readProperty_tabValue (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlTabStatementInstruction * p = (const cPtr_gtlTabStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTabStatementInstruction) ;
    return p->mProperty_tabValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlTabStatementInstruction::getter_tabValue (UNUSED_LOCATION_ARGS) const {
  return mProperty_tabValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlTabStatementInstruction::setter_setTabValue (GALGAS_gtlExpression inValue
                                                            COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlTabStatementInstruction * p = (cPtr_gtlTabStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTabStatementInstruction) ;
    p->mProperty_tabValue = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlTabStatementInstruction::setter_setTabValue (GALGAS_gtlExpression inValue
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_tabValue = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlTabStatementInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlTabStatementInstruction::cPtr_gtlTabStatementInstruction (const GALGAS_location & in_where,
                                                                  const GALGAS_string & in_signature,
                                                                  const GALGAS_gtlExpression & in_tabValue
                                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_tabValue (in_tabValue) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlTabStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTabStatementInstruction ;
}

void cPtr_gtlTabStatementInstruction::description (String & ioString,
                                                   const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlTabStatementInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_tabValue.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlTabStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlTabStatementInstruction (mProperty_where, mProperty_signature, mProperty_tabValue COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlTabStatementInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTabStatementInstruction ("gtlTabStatementInstruction",
                                                                                  & kTypeDescriptor_GALGAS_gtlInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlTabStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTabStatementInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlTabStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTabStatementInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTabStatementInstruction GALGAS_gtlTabStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlTabStatementInstruction result ;
  const GALGAS_gtlTabStatementInstruction * p = (const GALGAS_gtlTabStatementInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlTabStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTabStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlSetterCallInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlSetterCallInstruction * p = (const cPtr_gtlSetterCallInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlSetterCallInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_target.objectCompare (p->mProperty_target) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_setterName.objectCompare (p->mProperty_setterName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_arguments.objectCompare (p->mProperty_arguments) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlSetterCallInstruction::GALGAS_gtlSetterCallInstruction (void) :
GALGAS_gtlInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlSetterCallInstruction::GALGAS_gtlSetterCallInstruction (const cPtr_gtlSetterCallInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlSetterCallInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlSetterCallInstruction GALGAS_gtlSetterCallInstruction::class_func_new (const GALGAS_location & inAttribute_where,
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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath GALGAS_gtlSetterCallInstruction::readProperty_target (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlVarPath () ;
  }else{
    const cPtr_gtlSetterCallInstruction * p = (const cPtr_gtlSetterCallInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSetterCallInstruction) ;
    return p->mProperty_target ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath cPtr_gtlSetterCallInstruction::getter_target (UNUSED_LOCATION_ARGS) const {
  return mProperty_target ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_gtlSetterCallInstruction::readProperty_setterName (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_gtlSetterCallInstruction * p = (const cPtr_gtlSetterCallInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSetterCallInstruction) ;
    return p->mProperty_setterName ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlSetterCallInstruction::getter_setterName (UNUSED_LOCATION_ARGS) const {
  return mProperty_setterName ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList GALGAS_gtlSetterCallInstruction::readProperty_arguments (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpressionList () ;
  }else{
    const cPtr_gtlSetterCallInstruction * p = (const cPtr_gtlSetterCallInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSetterCallInstruction) ;
    return p->mProperty_arguments ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList cPtr_gtlSetterCallInstruction::getter_arguments (UNUSED_LOCATION_ARGS) const {
  return mProperty_arguments ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlSetterCallInstruction::setter_setTarget (GALGAS_gtlVarPath inValue
                                                        COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlSetterCallInstruction * p = (cPtr_gtlSetterCallInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSetterCallInstruction) ;
    p->mProperty_target = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlSetterCallInstruction::setter_setTarget (GALGAS_gtlVarPath inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_target = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlSetterCallInstruction::setter_setSetterName (GALGAS_lstring inValue
                                                            COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlSetterCallInstruction * p = (cPtr_gtlSetterCallInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSetterCallInstruction) ;
    p->mProperty_setterName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlSetterCallInstruction::setter_setSetterName (GALGAS_lstring inValue
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_setterName = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlSetterCallInstruction::setter_setArguments (GALGAS_gtlExpressionList inValue
                                                           COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlSetterCallInstruction * p = (cPtr_gtlSetterCallInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSetterCallInstruction) ;
    p->mProperty_arguments = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlSetterCallInstruction::setter_setArguments (GALGAS_gtlExpressionList inValue
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_arguments = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlSetterCallInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlSetterCallInstruction::cPtr_gtlSetterCallInstruction (const GALGAS_location & in_where,
                                                              const GALGAS_string & in_signature,
                                                              const GALGAS_gtlVarPath & in_target,
                                                              const GALGAS_lstring & in_setterName,
                                                              const GALGAS_gtlExpressionList & in_arguments
                                                              COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_target (in_target),
mProperty_setterName (in_setterName),
mProperty_arguments (in_arguments) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlSetterCallInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSetterCallInstruction ;
}

void cPtr_gtlSetterCallInstruction::description (String & ioString,
                                                 const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlSetterCallInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_target.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_setterName.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_arguments.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlSetterCallInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlSetterCallInstruction (mProperty_where, mProperty_signature, mProperty_target, mProperty_setterName, mProperty_arguments COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlSetterCallInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlSetterCallInstruction ("gtlSetterCallInstruction",
                                                                                & kTypeDescriptor_GALGAS_gtlInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlSetterCallInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSetterCallInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlSetterCallInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlSetterCallInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlSetterCallInstruction GALGAS_gtlSetterCallInstruction::extractObject (const GALGAS_object & inObject,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlSetterCallInstruction result ;
  const GALGAS_gtlSetterCallInstruction * p = (const GALGAS_gtlSetterCallInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlSetterCallInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlSetterCallInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext appendInstructionToStepDo'
//
//--------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_debuggerContext_appendInstructionToStepDo> gExtensionModifierTable_debuggerContext_appendInstructionToStepDo ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_appendInstructionToStepDo (const int32_t inClassIndex,
                                                     extensionSetterSignature_debuggerContext_appendInstructionToStepDo inModifier) {
  gExtensionModifierTable_debuggerContext_appendInstructionToStepDo.forceObjectAtIndex (inClassIndex, inModifier, nullptr) ;
}

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_appendInstructionToStepDo (cPtr_debuggerContext * inObject,
                                                    GALGAS_gtlInstruction in_instruction,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debuggerContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_debuggerContext_appendInstructionToStepDo f = nullptr ;
    if (classIndex < gExtensionModifierTable_debuggerContext_appendInstructionToStepDo.count ()) {
      f = gExtensionModifierTable_debuggerContext_appendInstructionToStepDo (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_debuggerContext_appendInstructionToStepDo.count ()) {
           f = gExtensionModifierTable_debuggerContext_appendInstructionToStepDo (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_debuggerContext_appendInstructionToStepDo.forceObjectAtIndex (classIndex, f, nullptr) ;
    }
    f (inObject, in_instruction, inCompiler COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

static void extensionSetter_debuggerContext_appendInstructionToStepDo (cPtr_debuggerContext * inObject,
                                                                       GALGAS_gtlInstruction inArgument_instruction,
                                                                       Compiler * /* inCompiler */
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_debuggerContext * object = inObject ;
  macroValidSharedObject (object, cPtr_debuggerContext) ;
  object->mProperty_doList.addAssign_operation (inArgument_instruction  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 130)) ;
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_debuggerContext_appendInstructionToStepDo (void) {
  enterExtensionSetter_appendInstructionToStepDo (kTypeDescriptor_GALGAS_debuggerContext.mSlotID,
                                                  extensionSetter_debuggerContext_appendInstructionToStepDo) ;
}

//--------------------------------------------------------------------------------------------------

static void freeExtensionModifier_debuggerContext_appendInstructionToStepDo (void) {
  gExtensionModifierTable_debuggerContext_appendInstructionToStepDo.removeAll () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_debuggerContext_appendInstructionToStepDo (defineExtensionSetter_debuggerContext_appendInstructionToStepDo,
                                                                    freeExtensionModifier_debuggerContext_appendInstructionToStepDo) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext deleteStepDoInstruction'
//
//--------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_debuggerContext_deleteStepDoInstruction> gExtensionModifierTable_debuggerContext_deleteStepDoInstruction ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteStepDoInstruction (const int32_t inClassIndex,
                                                   extensionSetterSignature_debuggerContext_deleteStepDoInstruction inModifier) {
  gExtensionModifierTable_debuggerContext_deleteStepDoInstruction.forceObjectAtIndex (inClassIndex, inModifier, nullptr) ;
}

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteStepDoInstruction (cPtr_debuggerContext * inObject,
                                                  const GALGAS_lbigint constin_numToDelete,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debuggerContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_debuggerContext_deleteStepDoInstruction f = nullptr ;
    if (classIndex < gExtensionModifierTable_debuggerContext_deleteStepDoInstruction.count ()) {
      f = gExtensionModifierTable_debuggerContext_deleteStepDoInstruction (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_debuggerContext_deleteStepDoInstruction.count ()) {
           f = gExtensionModifierTable_debuggerContext_deleteStepDoInstruction (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_debuggerContext_deleteStepDoInstruction.forceObjectAtIndex (classIndex, f, nullptr) ;
    }
    f (inObject, constin_numToDelete, inCompiler COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

static void extensionSetter_debuggerContext_deleteStepDoInstruction (cPtr_debuggerContext * inObject,
                                                                     const GALGAS_lbigint constinArgument_numToDelete,
                                                                     Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_debuggerContext * object = inObject ;
  macroValidSharedObject (object, cPtr_debuggerContext) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsInfOrEqual, constinArgument_numToDelete.readProperty_bigint ().objectCompare (GALGAS_uint::class_func_max (SOURCE_FILE ("gtl_debugger.galgas", 137)).getter_bigint (SOURCE_FILE ("gtl_debugger.galgas", 137)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_uint var_numToDeleteUInt_5233 = constinArgument_numToDelete.readProperty_bigint ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 138)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsStrictInf, var_numToDeleteUInt_5233.objectCompare (object->mProperty_doList.getter_count (SOURCE_FILE ("gtl_debugger.galgas", 139)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_gtlInstruction var_instruction_5367 ;
          {
          object->mProperty_doList.setter_removeAtIndex (var_instruction_5367, var_numToDeleteUInt_5233, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 140)) ;
          }
          inCompiler->printMessage (GALGAS_string ("Command: ")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 141)) ;
          inCompiler->printMessage (object->mProperty_instructionColor.add_operation (object->mProperty_instructionFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 142))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 142)) ;
          callExtensionMethod_display ((cPtr_gtlInstruction *) var_instruction_5367.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 143)) ;
          inCompiler->printMessage (object->mProperty_outputColor.add_operation (object->mProperty_outputFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 144))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 144)) ;
          inCompiler->printMessage (GALGAS_string (" deleted\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 145)) ;
        }
      }
      if (kBoolFalse == test_1) {
        inCompiler->printMessage (object->mProperty_warningColor.add_operation (object->mProperty_warningFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 147))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 147)) ;
        inCompiler->printMessage (GALGAS_string ("no do command at this index: ").add_operation (constinArgument_numToDelete.readProperty_bigint ().getter_string (SOURCE_FILE ("gtl_debugger.galgas", 148)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 148)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 148))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 148)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    inCompiler->printMessage (object->mProperty_warningColor.add_operation (object->mProperty_warningFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 151))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 151)) ;
    inCompiler->printMessage (GALGAS_string ("no do command at this index: ").add_operation (constinArgument_numToDelete.readProperty_bigint ().getter_string (SOURCE_FILE ("gtl_debugger.galgas", 152)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 152)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 152))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 152)) ;
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_debuggerContext_deleteStepDoInstruction (void) {
  enterExtensionSetter_deleteStepDoInstruction (kTypeDescriptor_GALGAS_debuggerContext.mSlotID,
                                                extensionSetter_debuggerContext_deleteStepDoInstruction) ;
}

//--------------------------------------------------------------------------------------------------

static void freeExtensionModifier_debuggerContext_deleteStepDoInstruction (void) {
  gExtensionModifierTable_debuggerContext_deleteStepDoInstruction.removeAll () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_debuggerContext_deleteStepDoInstruction (defineExtensionSetter_debuggerContext_deleteStepDoInstruction,
                                                                  freeExtensionModifier_debuggerContext_deleteStepDoInstruction) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext deleteAllStepDoInstructions'
//
//--------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_debuggerContext_deleteAllStepDoInstructions> gExtensionModifierTable_debuggerContext_deleteAllStepDoInstructions ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteAllStepDoInstructions (const int32_t inClassIndex,
                                                       extensionSetterSignature_debuggerContext_deleteAllStepDoInstructions inModifier) {
  gExtensionModifierTable_debuggerContext_deleteAllStepDoInstructions.forceObjectAtIndex (inClassIndex, inModifier, nullptr) ;
}

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteAllStepDoInstructions (cPtr_debuggerContext * inObject,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debuggerContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_debuggerContext_deleteAllStepDoInstructions f = nullptr ;
    if (classIndex < gExtensionModifierTable_debuggerContext_deleteAllStepDoInstructions.count ()) {
      f = gExtensionModifierTable_debuggerContext_deleteAllStepDoInstructions (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_debuggerContext_deleteAllStepDoInstructions.count ()) {
           f = gExtensionModifierTable_debuggerContext_deleteAllStepDoInstructions (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_debuggerContext_deleteAllStepDoInstructions.forceObjectAtIndex (classIndex, f, nullptr) ;
    }
    f (inObject, inCompiler COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

static void extensionSetter_debuggerContext_deleteAllStepDoInstructions (cPtr_debuggerContext * inObject,
                                                                         Compiler * /* inCompiler */
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_debuggerContext * object = inObject ;
  macroValidSharedObject (object, cPtr_debuggerContext) ;
  object->mProperty_doList = GALGAS_gtlInstructionList::class_func_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 159)) ;
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_debuggerContext_deleteAllStepDoInstructions (void) {
  enterExtensionSetter_deleteAllStepDoInstructions (kTypeDescriptor_GALGAS_debuggerContext.mSlotID,
                                                    extensionSetter_debuggerContext_deleteAllStepDoInstructions) ;
}

//--------------------------------------------------------------------------------------------------

static void freeExtensionModifier_debuggerContext_deleteAllStepDoInstructions (void) {
  gExtensionModifierTable_debuggerContext_deleteAllStepDoInstructions.removeAll () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_debuggerContext_deleteAllStepDoInstructions (defineExtensionSetter_debuggerContext_deleteAllStepDoInstructions,
                                                                      freeExtensionModifier_debuggerContext_deleteAllStepDoInstructions) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@debuggerContext listStepDoInstructions'
//
//--------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::method_listStepDoInstructions (Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, this->mProperty_doList.getter_count (SOURCE_FILE ("gtl_debugger.galgas", 165)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      inCompiler->printMessage (GALGAS_string ("Step do commands:\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 166)) ;
      cEnumerator_gtlInstructionList enumerator_6190 (this->mProperty_doList, kENUMERATION_UP) ;
      GALGAS_uint index_6185 ((uint32_t) 0) ;
      while (enumerator_6190.hasCurrentObject ()) {
        inCompiler->printMessage (index_6185.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 168)).getter_stringByLeftPadding (GALGAS_uint (uint32_t (4U)), GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_debugger.galgas", 168)).add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 168))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 168)) ;
        inCompiler->printMessage (this->mProperty_instructionColor.add_operation (this->mProperty_instructionFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 169))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 169)) ;
        callExtensionMethod_display ((cPtr_gtlInstruction *) enumerator_6190.current_instruction (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 170)) ;
        inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 171)) ;
        inCompiler->printMessage (this->mProperty_outputColor.add_operation (this->mProperty_outputFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 172))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 172)) ;
        enumerator_6190.gotoNextObject () ;
        index_6185.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 167)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    inCompiler->printMessage (GALGAS_string ("No step do commands\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 175)) ;
  }
}

//--------------------------------------------------------------------------------------------------

void callExtensionMethod_listStepDoInstructions (cPtr_debuggerContext * inObject,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debuggerContext) ;
    inObject->method_listStepDoInstructions  (inCompiler COMMA_THERE) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext setBreakpoint'
//
//--------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_debuggerContext_setBreakpoint> gExtensionModifierTable_debuggerContext_setBreakpoint ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_setBreakpoint (const int32_t inClassIndex,
                                         extensionSetterSignature_debuggerContext_setBreakpoint inModifier) {
  gExtensionModifierTable_debuggerContext_setBreakpoint.forceObjectAtIndex (inClassIndex, inModifier, nullptr) ;
}

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_setBreakpoint (cPtr_debuggerContext * inObject,
                                        const GALGAS_string constin_fileName,
                                        const GALGAS_uint constin_lineNum,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debuggerContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_debuggerContext_setBreakpoint f = nullptr ;
    if (classIndex < gExtensionModifierTable_debuggerContext_setBreakpoint.count ()) {
      f = gExtensionModifierTable_debuggerContext_setBreakpoint (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_debuggerContext_setBreakpoint.count ()) {
           f = gExtensionModifierTable_debuggerContext_setBreakpoint (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_debuggerContext_setBreakpoint.forceObjectAtIndex (classIndex, f, nullptr) ;
    }
    f (inObject, constin_fileName, constin_lineNum, inCompiler COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

static void extensionSetter_debuggerContext_setBreakpoint (cPtr_debuggerContext * inObject,
                                                           const GALGAS_string constinArgument_fileName,
                                                           const GALGAS_uint constinArgument_lineNum,
                                                           Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_debuggerContext * object = inObject ;
  macroValidSharedObject (object, cPtr_debuggerContext) ;
  GALGAS_string var_signature_6666 = constinArgument_fileName.add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 184)).add_operation (constinArgument_lineNum.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 184)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 184)).getter_md_35_ (SOURCE_FILE ("gtl_debugger.galgas", 184)) ;
  GALGAS_bool var_notThere_6717 = GALGAS_bool (true) ;
  cEnumerator_gtlBreakpointList enumerator_6740 (object->mProperty_breakpoints, kENUMERATION_UP) ;
  while (enumerator_6740.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (kIsEqual, enumerator_6740.current_breakpoint (HERE).readProperty_signature ().objectCompare (var_signature_6666)).boolEnum () ;
      if (kBoolTrue == test_0) {
        var_notThere_6717 = GALGAS_bool (false) ;
      }
    }
    enumerator_6740.gotoNextObject () ;
  }
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = var_notThere_6717.boolEnum () ;
    if (kBoolTrue == test_1) {
      object->mProperty_breakpoints.addAssign_operation (GALGAS_gtlBreakpoint::class_func_new (constinArgument_fileName, constinArgument_lineNum, var_signature_6666  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 192))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 192)) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_debuggerContext_setBreakpoint (void) {
  enterExtensionSetter_setBreakpoint (kTypeDescriptor_GALGAS_debuggerContext.mSlotID,
                                      extensionSetter_debuggerContext_setBreakpoint) ;
}

//--------------------------------------------------------------------------------------------------

static void freeExtensionModifier_debuggerContext_setBreakpoint (void) {
  gExtensionModifierTable_debuggerContext_setBreakpoint.removeAll () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_debuggerContext_setBreakpoint (defineExtensionSetter_debuggerContext_setBreakpoint,
                                                        freeExtensionModifier_debuggerContext_setBreakpoint) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@debuggerContext listBreakpoints'
//
//--------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::method_listBreakpoints (Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, this->mProperty_breakpoints.getter_count (SOURCE_FILE ("gtl_debugger.galgas", 199)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      inCompiler->printMessage (GALGAS_string ("Breakpoints:\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 200)) ;
      cEnumerator_gtlBreakpointList enumerator_7140 (this->mProperty_breakpoints, kENUMERATION_UP) ;
      GALGAS_uint index_7135 ((uint32_t) 0) ;
      while (enumerator_7140.hasCurrentObject ()) {
        inCompiler->printMessage (index_7135.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 202)).getter_stringByLeftPadding (GALGAS_uint (uint32_t (4U)), GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_debugger.galgas", 202)).add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 202))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 202)) ;
        inCompiler->printMessage (this->mProperty_instructionColor.add_operation (this->mProperty_instructionFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 203))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 203)) ;
        inCompiler->printMessage (enumerator_7140.current_breakpoint (HERE).readProperty_fileName ().add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 204)).add_operation (enumerator_7140.current_breakpoint (HERE).readProperty_lineNum ().getter_string (SOURCE_FILE ("gtl_debugger.galgas", 204)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 204))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 204)) ;
        inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 205)) ;
        inCompiler->printMessage (this->mProperty_outputColor.add_operation (this->mProperty_outputFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 206))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 206)) ;
        enumerator_7140.gotoNextObject () ;
        index_7135.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 201)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    inCompiler->printMessage (GALGAS_string ("No breakpoint\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 209)) ;
  }
}

//--------------------------------------------------------------------------------------------------

void callExtensionMethod_listBreakpoints (cPtr_debuggerContext * inObject,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debuggerContext) ;
    inObject->method_listBreakpoints  (inCompiler COMMA_THERE) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext deleteBreakpoint'
//
//--------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_debuggerContext_deleteBreakpoint> gExtensionModifierTable_debuggerContext_deleteBreakpoint ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteBreakpoint (const int32_t inClassIndex,
                                            extensionSetterSignature_debuggerContext_deleteBreakpoint inModifier) {
  gExtensionModifierTable_debuggerContext_deleteBreakpoint.forceObjectAtIndex (inClassIndex, inModifier, nullptr) ;
}

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteBreakpoint (cPtr_debuggerContext * inObject,
                                           const GALGAS_lbigint constin_numToDelete,
                                           Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debuggerContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_debuggerContext_deleteBreakpoint f = nullptr ;
    if (classIndex < gExtensionModifierTable_debuggerContext_deleteBreakpoint.count ()) {
      f = gExtensionModifierTable_debuggerContext_deleteBreakpoint (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_debuggerContext_deleteBreakpoint.count ()) {
           f = gExtensionModifierTable_debuggerContext_deleteBreakpoint (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_debuggerContext_deleteBreakpoint.forceObjectAtIndex (classIndex, f, nullptr) ;
    }
    f (inObject, constin_numToDelete, inCompiler COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

static void extensionSetter_debuggerContext_deleteBreakpoint (cPtr_debuggerContext * inObject,
                                                              const GALGAS_lbigint constinArgument_numToDelete,
                                                              Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_debuggerContext * object = inObject ;
  macroValidSharedObject (object, cPtr_debuggerContext) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsInfOrEqual, constinArgument_numToDelete.readProperty_bigint ().objectCompare (GALGAS_uint::class_func_max (SOURCE_FILE ("gtl_debugger.galgas", 217)).getter_bigint (SOURCE_FILE ("gtl_debugger.galgas", 217)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_uint var_numToDeleteUInt_7690 = constinArgument_numToDelete.readProperty_bigint ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 218)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsStrictInf, var_numToDeleteUInt_7690.objectCompare (object->mProperty_breakpoints.getter_count (SOURCE_FILE ("gtl_debugger.galgas", 219)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_gtlBreakpoint var_bp_7833 ;
          {
          object->mProperty_breakpoints.setter_removeAtIndex (var_bp_7833, var_numToDeleteUInt_7690, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 220)) ;
          }
          inCompiler->printMessage (GALGAS_string ("Breakpoint: ")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 221)) ;
          inCompiler->printMessage (object->mProperty_instructionColor.add_operation (object->mProperty_instructionFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 222))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 222)) ;
          inCompiler->printMessage (var_bp_7833.readProperty_fileName ().add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 223)).add_operation (var_bp_7833.readProperty_lineNum ().getter_string (SOURCE_FILE ("gtl_debugger.galgas", 223)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 223))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 223)) ;
          inCompiler->printMessage (object->mProperty_outputColor.add_operation (object->mProperty_outputFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 224))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 224)) ;
          inCompiler->printMessage (GALGAS_string (" deleted\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 225)) ;
        }
      }
      if (kBoolFalse == test_1) {
        inCompiler->printMessage (object->mProperty_warningColor.add_operation (object->mProperty_warningFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 227))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 227)) ;
        inCompiler->printMessage (GALGAS_string ("no breakpoint at this index: ").add_operation (constinArgument_numToDelete.readProperty_bigint ().getter_string (SOURCE_FILE ("gtl_debugger.galgas", 228)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 228)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 228))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 228)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    inCompiler->printMessage (object->mProperty_warningColor.add_operation (object->mProperty_warningFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 231))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 231)) ;
    inCompiler->printMessage (GALGAS_string ("no breakpoint at this index: ").add_operation (constinArgument_numToDelete.readProperty_bigint ().getter_string (SOURCE_FILE ("gtl_debugger.galgas", 232)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 232)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 232))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 232)) ;
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_debuggerContext_deleteBreakpoint (void) {
  enterExtensionSetter_deleteBreakpoint (kTypeDescriptor_GALGAS_debuggerContext.mSlotID,
                                         extensionSetter_debuggerContext_deleteBreakpoint) ;
}

//--------------------------------------------------------------------------------------------------

static void freeExtensionModifier_debuggerContext_deleteBreakpoint (void) {
  gExtensionModifierTable_debuggerContext_deleteBreakpoint.removeAll () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_debuggerContext_deleteBreakpoint (defineExtensionSetter_debuggerContext_deleteBreakpoint,
                                                           freeExtensionModifier_debuggerContext_deleteBreakpoint) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext deleteAllBreakpoints'
//
//--------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_debuggerContext_deleteAllBreakpoints> gExtensionModifierTable_debuggerContext_deleteAllBreakpoints ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteAllBreakpoints (const int32_t inClassIndex,
                                                extensionSetterSignature_debuggerContext_deleteAllBreakpoints inModifier) {
  gExtensionModifierTable_debuggerContext_deleteAllBreakpoints.forceObjectAtIndex (inClassIndex, inModifier, nullptr) ;
}

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteAllBreakpoints (cPtr_debuggerContext * inObject,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debuggerContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_debuggerContext_deleteAllBreakpoints f = nullptr ;
    if (classIndex < gExtensionModifierTable_debuggerContext_deleteAllBreakpoints.count ()) {
      f = gExtensionModifierTable_debuggerContext_deleteAllBreakpoints (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_debuggerContext_deleteAllBreakpoints.count ()) {
           f = gExtensionModifierTable_debuggerContext_deleteAllBreakpoints (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_debuggerContext_deleteAllBreakpoints.forceObjectAtIndex (classIndex, f, nullptr) ;
    }
    f (inObject, inCompiler COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

static void extensionSetter_debuggerContext_deleteAllBreakpoints (cPtr_debuggerContext * inObject,
                                                                  Compiler * /* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_debuggerContext * object = inObject ;
  macroValidSharedObject (object, cPtr_debuggerContext) ;
  object->mProperty_breakpoints = GALGAS_gtlBreakpointList::class_func_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 239)) ;
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_debuggerContext_deleteAllBreakpoints (void) {
  enterExtensionSetter_deleteAllBreakpoints (kTypeDescriptor_GALGAS_debuggerContext.mSlotID,
                                             extensionSetter_debuggerContext_deleteAllBreakpoints) ;
}

//--------------------------------------------------------------------------------------------------

static void freeExtensionModifier_debuggerContext_deleteAllBreakpoints (void) {
  gExtensionModifierTable_debuggerContext_deleteAllBreakpoints.removeAll () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_debuggerContext_deleteAllBreakpoints (defineExtensionSetter_debuggerContext_deleteAllBreakpoints,
                                                               freeExtensionModifier_debuggerContext_deleteAllBreakpoints) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext setWatchpoint'
//
//--------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_debuggerContext_setWatchpoint> gExtensionModifierTable_debuggerContext_setWatchpoint ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_setWatchpoint (const int32_t inClassIndex,
                                         extensionSetterSignature_debuggerContext_setWatchpoint inModifier) {
  gExtensionModifierTable_debuggerContext_setWatchpoint.forceObjectAtIndex (inClassIndex, inModifier, nullptr) ;
}

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_setWatchpoint (cPtr_debuggerContext * inObject,
                                        const GALGAS_gtlExpression constin_watchExpression,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debuggerContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_debuggerContext_setWatchpoint f = nullptr ;
    if (classIndex < gExtensionModifierTable_debuggerContext_setWatchpoint.count ()) {
      f = gExtensionModifierTable_debuggerContext_setWatchpoint (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_debuggerContext_setWatchpoint.count ()) {
           f = gExtensionModifierTable_debuggerContext_setWatchpoint (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_debuggerContext_setWatchpoint.forceObjectAtIndex (classIndex, f, nullptr) ;
    }
    f (inObject, constin_watchExpression, inCompiler COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

static void extensionSetter_debuggerContext_setWatchpoint (cPtr_debuggerContext * inObject,
                                                           const GALGAS_gtlExpression constinArgument_watchExpression,
                                                           Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_debuggerContext * object = inObject ;
  macroValidSharedObject (object, cPtr_debuggerContext) ;
  object->mProperty_watchpoints.addAssign_operation (constinArgument_watchExpression  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 246)) ;
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_debuggerContext_setWatchpoint (void) {
  enterExtensionSetter_setWatchpoint (kTypeDescriptor_GALGAS_debuggerContext.mSlotID,
                                      extensionSetter_debuggerContext_setWatchpoint) ;
}

//--------------------------------------------------------------------------------------------------

static void freeExtensionModifier_debuggerContext_setWatchpoint (void) {
  gExtensionModifierTable_debuggerContext_setWatchpoint.removeAll () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_debuggerContext_setWatchpoint (defineExtensionSetter_debuggerContext_setWatchpoint,
                                                        freeExtensionModifier_debuggerContext_setWatchpoint) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@debuggerContext listWatchpoints'
//
//--------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::method_listWatchpoints (Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, this->mProperty_watchpoints.getter_count (SOURCE_FILE ("gtl_debugger.galgas", 252)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      inCompiler->printMessage (GALGAS_string ("Watchpoints:\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 253)) ;
      cEnumerator_gtlExpressionList enumerator_8857 (this->mProperty_watchpoints, kENUMERATION_UP) ;
      GALGAS_uint index_8852 ((uint32_t) 0) ;
      while (enumerator_8857.hasCurrentObject ()) {
        inCompiler->printMessage (index_8852.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 255)).getter_stringByLeftPadding (GALGAS_uint (uint32_t (4U)), GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_debugger.galgas", 255)).add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 255))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 255)) ;
        inCompiler->printMessage (this->mProperty_instructionColor.add_operation (this->mProperty_instructionFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 256))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 256)) ;
        inCompiler->printMessage (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) enumerator_8857.current_expression (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 257))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 257)) ;
        inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 258)) ;
        inCompiler->printMessage (this->mProperty_outputColor.add_operation (this->mProperty_outputFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 259))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 259)) ;
        enumerator_8857.gotoNextObject () ;
        index_8852.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 254)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    inCompiler->printMessage (GALGAS_string ("No Watchpoint\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 262)) ;
  }
}

//--------------------------------------------------------------------------------------------------

void callExtensionMethod_listWatchpoints (cPtr_debuggerContext * inObject,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debuggerContext) ;
    inObject->method_listWatchpoints  (inCompiler COMMA_THERE) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext deleteWatchpoint'
//
//--------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_debuggerContext_deleteWatchpoint> gExtensionModifierTable_debuggerContext_deleteWatchpoint ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteWatchpoint (const int32_t inClassIndex,
                                            extensionSetterSignature_debuggerContext_deleteWatchpoint inModifier) {
  gExtensionModifierTable_debuggerContext_deleteWatchpoint.forceObjectAtIndex (inClassIndex, inModifier, nullptr) ;
}

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteWatchpoint (cPtr_debuggerContext * inObject,
                                           const GALGAS_lbigint constin_numToDelete,
                                           Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debuggerContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_debuggerContext_deleteWatchpoint f = nullptr ;
    if (classIndex < gExtensionModifierTable_debuggerContext_deleteWatchpoint.count ()) {
      f = gExtensionModifierTable_debuggerContext_deleteWatchpoint (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_debuggerContext_deleteWatchpoint.count ()) {
           f = gExtensionModifierTable_debuggerContext_deleteWatchpoint (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_debuggerContext_deleteWatchpoint.forceObjectAtIndex (classIndex, f, nullptr) ;
    }
    f (inObject, constin_numToDelete, inCompiler COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

static void extensionSetter_debuggerContext_deleteWatchpoint (cPtr_debuggerContext * inObject,
                                                              const GALGAS_lbigint constinArgument_numToDelete,
                                                              Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_debuggerContext * object = inObject ;
  macroValidSharedObject (object, cPtr_debuggerContext) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsInfOrEqual, constinArgument_numToDelete.readProperty_bigint ().objectCompare (GALGAS_uint::class_func_max (SOURCE_FILE ("gtl_debugger.galgas", 270)).getter_bigint (SOURCE_FILE ("gtl_debugger.galgas", 270)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_uint var_numToDeleteUInt_9374 = constinArgument_numToDelete.readProperty_bigint ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 271)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsStrictInf, var_numToDeleteUInt_9374.objectCompare (object->mProperty_watchpoints.getter_count (SOURCE_FILE ("gtl_debugger.galgas", 272)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_gtlExpression var_wp_9517 ;
          {
          object->mProperty_watchpoints.setter_removeAtIndex (var_wp_9517, var_numToDeleteUInt_9374, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 273)) ;
          }
          inCompiler->printMessage (GALGAS_string ("Watchpoint: ")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 274)) ;
          inCompiler->printMessage (object->mProperty_instructionColor.add_operation (object->mProperty_instructionFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 275))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 275)) ;
          inCompiler->printMessage (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) var_wp_9517.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 276))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 276)) ;
          inCompiler->printMessage (object->mProperty_outputColor.add_operation (object->mProperty_outputFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 277))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 277)) ;
          inCompiler->printMessage (GALGAS_string (" deleted\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 278)) ;
        }
      }
      if (kBoolFalse == test_1) {
        inCompiler->printMessage (object->mProperty_warningColor.add_operation (object->mProperty_warningFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 280))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 280)) ;
        inCompiler->printMessage (GALGAS_string ("no watchpoint at this index: ").add_operation (constinArgument_numToDelete.readProperty_bigint ().getter_string (SOURCE_FILE ("gtl_debugger.galgas", 281)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 281)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 281))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 281)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    inCompiler->printMessage (object->mProperty_warningColor.add_operation (object->mProperty_warningFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 284))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 284)) ;
    inCompiler->printMessage (GALGAS_string ("no watchpoint at this index: ").add_operation (constinArgument_numToDelete.readProperty_bigint ().getter_string (SOURCE_FILE ("gtl_debugger.galgas", 285)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 285)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 285))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 285)) ;
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_debuggerContext_deleteWatchpoint (void) {
  enterExtensionSetter_deleteWatchpoint (kTypeDescriptor_GALGAS_debuggerContext.mSlotID,
                                         extensionSetter_debuggerContext_deleteWatchpoint) ;
}

//--------------------------------------------------------------------------------------------------

static void freeExtensionModifier_debuggerContext_deleteWatchpoint (void) {
  gExtensionModifierTable_debuggerContext_deleteWatchpoint.removeAll () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_debuggerContext_deleteWatchpoint (defineExtensionSetter_debuggerContext_deleteWatchpoint,
                                                           freeExtensionModifier_debuggerContext_deleteWatchpoint) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext deleteAllWatchpoints'
//
//--------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_debuggerContext_deleteAllWatchpoints> gExtensionModifierTable_debuggerContext_deleteAllWatchpoints ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteAllWatchpoints (const int32_t inClassIndex,
                                                extensionSetterSignature_debuggerContext_deleteAllWatchpoints inModifier) {
  gExtensionModifierTable_debuggerContext_deleteAllWatchpoints.forceObjectAtIndex (inClassIndex, inModifier, nullptr) ;
}

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteAllWatchpoints (cPtr_debuggerContext * inObject,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debuggerContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_debuggerContext_deleteAllWatchpoints f = nullptr ;
    if (classIndex < gExtensionModifierTable_debuggerContext_deleteAllWatchpoints.count ()) {
      f = gExtensionModifierTable_debuggerContext_deleteAllWatchpoints (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_debuggerContext_deleteAllWatchpoints.count ()) {
           f = gExtensionModifierTable_debuggerContext_deleteAllWatchpoints (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_debuggerContext_deleteAllWatchpoints.forceObjectAtIndex (classIndex, f, nullptr) ;
    }
    f (inObject, inCompiler COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

static void extensionSetter_debuggerContext_deleteAllWatchpoints (cPtr_debuggerContext * inObject,
                                                                  Compiler * /* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_debuggerContext * object = inObject ;
  macroValidSharedObject (object, cPtr_debuggerContext) ;
  object->mProperty_watchpoints = GALGAS_gtlExpressionList::class_func_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 292)) ;
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_debuggerContext_deleteAllWatchpoints (void) {
  enterExtensionSetter_deleteAllWatchpoints (kTypeDescriptor_GALGAS_debuggerContext.mSlotID,
                                             extensionSetter_debuggerContext_deleteAllWatchpoints) ;
}

//--------------------------------------------------------------------------------------------------

static void freeExtensionModifier_debuggerContext_deleteAllWatchpoints (void) {
  gExtensionModifierTable_debuggerContext_deleteAllWatchpoints.removeAll () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_debuggerContext_deleteAllWatchpoints (defineExtensionSetter_debuggerContext_deleteAllWatchpoints,
                                                               freeExtensionModifier_debuggerContext_deleteAllWatchpoints) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@debuggerContext breakOn'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_debuggerContext::getter_breakOn (const GALGAS_gtlInstruction constinArgument_instruction,
                                                  Compiler */* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_breakOn ; // Returned variable
  result_breakOn = GALGAS_bool (false) ;
  cEnumerator_gtlBreakpointList enumerator_10334 (this->mProperty_breakpoints, kENUMERATION_UP) ;
  while (enumerator_10334.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (kIsEqual, constinArgument_instruction.readProperty_signature ().objectCompare (enumerator_10334.current_breakpoint (HERE).readProperty_signature ())).boolEnum () ;
      if (kBoolTrue == test_0) {
        result_breakOn = GALGAS_bool (true) ;
      }
    }
    enumerator_10334.gotoNextObject () ;
  }
//---
  return result_breakOn ;
}



//--------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_breakOn (const cPtr_debuggerContext * inObject,
                                         const GALGAS_gtlInstruction in_instruction,
                                         Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_breakOn (in_instruction, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@debuggerContext watchOn'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_debuggerContext::getter_watchOn (const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_gtlData constinArgument_vars,
                                                  const GALGAS_library constinArgument_lib,
                                                  Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_watchOn ; // Returned variable
  result_watchOn = GALGAS_bool (false) ;
  cEnumerator_gtlExpressionList enumerator_10679 (this->mProperty_watchpoints, kENUMERATION_UP) ;
  while (enumerator_10679.hasCurrentObject ()) {
    GALGAS_gtlData var_watchResult_10718 = callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_10679.current_expression (HERE).ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 317)) ;
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (var_watchResult_10718.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_gtlBool temp_1 ;
        if (var_watchResult_10718.isValid ()) {
          if (nullptr != dynamic_cast <const cPtr_gtlBool *> (var_watchResult_10718.ptr ())) {
            temp_1 = (cPtr_gtlBool *) var_watchResult_10718.ptr () ;
          }else{
            inCompiler->castError ("gtlBool", var_watchResult_10718.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_debugger.galgas", 319)) ;
          }
        }
        GALGAS_bool var_matchWatch_10817 = temp_1.readProperty_value () ;
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = var_matchWatch_10817.boolEnum () ;
          if (kBoolTrue == test_2) {
            inCompiler->printMessage (this->mProperty_outputColor.add_operation (this->mProperty_outputFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 321))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 321)) ;
            inCompiler->printMessage (GALGAS_string ("match ")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 322)) ;
            inCompiler->printMessage (this->mProperty_instructionColor.add_operation (this->mProperty_instructionFace, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 323))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 323)) ;
            inCompiler->printMessage (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) enumerator_10679.current_expression (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 324))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 324)) ;
            inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 325)) ;
            inCompiler->printMessage (function_endc (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 326))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 326)) ;
            result_watchOn = GALGAS_bool (true) ;
          }
        }
      }
    }
    enumerator_10679.gotoNextObject () ;
  }
//---
  return result_watchOn ;
}



//--------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_watchOn (const cPtr_debuggerContext * inObject,
                                         const GALGAS_gtlContext in_context,
                                         const GALGAS_gtlData in_vars,
                                         const GALGAS_library in_lib,
                                         Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_watchOn (in_context, in_vars, in_lib, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//Extension method '@debuggerContext hereWeAre'
//
//--------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::method_hereWeAre (const GALGAS_uint constinArgument_window,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint var_indentation_11285 = GALGAS_uint (uint32_t (0U)) ;
  cEnumerator_gtlInstructionListContextStack enumerator_11319 (this->mProperty_contextStack.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 338)), kENUMERATION_UP) ;
  while (enumerator_11319.hasCurrentObject ()) {
    inCompiler->printMessage (GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), var_indentation_11285  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 339))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 339)) ;
    const GALGAS_debuggerContext temp_0 = this ;
    callExtensionMethod_displayWithLocation ((cPtr_gtlInstruction *) enumerator_11319.current_instructionList (HERE).getter_instructionAtIndex (enumerator_11319.current_nextInstructionIndex (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 340)).ptr (), temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 340)) ;
    var_indentation_11285 = var_indentation_11285.add_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 341)) ;
    enumerator_11319.gotoNextObject () ;
  }
  GALGAS_string var_identationString_11573 = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), var_indentation_11285  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 344)) ;
  GALGAS_uint var_startIndex_11657 ;
  GALGAS_uint var_displayLength_11680 ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsSupOrEqual, this->mProperty_nextInstructionIndex.objectCompare (constinArgument_window)).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_startIndex_11657 = this->mProperty_nextInstructionIndex.substract_operation (constinArgument_window, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 349)) ;
    }
  }
  if (kBoolFalse == test_1) {
    var_startIndex_11657 = GALGAS_uint (uint32_t (0U)) ;
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsStrictInf, var_startIndex_11657.add_operation (constinArgument_window.multiply_operation (GALGAS_uint (uint32_t (2U)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 353)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 353)).objectCompare (this->mProperty_instructionList.getter_count (SOURCE_FILE ("gtl_debugger.galgas", 353)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      var_displayLength_11680 = GALGAS_uint (uint32_t (2U)).multiply_operation (constinArgument_window, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 354)) ;
    }
  }
  if (kBoolFalse == test_2) {
    var_displayLength_11680 = this->mProperty_instructionList.getter_count (SOURCE_FILE ("gtl_debugger.galgas", 356)).substract_operation (var_startIndex_11657, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 356)) ;
  }
  inCompiler->printMessage (function_endc (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 358))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 358)) ;
  cEnumerator_gtlInstructionList enumerator_12004 (this->mProperty_instructionList.getter_subListWithRange (GALGAS_range::class_func_new (var_startIndex_11657, var_displayLength_11680, inCompiler  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 360)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 360)), kENUMERATION_UP) ;
  GALGAS_uint index_11999 ((uint32_t) 0) ;
  while (enumerator_12004.hasCurrentObject ()) {
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = GALGAS_bool (kIsEqual, index_11999.add_operation (var_startIndex_11657, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 363)).objectCompare (this->mProperty_nextInstructionIndex)).boolEnum () ;
      if (kBoolTrue == test_3) {
        inCompiler->printMessage (function_red (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 364)).add_operation (function_bold (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 364)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 364))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 364)) ;
        inCompiler->printMessage (var_identationString_11573.add_operation (GALGAS_string (">>> "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 365))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 365)) ;
        inCompiler->printMessage (function_endc (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 366))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 366)) ;
      }
    }
    if (kBoolFalse == test_3) {
      inCompiler->printMessage (var_identationString_11573.add_operation (GALGAS_string ("    "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 368))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 368)) ;
    }
    const GALGAS_debuggerContext temp_4 = this ;
    callExtensionMethod_displayWithLocation ((cPtr_gtlInstruction *) enumerator_12004.current_instruction (HERE).ptr (), temp_4, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 370)) ;
    enumerator_12004.gotoNextObject () ;
    index_11999.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 359)) ;
  }
}

//--------------------------------------------------------------------------------------------------

void callExtensionMethod_hereWeAre (cPtr_debuggerContext * inObject,
                                    const GALGAS_uint constin_window,
                                    Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debuggerContext) ;
    inObject->method_hereWeAre  (constin_window, inCompiler COMMA_THERE) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext pushInstructionList'
//
//--------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_debuggerContext_pushInstructionList> gExtensionModifierTable_debuggerContext_pushInstructionList ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_pushInstructionList (const int32_t inClassIndex,
                                               extensionSetterSignature_debuggerContext_pushInstructionList inModifier) {
  gExtensionModifierTable_debuggerContext_pushInstructionList.forceObjectAtIndex (inClassIndex, inModifier, nullptr) ;
}

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_pushInstructionList (cPtr_debuggerContext * inObject,
                                              const GALGAS_gtlInstructionList constin_instructions,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debuggerContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_debuggerContext_pushInstructionList f = nullptr ;
    if (classIndex < gExtensionModifierTable_debuggerContext_pushInstructionList.count ()) {
      f = gExtensionModifierTable_debuggerContext_pushInstructionList (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_debuggerContext_pushInstructionList.count ()) {
           f = gExtensionModifierTable_debuggerContext_pushInstructionList (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_debuggerContext_pushInstructionList.forceObjectAtIndex (classIndex, f, nullptr) ;
    }
    f (inObject, constin_instructions, inCompiler COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

static void extensionSetter_debuggerContext_pushInstructionList (cPtr_debuggerContext * inObject,
                                                                 const GALGAS_gtlInstructionList constinArgument_instructions,
                                                                 Compiler * /* inCompiler */
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_debuggerContext * object = inObject ;
  macroValidSharedObject (object, cPtr_debuggerContext) ;
  object->mProperty_contextStack.addAssign_operation (object->mProperty_nextInstructionIndex, object->mProperty_instructionList  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 379)) ;
  object->mProperty_nextInstructionIndex = GALGAS_uint (uint32_t (0U)) ;
  object->mProperty_instructionList = constinArgument_instructions ;
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_debuggerContext_pushInstructionList (void) {
  enterExtensionSetter_pushInstructionList (kTypeDescriptor_GALGAS_debuggerContext.mSlotID,
                                            extensionSetter_debuggerContext_pushInstructionList) ;
}

//--------------------------------------------------------------------------------------------------

static void freeExtensionModifier_debuggerContext_pushInstructionList (void) {
  gExtensionModifierTable_debuggerContext_pushInstructionList.removeAll () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_debuggerContext_pushInstructionList (defineExtensionSetter_debuggerContext_pushInstructionList,
                                                              freeExtensionModifier_debuggerContext_pushInstructionList) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext popInstructionList'
//
//--------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_debuggerContext_popInstructionList> gExtensionModifierTable_debuggerContext_popInstructionList ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_popInstructionList (const int32_t inClassIndex,
                                              extensionSetterSignature_debuggerContext_popInstructionList inModifier) {
  gExtensionModifierTable_debuggerContext_popInstructionList.forceObjectAtIndex (inClassIndex, inModifier, nullptr) ;
}

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_popInstructionList (cPtr_debuggerContext * inObject,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debuggerContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_debuggerContext_popInstructionList f = nullptr ;
    if (classIndex < gExtensionModifierTable_debuggerContext_popInstructionList.count ()) {
      f = gExtensionModifierTable_debuggerContext_popInstructionList (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_debuggerContext_popInstructionList.count ()) {
           f = gExtensionModifierTable_debuggerContext_popInstructionList (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_debuggerContext_popInstructionList.forceObjectAtIndex (classIndex, f, nullptr) ;
    }
    f (inObject, inCompiler COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

static void extensionSetter_debuggerContext_popInstructionList (cPtr_debuggerContext * inObject,
                                                                Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_debuggerContext * object = inObject ;
  macroValidSharedObject (object, cPtr_debuggerContext) ;
  {
  object->mProperty_contextStack.setter_popLast (object->mProperty_nextInstructionIndex, object->mProperty_instructionList, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 386)) ;
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_debuggerContext_popInstructionList (void) {
  enterExtensionSetter_popInstructionList (kTypeDescriptor_GALGAS_debuggerContext.mSlotID,
                                           extensionSetter_debuggerContext_popInstructionList) ;
}

//--------------------------------------------------------------------------------------------------

static void freeExtensionModifier_debuggerContext_popInstructionList (void) {
  gExtensionModifierTable_debuggerContext_popInstructionList.removeAll () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_debuggerContext_popInstructionList (defineExtensionSetter_debuggerContext_popInstructionList,
                                                             freeExtensionModifier_debuggerContext_popInstructionList) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext getCommand'
//
//--------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_debuggerContext_getCommand> gExtensionModifierTable_debuggerContext_getCommand ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_getCommand (const int32_t inClassIndex,
                                      extensionSetterSignature_debuggerContext_getCommand inModifier) {
  gExtensionModifierTable_debuggerContext_getCommand.forceObjectAtIndex (inClassIndex, inModifier, nullptr) ;
}

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_getCommand (cPtr_debuggerContext * inObject,
                                     GALGAS_string & out_command,
                                     Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
//--- Drop output arguments
  out_command.drop () ;
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_debuggerContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_debuggerContext_getCommand f = nullptr ;
    if (classIndex < gExtensionModifierTable_debuggerContext_getCommand.count ()) {
      f = gExtensionModifierTable_debuggerContext_getCommand (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_debuggerContext_getCommand.count ()) {
           f = gExtensionModifierTable_debuggerContext_getCommand (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_debuggerContext_getCommand.forceObjectAtIndex (classIndex, f, nullptr) ;
    }
    f (inObject, out_command, inCompiler COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

static void extensionSetter_debuggerContext_getCommand (cPtr_debuggerContext * inObject,
                                                        GALGAS_string & outArgument_command,
                                                        Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_debuggerContext * object = inObject ;
  macroValidSharedObject (object, cPtr_debuggerContext) ;
  {
  object->mProperty_commandInput.insulate (HERE) ;
  cPtr_debugCommandInput * ptr_12915 = (cPtr_debugCommandInput *) object->mProperty_commandInput.ptr () ;
  callExtensionSetter_getCommand ((cPtr_debugCommandInput *) ptr_12915, outArgument_command, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 393)) ;
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_debuggerContext_getCommand (void) {
  enterExtensionSetter_getCommand (kTypeDescriptor_GALGAS_debuggerContext.mSlotID,
                                   extensionSetter_debuggerContext_getCommand) ;
}

//--------------------------------------------------------------------------------------------------

static void freeExtensionModifier_debuggerContext_getCommand (void) {
  gExtensionModifierTable_debuggerContext_getCommand.removeAll () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_debuggerContext_getCommand (defineExtensionSetter_debuggerContext_getCommand,
                                                     freeExtensionModifier_debuggerContext_getCommand) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlExpression stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string callExtensionGetter_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (nullptr != inObject) {
    result = inObject->getter_stringRepresentation (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string callExtensionGetter_stringRepresentation (const cPtr_gtlData * inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (nullptr != inObject) {
    result = inObject->getter_stringRepresentation (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//Extension Getter '@lsint stringRepresentation'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_stringRepresentation (const GALGAS_lsint & inObject,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_lsint temp_0 = inObject ;
  GALGAS_string temp_1 ;
  const enumGalgasBool test_2 = GALGAS_bool (kIsStrictInf, GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1120)).objectCompare (temp_0.readProperty_sint ().getter_bigint (SOURCE_FILE ("gtl_debugger.galgas", 1120)))).boolEnum () ;
  if (kBoolTrue == test_2) {
    temp_1 = GALGAS_string ("<") ;
  }else if (kBoolFalse == test_2) {
    temp_1 = GALGAS_string (">") ;
  }
  result_result = temp_1 ;
//---
  return result_result ;
}




//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlDoNotInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlDoNotInstruction * p = (const cPtr_gtlDoNotInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlDoNotInstruction) ;
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

//--------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlDoNotInstruction::objectCompare (const GALGAS_gtlDoNotInstruction & inOperand) const {
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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlDoNotInstruction::GALGAS_gtlDoNotInstruction (void) :
GALGAS_gtlInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlDoNotInstruction::GALGAS_gtlDoNotInstruction (const cPtr_gtlDoNotInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlDoNotInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlDoNotInstruction GALGAS_gtlDoNotInstruction::class_func_new (const GALGAS_location & inAttribute_where,
                                                                       const GALGAS_string & inAttribute_signature,
                                                                       const GALGAS_lbigint & inAttribute_numToDelete
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_gtlDoNotInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_numToDelete.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlDoNotInstruction (inAttribute_where, inAttribute_signature, inAttribute_numToDelete COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lbigint GALGAS_gtlDoNotInstruction::readProperty_numToDelete (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lbigint () ;
  }else{
    const cPtr_gtlDoNotInstruction * p = (const cPtr_gtlDoNotInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlDoNotInstruction) ;
    return p->mProperty_numToDelete ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lbigint cPtr_gtlDoNotInstruction::getter_numToDelete (UNUSED_LOCATION_ARGS) const {
  return mProperty_numToDelete ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlDoNotInstruction::setter_setNumToDelete (GALGAS_lbigint inValue
                                                        COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlDoNotInstruction * p = (cPtr_gtlDoNotInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlDoNotInstruction) ;
    p->mProperty_numToDelete = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlDoNotInstruction::setter_setNumToDelete (GALGAS_lbigint inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_numToDelete = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlDoNotInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlDoNotInstruction::cPtr_gtlDoNotInstruction (const GALGAS_location & in_where,
                                                    const GALGAS_string & in_signature,
                                                    const GALGAS_lbigint & in_numToDelete
                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_numToDelete (in_numToDelete) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlDoNotInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDoNotInstruction ;
}

void cPtr_gtlDoNotInstruction::description (String & ioString,
                                            const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlDoNotInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_numToDelete.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlDoNotInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlDoNotInstruction (mProperty_where, mProperty_signature, mProperty_numToDelete COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlDoNotInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlDoNotInstruction ("gtlDoNotInstruction",
                                                                           & kTypeDescriptor_GALGAS_gtlInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlDoNotInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDoNotInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlDoNotInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlDoNotInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlDoNotInstruction GALGAS_gtlDoNotInstruction::extractObject (const GALGAS_object & inObject,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlDoNotInstruction result ;
  const GALGAS_gtlDoNotInstruction * p = (const GALGAS_gtlDoNotInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlDoNotInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlDoNotInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlWatchpointInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlWatchpointInstruction * p = (const cPtr_gtlWatchpointInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlWatchpointInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_watchExpression.objectCompare (p->mProperty_watchExpression) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlWatchpointInstruction::objectCompare (const GALGAS_gtlWatchpointInstruction & inOperand) const {
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

//--------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointInstruction::GALGAS_gtlWatchpointInstruction (void) :
GALGAS_gtlInstruction () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointInstruction::GALGAS_gtlWatchpointInstruction (const cPtr_gtlWatchpointInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlWatchpointInstruction) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointInstruction GALGAS_gtlWatchpointInstruction::class_func_new (const GALGAS_location & inAttribute_where,
                                                                                 const GALGAS_string & inAttribute_signature,
                                                                                 const GALGAS_gtlExpression & inAttribute_watchExpression
                                                                                 COMMA_LOCATION_ARGS) {
  GALGAS_gtlWatchpointInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_watchExpression.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlWatchpointInstruction (inAttribute_where, inAttribute_signature, inAttribute_watchExpression COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlWatchpointInstruction::readProperty_watchExpression (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlWatchpointInstruction * p = (const cPtr_gtlWatchpointInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWatchpointInstruction) ;
    return p->mProperty_watchExpression ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlWatchpointInstruction::getter_watchExpression (UNUSED_LOCATION_ARGS) const {
  return mProperty_watchExpression ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_gtlWatchpointInstruction::setter_setWatchExpression (GALGAS_gtlExpression inValue
                                                                 COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlWatchpointInstruction * p = (cPtr_gtlWatchpointInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlWatchpointInstruction) ;
    p->mProperty_watchExpression = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointInstruction::setter_setWatchExpression (GALGAS_gtlExpression inValue
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_watchExpression = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @gtlWatchpointInstruction class
//--------------------------------------------------------------------------------------------------

cPtr_gtlWatchpointInstruction::cPtr_gtlWatchpointInstruction (const GALGAS_location & in_where,
                                                              const GALGAS_string & in_signature,
                                                              const GALGAS_gtlExpression & in_watchExpression
                                                              COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_watchExpression (in_watchExpression) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlWatchpointInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlWatchpointInstruction ;
}

void cPtr_gtlWatchpointInstruction::description (String & ioString,
                                                 const int32_t inIndentation) const {
  ioString.appendCString ("[@gtlWatchpointInstruction:") ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_watchExpression.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlWatchpointInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlWatchpointInstruction (mProperty_where, mProperty_signature, mProperty_watchExpression COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @gtlWatchpointInstruction generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlWatchpointInstruction ("gtlWatchpointInstruction",
                                                                                & kTypeDescriptor_GALGAS_gtlInstruction) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlWatchpointInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlWatchpointInstruction ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlWatchpointInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlWatchpointInstruction (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_gtlWatchpointInstruction GALGAS_gtlWatchpointInstruction::extractObject (const GALGAS_object & inObject,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlWatchpointInstruction result ;
  const GALGAS_gtlWatchpointInstruction * p = (const GALGAS_gtlWatchpointInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlWatchpointInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlWatchpointInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#include "MF_MemoryControl.h"
#include "C_galgas_CLI_Options.h"

#include "FileManager.h"

//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//
//                                     LL(1) PRODUCTION RULES                                       
//
//--------------------------------------------------------------------------------------------------

static const int32_t gProductions_gtl_debugger_grammar [] = {
// At index 0 : <gtl_expression>, in file 'gtl_debugger_expression_parser.ggs', line 33
  TOP_DOWN_NONTERMINAL (5) // <gtl_relation_term>
, TOP_DOWN_NONTERMINAL (24) // <select_gtl_5F_debugger_5F_expression_5F_parser_0>
, TOP_DOWN_END_PRODUCTION ()
// At index 3 : <gtl_variable>, in file 'gtl_debugger_expression_parser.ggs', line 667
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (45) // <select_gtl_5F_debugger_5F_expression_5F_parser_21>
, TOP_DOWN_NONTERMINAL (44) // <select_gtl_5F_debugger_5F_expression_5F_parser_20>
, TOP_DOWN_END_PRODUCTION ()
// At index 7 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 37
, TOP_DOWN_NONTERMINAL (10) // <select_gtl_5F_debugger_5F_parser_0>
, TOP_DOWN_END_PRODUCTION ()
// At index 9 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 52
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_help) // $help$
, TOP_DOWN_END_PRODUCTION ()
// At index 11 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 63
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_step) // $step$
, TOP_DOWN_END_PRODUCTION ()
// At index 13 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 74
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_load) // $load$
, TOP_DOWN_NONTERMINAL (11) // <select_gtl_5F_debugger_5F_parser_1>
, TOP_DOWN_END_PRODUCTION ()
// At index 16 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 92
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_hist) // $hist$
, TOP_DOWN_END_PRODUCTION ()
// At index 18 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 103
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_break) // $break$
, TOP_DOWN_NONTERMINAL (12) // <select_gtl_5F_debugger_5F_parser_2>
, TOP_DOWN_END_PRODUCTION ()
// At index 21 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 169
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_watch) // $watch$
, TOP_DOWN_NONTERMINAL (15) // <select_gtl_5F_debugger_5F_parser_5>
, TOP_DOWN_END_PRODUCTION ()
// At index 24 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 207
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_do) // $do$
, TOP_DOWN_NONTERMINAL (17) // <select_gtl_5F_debugger_5F_parser_7>
, TOP_DOWN_END_PRODUCTION ()
// At index 27 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 244
, TOP_DOWN_END_PRODUCTION ()
// At index 28 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 254
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_let) // $let$
, TOP_DOWN_NONTERMINAL (1) // <gtl_variable>
, TOP_DOWN_NONTERMINAL (19) // <select_gtl_5F_debugger_5F_parser_9>
, TOP_DOWN_END_PRODUCTION ()
// At index 32 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 368
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_unlet) // $unlet$
, TOP_DOWN_NONTERMINAL (1) // <gtl_variable>
, TOP_DOWN_END_PRODUCTION ()
// At index 35 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 381
, TOP_DOWN_NONTERMINAL (3) // <gtl_step_do_command>
, TOP_DOWN_END_PRODUCTION ()
// At index 37 : <gtl_step_do_command>, in file 'gtl_debugger_parser.ggs', line 388
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_variables) // $variables$
, TOP_DOWN_END_PRODUCTION ()
// At index 39 : <gtl_step_do_command>, in file 'gtl_debugger_parser.ggs', line 400
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_display) // $display$
, TOP_DOWN_NONTERMINAL (1) // <gtl_variable>
, TOP_DOWN_END_PRODUCTION ()
// At index 42 : <gtl_step_do_command>, in file 'gtl_debugger_parser.ggs', line 413
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_print) // $print$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 45 : <gtl_step_do_command>, in file 'gtl_debugger_parser.ggs', line 427
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_list) // $list$
, TOP_DOWN_NONTERMINAL (20) // <select_gtl_5F_debugger_5F_parser_10>
, TOP_DOWN_END_PRODUCTION ()
// At index 48 : <gtl_step_do_command>, in file 'gtl_debugger_parser.ggs', line 448
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_if) // $if$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_then) // $then$
, TOP_DOWN_NONTERMINAL (4) // <gtl_step_do_command_list>
, TOP_DOWN_NONTERMINAL (21) // <select_gtl_5F_debugger_5F_parser_11>
, TOP_DOWN_NONTERMINAL (22) // <select_gtl_5F_debugger_5F_parser_12>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_end) // $end$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_if) // $if$
, TOP_DOWN_END_PRODUCTION ()
// At index 57 : <gtl_step_do_command_list>, in file 'gtl_debugger_parser.ggs', line 481
, TOP_DOWN_NONTERMINAL (23) // <select_gtl_5F_debugger_5F_parser_13>
, TOP_DOWN_END_PRODUCTION ()
// At index 59 : <gtl_relation_term>, in file 'gtl_debugger_expression_parser.ggs', line 53
, TOP_DOWN_NONTERMINAL (6) // <gtl_relation_factor>
, TOP_DOWN_NONTERMINAL (25) // <select_gtl_5F_debugger_5F_expression_5F_parser_1>
, TOP_DOWN_END_PRODUCTION ()
// At index 62 : <gtl_relation_factor>, in file 'gtl_debugger_expression_parser.ggs', line 69
, TOP_DOWN_NONTERMINAL (7) // <gtl_simple_expression>
, TOP_DOWN_NONTERMINAL (26) // <select_gtl_5F_debugger_5F_expression_5F_parser_2>
, TOP_DOWN_END_PRODUCTION ()
// At index 65 : <gtl_simple_expression>, in file 'gtl_debugger_expression_parser.ggs', line 117
, TOP_DOWN_NONTERMINAL (8) // <gtl_term>
, TOP_DOWN_NONTERMINAL (27) // <select_gtl_5F_debugger_5F_expression_5F_parser_3>
, TOP_DOWN_END_PRODUCTION ()
// At index 68 : <gtl_term>, in file 'gtl_debugger_expression_parser.ggs', line 162
, TOP_DOWN_NONTERMINAL (9) // <gtl_factor>
, TOP_DOWN_NONTERMINAL (28) // <select_gtl_5F_debugger_5F_expression_5F_parser_4>
, TOP_DOWN_END_PRODUCTION ()
// At index 71 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 192
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__28_) // $($
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__29_) // $)$
, TOP_DOWN_END_PRODUCTION ()
// At index 75 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 208
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_not) // $not$
, TOP_DOWN_NONTERMINAL (9) // <gtl_factor>
, TOP_DOWN_END_PRODUCTION ()
// At index 78 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 220
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__7E_) // $~$
, TOP_DOWN_NONTERMINAL (9) // <gtl_factor>
, TOP_DOWN_END_PRODUCTION ()
// At index 81 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 232
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_) // $-$
, TOP_DOWN_NONTERMINAL (9) // <gtl_factor>
, TOP_DOWN_END_PRODUCTION ()
// At index 84 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 244
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_) // $+$
, TOP_DOWN_NONTERMINAL (9) // <gtl_factor>
, TOP_DOWN_END_PRODUCTION ()
// At index 87 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 256
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_yes) // $yes$
, TOP_DOWN_END_PRODUCTION ()
// At index 89 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 269
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_no) // $no$
, TOP_DOWN_END_PRODUCTION ()
// At index 91 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 282
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) // $signed_literal_integer_bigint$
, TOP_DOWN_END_PRODUCTION ()
// At index 93 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 295
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_double) // $literal_double$
, TOP_DOWN_END_PRODUCTION ()
// At index 95 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 308
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_string) // $string$
, TOP_DOWN_END_PRODUCTION ()
// At index 97 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 321
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_char) // $literal_char$
, TOP_DOWN_END_PRODUCTION ()
// At index 99 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 335
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_) // $[$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (29) // <select_gtl_5F_debugger_5F_expression_5F_parser_5>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_) // $]$
, TOP_DOWN_END_PRODUCTION ()
// At index 105 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 369
, TOP_DOWN_NONTERMINAL (1) // <gtl_variable>
, TOP_DOWN_NONTERMINAL (31) // <select_gtl_5F_debugger_5F_expression_5F_parser_7>
, TOP_DOWN_END_PRODUCTION ()
// At index 108 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 401
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_exists) // $exists$
, TOP_DOWN_NONTERMINAL (1) // <gtl_variable>
, TOP_DOWN_NONTERMINAL (34) // <select_gtl_5F_debugger_5F_expression_5F_parser_10>
, TOP_DOWN_END_PRODUCTION ()
// At index 112 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 420
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_typeof) // $typeof$
, TOP_DOWN_NONTERMINAL (1) // <gtl_variable>
, TOP_DOWN_END_PRODUCTION ()
// At index 115 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 429
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_true) // $true$
, TOP_DOWN_END_PRODUCTION ()
// At index 117 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 445
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_false) // $false$
, TOP_DOWN_END_PRODUCTION ()
// At index 119 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 461
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_enum) // $literal_enum$
, TOP_DOWN_END_PRODUCTION ()
// At index 121 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 477
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__40_) // $@$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_END_PRODUCTION ()
// At index 124 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 514
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_emptylist) // $emptylist$
, TOP_DOWN_END_PRODUCTION ()
// At index 126 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 533
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_emptymap) // $emptymap$
, TOP_DOWN_END_PRODUCTION ()
// At index 128 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 552
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_mapof) // $mapof$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (35) // <select_gtl_5F_debugger_5F_expression_5F_parser_11>
, TOP_DOWN_END_PRODUCTION ()
// At index 132 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 576
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_listof) // $listof$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_end) // $end$
, TOP_DOWN_END_PRODUCTION ()
// At index 136 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 587
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__40__28_) // $@($
, TOP_DOWN_NONTERMINAL (36) // <select_gtl_5F_debugger_5F_expression_5F_parser_12>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__29_) // $)$
, TOP_DOWN_END_PRODUCTION ()
// At index 140 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 606
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__40__5B_) // $@[$
, TOP_DOWN_NONTERMINAL (38) // <select_gtl_5F_debugger_5F_expression_5F_parser_14>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_) // $]$
, TOP_DOWN_END_PRODUCTION ()
// At index 144 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 627
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__40__7B_) // $@{$
, TOP_DOWN_NONTERMINAL (40) // <select_gtl_5F_debugger_5F_expression_5F_parser_16>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_) // $}$
, TOP_DOWN_END_PRODUCTION ()
// At index 148 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 648
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__40__21_) // $@!$
, TOP_DOWN_NONTERMINAL (42) // <select_gtl_5F_debugger_5F_expression_5F_parser_18>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__21_) // $!$
, TOP_DOWN_END_PRODUCTION ()
//---- Added productions from 'select' and 'repeat' instructions
// At index 152 : <select_gtl_5F_debugger_5F_parser_0>, in file 'gtl_debugger_parser.ggs', line 40
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_cont) // $cont$
, TOP_DOWN_END_PRODUCTION ()
// At index 154 : <select_gtl_5F_debugger_5F_parser_0>, in file 'gtl_debugger_parser.ggs', line 40
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_continue) // $continue$
, TOP_DOWN_END_PRODUCTION ()
// At index 156 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 79
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_END_PRODUCTION ()
// At index 158 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 79
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_string) // $string$
, TOP_DOWN_END_PRODUCTION ()
// At index 160 : <select_gtl_5F_debugger_5F_parser_2>, in file 'gtl_debugger_parser.ggs', line 107
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_not) // $not$
, TOP_DOWN_NONTERMINAL (13) // <select_gtl_5F_debugger_5F_parser_3>
, TOP_DOWN_END_PRODUCTION ()
// At index 163 : <select_gtl_5F_debugger_5F_parser_2>, in file 'gtl_debugger_parser.ggs', line 107
, TOP_DOWN_NONTERMINAL (14) // <select_gtl_5F_debugger_5F_parser_4>
, TOP_DOWN_END_PRODUCTION ()
// At index 165 : <select_gtl_5F_debugger_5F_parser_2>, in file 'gtl_debugger_parser.ggs', line 107
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_string) // $string$
, TOP_DOWN_END_PRODUCTION ()
// At index 167 : <select_gtl_5F_debugger_5F_parser_2>, in file 'gtl_debugger_parser.ggs', line 107
, TOP_DOWN_END_PRODUCTION ()
// At index 168 : <select_gtl_5F_debugger_5F_parser_3>, in file 'gtl_debugger_parser.ggs', line 109
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) // $signed_literal_integer_bigint$
, TOP_DOWN_END_PRODUCTION ()
// At index 170 : <select_gtl_5F_debugger_5F_parser_3>, in file 'gtl_debugger_parser.ggs', line 109
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_all) // $all$
, TOP_DOWN_END_PRODUCTION ()
// At index 172 : <select_gtl_5F_debugger_5F_parser_4>, in file 'gtl_debugger_parser.ggs', line 124
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2E_) // $.$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) // $signed_literal_integer_bigint$
, TOP_DOWN_END_PRODUCTION ()
// At index 178 : <select_gtl_5F_debugger_5F_parser_4>, in file 'gtl_debugger_parser.ggs', line 124
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) // $signed_literal_integer_bigint$
, TOP_DOWN_END_PRODUCTION ()
// At index 180 : <select_gtl_5F_debugger_5F_parser_5>, in file 'gtl_debugger_parser.ggs', line 173
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_not) // $not$
, TOP_DOWN_NONTERMINAL (16) // <select_gtl_5F_debugger_5F_parser_6>
, TOP_DOWN_END_PRODUCTION ()
// At index 183 : <select_gtl_5F_debugger_5F_parser_5>, in file 'gtl_debugger_parser.ggs', line 173
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__28_) // $($
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__29_) // $)$
, TOP_DOWN_END_PRODUCTION ()
// At index 187 : <select_gtl_5F_debugger_5F_parser_5>, in file 'gtl_debugger_parser.ggs', line 173
, TOP_DOWN_END_PRODUCTION ()
// At index 188 : <select_gtl_5F_debugger_5F_parser_6>, in file 'gtl_debugger_parser.ggs', line 175
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) // $signed_literal_integer_bigint$
, TOP_DOWN_END_PRODUCTION ()
// At index 190 : <select_gtl_5F_debugger_5F_parser_6>, in file 'gtl_debugger_parser.ggs', line 175
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_all) // $all$
, TOP_DOWN_END_PRODUCTION ()
// At index 192 : <select_gtl_5F_debugger_5F_parser_7>, in file 'gtl_debugger_parser.ggs', line 212
, TOP_DOWN_NONTERMINAL (3) // <gtl_step_do_command>
, TOP_DOWN_END_PRODUCTION ()
// At index 194 : <select_gtl_5F_debugger_5F_parser_7>, in file 'gtl_debugger_parser.ggs', line 212
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_not) // $not$
, TOP_DOWN_NONTERMINAL (18) // <select_gtl_5F_debugger_5F_parser_8>
, TOP_DOWN_END_PRODUCTION ()
// At index 197 : <select_gtl_5F_debugger_5F_parser_7>, in file 'gtl_debugger_parser.ggs', line 212
, TOP_DOWN_END_PRODUCTION ()
// At index 198 : <select_gtl_5F_debugger_5F_parser_8>, in file 'gtl_debugger_parser.ggs', line 221
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) // $signed_literal_integer_bigint$
, TOP_DOWN_END_PRODUCTION ()
// At index 200 : <select_gtl_5F_debugger_5F_parser_8>, in file 'gtl_debugger_parser.ggs', line 221
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_all) // $all$
, TOP_DOWN_END_PRODUCTION ()
// At index 202 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3D_) // $:=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 205 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2B__3D_) // $+=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 208 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2D__3D_) // $-=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 211 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2A__3D_) // $*=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 214 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2F__3D_) // $/=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 217 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_mod_3D_) // $mod=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 220 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C__3D_) // $<<=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 223 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E__3D_) // $>>=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 226 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__26__3D_) // $&=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 229 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__7C__3D_) // $|=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 232 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__5E__3D_) // $^=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 235 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
, TOP_DOWN_END_PRODUCTION ()
// At index 236 : <select_gtl_5F_debugger_5F_parser_10>, in file 'gtl_debugger_parser.ggs', line 432
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) // $signed_literal_integer_bigint$
, TOP_DOWN_END_PRODUCTION ()
// At index 238 : <select_gtl_5F_debugger_5F_parser_10>, in file 'gtl_debugger_parser.ggs', line 432
, TOP_DOWN_END_PRODUCTION ()
// At index 239 : <select_gtl_5F_debugger_5F_parser_11>, in file 'gtl_debugger_parser.ggs', line 455
, TOP_DOWN_END_PRODUCTION ()
// At index 240 : <select_gtl_5F_debugger_5F_parser_11>, in file 'gtl_debugger_parser.ggs', line 455
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif) // $elsif$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_then) // $then$
, TOP_DOWN_NONTERMINAL (4) // <gtl_step_do_command_list>
, TOP_DOWN_NONTERMINAL (21) // <select_gtl_5F_debugger_5F_parser_11>
, TOP_DOWN_END_PRODUCTION ()
// At index 246 : <select_gtl_5F_debugger_5F_parser_12>, in file 'gtl_debugger_parser.ggs', line 465
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_else) // $else$
, TOP_DOWN_NONTERMINAL (4) // <gtl_step_do_command_list>
, TOP_DOWN_END_PRODUCTION ()
// At index 249 : <select_gtl_5F_debugger_5F_parser_12>, in file 'gtl_debugger_parser.ggs', line 465
, TOP_DOWN_END_PRODUCTION ()
// At index 250 : <select_gtl_5F_debugger_5F_parser_13>, in file 'gtl_debugger_parser.ggs', line 486
, TOP_DOWN_END_PRODUCTION ()
// At index 251 : <select_gtl_5F_debugger_5F_parser_13>, in file 'gtl_debugger_parser.ggs', line 486
, TOP_DOWN_NONTERMINAL (3) // <gtl_step_do_command>
, TOP_DOWN_NONTERMINAL (23) // <select_gtl_5F_debugger_5F_parser_13>
, TOP_DOWN_END_PRODUCTION ()
// At index 254 : <select_gtl_5F_debugger_5F_expression_5F_parser_0>, in file 'gtl_debugger_expression_parser.ggs', line 37
, TOP_DOWN_END_PRODUCTION ()
// At index 255 : <select_gtl_5F_debugger_5F_expression_5F_parser_0>, in file 'gtl_debugger_expression_parser.ggs', line 37
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__7C_) // $|$
, TOP_DOWN_NONTERMINAL (5) // <gtl_relation_term>
, TOP_DOWN_NONTERMINAL (24) // <select_gtl_5F_debugger_5F_expression_5F_parser_0>
, TOP_DOWN_END_PRODUCTION ()
// At index 259 : <select_gtl_5F_debugger_5F_expression_5F_parser_0>, in file 'gtl_debugger_expression_parser.ggs', line 37
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__5E_) // $^$
, TOP_DOWN_NONTERMINAL (5) // <gtl_relation_term>
, TOP_DOWN_NONTERMINAL (24) // <select_gtl_5F_debugger_5F_expression_5F_parser_0>
, TOP_DOWN_END_PRODUCTION ()
// At index 263 : <select_gtl_5F_debugger_5F_expression_5F_parser_1>, in file 'gtl_debugger_expression_parser.ggs', line 57
, TOP_DOWN_END_PRODUCTION ()
// At index 264 : <select_gtl_5F_debugger_5F_expression_5F_parser_1>, in file 'gtl_debugger_expression_parser.ggs', line 57
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__26_) // $&$
, TOP_DOWN_NONTERMINAL (6) // <gtl_relation_factor>
, TOP_DOWN_NONTERMINAL (25) // <select_gtl_5F_debugger_5F_expression_5F_parser_1>
, TOP_DOWN_END_PRODUCTION ()
// At index 268 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>, in file 'gtl_debugger_expression_parser.ggs', line 73
, TOP_DOWN_END_PRODUCTION ()
// At index 269 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>, in file 'gtl_debugger_expression_parser.ggs', line 73
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3D__3D_) // $==$
, TOP_DOWN_NONTERMINAL (7) // <gtl_simple_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 272 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>, in file 'gtl_debugger_expression_parser.ggs', line 73
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__21__3D_) // $!=$
, TOP_DOWN_NONTERMINAL (7) // <gtl_simple_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 275 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>, in file 'gtl_debugger_expression_parser.ggs', line 73
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3D_) // $<=$
, TOP_DOWN_NONTERMINAL (7) // <gtl_simple_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 278 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>, in file 'gtl_debugger_expression_parser.ggs', line 73
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3D_) // $>=$
, TOP_DOWN_NONTERMINAL (7) // <gtl_simple_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 281 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>, in file 'gtl_debugger_expression_parser.ggs', line 73
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3E_) // $>$
, TOP_DOWN_NONTERMINAL (7) // <gtl_simple_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 284 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>, in file 'gtl_debugger_expression_parser.ggs', line 73
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3C_) // $<$
, TOP_DOWN_NONTERMINAL (7) // <gtl_simple_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 287 : <select_gtl_5F_debugger_5F_expression_5F_parser_3>, in file 'gtl_debugger_expression_parser.ggs', line 121
, TOP_DOWN_END_PRODUCTION ()
// At index 288 : <select_gtl_5F_debugger_5F_expression_5F_parser_3>, in file 'gtl_debugger_expression_parser.ggs', line 121
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C_) // $<<$
, TOP_DOWN_NONTERMINAL (8) // <gtl_term>
, TOP_DOWN_NONTERMINAL (27) // <select_gtl_5F_debugger_5F_expression_5F_parser_3>
, TOP_DOWN_END_PRODUCTION ()
// At index 292 : <select_gtl_5F_debugger_5F_expression_5F_parser_3>, in file 'gtl_debugger_expression_parser.ggs', line 121
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E_) // $>>$
, TOP_DOWN_NONTERMINAL (8) // <gtl_term>
, TOP_DOWN_NONTERMINAL (27) // <select_gtl_5F_debugger_5F_expression_5F_parser_3>
, TOP_DOWN_END_PRODUCTION ()
// At index 296 : <select_gtl_5F_debugger_5F_expression_5F_parser_3>, in file 'gtl_debugger_expression_parser.ggs', line 121
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_) // $+$
, TOP_DOWN_NONTERMINAL (8) // <gtl_term>
, TOP_DOWN_NONTERMINAL (27) // <select_gtl_5F_debugger_5F_expression_5F_parser_3>
, TOP_DOWN_END_PRODUCTION ()
// At index 300 : <select_gtl_5F_debugger_5F_expression_5F_parser_3>, in file 'gtl_debugger_expression_parser.ggs', line 121
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2E_) // $.$
, TOP_DOWN_NONTERMINAL (8) // <gtl_term>
, TOP_DOWN_NONTERMINAL (27) // <select_gtl_5F_debugger_5F_expression_5F_parser_3>
, TOP_DOWN_END_PRODUCTION ()
// At index 304 : <select_gtl_5F_debugger_5F_expression_5F_parser_3>, in file 'gtl_debugger_expression_parser.ggs', line 121
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_) // $-$
, TOP_DOWN_NONTERMINAL (8) // <gtl_term>
, TOP_DOWN_NONTERMINAL (27) // <select_gtl_5F_debugger_5F_expression_5F_parser_3>
, TOP_DOWN_END_PRODUCTION ()
// At index 308 : <select_gtl_5F_debugger_5F_expression_5F_parser_4>, in file 'gtl_debugger_expression_parser.ggs', line 166
, TOP_DOWN_END_PRODUCTION ()
// At index 309 : <select_gtl_5F_debugger_5F_expression_5F_parser_4>, in file 'gtl_debugger_expression_parser.ggs', line 166
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2A_) // $*$
, TOP_DOWN_NONTERMINAL (9) // <gtl_factor>
, TOP_DOWN_NONTERMINAL (28) // <select_gtl_5F_debugger_5F_expression_5F_parser_4>
, TOP_DOWN_END_PRODUCTION ()
// At index 313 : <select_gtl_5F_debugger_5F_expression_5F_parser_4>, in file 'gtl_debugger_expression_parser.ggs', line 166
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2F_) // $/$
, TOP_DOWN_NONTERMINAL (9) // <gtl_factor>
, TOP_DOWN_NONTERMINAL (28) // <select_gtl_5F_debugger_5F_expression_5F_parser_4>
, TOP_DOWN_END_PRODUCTION ()
// At index 317 : <select_gtl_5F_debugger_5F_expression_5F_parser_4>, in file 'gtl_debugger_expression_parser.ggs', line 166
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_mod) // $mod$
, TOP_DOWN_NONTERMINAL (9) // <gtl_factor>
, TOP_DOWN_NONTERMINAL (28) // <select_gtl_5F_debugger_5F_expression_5F_parser_4>
, TOP_DOWN_END_PRODUCTION ()
// At index 321 : <select_gtl_5F_debugger_5F_expression_5F_parser_5>, in file 'gtl_debugger_expression_parser.ggs', line 348
, TOP_DOWN_END_PRODUCTION ()
// At index 322 : <select_gtl_5F_debugger_5F_expression_5F_parser_5>, in file 'gtl_debugger_expression_parser.ggs', line 348
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (30) // <select_gtl_5F_debugger_5F_expression_5F_parser_6>
, TOP_DOWN_END_PRODUCTION ()
// At index 326 : <select_gtl_5F_debugger_5F_expression_5F_parser_6>, in file 'gtl_debugger_expression_parser.ggs', line 351
, TOP_DOWN_END_PRODUCTION ()
// At index 327 : <select_gtl_5F_debugger_5F_expression_5F_parser_6>, in file 'gtl_debugger_expression_parser.ggs', line 351
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (30) // <select_gtl_5F_debugger_5F_expression_5F_parser_6>
, TOP_DOWN_END_PRODUCTION ()
// At index 331 : <select_gtl_5F_debugger_5F_expression_5F_parser_7>, in file 'gtl_debugger_expression_parser.ggs', line 373
, TOP_DOWN_END_PRODUCTION ()
// At index 332 : <select_gtl_5F_debugger_5F_expression_5F_parser_7>, in file 'gtl_debugger_expression_parser.ggs', line 373
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__28_) // $($
, TOP_DOWN_NONTERMINAL (32) // <select_gtl_5F_debugger_5F_expression_5F_parser_8>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__29_) // $)$
, TOP_DOWN_END_PRODUCTION ()
// At index 336 : <select_gtl_5F_debugger_5F_expression_5F_parser_8>, in file 'gtl_debugger_expression_parser.ggs', line 381
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (33) // <select_gtl_5F_debugger_5F_expression_5F_parser_9>
, TOP_DOWN_END_PRODUCTION ()
// At index 339 : <select_gtl_5F_debugger_5F_expression_5F_parser_8>, in file 'gtl_debugger_expression_parser.ggs', line 381
, TOP_DOWN_END_PRODUCTION ()
// At index 340 : <select_gtl_5F_debugger_5F_expression_5F_parser_9>, in file 'gtl_debugger_expression_parser.ggs', line 382
, TOP_DOWN_END_PRODUCTION ()
// At index 341 : <select_gtl_5F_debugger_5F_expression_5F_parser_9>, in file 'gtl_debugger_expression_parser.ggs', line 382
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (33) // <select_gtl_5F_debugger_5F_expression_5F_parser_9>
, TOP_DOWN_END_PRODUCTION ()
// At index 345 : <select_gtl_5F_debugger_5F_expression_5F_parser_10>, in file 'gtl_debugger_expression_parser.ggs', line 405
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_default) // $default$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__28_) // $($
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__29_) // $)$
, TOP_DOWN_END_PRODUCTION ()
// At index 350 : <select_gtl_5F_debugger_5F_expression_5F_parser_10>, in file 'gtl_debugger_expression_parser.ggs', line 405
, TOP_DOWN_END_PRODUCTION ()
// At index 351 : <select_gtl_5F_debugger_5F_expression_5F_parser_11>, in file 'gtl_debugger_expression_parser.ggs', line 557
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_by) // $by$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_END_PRODUCTION ()
// At index 354 : <select_gtl_5F_debugger_5F_expression_5F_parser_11>, in file 'gtl_debugger_expression_parser.ggs', line 557
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_end) // $end$
, TOP_DOWN_END_PRODUCTION ()
// At index 356 : <select_gtl_5F_debugger_5F_expression_5F_parser_12>, in file 'gtl_debugger_expression_parser.ggs', line 592
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (37) // <select_gtl_5F_debugger_5F_expression_5F_parser_13>
, TOP_DOWN_END_PRODUCTION ()
// At index 359 : <select_gtl_5F_debugger_5F_expression_5F_parser_12>, in file 'gtl_debugger_expression_parser.ggs', line 592
, TOP_DOWN_END_PRODUCTION ()
// At index 360 : <select_gtl_5F_debugger_5F_expression_5F_parser_13>, in file 'gtl_debugger_expression_parser.ggs', line 593
, TOP_DOWN_END_PRODUCTION ()
// At index 361 : <select_gtl_5F_debugger_5F_expression_5F_parser_13>, in file 'gtl_debugger_expression_parser.ggs', line 593
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (37) // <select_gtl_5F_debugger_5F_expression_5F_parser_13>
, TOP_DOWN_END_PRODUCTION ()
// At index 365 : <select_gtl_5F_debugger_5F_expression_5F_parser_14>, in file 'gtl_debugger_expression_parser.ggs', line 611
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_string) // $string$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (39) // <select_gtl_5F_debugger_5F_expression_5F_parser_15>
, TOP_DOWN_END_PRODUCTION ()
// At index 370 : <select_gtl_5F_debugger_5F_expression_5F_parser_14>, in file 'gtl_debugger_expression_parser.ggs', line 611
, TOP_DOWN_END_PRODUCTION ()
// At index 371 : <select_gtl_5F_debugger_5F_expression_5F_parser_15>, in file 'gtl_debugger_expression_parser.ggs', line 612
, TOP_DOWN_END_PRODUCTION ()
// At index 372 : <select_gtl_5F_debugger_5F_expression_5F_parser_15>, in file 'gtl_debugger_expression_parser.ggs', line 612
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_string) // $string$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (39) // <select_gtl_5F_debugger_5F_expression_5F_parser_15>
, TOP_DOWN_END_PRODUCTION ()
// At index 378 : <select_gtl_5F_debugger_5F_expression_5F_parser_16>, in file 'gtl_debugger_expression_parser.ggs', line 632
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (41) // <select_gtl_5F_debugger_5F_expression_5F_parser_17>
, TOP_DOWN_END_PRODUCTION ()
// At index 383 : <select_gtl_5F_debugger_5F_expression_5F_parser_16>, in file 'gtl_debugger_expression_parser.ggs', line 632
, TOP_DOWN_END_PRODUCTION ()
// At index 384 : <select_gtl_5F_debugger_5F_expression_5F_parser_17>, in file 'gtl_debugger_expression_parser.ggs', line 633
, TOP_DOWN_END_PRODUCTION ()
// At index 385 : <select_gtl_5F_debugger_5F_expression_5F_parser_17>, in file 'gtl_debugger_expression_parser.ggs', line 633
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (41) // <select_gtl_5F_debugger_5F_expression_5F_parser_17>
, TOP_DOWN_END_PRODUCTION ()
// At index 391 : <select_gtl_5F_debugger_5F_expression_5F_parser_18>, in file 'gtl_debugger_expression_parser.ggs', line 653
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (43) // <select_gtl_5F_debugger_5F_expression_5F_parser_19>
, TOP_DOWN_END_PRODUCTION ()
// At index 394 : <select_gtl_5F_debugger_5F_expression_5F_parser_18>, in file 'gtl_debugger_expression_parser.ggs', line 653
, TOP_DOWN_END_PRODUCTION ()
// At index 395 : <select_gtl_5F_debugger_5F_expression_5F_parser_19>, in file 'gtl_debugger_expression_parser.ggs', line 654
, TOP_DOWN_END_PRODUCTION ()
// At index 396 : <select_gtl_5F_debugger_5F_expression_5F_parser_19>, in file 'gtl_debugger_expression_parser.ggs', line 654
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (43) // <select_gtl_5F_debugger_5F_expression_5F_parser_19>
, TOP_DOWN_END_PRODUCTION ()
// At index 400 : <select_gtl_5F_debugger_5F_expression_5F_parser_20>, in file 'gtl_debugger_expression_parser.ggs', line 671
, TOP_DOWN_END_PRODUCTION ()
// At index 401 : <select_gtl_5F_debugger_5F_expression_5F_parser_20>, in file 'gtl_debugger_expression_parser.ggs', line 671
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3A_) // $::$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (45) // <select_gtl_5F_debugger_5F_expression_5F_parser_21>
, TOP_DOWN_NONTERMINAL (44) // <select_gtl_5F_debugger_5F_expression_5F_parser_20>
, TOP_DOWN_END_PRODUCTION ()
// At index 406 : <select_gtl_5F_debugger_5F_expression_5F_parser_21>, in file 'gtl_debugger_expression_parser.ggs', line 673
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_) // $[$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_) // $]$
, TOP_DOWN_NONTERMINAL (46) // <select_gtl_5F_debugger_5F_expression_5F_parser_22>
, TOP_DOWN_END_PRODUCTION ()
// At index 411 : <select_gtl_5F_debugger_5F_expression_5F_parser_21>, in file 'gtl_debugger_expression_parser.ggs', line 673
, TOP_DOWN_END_PRODUCTION ()
// At index 412 : <select_gtl_5F_debugger_5F_expression_5F_parser_22>, in file 'gtl_debugger_expression_parser.ggs', line 678
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_) // $[$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_) // $]$
, TOP_DOWN_NONTERMINAL (47) // <select_gtl_5F_debugger_5F_expression_5F_parser_23>
, TOP_DOWN_END_PRODUCTION ()
// At index 417 : <select_gtl_5F_debugger_5F_expression_5F_parser_22>, in file 'gtl_debugger_expression_parser.ggs', line 678
, TOP_DOWN_END_PRODUCTION ()
// At index 418 : <select_gtl_5F_debugger_5F_expression_5F_parser_23>, in file 'gtl_debugger_expression_parser.ggs', line 683
, TOP_DOWN_END_PRODUCTION ()
// At index 419 : <select_gtl_5F_debugger_5F_expression_5F_parser_23>, in file 'gtl_debugger_expression_parser.ggs', line 683
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_) // $[$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_) // $]$
, TOP_DOWN_NONTERMINAL (47) // <select_gtl_5F_debugger_5F_expression_5F_parser_23>
, TOP_DOWN_END_PRODUCTION ()
// At index 424 : <>, in file '.ggs', line 0
, TOP_DOWN_NONTERMINAL (2) // <gtl_debugger_command>
, TOP_DOWN_END_PRODUCTION ()
} ;

//--------------------------------------------------------------------------------------------------
//
//                                P R O D U C T I O N    N A M E S                                  
//
//--------------------------------------------------------------------------------------------------

static const cProductionNameDescriptor gProductionNames_gtl_debugger_grammar [154] = {
 {"<gtl_expression>", "gtl_debugger_expression_parser", 0}, // at index 0
 {"<gtl_variable>", "gtl_debugger_expression_parser", 3}, // at index 1
 {"<gtl_debugger_command>", "gtl_debugger_parser", 7}, // at index 2
 {"<gtl_debugger_command>", "gtl_debugger_parser", 9}, // at index 3
 {"<gtl_debugger_command>", "gtl_debugger_parser", 11}, // at index 4
 {"<gtl_debugger_command>", "gtl_debugger_parser", 13}, // at index 5
 {"<gtl_debugger_command>", "gtl_debugger_parser", 16}, // at index 6
 {"<gtl_debugger_command>", "gtl_debugger_parser", 18}, // at index 7
 {"<gtl_debugger_command>", "gtl_debugger_parser", 21}, // at index 8
 {"<gtl_debugger_command>", "gtl_debugger_parser", 24}, // at index 9
 {"<gtl_debugger_command>", "gtl_debugger_parser", 27}, // at index 10
 {"<gtl_debugger_command>", "gtl_debugger_parser", 28}, // at index 11
 {"<gtl_debugger_command>", "gtl_debugger_parser", 32}, // at index 12
 {"<gtl_debugger_command>", "gtl_debugger_parser", 35}, // at index 13
 {"<gtl_step_do_command>", "gtl_debugger_parser", 37}, // at index 14
 {"<gtl_step_do_command>", "gtl_debugger_parser", 39}, // at index 15
 {"<gtl_step_do_command>", "gtl_debugger_parser", 42}, // at index 16
 {"<gtl_step_do_command>", "gtl_debugger_parser", 45}, // at index 17
 {"<gtl_step_do_command>", "gtl_debugger_parser", 48}, // at index 18
 {"<gtl_step_do_command_list>", "gtl_debugger_parser", 57}, // at index 19
 {"<gtl_relation_term>", "gtl_debugger_expression_parser", 59}, // at index 20
 {"<gtl_relation_factor>", "gtl_debugger_expression_parser", 62}, // at index 21
 {"<gtl_simple_expression>", "gtl_debugger_expression_parser", 65}, // at index 22
 {"<gtl_term>", "gtl_debugger_expression_parser", 68}, // at index 23
 {"<gtl_factor>", "gtl_debugger_expression_parser", 71}, // at index 24
 {"<gtl_factor>", "gtl_debugger_expression_parser", 75}, // at index 25
 {"<gtl_factor>", "gtl_debugger_expression_parser", 78}, // at index 26
 {"<gtl_factor>", "gtl_debugger_expression_parser", 81}, // at index 27
 {"<gtl_factor>", "gtl_debugger_expression_parser", 84}, // at index 28
 {"<gtl_factor>", "gtl_debugger_expression_parser", 87}, // at index 29
 {"<gtl_factor>", "gtl_debugger_expression_parser", 89}, // at index 30
 {"<gtl_factor>", "gtl_debugger_expression_parser", 91}, // at index 31
 {"<gtl_factor>", "gtl_debugger_expression_parser", 93}, // at index 32
 {"<gtl_factor>", "gtl_debugger_expression_parser", 95}, // at index 33
 {"<gtl_factor>", "gtl_debugger_expression_parser", 97}, // at index 34
 {"<gtl_factor>", "gtl_debugger_expression_parser", 99}, // at index 35
 {"<gtl_factor>", "gtl_debugger_expression_parser", 105}, // at index 36
 {"<gtl_factor>", "gtl_debugger_expression_parser", 108}, // at index 37
 {"<gtl_factor>", "gtl_debugger_expression_parser", 112}, // at index 38
 {"<gtl_factor>", "gtl_debugger_expression_parser", 115}, // at index 39
 {"<gtl_factor>", "gtl_debugger_expression_parser", 117}, // at index 40
 {"<gtl_factor>", "gtl_debugger_expression_parser", 119}, // at index 41
 {"<gtl_factor>", "gtl_debugger_expression_parser", 121}, // at index 42
 {"<gtl_factor>", "gtl_debugger_expression_parser", 124}, // at index 43
 {"<gtl_factor>", "gtl_debugger_expression_parser", 126}, // at index 44
 {"<gtl_factor>", "gtl_debugger_expression_parser", 128}, // at index 45
 {"<gtl_factor>", "gtl_debugger_expression_parser", 132}, // at index 46
 {"<gtl_factor>", "gtl_debugger_expression_parser", 136}, // at index 47
 {"<gtl_factor>", "gtl_debugger_expression_parser", 140}, // at index 48
 {"<gtl_factor>", "gtl_debugger_expression_parser", 144}, // at index 49
 {"<gtl_factor>", "gtl_debugger_expression_parser", 148}, // at index 50
 {"<select_gtl_5F_debugger_5F_parser_0>", "gtl_debugger_parser", 152}, // at index 51
 {"<select_gtl_5F_debugger_5F_parser_0>", "gtl_debugger_parser", 154}, // at index 52
 {"<select_gtl_5F_debugger_5F_parser_1>", "gtl_debugger_parser", 156}, // at index 53
 {"<select_gtl_5F_debugger_5F_parser_1>", "gtl_debugger_parser", 158}, // at index 54
 {"<select_gtl_5F_debugger_5F_parser_2>", "gtl_debugger_parser", 160}, // at index 55
 {"<select_gtl_5F_debugger_5F_parser_2>", "gtl_debugger_parser", 163}, // at index 56
 {"<select_gtl_5F_debugger_5F_parser_2>", "gtl_debugger_parser", 165}, // at index 57
 {"<select_gtl_5F_debugger_5F_parser_2>", "gtl_debugger_parser", 167}, // at index 58
 {"<select_gtl_5F_debugger_5F_parser_3>", "gtl_debugger_parser", 168}, // at index 59
 {"<select_gtl_5F_debugger_5F_parser_3>", "gtl_debugger_parser", 170}, // at index 60
 {"<select_gtl_5F_debugger_5F_parser_4>", "gtl_debugger_parser", 172}, // at index 61
 {"<select_gtl_5F_debugger_5F_parser_4>", "gtl_debugger_parser", 178}, // at index 62
 {"<select_gtl_5F_debugger_5F_parser_5>", "gtl_debugger_parser", 180}, // at index 63
 {"<select_gtl_5F_debugger_5F_parser_5>", "gtl_debugger_parser", 183}, // at index 64
 {"<select_gtl_5F_debugger_5F_parser_5>", "gtl_debugger_parser", 187}, // at index 65
 {"<select_gtl_5F_debugger_5F_parser_6>", "gtl_debugger_parser", 188}, // at index 66
 {"<select_gtl_5F_debugger_5F_parser_6>", "gtl_debugger_parser", 190}, // at index 67
 {"<select_gtl_5F_debugger_5F_parser_7>", "gtl_debugger_parser", 192}, // at index 68
 {"<select_gtl_5F_debugger_5F_parser_7>", "gtl_debugger_parser", 194}, // at index 69
 {"<select_gtl_5F_debugger_5F_parser_7>", "gtl_debugger_parser", 197}, // at index 70
 {"<select_gtl_5F_debugger_5F_parser_8>", "gtl_debugger_parser", 198}, // at index 71
 {"<select_gtl_5F_debugger_5F_parser_8>", "gtl_debugger_parser", 200}, // at index 72
 {"<select_gtl_5F_debugger_5F_parser_9>", "gtl_debugger_parser", 202}, // at index 73
 {"<select_gtl_5F_debugger_5F_parser_9>", "gtl_debugger_parser", 205}, // at index 74
 {"<select_gtl_5F_debugger_5F_parser_9>", "gtl_debugger_parser", 208}, // at index 75
 {"<select_gtl_5F_debugger_5F_parser_9>", "gtl_debugger_parser", 211}, // at index 76
 {"<select_gtl_5F_debugger_5F_parser_9>", "gtl_debugger_parser", 214}, // at index 77
 {"<select_gtl_5F_debugger_5F_parser_9>", "gtl_debugger_parser", 217}, // at index 78
 {"<select_gtl_5F_debugger_5F_parser_9>", "gtl_debugger_parser", 220}, // at index 79
 {"<select_gtl_5F_debugger_5F_parser_9>", "gtl_debugger_parser", 223}, // at index 80
 {"<select_gtl_5F_debugger_5F_parser_9>", "gtl_debugger_parser", 226}, // at index 81
 {"<select_gtl_5F_debugger_5F_parser_9>", "gtl_debugger_parser", 229}, // at index 82
 {"<select_gtl_5F_debugger_5F_parser_9>", "gtl_debugger_parser", 232}, // at index 83
 {"<select_gtl_5F_debugger_5F_parser_9>", "gtl_debugger_parser", 235}, // at index 84
 {"<select_gtl_5F_debugger_5F_parser_10>", "gtl_debugger_parser", 236}, // at index 85
 {"<select_gtl_5F_debugger_5F_parser_10>", "gtl_debugger_parser", 238}, // at index 86
 {"<select_gtl_5F_debugger_5F_parser_11>", "gtl_debugger_parser", 239}, // at index 87
 {"<select_gtl_5F_debugger_5F_parser_11>", "gtl_debugger_parser", 240}, // at index 88
 {"<select_gtl_5F_debugger_5F_parser_12>", "gtl_debugger_parser", 246}, // at index 89
 {"<select_gtl_5F_debugger_5F_parser_12>", "gtl_debugger_parser", 249}, // at index 90
 {"<select_gtl_5F_debugger_5F_parser_13>", "gtl_debugger_parser", 250}, // at index 91
 {"<select_gtl_5F_debugger_5F_parser_13>", "gtl_debugger_parser", 251}, // at index 92
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_0>", "gtl_debugger_expression_parser", 254}, // at index 93
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_0>", "gtl_debugger_expression_parser", 255}, // at index 94
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_0>", "gtl_debugger_expression_parser", 259}, // at index 95
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_1>", "gtl_debugger_expression_parser", 263}, // at index 96
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_1>", "gtl_debugger_expression_parser", 264}, // at index 97
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_2>", "gtl_debugger_expression_parser", 268}, // at index 98
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_2>", "gtl_debugger_expression_parser", 269}, // at index 99
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_2>", "gtl_debugger_expression_parser", 272}, // at index 100
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_2>", "gtl_debugger_expression_parser", 275}, // at index 101
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_2>", "gtl_debugger_expression_parser", 278}, // at index 102
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_2>", "gtl_debugger_expression_parser", 281}, // at index 103
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_2>", "gtl_debugger_expression_parser", 284}, // at index 104
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_3>", "gtl_debugger_expression_parser", 287}, // at index 105
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_3>", "gtl_debugger_expression_parser", 288}, // at index 106
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_3>", "gtl_debugger_expression_parser", 292}, // at index 107
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_3>", "gtl_debugger_expression_parser", 296}, // at index 108
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_3>", "gtl_debugger_expression_parser", 300}, // at index 109
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_3>", "gtl_debugger_expression_parser", 304}, // at index 110
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_4>", "gtl_debugger_expression_parser", 308}, // at index 111
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_4>", "gtl_debugger_expression_parser", 309}, // at index 112
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_4>", "gtl_debugger_expression_parser", 313}, // at index 113
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_4>", "gtl_debugger_expression_parser", 317}, // at index 114
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_5>", "gtl_debugger_expression_parser", 321}, // at index 115
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_5>", "gtl_debugger_expression_parser", 322}, // at index 116
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_6>", "gtl_debugger_expression_parser", 326}, // at index 117
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_6>", "gtl_debugger_expression_parser", 327}, // at index 118
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_7>", "gtl_debugger_expression_parser", 331}, // at index 119
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_7>", "gtl_debugger_expression_parser", 332}, // at index 120
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_8>", "gtl_debugger_expression_parser", 336}, // at index 121
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_8>", "gtl_debugger_expression_parser", 339}, // at index 122
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_9>", "gtl_debugger_expression_parser", 340}, // at index 123
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_9>", "gtl_debugger_expression_parser", 341}, // at index 124
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_10>", "gtl_debugger_expression_parser", 345}, // at index 125
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_10>", "gtl_debugger_expression_parser", 350}, // at index 126
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_11>", "gtl_debugger_expression_parser", 351}, // at index 127
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_11>", "gtl_debugger_expression_parser", 354}, // at index 128
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_12>", "gtl_debugger_expression_parser", 356}, // at index 129
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_12>", "gtl_debugger_expression_parser", 359}, // at index 130
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_13>", "gtl_debugger_expression_parser", 360}, // at index 131
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_13>", "gtl_debugger_expression_parser", 361}, // at index 132
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_14>", "gtl_debugger_expression_parser", 365}, // at index 133
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_14>", "gtl_debugger_expression_parser", 370}, // at index 134
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_15>", "gtl_debugger_expression_parser", 371}, // at index 135
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_15>", "gtl_debugger_expression_parser", 372}, // at index 136
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_16>", "gtl_debugger_expression_parser", 378}, // at index 137
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_16>", "gtl_debugger_expression_parser", 383}, // at index 138
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_17>", "gtl_debugger_expression_parser", 384}, // at index 139
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_17>", "gtl_debugger_expression_parser", 385}, // at index 140
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_18>", "gtl_debugger_expression_parser", 391}, // at index 141
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_18>", "gtl_debugger_expression_parser", 394}, // at index 142
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_19>", "gtl_debugger_expression_parser", 395}, // at index 143
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_19>", "gtl_debugger_expression_parser", 396}, // at index 144
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_20>", "gtl_debugger_expression_parser", 400}, // at index 145
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_20>", "gtl_debugger_expression_parser", 401}, // at index 146
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_21>", "gtl_debugger_expression_parser", 406}, // at index 147
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_21>", "gtl_debugger_expression_parser", 411}, // at index 148
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_22>", "gtl_debugger_expression_parser", 412}, // at index 149
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_22>", "gtl_debugger_expression_parser", 417}, // at index 150
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_23>", "gtl_debugger_expression_parser", 418}, // at index 151
 {"<select_gtl_5F_debugger_5F_expression_5F_parser_23>", "gtl_debugger_expression_parser", 419}, // at index 152
 {"<>", "", 424} // at index 153
} ;

//--------------------------------------------------------------------------------------------------
//
//                       L L ( 1 )    P R O D U C T I O N    I N D E X E S                          
//
//--------------------------------------------------------------------------------------------------

static const int32_t gProductionIndexes_gtl_debugger_grammar [154] = {
0, // index 0 : <gtl_expression>, in file 'gtl_debugger_expression_parser.ggs', line 33
3, // index 1 : <gtl_variable>, in file 'gtl_debugger_expression_parser.ggs', line 667
7, // index 2 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 37
9, // index 3 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 52
11, // index 4 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 63
13, // index 5 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 74
16, // index 6 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 92
18, // index 7 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 103
21, // index 8 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 169
24, // index 9 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 207
27, // index 10 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 244
28, // index 11 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 254
32, // index 12 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 368
35, // index 13 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 381
37, // index 14 : <gtl_step_do_command>, in file 'gtl_debugger_parser.ggs', line 388
39, // index 15 : <gtl_step_do_command>, in file 'gtl_debugger_parser.ggs', line 400
42, // index 16 : <gtl_step_do_command>, in file 'gtl_debugger_parser.ggs', line 413
45, // index 17 : <gtl_step_do_command>, in file 'gtl_debugger_parser.ggs', line 427
48, // index 18 : <gtl_step_do_command>, in file 'gtl_debugger_parser.ggs', line 448
57, // index 19 : <gtl_step_do_command_list>, in file 'gtl_debugger_parser.ggs', line 481
59, // index 20 : <gtl_relation_term>, in file 'gtl_debugger_expression_parser.ggs', line 53
62, // index 21 : <gtl_relation_factor>, in file 'gtl_debugger_expression_parser.ggs', line 69
65, // index 22 : <gtl_simple_expression>, in file 'gtl_debugger_expression_parser.ggs', line 117
68, // index 23 : <gtl_term>, in file 'gtl_debugger_expression_parser.ggs', line 162
71, // index 24 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 192
75, // index 25 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 208
78, // index 26 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 220
81, // index 27 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 232
84, // index 28 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 244
87, // index 29 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 256
89, // index 30 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 269
91, // index 31 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 282
93, // index 32 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 295
95, // index 33 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 308
97, // index 34 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 321
99, // index 35 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 335
105, // index 36 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 369
108, // index 37 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 401
112, // index 38 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 420
115, // index 39 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 429
117, // index 40 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 445
119, // index 41 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 461
121, // index 42 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 477
124, // index 43 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 514
126, // index 44 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 533
128, // index 45 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 552
132, // index 46 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 576
136, // index 47 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 587
140, // index 48 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 606
144, // index 49 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 627
148, // index 50 : <gtl_factor>, in file 'gtl_debugger_expression_parser.ggs', line 648
152, // index 51 : <select_gtl_5F_debugger_5F_parser_0>, in file 'gtl_debugger_parser.ggs', line 40
154, // index 52 : <select_gtl_5F_debugger_5F_parser_0>, in file 'gtl_debugger_parser.ggs', line 40
156, // index 53 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 79
158, // index 54 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 79
160, // index 55 : <select_gtl_5F_debugger_5F_parser_2>, in file 'gtl_debugger_parser.ggs', line 107
163, // index 56 : <select_gtl_5F_debugger_5F_parser_2>, in file 'gtl_debugger_parser.ggs', line 107
165, // index 57 : <select_gtl_5F_debugger_5F_parser_2>, in file 'gtl_debugger_parser.ggs', line 107
167, // index 58 : <select_gtl_5F_debugger_5F_parser_2>, in file 'gtl_debugger_parser.ggs', line 107
168, // index 59 : <select_gtl_5F_debugger_5F_parser_3>, in file 'gtl_debugger_parser.ggs', line 109
170, // index 60 : <select_gtl_5F_debugger_5F_parser_3>, in file 'gtl_debugger_parser.ggs', line 109
172, // index 61 : <select_gtl_5F_debugger_5F_parser_4>, in file 'gtl_debugger_parser.ggs', line 124
178, // index 62 : <select_gtl_5F_debugger_5F_parser_4>, in file 'gtl_debugger_parser.ggs', line 124
180, // index 63 : <select_gtl_5F_debugger_5F_parser_5>, in file 'gtl_debugger_parser.ggs', line 173
183, // index 64 : <select_gtl_5F_debugger_5F_parser_5>, in file 'gtl_debugger_parser.ggs', line 173
187, // index 65 : <select_gtl_5F_debugger_5F_parser_5>, in file 'gtl_debugger_parser.ggs', line 173
188, // index 66 : <select_gtl_5F_debugger_5F_parser_6>, in file 'gtl_debugger_parser.ggs', line 175
190, // index 67 : <select_gtl_5F_debugger_5F_parser_6>, in file 'gtl_debugger_parser.ggs', line 175
192, // index 68 : <select_gtl_5F_debugger_5F_parser_7>, in file 'gtl_debugger_parser.ggs', line 212
194, // index 69 : <select_gtl_5F_debugger_5F_parser_7>, in file 'gtl_debugger_parser.ggs', line 212
197, // index 70 : <select_gtl_5F_debugger_5F_parser_7>, in file 'gtl_debugger_parser.ggs', line 212
198, // index 71 : <select_gtl_5F_debugger_5F_parser_8>, in file 'gtl_debugger_parser.ggs', line 221
200, // index 72 : <select_gtl_5F_debugger_5F_parser_8>, in file 'gtl_debugger_parser.ggs', line 221
202, // index 73 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
205, // index 74 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
208, // index 75 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
211, // index 76 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
214, // index 77 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
217, // index 78 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
220, // index 79 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
223, // index 80 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
226, // index 81 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
229, // index 82 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
232, // index 83 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
235, // index 84 : <select_gtl_5F_debugger_5F_parser_9>, in file 'gtl_debugger_parser.ggs', line 259
236, // index 85 : <select_gtl_5F_debugger_5F_parser_10>, in file 'gtl_debugger_parser.ggs', line 432
238, // index 86 : <select_gtl_5F_debugger_5F_parser_10>, in file 'gtl_debugger_parser.ggs', line 432
239, // index 87 : <select_gtl_5F_debugger_5F_parser_11>, in file 'gtl_debugger_parser.ggs', line 455
240, // index 88 : <select_gtl_5F_debugger_5F_parser_11>, in file 'gtl_debugger_parser.ggs', line 455
246, // index 89 : <select_gtl_5F_debugger_5F_parser_12>, in file 'gtl_debugger_parser.ggs', line 465
249, // index 90 : <select_gtl_5F_debugger_5F_parser_12>, in file 'gtl_debugger_parser.ggs', line 465
250, // index 91 : <select_gtl_5F_debugger_5F_parser_13>, in file 'gtl_debugger_parser.ggs', line 486
251, // index 92 : <select_gtl_5F_debugger_5F_parser_13>, in file 'gtl_debugger_parser.ggs', line 486
254, // index 93 : <select_gtl_5F_debugger_5F_expression_5F_parser_0>, in file 'gtl_debugger_expression_parser.ggs', line 37
255, // index 94 : <select_gtl_5F_debugger_5F_expression_5F_parser_0>, in file 'gtl_debugger_expression_parser.ggs', line 37
259, // index 95 : <select_gtl_5F_debugger_5F_expression_5F_parser_0>, in file 'gtl_debugger_expression_parser.ggs', line 37
263, // index 96 : <select_gtl_5F_debugger_5F_expression_5F_parser_1>, in file 'gtl_debugger_expression_parser.ggs', line 57
264, // index 97 : <select_gtl_5F_debugger_5F_expression_5F_parser_1>, in file 'gtl_debugger_expression_parser.ggs', line 57
268, // index 98 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>, in file 'gtl_debugger_expression_parser.ggs', line 73
269, // index 99 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>, in file 'gtl_debugger_expression_parser.ggs', line 73
272, // index 100 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>, in file 'gtl_debugger_expression_parser.ggs', line 73
275, // index 101 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>, in file 'gtl_debugger_expression_parser.ggs', line 73
278, // index 102 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>, in file 'gtl_debugger_expression_parser.ggs', line 73
281, // index 103 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>, in file 'gtl_debugger_expression_parser.ggs', line 73
284, // index 104 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>, in file 'gtl_debugger_expression_parser.ggs', line 73
287, // index 105 : <select_gtl_5F_debugger_5F_expression_5F_parser_3>, in file 'gtl_debugger_expression_parser.ggs', line 121
288, // index 106 : <select_gtl_5F_debugger_5F_expression_5F_parser_3>, in file 'gtl_debugger_expression_parser.ggs', line 121
292, // index 107 : <select_gtl_5F_debugger_5F_expression_5F_parser_3>, in file 'gtl_debugger_expression_parser.ggs', line 121
296, // index 108 : <select_gtl_5F_debugger_5F_expression_5F_parser_3>, in file 'gtl_debugger_expression_parser.ggs', line 121
300, // index 109 : <select_gtl_5F_debugger_5F_expression_5F_parser_3>, in file 'gtl_debugger_expression_parser.ggs', line 121
304, // index 110 : <select_gtl_5F_debugger_5F_expression_5F_parser_3>, in file 'gtl_debugger_expression_parser.ggs', line 121
308, // index 111 : <select_gtl_5F_debugger_5F_expression_5F_parser_4>, in file 'gtl_debugger_expression_parser.ggs', line 166
309, // index 112 : <select_gtl_5F_debugger_5F_expression_5F_parser_4>, in file 'gtl_debugger_expression_parser.ggs', line 166
313, // index 113 : <select_gtl_5F_debugger_5F_expression_5F_parser_4>, in file 'gtl_debugger_expression_parser.ggs', line 166
317, // index 114 : <select_gtl_5F_debugger_5F_expression_5F_parser_4>, in file 'gtl_debugger_expression_parser.ggs', line 166
321, // index 115 : <select_gtl_5F_debugger_5F_expression_5F_parser_5>, in file 'gtl_debugger_expression_parser.ggs', line 348
322, // index 116 : <select_gtl_5F_debugger_5F_expression_5F_parser_5>, in file 'gtl_debugger_expression_parser.ggs', line 348
326, // index 117 : <select_gtl_5F_debugger_5F_expression_5F_parser_6>, in file 'gtl_debugger_expression_parser.ggs', line 351
327, // index 118 : <select_gtl_5F_debugger_5F_expression_5F_parser_6>, in file 'gtl_debugger_expression_parser.ggs', line 351
331, // index 119 : <select_gtl_5F_debugger_5F_expression_5F_parser_7>, in file 'gtl_debugger_expression_parser.ggs', line 373
332, // index 120 : <select_gtl_5F_debugger_5F_expression_5F_parser_7>, in file 'gtl_debugger_expression_parser.ggs', line 373
336, // index 121 : <select_gtl_5F_debugger_5F_expression_5F_parser_8>, in file 'gtl_debugger_expression_parser.ggs', line 381
339, // index 122 : <select_gtl_5F_debugger_5F_expression_5F_parser_8>, in file 'gtl_debugger_expression_parser.ggs', line 381
340, // index 123 : <select_gtl_5F_debugger_5F_expression_5F_parser_9>, in file 'gtl_debugger_expression_parser.ggs', line 382
341, // index 124 : <select_gtl_5F_debugger_5F_expression_5F_parser_9>, in file 'gtl_debugger_expression_parser.ggs', line 382
345, // index 125 : <select_gtl_5F_debugger_5F_expression_5F_parser_10>, in file 'gtl_debugger_expression_parser.ggs', line 405
350, // index 126 : <select_gtl_5F_debugger_5F_expression_5F_parser_10>, in file 'gtl_debugger_expression_parser.ggs', line 405
351, // index 127 : <select_gtl_5F_debugger_5F_expression_5F_parser_11>, in file 'gtl_debugger_expression_parser.ggs', line 557
354, // index 128 : <select_gtl_5F_debugger_5F_expression_5F_parser_11>, in file 'gtl_debugger_expression_parser.ggs', line 557
356, // index 129 : <select_gtl_5F_debugger_5F_expression_5F_parser_12>, in file 'gtl_debugger_expression_parser.ggs', line 592
359, // index 130 : <select_gtl_5F_debugger_5F_expression_5F_parser_12>, in file 'gtl_debugger_expression_parser.ggs', line 592
360, // index 131 : <select_gtl_5F_debugger_5F_expression_5F_parser_13>, in file 'gtl_debugger_expression_parser.ggs', line 593
361, // index 132 : <select_gtl_5F_debugger_5F_expression_5F_parser_13>, in file 'gtl_debugger_expression_parser.ggs', line 593
365, // index 133 : <select_gtl_5F_debugger_5F_expression_5F_parser_14>, in file 'gtl_debugger_expression_parser.ggs', line 611
370, // index 134 : <select_gtl_5F_debugger_5F_expression_5F_parser_14>, in file 'gtl_debugger_expression_parser.ggs', line 611
371, // index 135 : <select_gtl_5F_debugger_5F_expression_5F_parser_15>, in file 'gtl_debugger_expression_parser.ggs', line 612
372, // index 136 : <select_gtl_5F_debugger_5F_expression_5F_parser_15>, in file 'gtl_debugger_expression_parser.ggs', line 612
378, // index 137 : <select_gtl_5F_debugger_5F_expression_5F_parser_16>, in file 'gtl_debugger_expression_parser.ggs', line 632
383, // index 138 : <select_gtl_5F_debugger_5F_expression_5F_parser_16>, in file 'gtl_debugger_expression_parser.ggs', line 632
384, // index 139 : <select_gtl_5F_debugger_5F_expression_5F_parser_17>, in file 'gtl_debugger_expression_parser.ggs', line 633
385, // index 140 : <select_gtl_5F_debugger_5F_expression_5F_parser_17>, in file 'gtl_debugger_expression_parser.ggs', line 633
391, // index 141 : <select_gtl_5F_debugger_5F_expression_5F_parser_18>, in file 'gtl_debugger_expression_parser.ggs', line 653
394, // index 142 : <select_gtl_5F_debugger_5F_expression_5F_parser_18>, in file 'gtl_debugger_expression_parser.ggs', line 653
395, // index 143 : <select_gtl_5F_debugger_5F_expression_5F_parser_19>, in file 'gtl_debugger_expression_parser.ggs', line 654
396, // index 144 : <select_gtl_5F_debugger_5F_expression_5F_parser_19>, in file 'gtl_debugger_expression_parser.ggs', line 654
400, // index 145 : <select_gtl_5F_debugger_5F_expression_5F_parser_20>, in file 'gtl_debugger_expression_parser.ggs', line 671
401, // index 146 : <select_gtl_5F_debugger_5F_expression_5F_parser_20>, in file 'gtl_debugger_expression_parser.ggs', line 671
406, // index 147 : <select_gtl_5F_debugger_5F_expression_5F_parser_21>, in file 'gtl_debugger_expression_parser.ggs', line 673
411, // index 148 : <select_gtl_5F_debugger_5F_expression_5F_parser_21>, in file 'gtl_debugger_expression_parser.ggs', line 673
412, // index 149 : <select_gtl_5F_debugger_5F_expression_5F_parser_22>, in file 'gtl_debugger_expression_parser.ggs', line 678
417, // index 150 : <select_gtl_5F_debugger_5F_expression_5F_parser_22>, in file 'gtl_debugger_expression_parser.ggs', line 678
418, // index 151 : <select_gtl_5F_debugger_5F_expression_5F_parser_23>, in file 'gtl_debugger_expression_parser.ggs', line 683
419, // index 152 : <select_gtl_5F_debugger_5F_expression_5F_parser_23>, in file 'gtl_debugger_expression_parser.ggs', line 683
424 // index 153 : <>, in file '.ggs', line 0
} ;

//--------------------------------------------------------------------------------------------------
//
//                 L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                   
//
//--------------------------------------------------------------------------------------------------

static const int32_t gFirstProductionIndexes_gtl_debugger_grammar [50] = {
0, // at 0 : <gtl_expression>
1, // at 1 : <gtl_variable>
2, // at 2 : <gtl_debugger_command>
14, // at 3 : <gtl_step_do_command>
19, // at 4 : <gtl_step_do_command_list>
20, // at 5 : <gtl_relation_term>
21, // at 6 : <gtl_relation_factor>
22, // at 7 : <gtl_simple_expression>
23, // at 8 : <gtl_term>
24, // at 9 : <gtl_factor>
51, // at 10 : <select_gtl_5F_debugger_5F_parser_0>
53, // at 11 : <select_gtl_5F_debugger_5F_parser_1>
55, // at 12 : <select_gtl_5F_debugger_5F_parser_2>
59, // at 13 : <select_gtl_5F_debugger_5F_parser_3>
61, // at 14 : <select_gtl_5F_debugger_5F_parser_4>
63, // at 15 : <select_gtl_5F_debugger_5F_parser_5>
66, // at 16 : <select_gtl_5F_debugger_5F_parser_6>
68, // at 17 : <select_gtl_5F_debugger_5F_parser_7>
71, // at 18 : <select_gtl_5F_debugger_5F_parser_8>
73, // at 19 : <select_gtl_5F_debugger_5F_parser_9>
85, // at 20 : <select_gtl_5F_debugger_5F_parser_10>
87, // at 21 : <select_gtl_5F_debugger_5F_parser_11>
89, // at 22 : <select_gtl_5F_debugger_5F_parser_12>
91, // at 23 : <select_gtl_5F_debugger_5F_parser_13>
93, // at 24 : <select_gtl_5F_debugger_5F_expression_5F_parser_0>
96, // at 25 : <select_gtl_5F_debugger_5F_expression_5F_parser_1>
98, // at 26 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>
105, // at 27 : <select_gtl_5F_debugger_5F_expression_5F_parser_3>
111, // at 28 : <select_gtl_5F_debugger_5F_expression_5F_parser_4>
115, // at 29 : <select_gtl_5F_debugger_5F_expression_5F_parser_5>
117, // at 30 : <select_gtl_5F_debugger_5F_expression_5F_parser_6>
119, // at 31 : <select_gtl_5F_debugger_5F_expression_5F_parser_7>
121, // at 32 : <select_gtl_5F_debugger_5F_expression_5F_parser_8>
123, // at 33 : <select_gtl_5F_debugger_5F_expression_5F_parser_9>
125, // at 34 : <select_gtl_5F_debugger_5F_expression_5F_parser_10>
127, // at 35 : <select_gtl_5F_debugger_5F_expression_5F_parser_11>
129, // at 36 : <select_gtl_5F_debugger_5F_expression_5F_parser_12>
131, // at 37 : <select_gtl_5F_debugger_5F_expression_5F_parser_13>
133, // at 38 : <select_gtl_5F_debugger_5F_expression_5F_parser_14>
135, // at 39 : <select_gtl_5F_debugger_5F_expression_5F_parser_15>
137, // at 40 : <select_gtl_5F_debugger_5F_expression_5F_parser_16>
139, // at 41 : <select_gtl_5F_debugger_5F_expression_5F_parser_17>
141, // at 42 : <select_gtl_5F_debugger_5F_expression_5F_parser_18>
143, // at 43 : <select_gtl_5F_debugger_5F_expression_5F_parser_19>
145, // at 44 : <select_gtl_5F_debugger_5F_expression_5F_parser_20>
147, // at 45 : <select_gtl_5F_debugger_5F_expression_5F_parser_21>
149, // at 46 : <select_gtl_5F_debugger_5F_expression_5F_parser_22>
151, // at 47 : <select_gtl_5F_debugger_5F_expression_5F_parser_23>
153, // at 48 : <>
0} ;

//--------------------------------------------------------------------------------------------------
//
//                          L L ( 1 )    D E C I S I O N    T A B L E S                             
//
//--------------------------------------------------------------------------------------------------

static const int32_t gDecision_gtl_debugger_grammar [] = {
// At index 0 : <gtl_expression> only one production, no choice
  -1,
// At index 1 : <gtl_variable> only one production, no choice
  -1,
// At index 2 : <gtl_debugger_command>
Lexique_gtl_5F_debugger_5F_scanner::kToken_cont, Lexique_gtl_5F_debugger_5F_scanner::kToken_continue, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_help, -1, // Choice 2
Lexique_gtl_5F_debugger_5F_scanner::kToken_step, -1, // Choice 3
Lexique_gtl_5F_debugger_5F_scanner::kToken_load, -1, // Choice 4
Lexique_gtl_5F_debugger_5F_scanner::kToken_hist, -1, // Choice 5
Lexique_gtl_5F_debugger_5F_scanner::kToken_break, -1, // Choice 6
Lexique_gtl_5F_debugger_5F_scanner::kToken_watch, -1, // Choice 7
Lexique_gtl_5F_debugger_5F_scanner::kToken_do, -1, // Choice 8
Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 9
Lexique_gtl_5F_debugger_5F_scanner::kToken_let, -1, // Choice 10
Lexique_gtl_5F_debugger_5F_scanner::kToken_unlet, -1, // Choice 11
Lexique_gtl_5F_debugger_5F_scanner::kToken_variables, Lexique_gtl_5F_debugger_5F_scanner::kToken_display, Lexique_gtl_5F_debugger_5F_scanner::kToken_print, Lexique_gtl_5F_debugger_5F_scanner::kToken_list, Lexique_gtl_5F_debugger_5F_scanner::kToken_if, -1, // Choice 12
  -1,
// At index 32 : <gtl_step_do_command>
Lexique_gtl_5F_debugger_5F_scanner::kToken_variables, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_display, -1, // Choice 2
Lexique_gtl_5F_debugger_5F_scanner::kToken_print, -1, // Choice 3
Lexique_gtl_5F_debugger_5F_scanner::kToken_list, -1, // Choice 4
Lexique_gtl_5F_debugger_5F_scanner::kToken_if, -1, // Choice 5
  -1,
// At index 43 : <gtl_step_do_command_list> only one production, no choice
  -1,
// At index 44 : <gtl_relation_term> only one production, no choice
  -1,
// At index 45 : <gtl_relation_factor> only one production, no choice
  -1,
// At index 46 : <gtl_simple_expression> only one production, no choice
  -1,
// At index 47 : <gtl_term> only one production, no choice
  -1,
// At index 48 : <gtl_factor>
Lexique_gtl_5F_debugger_5F_scanner::kToken__28_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_not, -1, // Choice 2
Lexique_gtl_5F_debugger_5F_scanner::kToken__7E_, -1, // Choice 3
Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_, -1, // Choice 4
Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_, -1, // Choice 5
Lexique_gtl_5F_debugger_5F_scanner::kToken_yes, -1, // Choice 6
Lexique_gtl_5F_debugger_5F_scanner::kToken_no, -1, // Choice 7
Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, -1, // Choice 8
Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_double, -1, // Choice 9
Lexique_gtl_5F_debugger_5F_scanner::kToken_string, -1, // Choice 10
Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_char, -1, // Choice 11
Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_, -1, // Choice 12
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, -1, // Choice 13
Lexique_gtl_5F_debugger_5F_scanner::kToken_exists, -1, // Choice 14
Lexique_gtl_5F_debugger_5F_scanner::kToken_typeof, -1, // Choice 15
Lexique_gtl_5F_debugger_5F_scanner::kToken_true, -1, // Choice 16
Lexique_gtl_5F_debugger_5F_scanner::kToken_false, -1, // Choice 17
Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_enum, -1, // Choice 18
Lexique_gtl_5F_debugger_5F_scanner::kToken__40_, -1, // Choice 19
Lexique_gtl_5F_debugger_5F_scanner::kToken_emptylist, -1, // Choice 20
Lexique_gtl_5F_debugger_5F_scanner::kToken_emptymap, -1, // Choice 21
Lexique_gtl_5F_debugger_5F_scanner::kToken_mapof, -1, // Choice 22
Lexique_gtl_5F_debugger_5F_scanner::kToken_listof, -1, // Choice 23
Lexique_gtl_5F_debugger_5F_scanner::kToken__40__28_, -1, // Choice 24
Lexique_gtl_5F_debugger_5F_scanner::kToken__40__5B_, -1, // Choice 25
Lexique_gtl_5F_debugger_5F_scanner::kToken__40__7B_, -1, // Choice 26
Lexique_gtl_5F_debugger_5F_scanner::kToken__40__21_, -1, // Choice 27
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 103 : <select_gtl_5F_debugger_5F_parser_0>
Lexique_gtl_5F_debugger_5F_scanner::kToken_cont, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_continue, -1, // Choice 2
  -1,
// At index 108 : <select_gtl_5F_debugger_5F_parser_1>
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_string, -1, // Choice 2
  -1,
// At index 113 : <select_gtl_5F_debugger_5F_parser_2>
Lexique_gtl_5F_debugger_5F_scanner::kToken_not, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, -1, // Choice 2
Lexique_gtl_5F_debugger_5F_scanner::kToken_string, -1, // Choice 3
Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 4
  -1,
// At index 123 : <select_gtl_5F_debugger_5F_parser_3>
Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_all, -1, // Choice 2
  -1,
// At index 128 : <select_gtl_5F_debugger_5F_parser_4>
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, -1, // Choice 2
  -1,
// At index 133 : <select_gtl_5F_debugger_5F_parser_5>
Lexique_gtl_5F_debugger_5F_scanner::kToken_not, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__28_, -1, // Choice 2
Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 3
  -1,
// At index 140 : <select_gtl_5F_debugger_5F_parser_6>
Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_all, -1, // Choice 2
  -1,
// At index 145 : <select_gtl_5F_debugger_5F_parser_7>
Lexique_gtl_5F_debugger_5F_scanner::kToken_variables, Lexique_gtl_5F_debugger_5F_scanner::kToken_display, Lexique_gtl_5F_debugger_5F_scanner::kToken_print, Lexique_gtl_5F_debugger_5F_scanner::kToken_list, Lexique_gtl_5F_debugger_5F_scanner::kToken_if, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_not, -1, // Choice 2
Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 3
  -1,
// At index 156 : <select_gtl_5F_debugger_5F_parser_8>
Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_all, -1, // Choice 2
  -1,
// At index 161 : <select_gtl_5F_debugger_5F_parser_9>
Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3D_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__2B__3D_, -1, // Choice 2
Lexique_gtl_5F_debugger_5F_scanner::kToken__2D__3D_, -1, // Choice 3
Lexique_gtl_5F_debugger_5F_scanner::kToken__2A__3D_, -1, // Choice 4
Lexique_gtl_5F_debugger_5F_scanner::kToken__2F__3D_, -1, // Choice 5
Lexique_gtl_5F_debugger_5F_scanner::kToken_mod_3D_, -1, // Choice 6
Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C__3D_, -1, // Choice 7
Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E__3D_, -1, // Choice 8
Lexique_gtl_5F_debugger_5F_scanner::kToken__26__3D_, -1, // Choice 9
Lexique_gtl_5F_debugger_5F_scanner::kToken__7C__3D_, -1, // Choice 10
Lexique_gtl_5F_debugger_5F_scanner::kToken__5E__3D_, -1, // Choice 11
Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 12
  -1,
// At index 186 : <select_gtl_5F_debugger_5F_parser_10>
Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_variables, Lexique_gtl_5F_debugger_5F_scanner::kToken_display, Lexique_gtl_5F_debugger_5F_scanner::kToken_print, Lexique_gtl_5F_debugger_5F_scanner::kToken_list, Lexique_gtl_5F_debugger_5F_scanner::kToken_if, Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif, Lexique_gtl_5F_debugger_5F_scanner::kToken_else, Lexique_gtl_5F_debugger_5F_scanner::kToken_end, Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 199 : <select_gtl_5F_debugger_5F_parser_11>
Lexique_gtl_5F_debugger_5F_scanner::kToken_else, Lexique_gtl_5F_debugger_5F_scanner::kToken_end, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif, -1, // Choice 2
  -1,
// At index 205 : <select_gtl_5F_debugger_5F_parser_12>
Lexique_gtl_5F_debugger_5F_scanner::kToken_else, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 210 : <select_gtl_5F_debugger_5F_parser_13>
Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif, Lexique_gtl_5F_debugger_5F_scanner::kToken_else, Lexique_gtl_5F_debugger_5F_scanner::kToken_end, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_variables, Lexique_gtl_5F_debugger_5F_scanner::kToken_display, Lexique_gtl_5F_debugger_5F_scanner::kToken_print, Lexique_gtl_5F_debugger_5F_scanner::kToken_list, Lexique_gtl_5F_debugger_5F_scanner::kToken_if, -1, // Choice 2
  -1,
// At index 221 : <select_gtl_5F_debugger_5F_expression_5F_parser_0>
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, Lexique_gtl_5F_debugger_5F_scanner::kToken__29_, Lexique_gtl_5F_debugger_5F_scanner::kToken_variables, Lexique_gtl_5F_debugger_5F_scanner::kToken_display, Lexique_gtl_5F_debugger_5F_scanner::kToken_print, Lexique_gtl_5F_debugger_5F_scanner::kToken_list, Lexique_gtl_5F_debugger_5F_scanner::kToken_if, Lexique_gtl_5F_debugger_5F_scanner::kToken_then, Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif, Lexique_gtl_5F_debugger_5F_scanner::kToken_else, Lexique_gtl_5F_debugger_5F_scanner::kToken_end, Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_by, Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21_, Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__7C_, -1, // Choice 2
Lexique_gtl_5F_debugger_5F_scanner::kToken__5E_, -1, // Choice 3
  -1,
// At index 244 : <select_gtl_5F_debugger_5F_expression_5F_parser_1>
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, Lexique_gtl_5F_debugger_5F_scanner::kToken__29_, Lexique_gtl_5F_debugger_5F_scanner::kToken_variables, Lexique_gtl_5F_debugger_5F_scanner::kToken_display, Lexique_gtl_5F_debugger_5F_scanner::kToken_print, Lexique_gtl_5F_debugger_5F_scanner::kToken_list, Lexique_gtl_5F_debugger_5F_scanner::kToken_if, Lexique_gtl_5F_debugger_5F_scanner::kToken_then, Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif, Lexique_gtl_5F_debugger_5F_scanner::kToken_else, Lexique_gtl_5F_debugger_5F_scanner::kToken_end, Lexique_gtl_5F_debugger_5F_scanner::kToken__7C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_by, Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21_, Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__26_, -1, // Choice 2
  -1,
// At index 267 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, Lexique_gtl_5F_debugger_5F_scanner::kToken__29_, Lexique_gtl_5F_debugger_5F_scanner::kToken_variables, Lexique_gtl_5F_debugger_5F_scanner::kToken_display, Lexique_gtl_5F_debugger_5F_scanner::kToken_print, Lexique_gtl_5F_debugger_5F_scanner::kToken_list, Lexique_gtl_5F_debugger_5F_scanner::kToken_if, Lexique_gtl_5F_debugger_5F_scanner::kToken_then, Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif, Lexique_gtl_5F_debugger_5F_scanner::kToken_else, Lexique_gtl_5F_debugger_5F_scanner::kToken_end, Lexique_gtl_5F_debugger_5F_scanner::kToken__7C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__26_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_by, Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21_, Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__3D__3D_, -1, // Choice 2
Lexique_gtl_5F_debugger_5F_scanner::kToken__21__3D_, -1, // Choice 3
Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3D_, -1, // Choice 4
Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3D_, -1, // Choice 5
Lexique_gtl_5F_debugger_5F_scanner::kToken__3E_, -1, // Choice 6
Lexique_gtl_5F_debugger_5F_scanner::kToken__3C_, -1, // Choice 7
  -1,
// At index 301 : <select_gtl_5F_debugger_5F_expression_5F_parser_3>
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, Lexique_gtl_5F_debugger_5F_scanner::kToken__29_, Lexique_gtl_5F_debugger_5F_scanner::kToken_variables, Lexique_gtl_5F_debugger_5F_scanner::kToken_display, Lexique_gtl_5F_debugger_5F_scanner::kToken_print, Lexique_gtl_5F_debugger_5F_scanner::kToken_list, Lexique_gtl_5F_debugger_5F_scanner::kToken_if, Lexique_gtl_5F_debugger_5F_scanner::kToken_then, Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif, Lexique_gtl_5F_debugger_5F_scanner::kToken_else, Lexique_gtl_5F_debugger_5F_scanner::kToken_end, Lexique_gtl_5F_debugger_5F_scanner::kToken__7C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__26_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3D__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_by, Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21_, Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C_, -1, // Choice 2
Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E_, -1, // Choice 3
Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_, -1, // Choice 4
Lexique_gtl_5F_debugger_5F_scanner::kToken__2E_, -1, // Choice 5
Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_, -1, // Choice 6
  -1,
// At index 339 : <select_gtl_5F_debugger_5F_expression_5F_parser_4>
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, Lexique_gtl_5F_debugger_5F_scanner::kToken__2E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__29_, Lexique_gtl_5F_debugger_5F_scanner::kToken_variables, Lexique_gtl_5F_debugger_5F_scanner::kToken_display, Lexique_gtl_5F_debugger_5F_scanner::kToken_print, Lexique_gtl_5F_debugger_5F_scanner::kToken_list, Lexique_gtl_5F_debugger_5F_scanner::kToken_if, Lexique_gtl_5F_debugger_5F_scanner::kToken_then, Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif, Lexique_gtl_5F_debugger_5F_scanner::kToken_else, Lexique_gtl_5F_debugger_5F_scanner::kToken_end, Lexique_gtl_5F_debugger_5F_scanner::kToken__7C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__26_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3D__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_by, Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21_, Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__2A_, -1, // Choice 2
Lexique_gtl_5F_debugger_5F_scanner::kToken__2F_, -1, // Choice 3
Lexique_gtl_5F_debugger_5F_scanner::kToken_mod, -1, // Choice 4
  -1,
// At index 378 : <select_gtl_5F_debugger_5F_expression_5F_parser_5>
Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__3A_, -1, // Choice 2
  -1,
// At index 383 : <select_gtl_5F_debugger_5F_expression_5F_parser_6>
Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 388 : <select_gtl_5F_debugger_5F_expression_5F_parser_7>
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, Lexique_gtl_5F_debugger_5F_scanner::kToken__2E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__29_, Lexique_gtl_5F_debugger_5F_scanner::kToken_variables, Lexique_gtl_5F_debugger_5F_scanner::kToken_display, Lexique_gtl_5F_debugger_5F_scanner::kToken_print, Lexique_gtl_5F_debugger_5F_scanner::kToken_list, Lexique_gtl_5F_debugger_5F_scanner::kToken_if, Lexique_gtl_5F_debugger_5F_scanner::kToken_then, Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif, Lexique_gtl_5F_debugger_5F_scanner::kToken_else, Lexique_gtl_5F_debugger_5F_scanner::kToken_end, Lexique_gtl_5F_debugger_5F_scanner::kToken__7C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__26_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3D__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2A_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2F_, Lexique_gtl_5F_debugger_5F_scanner::kToken_mod, Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_by, Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21_, Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__28_, -1, // Choice 2
  -1,
// At index 426 : <select_gtl_5F_debugger_5F_expression_5F_parser_8>
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, Lexique_gtl_5F_debugger_5F_scanner::kToken_string, Lexique_gtl_5F_debugger_5F_scanner::kToken_not, Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, Lexique_gtl_5F_debugger_5F_scanner::kToken__28_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__7E_, Lexique_gtl_5F_debugger_5F_scanner::kToken_yes, Lexique_gtl_5F_debugger_5F_scanner::kToken_no, Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_double, Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_char, Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_, Lexique_gtl_5F_debugger_5F_scanner::kToken_exists, Lexique_gtl_5F_debugger_5F_scanner::kToken_typeof, Lexique_gtl_5F_debugger_5F_scanner::kToken_true, Lexique_gtl_5F_debugger_5F_scanner::kToken_false, Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_enum, Lexique_gtl_5F_debugger_5F_scanner::kToken__40_, Lexique_gtl_5F_debugger_5F_scanner::kToken_emptylist, Lexique_gtl_5F_debugger_5F_scanner::kToken_emptymap, Lexique_gtl_5F_debugger_5F_scanner::kToken_mapof, Lexique_gtl_5F_debugger_5F_scanner::kToken_listof, Lexique_gtl_5F_debugger_5F_scanner::kToken__40__28_, Lexique_gtl_5F_debugger_5F_scanner::kToken__40__5B_, Lexique_gtl_5F_debugger_5F_scanner::kToken__40__7B_, Lexique_gtl_5F_debugger_5F_scanner::kToken__40__21_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 457 : <select_gtl_5F_debugger_5F_expression_5F_parser_9>
Lexique_gtl_5F_debugger_5F_scanner::kToken__29_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 462 : <select_gtl_5F_debugger_5F_expression_5F_parser_10>
Lexique_gtl_5F_debugger_5F_scanner::kToken_default, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, Lexique_gtl_5F_debugger_5F_scanner::kToken__2E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__29_, Lexique_gtl_5F_debugger_5F_scanner::kToken_variables, Lexique_gtl_5F_debugger_5F_scanner::kToken_display, Lexique_gtl_5F_debugger_5F_scanner::kToken_print, Lexique_gtl_5F_debugger_5F_scanner::kToken_list, Lexique_gtl_5F_debugger_5F_scanner::kToken_if, Lexique_gtl_5F_debugger_5F_scanner::kToken_then, Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif, Lexique_gtl_5F_debugger_5F_scanner::kToken_else, Lexique_gtl_5F_debugger_5F_scanner::kToken_end, Lexique_gtl_5F_debugger_5F_scanner::kToken__7C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__26_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3D__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2A_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2F_, Lexique_gtl_5F_debugger_5F_scanner::kToken_mod, Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_by, Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21_, Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 500 : <select_gtl_5F_debugger_5F_expression_5F_parser_11>
Lexique_gtl_5F_debugger_5F_scanner::kToken_by, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 505 : <select_gtl_5F_debugger_5F_expression_5F_parser_12>
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, Lexique_gtl_5F_debugger_5F_scanner::kToken_string, Lexique_gtl_5F_debugger_5F_scanner::kToken_not, Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, Lexique_gtl_5F_debugger_5F_scanner::kToken__28_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__7E_, Lexique_gtl_5F_debugger_5F_scanner::kToken_yes, Lexique_gtl_5F_debugger_5F_scanner::kToken_no, Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_double, Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_char, Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_, Lexique_gtl_5F_debugger_5F_scanner::kToken_exists, Lexique_gtl_5F_debugger_5F_scanner::kToken_typeof, Lexique_gtl_5F_debugger_5F_scanner::kToken_true, Lexique_gtl_5F_debugger_5F_scanner::kToken_false, Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_enum, Lexique_gtl_5F_debugger_5F_scanner::kToken__40_, Lexique_gtl_5F_debugger_5F_scanner::kToken_emptylist, Lexique_gtl_5F_debugger_5F_scanner::kToken_emptymap, Lexique_gtl_5F_debugger_5F_scanner::kToken_mapof, Lexique_gtl_5F_debugger_5F_scanner::kToken_listof, Lexique_gtl_5F_debugger_5F_scanner::kToken__40__28_, Lexique_gtl_5F_debugger_5F_scanner::kToken__40__5B_, Lexique_gtl_5F_debugger_5F_scanner::kToken__40__7B_, Lexique_gtl_5F_debugger_5F_scanner::kToken__40__21_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 536 : <select_gtl_5F_debugger_5F_expression_5F_parser_13>
Lexique_gtl_5F_debugger_5F_scanner::kToken__29_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 541 : <select_gtl_5F_debugger_5F_expression_5F_parser_14>
Lexique_gtl_5F_debugger_5F_scanner::kToken_string, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_, -1, // Choice 2
  -1,
// At index 546 : <select_gtl_5F_debugger_5F_expression_5F_parser_15>
Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 551 : <select_gtl_5F_debugger_5F_expression_5F_parser_16>
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_, -1, // Choice 2
  -1,
// At index 556 : <select_gtl_5F_debugger_5F_expression_5F_parser_17>
Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 561 : <select_gtl_5F_debugger_5F_expression_5F_parser_18>
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, Lexique_gtl_5F_debugger_5F_scanner::kToken_string, Lexique_gtl_5F_debugger_5F_scanner::kToken_not, Lexique_gtl_5F_debugger_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, Lexique_gtl_5F_debugger_5F_scanner::kToken__28_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__7E_, Lexique_gtl_5F_debugger_5F_scanner::kToken_yes, Lexique_gtl_5F_debugger_5F_scanner::kToken_no, Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_double, Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_char, Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_, Lexique_gtl_5F_debugger_5F_scanner::kToken_exists, Lexique_gtl_5F_debugger_5F_scanner::kToken_typeof, Lexique_gtl_5F_debugger_5F_scanner::kToken_true, Lexique_gtl_5F_debugger_5F_scanner::kToken_false, Lexique_gtl_5F_debugger_5F_scanner::kToken_literal_5F_enum, Lexique_gtl_5F_debugger_5F_scanner::kToken__40_, Lexique_gtl_5F_debugger_5F_scanner::kToken_emptylist, Lexique_gtl_5F_debugger_5F_scanner::kToken_emptymap, Lexique_gtl_5F_debugger_5F_scanner::kToken_mapof, Lexique_gtl_5F_debugger_5F_scanner::kToken_listof, Lexique_gtl_5F_debugger_5F_scanner::kToken__40__28_, Lexique_gtl_5F_debugger_5F_scanner::kToken__40__5B_, Lexique_gtl_5F_debugger_5F_scanner::kToken__40__7B_, Lexique_gtl_5F_debugger_5F_scanner::kToken__40__21_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__21_, -1, // Choice 2
  -1,
// At index 592 : <select_gtl_5F_debugger_5F_expression_5F_parser_19>
Lexique_gtl_5F_debugger_5F_scanner::kToken__21_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 597 : <select_gtl_5F_debugger_5F_expression_5F_parser_20>
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, Lexique_gtl_5F_debugger_5F_scanner::kToken__2E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__28_, Lexique_gtl_5F_debugger_5F_scanner::kToken__29_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2B__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2D__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2A__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2F__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_mod_3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__26__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__7C__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5E__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_variables, Lexique_gtl_5F_debugger_5F_scanner::kToken_display, Lexique_gtl_5F_debugger_5F_scanner::kToken_print, Lexique_gtl_5F_debugger_5F_scanner::kToken_list, Lexique_gtl_5F_debugger_5F_scanner::kToken_if, Lexique_gtl_5F_debugger_5F_scanner::kToken_then, Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif, Lexique_gtl_5F_debugger_5F_scanner::kToken_else, Lexique_gtl_5F_debugger_5F_scanner::kToken_end, Lexique_gtl_5F_debugger_5F_scanner::kToken__7C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__26_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3D__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2A_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2F_, Lexique_gtl_5F_debugger_5F_scanner::kToken_mod, Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_default, Lexique_gtl_5F_debugger_5F_scanner::kToken_by, Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21_, Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3A_, -1, // Choice 2
  -1,
// At index 648 : <select_gtl_5F_debugger_5F_expression_5F_parser_21>
Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, Lexique_gtl_5F_debugger_5F_scanner::kToken__2E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__28_, Lexique_gtl_5F_debugger_5F_scanner::kToken__29_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2B__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2D__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2A__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2F__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_mod_3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__26__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__7C__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5E__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_variables, Lexique_gtl_5F_debugger_5F_scanner::kToken_display, Lexique_gtl_5F_debugger_5F_scanner::kToken_print, Lexique_gtl_5F_debugger_5F_scanner::kToken_list, Lexique_gtl_5F_debugger_5F_scanner::kToken_if, Lexique_gtl_5F_debugger_5F_scanner::kToken_then, Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif, Lexique_gtl_5F_debugger_5F_scanner::kToken_else, Lexique_gtl_5F_debugger_5F_scanner::kToken_end, Lexique_gtl_5F_debugger_5F_scanner::kToken__7C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__26_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3D__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2A_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2F_, Lexique_gtl_5F_debugger_5F_scanner::kToken_mod, Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_default, Lexique_gtl_5F_debugger_5F_scanner::kToken_by, Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3A_, Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 700 : <select_gtl_5F_debugger_5F_expression_5F_parser_22>
Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, Lexique_gtl_5F_debugger_5F_scanner::kToken__2E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__28_, Lexique_gtl_5F_debugger_5F_scanner::kToken__29_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2B__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2D__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2A__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2F__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_mod_3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__26__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__7C__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5E__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_variables, Lexique_gtl_5F_debugger_5F_scanner::kToken_display, Lexique_gtl_5F_debugger_5F_scanner::kToken_print, Lexique_gtl_5F_debugger_5F_scanner::kToken_list, Lexique_gtl_5F_debugger_5F_scanner::kToken_if, Lexique_gtl_5F_debugger_5F_scanner::kToken_then, Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif, Lexique_gtl_5F_debugger_5F_scanner::kToken_else, Lexique_gtl_5F_debugger_5F_scanner::kToken_end, Lexique_gtl_5F_debugger_5F_scanner::kToken__7C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__26_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3D__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2A_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2F_, Lexique_gtl_5F_debugger_5F_scanner::kToken_mod, Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_default, Lexique_gtl_5F_debugger_5F_scanner::kToken_by, Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3A_, Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 752 : <select_gtl_5F_debugger_5F_expression_5F_parser_23>
Lexique_gtl_5F_debugger_5F_scanner::kToken_identifier, Lexique_gtl_5F_debugger_5F_scanner::kToken__2E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__28_, Lexique_gtl_5F_debugger_5F_scanner::kToken__29_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2B__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2D__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2A__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2F__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_mod_3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__26__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__7C__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5E__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_variables, Lexique_gtl_5F_debugger_5F_scanner::kToken_display, Lexique_gtl_5F_debugger_5F_scanner::kToken_print, Lexique_gtl_5F_debugger_5F_scanner::kToken_list, Lexique_gtl_5F_debugger_5F_scanner::kToken_if, Lexique_gtl_5F_debugger_5F_scanner::kToken_then, Lexique_gtl_5F_debugger_5F_scanner::kToken_elsif, Lexique_gtl_5F_debugger_5F_scanner::kToken_else, Lexique_gtl_5F_debugger_5F_scanner::kToken_end, Lexique_gtl_5F_debugger_5F_scanner::kToken__7C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__26_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3D__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3C__3C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3E__3E_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2B_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2A_, Lexique_gtl_5F_debugger_5F_scanner::kToken__2F_, Lexique_gtl_5F_debugger_5F_scanner::kToken_mod, Lexique_gtl_5F_debugger_5F_scanner::kToken__2C_, Lexique_gtl_5F_debugger_5F_scanner::kToken__5D_, Lexique_gtl_5F_debugger_5F_scanner::kToken_default, Lexique_gtl_5F_debugger_5F_scanner::kToken_by, Lexique_gtl_5F_debugger_5F_scanner::kToken__7D_, Lexique_gtl_5F_debugger_5F_scanner::kToken__21_, Lexique_gtl_5F_debugger_5F_scanner::kToken__3A__3A_, Lexique_gtl_5F_debugger_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_debugger_5F_scanner::kToken__5B_, -1, // Choice 2
  -1,
// At index 804 : <> only one production, no choice
  -1,
0} ;

//--------------------------------------------------------------------------------------------------
//
//                  L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                    
//
//--------------------------------------------------------------------------------------------------

static const int32_t gDecisionIndexes_gtl_debugger_grammar [50] = {
0, // at 0 : <gtl_expression>
1, // at 1 : <gtl_variable>
2, // at 2 : <gtl_debugger_command>
32, // at 3 : <gtl_step_do_command>
43, // at 4 : <gtl_step_do_command_list>
44, // at 5 : <gtl_relation_term>
45, // at 6 : <gtl_relation_factor>
46, // at 7 : <gtl_simple_expression>
47, // at 8 : <gtl_term>
48, // at 9 : <gtl_factor>
103, // at 10 : <select_gtl_5F_debugger_5F_parser_0>
108, // at 11 : <select_gtl_5F_debugger_5F_parser_1>
113, // at 12 : <select_gtl_5F_debugger_5F_parser_2>
123, // at 13 : <select_gtl_5F_debugger_5F_parser_3>
128, // at 14 : <select_gtl_5F_debugger_5F_parser_4>
133, // at 15 : <select_gtl_5F_debugger_5F_parser_5>
140, // at 16 : <select_gtl_5F_debugger_5F_parser_6>
145, // at 17 : <select_gtl_5F_debugger_5F_parser_7>
156, // at 18 : <select_gtl_5F_debugger_5F_parser_8>
161, // at 19 : <select_gtl_5F_debugger_5F_parser_9>
186, // at 20 : <select_gtl_5F_debugger_5F_parser_10>
199, // at 21 : <select_gtl_5F_debugger_5F_parser_11>
205, // at 22 : <select_gtl_5F_debugger_5F_parser_12>
210, // at 23 : <select_gtl_5F_debugger_5F_parser_13>
221, // at 24 : <select_gtl_5F_debugger_5F_expression_5F_parser_0>
244, // at 25 : <select_gtl_5F_debugger_5F_expression_5F_parser_1>
267, // at 26 : <select_gtl_5F_debugger_5F_expression_5F_parser_2>
301, // at 27 : <select_gtl_5F_debugger_5F_expression_5F_parser_3>
339, // at 28 : <select_gtl_5F_debugger_5F_expression_5F_parser_4>
378, // at 29 : <select_gtl_5F_debugger_5F_expression_5F_parser_5>
383, // at 30 : <select_gtl_5F_debugger_5F_expression_5F_parser_6>
388, // at 31 : <select_gtl_5F_debugger_5F_expression_5F_parser_7>
426, // at 32 : <select_gtl_5F_debugger_5F_expression_5F_parser_8>
457, // at 33 : <select_gtl_5F_debugger_5F_expression_5F_parser_9>
462, // at 34 : <select_gtl_5F_debugger_5F_expression_5F_parser_10>
500, // at 35 : <select_gtl_5F_debugger_5F_expression_5F_parser_11>
505, // at 36 : <select_gtl_5F_debugger_5F_expression_5F_parser_12>
536, // at 37 : <select_gtl_5F_debugger_5F_expression_5F_parser_13>
541, // at 38 : <select_gtl_5F_debugger_5F_expression_5F_parser_14>
546, // at 39 : <select_gtl_5F_debugger_5F_expression_5F_parser_15>
551, // at 40 : <select_gtl_5F_debugger_5F_expression_5F_parser_16>
556, // at 41 : <select_gtl_5F_debugger_5F_expression_5F_parser_17>
561, // at 42 : <select_gtl_5F_debugger_5F_expression_5F_parser_18>
592, // at 43 : <select_gtl_5F_debugger_5F_expression_5F_parser_19>
597, // at 44 : <select_gtl_5F_debugger_5F_expression_5F_parser_20>
648, // at 45 : <select_gtl_5F_debugger_5F_expression_5F_parser_21>
700, // at 46 : <select_gtl_5F_debugger_5F_expression_5F_parser_22>
752, // at 47 : <select_gtl_5F_debugger_5F_expression_5F_parser_23>
804, // at 48 : <>
0} ;

//--------------------------------------------------------------------------------------------------
//
//                          'gtl_expression' non terminal implementation                            
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_expression_parse (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_expression_i0_parse(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_expression_indexing (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_expression_i0_indexing(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_expression_ (GALGAS_gtlExpression & parameter_1,
                                Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_expression_i0_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                           'gtl_variable' non terminal implementation                             
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_variable_parse (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_variable_i32_parse(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_variable_indexing (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_variable_i32_indexing(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_variable_ (GALGAS_gtlVarPath & parameter_1,
                                Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_variable_i32_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                       'gtl_debugger_command' non terminal implementation                         
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_debugger_5F_command_parse (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i0_parse(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i1_parse(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i2_parse(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i3_parse(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i4_parse(inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i5_parse(inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i6_parse(inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i7_parse(inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i8_parse(inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i9_parse(inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i10_parse(inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i11_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_debugger_5F_command_indexing (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i0_indexing(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i1_indexing(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i2_indexing(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i3_indexing(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i4_indexing(inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i5_indexing(inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i6_indexing(inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i7_indexing(inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i8_indexing(inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i9_indexing(inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i10_indexing(inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i11_indexing(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_debugger_5F_command_ (GALGAS_gtlInstruction & parameter_1,
                                Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i0_(parameter_1, inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i1_(parameter_1, inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i2_(parameter_1, inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i3_(parameter_1, inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i4_(parameter_1, inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i5_(parameter_1, inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i6_(parameter_1, inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i7_(parameter_1, inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i8_(parameter_1, inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i9_(parameter_1, inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i10_(parameter_1, inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i11_(parameter_1, inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_debugger_5F_grammar::performIndexing (Compiler * inCompiler,
             const String & inSourceFilePath) {
  Lexique_gtl_5F_debugger_5F_scanner * scanner = nullptr ;
  macroMyNew (scanner, Lexique_gtl_5F_debugger_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  scanner->enableIndexing () ;
  if (scanner->sourceText ().isValid ()) {
    const bool ok = scanner->performTopDownParsing (gProductions_gtl_debugger_grammar, gProductionNames_gtl_debugger_grammar, gProductionIndexes_gtl_debugger_grammar,
                                                    gFirstProductionIndexes_gtl_debugger_grammar, gDecision_gtl_debugger_grammar, gDecisionIndexes_gtl_debugger_grammar, 424) ;
    if (ok) {
      cGrammar_gtl_5F_debugger_5F_grammar grammar ;
      grammar.nt_gtl_5F_debugger_5F_command_indexing (scanner) ;
    }
    scanner->generateIndexFile () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::performOnlyLexicalAnalysis (Compiler * inCompiler,
             const String & inSourceFilePath) {
  Lexique_gtl_5F_debugger_5F_scanner * scanner = nullptr ;
  macroMyNew (scanner, Lexique_gtl_5F_debugger_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::performOnlySyntaxAnalysis (Compiler * inCompiler,
             const String & inSourceFilePath) {
  Lexique_gtl_5F_debugger_5F_scanner * scanner = nullptr ;
  macroMyNew (scanner, Lexique_gtl_5F_debugger_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performTopDownParsing (gProductions_gtl_debugger_grammar, gProductionNames_gtl_debugger_grammar, gProductionIndexes_gtl_debugger_grammar,
                                    gFirstProductionIndexes_gtl_debugger_grammar, gDecision_gtl_debugger_grammar, gDecisionIndexes_gtl_debugger_grammar, 424) ;
  }
  macroDetachSharedObject (scanner) ;
}

//--------------------------------------------------------------------------------------------------
//
//                              Grammar start symbol implementation                                 
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_debugger_5F_grammar::_performSourceFileParsing_ (Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_gtlInstruction &  parameter_1
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.readProperty_string () ;
    String filePath = filePathAsString.stringValue () ;
    if (! FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (FileManager::fileExistsAtPath (filePath)) {
    Lexique_gtl_5F_debugger_5F_scanner * scanner = nullptr ;
    macroMyNew (scanner, Lexique_gtl_5F_debugger_5F_scanner (inCompiler, filePath COMMA_HERE)) ;
    if (scanner->sourceText ().isValid ()) {
      const bool ok = scanner->performTopDownParsing (gProductions_gtl_debugger_grammar, gProductionNames_gtl_debugger_grammar, gProductionIndexes_gtl_debugger_grammar,
                                                      gFirstProductionIndexes_gtl_debugger_grammar, gDecision_gtl_debugger_grammar, gDecisionIndexes_gtl_debugger_grammar, 424) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_gtl_5F_debugger_5F_grammar grammar ;
        grammar.nt_gtl_5F_debugger_5F_command_ (parameter_1, scanner) ;
        }
      }else{
        String message ;
        message.appendString ("the '") ;
        message.appendString (filePath) ;
        message.appendString ("' file exists, but cannot be read") ;
        const GALGAS_location errorLocation (inFilePath.readProperty_location ()) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      String message ;
      message.appendString ("the '") ;
      message.appendString (filePath) ;
      message.appendString ("' file does not exist") ;
      const GALGAS_location errorLocation (inFilePath.readProperty_location ()) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_debugger_5F_grammar::_performSourceStringParsing_ (Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                GALGAS_gtlInstruction &  parameter_1
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const String sourceString = inSourceString.stringValue () ;
    const String nameString = inNameString.stringValue () ;
    Lexique_gtl_5F_debugger_5F_scanner * scanner = nullptr ;
    macroMyNew (scanner, Lexique_gtl_5F_debugger_5F_scanner (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_gtl_debugger_grammar, gProductionNames_gtl_debugger_grammar, gProductionIndexes_gtl_debugger_grammar,
                                                    gFirstProductionIndexes_gtl_debugger_grammar, gDecision_gtl_debugger_grammar, gDecisionIndexes_gtl_debugger_grammar, 424) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_gtl_5F_debugger_5F_grammar grammar ;
      grammar.nt_gtl_5F_debugger_5F_command_ (parameter_1, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//--------------------------------------------------------------------------------------------------
//
//                       'gtl_step_do_command' non terminal implementation                          
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_step_5F_do_5F_command_parse (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i12_parse(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i13_parse(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i14_parse(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i15_parse(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i16_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_step_5F_do_5F_command_indexing (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i12_indexing(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i13_indexing(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i14_indexing(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i15_indexing(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i16_indexing(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_step_5F_do_5F_command_ (GALGAS_gtlInstruction & parameter_1,
                                Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i12_(parameter_1, inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i13_(parameter_1, inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i14_(parameter_1, inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i15_(parameter_1, inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i16_(parameter_1, inLexique) ;
    break ;
  default :
    break ;
  }
}

//--------------------------------------------------------------------------------------------------
//
//                     'gtl_step_do_command_list' non terminal implementation                       
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_step_5F_do_5F_command_5F_list_parse (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_5F_list_i17_parse(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_step_5F_do_5F_command_5F_list_indexing (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_5F_list_i17_indexing(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_step_5F_do_5F_command_5F_list_ (GALGAS_gtlInstructionList & parameter_1,
                                Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_5F_list_i17_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                        'gtl_relation_term' non terminal implementation                           
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_relation_5F_term_parse (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_parse(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_relation_5F_term_indexing (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_indexing(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_relation_5F_term_ (GALGAS_gtlExpression & parameter_1,
                                Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                       'gtl_relation_factor' non terminal implementation                          
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_relation_5F_factor_parse (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_parse(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_relation_5F_factor_indexing (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_indexing(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_relation_5F_factor_ (GALGAS_gtlExpression & parameter_1,
                                Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                      'gtl_simple_expression' non terminal implementation                         
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_simple_5F_expression_parse (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_parse(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_simple_5F_expression_indexing (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_indexing(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_simple_5F_expression_ (GALGAS_gtlExpression & parameter_1,
                                Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                             'gtl_term' non terminal implementation                               
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_term_parse (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_term_i4_parse(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_term_indexing (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_term_i4_indexing(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_term_ (GALGAS_gtlExpression & parameter_1,
                                Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_term_i4_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                            'gtl_factor' non terminal implementation                              
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_factor_parse (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i5_parse(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i6_parse(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i7_parse(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i8_parse(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i9_parse(inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i10_parse(inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i11_parse(inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i12_parse(inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i13_parse(inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i14_parse(inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i15_parse(inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i16_parse(inLexique) ;
    break ;
  case 13 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i17_parse(inLexique) ;
    break ;
  case 14 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i18_parse(inLexique) ;
    break ;
  case 15 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i19_parse(inLexique) ;
    break ;
  case 16 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i20_parse(inLexique) ;
    break ;
  case 17 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i21_parse(inLexique) ;
    break ;
  case 18 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i22_parse(inLexique) ;
    break ;
  case 19 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i23_parse(inLexique) ;
    break ;
  case 20 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i24_parse(inLexique) ;
    break ;
  case 21 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i25_parse(inLexique) ;
    break ;
  case 22 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i26_parse(inLexique) ;
    break ;
  case 23 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i27_parse(inLexique) ;
    break ;
  case 24 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i28_parse(inLexique) ;
    break ;
  case 25 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i29_parse(inLexique) ;
    break ;
  case 26 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i30_parse(inLexique) ;
    break ;
  case 27 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i31_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_factor_indexing (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i5_indexing(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i6_indexing(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i7_indexing(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i8_indexing(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i9_indexing(inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i10_indexing(inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i11_indexing(inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i12_indexing(inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i13_indexing(inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i14_indexing(inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i15_indexing(inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i16_indexing(inLexique) ;
    break ;
  case 13 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i17_indexing(inLexique) ;
    break ;
  case 14 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i18_indexing(inLexique) ;
    break ;
  case 15 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i19_indexing(inLexique) ;
    break ;
  case 16 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i20_indexing(inLexique) ;
    break ;
  case 17 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i21_indexing(inLexique) ;
    break ;
  case 18 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i22_indexing(inLexique) ;
    break ;
  case 19 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i23_indexing(inLexique) ;
    break ;
  case 20 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i24_indexing(inLexique) ;
    break ;
  case 21 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i25_indexing(inLexique) ;
    break ;
  case 22 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i26_indexing(inLexique) ;
    break ;
  case 23 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i27_indexing(inLexique) ;
    break ;
  case 24 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i28_indexing(inLexique) ;
    break ;
  case 25 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i29_indexing(inLexique) ;
    break ;
  case 26 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i30_indexing(inLexique) ;
    break ;
  case 27 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i31_indexing(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_factor_ (GALGAS_gtlExpression & parameter_1,
                                Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i5_(parameter_1, inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i6_(parameter_1, inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i7_(parameter_1, inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i8_(parameter_1, inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i9_(parameter_1, inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i10_(parameter_1, inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i11_(parameter_1, inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i12_(parameter_1, inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i13_(parameter_1, inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i14_(parameter_1, inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i15_(parameter_1, inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i16_(parameter_1, inLexique) ;
    break ;
  case 13 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i17_(parameter_1, inLexique) ;
    break ;
  case 14 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i18_(parameter_1, inLexique) ;
    break ;
  case 15 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i19_(parameter_1, inLexique) ;
    break ;
  case 16 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i20_(parameter_1, inLexique) ;
    break ;
  case 17 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i21_(parameter_1, inLexique) ;
    break ;
  case 18 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i22_(parameter_1, inLexique) ;
    break ;
  case 19 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i23_(parameter_1, inLexique) ;
    break ;
  case 20 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i24_(parameter_1, inLexique) ;
    break ;
  case 21 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i25_(parameter_1, inLexique) ;
    break ;
  case 22 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i26_(parameter_1, inLexique) ;
    break ;
  case 23 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i27_(parameter_1, inLexique) ;
    break ;
  case 24 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i28_(parameter_1, inLexique) ;
    break ;
  case 25 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i29_(parameter_1, inLexique) ;
    break ;
  case 26 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i30_(parameter_1, inLexique) ;
    break ;
  case 27 :
    rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i31_(parameter_1, inLexique) ;
    break ;
  default :
    break ;
  }
}

//--------------------------------------------------------------------------------------------------
//
//             'select_gtl_5F_debugger_5F_parser_0' added non terminal implementation               
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_parser_0 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//             'select_gtl_5F_debugger_5F_parser_1' added non terminal implementation               
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_parser_1 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//             'select_gtl_5F_debugger_5F_parser_2' added non terminal implementation               
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_parser_2 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//             'select_gtl_5F_debugger_5F_parser_3' added non terminal implementation               
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_parser_3 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//             'select_gtl_5F_debugger_5F_parser_4' added non terminal implementation               
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_parser_4 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//             'select_gtl_5F_debugger_5F_parser_5' added non terminal implementation               
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_parser_5 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//             'select_gtl_5F_debugger_5F_parser_6' added non terminal implementation               
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_parser_6 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//             'select_gtl_5F_debugger_5F_parser_7' added non terminal implementation               
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_parser_7 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//             'select_gtl_5F_debugger_5F_parser_8' added non terminal implementation               
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_parser_8 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//             'select_gtl_5F_debugger_5F_parser_9' added non terminal implementation               
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_parser_9 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//            'select_gtl_5F_debugger_5F_parser_10' added non terminal implementation               
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_parser_10 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//            'select_gtl_5F_debugger_5F_parser_11' added non terminal implementation               
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_parser_11 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//            'select_gtl_5F_debugger_5F_parser_12' added non terminal implementation               
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_parser_12 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//            'select_gtl_5F_debugger_5F_parser_13' added non terminal implementation               
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_parser_13 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//      'select_gtl_5F_debugger_5F_expression_5F_parser_0' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_0 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//      'select_gtl_5F_debugger_5F_expression_5F_parser_1' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_1 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//      'select_gtl_5F_debugger_5F_expression_5F_parser_2' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_2 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//      'select_gtl_5F_debugger_5F_expression_5F_parser_3' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_3 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//      'select_gtl_5F_debugger_5F_expression_5F_parser_4' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_4 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//      'select_gtl_5F_debugger_5F_expression_5F_parser_5' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_5 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//      'select_gtl_5F_debugger_5F_expression_5F_parser_6' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_6 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//      'select_gtl_5F_debugger_5F_expression_5F_parser_7' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_7 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//      'select_gtl_5F_debugger_5F_expression_5F_parser_8' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_8 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//      'select_gtl_5F_debugger_5F_expression_5F_parser_9' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_9 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//     'select_gtl_5F_debugger_5F_expression_5F_parser_10' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_10 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//     'select_gtl_5F_debugger_5F_expression_5F_parser_11' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_11 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//     'select_gtl_5F_debugger_5F_expression_5F_parser_12' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_12 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//     'select_gtl_5F_debugger_5F_expression_5F_parser_13' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_13 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//     'select_gtl_5F_debugger_5F_expression_5F_parser_14' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_14 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//     'select_gtl_5F_debugger_5F_expression_5F_parser_15' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_15 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//     'select_gtl_5F_debugger_5F_expression_5F_parser_16' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_16 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//     'select_gtl_5F_debugger_5F_expression_5F_parser_17' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_17 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//     'select_gtl_5F_debugger_5F_expression_5F_parser_18' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_18 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//     'select_gtl_5F_debugger_5F_expression_5F_parser_19' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_19 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//     'select_gtl_5F_debugger_5F_expression_5F_parser_20' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_20 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//     'select_gtl_5F_debugger_5F_expression_5F_parser_21' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_21 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//     'select_gtl_5F_debugger_5F_expression_5F_parser_22' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_22 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//     'select_gtl_5F_debugger_5F_expression_5F_parser_23' added non terminal implementation        
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_expression_5F_parser_23 (Lexique_gtl_5F_debugger_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------



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

//--------------------------------------------------------------------------------------------------

GALGAS_object_5F_t::GALGAS_object_5F_t (void) :
AC_GALGAS_value_class () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_object_5F_t::GALGAS_object_5F_t (const cPtr_object_5F_t * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_object_5F_t) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_object_5F_t::readProperty_oil_5F_desc (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_object_5F_t * p = (const cPtr_object_5F_t *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_object_5F_t) ;
    return p->mProperty_oil_5F_desc ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_object_5F_t::getter_oil_5F_desc (UNUSED_LOCATION_ARGS) const {
  return mProperty_oil_5F_desc ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_object_5F_t::readProperty_location (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_location () ;
  }else{
    const cPtr_object_5F_t * p = (const cPtr_object_5F_t *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_object_5F_t) ;
    return p->mProperty_location ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_location cPtr_object_5F_t::getter_location (UNUSED_LOCATION_ARGS) const {
  return mProperty_location ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_object_5F_t::setter_setOil_5F_desc (GALGAS_lstring inValue
                                                COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_object_5F_t * p = (cPtr_object_5F_t *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_object_5F_t) ;
    p->mProperty_oil_5F_desc = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_object_5F_t::setter_setOil_5F_desc (GALGAS_lstring inValue
                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_oil_5F_desc = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_object_5F_t::setter_setLocation (GALGAS_location inValue
                                             COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_object_5F_t * p = (cPtr_object_5F_t *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_object_5F_t) ;
    p->mProperty_location = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_object_5F_t::setter_setLocation (GALGAS_location inValue
                                           COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_location = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @object_t class
//--------------------------------------------------------------------------------------------------

cPtr_object_5F_t::cPtr_object_5F_t (const GALGAS_lstring & in_oil_5F_desc,
                                    const GALGAS_location & in_location
                                    COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_oil_5F_desc (in_oil_5F_desc),
mProperty_location (in_location) {
}


//--------------------------------------------------------------------------------------------------
//
//     @object_t generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_object_5F_t ("object_t",
                                                                   nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_object_5F_t::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_object_5F_t ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_object_5F_t::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_object_5F_t (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_object_5F_t GALGAS_object_5F_t::extractObject (const GALGAS_object & inObject,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_object_5F_t result ;
  const GALGAS_object_5F_t * p = (const GALGAS_object_5F_t *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_object_5F_t *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("object_t", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------



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

//--------------------------------------------------------------------------------------------------

GALGAS_impType::GALGAS_impType (void) :
AC_GALGAS_value_class () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_impType::GALGAS_impType (const cPtr_impType * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impType) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_locationList GALGAS_impType::readProperty_locations (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_locationList () ;
  }else{
    const cPtr_impType * p = (const cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    return p->mProperty_locations ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_locationList cPtr_impType::getter_locations (UNUSED_LOCATION_ARGS) const {
  return mProperty_locations ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_dataType GALGAS_impType::readProperty_type (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_dataType () ;
  }else{
    const cPtr_impType * p = (const cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    return p->mProperty_type ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_dataType cPtr_impType::getter_type (UNUSED_LOCATION_ARGS) const {
  return mProperty_type ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_impType::readProperty_name (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_impType * p = (const cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    return p->mProperty_name ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_impType::getter_name (UNUSED_LOCATION_ARGS) const {
  return mProperty_name ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_impType::readProperty_multiple (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_impType * p = (const cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    return p->mProperty_multiple ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_impType::getter_multiple (UNUSED_LOCATION_ARGS) const {
  return mProperty_multiple ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstringlist GALGAS_impType::readProperty_descs (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstringlist () ;
  }else{
    const cPtr_impType * p = (const cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    return p->mProperty_descs ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstringlist cPtr_impType::getter_descs (UNUSED_LOCATION_ARGS) const {
  return mProperty_descs ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_impType::setter_setLocations (GALGAS_locationList inValue
                                          COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_impType * p = (cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    p->mProperty_locations = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_impType::setter_setLocations (GALGAS_locationList inValue
                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_locations = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_impType::setter_setType (GALGAS_dataType inValue
                                     COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_impType * p = (cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    p->mProperty_type = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_impType::setter_setType (GALGAS_dataType inValue
                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_type = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_impType::setter_setName (GALGAS_lstring inValue
                                     COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_impType * p = (cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    p->mProperty_name = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_impType::setter_setName (GALGAS_lstring inValue
                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_name = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_impType::setter_setMultiple (GALGAS_bool inValue
                                         COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_impType * p = (cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    p->mProperty_multiple = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_impType::setter_setMultiple (GALGAS_bool inValue
                                       COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_multiple = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_impType::setter_setDescs (GALGAS_lstringlist inValue
                                      COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_impType * p = (cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    p->mProperty_descs = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_impType::setter_setDescs (GALGAS_lstringlist inValue
                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_descs = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @impType class
//--------------------------------------------------------------------------------------------------

cPtr_impType::cPtr_impType (const GALGAS_locationList & in_locations,
                            const GALGAS_dataType & in_type,
                            const GALGAS_lstring & in_name,
                            const GALGAS_bool & in_multiple,
                            const GALGAS_lstringlist & in_descs
                            COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_locations (in_locations),
mProperty_type (in_type),
mProperty_name (in_name),
mProperty_multiple (in_multiple),
mProperty_descs (in_descs) {
}


//--------------------------------------------------------------------------------------------------
//
//     @impType generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impType ("impType",
                                                               nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_impType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impType ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_impType::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impType (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_impType GALGAS_impType::extractObject (const GALGAS_object & inObject,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_impType result ;
  const GALGAS_impType * p = (const GALGAS_impType *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_impType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@impType getDefaultValue'
//
//--------------------------------------------------------------------------------------------------

GALGAS_object_5F_t cPtr_impType::getter_getDefaultValue (Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_object_5F_t result_outDefaultValue ; // Returned variable
  result_outDefaultValue = GALGAS_void::class_func_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 440)), GALGAS_location::class_func_nowhere (SOURCE_FILE ("implementation_types.galgas", 440))  COMMA_SOURCE_FILE ("implementation_types.galgas", 440)) ;
//---
  return result_outDefaultValue ;
}



//--------------------------------------------------------------------------------------------------

GALGAS_object_5F_t callExtensionGetter_getDefaultValue (const cPtr_impType * inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_object_5F_t result ;
  if (nullptr != inObject) {
    result = inObject->getter_getDefaultValue (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@impType setDefValue'
//
//--------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_impType_setDefValue> gExtensionModifierTable_impType_setDefValue ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_setDefValue (const int32_t inClassIndex,
                                       extensionSetterSignature_impType_setDefValue inModifier) {
  gExtensionModifierTable_impType_setDefValue.forceObjectAtIndex (inClassIndex, inModifier, nullptr) ;
}

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_setDefValue (cPtr_impType * inObject,
                                      GALGAS_object_5F_t in_inDefaultValue,
                                      Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_impType) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_impType_setDefValue f = nullptr ;
    if (classIndex < gExtensionModifierTable_impType_setDefValue.count ()) {
      f = gExtensionModifierTable_impType_setDefValue (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_impType_setDefValue.count ()) {
           f = gExtensionModifierTable_impType_setDefValue (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_impType_setDefValue.forceObjectAtIndex (classIndex, f, nullptr) ;
    }
    f (inObject, in_inDefaultValue, inCompiler COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

static void extensionSetter_impType_setDefValue (cPtr_impType * /* inObject */,
                                                 GALGAS_object_5F_t /* inArgument_inDefaultValue */,
                                                 Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_impType_setDefValue (void) {
  enterExtensionSetter_setDefValue (kTypeDescriptor_GALGAS_impType.mSlotID,
                                    extensionSetter_impType_setDefValue) ;
}

//--------------------------------------------------------------------------------------------------

static void freeExtensionModifier_impType_setDefValue (void) {
  gExtensionModifierTable_impType_setDefValue.removeAll () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_impType_setDefValue (defineExtensionSetter_impType_setDefValue,
                                              freeExtensionModifier_impType_setDefValue) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@impType mergeWithType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_impType callExtensionGetter_mergeWithType (const cPtr_impType * inObject,
                                                  GALGAS_impType in_typeToMerge,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_impType result ;
  if (nullptr != inObject) {
    result = inObject->getter_mergeWithType (in_typeToMerge, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@impType autoAllowed'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_impType::getter_autoAllowed (Compiler */* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (false) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_autoAllowed (const cPtr_impType * inObject,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_autoAllowed (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_impStructType::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_impStructType * p = (const cPtr_impStructType *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_impStructType) ;
  if (kOperandEqual == result) {
    result = mProperty_locations.objectCompare (p->mProperty_locations) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_type.objectCompare (p->mProperty_type) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_name.objectCompare (p->mProperty_name) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_multiple.objectCompare (p->mProperty_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_descs.objectCompare (p->mProperty_descs) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_structAttributes.objectCompare (p->mProperty_structAttributes) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_impStructType::GALGAS_impStructType (void) :
GALGAS_impType () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_impStructType::GALGAS_impStructType (const cPtr_impStructType * inSourcePtr) :
GALGAS_impType (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impStructType) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_impStructType GALGAS_impStructType::class_func_new (const GALGAS_locationList & inAttribute_locations,
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

//--------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap GALGAS_impStructType::readProperty_structAttributes (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_implementationObjectMap () ;
  }else{
    const cPtr_impStructType * p = (const cPtr_impStructType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impStructType) ;
    return p->mProperty_structAttributes ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap cPtr_impStructType::getter_structAttributes (UNUSED_LOCATION_ARGS) const {
  return mProperty_structAttributes ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_impStructType::setter_setStructAttributes (GALGAS_implementationObjectMap inValue
                                                       COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_impStructType * p = (cPtr_impStructType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impStructType) ;
    p->mProperty_structAttributes = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_impStructType::setter_setStructAttributes (GALGAS_implementationObjectMap inValue
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_structAttributes = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @impStructType class
//--------------------------------------------------------------------------------------------------

cPtr_impStructType::cPtr_impStructType (const GALGAS_locationList & in_locations,
                                        const GALGAS_dataType & in_type,
                                        const GALGAS_lstring & in_name,
                                        const GALGAS_bool & in_multiple,
                                        const GALGAS_lstringlist & in_descs,
                                        const GALGAS_implementationObjectMap & in_structAttributes
                                        COMMA_LOCATION_ARGS) :
cPtr_impType (in_locations, in_type, in_name, in_multiple, in_descs COMMA_THERE),
mProperty_structAttributes (in_structAttributes) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_impStructType::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impStructType ;
}

void cPtr_impStructType::description (String & ioString,
                                      const int32_t inIndentation) const {
  ioString.appendCString ("[@impStructType:") ;
  mProperty_locations.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_type.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_name.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_multiple.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_descs.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_structAttributes.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_impStructType::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_impStructType (mProperty_locations, mProperty_type, mProperty_name, mProperty_multiple, mProperty_descs, mProperty_structAttributes COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @impStructType generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impStructType ("impStructType",
                                                                     & kTypeDescriptor_GALGAS_impType) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_impStructType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impStructType ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_impStructType::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impStructType (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_impStructType GALGAS_impStructType::extractObject (const GALGAS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_impStructType result ;
  const GALGAS_impStructType * p = (const GALGAS_impStructType *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_impStructType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impStructType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_impVoid::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_impVoid * p = (const cPtr_impVoid *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_impVoid) ;
  if (kOperandEqual == result) {
    result = mProperty_locations.objectCompare (p->mProperty_locations) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_type.objectCompare (p->mProperty_type) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_name.objectCompare (p->mProperty_name) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_multiple.objectCompare (p->mProperty_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_descs.objectCompare (p->mProperty_descs) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_impVoid::GALGAS_impVoid (void) :
GALGAS_impType () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_impVoid::GALGAS_impVoid (const cPtr_impVoid * inSourcePtr) :
GALGAS_impType (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impVoid) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_impVoid GALGAS_impVoid::class_func_new (const GALGAS_locationList & inAttribute_locations,
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

//--------------------------------------------------------------------------------------------------
//Pointer class for @impVoid class
//--------------------------------------------------------------------------------------------------

cPtr_impVoid::cPtr_impVoid (const GALGAS_locationList & in_locations,
                            const GALGAS_dataType & in_type,
                            const GALGAS_lstring & in_name,
                            const GALGAS_bool & in_multiple,
                            const GALGAS_lstringlist & in_descs
                            COMMA_LOCATION_ARGS) :
cPtr_impType (in_locations, in_type, in_name, in_multiple, in_descs COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_impVoid::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impVoid ;
}

void cPtr_impVoid::description (String & ioString,
                                const int32_t inIndentation) const {
  ioString.appendCString ("[@impVoid:") ;
  mProperty_locations.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_type.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_name.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_multiple.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_descs.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_impVoid::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_impVoid (mProperty_locations, mProperty_type, mProperty_name, mProperty_multiple, mProperty_descs COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @impVoid generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impVoid ("impVoid",
                                                               & kTypeDescriptor_GALGAS_impType) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_impVoid::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impVoid ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_impVoid::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impVoid (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_impVoid GALGAS_impVoid::extractObject (const GALGAS_object & inObject,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_impVoid result ;
  const GALGAS_impVoid * p = (const GALGAS_impVoid *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_impVoid *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impVoid", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_impAutoDefaultType::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_impAutoDefaultType * p = (const cPtr_impAutoDefaultType *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_impAutoDefaultType) ;
  if (kOperandEqual == result) {
    result = mProperty_locations.objectCompare (p->mProperty_locations) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_type.objectCompare (p->mProperty_type) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_name.objectCompare (p->mProperty_name) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_multiple.objectCompare (p->mProperty_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_descs.objectCompare (p->mProperty_descs) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_withAuto.objectCompare (p->mProperty_withAuto) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_defaultValue.objectCompare (p->mProperty_defaultValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_impAutoDefaultType::GALGAS_impAutoDefaultType (void) :
GALGAS_impType () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_impAutoDefaultType::GALGAS_impAutoDefaultType (const cPtr_impAutoDefaultType * inSourcePtr) :
GALGAS_impType (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impAutoDefaultType) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_impAutoDefaultType GALGAS_impAutoDefaultType::class_func_new (const GALGAS_locationList & inAttribute_locations,
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

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_impAutoDefaultType::readProperty_withAuto (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_impAutoDefaultType * p = (const cPtr_impAutoDefaultType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impAutoDefaultType) ;
    return p->mProperty_withAuto ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_impAutoDefaultType::getter_withAuto (UNUSED_LOCATION_ARGS) const {
  return mProperty_withAuto ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_object_5F_t GALGAS_impAutoDefaultType::readProperty_defaultValue (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_object_5F_t () ;
  }else{
    const cPtr_impAutoDefaultType * p = (const cPtr_impAutoDefaultType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impAutoDefaultType) ;
    return p->mProperty_defaultValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_object_5F_t cPtr_impAutoDefaultType::getter_defaultValue (UNUSED_LOCATION_ARGS) const {
  return mProperty_defaultValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_impAutoDefaultType::setter_setWithAuto (GALGAS_bool inValue
                                                    COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_impAutoDefaultType * p = (cPtr_impAutoDefaultType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impAutoDefaultType) ;
    p->mProperty_withAuto = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_impAutoDefaultType::setter_setWithAuto (GALGAS_bool inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_withAuto = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_impAutoDefaultType::setter_setDefaultValue (GALGAS_object_5F_t inValue
                                                        COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_impAutoDefaultType * p = (cPtr_impAutoDefaultType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impAutoDefaultType) ;
    p->mProperty_defaultValue = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_impAutoDefaultType::setter_setDefaultValue (GALGAS_object_5F_t inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_defaultValue = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @impAutoDefaultType class
//--------------------------------------------------------------------------------------------------

cPtr_impAutoDefaultType::cPtr_impAutoDefaultType (const GALGAS_locationList & in_locations,
                                                  const GALGAS_dataType & in_type,
                                                  const GALGAS_lstring & in_name,
                                                  const GALGAS_bool & in_multiple,
                                                  const GALGAS_lstringlist & in_descs,
                                                  const GALGAS_bool & in_withAuto,
                                                  const GALGAS_object_5F_t & in_defaultValue
                                                  COMMA_LOCATION_ARGS) :
cPtr_impType (in_locations, in_type, in_name, in_multiple, in_descs COMMA_THERE),
mProperty_withAuto (in_withAuto),
mProperty_defaultValue (in_defaultValue) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_impAutoDefaultType::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impAutoDefaultType ;
}

void cPtr_impAutoDefaultType::description (String & ioString,
                                           const int32_t inIndentation) const {
  ioString.appendCString ("[@impAutoDefaultType:") ;
  mProperty_locations.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_type.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_name.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_multiple.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_descs.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_withAuto.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_defaultValue.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_impAutoDefaultType::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_impAutoDefaultType (mProperty_locations, mProperty_type, mProperty_name, mProperty_multiple, mProperty_descs, mProperty_withAuto, mProperty_defaultValue COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @impAutoDefaultType generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impAutoDefaultType ("impAutoDefaultType",
                                                                          & kTypeDescriptor_GALGAS_impType) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_impAutoDefaultType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impAutoDefaultType ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_impAutoDefaultType::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impAutoDefaultType (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_impAutoDefaultType GALGAS_impAutoDefaultType::extractObject (const GALGAS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_impAutoDefaultType result ;
  const GALGAS_impAutoDefaultType * p = (const GALGAS_impAutoDefaultType *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_impAutoDefaultType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impAutoDefaultType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//Extension method '@impAutoDefaultType setDefault'
//
//--------------------------------------------------------------------------------------------------

void cPtr_impAutoDefaultType::method_setDefault (GALGAS_objectAttributes & ioArgument_attributes,
                                                 Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = ioArgument_attributes.readProperty_objectParams ().getter_hasKey (this->mProperty_name.readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 527)).operator_not (SOURCE_FILE ("implementation_types.galgas", 527)).boolEnum () ;
    if (kBoolTrue == test_0) {
      if (this->mProperty_defaultValue.isValid ()) {
        if (this->mProperty_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_void) {
        }else if (this->mProperty_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
          GALGAS_identifierMap var_attr_14430 = ioArgument_attributes.readProperty_objectParams () ;
          {
          var_attr_14430.setter_put (this->mProperty_name, this->mProperty_defaultValue, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 532)) ;
          }
          {
          ioArgument_attributes.setter_setObjectParams (var_attr_14430 COMMA_SOURCE_FILE ("implementation_types.galgas", 533)) ;
          }
        }else{
          GALGAS_identifierMap var_attr_14626 = ioArgument_attributes.readProperty_objectParams () ;
          {
          var_attr_14626.setter_put (this->mProperty_name, this->mProperty_defaultValue, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 537)) ;
          }
          {
          ioArgument_attributes.setter_setObjectParams (var_attr_14626 COMMA_SOURCE_FILE ("implementation_types.galgas", 538)) ;
          }
        }
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

void callExtensionMethod_setDefault (cPtr_impAutoDefaultType * inObject,
                                     GALGAS_objectAttributes & io_attributes,
                                     Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_impAutoDefaultType) ;
    inObject->method_setDefault  (io_attributes, inCompiler COMMA_THERE) ;
  }
}
//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_refType::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_refType * p = (const cPtr_refType *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_refType) ;
  if (kOperandEqual == result) {
    result = mProperty_locations.objectCompare (p->mProperty_locations) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_type.objectCompare (p->mProperty_type) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_name.objectCompare (p->mProperty_name) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_multiple.objectCompare (p->mProperty_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_descs.objectCompare (p->mProperty_descs) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_ref.objectCompare (p->mProperty_ref) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_refType::GALGAS_refType (void) :
GALGAS_impType () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_refType::GALGAS_refType (const cPtr_refType * inSourcePtr) :
GALGAS_impType (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_refType) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_refType GALGAS_refType::class_func_new (const GALGAS_locationList & inAttribute_locations,
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

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_refType::readProperty_ref (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_refType * p = (const cPtr_refType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_refType) ;
    return p->mProperty_ref ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_refType::getter_ref (UNUSED_LOCATION_ARGS) const {
  return mProperty_ref ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_refType::setter_setRef (GALGAS_lstring inValue
                                    COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_refType * p = (cPtr_refType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_refType) ;
    p->mProperty_ref = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_refType::setter_setRef (GALGAS_lstring inValue
                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_ref = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @refType class
//--------------------------------------------------------------------------------------------------

cPtr_refType::cPtr_refType (const GALGAS_locationList & in_locations,
                            const GALGAS_dataType & in_type,
                            const GALGAS_lstring & in_name,
                            const GALGAS_bool & in_multiple,
                            const GALGAS_lstringlist & in_descs,
                            const GALGAS_lstring & in_ref
                            COMMA_LOCATION_ARGS) :
cPtr_impType (in_locations, in_type, in_name, in_multiple, in_descs COMMA_THERE),
mProperty_ref (in_ref) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_refType::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_refType ;
}

void cPtr_refType::description (String & ioString,
                                const int32_t inIndentation) const {
  ioString.appendCString ("[@refType:") ;
  mProperty_locations.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_type.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_name.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_multiple.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_descs.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_ref.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_refType::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_refType (mProperty_locations, mProperty_type, mProperty_name, mProperty_multiple, mProperty_descs, mProperty_ref COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @refType generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_refType ("refType",
                                                               & kTypeDescriptor_GALGAS_impType) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_refType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_refType ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_refType::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_refType (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_refType GALGAS_refType::extractObject (const GALGAS_object & inObject,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_refType result ;
  const GALGAS_refType * p = (const GALGAS_refType *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_refType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("refType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_implementationObject::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_implementationObject * p = (const cPtr_implementationObject *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_implementationObject) ;
  if (kOperandEqual == result) {
    result = mProperty_multiple.objectCompare (p->mProperty_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_attributes.objectCompare (p->mProperty_attributes) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_implementationObject::GALGAS_implementationObject (void) :
AC_GALGAS_value_class () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_implementationObject::GALGAS_implementationObject (const cPtr_implementationObject * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_implementationObject) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_implementationObject GALGAS_implementationObject::class_func_new (const GALGAS_lbool & inAttribute_multiple,
                                                                         const GALGAS_implementationObjectMap & inAttribute_attributes
                                                                         COMMA_LOCATION_ARGS) {
  GALGAS_implementationObject result ;
  if (inAttribute_multiple.isValid () && inAttribute_attributes.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_implementationObject (inAttribute_multiple, inAttribute_attributes COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lbool GALGAS_implementationObject::readProperty_multiple (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lbool () ;
  }else{
    const cPtr_implementationObject * p = (const cPtr_implementationObject *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_implementationObject) ;
    return p->mProperty_multiple ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lbool cPtr_implementationObject::getter_multiple (UNUSED_LOCATION_ARGS) const {
  return mProperty_multiple ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap GALGAS_implementationObject::readProperty_attributes (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_implementationObjectMap () ;
  }else{
    const cPtr_implementationObject * p = (const cPtr_implementationObject *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_implementationObject) ;
    return p->mProperty_attributes ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap cPtr_implementationObject::getter_attributes (UNUSED_LOCATION_ARGS) const {
  return mProperty_attributes ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_implementationObject::setter_setMultiple (GALGAS_lbool inValue
                                                      COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_implementationObject * p = (cPtr_implementationObject *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_implementationObject) ;
    p->mProperty_multiple = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_implementationObject::setter_setMultiple (GALGAS_lbool inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_multiple = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_implementationObject::setter_setAttributes (GALGAS_implementationObjectMap inValue
                                                        COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_implementationObject * p = (cPtr_implementationObject *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_implementationObject) ;
    p->mProperty_attributes = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_implementationObject::setter_setAttributes (GALGAS_implementationObjectMap inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_attributes = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @implementationObject class
//--------------------------------------------------------------------------------------------------

cPtr_implementationObject::cPtr_implementationObject (const GALGAS_lbool & in_multiple,
                                                      const GALGAS_implementationObjectMap & in_attributes
                                                      COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_multiple (in_multiple),
mProperty_attributes (in_attributes) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_implementationObject::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementationObject ;
}

void cPtr_implementationObject::description (String & ioString,
                                             const int32_t inIndentation) const {
  ioString.appendCString ("[@implementationObject:") ;
  mProperty_multiple.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_attributes.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_implementationObject::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_implementationObject (mProperty_multiple, mProperty_attributes COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @implementationObject generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_implementationObject ("implementationObject",
                                                                            nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_implementationObject::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementationObject ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_implementationObject::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_implementationObject (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_implementationObject GALGAS_implementationObject::extractObject (const GALGAS_object & inObject,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_implementationObject result ;
  const GALGAS_implementationObject * p = (const GALGAS_implementationObject *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_implementationObject *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("implementationObject", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_impRangedType::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_impRangedType * p = (const cPtr_impRangedType *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_impRangedType) ;
  if (kOperandEqual == result) {
    result = mProperty_locations.objectCompare (p->mProperty_locations) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_type.objectCompare (p->mProperty_type) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_name.objectCompare (p->mProperty_name) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_multiple.objectCompare (p->mProperty_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_descs.objectCompare (p->mProperty_descs) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_withAuto.objectCompare (p->mProperty_withAuto) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_defaultValue.objectCompare (p->mProperty_defaultValue) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_setOrRange.objectCompare (p->mProperty_setOrRange) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_impRangedType::GALGAS_impRangedType (void) :
GALGAS_impAutoDefaultType () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_impRangedType::GALGAS_impRangedType (const cPtr_impRangedType * inSourcePtr) :
GALGAS_impAutoDefaultType (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impRangedType) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_impRangedType GALGAS_impRangedType::class_func_new (const GALGAS_locationList & inAttribute_locations,
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

//--------------------------------------------------------------------------------------------------

GALGAS_attributeRange GALGAS_impRangedType::readProperty_setOrRange (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_attributeRange () ;
  }else{
    const cPtr_impRangedType * p = (const cPtr_impRangedType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impRangedType) ;
    return p->mProperty_setOrRange ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_attributeRange cPtr_impRangedType::getter_setOrRange (UNUSED_LOCATION_ARGS) const {
  return mProperty_setOrRange ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_impRangedType::setter_setSetOrRange (GALGAS_attributeRange inValue
                                                 COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_impRangedType * p = (cPtr_impRangedType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impRangedType) ;
    p->mProperty_setOrRange = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_impRangedType::setter_setSetOrRange (GALGAS_attributeRange inValue
                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_setOrRange = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @impRangedType class
//--------------------------------------------------------------------------------------------------

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
mProperty_setOrRange (in_setOrRange) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_impRangedType::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impRangedType ;
}

void cPtr_impRangedType::description (String & ioString,
                                      const int32_t inIndentation) const {
  ioString.appendCString ("[@impRangedType:") ;
  mProperty_locations.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_type.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_name.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_multiple.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_descs.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_withAuto.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_defaultValue.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_setOrRange.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_impRangedType::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_impRangedType (mProperty_locations, mProperty_type, mProperty_name, mProperty_multiple, mProperty_descs, mProperty_withAuto, mProperty_defaultValue, mProperty_setOrRange COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @impRangedType generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impRangedType ("impRangedType",
                                                                     & kTypeDescriptor_GALGAS_impAutoDefaultType) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_impRangedType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impRangedType ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_impRangedType::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impRangedType (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_impRangedType GALGAS_impRangedType::extractObject (const GALGAS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_impRangedType result ;
  const GALGAS_impRangedType * p = (const GALGAS_impRangedType *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_impRangedType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impRangedType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_impBoolType::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_impBoolType * p = (const cPtr_impBoolType *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_impBoolType) ;
  if (kOperandEqual == result) {
    result = mProperty_locations.objectCompare (p->mProperty_locations) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_type.objectCompare (p->mProperty_type) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_name.objectCompare (p->mProperty_name) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_multiple.objectCompare (p->mProperty_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_descs.objectCompare (p->mProperty_descs) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_withAuto.objectCompare (p->mProperty_withAuto) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_defaultValue.objectCompare (p->mProperty_defaultValue) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_trueSubAttributes.objectCompare (p->mProperty_trueSubAttributes) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_falseSubAttributes.objectCompare (p->mProperty_falseSubAttributes) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_impBoolType::GALGAS_impBoolType (void) :
GALGAS_impAutoDefaultType () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_impBoolType::GALGAS_impBoolType (const cPtr_impBoolType * inSourcePtr) :
GALGAS_impAutoDefaultType (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impBoolType) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_impBoolType GALGAS_impBoolType::class_func_new (const GALGAS_locationList & inAttribute_locations,
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

//--------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap GALGAS_impBoolType::readProperty_trueSubAttributes (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_implementationObjectMap () ;
  }else{
    const cPtr_impBoolType * p = (const cPtr_impBoolType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impBoolType) ;
    return p->mProperty_trueSubAttributes ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap cPtr_impBoolType::getter_trueSubAttributes (UNUSED_LOCATION_ARGS) const {
  return mProperty_trueSubAttributes ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap GALGAS_impBoolType::readProperty_falseSubAttributes (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_implementationObjectMap () ;
  }else{
    const cPtr_impBoolType * p = (const cPtr_impBoolType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impBoolType) ;
    return p->mProperty_falseSubAttributes ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap cPtr_impBoolType::getter_falseSubAttributes (UNUSED_LOCATION_ARGS) const {
  return mProperty_falseSubAttributes ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_impBoolType::setter_setTrueSubAttributes (GALGAS_implementationObjectMap inValue
                                                      COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_impBoolType * p = (cPtr_impBoolType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impBoolType) ;
    p->mProperty_trueSubAttributes = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_impBoolType::setter_setTrueSubAttributes (GALGAS_implementationObjectMap inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_trueSubAttributes = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_impBoolType::setter_setFalseSubAttributes (GALGAS_implementationObjectMap inValue
                                                       COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_impBoolType * p = (cPtr_impBoolType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impBoolType) ;
    p->mProperty_falseSubAttributes = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_impBoolType::setter_setFalseSubAttributes (GALGAS_implementationObjectMap inValue
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_falseSubAttributes = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @impBoolType class
//--------------------------------------------------------------------------------------------------

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
mProperty_trueSubAttributes (in_trueSubAttributes),
mProperty_falseSubAttributes (in_falseSubAttributes) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_impBoolType::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impBoolType ;
}

void cPtr_impBoolType::description (String & ioString,
                                    const int32_t inIndentation) const {
  ioString.appendCString ("[@impBoolType:") ;
  mProperty_locations.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_type.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_name.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_multiple.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_descs.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_withAuto.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_defaultValue.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_trueSubAttributes.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_falseSubAttributes.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_impBoolType::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_impBoolType (mProperty_locations, mProperty_type, mProperty_name, mProperty_multiple, mProperty_descs, mProperty_withAuto, mProperty_defaultValue, mProperty_trueSubAttributes, mProperty_falseSubAttributes COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @impBoolType generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impBoolType ("impBoolType",
                                                                   & kTypeDescriptor_GALGAS_impAutoDefaultType) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_impBoolType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impBoolType ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_impBoolType::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impBoolType (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_impBoolType GALGAS_impBoolType::extractObject (const GALGAS_object & inObject,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_impBoolType result ;
  const GALGAS_impBoolType * p = (const GALGAS_impBoolType *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_impBoolType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impBoolType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_impEnumType::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_impEnumType * p = (const cPtr_impEnumType *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_impEnumType) ;
  if (kOperandEqual == result) {
    result = mProperty_locations.objectCompare (p->mProperty_locations) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_type.objectCompare (p->mProperty_type) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_name.objectCompare (p->mProperty_name) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_multiple.objectCompare (p->mProperty_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_descs.objectCompare (p->mProperty_descs) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_withAuto.objectCompare (p->mProperty_withAuto) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_defaultValue.objectCompare (p->mProperty_defaultValue) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_valuesMap.objectCompare (p->mProperty_valuesMap) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_impEnumType::GALGAS_impEnumType (void) :
GALGAS_impAutoDefaultType () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_impEnumType::GALGAS_impEnumType (const cPtr_impEnumType * inSourcePtr) :
GALGAS_impAutoDefaultType (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impEnumType) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_impEnumType GALGAS_impEnumType::class_func_new (const GALGAS_locationList & inAttribute_locations,
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

//--------------------------------------------------------------------------------------------------

GALGAS_enumValues GALGAS_impEnumType::readProperty_valuesMap (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_enumValues () ;
  }else{
    const cPtr_impEnumType * p = (const cPtr_impEnumType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impEnumType) ;
    return p->mProperty_valuesMap ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_enumValues cPtr_impEnumType::getter_valuesMap (UNUSED_LOCATION_ARGS) const {
  return mProperty_valuesMap ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_impEnumType::setter_setValuesMap (GALGAS_enumValues inValue
                                              COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_impEnumType * p = (cPtr_impEnumType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impEnumType) ;
    p->mProperty_valuesMap = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_impEnumType::setter_setValuesMap (GALGAS_enumValues inValue
                                            COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_valuesMap = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @impEnumType class
//--------------------------------------------------------------------------------------------------

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
mProperty_valuesMap (in_valuesMap) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_impEnumType::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impEnumType ;
}

void cPtr_impEnumType::description (String & ioString,
                                    const int32_t inIndentation) const {
  ioString.appendCString ("[@impEnumType:") ;
  mProperty_locations.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_type.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_name.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_multiple.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_descs.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_withAuto.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_defaultValue.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_valuesMap.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_impEnumType::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_impEnumType (mProperty_locations, mProperty_type, mProperty_name, mProperty_multiple, mProperty_descs, mProperty_withAuto, mProperty_defaultValue, mProperty_valuesMap COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @impEnumType generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impEnumType ("impEnumType",
                                                                   & kTypeDescriptor_GALGAS_impAutoDefaultType) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_impEnumType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impEnumType ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_impEnumType::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impEnumType (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_impEnumType GALGAS_impEnumType::extractObject (const GALGAS_object & inObject,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_impEnumType result ;
  const GALGAS_impEnumType * p = (const GALGAS_impEnumType *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_impEnumType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impEnumType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//Extension method '@impType checkAttributeReferences'
//
//--------------------------------------------------------------------------------------------------

void cPtr_impType::method_checkAttributeReferences (const GALGAS_implementation /* constinArgument_imp */,
                                                    Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
}

//--------------------------------------------------------------------------------------------------

void callExtensionMethod_checkAttributeReferences (cPtr_impType * inObject,
                                                   const GALGAS_implementation constin_imp,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_impType) ;
    inObject->method_checkAttributeReferences  (constin_imp, inCompiler COMMA_THERE) ;
  }
}
//--------------------------------------------------------------------------------------------------
//
//Extension getter '@implementationObject mergeImplementationObjectWith'
//
//--------------------------------------------------------------------------------------------------

GALGAS_implementationObject cPtr_implementationObject::getter_mergeImplementationObjectWith (const GALGAS_implementationObject constinArgument_objToMerge,
                                                                                             Compiler * inCompiler
                                                                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_implementationObject result_mergedObj ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, this->mProperty_multiple.objectCompare (constinArgument_objToMerge.readProperty_multiple ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (gOption_goil_5F_options_warnMultiple.readProperty_value ()).boolEnum () ;
        if (kBoolTrue == test_1) {
          TC_Array <C_FixItDescription> fixItArray2 ;
          inCompiler->emitSemanticWarning (constinArgument_objToMerge.readProperty_multiple ().readProperty_location (), GALGAS_string ("multiple redefinition"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 1027)) ;
          TC_Array <C_FixItDescription> fixItArray3 ;
          inCompiler->emitSemanticWarning (this->mProperty_multiple.readProperty_location (), GALGAS_string ("was defined here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 1028)) ;
        }
      }
    }
  }
  result_mergedObj = GALGAS_implementationObject::class_func_new (this->mProperty_multiple, extensionGetter_mergeImplementationObjectAttributesWith (this->mProperty_attributes, constinArgument_objToMerge.readProperty_attributes (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1041))  COMMA_SOURCE_FILE ("implementation_types.galgas", 1041)) ;
//---
  return result_mergedObj ;
}



//--------------------------------------------------------------------------------------------------

GALGAS_implementationObject callExtensionGetter_mergeImplementationObjectWith (const cPtr_implementationObject * inObject,
                                                                               const GALGAS_implementationObject in_objToMerge,
                                                                               Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) {
  GALGAS_implementationObject result ;
  if (nullptr != inObject) {
    result = inObject->getter_mergeImplementationObjectWith (in_objToMerge, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@object_t mergeSubAttributes'
//
//--------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_object_5F_t_mergeSubAttributes> gExtensionModifierTable_object_5F_t_mergeSubAttributes ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_mergeSubAttributes (const int32_t inClassIndex,
                                              extensionSetterSignature_object_5F_t_mergeSubAttributes inModifier) {
  gExtensionModifierTable_object_5F_t_mergeSubAttributes.forceObjectAtIndex (inClassIndex, inModifier, nullptr) ;
}

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_mergeSubAttributes (cPtr_object_5F_t * inObject,
                                             GALGAS_object_5F_t in_withObject,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_object_5F_t) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_object_5F_t_mergeSubAttributes f = nullptr ;
    if (classIndex < gExtensionModifierTable_object_5F_t_mergeSubAttributes.count ()) {
      f = gExtensionModifierTable_object_5F_t_mergeSubAttributes (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_object_5F_t_mergeSubAttributes.count ()) {
           f = gExtensionModifierTable_object_5F_t_mergeSubAttributes (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_object_5F_t_mergeSubAttributes.forceObjectAtIndex (classIndex, f, nullptr) ;
    }
    f (inObject, in_withObject, inCompiler COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

static void extensionSetter_object_5F_t_mergeSubAttributes (cPtr_object_5F_t * /* inObject */,
                                                            GALGAS_object_5F_t /* inArgument_withObject */,
                                                            Compiler * /* inCompiler */
                                                            COMMA_UNUSED_LOCATION_ARGS) {
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_object_5F_t_mergeSubAttributes (void) {
  enterExtensionSetter_mergeSubAttributes (kTypeDescriptor_GALGAS_object_5F_t.mSlotID,
                                           extensionSetter_object_5F_t_mergeSubAttributes) ;
}

//--------------------------------------------------------------------------------------------------

static void freeExtensionModifier_object_5F_t_mergeSubAttributes (void) {
  gExtensionModifierTable_object_5F_t_mergeSubAttributes.removeAll () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_object_5F_t_mergeSubAttributes (defineExtensionSetter_object_5F_t_mergeSubAttributes,
                                                         freeExtensionModifier_object_5F_t_mergeSubAttributes) ;

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_void::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void * p = (const cPtr_void *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_void::GALGAS_void (void) :
GALGAS_object_5F_t () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_void::GALGAS_void (const cPtr_void * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_void GALGAS_void::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                         const GALGAS_location & inAttribute_location
                                         COMMA_LOCATION_ARGS) {
  GALGAS_void result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_void (inAttribute_oil_5F_desc, inAttribute_location COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @void class
//--------------------------------------------------------------------------------------------------

cPtr_void::cPtr_void (const GALGAS_lstring & in_oil_5F_desc,
                      const GALGAS_location & in_location
                      COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_void::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void ;
}

void cPtr_void::description (String & ioString,
                             const int32_t inIndentation) const {
  ioString.appendCString ("[@void:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_void::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_void (mProperty_oil_5F_desc, mProperty_location COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @void generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void ("void",
                                                            & kTypeDescriptor_GALGAS_object_5F_t) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_void::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_void::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_void GALGAS_void::extractObject (const GALGAS_object & inObject,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_void result ;
  const GALGAS_void * p = (const GALGAS_void *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_void *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("void", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_auto::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_auto * p = (const cPtr_auto *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_auto) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_auto::GALGAS_auto (void) :
GALGAS_object_5F_t () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_auto::GALGAS_auto (const cPtr_auto * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_auto) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_auto GALGAS_auto::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                         const GALGAS_location & inAttribute_location
                                         COMMA_LOCATION_ARGS) {
  GALGAS_auto result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_auto (inAttribute_oil_5F_desc, inAttribute_location COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @auto class
//--------------------------------------------------------------------------------------------------

cPtr_auto::cPtr_auto (const GALGAS_lstring & in_oil_5F_desc,
                      const GALGAS_location & in_location
                      COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_auto::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_auto ;
}

void cPtr_auto::description (String & ioString,
                             const int32_t inIndentation) const {
  ioString.appendCString ("[@auto:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_auto::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_auto (mProperty_oil_5F_desc, mProperty_location COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @auto generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_auto ("auto",
                                                            & kTypeDescriptor_GALGAS_object_5F_t) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_auto::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_auto ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_auto::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_auto (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_auto GALGAS_auto::extractObject (const GALGAS_object & inObject,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_auto result ;
  const GALGAS_auto * p = (const GALGAS_auto *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_auto *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("auto", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_multipleAttribute::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_multipleAttribute * p = (const cPtr_multipleAttribute *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_multipleAttribute) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_items.objectCompare (p->mProperty_items) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_multipleAttribute::GALGAS_multipleAttribute (void) :
GALGAS_object_5F_t () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_multipleAttribute::GALGAS_multipleAttribute (const cPtr_multipleAttribute * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_multipleAttribute) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_multipleAttribute GALGAS_multipleAttribute::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                   const GALGAS_location & inAttribute_location,
                                                                   const GALGAS_identifierList & inAttribute_items
                                                                   COMMA_LOCATION_ARGS) {
  GALGAS_multipleAttribute result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_items.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_multipleAttribute (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_items COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_identifierList GALGAS_multipleAttribute::readProperty_items (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_identifierList () ;
  }else{
    const cPtr_multipleAttribute * p = (const cPtr_multipleAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_multipleAttribute) ;
    return p->mProperty_items ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_identifierList cPtr_multipleAttribute::getter_items (UNUSED_LOCATION_ARGS) const {
  return mProperty_items ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_multipleAttribute::setter_setItems (GALGAS_identifierList inValue
                                                COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_multipleAttribute * p = (cPtr_multipleAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_multipleAttribute) ;
    p->mProperty_items = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_multipleAttribute::setter_setItems (GALGAS_identifierList inValue
                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_items = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @multipleAttribute class
//--------------------------------------------------------------------------------------------------

cPtr_multipleAttribute::cPtr_multipleAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                                const GALGAS_location & in_location,
                                                const GALGAS_identifierList & in_items
                                                COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_items (in_items) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_multipleAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_multipleAttribute ;
}

void cPtr_multipleAttribute::description (String & ioString,
                                          const int32_t inIndentation) const {
  ioString.appendCString ("[@multipleAttribute:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_items.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_multipleAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_multipleAttribute (mProperty_oil_5F_desc, mProperty_location, mProperty_items COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @multipleAttribute generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_multipleAttribute ("multipleAttribute",
                                                                         & kTypeDescriptor_GALGAS_object_5F_t) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_multipleAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_multipleAttribute ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_multipleAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_multipleAttribute (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_multipleAttribute GALGAS_multipleAttribute::extractObject (const GALGAS_object & inObject,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_multipleAttribute result ;
  const GALGAS_multipleAttribute * p = (const GALGAS_multipleAttribute *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_multipleAttribute *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("multipleAttribute", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_boolAttribute::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_boolAttribute * p = (const cPtr_boolAttribute *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_boolAttribute) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_subAttributes.objectCompare (p->mProperty_subAttributes) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_boolAttribute::GALGAS_boolAttribute (void) :
GALGAS_object_5F_t () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_boolAttribute::GALGAS_boolAttribute (const cPtr_boolAttribute * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_boolAttribute) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_boolAttribute GALGAS_boolAttribute::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
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

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_boolAttribute::readProperty_value (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_boolAttribute * p = (const cPtr_boolAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_boolAttribute) ;
    return p->mProperty_value ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_boolAttribute::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_objectAttributes GALGAS_boolAttribute::readProperty_subAttributes (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_objectAttributes () ;
  }else{
    const cPtr_boolAttribute * p = (const cPtr_boolAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_boolAttribute) ;
    return p->mProperty_subAttributes ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_objectAttributes cPtr_boolAttribute::getter_subAttributes (UNUSED_LOCATION_ARGS) const {
  return mProperty_subAttributes ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_boolAttribute::setter_setValue (GALGAS_bool inValue
                                            COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_boolAttribute * p = (cPtr_boolAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_boolAttribute) ;
    p->mProperty_value = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_boolAttribute::setter_setValue (GALGAS_bool inValue
                                          COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_boolAttribute::setter_setSubAttributes (GALGAS_objectAttributes inValue
                                                    COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_boolAttribute * p = (cPtr_boolAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_boolAttribute) ;
    p->mProperty_subAttributes = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_boolAttribute::setter_setSubAttributes (GALGAS_objectAttributes inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_subAttributes = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @boolAttribute class
//--------------------------------------------------------------------------------------------------

cPtr_boolAttribute::cPtr_boolAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                        const GALGAS_location & in_location,
                                        const GALGAS_bool & in_value,
                                        const GALGAS_objectAttributes & in_subAttributes
                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value),
mProperty_subAttributes (in_subAttributes) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_boolAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_boolAttribute ;
}

void cPtr_boolAttribute::description (String & ioString,
                                      const int32_t inIndentation) const {
  ioString.appendCString ("[@boolAttribute:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_subAttributes.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_boolAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_boolAttribute (mProperty_oil_5F_desc, mProperty_location, mProperty_value, mProperty_subAttributes COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @boolAttribute generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_boolAttribute ("boolAttribute",
                                                                     & kTypeDescriptor_GALGAS_object_5F_t) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_boolAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_boolAttribute ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_boolAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_boolAttribute (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_boolAttribute GALGAS_boolAttribute::extractObject (const GALGAS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_boolAttribute result ;
  const GALGAS_boolAttribute * p = (const GALGAS_boolAttribute *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_boolAttribute *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("boolAttribute", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_enumAttribute::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_enumAttribute * p = (const cPtr_enumAttribute *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_enumAttribute) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_subAttributes.objectCompare (p->mProperty_subAttributes) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_enumAttribute::GALGAS_enumAttribute (void) :
GALGAS_object_5F_t () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_enumAttribute::GALGAS_enumAttribute (const cPtr_enumAttribute * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_enumAttribute) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_enumAttribute GALGAS_enumAttribute::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
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

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_enumAttribute::readProperty_value (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_enumAttribute * p = (const cPtr_enumAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_enumAttribute) ;
    return p->mProperty_value ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_enumAttribute::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_objectAttributes GALGAS_enumAttribute::readProperty_subAttributes (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_objectAttributes () ;
  }else{
    const cPtr_enumAttribute * p = (const cPtr_enumAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_enumAttribute) ;
    return p->mProperty_subAttributes ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_objectAttributes cPtr_enumAttribute::getter_subAttributes (UNUSED_LOCATION_ARGS) const {
  return mProperty_subAttributes ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_enumAttribute::setter_setValue (GALGAS_string inValue
                                            COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_enumAttribute * p = (cPtr_enumAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_enumAttribute) ;
    p->mProperty_value = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_enumAttribute::setter_setValue (GALGAS_string inValue
                                          COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_enumAttribute::setter_setSubAttributes (GALGAS_objectAttributes inValue
                                                    COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_enumAttribute * p = (cPtr_enumAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_enumAttribute) ;
    p->mProperty_subAttributes = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_enumAttribute::setter_setSubAttributes (GALGAS_objectAttributes inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_subAttributes = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @enumAttribute class
//--------------------------------------------------------------------------------------------------

cPtr_enumAttribute::cPtr_enumAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                        const GALGAS_location & in_location,
                                        const GALGAS_string & in_value,
                                        const GALGAS_objectAttributes & in_subAttributes
                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value),
mProperty_subAttributes (in_subAttributes) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_enumAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_enumAttribute ;
}

void cPtr_enumAttribute::description (String & ioString,
                                      const int32_t inIndentation) const {
  ioString.appendCString ("[@enumAttribute:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_subAttributes.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_enumAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_enumAttribute (mProperty_oil_5F_desc, mProperty_location, mProperty_value, mProperty_subAttributes COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @enumAttribute generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_enumAttribute ("enumAttribute",
                                                                     & kTypeDescriptor_GALGAS_object_5F_t) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_enumAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_enumAttribute ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_enumAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_enumAttribute (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_enumAttribute GALGAS_enumAttribute::extractObject (const GALGAS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_enumAttribute result ;
  const GALGAS_enumAttribute * p = (const GALGAS_enumAttribute *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_enumAttribute *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("enumAttribute", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_objectRefAttribute::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_objectRefAttribute * p = (const cPtr_objectRefAttribute *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_objectRefAttribute) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_objectRefAttribute::GALGAS_objectRefAttribute (void) :
GALGAS_object_5F_t () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_objectRefAttribute::GALGAS_objectRefAttribute (const cPtr_objectRefAttribute * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_objectRefAttribute) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_objectRefAttribute GALGAS_objectRefAttribute::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                     const GALGAS_location & inAttribute_location,
                                                                     const GALGAS_lstring & inAttribute_value
                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_objectRefAttribute result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_objectRefAttribute (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_objectRefAttribute::readProperty_value (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_objectRefAttribute * p = (const cPtr_objectRefAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_objectRefAttribute) ;
    return p->mProperty_value ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_objectRefAttribute::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_objectRefAttribute::setter_setValue (GALGAS_lstring inValue
                                                 COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_objectRefAttribute * p = (cPtr_objectRefAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_objectRefAttribute) ;
    p->mProperty_value = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_objectRefAttribute::setter_setValue (GALGAS_lstring inValue
                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @objectRefAttribute class
//--------------------------------------------------------------------------------------------------

cPtr_objectRefAttribute::cPtr_objectRefAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                                  const GALGAS_location & in_location,
                                                  const GALGAS_lstring & in_value
                                                  COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_objectRefAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectRefAttribute ;
}

void cPtr_objectRefAttribute::description (String & ioString,
                                           const int32_t inIndentation) const {
  ioString.appendCString ("[@objectRefAttribute:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_objectRefAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_objectRefAttribute (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @objectRefAttribute generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectRefAttribute ("objectRefAttribute",
                                                                          & kTypeDescriptor_GALGAS_object_5F_t) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_objectRefAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectRefAttribute ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_objectRefAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectRefAttribute (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_objectRefAttribute GALGAS_objectRefAttribute::extractObject (const GALGAS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_objectRefAttribute result ;
  const GALGAS_objectRefAttribute * p = (const GALGAS_objectRefAttribute *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_objectRefAttribute *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectRefAttribute", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_uint_33__32__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_33__32__5F_class * p = (const cPtr_uint_33__32__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_33__32__5F_class) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_uint_33__32__5F_class::GALGAS_uint_33__32__5F_class (void) :
GALGAS_object_5F_t () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint_33__32__5F_class::GALGAS_uint_33__32__5F_class (const cPtr_uint_33__32__5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_33__32__5F_class) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_uint_33__32__5F_class GALGAS_uint_33__32__5F_class::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                           const GALGAS_location & inAttribute_location,
                                                                           const GALGAS_uint & inAttribute_value
                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_33__32__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_uint_33__32__5F_class::readProperty_value (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    const cPtr_uint_33__32__5F_class * p = (const cPtr_uint_33__32__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32__5F_class) ;
    return p->mProperty_value ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_uint_33__32__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32__5F_class::setter_setValue (GALGAS_uint inValue
                                                    COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_uint_33__32__5F_class * p = (cPtr_uint_33__32__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32__5F_class) ;
    p->mProperty_value = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_uint_33__32__5F_class::setter_setValue (GALGAS_uint inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @uint32_class class
//--------------------------------------------------------------------------------------------------

cPtr_uint_33__32__5F_class::cPtr_uint_33__32__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                        const GALGAS_location & in_location,
                                                        const GALGAS_uint & in_value
                                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_uint_33__32__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32__5F_class ;
}

void cPtr_uint_33__32__5F_class::description (String & ioString,
                                              const int32_t inIndentation) const {
  ioString.appendCString ("[@uint32_class:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_uint_33__32__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_uint_33__32__5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @uint32_class generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uint_33__32__5F_class ("uint32_class",
                                                                             & kTypeDescriptor_GALGAS_object_5F_t) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_33__32__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32__5F_class ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_33__32__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_33__32__5F_class (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint_33__32__5F_class GALGAS_uint_33__32__5F_class::extractObject (const GALGAS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32__5F_class result ;
  const GALGAS_uint_33__32__5F_class * p = (const GALGAS_uint_33__32__5F_class *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_uint_33__32__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint32_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_sint_33__32__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_33__32__5F_class * p = (const cPtr_sint_33__32__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_33__32__5F_class) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_sint_33__32__5F_class::GALGAS_sint_33__32__5F_class (void) :
GALGAS_object_5F_t () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_sint_33__32__5F_class::GALGAS_sint_33__32__5F_class (const cPtr_sint_33__32__5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_33__32__5F_class) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_sint_33__32__5F_class GALGAS_sint_33__32__5F_class::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                           const GALGAS_location & inAttribute_location,
                                                                           const GALGAS_sint & inAttribute_value
                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sint_33__32__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint_33__32__5F_class::readProperty_value (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_sint () ;
  }else{
    const cPtr_sint_33__32__5F_class * p = (const cPtr_sint_33__32__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32__5F_class) ;
    return p->mProperty_value ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_sint cPtr_sint_33__32__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32__5F_class::setter_setValue (GALGAS_sint inValue
                                                    COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_sint_33__32__5F_class * p = (cPtr_sint_33__32__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32__5F_class) ;
    p->mProperty_value = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_sint_33__32__5F_class::setter_setValue (GALGAS_sint inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @sint32_class class
//--------------------------------------------------------------------------------------------------

cPtr_sint_33__32__5F_class::cPtr_sint_33__32__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                        const GALGAS_location & in_location,
                                                        const GALGAS_sint & in_value
                                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_sint_33__32__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32__5F_class ;
}

void cPtr_sint_33__32__5F_class::description (String & ioString,
                                              const int32_t inIndentation) const {
  ioString.appendCString ("[@sint32_class:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_sint_33__32__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_sint_33__32__5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @sint32_class generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sint_33__32__5F_class ("sint32_class",
                                                                             & kTypeDescriptor_GALGAS_object_5F_t) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sint_33__32__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32__5F_class ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sint_33__32__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_33__32__5F_class (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_sint_33__32__5F_class GALGAS_sint_33__32__5F_class::extractObject (const GALGAS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32__5F_class result ;
  const GALGAS_sint_33__32__5F_class * p = (const GALGAS_sint_33__32__5F_class *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_sint_33__32__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint32_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_uint_36__34__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_36__34__5F_class * p = (const cPtr_uint_36__34__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_36__34__5F_class) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_uint_36__34__5F_class::GALGAS_uint_36__34__5F_class (void) :
GALGAS_object_5F_t () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint_36__34__5F_class::GALGAS_uint_36__34__5F_class (const cPtr_uint_36__34__5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_36__34__5F_class) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_uint_36__34__5F_class GALGAS_uint_36__34__5F_class::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                           const GALGAS_location & inAttribute_location,
                                                                           const GALGAS_uint_36__34_ & inAttribute_value
                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_36__34__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ GALGAS_uint_36__34__5F_class::readProperty_value (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint_36__34_ () ;
  }else{
    const cPtr_uint_36__34__5F_class * p = (const cPtr_uint_36__34__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34__5F_class) ;
    return p->mProperty_value ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ cPtr_uint_36__34__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34__5F_class::setter_setValue (GALGAS_uint_36__34_ inValue
                                                    COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_uint_36__34__5F_class * p = (cPtr_uint_36__34__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34__5F_class) ;
    p->mProperty_value = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_uint_36__34__5F_class::setter_setValue (GALGAS_uint_36__34_ inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @uint64_class class
//--------------------------------------------------------------------------------------------------

cPtr_uint_36__34__5F_class::cPtr_uint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                        const GALGAS_location & in_location,
                                                        const GALGAS_uint_36__34_ & in_value
                                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_uint_36__34__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34__5F_class ;
}

void cPtr_uint_36__34__5F_class::description (String & ioString,
                                              const int32_t inIndentation) const {
  ioString.appendCString ("[@uint64_class:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_uint_36__34__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_uint_36__34__5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @uint64_class generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uint_36__34__5F_class ("uint64_class",
                                                                             & kTypeDescriptor_GALGAS_object_5F_t) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_36__34__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34__5F_class ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_36__34__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34__5F_class (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint_36__34__5F_class GALGAS_uint_36__34__5F_class::extractObject (const GALGAS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34__5F_class result ;
  const GALGAS_uint_36__34__5F_class * p = (const GALGAS_uint_36__34__5F_class *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_uint_36__34__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_sint_36__34__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_36__34__5F_class * p = (const cPtr_sint_36__34__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_36__34__5F_class) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_sint_36__34__5F_class::GALGAS_sint_36__34__5F_class (void) :
GALGAS_object_5F_t () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_sint_36__34__5F_class::GALGAS_sint_36__34__5F_class (const cPtr_sint_36__34__5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_36__34__5F_class) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_sint_36__34__5F_class GALGAS_sint_36__34__5F_class::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                           const GALGAS_location & inAttribute_location,
                                                                           const GALGAS_sint_36__34_ & inAttribute_value
                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sint_36__34__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34__5F_class::readProperty_value (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_sint_36__34_ () ;
  }else{
    const cPtr_sint_36__34__5F_class * p = (const cPtr_sint_36__34__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34__5F_class) ;
    return p->mProperty_value ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ cPtr_sint_36__34__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34__5F_class::setter_setValue (GALGAS_sint_36__34_ inValue
                                                    COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_sint_36__34__5F_class * p = (cPtr_sint_36__34__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34__5F_class) ;
    p->mProperty_value = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_sint_36__34__5F_class::setter_setValue (GALGAS_sint_36__34_ inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @sint64_class class
//--------------------------------------------------------------------------------------------------

cPtr_sint_36__34__5F_class::cPtr_sint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                        const GALGAS_location & in_location,
                                                        const GALGAS_sint_36__34_ & in_value
                                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_sint_36__34__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34__5F_class ;
}

void cPtr_sint_36__34__5F_class::description (String & ioString,
                                              const int32_t inIndentation) const {
  ioString.appendCString ("[@sint64_class:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_sint_36__34__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_sint_36__34__5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @sint64_class generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sint_36__34__5F_class ("sint64_class",
                                                                             & kTypeDescriptor_GALGAS_object_5F_t) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sint_36__34__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34__5F_class ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sint_36__34__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_36__34__5F_class (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_sint_36__34__5F_class GALGAS_sint_36__34__5F_class::extractObject (const GALGAS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34__5F_class result ;
  const GALGAS_sint_36__34__5F_class * p = (const GALGAS_sint_36__34__5F_class *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_sint_36__34__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint64_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_float_5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_float_5F_class * p = (const cPtr_float_5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_float_5F_class) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_float_5F_class::GALGAS_float_5F_class (void) :
GALGAS_object_5F_t () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_float_5F_class::GALGAS_float_5F_class (const cPtr_float_5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_float_5F_class) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_float_5F_class GALGAS_float_5F_class::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                             const GALGAS_location & inAttribute_location,
                                                             const GALGAS_double & inAttribute_value
                                                             COMMA_LOCATION_ARGS) {
  GALGAS_float_5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_float_5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_float_5F_class::readProperty_value (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_double () ;
  }else{
    const cPtr_float_5F_class * p = (const cPtr_float_5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_float_5F_class) ;
    return p->mProperty_value ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_double cPtr_float_5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_float_5F_class::setter_setValue (GALGAS_double inValue
                                             COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_float_5F_class * p = (cPtr_float_5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_float_5F_class) ;
    p->mProperty_value = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_float_5F_class::setter_setValue (GALGAS_double inValue
                                           COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @float_class class
//--------------------------------------------------------------------------------------------------

cPtr_float_5F_class::cPtr_float_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                          const GALGAS_location & in_location,
                                          const GALGAS_double & in_value
                                          COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_float_5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_float_5F_class ;
}

void cPtr_float_5F_class::description (String & ioString,
                                       const int32_t inIndentation) const {
  ioString.appendCString ("[@float_class:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_float_5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_float_5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @float_class generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_float_5F_class ("float_class",
                                                                      & kTypeDescriptor_GALGAS_object_5F_t) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_float_5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_float_5F_class ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_float_5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_float_5F_class (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_float_5F_class GALGAS_float_5F_class::extractObject (const GALGAS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_float_5F_class result ;
  const GALGAS_float_5F_class * p = (const GALGAS_float_5F_class *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_float_5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("float_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_string_5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_string_5F_class * p = (const cPtr_string_5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_string_5F_class) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_string_5F_class::GALGAS_string_5F_class (void) :
GALGAS_object_5F_t () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_string_5F_class::GALGAS_string_5F_class (const cPtr_string_5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_string_5F_class) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_string_5F_class GALGAS_string_5F_class::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                               const GALGAS_location & inAttribute_location,
                                                               const GALGAS_string & inAttribute_value
                                                               COMMA_LOCATION_ARGS) {
  GALGAS_string_5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_string_5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string_5F_class::readProperty_value (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_string_5F_class * p = (const cPtr_string_5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_string_5F_class) ;
    return p->mProperty_value ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_string_5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string_5F_class::setter_setValue (GALGAS_string inValue
                                              COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_string_5F_class * p = (cPtr_string_5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_string_5F_class) ;
    p->mProperty_value = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_string_5F_class::setter_setValue (GALGAS_string inValue
                                            COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @string_class class
//--------------------------------------------------------------------------------------------------

cPtr_string_5F_class::cPtr_string_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                            const GALGAS_location & in_location,
                                            const GALGAS_string & in_value
                                            COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_string_5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_string_5F_class ;
}

void cPtr_string_5F_class::description (String & ioString,
                                        const int32_t inIndentation) const {
  ioString.appendCString ("[@string_class:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_string_5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_string_5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @string_class generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_string_5F_class ("string_class",
                                                                       & kTypeDescriptor_GALGAS_object_5F_t) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_string_5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_string_5F_class ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_string_5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_string_5F_class (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string_5F_class GALGAS_string_5F_class::extractObject (const GALGAS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_string_5F_class result ;
  const GALGAS_string_5F_class * p = (const GALGAS_string_5F_class *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_string_5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("string_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_stringAttribute::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_stringAttribute * p = (const cPtr_stringAttribute *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_stringAttribute) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_stringAttribute::GALGAS_stringAttribute (void) :
GALGAS_object_5F_t () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_stringAttribute::GALGAS_stringAttribute (const cPtr_stringAttribute * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_stringAttribute) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_stringAttribute GALGAS_stringAttribute::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                               const GALGAS_location & inAttribute_location,
                                                               const GALGAS_string & inAttribute_value
                                                               COMMA_LOCATION_ARGS) {
  GALGAS_stringAttribute result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_stringAttribute (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_stringAttribute::readProperty_value (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_stringAttribute * p = (const cPtr_stringAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_stringAttribute) ;
    return p->mProperty_value ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_stringAttribute::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_stringAttribute::setter_setValue (GALGAS_string inValue
                                              COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_stringAttribute * p = (cPtr_stringAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_stringAttribute) ;
    p->mProperty_value = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_stringAttribute::setter_setValue (GALGAS_string inValue
                                            COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @stringAttribute class
//--------------------------------------------------------------------------------------------------

cPtr_stringAttribute::cPtr_stringAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                            const GALGAS_location & in_location,
                                            const GALGAS_string & in_value
                                            COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_stringAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringAttribute ;
}

void cPtr_stringAttribute::description (String & ioString,
                                        const int32_t inIndentation) const {
  ioString.appendCString ("[@stringAttribute:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_stringAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_stringAttribute (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @stringAttribute generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringAttribute ("stringAttribute",
                                                                       & kTypeDescriptor_GALGAS_object_5F_t) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_stringAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringAttribute ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_stringAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringAttribute (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_stringAttribute GALGAS_stringAttribute::extractObject (const GALGAS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_stringAttribute result ;
  const GALGAS_stringAttribute * p = (const GALGAS_stringAttribute *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_stringAttribute *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringAttribute", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_structAttribute::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_structAttribute * p = (const cPtr_structAttribute *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_structAttribute) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_structName.objectCompare (p->mProperty_structName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_subAttributes.objectCompare (p->mProperty_subAttributes) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_structAttribute::GALGAS_structAttribute (void) :
GALGAS_object_5F_t () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_structAttribute::GALGAS_structAttribute (const cPtr_structAttribute * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_structAttribute) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_structAttribute GALGAS_structAttribute::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
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

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_structAttribute::readProperty_structName (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_structAttribute * p = (const cPtr_structAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_structAttribute) ;
    return p->mProperty_structName ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_structAttribute::getter_structName (UNUSED_LOCATION_ARGS) const {
  return mProperty_structName ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_objectAttributes GALGAS_structAttribute::readProperty_subAttributes (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_objectAttributes () ;
  }else{
    const cPtr_structAttribute * p = (const cPtr_structAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_structAttribute) ;
    return p->mProperty_subAttributes ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_objectAttributes cPtr_structAttribute::getter_subAttributes (UNUSED_LOCATION_ARGS) const {
  return mProperty_subAttributes ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_structAttribute::setter_setStructName (GALGAS_lstring inValue
                                                   COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_structAttribute * p = (cPtr_structAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_structAttribute) ;
    p->mProperty_structName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_structAttribute::setter_setStructName (GALGAS_lstring inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_structName = inValue ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_structAttribute::setter_setSubAttributes (GALGAS_objectAttributes inValue
                                                      COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_structAttribute * p = (cPtr_structAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_structAttribute) ;
    p->mProperty_subAttributes = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_structAttribute::setter_setSubAttributes (GALGAS_objectAttributes inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_subAttributes = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @structAttribute class
//--------------------------------------------------------------------------------------------------

cPtr_structAttribute::cPtr_structAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                            const GALGAS_location & in_location,
                                            const GALGAS_lstring & in_structName,
                                            const GALGAS_objectAttributes & in_subAttributes
                                            COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_structName (in_structName),
mProperty_subAttributes (in_subAttributes) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_structAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_structAttribute ;
}

void cPtr_structAttribute::description (String & ioString,
                                        const int32_t inIndentation) const {
  ioString.appendCString ("[@structAttribute:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_structName.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_subAttributes.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_structAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_structAttribute (mProperty_oil_5F_desc, mProperty_location, mProperty_structName, mProperty_subAttributes COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @structAttribute generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_structAttribute ("structAttribute",
                                                                       & kTypeDescriptor_GALGAS_object_5F_t) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_structAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_structAttribute ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_structAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_structAttribute (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_structAttribute GALGAS_structAttribute::extractObject (const GALGAS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_structAttribute result ;
  const GALGAS_structAttribute * p = (const GALGAS_structAttribute *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_structAttribute *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("structAttribute", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_bool_5F_t::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_bool_5F_t * p = (const cPtr_bool_5F_t *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_bool_5F_t) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_bool_5F_t::GALGAS_bool_5F_t (void) :
GALGAS_object_5F_t () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool_5F_t::GALGAS_bool_5F_t (const cPtr_bool_5F_t * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_bool_5F_t) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_bool_5F_t GALGAS_bool_5F_t::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                   const GALGAS_location & inAttribute_location,
                                                   const GALGAS_bool & inAttribute_value
                                                   COMMA_LOCATION_ARGS) {
  GALGAS_bool_5F_t result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_bool_5F_t (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_bool_5F_t::readProperty_value (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_bool_5F_t * p = (const cPtr_bool_5F_t *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_bool_5F_t) ;
    return p->mProperty_value ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_bool_5F_t::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_bool_5F_t::setter_setValue (GALGAS_bool inValue
                                        COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_bool_5F_t * p = (cPtr_bool_5F_t *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_bool_5F_t) ;
    p->mProperty_value = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void cPtr_bool_5F_t::setter_setValue (GALGAS_bool inValue
                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @bool_t class
//--------------------------------------------------------------------------------------------------

cPtr_bool_5F_t::cPtr_bool_5F_t (const GALGAS_lstring & in_oil_5F_desc,
                                const GALGAS_location & in_location,
                                const GALGAS_bool & in_value
                                COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_bool_5F_t::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_bool_5F_t ;
}

void cPtr_bool_5F_t::description (String & ioString,
                                  const int32_t inIndentation) const {
  ioString.appendCString ("[@bool_t:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_bool_5F_t::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_bool_5F_t (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @bool_t generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_bool_5F_t ("bool_t",
                                                                 & kTypeDescriptor_GALGAS_object_5F_t) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_bool_5F_t::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_bool_5F_t ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_bool_5F_t::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_bool_5F_t (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool_5F_t GALGAS_bool_5F_t::extractObject (const GALGAS_object & inObject,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_bool_5F_t result ;
  const GALGAS_bool_5F_t * p = (const GALGAS_bool_5F_t *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_bool_5F_t *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("bool_t", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_void_5F_uint_33__32__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void_5F_uint_33__32__5F_class * p = (const cPtr_void_5F_uint_33__32__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void_5F_uint_33__32__5F_class) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_33__32__5F_class::GALGAS_void_5F_uint_33__32__5F_class (void) :
GALGAS_uint_33__32__5F_class () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_33__32__5F_class::GALGAS_void_5F_uint_33__32__5F_class (const cPtr_void_5F_uint_33__32__5F_class * inSourcePtr) :
GALGAS_uint_33__32__5F_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_uint_33__32__5F_class) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_33__32__5F_class GALGAS_void_5F_uint_33__32__5F_class::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                                           const GALGAS_location & inAttribute_location,
                                                                                           const GALGAS_uint & inAttribute_value
                                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_uint_33__32__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_void_5F_uint_33__32__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @void_uint32_class class
//--------------------------------------------------------------------------------------------------

cPtr_void_5F_uint_33__32__5F_class::cPtr_void_5F_uint_33__32__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                                        const GALGAS_location & in_location,
                                                                        const GALGAS_uint & in_value
                                                                        COMMA_LOCATION_ARGS) :
cPtr_uint_33__32__5F_class (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_void_5F_uint_33__32__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_uint_33__32__5F_class ;
}

void cPtr_void_5F_uint_33__32__5F_class::description (String & ioString,
                                                      const int32_t inIndentation) const {
  ioString.appendCString ("[@void_uint32_class:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_void_5F_uint_33__32__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_void_5F_uint_33__32__5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @void_uint32_class generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void_5F_uint_33__32__5F_class ("void_uint32_class",
                                                                                     & kTypeDescriptor_GALGAS_uint_33__32__5F_class) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_void_5F_uint_33__32__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_uint_33__32__5F_class ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_void_5F_uint_33__32__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_uint_33__32__5F_class (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_33__32__5F_class GALGAS_void_5F_uint_33__32__5F_class::extractObject (const GALGAS_object & inObject,
                                                                                          Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_uint_33__32__5F_class result ;
  const GALGAS_void_5F_uint_33__32__5F_class * p = (const GALGAS_void_5F_uint_33__32__5F_class *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_void_5F_uint_33__32__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("void_uint32_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_void_5F_sint_33__32__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void_5F_sint_33__32__5F_class * p = (const cPtr_void_5F_sint_33__32__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void_5F_sint_33__32__5F_class) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_void_5F_sint_33__32__5F_class::GALGAS_void_5F_sint_33__32__5F_class (void) :
GALGAS_sint_33__32__5F_class () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_void_5F_sint_33__32__5F_class::GALGAS_void_5F_sint_33__32__5F_class (const cPtr_void_5F_sint_33__32__5F_class * inSourcePtr) :
GALGAS_sint_33__32__5F_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_sint_33__32__5F_class) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_void_5F_sint_33__32__5F_class GALGAS_void_5F_sint_33__32__5F_class::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                                           const GALGAS_location & inAttribute_location,
                                                                                           const GALGAS_sint & inAttribute_value
                                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_sint_33__32__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_void_5F_sint_33__32__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @void_sint32_class class
//--------------------------------------------------------------------------------------------------

cPtr_void_5F_sint_33__32__5F_class::cPtr_void_5F_sint_33__32__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                                        const GALGAS_location & in_location,
                                                                        const GALGAS_sint & in_value
                                                                        COMMA_LOCATION_ARGS) :
cPtr_sint_33__32__5F_class (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_void_5F_sint_33__32__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_sint_33__32__5F_class ;
}

void cPtr_void_5F_sint_33__32__5F_class::description (String & ioString,
                                                      const int32_t inIndentation) const {
  ioString.appendCString ("[@void_sint32_class:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_void_5F_sint_33__32__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_void_5F_sint_33__32__5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @void_sint32_class generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void_5F_sint_33__32__5F_class ("void_sint32_class",
                                                                                     & kTypeDescriptor_GALGAS_sint_33__32__5F_class) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_void_5F_sint_33__32__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_sint_33__32__5F_class ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_void_5F_sint_33__32__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_sint_33__32__5F_class (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_void_5F_sint_33__32__5F_class GALGAS_void_5F_sint_33__32__5F_class::extractObject (const GALGAS_object & inObject,
                                                                                          Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_sint_33__32__5F_class result ;
  const GALGAS_void_5F_sint_33__32__5F_class * p = (const GALGAS_void_5F_sint_33__32__5F_class *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_void_5F_sint_33__32__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("void_sint32_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//--------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_void_5F_uint_36__34__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void_5F_uint_36__34__5F_class * p = (const cPtr_void_5F_uint_36__34__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void_5F_uint_36__34__5F_class) ;
  if (kOperandEqual == result) {
    result = mProperty_oil_5F_desc.objectCompare (p->mProperty_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


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

//--------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_36__34__5F_class::GALGAS_void_5F_uint_36__34__5F_class (void) :
GALGAS_uint_36__34__5F_class () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_36__34__5F_class::GALGAS_void_5F_uint_36__34__5F_class (const cPtr_void_5F_uint_36__34__5F_class * inSourcePtr) :
GALGAS_uint_36__34__5F_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_uint_36__34__5F_class) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_36__34__5F_class GALGAS_void_5F_uint_36__34__5F_class::class_func_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                                           const GALGAS_location & inAttribute_location,
                                                                                           const GALGAS_uint_36__34_ & inAttribute_value
                                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_uint_36__34__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_void_5F_uint_36__34__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @void_uint64_class class
//--------------------------------------------------------------------------------------------------

cPtr_void_5F_uint_36__34__5F_class::cPtr_void_5F_uint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                                        const GALGAS_location & in_location,
                                                                        const GALGAS_uint_36__34_ & in_value
                                                                        COMMA_LOCATION_ARGS) :
cPtr_uint_36__34__5F_class (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_void_5F_uint_36__34__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_uint_36__34__5F_class ;
}

void cPtr_void_5F_uint_36__34__5F_class::description (String & ioString,
                                                      const int32_t inIndentation) const {
  ioString.appendCString ("[@void_uint64_class:") ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_void_5F_uint_36__34__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_void_5F_uint_36__34__5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @void_uint64_class generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void_5F_uint_36__34__5F_class ("void_uint64_class",
                                                                                     & kTypeDescriptor_GALGAS_uint_36__34__5F_class) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_void_5F_uint_36__34__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_uint_36__34__5F_class ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_void_5F_uint_36__34__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_uint_36__34__5F_class (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_36__34__5F_class GALGAS_void_5F_uint_36__34__5F_class::extractObject (const GALGAS_object & inObject,
                                                                                          Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_uint_36__34__5F_class result ;
  const GALGAS_void_5F_uint_36__34__5F_class * p = (const GALGAS_void_5F_uint_36__34__5F_class *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_void_5F_uint_36__34__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("void_uint64_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}


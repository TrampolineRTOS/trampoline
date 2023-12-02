#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-2.h"

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_uint_36__34_AttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_36__34_AttributeMinMax * p = (const cPtr_uint_36__34_AttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_36__34_AttributeMinMax) ;
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


typeComparisonResult GALGAS_uint_36__34_AttributeMinMax::objectCompare (const GALGAS_uint_36__34_AttributeMinMax & inOperand) const {
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

GALGAS_uint_36__34_AttributeMinMax::GALGAS_uint_36__34_AttributeMinMax (void) :
GALGAS_attributeRange () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_AttributeMinMax GALGAS_uint_36__34_AttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                              GALGAS_uint_36__34_::constructor_default (HERE),
                                                              GALGAS_uint_36__34_::constructor_default (HERE)
                                                              COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_AttributeMinMax::GALGAS_uint_36__34_AttributeMinMax (const cPtr_uint_36__34_AttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_36__34_AttributeMinMax) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_AttributeMinMax GALGAS_uint_36__34_AttributeMinMax::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                        const GALGAS_uint_36__34_ & inAttribute_min,
                                                                                        const GALGAS_uint_36__34_ & inAttribute_max
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_AttributeMinMax result ;
  if (inAttribute_location.isValid () && inAttribute_min.isValid () && inAttribute_max.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_36__34_AttributeMinMax (inAttribute_location, inAttribute_min, inAttribute_max COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ GALGAS_uint_36__34_AttributeMinMax::readProperty_min (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint_36__34_ () ;
  }else{
    const cPtr_uint_36__34_AttributeMinMax * p = (const cPtr_uint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34_AttributeMinMax) ;
    return p->mProperty_min ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ cPtr_uint_36__34_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mProperty_min ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ GALGAS_uint_36__34_AttributeMinMax::readProperty_max (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint_36__34_ () ;
  }else{
    const cPtr_uint_36__34_AttributeMinMax * p = (const cPtr_uint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34_AttributeMinMax) ;
    return p->mProperty_max ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ cPtr_uint_36__34_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mProperty_max ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_AttributeMinMax::setter_setMin (GALGAS_uint_36__34_ inValue
                                                        COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_uint_36__34_AttributeMinMax * p = (cPtr_uint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34_AttributeMinMax) ;
    p->mProperty_min = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_uint_36__34_AttributeMinMax::setter_setMin (GALGAS_uint_36__34_ inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_min = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_AttributeMinMax::setter_setMax (GALGAS_uint_36__34_ inValue
                                                        COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_uint_36__34_AttributeMinMax * p = (cPtr_uint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34_AttributeMinMax) ;
    p->mProperty_max = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_uint_36__34_AttributeMinMax::setter_setMax (GALGAS_uint_36__34_ inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_max = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @uint64AttributeMinMax class
//----------------------------------------------------------------------------------------------------------------------

cPtr_uint_36__34_AttributeMinMax::cPtr_uint_36__34_AttributeMinMax (const GALGAS_location & in_location,
                                                                    const GALGAS_uint_36__34_ & in_min,
                                                                    const GALGAS_uint_36__34_ & in_max
                                                                    COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mProperty_min (in_min),
mProperty_max (in_max) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_uint_36__34_AttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax ;
}

void cPtr_uint_36__34_AttributeMinMax::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@uint64AttributeMinMax:" ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_uint_36__34_AttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_uint_36__34_AttributeMinMax (mProperty_location, mProperty_min, mProperty_max COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @uint64AttributeMinMax generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax ("uint64AttributeMinMax",
                                                    & kTypeDescriptor_GALGAS_attributeRange) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_36__34_AttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_36__34_AttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34_AttributeMinMax (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_AttributeMinMax GALGAS_uint_36__34_AttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_AttributeMinMax result ;
  const GALGAS_uint_36__34_AttributeMinMax * p = (const GALGAS_uint_36__34_AttributeMinMax *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_uint_36__34_AttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64AttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_sint_33__32_AttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_33__32_AttributeMinMax * p = (const cPtr_sint_33__32_AttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_33__32_AttributeMinMax) ;
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


typeComparisonResult GALGAS_sint_33__32_AttributeMinMax::objectCompare (const GALGAS_sint_33__32_AttributeMinMax & inOperand) const {
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

GALGAS_sint_33__32_AttributeMinMax::GALGAS_sint_33__32_AttributeMinMax (void) :
GALGAS_attributeRange () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_AttributeMinMax GALGAS_sint_33__32_AttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                              GALGAS_sint::constructor_default (HERE),
                                                              GALGAS_sint::constructor_default (HERE)
                                                              COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_AttributeMinMax::GALGAS_sint_33__32_AttributeMinMax (const cPtr_sint_33__32_AttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_33__32_AttributeMinMax) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_AttributeMinMax GALGAS_sint_33__32_AttributeMinMax::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                        const GALGAS_sint & inAttribute_min,
                                                                                        const GALGAS_sint & inAttribute_max
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_AttributeMinMax result ;
  if (inAttribute_location.isValid () && inAttribute_min.isValid () && inAttribute_max.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sint_33__32_AttributeMinMax (inAttribute_location, inAttribute_min, inAttribute_max COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint_33__32_AttributeMinMax::readProperty_min (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_sint () ;
  }else{
    const cPtr_sint_33__32_AttributeMinMax * p = (const cPtr_sint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32_AttributeMinMax) ;
    return p->mProperty_min ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint cPtr_sint_33__32_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mProperty_min ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint_33__32_AttributeMinMax::readProperty_max (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_sint () ;
  }else{
    const cPtr_sint_33__32_AttributeMinMax * p = (const cPtr_sint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32_AttributeMinMax) ;
    return p->mProperty_max ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint cPtr_sint_33__32_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mProperty_max ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_AttributeMinMax::setter_setMin (GALGAS_sint inValue
                                                        COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_sint_33__32_AttributeMinMax * p = (cPtr_sint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32_AttributeMinMax) ;
    p->mProperty_min = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_sint_33__32_AttributeMinMax::setter_setMin (GALGAS_sint inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_min = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_AttributeMinMax::setter_setMax (GALGAS_sint inValue
                                                        COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_sint_33__32_AttributeMinMax * p = (cPtr_sint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32_AttributeMinMax) ;
    p->mProperty_max = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_sint_33__32_AttributeMinMax::setter_setMax (GALGAS_sint inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_max = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @sint32AttributeMinMax class
//----------------------------------------------------------------------------------------------------------------------

cPtr_sint_33__32_AttributeMinMax::cPtr_sint_33__32_AttributeMinMax (const GALGAS_location & in_location,
                                                                    const GALGAS_sint & in_min,
                                                                    const GALGAS_sint & in_max
                                                                    COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mProperty_min (in_min),
mProperty_max (in_max) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_sint_33__32_AttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax ;
}

void cPtr_sint_33__32_AttributeMinMax::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@sint32AttributeMinMax:" ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_sint_33__32_AttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_sint_33__32_AttributeMinMax (mProperty_location, mProperty_min, mProperty_max COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @sint32AttributeMinMax generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax ("sint32AttributeMinMax",
                                                    & kTypeDescriptor_GALGAS_attributeRange) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sint_33__32_AttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sint_33__32_AttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_33__32_AttributeMinMax (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_AttributeMinMax GALGAS_sint_33__32_AttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_AttributeMinMax result ;
  const GALGAS_sint_33__32_AttributeMinMax * p = (const GALGAS_sint_33__32_AttributeMinMax *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_sint_33__32_AttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint32AttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_sint_36__34_AttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_36__34_AttributeMinMax * p = (const cPtr_sint_36__34_AttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_36__34_AttributeMinMax) ;
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


typeComparisonResult GALGAS_sint_36__34_AttributeMinMax::objectCompare (const GALGAS_sint_36__34_AttributeMinMax & inOperand) const {
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

GALGAS_sint_36__34_AttributeMinMax::GALGAS_sint_36__34_AttributeMinMax (void) :
GALGAS_attributeRange () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_AttributeMinMax GALGAS_sint_36__34_AttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                              GALGAS_sint_36__34_::constructor_default (HERE),
                                                              GALGAS_sint_36__34_::constructor_default (HERE)
                                                              COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_AttributeMinMax::GALGAS_sint_36__34_AttributeMinMax (const cPtr_sint_36__34_AttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_36__34_AttributeMinMax) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_AttributeMinMax GALGAS_sint_36__34_AttributeMinMax::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                        const GALGAS_sint_36__34_ & inAttribute_min,
                                                                                        const GALGAS_sint_36__34_ & inAttribute_max
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_AttributeMinMax result ;
  if (inAttribute_location.isValid () && inAttribute_min.isValid () && inAttribute_max.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sint_36__34_AttributeMinMax (inAttribute_location, inAttribute_min, inAttribute_max COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_AttributeMinMax::readProperty_min (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_sint_36__34_ () ;
  }else{
    const cPtr_sint_36__34_AttributeMinMax * p = (const cPtr_sint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34_AttributeMinMax) ;
    return p->mProperty_min ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ cPtr_sint_36__34_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mProperty_min ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_AttributeMinMax::readProperty_max (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_sint_36__34_ () ;
  }else{
    const cPtr_sint_36__34_AttributeMinMax * p = (const cPtr_sint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34_AttributeMinMax) ;
    return p->mProperty_max ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ cPtr_sint_36__34_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mProperty_max ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_AttributeMinMax::setter_setMin (GALGAS_sint_36__34_ inValue
                                                        COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_sint_36__34_AttributeMinMax * p = (cPtr_sint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34_AttributeMinMax) ;
    p->mProperty_min = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_sint_36__34_AttributeMinMax::setter_setMin (GALGAS_sint_36__34_ inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_min = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_AttributeMinMax::setter_setMax (GALGAS_sint_36__34_ inValue
                                                        COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_sint_36__34_AttributeMinMax * p = (cPtr_sint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34_AttributeMinMax) ;
    p->mProperty_max = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_sint_36__34_AttributeMinMax::setter_setMax (GALGAS_sint_36__34_ inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_max = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @sint64AttributeMinMax class
//----------------------------------------------------------------------------------------------------------------------

cPtr_sint_36__34_AttributeMinMax::cPtr_sint_36__34_AttributeMinMax (const GALGAS_location & in_location,
                                                                    const GALGAS_sint_36__34_ & in_min,
                                                                    const GALGAS_sint_36__34_ & in_max
                                                                    COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mProperty_min (in_min),
mProperty_max (in_max) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_sint_36__34_AttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax ;
}

void cPtr_sint_36__34_AttributeMinMax::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@sint64AttributeMinMax:" ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_sint_36__34_AttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_sint_36__34_AttributeMinMax (mProperty_location, mProperty_min, mProperty_max COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @sint64AttributeMinMax generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax ("sint64AttributeMinMax",
                                                    & kTypeDescriptor_GALGAS_attributeRange) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sint_36__34_AttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sint_36__34_AttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_36__34_AttributeMinMax (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_AttributeMinMax GALGAS_sint_36__34_AttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_AttributeMinMax result ;
  const GALGAS_sint_36__34_AttributeMinMax * p = (const GALGAS_sint_36__34_AttributeMinMax *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_sint_36__34_AttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint64AttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_floatAttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_floatAttributeMinMax * p = (const cPtr_floatAttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_floatAttributeMinMax) ;
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


typeComparisonResult GALGAS_floatAttributeMinMax::objectCompare (const GALGAS_floatAttributeMinMax & inOperand) const {
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

GALGAS_floatAttributeMinMax::GALGAS_floatAttributeMinMax (void) :
GALGAS_attributeRange () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatAttributeMinMax GALGAS_floatAttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_floatAttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                       GALGAS_double::constructor_default (HERE),
                                                       GALGAS_double::constructor_default (HERE)
                                                       COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatAttributeMinMax::GALGAS_floatAttributeMinMax (const cPtr_floatAttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_floatAttributeMinMax) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatAttributeMinMax GALGAS_floatAttributeMinMax::constructor_new (const GALGAS_location & inAttribute_location,
                                                                          const GALGAS_double & inAttribute_min,
                                                                          const GALGAS_double & inAttribute_max
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_floatAttributeMinMax result ;
  if (inAttribute_location.isValid () && inAttribute_min.isValid () && inAttribute_max.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_floatAttributeMinMax (inAttribute_location, inAttribute_min, inAttribute_max COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_floatAttributeMinMax::readProperty_min (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_double () ;
  }else{
    const cPtr_floatAttributeMinMax * p = (const cPtr_floatAttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_floatAttributeMinMax) ;
    return p->mProperty_min ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_floatAttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mProperty_min ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_floatAttributeMinMax::readProperty_max (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_double () ;
  }else{
    const cPtr_floatAttributeMinMax * p = (const cPtr_floatAttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_floatAttributeMinMax) ;
    return p->mProperty_max ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_floatAttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mProperty_max ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatAttributeMinMax::setter_setMin (GALGAS_double inValue
                                                 COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_floatAttributeMinMax * p = (cPtr_floatAttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_floatAttributeMinMax) ;
    p->mProperty_min = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_floatAttributeMinMax::setter_setMin (GALGAS_double inValue
                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_min = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatAttributeMinMax::setter_setMax (GALGAS_double inValue
                                                 COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_floatAttributeMinMax * p = (cPtr_floatAttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_floatAttributeMinMax) ;
    p->mProperty_max = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_floatAttributeMinMax::setter_setMax (GALGAS_double inValue
                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_max = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @floatAttributeMinMax class
//----------------------------------------------------------------------------------------------------------------------

cPtr_floatAttributeMinMax::cPtr_floatAttributeMinMax (const GALGAS_location & in_location,
                                                      const GALGAS_double & in_min,
                                                      const GALGAS_double & in_max
                                                      COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mProperty_min (in_min),
mProperty_max (in_max) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_floatAttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatAttributeMinMax ;
}

void cPtr_floatAttributeMinMax::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@floatAttributeMinMax:" ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_floatAttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_floatAttributeMinMax (mProperty_location, mProperty_min, mProperty_max COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @floatAttributeMinMax generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_floatAttributeMinMax ("floatAttributeMinMax",
                                             & kTypeDescriptor_GALGAS_attributeRange) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_floatAttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatAttributeMinMax ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_floatAttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_floatAttributeMinMax (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatAttributeMinMax GALGAS_floatAttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_floatAttributeMinMax result ;
  const GALGAS_floatAttributeMinMax * p = (const GALGAS_floatAttributeMinMax *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_floatAttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("floatAttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@locationList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_locationList : public cCollectionElement {
  public: GALGAS_locationList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_locationList (const GALGAS_location & in_location
                                           COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_locationList (const GALGAS_locationList_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_locationList::cCollectionElement_locationList (const GALGAS_location & in_location
                                                                  COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_location) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_locationList::cCollectionElement_locationList (const GALGAS_locationList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_location) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_locationList::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_locationList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_locationList (mObject.mProperty_location COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_locationList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "location" ":" ;
  mObject.mProperty_location.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_locationList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_locationList * operand = (cCollectionElement_locationList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_locationList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList::GALGAS_locationList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList::GALGAS_locationList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList GALGAS_locationList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_locationList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList GALGAS_locationList::constructor_listWithValue (const GALGAS_location & inOperand0
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_locationList result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_locationList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_locationList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_locationList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                     const GALGAS_location & in_location
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement_locationList * p = nullptr ;
  macroMyNew (p, cCollectionElement_locationList (in_location COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_locationList::addAssign_operation (const GALGAS_location & inOperand0
                                               COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_locationList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_locationList::setter_append (const GALGAS_location inOperand0,
                                         C_Compiler * /* inCompiler */
                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_locationList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_locationList::setter_insertAtIndex (const GALGAS_location inOperand0,
                                                const GALGAS_uint inInsertionIndex,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_locationList (inOperand0 COMMA_THERE)) ;
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

void GALGAS_locationList::setter_removeAtIndex (GALGAS_location & outOperand0,
                                                const GALGAS_uint inRemoveIndex,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_locationList * p = (cCollectionElement_locationList *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_locationList) ;
        outOperand0 = p->mObject.mProperty_location ;
      }
    }else{
      outOperand0.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_locationList::setter_popFirst (GALGAS_location & outOperand0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_locationList * p = (cCollectionElement_locationList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_locationList) ;
    outOperand0 = p->mObject.mProperty_location ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_locationList::setter_popLast (GALGAS_location & outOperand0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_locationList * p = (cCollectionElement_locationList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_locationList) ;
    outOperand0 = p->mObject.mProperty_location ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_locationList::method_first (GALGAS_location & outOperand0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_locationList * p = (cCollectionElement_locationList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_locationList) ;
    outOperand0 = p->mObject.mProperty_location ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_locationList::method_last (GALGAS_location & outOperand0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_locationList * p = (cCollectionElement_locationList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_locationList) ;
    outOperand0 = p->mObject.mProperty_location ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList GALGAS_locationList::add_operation (const GALGAS_locationList & inOperand,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_locationList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList GALGAS_locationList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_locationList result = GALGAS_locationList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList GALGAS_locationList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_locationList result = GALGAS_locationList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList GALGAS_locationList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_locationList result = GALGAS_locationList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_locationList::plusAssign_operation (const GALGAS_locationList inOperand,
                                                C_Compiler * /* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_locationList::setter_setLocationAtIndex (GALGAS_location inOperand,
                                                     GALGAS_uint inIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement_locationList * p = (cCollectionElement_locationList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_locationList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_location = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_locationList::getter_locationAtIndex (const GALGAS_uint & inIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_locationList * p = (cCollectionElement_locationList *) attributes.ptr () ;
  GALGAS_location result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_locationList) ;
    result = p->mObject.mProperty_location ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_locationList::cEnumerator_locationList (const GALGAS_locationList & inEnumeratedObject,
                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList_2D_element cEnumerator_locationList::current (LOCATION_ARGS) const {
  const cCollectionElement_locationList * p = (const cCollectionElement_locationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_locationList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cEnumerator_locationList::current_location (LOCATION_ARGS) const {
  const cCollectionElement_locationList * p = (const cCollectionElement_locationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_locationList) ;
  return p->mObject.mProperty_location ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @locationList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_locationList ("locationList",
                                     nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_locationList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_locationList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_locationList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_locationList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList GALGAS_locationList::extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_locationList result ;
  const GALGAS_locationList * p = (const GALGAS_locationList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_locationList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("locationList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_implementationObjectMap::cMapElement_implementationObjectMap (const GALGAS_lstring & inKey,
                                                                          const GALGAS_impType & in_type
                                                                          COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_type (in_type) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_implementationObjectMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_implementationObjectMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_implementationObjectMap (mProperty_lkey, mProperty_type COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_implementationObjectMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "type" ":" ;
  mProperty_type.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_implementationObjectMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_implementationObjectMap * operand = (cMapElement_implementationObjectMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_type.objectCompare (operand->mProperty_type) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap::GALGAS_implementationObjectMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap::GALGAS_implementationObjectMap (const GALGAS_implementationObjectMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap & GALGAS_implementationObjectMap::operator = (const GALGAS_implementationObjectMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap GALGAS_implementationObjectMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_implementationObjectMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap GALGAS_implementationObjectMap::constructor_mapWithMapToOverride (const GALGAS_implementationObjectMap & inMapToOverride
                                                                                                 COMMA_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap GALGAS_implementationObjectMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const {
  GALGAS_implementationObjectMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationObjectMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                          const GALGAS_impType & inArgument0,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  cMapElement_implementationObjectMap * p = nullptr ;
  macroMyNew (p, cMapElement_implementationObjectMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@implementationObjectMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap GALGAS_implementationObjectMap::add_operation (const GALGAS_implementationObjectMap & inOperand,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_implementationObjectMap result = *this ;
  cEnumerator_implementationObjectMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_type (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationObjectMap::setter_put (GALGAS_lstring inKey,
                                                 GALGAS_impType inArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cMapElement_implementationObjectMap * p = nullptr ;
  macroMyNew (p, cMapElement_implementationObjectMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "%K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_implementationObjectMap_get = "%K does not exists" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationObjectMap::method_get (GALGAS_lstring inKey,
                                                 GALGAS_impType & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  const cMapElement_implementationObjectMap * p = (const cMapElement_implementationObjectMap *) performSearch (inKey,
                                                                                                               inCompiler,
                                                                                                               kSearchErrorMessage_implementationObjectMap_get
                                                                                                               COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_implementationObjectMap) ;
    outArgument0 = p->mProperty_type ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationObjectMap::setter_del (GALGAS_lstring inKey,
                                                 GALGAS_impType & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "%K does not exists" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_implementationObjectMap * p = (cMapElement_implementationObjectMap *) attributes.ptr () ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_implementationObjectMap) ;
    outArgument0 = p->mProperty_type ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_impType GALGAS_implementationObjectMap::getter_typeForKey (const GALGAS_string & inKey,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_implementationObjectMap * p = (const cMapElement_implementationObjectMap *) attributes ;
  GALGAS_impType result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_implementationObjectMap) ;
    result = p->mProperty_type ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationObjectMap::setter_setTypeForKey (GALGAS_impType inAttributeValue,
                                                           GALGAS_string inKey,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_implementationObjectMap * p = (cMapElement_implementationObjectMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_implementationObjectMap) ;
    p->mProperty_type = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_implementationObjectMap * GALGAS_implementationObjectMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                                         const GALGAS_string & inKey
                                                                                                         COMMA_LOCATION_ARGS) {
  cMapElement_implementationObjectMap * result = (cMapElement_implementationObjectMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_implementationObjectMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_implementationObjectMap::cEnumerator_implementationObjectMap (const GALGAS_implementationObjectMap & inEnumeratedObject,
                                                                          const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap_2D_element cEnumerator_implementationObjectMap::current (LOCATION_ARGS) const {
  const cMapElement_implementationObjectMap * p = (const cMapElement_implementationObjectMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_implementationObjectMap) ;
  return GALGAS_implementationObjectMap_2D_element (p->mProperty_lkey, p->mProperty_type) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_implementationObjectMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_impType cEnumerator_implementationObjectMap::current_type (LOCATION_ARGS) const {
  const cMapElement_implementationObjectMap * p = (const cMapElement_implementationObjectMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_implementationObjectMap) ;
  return p->mProperty_type ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_implementationObjectMap::optional_searchKey (const GALGAS_string & inKey,
                                                         GALGAS_impType & outArgument0) const {
  const cMapElement_implementationObjectMap * p = (const cMapElement_implementationObjectMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_implementationObjectMap) ;
    outArgument0 = p->mProperty_type ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @implementationObjectMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_implementationObjectMap ("implementationObjectMap",
                                                nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_implementationObjectMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementationObjectMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_implementationObjectMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_implementationObjectMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap GALGAS_implementationObjectMap::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result ;
  const GALGAS_implementationObjectMap * p = (const GALGAS_implementationObjectMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_implementationObjectMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("implementationObjectMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_enumValues::cMapElement_enumValues (const GALGAS_lstring & inKey,
                                                const GALGAS_implementationObjectMap & in_subAttributes
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_subAttributes (in_subAttributes) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_enumValues::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_enumValues::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_enumValues (mProperty_lkey, mProperty_subAttributes COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_enumValues::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "subAttributes" ":" ;
  mProperty_subAttributes.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_enumValues::compare (const cCollectionElement * inOperand) const {
  cMapElement_enumValues * operand = (cMapElement_enumValues *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_subAttributes.objectCompare (operand->mProperty_subAttributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues::GALGAS_enumValues (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues::GALGAS_enumValues (const GALGAS_enumValues & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues & GALGAS_enumValues::operator = (const GALGAS_enumValues & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues GALGAS_enumValues::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_enumValues result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues GALGAS_enumValues::constructor_mapWithMapToOverride (const GALGAS_enumValues & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_enumValues result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues GALGAS_enumValues::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_enumValues result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_enumValues::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_implementationObjectMap & inArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_enumValues * p = nullptr ;
  macroMyNew (p, cMapElement_enumValues (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@enumValues insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues GALGAS_enumValues::add_operation (const GALGAS_enumValues & inOperand,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_enumValues result = *this ;
  cEnumerator_enumValues enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_subAttributes (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_enumValues::setter_put (GALGAS_lstring inKey,
                                    GALGAS_implementationObjectMap inArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  cMapElement_enumValues * p = nullptr ;
  macroMyNew (p, cMapElement_enumValues (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "%K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_enumValues_get = "%K does not exists" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_enumValues::method_get (GALGAS_lstring inKey,
                                    GALGAS_implementationObjectMap & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  const cMapElement_enumValues * p = (const cMapElement_enumValues *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_enumValues_get
                                                                                     COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_enumValues) ;
    outArgument0 = p->mProperty_subAttributes ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_enumValues::setter_del (GALGAS_lstring inKey,
                                    GALGAS_implementationObjectMap & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "%K does not exists" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_enumValues * p = (cMapElement_enumValues *) attributes.ptr () ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_enumValues) ;
    outArgument0 = p->mProperty_subAttributes ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap GALGAS_enumValues::getter_subAttributesForKey (const GALGAS_string & inKey,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_enumValues * p = (const cMapElement_enumValues *) attributes ;
  GALGAS_implementationObjectMap result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_enumValues) ;
    result = p->mProperty_subAttributes ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_enumValues::setter_setSubAttributesForKey (GALGAS_implementationObjectMap inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_enumValues * p = (cMapElement_enumValues *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_enumValues) ;
    p->mProperty_subAttributes = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_enumValues * GALGAS_enumValues::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_enumValues * result = (cMapElement_enumValues *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_enumValues) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_enumValues::cEnumerator_enumValues (const GALGAS_enumValues & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues_2D_element cEnumerator_enumValues::current (LOCATION_ARGS) const {
  const cMapElement_enumValues * p = (const cMapElement_enumValues *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_enumValues) ;
  return GALGAS_enumValues_2D_element (p->mProperty_lkey, p->mProperty_subAttributes) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_enumValues::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap cEnumerator_enumValues::current_subAttributes (LOCATION_ARGS) const {
  const cMapElement_enumValues * p = (const cMapElement_enumValues *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_enumValues) ;
  return p->mProperty_subAttributes ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_enumValues::optional_searchKey (const GALGAS_string & inKey,
                                            GALGAS_implementationObjectMap & outArgument0) const {
  const cMapElement_enumValues * p = (const cMapElement_enumValues *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_enumValues) ;
    outArgument0 = p->mProperty_subAttributes ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @enumValues generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_enumValues ("enumValues",
                                   nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_enumValues::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_enumValues ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_enumValues::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_enumValues (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues GALGAS_enumValues::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_enumValues result ;
  const GALGAS_enumValues * p = (const GALGAS_enumValues *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_enumValues *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("enumValues", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@enumValues mergeWithEnum'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues extensionGetter_mergeWithEnum (const GALGAS_enumValues & inObject,
                                                 const GALGAS_enumValues & constinArgument_enumToMerge,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_enumValues result_mergedEnum ; // Returned variable
  result_mergedEnum = GALGAS_enumValues::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 734)) ;
  const GALGAS_enumValues temp_0 = inObject ;
  cEnumerator_enumValues enumerator_20480 (temp_0, kENUMERATION_UP) ;
  while (enumerator_20480.hasCurrentObject ()) {
    GALGAS_implementationObjectMap var_attributes_20523 = enumerator_20480.current_subAttributes (HERE) ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = constinArgument_enumToMerge.getter_hasKey (enumerator_20480.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 737)).boolEnum () ;
      if (kBoolTrue == test_1) {
        GALGAS_implementationObjectMap var_attributesToMerge_20657 ;
        constinArgument_enumToMerge.method_get (enumerator_20480.current_lkey (HERE), var_attributesToMerge_20657, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 738)) ;
        var_attributes_20523 = extensionGetter_mergeImplementationObjectAttributesWith (enumerator_20480.current_subAttributes (HERE), var_attributesToMerge_20657, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 739)) ;
      }
    }
    {
    result_mergedEnum.setter_put (enumerator_20480.current_lkey (HERE), var_attributes_20523, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 741)) ;
    }
    enumerator_20480.gotoNextObject () ;
  }
  cEnumerator_enumValues enumerator_20831 (constinArgument_enumToMerge, kENUMERATION_UP) ;
  while (enumerator_20831.hasCurrentObject ()) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      const GALGAS_enumValues temp_3 = inObject ;
      test_2 = temp_3.getter_hasKey (enumerator_20831.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 744)).operator_not (SOURCE_FILE ("implementation_types.galgas", 744)).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        result_mergedEnum.setter_put (enumerator_20831.current_lkey (HERE), enumerator_20831.current_subAttributes (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 745)) ;
        }
      }
    }
    enumerator_20831.gotoNextObject () ;
  }
//---
  return result_mergedEnum ;
}




//----------------------------------------------------------------------------------------------------------------------

cMapElement_implementationMap::cMapElement_implementationMap (const GALGAS_lstring & inKey,
                                                              const GALGAS_implementationObject & in_obj
                                                              COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_obj (in_obj) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_implementationMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_implementationMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_implementationMap (mProperty_lkey, mProperty_obj COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_implementationMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "obj" ":" ;
  mProperty_obj.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_implementationMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_implementationMap * operand = (cMapElement_implementationMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_obj.objectCompare (operand->mProperty_obj) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap::GALGAS_implementationMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap::GALGAS_implementationMap (const GALGAS_implementationMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap & GALGAS_implementationMap::operator = (const GALGAS_implementationMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap GALGAS_implementationMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_implementationMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap GALGAS_implementationMap::constructor_mapWithMapToOverride (const GALGAS_implementationMap & inMapToOverride
                                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_implementationMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap GALGAS_implementationMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_implementationMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                    const GALGAS_implementationObject & inArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cMapElement_implementationMap * p = nullptr ;
  macroMyNew (p, cMapElement_implementationMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@implementationMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap GALGAS_implementationMap::add_operation (const GALGAS_implementationMap & inOperand,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_implementationMap result = *this ;
  cEnumerator_implementationMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_obj (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationMap::setter_put (GALGAS_lstring inKey,
                                           GALGAS_implementationObject inArgument0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  cMapElement_implementationMap * p = nullptr ;
  macroMyNew (p, cMapElement_implementationMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "%K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_implementationMap_get = "%K does not exists" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationMap::method_get (GALGAS_lstring inKey,
                                           GALGAS_implementationObject & outArgument0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  const cMapElement_implementationMap * p = (const cMapElement_implementationMap *) performSearch (inKey,
                                                                                                   inCompiler,
                                                                                                   kSearchErrorMessage_implementationMap_get
                                                                                                   COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_implementationMap) ;
    outArgument0 = p->mProperty_obj ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationMap::setter_del (GALGAS_lstring inKey,
                                           GALGAS_implementationObject & outArgument0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "%K does not exists" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_implementationMap * p = (cMapElement_implementationMap *) attributes.ptr () ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_implementationMap) ;
    outArgument0 = p->mProperty_obj ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObject GALGAS_implementationMap::getter_objForKey (const GALGAS_string & inKey,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_implementationMap * p = (const cMapElement_implementationMap *) attributes ;
  GALGAS_implementationObject result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_implementationMap) ;
    result = p->mProperty_obj ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationMap::setter_setObjForKey (GALGAS_implementationObject inAttributeValue,
                                                    GALGAS_string inKey,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_implementationMap * p = (cMapElement_implementationMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_implementationMap) ;
    p->mProperty_obj = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_implementationMap * GALGAS_implementationMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                             const GALGAS_string & inKey
                                                                                             COMMA_LOCATION_ARGS) {
  cMapElement_implementationMap * result = (cMapElement_implementationMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_implementationMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_implementationMap::cEnumerator_implementationMap (const GALGAS_implementationMap & inEnumeratedObject,
                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap_2D_element cEnumerator_implementationMap::current (LOCATION_ARGS) const {
  const cMapElement_implementationMap * p = (const cMapElement_implementationMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_implementationMap) ;
  return GALGAS_implementationMap_2D_element (p->mProperty_lkey, p->mProperty_obj) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_implementationMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObject cEnumerator_implementationMap::current_obj (LOCATION_ARGS) const {
  const cMapElement_implementationMap * p = (const cMapElement_implementationMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_implementationMap) ;
  return p->mProperty_obj ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_implementationMap::optional_searchKey (const GALGAS_string & inKey,
                                                   GALGAS_implementationObject & outArgument0) const {
  const cMapElement_implementationMap * p = (const cMapElement_implementationMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_implementationMap) ;
    outArgument0 = p->mProperty_obj ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @implementationMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_implementationMap ("implementationMap",
                                          nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_implementationMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementationMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_implementationMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_implementationMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap GALGAS_implementationMap::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_implementationMap result ;
  const GALGAS_implementationMap * p = (const GALGAS_implementationMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_implementationMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("implementationMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_implementation::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_implementation * p = (const cPtr_implementation *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_implementation) ;
  if (kOperandEqual == result) {
    result = mProperty_imp.objectCompare (p->mProperty_imp) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementation::GALGAS_implementation (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementation GALGAS_implementation::constructor_default (LOCATION_ARGS) {
  return GALGAS_implementation::constructor_new (GALGAS_implementationMap::constructor_emptyMap (HERE)
                                                 COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementation::GALGAS_implementation (const cPtr_implementation * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_implementation) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementation GALGAS_implementation::constructor_new (const GALGAS_implementationMap & inAttribute_imp
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_implementation result ;
  if (inAttribute_imp.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_implementation (inAttribute_imp COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap GALGAS_implementation::readProperty_imp (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_implementationMap () ;
  }else{
    const cPtr_implementation * p = (const cPtr_implementation *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_implementation) ;
    return p->mProperty_imp ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap cPtr_implementation::getter_imp (UNUSED_LOCATION_ARGS) const {
  return mProperty_imp ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementation::setter_setImp (GALGAS_implementationMap inValue
                                           COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_implementation * p = (cPtr_implementation *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_implementation) ;
    p->mProperty_imp = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_implementation::setter_setImp (GALGAS_implementationMap inValue
                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_imp = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @implementation class
//----------------------------------------------------------------------------------------------------------------------

cPtr_implementation::cPtr_implementation (const GALGAS_implementationMap & in_imp
                                          COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_imp (in_imp) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_implementation::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementation ;
}

void cPtr_implementation::description (C_String & ioString,
                                       const int32_t inIndentation) const {
  ioString << "[@implementation:" ;
  mProperty_imp.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_implementation::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_implementation (mProperty_imp COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @implementation generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_implementation ("implementation",
                                       nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_implementation::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementation ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_implementation::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_implementation (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementation GALGAS_implementation::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_implementation result ;
  const GALGAS_implementation * p = (const GALGAS_implementation *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_implementation *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("implementation", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@implementation hasKey'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_implementation::getter_hasKey (const GALGAS_string constinArgument_key,
                                                C_Compiler */* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = this->mProperty_imp.getter_hasKey (constinArgument_key COMMA_SOURCE_FILE ("implementation_types.galgas", 803)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_hasKey (const cPtr_implementation * inObject,
                                        const GALGAS_string in_key,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_hasKey (in_key, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@implementation hasLKey'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_implementation::getter_hasLKey (const GALGAS_lstring constinArgument_key,
                                                 C_Compiler */* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = this->mProperty_imp.getter_hasKey (constinArgument_key.readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 809)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_hasLKey (const cPtr_implementation * inObject,
                                         const GALGAS_lstring in_key,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_hasLKey (in_key, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@implementation impObject'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObject cPtr_implementation::getter_impObject (const GALGAS_string constinArgument_objKind,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_implementationObject result_obj ; // Returned variable
  result_obj = GALGAS_implementationObject::constructor_new (GALGAS_lbool::constructor_new (GALGAS_bool (false), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 815))  COMMA_SOURCE_FILE ("implementation_types.galgas", 815)), GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 815))  COMMA_SOURCE_FILE ("implementation_types.galgas", 815)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_imp.getter_hasKey (constinArgument_objKind COMMA_SOURCE_FILE ("implementation_types.galgas", 816)).boolEnum () ;
    if (kBoolTrue == test_0) {
      this->mProperty_imp.method_get (function_lstringWith (constinArgument_objKind, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 817)), result_obj, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 817)) ;
    }
  }
//---
  return result_obj ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObject callExtensionGetter_impObject (const cPtr_implementation * inObject,
                                                           const GALGAS_string in_objKind,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) {
  GALGAS_implementationObject result ;
  if (nullptr != inObject) {
    result = inObject->getter_impObject (in_objKind, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@implementation checkTypeForKind'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_implementation::method_checkTypeForKind (const GALGAS_string constinArgument_objKind,
                                                   const GALGAS_string constinArgument_attributeName,
                                                   const GALGAS_dataType constinArgument_expectedType,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_implementation temp_0 = this ;
  GALGAS_implementationObject var_obj_22831 = callExtensionGetter_impObject ((const cPtr_implementation *) temp_0.ptr (), constinArgument_objKind, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 825)) ;
  {
  routine_checkTypeForAttribute (var_obj_22831.readProperty_attributes (), constinArgument_attributeName, constinArgument_expectedType, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 826)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_checkTypeForKind (cPtr_implementation * inObject,
                                           const GALGAS_string constin_objKind,
                                           const GALGAS_string constin_attributeName,
                                           const GALGAS_dataType constin_expectedType,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_implementation) ;
    inObject->method_checkTypeForKind  (constin_objKind, constin_attributeName, constin_expectedType, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@implementation checkObjectReferences'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_implementation::method_checkObjectReferences (C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_implementationMap enumerator_22993 (this->mProperty_imp, kENUMERATION_UP) ;
  while (enumerator_22993.hasCurrentObject ()) {
    cEnumerator_implementationObjectMap enumerator_23015 (enumerator_22993.current_obj (HERE).readProperty_attributes (), kENUMERATION_UP) ;
    while (enumerator_23015.hasCurrentObject ()) {
      const GALGAS_implementation temp_0 = this ;
      callExtensionMethod_checkAttributeReferences ((cPtr_impType *) enumerator_23015.current_type (HERE).ptr (), temp_0, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 832)) ;
      enumerator_23015.gotoNextObject () ;
    }
    enumerator_22993.gotoNextObject () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_checkObjectReferences (cPtr_implementation * inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_implementation) ;
    inObject->method_checkObjectReferences  (inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@implementationObjectMap mergeImplementationObjectAttributesWith'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap extensionGetter_mergeImplementationObjectAttributesWith (const GALGAS_implementationObjectMap & inObject,
                                                                                        const GALGAS_implementationObjectMap & constinArgument_attributesToMerge,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result_mergedAttributes ; // Returned variable
  result_mergedAttributes = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 1054)) ;
  const GALGAS_implementationObjectMap temp_0 = inObject ;
  cEnumerator_implementationObjectMap enumerator_30611 (temp_0, kENUMERATION_UP) ;
  while (enumerator_30611.hasCurrentObject ()) {
    GALGAS_impType var_merged_30638 = enumerator_30611.current_type (HERE) ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = constinArgument_attributesToMerge.getter_hasKey (enumerator_30611.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 1057)).boolEnum () ;
      if (kBoolTrue == test_1) {
        GALGAS_impType var_typeToMerge_30755 ;
        constinArgument_attributesToMerge.method_get (enumerator_30611.current_lkey (HERE), var_typeToMerge_30755, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1058)) ;
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = GALGAS_bool (kIsEqual, enumerator_30611.current_type (HERE).getter_dynamicType (SOURCE_FILE ("implementation_types.galgas", 1059)).objectCompare (var_typeToMerge_30755.getter_dynamicType (SOURCE_FILE ("implementation_types.galgas", 1059)))).boolEnum () ;
          if (kBoolTrue == test_2) {
            var_merged_30638 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_30611.current_type (HERE).ptr (), var_typeToMerge_30755, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1060)) ;
          }
        }
        if (kBoolFalse == test_2) {
          TC_Array <C_FixItDescription> fixItArray3 ;
          inCompiler->emitSemanticError (enumerator_30611.current_lkey (HERE).readProperty_location (), GALGAS_string ("Redefined type"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 1063)) ;
        }
      }
    }
    {
    result_mergedAttributes.setter_put (enumerator_30611.current_lkey (HERE), var_merged_30638, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1066)) ;
    }
    enumerator_30611.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_31031 (constinArgument_attributesToMerge, kENUMERATION_UP) ;
  while (enumerator_31031.hasCurrentObject ()) {
    enumGalgasBool test_4 = kBoolTrue ;
    if (kBoolTrue == test_4) {
      const GALGAS_implementationObjectMap temp_5 = inObject ;
      test_4 = temp_5.getter_hasKey (enumerator_31031.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 1069)).operator_not (SOURCE_FILE ("implementation_types.galgas", 1069)).boolEnum () ;
      if (kBoolTrue == test_4) {
        {
        result_mergedAttributes.setter_put (enumerator_31031.current_lkey (HERE), enumerator_31031.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1070)) ;
        }
      }
    }
    enumerator_31031.gotoNextObject () ;
  }
//---
  return result_mergedAttributes ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@attributeRange contains'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_contains (const cPtr_attributeRange * inObject,
                                          const GALGAS_object_5F_t in_obj,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_contains (in_obj, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@attributeRange string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string callExtensionGetter_string (const cPtr_attributeRange * inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (nullptr != inObject) {
    result = inObject->getter_string (inCompiler COMMA_THERE) ;
  }
  return result ;
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

cTokenFor_options_5F_scanner::cTokenFor_options_5F_scanner (void) :
mLexicalAttribute_floatNumber (),
mLexicalAttribute_integerNumber (),
mLexicalAttribute_key (),
mLexicalAttribute_number (),
mLexicalAttribute_string () {
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique_options_5F_scanner::C_Lexique_options_5F_scanner (C_Compiler * inCallerCompiler,
                                                            const C_String & inSourceFileName
                                                            COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceFileName COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique_options_5F_scanner::C_Lexique_options_5F_scanner (C_Compiler * inCallerCompiler,
                                                            const C_String & inSourceString,
                                                            const C_String & inStringForError
                                                            COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------
//                        Lexical error message list                                             
//----------------------------------------------------------------------------------------------------------------------

static const char * gLexicalMessage_options_5F_scanner_decimalNumberTooLarge = "decimal number too large" ;

static const char * gLexicalMessage_options_5F_scanner_internalError = "internal error" ;

static const char * gLexicalMessage_options_5F_scanner_unableToConvertToDouble = "Unable to convert the string to double" ;

static const char * gLexicalMessage_options_5F_scanner_unterminatedLitteralString = "Unterminated literal string" ;

//----------------------------------------------------------------------------------------------------------------------
//                getMessageForTerminal                                                          
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_options_5F_scanner::getMessageForTerminal (const int32_t inTerminalIndex) const {
  C_String result = "<unknown>" ;
  if ((inTerminalIndex >= 0) && (inTerminalIndex < 10)) {
    static const char * syntaxErrorMessageArray [10] = {kEndOfSourceLexicalErrorMessage,
        "identifier",
        "literal string",
        "literal unsigned 64 bits integer",
        "literal float",
        "'=' delimiter",
        "',' delimiter",
        "'-' delimiter",
        "'(' delimiter",
        "')' delimiter"
    } ;
    result = syntaxErrorMessageArray [inTerminalIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                      U N I C O D E    S T R I N G S                                           
//----------------------------------------------------------------------------------------------------------------------

//--- Unicode string for '$_28_$'
static const utf32 kUnicodeString_options_5F_scanner__28_ [] = {
  TO_UNICODE ('('),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_29_$'
static const utf32 kUnicodeString_options_5F_scanner__29_ [] = {
  TO_UNICODE (')'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2C_$'
static const utf32 kUnicodeString_options_5F_scanner__2C_ [] = {
  TO_UNICODE (','),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D_$'
static const utf32 kUnicodeString_options_5F_scanner__2D_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_30_X$'
static const utf32 kUnicodeString_options_5F_scanner__30_X [] = {
  TO_UNICODE ('0'),
  TO_UNICODE ('X'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_30_x$'
static const utf32 kUnicodeString_options_5F_scanner__30_x [] = {
  TO_UNICODE ('0'),
  TO_UNICODE ('x'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3D_$'
static const utf32 kUnicodeString_options_5F_scanner__3D_ [] = {
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'optionsDelimiters'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_options_5F_scanner_optionsDelimiters = 5 ;

static const C_unicode_lexique_table_entry ktable_for_options_5F_scanner_optionsDelimiters [ktable_size_options_5F_scanner_optionsDelimiters] = {
  C_unicode_lexique_table_entry (kUnicodeString_options_5F_scanner__28_, 1, C_Lexique_options_5F_scanner::kToken__28_),
  C_unicode_lexique_table_entry (kUnicodeString_options_5F_scanner__29_, 1, C_Lexique_options_5F_scanner::kToken__29_),
  C_unicode_lexique_table_entry (kUnicodeString_options_5F_scanner__2C_, 1, C_Lexique_options_5F_scanner::kToken__2C_),
  C_unicode_lexique_table_entry (kUnicodeString_options_5F_scanner__2D_, 1, C_Lexique_options_5F_scanner::kToken__2D_),
  C_unicode_lexique_table_entry (kUnicodeString_options_5F_scanner__3D_, 1, C_Lexique_options_5F_scanner::kToken__3D_)
} ;

int32_t C_Lexique_options_5F_scanner::search_into_optionsDelimiters (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_options_5F_scanner_optionsDelimiters, ktable_size_options_5F_scanner_optionsDelimiters) ;
}


//----------------------------------------------------------------------------------------------------------------------
//                          getCurrentTokenString                                                
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_options_5F_scanner::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_options_5F_scanner * ptr = (const cTokenFor_options_5F_scanner *) inTokenPtr ;
  C_String s ;
  if (ptr == nullptr) {
    s.appendCString("$$") ;
  }else{
    switch (ptr->mTokenCode) {
    case kToken_:
      s.appendCString("$$") ;
      break ;
    case kToken_idf:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("idf") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_key) ;
      break ;
    case kToken_string:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("string") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_string) ;
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
    case kToken__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (",") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("-") ;
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

void C_Lexique_options_5F_scanner::internalParseLexicalToken (cTokenFor_options_5F_scanner & token) {
  bool loop = true ;
  token.mLexicalAttribute_floatNumber = 0.0 ;
  token.mLexicalAttribute_integerNumber = 0 ;
  token.mLexicalAttribute_key.setLengthToZero () ;
  token.mLexicalAttribute_number.setLengthToZero () ;
  token.mLexicalAttribute_string.setLengthToZero () ;
  mTokenStartLocation = mCurrentLocation ;
  try{
    if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z'))) {
      do {
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_key, previousChar ()) ;
        if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32Char (TO_UNICODE ('_')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      token.mTokenCode = kToken_idf ;
      enterToken (token) ;
    }else if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
      do {
        if (testForInputUTF32CharRange (TO_UNICODE (' '), TO_UNICODE ('!')) || testForInputUTF32CharRange (TO_UNICODE ('#'), TO_UNICODE (65533))) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_string, previousChar ()) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
        token.mTokenCode = kToken_string ;
        enterToken (token) ;
      }else{
        lexicalError (gLexicalMessage_options_5F_scanner_unterminatedLitteralString COMMA_LINE_AND_SOURCE_FILE) ;
      }
    }else if (testForInputUTF32String (kUnicodeString_options_5F_scanner__30_x, 2, true) || testForInputUTF32String (kUnicodeString_options_5F_scanner__30_X, 2, true)) {
      do {
        if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
          ::scanner_routine_enterHexDigitIntoUInt64 (*this, previousChar (), token.mLexicalAttribute_integerNumber, gLexicalMessage_options_5F_scanner_decimalNumberTooLarge, gLexicalMessage_options_5F_scanner_internalError) ;
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
        ::scanner_routine_enterDigitIntoUInt64 (*this, previousChar (), token.mLexicalAttribute_integerNumber, gLexicalMessage_options_5F_scanner_decimalNumberTooLarge, gLexicalMessage_options_5F_scanner_internalError) ;
        if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (testForInputUTF32Char (TO_UNICODE ('.'))) {
        do {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_number, previousChar ()) ;
          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          }else{
            loop = false ;
          }
        }while (loop) ;
        loop = true ;
        ::scanner_routine_convertStringToDouble (*this, token.mLexicalAttribute_number, token.mLexicalAttribute_floatNumber, gLexicalMessage_options_5F_scanner_unableToConvertToDouble) ;
        token.mTokenCode = kToken_float_5F_number ;
        enterToken (token) ;
      }else{
        token.mTokenCode = kToken_uint_5F_number ;
        enterToken (token) ;
      }
    }else if (testForInputUTF32String (kUnicodeString_options_5F_scanner__3D_, 1, true)) {
      token.mTokenCode = kToken__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_options_5F_scanner__2D_, 1, true)) {
      token.mTokenCode = kToken__2D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_options_5F_scanner__2C_, 1, true)) {
      token.mTokenCode = kToken__2C_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_options_5F_scanner__29_, 1, true)) {
      token.mTokenCode = kToken__29_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_options_5F_scanner__28_, 1, true)) {
      token.mTokenCode = kToken__28_ ;
      enterToken (token) ;
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

bool C_Lexique_options_5F_scanner::parseLexicalToken (void) {
  cTokenFor_options_5F_scanner token ;
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

void C_Lexique_options_5F_scanner::enterToken (cTokenFor_options_5F_scanner & ioToken) {
  cTokenFor_options_5F_scanner * ptr = nullptr ;
  macroMyNew (ptr, cTokenFor_options_5F_scanner ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
  // ptr->mIsOptional = ioToken.mIsOptional ;
  ptr->mStartLocation = mTokenStartLocation ;
  ptr->mEndLocation = mTokenEndLocation ;
  ptr->mTemplateStringBeforeToken = ioToken.mTemplateStringBeforeToken ;
  ioToken.mTemplateStringBeforeToken = "" ;
  ptr->mLexicalAttribute_floatNumber = ioToken.mLexicalAttribute_floatNumber ;
  ptr->mLexicalAttribute_integerNumber = ioToken.mLexicalAttribute_integerNumber ;
  ptr->mLexicalAttribute_key = ioToken.mLexicalAttribute_key ;
  ptr->mLexicalAttribute_number = ioToken.mLexicalAttribute_number ;
  ptr->mLexicalAttribute_string = ioToken.mLexicalAttribute_string ;
  enterTokenFromPointer (ptr) ;
}

//----------------------------------------------------------------------------------------------------------------------
//               A T T R I B U T E   A C C E S S                                                 
//----------------------------------------------------------------------------------------------------------------------

double C_Lexique_options_5F_scanner::attributeValue_floatNumber (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_floatNumber ;
}

//----------------------------------------------------------------------------------------------------------------------

uint64_t C_Lexique_options_5F_scanner::attributeValue_integerNumber (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_integerNumber ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_options_5F_scanner::attributeValue_key (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_key ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_options_5F_scanner::attributeValue_number (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_number ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_options_5F_scanner::attributeValue_string (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_string ;
}

//----------------------------------------------------------------------------------------------------------------------
//         A S S I G N    F R O M    A T T R I B U T E                                           
//----------------------------------------------------------------------------------------------------------------------

GALGAS_ldouble C_Lexique_options_5F_scanner::synthetizedAttribute_floatNumber (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_options_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_double value (ptr->mLexicalAttribute_floatNumber) ;
  GALGAS_ldouble result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint_36__34_ C_Lexique_options_5F_scanner::synthetizedAttribute_integerNumber (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_options_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_uint_36__34_ value (ptr->mLexicalAttribute_integerNumber) ;
  GALGAS_luint_36__34_ result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_options_5F_scanner::synthetizedAttribute_key (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_options_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_key) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_options_5F_scanner::synthetizedAttribute_number (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_options_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_number) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_options_5F_scanner::synthetizedAttribute_string (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_options_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_string) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                         I N T R O S P E C T I O N                                             
//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist C_Lexique_options_5F_scanner::symbols (LOCATION_ARGS) {
  GALGAS_stringlist result = GALGAS_stringlist::constructor_emptyList (THERE) ;
  result.addAssign_operation (GALGAS_string ("idf") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("string") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("uint_number") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("float_number") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (",") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("-") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("(") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (")") COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

static void getKeywordLists_options_5F_scanner (TC_UniqueArray <C_String> & ioList) {
  ioList.appendObject ("options_scanner:optionsDelimiters") ;
}

//----------------------------------------------------------------------------------------------------------------------

static void getKeywordsForIdentifier_options_5F_scanner (const C_String & inIdentifier,
                                                         bool & ioFound,
                                                         TC_UniqueArray <C_String> & ioList) {
  if (inIdentifier == "options_scanner:optionsDelimiters") {
    ioFound = true ;
    ioList.appendObject ("(") ;
    ioList.appendObject (")") ;
    ioList.appendObject (",") ;
    ioList.appendObject ("-") ;
    ioList.appendObject ("=") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static cLexiqueIntrospection lexiqueIntrospection_options_5F_scanner
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_options_5F_scanner, getKeywordsForIdentifier_options_5F_scanner) ;

//----------------------------------------------------------------------------------------------------------------------
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                           
//----------------------------------------------------------------------------------------------------------------------

uint32_t C_Lexique_options_5F_scanner::styleIndexForTerminal (const int32_t inTerminalIndex) const {
  static const uint32_t kTerminalSymbolStyles [10] = {0,
    1 /* options_scanner_1_idf */,
    3 /* options_scanner_1_string */,
    4 /* options_scanner_1_uint_5F_number */,
    5 /* options_scanner_1_float_5F_number */,
    2 /* options_scanner_1__3D_ */,
    2 /* options_scanner_1__2C_ */,
    2 /* options_scanner_1__2D_ */,
    2 /* options_scanner_1__28_ */,
    2 /* options_scanner_1__29_ */
  } ;
  return (inTerminalIndex >= 0) ? kTerminalSymbolStyles [inTerminalIndex] : 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                      
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_options_5F_scanner::styleNameForIndex (const uint32_t inStyleIndex) const {
  C_String result ;
  if (inStyleIndex < 6) {
    static const char * kStyleArray [6] = {
      "",
      "identifierStyle",
      "delimitersStyle",
      "stringStyle",
      "integerStyle",
      "floatStyle"
    } ;
    result = kStyleArray [inStyleIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_identifierMap::cMapElement_identifierMap (const GALGAS_lstring & inKey,
                                                      const GALGAS_object_5F_t & in_value
                                                      COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_identifierMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_identifierMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_identifierMap (mProperty_lkey, mProperty_value COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_identifierMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mProperty_value.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_identifierMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_identifierMap * operand = (cMapElement_identifierMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (operand->mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap::GALGAS_identifierMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap::GALGAS_identifierMap (const GALGAS_identifierMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap & GALGAS_identifierMap::operator = (const GALGAS_identifierMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap GALGAS_identifierMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_identifierMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap GALGAS_identifierMap::constructor_mapWithMapToOverride (const GALGAS_identifierMap & inMapToOverride
                                                                             COMMA_LOCATION_ARGS) {
  GALGAS_identifierMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap GALGAS_identifierMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_identifierMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                const GALGAS_object_5F_t & inArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cMapElement_identifierMap * p = nullptr ;
  macroMyNew (p, cMapElement_identifierMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@identifierMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap GALGAS_identifierMap::add_operation (const GALGAS_identifierMap & inOperand,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_identifierMap result = *this ;
  cEnumerator_identifierMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_value (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierMap::setter_put (GALGAS_lstring inKey,
                                       GALGAS_object_5F_t inArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  cMapElement_identifierMap * p = nullptr ;
  macroMyNew (p, cMapElement_identifierMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "%K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_identifierMap_get = "Identifier %K is not defined" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierMap::method_get (GALGAS_lstring inKey,
                                       GALGAS_object_5F_t & outArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  const cMapElement_identifierMap * p = (const cMapElement_identifierMap *) performSearch (inKey,
                                                                                           inCompiler,
                                                                                           kSearchErrorMessage_identifierMap_get
                                                                                           COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_identifierMap) ;
    outArgument0 = p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierMap::setter_del (GALGAS_lstring inKey,
                                       GALGAS_object_5F_t & outArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "Identifier %K is not defined" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_identifierMap * p = (cMapElement_identifierMap *) attributes.ptr () ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_identifierMap) ;
    outArgument0 = p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_object_5F_t GALGAS_identifierMap::getter_valueForKey (const GALGAS_string & inKey,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_identifierMap * p = (const cMapElement_identifierMap *) attributes ;
  GALGAS_object_5F_t result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_identifierMap) ;
    result = p->mProperty_value ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierMap::setter_setValueForKey (GALGAS_object_5F_t inAttributeValue,
                                                  GALGAS_string inKey,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_identifierMap * p = (cMapElement_identifierMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_identifierMap) ;
    p->mProperty_value = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_identifierMap * GALGAS_identifierMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                     const GALGAS_string & inKey
                                                                                     COMMA_LOCATION_ARGS) {
  cMapElement_identifierMap * result = (cMapElement_identifierMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_identifierMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_identifierMap::cEnumerator_identifierMap (const GALGAS_identifierMap & inEnumeratedObject,
                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap_2D_element cEnumerator_identifierMap::current (LOCATION_ARGS) const {
  const cMapElement_identifierMap * p = (const cMapElement_identifierMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_identifierMap) ;
  return GALGAS_identifierMap_2D_element (p->mProperty_lkey, p->mProperty_value) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_identifierMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_object_5F_t cEnumerator_identifierMap::current_value (LOCATION_ARGS) const {
  const cMapElement_identifierMap * p = (const cMapElement_identifierMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_identifierMap) ;
  return p->mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_identifierMap::optional_searchKey (const GALGAS_string & inKey,
                                               GALGAS_object_5F_t & outArgument0) const {
  const cMapElement_identifierMap * p = (const cMapElement_identifierMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_identifierMap) ;
    outArgument0 = p->mProperty_value ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @identifierMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_identifierMap ("identifierMap",
                                      nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_identifierMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_identifierMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_identifierMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_identifierMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap GALGAS_identifierMap::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_identifierMap result ;
  const GALGAS_identifierMap * p = (const GALGAS_identifierMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_identifierMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("identifierMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_objectAttributes::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_objectAttributes * p = (const cPtr_objectAttributes *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_objectAttributes) ;
  if (kOperandEqual == result) {
    result = mProperty_objectParams.objectCompare (p->mProperty_objectParams) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectAttributes::GALGAS_objectAttributes (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectAttributes GALGAS_objectAttributes::constructor_default (LOCATION_ARGS) {
  return GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (HERE)
                                                   COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectAttributes::GALGAS_objectAttributes (const cPtr_objectAttributes * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_objectAttributes) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectAttributes GALGAS_objectAttributes::constructor_new (const GALGAS_identifierMap & inAttribute_objectParams
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_objectAttributes result ;
  if (inAttribute_objectParams.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_objectAttributes (inAttribute_objectParams COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap GALGAS_objectAttributes::readProperty_objectParams (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_identifierMap () ;
  }else{
    const cPtr_objectAttributes * p = (const cPtr_objectAttributes *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_objectAttributes) ;
    return p->mProperty_objectParams ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap cPtr_objectAttributes::getter_objectParams (UNUSED_LOCATION_ARGS) const {
  return mProperty_objectParams ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectAttributes::setter_setObjectParams (GALGAS_identifierMap inValue
                                                      COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_objectAttributes * p = (cPtr_objectAttributes *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_objectAttributes) ;
    p->mProperty_objectParams = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_objectAttributes::setter_setObjectParams (GALGAS_identifierMap inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_objectParams = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @objectAttributes class
//----------------------------------------------------------------------------------------------------------------------

cPtr_objectAttributes::cPtr_objectAttributes (const GALGAS_identifierMap & in_objectParams
                                              COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_objectParams (in_objectParams) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_objectAttributes::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectAttributes ;
}

void cPtr_objectAttributes::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@objectAttributes:" ;
  mProperty_objectParams.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_objectAttributes::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_objectAttributes (mProperty_objectParams COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @objectAttributes generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectAttributes ("objectAttributes",
                                         nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_objectAttributes::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectAttributes ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_objectAttributes::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectAttributes (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectAttributes GALGAS_objectAttributes::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_objectAttributes result ;
  const GALGAS_objectAttributes * p = (const GALGAS_objectAttributes *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_objectAttributes *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectAttributes", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@objectAttributes mergeAttributes'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_objectAttributes_mergeAttributes> gExtensionModifierTable_objectAttributes_mergeAttributes ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_mergeAttributes (const int32_t inClassIndex,
                                           extensionSetterSignature_objectAttributes_mergeAttributes inModifier) {
  gExtensionModifierTable_objectAttributes_mergeAttributes.forceObjectAtIndex (inClassIndex, inModifier, nullptr COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_mergeAttributes (cPtr_objectAttributes * inObject,
                                          GALGAS_objectAttributes in_withAttributes,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_objectAttributes) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_objectAttributes_mergeAttributes f = nullptr ;
    if (classIndex < gExtensionModifierTable_objectAttributes_mergeAttributes.count ()) {
      f = gExtensionModifierTable_objectAttributes_mergeAttributes (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_objectAttributes_mergeAttributes.count ()) {
           f = gExtensionModifierTable_objectAttributes_mergeAttributes (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_objectAttributes_mergeAttributes.forceObjectAtIndex (classIndex, f, nullptr COMMA_HERE) ;
    }
    f (inObject, in_withAttributes, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_objectAttributes_mergeAttributes (cPtr_objectAttributes * inObject,
                                                              GALGAS_objectAttributes inArgument_withAttributes,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_objectAttributes * object = inObject ;
  macroValidSharedObject (object, cPtr_objectAttributes) ;
  cEnumerator_identifierMap enumerator_1441 (inArgument_withAttributes.readProperty_objectParams (), kENUMERATION_UP) ;
  while (enumerator_1441.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = object->mProperty_objectParams.getter_hasKey (enumerator_1441.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("goil_basic_types.galgas", 60)).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_object_5F_t var_object_1617 ;
        {
        object->mProperty_objectParams.setter_del (enumerator_1441.current_lkey (HERE), var_object_1617, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 62)) ;
        }
        {
        var_object_1617.insulate (HERE) ;
        cPtr_object_5F_t * ptr_1634 = (cPtr_object_5F_t *) var_object_1617.ptr () ;
        callExtensionSetter_mergeSubAttributes ((cPtr_object_5F_t *) ptr_1634, enumerator_1441.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 63)) ;
        }
        {
        object->mProperty_objectParams.setter_put (enumerator_1441.current_lkey (HERE), var_object_1617, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 64)) ;
        }
      }
    }
    if (kBoolFalse == test_0) {
      {
      object->mProperty_objectParams.setter_put (enumerator_1441.current_lkey (HERE), enumerator_1441.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 67)) ;
      }
    }
    enumerator_1441.gotoNextObject () ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_objectAttributes_mergeAttributes (void) {
  enterExtensionSetter_mergeAttributes (kTypeDescriptor_GALGAS_objectAttributes.mSlotID,
                                        extensionSetter_objectAttributes_mergeAttributes) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_objectAttributes_mergeAttributes (void) {
  gExtensionModifierTable_objectAttributes_mergeAttributes.removeAll () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_objectAttributes_mergeAttributes (defineExtensionSetter_objectAttributes_mergeAttributes,
                                                             freeExtensionModifier_objectAttributes_mergeAttributes) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@identifierList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_identifierList : public cCollectionElement {
  public: GALGAS_identifierList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_identifierList (const GALGAS_object_5F_t & in_item
                                             COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_identifierList (const GALGAS_identifierList_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_identifierList::cCollectionElement_identifierList (const GALGAS_object_5F_t & in_item
                                                                      COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_item) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_identifierList::cCollectionElement_identifierList (const GALGAS_identifierList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_item) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_identifierList::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_identifierList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_identifierList (mObject.mProperty_item COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_identifierList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "item" ":" ;
  mObject.mProperty_item.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_identifierList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_identifierList * operand = (cCollectionElement_identifierList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_identifierList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList::GALGAS_identifierList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList::GALGAS_identifierList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList GALGAS_identifierList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_identifierList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList GALGAS_identifierList::constructor_listWithValue (const GALGAS_object_5F_t & inOperand0
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_identifierList result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_identifierList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_identifierList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                       const GALGAS_object_5F_t & in_item
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement_identifierList * p = nullptr ;
  macroMyNew (p, cCollectionElement_identifierList (in_item COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierList::addAssign_operation (const GALGAS_object_5F_t & inOperand0
                                                 COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_identifierList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierList::setter_append (const GALGAS_object_5F_t inOperand0,
                                           C_Compiler * /* inCompiler */
                                           COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_identifierList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierList::setter_insertAtIndex (const GALGAS_object_5F_t inOperand0,
                                                  const GALGAS_uint inInsertionIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_identifierList (inOperand0 COMMA_THERE)) ;
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

void GALGAS_identifierList::setter_removeAtIndex (GALGAS_object_5F_t & outOperand0,
                                                  const GALGAS_uint inRemoveIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_identifierList) ;
        outOperand0 = p->mObject.mProperty_item ;
      }
    }else{
      outOperand0.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierList::setter_popFirst (GALGAS_object_5F_t & outOperand0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_identifierList) ;
    outOperand0 = p->mObject.mProperty_item ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierList::setter_popLast (GALGAS_object_5F_t & outOperand0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_identifierList) ;
    outOperand0 = p->mObject.mProperty_item ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierList::method_first (GALGAS_object_5F_t & outOperand0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_identifierList) ;
    outOperand0 = p->mObject.mProperty_item ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierList::method_last (GALGAS_object_5F_t & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_identifierList) ;
    outOperand0 = p->mObject.mProperty_item ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList GALGAS_identifierList::add_operation (const GALGAS_identifierList & inOperand,
                                                            C_Compiler * /* inCompiler */
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_identifierList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList GALGAS_identifierList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_identifierList result = GALGAS_identifierList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList GALGAS_identifierList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_identifierList result = GALGAS_identifierList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList GALGAS_identifierList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_identifierList result = GALGAS_identifierList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierList::plusAssign_operation (const GALGAS_identifierList inOperand,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierList::setter_setItemAtIndex (GALGAS_object_5F_t inOperand,
                                                   GALGAS_uint inIndex,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_identifierList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_item = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_object_5F_t GALGAS_identifierList::getter_itemAtIndex (const GALGAS_uint & inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
  GALGAS_object_5F_t result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_identifierList) ;
    result = p->mObject.mProperty_item ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_identifierList::cEnumerator_identifierList (const GALGAS_identifierList & inEnumeratedObject,
                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList_2D_element cEnumerator_identifierList::current (LOCATION_ARGS) const {
  const cCollectionElement_identifierList * p = (const cCollectionElement_identifierList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_identifierList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_object_5F_t cEnumerator_identifierList::current_item (LOCATION_ARGS) const {
  const cCollectionElement_identifierList * p = (const cCollectionElement_identifierList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_identifierList) ;
  return p->mObject.mProperty_item ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @identifierList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_identifierList ("identifierList",
                                       nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_identifierList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_identifierList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_identifierList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_identifierList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList GALGAS_identifierList::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_identifierList result ;
  const GALGAS_identifierList * p = (const GALGAS_identifierList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_identifierList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("identifierList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_stringMap::cMapElement_stringMap (const GALGAS_lstring & inKey,
                                              const GALGAS_string & in_value
                                              COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_stringMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_stringMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_stringMap (mProperty_lkey, mProperty_value COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_stringMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mProperty_value.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_stringMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_stringMap * operand = (cMapElement_stringMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (operand->mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap::GALGAS_stringMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap::GALGAS_stringMap (const GALGAS_stringMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap & GALGAS_stringMap::operator = (const GALGAS_stringMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap GALGAS_stringMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_stringMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap GALGAS_stringMap::constructor_mapWithMapToOverride (const GALGAS_stringMap & inMapToOverride
                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_stringMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap GALGAS_stringMap::getter_overriddenMap (C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_stringMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringMap::addAssign_operation (const GALGAS_lstring & inKey,
                                            const GALGAS_string & inArgument0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  cMapElement_stringMap * p = nullptr ;
  macroMyNew (p, cMapElement_stringMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@stringMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap GALGAS_stringMap::add_operation (const GALGAS_stringMap & inOperand,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_stringMap result = *this ;
  cEnumerator_stringMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_value (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringMap::setter_put (GALGAS_lstring inKey,
                                   GALGAS_string inArgument0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
  cMapElement_stringMap * p = nullptr ;
  macroMyNew (p, cMapElement_stringMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "stringmap key %K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_stringMap_get = "stringmap key %K is not defined" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringMap::method_get (GALGAS_lstring inKey,
                                   GALGAS_string & outArgument0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) const {
  const cMapElement_stringMap * p = (const cMapElement_stringMap *) performSearch (inKey,
                                                                                   inCompiler,
                                                                                   kSearchErrorMessage_stringMap_get
                                                                                   COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_stringMap) ;
    outArgument0 = p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_stringMap::getter_valueForKey (const GALGAS_string & inKey,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_stringMap * p = (const cMapElement_stringMap *) attributes ;
  GALGAS_string result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_stringMap) ;
    result = p->mProperty_value ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringMap::setter_setValueForKey (GALGAS_string inAttributeValue,
                                              GALGAS_string inKey,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_stringMap * p = (cMapElement_stringMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_stringMap) ;
    p->mProperty_value = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_stringMap * GALGAS_stringMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                             const GALGAS_string & inKey
                                                                             COMMA_LOCATION_ARGS) {
  cMapElement_stringMap * result = (cMapElement_stringMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_stringMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_stringMap::cEnumerator_stringMap (const GALGAS_stringMap & inEnumeratedObject,
                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap_2D_element cEnumerator_stringMap::current (LOCATION_ARGS) const {
  const cMapElement_stringMap * p = (const cMapElement_stringMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_stringMap) ;
  return GALGAS_stringMap_2D_element (p->mProperty_lkey, p->mProperty_value) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_stringMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cEnumerator_stringMap::current_value (LOCATION_ARGS) const {
  const cMapElement_stringMap * p = (const cMapElement_stringMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_stringMap) ;
  return p->mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_stringMap::optional_searchKey (const GALGAS_string & inKey,
                                           GALGAS_string & outArgument0) const {
  const cMapElement_stringMap * p = (const cMapElement_stringMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_stringMap) ;
    outArgument0 = p->mProperty_value ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @stringMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringMap ("stringMap",
                                  nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_stringMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_stringMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap GALGAS_stringMap::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_stringMap result ;
  const GALGAS_stringMap * p = (const GALGAS_stringMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_stringMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_lstringMap::cMapElement_lstringMap (const GALGAS_lstring & inKey,
                                                const GALGAS_lstring & in_value
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_lstringMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_lstringMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_lstringMap (mProperty_lkey, mProperty_value COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_lstringMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mProperty_value.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_lstringMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_lstringMap * operand = (cMapElement_lstringMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (operand->mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap::GALGAS_lstringMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap::GALGAS_lstringMap (const GALGAS_lstringMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap & GALGAS_lstringMap::operator = (const GALGAS_lstringMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap GALGAS_lstringMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_lstringMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap GALGAS_lstringMap::constructor_mapWithMapToOverride (const GALGAS_lstringMap & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_lstringMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap GALGAS_lstringMap::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_lstringMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_lstring & inArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_lstringMap * p = nullptr ;
  macroMyNew (p, cMapElement_lstringMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@lstringMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap GALGAS_lstringMap::add_operation (const GALGAS_lstringMap & inOperand,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_lstringMap result = *this ;
  cEnumerator_lstringMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_value (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringMap::setter_put (GALGAS_lstring inKey,
                                    GALGAS_lstring inArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  cMapElement_lstringMap * p = nullptr ;
  macroMyNew (p, cMapElement_lstringMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "lstringmap key %K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_lstringMap_get = "lstringmap key %K is not defined" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringMap::method_get (GALGAS_lstring inKey,
                                    GALGAS_lstring & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  const cMapElement_lstringMap * p = (const cMapElement_lstringMap *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_lstringMap_get
                                                                                     COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_lstringMap) ;
    outArgument0 = p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_lstringMap::getter_valueForKey (const GALGAS_string & inKey,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_lstringMap * p = (const cMapElement_lstringMap *) attributes ;
  GALGAS_lstring result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_lstringMap) ;
    result = p->mProperty_value ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringMap::setter_setValueForKey (GALGAS_lstring inAttributeValue,
                                               GALGAS_string inKey,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_lstringMap * p = (cMapElement_lstringMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_lstringMap) ;
    p->mProperty_value = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_lstringMap * GALGAS_lstringMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_lstringMap * result = (cMapElement_lstringMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_lstringMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_lstringMap::cEnumerator_lstringMap (const GALGAS_lstringMap & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap_2D_element cEnumerator_lstringMap::current (LOCATION_ARGS) const {
  const cMapElement_lstringMap * p = (const cMapElement_lstringMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_lstringMap) ;
  return GALGAS_lstringMap_2D_element (p->mProperty_lkey, p->mProperty_value) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_lstringMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_lstringMap::current_value (LOCATION_ARGS) const {
  const cMapElement_lstringMap * p = (const cMapElement_lstringMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_lstringMap) ;
  return p->mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_lstringMap::optional_searchKey (const GALGAS_string & inKey,
                                            GALGAS_lstring & outArgument0) const {
  const cMapElement_lstringMap * p = (const cMapElement_lstringMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_lstringMap) ;
    outArgument0 = p->mProperty_value ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @lstringMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lstringMap ("lstringMap",
                                   nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_lstringMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lstringMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_lstringMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lstringMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap GALGAS_lstringMap::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_lstringMap result ;
  const GALGAS_lstringMap * p = (const GALGAS_lstringMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_lstringMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lstringMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_prefix_5F_map::cMapElement_prefix_5F_map (const GALGAS_lstring & inKey,
                                                      const GALGAS_string & in_prefix,
                                                      const GALGAS_string & in_tag_5F_to_5F_rep
                                                      COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_prefix (in_prefix),
mProperty_tag_5F_to_5F_rep (in_tag_5F_to_5F_rep) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_prefix_5F_map::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_prefix_5F_map::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_prefix_5F_map (mProperty_lkey, mProperty_prefix, mProperty_tag_5F_to_5F_rep COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_prefix_5F_map::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "prefix" ":" ;
  mProperty_prefix.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "tag_to_rep" ":" ;
  mProperty_tag_5F_to_5F_rep.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_prefix_5F_map::compare (const cCollectionElement * inOperand) const {
  cMapElement_prefix_5F_map * operand = (cMapElement_prefix_5F_map *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_prefix.objectCompare (operand->mProperty_prefix) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_tag_5F_to_5F_rep.objectCompare (operand->mProperty_tag_5F_to_5F_rep) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map::GALGAS_prefix_5F_map (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map::GALGAS_prefix_5F_map (const GALGAS_prefix_5F_map & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map & GALGAS_prefix_5F_map::operator = (const GALGAS_prefix_5F_map & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map GALGAS_prefix_5F_map::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_prefix_5F_map result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map GALGAS_prefix_5F_map::constructor_mapWithMapToOverride (const GALGAS_prefix_5F_map & inMapToOverride
                                                                             COMMA_LOCATION_ARGS) {
  GALGAS_prefix_5F_map result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map GALGAS_prefix_5F_map::getter_overriddenMap (C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_prefix_5F_map result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_prefix_5F_map::addAssign_operation (const GALGAS_lstring & inKey,
                                                const GALGAS_string & inArgument0,
                                                const GALGAS_string & inArgument1,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cMapElement_prefix_5F_map * p = nullptr ;
  macroMyNew (p, cMapElement_prefix_5F_map (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@prefix_5F_map insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map GALGAS_prefix_5F_map::add_operation (const GALGAS_prefix_5F_map & inOperand,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_prefix_5F_map result = *this ;
  cEnumerator_prefix_5F_map enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_prefix (HERE), enumerator.current_tag_5F_to_5F_rep (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_prefix_5F_map::setter_add (GALGAS_lstring inKey,
                                       GALGAS_string inArgument0,
                                       GALGAS_string inArgument1,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  cMapElement_prefix_5F_map * p = nullptr ;
  macroMyNew (p, cMapElement_prefix_5F_map (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "prefix %K duplicated %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_prefix_5F_map::setter_insert_5F_prefix (GALGAS_lstring inKey,
                                                    GALGAS_string inArgument0,
                                                    GALGAS_string inArgument1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cMapElement_prefix_5F_map * p = nullptr ;
  macroMyNew (p, cMapElement_prefix_5F_map (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "prefix %K duplicated %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_prefix_5F_map_prefix = "prefix %K is not defined" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_prefix_5F_map::method_prefix (GALGAS_lstring inKey,
                                          GALGAS_string & outArgument0,
                                          GALGAS_string & outArgument1,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) performSearch (inKey,
                                                                                           inCompiler,
                                                                                           kSearchErrorMessage_prefix_5F_map_prefix
                                                                                           COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
    outArgument0 = p->mProperty_prefix ;
    outArgument1 = p->mProperty_tag_5F_to_5F_rep ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_prefix_5F_map::getter_prefixForKey (const GALGAS_string & inKey,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) attributes ;
  GALGAS_string result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
    result = p->mProperty_prefix ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_prefix_5F_map::getter_tag_5F_to_5F_repForKey (const GALGAS_string & inKey,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) attributes ;
  GALGAS_string result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
    result = p->mProperty_tag_5F_to_5F_rep ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_prefix_5F_map::setter_setPrefixForKey (GALGAS_string inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_prefix_5F_map * p = (cMapElement_prefix_5F_map *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
    p->mProperty_prefix = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_prefix_5F_map::setter_setTag_5F_to_5F_repForKey (GALGAS_string inAttributeValue,
                                                             GALGAS_string inKey,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_prefix_5F_map * p = (cMapElement_prefix_5F_map *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
    p->mProperty_tag_5F_to_5F_rep = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_prefix_5F_map * GALGAS_prefix_5F_map::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                     const GALGAS_string & inKey
                                                                                     COMMA_LOCATION_ARGS) {
  cMapElement_prefix_5F_map * result = (cMapElement_prefix_5F_map *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_prefix_5F_map) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_prefix_5F_map::cEnumerator_prefix_5F_map (const GALGAS_prefix_5F_map & inEnumeratedObject,
                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map_2D_element cEnumerator_prefix_5F_map::current (LOCATION_ARGS) const {
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
  return GALGAS_prefix_5F_map_2D_element (p->mProperty_lkey, p->mProperty_prefix, p->mProperty_tag_5F_to_5F_rep) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_prefix_5F_map::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cEnumerator_prefix_5F_map::current_prefix (LOCATION_ARGS) const {
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
  return p->mProperty_prefix ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cEnumerator_prefix_5F_map::current_tag_5F_to_5F_rep (LOCATION_ARGS) const {
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
  return p->mProperty_tag_5F_to_5F_rep ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_prefix_5F_map::optional_searchKey (const GALGAS_string & inKey,
                                               GALGAS_string & outArgument0,
                                               GALGAS_string & outArgument1) const {
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
    outArgument0 = p->mProperty_prefix ;
    outArgument1 = p->mProperty_tag_5F_to_5F_rep ;
  }else{
    outArgument0.drop () ;
    outArgument1.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @prefix_map generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_prefix_5F_map ("prefix_map",
                                      nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_prefix_5F_map::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_prefix_5F_map ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_prefix_5F_map::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_prefix_5F_map (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map GALGAS_prefix_5F_map::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_prefix_5F_map result ;
  const GALGAS_prefix_5F_map * p = (const GALGAS_prefix_5F_map *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_prefix_5F_map *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("prefix_map", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_stringset_5F_map::cMapElement_stringset_5F_map (const GALGAS_lstring & inKey,
                                                            const GALGAS_stringset & in_ids
                                                            COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_ids (in_ids) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_stringset_5F_map::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_stringset_5F_map::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_stringset_5F_map (mProperty_lkey, mProperty_ids COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_stringset_5F_map::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "ids" ":" ;
  mProperty_ids.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_stringset_5F_map::compare (const cCollectionElement * inOperand) const {
  cMapElement_stringset_5F_map * operand = (cMapElement_stringset_5F_map *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_ids.objectCompare (operand->mProperty_ids) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map::GALGAS_stringset_5F_map (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map::GALGAS_stringset_5F_map (const GALGAS_stringset_5F_map & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map & GALGAS_stringset_5F_map::operator = (const GALGAS_stringset_5F_map & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map GALGAS_stringset_5F_map::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_stringset_5F_map result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map GALGAS_stringset_5F_map::constructor_mapWithMapToOverride (const GALGAS_stringset_5F_map & inMapToOverride
                                                                                   COMMA_LOCATION_ARGS) {
  GALGAS_stringset_5F_map result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map GALGAS_stringset_5F_map::getter_overriddenMap (C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  GALGAS_stringset_5F_map result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringset_5F_map::addAssign_operation (const GALGAS_lstring & inKey,
                                                   const GALGAS_stringset & inArgument0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cMapElement_stringset_5F_map * p = nullptr ;
  macroMyNew (p, cMapElement_stringset_5F_map (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@stringset_5F_map insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map GALGAS_stringset_5F_map::add_operation (const GALGAS_stringset_5F_map & inOperand,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_stringset_5F_map result = *this ;
  cEnumerator_stringset_5F_map enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_ids (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringset_5F_map::setter_add (GALGAS_lstring inKey,
                                          GALGAS_stringset inArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  cMapElement_stringset_5F_map * p = nullptr ;
  macroMyNew (p, cMapElement_stringset_5F_map (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "Key %K is already used there" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_stringset_5F_map_get = "Key %K is not there" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringset_5F_map::method_get (GALGAS_lstring inKey,
                                          GALGAS_stringset & outArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const cMapElement_stringset_5F_map * p = (const cMapElement_stringset_5F_map *) performSearch (inKey,
                                                                                                 inCompiler,
                                                                                                 kSearchErrorMessage_stringset_5F_map_get
                                                                                                 COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
    outArgument0 = p->mProperty_ids ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringset_5F_map::setter_delete (GALGAS_lstring inKey,
                                             GALGAS_stringset & outArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "Key %K cannot be deleted" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_stringset_5F_map * p = (cMapElement_stringset_5F_map *) attributes.ptr () ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
    outArgument0 = p->mProperty_ids ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset GALGAS_stringset_5F_map::getter_idsForKey (const GALGAS_string & inKey,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_stringset_5F_map * p = (const cMapElement_stringset_5F_map *) attributes ;
  GALGAS_stringset result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
    result = p->mProperty_ids ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringset_5F_map::setter_setIdsForKey (GALGAS_stringset inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_stringset_5F_map * p = (cMapElement_stringset_5F_map *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
    p->mProperty_ids = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_stringset_5F_map * GALGAS_stringset_5F_map::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                           const GALGAS_string & inKey
                                                                                           COMMA_LOCATION_ARGS) {
  cMapElement_stringset_5F_map * result = (cMapElement_stringset_5F_map *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_stringset_5F_map) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_stringset_5F_map::cEnumerator_stringset_5F_map (const GALGAS_stringset_5F_map & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map_2D_element cEnumerator_stringset_5F_map::current (LOCATION_ARGS) const {
  const cMapElement_stringset_5F_map * p = (const cMapElement_stringset_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
  return GALGAS_stringset_5F_map_2D_element (p->mProperty_lkey, p->mProperty_ids) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_stringset_5F_map::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset cEnumerator_stringset_5F_map::current_ids (LOCATION_ARGS) const {
  const cMapElement_stringset_5F_map * p = (const cMapElement_stringset_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
  return p->mProperty_ids ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_stringset_5F_map::optional_searchKey (const GALGAS_string & inKey,
                                                  GALGAS_stringset & outArgument0) const {
  const cMapElement_stringset_5F_map * p = (const cMapElement_stringset_5F_map *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
    outArgument0 = p->mProperty_ids ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @stringset_map generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringset_5F_map ("stringset_map",
                                         nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_stringset_5F_map::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringset_5F_map ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_stringset_5F_map::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringset_5F_map (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map GALGAS_stringset_5F_map::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_stringset_5F_map result ;
  const GALGAS_stringset_5F_map * p = (const GALGAS_stringset_5F_map *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_stringset_5F_map *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringset_map", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@ident_5F_list' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_ident_5F_list : public cCollectionElement {
  public: GALGAS_ident_5F_list_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_ident_5F_list (const GALGAS_lstring & in_obj_5F_name
                                            COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_ident_5F_list (const GALGAS_ident_5F_list_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_ident_5F_list::cCollectionElement_ident_5F_list (const GALGAS_lstring & in_obj_5F_name
                                                                    COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_obj_5F_name) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_ident_5F_list::cCollectionElement_ident_5F_list (const GALGAS_ident_5F_list_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_obj_5F_name) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_ident_5F_list::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_ident_5F_list::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_ident_5F_list (mObject.mProperty_obj_5F_name COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_ident_5F_list::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "obj_name" ":" ;
  mObject.mProperty_obj_5F_name.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_ident_5F_list::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_ident_5F_list * operand = (cCollectionElement_ident_5F_list *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_ident_5F_list) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list::GALGAS_ident_5F_list (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list::GALGAS_ident_5F_list (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list GALGAS_ident_5F_list::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_ident_5F_list  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list GALGAS_ident_5F_list::constructor_listWithValue (const GALGAS_lstring & inOperand0
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_ident_5F_list (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_ident_5F_list::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                      const GALGAS_lstring & in_obj_5F_name
                                                      COMMA_LOCATION_ARGS) {
  cCollectionElement_ident_5F_list * p = nullptr ;
  macroMyNew (p, cCollectionElement_ident_5F_list (in_obj_5F_name COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list::addAssign_operation (const GALGAS_lstring & inOperand0
                                                COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_ident_5F_list (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list::setter_append (const GALGAS_lstring inOperand0,
                                          C_Compiler * /* inCompiler */
                                          COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_ident_5F_list (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                 const GALGAS_uint inInsertionIndex,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_ident_5F_list (inOperand0 COMMA_THERE)) ;
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

void GALGAS_ident_5F_list::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                 const GALGAS_uint inRemoveIndex,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
        outOperand0 = p->mObject.mProperty_obj_5F_name ;
      }
    }else{
      outOperand0.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list::setter_popFirst (GALGAS_lstring & outOperand0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
    outOperand0 = p->mObject.mProperty_obj_5F_name ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list::setter_popLast (GALGAS_lstring & outOperand0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
    outOperand0 = p->mObject.mProperty_obj_5F_name ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list::method_first (GALGAS_lstring & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
    outOperand0 = p->mObject.mProperty_obj_5F_name ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list::method_last (GALGAS_lstring & outOperand0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
    outOperand0 = p->mObject.mProperty_obj_5F_name ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list GALGAS_ident_5F_list::add_operation (const GALGAS_ident_5F_list & inOperand,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_ident_5F_list result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list GALGAS_ident_5F_list::getter_subListWithRange (const GALGAS_range & inRange,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_ident_5F_list result = GALGAS_ident_5F_list::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list GALGAS_ident_5F_list::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_ident_5F_list result = GALGAS_ident_5F_list::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list GALGAS_ident_5F_list::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_ident_5F_list result = GALGAS_ident_5F_list::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list::plusAssign_operation (const GALGAS_ident_5F_list inOperand,
                                                 C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list::setter_setObj_5F_nameAtIndex (GALGAS_lstring inOperand,
                                                         GALGAS_uint inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_obj_5F_name = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_ident_5F_list::getter_obj_5F_nameAtIndex (const GALGAS_uint & inIndex,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
    result = p->mObject.mProperty_obj_5F_name ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_ident_5F_list::cEnumerator_ident_5F_list (const GALGAS_ident_5F_list & inEnumeratedObject,
                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_2D_element cEnumerator_ident_5F_list::current (LOCATION_ARGS) const {
  const cCollectionElement_ident_5F_list * p = (const cCollectionElement_ident_5F_list *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_ident_5F_list::current_obj_5F_name (LOCATION_ARGS) const {
  const cCollectionElement_ident_5F_list * p = (const cCollectionElement_ident_5F_list *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
  return p->mObject.mProperty_obj_5F_name ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @ident_list generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ident_5F_list ("ident_list",
                                      nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_ident_5F_list::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ident_5F_list ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_ident_5F_list::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ident_5F_list (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list GALGAS_ident_5F_list::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list result ;
  const GALGAS_ident_5F_list * p = (const GALGAS_ident_5F_list *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_ident_5F_list *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ident_list", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_ident_5F_list_5F_map::cMapElement_ident_5F_list_5F_map (const GALGAS_lstring & inKey,
                                                                    const GALGAS_ident_5F_list & in_objs
                                                                    COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_objs (in_objs) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_ident_5F_list_5F_map::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_ident_5F_list_5F_map::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_ident_5F_list_5F_map (mProperty_lkey, mProperty_objs COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_ident_5F_list_5F_map::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "objs" ":" ;
  mProperty_objs.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_ident_5F_list_5F_map::compare (const cCollectionElement * inOperand) const {
  cMapElement_ident_5F_list_5F_map * operand = (cMapElement_ident_5F_list_5F_map *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_objs.objectCompare (operand->mProperty_objs) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map::GALGAS_ident_5F_list_5F_map (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map::GALGAS_ident_5F_list_5F_map (const GALGAS_ident_5F_list_5F_map & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map & GALGAS_ident_5F_list_5F_map::operator = (const GALGAS_ident_5F_list_5F_map & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map GALGAS_ident_5F_list_5F_map::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_ident_5F_list_5F_map result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map GALGAS_ident_5F_list_5F_map::constructor_mapWithMapToOverride (const GALGAS_ident_5F_list_5F_map & inMapToOverride
                                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list_5F_map result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map GALGAS_ident_5F_list_5F_map::getter_overriddenMap (C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_ident_5F_list_5F_map result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list_5F_map::addAssign_operation (const GALGAS_lstring & inKey,
                                                       const GALGAS_ident_5F_list & inArgument0,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cMapElement_ident_5F_list_5F_map * p = nullptr ;
  macroMyNew (p, cMapElement_ident_5F_list_5F_map (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@ident_5F_list_5F_map insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map GALGAS_ident_5F_list_5F_map::add_operation (const GALGAS_ident_5F_list_5F_map & inOperand,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_ident_5F_list_5F_map result = *this ;
  cEnumerator_ident_5F_list_5F_map enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_objs (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list_5F_map::setter_add (GALGAS_lstring inKey,
                                              GALGAS_ident_5F_list inArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  cMapElement_ident_5F_list_5F_map * p = nullptr ;
  macroMyNew (p, cMapElement_ident_5F_list_5F_map (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "Key %K is already used there" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_ident_5F_list_5F_map_get = "Key %K is not there" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list_5F_map::method_get (GALGAS_lstring inKey,
                                              GALGAS_ident_5F_list & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  const cMapElement_ident_5F_list_5F_map * p = (const cMapElement_ident_5F_list_5F_map *) performSearch (inKey,
                                                                                                         inCompiler,
                                                                                                         kSearchErrorMessage_ident_5F_list_5F_map_get
                                                                                                         COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
    outArgument0 = p->mProperty_objs ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list_5F_map::setter_delete (GALGAS_lstring inKey,
                                                 GALGAS_ident_5F_list & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "Key %K cannot be deleted" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_ident_5F_list_5F_map * p = (cMapElement_ident_5F_list_5F_map *) attributes.ptr () ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
    outArgument0 = p->mProperty_objs ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list GALGAS_ident_5F_list_5F_map::getter_objsForKey (const GALGAS_string & inKey,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_ident_5F_list_5F_map * p = (const cMapElement_ident_5F_list_5F_map *) attributes ;
  GALGAS_ident_5F_list result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
    result = p->mProperty_objs ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list_5F_map::setter_setObjsForKey (GALGAS_ident_5F_list inAttributeValue,
                                                        GALGAS_string inKey,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_ident_5F_list_5F_map * p = (cMapElement_ident_5F_list_5F_map *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
    p->mProperty_objs = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_ident_5F_list_5F_map * GALGAS_ident_5F_list_5F_map::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                                   const GALGAS_string & inKey
                                                                                                   COMMA_LOCATION_ARGS) {
  cMapElement_ident_5F_list_5F_map * result = (cMapElement_ident_5F_list_5F_map *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_ident_5F_list_5F_map) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_ident_5F_list_5F_map::cEnumerator_ident_5F_list_5F_map (const GALGAS_ident_5F_list_5F_map & inEnumeratedObject,
                                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map_2D_element cEnumerator_ident_5F_list_5F_map::current (LOCATION_ARGS) const {
  const cMapElement_ident_5F_list_5F_map * p = (const cMapElement_ident_5F_list_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
  return GALGAS_ident_5F_list_5F_map_2D_element (p->mProperty_lkey, p->mProperty_objs) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_ident_5F_list_5F_map::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list cEnumerator_ident_5F_list_5F_map::current_objs (LOCATION_ARGS) const {
  const cMapElement_ident_5F_list_5F_map * p = (const cMapElement_ident_5F_list_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
  return p->mProperty_objs ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_ident_5F_list_5F_map::optional_searchKey (const GALGAS_string & inKey,
                                                      GALGAS_ident_5F_list & outArgument0) const {
  const cMapElement_ident_5F_list_5F_map * p = (const cMapElement_ident_5F_list_5F_map *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
    outArgument0 = p->mProperty_objs ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @ident_list_map generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ident_5F_list_5F_map ("ident_list_map",
                                             nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_ident_5F_list_5F_map::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ident_5F_list_5F_map ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_ident_5F_list_5F_map::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ident_5F_list_5F_map (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map GALGAS_ident_5F_list_5F_map::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list_5F_map result ;
  const GALGAS_ident_5F_list_5F_map * p = (const GALGAS_ident_5F_list_5F_map *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_ident_5F_list_5F_map *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ident_list_map", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------



typeComparisonResult GALGAS_autostart_5F_obj::objectCompare (const GALGAS_autostart_5F_obj & inOperand) const {
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

GALGAS_autostart_5F_obj::GALGAS_autostart_5F_obj (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_autostart_5F_obj::GALGAS_autostart_5F_obj (const cPtr_autostart_5F_obj * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_autostart_5F_obj) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_autostart_5F_obj::readProperty_location (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_location () ;
  }else{
    const cPtr_autostart_5F_obj * p = (const cPtr_autostart_5F_obj *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_autostart_5F_obj) ;
    return p->mProperty_location ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cPtr_autostart_5F_obj::getter_location (UNUSED_LOCATION_ARGS) const {
  return mProperty_location ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_autostart_5F_obj::setter_setLocation (GALGAS_location inValue
                                                  COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_autostart_5F_obj * p = (cPtr_autostart_5F_obj *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_autostart_5F_obj) ;
    p->mProperty_location = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_autostart_5F_obj::setter_setLocation (GALGAS_location inValue
                                                COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_location = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @autostart_obj class
//----------------------------------------------------------------------------------------------------------------------

cPtr_autostart_5F_obj::cPtr_autostart_5F_obj (const GALGAS_location & in_location
                                              COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_location (in_location) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @autostart_obj generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_autostart_5F_obj ("autostart_obj",
                                         nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_autostart_5F_obj::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_obj ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_autostart_5F_obj::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_autostart_5F_obj (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_autostart_5F_obj GALGAS_autostart_5F_obj::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_obj result ;
  const GALGAS_autostart_5F_obj * p = (const GALGAS_autostart_5F_obj *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_autostart_5F_obj *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("autostart_obj", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_autostart_5F_void::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_autostart_5F_void * p = (const cPtr_autostart_5F_void *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_autostart_5F_void) ;
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_autostart_5F_void::objectCompare (const GALGAS_autostart_5F_void & inOperand) const {
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

GALGAS_autostart_5F_void::GALGAS_autostart_5F_void (void) :
GALGAS_autostart_5F_obj () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_autostart_5F_void GALGAS_autostart_5F_void::constructor_default (LOCATION_ARGS) {
  return GALGAS_autostart_5F_void::constructor_new (GALGAS_location::constructor_nowhere (HERE)
                                                    COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_autostart_5F_void::GALGAS_autostart_5F_void (const cPtr_autostart_5F_void * inSourcePtr) :
GALGAS_autostart_5F_obj (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_autostart_5F_void) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_autostart_5F_void GALGAS_autostart_5F_void::constructor_new (const GALGAS_location & inAttribute_location
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_void result ;
  if (inAttribute_location.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_autostart_5F_void (inAttribute_location COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @autostart_void class
//----------------------------------------------------------------------------------------------------------------------

cPtr_autostart_5F_void::cPtr_autostart_5F_void (const GALGAS_location & in_location
                                                COMMA_LOCATION_ARGS) :
cPtr_autostart_5F_obj (in_location COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_autostart_5F_void::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_void ;
}

void cPtr_autostart_5F_void::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@autostart_void:" ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_autostart_5F_void::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_autostart_5F_void (mProperty_location COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @autostart_void generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_autostart_5F_void ("autostart_void",
                                          & kTypeDescriptor_GALGAS_autostart_5F_obj) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_autostart_5F_void::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_void ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_autostart_5F_void::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_autostart_5F_void (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_autostart_5F_void GALGAS_autostart_5F_void::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_void result ;
  const GALGAS_autostart_5F_void * p = (const GALGAS_autostart_5F_void *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_autostart_5F_void *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("autostart_void", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_autostart_5F_false::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_autostart_5F_false * p = (const cPtr_autostart_5F_false *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_autostart_5F_false) ;
  if (kOperandEqual == result) {
    result = mProperty_location.objectCompare (p->mProperty_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_autostart_5F_false::objectCompare (const GALGAS_autostart_5F_false & inOperand) const {
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

GALGAS_autostart_5F_false::GALGAS_autostart_5F_false (void) :
GALGAS_autostart_5F_obj () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_autostart_5F_false GALGAS_autostart_5F_false::constructor_default (LOCATION_ARGS) {
  return GALGAS_autostart_5F_false::constructor_new (GALGAS_location::constructor_nowhere (HERE)
                                                     COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_autostart_5F_false::GALGAS_autostart_5F_false (const cPtr_autostart_5F_false * inSourcePtr) :
GALGAS_autostart_5F_obj (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_autostart_5F_false) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_autostart_5F_false GALGAS_autostart_5F_false::constructor_new (const GALGAS_location & inAttribute_location
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_false result ;
  if (inAttribute_location.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_autostart_5F_false (inAttribute_location COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @autostart_false class
//----------------------------------------------------------------------------------------------------------------------

cPtr_autostart_5F_false::cPtr_autostart_5F_false (const GALGAS_location & in_location
                                                  COMMA_LOCATION_ARGS) :
cPtr_autostart_5F_obj (in_location COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_autostart_5F_false::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_false ;
}

void cPtr_autostart_5F_false::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@autostart_false:" ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_autostart_5F_false::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_autostart_5F_false (mProperty_location COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @autostart_false generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_autostart_5F_false ("autostart_false",
                                           & kTypeDescriptor_GALGAS_autostart_5F_obj) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_autostart_5F_false::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_false ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_autostart_5F_false::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_autostart_5F_false (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_autostart_5F_false GALGAS_autostart_5F_false::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_false result ;
  const GALGAS_autostart_5F_false * p = (const GALGAS_autostart_5F_false *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_autostart_5F_false *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("autostart_false", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@objectAttributes fieldMap'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_objectAttributes::getter_fieldMap (C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlStruct::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 160)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 160)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 160))  COMMA_SOURCE_FILE ("systemConfig.galgas", 160)) ;
  cEnumerator_identifierMap enumerator_5172 (this->mProperty_objectParams, kENUMERATION_UP) ;
  while (enumerator_5172.hasCurrentObject ()) {
    callExtensionMethod_set ((cPtr_object_5F_t *) enumerator_5172.current_value (HERE).ptr (), enumerator_5172.current_lkey (HERE), result_result, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 162)) ;
    enumerator_5172.gotoNextObject () ;
  }
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_fieldMap (const cPtr_objectAttributes * inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_fieldMap (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@string trimLeft'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_trimLeft (const GALGAS_string & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    const GALGAS_string temp_1 = inObject ;
    test_0 = GALGAS_bool (kIsEqual, temp_1.getter_leftSubString (GALGAS_uint (uint32_t (1U)) COMMA_SOURCE_FILE ("systemConfig.galgas", 169)).objectCompare (GALGAS_string (" "))).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_string temp_2 = inObject ;
      const GALGAS_string temp_3 = inObject ;
      result_result = extensionGetter_trimLeft (temp_2.getter_rightSubString (temp_3.getter_count (SOURCE_FILE ("systemConfig.galgas", 170)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 170)) COMMA_SOURCE_FILE ("systemConfig.galgas", 170)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 170)) ;
    }
  }
  if (kBoolFalse == test_0) {
    const GALGAS_string temp_4 = inObject ;
    result_result = temp_4 ;
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@string trimRight'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_trimRight (const GALGAS_string & inObject,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    const GALGAS_string temp_1 = inObject ;
    test_0 = GALGAS_bool (kIsEqual, temp_1.getter_rightSubString (GALGAS_uint (uint32_t (1U)) COMMA_SOURCE_FILE ("systemConfig.galgas", 179)).objectCompare (GALGAS_string (" "))).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_string temp_2 = inObject ;
      const GALGAS_string temp_3 = inObject ;
      result_result = extensionGetter_trimRight (temp_2.getter_leftSubString (temp_3.getter_count (SOURCE_FILE ("systemConfig.galgas", 180)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 180)) COMMA_SOURCE_FILE ("systemConfig.galgas", 180)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 180)) ;
    }
  }
  if (kBoolFalse == test_0) {
    const GALGAS_string temp_4 = inObject ;
    result_result = temp_4 ;
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@implementation verifyApplication'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_implementation::method_verifyApplication (const GALGAS_applicationDefinition constinArgument_appDef,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_implementationMap enumerator_907 (this->mProperty_imp, kENUMERATION_UP) ;
  while (enumerator_907.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = constinArgument_appDef.readProperty_objects ().getter_hasKey (enumerator_907.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("semantic_verification.galgas", 35)).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_objectKind var_obj_1005 ;
        constinArgument_appDef.readProperty_objects ().method_get (enumerator_907.current_lkey (HERE), var_obj_1005, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 37)) ;
        callExtensionMethod_verifyApplication ((cPtr_implementationObject *) enumerator_907.current_obj (HERE).ptr (), var_obj_1005, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 38)) ;
      }
    }
    enumerator_907.gotoNextObject () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyApplication (cPtr_implementation * inObject,
                                            const GALGAS_applicationDefinition constin_appDef,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_implementation) ;
    inObject->method_verifyApplication  (constin_appDef, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

cMapElement_objectsMap::cMapElement_objectsMap (const GALGAS_lstring & inKey,
                                                const GALGAS_objectKind & in_objectsOfKind
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_objectsOfKind (in_objectsOfKind) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_objectsMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_objectsMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_objectsMap (mProperty_lkey, mProperty_objectsOfKind COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_objectsMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "objectsOfKind" ":" ;
  mProperty_objectsOfKind.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_objectsMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_objectsMap * operand = (cMapElement_objectsMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_objectsOfKind.objectCompare (operand->mProperty_objectsOfKind) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap::GALGAS_objectsMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap::GALGAS_objectsMap (const GALGAS_objectsMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap & GALGAS_objectsMap::operator = (const GALGAS_objectsMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap GALGAS_objectsMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_objectsMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap GALGAS_objectsMap::constructor_mapWithMapToOverride (const GALGAS_objectsMap & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_objectsMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap GALGAS_objectsMap::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_objectsMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectsMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_objectKind & inArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_objectsMap * p = nullptr ;
  macroMyNew (p, cMapElement_objectsMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@objectsMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap GALGAS_objectsMap::add_operation (const GALGAS_objectsMap & inOperand,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_objectsMap result = *this ;
  cEnumerator_objectsMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_objectsOfKind (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectsMap::setter_put (GALGAS_lstring inKey,
                                    GALGAS_objectKind inArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  cMapElement_objectsMap * p = nullptr ;
  macroMyNew (p, cMapElement_objectsMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "%K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_objectsMap_get = "%K does not exists" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectsMap::method_get (GALGAS_lstring inKey,
                                    GALGAS_objectKind & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  const cMapElement_objectsMap * p = (const cMapElement_objectsMap *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_objectsMap_get
                                                                                     COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_objectsMap) ;
    outArgument0 = p->mProperty_objectsOfKind ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectsMap::setter_del (GALGAS_lstring inKey,
                                    GALGAS_objectKind & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "%K does not exists" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_objectsMap * p = (cMapElement_objectsMap *) attributes.ptr () ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_objectsMap) ;
    outArgument0 = p->mProperty_objectsOfKind ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKind GALGAS_objectsMap::getter_objectsOfKindForKey (const GALGAS_string & inKey,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_objectsMap * p = (const cMapElement_objectsMap *) attributes ;
  GALGAS_objectKind result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_objectsMap) ;
    result = p->mProperty_objectsOfKind ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectsMap::setter_setObjectsOfKindForKey (GALGAS_objectKind inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_objectsMap * p = (cMapElement_objectsMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_objectsMap) ;
    p->mProperty_objectsOfKind = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_objectsMap * GALGAS_objectsMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_objectsMap * result = (cMapElement_objectsMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_objectsMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_objectsMap::cEnumerator_objectsMap (const GALGAS_objectsMap & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap_2D_element cEnumerator_objectsMap::current (LOCATION_ARGS) const {
  const cMapElement_objectsMap * p = (const cMapElement_objectsMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_objectsMap) ;
  return GALGAS_objectsMap_2D_element (p->mProperty_lkey, p->mProperty_objectsOfKind) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_objectsMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKind cEnumerator_objectsMap::current_objectsOfKind (LOCATION_ARGS) const {
  const cMapElement_objectsMap * p = (const cMapElement_objectsMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_objectsMap) ;
  return p->mProperty_objectsOfKind ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_objectsMap::optional_searchKey (const GALGAS_string & inKey,
                                            GALGAS_objectKind & outArgument0) const {
  const cMapElement_objectsMap * p = (const cMapElement_objectsMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_objectsMap) ;
    outArgument0 = p->mProperty_objectsOfKind ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @objectsMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectsMap ("objectsMap",
                                   nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_objectsMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectsMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_objectsMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectsMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap GALGAS_objectsMap::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_objectsMap result ;
  const GALGAS_objectsMap * p = (const GALGAS_objectsMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_objectsMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectsMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@objectAttributes verifyCrossReferences'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_objectAttributes::method_verifyCrossReferences (const GALGAS_objectsMap constinArgument_allObjects,
                                                          const GALGAS_implementationObjectMap constinArgument_attributes,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_identifierMap enumerator_18641 (this->mProperty_objectParams, kENUMERATION_UP) ;
  while (enumerator_18641.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = constinArgument_attributes.getter_hasKey (enumerator_18641.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("semantic_verification.galgas", 599)).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_impType var_type_18752 ;
        constinArgument_attributes.method_get (enumerator_18641.current_lkey (HERE), var_type_18752, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 600)) ;
        callExtensionMethod_verifyCrossReferences ((cPtr_object_5F_t *) enumerator_18641.current_value (HERE).ptr (), constinArgument_allObjects, var_type_18752, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 601)) ;
      }
    }
    enumerator_18641.gotoNextObject () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyCrossReferences (cPtr_objectAttributes * inObject,
                                                const GALGAS_objectsMap constin_allObjects,
                                                const GALGAS_implementationObjectMap constin_attributes,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_objectAttributes) ;
    inObject->method_verifyCrossReferences  (constin_allObjects, constin_attributes, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

cMapElement_objectKindMap::cMapElement_objectKindMap (const GALGAS_lstring & inKey,
                                                      const GALGAS_objectAttributes & in_attributes
                                                      COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_attributes (in_attributes) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_objectKindMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_objectKindMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_objectKindMap (mProperty_lkey, mProperty_attributes COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_objectKindMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "attributes" ":" ;
  mProperty_attributes.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_objectKindMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_objectKindMap * operand = (cMapElement_objectKindMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_attributes.objectCompare (operand->mProperty_attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap::GALGAS_objectKindMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap::GALGAS_objectKindMap (const GALGAS_objectKindMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap & GALGAS_objectKindMap::operator = (const GALGAS_objectKindMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap GALGAS_objectKindMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_objectKindMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap GALGAS_objectKindMap::constructor_mapWithMapToOverride (const GALGAS_objectKindMap & inMapToOverride
                                                                             COMMA_LOCATION_ARGS) {
  GALGAS_objectKindMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap GALGAS_objectKindMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_objectKindMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectKindMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                const GALGAS_objectAttributes & inArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cMapElement_objectKindMap * p = nullptr ;
  macroMyNew (p, cMapElement_objectKindMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@objectKindMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap GALGAS_objectKindMap::add_operation (const GALGAS_objectKindMap & inOperand,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_objectKindMap result = *this ;
  cEnumerator_objectKindMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_attributes (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectKindMap::setter_put (GALGAS_lstring inKey,
                                       GALGAS_objectAttributes inArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  cMapElement_objectKindMap * p = nullptr ;
  macroMyNew (p, cMapElement_objectKindMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "%K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_objectKindMap_get = "%K does not exists" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectKindMap::method_get (GALGAS_lstring inKey,
                                       GALGAS_objectAttributes & outArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  const cMapElement_objectKindMap * p = (const cMapElement_objectKindMap *) performSearch (inKey,
                                                                                           inCompiler,
                                                                                           kSearchErrorMessage_objectKindMap_get
                                                                                           COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_objectKindMap) ;
    outArgument0 = p->mProperty_attributes ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectKindMap::setter_del (GALGAS_lstring inKey,
                                       GALGAS_objectAttributes & outArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "%K does not exists" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_objectKindMap * p = (cMapElement_objectKindMap *) attributes.ptr () ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_objectKindMap) ;
    outArgument0 = p->mProperty_attributes ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectAttributes GALGAS_objectKindMap::getter_attributesForKey (const GALGAS_string & inKey,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_objectKindMap * p = (const cMapElement_objectKindMap *) attributes ;
  GALGAS_objectAttributes result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_objectKindMap) ;
    result = p->mProperty_attributes ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectKindMap::setter_setAttributesForKey (GALGAS_objectAttributes inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_objectKindMap * p = (cMapElement_objectKindMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_objectKindMap) ;
    p->mProperty_attributes = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_objectKindMap * GALGAS_objectKindMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                     const GALGAS_string & inKey
                                                                                     COMMA_LOCATION_ARGS) {
  cMapElement_objectKindMap * result = (cMapElement_objectKindMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_objectKindMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_objectKindMap::cEnumerator_objectKindMap (const GALGAS_objectKindMap & inEnumeratedObject,
                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap_2D_element cEnumerator_objectKindMap::current (LOCATION_ARGS) const {
  const cMapElement_objectKindMap * p = (const cMapElement_objectKindMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_objectKindMap) ;
  return GALGAS_objectKindMap_2D_element (p->mProperty_lkey, p->mProperty_attributes) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_objectKindMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectAttributes cEnumerator_objectKindMap::current_attributes (LOCATION_ARGS) const {
  const cMapElement_objectKindMap * p = (const cMapElement_objectKindMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_objectKindMap) ;
  return p->mProperty_attributes ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_objectKindMap::optional_searchKey (const GALGAS_string & inKey,
                                               GALGAS_objectAttributes & outArgument0) const {
  const cMapElement_objectKindMap * p = (const cMapElement_objectKindMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_objectKindMap) ;
    outArgument0 = p->mProperty_attributes ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @objectKindMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectKindMap ("objectKindMap",
                                      nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_objectKindMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectKindMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_objectKindMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectKindMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap GALGAS_objectKindMap::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_objectKindMap result ;
  const GALGAS_objectKindMap * p = (const GALGAS_objectKindMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_objectKindMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectKindMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_start_i0_ (C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_implementation var_imp_953 = GALGAS_implementation::constructor_new (GALGAS_implementationMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 39))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 39)) ;
  GALGAS_applicationDefinition var_application_1039 = function_emptyApplicationDefinition (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 40)) ;
  GALGAS_string var_fileIncludeList_1093 = GALGAS_string::makeEmptyString () ;
  GALGAS_lstring var_version_1176 ;
  GALGAS_lstring var_desc_1199 ;
  nt_OIL_5F_version_ (var_version_1176, var_desc_1199, inCompiler) ;
  {
  var_application_1039.setter_setVersion (var_version_1176 COMMA_SOURCE_FILE ("goil_syntax.galgas", 48)) ;
  }
  {
  var_application_1039.setter_setVersionDescription (var_desc_1199 COMMA_SOURCE_FILE ("goil_syntax.galgas", 49)) ;
  }
  GALGAS_string var_config_5F_file_5F_name_1336 = GALGAS_string (gOption_goil_5F_options_config.readProperty_value ()) ;
  GALGAS_stringlist var_configFiles_1447 = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name_1336.add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 56)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 56)) ;
  cEnumerator_stringlist enumerator_1657 (var_configFiles_1447, kENUMERATION_DOWN) ;
  while (enumerator_1657.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_1657.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 63)), var_imp_953, var_application_1039, var_fileIncludeList_1093, GALGAS_bool (false)  COMMA_SOURCE_FILE ("goil_syntax.galgas", 63)) ;
    enumerator_1657.gotoNextObject () ;
  }
  GALGAS_stringlist var_configVersionFiles_2033 = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name_1336.add_operation (var_version_1176.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 74)).add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 74)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 72)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, var_configVersionFiles_2033.getter_count (SOURCE_FILE ("goil_syntax.galgas", 76)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 77)), GALGAS_string ("OIL version ").add_operation (var_version_1176.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 77)).add_operation (GALGAS_string (" does not exist"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 77)), fixItArray1  COMMA_SOURCE_FILE ("goil_syntax.galgas", 77)) ;
    }
  }
  cEnumerator_stringlist enumerator_2262 (var_configVersionFiles_2033, kENUMERATION_DOWN) ;
  while (enumerator_2262.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_2262.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 81)), var_imp_953, var_application_1039, var_fileIncludeList_1093, GALGAS_bool (false)  COMMA_SOURCE_FILE ("goil_syntax.galgas", 81)) ;
    enumerator_2262.gotoNextObject () ;
  }
  nt_file_ (var_imp_953, var_application_1039, var_fileIncludeList_1093, GALGAS_bool (true), inCompiler) ;
  callExtensionMethod_checkObjectReferences ((cPtr_implementation *) var_imp_953.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 92)) ;
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("goil_syntax.galgas", 94)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      routine_setDefaults (var_imp_953, var_application_1039, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 95)) ;
      }
    }
  }
  enumGalgasBool test_3 = kBoolTrue ;
  if (kBoolTrue == test_3) {
    test_3 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("goil_syntax.galgas", 102)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_3) {
      {
      routine_verifyAll (var_imp_953, var_application_1039, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 103)) ;
      }
    }
  }
  enumGalgasBool test_4 = kBoolTrue ;
  if (kBoolTrue == test_4) {
    test_4 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("goil_syntax.galgas", 105)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_4) {
      GALGAS_gtlData var_templateData_2863 = callExtensionGetter_templateData ((const cPtr_applicationDefinition *) var_application_1039.ptr (), var_imp_953, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 106)) ;
      {
      routine_generate_5F_all (var_templateData_2863, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 109)) ;
      }
    }
  }
  var_fileIncludeList_1093 = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 112)).getter_lastPathComponent (SOURCE_FILE ("goil_syntax.galgas", 112)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 112)).add_operation (var_fileIncludeList_1093, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 112)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 112)) ;
  GALGAS_string var_oilDepFileName_3168 = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 113)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("goil_syntax.galgas", 113)).add_operation (GALGAS_string ("/build/"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 113)).add_operation (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 114)).getter_lastPathComponent (SOURCE_FILE ("goil_syntax.galgas", 114)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 114)).add_operation (GALGAS_string (".dep"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 114)) ;
  var_fileIncludeList_1093.method_writeToFile (var_oilDepFileName_3168, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 116)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_start_i0_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_OIL_5F_version_parse (inCompiler) ;
  nt_file_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_start_i0_indexing (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_OIL_5F_version_indexing (inCompiler) ;
  nt_file_indexing (inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_file_i1_ (GALGAS_implementation & ioArgument_imp,
                                                           GALGAS_applicationDefinition & ioArgument_application,
                                                           GALGAS_string & ioArgument_fileIncludeList,
                                                           const GALGAS_bool constinArgument_rootFile,
                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_rootFile.operator_not (SOURCE_FILE ("goil_syntax.galgas", 125)).boolEnum () ;
    if (kBoolTrue == test_0) {
      ioArgument_fileIncludeList.plusAssign_operation(GALGAS_string (" \\\n ").add_operation (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 126)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 126)), inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 126)) ;
    }
  }
  bool repeatFlag_1 = true ;
  while (repeatFlag_1) {
    switch (select_goil_5F_syntax_0 (inCompiler)) {
    case 2: {
      nt_include_5F_file_5F_level_ (ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, GALGAS_bool (false), inCompiler) ;
    } break ;
    case 3: {
      nt_implementation_5F_definition_ (ioArgument_imp, inCompiler) ;
    } break ;
    case 4: {
      nt_application_5F_definition_ (ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, GALGAS_bool (false), inCompiler) ;
    } break ;
    default:
      repeatFlag_1 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_file_i1_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_0 (inCompiler)) {
    case 2: {
      nt_include_5F_file_5F_level_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_implementation_5F_definition_parse (inCompiler) ;
    } break ;
    case 4: {
      nt_application_5F_definition_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_file_i1_indexing (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_0 (inCompiler)) {
    case 2: {
      nt_include_5F_file_5F_level_indexing (inCompiler) ;
    } break ;
    case 3: {
      nt_implementation_5F_definition_indexing (inCompiler) ;
    } break ;
    case 4: {
      nt_application_5F_definition_indexing (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_file_5F_without_5F_include_i2_ (GALGAS_implementation & ioArgument_imp,
                                                                                 GALGAS_applicationDefinition & ioArgument_application,
                                                                                 C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_string var_includeList_4002 = GALGAS_string::makeEmptyString () ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_1 (inCompiler)) {
    case 2: {
      nt_implementation_5F_definition_ (ioArgument_imp, inCompiler) ;
    } break ;
    case 3: {
      nt_application_5F_definition_ (ioArgument_imp, ioArgument_application, var_includeList_4002, GALGAS_bool (false), inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_file_5F_without_5F_include_i2_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_1 (inCompiler)) {
    case 2: {
      nt_implementation_5F_definition_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_application_5F_definition_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_file_5F_without_5F_include_i2_indexing (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_1 (inCompiler)) {
    case 2: {
      nt_implementation_5F_definition_indexing (inCompiler) ;
    } break ;
    case 3: {
      nt_application_5F_definition_indexing (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_sign_i3_ (GALGAS_bool & outArgument_signed,
                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_signed.drop () ; // Release 'out' argument
  switch (select_goil_5F_syntax_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__2D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 148)) ;
    outArgument_signed = GALGAS_bool (true) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__2B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 150)) ;
    outArgument_signed = GALGAS_bool (false) ;
  } break ;
  case 3: {
    outArgument_signed = GALGAS_bool (false) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_sign_i3_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__2D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 148)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__2B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 150)) ;
  } break ;
  case 3: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_sign_i3_indexing (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__2D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 148)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__2B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 150)) ;
  } break ;
  case 3: {
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_description_i4_ (GALGAS_lstring & outArgument_desc,
                                                                  C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_desc.drop () ; // Release 'out' argument
  switch (select_goil_5F_syntax_3 (inCompiler)) {
  case 1: {
    outArgument_desc = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 161)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3A_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 163)) ;
    GALGAS_lstring var_partialString_4416 ;
    var_partialString_4416 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 165)) ;
    GALGAS_string var_result_4470 = var_partialString_4416.readProperty_string () ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      if (select_goil_5F_syntax_4 (inCompiler) == 2) {
        var_partialString_4416 = inCompiler->synthetizedAttribute_a_5F_string () ;
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 169)) ;
        GALGAS_string var_toappend_4567 = var_partialString_4416.readProperty_string () ;
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = GALGAS_bool (kIsNotEqual, var_result_4470.getter_rightSubString (GALGAS_uint (uint32_t (2U)) COMMA_SOURCE_FILE ("goil_syntax.galgas", 171)).objectCompare (GALGAS_string ("\\n"))).boolEnum () ;
          if (kBoolTrue == test_1) {
            var_toappend_4567 = GALGAS_string (" ").add_operation (var_toappend_4567, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 172)) ;
          }
        }
        var_result_4470.plusAssign_operation(var_toappend_4567, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 174)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
    outArgument_desc = GALGAS_lstring::constructor_new (var_result_4470.getter_stringByReplacingStringByString (GALGAS_string ("\\n"), GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 176)), var_partialString_4416.readProperty_location ()  COMMA_SOURCE_FILE ("goil_syntax.galgas", 176)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_description_i4_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_3 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3A_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 163)) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 165)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      if (select_goil_5F_syntax_4 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 169)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_description_i4_indexing (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_3 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3A_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 163)) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 165)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      if (select_goil_5F_syntax_4 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 169)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_OIL_5F_version_i5_ (GALGAS_lstring & outArgument_version,
                                                                     GALGAS_lstring & outArgument_desc,
                                                                     C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_version.drop () ; // Release 'out' argument
  outArgument_desc.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION COMMA_SOURCE_FILE ("goil_syntax.galgas", 184)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 184)) ;
  outArgument_version = inCompiler->synthetizedAttribute_a_5F_string () ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 184)) ;
  nt_description_ (outArgument_desc, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 184)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_OIL_5F_version_i5_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION COMMA_SOURCE_FILE ("goil_syntax.galgas", 184)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 184)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 184)) ;
  nt_description_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 184)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_OIL_5F_version_i5_indexing (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION COMMA_SOURCE_FILE ("goil_syntax.galgas", 184)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 184)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 184)) ;
  nt_description_indexing (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 184)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_application_5F_definition_i6_ (const GALGAS_implementation constinArgument_imp,
                                                                                GALGAS_applicationDefinition & ioArgument_application,
                                                                                GALGAS_string & ioArgument_fileIncludeList,
                                                                                const GALGAS_bool constinArgument_rootFile,
                                                                                C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_CPU COMMA_SOURCE_FILE ("goil_syntax.galgas", 196)) ;
  GALGAS_lstring var_cpuName_5378 = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 196)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 196)) ;
  GALGAS_objectsMap var_objects_5406 = ioArgument_application.readProperty_objects () ;
  nt_object_5F_definition_5F_list_ (constinArgument_imp, var_objects_5406, ioArgument_fileIncludeList, constinArgument_rootFile, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 199)) ;
  GALGAS_lstring joker_5530 ; // Joker input parameter
  nt_description_ (joker_5530, inCompiler) ;
  joker_5530.drop () ; // Release temporary input variables (joker in source)
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 199)) ;
  {
  ioArgument_application.setter_setName (var_cpuName_5378 COMMA_SOURCE_FILE ("goil_syntax.galgas", 200)) ;
  }
  {
  ioArgument_application.setter_setObjects (var_objects_5406 COMMA_SOURCE_FILE ("goil_syntax.galgas", 201)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_application_5F_definition_i6_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_CPU COMMA_SOURCE_FILE ("goil_syntax.galgas", 196)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 196)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 196)) ;
  nt_object_5F_definition_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 199)) ;
  nt_description_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 199)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_application_5F_definition_i6_indexing (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_CPU COMMA_SOURCE_FILE ("goil_syntax.galgas", 196)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 196)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 196)) ;
  nt_object_5F_definition_5F_list_indexing (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 199)) ;
  nt_description_indexing (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 199)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_object_5F_definition_5F_list_i7_ (const GALGAS_implementation constinArgument_imp,
                                                                                   GALGAS_objectsMap & ioArgument_objects,
                                                                                   GALGAS_string & ioArgument_fileIncludeList,
                                                                                   const GALGAS_bool constinArgument_rootFile,
                                                                                   C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_5 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_objectKind_5789 = inCompiler->synthetizedAttribute_att_5F_token () ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 212)) ;
      GALGAS_implementationObject var_impObjOfKind_5830 = callExtensionGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), var_objectKind_5789.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 213)) ;
      GALGAS_objectKind var_objectsForKind_5901 = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 214))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 214)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = ioArgument_objects.getter_hasKey (var_objectKind_5789.readProperty_string () COMMA_SOURCE_FILE ("goil_syntax.galgas", 215)).boolEnum () ;
        if (kBoolTrue == test_1) {
          {
          ioArgument_objects.setter_del (var_objectKind_5789, var_objectsForKind_5901, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 216)) ;
          }
        }
      }
      GALGAS_lstring var_objectName_6096 = inCompiler->synthetizedAttribute_att_5F_token () ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 218)) ;
      GALGAS_objectAttributes var_object_6129 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 219)) ;
      GALGAS_objectKindMap var_objectsKind_6171 = var_objectsForKind_5901.readProperty_objects () ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, var_impObjOfKind_5830.readProperty_multiple ().readProperty_bool ().objectCompare (GALGAS_bool (false))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_objectName_6096 = var_objectKind_5789 ;
        }
      }
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = var_objectsKind_6171.getter_hasKey (var_objectName_6096.readProperty_string () COMMA_SOURCE_FILE ("goil_syntax.galgas", 227)).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          var_objectsKind_6171.setter_del (var_objectName_6096, var_object_6129, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 228)) ;
          }
        }
      }
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 230)) ;
      nt_oil_5F_declaration_5F_list_ (var_impObjOfKind_5830.readProperty_attributes (), var_object_6129, inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 232)) ;
      GALGAS_lstring var_oil_5F_desc_6733 ;
      nt_description_ (var_oil_5F_desc_6733, inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 234)) ;
      GALGAS_identifierMap var_attributes_6769 = var_object_6129.readProperty_objectParams () ;
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = var_attributes_6769.getter_hasKey (GALGAS_string ("NAME") COMMA_SOURCE_FILE ("goil_syntax.galgas", 236)).operator_not (SOURCE_FILE ("goil_syntax.galgas", 236)).boolEnum () ;
        if (kBoolTrue == test_4) {
          {
          var_attributes_6769.setter_put (GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), var_objectName_6096.readProperty_location ()  COMMA_SOURCE_FILE ("goil_syntax.galgas", 237)), GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_6733, var_objectName_6096.readProperty_location (), var_objectName_6096.readProperty_string ()  COMMA_SOURCE_FILE ("goil_syntax.galgas", 239)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 237)) ;
          }
          {
          var_object_6129.setter_setObjectParams (var_attributes_6769 COMMA_SOURCE_FILE ("goil_syntax.galgas", 242)) ;
          }
        }
      }
      {
      var_objectsKind_6171.setter_put (var_objectName_6096, var_object_6129, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 244)) ;
      }
      {
      var_objectsForKind_5901.setter_setObjects (var_objectsKind_6171 COMMA_SOURCE_FILE ("goil_syntax.galgas", 245)) ;
      }
      {
      ioArgument_objects.setter_put (var_objectKind_5789, var_objectsForKind_5901, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 246)) ;
      }
    } break ;
    case 3: {
      nt_include_5F_cpu_5F_level_ (constinArgument_imp, ioArgument_objects, ioArgument_fileIncludeList, constinArgument_rootFile, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_object_5F_definition_5F_list_i7_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_5 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 212)) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 218)) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 230)) ;
      nt_oil_5F_declaration_5F_list_parse (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 232)) ;
      nt_description_parse (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 234)) ;
    } break ;
    case 3: {
      nt_include_5F_cpu_5F_level_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_object_5F_definition_5F_list_i7_indexing (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_5 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 212)) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 218)) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 230)) ;
      nt_oil_5F_declaration_5F_list_indexing (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 232)) ;
      nt_description_indexing (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 234)) ;
    } break ;
    case 3: {
      nt_include_5F_cpu_5F_level_indexing (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_boolean_i8_ (GALGAS_lbool & outArgument_val,
                                                              C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_val.drop () ; // Release 'out' argument
  switch (select_goil_5F_syntax_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_TRUE COMMA_SOURCE_FILE ("goil_syntax.galgas", 256)) ;
    outArgument_val = GALGAS_lbool::constructor_new (GALGAS_bool (true), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 257))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 257)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_FALSE COMMA_SOURCE_FILE ("goil_syntax.galgas", 259)) ;
    outArgument_val = GALGAS_lbool::constructor_new (GALGAS_bool (false), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 260))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 260)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_boolean_i8_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_TRUE COMMA_SOURCE_FILE ("goil_syntax.galgas", 256)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_FALSE COMMA_SOURCE_FILE ("goil_syntax.galgas", 259)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_boolean_i8_indexing (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_TRUE COMMA_SOURCE_FILE ("goil_syntax.galgas", 256)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_FALSE COMMA_SOURCE_FILE ("goil_syntax.galgas", 259)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_oil_5F_declaration_5F_list_i9_ (const GALGAS_implementationObjectMap constinArgument_types,
                                                                                 GALGAS_objectAttributes & ioArgument_identifiers,
                                                                                 C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_7 (inCompiler)) {
    case 2: {
      nt_oil_5F_declaration_ (constinArgument_types, ioArgument_identifiers, inCompiler) ;
    } break ;
    case 3: {
      nt_include_5F_object_5F_level_ (constinArgument_types, ioArgument_identifiers, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_oil_5F_declaration_5F_list_i9_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_7 (inCompiler)) {
    case 2: {
      nt_oil_5F_declaration_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_include_5F_object_5F_level_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_oil_5F_declaration_5F_list_i9_indexing (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_7 (inCompiler)) {
    case 2: {
      nt_oil_5F_declaration_indexing (inCompiler) ;
    } break ;
    case 3: {
      nt_include_5F_object_5F_level_indexing (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_oil_5F_declaration_i10_ (const GALGAS_implementationObjectMap constinArgument_types,
                                                                          GALGAS_objectAttributes & ioArgument_identifiers,
                                                                          C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_lstring var_idf_8101 ;
  GALGAS_object_5F_t var_val_8117 ;
  var_idf_8101 = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 281)) ;
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("goil_syntax.galgas", 285)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 285))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 285)) ;
  GALGAS_impType var_type_8188 = GALGAS_impVoid::constructor_new (temp_0, GALGAS_dataType::constructor_void (SOURCE_FILE ("goil_syntax.galgas", 285)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 285)), GALGAS_bool (false), GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("goil_syntax.galgas", 285))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 285)) ;
  GALGAS_bool var_typeOk_8285 = GALGAS_bool (false) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = constinArgument_types.getter_hasKey (var_idf_8101.readProperty_string () COMMA_SOURCE_FILE ("goil_syntax.galgas", 287)).boolEnum () ;
    if (kBoolTrue == test_1) {
      constinArgument_types.method_get (var_idf_8101, var_type_8188, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 288)) ;
      var_typeOk_8285 = GALGAS_bool (true) ;
    }
  }
  if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (var_idf_8101.readProperty_location (), var_idf_8101.readProperty_string ().add_operation (GALGAS_string (" is not declared in the IMPLEMENTATION"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 291)), fixItArray2  COMMA_SOURCE_FILE ("goil_syntax.galgas", 291)) ;
  }
  switch (select_goil_5F_syntax_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 294)) ;
    switch (select_goil_5F_syntax_9 (inCompiler)) {
    case 1: {
      GALGAS_lstring var_value_8574 ;
      var_value_8574 = inCompiler->synthetizedAttribute_att_5F_token () ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 298)) ;
      GALGAS_implementationObjectMap var_subTypes_8609 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 299)) ;
      GALGAS_objectAttributes var_subAttributes_8681 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 300)) ;
      switch (var_type_8188.readProperty_type ().enumValue ()) {
      case GALGAS_dataType::kNotBuilt:
        break ;
      case GALGAS_dataType::kEnum_enumeration:
        {
          if (var_type_8188.isValid ()) {
            if (var_type_8188.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
              GALGAS_impEnumType cast_8811_enumType ((cPtr_impEnumType *) var_type_8188.ptr ()) ;
              enumGalgasBool test_3 = kBoolTrue ;
              if (kBoolTrue == test_3) {
                test_3 = cast_8811_enumType.readProperty_valuesMap ().getter_hasKey (var_value_8574.readProperty_string () COMMA_SOURCE_FILE ("goil_syntax.galgas", 305)).boolEnum () ;
                if (kBoolTrue == test_3) {
                  cast_8811_enumType.readProperty_valuesMap ().method_get (var_value_8574, var_subTypes_8609, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 306)) ;
                }
              }
              if (kBoolFalse == test_3) {
                TC_Array <C_FixItDescription> fixItArray4 ;
                inCompiler->emitSemanticError (var_value_8574.readProperty_location (), var_value_8574.readProperty_string ().add_operation (GALGAS_string (" ENUM value undeclared. One of the following values are expected: "), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 308)).add_operation (function_valueList (cast_8811_enumType.readProperty_valuesMap (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 308)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 308)), fixItArray4  COMMA_SOURCE_FILE ("goil_syntax.galgas", 308)) ;
              }
            }
          }
        }
        break ;
      case GALGAS_dataType::kEnum_identifier:
        {
        }
        break ;
      case GALGAS_dataType::kEnum_objectType:
        {
        }
        break ;
      case GALGAS_dataType::kEnum_void:
      case GALGAS_dataType::kEnum_uint_33__32_Number:
      case GALGAS_dataType::kEnum_sint_33__32_Number:
      case GALGAS_dataType::kEnum_uint_36__34_Number:
      case GALGAS_dataType::kEnum_sint_36__34_Number:
      case GALGAS_dataType::kEnum_floatNumber:
      case GALGAS_dataType::kEnum_string:
      case GALGAS_dataType::kEnum_structType:
      case GALGAS_dataType::kEnum_boolean:
        {
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (var_idf_8101.readProperty_location (), var_idf_8101.readProperty_string ().add_operation (GALGAS_string (" is not an ENUM nor and IDENTIFIER nor an object reference"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 314)), fixItArray5  COMMA_SOURCE_FILE ("goil_syntax.galgas", 314)) ;
        }
        break ;
      }
      switch (select_goil_5F_syntax_10 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 317)) ;
        nt_oil_5F_declaration_5F_list_ (var_subTypes_8609, var_subAttributes_8681, inCompiler) ;
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 319)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      GALGAS_lstring var_oil_5F_desc_9535 ;
      nt_description_ (var_oil_5F_desc_9535, inCompiler) ;
      enumGalgasBool test_6 = kBoolTrue ;
      if (kBoolTrue == test_6) {
        test_6 = GALGAS_bool (kIsEqual, var_type_8188.readProperty_type ().objectCompare (GALGAS_dataType::constructor_enumeration (SOURCE_FILE ("goil_syntax.galgas", 322)))).boolEnum () ;
        if (kBoolTrue == test_6) {
          var_val_8117 = GALGAS_enumAttribute::constructor_new (var_oil_5F_desc_9535, var_value_8574.readProperty_location (), var_value_8574.readProperty_string (), var_subAttributes_8681  COMMA_SOURCE_FILE ("goil_syntax.galgas", 323)) ;
        }
      }
      if (kBoolFalse == test_6) {
        enumGalgasBool test_7 = kBoolTrue ;
        if (kBoolTrue == test_7) {
          test_7 = GALGAS_bool (kIsEqual, var_type_8188.readProperty_type ().objectCompare (GALGAS_dataType::constructor_objectType (SOURCE_FILE ("goil_syntax.galgas", 324)))).boolEnum () ;
          if (kBoolTrue == test_7) {
            var_val_8117 = GALGAS_objectRefAttribute::constructor_new (var_oil_5F_desc_9535, var_value_8574.readProperty_location (), var_value_8574  COMMA_SOURCE_FILE ("goil_syntax.galgas", 325)) ;
          }
        }
        if (kBoolFalse == test_7) {
          var_val_8117 = GALGAS_string_5F_class::constructor_new (var_oil_5F_desc_9535, var_value_8574.readProperty_location (), var_value_8574.readProperty_string ()  COMMA_SOURCE_FILE ("goil_syntax.galgas", 327)) ;
        }
      }
    } break ;
    case 2: {
      GALGAS_bool var_sign_9971 ;
      nt_sign_ (var_sign_9971, inCompiler) ;
      switch (select_goil_5F_syntax_11 (inCompiler)) {
      case 1: {
        GALGAS_luint_36__34_ var_value_10052 ;
        var_value_10052 = inCompiler->synthetizedAttribute_integerNumber () ;
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_uint_5F_number COMMA_SOURCE_FILE ("goil_syntax.galgas", 336)) ;
        GALGAS_lstring var_oil_5F_desc_10123 ;
        nt_description_ (var_oil_5F_desc_10123, inCompiler) ;
        var_val_8117 = function_checkAndGetIntegerNumber (var_oil_5F_desc_10123, var_type_8188.readProperty_type (), var_value_10052, var_sign_9971, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 338)) ;
        if (var_type_8188.isValid ()) {
          if (var_type_8188.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impRangedType) {
            GALGAS_impRangedType cast_10257_rangedType ((cPtr_impRangedType *) var_type_8188.ptr ()) ;
            enumGalgasBool test_8 = kBoolTrue ;
            if (kBoolTrue == test_8) {
              test_8 = callExtensionGetter_contains ((const cPtr_attributeRange *) cast_10257_rangedType.readProperty_setOrRange ().ptr (), var_val_8117, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 341)).operator_not (SOURCE_FILE ("goil_syntax.galgas", 341)).boolEnum () ;
              if (kBoolTrue == test_8) {
                TC_Array <C_FixItDescription> fixItArray9 ;
                inCompiler->emitSemanticError (var_value_10052.readProperty_location (), GALGAS_string ("Integer out or range. Allowed values are: ").add_operation (callExtensionGetter_string ((const cPtr_attributeRange *) cast_10257_rangedType.readProperty_setOrRange ().ptr (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 342)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 342)), fixItArray9  COMMA_SOURCE_FILE ("goil_syntax.galgas", 342)) ;
              }
            }
          }
        }
      } break ;
      case 2: {
        GALGAS_ldouble var_value_10521 ;
        var_value_10521 = inCompiler->synthetizedAttribute_floatNumber () ;
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_float_5F_number COMMA_SOURCE_FILE ("goil_syntax.galgas", 348)) ;
        GALGAS_lstring var_oil_5F_desc_10593 ;
        nt_description_ (var_oil_5F_desc_10593, inCompiler) ;
        var_val_8117 = function_checkAndGetFloatNumber (var_oil_5F_desc_10593, var_type_8188.readProperty_type (), var_value_10521, var_sign_9971, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 350)) ;
        if (var_type_8188.isValid ()) {
          if (var_type_8188.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impRangedType) {
            GALGAS_impRangedType cast_10725_rangedType ((cPtr_impRangedType *) var_type_8188.ptr ()) ;
            enumGalgasBool test_10 = kBoolTrue ;
            if (kBoolTrue == test_10) {
              test_10 = callExtensionGetter_contains ((const cPtr_attributeRange *) cast_10725_rangedType.readProperty_setOrRange ().ptr (), var_val_8117, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 353)).operator_not (SOURCE_FILE ("goil_syntax.galgas", 353)).boolEnum () ;
              if (kBoolTrue == test_10) {
                TC_Array <C_FixItDescription> fixItArray11 ;
                inCompiler->emitSemanticError (var_value_10521.readProperty_location (), GALGAS_string ("Float out or range. Allowed values are: ").add_operation (callExtensionGetter_string ((const cPtr_attributeRange *) cast_10725_rangedType.readProperty_setOrRange ().ptr (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 354)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 354)), fixItArray11  COMMA_SOURCE_FILE ("goil_syntax.galgas", 354)) ;
              }
            }
          }
        }
      } break ;
      default:
        break ;
      }
    } break ;
    case 3: {
      GALGAS_lbool var_value_10988 ;
      nt_boolean_ (var_value_10988, inCompiler) ;
      GALGAS_implementationObjectMap var_subTypes_11027 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 362)) ;
      GALGAS_objectAttributes var_subAttributes_11097 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 363)) ;
      enumGalgasBool test_12 = kBoolTrue ;
      if (kBoolTrue == test_12) {
        test_12 = GALGAS_bool (kIsNotEqual, var_type_8188.readProperty_type ().objectCompare (GALGAS_dataType::constructor_boolean (SOURCE_FILE ("goil_syntax.galgas", 364)))).boolEnum () ;
        if (kBoolTrue == test_12) {
          TC_Array <C_FixItDescription> fixItArray13 ;
          inCompiler->emitSemanticError (var_idf_8101.readProperty_location (), extensionGetter_oilType (var_type_8188.readProperty_type (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 365)).add_operation (GALGAS_string (" expected, got a BOOLEAN"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 365)), fixItArray13  COMMA_SOURCE_FILE ("goil_syntax.galgas", 365)) ;
        }
      }
      if (kBoolFalse == test_12) {
        if (var_type_8188.isValid ()) {
          if (var_type_8188.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impBoolType) {
            GALGAS_impBoolType cast_11305_boolType ((cPtr_impBoolType *) var_type_8188.ptr ()) ;
            enumGalgasBool test_14 = kBoolTrue ;
            if (kBoolTrue == test_14) {
              test_14 = var_value_10988.readProperty_bool ().boolEnum () ;
              if (kBoolTrue == test_14) {
                var_subTypes_11027 = cast_11305_boolType.readProperty_trueSubAttributes () ;
              }
            }
            if (kBoolFalse == test_14) {
              var_subTypes_11027 = cast_11305_boolType.readProperty_falseSubAttributes () ;
            }
          }
        }
      }
      switch (select_goil_5F_syntax_12 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 377)) ;
        enumGalgasBool test_15 = kBoolTrue ;
        if (kBoolTrue == test_15) {
          test_15 = GALGAS_bool (kIsEqual, var_subTypes_11027.getter_count (SOURCE_FILE ("goil_syntax.galgas", 378)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
          if (kBoolTrue == test_15) {
            TC_Array <C_FixItDescription> fixItArray16 ;
            inCompiler->emitSemanticError (var_value_10988.readProperty_location (), function_stringLBool (var_value_10988, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 379)).add_operation (GALGAS_string (" value of "), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 379)).add_operation (var_idf_8101.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 379)).add_operation (GALGAS_string (" has no sub-attribute"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 379)), fixItArray16  COMMA_SOURCE_FILE ("goil_syntax.galgas", 379)) ;
          }
        }
        nt_oil_5F_declaration_5F_list_ (var_subTypes_11027, var_subAttributes_11097, inCompiler) ;
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 382)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      GALGAS_lstring var_oil_5F_desc_11803 ;
      nt_description_ (var_oil_5F_desc_11803, inCompiler) ;
      var_val_8117 = GALGAS_boolAttribute::constructor_new (var_oil_5F_desc_11803, var_idf_8101.readProperty_location (), var_value_10988.readProperty_bool (), var_subAttributes_11097  COMMA_SOURCE_FILE ("goil_syntax.galgas", 385)) ;
    } break ;
    case 4: {
      GALGAS_lstring var_literalString_11951 ;
      var_literalString_11951 = inCompiler->synthetizedAttribute_a_5F_string () ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 389)) ;
      GALGAS_lstring var_oil_5F_desc_12029 ;
      nt_description_ (var_oil_5F_desc_12029, inCompiler) ;
      var_val_8117 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_12029, var_literalString_11951.readProperty_location (), var_literalString_11951.readProperty_string ()  COMMA_SOURCE_FILE ("goil_syntax.galgas", 391)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_AUTO COMMA_SOURCE_FILE ("goil_syntax.galgas", 394)) ;
      GALGAS_lstring var_oil_5F_desc_12202 ;
      nt_description_ (var_oil_5F_desc_12202, inCompiler) ;
      enumGalgasBool test_17 = kBoolTrue ;
      if (kBoolTrue == test_17) {
        test_17 = callExtensionGetter_autoAllowed ((const cPtr_impType *) var_type_8188.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 397)).boolEnum () ;
        if (kBoolTrue == test_17) {
          var_val_8117 = GALGAS_auto::constructor_new (var_oil_5F_desc_12202, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 398))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 398)) ;
        }
      }
      if (kBoolFalse == test_17) {
        TC_Array <C_FixItDescription> fixItArray18 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 413)), GALGAS_string ("AUTO is not allowed"), fixItArray18  COMMA_SOURCE_FILE ("goil_syntax.galgas", 413)) ;
        var_val_8117.drop () ; // Release error dropped variable
      }
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    GALGAS_lstring var_name_13037 = inCompiler->synthetizedAttribute_att_5F_token () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 417)) ;
    GALGAS_implementationObjectMap var_subTypes_13050 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 418)) ;
    GALGAS_objectAttributes var_subAttributes_13118 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 419)) ;
    enumGalgasBool test_19 = kBoolTrue ;
    if (kBoolTrue == test_19) {
      test_19 = GALGAS_bool (kIsNotEqual, var_type_8188.readProperty_type ().objectCompare (GALGAS_dataType::constructor_structType (SOURCE_FILE ("goil_syntax.galgas", 421)))).boolEnum () ;
      if (kBoolTrue == test_19) {
        TC_Array <C_FixItDescription> fixItArray20 ;
        inCompiler->emitSemanticError (var_idf_8101.readProperty_location (), extensionGetter_oilType (var_type_8188.readProperty_type (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 422)).add_operation (GALGAS_string (" expected, got a STRUCT"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 422)), fixItArray20  COMMA_SOURCE_FILE ("goil_syntax.galgas", 422)) ;
      }
    }
    if (kBoolFalse == test_19) {
      if (var_type_8188.isValid ()) {
        if (var_type_8188.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impStructType) {
          GALGAS_impStructType cast_13333_structType ((cPtr_impStructType *) var_type_8188.ptr ()) ;
          var_subTypes_13050 = cast_13333_structType.readProperty_structAttributes () ;
        }
      }
    }
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 429)) ;
    nt_oil_5F_declaration_5F_list_ (var_subTypes_13050, var_subAttributes_13118, inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 431)) ;
    GALGAS_lstring var_oil_5F_desc_13527 ;
    nt_description_ (var_oil_5F_desc_13527, inCompiler) ;
    var_val_8117 = GALGAS_structAttribute::constructor_new (var_oil_5F_desc_13527, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 433)), var_name_13037, var_subAttributes_13118  COMMA_SOURCE_FILE ("goil_syntax.galgas", 433)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 435)) ;
  GALGAS_identifierMap var_idfs_13675 = ioArgument_identifiers.readProperty_objectParams () ;
  enumGalgasBool test_21 = kBoolTrue ;
  if (kBoolTrue == test_21) {
    test_21 = var_type_8188.readProperty_multiple ().boolEnum () ;
    if (kBoolTrue == test_21) {
      enumGalgasBool test_22 = kBoolTrue ;
      if (kBoolTrue == test_22) {
        test_22 = var_idfs_13675.getter_hasKey (var_idf_8101.readProperty_string () COMMA_SOURCE_FILE ("goil_syntax.galgas", 440)).boolEnum () ;
        if (kBoolTrue == test_22) {
          GALGAS_object_5F_t var_attributeList_13794 ;
          {
          var_idfs_13675.setter_del (var_idf_8101, var_attributeList_13794, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 444)) ;
          }
          if (var_attributeList_13794.isValid ()) {
            if (var_attributeList_13794.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
              GALGAS_multipleAttribute cast_13987_multiAttribute ((cPtr_multipleAttribute *) var_attributeList_13794.ptr ()) ;
              GALGAS_identifierList var_aList_14028 = cast_13987_multiAttribute.readProperty_items () ;
              var_aList_14028.addAssign_operation (var_val_8117  COMMA_SOURCE_FILE ("goil_syntax.galgas", 448)) ;
              var_val_8117 = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 449)), cast_13987_multiAttribute.readProperty_location (), var_aList_14028  COMMA_SOURCE_FILE ("goil_syntax.galgas", 449)) ;
            }
          }
        }
      }
      if (kBoolFalse == test_22) {
        GALGAS_identifierList var_aList_14218 = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("goil_syntax.galgas", 452)) ;
        GALGAS_object_5F_t var_defaultValue_14294 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) var_type_8188.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 454)) ;
        if (var_defaultValue_14294.isValid ()) {
          if (var_defaultValue_14294.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
            GALGAS_multipleAttribute cast_14421_multiAttribute ((cPtr_multipleAttribute *) var_defaultValue_14294.ptr ()) ;
            var_aList_14218 = cast_14421_multiAttribute.readProperty_items () ;
          }
        }
        var_aList_14218.addAssign_operation (var_val_8117  COMMA_SOURCE_FILE ("goil_syntax.galgas", 464)) ;
        var_val_8117 = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 466)), var_val_8117.readProperty_location (), var_aList_14218  COMMA_SOURCE_FILE ("goil_syntax.galgas", 466)) ;
      }
    }
  }
  if (kBoolFalse == test_21) {
    enumGalgasBool test_23 = kBoolTrue ;
    if (kBoolTrue == test_23) {
      test_23 = var_idfs_13675.getter_hasKey (var_idf_8101.readProperty_string () COMMA_SOURCE_FILE ("goil_syntax.galgas", 469)).boolEnum () ;
      if (kBoolTrue == test_23) {
        GALGAS_object_5F_t var_existingObject_14901 ;
        {
        var_idfs_13675.setter_del (var_idf_8101, var_existingObject_14901, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 473)) ;
        }
        {
        var_val_8117.insulate (HERE) ;
        cPtr_object_5F_t * ptr_14965 = (cPtr_object_5F_t *) var_val_8117.ptr () ;
        callExtensionSetter_mergeSubAttributes ((cPtr_object_5F_t *) ptr_14965, var_existingObject_14901, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 474)) ;
        }
      }
    }
  }
  enumGalgasBool test_24 = kBoolTrue ;
  if (kBoolTrue == test_24) {
    test_24 = var_typeOk_8285.boolEnum () ;
    if (kBoolTrue == test_24) {
      {
      var_idfs_13675.setter_put (var_idf_8101, var_val_8117, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 478)) ;
      }
    }
  }
  {
  ioArgument_identifiers.setter_setObjectParams (var_idfs_13675 COMMA_SOURCE_FILE ("goil_syntax.galgas", 480)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_oil_5F_declaration_i10_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 281)) ;
  switch (select_goil_5F_syntax_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 294)) ;
    switch (select_goil_5F_syntax_9 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 298)) ;
      switch (select_goil_5F_syntax_10 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 317)) ;
        nt_oil_5F_declaration_5F_list_parse (inCompiler) ;
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 319)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      nt_description_parse (inCompiler) ;
    } break ;
    case 2: {
      nt_sign_parse (inCompiler) ;
      switch (select_goil_5F_syntax_11 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_uint_5F_number COMMA_SOURCE_FILE ("goil_syntax.galgas", 336)) ;
        nt_description_parse (inCompiler) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_float_5F_number COMMA_SOURCE_FILE ("goil_syntax.galgas", 348)) ;
        nt_description_parse (inCompiler) ;
      } break ;
      default:
        break ;
      }
    } break ;
    case 3: {
      nt_boolean_parse (inCompiler) ;
      switch (select_goil_5F_syntax_12 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 377)) ;
        nt_oil_5F_declaration_5F_list_parse (inCompiler) ;
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 382)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      nt_description_parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 389)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_AUTO COMMA_SOURCE_FILE ("goil_syntax.galgas", 394)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 417)) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 429)) ;
    nt_oil_5F_declaration_5F_list_parse (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 431)) ;
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 435)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_oil_5F_declaration_i10_indexing (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 281)) ;
  switch (select_goil_5F_syntax_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 294)) ;
    switch (select_goil_5F_syntax_9 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 298)) ;
      switch (select_goil_5F_syntax_10 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 317)) ;
        nt_oil_5F_declaration_5F_list_indexing (inCompiler) ;
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 319)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      nt_description_indexing (inCompiler) ;
    } break ;
    case 2: {
      nt_sign_indexing (inCompiler) ;
      switch (select_goil_5F_syntax_11 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_uint_5F_number COMMA_SOURCE_FILE ("goil_syntax.galgas", 336)) ;
        nt_description_indexing (inCompiler) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_float_5F_number COMMA_SOURCE_FILE ("goil_syntax.galgas", 348)) ;
        nt_description_indexing (inCompiler) ;
      } break ;
      default:
        break ;
      }
    } break ;
    case 3: {
      nt_boolean_indexing (inCompiler) ;
      switch (select_goil_5F_syntax_12 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 377)) ;
        nt_oil_5F_declaration_5F_list_indexing (inCompiler) ;
        inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 382)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      nt_description_indexing (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 389)) ;
      nt_description_indexing (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_AUTO COMMA_SOURCE_FILE ("goil_syntax.galgas", 394)) ;
      nt_description_indexing (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("goil_syntax.galgas", 417)) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 429)) ;
    nt_oil_5F_declaration_5F_list_indexing (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 431)) ;
    nt_description_indexing (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("goil_syntax.galgas", 435)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_file_5F_level_i11_ (GALGAS_implementation & ioArgument_imp,
                                                                                GALGAS_applicationDefinition & ioArgument_application,
                                                                                GALGAS_string & ioArgument_fileIncludeList,
                                                                                const GALGAS_bool constinArgument_rootFile,
                                                                                C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_bool var_includeIfExists_15268 = GALGAS_bool (false) ;
  switch (select_goil_5F_syntax_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_include COMMA_SOURCE_FILE ("goil_syntax.galgas", 491)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_includeifexists COMMA_SOURCE_FILE ("goil_syntax.galgas", 493)) ;
    var_includeIfExists_15268 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  GALGAS_lstring var_file_5F_name_15384 ;
  switch (select_goil_5F_syntax_14 (inCompiler)) {
  case 1: {
    var_file_5F_name_15384 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_g_5F_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 497)) ;
    {
    routine_file_5F_in_5F_path (var_file_5F_name_15384, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 498)) ;
    }
  } break ;
  case 2: {
    var_file_5F_name_15384 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 500)) ;
  } break ;
  default:
    break ;
  }
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    GALGAS_bool test_1 = var_includeIfExists_15268.operator_not (SOURCE_FILE ("goil_syntax.galgas", 502)) ;
    if (kBoolTrue != test_1.boolEnum ()) {
      GALGAS_bool test_2 = var_includeIfExists_15268 ;
      if (kBoolTrue == test_2.boolEnum ()) {
        test_2 = var_file_5F_name_15384.readProperty_string ().getter_fileExists (SOURCE_FILE ("goil_syntax.galgas", 502)) ;
      }
      test_1 = test_2 ;
    }
    test_0 = test_1.boolEnum () ;
    if (kBoolTrue == test_0) {
      cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, var_file_5F_name_15384, ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, constinArgument_rootFile  COMMA_SOURCE_FILE ("goil_syntax.galgas", 503)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_file_5F_level_i11_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_include COMMA_SOURCE_FILE ("goil_syntax.galgas", 491)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_includeifexists COMMA_SOURCE_FILE ("goil_syntax.galgas", 493)) ;
  } break ;
  default:
    break ;
  }
  switch (select_goil_5F_syntax_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_g_5F_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 497)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 500)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_file_5F_level_i11_indexing (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_include COMMA_SOURCE_FILE ("goil_syntax.galgas", 491)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_includeifexists COMMA_SOURCE_FILE ("goil_syntax.galgas", 493)) ;
  } break ;
  default:
    break ;
  }
  switch (select_goil_5F_syntax_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_g_5F_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 497)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 500)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_cpu_5F_level_i12_ (const GALGAS_implementation constinArgument_imp,
                                                                               GALGAS_objectsMap & ioArgument_objects,
                                                                               GALGAS_string & ioArgument_fileIncludeList,
                                                                               const GALGAS_bool constinArgument_rootFile,
                                                                               C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_bool var_includeIfExists_15817 = GALGAS_bool (false) ;
  switch (select_goil_5F_syntax_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_include COMMA_SOURCE_FILE ("goil_syntax.galgas", 515)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_includeifexists COMMA_SOURCE_FILE ("goil_syntax.galgas", 517)) ;
    var_includeIfExists_15817 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  GALGAS_lstring var_file_5F_name_15933 ;
  switch (select_goil_5F_syntax_16 (inCompiler)) {
  case 1: {
    var_file_5F_name_15933 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_g_5F_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 521)) ;
    {
    routine_file_5F_in_5F_path (var_file_5F_name_15933, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 522)) ;
    }
  } break ;
  case 2: {
    var_file_5F_name_15933 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 524)) ;
  } break ;
  default:
    break ;
  }
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    GALGAS_bool test_1 = var_includeIfExists_15817.operator_not (SOURCE_FILE ("goil_syntax.galgas", 526)) ;
    if (kBoolTrue != test_1.boolEnum ()) {
      GALGAS_bool test_2 = var_includeIfExists_15817 ;
      if (kBoolTrue == test_2.boolEnum ()) {
        test_2 = var_file_5F_name_15933.readProperty_string ().getter_fileExists (SOURCE_FILE ("goil_syntax.galgas", 526)) ;
      }
      test_1 = test_2 ;
    }
    test_0 = test_1.boolEnum () ;
    if (kBoolTrue == test_0) {
      cGrammar_goil_5F_cpu_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, var_file_5F_name_15933, constinArgument_imp, ioArgument_objects, ioArgument_fileIncludeList, constinArgument_rootFile  COMMA_SOURCE_FILE ("goil_syntax.galgas", 527)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_cpu_5F_level_i12_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_include COMMA_SOURCE_FILE ("goil_syntax.galgas", 515)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_includeifexists COMMA_SOURCE_FILE ("goil_syntax.galgas", 517)) ;
  } break ;
  default:
    break ;
  }
  switch (select_goil_5F_syntax_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_g_5F_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 521)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 524)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_cpu_5F_level_i12_indexing (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_include COMMA_SOURCE_FILE ("goil_syntax.galgas", 515)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_includeifexists COMMA_SOURCE_FILE ("goil_syntax.galgas", 517)) ;
  } break ;
  default:
    break ;
  }
  switch (select_goil_5F_syntax_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_g_5F_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 521)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 524)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_object_5F_level_i13_ (const GALGAS_implementationObjectMap constinArgument_types,
                                                                                  GALGAS_objectAttributes & ioArgument_identifiers,
                                                                                  C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_bool var_includeIfExists_16334 = GALGAS_bool (false) ;
  switch (select_goil_5F_syntax_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_include COMMA_SOURCE_FILE ("goil_syntax.galgas", 537)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_includeifexists COMMA_SOURCE_FILE ("goil_syntax.galgas", 539)) ;
    var_includeIfExists_16334 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  GALGAS_lstring var_file_5F_name_16450 ;
  switch (select_goil_5F_syntax_18 (inCompiler)) {
  case 1: {
    var_file_5F_name_16450 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_g_5F_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 543)) ;
    {
    routine_file_5F_in_5F_path (var_file_5F_name_16450, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 544)) ;
    }
  } break ;
  case 2: {
    var_file_5F_name_16450 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 546)) ;
  } break ;
  default:
    break ;
  }
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    GALGAS_bool test_1 = var_includeIfExists_16334.operator_not (SOURCE_FILE ("goil_syntax.galgas", 548)) ;
    if (kBoolTrue != test_1.boolEnum ()) {
      GALGAS_bool test_2 = var_includeIfExists_16334 ;
      if (kBoolTrue == test_2.boolEnum ()) {
        test_2 = var_file_5F_name_16450.readProperty_string ().getter_fileExists (SOURCE_FILE ("goil_syntax.galgas", 548)) ;
      }
      test_1 = test_2 ;
    }
    test_0 = test_1.boolEnum () ;
    if (kBoolTrue == test_0) {
      cGrammar_goil_5F_object_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, var_file_5F_name_16450, constinArgument_types, ioArgument_identifiers  COMMA_SOURCE_FILE ("goil_syntax.galgas", 549)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_object_5F_level_i13_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_include COMMA_SOURCE_FILE ("goil_syntax.galgas", 537)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_includeifexists COMMA_SOURCE_FILE ("goil_syntax.galgas", 539)) ;
  } break ;
  default:
    break ;
  }
  switch (select_goil_5F_syntax_18 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_g_5F_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 543)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 546)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_object_5F_level_i13_indexing (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_include COMMA_SOURCE_FILE ("goil_syntax.galgas", 537)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_includeifexists COMMA_SOURCE_FILE ("goil_syntax.galgas", 539)) ;
  } break ;
  default:
    break ;
  }
  switch (select_goil_5F_syntax_18 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_g_5F_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 543)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("goil_syntax.galgas", 546)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int32_t gProductions_goil_object_level_include [] = {
// At index 0 : <start>, in file 'goil_syntax.ggs', line 38
  NONTERMINAL (6) // <OIL_version>
, NONTERMINAL (2) // <file>
, END_PRODUCTION
// At index 3 : <file>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (15) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 5 : <file_without_include>, in file 'goil_syntax.ggs', line 135
, NONTERMINAL (16) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 7 : <sign>, in file 'goil_syntax.ggs', line 146
, NONTERMINAL (17) // <select_goil_5F_syntax_2>
, END_PRODUCTION
// At index 9 : <description>, in file 'goil_syntax.ggs', line 159
, NONTERMINAL (18) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 11 : <OIL_version>, in file 'goil_syntax.ggs', line 183
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) // $OIL_VERSION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (5) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 17 : <application_definition>, in file 'goil_syntax.ggs', line 190
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) // $CPU$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (8) // <object_definition_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (5) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 25 : <object_definition_list>, in file 'goil_syntax.ggs', line 204
, NONTERMINAL (20) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 27 : <boolean>, in file 'goil_syntax.ggs', line 254
, NONTERMINAL (21) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 29 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 264
, NONTERMINAL (22) // <select_goil_5F_syntax_7>
, END_PRODUCTION
// At index 31 : <oil_declaration>, in file 'goil_syntax.ggs', line 276
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (23) // <select_goil_5F_syntax_8>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 35 : <include_file_level>, in file 'goil_syntax.ggs', line 483
, NONTERMINAL (28) // <select_goil_5F_syntax_13>
, NONTERMINAL (29) // <select_goil_5F_syntax_14>
, END_PRODUCTION
// At index 38 : <include_cpu_level>, in file 'goil_syntax.ggs', line 507
, NONTERMINAL (30) // <select_goil_5F_syntax_15>
, NONTERMINAL (31) // <select_goil_5F_syntax_16>
, END_PRODUCTION
// At index 41 : <include_object_level>, in file 'goil_syntax.ggs', line 531
, NONTERMINAL (32) // <select_goil_5F_syntax_17>
, NONTERMINAL (33) // <select_goil_5F_syntax_18>
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 44 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
, END_PRODUCTION
// At index 45 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
, NONTERMINAL (12) // <include_file_level>
, NONTERMINAL (15) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 48 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (15) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 51 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
, NONTERMINAL (7) // <application_definition>
, NONTERMINAL (15) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 54 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
, END_PRODUCTION
// At index 55 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (16) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 58 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
, NONTERMINAL (7) // <application_definition>
, NONTERMINAL (16) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 61 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) // $-$
, END_PRODUCTION
// At index 63 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) // $+$
, END_PRODUCTION
// At index 65 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
, END_PRODUCTION
// At index 66 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 160
, END_PRODUCTION
// At index 67 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 160
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) // $:$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (19) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 71 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 167
, END_PRODUCTION
// At index 72 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 167
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (19) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 75 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
, END_PRODUCTION
// At index 76 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (10) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (5) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (20) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 85 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
, NONTERMINAL (13) // <include_cpu_level>
, NONTERMINAL (20) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 88 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 255
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 90 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 255
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 92 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
, END_PRODUCTION
// At index 93 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
, NONTERMINAL (11) // <oil_declaration>
, NONTERMINAL (22) // <select_goil_5F_syntax_7>
, END_PRODUCTION
// At index 96 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
, NONTERMINAL (14) // <include_object_level>
, NONTERMINAL (22) // <select_goil_5F_syntax_7>
, END_PRODUCTION
// At index 99 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 293
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (24) // <select_goil_5F_syntax_9>
, END_PRODUCTION
// At index 102 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 293
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (10) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 108 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (25) // <select_goil_5F_syntax_10>
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 112 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
, NONTERMINAL (4) // <sign>
, NONTERMINAL (26) // <select_goil_5F_syntax_11>
, END_PRODUCTION
// At index 115 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
, NONTERMINAL (9) // <boolean>
, NONTERMINAL (27) // <select_goil_5F_syntax_12>
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 119 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 122 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 125 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 316
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (10) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 129 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 316
, END_PRODUCTION
// At index 130 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 333
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 133 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 333
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 136 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 376
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (10) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 140 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 376
, END_PRODUCTION
// At index 141 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 490
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 143 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 490
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 145 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 496
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 147 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 496
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 149 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 514
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 151 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 514
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 153 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 520
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 155 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 520
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 157 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 536
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 159 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 536
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 161 : <select_goil_5F_syntax_18>, in file 'goil_syntax.ggs', line 542
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 163 : <select_goil_5F_syntax_18>, in file 'goil_syntax.ggs', line 542
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 165 : <>, in file '.ggs', line 0
, NONTERMINAL (10) // <oil_declaration_list>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_goil_object_level_include [62] = {
 {"<start>", "goil_syntax", 0}, // at index 0
 {"<file>", "goil_syntax", 3}, // at index 1
 {"<file_without_include>", "goil_syntax", 5}, // at index 2
 {"<sign>", "goil_syntax", 7}, // at index 3
 {"<description>", "goil_syntax", 9}, // at index 4
 {"<OIL_version>", "goil_syntax", 11}, // at index 5
 {"<application_definition>", "goil_syntax", 17}, // at index 6
 {"<object_definition_list>", "goil_syntax", 25}, // at index 7
 {"<boolean>", "goil_syntax", 27}, // at index 8
 {"<oil_declaration_list>", "goil_syntax", 29}, // at index 9
 {"<oil_declaration>", "goil_syntax", 31}, // at index 10
 {"<include_file_level>", "goil_syntax", 35}, // at index 11
 {"<include_cpu_level>", "goil_syntax", 38}, // at index 12
 {"<include_object_level>", "goil_syntax", 41}, // at index 13
 {"<select_goil_5F_syntax_0>", "goil_syntax", 44}, // at index 14
 {"<select_goil_5F_syntax_0>", "goil_syntax", 45}, // at index 15
 {"<select_goil_5F_syntax_0>", "goil_syntax", 48}, // at index 16
 {"<select_goil_5F_syntax_0>", "goil_syntax", 51}, // at index 17
 {"<select_goil_5F_syntax_1>", "goil_syntax", 54}, // at index 18
 {"<select_goil_5F_syntax_1>", "goil_syntax", 55}, // at index 19
 {"<select_goil_5F_syntax_1>", "goil_syntax", 58}, // at index 20
 {"<select_goil_5F_syntax_2>", "goil_syntax", 61}, // at index 21
 {"<select_goil_5F_syntax_2>", "goil_syntax", 63}, // at index 22
 {"<select_goil_5F_syntax_2>", "goil_syntax", 65}, // at index 23
 {"<select_goil_5F_syntax_3>", "goil_syntax", 66}, // at index 24
 {"<select_goil_5F_syntax_3>", "goil_syntax", 67}, // at index 25
 {"<select_goil_5F_syntax_4>", "goil_syntax", 71}, // at index 26
 {"<select_goil_5F_syntax_4>", "goil_syntax", 72}, // at index 27
 {"<select_goil_5F_syntax_5>", "goil_syntax", 75}, // at index 28
 {"<select_goil_5F_syntax_5>", "goil_syntax", 76}, // at index 29
 {"<select_goil_5F_syntax_5>", "goil_syntax", 85}, // at index 30
 {"<select_goil_5F_syntax_6>", "goil_syntax", 88}, // at index 31
 {"<select_goil_5F_syntax_6>", "goil_syntax", 90}, // at index 32
 {"<select_goil_5F_syntax_7>", "goil_syntax", 92}, // at index 33
 {"<select_goil_5F_syntax_7>", "goil_syntax", 93}, // at index 34
 {"<select_goil_5F_syntax_7>", "goil_syntax", 96}, // at index 35
 {"<select_goil_5F_syntax_8>", "goil_syntax", 99}, // at index 36
 {"<select_goil_5F_syntax_8>", "goil_syntax", 102}, // at index 37
 {"<select_goil_5F_syntax_9>", "goil_syntax", 108}, // at index 38
 {"<select_goil_5F_syntax_9>", "goil_syntax", 112}, // at index 39
 {"<select_goil_5F_syntax_9>", "goil_syntax", 115}, // at index 40
 {"<select_goil_5F_syntax_9>", "goil_syntax", 119}, // at index 41
 {"<select_goil_5F_syntax_9>", "goil_syntax", 122}, // at index 42
 {"<select_goil_5F_syntax_10>", "goil_syntax", 125}, // at index 43
 {"<select_goil_5F_syntax_10>", "goil_syntax", 129}, // at index 44
 {"<select_goil_5F_syntax_11>", "goil_syntax", 130}, // at index 45
 {"<select_goil_5F_syntax_11>", "goil_syntax", 133}, // at index 46
 {"<select_goil_5F_syntax_12>", "goil_syntax", 136}, // at index 47
 {"<select_goil_5F_syntax_12>", "goil_syntax", 140}, // at index 48
 {"<select_goil_5F_syntax_13>", "goil_syntax", 141}, // at index 49
 {"<select_goil_5F_syntax_13>", "goil_syntax", 143}, // at index 50
 {"<select_goil_5F_syntax_14>", "goil_syntax", 145}, // at index 51
 {"<select_goil_5F_syntax_14>", "goil_syntax", 147}, // at index 52
 {"<select_goil_5F_syntax_15>", "goil_syntax", 149}, // at index 53
 {"<select_goil_5F_syntax_15>", "goil_syntax", 151}, // at index 54
 {"<select_goil_5F_syntax_16>", "goil_syntax", 153}, // at index 55
 {"<select_goil_5F_syntax_16>", "goil_syntax", 155}, // at index 56
 {"<select_goil_5F_syntax_17>", "goil_syntax", 157}, // at index 57
 {"<select_goil_5F_syntax_17>", "goil_syntax", 159}, // at index 58
 {"<select_goil_5F_syntax_18>", "goil_syntax", 161}, // at index 59
 {"<select_goil_5F_syntax_18>", "goil_syntax", 163}, // at index 60
 {"<>", "", 165} // at index 61
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t gProductionIndexes_goil_object_level_include [62] = {
0, // index 0 : <start>, in file 'goil_syntax.ggs', line 38
3, // index 1 : <file>, in file 'goil_syntax.ggs', line 119
5, // index 2 : <file_without_include>, in file 'goil_syntax.ggs', line 135
7, // index 3 : <sign>, in file 'goil_syntax.ggs', line 146
9, // index 4 : <description>, in file 'goil_syntax.ggs', line 159
11, // index 5 : <OIL_version>, in file 'goil_syntax.ggs', line 183
17, // index 6 : <application_definition>, in file 'goil_syntax.ggs', line 190
25, // index 7 : <object_definition_list>, in file 'goil_syntax.ggs', line 204
27, // index 8 : <boolean>, in file 'goil_syntax.ggs', line 254
29, // index 9 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 264
31, // index 10 : <oil_declaration>, in file 'goil_syntax.ggs', line 276
35, // index 11 : <include_file_level>, in file 'goil_syntax.ggs', line 483
38, // index 12 : <include_cpu_level>, in file 'goil_syntax.ggs', line 507
41, // index 13 : <include_object_level>, in file 'goil_syntax.ggs', line 531
44, // index 14 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
45, // index 15 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
48, // index 16 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
51, // index 17 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
54, // index 18 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
55, // index 19 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
58, // index 20 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
61, // index 21 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
63, // index 22 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
65, // index 23 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
66, // index 24 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 160
67, // index 25 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 160
71, // index 26 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 167
72, // index 27 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 167
75, // index 28 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
76, // index 29 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
85, // index 30 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
88, // index 31 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 255
90, // index 32 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 255
92, // index 33 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
93, // index 34 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
96, // index 35 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
99, // index 36 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 293
102, // index 37 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 293
108, // index 38 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
112, // index 39 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
115, // index 40 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
119, // index 41 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
122, // index 42 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
125, // index 43 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 316
129, // index 44 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 316
130, // index 45 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 333
133, // index 46 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 333
136, // index 47 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 376
140, // index 48 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 376
141, // index 49 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 490
143, // index 50 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 490
145, // index 51 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 496
147, // index 52 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 496
149, // index 53 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 514
151, // index 54 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 514
153, // index 55 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 520
155, // index 56 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 520
157, // index 57 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 536
159, // index 58 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 536
161, // index 59 : <select_goil_5F_syntax_18>, in file 'goil_syntax.ggs', line 542
163, // index 60 : <select_goil_5F_syntax_18>, in file 'goil_syntax.ggs', line 542
165 // index 61 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t gFirstProductionIndexes_goil_object_level_include [36] = {
0, // at 0 : <implementation_definition>
0, // at 1 : <start>
1, // at 2 : <file>
2, // at 3 : <file_without_include>
3, // at 4 : <sign>
4, // at 5 : <description>
5, // at 6 : <OIL_version>
6, // at 7 : <application_definition>
7, // at 8 : <object_definition_list>
8, // at 9 : <boolean>
9, // at 10 : <oil_declaration_list>
10, // at 11 : <oil_declaration>
11, // at 12 : <include_file_level>
12, // at 13 : <include_cpu_level>
13, // at 14 : <include_object_level>
14, // at 15 : <select_goil_5F_syntax_0>
18, // at 16 : <select_goil_5F_syntax_1>
21, // at 17 : <select_goil_5F_syntax_2>
24, // at 18 : <select_goil_5F_syntax_3>
26, // at 19 : <select_goil_5F_syntax_4>
28, // at 20 : <select_goil_5F_syntax_5>
31, // at 21 : <select_goil_5F_syntax_6>
33, // at 22 : <select_goil_5F_syntax_7>
36, // at 23 : <select_goil_5F_syntax_8>
38, // at 24 : <select_goil_5F_syntax_9>
43, // at 25 : <select_goil_5F_syntax_10>
45, // at 26 : <select_goil_5F_syntax_11>
47, // at 27 : <select_goil_5F_syntax_12>
49, // at 28 : <select_goil_5F_syntax_13>
51, // at 29 : <select_goil_5F_syntax_14>
53, // at 30 : <select_goil_5F_syntax_15>
55, // at 31 : <select_goil_5F_syntax_16>
57, // at 32 : <select_goil_5F_syntax_17>
59, // at 33 : <select_goil_5F_syntax_18>
61, // at 34 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t gDecision_goil_object_level_include [] = {
// At index 0 : <implementation_definition> no production
// At index 0 : <start> only one production, no choice
  -1,
// At index 1 : <file> only one production, no choice
  -1,
// At index 2 : <file_without_include> only one production, no choice
  -1,
// At index 3 : <sign> only one production, no choice
  -1,
// At index 4 : <description> only one production, no choice
  -1,
// At index 5 : <OIL_version> only one production, no choice
  -1,
// At index 6 : <application_definition> only one production, no choice
  -1,
// At index 7 : <object_definition_list> only one production, no choice
  -1,
// At index 8 : <boolean> only one production, no choice
  -1,
// At index 9 : <oil_declaration_list> only one production, no choice
  -1,
// At index 10 : <oil_declaration> only one production, no choice
  -1,
// At index 11 : <include_file_level> only one production, no choice
  -1,
// At index 12 : <include_cpu_level> only one production, no choice
  -1,
// At index 13 : <include_object_level> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 14 : <select_goil_5F_syntax_0>
-1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
-1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 22 : <select_goil_5F_syntax_1>
-1, // Choice 1
-1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 3
  -1,
// At index 27 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 3
  -1,
// At index 35 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 40 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 45 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 53 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 58 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__7D_, C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 67 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 72 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 87 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 93 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 98 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 104 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 109 : <select_goil_5F_syntax_14>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 114 : <select_goil_5F_syntax_15>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 119 : <select_goil_5F_syntax_16>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 124 : <select_goil_5F_syntax_17>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 129 : <select_goil_5F_syntax_18>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 134 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t gDecisionIndexes_goil_object_level_include [36] = {
0, // at 0 : <implementation_definition>
0, // at 1 : <start>
1, // at 2 : <file>
2, // at 3 : <file_without_include>
3, // at 4 : <sign>
4, // at 5 : <description>
5, // at 6 : <OIL_version>
6, // at 7 : <application_definition>
7, // at 8 : <object_definition_list>
8, // at 9 : <boolean>
9, // at 10 : <oil_declaration_list>
10, // at 11 : <oil_declaration>
11, // at 12 : <include_file_level>
12, // at 13 : <include_cpu_level>
13, // at 14 : <include_object_level>
14, // at 15 : <select_goil_5F_syntax_0>
22, // at 16 : <select_goil_5F_syntax_1>
27, // at 17 : <select_goil_5F_syntax_2>
35, // at 18 : <select_goil_5F_syntax_3>
40, // at 19 : <select_goil_5F_syntax_4>
45, // at 20 : <select_goil_5F_syntax_5>
53, // at 21 : <select_goil_5F_syntax_6>
58, // at 22 : <select_goil_5F_syntax_7>
67, // at 23 : <select_goil_5F_syntax_8>
72, // at 24 : <select_goil_5F_syntax_9>
87, // at 25 : <select_goil_5F_syntax_10>
93, // at 26 : <select_goil_5F_syntax_11>
98, // at 27 : <select_goil_5F_syntax_12>
104, // at 28 : <select_goil_5F_syntax_13>
109, // at 29 : <select_goil_5F_syntax_14>
114, // at 30 : <select_goil_5F_syntax_15>
119, // at 31 : <select_goil_5F_syntax_16>
124, // at 32 : <select_goil_5F_syntax_17>
129, // at 33 : <select_goil_5F_syntax_18>
134, // at 34 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_definition' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * ) {
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_implementation_5F_definition_indexing (C_Lexique_goil_5F_lexique * ) {
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_implementation_5F_definition_ (GALGAS_implementation & ,
                                C_Lexique_goil_5F_lexique * ) {
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'start' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_start_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_start_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_indexing(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_start_ (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_(inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'file' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_file_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_file_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_indexing(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_file_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'file_without_include' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_file_5F_without_5F_include_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_5F_without_5F_include_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_file_5F_without_5F_include_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_5F_without_5F_include_i2_indexing(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_file_5F_without_5F_include_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_5F_without_5F_include_i2_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'sign' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_sign_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i3_indexing(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'description' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_description_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i4_indexing(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i4_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'OIL_version' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_OIL_5F_version_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i5_indexing(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i5_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'application_definition' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_application_5F_definition_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i6_indexing(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_application_5F_definition_ (const GALGAS_implementation parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i6_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'object_definition_list' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_object_5F_definition_5F_list_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i7_indexing(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_object_5F_definition_5F_list_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i7_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'boolean' non terminal implementation                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_boolean_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i8_indexing(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i8_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'oil_declaration_list' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_oil_5F_declaration_5F_list_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i9_indexing(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i9_(parameter_1, parameter_2, inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::performIndexing (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  scanner->enableIndexing () ;
  if (scanner->sourceText ().isValid ()) {
    const bool ok = scanner->performTopDownParsing (gProductions_goil_object_level_include, gProductionNames_goil_object_level_include, gProductionIndexes_goil_object_level_include,
                                                    gFirstProductionIndexes_goil_object_level_include, gDecision_goil_object_level_include, gDecisionIndexes_goil_object_level_include, 165) ;
    if (ok) {
      cGrammar_goil_5F_object_5F_level_5F_include grammar ;
      grammar.nt_oil_5F_declaration_5F_list_indexing (scanner) ;
    }
    scanner->generateIndexFile () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performTopDownParsing (gProductions_goil_object_level_include, gProductionNames_goil_object_level_include, gProductionIndexes_goil_object_level_include,
                                    gFirstProductionIndexes_goil_object_level_include, gDecision_goil_object_level_include, gDecisionIndexes_goil_object_level_include, 165) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                const GALGAS_implementationObjectMap  parameter_1,
                                GALGAS_objectAttributes &  parameter_2
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.readProperty_string () ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, filePath COMMA_HERE)) ;
    if (scanner->sourceText ().isValid ()) {
      const bool ok = scanner->performTopDownParsing (gProductions_goil_object_level_include, gProductionNames_goil_object_level_include, gProductionIndexes_goil_object_level_include,
                                                      gFirstProductionIndexes_goil_object_level_include, gDecision_goil_object_level_include, gDecisionIndexes_goil_object_level_include, 165) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_object_5F_level_5F_include grammar ;
        grammar.nt_oil_5F_declaration_5F_list_ (parameter_1, parameter_2, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.readProperty_location ()) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.readProperty_location ()) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                const GALGAS_implementationObjectMap  parameter_1,
                                GALGAS_objectAttributes &  parameter_2
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_goil_object_level_include, gProductionNames_goil_object_level_include, gProductionIndexes_goil_object_level_include,
                                                    gFirstProductionIndexes_goil_object_level_include, gDecision_goil_object_level_include, gDecisionIndexes_goil_object_level_include, 165) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_goil_5F_object_5F_level_5F_include grammar ;
      grammar.nt_oil_5F_declaration_5F_list_ (parameter_1, parameter_2, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'oil_declaration' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_oil_5F_declaration_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i10_indexing(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i10_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_file_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_file_5F_level_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i11_indexing(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_file_5F_level_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i11_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_cpu_level' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_cpu_5F_level_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i12_indexing(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_cpu_5F_level_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i12_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'include_object_level' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i13_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_object_5F_level_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i13_indexing(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i13_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_0' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_1' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_2' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_3' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_4' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_5' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_6' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_7' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_8' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_9' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_10' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_11' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_12' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_13' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_14' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_15' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_16' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_17' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_18' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_18 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int32_t gProductions_goil_cpu_level_include [] = {
// At index 0 : <start>, in file 'goil_syntax.ggs', line 38
  NONTERMINAL (6) // <OIL_version>
, NONTERMINAL (2) // <file>
, END_PRODUCTION
// At index 3 : <file>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (15) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 5 : <file_without_include>, in file 'goil_syntax.ggs', line 135
, NONTERMINAL (16) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 7 : <sign>, in file 'goil_syntax.ggs', line 146
, NONTERMINAL (17) // <select_goil_5F_syntax_2>
, END_PRODUCTION
// At index 9 : <description>, in file 'goil_syntax.ggs', line 159
, NONTERMINAL (18) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 11 : <OIL_version>, in file 'goil_syntax.ggs', line 183
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) // $OIL_VERSION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (5) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 17 : <application_definition>, in file 'goil_syntax.ggs', line 190
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) // $CPU$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (8) // <object_definition_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (5) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 25 : <object_definition_list>, in file 'goil_syntax.ggs', line 204
, NONTERMINAL (20) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 27 : <boolean>, in file 'goil_syntax.ggs', line 254
, NONTERMINAL (21) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 29 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 264
, NONTERMINAL (22) // <select_goil_5F_syntax_7>
, END_PRODUCTION
// At index 31 : <oil_declaration>, in file 'goil_syntax.ggs', line 276
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (23) // <select_goil_5F_syntax_8>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 35 : <include_file_level>, in file 'goil_syntax.ggs', line 483
, NONTERMINAL (28) // <select_goil_5F_syntax_13>
, NONTERMINAL (29) // <select_goil_5F_syntax_14>
, END_PRODUCTION
// At index 38 : <include_cpu_level>, in file 'goil_syntax.ggs', line 507
, NONTERMINAL (30) // <select_goil_5F_syntax_15>
, NONTERMINAL (31) // <select_goil_5F_syntax_16>
, END_PRODUCTION
// At index 41 : <include_object_level>, in file 'goil_syntax.ggs', line 531
, NONTERMINAL (32) // <select_goil_5F_syntax_17>
, NONTERMINAL (33) // <select_goil_5F_syntax_18>
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 44 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
, END_PRODUCTION
// At index 45 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
, NONTERMINAL (12) // <include_file_level>
, NONTERMINAL (15) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 48 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (15) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 51 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
, NONTERMINAL (7) // <application_definition>
, NONTERMINAL (15) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 54 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
, END_PRODUCTION
// At index 55 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (16) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 58 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
, NONTERMINAL (7) // <application_definition>
, NONTERMINAL (16) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 61 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) // $-$
, END_PRODUCTION
// At index 63 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) // $+$
, END_PRODUCTION
// At index 65 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
, END_PRODUCTION
// At index 66 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 160
, END_PRODUCTION
// At index 67 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 160
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) // $:$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (19) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 71 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 167
, END_PRODUCTION
// At index 72 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 167
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (19) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 75 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
, END_PRODUCTION
// At index 76 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (10) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (5) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (20) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 85 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
, NONTERMINAL (13) // <include_cpu_level>
, NONTERMINAL (20) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 88 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 255
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 90 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 255
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 92 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
, END_PRODUCTION
// At index 93 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
, NONTERMINAL (11) // <oil_declaration>
, NONTERMINAL (22) // <select_goil_5F_syntax_7>
, END_PRODUCTION
// At index 96 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
, NONTERMINAL (14) // <include_object_level>
, NONTERMINAL (22) // <select_goil_5F_syntax_7>
, END_PRODUCTION
// At index 99 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 293
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (24) // <select_goil_5F_syntax_9>
, END_PRODUCTION
// At index 102 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 293
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (10) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 108 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (25) // <select_goil_5F_syntax_10>
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 112 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
, NONTERMINAL (4) // <sign>
, NONTERMINAL (26) // <select_goil_5F_syntax_11>
, END_PRODUCTION
// At index 115 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
, NONTERMINAL (9) // <boolean>
, NONTERMINAL (27) // <select_goil_5F_syntax_12>
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 119 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 122 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 125 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 316
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (10) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 129 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 316
, END_PRODUCTION
// At index 130 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 333
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 133 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 333
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 136 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 376
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (10) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 140 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 376
, END_PRODUCTION
// At index 141 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 490
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 143 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 490
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 145 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 496
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 147 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 496
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 149 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 514
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 151 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 514
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 153 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 520
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 155 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 520
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 157 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 536
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 159 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 536
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 161 : <select_goil_5F_syntax_18>, in file 'goil_syntax.ggs', line 542
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 163 : <select_goil_5F_syntax_18>, in file 'goil_syntax.ggs', line 542
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 165 : <>, in file '.ggs', line 0
, NONTERMINAL (8) // <object_definition_list>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_goil_cpu_level_include [62] = {
 {"<start>", "goil_syntax", 0}, // at index 0
 {"<file>", "goil_syntax", 3}, // at index 1
 {"<file_without_include>", "goil_syntax", 5}, // at index 2
 {"<sign>", "goil_syntax", 7}, // at index 3
 {"<description>", "goil_syntax", 9}, // at index 4
 {"<OIL_version>", "goil_syntax", 11}, // at index 5
 {"<application_definition>", "goil_syntax", 17}, // at index 6
 {"<object_definition_list>", "goil_syntax", 25}, // at index 7
 {"<boolean>", "goil_syntax", 27}, // at index 8
 {"<oil_declaration_list>", "goil_syntax", 29}, // at index 9
 {"<oil_declaration>", "goil_syntax", 31}, // at index 10
 {"<include_file_level>", "goil_syntax", 35}, // at index 11
 {"<include_cpu_level>", "goil_syntax", 38}, // at index 12
 {"<include_object_level>", "goil_syntax", 41}, // at index 13
 {"<select_goil_5F_syntax_0>", "goil_syntax", 44}, // at index 14
 {"<select_goil_5F_syntax_0>", "goil_syntax", 45}, // at index 15
 {"<select_goil_5F_syntax_0>", "goil_syntax", 48}, // at index 16
 {"<select_goil_5F_syntax_0>", "goil_syntax", 51}, // at index 17
 {"<select_goil_5F_syntax_1>", "goil_syntax", 54}, // at index 18
 {"<select_goil_5F_syntax_1>", "goil_syntax", 55}, // at index 19
 {"<select_goil_5F_syntax_1>", "goil_syntax", 58}, // at index 20
 {"<select_goil_5F_syntax_2>", "goil_syntax", 61}, // at index 21
 {"<select_goil_5F_syntax_2>", "goil_syntax", 63}, // at index 22
 {"<select_goil_5F_syntax_2>", "goil_syntax", 65}, // at index 23
 {"<select_goil_5F_syntax_3>", "goil_syntax", 66}, // at index 24
 {"<select_goil_5F_syntax_3>", "goil_syntax", 67}, // at index 25
 {"<select_goil_5F_syntax_4>", "goil_syntax", 71}, // at index 26
 {"<select_goil_5F_syntax_4>", "goil_syntax", 72}, // at index 27
 {"<select_goil_5F_syntax_5>", "goil_syntax", 75}, // at index 28
 {"<select_goil_5F_syntax_5>", "goil_syntax", 76}, // at index 29
 {"<select_goil_5F_syntax_5>", "goil_syntax", 85}, // at index 30
 {"<select_goil_5F_syntax_6>", "goil_syntax", 88}, // at index 31
 {"<select_goil_5F_syntax_6>", "goil_syntax", 90}, // at index 32
 {"<select_goil_5F_syntax_7>", "goil_syntax", 92}, // at index 33
 {"<select_goil_5F_syntax_7>", "goil_syntax", 93}, // at index 34
 {"<select_goil_5F_syntax_7>", "goil_syntax", 96}, // at index 35
 {"<select_goil_5F_syntax_8>", "goil_syntax", 99}, // at index 36
 {"<select_goil_5F_syntax_8>", "goil_syntax", 102}, // at index 37
 {"<select_goil_5F_syntax_9>", "goil_syntax", 108}, // at index 38
 {"<select_goil_5F_syntax_9>", "goil_syntax", 112}, // at index 39
 {"<select_goil_5F_syntax_9>", "goil_syntax", 115}, // at index 40
 {"<select_goil_5F_syntax_9>", "goil_syntax", 119}, // at index 41
 {"<select_goil_5F_syntax_9>", "goil_syntax", 122}, // at index 42
 {"<select_goil_5F_syntax_10>", "goil_syntax", 125}, // at index 43
 {"<select_goil_5F_syntax_10>", "goil_syntax", 129}, // at index 44
 {"<select_goil_5F_syntax_11>", "goil_syntax", 130}, // at index 45
 {"<select_goil_5F_syntax_11>", "goil_syntax", 133}, // at index 46
 {"<select_goil_5F_syntax_12>", "goil_syntax", 136}, // at index 47
 {"<select_goil_5F_syntax_12>", "goil_syntax", 140}, // at index 48
 {"<select_goil_5F_syntax_13>", "goil_syntax", 141}, // at index 49
 {"<select_goil_5F_syntax_13>", "goil_syntax", 143}, // at index 50
 {"<select_goil_5F_syntax_14>", "goil_syntax", 145}, // at index 51
 {"<select_goil_5F_syntax_14>", "goil_syntax", 147}, // at index 52
 {"<select_goil_5F_syntax_15>", "goil_syntax", 149}, // at index 53
 {"<select_goil_5F_syntax_15>", "goil_syntax", 151}, // at index 54
 {"<select_goil_5F_syntax_16>", "goil_syntax", 153}, // at index 55
 {"<select_goil_5F_syntax_16>", "goil_syntax", 155}, // at index 56
 {"<select_goil_5F_syntax_17>", "goil_syntax", 157}, // at index 57
 {"<select_goil_5F_syntax_17>", "goil_syntax", 159}, // at index 58
 {"<select_goil_5F_syntax_18>", "goil_syntax", 161}, // at index 59
 {"<select_goil_5F_syntax_18>", "goil_syntax", 163}, // at index 60
 {"<>", "", 165} // at index 61
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t gProductionIndexes_goil_cpu_level_include [62] = {
0, // index 0 : <start>, in file 'goil_syntax.ggs', line 38
3, // index 1 : <file>, in file 'goil_syntax.ggs', line 119
5, // index 2 : <file_without_include>, in file 'goil_syntax.ggs', line 135
7, // index 3 : <sign>, in file 'goil_syntax.ggs', line 146
9, // index 4 : <description>, in file 'goil_syntax.ggs', line 159
11, // index 5 : <OIL_version>, in file 'goil_syntax.ggs', line 183
17, // index 6 : <application_definition>, in file 'goil_syntax.ggs', line 190
25, // index 7 : <object_definition_list>, in file 'goil_syntax.ggs', line 204
27, // index 8 : <boolean>, in file 'goil_syntax.ggs', line 254
29, // index 9 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 264
31, // index 10 : <oil_declaration>, in file 'goil_syntax.ggs', line 276
35, // index 11 : <include_file_level>, in file 'goil_syntax.ggs', line 483
38, // index 12 : <include_cpu_level>, in file 'goil_syntax.ggs', line 507
41, // index 13 : <include_object_level>, in file 'goil_syntax.ggs', line 531
44, // index 14 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
45, // index 15 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
48, // index 16 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
51, // index 17 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
54, // index 18 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
55, // index 19 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
58, // index 20 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
61, // index 21 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
63, // index 22 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
65, // index 23 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
66, // index 24 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 160
67, // index 25 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 160
71, // index 26 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 167
72, // index 27 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 167
75, // index 28 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
76, // index 29 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
85, // index 30 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
88, // index 31 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 255
90, // index 32 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 255
92, // index 33 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
93, // index 34 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
96, // index 35 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
99, // index 36 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 293
102, // index 37 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 293
108, // index 38 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
112, // index 39 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
115, // index 40 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
119, // index 41 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
122, // index 42 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
125, // index 43 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 316
129, // index 44 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 316
130, // index 45 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 333
133, // index 46 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 333
136, // index 47 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 376
140, // index 48 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 376
141, // index 49 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 490
143, // index 50 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 490
145, // index 51 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 496
147, // index 52 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 496
149, // index 53 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 514
151, // index 54 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 514
153, // index 55 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 520
155, // index 56 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 520
157, // index 57 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 536
159, // index 58 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 536
161, // index 59 : <select_goil_5F_syntax_18>, in file 'goil_syntax.ggs', line 542
163, // index 60 : <select_goil_5F_syntax_18>, in file 'goil_syntax.ggs', line 542
165 // index 61 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t gFirstProductionIndexes_goil_cpu_level_include [36] = {
0, // at 0 : <implementation_definition>
0, // at 1 : <start>
1, // at 2 : <file>
2, // at 3 : <file_without_include>
3, // at 4 : <sign>
4, // at 5 : <description>
5, // at 6 : <OIL_version>
6, // at 7 : <application_definition>
7, // at 8 : <object_definition_list>
8, // at 9 : <boolean>
9, // at 10 : <oil_declaration_list>
10, // at 11 : <oil_declaration>
11, // at 12 : <include_file_level>
12, // at 13 : <include_cpu_level>
13, // at 14 : <include_object_level>
14, // at 15 : <select_goil_5F_syntax_0>
18, // at 16 : <select_goil_5F_syntax_1>
21, // at 17 : <select_goil_5F_syntax_2>
24, // at 18 : <select_goil_5F_syntax_3>
26, // at 19 : <select_goil_5F_syntax_4>
28, // at 20 : <select_goil_5F_syntax_5>
31, // at 21 : <select_goil_5F_syntax_6>
33, // at 22 : <select_goil_5F_syntax_7>
36, // at 23 : <select_goil_5F_syntax_8>
38, // at 24 : <select_goil_5F_syntax_9>
43, // at 25 : <select_goil_5F_syntax_10>
45, // at 26 : <select_goil_5F_syntax_11>
47, // at 27 : <select_goil_5F_syntax_12>
49, // at 28 : <select_goil_5F_syntax_13>
51, // at 29 : <select_goil_5F_syntax_14>
53, // at 30 : <select_goil_5F_syntax_15>
55, // at 31 : <select_goil_5F_syntax_16>
57, // at 32 : <select_goil_5F_syntax_17>
59, // at 33 : <select_goil_5F_syntax_18>
61, // at 34 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t gDecision_goil_cpu_level_include [] = {
// At index 0 : <implementation_definition> no production
// At index 0 : <start> only one production, no choice
  -1,
// At index 1 : <file> only one production, no choice
  -1,
// At index 2 : <file_without_include> only one production, no choice
  -1,
// At index 3 : <sign> only one production, no choice
  -1,
// At index 4 : <description> only one production, no choice
  -1,
// At index 5 : <OIL_version> only one production, no choice
  -1,
// At index 6 : <application_definition> only one production, no choice
  -1,
// At index 7 : <object_definition_list> only one production, no choice
  -1,
// At index 8 : <boolean> only one production, no choice
  -1,
// At index 9 : <oil_declaration_list> only one production, no choice
  -1,
// At index 10 : <oil_declaration> only one production, no choice
  -1,
// At index 11 : <include_file_level> only one production, no choice
  -1,
// At index 12 : <include_cpu_level> only one production, no choice
  -1,
// At index 13 : <include_object_level> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 14 : <select_goil_5F_syntax_0>
-1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
-1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 22 : <select_goil_5F_syntax_1>
-1, // Choice 1
-1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 3
  -1,
// At index 27 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 3
  -1,
// At index 35 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 40 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 45 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken__7D_, C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 54 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 59 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 67 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 72 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 87 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 93 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 98 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 104 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 109 : <select_goil_5F_syntax_14>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 114 : <select_goil_5F_syntax_15>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 119 : <select_goil_5F_syntax_16>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 124 : <select_goil_5F_syntax_17>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 129 : <select_goil_5F_syntax_18>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 134 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t gDecisionIndexes_goil_cpu_level_include [36] = {
0, // at 0 : <implementation_definition>
0, // at 1 : <start>
1, // at 2 : <file>
2, // at 3 : <file_without_include>
3, // at 4 : <sign>
4, // at 5 : <description>
5, // at 6 : <OIL_version>
6, // at 7 : <application_definition>
7, // at 8 : <object_definition_list>
8, // at 9 : <boolean>
9, // at 10 : <oil_declaration_list>
10, // at 11 : <oil_declaration>
11, // at 12 : <include_file_level>
12, // at 13 : <include_cpu_level>
13, // at 14 : <include_object_level>
14, // at 15 : <select_goil_5F_syntax_0>
22, // at 16 : <select_goil_5F_syntax_1>
27, // at 17 : <select_goil_5F_syntax_2>
35, // at 18 : <select_goil_5F_syntax_3>
40, // at 19 : <select_goil_5F_syntax_4>
45, // at 20 : <select_goil_5F_syntax_5>
54, // at 21 : <select_goil_5F_syntax_6>
59, // at 22 : <select_goil_5F_syntax_7>
67, // at 23 : <select_goil_5F_syntax_8>
72, // at 24 : <select_goil_5F_syntax_9>
87, // at 25 : <select_goil_5F_syntax_10>
93, // at 26 : <select_goil_5F_syntax_11>
98, // at 27 : <select_goil_5F_syntax_12>
104, // at 28 : <select_goil_5F_syntax_13>
109, // at 29 : <select_goil_5F_syntax_14>
114, // at 30 : <select_goil_5F_syntax_15>
119, // at 31 : <select_goil_5F_syntax_16>
124, // at 32 : <select_goil_5F_syntax_17>
129, // at 33 : <select_goil_5F_syntax_18>
134, // at 34 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_definition' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * ) {
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_implementation_5F_definition_indexing (C_Lexique_goil_5F_lexique * ) {
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_implementation_5F_definition_ (GALGAS_implementation & ,
                                C_Lexique_goil_5F_lexique * ) {
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'start' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_start_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_start_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_indexing(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_start_ (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_(inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'file' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_file_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_file_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_indexing(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_file_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'file_without_include' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_file_5F_without_5F_include_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_5F_without_5F_include_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_file_5F_without_5F_include_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_5F_without_5F_include_i2_indexing(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_file_5F_without_5F_include_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_5F_without_5F_include_i2_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'sign' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_sign_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i3_indexing(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'description' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_description_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i4_indexing(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i4_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'OIL_version' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_OIL_5F_version_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i5_indexing(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i5_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'application_definition' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_application_5F_definition_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i6_indexing(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_application_5F_definition_ (const GALGAS_implementation parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i6_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'object_definition_list' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_object_5F_definition_5F_list_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i7_indexing(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_object_5F_definition_5F_list_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i7_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::performIndexing (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  scanner->enableIndexing () ;
  if (scanner->sourceText ().isValid ()) {
    const bool ok = scanner->performTopDownParsing (gProductions_goil_cpu_level_include, gProductionNames_goil_cpu_level_include, gProductionIndexes_goil_cpu_level_include,
                                                    gFirstProductionIndexes_goil_cpu_level_include, gDecision_goil_cpu_level_include, gDecisionIndexes_goil_cpu_level_include, 165) ;
    if (ok) {
      cGrammar_goil_5F_cpu_5F_level_5F_include grammar ;
      grammar.nt_object_5F_definition_5F_list_indexing (scanner) ;
    }
    scanner->generateIndexFile () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performTopDownParsing (gProductions_goil_cpu_level_include, gProductionNames_goil_cpu_level_include, gProductionIndexes_goil_cpu_level_include,
                                    gFirstProductionIndexes_goil_cpu_level_include, gDecision_goil_cpu_level_include, gDecisionIndexes_goil_cpu_level_include, 165) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                const GALGAS_implementation  parameter_1,
                                GALGAS_objectsMap &  parameter_2,
                                GALGAS_string &  parameter_3,
                                const GALGAS_bool  parameter_4
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.readProperty_string () ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, filePath COMMA_HERE)) ;
    if (scanner->sourceText ().isValid ()) {
      const bool ok = scanner->performTopDownParsing (gProductions_goil_cpu_level_include, gProductionNames_goil_cpu_level_include, gProductionIndexes_goil_cpu_level_include,
                                                      gFirstProductionIndexes_goil_cpu_level_include, gDecision_goil_cpu_level_include, gDecisionIndexes_goil_cpu_level_include, 165) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_cpu_5F_level_5F_include grammar ;
        grammar.nt_object_5F_definition_5F_list_ (parameter_1, parameter_2, parameter_3, parameter_4, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.readProperty_location ()) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.readProperty_location ()) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                const GALGAS_implementation  parameter_1,
                                GALGAS_objectsMap &  parameter_2,
                                GALGAS_string &  parameter_3,
                                const GALGAS_bool  parameter_4
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_goil_cpu_level_include, gProductionNames_goil_cpu_level_include, gProductionIndexes_goil_cpu_level_include,
                                                    gFirstProductionIndexes_goil_cpu_level_include, gDecision_goil_cpu_level_include, gDecisionIndexes_goil_cpu_level_include, 165) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_goil_5F_cpu_5F_level_5F_include grammar ;
      grammar.nt_object_5F_definition_5F_list_ (parameter_1, parameter_2, parameter_3, parameter_4, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'boolean' non terminal implementation                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_boolean_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i8_indexing(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i8_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'oil_declaration_list' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_oil_5F_declaration_5F_list_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i9_indexing(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'oil_declaration' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_oil_5F_declaration_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i10_indexing(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i10_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_file_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_file_5F_level_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i11_indexing(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_file_5F_level_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i11_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_cpu_level' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_cpu_5F_level_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i12_indexing(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_cpu_5F_level_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i12_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'include_object_level' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i13_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_object_5F_level_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i13_indexing(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i13_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_0' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_1' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_2' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_3' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_4' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_5' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_6' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_7' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_8' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_9' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_10' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_11' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_12' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_13' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_14' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_15' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_16' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_17' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_18' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_18 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*



//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_parser_5F_start_i0_ (GALGAS_gtlData & outArgument_options,
                                                                                      C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_options.drop () ; // Release 'out' argument
  outArgument_options = GALGAS_gtlStruct::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("options_parser.galgas", 32)), function_lstring (GALGAS_string ("Passed options"), inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 32)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("options_parser.galgas", 32))  COMMA_SOURCE_FILE ("options_parser.galgas", 32)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_option_5F_item_ (outArgument_options, inCompiler) ;
    if (select_options_5F_parser_0 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("options_parser.galgas", 35)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_parser_5F_start_i0_parse (C_Lexique_options_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_option_5F_item_parse (inCompiler) ;
    if (select_options_5F_parser_0 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("options_parser.galgas", 35)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_parser_5F_start_i0_indexing (C_Lexique_options_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_option_5F_item_indexing (inCompiler) ;
    if (select_options_5F_parser_0 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("options_parser.galgas", 35)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_item_i1_ (GALGAS_gtlData & ioArgument_options,
                                                                           C_Lexique_options_5F_scanner * inCompiler) {
  GALGAS_lstring var_key_985 = inCompiler->synthetizedAttribute_key () ;
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_idf COMMA_SOURCE_FILE ("options_parser.galgas", 42)) ;
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("options_parser.galgas", 43)) ;
  GALGAS_gtlData var_opt_1010 ;
  switch (select_options_5F_parser_1 (inCompiler)) {
  case 1: {
    nt_option_5F_value_ (var_opt_1010, inCompiler) ;
  } break ;
  case 2: {
    nt_list_5F_option_5F_value_ (var_opt_1010, inCompiler) ;
  } break ;
  default:
    break ;
  }
  {
  ioArgument_options.insulate (HERE) ;
  cPtr_gtlData * ptr_1092 = (cPtr_gtlData *) ioArgument_options.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1092, var_key_985, var_opt_1010, inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 50)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_item_i1_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_idf COMMA_SOURCE_FILE ("options_parser.galgas", 42)) ;
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("options_parser.galgas", 43)) ;
  switch (select_options_5F_parser_1 (inCompiler)) {
  case 1: {
    nt_option_5F_value_parse (inCompiler) ;
  } break ;
  case 2: {
    nt_list_5F_option_5F_value_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_item_i1_indexing (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_idf COMMA_SOURCE_FILE ("options_parser.galgas", 42)) ;
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("options_parser.galgas", 43)) ;
  switch (select_options_5F_parser_1 (inCompiler)) {
  case 1: {
    nt_option_5F_value_indexing (inCompiler) ;
  } break ;
  case 2: {
    nt_list_5F_option_5F_value_indexing (inCompiler) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i2_ (GALGAS_gtlData & outArgument_opt,
                                                                            C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  GALGAS_lstring var_str_1193 = inCompiler->synthetizedAttribute_string () ;
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_string COMMA_SOURCE_FILE ("options_parser.galgas", 56)) ;
  outArgument_opt = GALGAS_gtlString::constructor_new (var_str_1193.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 57)), var_str_1193.readProperty_string ()  COMMA_SOURCE_FILE ("options_parser.galgas", 57)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i2_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_string COMMA_SOURCE_FILE ("options_parser.galgas", 56)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i2_indexing (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_string COMMA_SOURCE_FILE ("options_parser.galgas", 56)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i3_ (GALGAS_gtlData & outArgument_opt,
                                                                            C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  GALGAS_lstring var_str_1313 = inCompiler->synthetizedAttribute_key () ;
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_idf COMMA_SOURCE_FILE ("options_parser.galgas", 63)) ;
  outArgument_opt = GALGAS_gtlString::constructor_new (var_str_1313.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 64)), var_str_1313.readProperty_string ()  COMMA_SOURCE_FILE ("options_parser.galgas", 64)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i3_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_idf COMMA_SOURCE_FILE ("options_parser.galgas", 63)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i3_indexing (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_idf COMMA_SOURCE_FILE ("options_parser.galgas", 63)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i4_ (GALGAS_gtlData & outArgument_opt,
                                                                            C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  GALGAS_luint_36__34_ var_num_1441 = inCompiler->synthetizedAttribute_integerNumber () ;
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_uint_5F_number COMMA_SOURCE_FILE ("options_parser.galgas", 70)) ;
  outArgument_opt = GALGAS_gtlInt::constructor_new (var_num_1441.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 71)), var_num_1441.readProperty_uint_36__34_ ().getter_bigint (SOURCE_FILE ("options_parser.galgas", 71))  COMMA_SOURCE_FILE ("options_parser.galgas", 71)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i4_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_uint_5F_number COMMA_SOURCE_FILE ("options_parser.galgas", 70)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i4_indexing (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_uint_5F_number COMMA_SOURCE_FILE ("options_parser.galgas", 70)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i5_ (GALGAS_gtlData & outArgument_opt,
                                                                            C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  GALGAS_ldouble var_num_1576 = inCompiler->synthetizedAttribute_floatNumber () ;
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_float_5F_number COMMA_SOURCE_FILE ("options_parser.galgas", 77)) ;
  outArgument_opt = GALGAS_gtlFloat::constructor_new (var_num_1576.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 78)), var_num_1576.readProperty_double ()  COMMA_SOURCE_FILE ("options_parser.galgas", 78)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i5_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_float_5F_number COMMA_SOURCE_FILE ("options_parser.galgas", 77)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i5_indexing (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_float_5F_number COMMA_SOURCE_FILE ("options_parser.galgas", 77)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i6_ (GALGAS_gtlData & outArgument_opt,
                                                                            C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("options_parser.galgas", 84)) ;
  switch (select_options_5F_parser_2 (inCompiler)) {
  case 1: {
    GALGAS_luint_36__34_ var_num_1720 = inCompiler->synthetizedAttribute_integerNumber () ;
    inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_uint_5F_number COMMA_SOURCE_FILE ("options_parser.galgas", 86)) ;
    outArgument_opt = GALGAS_gtlInt::constructor_new (var_num_1720.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 87)), var_num_1720.readProperty_uint_36__34_ ().getter_bigint (SOURCE_FILE ("options_parser.galgas", 87)).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 87))  COMMA_SOURCE_FILE ("options_parser.galgas", 87)) ;
  } break ;
  case 2: {
    GALGAS_ldouble var_num_1824 = inCompiler->synthetizedAttribute_floatNumber () ;
    inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_float_5F_number COMMA_SOURCE_FILE ("options_parser.galgas", 89)) ;
    outArgument_opt = GALGAS_gtlFloat::constructor_new (var_num_1824.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 90)), var_num_1824.readProperty_double ().operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 90))  COMMA_SOURCE_FILE ("options_parser.galgas", 90)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i6_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("options_parser.galgas", 84)) ;
  switch (select_options_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_uint_5F_number COMMA_SOURCE_FILE ("options_parser.galgas", 86)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_float_5F_number COMMA_SOURCE_FILE ("options_parser.galgas", 89)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i6_indexing (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("options_parser.galgas", 84)) ;
  switch (select_options_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_uint_5F_number COMMA_SOURCE_FILE ("options_parser.galgas", 86)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken_float_5F_number COMMA_SOURCE_FILE ("options_parser.galgas", 89)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_list_5F_option_5F_value_i7_ (GALGAS_gtlData & outArgument_opt,
                                                                                    C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  GALGAS_list var_listOption_1952 = GALGAS_list::constructor_emptyList (SOURCE_FILE ("options_parser.galgas", 97)) ;
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("options_parser.galgas", 98)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_gtlData var_item_2024 ;
    nt_option_5F_value_ (var_item_2024, inCompiler) ;
    var_listOption_1952.addAssign_operation (var_item_2024  COMMA_SOURCE_FILE ("options_parser.galgas", 101)) ;
    if (select_options_5F_parser_3 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("options_parser.galgas", 102)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  outArgument_opt = GALGAS_gtlList::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("options_parser.galgas", 104)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 104)), var_listOption_1952  COMMA_SOURCE_FILE ("options_parser.galgas", 104)) ;
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("options_parser.galgas", 105)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_list_5F_option_5F_value_i7_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("options_parser.galgas", 98)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_option_5F_value_parse (inCompiler) ;
    if (select_options_5F_parser_3 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("options_parser.galgas", 102)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("options_parser.galgas", 105)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_list_5F_option_5F_value_i7_indexing (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("options_parser.galgas", 98)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_option_5F_value_indexing (inCompiler) ;
    if (select_options_5F_parser_3 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("options_parser.galgas", 102)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_options_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("options_parser.galgas", 105)) ;
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

cTokenFor_arxml_5F_scanner::cTokenFor_arxml_5F_scanner (void) :
mLexicalAttribute_tokenString () {
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique_arxml_5F_scanner::C_Lexique_arxml_5F_scanner (C_Compiler * inCallerCompiler,
                                                        const C_String & inSourceFileName
                                                        COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceFileName COMMA_THERE),
mMatchedTemplateDelimiterIndex (-1) {
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique_arxml_5F_scanner::C_Lexique_arxml_5F_scanner (C_Compiler * inCallerCompiler,
                                                        const C_String & inSourceString,
                                                        const C_String & inStringForError
                                                        COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE),
mMatchedTemplateDelimiterIndex (-1) {
}

//----------------------------------------------------------------------------------------------------------------------
//                        Lexical error message list                                             
//----------------------------------------------------------------------------------------------------------------------

static const char * gLexicalMessage_arxml_5F_scanner_incorrectAttributeEnd = "attribute value should be enclosed between apostrophes (') or quotation marks (\")" ;

static const char * gLexicalMessage_arxml_5F_scanner_incorrectCommentError = "incorrect XML comment" ;

//----------------------------------------------------------------------------------------------------------------------
//                getMessageForTerminal                                                          
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_arxml_5F_scanner::getMessageForTerminal (const int32_t inTerminalIndex) const {
  C_String result = "<unknown>" ;
  if ((inTerminalIndex >= 0) && (inTerminalIndex < 11)) {
    static const char * syntaxErrorMessageArray [11] = {kEndOfSourceLexicalErrorMessage,
        "a comment",
        "a name",
        "an attribute value",
        "the '<' delimitor",
        "the '<\?' delimitor",
        "the '>' delimitor",
        "the '\?>' delimitor",
        "the '/>' delimitor",
        "the '</' delimitor",
        "the '=' delimitor"
    } ;
    result = syntaxErrorMessageArray [inTerminalIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                      U N I C O D E    S T R I N G S                                           
//----------------------------------------------------------------------------------------------------------------------

//--- Unicode string for '$_22_$'
static const utf32 kUnicodeString_arxml_5F_scanner__22_ [] = {
  TO_UNICODE ('\"'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_$'
static const utf32 kUnicodeString_arxml_5F_scanner__26_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26__23_$'
static const utf32 kUnicodeString_arxml_5F_scanner__26__23_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('#'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_amp_3B_$'
static const utf32 kUnicodeString_arxml_5F_scanner__26_amp_3B_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('a'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_apos_3B_$'
static const utf32 kUnicodeString_arxml_5F_scanner__26_apos_3B_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('a'),
  TO_UNICODE ('p'),
  TO_UNICODE ('o'),
  TO_UNICODE ('s'),
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_gt_3B_$'
static const utf32 kUnicodeString_arxml_5F_scanner__26_gt_3B_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('g'),
  TO_UNICODE ('t'),
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_lt_3B_$'
static const utf32 kUnicodeString_arxml_5F_scanner__26_lt_3B_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('l'),
  TO_UNICODE ('t'),
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_quot_3B_$'
static const utf32 kUnicodeString_arxml_5F_scanner__26_quot_3B_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('q'),
  TO_UNICODE ('u'),
  TO_UNICODE ('o'),
  TO_UNICODE ('t'),
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_27_$'
static const utf32 kUnicodeString_arxml_5F_scanner__27_ [] = {
  TO_UNICODE ('\''),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D__2D__3E_$'
static const utf32 kUnicodeString_arxml_5F_scanner__2D__2D__3E_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE ('-'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2F__3E_$'
static const utf32 kUnicodeString_arxml_5F_scanner__2F__3E_ [] = {
  TO_UNICODE ('/'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3B_$'
static const utf32 kUnicodeString_arxml_5F_scanner__3B_ [] = {
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C_$'
static const utf32 kUnicodeString_arxml_5F_scanner__3C_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__21__2D__2D_$'
static const utf32 kUnicodeString_arxml_5F_scanner__3C__21__2D__2D_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('!'),
  TO_UNICODE ('-'),
  TO_UNICODE ('-'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__2F_$'
static const utf32 kUnicodeString_arxml_5F_scanner__3C__2F_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('/'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__3F_$'
static const utf32 kUnicodeString_arxml_5F_scanner__3C__3F_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('\?'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3D_$'
static const utf32 kUnicodeString_arxml_5F_scanner__3D_ [] = {
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E_$'
static const utf32 kUnicodeString_arxml_5F_scanner__3E_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3F__3E_$'
static const utf32 kUnicodeString_arxml_5F_scanner__3F__3E_ [] = {
  TO_UNICODE ('\?'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'xmlDelimitorsList'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_arxml_5F_scanner_xmlDelimitorsList = 7 ;

static const C_unicode_lexique_table_entry ktable_for_arxml_5F_scanner_xmlDelimitorsList [ktable_size_arxml_5F_scanner_xmlDelimitorsList] = {
  C_unicode_lexique_table_entry (kUnicodeString_arxml_5F_scanner__3C_, 1, C_Lexique_arxml_5F_scanner::kToken__3C_),
  C_unicode_lexique_table_entry (kUnicodeString_arxml_5F_scanner__3D_, 1, C_Lexique_arxml_5F_scanner::kToken__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_arxml_5F_scanner__3E_, 1, C_Lexique_arxml_5F_scanner::kToken__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_arxml_5F_scanner__2F__3E_, 2, C_Lexique_arxml_5F_scanner::kToken__2F__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_arxml_5F_scanner__3C__2F_, 2, C_Lexique_arxml_5F_scanner::kToken__3C__2F_),
  C_unicode_lexique_table_entry (kUnicodeString_arxml_5F_scanner__3C__3F_, 2, C_Lexique_arxml_5F_scanner::kToken__3C__3F_),
  C_unicode_lexique_table_entry (kUnicodeString_arxml_5F_scanner__3F__3E_, 2, C_Lexique_arxml_5F_scanner::kToken__3F__3E_)
} ;

int32_t C_Lexique_arxml_5F_scanner::search_into_xmlDelimitorsList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_arxml_5F_scanner_xmlDelimitorsList, ktable_size_arxml_5F_scanner_xmlDelimitorsList) ;
}


//----------------------------------------------------------------------------------------------------------------------
//                          getCurrentTokenString                                                
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_arxml_5F_scanner::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_arxml_5F_scanner * ptr = (const cTokenFor_arxml_5F_scanner *) inTokenPtr ;
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
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_name:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("name") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_value:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("value") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken__3C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__3F_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<\?") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (">") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3F__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("\?>") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2F__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("/>") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__2F_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("</") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("=") ;
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

static const cTemplateDelimiter arxml_5F_scanner_kTemplateDefinitionArray [1] = {
  cTemplateDelimiter (kUnicodeString_arxml_5F_scanner__3C_, 1, nullptr, 0, nullptr, false)
} ;

//----------------------------------------------------------------------------------------------------------------------
//                           Template Replacements                                               
//----------------------------------------------------------------------------------------------------------------------

static const cTemplateDelimiter arxml_5F_scanner_kTemplateReplacementArray [6] = {
  cTemplateDelimiter (kUnicodeString_arxml_5F_scanner__26_amp_3B_, 5, kUnicodeString_arxml_5F_scanner__26_, 1, nullptr, true),
  cTemplateDelimiter (kUnicodeString_arxml_5F_scanner__26_lt_3B_, 4, kUnicodeString_arxml_5F_scanner__3C_, 1, nullptr, true),
  cTemplateDelimiter (kUnicodeString_arxml_5F_scanner__26_gt_3B_, 4, kUnicodeString_arxml_5F_scanner__3E_, 1, nullptr, true),
  cTemplateDelimiter (kUnicodeString_arxml_5F_scanner__26_quot_3B_, 6, kUnicodeString_arxml_5F_scanner__22_, 1, nullptr, true),
  cTemplateDelimiter (kUnicodeString_arxml_5F_scanner__26_apos_3B_, 6, kUnicodeString_arxml_5F_scanner__27_, 1, nullptr, true),
  cTemplateDelimiter (kUnicodeString_arxml_5F_scanner__26__23_, 2, kUnicodeString_arxml_5F_scanner__3B_, 1, scanner_routine_codePointToUnicode, true)
} ;

//----------------------------------------------------------------------------------------------------------------------
//            Terminal Symbols as end of script in template mark                                 
//----------------------------------------------------------------------------------------------------------------------

static const bool arxml_5F_scanner_kEndOfScriptInTemplateArray [10] = {
  true /* comment */,
  false /* name */,
  false /* value */,
  false /* < */,
  false /* <? */,
  true /* > */,
  true /* ?> */,
  true /* /> */,
  false /* </ */,
  false /* = */
} ;

//----------------------------------------------------------------------------------------------------------------------
//               INTERNAL PARSE LEXICAL TOKEN                                         
//----------------------------------------------------------------------------------------------------------------------

void C_Lexique_arxml_5F_scanner::internalParseLexicalToken (cTokenFor_arxml_5F_scanner & token) {
  bool loop = true ;
  token.mLexicalAttribute_tokenString.setLengthToZero () ;
  mTokenStartLocation = mCurrentLocation ;
  try{
    if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__3C__21__2D__2D_, 4, true)) {
      do {
        if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__26_amp_3B_, 5, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('&')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__26_lt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('<')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__26_gt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('>')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__26_quot_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\"')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__26_apos_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\'')) ;
        }else if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (',')) || testForInputUTF32CharRange (TO_UNICODE ('.'), TO_UNICODE (1114111))) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        }else if (notTestForInputUTF32String (kUnicodeString_arxml_5F_scanner__2D__2D__3E_, 3, gLexicalMessage_arxml_5F_scanner_incorrectCommentError COMMA_LINE_AND_SOURCE_FILE)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('-')) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      token.mTokenCode = kToken_comment ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__3F__3E_, 2, true)) {
      token.mTokenCode = kToken__3F__3E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__3C__3F_, 2, true)) {
      token.mTokenCode = kToken__3C__3F_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__3C__2F_, 2, true)) {
      token.mTokenCode = kToken__3C__2F_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__2F__3E_, 2, true)) {
      token.mTokenCode = kToken__2F__3E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__3E_, 1, true)) {
      token.mTokenCode = kToken__3E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__3D_, 1, true)) {
      token.mTokenCode = kToken__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__3C_, 1, true)) {
      token.mTokenCode = kToken__3C_ ;
      enterToken (token) ;
    }else if (testForCharWithFunction (isUnicodeLetter)) {
      do {
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        if (testForCharWithFunction (isUnicodeLetter) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32Char (TO_UNICODE ('-')) || testForInputUTF32Char (TO_UNICODE (':'))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      token.mTokenCode = kToken_name ;
      enterToken (token) ;
    }else if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
      do {
        if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__26_amp_3B_, 5, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('&')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__26_lt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('<')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__26_gt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('>')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__26_quot_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\"')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__26_apos_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\'')) ;
        }else if (notTestForInputUTF32String (kUnicodeString_arxml_5F_scanner__22_, 1, gLexicalMessage_arxml_5F_scanner_incorrectAttributeEnd COMMA_LINE_AND_SOURCE_FILE)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      token.mTokenCode = kToken_value ;
      enterToken (token) ;
    }else if (testForInputUTF32Char (TO_UNICODE ('\''))) {
      do {
        if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__26_amp_3B_, 5, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('&')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__26_lt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('<')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__26_gt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('>')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__26_quot_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\"')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxml_5F_scanner__26_apos_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\'')) ;
        }else if (notTestForInputUTF32String (kUnicodeString_arxml_5F_scanner__27_, 1, gLexicalMessage_arxml_5F_scanner_incorrectAttributeEnd COMMA_LINE_AND_SOURCE_FILE)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      token.mTokenCode = kToken_value ;
      enterToken (token) ;
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

bool C_Lexique_arxml_5F_scanner::parseLexicalToken (void) {
  cTokenFor_arxml_5F_scanner token ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
    if ((mMatchedTemplateDelimiterIndex >= 0)
     && (arxml_5F_scanner_kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndStringLength > 0)
     && (UNICODE_VALUE (mCurrentChar) != '\0')) {
      const bool foundEndDelimitor = testForInputUTF32String (arxml_5F_scanner_kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndString,
                                                              arxml_5F_scanner_kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndStringLength,
                                                              true) ;
      if (foundEndDelimitor) {
        mMatchedTemplateDelimiterIndex = -1 ;
      }
    }
    while ((mMatchedTemplateDelimiterIndex < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
      int32_t replacementIndex = 0 ;
      while (replacementIndex >= 0) {
        replacementIndex = findTemplateDelimiterIndex (arxml_5F_scanner_kTemplateReplacementArray, 6) ;
        if (replacementIndex >= 0) {
          if (arxml_5F_scanner_kTemplateReplacementArray [replacementIndex].mReplacementFunction == nullptr) {
            token.mTemplateStringBeforeToken << arxml_5F_scanner_kTemplateReplacementArray [replacementIndex].mEndString ;
          }else{
            C_String s ;
            while (notTestForInputUTF32String (arxml_5F_scanner_kTemplateReplacementArray [replacementIndex].mEndString,
                                               arxml_5F_scanner_kTemplateReplacementArray [replacementIndex].mEndStringLength,
                                               kEndOfSourceLexicalErrorMessage
                                               COMMA_HERE)) {
              s.appendUnicodeCharacter (previousChar () COMMA_HERE) ;
            }
            arxml_5F_scanner_kTemplateReplacementArray [replacementIndex].mReplacementFunction (*this, s, token.mTemplateStringBeforeToken) ;
          }
        }
      }
      mMatchedTemplateDelimiterIndex = findTemplateDelimiterIndex (arxml_5F_scanner_kTemplateDefinitionArray, 1) ;
      if (mMatchedTemplateDelimiterIndex < 0) {
        token.mTemplateStringBeforeToken.appendUnicodeCharacter (mCurrentChar COMMA_HERE) ;
        advance () ;
      }
    }
    if ((mMatchedTemplateDelimiterIndex >= 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
      internalParseLexicalToken (token) ;
    }
    if ((token.mTokenCode > 0) && arxml_5F_scanner_kEndOfScriptInTemplateArray [token.mTokenCode - 1]) {
      mMatchedTemplateDelimiterIndex = -1 ;
    }
  
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

void C_Lexique_arxml_5F_scanner::enterToken (cTokenFor_arxml_5F_scanner & ioToken) {
  cTokenFor_arxml_5F_scanner * ptr = nullptr ;
  macroMyNew (ptr, cTokenFor_arxml_5F_scanner ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
  // ptr->mIsOptional = ioToken.mIsOptional ;
  ptr->mStartLocation = mTokenStartLocation ;
  ptr->mEndLocation = mTokenEndLocation ;
  ptr->mTemplateStringBeforeToken = ioToken.mTemplateStringBeforeToken ;
  ioToken.mTemplateStringBeforeToken = "" ;
  ptr->mLexicalAttribute_tokenString = ioToken.mLexicalAttribute_tokenString ;
  enterTokenFromPointer (ptr) ;
}

//----------------------------------------------------------------------------------------------------------------------
//               A T T R I B U T E   A C C E S S                                                 
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_arxml_5F_scanner::attributeValue_tokenString (void) const {
  cTokenFor_arxml_5F_scanner * ptr = (cTokenFor_arxml_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_tokenString ;
}

//----------------------------------------------------------------------------------------------------------------------
//         A S S I G N    F R O M    A T T R I B U T E                                           
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_arxml_5F_scanner::synthetizedAttribute_tokenString (void) const {
  cTokenFor_arxml_5F_scanner * ptr = (cTokenFor_arxml_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_arxml_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_tokenString) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                         I N T R O S P E C T I O N                                             
//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist C_Lexique_arxml_5F_scanner::symbols (LOCATION_ARGS) {
  GALGAS_stringlist result = GALGAS_stringlist::constructor_emptyList (THERE) ;
  result.addAssign_operation (GALGAS_string ("comment") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("name") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("value") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<\?") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (">") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("\?>") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("/>") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("</") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("=") COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

static void getKeywordLists_arxml_5F_scanner (TC_UniqueArray <C_String> & ioList) {
  ioList.appendObject ("arxml_scanner:xmlDelimitorsList") ;
}

//----------------------------------------------------------------------------------------------------------------------

static void getKeywordsForIdentifier_arxml_5F_scanner (const C_String & inIdentifier,
                                                       bool & ioFound,
                                                       TC_UniqueArray <C_String> & ioList) {
  if (inIdentifier == "arxml_scanner:xmlDelimitorsList") {
    ioFound = true ;
    ioList.appendObject ("<") ;
    ioList.appendObject ("=") ;
    ioList.appendObject (">") ;
    ioList.appendObject ("/>") ;
    ioList.appendObject ("</") ;
    ioList.appendObject ("<\?") ;
    ioList.appendObject ("\?>") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static cLexiqueIntrospection lexiqueIntrospection_arxml_5F_scanner
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_arxml_5F_scanner, getKeywordsForIdentifier_arxml_5F_scanner) ;

//----------------------------------------------------------------------------------------------------------------------
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                           
//----------------------------------------------------------------------------------------------------------------------

uint32_t C_Lexique_arxml_5F_scanner::styleIndexForTerminal (const int32_t inTerminalIndex) const {
  static const uint32_t kTerminalSymbolStyles [11] = {0,
    4 /* arxml_scanner_1_comment */,
    2 /* arxml_scanner_1_name */,
    3 /* arxml_scanner_1_value */,
    1 /* arxml_scanner_1__3C_ */,
    1 /* arxml_scanner_1__3C__3F_ */,
    1 /* arxml_scanner_1__3E_ */,
    1 /* arxml_scanner_1__3F__3E_ */,
    1 /* arxml_scanner_1__2F__3E_ */,
    1 /* arxml_scanner_1__3C__2F_ */,
    1 /* arxml_scanner_1__3D_ */
  } ;
  return (inTerminalIndex >= 0) ? kTerminalSymbolStyles [inTerminalIndex] : 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                      
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_arxml_5F_scanner::styleNameForIndex (const uint32_t inStyleIndex) const {
  C_String result ;
  if (inStyleIndex < 6) {
    static const char * kStyleArray [6] = {
      "",
      "delimitersStyle",
      "nameStyle",
      "attributeValue",
      "commentStyle",
      "textStyle"
    } ;
    result = kStyleArray [inStyleIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_arxmlAttributeMap::cMapElement_arxmlAttributeMap (const GALGAS_lstring & inKey,
                                                              const GALGAS_lstring & in_value
                                                              COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_arxmlAttributeMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_arxmlAttributeMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_arxmlAttributeMap (mProperty_lkey, mProperty_value COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_arxmlAttributeMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mProperty_value.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_arxmlAttributeMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_arxmlAttributeMap * operand = (cMapElement_arxmlAttributeMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (operand->mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap::GALGAS_arxmlAttributeMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap::GALGAS_arxmlAttributeMap (const GALGAS_arxmlAttributeMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap & GALGAS_arxmlAttributeMap::operator = (const GALGAS_arxmlAttributeMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap GALGAS_arxmlAttributeMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_arxmlAttributeMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap GALGAS_arxmlAttributeMap::constructor_mapWithMapToOverride (const GALGAS_arxmlAttributeMap & inMapToOverride
                                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_arxmlAttributeMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap GALGAS_arxmlAttributeMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlAttributeMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlAttributeMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                    const GALGAS_lstring & inArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cMapElement_arxmlAttributeMap * p = nullptr ;
  macroMyNew (p, cMapElement_arxmlAttributeMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@arxmlAttributeMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap GALGAS_arxmlAttributeMap::add_operation (const GALGAS_arxmlAttributeMap & inOperand,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlAttributeMap result = *this ;
  cEnumerator_arxmlAttributeMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_value (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlAttributeMap::setter_insertKey (GALGAS_lstring inKey,
                                                 GALGAS_lstring inArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cMapElement_arxmlAttributeMap * p = nullptr ;
  macroMyNew (p, cMapElement_arxmlAttributeMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the '%K' attribute has been already declared" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_arxmlAttributeMap_searchKey = "the '%K' attribute is not declared" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlAttributeMap::method_searchKey (GALGAS_lstring inKey,
                                                 GALGAS_lstring & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  const cMapElement_arxmlAttributeMap * p = (const cMapElement_arxmlAttributeMap *) performSearch (inKey,
                                                                                                   inCompiler,
                                                                                                   kSearchErrorMessage_arxmlAttributeMap_searchKey
                                                                                                   COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_arxmlAttributeMap) ;
    outArgument0 = p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlAttributeMap::getter_valueForKey (const GALGAS_string & inKey,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_arxmlAttributeMap * p = (const cMapElement_arxmlAttributeMap *) attributes ;
  GALGAS_lstring result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_arxmlAttributeMap) ;
    result = p->mProperty_value ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlAttributeMap::setter_setValueForKey (GALGAS_lstring inAttributeValue,
                                                      GALGAS_string inKey,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_arxmlAttributeMap * p = (cMapElement_arxmlAttributeMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_arxmlAttributeMap) ;
    p->mProperty_value = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_arxmlAttributeMap * GALGAS_arxmlAttributeMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                             const GALGAS_string & inKey
                                                                                             COMMA_LOCATION_ARGS) {
  cMapElement_arxmlAttributeMap * result = (cMapElement_arxmlAttributeMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_arxmlAttributeMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_arxmlAttributeMap::cEnumerator_arxmlAttributeMap (const GALGAS_arxmlAttributeMap & inEnumeratedObject,
                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap_2D_element cEnumerator_arxmlAttributeMap::current (LOCATION_ARGS) const {
  const cMapElement_arxmlAttributeMap * p = (const cMapElement_arxmlAttributeMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_arxmlAttributeMap) ;
  return GALGAS_arxmlAttributeMap_2D_element (p->mProperty_lkey, p->mProperty_value) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_arxmlAttributeMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_arxmlAttributeMap::current_value (LOCATION_ARGS) const {
  const cMapElement_arxmlAttributeMap * p = (const cMapElement_arxmlAttributeMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_arxmlAttributeMap) ;
  return p->mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_arxmlAttributeMap::optional_searchKey (const GALGAS_string & inKey,
                                                   GALGAS_lstring & outArgument0) const {
  const cMapElement_arxmlAttributeMap * p = (const cMapElement_arxmlAttributeMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_arxmlAttributeMap) ;
    outArgument0 = p->mProperty_value ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlAttributeMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlAttributeMap ("arxmlAttributeMap",
                                          nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlAttributeMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlAttributeMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlAttributeMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlAttributeMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap GALGAS_arxmlAttributeMap::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_arxmlAttributeMap result ;
  const GALGAS_arxmlAttributeMap * p = (const GALGAS_arxmlAttributeMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_arxmlAttributeMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlAttributeMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlAttributeMap print'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_print (const GALGAS_arxmlAttributeMap inObject,
                            const GALGAS_uint /* constinArgument_indentation */,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_arxmlAttributeMap temp_0 = inObject ;
  cEnumerator_arxmlAttributeMap enumerator_1041 (temp_0, kENUMERATION_UP) ;
  const bool bool_1 = true ;
  if (enumerator_1041.hasCurrentObject () && bool_1) {
    inCompiler->printMessage (GALGAS_string (" ( ")  COMMA_SOURCE_FILE ("arxml_types.galgas", 43)) ;
    while (enumerator_1041.hasCurrentObject () && bool_1) {
      inCompiler->printMessage (enumerator_1041.current_lkey (HERE).readProperty_string ().add_operation (GALGAS_string (" = "), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 45)).add_operation (enumerator_1041.current_value (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 45))  COMMA_SOURCE_FILE ("arxml_types.galgas", 45)) ;
      enumerator_1041.gotoNextObject () ;
      if (enumerator_1041.hasCurrentObject () && bool_1) {
        inCompiler->printMessage (GALGAS_string (" , ")  COMMA_SOURCE_FILE ("arxml_types.galgas", 47)) ;
      }
    }
    inCompiler->printMessage (GALGAS_string (" )")  COMMA_SOURCE_FILE ("arxml_types.galgas", 49)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@arxmlNodeList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_arxmlNodeList : public cCollectionElement {
  public: GALGAS_arxmlNodeList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_arxmlNodeList (const GALGAS_arxmlNode & in_node
                                            COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_arxmlNodeList (const GALGAS_arxmlNodeList_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_arxmlNodeList::cCollectionElement_arxmlNodeList (const GALGAS_arxmlNode & in_node
                                                                    COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_node) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_arxmlNodeList::cCollectionElement_arxmlNodeList (const GALGAS_arxmlNodeList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_node) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_arxmlNodeList::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_arxmlNodeList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_arxmlNodeList (mObject.mProperty_node COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_arxmlNodeList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "node" ":" ;
  mObject.mProperty_node.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_arxmlNodeList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_arxmlNodeList * operand = (cCollectionElement_arxmlNodeList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_arxmlNodeList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList::GALGAS_arxmlNodeList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList::GALGAS_arxmlNodeList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList GALGAS_arxmlNodeList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlNodeList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList GALGAS_arxmlNodeList::constructor_listWithValue (const GALGAS_arxmlNode & inOperand0
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_arxmlNodeList result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlNodeList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_arxmlNodeList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlNodeList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                      const GALGAS_arxmlNode & in_node
                                                      COMMA_LOCATION_ARGS) {
  cCollectionElement_arxmlNodeList * p = nullptr ;
  macroMyNew (p, cCollectionElement_arxmlNodeList (in_node COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlNodeList::addAssign_operation (const GALGAS_arxmlNode & inOperand0
                                                COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_arxmlNodeList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlNodeList::setter_append (const GALGAS_arxmlNode inOperand0,
                                          C_Compiler * /* inCompiler */
                                          COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_arxmlNodeList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlNodeList::setter_insertAtIndex (const GALGAS_arxmlNode inOperand0,
                                                 const GALGAS_uint inInsertionIndex,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_arxmlNodeList (inOperand0 COMMA_THERE)) ;
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

void GALGAS_arxmlNodeList::setter_removeAtIndex (GALGAS_arxmlNode & outOperand0,
                                                 const GALGAS_uint inRemoveIndex,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_arxmlNodeList * p = (cCollectionElement_arxmlNodeList *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_arxmlNodeList) ;
        outOperand0 = p->mObject.mProperty_node ;
      }
    }else{
      outOperand0.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlNodeList::setter_popFirst (GALGAS_arxmlNode & outOperand0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlNodeList * p = (cCollectionElement_arxmlNodeList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlNodeList) ;
    outOperand0 = p->mObject.mProperty_node ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlNodeList::setter_popLast (GALGAS_arxmlNode & outOperand0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlNodeList * p = (cCollectionElement_arxmlNodeList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlNodeList) ;
    outOperand0 = p->mObject.mProperty_node ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlNodeList::method_first (GALGAS_arxmlNode & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlNodeList * p = (cCollectionElement_arxmlNodeList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlNodeList) ;
    outOperand0 = p->mObject.mProperty_node ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlNodeList::method_last (GALGAS_arxmlNode & outOperand0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlNodeList * p = (cCollectionElement_arxmlNodeList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlNodeList) ;
    outOperand0 = p->mObject.mProperty_node ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList GALGAS_arxmlNodeList::add_operation (const GALGAS_arxmlNodeList & inOperand,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_arxmlNodeList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList GALGAS_arxmlNodeList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlNodeList result = GALGAS_arxmlNodeList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList GALGAS_arxmlNodeList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlNodeList result = GALGAS_arxmlNodeList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList GALGAS_arxmlNodeList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlNodeList result = GALGAS_arxmlNodeList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlNodeList::plusAssign_operation (const GALGAS_arxmlNodeList inOperand,
                                                 C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlNodeList::setter_setNodeAtIndex (GALGAS_arxmlNode inOperand,
                                                  GALGAS_uint inIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_arxmlNodeList * p = (cCollectionElement_arxmlNodeList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_arxmlNodeList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_node = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNode GALGAS_arxmlNodeList::getter_nodeAtIndex (const GALGAS_uint & inIndex,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlNodeList * p = (cCollectionElement_arxmlNodeList *) attributes.ptr () ;
  GALGAS_arxmlNode result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_arxmlNodeList) ;
    result = p->mObject.mProperty_node ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_arxmlNodeList::cEnumerator_arxmlNodeList (const GALGAS_arxmlNodeList & inEnumeratedObject,
                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList_2D_element cEnumerator_arxmlNodeList::current (LOCATION_ARGS) const {
  const cCollectionElement_arxmlNodeList * p = (const cCollectionElement_arxmlNodeList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_arxmlNodeList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNode cEnumerator_arxmlNodeList::current_node (LOCATION_ARGS) const {
  const cCollectionElement_arxmlNodeList * p = (const cCollectionElement_arxmlNodeList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_arxmlNodeList) ;
  return p->mObject.mProperty_node ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlNodeList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlNodeList ("arxmlNodeList",
                                      nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlNodeList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlNodeList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlNodeList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlNodeList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList GALGAS_arxmlNodeList::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_arxmlNodeList result ;
  const GALGAS_arxmlNodeList * p = (const GALGAS_arxmlNodeList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_arxmlNodeList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlNodeList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------



typeComparisonResult GALGAS_arxmlNode::objectCompare (const GALGAS_arxmlNode & inOperand) const {
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

GALGAS_arxmlNode::GALGAS_arxmlNode (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNode::GALGAS_arxmlNode (const cPtr_arxmlNode * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlNode) ;
}
//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @arxmlNode class
//----------------------------------------------------------------------------------------------------------------------

cPtr_arxmlNode::cPtr_arxmlNode (LOCATION_ARGS) :
acPtr_class (THERE) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlNode generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlNode ("arxmlNode",
                                  nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlNode::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlNode ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlNode::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlNode (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNode GALGAS_arxmlNode::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_arxmlNode result ;
  const GALGAS_arxmlNode * p = (const GALGAS_arxmlNode *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_arxmlNode *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlNode", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlNodeList print'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_print (const GALGAS_arxmlNodeList inObject,
                            const GALGAS_uint constinArgument_indentation,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_arxmlNodeList temp_0 = inObject ;
  cEnumerator_arxmlNodeList enumerator_1395 (temp_0, kENUMERATION_UP) ;
  while (enumerator_1395.hasCurrentObject ()) {
    callExtensionMethod_print ((cPtr_arxmlNode *) enumerator_1395.current_node (HERE).ptr (), constinArgument_indentation.add_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 65)), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 65)) ;
    enumerator_1395.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlNodeList getElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_getElementsFromName (const GALGAS_arxmlNodeList inObject,
                                          const GALGAS_string constinArgument_nodeName,
                                          GALGAS_arxmlElementList & ioArgument_nodeList,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_arxmlNodeList temp_0 = inObject ;
  cEnumerator_arxmlNodeList enumerator_1567 (temp_0, kENUMERATION_UP) ;
  while (enumerator_1567.hasCurrentObject ()) {
    callExtensionMethod_getElementsFromName ((cPtr_arxmlNode *) enumerator_1567.current_node (HERE).ptr (), constinArgument_nodeName, ioArgument_nodeList, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 74)) ;
    enumerator_1567.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlNodeList getSubElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_getSubElementsFromName (const GALGAS_arxmlNodeList inObject,
                                             const GALGAS_string constinArgument_nodeName,
                                             GALGAS_arxmlElementList & ioArgument_nodeList,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_arxmlNodeList temp_0 = inObject ;
  cEnumerator_arxmlNodeList enumerator_1760 (temp_0, kENUMERATION_UP) ;
  while (enumerator_1760.hasCurrentObject ()) {
    callExtensionMethod_getSubElementsFromName ((cPtr_arxmlNode *) enumerator_1760.current_node (HERE).ptr (), constinArgument_nodeName, ioArgument_nodeList, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 83)) ;
    enumerator_1760.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlNodeList getProperty'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_getProperty (const GALGAS_arxmlNodeList inObject,
                                  const GALGAS_string constinArgument_nodeName,
                                  GALGAS_lstring & ioArgument_value,
                                  GALGAS_bool & ioArgument_found,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_arxmlNodeList temp_0 = inObject ;
  cEnumerator_arxmlNodeList enumerator_1949 (temp_0, kENUMERATION_UP) ;
  bool bool_1 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 93)).isValidAndTrue () ;
  if (enumerator_1949.hasCurrentObject () && bool_1) {
    while (enumerator_1949.hasCurrentObject () && bool_1) {
      callExtensionMethod_getProperty ((cPtr_arxmlNode *) enumerator_1949.current_node (HERE).ptr (), constinArgument_nodeName, ioArgument_value, ioArgument_found, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 95)) ;
      enumerator_1949.gotoNextObject () ;
      if (enumerator_1949.hasCurrentObject ()) {
        bool_1 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 93)).isValidAndTrue () ;
      }
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@arxmlElementList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_arxmlElementList : public cCollectionElement {
  public: GALGAS_arxmlElementList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_arxmlElementList (const GALGAS_arxmlElementNode & in_node
                                               COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_arxmlElementList (const GALGAS_arxmlElementList_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_arxmlElementList::cCollectionElement_arxmlElementList (const GALGAS_arxmlElementNode & in_node
                                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_node) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_arxmlElementList::cCollectionElement_arxmlElementList (const GALGAS_arxmlElementList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_node) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_arxmlElementList::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_arxmlElementList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_arxmlElementList (mObject.mProperty_node COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_arxmlElementList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "node" ":" ;
  mObject.mProperty_node.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_arxmlElementList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_arxmlElementList * operand = (cCollectionElement_arxmlElementList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_arxmlElementList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementList::GALGAS_arxmlElementList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementList::GALGAS_arxmlElementList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementList GALGAS_arxmlElementList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlElementList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementList GALGAS_arxmlElementList::constructor_listWithValue (const GALGAS_arxmlElementNode & inOperand0
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementList result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlElementList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_arxmlElementList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                         const GALGAS_arxmlElementNode & in_node
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_arxmlElementList * p = nullptr ;
  macroMyNew (p, cCollectionElement_arxmlElementList (in_node COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementList::addAssign_operation (const GALGAS_arxmlElementNode & inOperand0
                                                   COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_arxmlElementList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementList::setter_append (const GALGAS_arxmlElementNode inOperand0,
                                             C_Compiler * /* inCompiler */
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_arxmlElementList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementList::setter_insertAtIndex (const GALGAS_arxmlElementNode inOperand0,
                                                    const GALGAS_uint inInsertionIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_arxmlElementList (inOperand0 COMMA_THERE)) ;
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

void GALGAS_arxmlElementList::setter_removeAtIndex (GALGAS_arxmlElementNode & outOperand0,
                                                    const GALGAS_uint inRemoveIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_arxmlElementList * p = (cCollectionElement_arxmlElementList *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_arxmlElementList) ;
        outOperand0 = p->mObject.mProperty_node ;
      }
    }else{
      outOperand0.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementList::setter_popFirst (GALGAS_arxmlElementNode & outOperand0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlElementList * p = (cCollectionElement_arxmlElementList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlElementList) ;
    outOperand0 = p->mObject.mProperty_node ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementList::setter_popLast (GALGAS_arxmlElementNode & outOperand0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlElementList * p = (cCollectionElement_arxmlElementList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlElementList) ;
    outOperand0 = p->mObject.mProperty_node ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementList::method_first (GALGAS_arxmlElementNode & outOperand0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlElementList * p = (cCollectionElement_arxmlElementList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlElementList) ;
    outOperand0 = p->mObject.mProperty_node ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementList::method_last (GALGAS_arxmlElementNode & outOperand0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlElementList * p = (cCollectionElement_arxmlElementList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlElementList) ;
    outOperand0 = p->mObject.mProperty_node ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementList GALGAS_arxmlElementList::add_operation (const GALGAS_arxmlElementList & inOperand,
                                                                C_Compiler * /* inCompiler */
                                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_arxmlElementList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementList GALGAS_arxmlElementList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlElementList result = GALGAS_arxmlElementList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementList GALGAS_arxmlElementList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlElementList result = GALGAS_arxmlElementList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementList GALGAS_arxmlElementList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlElementList result = GALGAS_arxmlElementList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementList::plusAssign_operation (const GALGAS_arxmlElementList inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementList::setter_setNodeAtIndex (GALGAS_arxmlElementNode inOperand,
                                                     GALGAS_uint inIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement_arxmlElementList * p = (cCollectionElement_arxmlElementList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_arxmlElementList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_node = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementNode GALGAS_arxmlElementList::getter_nodeAtIndex (const GALGAS_uint & inIndex,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlElementList * p = (cCollectionElement_arxmlElementList *) attributes.ptr () ;
  GALGAS_arxmlElementNode result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_arxmlElementList) ;
    result = p->mObject.mProperty_node ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_arxmlElementList::cEnumerator_arxmlElementList (const GALGAS_arxmlElementList & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementList_2D_element cEnumerator_arxmlElementList::current (LOCATION_ARGS) const {
  const cCollectionElement_arxmlElementList * p = (const cCollectionElement_arxmlElementList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_arxmlElementList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementNode cEnumerator_arxmlElementList::current_node (LOCATION_ARGS) const {
  const cCollectionElement_arxmlElementList * p = (const cCollectionElement_arxmlElementList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_arxmlElementList) ;
  return p->mObject.mProperty_node ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlElementList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlElementList ("arxmlElementList",
                                         nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlElementList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlElementList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlElementList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementList GALGAS_arxmlElementList::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementList result ;
  const GALGAS_arxmlElementList * p = (const GALGAS_arxmlElementList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_arxmlElementList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlElementList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementList getElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_getElementsFromName (const GALGAS_arxmlElementList inObject,
                                          const GALGAS_string constinArgument_nodeName,
                                          GALGAS_arxmlElementList & ioArgument_nodeList,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_arxmlElementList temp_0 = inObject ;
  cEnumerator_arxmlElementList enumerator_2314 (temp_0, kENUMERATION_UP) ;
  while (enumerator_2314.hasCurrentObject ()) {
    callExtensionMethod_getElementsFromName ((cPtr_arxmlElementNode *) enumerator_2314.current_node (HERE).ptr (), constinArgument_nodeName, ioArgument_nodeList, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 112)) ;
    enumerator_2314.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementList getSubElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_getSubElementsFromName (const GALGAS_arxmlElementList inObject,
                                             const GALGAS_string constinArgument_nodeName,
                                             GALGAS_arxmlElementList & ioArgument_nodeList,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_arxmlElementList temp_0 = inObject ;
  cEnumerator_arxmlElementList enumerator_2510 (temp_0, kENUMERATION_UP) ;
  while (enumerator_2510.hasCurrentObject ()) {
    callExtensionMethod_getSubElementsFromName ((cPtr_arxmlElementNode *) enumerator_2510.current_node (HERE).ptr (), constinArgument_nodeName, ioArgument_nodeList, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 121)) ;
    enumerator_2510.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementList getProperty'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_getProperty (const GALGAS_arxmlElementList inObject,
                                  const GALGAS_string constinArgument_nodeName,
                                  GALGAS_lstring & ioArgument_value,
                                  GALGAS_bool & ioArgument_found,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_arxmlElementList temp_0 = inObject ;
  cEnumerator_arxmlElementList enumerator_2702 (temp_0, kENUMERATION_UP) ;
  bool bool_1 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 131)).isValidAndTrue () ;
  if (enumerator_2702.hasCurrentObject () && bool_1) {
    while (enumerator_2702.hasCurrentObject () && bool_1) {
      callExtensionMethod_getProperty ((cPtr_arxmlElementNode *) enumerator_2702.current_node (HERE).ptr (), constinArgument_nodeName, ioArgument_value, ioArgument_found, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 133)) ;
      enumerator_2702.gotoNextObject () ;
      if (enumerator_2702.hasCurrentObject ()) {
        bool_1 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 131)).isValidAndTrue () ;
      }
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension method '@arxmlNode print'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_print (cPtr_arxmlNode * inObject,
                                const GALGAS_uint constin_indentation,
                                C_Compiler * inCompiler
                                COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlNode) ;
    inObject->method_print (constin_indentation, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension method '@arxmlNode getElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getElementsFromName (cPtr_arxmlNode * inObject,
                                              const GALGAS_string constin_nodeName,
                                              GALGAS_arxmlElementList & io_nodeList,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlNode) ;
    inObject->method_getElementsFromName (constin_nodeName, io_nodeList, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension method '@arxmlNode getSubElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getSubElementsFromName (cPtr_arxmlNode * inObject,
                                                 const GALGAS_string constin_nodeName,
                                                 GALGAS_arxmlElementList & io_nodeList,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlNode) ;
    inObject->method_getSubElementsFromName (constin_nodeName, io_nodeList, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension method '@arxmlNode getProperty'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getProperty (cPtr_arxmlNode * inObject,
                                      const GALGAS_string constin_nodeName,
                                      GALGAS_lstring & io_value,
                                      GALGAS_bool & io_found,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlNode) ;
    inObject->method_getProperty (constin_nodeName, io_value, io_found, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_arxmlDocument::dynamicObjectCompare (const acPtr_class * /* inOperandPtr */) const {
  return kOperandEqual ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_arxmlDocument::objectCompare (const GALGAS_arxmlDocument & inOperand) const {
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

GALGAS_arxmlDocument::GALGAS_arxmlDocument (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlDocument GALGAS_arxmlDocument::constructor_default (LOCATION_ARGS) {
  return GALGAS_arxmlDocument::constructor_new (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlDocument::GALGAS_arxmlDocument (const cPtr_arxmlDocument * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlDocument) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlDocument GALGAS_arxmlDocument::constructor_new (LOCATION_ARGS) {
  GALGAS_arxmlDocument result ;
  macroMyNew (result.mObjectPtr, cPtr_arxmlDocument (THERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @arxmlDocument class
//----------------------------------------------------------------------------------------------------------------------

cPtr_arxmlDocument::cPtr_arxmlDocument (LOCATION_ARGS) :
acPtr_class (THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_arxmlDocument::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlDocument ;
}

void cPtr_arxmlDocument::description (C_String & ioString,
                                      const int32_t /* inIndentation */) const {
  ioString << "[@arxmlDocument]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_arxmlDocument::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_arxmlDocument (THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlDocument generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlDocument ("arxmlDocument",
                                      nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlDocument::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlDocument ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlDocument::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlDocument (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlDocument GALGAS_arxmlDocument::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_arxmlDocument result ;
  const GALGAS_arxmlDocument * p = (const GALGAS_arxmlDocument *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_arxmlDocument *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlDocument", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_arxmlElementValueMap::cMapElement_arxmlElementValueMap (const GALGAS_lstring & inKey,
                                                                    const GALGAS_arxmlElementValueList & in_values
                                                                    COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_values (in_values) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_arxmlElementValueMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_arxmlElementValueMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_arxmlElementValueMap (mProperty_lkey, mProperty_values COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_arxmlElementValueMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "values" ":" ;
  mProperty_values.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_arxmlElementValueMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_arxmlElementValueMap * operand = (cMapElement_arxmlElementValueMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_values.objectCompare (operand->mProperty_values) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap::GALGAS_arxmlElementValueMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap::GALGAS_arxmlElementValueMap (const GALGAS_arxmlElementValueMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap & GALGAS_arxmlElementValueMap::operator = (const GALGAS_arxmlElementValueMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap GALGAS_arxmlElementValueMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_arxmlElementValueMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap GALGAS_arxmlElementValueMap::constructor_mapWithMapToOverride (const GALGAS_arxmlElementValueMap & inMapToOverride
                                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementValueMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap GALGAS_arxmlElementValueMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlElementValueMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                       const GALGAS_arxmlElementValueList & inArgument0,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cMapElement_arxmlElementValueMap * p = nullptr ;
  macroMyNew (p, cMapElement_arxmlElementValueMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@arxmlElementValueMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap GALGAS_arxmlElementValueMap::add_operation (const GALGAS_arxmlElementValueMap & inOperand,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlElementValueMap result = *this ;
  cEnumerator_arxmlElementValueMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_values (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueMap::setter_insertKey (GALGAS_lstring inKey,
                                                    GALGAS_arxmlElementValueList inArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cMapElement_arxmlElementValueMap * p = nullptr ;
  macroMyNew (p, cMapElement_arxmlElementValueMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the '%K' element has been already declared" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_arxmlElementValueMap_searchKey = "the '%K' element is not declared" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueMap::method_searchKey (GALGAS_lstring inKey,
                                                    GALGAS_arxmlElementValueList & outArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  const cMapElement_arxmlElementValueMap * p = (const cMapElement_arxmlElementValueMap *) performSearch (inKey,
                                                                                                         inCompiler,
                                                                                                         kSearchErrorMessage_arxmlElementValueMap_searchKey
                                                                                                         COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_arxmlElementValueMap) ;
    outArgument0 = p->mProperty_values ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueMap::setter_removeKey (GALGAS_lstring inKey,
                                                    GALGAS_arxmlElementValueList & outArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "the '%K' element does not exists" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_arxmlElementValueMap * p = (cMapElement_arxmlElementValueMap *) attributes.ptr () ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_arxmlElementValueMap) ;
    outArgument0 = p->mProperty_values ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList GALGAS_arxmlElementValueMap::getter_valuesForKey (const GALGAS_string & inKey,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_arxmlElementValueMap * p = (const cMapElement_arxmlElementValueMap *) attributes ;
  GALGAS_arxmlElementValueList result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_arxmlElementValueMap) ;
    result = p->mProperty_values ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueMap::setter_setValuesForKey (GALGAS_arxmlElementValueList inAttributeValue,
                                                          GALGAS_string inKey,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_arxmlElementValueMap * p = (cMapElement_arxmlElementValueMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_arxmlElementValueMap) ;
    p->mProperty_values = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_arxmlElementValueMap * GALGAS_arxmlElementValueMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                                   const GALGAS_string & inKey
                                                                                                   COMMA_LOCATION_ARGS) {
  cMapElement_arxmlElementValueMap * result = (cMapElement_arxmlElementValueMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_arxmlElementValueMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_arxmlElementValueMap::cEnumerator_arxmlElementValueMap (const GALGAS_arxmlElementValueMap & inEnumeratedObject,
                                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap_2D_element cEnumerator_arxmlElementValueMap::current (LOCATION_ARGS) const {
  const cMapElement_arxmlElementValueMap * p = (const cMapElement_arxmlElementValueMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_arxmlElementValueMap) ;
  return GALGAS_arxmlElementValueMap_2D_element (p->mProperty_lkey, p->mProperty_values) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_arxmlElementValueMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList cEnumerator_arxmlElementValueMap::current_values (LOCATION_ARGS) const {
  const cMapElement_arxmlElementValueMap * p = (const cMapElement_arxmlElementValueMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_arxmlElementValueMap) ;
  return p->mProperty_values ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_arxmlElementValueMap::optional_searchKey (const GALGAS_string & inKey,
                                                      GALGAS_arxmlElementValueList & outArgument0) const {
  const cMapElement_arxmlElementValueMap * p = (const cMapElement_arxmlElementValueMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_arxmlElementValueMap) ;
    outArgument0 = p->mProperty_values ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlElementValueMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlElementValueMap ("arxmlElementValueMap",
                                             nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlElementValueMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementValueMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlElementValueMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlElementValueMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap GALGAS_arxmlElementValueMap::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementValueMap result ;
  const GALGAS_arxmlElementValueMap * p = (const GALGAS_arxmlElementValueMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_arxmlElementValueMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlElementValueMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@arxmlElementValueList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_arxmlElementValueList : public cCollectionElement {
  public: GALGAS_arxmlElementValueList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_arxmlElementValueList (const GALGAS_arxmlElementValue & in_value
                                                    COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_arxmlElementValueList (const GALGAS_arxmlElementValueList_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_arxmlElementValueList::cCollectionElement_arxmlElementValueList (const GALGAS_arxmlElementValue & in_value
                                                                                    COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_arxmlElementValueList::cCollectionElement_arxmlElementValueList (const GALGAS_arxmlElementValueList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_value) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_arxmlElementValueList::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_arxmlElementValueList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_arxmlElementValueList (mObject.mProperty_value COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_arxmlElementValueList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mProperty_value.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_arxmlElementValueList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_arxmlElementValueList * operand = (cCollectionElement_arxmlElementValueList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_arxmlElementValueList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList::GALGAS_arxmlElementValueList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList::GALGAS_arxmlElementValueList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList GALGAS_arxmlElementValueList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlElementValueList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList GALGAS_arxmlElementValueList::constructor_listWithValue (const GALGAS_arxmlElementValue & inOperand0
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlElementValueList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_arxmlElementValueList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                              const GALGAS_arxmlElementValue & in_value
                                                              COMMA_LOCATION_ARGS) {
  cCollectionElement_arxmlElementValueList * p = nullptr ;
  macroMyNew (p, cCollectionElement_arxmlElementValueList (in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::addAssign_operation (const GALGAS_arxmlElementValue & inOperand0
                                                        COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_arxmlElementValueList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::setter_append (const GALGAS_arxmlElementValue inOperand0,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_arxmlElementValueList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::setter_insertAtIndex (const GALGAS_arxmlElementValue inOperand0,
                                                         const GALGAS_uint inInsertionIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_arxmlElementValueList (inOperand0 COMMA_THERE)) ;
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

void GALGAS_arxmlElementValueList::setter_removeAtIndex (GALGAS_arxmlElementValue & outOperand0,
                                                         const GALGAS_uint inRemoveIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_arxmlElementValueList * p = (cCollectionElement_arxmlElementValueList *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
        outOperand0 = p->mObject.mProperty_value ;
      }
    }else{
      outOperand0.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::setter_popFirst (GALGAS_arxmlElementValue & outOperand0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlElementValueList * p = (cCollectionElement_arxmlElementValueList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
    outOperand0 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::setter_popLast (GALGAS_arxmlElementValue & outOperand0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlElementValueList * p = (cCollectionElement_arxmlElementValueList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
    outOperand0 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::method_first (GALGAS_arxmlElementValue & outOperand0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlElementValueList * p = (cCollectionElement_arxmlElementValueList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
    outOperand0 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::method_last (GALGAS_arxmlElementValue & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlElementValueList * p = (cCollectionElement_arxmlElementValueList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
    outOperand0 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList GALGAS_arxmlElementValueList::add_operation (const GALGAS_arxmlElementValueList & inOperand,
                                                                          C_Compiler * /* inCompiler */
                                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_arxmlElementValueList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList GALGAS_arxmlElementValueList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlElementValueList result = GALGAS_arxmlElementValueList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList GALGAS_arxmlElementValueList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlElementValueList result = GALGAS_arxmlElementValueList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList GALGAS_arxmlElementValueList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlElementValueList result = GALGAS_arxmlElementValueList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::plusAssign_operation (const GALGAS_arxmlElementValueList inOperand,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::setter_setValueAtIndex (GALGAS_arxmlElementValue inOperand,
                                                           GALGAS_uint inIndex,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement_arxmlElementValueList * p = (cCollectionElement_arxmlElementValueList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_value = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValue GALGAS_arxmlElementValueList::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlElementValueList * p = (cCollectionElement_arxmlElementValueList *) attributes.ptr () ;
  GALGAS_arxmlElementValue result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
    result = p->mObject.mProperty_value ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_arxmlElementValueList::cEnumerator_arxmlElementValueList (const GALGAS_arxmlElementValueList & inEnumeratedObject,
                                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList_2D_element cEnumerator_arxmlElementValueList::current (LOCATION_ARGS) const {
  const cCollectionElement_arxmlElementValueList * p = (const cCollectionElement_arxmlElementValueList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValue cEnumerator_arxmlElementValueList::current_value (LOCATION_ARGS) const {
  const cCollectionElement_arxmlElementValueList * p = (const cCollectionElement_arxmlElementValueList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
  return p->mObject.mProperty_value ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlElementValueList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlElementValueList ("arxmlElementValueList",
                                              nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlElementValueList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementValueList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlElementValueList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlElementValueList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList GALGAS_arxmlElementValueList::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList result ;
  const GALGAS_arxmlElementValueList * p = (const GALGAS_arxmlElementValueList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_arxmlElementValueList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlElementValueList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
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

cTokenFor_arxmlmetaparser_5F_scanner::cTokenFor_arxmlmetaparser_5F_scanner (void) :
mLexicalAttribute_tokenString () {
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique_arxmlmetaparser_5F_scanner::C_Lexique_arxmlmetaparser_5F_scanner (C_Compiler * inCallerCompiler,
                                                                            const C_String & inSourceFileName
                                                                            COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceFileName COMMA_THERE),
mMatchedTemplateDelimiterIndex (-1) {
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique_arxmlmetaparser_5F_scanner::C_Lexique_arxmlmetaparser_5F_scanner (C_Compiler * inCallerCompiler,
                                                                            const C_String & inSourceString,
                                                                            const C_String & inStringForError
                                                                            COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE),
mMatchedTemplateDelimiterIndex (-1) {
}

//----------------------------------------------------------------------------------------------------------------------
//                        Lexical error message list                                             
//----------------------------------------------------------------------------------------------------------------------

static const char * gLexicalMessage_arxmlmetaparser_5F_scanner_incorrectAttributeEnd = "attribute value should be enclosed between apostrophes (') or quotation marks (\")" ;

static const char * gLexicalMessage_arxmlmetaparser_5F_scanner_incorrectCommentError = "incorrect XML comment" ;

//----------------------------------------------------------------------------------------------------------------------
//                getMessageForTerminal                                                          
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_arxmlmetaparser_5F_scanner::getMessageForTerminal (const int32_t inTerminalIndex) const {
  C_String result = "<unknown>" ;
  if ((inTerminalIndex >= 0) && (inTerminalIndex < 77)) {
    static const char * syntaxErrorMessageArray [77] = {kEndOfSourceLexicalErrorMessage,
        "a comment",
        "a name",
        "an attribute value",
        "an identifier",
        "the '<' delimitor",
        "the '<xsd:' delimitor",
        "the '</xsd:' delimitor",
        "the '<\?xml' delimitor",
        "the '>' delimitor",
        "the '\?>' delimitor",
        "the '/>' delimitor",
        "the '</' delimitor",
        "the '=' delimitor",
        "the 'group' keyword",
        "the 'annotation' keyword",
        "the 'appinfo' keyword",
        "the 'attribute' keyword",
        "the 'attributeGroup' keyword",
        "the 'choice' keyword",
        "the 'complexType' keyword",
        "the 'documentation' keyword",
        "the 'element' keyword",
        "the 'enumeration' keyword",
        "the 'extension' keyword",
        "the 'import' keyword",
        "the 'maxLength' keyword",
        "the 'pattern' keyword",
        "the 'restriction' keyword",
        "the 'schema' keyword",
        "the 'sequence' keyword",
        "the 'simpleContent' keyword",
        "the 'simpleType' keyword",
        "the 'whiteSpace' keyword",
        "the 'abstract' keyword",
        "the 'attributeFormDefault' keyword",
        "the 'attributeRef' keyword",
        "the 'base' keyword",
        "the 'category' keyword",
        "the 'CATEGORY' keyword",
        "the 'color' keyword",
        "the 'customType' keyword",
        "the 'elementFormDefault' keyword",
        "the 'encoding' keyword",
        "the 'enforceMinMultiplicity' keyword",
        "the 'globalElement' keyword",
        "the 'id' keyword",
        "the 'latestBindingTime' keyword",
        "the 'maxOccurs' keyword",
        "the 'minOccurs' keyword",
        "the 'mixed' keyword",
        "the 'name' keyword",
        "the 'namePlural' keyword",
        "the 'namespace' keyword",
        "the 'noteType' keyword",
        "the 'nsPrefix' keyword",
        "the 'qualifiedName' keyword",
        "the 'recommendedPackage' keyword",
        "the 'ref' keyword",
        "the 'roleElement' keyword",
        "the 'roleWrapperElement' keyword",
        "the 'schemaLocation' keyword",
        "the 'sequenceOffset' keyword",
        "the 'source' keyword",
        "the 'Splitkey' keyword",
        "the 'Status' keyword",
        "the 'StatusRevisionBegin' keyword",
        "the 'targetNamespace' keyword",
        "the 'type' keyword",
        "the 'typeElement' keyword",
        "the 'typeWrapperElement' keyword",
        "the 'use' keyword",
        "the 'value' keyword",
        "the 'version' keyword",
        "the 'xmlns:AR' keyword",
        "the 'xmlns:xsd' keyword",
        "the 'TODO' keyword"
    } ;
    result = syntaxErrorMessageArray [inTerminalIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                      U N I C O D E    S T R I N G S                                           
//----------------------------------------------------------------------------------------------------------------------

//--- Unicode string for '$_22_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__22_ [] = {
  TO_UNICODE ('\"'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__26_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26__23_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__26__23_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('#'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_amp_3B_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__26_amp_3B_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('a'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_apos_3B_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__26_apos_3B_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('a'),
  TO_UNICODE ('p'),
  TO_UNICODE ('o'),
  TO_UNICODE ('s'),
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_gt_3B_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__26_gt_3B_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('g'),
  TO_UNICODE ('t'),
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_lt_3B_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__26_lt_3B_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('l'),
  TO_UNICODE ('t'),
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_quot_3B_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__26_quot_3B_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('q'),
  TO_UNICODE ('u'),
  TO_UNICODE ('o'),
  TO_UNICODE ('t'),
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_27_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__27_ [] = {
  TO_UNICODE ('\''),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D__2D__3E_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__2D__2D__3E_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE ('-'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2F__3E_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__2F__3E_ [] = {
  TO_UNICODE ('/'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3B_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3B_ [] = {
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3C_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__21__2D__2D_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3C__21__2D__2D_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('!'),
  TO_UNICODE ('-'),
  TO_UNICODE ('-'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__2F_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3C__2F_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('/'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__2F_xsd_3A_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3C__2F_xsd_3A_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('/'),
  TO_UNICODE ('x'),
  TO_UNICODE ('s'),
  TO_UNICODE ('d'),
  TO_UNICODE (':'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__3F_xml$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3C__3F_xml [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('\?'),
  TO_UNICODE ('x'),
  TO_UNICODE ('m'),
  TO_UNICODE ('l'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C_xsd_3A_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3C_xsd_3A_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('x'),
  TO_UNICODE ('s'),
  TO_UNICODE ('d'),
  TO_UNICODE (':'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3D_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3D_ [] = {
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3E_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3F__3E_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3F__3E_ [] = {
  TO_UNICODE ('\?'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$CATEGORY$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_CATEGORY [] = {
  TO_UNICODE ('C'),
  TO_UNICODE ('A'),
  TO_UNICODE ('T'),
  TO_UNICODE ('E'),
  TO_UNICODE ('G'),
  TO_UNICODE ('O'),
  TO_UNICODE ('R'),
  TO_UNICODE ('Y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$Splitkey$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_Splitkey [] = {
  TO_UNICODE ('S'),
  TO_UNICODE ('p'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('k'),
  TO_UNICODE ('e'),
  TO_UNICODE ('y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$Status$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_Status [] = {
  TO_UNICODE ('S'),
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('u'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$StatusRevisionBegin$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_StatusRevisionBegin [] = {
  TO_UNICODE ('S'),
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('u'),
  TO_UNICODE ('s'),
  TO_UNICODE ('R'),
  TO_UNICODE ('e'),
  TO_UNICODE ('v'),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE ('B'),
  TO_UNICODE ('e'),
  TO_UNICODE ('g'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$TODO$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_TODO [] = {
  TO_UNICODE ('T'),
  TO_UNICODE ('O'),
  TO_UNICODE ('D'),
  TO_UNICODE ('O'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$abstract$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_abstract [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('b'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('a'),
  TO_UNICODE ('c'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$annotation$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_annotation [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('n'),
  TO_UNICODE ('n'),
  TO_UNICODE ('o'),
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$appinfo$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_appinfo [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('p'),
  TO_UNICODE ('p'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('f'),
  TO_UNICODE ('o'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$attribute$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_attribute [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('b'),
  TO_UNICODE ('u'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$attributeFormDefault$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_attributeFormDefault [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('b'),
  TO_UNICODE ('u'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('F'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('m'),
  TO_UNICODE ('D'),
  TO_UNICODE ('e'),
  TO_UNICODE ('f'),
  TO_UNICODE ('a'),
  TO_UNICODE ('u'),
  TO_UNICODE ('l'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$attributeGroup$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_attributeGroup [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('b'),
  TO_UNICODE ('u'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('G'),
  TO_UNICODE ('r'),
  TO_UNICODE ('o'),
  TO_UNICODE ('u'),
  TO_UNICODE ('p'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$attributeRef$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_attributeRef [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('b'),
  TO_UNICODE ('u'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('R'),
  TO_UNICODE ('e'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$base$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_base [] = {
  TO_UNICODE ('b'),
  TO_UNICODE ('a'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$category$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_category [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('g'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$choice$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_choice [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('h'),
  TO_UNICODE ('o'),
  TO_UNICODE ('i'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$color$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_color [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('l'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$complexType$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_complexType [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('x'),
  TO_UNICODE ('T'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$customType$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_customType [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('u'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('o'),
  TO_UNICODE ('m'),
  TO_UNICODE ('T'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$documentation$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_documentation [] = {
  TO_UNICODE ('d'),
  TO_UNICODE ('o'),
  TO_UNICODE ('c'),
  TO_UNICODE ('u'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$element$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_element [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$elementFormDefault$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_elementFormDefault [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE ('F'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('m'),
  TO_UNICODE ('D'),
  TO_UNICODE ('e'),
  TO_UNICODE ('f'),
  TO_UNICODE ('a'),
  TO_UNICODE ('u'),
  TO_UNICODE ('l'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$encoding$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_encoding [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('d'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('g'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$enforceMinMultiplicity$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_enforceMinMultiplicity [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('f'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE ('M'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('M'),
  TO_UNICODE ('u'),
  TO_UNICODE ('l'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('p'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('c'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$enumeration$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_enumeration [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('u'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$extension$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_extension [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('x'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('s'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$globalElement$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_globalElement [] = {
  TO_UNICODE ('g'),
  TO_UNICODE ('l'),
  TO_UNICODE ('o'),
  TO_UNICODE ('b'),
  TO_UNICODE ('a'),
  TO_UNICODE ('l'),
  TO_UNICODE ('E'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$group$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_group [] = {
  TO_UNICODE ('g'),
  TO_UNICODE ('r'),
  TO_UNICODE ('o'),
  TO_UNICODE ('u'),
  TO_UNICODE ('p'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$id$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_id [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$import$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_import [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$latestBindingTime$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_latestBindingTime [] = {
  TO_UNICODE ('l'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('B'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('d'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('g'),
  TO_UNICODE ('T'),
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$maxLength$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_maxLength [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('a'),
  TO_UNICODE ('x'),
  TO_UNICODE ('L'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('g'),
  TO_UNICODE ('t'),
  TO_UNICODE ('h'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$maxOccurs$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_maxOccurs [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('a'),
  TO_UNICODE ('x'),
  TO_UNICODE ('O'),
  TO_UNICODE ('c'),
  TO_UNICODE ('c'),
  TO_UNICODE ('u'),
  TO_UNICODE ('r'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$minOccurs$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_minOccurs [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('O'),
  TO_UNICODE ('c'),
  TO_UNICODE ('c'),
  TO_UNICODE ('u'),
  TO_UNICODE ('r'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$mixed$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_mixed [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('i'),
  TO_UNICODE ('x'),
  TO_UNICODE ('e'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$name$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_name [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('a'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$namePlural$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_namePlural [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('a'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('P'),
  TO_UNICODE ('l'),
  TO_UNICODE ('u'),
  TO_UNICODE ('r'),
  TO_UNICODE ('a'),
  TO_UNICODE ('l'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$namespace$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_namespace [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('a'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE ('p'),
  TO_UNICODE ('a'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$noteType$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_noteType [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('o'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('T'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$nsPrefix$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_nsPrefix [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('s'),
  TO_UNICODE ('P'),
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('f'),
  TO_UNICODE ('i'),
  TO_UNICODE ('x'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$pattern$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_pattern [] = {
  TO_UNICODE ('p'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$qualifiedName$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_qualifiedName [] = {
  TO_UNICODE ('q'),
  TO_UNICODE ('u'),
  TO_UNICODE ('a'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('f'),
  TO_UNICODE ('i'),
  TO_UNICODE ('e'),
  TO_UNICODE ('d'),
  TO_UNICODE ('N'),
  TO_UNICODE ('a'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$recommendedPackage$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_recommendedPackage [] = {
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('m'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE ('d'),
  TO_UNICODE ('P'),
  TO_UNICODE ('a'),
  TO_UNICODE ('c'),
  TO_UNICODE ('k'),
  TO_UNICODE ('a'),
  TO_UNICODE ('g'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$ref$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_ref [] = {
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$restriction$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_restriction [] = {
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('c'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$roleElement$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_roleElement [] = {
  TO_UNICODE ('r'),
  TO_UNICODE ('o'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('E'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$roleWrapperElement$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_roleWrapperElement [] = {
  TO_UNICODE ('r'),
  TO_UNICODE ('o'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('W'),
  TO_UNICODE ('r'),
  TO_UNICODE ('a'),
  TO_UNICODE ('p'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('E'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$schema$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_schema [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('c'),
  TO_UNICODE ('h'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('a'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$schemaLocation$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_schemaLocation [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('c'),
  TO_UNICODE ('h'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('a'),
  TO_UNICODE ('L'),
  TO_UNICODE ('o'),
  TO_UNICODE ('c'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$sequence$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_sequence [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE ('q'),
  TO_UNICODE ('u'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$sequenceOffset$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_sequenceOffset [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE ('q'),
  TO_UNICODE ('u'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE ('O'),
  TO_UNICODE ('f'),
  TO_UNICODE ('f'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$simpleContent$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_simpleContent [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('C'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$simpleType$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_simpleType [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('T'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$source$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_source [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('o'),
  TO_UNICODE ('u'),
  TO_UNICODE ('r'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$targetNamespace$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_targetNamespace [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('r'),
  TO_UNICODE ('g'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE ('N'),
  TO_UNICODE ('a'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE ('p'),
  TO_UNICODE ('a'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$type$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_type [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$typeElement$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_typeElement [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE ('E'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$typeWrapperElement$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_typeWrapperElement [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE ('W'),
  TO_UNICODE ('r'),
  TO_UNICODE ('a'),
  TO_UNICODE ('p'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('E'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$use$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_use [] = {
  TO_UNICODE ('u'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$value$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_value [] = {
  TO_UNICODE ('v'),
  TO_UNICODE ('a'),
  TO_UNICODE ('l'),
  TO_UNICODE ('u'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$version$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_version [] = {
  TO_UNICODE ('v'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('s'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$whiteSpace$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_whiteSpace [] = {
  TO_UNICODE ('w'),
  TO_UNICODE ('h'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('S'),
  TO_UNICODE ('p'),
  TO_UNICODE ('a'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$xmlns_3A_AR$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_xmlns_3A_AR [] = {
  TO_UNICODE ('x'),
  TO_UNICODE ('m'),
  TO_UNICODE ('l'),
  TO_UNICODE ('n'),
  TO_UNICODE ('s'),
  TO_UNICODE (':'),
  TO_UNICODE ('A'),
  TO_UNICODE ('R'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$xmlns_3A_xsd$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_xmlns_3A_xsd [] = {
  TO_UNICODE ('x'),
  TO_UNICODE ('m'),
  TO_UNICODE ('l'),
  TO_UNICODE ('n'),
  TO_UNICODE ('s'),
  TO_UNICODE (':'),
  TO_UNICODE ('x'),
  TO_UNICODE ('s'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'keyWordList'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_arxmlmetaparser_5F_scanner_keyWordList = 63 ;

static const C_unicode_lexique_table_entry ktable_for_arxmlmetaparser_5F_scanner_keyWordList [ktable_size_arxmlmetaparser_5F_scanner_keyWordList] = {
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_id, 2, C_Lexique_arxmlmetaparser_5F_scanner::kToken_id),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_ref, 3, C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_use, 3, C_Lexique_arxmlmetaparser_5F_scanner::kToken_use),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_TODO, 4, C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_base, 4, C_Lexique_arxmlmetaparser_5F_scanner::kToken_base),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_name, 4, C_Lexique_arxmlmetaparser_5F_scanner::kToken_name),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_type, 4, C_Lexique_arxmlmetaparser_5F_scanner::kToken_type),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_color, 5, C_Lexique_arxmlmetaparser_5F_scanner::kToken_color),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_group, 5, C_Lexique_arxmlmetaparser_5F_scanner::kToken_group),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_mixed, 5, C_Lexique_arxmlmetaparser_5F_scanner::kToken_mixed),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_value, 5, C_Lexique_arxmlmetaparser_5F_scanner::kToken_value),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_Status, 6, C_Lexique_arxmlmetaparser_5F_scanner::kToken_Status),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_choice, 6, C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_import, 6, C_Lexique_arxmlmetaparser_5F_scanner::kToken_import),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_schema, 6, C_Lexique_arxmlmetaparser_5F_scanner::kToken_schema),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_source, 6, C_Lexique_arxmlmetaparser_5F_scanner::kToken_source),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_appinfo, 7, C_Lexique_arxmlmetaparser_5F_scanner::kToken_appinfo),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_element, 7, C_Lexique_arxmlmetaparser_5F_scanner::kToken_element),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_pattern, 7, C_Lexique_arxmlmetaparser_5F_scanner::kToken_pattern),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_version, 7, C_Lexique_arxmlmetaparser_5F_scanner::kToken_version),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_CATEGORY, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_CATEGORY),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_Splitkey, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_Splitkey),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_abstract, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_abstract),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_category, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_category),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_encoding, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_encoding),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_noteType, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_noteType),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_nsPrefix, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_nsPrefix),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_sequence, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_xmlns_3A_AR, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlns_3A_AR),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_attribute, 9, C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_extension, 9, C_Lexique_arxmlmetaparser_5F_scanner::kToken_extension),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_maxLength, 9, C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxLength),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_maxOccurs, 9, C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxOccurs),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_minOccurs, 9, C_Lexique_arxmlmetaparser_5F_scanner::kToken_minOccurs),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_namespace, 9, C_Lexique_arxmlmetaparser_5F_scanner::kToken_namespace),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_xmlns_3A_xsd, 9, C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlns_3A_xsd),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_annotation, 10, C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_customType, 10, C_Lexique_arxmlmetaparser_5F_scanner::kToken_customType),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_namePlural, 10, C_Lexique_arxmlmetaparser_5F_scanner::kToken_namePlural),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_simpleType, 10, C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_whiteSpace, 10, C_Lexique_arxmlmetaparser_5F_scanner::kToken_whiteSpace),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_complexType, 11, C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_enumeration, 11, C_Lexique_arxmlmetaparser_5F_scanner::kToken_enumeration),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_restriction, 11, C_Lexique_arxmlmetaparser_5F_scanner::kToken_restriction),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_roleElement, 11, C_Lexique_arxmlmetaparser_5F_scanner::kToken_roleElement),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_typeElement, 11, C_Lexique_arxmlmetaparser_5F_scanner::kToken_typeElement),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_attributeRef, 12, C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeRef),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_documentation, 13, C_Lexique_arxmlmetaparser_5F_scanner::kToken_documentation),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_globalElement, 13, C_Lexique_arxmlmetaparser_5F_scanner::kToken_globalElement),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_qualifiedName, 13, C_Lexique_arxmlmetaparser_5F_scanner::kToken_qualifiedName),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_simpleContent, 13, C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleContent),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_attributeGroup, 14, C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_schemaLocation, 14, C_Lexique_arxmlmetaparser_5F_scanner::kToken_schemaLocation),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_sequenceOffset, 14, C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequenceOffset),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_targetNamespace, 15, C_Lexique_arxmlmetaparser_5F_scanner::kToken_targetNamespace),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_latestBindingTime, 17, C_Lexique_arxmlmetaparser_5F_scanner::kToken_latestBindingTime),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_elementFormDefault, 18, C_Lexique_arxmlmetaparser_5F_scanner::kToken_elementFormDefault),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_recommendedPackage, 18, C_Lexique_arxmlmetaparser_5F_scanner::kToken_recommendedPackage),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_roleWrapperElement, 18, C_Lexique_arxmlmetaparser_5F_scanner::kToken_roleWrapperElement),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_typeWrapperElement, 18, C_Lexique_arxmlmetaparser_5F_scanner::kToken_typeWrapperElement),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_StatusRevisionBegin, 19, C_Lexique_arxmlmetaparser_5F_scanner::kToken_StatusRevisionBegin),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_attributeFormDefault, 20, C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeFormDefault),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_enforceMinMultiplicity, 22, C_Lexique_arxmlmetaparser_5F_scanner::kToken_enforceMinMultiplicity)
} ;

int32_t C_Lexique_arxmlmetaparser_5F_scanner::search_into_keyWordList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_arxmlmetaparser_5F_scanner_keyWordList, ktable_size_arxmlmetaparser_5F_scanner_keyWordList) ;
}

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'xmlDelimitorsList'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_arxmlmetaparser_5F_scanner_xmlDelimitorsList = 9 ;

static const C_unicode_lexique_table_entry ktable_for_arxmlmetaparser_5F_scanner_xmlDelimitorsList [ktable_size_arxmlmetaparser_5F_scanner_xmlDelimitorsList] = {
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__3C_, 1, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__3D_, 1, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__3E_, 1, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__2F__3E_, 2, C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__3C__2F_, 2, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__3F__3E_, 2, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3F__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__3C__3F_xml, 5, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__3F_xml),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__3C_xsd_3A_, 5, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__3C__2F_xsd_3A_, 6, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_)
} ;

int32_t C_Lexique_arxmlmetaparser_5F_scanner::search_into_xmlDelimitorsList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_arxmlmetaparser_5F_scanner_xmlDelimitorsList, ktable_size_arxmlmetaparser_5F_scanner_xmlDelimitorsList) ;
}


//----------------------------------------------------------------------------------------------------------------------
//                          getCurrentTokenString                                                
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_arxmlmetaparser_5F_scanner::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_arxmlmetaparser_5F_scanner * ptr = (const cTokenFor_arxmlmetaparser_5F_scanner *) inTokenPtr ;
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
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_xmlTag:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("xmlTag") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_xmlTagValue:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("xmlTagValue") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_identifier:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("identifier") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken__3C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C_xsd_3A_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<xsd:") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__2F_xsd_3A_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("</xsd:") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__3F_xml:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<\?xml") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (">") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3F__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("\?>") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2F__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("/>") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__2F_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("</") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_group:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("group") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_annotation:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("annotation") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_appinfo:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("appinfo") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_attribute:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("attribute") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_attributeGroup:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("attributeGroup") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_choice:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("choice") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_complexType:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("complexType") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_documentation:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("documentation") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_element:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("element") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_enumeration:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("enumeration") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_extension:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("extension") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_import:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("import") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_maxLength:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("maxLength") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_pattern:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("pattern") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_restriction:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("restriction") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_schema:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("schema") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_sequence:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("sequence") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_simpleContent:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("simpleContent") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_simpleType:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("simpleType") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_whiteSpace:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("whiteSpace") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_abstract:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("abstract") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_attributeFormDefault:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("attributeFormDefault") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_attributeRef:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("attributeRef") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_base:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("base") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_category:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("category") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_CATEGORY:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("CATEGORY") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_color:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("color") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_customType:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("customType") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_elementFormDefault:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("elementFormDefault") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_encoding:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("encoding") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_enforceMinMultiplicity:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("enforceMinMultiplicity") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_globalElement:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("globalElement") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_id:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("id") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_latestBindingTime:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("latestBindingTime") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_maxOccurs:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("maxOccurs") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_minOccurs:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("minOccurs") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_mixed:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("mixed") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_name:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("name") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_namePlural:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("namePlural") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_namespace:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("namespace") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_noteType:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("noteType") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_nsPrefix:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("nsPrefix") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_qualifiedName:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("qualifiedName") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_recommendedPackage:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("recommendedPackage") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_ref:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("ref") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_roleElement:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("roleElement") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_roleWrapperElement:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("roleWrapperElement") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_schemaLocation:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("schemaLocation") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_sequenceOffset:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("sequenceOffset") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_source:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("source") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_Splitkey:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("Splitkey") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_Status:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("Status") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_StatusRevisionBegin:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("StatusRevisionBegin") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_targetNamespace:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("targetNamespace") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_type:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("type") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_typeElement:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("typeElement") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_typeWrapperElement:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("typeWrapperElement") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_use:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("use") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_value:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("value") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_version:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("version") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_xmlns_3A_AR:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("xmlns:AR") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_xmlns_3A_xsd:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("xmlns:xsd") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_TODO:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("TODO") ;
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

static const cTemplateDelimiter arxmlmetaparser_5F_scanner_kTemplateDefinitionArray [1] = {
  cTemplateDelimiter (kUnicodeString_arxmlmetaparser_5F_scanner__3C_, 1, nullptr, 0, nullptr, false)
} ;

//----------------------------------------------------------------------------------------------------------------------
//                           Template Replacements                                               
//----------------------------------------------------------------------------------------------------------------------

static const cTemplateDelimiter arxmlmetaparser_5F_scanner_kTemplateReplacementArray [6] = {
  cTemplateDelimiter (kUnicodeString_arxmlmetaparser_5F_scanner__26_amp_3B_, 5, kUnicodeString_arxmlmetaparser_5F_scanner__26_, 1, nullptr, true),
  cTemplateDelimiter (kUnicodeString_arxmlmetaparser_5F_scanner__26_lt_3B_, 4, kUnicodeString_arxmlmetaparser_5F_scanner__3C_, 1, nullptr, true),
  cTemplateDelimiter (kUnicodeString_arxmlmetaparser_5F_scanner__26_gt_3B_, 4, kUnicodeString_arxmlmetaparser_5F_scanner__3E_, 1, nullptr, true),
  cTemplateDelimiter (kUnicodeString_arxmlmetaparser_5F_scanner__26_quot_3B_, 6, kUnicodeString_arxmlmetaparser_5F_scanner__22_, 1, nullptr, true),
  cTemplateDelimiter (kUnicodeString_arxmlmetaparser_5F_scanner__26_apos_3B_, 6, kUnicodeString_arxmlmetaparser_5F_scanner__27_, 1, nullptr, true),
  cTemplateDelimiter (kUnicodeString_arxmlmetaparser_5F_scanner__26__23_, 2, kUnicodeString_arxmlmetaparser_5F_scanner__3B_, 1, scanner_routine_codePointToUnicode, true)
} ;

//----------------------------------------------------------------------------------------------------------------------
//            Terminal Symbols as end of script in template mark                                 
//----------------------------------------------------------------------------------------------------------------------

static const bool arxmlmetaparser_5F_scanner_kEndOfScriptInTemplateArray [76] = {
  true /* comment */,
  false /* xmlTag */,
  false /* xmlTagValue */,
  false /* identifier */,
  false /* < */,
  false /* <xsd: */,
  false /* </xsd: */,
  false /* <?xml */,
  true /* > */,
  true /* ?> */,
  true /* /> */,
  false /* </ */,
  false /* = */,
  false /* group */,
  false /* annotation */,
  false /* appinfo */,
  false /* attribute */,
  false /* attributeGroup */,
  false /* choice */,
  false /* complexType */,
  false /* documentation */,
  false /* element */,
  false /* enumeration */,
  false /* extension */,
  false /* import */,
  false /* maxLength */,
  false /* pattern */,
  false /* restriction */,
  false /* schema */,
  false /* sequence */,
  false /* simpleContent */,
  false /* simpleType */,
  false /* whiteSpace */,
  false /* abstract */,
  false /* attributeFormDefault */,
  false /* attributeRef */,
  false /* base */,
  false /* category */,
  false /* CATEGORY */,
  false /* color */,
  false /* customType */,
  false /* elementFormDefault */,
  false /* encoding */,
  false /* enforceMinMultiplicity */,
  false /* globalElement */,
  false /* id */,
  false /* latestBindingTime */,
  false /* maxOccurs */,
  false /* minOccurs */,
  false /* mixed */,
  false /* name */,
  false /* namePlural */,
  false /* namespace */,
  false /* noteType */,
  false /* nsPrefix */,
  false /* qualifiedName */,
  false /* recommendedPackage */,
  false /* ref */,
  false /* roleElement */,
  false /* roleWrapperElement */,
  false /* schemaLocation */,
  false /* sequenceOffset */,
  false /* source */,
  false /* Splitkey */,
  false /* Status */,
  false /* StatusRevisionBegin */,
  false /* targetNamespace */,
  false /* type */,
  false /* typeElement */,
  false /* typeWrapperElement */,
  false /* use */,
  false /* value */,
  false /* version */,
  false /* xmlns:AR */,
  false /* xmlns:xsd */,
  false /* TODO */
} ;

//----------------------------------------------------------------------------------------------------------------------
//               INTERNAL PARSE LEXICAL TOKEN                                         
//----------------------------------------------------------------------------------------------------------------------

void C_Lexique_arxmlmetaparser_5F_scanner::internalParseLexicalToken (cTokenFor_arxmlmetaparser_5F_scanner & token) {
  bool loop = true ;
  token.mLexicalAttribute_tokenString.setLengthToZero () ;
  mTokenStartLocation = mCurrentLocation ;
  try{
    if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3C__21__2D__2D_, 4, true)) {
      do {
        if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_amp_3B_, 5, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('&')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_lt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('<')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_gt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('>')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_quot_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\"')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_apos_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\'')) ;
        }else if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (',')) || testForInputUTF32CharRange (TO_UNICODE ('.'), TO_UNICODE (1114111))) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        }else if (notTestForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__2D__2D__3E_, 3, gLexicalMessage_arxmlmetaparser_5F_scanner_incorrectCommentError COMMA_LINE_AND_SOURCE_FILE)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('-')) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      enterDroppedTerminal (kToken_comment) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3C__2F_xsd_3A_, 6, true)) {
      token.mTokenCode = kToken__3C__2F_xsd_3A_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3C_xsd_3A_, 5, true)) {
      token.mTokenCode = kToken__3C_xsd_3A_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3C__3F_xml, 5, true)) {
      token.mTokenCode = kToken__3C__3F_xml ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3F__3E_, 2, true)) {
      token.mTokenCode = kToken__3F__3E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3C__2F_, 2, true)) {
      token.mTokenCode = kToken__3C__2F_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__2F__3E_, 2, true)) {
      token.mTokenCode = kToken__2F__3E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3E_, 1, true)) {
      token.mTokenCode = kToken__3E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3D_, 1, true)) {
      token.mTokenCode = kToken__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3C_, 1, true)) {
      token.mTokenCode = kToken__3C_ ;
      enterToken (token) ;
    }else if (testForCharWithFunction (isUnicodeLetter)) {
      do {
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        if (testForCharWithFunction (isUnicodeLetter) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32Char (TO_UNICODE ('-')) || testForInputUTF32Char (TO_UNICODE (':'))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (token.mTokenCode == -1) {
        token.mTokenCode = search_into_keyWordList (token.mLexicalAttribute_tokenString) ;
      }
      if (token.mTokenCode == -1) {
        token.mTokenCode = kToken_xmlTag ;
      }
      enterToken (token) ;
    }else if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
      do {
        if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_amp_3B_, 5, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('&')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_lt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('<')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_gt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('>')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_quot_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\"')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_apos_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\'')) ;
        }else if (notTestForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__22_, 1, gLexicalMessage_arxmlmetaparser_5F_scanner_incorrectAttributeEnd COMMA_LINE_AND_SOURCE_FILE)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      token.mTokenCode = kToken_xmlTagValue ;
      enterToken (token) ;
    }else if (testForInputUTF32Char (TO_UNICODE ('\''))) {
      do {
        if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_amp_3B_, 5, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('&')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_lt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('<')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_gt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('>')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_quot_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\"')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_apos_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\'')) ;
        }else if (notTestForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__27_, 1, gLexicalMessage_arxmlmetaparser_5F_scanner_incorrectAttributeEnd COMMA_LINE_AND_SOURCE_FILE)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      token.mTokenCode = kToken_xmlTagValue ;
      enterToken (token) ;
    }else if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (' '))) {
    }else if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (';')) || testForInputUTF32CharRange (TO_UNICODE ('='), TO_UNICODE (1114111))) {
      do {
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (';')) || testForInputUTF32CharRange (TO_UNICODE ('='), TO_UNICODE (1114111))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (token.mTokenCode == -1) {
        token.mTokenCode = search_into_keyWordList (token.mLexicalAttribute_tokenString) ;
      }
      if (token.mTokenCode == -1) {
        token.mTokenCode = kToken_identifier ;
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

bool C_Lexique_arxmlmetaparser_5F_scanner::parseLexicalToken (void) {
  cTokenFor_arxmlmetaparser_5F_scanner token ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
    if ((mMatchedTemplateDelimiterIndex >= 0)
     && (arxmlmetaparser_5F_scanner_kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndStringLength > 0)
     && (UNICODE_VALUE (mCurrentChar) != '\0')) {
      const bool foundEndDelimitor = testForInputUTF32String (arxmlmetaparser_5F_scanner_kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndString,
                                                              arxmlmetaparser_5F_scanner_kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndStringLength,
                                                              true) ;
      if (foundEndDelimitor) {
        mMatchedTemplateDelimiterIndex = -1 ;
      }
    }
    while ((mMatchedTemplateDelimiterIndex < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
      int32_t replacementIndex = 0 ;
      while (replacementIndex >= 0) {
        replacementIndex = findTemplateDelimiterIndex (arxmlmetaparser_5F_scanner_kTemplateReplacementArray, 6) ;
        if (replacementIndex >= 0) {
          if (arxmlmetaparser_5F_scanner_kTemplateReplacementArray [replacementIndex].mReplacementFunction == nullptr) {
            token.mTemplateStringBeforeToken << arxmlmetaparser_5F_scanner_kTemplateReplacementArray [replacementIndex].mEndString ;
          }else{
            C_String s ;
            while (notTestForInputUTF32String (arxmlmetaparser_5F_scanner_kTemplateReplacementArray [replacementIndex].mEndString,
                                               arxmlmetaparser_5F_scanner_kTemplateReplacementArray [replacementIndex].mEndStringLength,
                                               kEndOfSourceLexicalErrorMessage
                                               COMMA_HERE)) {
              s.appendUnicodeCharacter (previousChar () COMMA_HERE) ;
            }
            arxmlmetaparser_5F_scanner_kTemplateReplacementArray [replacementIndex].mReplacementFunction (*this, s, token.mTemplateStringBeforeToken) ;
          }
        }
      }
      mMatchedTemplateDelimiterIndex = findTemplateDelimiterIndex (arxmlmetaparser_5F_scanner_kTemplateDefinitionArray, 1) ;
      if (mMatchedTemplateDelimiterIndex < 0) {
        token.mTemplateStringBeforeToken.appendUnicodeCharacter (mCurrentChar COMMA_HERE) ;
        advance () ;
      }
    }
    if ((mMatchedTemplateDelimiterIndex >= 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
      internalParseLexicalToken (token) ;
    }
    if ((token.mTokenCode > 0) && arxmlmetaparser_5F_scanner_kEndOfScriptInTemplateArray [token.mTokenCode - 1]) {
      mMatchedTemplateDelimiterIndex = -1 ;
    }
  
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

void C_Lexique_arxmlmetaparser_5F_scanner::enterToken (cTokenFor_arxmlmetaparser_5F_scanner & ioToken) {
  cTokenFor_arxmlmetaparser_5F_scanner * ptr = nullptr ;
  macroMyNew (ptr, cTokenFor_arxmlmetaparser_5F_scanner ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
  // ptr->mIsOptional = ioToken.mIsOptional ;
  ptr->mStartLocation = mTokenStartLocation ;
  ptr->mEndLocation = mTokenEndLocation ;
  ptr->mTemplateStringBeforeToken = ioToken.mTemplateStringBeforeToken ;
  ioToken.mTemplateStringBeforeToken = "" ;
  ptr->mLexicalAttribute_tokenString = ioToken.mLexicalAttribute_tokenString ;
  enterTokenFromPointer (ptr) ;
}

//----------------------------------------------------------------------------------------------------------------------
//               A T T R I B U T E   A C C E S S                                                 
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_arxmlmetaparser_5F_scanner::attributeValue_tokenString (void) const {
  cTokenFor_arxmlmetaparser_5F_scanner * ptr = (cTokenFor_arxmlmetaparser_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_tokenString ;
}

//----------------------------------------------------------------------------------------------------------------------
//         A S S I G N    F R O M    A T T R I B U T E                                           
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_arxmlmetaparser_5F_scanner::synthetizedAttribute_tokenString (void) const {
  cTokenFor_arxmlmetaparser_5F_scanner * ptr = (cTokenFor_arxmlmetaparser_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_arxmlmetaparser_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_tokenString) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                         I N T R O S P E C T I O N                                             
//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist C_Lexique_arxmlmetaparser_5F_scanner::symbols (LOCATION_ARGS) {
  GALGAS_stringlist result = GALGAS_stringlist::constructor_emptyList (THERE) ;
  result.addAssign_operation (GALGAS_string ("comment") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("xmlTag") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("xmlTagValue") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("identifier") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<xsd:") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("</xsd:") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<\?xml") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (">") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("\?>") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("/>") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("</") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("group") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("annotation") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("appinfo") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("attribute") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("attributeGroup") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("choice") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("complexType") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("documentation") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("element") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("enumeration") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("extension") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("import") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("maxLength") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("pattern") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("restriction") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("schema") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("sequence") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("simpleContent") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("simpleType") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("whiteSpace") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("abstract") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("attributeFormDefault") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("attributeRef") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("base") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("category") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("CATEGORY") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("color") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("customType") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("elementFormDefault") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("encoding") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("enforceMinMultiplicity") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("globalElement") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("id") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("latestBindingTime") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("maxOccurs") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("minOccurs") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("mixed") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("name") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("namePlural") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("namespace") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("noteType") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("nsPrefix") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("qualifiedName") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("recommendedPackage") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("ref") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("roleElement") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("roleWrapperElement") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("schemaLocation") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("sequenceOffset") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("source") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("Splitkey") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("Status") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("StatusRevisionBegin") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("targetNamespace") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("type") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("typeElement") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("typeWrapperElement") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("use") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("value") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("version") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("xmlns:AR") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("xmlns:xsd") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("TODO") COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

static void getKeywordLists_arxmlmetaparser_5F_scanner (TC_UniqueArray <C_String> & ioList) {
  ioList.appendObject ("arxmlmetaparser_scanner:keyWordList") ;
  ioList.appendObject ("arxmlmetaparser_scanner:xmlDelimitorsList") ;
}

//----------------------------------------------------------------------------------------------------------------------

static void getKeywordsForIdentifier_arxmlmetaparser_5F_scanner (const C_String & inIdentifier,
                                                                 bool & ioFound,
                                                                 TC_UniqueArray <C_String> & ioList) {
  if (inIdentifier == "arxmlmetaparser_scanner:keyWordList") {
    ioFound = true ;
    ioList.appendObject ("id") ;
    ioList.appendObject ("ref") ;
    ioList.appendObject ("use") ;
    ioList.appendObject ("TODO") ;
    ioList.appendObject ("base") ;
    ioList.appendObject ("name") ;
    ioList.appendObject ("type") ;
    ioList.appendObject ("color") ;
    ioList.appendObject ("group") ;
    ioList.appendObject ("mixed") ;
    ioList.appendObject ("value") ;
    ioList.appendObject ("Status") ;
    ioList.appendObject ("choice") ;
    ioList.appendObject ("import") ;
    ioList.appendObject ("schema") ;
    ioList.appendObject ("source") ;
    ioList.appendObject ("appinfo") ;
    ioList.appendObject ("element") ;
    ioList.appendObject ("pattern") ;
    ioList.appendObject ("version") ;
    ioList.appendObject ("CATEGORY") ;
    ioList.appendObject ("Splitkey") ;
    ioList.appendObject ("abstract") ;
    ioList.appendObject ("category") ;
    ioList.appendObject ("encoding") ;
    ioList.appendObject ("noteType") ;
    ioList.appendObject ("nsPrefix") ;
    ioList.appendObject ("sequence") ;
    ioList.appendObject ("xmlns:AR") ;
    ioList.appendObject ("attribute") ;
    ioList.appendObject ("extension") ;
    ioList.appendObject ("maxLength") ;
    ioList.appendObject ("maxOccurs") ;
    ioList.appendObject ("minOccurs") ;
    ioList.appendObject ("namespace") ;
    ioList.appendObject ("xmlns:xsd") ;
    ioList.appendObject ("annotation") ;
    ioList.appendObject ("customType") ;
    ioList.appendObject ("namePlural") ;
    ioList.appendObject ("simpleType") ;
    ioList.appendObject ("whiteSpace") ;
    ioList.appendObject ("complexType") ;
    ioList.appendObject ("enumeration") ;
    ioList.appendObject ("restriction") ;
    ioList.appendObject ("roleElement") ;
    ioList.appendObject ("typeElement") ;
    ioList.appendObject ("attributeRef") ;
    ioList.appendObject ("documentation") ;
    ioList.appendObject ("globalElement") ;
    ioList.appendObject ("qualifiedName") ;
    ioList.appendObject ("simpleContent") ;
    ioList.appendObject ("attributeGroup") ;
    ioList.appendObject ("schemaLocation") ;
    ioList.appendObject ("sequenceOffset") ;
    ioList.appendObject ("targetNamespace") ;
    ioList.appendObject ("latestBindingTime") ;
    ioList.appendObject ("elementFormDefault") ;
    ioList.appendObject ("recommendedPackage") ;
    ioList.appendObject ("roleWrapperElement") ;
    ioList.appendObject ("typeWrapperElement") ;
    ioList.appendObject ("StatusRevisionBegin") ;
    ioList.appendObject ("attributeFormDefault") ;
    ioList.appendObject ("enforceMinMultiplicity") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "arxmlmetaparser_scanner:xmlDelimitorsList") {
    ioFound = true ;
    ioList.appendObject ("<") ;
    ioList.appendObject ("=") ;
    ioList.appendObject (">") ;
    ioList.appendObject ("/>") ;
    ioList.appendObject ("</") ;
    ioList.appendObject ("\?>") ;
    ioList.appendObject ("<\?xml") ;
    ioList.appendObject ("<xsd:") ;
    ioList.appendObject ("</xsd:") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static cLexiqueIntrospection lexiqueIntrospection_arxmlmetaparser_5F_scanner
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_arxmlmetaparser_5F_scanner, getKeywordsForIdentifier_arxmlmetaparser_5F_scanner) ;

//----------------------------------------------------------------------------------------------------------------------
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                           
//----------------------------------------------------------------------------------------------------------------------

uint32_t C_Lexique_arxmlmetaparser_5F_scanner::styleIndexForTerminal (const int32_t inTerminalIndex) const {
  static const uint32_t kTerminalSymbolStyles [77] = {0,
    4 /* arxmlmetaparser_scanner_1_comment */,
    2 /* arxmlmetaparser_scanner_1_xmlTag */,
    3 /* arxmlmetaparser_scanner_1_xmlTagValue */,
    5 /* arxmlmetaparser_scanner_1_identifier */,
    1 /* arxmlmetaparser_scanner_1__3C_ */,
    1 /* arxmlmetaparser_scanner_1__3C_xsd_3A_ */,
    1 /* arxmlmetaparser_scanner_1__3C__2F_xsd_3A_ */,
    1 /* arxmlmetaparser_scanner_1__3C__3F_xml */,
    1 /* arxmlmetaparser_scanner_1__3E_ */,
    1 /* arxmlmetaparser_scanner_1__3F__3E_ */,
    1 /* arxmlmetaparser_scanner_1__2F__3E_ */,
    1 /* arxmlmetaparser_scanner_1__3C__2F_ */,
    1 /* arxmlmetaparser_scanner_1__3D_ */,
    6 /* arxmlmetaparser_scanner_1_group */,
    6 /* arxmlmetaparser_scanner_1_annotation */,
    6 /* arxmlmetaparser_scanner_1_appinfo */,
    6 /* arxmlmetaparser_scanner_1_attribute */,
    6 /* arxmlmetaparser_scanner_1_attributeGroup */,
    6 /* arxmlmetaparser_scanner_1_choice */,
    6 /* arxmlmetaparser_scanner_1_complexType */,
    6 /* arxmlmetaparser_scanner_1_documentation */,
    6 /* arxmlmetaparser_scanner_1_element */,
    6 /* arxmlmetaparser_scanner_1_enumeration */,
    6 /* arxmlmetaparser_scanner_1_extension */,
    6 /* arxmlmetaparser_scanner_1_import */,
    6 /* arxmlmetaparser_scanner_1_maxLength */,
    6 /* arxmlmetaparser_scanner_1_pattern */,
    6 /* arxmlmetaparser_scanner_1_restriction */,
    6 /* arxmlmetaparser_scanner_1_schema */,
    6 /* arxmlmetaparser_scanner_1_sequence */,
    6 /* arxmlmetaparser_scanner_1_simpleContent */,
    6 /* arxmlmetaparser_scanner_1_simpleType */,
    6 /* arxmlmetaparser_scanner_1_whiteSpace */,
    6 /* arxmlmetaparser_scanner_1_abstract */,
    6 /* arxmlmetaparser_scanner_1_attributeFormDefault */,
    6 /* arxmlmetaparser_scanner_1_attributeRef */,
    6 /* arxmlmetaparser_scanner_1_base */,
    6 /* arxmlmetaparser_scanner_1_category */,
    6 /* arxmlmetaparser_scanner_1_CATEGORY */,
    6 /* arxmlmetaparser_scanner_1_color */,
    6 /* arxmlmetaparser_scanner_1_customType */,
    6 /* arxmlmetaparser_scanner_1_elementFormDefault */,
    6 /* arxmlmetaparser_scanner_1_encoding */,
    6 /* arxmlmetaparser_scanner_1_enforceMinMultiplicity */,
    6 /* arxmlmetaparser_scanner_1_globalElement */,
    6 /* arxmlmetaparser_scanner_1_id */,
    6 /* arxmlmetaparser_scanner_1_latestBindingTime */,
    6 /* arxmlmetaparser_scanner_1_maxOccurs */,
    6 /* arxmlmetaparser_scanner_1_minOccurs */,
    6 /* arxmlmetaparser_scanner_1_mixed */,
    6 /* arxmlmetaparser_scanner_1_name */,
    6 /* arxmlmetaparser_scanner_1_namePlural */,
    6 /* arxmlmetaparser_scanner_1_namespace */,
    6 /* arxmlmetaparser_scanner_1_noteType */,
    6 /* arxmlmetaparser_scanner_1_nsPrefix */,
    6 /* arxmlmetaparser_scanner_1_qualifiedName */,
    6 /* arxmlmetaparser_scanner_1_recommendedPackage */,
    6 /* arxmlmetaparser_scanner_1_ref */,
    6 /* arxmlmetaparser_scanner_1_roleElement */,
    6 /* arxmlmetaparser_scanner_1_roleWrapperElement */,
    6 /* arxmlmetaparser_scanner_1_schemaLocation */,
    6 /* arxmlmetaparser_scanner_1_sequenceOffset */,
    6 /* arxmlmetaparser_scanner_1_source */,
    6 /* arxmlmetaparser_scanner_1_Splitkey */,
    6 /* arxmlmetaparser_scanner_1_Status */,
    6 /* arxmlmetaparser_scanner_1_StatusRevisionBegin */,
    6 /* arxmlmetaparser_scanner_1_targetNamespace */,
    6 /* arxmlmetaparser_scanner_1_type */,
    6 /* arxmlmetaparser_scanner_1_typeElement */,
    6 /* arxmlmetaparser_scanner_1_typeWrapperElement */,
    6 /* arxmlmetaparser_scanner_1_use */,
    6 /* arxmlmetaparser_scanner_1_value */,
    6 /* arxmlmetaparser_scanner_1_version */,
    6 /* arxmlmetaparser_scanner_1_xmlns_3A_AR */,
    6 /* arxmlmetaparser_scanner_1_xmlns_3A_xsd */,
    6 /* arxmlmetaparser_scanner_1_TODO */
  } ;
  return (inTerminalIndex >= 0) ? kTerminalSymbolStyles [inTerminalIndex] : 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                      
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_arxmlmetaparser_5F_scanner::styleNameForIndex (const uint32_t inStyleIndex) const {
  C_String result ;
  if (inStyleIndex < 7) {
    static const char * kStyleArray [7] = {
      "",
      "delimitersStyle",
      "nameStyle",
      "attributeValue",
      "commentStyle",
      "textStyle",
      "keywordsStyle"
    } ;
    result = kStyleArray [inStyleIndex] ;
  }
  return result ;
}


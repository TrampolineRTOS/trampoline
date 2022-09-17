#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-5.h"

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumAttribute::GALGAS_enumAttribute (void) :
GALGAS_object_5F_t () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumAttribute GALGAS_enumAttribute::constructor_default (LOCATION_ARGS) {
  return GALGAS_enumAttribute::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                GALGAS_location::constructor_nowhere (HERE),
                                                GALGAS_string::constructor_default (HERE),
                                                GALGAS_objectAttributes::constructor_default (HERE)
                                                COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumAttribute::GALGAS_enumAttribute (const cPtr_enumAttribute * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_enumAttribute) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_enumAttribute::readProperty_value (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_enumAttribute * p = (const cPtr_enumAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_enumAttribute) ;
    return p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_enumAttribute::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectAttributes GALGAS_enumAttribute::readProperty_subAttributes (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_objectAttributes () ;
  }else{
    const cPtr_enumAttribute * p = (const cPtr_enumAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_enumAttribute) ;
    return p->mProperty_subAttributes ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectAttributes cPtr_enumAttribute::getter_subAttributes (UNUSED_LOCATION_ARGS) const {
  return mProperty_subAttributes ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_enumAttribute::setter_setValue (GALGAS_string inValue
                                            COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_enumAttribute * p = (cPtr_enumAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_enumAttribute) ;
    p->mProperty_value = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_enumAttribute::setter_setValue (GALGAS_string inValue
                                          COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_enumAttribute::setter_setSubAttributes (GALGAS_objectAttributes inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_enumAttribute * p = (cPtr_enumAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_enumAttribute) ;
    p->mProperty_subAttributes = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_enumAttribute::setter_setSubAttributes (GALGAS_objectAttributes inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_subAttributes = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @enumAttribute class
//----------------------------------------------------------------------------------------------------------------------

cPtr_enumAttribute::cPtr_enumAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                        const GALGAS_location & in_location,
                                        const GALGAS_string & in_value,
                                        const GALGAS_objectAttributes & in_subAttributes
                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value),
mProperty_subAttributes (in_subAttributes) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_enumAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_enumAttribute ;
}

void cPtr_enumAttribute::description (C_String & ioString,
                                      const int32_t inIndentation) const {
  ioString << "[@enumAttribute:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_subAttributes.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_enumAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_enumAttribute (mProperty_oil_5F_desc, mProperty_location, mProperty_value, mProperty_subAttributes COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@enumAttribute type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_enumAttribute ("enumAttribute",
                                      & kTypeDescriptor_GALGAS_object_5F_t) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_enumAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_enumAttribute ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_enumAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_enumAttribute (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectRefAttribute::GALGAS_objectRefAttribute (void) :
GALGAS_object_5F_t () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectRefAttribute GALGAS_objectRefAttribute::constructor_default (LOCATION_ARGS) {
  return GALGAS_objectRefAttribute::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                     GALGAS_location::constructor_nowhere (HERE),
                                                     GALGAS_lstring::constructor_default (HERE)
                                                     COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectRefAttribute::GALGAS_objectRefAttribute (const cPtr_objectRefAttribute * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_objectRefAttribute) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_objectRefAttribute::readProperty_value (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_objectRefAttribute * p = (const cPtr_objectRefAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_objectRefAttribute) ;
    return p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_objectRefAttribute::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectRefAttribute::setter_setValue (GALGAS_lstring inValue
                                                 COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_objectRefAttribute * p = (cPtr_objectRefAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_objectRefAttribute) ;
    p->mProperty_value = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_objectRefAttribute::setter_setValue (GALGAS_lstring inValue
                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @objectRefAttribute class
//----------------------------------------------------------------------------------------------------------------------

cPtr_objectRefAttribute::cPtr_objectRefAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                                  const GALGAS_location & in_location,
                                                  const GALGAS_lstring & in_value
                                                  COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_objectRefAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectRefAttribute ;
}

void cPtr_objectRefAttribute::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@objectRefAttribute:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_objectRefAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_objectRefAttribute (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@objectRefAttribute type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectRefAttribute ("objectRefAttribute",
                                           & kTypeDescriptor_GALGAS_object_5F_t) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_objectRefAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectRefAttribute ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_objectRefAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectRefAttribute (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32__5F_class::GALGAS_uint_33__32__5F_class (void) :
GALGAS_object_5F_t () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32__5F_class GALGAS_uint_33__32__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_33__32__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_location::constructor_nowhere (HERE),
                                                        GALGAS_uint::constructor_default (HERE)
                                                        COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32__5F_class::GALGAS_uint_33__32__5F_class (const cPtr_uint_33__32__5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_33__32__5F_class) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_uint_33__32__5F_class::readProperty_value (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    const cPtr_uint_33__32__5F_class * p = (const cPtr_uint_33__32__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32__5F_class) ;
    return p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_uint_33__32__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32__5F_class::setter_setValue (GALGAS_uint inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_uint_33__32__5F_class * p = (cPtr_uint_33__32__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32__5F_class) ;
    p->mProperty_value = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_uint_33__32__5F_class::setter_setValue (GALGAS_uint inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @uint32_class class
//----------------------------------------------------------------------------------------------------------------------

cPtr_uint_33__32__5F_class::cPtr_uint_33__32__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                        const GALGAS_location & in_location,
                                                        const GALGAS_uint & in_value
                                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_uint_33__32__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32__5F_class ;
}

void cPtr_uint_33__32__5F_class::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@uint32_class:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_uint_33__32__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_uint_33__32__5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@uint32_class type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_33__32__5F_class ("uint32_class",
                                              & kTypeDescriptor_GALGAS_object_5F_t) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_33__32__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32__5F_class ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_33__32__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_33__32__5F_class (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32__5F_class::GALGAS_sint_33__32__5F_class (void) :
GALGAS_object_5F_t () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32__5F_class GALGAS_sint_33__32__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_33__32__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_location::constructor_nowhere (HERE),
                                                        GALGAS_sint::constructor_default (HERE)
                                                        COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32__5F_class::GALGAS_sint_33__32__5F_class (const cPtr_sint_33__32__5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_33__32__5F_class) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint_33__32__5F_class::readProperty_value (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_sint () ;
  }else{
    const cPtr_sint_33__32__5F_class * p = (const cPtr_sint_33__32__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32__5F_class) ;
    return p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint cPtr_sint_33__32__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32__5F_class::setter_setValue (GALGAS_sint inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_sint_33__32__5F_class * p = (cPtr_sint_33__32__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32__5F_class) ;
    p->mProperty_value = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_sint_33__32__5F_class::setter_setValue (GALGAS_sint inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @sint32_class class
//----------------------------------------------------------------------------------------------------------------------

cPtr_sint_33__32__5F_class::cPtr_sint_33__32__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                        const GALGAS_location & in_location,
                                                        const GALGAS_sint & in_value
                                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_sint_33__32__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32__5F_class ;
}

void cPtr_sint_33__32__5F_class::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@sint32_class:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_sint_33__32__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_sint_33__32__5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@sint32_class type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_33__32__5F_class ("sint32_class",
                                              & kTypeDescriptor_GALGAS_object_5F_t) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sint_33__32__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32__5F_class ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sint_33__32__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_33__32__5F_class (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34__5F_class::GALGAS_uint_36__34__5F_class (void) :
GALGAS_object_5F_t () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34__5F_class GALGAS_uint_36__34__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_36__34__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_location::constructor_nowhere (HERE),
                                                        GALGAS_uint_36__34_::constructor_default (HERE)
                                                        COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34__5F_class::GALGAS_uint_36__34__5F_class (const cPtr_uint_36__34__5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_36__34__5F_class) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ GALGAS_uint_36__34__5F_class::readProperty_value (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_uint_36__34_ () ;
  }else{
    const cPtr_uint_36__34__5F_class * p = (const cPtr_uint_36__34__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34__5F_class) ;
    return p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ cPtr_uint_36__34__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34__5F_class::setter_setValue (GALGAS_uint_36__34_ inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_uint_36__34__5F_class * p = (cPtr_uint_36__34__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34__5F_class) ;
    p->mProperty_value = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_uint_36__34__5F_class::setter_setValue (GALGAS_uint_36__34_ inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @uint64_class class
//----------------------------------------------------------------------------------------------------------------------

cPtr_uint_36__34__5F_class::cPtr_uint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                        const GALGAS_location & in_location,
                                                        const GALGAS_uint_36__34_ & in_value
                                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_uint_36__34__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34__5F_class ;
}

void cPtr_uint_36__34__5F_class::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@uint64_class:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_uint_36__34__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_uint_36__34__5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@uint64_class type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34__5F_class ("uint64_class",
                                              & kTypeDescriptor_GALGAS_object_5F_t) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_36__34__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34__5F_class ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_36__34__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34__5F_class (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34__5F_class::GALGAS_sint_36__34__5F_class (void) :
GALGAS_object_5F_t () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34__5F_class GALGAS_sint_36__34__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_36__34__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_location::constructor_nowhere (HERE),
                                                        GALGAS_sint_36__34_::constructor_default (HERE)
                                                        COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34__5F_class::GALGAS_sint_36__34__5F_class (const cPtr_sint_36__34__5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_36__34__5F_class) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34__5F_class::readProperty_value (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_sint_36__34_ () ;
  }else{
    const cPtr_sint_36__34__5F_class * p = (const cPtr_sint_36__34__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34__5F_class) ;
    return p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ cPtr_sint_36__34__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34__5F_class::setter_setValue (GALGAS_sint_36__34_ inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_sint_36__34__5F_class * p = (cPtr_sint_36__34__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34__5F_class) ;
    p->mProperty_value = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_sint_36__34__5F_class::setter_setValue (GALGAS_sint_36__34_ inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @sint64_class class
//----------------------------------------------------------------------------------------------------------------------

cPtr_sint_36__34__5F_class::cPtr_sint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                        const GALGAS_location & in_location,
                                                        const GALGAS_sint_36__34_ & in_value
                                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_sint_36__34__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34__5F_class ;
}

void cPtr_sint_36__34__5F_class::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@sint64_class:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_sint_36__34__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_sint_36__34__5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@sint64_class type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_36__34__5F_class ("sint64_class",
                                              & kTypeDescriptor_GALGAS_object_5F_t) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sint_36__34__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34__5F_class ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sint_36__34__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_36__34__5F_class (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_float_5F_class::GALGAS_float_5F_class (void) :
GALGAS_object_5F_t () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_float_5F_class GALGAS_float_5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_float_5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                 GALGAS_location::constructor_nowhere (HERE),
                                                 GALGAS_double::constructor_default (HERE)
                                                 COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_float_5F_class::GALGAS_float_5F_class (const cPtr_float_5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_float_5F_class) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_float_5F_class::readProperty_value (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_double () ;
  }else{
    const cPtr_float_5F_class * p = (const cPtr_float_5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_float_5F_class) ;
    return p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_float_5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_float_5F_class::setter_setValue (GALGAS_double inValue
                                             COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_float_5F_class * p = (cPtr_float_5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_float_5F_class) ;
    p->mProperty_value = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_float_5F_class::setter_setValue (GALGAS_double inValue
                                           COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @float_class class
//----------------------------------------------------------------------------------------------------------------------

cPtr_float_5F_class::cPtr_float_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                          const GALGAS_location & in_location,
                                          const GALGAS_double & in_value
                                          COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_float_5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_float_5F_class ;
}

void cPtr_float_5F_class::description (C_String & ioString,
                                       const int32_t inIndentation) const {
  ioString << "[@float_class:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_float_5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_float_5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@float_class type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_float_5F_class ("float_class",
                                       & kTypeDescriptor_GALGAS_object_5F_t) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_float_5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_float_5F_class ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_float_5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_float_5F_class (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string_5F_class::GALGAS_string_5F_class (void) :
GALGAS_object_5F_t () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string_5F_class GALGAS_string_5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_string_5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                  GALGAS_location::constructor_nowhere (HERE),
                                                  GALGAS_string::constructor_default (HERE)
                                                  COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string_5F_class::GALGAS_string_5F_class (const cPtr_string_5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_string_5F_class) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string_5F_class::readProperty_value (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_string_5F_class * p = (const cPtr_string_5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_string_5F_class) ;
    return p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_string_5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_string_5F_class::setter_setValue (GALGAS_string inValue
                                              COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_string_5F_class * p = (cPtr_string_5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_string_5F_class) ;
    p->mProperty_value = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_string_5F_class::setter_setValue (GALGAS_string inValue
                                            COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @string_class class
//----------------------------------------------------------------------------------------------------------------------

cPtr_string_5F_class::cPtr_string_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                            const GALGAS_location & in_location,
                                            const GALGAS_string & in_value
                                            COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_string_5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_string_5F_class ;
}

void cPtr_string_5F_class::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@string_class:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_string_5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_string_5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@string_class type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_string_5F_class ("string_class",
                                        & kTypeDescriptor_GALGAS_object_5F_t) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_string_5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_string_5F_class ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_string_5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_string_5F_class (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringAttribute::GALGAS_stringAttribute (void) :
GALGAS_object_5F_t () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringAttribute GALGAS_stringAttribute::constructor_default (LOCATION_ARGS) {
  return GALGAS_stringAttribute::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                  GALGAS_location::constructor_nowhere (HERE),
                                                  GALGAS_string::constructor_default (HERE)
                                                  COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringAttribute::GALGAS_stringAttribute (const cPtr_stringAttribute * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_stringAttribute) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_stringAttribute::readProperty_value (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_stringAttribute * p = (const cPtr_stringAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_stringAttribute) ;
    return p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_stringAttribute::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringAttribute::setter_setValue (GALGAS_string inValue
                                              COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_stringAttribute * p = (cPtr_stringAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_stringAttribute) ;
    p->mProperty_value = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_stringAttribute::setter_setValue (GALGAS_string inValue
                                            COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @stringAttribute class
//----------------------------------------------------------------------------------------------------------------------

cPtr_stringAttribute::cPtr_stringAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                            const GALGAS_location & in_location,
                                            const GALGAS_string & in_value
                                            COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_stringAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringAttribute ;
}

void cPtr_stringAttribute::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@stringAttribute:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_stringAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_stringAttribute (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@stringAttribute type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringAttribute ("stringAttribute",
                                        & kTypeDescriptor_GALGAS_object_5F_t) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_stringAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringAttribute ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_stringAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringAttribute (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_structAttribute::GALGAS_structAttribute (void) :
GALGAS_object_5F_t () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_structAttribute GALGAS_structAttribute::constructor_default (LOCATION_ARGS) {
  return GALGAS_structAttribute::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                  GALGAS_location::constructor_nowhere (HERE),
                                                  GALGAS_lstring::constructor_default (HERE),
                                                  GALGAS_objectAttributes::constructor_default (HERE)
                                                  COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_structAttribute::GALGAS_structAttribute (const cPtr_structAttribute * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_structAttribute) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_structAttribute::readProperty_structName (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_structAttribute * p = (const cPtr_structAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_structAttribute) ;
    return p->mProperty_structName ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_structAttribute::getter_structName (UNUSED_LOCATION_ARGS) const {
  return mProperty_structName ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectAttributes GALGAS_structAttribute::readProperty_subAttributes (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_objectAttributes () ;
  }else{
    const cPtr_structAttribute * p = (const cPtr_structAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_structAttribute) ;
    return p->mProperty_subAttributes ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectAttributes cPtr_structAttribute::getter_subAttributes (UNUSED_LOCATION_ARGS) const {
  return mProperty_subAttributes ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_structAttribute::setter_setStructName (GALGAS_lstring inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_structAttribute * p = (cPtr_structAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_structAttribute) ;
    p->mProperty_structName = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_structAttribute::setter_setStructName (GALGAS_lstring inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_structName = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_structAttribute::setter_setSubAttributes (GALGAS_objectAttributes inValue
                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_structAttribute * p = (cPtr_structAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_structAttribute) ;
    p->mProperty_subAttributes = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_structAttribute::setter_setSubAttributes (GALGAS_objectAttributes inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_subAttributes = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @structAttribute class
//----------------------------------------------------------------------------------------------------------------------

cPtr_structAttribute::cPtr_structAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                            const GALGAS_location & in_location,
                                            const GALGAS_lstring & in_structName,
                                            const GALGAS_objectAttributes & in_subAttributes
                                            COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_structName (in_structName),
mProperty_subAttributes (in_subAttributes) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_structAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_structAttribute ;
}

void cPtr_structAttribute::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@structAttribute:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_structName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_subAttributes.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_structAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_structAttribute (mProperty_oil_5F_desc, mProperty_location, mProperty_structName, mProperty_subAttributes COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@structAttribute type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_structAttribute ("structAttribute",
                                        & kTypeDescriptor_GALGAS_object_5F_t) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_structAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_structAttribute ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_structAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_structAttribute (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool_5F_t::GALGAS_bool_5F_t (void) :
GALGAS_object_5F_t () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool_5F_t GALGAS_bool_5F_t::constructor_default (LOCATION_ARGS) {
  return GALGAS_bool_5F_t::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                            GALGAS_location::constructor_nowhere (HERE),
                                            GALGAS_bool::constructor_default (HERE)
                                            COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool_5F_t::GALGAS_bool_5F_t (const cPtr_bool_5F_t * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_bool_5F_t) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_bool_5F_t::readProperty_value (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_bool_5F_t * p = (const cPtr_bool_5F_t *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_bool_5F_t) ;
    return p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_bool_5F_t::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_bool_5F_t::setter_setValue (GALGAS_bool inValue
                                        COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_bool_5F_t * p = (cPtr_bool_5F_t *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_bool_5F_t) ;
    p->mProperty_value = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_bool_5F_t::setter_setValue (GALGAS_bool inValue
                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @bool_t class
//----------------------------------------------------------------------------------------------------------------------

cPtr_bool_5F_t::cPtr_bool_5F_t (const GALGAS_lstring & in_oil_5F_desc,
                                const GALGAS_location & in_location,
                                const GALGAS_bool & in_value
                                COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_bool_5F_t::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_bool_5F_t ;
}

void cPtr_bool_5F_t::description (C_String & ioString,
                                  const int32_t inIndentation) const {
  ioString << "[@bool_t:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_bool_5F_t::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_bool_5F_t (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@bool_t type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_bool_5F_t ("bool_t",
                                  & kTypeDescriptor_GALGAS_object_5F_t) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_bool_5F_t::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_bool_5F_t ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_bool_5F_t::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_bool_5F_t (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_33__32__5F_class::GALGAS_void_5F_uint_33__32__5F_class (void) :
GALGAS_uint_33__32__5F_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_33__32__5F_class GALGAS_void_5F_uint_33__32__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_void_5F_uint_33__32__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                                GALGAS_location::constructor_nowhere (HERE),
                                                                GALGAS_uint::constructor_default (HERE)
                                                                COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_33__32__5F_class::GALGAS_void_5F_uint_33__32__5F_class (const cPtr_void_5F_uint_33__32__5F_class * inSourcePtr) :
GALGAS_uint_33__32__5F_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_uint_33__32__5F_class) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @void_uint32_class class
//----------------------------------------------------------------------------------------------------------------------

cPtr_void_5F_uint_33__32__5F_class::cPtr_void_5F_uint_33__32__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                                        const GALGAS_location & in_location,
                                                                        const GALGAS_uint & in_value
                                                                        COMMA_LOCATION_ARGS) :
cPtr_uint_33__32__5F_class (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_void_5F_uint_33__32__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_uint_33__32__5F_class ;
}

void cPtr_void_5F_uint_33__32__5F_class::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "[@void_uint32_class:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_void_5F_uint_33__32__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void_5F_uint_33__32__5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@void_uint32_class type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void_5F_uint_33__32__5F_class ("void_uint32_class",
                                                      & kTypeDescriptor_GALGAS_uint_33__32__5F_class) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_void_5F_uint_33__32__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_uint_33__32__5F_class ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_void_5F_uint_33__32__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_uint_33__32__5F_class (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_sint_33__32__5F_class::GALGAS_void_5F_sint_33__32__5F_class (void) :
GALGAS_sint_33__32__5F_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_sint_33__32__5F_class GALGAS_void_5F_sint_33__32__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_void_5F_sint_33__32__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                                GALGAS_location::constructor_nowhere (HERE),
                                                                GALGAS_sint::constructor_default (HERE)
                                                                COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_sint_33__32__5F_class::GALGAS_void_5F_sint_33__32__5F_class (const cPtr_void_5F_sint_33__32__5F_class * inSourcePtr) :
GALGAS_sint_33__32__5F_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_sint_33__32__5F_class) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @void_sint32_class class
//----------------------------------------------------------------------------------------------------------------------

cPtr_void_5F_sint_33__32__5F_class::cPtr_void_5F_sint_33__32__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                                        const GALGAS_location & in_location,
                                                                        const GALGAS_sint & in_value
                                                                        COMMA_LOCATION_ARGS) :
cPtr_sint_33__32__5F_class (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_void_5F_sint_33__32__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_sint_33__32__5F_class ;
}

void cPtr_void_5F_sint_33__32__5F_class::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "[@void_sint32_class:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_void_5F_sint_33__32__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void_5F_sint_33__32__5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@void_sint32_class type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void_5F_sint_33__32__5F_class ("void_sint32_class",
                                                      & kTypeDescriptor_GALGAS_sint_33__32__5F_class) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_void_5F_sint_33__32__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_sint_33__32__5F_class ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_void_5F_sint_33__32__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_sint_33__32__5F_class (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_36__34__5F_class::GALGAS_void_5F_uint_36__34__5F_class (void) :
GALGAS_uint_36__34__5F_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_36__34__5F_class GALGAS_void_5F_uint_36__34__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_void_5F_uint_36__34__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                                GALGAS_location::constructor_nowhere (HERE),
                                                                GALGAS_uint_36__34_::constructor_default (HERE)
                                                                COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_36__34__5F_class::GALGAS_void_5F_uint_36__34__5F_class (const cPtr_void_5F_uint_36__34__5F_class * inSourcePtr) :
GALGAS_uint_36__34__5F_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_uint_36__34__5F_class) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @void_uint64_class class
//----------------------------------------------------------------------------------------------------------------------

cPtr_void_5F_uint_36__34__5F_class::cPtr_void_5F_uint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                                        const GALGAS_location & in_location,
                                                                        const GALGAS_uint_36__34_ & in_value
                                                                        COMMA_LOCATION_ARGS) :
cPtr_uint_36__34__5F_class (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_void_5F_uint_36__34__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_uint_36__34__5F_class ;
}

void cPtr_void_5F_uint_36__34__5F_class::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "[@void_uint64_class:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_void_5F_uint_36__34__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void_5F_uint_36__34__5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@void_uint64_class type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void_5F_uint_36__34__5F_class ("void_uint64_class",
                                                      & kTypeDescriptor_GALGAS_uint_36__34__5F_class) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_void_5F_uint_36__34__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_uint_36__34__5F_class ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_void_5F_uint_36__34__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_uint_36__34__5F_class (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_void_5F_sint_36__34__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void_5F_sint_36__34__5F_class * p = (const cPtr_void_5F_sint_36__34__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void_5F_sint_36__34__5F_class) ;
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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_sint_36__34__5F_class::GALGAS_void_5F_sint_36__34__5F_class (void) :
GALGAS_sint_36__34__5F_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_sint_36__34__5F_class GALGAS_void_5F_sint_36__34__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_void_5F_sint_36__34__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                                GALGAS_location::constructor_nowhere (HERE),
                                                                GALGAS_sint_36__34_::constructor_default (HERE)
                                                                COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_sint_36__34__5F_class::GALGAS_void_5F_sint_36__34__5F_class (const cPtr_void_5F_sint_36__34__5F_class * inSourcePtr) :
GALGAS_sint_36__34__5F_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_sint_36__34__5F_class) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @void_sint64_class class
//----------------------------------------------------------------------------------------------------------------------

cPtr_void_5F_sint_36__34__5F_class::cPtr_void_5F_sint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                                        const GALGAS_location & in_location,
                                                                        const GALGAS_sint_36__34_ & in_value
                                                                        COMMA_LOCATION_ARGS) :
cPtr_sint_36__34__5F_class (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_void_5F_sint_36__34__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_sint_36__34__5F_class ;
}

void cPtr_void_5F_sint_36__34__5F_class::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "[@void_sint64_class:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_void_5F_sint_36__34__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void_5F_sint_36__34__5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@void_sint64_class type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void_5F_sint_36__34__5F_class ("void_sint64_class",
                                                      & kTypeDescriptor_GALGAS_sint_36__34__5F_class) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_void_5F_sint_36__34__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_sint_36__34__5F_class ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_void_5F_sint_36__34__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_sint_36__34__5F_class (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_void_5F_float_5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void_5F_float_5F_class * p = (const cPtr_void_5F_float_5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void_5F_float_5F_class) ;
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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_float_5F_class::GALGAS_void_5F_float_5F_class (void) :
GALGAS_float_5F_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_float_5F_class GALGAS_void_5F_float_5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_void_5F_float_5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                         GALGAS_location::constructor_nowhere (HERE),
                                                         GALGAS_double::constructor_default (HERE)
                                                         COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_float_5F_class::GALGAS_void_5F_float_5F_class (const cPtr_void_5F_float_5F_class * inSourcePtr) :
GALGAS_float_5F_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_float_5F_class) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @void_float_class class
//----------------------------------------------------------------------------------------------------------------------

cPtr_void_5F_float_5F_class::cPtr_void_5F_float_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                          const GALGAS_location & in_location,
                                                          const GALGAS_double & in_value
                                                          COMMA_LOCATION_ARGS) :
cPtr_float_5F_class (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_void_5F_float_5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_float_5F_class ;
}

void cPtr_void_5F_float_5F_class::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@void_float_class:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_void_5F_float_5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void_5F_float_5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@void_float_class type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void_5F_float_5F_class ("void_float_class",
                                               & kTypeDescriptor_GALGAS_float_5F_class) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_void_5F_float_5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_float_5F_class ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_void_5F_float_5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_float_5F_class (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_void_5F_string_5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void_5F_string_5F_class * p = (const cPtr_void_5F_string_5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void_5F_string_5F_class) ;
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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_string_5F_class::GALGAS_void_5F_string_5F_class (void) :
GALGAS_string_5F_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_string_5F_class GALGAS_void_5F_string_5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_void_5F_string_5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                          GALGAS_location::constructor_nowhere (HERE),
                                                          GALGAS_string::constructor_default (HERE)
                                                          COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_string_5F_class::GALGAS_void_5F_string_5F_class (const cPtr_void_5F_string_5F_class * inSourcePtr) :
GALGAS_string_5F_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_string_5F_class) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @void_string_class class
//----------------------------------------------------------------------------------------------------------------------

cPtr_void_5F_string_5F_class::cPtr_void_5F_string_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                            const GALGAS_location & in_location,
                                                            const GALGAS_string & in_value
                                                            COMMA_LOCATION_ARGS) :
cPtr_string_5F_class (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_void_5F_string_5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_string_5F_class ;
}

void cPtr_void_5F_string_5F_class::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@void_string_class:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_void_5F_string_5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void_5F_string_5F_class (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@void_string_class type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void_5F_string_5F_class ("void_string_class",
                                                & kTypeDescriptor_GALGAS_string_5F_class) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_void_5F_string_5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_string_5F_class ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_void_5F_string_5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_string_5F_class (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_void_5F_bool_5F_t::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void_5F_bool_5F_t * p = (const cPtr_void_5F_bool_5F_t *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void_5F_bool_5F_t) ;
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

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_bool_5F_t::GALGAS_void_5F_bool_5F_t (void) :
GALGAS_bool_5F_t () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_bool_5F_t GALGAS_void_5F_bool_5F_t::constructor_default (LOCATION_ARGS) {
  return GALGAS_void_5F_bool_5F_t::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                    GALGAS_location::constructor_nowhere (HERE),
                                                    GALGAS_bool::constructor_default (HERE)
                                                    COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_bool_5F_t::GALGAS_void_5F_bool_5F_t (const cPtr_void_5F_bool_5F_t * inSourcePtr) :
GALGAS_bool_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_bool_5F_t) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @void_bool_t class
//----------------------------------------------------------------------------------------------------------------------

cPtr_void_5F_bool_5F_t::cPtr_void_5F_bool_5F_t (const GALGAS_lstring & in_oil_5F_desc,
                                                const GALGAS_location & in_location,
                                                const GALGAS_bool & in_value
                                                COMMA_LOCATION_ARGS) :
cPtr_bool_5F_t (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_void_5F_bool_5F_t::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_bool_5F_t ;
}

void cPtr_void_5F_bool_5F_t::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@void_bool_t:" ;
  mProperty_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_void_5F_bool_5F_t::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void_5F_bool_5F_t (mProperty_oil_5F_desc, mProperty_location, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@void_bool_t type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void_5F_bool_5F_t ("void_bool_t",
                                          & kTypeDescriptor_GALGAS_bool_5F_t) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_void_5F_bool_5F_t::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_bool_5F_t ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_void_5F_bool_5F_t::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_bool_5F_t (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------



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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_oil_5F_obj::GALGAS_oil_5F_obj (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_oil_5F_obj::GALGAS_oil_5F_obj (const cPtr_oil_5F_obj * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_oil_5F_obj) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_oil_5F_obj::readProperty_desc (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_oil_5F_obj * p = (const cPtr_oil_5F_obj *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_oil_5F_obj) ;
    return p->mProperty_desc ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_oil_5F_obj::getter_desc (UNUSED_LOCATION_ARGS) const {
  return mProperty_desc ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_oil_5F_obj::setter_setDesc (GALGAS_lstring inValue
                                        COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_oil_5F_obj * p = (cPtr_oil_5F_obj *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_oil_5F_obj) ;
    p->mProperty_desc = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_oil_5F_obj::setter_setDesc (GALGAS_lstring inValue
                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_desc = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @oil_obj class
//----------------------------------------------------------------------------------------------------------------------

cPtr_oil_5F_obj::cPtr_oil_5F_obj (const GALGAS_lstring & in_desc
                                  COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_desc (in_desc) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//@oil_obj type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_oil_5F_obj ("oil_obj",
                                   NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_oil_5F_obj::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_oil_5F_obj ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_oil_5F_obj::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_oil_5F_obj (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@object_t set'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_object_5F_t::method_set (const GALGAS_lstring constinArgument_name,
                                   GALGAS_gtlData & /* ioArgument_result */,
                                   C_Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 28)), GALGAS_string ("Attribute: ").add_operation (constinArgument_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 28)).add_operation (GALGAS_string (", Internal error"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 28)), fixItArray0  COMMA_SOURCE_FILE ("systemConfig.galgas", 28)) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_set (cPtr_object_5F_t * inObject,
                              const GALGAS_lstring constin_name,
                              GALGAS_gtlData & io_result,
                              C_Compiler * inCompiler
                              COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_object_5F_t) ;
    inObject->method_set  (constin_name, io_result, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_applicationDefinition::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_applicationDefinition) ;
  if (kOperandEqual == result) {
    result = mProperty_name.objectCompare (p->mProperty_name) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_cpuDescription.objectCompare (p->mProperty_cpuDescription) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_version.objectCompare (p->mProperty_version) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_versionDescription.objectCompare (p->mProperty_versionDescription) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_objects.objectCompare (p->mProperty_objects) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_applicationDefinition::objectCompare (const GALGAS_applicationDefinition & inOperand) const {
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

GALGAS_applicationDefinition::GALGAS_applicationDefinition (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_applicationDefinition GALGAS_applicationDefinition::constructor_default (LOCATION_ARGS) {
  return GALGAS_applicationDefinition::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_objectsMap::constructor_emptyMap (HERE)
                                                        COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_applicationDefinition::GALGAS_applicationDefinition (const cPtr_applicationDefinition * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_applicationDefinition) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_applicationDefinition GALGAS_applicationDefinition::constructor_new (const GALGAS_lstring & inAttribute_name,
                                                                            const GALGAS_lstring & inAttribute_cpuDescription,
                                                                            const GALGAS_lstring & inAttribute_version,
                                                                            const GALGAS_lstring & inAttribute_versionDescription,
                                                                            const GALGAS_objectsMap & inAttribute_objects
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_applicationDefinition result ;
  if (inAttribute_name.isValid () && inAttribute_cpuDescription.isValid () && inAttribute_version.isValid () && inAttribute_versionDescription.isValid () && inAttribute_objects.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_applicationDefinition (inAttribute_name, inAttribute_cpuDescription, inAttribute_version, inAttribute_versionDescription, inAttribute_objects COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_applicationDefinition::readProperty_name (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    return p->mProperty_name ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_applicationDefinition::getter_name (UNUSED_LOCATION_ARGS) const {
  return mProperty_name ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_applicationDefinition::readProperty_cpuDescription (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    return p->mProperty_cpuDescription ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_applicationDefinition::getter_cpuDescription (UNUSED_LOCATION_ARGS) const {
  return mProperty_cpuDescription ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_applicationDefinition::readProperty_version (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    return p->mProperty_version ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_applicationDefinition::getter_version (UNUSED_LOCATION_ARGS) const {
  return mProperty_version ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_applicationDefinition::readProperty_versionDescription (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    return p->mProperty_versionDescription ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_applicationDefinition::getter_versionDescription (UNUSED_LOCATION_ARGS) const {
  return mProperty_versionDescription ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap GALGAS_applicationDefinition::readProperty_objects (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_objectsMap () ;
  }else{
    const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    return p->mProperty_objects ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap cPtr_applicationDefinition::getter_objects (UNUSED_LOCATION_ARGS) const {
  return mProperty_objects ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_applicationDefinition::setter_setName (GALGAS_lstring inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_applicationDefinition * p = (cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    p->mProperty_name = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_applicationDefinition::setter_setName (GALGAS_lstring inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_name = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_applicationDefinition::setter_setCpuDescription (GALGAS_lstring inValue
                                                             COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_applicationDefinition * p = (cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    p->mProperty_cpuDescription = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_applicationDefinition::setter_setCpuDescription (GALGAS_lstring inValue
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_cpuDescription = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_applicationDefinition::setter_setVersion (GALGAS_lstring inValue
                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_applicationDefinition * p = (cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    p->mProperty_version = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_applicationDefinition::setter_setVersion (GALGAS_lstring inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_version = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_applicationDefinition::setter_setVersionDescription (GALGAS_lstring inValue
                                                                 COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_applicationDefinition * p = (cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    p->mProperty_versionDescription = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_applicationDefinition::setter_setVersionDescription (GALGAS_lstring inValue
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_versionDescription = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_applicationDefinition::setter_setObjects (GALGAS_objectsMap inValue
                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_applicationDefinition * p = (cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    p->mProperty_objects = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_applicationDefinition::setter_setObjects (GALGAS_objectsMap inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_objects = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @applicationDefinition class
//----------------------------------------------------------------------------------------------------------------------

cPtr_applicationDefinition::cPtr_applicationDefinition (const GALGAS_lstring & in_name,
                                                        const GALGAS_lstring & in_cpuDescription,
                                                        const GALGAS_lstring & in_version,
                                                        const GALGAS_lstring & in_versionDescription,
                                                        const GALGAS_objectsMap & in_objects
                                                        COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_name (in_name),
mProperty_cpuDescription (in_cpuDescription),
mProperty_version (in_version),
mProperty_versionDescription (in_versionDescription),
mProperty_objects (in_objects) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_applicationDefinition::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_applicationDefinition ;
}

void cPtr_applicationDefinition::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@applicationDefinition:" ;
  mProperty_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_cpuDescription.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_version.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_versionDescription.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_objects.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_applicationDefinition::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_applicationDefinition (mProperty_name, mProperty_cpuDescription, mProperty_version, mProperty_versionDescription, mProperty_objects COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@applicationDefinition type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_applicationDefinition ("applicationDefinition",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_applicationDefinition::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_applicationDefinition ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_applicationDefinition::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_applicationDefinition (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_applicationDefinition GALGAS_applicationDefinition::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_applicationDefinition result ;
  const GALGAS_applicationDefinition * p = (const GALGAS_applicationDefinition *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_applicationDefinition *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("applicationDefinition", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@applicationDefinition applicationWithDefaults'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_applicationDefinition cPtr_applicationDefinition::getter_applicationWithDefaults (const GALGAS_implementation /* constinArgument_imp */,
                                                                                         C_Compiler */* inCompiler */
                                                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_applicationDefinition result_result ; // Returned variable
  const GALGAS_applicationDefinition temp_0 = this ;
  result_result = temp_0 ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_applicationDefinition callExtensionGetter_applicationWithDefaults (const cPtr_applicationDefinition * inObject,
                                                                          const GALGAS_implementation in_imp,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_applicationDefinition result ;
  if (nullptr != inObject) {
    result = inObject->getter_applicationWithDefaults (in_imp, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@implementationObject verifyApplication'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_implementationObject::method_verifyApplication (const GALGAS_objectKind constinArgument_objectsOfKind,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_objectKindMap enumerator_1281 (constinArgument_objectsOfKind.readProperty_objects (), kENUMERATION_UP) ;
  while (enumerator_1281.hasCurrentObject ()) {
    cEnumerator_implementationObjectMap enumerator_1323 (this->mProperty_attributes, kENUMERATION_UP) ;
    while (enumerator_1323.hasCurrentObject ()) {
      callExtensionMethod_verifyApplication ((cPtr_impType *) enumerator_1323.current_type (HERE).ptr (), enumerator_1281.current_attributes (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 48)) ;
      enumerator_1323.gotoNextObject () ;
    }
    enumerator_1281.gotoNextObject () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyApplication (cPtr_implementationObject * inObject,
                                            const GALGAS_objectKind constin_objectsOfKind,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_implementationObject) ;
    inObject->method_verifyApplication  (constin_objectsOfKind, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@impType verifyApplication'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_impType::method_verifyApplication (const GALGAS_objectAttributes constinArgument_attrs,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_identifierMap enumerator_1559 (constinArgument_attrs.readProperty_objectParams (), kENUMERATION_UP) ;
  while (enumerator_1559.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (kIsEqual, enumerator_1559.current_lkey (HERE).readProperty_string ().objectCompare (this->mProperty_name.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_0) {
        const GALGAS_impType temp_1 = this ;
        callExtensionMethod_verifyMultipleType ((cPtr_impType *) temp_1.ptr (), enumerator_1559.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 58)) ;
      }
    }
    enumerator_1559.gotoNextObject () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyApplication (cPtr_impType * inObject,
                                            const GALGAS_objectAttributes constin_attrs,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_impType) ;
    inObject->method_verifyApplication  (constin_attrs, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@impType verifyType'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_impType::method_verifyType (const GALGAS_object_5F_t constinArgument_attr,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (constinArgument_attr.readProperty_location (), GALGAS_string ("Internal error, a generic type should not be instantiated"), fixItArray0  COMMA_SOURCE_FILE ("semantic_verification.galgas", 66)) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyType (cPtr_impType * inObject,
                                     const GALGAS_object_5F_t constin_attr,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_impType) ;
    inObject->method_verifyType  (constin_attr, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@impType verifyMultipleType'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_impType::method_verifyMultipleType (const GALGAS_object_5F_t constinArgument_attr,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
      GALGAS_multipleAttribute cast_2084_ma ((cPtr_multipleAttribute *) constinArgument_attr.ptr ()) ;
      cEnumerator_identifierList enumerator_2097 (cast_2084_ma.readProperty_items (), kENUMERATION_UP) ;
      while (enumerator_2097.hasCurrentObject ()) {
        const GALGAS_impType temp_0 = this ;
        callExtensionMethod_verifyType ((cPtr_impType *) temp_0.ptr (), enumerator_2097.current_item (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 75)) ;
        enumerator_2097.gotoNextObject () ;
      }
    }else{
      const GALGAS_impType temp_1 = this ;
      callExtensionMethod_verifyType ((cPtr_impType *) temp_1.ptr (), constinArgument_attr, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 78)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyMultipleType (cPtr_impType * inObject,
                                             const GALGAS_object_5F_t constin_attr,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_impType) ;
    inObject->method_verifyMultipleType  (constin_attr, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@objectsMap verifyCrossReferences'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_verifyCrossReferences (const GALGAS_objectsMap inObject,
                                            const GALGAS_implementation constinArgument_imp,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_objectsMap temp_0 = inObject ;
  cEnumerator_objectsMap enumerator_18170 (temp_0, kENUMERATION_UP) ;
  while (enumerator_18170.hasCurrentObject ()) {
    GALGAS_implementationObject var_obj_18237 ;
    constinArgument_imp.readProperty_imp ().method_get (enumerator_18170.current_lkey (HERE), var_obj_18237, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 580)) ;
    const GALGAS_objectsMap temp_1 = inObject ;
    callExtensionMethod_verifyCrossReferences ((cPtr_objectKind *) enumerator_18170.current_objectsOfKind (HERE).ptr (), temp_1, var_obj_18237, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 581)) ;
    enumerator_18170.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_objectKind::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_objectKind * p = (const cPtr_objectKind *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_objectKind) ;
  if (kOperandEqual == result) {
    result = mProperty_objects.objectCompare (p->mProperty_objects) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKind::GALGAS_objectKind (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKind GALGAS_objectKind::constructor_default (LOCATION_ARGS) {
  return GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (HERE)
                                             COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKind::GALGAS_objectKind (const cPtr_objectKind * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_objectKind) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKind GALGAS_objectKind::constructor_new (const GALGAS_objectKindMap & inAttribute_objects
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_objectKind result ;
  if (inAttribute_objects.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_objectKind (inAttribute_objects COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap GALGAS_objectKind::readProperty_objects (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_objectKindMap () ;
  }else{
    const cPtr_objectKind * p = (const cPtr_objectKind *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_objectKind) ;
    return p->mProperty_objects ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap cPtr_objectKind::getter_objects (UNUSED_LOCATION_ARGS) const {
  return mProperty_objects ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectKind::setter_setObjects (GALGAS_objectKindMap inValue
                                           COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_objectKind * p = (cPtr_objectKind *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_objectKind) ;
    p->mProperty_objects = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_objectKind::setter_setObjects (GALGAS_objectKindMap inValue
                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_objects = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @objectKind class
//----------------------------------------------------------------------------------------------------------------------

cPtr_objectKind::cPtr_objectKind (const GALGAS_objectKindMap & in_objects
                                  COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_objects (in_objects) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_objectKind::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectKind ;
}

void cPtr_objectKind::description (C_String & ioString,
                                   const int32_t inIndentation) const {
  ioString << "[@objectKind:" ;
  mProperty_objects.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_objectKind::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_objectKind (mProperty_objects COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@objectKind type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectKind ("objectKind",
                                   NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_objectKind::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectKind ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_objectKind::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectKind (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@object_t verifyCrossReferences'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_object_5F_t::method_verifyCrossReferences (const GALGAS_objectsMap /* constinArgument_allObjects */,
                                                     const GALGAS_impType /* constinArgument_type */,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyCrossReferences (cPtr_object_5F_t * inObject,
                                                const GALGAS_objectsMap constin_allObjects,
                                                const GALGAS_impType constin_type,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_object_5F_t) ;
    inObject->method_verifyCrossReferences  (constin_allObjects, constin_type, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@applicationDefinition verifyCrossReferences'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_applicationDefinition::method_verifyCrossReferences (const GALGAS_implementation constinArgument_imp,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_verifyCrossReferences (this->mProperty_objects, constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 667)) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyCrossReferences (cPtr_applicationDefinition * inObject,
                                                const GALGAS_implementation constin_imp,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_applicationDefinition) ;
    inObject->method_verifyCrossReferences  (constin_imp, inCompiler COMMA_THERE) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_definition_i0_ (GALGAS_implementation & ioArgument_implementation,
                                                                                                       C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION COMMA_SOURCE_FILE ("implementation_parser.galgas", 39)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("implementation_parser.galgas", 39)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 39)) ;
  nt_implementation_5F_object_5F_list_ (ioArgument_implementation, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 41)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 41)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_definition_i0_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION COMMA_SOURCE_FILE ("implementation_parser.galgas", 39)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("implementation_parser.galgas", 39)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 39)) ;
  nt_implementation_5F_object_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 41)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 41)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_ (GALGAS_implementation & ioArgument_implementation,
                                                                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_0 (inCompiler)) {
    case 2: {
      nt_implementation_5F_objects_ (ioArgument_implementation, inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 48)) ;
    } break ;
    case 3: {
      nt_include_5F_implementation_5F_level_ (ioArgument_implementation, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_0 (inCompiler)) {
    case 2: {
      nt_implementation_5F_objects_parse (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 48)) ;
    } break ;
    case 3: {
      nt_include_5F_implementation_5F_level_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_ (GALGAS_implementation & ioArgument_implementation,
                                                                                                             C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_bool var_includeIfExists_1381 = GALGAS_bool (false) ;
  switch (select_implementation_5F_parser_1 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_include COMMA_SOURCE_FILE ("implementation_parser.galgas", 58)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_includeifexists COMMA_SOURCE_FILE ("implementation_parser.galgas", 60)) ;
    var_includeIfExists_1381 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  GALGAS_lstring var_file_5F_name_1489 ;
  switch (select_implementation_5F_parser_2 (inCompiler)) {
  case 1: {
    var_file_5F_name_1489 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_g_5F_string COMMA_SOURCE_FILE ("implementation_parser.galgas", 64)) ;
    {
    routine_file_5F_in_5F_path (var_file_5F_name_1489, inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 65)) ;
    }
  } break ;
  case 2: {
    var_file_5F_name_1489 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("implementation_parser.galgas", 67)) ;
  } break ;
  default:
    break ;
  }
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    GALGAS_bool test_1 = var_includeIfExists_1381.operator_not (SOURCE_FILE ("implementation_parser.galgas", 69)) ;
    if (kBoolTrue != test_1.boolEnum ()) {
      GALGAS_bool test_2 = var_includeIfExists_1381 ;
      if (kBoolTrue == test_2.boolEnum ()) {
        test_2 = var_file_5F_name_1489.readProperty_string ().getter_fileExists (SOURCE_FILE ("implementation_parser.galgas", 69)) ;
      }
      test_1 = test_2 ;
    }
    test_0 = test_1.boolEnum () ;
    if (kBoolTrue == test_0) {
      cGrammar_goil_5F_implementation_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, var_file_5F_name_1489, ioArgument_implementation  COMMA_SOURCE_FILE ("implementation_parser.galgas", 70)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_1 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_include COMMA_SOURCE_FILE ("implementation_parser.galgas", 58)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_includeifexists COMMA_SOURCE_FILE ("implementation_parser.galgas", 60)) ;
  } break ;
  default:
    break ;
  }
  switch (select_implementation_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_g_5F_string COMMA_SOURCE_FILE ("implementation_parser.galgas", 64)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("implementation_parser.galgas", 67)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_include_5F_type_5F_level_i3_ (GALGAS_implementationObjectMap & ioArgument_objectAttributes,
                                                                                                   C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_bool var_includeIfExists_1853 = GALGAS_bool (false) ;
  switch (select_implementation_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_include COMMA_SOURCE_FILE ("implementation_parser.galgas", 79)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_includeifexists COMMA_SOURCE_FILE ("implementation_parser.galgas", 81)) ;
    var_includeIfExists_1853 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  GALGAS_lstring var_file_5F_name_1961 ;
  switch (select_implementation_5F_parser_4 (inCompiler)) {
  case 1: {
    var_file_5F_name_1961 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_g_5F_string COMMA_SOURCE_FILE ("implementation_parser.galgas", 85)) ;
    {
    routine_file_5F_in_5F_path (var_file_5F_name_1961, inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 86)) ;
    }
  } break ;
  case 2: {
    var_file_5F_name_1961 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("implementation_parser.galgas", 88)) ;
  } break ;
  default:
    break ;
  }
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    GALGAS_bool test_1 = var_includeIfExists_1853.operator_not (SOURCE_FILE ("implementation_parser.galgas", 90)) ;
    if (kBoolTrue != test_1.boolEnum ()) {
      GALGAS_bool test_2 = var_includeIfExists_1853 ;
      if (kBoolTrue == test_2.boolEnum ()) {
        test_2 = var_file_5F_name_1961.readProperty_string ().getter_fileExists (SOURCE_FILE ("implementation_parser.galgas", 90)) ;
      }
      test_1 = test_2 ;
    }
    test_0 = test_1.boolEnum () ;
    if (kBoolTrue == test_0) {
      cGrammar_goil_5F_type_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, var_file_5F_name_1961, ioArgument_objectAttributes  COMMA_SOURCE_FILE ("implementation_parser.galgas", 91)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_include_5F_type_5F_level_i3_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_include COMMA_SOURCE_FILE ("implementation_parser.galgas", 79)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_includeifexists COMMA_SOURCE_FILE ("implementation_parser.galgas", 81)) ;
  } break ;
  default:
    break ;
  }
  switch (select_implementation_5F_parser_4 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_g_5F_string COMMA_SOURCE_FILE ("implementation_parser.galgas", 85)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("implementation_parser.galgas", 88)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_objects_i4_ (GALGAS_implementation & ioArgument_implementation,
                                                                                                    C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_implementationMap var_imp_2309 = ioArgument_implementation.readProperty_imp () ;
  GALGAS_lstring var_objectName_2368 = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("implementation_parser.galgas", 100)) ;
  GALGAS_lbool var_multiple_2412 ;
  switch (select_implementation_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 104)) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 104)) ;
    var_multiple_2412 = GALGAS_lbool::constructor_new (GALGAS_bool (true), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 104))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 104)) ;
  } break ;
  case 2: {
    var_multiple_2412 = GALGAS_lbool::constructor_new (GALGAS_bool (false), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 106))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 106)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_implementationObjectMap var_objectAttributes_2629 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 109)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 111)) ;
  nt_implementation_5F_list_ (var_objectAttributes_2629, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 113)) ;
  GALGAS_implementationObject var_newObject_2738 = GALGAS_implementationObject::constructor_new (var_multiple_2412, var_objectAttributes_2629  COMMA_SOURCE_FILE ("implementation_parser.galgas", 115)) ;
  GALGAS_implementationObject var_object_2910 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasKey ((const cPtr_implementation *) ioArgument_implementation.ptr (), var_objectName_2368.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 120)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      var_imp_2309.setter_del (var_objectName_2368, var_object_2910, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 121)) ;
      }
      var_object_2910 = callExtensionGetter_mergeImplementationObjectWith ((const cPtr_implementationObject *) var_object_2910.ptr (), var_newObject_2738, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 122)) ;
    }
  }
  if (kBoolFalse == test_0) {
    var_object_2910 = var_newObject_2738 ;
  }
  {
  var_imp_2309.setter_put (var_objectName_2368, var_object_2910, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 128)) ;
  }
  {
  ioArgument_implementation.setter_setImp (var_imp_2309 COMMA_SOURCE_FILE ("implementation_parser.galgas", 129)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_objects_i4_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("implementation_parser.galgas", 100)) ;
  switch (select_implementation_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 104)) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 104)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 111)) ;
  nt_implementation_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 113)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_list_i5_ (GALGAS_implementationObjectMap & ioArgument_objectAttributes,
                                                                                                 C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_6 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_attributeName_3346 ;
      GALGAS_impType var_type_3364 ;
      nt_implementation_5F_type_ (var_attributeName_3346, var_type_3364, inCompiler) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = ioArgument_objectAttributes.getter_hasKey (var_attributeName_3346.readProperty_string () COMMA_SOURCE_FILE ("implementation_parser.galgas", 140)).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_impType var_previousType_3505 ;
          ioArgument_objectAttributes.method_get (var_attributeName_3346, var_previousType_3505, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 142)) ;
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            test_2 = var_previousType_3505.readProperty_multiple ().boolEnum () ;
            if (kBoolTrue == test_2) {
              GALGAS_object_5F_t var_previousDefaultValue_3855 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) var_previousType_3505.ptr (), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 148)) ;
              GALGAS_object_5F_t var_defaultValue_3923 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) var_type_3364.ptr (), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 149)) ;
              GALGAS_bool var_oneIsMultiple_3976 = GALGAS_bool (false) ;
              enumGalgasBool test_3 = kBoolTrue ;
              if (kBoolTrue == test_3) {
                test_3 = GALGAS_bool (var_previousDefaultValue_3855.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute).boolEnum () ;
                if (kBoolTrue == test_3) {
                  var_oneIsMultiple_3976 = GALGAS_bool (true) ;
                }
              }
              if (kBoolFalse == test_3) {
                enumGalgasBool test_4 = kBoolTrue ;
                if (kBoolTrue == test_4) {
                  test_4 = GALGAS_bool (var_defaultValue_3923.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute).boolEnum () ;
                  if (kBoolTrue == test_4) {
                    var_oneIsMultiple_3976 = GALGAS_bool (true) ;
                  }
                }
              }
              enumGalgasBool test_5 = kBoolTrue ;
              if (kBoolTrue == test_5) {
                test_5 = var_oneIsMultiple_3976.boolEnum () ;
                if (kBoolTrue == test_5) {
                  GALGAS_identifierList var_aList_4397 = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 160)) ;
                  GALGAS_lstring var_desc_4434 = function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 161)) ;
                  GALGAS_location var_location_4480 = GALGAS_location::constructor_nowhere (SOURCE_FILE ("implementation_parser.galgas", 162)) ;
                  if (var_previousDefaultValue_3855.isValid ()) {
                    if (var_previousDefaultValue_3855.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
                      GALGAS_multipleAttribute cast_4612_multiAttribute ((cPtr_multipleAttribute *) var_previousDefaultValue_3855.ptr ()) ;
                      var_aList_4397 = cast_4612_multiAttribute.readProperty_items () ;
                      var_desc_4434 = cast_4612_multiAttribute.readProperty_oil_5F_desc () ;
                      var_location_4480 = cast_4612_multiAttribute.readProperty_location () ;
                    }
                  }
                  if (var_defaultValue_3923.isValid ()) {
                    if (var_defaultValue_3923.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
                      GALGAS_multipleAttribute cast_4886_multiAttribute ((cPtr_multipleAttribute *) var_defaultValue_3923.ptr ()) ;
                      var_aList_4397.plusAssign_operation(cast_4886_multiAttribute.readProperty_items (), inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 175)) ;
                      enumGalgasBool test_6 = kBoolTrue ;
                      if (kBoolTrue == test_6) {
                        test_6 = GALGAS_bool (kIsEqual, var_desc_4434.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
                        if (kBoolTrue == test_6) {
                          var_desc_4434 = cast_4886_multiAttribute.readProperty_oil_5F_desc () ;
                        }
                      }
                      enumGalgasBool test_7 = kBoolTrue ;
                      if (kBoolTrue == test_7) {
                        test_7 = GALGAS_bool (kIsEqual, var_location_4480.objectCompare (GALGAS_location::constructor_nowhere (SOURCE_FILE ("implementation_parser.galgas", 179)))).boolEnum () ;
                        if (kBoolTrue == test_7) {
                          var_location_4480 = cast_4886_multiAttribute.readProperty_location () ;
                        }
                      }
                    }
                  }
                  GALGAS_object_5F_t var_newDefault_5239 = GALGAS_multipleAttribute::constructor_new (var_desc_4434, var_location_4480, var_aList_4397  COMMA_SOURCE_FILE ("implementation_parser.galgas", 185)) ;
                  {
                  var_type_3364.insulate (HERE) ;
                  cPtr_impType * ptr_5345 = (cPtr_impType *) var_type_3364.ptr () ;
                  callExtensionSetter_setDefValue ((cPtr_impType *) ptr_5345, var_newDefault_5239, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 188)) ;
                  }
                  {
                  GALGAS_impType joker_5422 ; // Joker input parameter
                  ioArgument_objectAttributes.setter_del (var_attributeName_3346, joker_5422, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 190)) ;
                  }
                  {
                  ioArgument_objectAttributes.setter_put (var_attributeName_3346, var_type_3364, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 191)) ;
                  }
                }
              }
            }
          }
          enumGalgasBool test_8 = kBoolTrue ;
          if (kBoolTrue == test_8) {
            test_8 = function_checkNewTypeWithinPreviousType (var_attributeName_3346, var_previousType_3505, var_type_3364, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 195)).boolEnum () ;
            if (kBoolTrue == test_8) {
              {
              GALGAS_impType joker_5708 ; // Joker input parameter
              ioArgument_objectAttributes.setter_del (var_attributeName_3346, joker_5708, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 198)) ;
              }
              {
              ioArgument_objectAttributes.setter_put (var_attributeName_3346, var_type_3364, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 199)) ;
              }
            }
          }
        }
      }
      if (kBoolFalse == test_1) {
        {
        ioArgument_objectAttributes.setter_put (var_attributeName_3346, var_type_3364, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 202)) ;
        }
      }
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 204)) ;
    } break ;
    case 3: {
      nt_include_5F_type_5F_level_ (ioArgument_objectAttributes, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_list_i5_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_6 (inCompiler)) {
    case 2: {
      nt_implementation_5F_type_parse (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 204)) ;
    } break ;
    case 3: {
      nt_include_5F_type_5F_level_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_type_i6_ (GALGAS_lstring & outArgument_attributeName,
                                                                                                 GALGAS_impType & outArgument_type,
                                                                                                 C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_attributeName.drop () ; // Release 'out' argument
  outArgument_type.drop () ; // Release 'out' argument
  switch (select_implementation_5F_parser_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 214)) ;
    nt_number_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 214)), inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_INT_33__32_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 216)) ;
    nt_number_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 216)), inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 218)) ;
    nt_number_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 218)), inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_INT_36__34_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 220)) ;
    nt_number_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 220)), inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_FLOAT COMMA_SOURCE_FILE ("implementation_parser.galgas", 222)) ;
    nt_number_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_parser.galgas", 222)), inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_ENUM COMMA_SOURCE_FILE ("implementation_parser.galgas", 224)) ;
    nt_enum_5F_options_ (outArgument_attributeName, outArgument_type, inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_BOOLEAN COMMA_SOURCE_FILE ("implementation_parser.galgas", 226)) ;
    nt_boolean_5F_options_ (outArgument_attributeName, outArgument_type, inCompiler) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_STRING COMMA_SOURCE_FILE ("implementation_parser.galgas", 228)) ;
    nt_string_5F_options_ (outArgument_attributeName, outArgument_type, inCompiler) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER COMMA_SOURCE_FILE ("implementation_parser.galgas", 230)) ;
    nt_type_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_identifier (SOURCE_FILE ("implementation_parser.galgas", 230)), inCompiler) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_STRUCT COMMA_SOURCE_FILE ("implementation_parser.galgas", 232)) ;
    nt_struct_5F_options_ (outArgument_attributeName, outArgument_type, inCompiler) ;
  } break ;
  case 11: {
    GALGAS_lstring var_typeName_6727 ;
    var_typeName_6727 = inCompiler->synthetizedAttribute_att_5F_token () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("implementation_parser.galgas", 234)) ;
    nt_objref_5F_option_ (outArgument_attributeName, outArgument_type, var_typeName_6727, inCompiler) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_type_i6_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 214)) ;
    nt_number_5F_options_parse (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_INT_33__32_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 216)) ;
    nt_number_5F_options_parse (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 218)) ;
    nt_number_5F_options_parse (inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_INT_36__34_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 220)) ;
    nt_number_5F_options_parse (inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_FLOAT COMMA_SOURCE_FILE ("implementation_parser.galgas", 222)) ;
    nt_number_5F_options_parse (inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_ENUM COMMA_SOURCE_FILE ("implementation_parser.galgas", 224)) ;
    nt_enum_5F_options_parse (inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_BOOLEAN COMMA_SOURCE_FILE ("implementation_parser.galgas", 226)) ;
    nt_boolean_5F_options_parse (inCompiler) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_STRING COMMA_SOURCE_FILE ("implementation_parser.galgas", 228)) ;
    nt_string_5F_options_parse (inCompiler) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER COMMA_SOURCE_FILE ("implementation_parser.galgas", 230)) ;
    nt_type_5F_options_parse (inCompiler) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_STRUCT COMMA_SOURCE_FILE ("implementation_parser.galgas", 232)) ;
    nt_struct_5F_options_parse (inCompiler) ;
  } break ;
  case 11: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("implementation_parser.galgas", 234)) ;
    nt_objref_5F_option_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_struct_5F_options_i7_ (GALGAS_lstring & outArgument_name,
                                                                                            GALGAS_impType & outArgument_options,
                                                                                            C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_implementationObjectMap var_structAttributes_6883 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 241)) ;
  switch (select_implementation_5F_parser_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 243)) ;
    nt_implementation_5F_list_ (var_structAttributes_6883, inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 245)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple_7055 ;
  nt_multiple_ (var_multiple_7055, inCompiler) ;
  GALGAS_lstring var_description_7105 ;
  nt_description_ (var_description_7105, inCompiler) ;
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 252)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 252))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 252)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 252)) ;
  temp_1.addAssign_operation (var_description_7105  COMMA_SOURCE_FILE ("implementation_parser.galgas", 252)) ;
  outArgument_options = GALGAS_impStructType::constructor_new (temp_0, GALGAS_dataType::constructor_structType (SOURCE_FILE ("implementation_parser.galgas", 252)), outArgument_name, var_multiple_7055, temp_1, var_structAttributes_6883  COMMA_SOURCE_FILE ("implementation_parser.galgas", 252)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_struct_5F_options_i7_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 243)) ;
    nt_implementation_5F_list_parse (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 245)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  nt_description_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_objref_5F_option_i8_ (GALGAS_lstring & outArgument_name,
                                                                                           GALGAS_impType & outArgument_options,
                                                                                           GALGAS_lstring inArgument_ref,
                                                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, inArgument_ref.readProperty_string ().getter_rightSubString (GALGAS_uint (uint32_t (5U)) COMMA_SOURCE_FILE ("implementation_parser.galgas", 259)).objectCompare (GALGAS_string ("_TYPE"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 260)), GALGAS_string ("an object reference must end with _TYPE"), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 260)) ;
    }
  }
  if (kBoolFalse == test_0) {
    inArgument_ref = GALGAS_lstring::constructor_new (inArgument_ref.readProperty_string ().getter_leftSubString (inArgument_ref.readProperty_string ().getter_length (SOURCE_FILE ("implementation_parser.galgas", 262)).substract_operation (GALGAS_uint (uint32_t (5U)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 262)) COMMA_SOURCE_FILE ("implementation_parser.galgas", 262)), inArgument_ref.readProperty_location ()  COMMA_SOURCE_FILE ("implementation_parser.galgas", 262)) ;
  }
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple_7610 ;
  nt_multiple_ (var_multiple_7610, inCompiler) ;
  GALGAS_lstring var_description_7660 ;
  nt_description_ (var_description_7660, inCompiler) ;
  GALGAS_locationList temp_2 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 269)) ;
  temp_2.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 269))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 269)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 269)) ;
  temp_3.addAssign_operation (var_description_7660  COMMA_SOURCE_FILE ("implementation_parser.galgas", 269)) ;
  outArgument_options = GALGAS_refType::constructor_new (temp_2, GALGAS_dataType::constructor_objectType (SOURCE_FILE ("implementation_parser.galgas", 269)), outArgument_name, var_multiple_7610, temp_3, inArgument_ref  COMMA_SOURCE_FILE ("implementation_parser.galgas", 269)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_objref_5F_option_i8_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  nt_description_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_string_5F_options_i9_ (GALGAS_lstring & outArgument_name,
                                                                                            GALGAS_impType & outArgument_options,
                                                                                            C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_bool var_withAuto_7885 ;
  nt_with_5F_auto_ (var_withAuto_7885, inCompiler) ;
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple_7964 ;
  nt_multiple_ (var_multiple_7964, inCompiler) ;
  GALGAS_object_5F_t var_defaultValue_8016 ;
  GALGAS_lstring var_oil_5F_desc_8040 ;
  switch (select_implementation_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 284)) ;
    switch (select_implementation_5F_parser_10 (inCompiler)) {
    case 1: {
      GALGAS_lstring var_stringValue_8109 = inCompiler->synthetizedAttribute_a_5F_string () ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("implementation_parser.galgas", 286)) ;
      nt_description_ (var_oil_5F_desc_8040, inCompiler) ;
      GALGAS_object_5F_t var_val_8163 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_8040, var_stringValue_8109.readProperty_location (), var_stringValue_8109.readProperty_string ()  COMMA_SOURCE_FILE ("implementation_parser.galgas", 288)) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = var_multiple_7964.boolEnum () ;
        if (kBoolTrue == test_0) {
          var_defaultValue_8016 = GALGAS_multipleAttribute::constructor_new (var_oil_5F_desc_8040, var_stringValue_8109.readProperty_location (), GALGAS_identifierList::constructor_listWithValue (var_val_8163  COMMA_SOURCE_FILE ("implementation_parser.galgas", 290))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 290)) ;
        }
      }
      if (kBoolFalse == test_0) {
        var_defaultValue_8016 = var_val_8163 ;
      }
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_AUTO COMMA_SOURCE_FILE ("implementation_parser.galgas", 295)) ;
      nt_description_ (var_oil_5F_desc_8040, inCompiler) ;
      var_defaultValue_8016 = GALGAS_auto::constructor_new (var_oil_5F_desc_8040, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 297))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 297)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT COMMA_SOURCE_FILE ("implementation_parser.galgas", 299)) ;
      nt_description_ (var_oil_5F_desc_8040, inCompiler) ;
      var_defaultValue_8016 = GALGAS_void::constructor_new (var_oil_5F_desc_8040, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 301))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 301)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_ (var_oil_5F_desc_8040, inCompiler) ;
    var_defaultValue_8016 = GALGAS_void::constructor_new (var_oil_5F_desc_8040, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 305))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 305)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_locationList temp_1 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 307)) ;
  temp_1.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 307))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 307)) ;
  GALGAS_lstringlist temp_2 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 307)) ;
  temp_2.addAssign_operation (var_oil_5F_desc_8040  COMMA_SOURCE_FILE ("implementation_parser.galgas", 307)) ;
  outArgument_options = GALGAS_impAutoDefaultType::constructor_new (temp_1, GALGAS_dataType::constructor_string (SOURCE_FILE ("implementation_parser.galgas", 307)), outArgument_name, var_multiple_7964, temp_2, var_withAuto_7885, var_defaultValue_8016  COMMA_SOURCE_FILE ("implementation_parser.galgas", 307)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_string_5F_options_i9_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_with_5F_auto_parse (inCompiler) ;
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  switch (select_implementation_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 284)) ;
    switch (select_implementation_5F_parser_10 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_string COMMA_SOURCE_FILE ("implementation_parser.galgas", 286)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_AUTO COMMA_SOURCE_FILE ("implementation_parser.galgas", 295)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT COMMA_SOURCE_FILE ("implementation_parser.galgas", 299)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_boolean_5F_options_i10_ (GALGAS_lstring & outArgument_name,
                                                                                              GALGAS_impType & outArgument_options,
                                                                                              C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_bool var_withAuto_8985 ;
  nt_with_5F_auto_ (var_withAuto_8985, inCompiler) ;
  GALGAS_implementationObjectMap var_trueSubAttributes_9033 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 315)) ;
  GALGAS_implementationObjectMap var_falseSubAttributes_9095 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 316)) ;
  switch (select_implementation_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 318)) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_TRUE COMMA_SOURCE_FILE ("implementation_parser.galgas", 319)) ;
    switch (select_implementation_5F_parser_12 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 321)) ;
      nt_implementation_5F_list_ (var_trueSubAttributes_9033, inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 323)) ;
    } break ;
    case 2: {
      var_trueSubAttributes_9033 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 325)) ;
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__2C_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 327)) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_FALSE COMMA_SOURCE_FILE ("implementation_parser.galgas", 328)) ;
    switch (select_implementation_5F_parser_13 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 330)) ;
      nt_implementation_5F_list_ (var_falseSubAttributes_9095, inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 332)) ;
    } break ;
    case 2: {
      var_falseSubAttributes_9095 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 334)) ;
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 336)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple_9566 ;
  nt_multiple_ (var_multiple_9566, inCompiler) ;
  GALGAS_object_5F_t var_defaultValue_9618 ;
  GALGAS_lstring var_oil_5F_desc_9642 ;
  switch (select_implementation_5F_parser_14 (inCompiler)) {
  case 1: {
    GALGAS_lbool var_boolValue_9676 ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 345)) ;
    nt_boolean_ (var_boolValue_9676, inCompiler) ;
    nt_description_ (var_oil_5F_desc_9642, inCompiler) ;
    var_defaultValue_9618 = GALGAS_boolAttribute::constructor_new (var_oil_5F_desc_9642, var_boolValue_9676.readProperty_location (), var_boolValue_9676.readProperty_bool (), GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 347))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 347))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 347)) ;
  } break ;
  case 2: {
    nt_description_ (var_oil_5F_desc_9642, inCompiler) ;
    var_defaultValue_9618 = GALGAS_void::constructor_new (var_oil_5F_desc_9642, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 350))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 350)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 352)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 352))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 352)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 352)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_9642  COMMA_SOURCE_FILE ("implementation_parser.galgas", 352)) ;
  outArgument_options = GALGAS_impBoolType::constructor_new (temp_0, GALGAS_dataType::constructor_boolean (SOURCE_FILE ("implementation_parser.galgas", 352)), outArgument_name, var_multiple_9566, temp_1, var_withAuto_8985, var_defaultValue_9618, var_trueSubAttributes_9033, var_falseSubAttributes_9095  COMMA_SOURCE_FILE ("implementation_parser.galgas", 352)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_boolean_5F_options_i10_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_with_5F_auto_parse (inCompiler) ;
  switch (select_implementation_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 318)) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_TRUE COMMA_SOURCE_FILE ("implementation_parser.galgas", 319)) ;
    switch (select_implementation_5F_parser_12 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 321)) ;
      nt_implementation_5F_list_parse (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 323)) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__2C_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 327)) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_FALSE COMMA_SOURCE_FILE ("implementation_parser.galgas", 328)) ;
    switch (select_implementation_5F_parser_13 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 330)) ;
      nt_implementation_5F_list_parse (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 332)) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 336)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  switch (select_implementation_5F_parser_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 345)) ;
    nt_boolean_parse (inCompiler) ;
    nt_description_parse (inCompiler) ;
  } break ;
  case 2: {
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_enum_5F_item_i11_ (GALGAS_enumValues & ioArgument_items,
                                                                                        C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_lstring var_enumItem_10207 ;
  GALGAS_implementationObjectMap var_subAttributes_10227 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 358)) ;
  nt_identifier_5F_or_5F_enum_5F_value_ (var_enumItem_10207, inCompiler) ;
  switch (select_implementation_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 361)) ;
    nt_implementation_5F_list_ (var_subAttributes_10227, inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 363)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  {
  ioArgument_items.setter_put (var_enumItem_10207, var_subAttributes_10227, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 365)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_enum_5F_item_i11_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_identifier_5F_or_5F_enum_5F_value_parse (inCompiler) ;
  switch (select_implementation_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 361)) ;
    nt_implementation_5F_list_parse (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__7D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 363)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_enum_5F_options_i12_ (GALGAS_lstring & outArgument_name,
                                                                                           GALGAS_impType & outArgument_options,
                                                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_bool var_withAuto_10503 ;
  nt_with_5F_auto_ (var_withAuto_10503, inCompiler) ;
  GALGAS_enumValues var_items_10539 = GALGAS_enumValues::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 373)) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 374)) ;
  nt_enum_5F_item_ (var_items_10539, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_16 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__2C_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 378)) ;
      nt_enum_5F_item_ (var_items_10539, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 380)) ;
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple_10703 ;
  nt_multiple_ (var_multiple_10703, inCompiler) ;
  GALGAS_lstring var_oil_5F_desc_10750 ;
  GALGAS_object_5F_t var_defaultValue_10779 ;
  switch (select_implementation_5F_parser_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 387)) ;
    switch (select_implementation_5F_parser_18 (inCompiler)) {
    case 1: {
      GALGAS_lstring var_stringValue_10838 ;
      var_stringValue_10838 = inCompiler->synthetizedAttribute_att_5F_token () ;
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("implementation_parser.galgas", 390)) ;
      nt_description_ (var_oil_5F_desc_10750, inCompiler) ;
      GALGAS_object_5F_t var_val_10917 = GALGAS_enumAttribute::constructor_new (var_oil_5F_desc_10750, var_stringValue_10838.readProperty_location (), var_stringValue_10838.readProperty_string (), GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 392))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 392))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 392)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = var_multiple_10703.boolEnum () ;
        if (kBoolTrue == test_1) {
          var_defaultValue_10779 = GALGAS_multipleAttribute::constructor_new (var_oil_5F_desc_10750, var_stringValue_10838.readProperty_location (), GALGAS_identifierList::constructor_listWithValue (var_val_10917  COMMA_SOURCE_FILE ("implementation_parser.galgas", 394))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 394)) ;
        }
      }
      if (kBoolFalse == test_1) {
        var_defaultValue_10779 = var_val_10917 ;
      }
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_AUTO COMMA_SOURCE_FILE ("implementation_parser.galgas", 399)) ;
      nt_description_ (var_oil_5F_desc_10750, inCompiler) ;
      var_defaultValue_10779 = GALGAS_auto::constructor_new (var_oil_5F_desc_10750, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 401))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 401)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT COMMA_SOURCE_FILE ("implementation_parser.galgas", 403)) ;
      nt_description_ (var_oil_5F_desc_10750, inCompiler) ;
      var_defaultValue_10779 = GALGAS_void::constructor_new (var_oil_5F_desc_10750, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 405))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 405)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_ (var_oil_5F_desc_10750, inCompiler) ;
    var_defaultValue_10779 = GALGAS_void::constructor_new (var_oil_5F_desc_10750, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 409))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 409)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 411)) ;
  temp_2.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 411))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 411)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 411)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_10750  COMMA_SOURCE_FILE ("implementation_parser.galgas", 411)) ;
  outArgument_options = GALGAS_impEnumType::constructor_new (temp_2, GALGAS_dataType::constructor_enumeration (SOURCE_FILE ("implementation_parser.galgas", 411)), outArgument_name, var_multiple_10703, temp_3, var_withAuto_10503, var_defaultValue_10779, var_items_10539  COMMA_SOURCE_FILE ("implementation_parser.galgas", 411)) ;
  {
  routine_verifyEnum (outArgument_options, inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 412)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_enum_5F_options_i12_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_with_5F_auto_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 374)) ;
  nt_enum_5F_item_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_16 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__2C_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 378)) ;
      nt_enum_5F_item_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 380)) ;
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  switch (select_implementation_5F_parser_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 387)) ;
    switch (select_implementation_5F_parser_18 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("implementation_parser.galgas", 390)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_AUTO COMMA_SOURCE_FILE ("implementation_parser.galgas", 399)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT COMMA_SOURCE_FILE ("implementation_parser.galgas", 403)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_number_5F_options_i13_ (GALGAS_lstring & outArgument_name,
                                                                                             GALGAS_impType & outArgument_options,
                                                                                             const GALGAS_dataType constinArgument_type,
                                                                                             C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_bool var_withAuto_11844 ;
  nt_with_5F_auto_ (var_withAuto_11844, inCompiler) ;
  GALGAS_attributeRange var_range_11896 ;
  nt_range_ (var_range_11896, constinArgument_type, inCompiler) ;
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple_11974 ;
  nt_multiple_ (var_multiple_11974, inCompiler) ;
  GALGAS_lstring var_oil_5F_desc_12021 ;
  GALGAS_object_5F_t var_defaultValue_12050 ;
  switch (select_implementation_5F_parser_19 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 429)) ;
    switch (select_implementation_5F_parser_20 (inCompiler)) {
    case 1: {
      GALGAS_object_5F_t var_val_12118 ;
      nt_int_5F_or_5F_float_ (var_val_12118, constinArgument_type, inCompiler) ;
      var_oil_5F_desc_12021 = var_val_12118.readProperty_oil_5F_desc () ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = var_multiple_11974.boolEnum () ;
        if (kBoolTrue == test_0) {
          var_defaultValue_12050 = GALGAS_multipleAttribute::constructor_new (var_oil_5F_desc_12021, var_val_12118.readProperty_location (), GALGAS_identifierList::constructor_listWithValue (var_val_12118  COMMA_SOURCE_FILE ("implementation_parser.galgas", 434))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 434)) ;
        }
      }
      if (kBoolFalse == test_0) {
        var_defaultValue_12050 = var_val_12118 ;
      }
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT COMMA_SOURCE_FILE ("implementation_parser.galgas", 439)) ;
      nt_description_ (var_oil_5F_desc_12021, inCompiler) ;
      var_defaultValue_12050 = GALGAS_void::constructor_new (var_oil_5F_desc_12021, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 441))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 441)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_AUTO COMMA_SOURCE_FILE ("implementation_parser.galgas", 443)) ;
      nt_description_ (var_oil_5F_desc_12021, inCompiler) ;
      var_defaultValue_12050 = GALGAS_auto::constructor_new (var_oil_5F_desc_12021, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 445))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 445)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_ (var_oil_5F_desc_12021, inCompiler) ;
    var_defaultValue_12050 = GALGAS_void::constructor_new (var_oil_5F_desc_12021, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 449))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 449)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_locationList temp_1 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 451)) ;
  temp_1.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 451))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 451)) ;
  GALGAS_lstringlist temp_2 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 451)) ;
  temp_2.addAssign_operation (var_oil_5F_desc_12021  COMMA_SOURCE_FILE ("implementation_parser.galgas", 451)) ;
  outArgument_options = GALGAS_impRangedType::constructor_new (temp_1, constinArgument_type, outArgument_name, var_multiple_11974, temp_2, var_withAuto_11844, var_defaultValue_12050, var_range_11896  COMMA_SOURCE_FILE ("implementation_parser.galgas", 451)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_number_5F_options_i13_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_with_5F_auto_parse (inCompiler) ;
  nt_range_parse (inCompiler) ;
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  switch (select_implementation_5F_parser_19 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 429)) ;
    switch (select_implementation_5F_parser_20 (inCompiler)) {
    case 1: {
      nt_int_5F_or_5F_float_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT COMMA_SOURCE_FILE ("implementation_parser.galgas", 439)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_AUTO COMMA_SOURCE_FILE ("implementation_parser.galgas", 443)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_type_5F_options_i14_ (GALGAS_lstring & outArgument_name,
                                                                                           GALGAS_impType & outArgument_options,
                                                                                           const GALGAS_dataType constinArgument_type,
                                                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_bool var_withAuto_12898 ;
  nt_with_5F_auto_ (var_withAuto_12898, inCompiler) ;
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple_12977 ;
  nt_multiple_ (var_multiple_12977, inCompiler) ;
  GALGAS_object_5F_t var_defaultValue_13029 ;
  GALGAS_lstring var_oil_5F_desc_13053 ;
  switch (select_implementation_5F_parser_21 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 466)) ;
    switch (select_implementation_5F_parser_22 (inCompiler)) {
    case 1: {
      GALGAS_lstring var_ident_13106 ;
      nt_identifier_5F_or_5F_attribute_ (var_ident_13106, inCompiler) ;
      nt_description_ (var_oil_5F_desc_13053, inCompiler) ;
      GALGAS_object_5F_t var_val_13199 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_13053, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 471)), var_ident_13106.readProperty_string ()  COMMA_SOURCE_FILE ("implementation_parser.galgas", 471)) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = var_multiple_12977.boolEnum () ;
        if (kBoolTrue == test_0) {
          var_defaultValue_13029 = GALGAS_multipleAttribute::constructor_new (var_oil_5F_desc_13053, var_val_13199.readProperty_location (), GALGAS_identifierList::constructor_listWithValue (var_val_13199  COMMA_SOURCE_FILE ("implementation_parser.galgas", 473))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 473)) ;
        }
      }
      if (kBoolFalse == test_0) {
        var_defaultValue_13029 = var_val_13199 ;
      }
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT COMMA_SOURCE_FILE ("implementation_parser.galgas", 478)) ;
      nt_description_ (var_oil_5F_desc_13053, inCompiler) ;
      var_defaultValue_13029 = GALGAS_void::constructor_new (var_oil_5F_desc_13053, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 480))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 480)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_AUTO COMMA_SOURCE_FILE ("implementation_parser.galgas", 482)) ;
      nt_description_ (var_oil_5F_desc_13053, inCompiler) ;
      var_defaultValue_13029 = GALGAS_auto::constructor_new (var_oil_5F_desc_13053, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 484))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 484)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_ (var_oil_5F_desc_13053, inCompiler) ;
    var_defaultValue_13029 = GALGAS_void::constructor_new (var_oil_5F_desc_13053, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 488))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 488)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_locationList temp_1 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 490)) ;
  temp_1.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 490))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 490)) ;
  GALGAS_lstringlist temp_2 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 490)) ;
  temp_2.addAssign_operation (var_oil_5F_desc_13053  COMMA_SOURCE_FILE ("implementation_parser.galgas", 490)) ;
  outArgument_options = GALGAS_impAutoDefaultType::constructor_new (temp_1, constinArgument_type, outArgument_name, var_multiple_12977, temp_2, var_withAuto_12898, var_defaultValue_13029  COMMA_SOURCE_FILE ("implementation_parser.galgas", 490)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_type_5F_options_i14_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_with_5F_auto_parse (inCompiler) ;
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  switch (select_implementation_5F_parser_21 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__3D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 466)) ;
    switch (select_implementation_5F_parser_22 (inCompiler)) {
    case 1: {
      nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT COMMA_SOURCE_FILE ("implementation_parser.galgas", 478)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_AUTO COMMA_SOURCE_FILE ("implementation_parser.galgas", 482)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_with_5F_auto_i15_ (GALGAS_bool & outArgument_withAuto,
                                                                                        C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_withAuto.drop () ; // Release 'out' argument
  switch (select_implementation_5F_parser_23 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO COMMA_SOURCE_FILE ("implementation_parser.galgas", 496)) ;
    outArgument_withAuto = GALGAS_bool (true) ;
  } break ;
  case 2: {
    outArgument_withAuto = GALGAS_bool (false) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_with_5F_auto_i15_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_23 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO COMMA_SOURCE_FILE ("implementation_parser.galgas", 496)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_int_5F_or_5F_float_i16_ (GALGAS_object_5F_t & outArgument_num,
                                                                                              const GALGAS_dataType constinArgument_type,
                                                                                              C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_num.drop () ; // Release 'out' argument
  GALGAS_bool var_signed_14099 ;
  nt_sign_ (var_signed_14099, inCompiler) ;
  switch (select_implementation_5F_parser_24 (inCompiler)) {
  case 1: {
    GALGAS_luint_36__34_ var_number_14149 ;
    var_number_14149 = inCompiler->synthetizedAttribute_integerNumber () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_uint_5F_number COMMA_SOURCE_FILE ("implementation_parser.galgas", 509)) ;
    GALGAS_lstring var_oil_5F_desc_14217 ;
    nt_description_ (var_oil_5F_desc_14217, inCompiler) ;
    outArgument_num = function_checkAndGetIntegerNumber (var_oil_5F_desc_14217, constinArgument_type, var_number_14149, var_signed_14099, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 511)) ;
  } break ;
  case 2: {
    GALGAS_ldouble var_number_14314 ;
    var_number_14314 = inCompiler->synthetizedAttribute_floatNumber () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_float_5F_number COMMA_SOURCE_FILE ("implementation_parser.galgas", 514)) ;
    GALGAS_lstring var_oil_5F_desc_14382 ;
    nt_description_ (var_oil_5F_desc_14382, inCompiler) ;
    outArgument_num = function_checkAndGetFloatNumber (var_oil_5F_desc_14382, constinArgument_type, var_number_14314, var_signed_14099, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 516)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_int_5F_or_5F_float_i16_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_sign_parse (inCompiler) ;
  switch (select_implementation_5F_parser_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_uint_5F_number COMMA_SOURCE_FILE ("implementation_parser.galgas", 509)) ;
    nt_description_parse (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_float_5F_number COMMA_SOURCE_FILE ("implementation_parser.galgas", 514)) ;
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_set_5F_followup_i17_ (GALGAS_numberList & ioArgument_numbers,
                                                                                           const GALGAS_dataType constinArgument_type,
                                                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_25 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__2C_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 525)) ;
      GALGAS_object_5F_t var_num_14572 ;
      nt_int_5F_or_5F_float_ (var_num_14572, constinArgument_type, inCompiler) ;
      ioArgument_numbers.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 528)), var_num_14572  COMMA_SOURCE_FILE ("implementation_parser.galgas", 528)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_set_5F_followup_i17_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_25 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__2C_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 525)) ;
      nt_int_5F_or_5F_float_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_range_5F_content_i18_ (GALGAS_attributeRange & outArgument_range,
                                                                                            const GALGAS_dataType constinArgument_type,
                                                                                            C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_range.drop () ; // Release 'out' argument
  GALGAS_object_5F_t var_start_14735 = GALGAS_void::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 535)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 535))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 535)) ;
  GALGAS_object_5F_t var_stop_14800 = GALGAS_void::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 536)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 536))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 536)) ;
  GALGAS_bool var_signed_14867 ;
  nt_sign_ (var_signed_14867, inCompiler) ;
  switch (select_implementation_5F_parser_26 (inCompiler)) {
  case 1: {
    GALGAS_luint_36__34_ var_number_14917 ;
    var_number_14917 = inCompiler->synthetizedAttribute_integerNumber () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number COMMA_SOURCE_FILE ("implementation_parser.galgas", 541)) ;
    var_start_14735 = function_checkAndGetIntegerNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 542)), constinArgument_type, var_number_14917, var_signed_14867, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 542)) ;
    nt_int_5F_or_5F_float_ (var_stop_14800, constinArgument_type, inCompiler) ;
    outArgument_range = function_buildRange (constinArgument_type, var_start_14735, var_stop_14800, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 544)) ;
  } break ;
  case 2: {
    GALGAS_luint_36__34_ var_number_15132 ;
    var_number_15132 = inCompiler->synthetizedAttribute_integerNumber () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_uint_5F_number COMMA_SOURCE_FILE ("implementation_parser.galgas", 547)) ;
    var_start_14735 = function_checkAndGetIntegerNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 548)), constinArgument_type, var_number_15132, var_signed_14867, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 548)) ;
    switch (select_implementation_5F_parser_27 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__2E__2E_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 550)) ;
      nt_int_5F_or_5F_float_ (var_stop_14800, constinArgument_type, inCompiler) ;
      outArgument_range = function_buildRange (constinArgument_type, var_start_14735, var_stop_14800, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 551)) ;
    } break ;
    case 2: {
      GALGAS_numberList var_numbers_15361 = GALGAS_numberList::constructor_listWithValue (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 553)), var_start_14735  COMMA_SOURCE_FILE ("implementation_parser.galgas", 553)) ;
      nt_set_5F_followup_ (var_numbers_15361, constinArgument_type, inCompiler) ;
      outArgument_range = function_attributeRangeWithNumberList (var_numbers_15361, constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 555)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 3: {
    GALGAS_ldouble var_number_15549 ;
    var_number_15549 = inCompiler->synthetizedAttribute_floatNumber () ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_float_5F_number COMMA_SOURCE_FILE ("implementation_parser.galgas", 559)) ;
    var_start_14735 = function_checkAndGetFloatNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 560)), constinArgument_type, var_number_15549, var_signed_14867, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 560)) ;
    switch (select_implementation_5F_parser_28 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__2E__2E_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 562)) ;
      nt_int_5F_or_5F_float_ (var_stop_14800, constinArgument_type, inCompiler) ;
      outArgument_range = function_buildRange (constinArgument_type, var_start_14735, var_stop_14800, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 563)) ;
    } break ;
    case 2: {
      GALGAS_numberList var_numbers_15777 = GALGAS_numberList::constructor_listWithValue (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 565)), var_start_14735  COMMA_SOURCE_FILE ("implementation_parser.galgas", 565)) ;
      nt_set_5F_followup_ (var_numbers_15777, constinArgument_type, inCompiler) ;
      outArgument_range = function_attributeRangeWithNumberList (var_numbers_15777, constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 567)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_range_5F_content_i18_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_sign_parse (inCompiler) ;
  switch (select_implementation_5F_parser_26 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number COMMA_SOURCE_FILE ("implementation_parser.galgas", 541)) ;
    nt_int_5F_or_5F_float_parse (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_uint_5F_number COMMA_SOURCE_FILE ("implementation_parser.galgas", 547)) ;
    switch (select_implementation_5F_parser_27 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__2E__2E_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 550)) ;
      nt_int_5F_or_5F_float_parse (inCompiler) ;
    } break ;
    case 2: {
      nt_set_5F_followup_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_float_5F_number COMMA_SOURCE_FILE ("implementation_parser.galgas", 559)) ;
    switch (select_implementation_5F_parser_28 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__2E__2E_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 562)) ;
      nt_int_5F_or_5F_float_parse (inCompiler) ;
    } break ;
    case 2: {
      nt_set_5F_followup_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_range_i19_ (GALGAS_attributeRange & outArgument_range,
                                                                                 const GALGAS_dataType constinArgument_rangeType,
                                                                                 C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_range.drop () ; // Release 'out' argument
  switch (select_implementation_5F_parser_29 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 576)) ;
    nt_range_5F_content_ (outArgument_range, constinArgument_rangeType, inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 576)) ;
  } break ;
  case 2: {
    outArgument_range = GALGAS_noRange::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 578))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 578)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_range_i19_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_29 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 576)) ;
    nt_range_5F_content_parse (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 576)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_multiple_i20_ (GALGAS_bool & outArgument_multi,
                                                                                    C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_multi.drop () ; // Release 'out' argument
  switch (select_implementation_5F_parser_30 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 585)) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 585)) ;
    outArgument_multi = GALGAS_bool (true) ;
  } break ;
  case 2: {
    outArgument_multi = GALGAS_bool (false) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_multiple_i20_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_30 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5B_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 585)) ;
    inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken__5D_ COMMA_SOURCE_FILE ("implementation_parser.galgas", 585)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_ (GALGAS_lstring & outArgument_name,
                                                                                                         C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_name = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("implementation_parser.galgas", 594)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("implementation_parser.galgas", 594)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_ (GALGAS_lstring & outArgument_name,
                                                                                                             C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_name = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("implementation_parser.galgas", 602)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_goil_5F_lexique::kToken_idf COMMA_SOURCE_FILE ("implementation_parser.galgas", 602)) ;
  inCompiler->resetTemplateString () ;
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

static const int16_t gProductions_goil_file_level_include [] = {
// At index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 36
  TERMINAL (C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION) // $IMPLEMENTATION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (14) // <implementation_object_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 7 : <start>, in file 'goil_syntax.ggs', line 38
, NONTERMINAL (5) // <OIL_version>
, NONTERMINAL (2) // <file>
, END_PRODUCTION
// At index 10 : <file>, in file 'goil_syntax.ggs', line 110
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 12 : <sign>, in file 'goil_syntax.ggs', line 126
, NONTERMINAL (37) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 14 : <description>, in file 'goil_syntax.ggs', line 139
, NONTERMINAL (38) // <select_goil_5F_syntax_2>
, END_PRODUCTION
// At index 16 : <OIL_version>, in file 'goil_syntax.ggs', line 163
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) // $OIL_VERSION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 22 : <application_definition>, in file 'goil_syntax.ggs', line 170
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) // $CPU$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (7) // <object_definition_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 30 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 32 : <boolean>, in file 'goil_syntax.ggs', line 234
, NONTERMINAL (41) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 34 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 36 : <oil_declaration>, in file 'goil_syntax.ggs', line 256
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (43) // <select_goil_5F_syntax_7>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 40 : <include_file_level>, in file 'goil_syntax.ggs', line 463
, NONTERMINAL (48) // <select_goil_5F_syntax_12>
, NONTERMINAL (49) // <select_goil_5F_syntax_13>
, END_PRODUCTION
// At index 43 : <include_cpu_level>, in file 'goil_syntax.ggs', line 487
, NONTERMINAL (50) // <select_goil_5F_syntax_14>
, NONTERMINAL (51) // <select_goil_5F_syntax_15>
, END_PRODUCTION
// At index 46 : <include_object_level>, in file 'goil_syntax.ggs', line 511
, NONTERMINAL (52) // <select_goil_5F_syntax_16>
, NONTERMINAL (53) // <select_goil_5F_syntax_17>
, END_PRODUCTION
// At index 49 : <implementation_object_list>, in file 'implementation_parser.ggs', line 44
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 51 : <include_implementation_level>, in file 'implementation_parser.ggs', line 53
, NONTERMINAL (55) // <select_implementation_5F_parser_1>
, NONTERMINAL (56) // <select_implementation_5F_parser_2>
, END_PRODUCTION
// At index 54 : <include_type_level>, in file 'implementation_parser.ggs', line 74
, NONTERMINAL (57) // <select_implementation_5F_parser_3>
, NONTERMINAL (58) // <select_implementation_5F_parser_4>
, END_PRODUCTION
// At index 57 : <implementation_objects>, in file 'implementation_parser.ggs', line 95
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (59) // <select_implementation_5F_parser_5>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 63 : <implementation_list>, in file 'implementation_parser.ggs', line 132
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 65 : <implementation_type>, in file 'implementation_parser.ggs', line 210
, NONTERMINAL (61) // <select_implementation_5F_parser_7>
, END_PRODUCTION
// At index 67 : <struct_options>, in file 'implementation_parser.ggs', line 238
, NONTERMINAL (62) // <select_implementation_5F_parser_8>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 72 : <objref_option>, in file 'implementation_parser.ggs', line 255
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 76 : <string_options>, in file 'implementation_parser.ggs', line 273
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (63) // <select_implementation_5F_parser_9>
, END_PRODUCTION
// At index 81 : <boolean_options>, in file 'implementation_parser.ggs', line 310
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (65) // <select_implementation_5F_parser_11>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (68) // <select_implementation_5F_parser_14>
, END_PRODUCTION
// At index 87 : <enum_item>, in file 'implementation_parser.ggs', line 355
, NONTERMINAL (35) // <identifier_or_enum_value>
, NONTERMINAL (69) // <select_implementation_5F_parser_15>
, END_PRODUCTION
// At index 90 : <enum_options>, in file 'implementation_parser.ggs', line 368
, NONTERMINAL (28) // <with_auto>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (71) // <select_implementation_5F_parser_17>
, END_PRODUCTION
// At index 99 : <number_options>, in file 'implementation_parser.ggs', line 415
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (32) // <range>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (73) // <select_implementation_5F_parser_19>
, END_PRODUCTION
// At index 105 : <type_options>, in file 'implementation_parser.ggs', line 454
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (75) // <select_implementation_5F_parser_21>
, END_PRODUCTION
// At index 110 : <with_auto>, in file 'implementation_parser.ggs', line 493
, NONTERMINAL (77) // <select_implementation_5F_parser_23>
, END_PRODUCTION
// At index 112 : <int_or_float>, in file 'implementation_parser.ggs', line 502
, NONTERMINAL (3) // <sign>
, NONTERMINAL (78) // <select_implementation_5F_parser_24>
, END_PRODUCTION
// At index 115 : <set_followup>, in file 'implementation_parser.ggs', line 520
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 117 : <range_content>, in file 'implementation_parser.ggs', line 532
, NONTERMINAL (3) // <sign>
, NONTERMINAL (80) // <select_implementation_5F_parser_26>
, END_PRODUCTION
// At index 120 : <range>, in file 'implementation_parser.ggs', line 572
, NONTERMINAL (83) // <select_implementation_5F_parser_29>
, END_PRODUCTION
// At index 122 : <multiple>, in file 'implementation_parser.ggs', line 582
, NONTERMINAL (84) // <select_implementation_5F_parser_30>
, END_PRODUCTION
// At index 124 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 592
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
// At index 126 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 597
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 128 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, END_PRODUCTION
// At index 129 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (11) // <include_file_level>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 132 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 135 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (6) // <application_definition>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 138 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) // $-$
, END_PRODUCTION
// At index 140 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) // $+$
, END_PRODUCTION
// At index 142 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, END_PRODUCTION
// At index 143 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, END_PRODUCTION
// At index 144 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) // $:$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (39) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 148 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, END_PRODUCTION
// At index 149 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (39) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 152 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, END_PRODUCTION
// At index 153 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 162 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, NONTERMINAL (12) // <include_cpu_level>
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 165 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 167 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 169 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
, END_PRODUCTION
// At index 170 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
, NONTERMINAL (10) // <oil_declaration>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 173 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
, NONTERMINAL (13) // <include_object_level>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 176 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (44) // <select_goil_5F_syntax_8>
, END_PRODUCTION
// At index 179 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 185 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (45) // <select_goil_5F_syntax_9>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 189 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, NONTERMINAL (3) // <sign>
, NONTERMINAL (46) // <select_goil_5F_syntax_10>
, END_PRODUCTION
// At index 192 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (47) // <select_goil_5F_syntax_11>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 196 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 199 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 202 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 206 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
, END_PRODUCTION
// At index 207 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 210 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 213 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 356
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 217 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 356
, END_PRODUCTION
// At index 218 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 470
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 220 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 470
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 222 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 476
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 224 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 476
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 226 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 494
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 228 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 494
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 230 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 500
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 232 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 500
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 234 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 516
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 236 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 516
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 238 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 522
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 240 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 522
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 242 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
, END_PRODUCTION
// At index 243 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
, NONTERMINAL (17) // <implementation_objects>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 247 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
, NONTERMINAL (15) // <include_implementation_level>
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 250 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 57
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 252 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 57
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 254 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 63
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 256 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 63
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 258 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 78
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 260 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 78
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 262 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 84
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 264 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 84
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 266 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 102
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 269 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 102
, END_PRODUCTION
// At index 270 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
, END_PRODUCTION
// At index 271 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
, NONTERMINAL (19) // <implementation_type>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 275 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
, NONTERMINAL (16) // <include_type_level>
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 278 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_) // $UINT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 281 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_33__32_) // $INT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 284 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_) // $UINT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 287 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_36__34_) // $INT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 290 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FLOAT) // $FLOAT$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 293 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_ENUM) // $ENUM$
, NONTERMINAL (25) // <enum_options>
, END_PRODUCTION
// At index 296 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_BOOLEAN) // $BOOLEAN$
, NONTERMINAL (23) // <boolean_options>
, END_PRODUCTION
// At index 299 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRING) // $STRING$
, NONTERMINAL (22) // <string_options>
, END_PRODUCTION
// At index 302 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER) // $IDENTIFIER$
, NONTERMINAL (27) // <type_options>
, END_PRODUCTION
// At index 305 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRUCT) // $STRUCT$
, NONTERMINAL (20) // <struct_options>
, END_PRODUCTION
// At index 308 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (21) // <objref_option>
, END_PRODUCTION
// At index 311 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 242
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 315 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 242
, END_PRODUCTION
// At index 316 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 283
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (64) // <select_implementation_5F_parser_10>
, END_PRODUCTION
// At index 319 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 283
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 321 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 324 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 327 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 330 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 317
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, NONTERMINAL (66) // <select_implementation_5F_parser_12>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, NONTERMINAL (67) // <select_implementation_5F_parser_13>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 338 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 317
, END_PRODUCTION
// At index 339 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 320
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 343 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 320
, END_PRODUCTION
// At index 344 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 329
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 348 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 329
, END_PRODUCTION
// At index 349 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 343
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 353 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 343
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 355 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 360
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 359 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 360
, END_PRODUCTION
// At index 360 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 376
, END_PRODUCTION
// At index 361 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 376
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, END_PRODUCTION
// At index 365 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 386
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (72) // <select_implementation_5F_parser_18>
, END_PRODUCTION
// At index 368 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 386
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 370 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 373 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 376 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 379 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 428
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (74) // <select_implementation_5F_parser_20>
, END_PRODUCTION
// At index 382 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 428
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 384 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 386 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 389 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 392 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 465
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (76) // <select_implementation_5F_parser_22>
, END_PRODUCTION
// At index 395 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 465
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 397 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 400 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 403 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 406 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 495
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO) // $WITH_AUTO$
, END_PRODUCTION
// At index 408 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 495
, END_PRODUCTION
// At index 409 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 507
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 412 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 507
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 415 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 523
, END_PRODUCTION
// At index 416 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 523
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (29) // <int_or_float>
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 420 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number) // $set_start_uint_number$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 423 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (81) // <select_implementation_5F_parser_27>
, END_PRODUCTION
// At index 426 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (82) // <select_implementation_5F_parser_28>
, END_PRODUCTION
// At index 429 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 549
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 432 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 549
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 434 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 561
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 437 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 561
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 439 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 575
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (31) // <range_content>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 443 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 575
, END_PRODUCTION
// At index 444 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 584
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 447 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 584
, END_PRODUCTION
// At index 448 : <>, in file '.ggs', line 0
, NONTERMINAL (2) // <file>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_goil_file_level_include [159] = {
 {"<implementation_definition>", "implementation_parser", 0}, // at index 0
 {"<start>", "goil_syntax", 7}, // at index 1
 {"<file>", "goil_syntax", 10}, // at index 2
 {"<sign>", "goil_syntax", 12}, // at index 3
 {"<description>", "goil_syntax", 14}, // at index 4
 {"<OIL_version>", "goil_syntax", 16}, // at index 5
 {"<application_definition>", "goil_syntax", 22}, // at index 6
 {"<object_definition_list>", "goil_syntax", 30}, // at index 7
 {"<boolean>", "goil_syntax", 32}, // at index 8
 {"<oil_declaration_list>", "goil_syntax", 34}, // at index 9
 {"<oil_declaration>", "goil_syntax", 36}, // at index 10
 {"<include_file_level>", "goil_syntax", 40}, // at index 11
 {"<include_cpu_level>", "goil_syntax", 43}, // at index 12
 {"<include_object_level>", "goil_syntax", 46}, // at index 13
 {"<implementation_object_list>", "implementation_parser", 49}, // at index 14
 {"<include_implementation_level>", "implementation_parser", 51}, // at index 15
 {"<include_type_level>", "implementation_parser", 54}, // at index 16
 {"<implementation_objects>", "implementation_parser", 57}, // at index 17
 {"<implementation_list>", "implementation_parser", 63}, // at index 18
 {"<implementation_type>", "implementation_parser", 65}, // at index 19
 {"<struct_options>", "implementation_parser", 67}, // at index 20
 {"<objref_option>", "implementation_parser", 72}, // at index 21
 {"<string_options>", "implementation_parser", 76}, // at index 22
 {"<boolean_options>", "implementation_parser", 81}, // at index 23
 {"<enum_item>", "implementation_parser", 87}, // at index 24
 {"<enum_options>", "implementation_parser", 90}, // at index 25
 {"<number_options>", "implementation_parser", 99}, // at index 26
 {"<type_options>", "implementation_parser", 105}, // at index 27
 {"<with_auto>", "implementation_parser", 110}, // at index 28
 {"<int_or_float>", "implementation_parser", 112}, // at index 29
 {"<set_followup>", "implementation_parser", 115}, // at index 30
 {"<range_content>", "implementation_parser", 117}, // at index 31
 {"<range>", "implementation_parser", 120}, // at index 32
 {"<multiple>", "implementation_parser", 122}, // at index 33
 {"<identifier_or_attribute>", "implementation_parser", 124}, // at index 34
 {"<identifier_or_enum_value>", "implementation_parser", 126}, // at index 35
 {"<select_goil_5F_syntax_0>", "goil_syntax", 128}, // at index 36
 {"<select_goil_5F_syntax_0>", "goil_syntax", 129}, // at index 37
 {"<select_goil_5F_syntax_0>", "goil_syntax", 132}, // at index 38
 {"<select_goil_5F_syntax_0>", "goil_syntax", 135}, // at index 39
 {"<select_goil_5F_syntax_1>", "goil_syntax", 138}, // at index 40
 {"<select_goil_5F_syntax_1>", "goil_syntax", 140}, // at index 41
 {"<select_goil_5F_syntax_1>", "goil_syntax", 142}, // at index 42
 {"<select_goil_5F_syntax_2>", "goil_syntax", 143}, // at index 43
 {"<select_goil_5F_syntax_2>", "goil_syntax", 144}, // at index 44
 {"<select_goil_5F_syntax_3>", "goil_syntax", 148}, // at index 45
 {"<select_goil_5F_syntax_3>", "goil_syntax", 149}, // at index 46
 {"<select_goil_5F_syntax_4>", "goil_syntax", 152}, // at index 47
 {"<select_goil_5F_syntax_4>", "goil_syntax", 153}, // at index 48
 {"<select_goil_5F_syntax_4>", "goil_syntax", 162}, // at index 49
 {"<select_goil_5F_syntax_5>", "goil_syntax", 165}, // at index 50
 {"<select_goil_5F_syntax_5>", "goil_syntax", 167}, // at index 51
 {"<select_goil_5F_syntax_6>", "goil_syntax", 169}, // at index 52
 {"<select_goil_5F_syntax_6>", "goil_syntax", 170}, // at index 53
 {"<select_goil_5F_syntax_6>", "goil_syntax", 173}, // at index 54
 {"<select_goil_5F_syntax_7>", "goil_syntax", 176}, // at index 55
 {"<select_goil_5F_syntax_7>", "goil_syntax", 179}, // at index 56
 {"<select_goil_5F_syntax_8>", "goil_syntax", 185}, // at index 57
 {"<select_goil_5F_syntax_8>", "goil_syntax", 189}, // at index 58
 {"<select_goil_5F_syntax_8>", "goil_syntax", 192}, // at index 59
 {"<select_goil_5F_syntax_8>", "goil_syntax", 196}, // at index 60
 {"<select_goil_5F_syntax_8>", "goil_syntax", 199}, // at index 61
 {"<select_goil_5F_syntax_9>", "goil_syntax", 202}, // at index 62
 {"<select_goil_5F_syntax_9>", "goil_syntax", 206}, // at index 63
 {"<select_goil_5F_syntax_10>", "goil_syntax", 207}, // at index 64
 {"<select_goil_5F_syntax_10>", "goil_syntax", 210}, // at index 65
 {"<select_goil_5F_syntax_11>", "goil_syntax", 213}, // at index 66
 {"<select_goil_5F_syntax_11>", "goil_syntax", 217}, // at index 67
 {"<select_goil_5F_syntax_12>", "goil_syntax", 218}, // at index 68
 {"<select_goil_5F_syntax_12>", "goil_syntax", 220}, // at index 69
 {"<select_goil_5F_syntax_13>", "goil_syntax", 222}, // at index 70
 {"<select_goil_5F_syntax_13>", "goil_syntax", 224}, // at index 71
 {"<select_goil_5F_syntax_14>", "goil_syntax", 226}, // at index 72
 {"<select_goil_5F_syntax_14>", "goil_syntax", 228}, // at index 73
 {"<select_goil_5F_syntax_15>", "goil_syntax", 230}, // at index 74
 {"<select_goil_5F_syntax_15>", "goil_syntax", 232}, // at index 75
 {"<select_goil_5F_syntax_16>", "goil_syntax", 234}, // at index 76
 {"<select_goil_5F_syntax_16>", "goil_syntax", 236}, // at index 77
 {"<select_goil_5F_syntax_17>", "goil_syntax", 238}, // at index 78
 {"<select_goil_5F_syntax_17>", "goil_syntax", 240}, // at index 79
 {"<select_implementation_5F_parser_0>", "implementation_parser", 242}, // at index 80
 {"<select_implementation_5F_parser_0>", "implementation_parser", 243}, // at index 81
 {"<select_implementation_5F_parser_0>", "implementation_parser", 247}, // at index 82
 {"<select_implementation_5F_parser_1>", "implementation_parser", 250}, // at index 83
 {"<select_implementation_5F_parser_1>", "implementation_parser", 252}, // at index 84
 {"<select_implementation_5F_parser_2>", "implementation_parser", 254}, // at index 85
 {"<select_implementation_5F_parser_2>", "implementation_parser", 256}, // at index 86
 {"<select_implementation_5F_parser_3>", "implementation_parser", 258}, // at index 87
 {"<select_implementation_5F_parser_3>", "implementation_parser", 260}, // at index 88
 {"<select_implementation_5F_parser_4>", "implementation_parser", 262}, // at index 89
 {"<select_implementation_5F_parser_4>", "implementation_parser", 264}, // at index 90
 {"<select_implementation_5F_parser_5>", "implementation_parser", 266}, // at index 91
 {"<select_implementation_5F_parser_5>", "implementation_parser", 269}, // at index 92
 {"<select_implementation_5F_parser_6>", "implementation_parser", 270}, // at index 93
 {"<select_implementation_5F_parser_6>", "implementation_parser", 271}, // at index 94
 {"<select_implementation_5F_parser_6>", "implementation_parser", 275}, // at index 95
 {"<select_implementation_5F_parser_7>", "implementation_parser", 278}, // at index 96
 {"<select_implementation_5F_parser_7>", "implementation_parser", 281}, // at index 97
 {"<select_implementation_5F_parser_7>", "implementation_parser", 284}, // at index 98
 {"<select_implementation_5F_parser_7>", "implementation_parser", 287}, // at index 99
 {"<select_implementation_5F_parser_7>", "implementation_parser", 290}, // at index 100
 {"<select_implementation_5F_parser_7>", "implementation_parser", 293}, // at index 101
 {"<select_implementation_5F_parser_7>", "implementation_parser", 296}, // at index 102
 {"<select_implementation_5F_parser_7>", "implementation_parser", 299}, // at index 103
 {"<select_implementation_5F_parser_7>", "implementation_parser", 302}, // at index 104
 {"<select_implementation_5F_parser_7>", "implementation_parser", 305}, // at index 105
 {"<select_implementation_5F_parser_7>", "implementation_parser", 308}, // at index 106
 {"<select_implementation_5F_parser_8>", "implementation_parser", 311}, // at index 107
 {"<select_implementation_5F_parser_8>", "implementation_parser", 315}, // at index 108
 {"<select_implementation_5F_parser_9>", "implementation_parser", 316}, // at index 109
 {"<select_implementation_5F_parser_9>", "implementation_parser", 319}, // at index 110
 {"<select_implementation_5F_parser_10>", "implementation_parser", 321}, // at index 111
 {"<select_implementation_5F_parser_10>", "implementation_parser", 324}, // at index 112
 {"<select_implementation_5F_parser_10>", "implementation_parser", 327}, // at index 113
 {"<select_implementation_5F_parser_11>", "implementation_parser", 330}, // at index 114
 {"<select_implementation_5F_parser_11>", "implementation_parser", 338}, // at index 115
 {"<select_implementation_5F_parser_12>", "implementation_parser", 339}, // at index 116
 {"<select_implementation_5F_parser_12>", "implementation_parser", 343}, // at index 117
 {"<select_implementation_5F_parser_13>", "implementation_parser", 344}, // at index 118
 {"<select_implementation_5F_parser_13>", "implementation_parser", 348}, // at index 119
 {"<select_implementation_5F_parser_14>", "implementation_parser", 349}, // at index 120
 {"<select_implementation_5F_parser_14>", "implementation_parser", 353}, // at index 121
 {"<select_implementation_5F_parser_15>", "implementation_parser", 355}, // at index 122
 {"<select_implementation_5F_parser_15>", "implementation_parser", 359}, // at index 123
 {"<select_implementation_5F_parser_16>", "implementation_parser", 360}, // at index 124
 {"<select_implementation_5F_parser_16>", "implementation_parser", 361}, // at index 125
 {"<select_implementation_5F_parser_17>", "implementation_parser", 365}, // at index 126
 {"<select_implementation_5F_parser_17>", "implementation_parser", 368}, // at index 127
 {"<select_implementation_5F_parser_18>", "implementation_parser", 370}, // at index 128
 {"<select_implementation_5F_parser_18>", "implementation_parser", 373}, // at index 129
 {"<select_implementation_5F_parser_18>", "implementation_parser", 376}, // at index 130
 {"<select_implementation_5F_parser_19>", "implementation_parser", 379}, // at index 131
 {"<select_implementation_5F_parser_19>", "implementation_parser", 382}, // at index 132
 {"<select_implementation_5F_parser_20>", "implementation_parser", 384}, // at index 133
 {"<select_implementation_5F_parser_20>", "implementation_parser", 386}, // at index 134
 {"<select_implementation_5F_parser_20>", "implementation_parser", 389}, // at index 135
 {"<select_implementation_5F_parser_21>", "implementation_parser", 392}, // at index 136
 {"<select_implementation_5F_parser_21>", "implementation_parser", 395}, // at index 137
 {"<select_implementation_5F_parser_22>", "implementation_parser", 397}, // at index 138
 {"<select_implementation_5F_parser_22>", "implementation_parser", 400}, // at index 139
 {"<select_implementation_5F_parser_22>", "implementation_parser", 403}, // at index 140
 {"<select_implementation_5F_parser_23>", "implementation_parser", 406}, // at index 141
 {"<select_implementation_5F_parser_23>", "implementation_parser", 408}, // at index 142
 {"<select_implementation_5F_parser_24>", "implementation_parser", 409}, // at index 143
 {"<select_implementation_5F_parser_24>", "implementation_parser", 412}, // at index 144
 {"<select_implementation_5F_parser_25>", "implementation_parser", 415}, // at index 145
 {"<select_implementation_5F_parser_25>", "implementation_parser", 416}, // at index 146
 {"<select_implementation_5F_parser_26>", "implementation_parser", 420}, // at index 147
 {"<select_implementation_5F_parser_26>", "implementation_parser", 423}, // at index 148
 {"<select_implementation_5F_parser_26>", "implementation_parser", 426}, // at index 149
 {"<select_implementation_5F_parser_27>", "implementation_parser", 429}, // at index 150
 {"<select_implementation_5F_parser_27>", "implementation_parser", 432}, // at index 151
 {"<select_implementation_5F_parser_28>", "implementation_parser", 434}, // at index 152
 {"<select_implementation_5F_parser_28>", "implementation_parser", 437}, // at index 153
 {"<select_implementation_5F_parser_29>", "implementation_parser", 439}, // at index 154
 {"<select_implementation_5F_parser_29>", "implementation_parser", 443}, // at index 155
 {"<select_implementation_5F_parser_30>", "implementation_parser", 444}, // at index 156
 {"<select_implementation_5F_parser_30>", "implementation_parser", 447}, // at index 157
 {"<>", "", 448} // at index 158
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_goil_file_level_include [159] = {
0, // index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 36
7, // index 1 : <start>, in file 'goil_syntax.ggs', line 38
10, // index 2 : <file>, in file 'goil_syntax.ggs', line 110
12, // index 3 : <sign>, in file 'goil_syntax.ggs', line 126
14, // index 4 : <description>, in file 'goil_syntax.ggs', line 139
16, // index 5 : <OIL_version>, in file 'goil_syntax.ggs', line 163
22, // index 6 : <application_definition>, in file 'goil_syntax.ggs', line 170
30, // index 7 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
32, // index 8 : <boolean>, in file 'goil_syntax.ggs', line 234
34, // index 9 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 244
36, // index 10 : <oil_declaration>, in file 'goil_syntax.ggs', line 256
40, // index 11 : <include_file_level>, in file 'goil_syntax.ggs', line 463
43, // index 12 : <include_cpu_level>, in file 'goil_syntax.ggs', line 487
46, // index 13 : <include_object_level>, in file 'goil_syntax.ggs', line 511
49, // index 14 : <implementation_object_list>, in file 'implementation_parser.ggs', line 44
51, // index 15 : <include_implementation_level>, in file 'implementation_parser.ggs', line 53
54, // index 16 : <include_type_level>, in file 'implementation_parser.ggs', line 74
57, // index 17 : <implementation_objects>, in file 'implementation_parser.ggs', line 95
63, // index 18 : <implementation_list>, in file 'implementation_parser.ggs', line 132
65, // index 19 : <implementation_type>, in file 'implementation_parser.ggs', line 210
67, // index 20 : <struct_options>, in file 'implementation_parser.ggs', line 238
72, // index 21 : <objref_option>, in file 'implementation_parser.ggs', line 255
76, // index 22 : <string_options>, in file 'implementation_parser.ggs', line 273
81, // index 23 : <boolean_options>, in file 'implementation_parser.ggs', line 310
87, // index 24 : <enum_item>, in file 'implementation_parser.ggs', line 355
90, // index 25 : <enum_options>, in file 'implementation_parser.ggs', line 368
99, // index 26 : <number_options>, in file 'implementation_parser.ggs', line 415
105, // index 27 : <type_options>, in file 'implementation_parser.ggs', line 454
110, // index 28 : <with_auto>, in file 'implementation_parser.ggs', line 493
112, // index 29 : <int_or_float>, in file 'implementation_parser.ggs', line 502
115, // index 30 : <set_followup>, in file 'implementation_parser.ggs', line 520
117, // index 31 : <range_content>, in file 'implementation_parser.ggs', line 532
120, // index 32 : <range>, in file 'implementation_parser.ggs', line 572
122, // index 33 : <multiple>, in file 'implementation_parser.ggs', line 582
124, // index 34 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 592
126, // index 35 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 597
128, // index 36 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
129, // index 37 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
132, // index 38 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
135, // index 39 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
138, // index 40 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
140, // index 41 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
142, // index 42 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
143, // index 43 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
144, // index 44 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
148, // index 45 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
149, // index 46 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
152, // index 47 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
153, // index 48 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
162, // index 49 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
165, // index 50 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
167, // index 51 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
169, // index 52 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
170, // index 53 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
173, // index 54 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
176, // index 55 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
179, // index 56 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
185, // index 57 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
189, // index 58 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
192, // index 59 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
196, // index 60 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
199, // index 61 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
202, // index 62 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
206, // index 63 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
207, // index 64 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
210, // index 65 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
213, // index 66 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 356
217, // index 67 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 356
218, // index 68 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 470
220, // index 69 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 470
222, // index 70 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 476
224, // index 71 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 476
226, // index 72 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 494
228, // index 73 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 494
230, // index 74 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 500
232, // index 75 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 500
234, // index 76 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 516
236, // index 77 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 516
238, // index 78 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 522
240, // index 79 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 522
242, // index 80 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
243, // index 81 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
247, // index 82 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
250, // index 83 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 57
252, // index 84 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 57
254, // index 85 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 63
256, // index 86 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 63
258, // index 87 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 78
260, // index 88 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 78
262, // index 89 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 84
264, // index 90 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 84
266, // index 91 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 102
269, // index 92 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 102
270, // index 93 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
271, // index 94 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
275, // index 95 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
278, // index 96 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
281, // index 97 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
284, // index 98 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
287, // index 99 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
290, // index 100 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
293, // index 101 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
296, // index 102 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
299, // index 103 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
302, // index 104 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
305, // index 105 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
308, // index 106 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
311, // index 107 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 242
315, // index 108 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 242
316, // index 109 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 283
319, // index 110 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 283
321, // index 111 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
324, // index 112 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
327, // index 113 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
330, // index 114 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 317
338, // index 115 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 317
339, // index 116 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 320
343, // index 117 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 320
344, // index 118 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 329
348, // index 119 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 329
349, // index 120 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 343
353, // index 121 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 343
355, // index 122 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 360
359, // index 123 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 360
360, // index 124 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 376
361, // index 125 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 376
365, // index 126 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 386
368, // index 127 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 386
370, // index 128 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
373, // index 129 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
376, // index 130 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
379, // index 131 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 428
382, // index 132 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 428
384, // index 133 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
386, // index 134 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
389, // index 135 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
392, // index 136 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 465
395, // index 137 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 465
397, // index 138 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
400, // index 139 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
403, // index 140 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
406, // index 141 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 495
408, // index 142 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 495
409, // index 143 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 507
412, // index 144 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 507
415, // index 145 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 523
416, // index 146 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 523
420, // index 147 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
423, // index 148 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
426, // index 149 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
429, // index 150 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 549
432, // index 151 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 549
434, // index 152 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 561
437, // index 153 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 561
439, // index 154 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 575
443, // index 155 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 575
444, // index 156 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 584
447, // index 157 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 584
448 // index 158 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_goil_file_level_include [87] = {
0, // at 0 : <implementation_definition>
1, // at 1 : <start>
2, // at 2 : <file>
3, // at 3 : <sign>
4, // at 4 : <description>
5, // at 5 : <OIL_version>
6, // at 6 : <application_definition>
7, // at 7 : <object_definition_list>
8, // at 8 : <boolean>
9, // at 9 : <oil_declaration_list>
10, // at 10 : <oil_declaration>
11, // at 11 : <include_file_level>
12, // at 12 : <include_cpu_level>
13, // at 13 : <include_object_level>
14, // at 14 : <implementation_object_list>
15, // at 15 : <include_implementation_level>
16, // at 16 : <include_type_level>
17, // at 17 : <implementation_objects>
18, // at 18 : <implementation_list>
19, // at 19 : <implementation_type>
20, // at 20 : <struct_options>
21, // at 21 : <objref_option>
22, // at 22 : <string_options>
23, // at 23 : <boolean_options>
24, // at 24 : <enum_item>
25, // at 25 : <enum_options>
26, // at 26 : <number_options>
27, // at 27 : <type_options>
28, // at 28 : <with_auto>
29, // at 29 : <int_or_float>
30, // at 30 : <set_followup>
31, // at 31 : <range_content>
32, // at 32 : <range>
33, // at 33 : <multiple>
34, // at 34 : <identifier_or_attribute>
35, // at 35 : <identifier_or_enum_value>
36, // at 36 : <select_goil_5F_syntax_0>
40, // at 37 : <select_goil_5F_syntax_1>
43, // at 38 : <select_goil_5F_syntax_2>
45, // at 39 : <select_goil_5F_syntax_3>
47, // at 40 : <select_goil_5F_syntax_4>
50, // at 41 : <select_goil_5F_syntax_5>
52, // at 42 : <select_goil_5F_syntax_6>
55, // at 43 : <select_goil_5F_syntax_7>
57, // at 44 : <select_goil_5F_syntax_8>
62, // at 45 : <select_goil_5F_syntax_9>
64, // at 46 : <select_goil_5F_syntax_10>
66, // at 47 : <select_goil_5F_syntax_11>
68, // at 48 : <select_goil_5F_syntax_12>
70, // at 49 : <select_goil_5F_syntax_13>
72, // at 50 : <select_goil_5F_syntax_14>
74, // at 51 : <select_goil_5F_syntax_15>
76, // at 52 : <select_goil_5F_syntax_16>
78, // at 53 : <select_goil_5F_syntax_17>
80, // at 54 : <select_implementation_5F_parser_0>
83, // at 55 : <select_implementation_5F_parser_1>
85, // at 56 : <select_implementation_5F_parser_2>
87, // at 57 : <select_implementation_5F_parser_3>
89, // at 58 : <select_implementation_5F_parser_4>
91, // at 59 : <select_implementation_5F_parser_5>
93, // at 60 : <select_implementation_5F_parser_6>
96, // at 61 : <select_implementation_5F_parser_7>
107, // at 62 : <select_implementation_5F_parser_8>
109, // at 63 : <select_implementation_5F_parser_9>
111, // at 64 : <select_implementation_5F_parser_10>
114, // at 65 : <select_implementation_5F_parser_11>
116, // at 66 : <select_implementation_5F_parser_12>
118, // at 67 : <select_implementation_5F_parser_13>
120, // at 68 : <select_implementation_5F_parser_14>
122, // at 69 : <select_implementation_5F_parser_15>
124, // at 70 : <select_implementation_5F_parser_16>
126, // at 71 : <select_implementation_5F_parser_17>
128, // at 72 : <select_implementation_5F_parser_18>
131, // at 73 : <select_implementation_5F_parser_19>
133, // at 74 : <select_implementation_5F_parser_20>
136, // at 75 : <select_implementation_5F_parser_21>
138, // at 76 : <select_implementation_5F_parser_22>
141, // at 77 : <select_implementation_5F_parser_23>
143, // at 78 : <select_implementation_5F_parser_24>
145, // at 79 : <select_implementation_5F_parser_25>
147, // at 80 : <select_implementation_5F_parser_26>
150, // at 81 : <select_implementation_5F_parser_27>
152, // at 82 : <select_implementation_5F_parser_28>
154, // at 83 : <select_implementation_5F_parser_29>
156, // at 84 : <select_implementation_5F_parser_30>
158, // at 85 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_goil_file_level_include [] = {
// At index 0 : <implementation_definition> only one production, no choice
  -1,
// At index 1 : <start> only one production, no choice
  -1,
// At index 2 : <file> only one production, no choice
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
// At index 14 : <implementation_object_list> only one production, no choice
  -1,
// At index 15 : <include_implementation_level> only one production, no choice
  -1,
// At index 16 : <include_type_level> only one production, no choice
  -1,
// At index 17 : <implementation_objects> only one production, no choice
  -1,
// At index 18 : <implementation_list> only one production, no choice
  -1,
// At index 19 : <implementation_type> only one production, no choice
  -1,
// At index 20 : <struct_options> only one production, no choice
  -1,
// At index 21 : <objref_option> only one production, no choice
  -1,
// At index 22 : <string_options> only one production, no choice
  -1,
// At index 23 : <boolean_options> only one production, no choice
  -1,
// At index 24 : <enum_item> only one production, no choice
  -1,
// At index 25 : <enum_options> only one production, no choice
  -1,
// At index 26 : <number_options> only one production, no choice
  -1,
// At index 27 : <type_options> only one production, no choice
  -1,
// At index 28 : <with_auto> only one production, no choice
  -1,
// At index 29 : <int_or_float> only one production, no choice
  -1,
// At index 30 : <set_followup> only one production, no choice
  -1,
// At index 31 : <range_content> only one production, no choice
  -1,
// At index 32 : <range> only one production, no choice
  -1,
// At index 33 : <multiple> only one production, no choice
  -1,
// At index 34 : <identifier_or_attribute> only one production, no choice
  -1,
// At index 35 : <identifier_or_enum_value> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 36 : <select_goil_5F_syntax_0>
C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 46 : <select_goil_5F_syntax_1>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 3
  -1,
// At index 55 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 62 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 69 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 77 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 82 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 90 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 95 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 111 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 117 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 122 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 128 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 133 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 138 : <select_goil_5F_syntax_14>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 143 : <select_goil_5F_syntax_15>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 148 : <select_goil_5F_syntax_16>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 153 : <select_goil_5F_syntax_17>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 158 : <select_implementation_5F_parser_0>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 166 : <select_implementation_5F_parser_1>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 171 : <select_implementation_5F_parser_2>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 176 : <select_implementation_5F_parser_3>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 181 : <select_implementation_5F_parser_4>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 186 : <select_implementation_5F_parser_5>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 2
  -1,
// At index 191 : <select_implementation_5F_parser_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken_UINT_33__32_, C_Lexique_goil_5F_lexique::kToken_INT_33__32_, C_Lexique_goil_5F_lexique::kToken_UINT_36__34_, C_Lexique_goil_5F_lexique::kToken_INT_36__34_, C_Lexique_goil_5F_lexique::kToken_FLOAT, C_Lexique_goil_5F_lexique::kToken_ENUM, C_Lexique_goil_5F_lexique::kToken_BOOLEAN, C_Lexique_goil_5F_lexique::kToken_STRING, C_Lexique_goil_5F_lexique::kToken_IDENTIFIER, C_Lexique_goil_5F_lexique::kToken_STRUCT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 209 : <select_implementation_5F_parser_7>
C_Lexique_goil_5F_lexique::kToken_UINT_33__32_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_INT_33__32_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_UINT_36__34_, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_INT_36__34_, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_FLOAT, -1, // Choice 5
C_Lexique_goil_5F_lexique::kToken_ENUM, -1, // Choice 6
C_Lexique_goil_5F_lexique::kToken_BOOLEAN, -1, // Choice 7
C_Lexique_goil_5F_lexique::kToken_STRING, -1, // Choice 8
C_Lexique_goil_5F_lexique::kToken_IDENTIFIER, -1, // Choice 9
C_Lexique_goil_5F_lexique::kToken_STRUCT, -1, // Choice 10
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 11
  -1,
// At index 232 : <select_implementation_5F_parser_8>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 237 : <select_implementation_5F_parser_9>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 245 : <select_implementation_5F_parser_10>
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 252 : <select_implementation_5F_parser_11>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 257 : <select_implementation_5F_parser_12>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 262 : <select_implementation_5F_parser_13>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 2
  -1,
// At index 267 : <select_implementation_5F_parser_14>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 275 : <select_implementation_5F_parser_15>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 281 : <select_implementation_5F_parser_16>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 286 : <select_implementation_5F_parser_17>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 294 : <select_implementation_5F_parser_18>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 301 : <select_implementation_5F_parser_19>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 309 : <select_implementation_5F_parser_20>
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 319 : <select_implementation_5F_parser_21>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 327 : <select_implementation_5F_parser_22>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 334 : <select_implementation_5F_parser_23>
C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 2
  -1,
// At index 340 : <select_implementation_5F_parser_24>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 345 : <select_implementation_5F_parser_25>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 350 : <select_implementation_5F_parser_26>
C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 3
  -1,
// At index 357 : <select_implementation_5F_parser_27>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 363 : <select_implementation_5F_parser_28>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 369 : <select_implementation_5F_parser_29>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 374 : <select_implementation_5F_parser_30>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3D_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 381 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_goil_file_level_include [87] = {
0, // at 0 : <implementation_definition>
1, // at 1 : <start>
2, // at 2 : <file>
3, // at 3 : <sign>
4, // at 4 : <description>
5, // at 5 : <OIL_version>
6, // at 6 : <application_definition>
7, // at 7 : <object_definition_list>
8, // at 8 : <boolean>
9, // at 9 : <oil_declaration_list>
10, // at 10 : <oil_declaration>
11, // at 11 : <include_file_level>
12, // at 12 : <include_cpu_level>
13, // at 13 : <include_object_level>
14, // at 14 : <implementation_object_list>
15, // at 15 : <include_implementation_level>
16, // at 16 : <include_type_level>
17, // at 17 : <implementation_objects>
18, // at 18 : <implementation_list>
19, // at 19 : <implementation_type>
20, // at 20 : <struct_options>
21, // at 21 : <objref_option>
22, // at 22 : <string_options>
23, // at 23 : <boolean_options>
24, // at 24 : <enum_item>
25, // at 25 : <enum_options>
26, // at 26 : <number_options>
27, // at 27 : <type_options>
28, // at 28 : <with_auto>
29, // at 29 : <int_or_float>
30, // at 30 : <set_followup>
31, // at 31 : <range_content>
32, // at 32 : <range>
33, // at 33 : <multiple>
34, // at 34 : <identifier_or_attribute>
35, // at 35 : <identifier_or_enum_value>
36, // at 36 : <select_goil_5F_syntax_0>
46, // at 37 : <select_goil_5F_syntax_1>
55, // at 38 : <select_goil_5F_syntax_2>
62, // at 39 : <select_goil_5F_syntax_3>
69, // at 40 : <select_goil_5F_syntax_4>
77, // at 41 : <select_goil_5F_syntax_5>
82, // at 42 : <select_goil_5F_syntax_6>
90, // at 43 : <select_goil_5F_syntax_7>
95, // at 44 : <select_goil_5F_syntax_8>
111, // at 45 : <select_goil_5F_syntax_9>
117, // at 46 : <select_goil_5F_syntax_10>
122, // at 47 : <select_goil_5F_syntax_11>
128, // at 48 : <select_goil_5F_syntax_12>
133, // at 49 : <select_goil_5F_syntax_13>
138, // at 50 : <select_goil_5F_syntax_14>
143, // at 51 : <select_goil_5F_syntax_15>
148, // at 52 : <select_goil_5F_syntax_16>
153, // at 53 : <select_goil_5F_syntax_17>
158, // at 54 : <select_implementation_5F_parser_0>
166, // at 55 : <select_implementation_5F_parser_1>
171, // at 56 : <select_implementation_5F_parser_2>
176, // at 57 : <select_implementation_5F_parser_3>
181, // at 58 : <select_implementation_5F_parser_4>
186, // at 59 : <select_implementation_5F_parser_5>
191, // at 60 : <select_implementation_5F_parser_6>
209, // at 61 : <select_implementation_5F_parser_7>
232, // at 62 : <select_implementation_5F_parser_8>
237, // at 63 : <select_implementation_5F_parser_9>
245, // at 64 : <select_implementation_5F_parser_10>
252, // at 65 : <select_implementation_5F_parser_11>
257, // at 66 : <select_implementation_5F_parser_12>
262, // at 67 : <select_implementation_5F_parser_13>
267, // at 68 : <select_implementation_5F_parser_14>
275, // at 69 : <select_implementation_5F_parser_15>
281, // at 70 : <select_implementation_5F_parser_16>
286, // at 71 : <select_implementation_5F_parser_17>
294, // at 72 : <select_implementation_5F_parser_18>
301, // at 73 : <select_implementation_5F_parser_19>
309, // at 74 : <select_implementation_5F_parser_20>
319, // at 75 : <select_implementation_5F_parser_21>
327, // at 76 : <select_implementation_5F_parser_22>
334, // at 77 : <select_implementation_5F_parser_23>
340, // at 78 : <select_implementation_5F_parser_24>
345, // at 79 : <select_implementation_5F_parser_25>
350, // at 80 : <select_implementation_5F_parser_26>
357, // at 81 : <select_implementation_5F_parser_27>
363, // at 82 : <select_implementation_5F_parser_28>
369, // at 83 : <select_implementation_5F_parser_29>
374, // at 84 : <select_implementation_5F_parser_30>
381, // at 85 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_definition' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_definition_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'start' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_start_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_start_ (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_(inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'file' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_file_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_file_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_goil_5F_file_5F_level_5F_include::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performTopDownParsing (gProductions_goil_file_level_include, gProductionNames_goil_file_level_include, gProductionIndexes_goil_file_level_include,
                                    gFirstProductionIndexes_goil_file_level_include, gDecision_goil_file_level_include, gDecisionIndexes_goil_file_level_include, 448) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_implementation &  parameter_1,
                                GALGAS_applicationDefinition &  parameter_2,
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
      const bool ok = scanner->performTopDownParsing (gProductions_goil_file_level_include, gProductionNames_goil_file_level_include, gProductionIndexes_goil_file_level_include,
                                                      gFirstProductionIndexes_goil_file_level_include, gDecision_goil_file_level_include, gDecisionIndexes_goil_file_level_include, 448) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_file_5F_level_5F_include grammar ;
        grammar.nt_file_ (parameter_1, parameter_2, parameter_3, parameter_4, scanner) ;
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

void cGrammar_goil_5F_file_5F_level_5F_include::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                GALGAS_implementation &  parameter_1,
                                GALGAS_applicationDefinition &  parameter_2,
                                GALGAS_string &  parameter_3,
                                const GALGAS_bool  parameter_4
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_goil_file_level_include, gProductionNames_goil_file_level_include, gProductionIndexes_goil_file_level_include,
                                                    gFirstProductionIndexes_goil_file_level_include, gDecision_goil_file_level_include, gDecisionIndexes_goil_file_level_include, 448) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_goil_5F_file_5F_level_5F_include grammar ;
      grammar.nt_file_ (parameter_1, parameter_2, parameter_3, parameter_4, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'sign' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'description' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'OIL_version' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'application_definition' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_application_5F_definition_ (const GALGAS_implementation parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'object_definition_list' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_object_5F_definition_5F_list_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'boolean' non terminal implementation                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'oil_declaration_list' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'oil_declaration' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_file_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_file_5F_level_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_cpu_level' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_cpu_5F_level_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'include_object_level' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_object_list' non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_object_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_object_5F_list_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'include_implementation_level' non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_implementation_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_implementation_5F_level_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_type_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_type_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'implementation_objects' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_objects_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_objects_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'implementation_list' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_list_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'implementation_type' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_type_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_type_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'struct_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_struct_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_struct_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'objref_option' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_objref_5F_option_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_objref_5F_option_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'string_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_string_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_string_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'boolean_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_boolean_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_boolean_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'enum_item' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_enum_5F_item_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_enum_5F_item_ (GALGAS_enumValues & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'enum_options' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_enum_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_enum_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'number_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_number_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_number_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'type_options' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_type_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_type_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'with_auto' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_with_5F_auto_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_with_5F_auto_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'int_or_float' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_int_5F_or_5F_float_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'set_followup' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_set_5F_followup_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_set_5F_followup_ (GALGAS_numberList & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'range_content' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_range_5F_content_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_range_5F_content_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'range' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_range_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_range_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'multiple' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_multiple_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_multiple_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'identifier_or_attribute' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'identifier_or_enum_value' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_0' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_1' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_2' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_3' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_4' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_5' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_6' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_7' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_8' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_9' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_10' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_11' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_12' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_13' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_14' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_15' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_16' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_17' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_0' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_1' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_2' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_3' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_4' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_5' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_6' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_7' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_8' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_9' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_10' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_11' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_12' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_13' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_14' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_15' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_16' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_17' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_18' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_18 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_19' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_19 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_20' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_20 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_21' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_21 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_22' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_22 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_23' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_23 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_24' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_24 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_25' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_25 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_26' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_26 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_27' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_27 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_28' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_28 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_29' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_29 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_30' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_30 (C_Lexique_goil_5F_lexique * inLexique) {
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

static const int16_t gProductions_goil_implementation_level_include [] = {
// At index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 36
  TERMINAL (C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION) // $IMPLEMENTATION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (14) // <implementation_object_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 7 : <start>, in file 'goil_syntax.ggs', line 38
, NONTERMINAL (5) // <OIL_version>
, NONTERMINAL (2) // <file>
, END_PRODUCTION
// At index 10 : <file>, in file 'goil_syntax.ggs', line 110
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 12 : <sign>, in file 'goil_syntax.ggs', line 126
, NONTERMINAL (37) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 14 : <description>, in file 'goil_syntax.ggs', line 139
, NONTERMINAL (38) // <select_goil_5F_syntax_2>
, END_PRODUCTION
// At index 16 : <OIL_version>, in file 'goil_syntax.ggs', line 163
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) // $OIL_VERSION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 22 : <application_definition>, in file 'goil_syntax.ggs', line 170
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) // $CPU$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (7) // <object_definition_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 30 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 32 : <boolean>, in file 'goil_syntax.ggs', line 234
, NONTERMINAL (41) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 34 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 36 : <oil_declaration>, in file 'goil_syntax.ggs', line 256
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (43) // <select_goil_5F_syntax_7>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 40 : <include_file_level>, in file 'goil_syntax.ggs', line 463
, NONTERMINAL (48) // <select_goil_5F_syntax_12>
, NONTERMINAL (49) // <select_goil_5F_syntax_13>
, END_PRODUCTION
// At index 43 : <include_cpu_level>, in file 'goil_syntax.ggs', line 487
, NONTERMINAL (50) // <select_goil_5F_syntax_14>
, NONTERMINAL (51) // <select_goil_5F_syntax_15>
, END_PRODUCTION
// At index 46 : <include_object_level>, in file 'goil_syntax.ggs', line 511
, NONTERMINAL (52) // <select_goil_5F_syntax_16>
, NONTERMINAL (53) // <select_goil_5F_syntax_17>
, END_PRODUCTION
// At index 49 : <implementation_object_list>, in file 'implementation_parser.ggs', line 44
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 51 : <include_implementation_level>, in file 'implementation_parser.ggs', line 53
, NONTERMINAL (55) // <select_implementation_5F_parser_1>
, NONTERMINAL (56) // <select_implementation_5F_parser_2>
, END_PRODUCTION
// At index 54 : <include_type_level>, in file 'implementation_parser.ggs', line 74
, NONTERMINAL (57) // <select_implementation_5F_parser_3>
, NONTERMINAL (58) // <select_implementation_5F_parser_4>
, END_PRODUCTION
// At index 57 : <implementation_objects>, in file 'implementation_parser.ggs', line 95
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (59) // <select_implementation_5F_parser_5>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 63 : <implementation_list>, in file 'implementation_parser.ggs', line 132
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 65 : <implementation_type>, in file 'implementation_parser.ggs', line 210
, NONTERMINAL (61) // <select_implementation_5F_parser_7>
, END_PRODUCTION
// At index 67 : <struct_options>, in file 'implementation_parser.ggs', line 238
, NONTERMINAL (62) // <select_implementation_5F_parser_8>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 72 : <objref_option>, in file 'implementation_parser.ggs', line 255
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 76 : <string_options>, in file 'implementation_parser.ggs', line 273
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (63) // <select_implementation_5F_parser_9>
, END_PRODUCTION
// At index 81 : <boolean_options>, in file 'implementation_parser.ggs', line 310
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (65) // <select_implementation_5F_parser_11>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (68) // <select_implementation_5F_parser_14>
, END_PRODUCTION
// At index 87 : <enum_item>, in file 'implementation_parser.ggs', line 355
, NONTERMINAL (35) // <identifier_or_enum_value>
, NONTERMINAL (69) // <select_implementation_5F_parser_15>
, END_PRODUCTION
// At index 90 : <enum_options>, in file 'implementation_parser.ggs', line 368
, NONTERMINAL (28) // <with_auto>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (71) // <select_implementation_5F_parser_17>
, END_PRODUCTION
// At index 99 : <number_options>, in file 'implementation_parser.ggs', line 415
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (32) // <range>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (73) // <select_implementation_5F_parser_19>
, END_PRODUCTION
// At index 105 : <type_options>, in file 'implementation_parser.ggs', line 454
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (75) // <select_implementation_5F_parser_21>
, END_PRODUCTION
// At index 110 : <with_auto>, in file 'implementation_parser.ggs', line 493
, NONTERMINAL (77) // <select_implementation_5F_parser_23>
, END_PRODUCTION
// At index 112 : <int_or_float>, in file 'implementation_parser.ggs', line 502
, NONTERMINAL (3) // <sign>
, NONTERMINAL (78) // <select_implementation_5F_parser_24>
, END_PRODUCTION
// At index 115 : <set_followup>, in file 'implementation_parser.ggs', line 520
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 117 : <range_content>, in file 'implementation_parser.ggs', line 532
, NONTERMINAL (3) // <sign>
, NONTERMINAL (80) // <select_implementation_5F_parser_26>
, END_PRODUCTION
// At index 120 : <range>, in file 'implementation_parser.ggs', line 572
, NONTERMINAL (83) // <select_implementation_5F_parser_29>
, END_PRODUCTION
// At index 122 : <multiple>, in file 'implementation_parser.ggs', line 582
, NONTERMINAL (84) // <select_implementation_5F_parser_30>
, END_PRODUCTION
// At index 124 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 592
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
// At index 126 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 597
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 128 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, END_PRODUCTION
// At index 129 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (11) // <include_file_level>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 132 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 135 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (6) // <application_definition>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 138 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) // $-$
, END_PRODUCTION
// At index 140 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) // $+$
, END_PRODUCTION
// At index 142 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, END_PRODUCTION
// At index 143 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, END_PRODUCTION
// At index 144 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) // $:$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (39) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 148 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, END_PRODUCTION
// At index 149 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (39) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 152 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, END_PRODUCTION
// At index 153 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 162 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, NONTERMINAL (12) // <include_cpu_level>
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 165 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 167 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 169 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
, END_PRODUCTION
// At index 170 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
, NONTERMINAL (10) // <oil_declaration>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 173 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
, NONTERMINAL (13) // <include_object_level>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 176 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (44) // <select_goil_5F_syntax_8>
, END_PRODUCTION
// At index 179 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 185 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (45) // <select_goil_5F_syntax_9>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 189 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, NONTERMINAL (3) // <sign>
, NONTERMINAL (46) // <select_goil_5F_syntax_10>
, END_PRODUCTION
// At index 192 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (47) // <select_goil_5F_syntax_11>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 196 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 199 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 202 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 206 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
, END_PRODUCTION
// At index 207 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 210 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 213 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 356
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 217 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 356
, END_PRODUCTION
// At index 218 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 470
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 220 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 470
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 222 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 476
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 224 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 476
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 226 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 494
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 228 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 494
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 230 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 500
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 232 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 500
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 234 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 516
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 236 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 516
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 238 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 522
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 240 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 522
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 242 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
, END_PRODUCTION
// At index 243 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
, NONTERMINAL (17) // <implementation_objects>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 247 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
, NONTERMINAL (15) // <include_implementation_level>
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 250 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 57
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 252 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 57
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 254 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 63
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 256 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 63
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 258 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 78
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 260 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 78
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 262 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 84
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 264 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 84
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 266 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 102
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 269 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 102
, END_PRODUCTION
// At index 270 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
, END_PRODUCTION
// At index 271 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
, NONTERMINAL (19) // <implementation_type>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 275 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
, NONTERMINAL (16) // <include_type_level>
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 278 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_) // $UINT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 281 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_33__32_) // $INT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 284 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_) // $UINT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 287 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_36__34_) // $INT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 290 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FLOAT) // $FLOAT$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 293 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_ENUM) // $ENUM$
, NONTERMINAL (25) // <enum_options>
, END_PRODUCTION
// At index 296 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_BOOLEAN) // $BOOLEAN$
, NONTERMINAL (23) // <boolean_options>
, END_PRODUCTION
// At index 299 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRING) // $STRING$
, NONTERMINAL (22) // <string_options>
, END_PRODUCTION
// At index 302 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER) // $IDENTIFIER$
, NONTERMINAL (27) // <type_options>
, END_PRODUCTION
// At index 305 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRUCT) // $STRUCT$
, NONTERMINAL (20) // <struct_options>
, END_PRODUCTION
// At index 308 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (21) // <objref_option>
, END_PRODUCTION
// At index 311 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 242
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 315 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 242
, END_PRODUCTION
// At index 316 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 283
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (64) // <select_implementation_5F_parser_10>
, END_PRODUCTION
// At index 319 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 283
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 321 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 324 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 327 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 330 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 317
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, NONTERMINAL (66) // <select_implementation_5F_parser_12>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, NONTERMINAL (67) // <select_implementation_5F_parser_13>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 338 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 317
, END_PRODUCTION
// At index 339 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 320
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 343 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 320
, END_PRODUCTION
// At index 344 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 329
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 348 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 329
, END_PRODUCTION
// At index 349 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 343
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 353 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 343
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 355 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 360
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 359 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 360
, END_PRODUCTION
// At index 360 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 376
, END_PRODUCTION
// At index 361 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 376
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, END_PRODUCTION
// At index 365 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 386
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (72) // <select_implementation_5F_parser_18>
, END_PRODUCTION
// At index 368 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 386
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 370 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 373 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 376 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 379 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 428
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (74) // <select_implementation_5F_parser_20>
, END_PRODUCTION
// At index 382 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 428
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 384 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 386 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 389 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 392 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 465
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (76) // <select_implementation_5F_parser_22>
, END_PRODUCTION
// At index 395 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 465
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 397 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 400 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 403 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 406 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 495
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO) // $WITH_AUTO$
, END_PRODUCTION
// At index 408 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 495
, END_PRODUCTION
// At index 409 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 507
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 412 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 507
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 415 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 523
, END_PRODUCTION
// At index 416 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 523
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (29) // <int_or_float>
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 420 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number) // $set_start_uint_number$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 423 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (81) // <select_implementation_5F_parser_27>
, END_PRODUCTION
// At index 426 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (82) // <select_implementation_5F_parser_28>
, END_PRODUCTION
// At index 429 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 549
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 432 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 549
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 434 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 561
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 437 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 561
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 439 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 575
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (31) // <range_content>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 443 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 575
, END_PRODUCTION
// At index 444 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 584
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 447 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 584
, END_PRODUCTION
// At index 448 : <>, in file '.ggs', line 0
, NONTERMINAL (14) // <implementation_object_list>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_goil_implementation_level_include [159] = {
 {"<implementation_definition>", "implementation_parser", 0}, // at index 0
 {"<start>", "goil_syntax", 7}, // at index 1
 {"<file>", "goil_syntax", 10}, // at index 2
 {"<sign>", "goil_syntax", 12}, // at index 3
 {"<description>", "goil_syntax", 14}, // at index 4
 {"<OIL_version>", "goil_syntax", 16}, // at index 5
 {"<application_definition>", "goil_syntax", 22}, // at index 6
 {"<object_definition_list>", "goil_syntax", 30}, // at index 7
 {"<boolean>", "goil_syntax", 32}, // at index 8
 {"<oil_declaration_list>", "goil_syntax", 34}, // at index 9
 {"<oil_declaration>", "goil_syntax", 36}, // at index 10
 {"<include_file_level>", "goil_syntax", 40}, // at index 11
 {"<include_cpu_level>", "goil_syntax", 43}, // at index 12
 {"<include_object_level>", "goil_syntax", 46}, // at index 13
 {"<implementation_object_list>", "implementation_parser", 49}, // at index 14
 {"<include_implementation_level>", "implementation_parser", 51}, // at index 15
 {"<include_type_level>", "implementation_parser", 54}, // at index 16
 {"<implementation_objects>", "implementation_parser", 57}, // at index 17
 {"<implementation_list>", "implementation_parser", 63}, // at index 18
 {"<implementation_type>", "implementation_parser", 65}, // at index 19
 {"<struct_options>", "implementation_parser", 67}, // at index 20
 {"<objref_option>", "implementation_parser", 72}, // at index 21
 {"<string_options>", "implementation_parser", 76}, // at index 22
 {"<boolean_options>", "implementation_parser", 81}, // at index 23
 {"<enum_item>", "implementation_parser", 87}, // at index 24
 {"<enum_options>", "implementation_parser", 90}, // at index 25
 {"<number_options>", "implementation_parser", 99}, // at index 26
 {"<type_options>", "implementation_parser", 105}, // at index 27
 {"<with_auto>", "implementation_parser", 110}, // at index 28
 {"<int_or_float>", "implementation_parser", 112}, // at index 29
 {"<set_followup>", "implementation_parser", 115}, // at index 30
 {"<range_content>", "implementation_parser", 117}, // at index 31
 {"<range>", "implementation_parser", 120}, // at index 32
 {"<multiple>", "implementation_parser", 122}, // at index 33
 {"<identifier_or_attribute>", "implementation_parser", 124}, // at index 34
 {"<identifier_or_enum_value>", "implementation_parser", 126}, // at index 35
 {"<select_goil_5F_syntax_0>", "goil_syntax", 128}, // at index 36
 {"<select_goil_5F_syntax_0>", "goil_syntax", 129}, // at index 37
 {"<select_goil_5F_syntax_0>", "goil_syntax", 132}, // at index 38
 {"<select_goil_5F_syntax_0>", "goil_syntax", 135}, // at index 39
 {"<select_goil_5F_syntax_1>", "goil_syntax", 138}, // at index 40
 {"<select_goil_5F_syntax_1>", "goil_syntax", 140}, // at index 41
 {"<select_goil_5F_syntax_1>", "goil_syntax", 142}, // at index 42
 {"<select_goil_5F_syntax_2>", "goil_syntax", 143}, // at index 43
 {"<select_goil_5F_syntax_2>", "goil_syntax", 144}, // at index 44
 {"<select_goil_5F_syntax_3>", "goil_syntax", 148}, // at index 45
 {"<select_goil_5F_syntax_3>", "goil_syntax", 149}, // at index 46
 {"<select_goil_5F_syntax_4>", "goil_syntax", 152}, // at index 47
 {"<select_goil_5F_syntax_4>", "goil_syntax", 153}, // at index 48
 {"<select_goil_5F_syntax_4>", "goil_syntax", 162}, // at index 49
 {"<select_goil_5F_syntax_5>", "goil_syntax", 165}, // at index 50
 {"<select_goil_5F_syntax_5>", "goil_syntax", 167}, // at index 51
 {"<select_goil_5F_syntax_6>", "goil_syntax", 169}, // at index 52
 {"<select_goil_5F_syntax_6>", "goil_syntax", 170}, // at index 53
 {"<select_goil_5F_syntax_6>", "goil_syntax", 173}, // at index 54
 {"<select_goil_5F_syntax_7>", "goil_syntax", 176}, // at index 55
 {"<select_goil_5F_syntax_7>", "goil_syntax", 179}, // at index 56
 {"<select_goil_5F_syntax_8>", "goil_syntax", 185}, // at index 57
 {"<select_goil_5F_syntax_8>", "goil_syntax", 189}, // at index 58
 {"<select_goil_5F_syntax_8>", "goil_syntax", 192}, // at index 59
 {"<select_goil_5F_syntax_8>", "goil_syntax", 196}, // at index 60
 {"<select_goil_5F_syntax_8>", "goil_syntax", 199}, // at index 61
 {"<select_goil_5F_syntax_9>", "goil_syntax", 202}, // at index 62
 {"<select_goil_5F_syntax_9>", "goil_syntax", 206}, // at index 63
 {"<select_goil_5F_syntax_10>", "goil_syntax", 207}, // at index 64
 {"<select_goil_5F_syntax_10>", "goil_syntax", 210}, // at index 65
 {"<select_goil_5F_syntax_11>", "goil_syntax", 213}, // at index 66
 {"<select_goil_5F_syntax_11>", "goil_syntax", 217}, // at index 67
 {"<select_goil_5F_syntax_12>", "goil_syntax", 218}, // at index 68
 {"<select_goil_5F_syntax_12>", "goil_syntax", 220}, // at index 69
 {"<select_goil_5F_syntax_13>", "goil_syntax", 222}, // at index 70
 {"<select_goil_5F_syntax_13>", "goil_syntax", 224}, // at index 71
 {"<select_goil_5F_syntax_14>", "goil_syntax", 226}, // at index 72
 {"<select_goil_5F_syntax_14>", "goil_syntax", 228}, // at index 73
 {"<select_goil_5F_syntax_15>", "goil_syntax", 230}, // at index 74
 {"<select_goil_5F_syntax_15>", "goil_syntax", 232}, // at index 75
 {"<select_goil_5F_syntax_16>", "goil_syntax", 234}, // at index 76
 {"<select_goil_5F_syntax_16>", "goil_syntax", 236}, // at index 77
 {"<select_goil_5F_syntax_17>", "goil_syntax", 238}, // at index 78
 {"<select_goil_5F_syntax_17>", "goil_syntax", 240}, // at index 79
 {"<select_implementation_5F_parser_0>", "implementation_parser", 242}, // at index 80
 {"<select_implementation_5F_parser_0>", "implementation_parser", 243}, // at index 81
 {"<select_implementation_5F_parser_0>", "implementation_parser", 247}, // at index 82
 {"<select_implementation_5F_parser_1>", "implementation_parser", 250}, // at index 83
 {"<select_implementation_5F_parser_1>", "implementation_parser", 252}, // at index 84
 {"<select_implementation_5F_parser_2>", "implementation_parser", 254}, // at index 85
 {"<select_implementation_5F_parser_2>", "implementation_parser", 256}, // at index 86
 {"<select_implementation_5F_parser_3>", "implementation_parser", 258}, // at index 87
 {"<select_implementation_5F_parser_3>", "implementation_parser", 260}, // at index 88
 {"<select_implementation_5F_parser_4>", "implementation_parser", 262}, // at index 89
 {"<select_implementation_5F_parser_4>", "implementation_parser", 264}, // at index 90
 {"<select_implementation_5F_parser_5>", "implementation_parser", 266}, // at index 91
 {"<select_implementation_5F_parser_5>", "implementation_parser", 269}, // at index 92
 {"<select_implementation_5F_parser_6>", "implementation_parser", 270}, // at index 93
 {"<select_implementation_5F_parser_6>", "implementation_parser", 271}, // at index 94
 {"<select_implementation_5F_parser_6>", "implementation_parser", 275}, // at index 95
 {"<select_implementation_5F_parser_7>", "implementation_parser", 278}, // at index 96
 {"<select_implementation_5F_parser_7>", "implementation_parser", 281}, // at index 97
 {"<select_implementation_5F_parser_7>", "implementation_parser", 284}, // at index 98
 {"<select_implementation_5F_parser_7>", "implementation_parser", 287}, // at index 99
 {"<select_implementation_5F_parser_7>", "implementation_parser", 290}, // at index 100
 {"<select_implementation_5F_parser_7>", "implementation_parser", 293}, // at index 101
 {"<select_implementation_5F_parser_7>", "implementation_parser", 296}, // at index 102
 {"<select_implementation_5F_parser_7>", "implementation_parser", 299}, // at index 103
 {"<select_implementation_5F_parser_7>", "implementation_parser", 302}, // at index 104
 {"<select_implementation_5F_parser_7>", "implementation_parser", 305}, // at index 105
 {"<select_implementation_5F_parser_7>", "implementation_parser", 308}, // at index 106
 {"<select_implementation_5F_parser_8>", "implementation_parser", 311}, // at index 107
 {"<select_implementation_5F_parser_8>", "implementation_parser", 315}, // at index 108
 {"<select_implementation_5F_parser_9>", "implementation_parser", 316}, // at index 109
 {"<select_implementation_5F_parser_9>", "implementation_parser", 319}, // at index 110
 {"<select_implementation_5F_parser_10>", "implementation_parser", 321}, // at index 111
 {"<select_implementation_5F_parser_10>", "implementation_parser", 324}, // at index 112
 {"<select_implementation_5F_parser_10>", "implementation_parser", 327}, // at index 113
 {"<select_implementation_5F_parser_11>", "implementation_parser", 330}, // at index 114
 {"<select_implementation_5F_parser_11>", "implementation_parser", 338}, // at index 115
 {"<select_implementation_5F_parser_12>", "implementation_parser", 339}, // at index 116
 {"<select_implementation_5F_parser_12>", "implementation_parser", 343}, // at index 117
 {"<select_implementation_5F_parser_13>", "implementation_parser", 344}, // at index 118
 {"<select_implementation_5F_parser_13>", "implementation_parser", 348}, // at index 119
 {"<select_implementation_5F_parser_14>", "implementation_parser", 349}, // at index 120
 {"<select_implementation_5F_parser_14>", "implementation_parser", 353}, // at index 121
 {"<select_implementation_5F_parser_15>", "implementation_parser", 355}, // at index 122
 {"<select_implementation_5F_parser_15>", "implementation_parser", 359}, // at index 123
 {"<select_implementation_5F_parser_16>", "implementation_parser", 360}, // at index 124
 {"<select_implementation_5F_parser_16>", "implementation_parser", 361}, // at index 125
 {"<select_implementation_5F_parser_17>", "implementation_parser", 365}, // at index 126
 {"<select_implementation_5F_parser_17>", "implementation_parser", 368}, // at index 127
 {"<select_implementation_5F_parser_18>", "implementation_parser", 370}, // at index 128
 {"<select_implementation_5F_parser_18>", "implementation_parser", 373}, // at index 129
 {"<select_implementation_5F_parser_18>", "implementation_parser", 376}, // at index 130
 {"<select_implementation_5F_parser_19>", "implementation_parser", 379}, // at index 131
 {"<select_implementation_5F_parser_19>", "implementation_parser", 382}, // at index 132
 {"<select_implementation_5F_parser_20>", "implementation_parser", 384}, // at index 133
 {"<select_implementation_5F_parser_20>", "implementation_parser", 386}, // at index 134
 {"<select_implementation_5F_parser_20>", "implementation_parser", 389}, // at index 135
 {"<select_implementation_5F_parser_21>", "implementation_parser", 392}, // at index 136
 {"<select_implementation_5F_parser_21>", "implementation_parser", 395}, // at index 137
 {"<select_implementation_5F_parser_22>", "implementation_parser", 397}, // at index 138
 {"<select_implementation_5F_parser_22>", "implementation_parser", 400}, // at index 139
 {"<select_implementation_5F_parser_22>", "implementation_parser", 403}, // at index 140
 {"<select_implementation_5F_parser_23>", "implementation_parser", 406}, // at index 141
 {"<select_implementation_5F_parser_23>", "implementation_parser", 408}, // at index 142
 {"<select_implementation_5F_parser_24>", "implementation_parser", 409}, // at index 143
 {"<select_implementation_5F_parser_24>", "implementation_parser", 412}, // at index 144
 {"<select_implementation_5F_parser_25>", "implementation_parser", 415}, // at index 145
 {"<select_implementation_5F_parser_25>", "implementation_parser", 416}, // at index 146
 {"<select_implementation_5F_parser_26>", "implementation_parser", 420}, // at index 147
 {"<select_implementation_5F_parser_26>", "implementation_parser", 423}, // at index 148
 {"<select_implementation_5F_parser_26>", "implementation_parser", 426}, // at index 149
 {"<select_implementation_5F_parser_27>", "implementation_parser", 429}, // at index 150
 {"<select_implementation_5F_parser_27>", "implementation_parser", 432}, // at index 151
 {"<select_implementation_5F_parser_28>", "implementation_parser", 434}, // at index 152
 {"<select_implementation_5F_parser_28>", "implementation_parser", 437}, // at index 153
 {"<select_implementation_5F_parser_29>", "implementation_parser", 439}, // at index 154
 {"<select_implementation_5F_parser_29>", "implementation_parser", 443}, // at index 155
 {"<select_implementation_5F_parser_30>", "implementation_parser", 444}, // at index 156
 {"<select_implementation_5F_parser_30>", "implementation_parser", 447}, // at index 157
 {"<>", "", 448} // at index 158
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_goil_implementation_level_include [159] = {
0, // index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 36
7, // index 1 : <start>, in file 'goil_syntax.ggs', line 38
10, // index 2 : <file>, in file 'goil_syntax.ggs', line 110
12, // index 3 : <sign>, in file 'goil_syntax.ggs', line 126
14, // index 4 : <description>, in file 'goil_syntax.ggs', line 139
16, // index 5 : <OIL_version>, in file 'goil_syntax.ggs', line 163
22, // index 6 : <application_definition>, in file 'goil_syntax.ggs', line 170
30, // index 7 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
32, // index 8 : <boolean>, in file 'goil_syntax.ggs', line 234
34, // index 9 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 244
36, // index 10 : <oil_declaration>, in file 'goil_syntax.ggs', line 256
40, // index 11 : <include_file_level>, in file 'goil_syntax.ggs', line 463
43, // index 12 : <include_cpu_level>, in file 'goil_syntax.ggs', line 487
46, // index 13 : <include_object_level>, in file 'goil_syntax.ggs', line 511
49, // index 14 : <implementation_object_list>, in file 'implementation_parser.ggs', line 44
51, // index 15 : <include_implementation_level>, in file 'implementation_parser.ggs', line 53
54, // index 16 : <include_type_level>, in file 'implementation_parser.ggs', line 74
57, // index 17 : <implementation_objects>, in file 'implementation_parser.ggs', line 95
63, // index 18 : <implementation_list>, in file 'implementation_parser.ggs', line 132
65, // index 19 : <implementation_type>, in file 'implementation_parser.ggs', line 210
67, // index 20 : <struct_options>, in file 'implementation_parser.ggs', line 238
72, // index 21 : <objref_option>, in file 'implementation_parser.ggs', line 255
76, // index 22 : <string_options>, in file 'implementation_parser.ggs', line 273
81, // index 23 : <boolean_options>, in file 'implementation_parser.ggs', line 310
87, // index 24 : <enum_item>, in file 'implementation_parser.ggs', line 355
90, // index 25 : <enum_options>, in file 'implementation_parser.ggs', line 368
99, // index 26 : <number_options>, in file 'implementation_parser.ggs', line 415
105, // index 27 : <type_options>, in file 'implementation_parser.ggs', line 454
110, // index 28 : <with_auto>, in file 'implementation_parser.ggs', line 493
112, // index 29 : <int_or_float>, in file 'implementation_parser.ggs', line 502
115, // index 30 : <set_followup>, in file 'implementation_parser.ggs', line 520
117, // index 31 : <range_content>, in file 'implementation_parser.ggs', line 532
120, // index 32 : <range>, in file 'implementation_parser.ggs', line 572
122, // index 33 : <multiple>, in file 'implementation_parser.ggs', line 582
124, // index 34 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 592
126, // index 35 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 597
128, // index 36 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
129, // index 37 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
132, // index 38 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
135, // index 39 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
138, // index 40 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
140, // index 41 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
142, // index 42 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
143, // index 43 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
144, // index 44 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
148, // index 45 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
149, // index 46 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
152, // index 47 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
153, // index 48 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
162, // index 49 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
165, // index 50 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
167, // index 51 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
169, // index 52 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
170, // index 53 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
173, // index 54 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
176, // index 55 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
179, // index 56 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
185, // index 57 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
189, // index 58 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
192, // index 59 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
196, // index 60 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
199, // index 61 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
202, // index 62 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
206, // index 63 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
207, // index 64 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
210, // index 65 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
213, // index 66 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 356
217, // index 67 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 356
218, // index 68 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 470
220, // index 69 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 470
222, // index 70 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 476
224, // index 71 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 476
226, // index 72 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 494
228, // index 73 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 494
230, // index 74 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 500
232, // index 75 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 500
234, // index 76 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 516
236, // index 77 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 516
238, // index 78 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 522
240, // index 79 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 522
242, // index 80 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
243, // index 81 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
247, // index 82 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
250, // index 83 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 57
252, // index 84 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 57
254, // index 85 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 63
256, // index 86 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 63
258, // index 87 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 78
260, // index 88 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 78
262, // index 89 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 84
264, // index 90 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 84
266, // index 91 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 102
269, // index 92 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 102
270, // index 93 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
271, // index 94 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
275, // index 95 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
278, // index 96 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
281, // index 97 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
284, // index 98 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
287, // index 99 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
290, // index 100 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
293, // index 101 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
296, // index 102 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
299, // index 103 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
302, // index 104 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
305, // index 105 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
308, // index 106 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
311, // index 107 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 242
315, // index 108 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 242
316, // index 109 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 283
319, // index 110 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 283
321, // index 111 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
324, // index 112 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
327, // index 113 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
330, // index 114 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 317
338, // index 115 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 317
339, // index 116 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 320
343, // index 117 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 320
344, // index 118 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 329
348, // index 119 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 329
349, // index 120 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 343
353, // index 121 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 343
355, // index 122 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 360
359, // index 123 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 360
360, // index 124 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 376
361, // index 125 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 376
365, // index 126 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 386
368, // index 127 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 386
370, // index 128 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
373, // index 129 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
376, // index 130 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
379, // index 131 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 428
382, // index 132 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 428
384, // index 133 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
386, // index 134 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
389, // index 135 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
392, // index 136 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 465
395, // index 137 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 465
397, // index 138 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
400, // index 139 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
403, // index 140 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
406, // index 141 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 495
408, // index 142 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 495
409, // index 143 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 507
412, // index 144 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 507
415, // index 145 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 523
416, // index 146 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 523
420, // index 147 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
423, // index 148 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
426, // index 149 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
429, // index 150 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 549
432, // index 151 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 549
434, // index 152 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 561
437, // index 153 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 561
439, // index 154 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 575
443, // index 155 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 575
444, // index 156 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 584
447, // index 157 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 584
448 // index 158 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_goil_implementation_level_include [87] = {
0, // at 0 : <implementation_definition>
1, // at 1 : <start>
2, // at 2 : <file>
3, // at 3 : <sign>
4, // at 4 : <description>
5, // at 5 : <OIL_version>
6, // at 6 : <application_definition>
7, // at 7 : <object_definition_list>
8, // at 8 : <boolean>
9, // at 9 : <oil_declaration_list>
10, // at 10 : <oil_declaration>
11, // at 11 : <include_file_level>
12, // at 12 : <include_cpu_level>
13, // at 13 : <include_object_level>
14, // at 14 : <implementation_object_list>
15, // at 15 : <include_implementation_level>
16, // at 16 : <include_type_level>
17, // at 17 : <implementation_objects>
18, // at 18 : <implementation_list>
19, // at 19 : <implementation_type>
20, // at 20 : <struct_options>
21, // at 21 : <objref_option>
22, // at 22 : <string_options>
23, // at 23 : <boolean_options>
24, // at 24 : <enum_item>
25, // at 25 : <enum_options>
26, // at 26 : <number_options>
27, // at 27 : <type_options>
28, // at 28 : <with_auto>
29, // at 29 : <int_or_float>
30, // at 30 : <set_followup>
31, // at 31 : <range_content>
32, // at 32 : <range>
33, // at 33 : <multiple>
34, // at 34 : <identifier_or_attribute>
35, // at 35 : <identifier_or_enum_value>
36, // at 36 : <select_goil_5F_syntax_0>
40, // at 37 : <select_goil_5F_syntax_1>
43, // at 38 : <select_goil_5F_syntax_2>
45, // at 39 : <select_goil_5F_syntax_3>
47, // at 40 : <select_goil_5F_syntax_4>
50, // at 41 : <select_goil_5F_syntax_5>
52, // at 42 : <select_goil_5F_syntax_6>
55, // at 43 : <select_goil_5F_syntax_7>
57, // at 44 : <select_goil_5F_syntax_8>
62, // at 45 : <select_goil_5F_syntax_9>
64, // at 46 : <select_goil_5F_syntax_10>
66, // at 47 : <select_goil_5F_syntax_11>
68, // at 48 : <select_goil_5F_syntax_12>
70, // at 49 : <select_goil_5F_syntax_13>
72, // at 50 : <select_goil_5F_syntax_14>
74, // at 51 : <select_goil_5F_syntax_15>
76, // at 52 : <select_goil_5F_syntax_16>
78, // at 53 : <select_goil_5F_syntax_17>
80, // at 54 : <select_implementation_5F_parser_0>
83, // at 55 : <select_implementation_5F_parser_1>
85, // at 56 : <select_implementation_5F_parser_2>
87, // at 57 : <select_implementation_5F_parser_3>
89, // at 58 : <select_implementation_5F_parser_4>
91, // at 59 : <select_implementation_5F_parser_5>
93, // at 60 : <select_implementation_5F_parser_6>
96, // at 61 : <select_implementation_5F_parser_7>
107, // at 62 : <select_implementation_5F_parser_8>
109, // at 63 : <select_implementation_5F_parser_9>
111, // at 64 : <select_implementation_5F_parser_10>
114, // at 65 : <select_implementation_5F_parser_11>
116, // at 66 : <select_implementation_5F_parser_12>
118, // at 67 : <select_implementation_5F_parser_13>
120, // at 68 : <select_implementation_5F_parser_14>
122, // at 69 : <select_implementation_5F_parser_15>
124, // at 70 : <select_implementation_5F_parser_16>
126, // at 71 : <select_implementation_5F_parser_17>
128, // at 72 : <select_implementation_5F_parser_18>
131, // at 73 : <select_implementation_5F_parser_19>
133, // at 74 : <select_implementation_5F_parser_20>
136, // at 75 : <select_implementation_5F_parser_21>
138, // at 76 : <select_implementation_5F_parser_22>
141, // at 77 : <select_implementation_5F_parser_23>
143, // at 78 : <select_implementation_5F_parser_24>
145, // at 79 : <select_implementation_5F_parser_25>
147, // at 80 : <select_implementation_5F_parser_26>
150, // at 81 : <select_implementation_5F_parser_27>
152, // at 82 : <select_implementation_5F_parser_28>
154, // at 83 : <select_implementation_5F_parser_29>
156, // at 84 : <select_implementation_5F_parser_30>
158, // at 85 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_goil_implementation_level_include [] = {
// At index 0 : <implementation_definition> only one production, no choice
  -1,
// At index 1 : <start> only one production, no choice
  -1,
// At index 2 : <file> only one production, no choice
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
// At index 14 : <implementation_object_list> only one production, no choice
  -1,
// At index 15 : <include_implementation_level> only one production, no choice
  -1,
// At index 16 : <include_type_level> only one production, no choice
  -1,
// At index 17 : <implementation_objects> only one production, no choice
  -1,
// At index 18 : <implementation_list> only one production, no choice
  -1,
// At index 19 : <implementation_type> only one production, no choice
  -1,
// At index 20 : <struct_options> only one production, no choice
  -1,
// At index 21 : <objref_option> only one production, no choice
  -1,
// At index 22 : <string_options> only one production, no choice
  -1,
// At index 23 : <boolean_options> only one production, no choice
  -1,
// At index 24 : <enum_item> only one production, no choice
  -1,
// At index 25 : <enum_options> only one production, no choice
  -1,
// At index 26 : <number_options> only one production, no choice
  -1,
// At index 27 : <type_options> only one production, no choice
  -1,
// At index 28 : <with_auto> only one production, no choice
  -1,
// At index 29 : <int_or_float> only one production, no choice
  -1,
// At index 30 : <set_followup> only one production, no choice
  -1,
// At index 31 : <range_content> only one production, no choice
  -1,
// At index 32 : <range> only one production, no choice
  -1,
// At index 33 : <multiple> only one production, no choice
  -1,
// At index 34 : <identifier_or_attribute> only one production, no choice
  -1,
// At index 35 : <identifier_or_enum_value> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 36 : <select_goil_5F_syntax_0>
-1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 45 : <select_goil_5F_syntax_1>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 3
  -1,
// At index 54 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 61 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 68 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 76 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 81 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 89 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 94 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 110 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 116 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 121 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 127 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 132 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 137 : <select_goil_5F_syntax_14>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 142 : <select_goil_5F_syntax_15>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 147 : <select_goil_5F_syntax_16>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 152 : <select_goil_5F_syntax_17>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 157 : <select_implementation_5F_parser_0>
C_Lexique_goil_5F_lexique::kToken__7D_, C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 166 : <select_implementation_5F_parser_1>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 171 : <select_implementation_5F_parser_2>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 176 : <select_implementation_5F_parser_3>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 181 : <select_implementation_5F_parser_4>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 186 : <select_implementation_5F_parser_5>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 2
  -1,
// At index 191 : <select_implementation_5F_parser_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken_UINT_33__32_, C_Lexique_goil_5F_lexique::kToken_INT_33__32_, C_Lexique_goil_5F_lexique::kToken_UINT_36__34_, C_Lexique_goil_5F_lexique::kToken_INT_36__34_, C_Lexique_goil_5F_lexique::kToken_FLOAT, C_Lexique_goil_5F_lexique::kToken_ENUM, C_Lexique_goil_5F_lexique::kToken_BOOLEAN, C_Lexique_goil_5F_lexique::kToken_STRING, C_Lexique_goil_5F_lexique::kToken_IDENTIFIER, C_Lexique_goil_5F_lexique::kToken_STRUCT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 209 : <select_implementation_5F_parser_7>
C_Lexique_goil_5F_lexique::kToken_UINT_33__32_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_INT_33__32_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_UINT_36__34_, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_INT_36__34_, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_FLOAT, -1, // Choice 5
C_Lexique_goil_5F_lexique::kToken_ENUM, -1, // Choice 6
C_Lexique_goil_5F_lexique::kToken_BOOLEAN, -1, // Choice 7
C_Lexique_goil_5F_lexique::kToken_STRING, -1, // Choice 8
C_Lexique_goil_5F_lexique::kToken_IDENTIFIER, -1, // Choice 9
C_Lexique_goil_5F_lexique::kToken_STRUCT, -1, // Choice 10
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 11
  -1,
// At index 232 : <select_implementation_5F_parser_8>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 237 : <select_implementation_5F_parser_9>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 245 : <select_implementation_5F_parser_10>
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 252 : <select_implementation_5F_parser_11>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 257 : <select_implementation_5F_parser_12>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 262 : <select_implementation_5F_parser_13>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 2
  -1,
// At index 267 : <select_implementation_5F_parser_14>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 275 : <select_implementation_5F_parser_15>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 281 : <select_implementation_5F_parser_16>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 286 : <select_implementation_5F_parser_17>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 294 : <select_implementation_5F_parser_18>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 301 : <select_implementation_5F_parser_19>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 309 : <select_implementation_5F_parser_20>
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 319 : <select_implementation_5F_parser_21>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 327 : <select_implementation_5F_parser_22>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 334 : <select_implementation_5F_parser_23>
C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 2
  -1,
// At index 340 : <select_implementation_5F_parser_24>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 345 : <select_implementation_5F_parser_25>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 350 : <select_implementation_5F_parser_26>
C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 3
  -1,
// At index 357 : <select_implementation_5F_parser_27>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 363 : <select_implementation_5F_parser_28>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 369 : <select_implementation_5F_parser_29>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 374 : <select_implementation_5F_parser_30>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3D_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 381 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_goil_implementation_level_include [87] = {
0, // at 0 : <implementation_definition>
1, // at 1 : <start>
2, // at 2 : <file>
3, // at 3 : <sign>
4, // at 4 : <description>
5, // at 5 : <OIL_version>
6, // at 6 : <application_definition>
7, // at 7 : <object_definition_list>
8, // at 8 : <boolean>
9, // at 9 : <oil_declaration_list>
10, // at 10 : <oil_declaration>
11, // at 11 : <include_file_level>
12, // at 12 : <include_cpu_level>
13, // at 13 : <include_object_level>
14, // at 14 : <implementation_object_list>
15, // at 15 : <include_implementation_level>
16, // at 16 : <include_type_level>
17, // at 17 : <implementation_objects>
18, // at 18 : <implementation_list>
19, // at 19 : <implementation_type>
20, // at 20 : <struct_options>
21, // at 21 : <objref_option>
22, // at 22 : <string_options>
23, // at 23 : <boolean_options>
24, // at 24 : <enum_item>
25, // at 25 : <enum_options>
26, // at 26 : <number_options>
27, // at 27 : <type_options>
28, // at 28 : <with_auto>
29, // at 29 : <int_or_float>
30, // at 30 : <set_followup>
31, // at 31 : <range_content>
32, // at 32 : <range>
33, // at 33 : <multiple>
34, // at 34 : <identifier_or_attribute>
35, // at 35 : <identifier_or_enum_value>
36, // at 36 : <select_goil_5F_syntax_0>
45, // at 37 : <select_goil_5F_syntax_1>
54, // at 38 : <select_goil_5F_syntax_2>
61, // at 39 : <select_goil_5F_syntax_3>
68, // at 40 : <select_goil_5F_syntax_4>
76, // at 41 : <select_goil_5F_syntax_5>
81, // at 42 : <select_goil_5F_syntax_6>
89, // at 43 : <select_goil_5F_syntax_7>
94, // at 44 : <select_goil_5F_syntax_8>
110, // at 45 : <select_goil_5F_syntax_9>
116, // at 46 : <select_goil_5F_syntax_10>
121, // at 47 : <select_goil_5F_syntax_11>
127, // at 48 : <select_goil_5F_syntax_12>
132, // at 49 : <select_goil_5F_syntax_13>
137, // at 50 : <select_goil_5F_syntax_14>
142, // at 51 : <select_goil_5F_syntax_15>
147, // at 52 : <select_goil_5F_syntax_16>
152, // at 53 : <select_goil_5F_syntax_17>
157, // at 54 : <select_implementation_5F_parser_0>
166, // at 55 : <select_implementation_5F_parser_1>
171, // at 56 : <select_implementation_5F_parser_2>
176, // at 57 : <select_implementation_5F_parser_3>
181, // at 58 : <select_implementation_5F_parser_4>
186, // at 59 : <select_implementation_5F_parser_5>
191, // at 60 : <select_implementation_5F_parser_6>
209, // at 61 : <select_implementation_5F_parser_7>
232, // at 62 : <select_implementation_5F_parser_8>
237, // at 63 : <select_implementation_5F_parser_9>
245, // at 64 : <select_implementation_5F_parser_10>
252, // at 65 : <select_implementation_5F_parser_11>
257, // at 66 : <select_implementation_5F_parser_12>
262, // at 67 : <select_implementation_5F_parser_13>
267, // at 68 : <select_implementation_5F_parser_14>
275, // at 69 : <select_implementation_5F_parser_15>
281, // at 70 : <select_implementation_5F_parser_16>
286, // at 71 : <select_implementation_5F_parser_17>
294, // at 72 : <select_implementation_5F_parser_18>
301, // at 73 : <select_implementation_5F_parser_19>
309, // at 74 : <select_implementation_5F_parser_20>
319, // at 75 : <select_implementation_5F_parser_21>
327, // at 76 : <select_implementation_5F_parser_22>
334, // at 77 : <select_implementation_5F_parser_23>
340, // at 78 : <select_implementation_5F_parser_24>
345, // at 79 : <select_implementation_5F_parser_25>
350, // at 80 : <select_implementation_5F_parser_26>
357, // at 81 : <select_implementation_5F_parser_27>
363, // at 82 : <select_implementation_5F_parser_28>
369, // at 83 : <select_implementation_5F_parser_29>
374, // at 84 : <select_implementation_5F_parser_30>
381, // at 85 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_definition' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_definition_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'start' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_start_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_start_ (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_(inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'file' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_file_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_file_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'sign' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'description' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'OIL_version' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'application_definition' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_application_5F_definition_ (const GALGAS_implementation parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'object_definition_list' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_object_5F_definition_5F_list_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'boolean' non terminal implementation                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'oil_declaration_list' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'oil_declaration' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_file_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_file_5F_level_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_cpu_level' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_cpu_5F_level_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'include_object_level' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_object_list' non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_object_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_object_5F_list_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_(parameter_1, inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performTopDownParsing (gProductions_goil_implementation_level_include, gProductionNames_goil_implementation_level_include, gProductionIndexes_goil_implementation_level_include,
                                    gFirstProductionIndexes_goil_implementation_level_include, gDecision_goil_implementation_level_include, gDecisionIndexes_goil_implementation_level_include, 448) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_implementation &  parameter_1
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
      const bool ok = scanner->performTopDownParsing (gProductions_goil_implementation_level_include, gProductionNames_goil_implementation_level_include, gProductionIndexes_goil_implementation_level_include,
                                                      gFirstProductionIndexes_goil_implementation_level_include, gDecision_goil_implementation_level_include, gDecisionIndexes_goil_implementation_level_include, 448) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_implementation_5F_level_5F_include grammar ;
        grammar.nt_implementation_5F_object_5F_list_ (parameter_1, scanner) ;
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

void cGrammar_goil_5F_implementation_5F_level_5F_include::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                GALGAS_implementation &  parameter_1
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_goil_implementation_level_include, gProductionNames_goil_implementation_level_include, gProductionIndexes_goil_implementation_level_include,
                                                    gFirstProductionIndexes_goil_implementation_level_include, gDecision_goil_implementation_level_include, gDecisionIndexes_goil_implementation_level_include, 448) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_goil_5F_implementation_5F_level_5F_include grammar ;
      grammar.nt_implementation_5F_object_5F_list_ (parameter_1, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'include_implementation_level' non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_implementation_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_implementation_5F_level_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_type_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_type_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'implementation_objects' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_objects_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_objects_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'implementation_list' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_list_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'implementation_type' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_type_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_type_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'struct_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_struct_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_struct_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'objref_option' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_objref_5F_option_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_objref_5F_option_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'string_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_string_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_string_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'boolean_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_boolean_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_boolean_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'enum_item' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_enum_5F_item_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_enum_5F_item_ (GALGAS_enumValues & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'enum_options' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_enum_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_enum_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'number_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_number_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_number_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'type_options' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_type_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_type_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'with_auto' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_with_5F_auto_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_with_5F_auto_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'int_or_float' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_int_5F_or_5F_float_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'set_followup' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_set_5F_followup_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_set_5F_followup_ (GALGAS_numberList & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'range_content' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_range_5F_content_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_range_5F_content_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'range' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_range_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_range_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'multiple' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_multiple_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_multiple_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'identifier_or_attribute' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'identifier_or_enum_value' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_0' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_1' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_2' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_3' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_4' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_5' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_6' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_7' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_8' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_9' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_10' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_11' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_12' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_13' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_14' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_15' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_16' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_17' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_0' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_1' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_2' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_3' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_4' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_5' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_6' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_7' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_8' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_9' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_10' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_11' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_12' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_13' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_14' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_15' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_16' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_17' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_18' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_18 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_19' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_19 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_20' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_20 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_21' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_21 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_22' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_22 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_23' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_23 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_24' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_24 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_25' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_25 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_26' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_26 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_27' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_27 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_28' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_28 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_29' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_29 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_30' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_30 (C_Lexique_goil_5F_lexique * inLexique) {
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

static const int16_t gProductions_goil_type_level_include [] = {
// At index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 36
  TERMINAL (C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION) // $IMPLEMENTATION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (14) // <implementation_object_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 7 : <start>, in file 'goil_syntax.ggs', line 38
, NONTERMINAL (5) // <OIL_version>
, NONTERMINAL (2) // <file>
, END_PRODUCTION
// At index 10 : <file>, in file 'goil_syntax.ggs', line 110
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 12 : <sign>, in file 'goil_syntax.ggs', line 126
, NONTERMINAL (37) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 14 : <description>, in file 'goil_syntax.ggs', line 139
, NONTERMINAL (38) // <select_goil_5F_syntax_2>
, END_PRODUCTION
// At index 16 : <OIL_version>, in file 'goil_syntax.ggs', line 163
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) // $OIL_VERSION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 22 : <application_definition>, in file 'goil_syntax.ggs', line 170
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) // $CPU$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (7) // <object_definition_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 30 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 32 : <boolean>, in file 'goil_syntax.ggs', line 234
, NONTERMINAL (41) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 34 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 36 : <oil_declaration>, in file 'goil_syntax.ggs', line 256
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (43) // <select_goil_5F_syntax_7>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 40 : <include_file_level>, in file 'goil_syntax.ggs', line 463
, NONTERMINAL (48) // <select_goil_5F_syntax_12>
, NONTERMINAL (49) // <select_goil_5F_syntax_13>
, END_PRODUCTION
// At index 43 : <include_cpu_level>, in file 'goil_syntax.ggs', line 487
, NONTERMINAL (50) // <select_goil_5F_syntax_14>
, NONTERMINAL (51) // <select_goil_5F_syntax_15>
, END_PRODUCTION
// At index 46 : <include_object_level>, in file 'goil_syntax.ggs', line 511
, NONTERMINAL (52) // <select_goil_5F_syntax_16>
, NONTERMINAL (53) // <select_goil_5F_syntax_17>
, END_PRODUCTION
// At index 49 : <implementation_object_list>, in file 'implementation_parser.ggs', line 44
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 51 : <include_implementation_level>, in file 'implementation_parser.ggs', line 53
, NONTERMINAL (55) // <select_implementation_5F_parser_1>
, NONTERMINAL (56) // <select_implementation_5F_parser_2>
, END_PRODUCTION
// At index 54 : <include_type_level>, in file 'implementation_parser.ggs', line 74
, NONTERMINAL (57) // <select_implementation_5F_parser_3>
, NONTERMINAL (58) // <select_implementation_5F_parser_4>
, END_PRODUCTION
// At index 57 : <implementation_objects>, in file 'implementation_parser.ggs', line 95
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (59) // <select_implementation_5F_parser_5>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 63 : <implementation_list>, in file 'implementation_parser.ggs', line 132
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 65 : <implementation_type>, in file 'implementation_parser.ggs', line 210
, NONTERMINAL (61) // <select_implementation_5F_parser_7>
, END_PRODUCTION
// At index 67 : <struct_options>, in file 'implementation_parser.ggs', line 238
, NONTERMINAL (62) // <select_implementation_5F_parser_8>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 72 : <objref_option>, in file 'implementation_parser.ggs', line 255
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 76 : <string_options>, in file 'implementation_parser.ggs', line 273
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (63) // <select_implementation_5F_parser_9>
, END_PRODUCTION
// At index 81 : <boolean_options>, in file 'implementation_parser.ggs', line 310
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (65) // <select_implementation_5F_parser_11>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (68) // <select_implementation_5F_parser_14>
, END_PRODUCTION
// At index 87 : <enum_item>, in file 'implementation_parser.ggs', line 355
, NONTERMINAL (35) // <identifier_or_enum_value>
, NONTERMINAL (69) // <select_implementation_5F_parser_15>
, END_PRODUCTION
// At index 90 : <enum_options>, in file 'implementation_parser.ggs', line 368
, NONTERMINAL (28) // <with_auto>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (71) // <select_implementation_5F_parser_17>
, END_PRODUCTION
// At index 99 : <number_options>, in file 'implementation_parser.ggs', line 415
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (32) // <range>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (73) // <select_implementation_5F_parser_19>
, END_PRODUCTION
// At index 105 : <type_options>, in file 'implementation_parser.ggs', line 454
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (75) // <select_implementation_5F_parser_21>
, END_PRODUCTION
// At index 110 : <with_auto>, in file 'implementation_parser.ggs', line 493
, NONTERMINAL (77) // <select_implementation_5F_parser_23>
, END_PRODUCTION
// At index 112 : <int_or_float>, in file 'implementation_parser.ggs', line 502
, NONTERMINAL (3) // <sign>
, NONTERMINAL (78) // <select_implementation_5F_parser_24>
, END_PRODUCTION
// At index 115 : <set_followup>, in file 'implementation_parser.ggs', line 520
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 117 : <range_content>, in file 'implementation_parser.ggs', line 532
, NONTERMINAL (3) // <sign>
, NONTERMINAL (80) // <select_implementation_5F_parser_26>
, END_PRODUCTION
// At index 120 : <range>, in file 'implementation_parser.ggs', line 572
, NONTERMINAL (83) // <select_implementation_5F_parser_29>
, END_PRODUCTION
// At index 122 : <multiple>, in file 'implementation_parser.ggs', line 582
, NONTERMINAL (84) // <select_implementation_5F_parser_30>
, END_PRODUCTION
// At index 124 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 592
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
// At index 126 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 597
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 128 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, END_PRODUCTION
// At index 129 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (11) // <include_file_level>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 132 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 135 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (6) // <application_definition>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 138 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) // $-$
, END_PRODUCTION
// At index 140 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) // $+$
, END_PRODUCTION
// At index 142 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, END_PRODUCTION
// At index 143 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, END_PRODUCTION
// At index 144 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) // $:$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (39) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 148 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, END_PRODUCTION
// At index 149 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (39) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 152 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, END_PRODUCTION
// At index 153 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 162 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, NONTERMINAL (12) // <include_cpu_level>
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 165 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 167 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 169 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
, END_PRODUCTION
// At index 170 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
, NONTERMINAL (10) // <oil_declaration>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 173 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
, NONTERMINAL (13) // <include_object_level>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 176 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (44) // <select_goil_5F_syntax_8>
, END_PRODUCTION
// At index 179 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 185 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (45) // <select_goil_5F_syntax_9>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 189 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, NONTERMINAL (3) // <sign>
, NONTERMINAL (46) // <select_goil_5F_syntax_10>
, END_PRODUCTION
// At index 192 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (47) // <select_goil_5F_syntax_11>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 196 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 199 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 202 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 206 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
, END_PRODUCTION
// At index 207 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 210 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 213 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 356
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 217 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 356
, END_PRODUCTION
// At index 218 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 470
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 220 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 470
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 222 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 476
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 224 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 476
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 226 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 494
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 228 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 494
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 230 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 500
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 232 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 500
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 234 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 516
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 236 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 516
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 238 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 522
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 240 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 522
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 242 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
, END_PRODUCTION
// At index 243 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
, NONTERMINAL (17) // <implementation_objects>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 247 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
, NONTERMINAL (15) // <include_implementation_level>
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 250 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 57
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 252 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 57
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 254 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 63
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 256 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 63
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 258 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 78
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 260 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 78
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 262 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 84
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 264 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 84
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 266 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 102
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 269 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 102
, END_PRODUCTION
// At index 270 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
, END_PRODUCTION
// At index 271 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
, NONTERMINAL (19) // <implementation_type>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 275 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
, NONTERMINAL (16) // <include_type_level>
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 278 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_) // $UINT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 281 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_33__32_) // $INT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 284 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_) // $UINT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 287 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_36__34_) // $INT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 290 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FLOAT) // $FLOAT$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 293 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_ENUM) // $ENUM$
, NONTERMINAL (25) // <enum_options>
, END_PRODUCTION
// At index 296 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_BOOLEAN) // $BOOLEAN$
, NONTERMINAL (23) // <boolean_options>
, END_PRODUCTION
// At index 299 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRING) // $STRING$
, NONTERMINAL (22) // <string_options>
, END_PRODUCTION
// At index 302 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER) // $IDENTIFIER$
, NONTERMINAL (27) // <type_options>
, END_PRODUCTION
// At index 305 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRUCT) // $STRUCT$
, NONTERMINAL (20) // <struct_options>
, END_PRODUCTION
// At index 308 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (21) // <objref_option>
, END_PRODUCTION
// At index 311 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 242
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 315 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 242
, END_PRODUCTION
// At index 316 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 283
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (64) // <select_implementation_5F_parser_10>
, END_PRODUCTION
// At index 319 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 283
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 321 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 324 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 327 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 330 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 317
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, NONTERMINAL (66) // <select_implementation_5F_parser_12>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, NONTERMINAL (67) // <select_implementation_5F_parser_13>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 338 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 317
, END_PRODUCTION
// At index 339 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 320
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 343 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 320
, END_PRODUCTION
// At index 344 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 329
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 348 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 329
, END_PRODUCTION
// At index 349 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 343
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 353 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 343
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 355 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 360
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 359 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 360
, END_PRODUCTION
// At index 360 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 376
, END_PRODUCTION
// At index 361 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 376
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, END_PRODUCTION
// At index 365 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 386
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (72) // <select_implementation_5F_parser_18>
, END_PRODUCTION
// At index 368 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 386
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 370 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 373 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 376 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 379 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 428
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (74) // <select_implementation_5F_parser_20>
, END_PRODUCTION
// At index 382 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 428
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 384 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 386 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 389 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 392 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 465
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (76) // <select_implementation_5F_parser_22>
, END_PRODUCTION
// At index 395 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 465
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 397 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 400 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 403 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 406 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 495
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO) // $WITH_AUTO$
, END_PRODUCTION
// At index 408 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 495
, END_PRODUCTION
// At index 409 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 507
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 412 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 507
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 415 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 523
, END_PRODUCTION
// At index 416 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 523
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (29) // <int_or_float>
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 420 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number) // $set_start_uint_number$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 423 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (81) // <select_implementation_5F_parser_27>
, END_PRODUCTION
// At index 426 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (82) // <select_implementation_5F_parser_28>
, END_PRODUCTION
// At index 429 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 549
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 432 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 549
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 434 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 561
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 437 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 561
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 439 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 575
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (31) // <range_content>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 443 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 575
, END_PRODUCTION
// At index 444 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 584
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 447 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 584
, END_PRODUCTION
// At index 448 : <>, in file '.ggs', line 0
, NONTERMINAL (18) // <implementation_list>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_goil_type_level_include [159] = {
 {"<implementation_definition>", "implementation_parser", 0}, // at index 0
 {"<start>", "goil_syntax", 7}, // at index 1
 {"<file>", "goil_syntax", 10}, // at index 2
 {"<sign>", "goil_syntax", 12}, // at index 3
 {"<description>", "goil_syntax", 14}, // at index 4
 {"<OIL_version>", "goil_syntax", 16}, // at index 5
 {"<application_definition>", "goil_syntax", 22}, // at index 6
 {"<object_definition_list>", "goil_syntax", 30}, // at index 7
 {"<boolean>", "goil_syntax", 32}, // at index 8
 {"<oil_declaration_list>", "goil_syntax", 34}, // at index 9
 {"<oil_declaration>", "goil_syntax", 36}, // at index 10
 {"<include_file_level>", "goil_syntax", 40}, // at index 11
 {"<include_cpu_level>", "goil_syntax", 43}, // at index 12
 {"<include_object_level>", "goil_syntax", 46}, // at index 13
 {"<implementation_object_list>", "implementation_parser", 49}, // at index 14
 {"<include_implementation_level>", "implementation_parser", 51}, // at index 15
 {"<include_type_level>", "implementation_parser", 54}, // at index 16
 {"<implementation_objects>", "implementation_parser", 57}, // at index 17
 {"<implementation_list>", "implementation_parser", 63}, // at index 18
 {"<implementation_type>", "implementation_parser", 65}, // at index 19
 {"<struct_options>", "implementation_parser", 67}, // at index 20
 {"<objref_option>", "implementation_parser", 72}, // at index 21
 {"<string_options>", "implementation_parser", 76}, // at index 22
 {"<boolean_options>", "implementation_parser", 81}, // at index 23
 {"<enum_item>", "implementation_parser", 87}, // at index 24
 {"<enum_options>", "implementation_parser", 90}, // at index 25
 {"<number_options>", "implementation_parser", 99}, // at index 26
 {"<type_options>", "implementation_parser", 105}, // at index 27
 {"<with_auto>", "implementation_parser", 110}, // at index 28
 {"<int_or_float>", "implementation_parser", 112}, // at index 29
 {"<set_followup>", "implementation_parser", 115}, // at index 30
 {"<range_content>", "implementation_parser", 117}, // at index 31
 {"<range>", "implementation_parser", 120}, // at index 32
 {"<multiple>", "implementation_parser", 122}, // at index 33
 {"<identifier_or_attribute>", "implementation_parser", 124}, // at index 34
 {"<identifier_or_enum_value>", "implementation_parser", 126}, // at index 35
 {"<select_goil_5F_syntax_0>", "goil_syntax", 128}, // at index 36
 {"<select_goil_5F_syntax_0>", "goil_syntax", 129}, // at index 37
 {"<select_goil_5F_syntax_0>", "goil_syntax", 132}, // at index 38
 {"<select_goil_5F_syntax_0>", "goil_syntax", 135}, // at index 39
 {"<select_goil_5F_syntax_1>", "goil_syntax", 138}, // at index 40
 {"<select_goil_5F_syntax_1>", "goil_syntax", 140}, // at index 41
 {"<select_goil_5F_syntax_1>", "goil_syntax", 142}, // at index 42
 {"<select_goil_5F_syntax_2>", "goil_syntax", 143}, // at index 43
 {"<select_goil_5F_syntax_2>", "goil_syntax", 144}, // at index 44
 {"<select_goil_5F_syntax_3>", "goil_syntax", 148}, // at index 45
 {"<select_goil_5F_syntax_3>", "goil_syntax", 149}, // at index 46
 {"<select_goil_5F_syntax_4>", "goil_syntax", 152}, // at index 47
 {"<select_goil_5F_syntax_4>", "goil_syntax", 153}, // at index 48
 {"<select_goil_5F_syntax_4>", "goil_syntax", 162}, // at index 49
 {"<select_goil_5F_syntax_5>", "goil_syntax", 165}, // at index 50
 {"<select_goil_5F_syntax_5>", "goil_syntax", 167}, // at index 51
 {"<select_goil_5F_syntax_6>", "goil_syntax", 169}, // at index 52
 {"<select_goil_5F_syntax_6>", "goil_syntax", 170}, // at index 53
 {"<select_goil_5F_syntax_6>", "goil_syntax", 173}, // at index 54
 {"<select_goil_5F_syntax_7>", "goil_syntax", 176}, // at index 55
 {"<select_goil_5F_syntax_7>", "goil_syntax", 179}, // at index 56
 {"<select_goil_5F_syntax_8>", "goil_syntax", 185}, // at index 57
 {"<select_goil_5F_syntax_8>", "goil_syntax", 189}, // at index 58
 {"<select_goil_5F_syntax_8>", "goil_syntax", 192}, // at index 59
 {"<select_goil_5F_syntax_8>", "goil_syntax", 196}, // at index 60
 {"<select_goil_5F_syntax_8>", "goil_syntax", 199}, // at index 61
 {"<select_goil_5F_syntax_9>", "goil_syntax", 202}, // at index 62
 {"<select_goil_5F_syntax_9>", "goil_syntax", 206}, // at index 63
 {"<select_goil_5F_syntax_10>", "goil_syntax", 207}, // at index 64
 {"<select_goil_5F_syntax_10>", "goil_syntax", 210}, // at index 65
 {"<select_goil_5F_syntax_11>", "goil_syntax", 213}, // at index 66
 {"<select_goil_5F_syntax_11>", "goil_syntax", 217}, // at index 67
 {"<select_goil_5F_syntax_12>", "goil_syntax", 218}, // at index 68
 {"<select_goil_5F_syntax_12>", "goil_syntax", 220}, // at index 69
 {"<select_goil_5F_syntax_13>", "goil_syntax", 222}, // at index 70
 {"<select_goil_5F_syntax_13>", "goil_syntax", 224}, // at index 71
 {"<select_goil_5F_syntax_14>", "goil_syntax", 226}, // at index 72
 {"<select_goil_5F_syntax_14>", "goil_syntax", 228}, // at index 73
 {"<select_goil_5F_syntax_15>", "goil_syntax", 230}, // at index 74
 {"<select_goil_5F_syntax_15>", "goil_syntax", 232}, // at index 75
 {"<select_goil_5F_syntax_16>", "goil_syntax", 234}, // at index 76
 {"<select_goil_5F_syntax_16>", "goil_syntax", 236}, // at index 77
 {"<select_goil_5F_syntax_17>", "goil_syntax", 238}, // at index 78
 {"<select_goil_5F_syntax_17>", "goil_syntax", 240}, // at index 79
 {"<select_implementation_5F_parser_0>", "implementation_parser", 242}, // at index 80
 {"<select_implementation_5F_parser_0>", "implementation_parser", 243}, // at index 81
 {"<select_implementation_5F_parser_0>", "implementation_parser", 247}, // at index 82
 {"<select_implementation_5F_parser_1>", "implementation_parser", 250}, // at index 83
 {"<select_implementation_5F_parser_1>", "implementation_parser", 252}, // at index 84
 {"<select_implementation_5F_parser_2>", "implementation_parser", 254}, // at index 85
 {"<select_implementation_5F_parser_2>", "implementation_parser", 256}, // at index 86
 {"<select_implementation_5F_parser_3>", "implementation_parser", 258}, // at index 87
 {"<select_implementation_5F_parser_3>", "implementation_parser", 260}, // at index 88
 {"<select_implementation_5F_parser_4>", "implementation_parser", 262}, // at index 89
 {"<select_implementation_5F_parser_4>", "implementation_parser", 264}, // at index 90
 {"<select_implementation_5F_parser_5>", "implementation_parser", 266}, // at index 91
 {"<select_implementation_5F_parser_5>", "implementation_parser", 269}, // at index 92
 {"<select_implementation_5F_parser_6>", "implementation_parser", 270}, // at index 93
 {"<select_implementation_5F_parser_6>", "implementation_parser", 271}, // at index 94
 {"<select_implementation_5F_parser_6>", "implementation_parser", 275}, // at index 95
 {"<select_implementation_5F_parser_7>", "implementation_parser", 278}, // at index 96
 {"<select_implementation_5F_parser_7>", "implementation_parser", 281}, // at index 97
 {"<select_implementation_5F_parser_7>", "implementation_parser", 284}, // at index 98
 {"<select_implementation_5F_parser_7>", "implementation_parser", 287}, // at index 99
 {"<select_implementation_5F_parser_7>", "implementation_parser", 290}, // at index 100
 {"<select_implementation_5F_parser_7>", "implementation_parser", 293}, // at index 101
 {"<select_implementation_5F_parser_7>", "implementation_parser", 296}, // at index 102
 {"<select_implementation_5F_parser_7>", "implementation_parser", 299}, // at index 103
 {"<select_implementation_5F_parser_7>", "implementation_parser", 302}, // at index 104
 {"<select_implementation_5F_parser_7>", "implementation_parser", 305}, // at index 105
 {"<select_implementation_5F_parser_7>", "implementation_parser", 308}, // at index 106
 {"<select_implementation_5F_parser_8>", "implementation_parser", 311}, // at index 107
 {"<select_implementation_5F_parser_8>", "implementation_parser", 315}, // at index 108
 {"<select_implementation_5F_parser_9>", "implementation_parser", 316}, // at index 109
 {"<select_implementation_5F_parser_9>", "implementation_parser", 319}, // at index 110
 {"<select_implementation_5F_parser_10>", "implementation_parser", 321}, // at index 111
 {"<select_implementation_5F_parser_10>", "implementation_parser", 324}, // at index 112
 {"<select_implementation_5F_parser_10>", "implementation_parser", 327}, // at index 113
 {"<select_implementation_5F_parser_11>", "implementation_parser", 330}, // at index 114
 {"<select_implementation_5F_parser_11>", "implementation_parser", 338}, // at index 115
 {"<select_implementation_5F_parser_12>", "implementation_parser", 339}, // at index 116
 {"<select_implementation_5F_parser_12>", "implementation_parser", 343}, // at index 117
 {"<select_implementation_5F_parser_13>", "implementation_parser", 344}, // at index 118
 {"<select_implementation_5F_parser_13>", "implementation_parser", 348}, // at index 119
 {"<select_implementation_5F_parser_14>", "implementation_parser", 349}, // at index 120
 {"<select_implementation_5F_parser_14>", "implementation_parser", 353}, // at index 121
 {"<select_implementation_5F_parser_15>", "implementation_parser", 355}, // at index 122
 {"<select_implementation_5F_parser_15>", "implementation_parser", 359}, // at index 123
 {"<select_implementation_5F_parser_16>", "implementation_parser", 360}, // at index 124
 {"<select_implementation_5F_parser_16>", "implementation_parser", 361}, // at index 125
 {"<select_implementation_5F_parser_17>", "implementation_parser", 365}, // at index 126
 {"<select_implementation_5F_parser_17>", "implementation_parser", 368}, // at index 127
 {"<select_implementation_5F_parser_18>", "implementation_parser", 370}, // at index 128
 {"<select_implementation_5F_parser_18>", "implementation_parser", 373}, // at index 129
 {"<select_implementation_5F_parser_18>", "implementation_parser", 376}, // at index 130
 {"<select_implementation_5F_parser_19>", "implementation_parser", 379}, // at index 131
 {"<select_implementation_5F_parser_19>", "implementation_parser", 382}, // at index 132
 {"<select_implementation_5F_parser_20>", "implementation_parser", 384}, // at index 133
 {"<select_implementation_5F_parser_20>", "implementation_parser", 386}, // at index 134
 {"<select_implementation_5F_parser_20>", "implementation_parser", 389}, // at index 135
 {"<select_implementation_5F_parser_21>", "implementation_parser", 392}, // at index 136
 {"<select_implementation_5F_parser_21>", "implementation_parser", 395}, // at index 137
 {"<select_implementation_5F_parser_22>", "implementation_parser", 397}, // at index 138
 {"<select_implementation_5F_parser_22>", "implementation_parser", 400}, // at index 139
 {"<select_implementation_5F_parser_22>", "implementation_parser", 403}, // at index 140
 {"<select_implementation_5F_parser_23>", "implementation_parser", 406}, // at index 141
 {"<select_implementation_5F_parser_23>", "implementation_parser", 408}, // at index 142
 {"<select_implementation_5F_parser_24>", "implementation_parser", 409}, // at index 143
 {"<select_implementation_5F_parser_24>", "implementation_parser", 412}, // at index 144
 {"<select_implementation_5F_parser_25>", "implementation_parser", 415}, // at index 145
 {"<select_implementation_5F_parser_25>", "implementation_parser", 416}, // at index 146
 {"<select_implementation_5F_parser_26>", "implementation_parser", 420}, // at index 147
 {"<select_implementation_5F_parser_26>", "implementation_parser", 423}, // at index 148
 {"<select_implementation_5F_parser_26>", "implementation_parser", 426}, // at index 149
 {"<select_implementation_5F_parser_27>", "implementation_parser", 429}, // at index 150
 {"<select_implementation_5F_parser_27>", "implementation_parser", 432}, // at index 151
 {"<select_implementation_5F_parser_28>", "implementation_parser", 434}, // at index 152
 {"<select_implementation_5F_parser_28>", "implementation_parser", 437}, // at index 153
 {"<select_implementation_5F_parser_29>", "implementation_parser", 439}, // at index 154
 {"<select_implementation_5F_parser_29>", "implementation_parser", 443}, // at index 155
 {"<select_implementation_5F_parser_30>", "implementation_parser", 444}, // at index 156
 {"<select_implementation_5F_parser_30>", "implementation_parser", 447}, // at index 157
 {"<>", "", 448} // at index 158
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_goil_type_level_include [159] = {
0, // index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 36
7, // index 1 : <start>, in file 'goil_syntax.ggs', line 38
10, // index 2 : <file>, in file 'goil_syntax.ggs', line 110
12, // index 3 : <sign>, in file 'goil_syntax.ggs', line 126
14, // index 4 : <description>, in file 'goil_syntax.ggs', line 139
16, // index 5 : <OIL_version>, in file 'goil_syntax.ggs', line 163
22, // index 6 : <application_definition>, in file 'goil_syntax.ggs', line 170
30, // index 7 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
32, // index 8 : <boolean>, in file 'goil_syntax.ggs', line 234
34, // index 9 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 244
36, // index 10 : <oil_declaration>, in file 'goil_syntax.ggs', line 256
40, // index 11 : <include_file_level>, in file 'goil_syntax.ggs', line 463
43, // index 12 : <include_cpu_level>, in file 'goil_syntax.ggs', line 487
46, // index 13 : <include_object_level>, in file 'goil_syntax.ggs', line 511
49, // index 14 : <implementation_object_list>, in file 'implementation_parser.ggs', line 44
51, // index 15 : <include_implementation_level>, in file 'implementation_parser.ggs', line 53
54, // index 16 : <include_type_level>, in file 'implementation_parser.ggs', line 74
57, // index 17 : <implementation_objects>, in file 'implementation_parser.ggs', line 95
63, // index 18 : <implementation_list>, in file 'implementation_parser.ggs', line 132
65, // index 19 : <implementation_type>, in file 'implementation_parser.ggs', line 210
67, // index 20 : <struct_options>, in file 'implementation_parser.ggs', line 238
72, // index 21 : <objref_option>, in file 'implementation_parser.ggs', line 255
76, // index 22 : <string_options>, in file 'implementation_parser.ggs', line 273
81, // index 23 : <boolean_options>, in file 'implementation_parser.ggs', line 310
87, // index 24 : <enum_item>, in file 'implementation_parser.ggs', line 355
90, // index 25 : <enum_options>, in file 'implementation_parser.ggs', line 368
99, // index 26 : <number_options>, in file 'implementation_parser.ggs', line 415
105, // index 27 : <type_options>, in file 'implementation_parser.ggs', line 454
110, // index 28 : <with_auto>, in file 'implementation_parser.ggs', line 493
112, // index 29 : <int_or_float>, in file 'implementation_parser.ggs', line 502
115, // index 30 : <set_followup>, in file 'implementation_parser.ggs', line 520
117, // index 31 : <range_content>, in file 'implementation_parser.ggs', line 532
120, // index 32 : <range>, in file 'implementation_parser.ggs', line 572
122, // index 33 : <multiple>, in file 'implementation_parser.ggs', line 582
124, // index 34 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 592
126, // index 35 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 597
128, // index 36 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
129, // index 37 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
132, // index 38 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
135, // index 39 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
138, // index 40 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
140, // index 41 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
142, // index 42 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
143, // index 43 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
144, // index 44 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
148, // index 45 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
149, // index 46 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
152, // index 47 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
153, // index 48 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
162, // index 49 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
165, // index 50 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
167, // index 51 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
169, // index 52 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
170, // index 53 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
173, // index 54 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
176, // index 55 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
179, // index 56 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
185, // index 57 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
189, // index 58 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
192, // index 59 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
196, // index 60 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
199, // index 61 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
202, // index 62 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
206, // index 63 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
207, // index 64 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
210, // index 65 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
213, // index 66 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 356
217, // index 67 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 356
218, // index 68 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 470
220, // index 69 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 470
222, // index 70 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 476
224, // index 71 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 476
226, // index 72 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 494
228, // index 73 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 494
230, // index 74 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 500
232, // index 75 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 500
234, // index 76 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 516
236, // index 77 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 516
238, // index 78 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 522
240, // index 79 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 522
242, // index 80 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
243, // index 81 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
247, // index 82 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
250, // index 83 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 57
252, // index 84 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 57
254, // index 85 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 63
256, // index 86 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 63
258, // index 87 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 78
260, // index 88 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 78
262, // index 89 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 84
264, // index 90 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 84
266, // index 91 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 102
269, // index 92 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 102
270, // index 93 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
271, // index 94 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
275, // index 95 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
278, // index 96 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
281, // index 97 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
284, // index 98 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
287, // index 99 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
290, // index 100 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
293, // index 101 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
296, // index 102 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
299, // index 103 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
302, // index 104 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
305, // index 105 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
308, // index 106 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
311, // index 107 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 242
315, // index 108 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 242
316, // index 109 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 283
319, // index 110 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 283
321, // index 111 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
324, // index 112 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
327, // index 113 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
330, // index 114 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 317
338, // index 115 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 317
339, // index 116 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 320
343, // index 117 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 320
344, // index 118 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 329
348, // index 119 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 329
349, // index 120 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 343
353, // index 121 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 343
355, // index 122 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 360
359, // index 123 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 360
360, // index 124 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 376
361, // index 125 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 376
365, // index 126 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 386
368, // index 127 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 386
370, // index 128 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
373, // index 129 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
376, // index 130 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
379, // index 131 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 428
382, // index 132 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 428
384, // index 133 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
386, // index 134 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
389, // index 135 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
392, // index 136 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 465
395, // index 137 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 465
397, // index 138 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
400, // index 139 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
403, // index 140 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
406, // index 141 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 495
408, // index 142 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 495
409, // index 143 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 507
412, // index 144 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 507
415, // index 145 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 523
416, // index 146 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 523
420, // index 147 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
423, // index 148 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
426, // index 149 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
429, // index 150 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 549
432, // index 151 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 549
434, // index 152 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 561
437, // index 153 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 561
439, // index 154 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 575
443, // index 155 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 575
444, // index 156 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 584
447, // index 157 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 584
448 // index 158 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_goil_type_level_include [87] = {
0, // at 0 : <implementation_definition>
1, // at 1 : <start>
2, // at 2 : <file>
3, // at 3 : <sign>
4, // at 4 : <description>
5, // at 5 : <OIL_version>
6, // at 6 : <application_definition>
7, // at 7 : <object_definition_list>
8, // at 8 : <boolean>
9, // at 9 : <oil_declaration_list>
10, // at 10 : <oil_declaration>
11, // at 11 : <include_file_level>
12, // at 12 : <include_cpu_level>
13, // at 13 : <include_object_level>
14, // at 14 : <implementation_object_list>
15, // at 15 : <include_implementation_level>
16, // at 16 : <include_type_level>
17, // at 17 : <implementation_objects>
18, // at 18 : <implementation_list>
19, // at 19 : <implementation_type>
20, // at 20 : <struct_options>
21, // at 21 : <objref_option>
22, // at 22 : <string_options>
23, // at 23 : <boolean_options>
24, // at 24 : <enum_item>
25, // at 25 : <enum_options>
26, // at 26 : <number_options>
27, // at 27 : <type_options>
28, // at 28 : <with_auto>
29, // at 29 : <int_or_float>
30, // at 30 : <set_followup>
31, // at 31 : <range_content>
32, // at 32 : <range>
33, // at 33 : <multiple>
34, // at 34 : <identifier_or_attribute>
35, // at 35 : <identifier_or_enum_value>
36, // at 36 : <select_goil_5F_syntax_0>
40, // at 37 : <select_goil_5F_syntax_1>
43, // at 38 : <select_goil_5F_syntax_2>
45, // at 39 : <select_goil_5F_syntax_3>
47, // at 40 : <select_goil_5F_syntax_4>
50, // at 41 : <select_goil_5F_syntax_5>
52, // at 42 : <select_goil_5F_syntax_6>
55, // at 43 : <select_goil_5F_syntax_7>
57, // at 44 : <select_goil_5F_syntax_8>
62, // at 45 : <select_goil_5F_syntax_9>
64, // at 46 : <select_goil_5F_syntax_10>
66, // at 47 : <select_goil_5F_syntax_11>
68, // at 48 : <select_goil_5F_syntax_12>
70, // at 49 : <select_goil_5F_syntax_13>
72, // at 50 : <select_goil_5F_syntax_14>
74, // at 51 : <select_goil_5F_syntax_15>
76, // at 52 : <select_goil_5F_syntax_16>
78, // at 53 : <select_goil_5F_syntax_17>
80, // at 54 : <select_implementation_5F_parser_0>
83, // at 55 : <select_implementation_5F_parser_1>
85, // at 56 : <select_implementation_5F_parser_2>
87, // at 57 : <select_implementation_5F_parser_3>
89, // at 58 : <select_implementation_5F_parser_4>
91, // at 59 : <select_implementation_5F_parser_5>
93, // at 60 : <select_implementation_5F_parser_6>
96, // at 61 : <select_implementation_5F_parser_7>
107, // at 62 : <select_implementation_5F_parser_8>
109, // at 63 : <select_implementation_5F_parser_9>
111, // at 64 : <select_implementation_5F_parser_10>
114, // at 65 : <select_implementation_5F_parser_11>
116, // at 66 : <select_implementation_5F_parser_12>
118, // at 67 : <select_implementation_5F_parser_13>
120, // at 68 : <select_implementation_5F_parser_14>
122, // at 69 : <select_implementation_5F_parser_15>
124, // at 70 : <select_implementation_5F_parser_16>
126, // at 71 : <select_implementation_5F_parser_17>
128, // at 72 : <select_implementation_5F_parser_18>
131, // at 73 : <select_implementation_5F_parser_19>
133, // at 74 : <select_implementation_5F_parser_20>
136, // at 75 : <select_implementation_5F_parser_21>
138, // at 76 : <select_implementation_5F_parser_22>
141, // at 77 : <select_implementation_5F_parser_23>
143, // at 78 : <select_implementation_5F_parser_24>
145, // at 79 : <select_implementation_5F_parser_25>
147, // at 80 : <select_implementation_5F_parser_26>
150, // at 81 : <select_implementation_5F_parser_27>
152, // at 82 : <select_implementation_5F_parser_28>
154, // at 83 : <select_implementation_5F_parser_29>
156, // at 84 : <select_implementation_5F_parser_30>
158, // at 85 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_goil_type_level_include [] = {
// At index 0 : <implementation_definition> only one production, no choice
  -1,
// At index 1 : <start> only one production, no choice
  -1,
// At index 2 : <file> only one production, no choice
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
// At index 14 : <implementation_object_list> only one production, no choice
  -1,
// At index 15 : <include_implementation_level> only one production, no choice
  -1,
// At index 16 : <include_type_level> only one production, no choice
  -1,
// At index 17 : <implementation_objects> only one production, no choice
  -1,
// At index 18 : <implementation_list> only one production, no choice
  -1,
// At index 19 : <implementation_type> only one production, no choice
  -1,
// At index 20 : <struct_options> only one production, no choice
  -1,
// At index 21 : <objref_option> only one production, no choice
  -1,
// At index 22 : <string_options> only one production, no choice
  -1,
// At index 23 : <boolean_options> only one production, no choice
  -1,
// At index 24 : <enum_item> only one production, no choice
  -1,
// At index 25 : <enum_options> only one production, no choice
  -1,
// At index 26 : <number_options> only one production, no choice
  -1,
// At index 27 : <type_options> only one production, no choice
  -1,
// At index 28 : <with_auto> only one production, no choice
  -1,
// At index 29 : <int_or_float> only one production, no choice
  -1,
// At index 30 : <set_followup> only one production, no choice
  -1,
// At index 31 : <range_content> only one production, no choice
  -1,
// At index 32 : <range> only one production, no choice
  -1,
// At index 33 : <multiple> only one production, no choice
  -1,
// At index 34 : <identifier_or_attribute> only one production, no choice
  -1,
// At index 35 : <identifier_or_enum_value> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 36 : <select_goil_5F_syntax_0>
-1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 45 : <select_goil_5F_syntax_1>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 3
  -1,
// At index 54 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 61 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 68 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 76 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 81 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 89 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 94 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 110 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 116 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 121 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 127 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 132 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 137 : <select_goil_5F_syntax_14>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 142 : <select_goil_5F_syntax_15>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 147 : <select_goil_5F_syntax_16>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 152 : <select_goil_5F_syntax_17>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 157 : <select_implementation_5F_parser_0>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 165 : <select_implementation_5F_parser_1>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 170 : <select_implementation_5F_parser_2>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 175 : <select_implementation_5F_parser_3>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 180 : <select_implementation_5F_parser_4>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 185 : <select_implementation_5F_parser_5>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 2
  -1,
// At index 190 : <select_implementation_5F_parser_6>
C_Lexique_goil_5F_lexique::kToken__7D_, C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken_UINT_33__32_, C_Lexique_goil_5F_lexique::kToken_INT_33__32_, C_Lexique_goil_5F_lexique::kToken_UINT_36__34_, C_Lexique_goil_5F_lexique::kToken_INT_36__34_, C_Lexique_goil_5F_lexique::kToken_FLOAT, C_Lexique_goil_5F_lexique::kToken_ENUM, C_Lexique_goil_5F_lexique::kToken_BOOLEAN, C_Lexique_goil_5F_lexique::kToken_STRING, C_Lexique_goil_5F_lexique::kToken_IDENTIFIER, C_Lexique_goil_5F_lexique::kToken_STRUCT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 209 : <select_implementation_5F_parser_7>
C_Lexique_goil_5F_lexique::kToken_UINT_33__32_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_INT_33__32_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_UINT_36__34_, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_INT_36__34_, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_FLOAT, -1, // Choice 5
C_Lexique_goil_5F_lexique::kToken_ENUM, -1, // Choice 6
C_Lexique_goil_5F_lexique::kToken_BOOLEAN, -1, // Choice 7
C_Lexique_goil_5F_lexique::kToken_STRING, -1, // Choice 8
C_Lexique_goil_5F_lexique::kToken_IDENTIFIER, -1, // Choice 9
C_Lexique_goil_5F_lexique::kToken_STRUCT, -1, // Choice 10
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 11
  -1,
// At index 232 : <select_implementation_5F_parser_8>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 237 : <select_implementation_5F_parser_9>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 245 : <select_implementation_5F_parser_10>
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 252 : <select_implementation_5F_parser_11>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 257 : <select_implementation_5F_parser_12>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 262 : <select_implementation_5F_parser_13>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 2
  -1,
// At index 267 : <select_implementation_5F_parser_14>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 275 : <select_implementation_5F_parser_15>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 281 : <select_implementation_5F_parser_16>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 286 : <select_implementation_5F_parser_17>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 294 : <select_implementation_5F_parser_18>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 301 : <select_implementation_5F_parser_19>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 309 : <select_implementation_5F_parser_20>
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 319 : <select_implementation_5F_parser_21>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 327 : <select_implementation_5F_parser_22>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 334 : <select_implementation_5F_parser_23>
C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 2
  -1,
// At index 340 : <select_implementation_5F_parser_24>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 345 : <select_implementation_5F_parser_25>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 350 : <select_implementation_5F_parser_26>
C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 3
  -1,
// At index 357 : <select_implementation_5F_parser_27>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 363 : <select_implementation_5F_parser_28>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 369 : <select_implementation_5F_parser_29>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 374 : <select_implementation_5F_parser_30>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3D_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 381 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_goil_type_level_include [87] = {
0, // at 0 : <implementation_definition>
1, // at 1 : <start>
2, // at 2 : <file>
3, // at 3 : <sign>
4, // at 4 : <description>
5, // at 5 : <OIL_version>
6, // at 6 : <application_definition>
7, // at 7 : <object_definition_list>
8, // at 8 : <boolean>
9, // at 9 : <oil_declaration_list>
10, // at 10 : <oil_declaration>
11, // at 11 : <include_file_level>
12, // at 12 : <include_cpu_level>
13, // at 13 : <include_object_level>
14, // at 14 : <implementation_object_list>
15, // at 15 : <include_implementation_level>
16, // at 16 : <include_type_level>
17, // at 17 : <implementation_objects>
18, // at 18 : <implementation_list>
19, // at 19 : <implementation_type>
20, // at 20 : <struct_options>
21, // at 21 : <objref_option>
22, // at 22 : <string_options>
23, // at 23 : <boolean_options>
24, // at 24 : <enum_item>
25, // at 25 : <enum_options>
26, // at 26 : <number_options>
27, // at 27 : <type_options>
28, // at 28 : <with_auto>
29, // at 29 : <int_or_float>
30, // at 30 : <set_followup>
31, // at 31 : <range_content>
32, // at 32 : <range>
33, // at 33 : <multiple>
34, // at 34 : <identifier_or_attribute>
35, // at 35 : <identifier_or_enum_value>
36, // at 36 : <select_goil_5F_syntax_0>
45, // at 37 : <select_goil_5F_syntax_1>
54, // at 38 : <select_goil_5F_syntax_2>
61, // at 39 : <select_goil_5F_syntax_3>
68, // at 40 : <select_goil_5F_syntax_4>
76, // at 41 : <select_goil_5F_syntax_5>
81, // at 42 : <select_goil_5F_syntax_6>
89, // at 43 : <select_goil_5F_syntax_7>
94, // at 44 : <select_goil_5F_syntax_8>
110, // at 45 : <select_goil_5F_syntax_9>
116, // at 46 : <select_goil_5F_syntax_10>
121, // at 47 : <select_goil_5F_syntax_11>
127, // at 48 : <select_goil_5F_syntax_12>
132, // at 49 : <select_goil_5F_syntax_13>
137, // at 50 : <select_goil_5F_syntax_14>
142, // at 51 : <select_goil_5F_syntax_15>
147, // at 52 : <select_goil_5F_syntax_16>
152, // at 53 : <select_goil_5F_syntax_17>
157, // at 54 : <select_implementation_5F_parser_0>
165, // at 55 : <select_implementation_5F_parser_1>
170, // at 56 : <select_implementation_5F_parser_2>
175, // at 57 : <select_implementation_5F_parser_3>
180, // at 58 : <select_implementation_5F_parser_4>
185, // at 59 : <select_implementation_5F_parser_5>
190, // at 60 : <select_implementation_5F_parser_6>
209, // at 61 : <select_implementation_5F_parser_7>
232, // at 62 : <select_implementation_5F_parser_8>
237, // at 63 : <select_implementation_5F_parser_9>
245, // at 64 : <select_implementation_5F_parser_10>
252, // at 65 : <select_implementation_5F_parser_11>
257, // at 66 : <select_implementation_5F_parser_12>
262, // at 67 : <select_implementation_5F_parser_13>
267, // at 68 : <select_implementation_5F_parser_14>
275, // at 69 : <select_implementation_5F_parser_15>
281, // at 70 : <select_implementation_5F_parser_16>
286, // at 71 : <select_implementation_5F_parser_17>
294, // at 72 : <select_implementation_5F_parser_18>
301, // at 73 : <select_implementation_5F_parser_19>
309, // at 74 : <select_implementation_5F_parser_20>
319, // at 75 : <select_implementation_5F_parser_21>
327, // at 76 : <select_implementation_5F_parser_22>
334, // at 77 : <select_implementation_5F_parser_23>
340, // at 78 : <select_implementation_5F_parser_24>
345, // at 79 : <select_implementation_5F_parser_25>
350, // at 80 : <select_implementation_5F_parser_26>
357, // at 81 : <select_implementation_5F_parser_27>
363, // at 82 : <select_implementation_5F_parser_28>
369, // at 83 : <select_implementation_5F_parser_29>
374, // at 84 : <select_implementation_5F_parser_30>
381, // at 85 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_definition' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_definition_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'start' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_start_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_start_ (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_(inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'file' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_file_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_file_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'sign' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'description' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'OIL_version' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'application_definition' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_application_5F_definition_ (const GALGAS_implementation parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'object_definition_list' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_object_5F_definition_5F_list_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'boolean' non terminal implementation                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'oil_declaration_list' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'oil_declaration' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_file_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_file_5F_level_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_cpu_level' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_cpu_5F_level_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'include_object_level' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_object_list' non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_object_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_object_5F_list_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'include_implementation_level' non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_implementation_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_implementation_5F_level_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_type_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_type_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'implementation_objects' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_objects_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_objects_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'implementation_list' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_list_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_(parameter_1, inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_goil_5F_type_5F_level_5F_include::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performTopDownParsing (gProductions_goil_type_level_include, gProductionNames_goil_type_level_include, gProductionIndexes_goil_type_level_include,
                                    gFirstProductionIndexes_goil_type_level_include, gDecision_goil_type_level_include, gDecisionIndexes_goil_type_level_include, 448) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_implementationObjectMap &  parameter_1
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
      const bool ok = scanner->performTopDownParsing (gProductions_goil_type_level_include, gProductionNames_goil_type_level_include, gProductionIndexes_goil_type_level_include,
                                                      gFirstProductionIndexes_goil_type_level_include, gDecision_goil_type_level_include, gDecisionIndexes_goil_type_level_include, 448) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_type_5F_level_5F_include grammar ;
        grammar.nt_implementation_5F_list_ (parameter_1, scanner) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                GALGAS_implementationObjectMap &  parameter_1
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_goil_type_level_include, gProductionNames_goil_type_level_include, gProductionIndexes_goil_type_level_include,
                                                    gFirstProductionIndexes_goil_type_level_include, gDecision_goil_type_level_include, gDecisionIndexes_goil_type_level_include, 448) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_goil_5F_type_5F_level_5F_include grammar ;
      grammar.nt_implementation_5F_list_ (parameter_1, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'implementation_type' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_type_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_type_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'struct_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_struct_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_struct_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'objref_option' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_objref_5F_option_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_objref_5F_option_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'string_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_string_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_string_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'boolean_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_boolean_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_boolean_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'enum_item' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_enum_5F_item_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_enum_5F_item_ (GALGAS_enumValues & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'enum_options' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_enum_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_enum_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'number_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_number_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_number_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'type_options' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_type_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_type_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'with_auto' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_with_5F_auto_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_with_5F_auto_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'int_or_float' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_int_5F_or_5F_float_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'set_followup' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_set_5F_followup_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_set_5F_followup_ (GALGAS_numberList & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'range_content' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_range_5F_content_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_range_5F_content_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'range' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_range_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_range_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'multiple' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_multiple_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_multiple_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'identifier_or_attribute' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'identifier_or_enum_value' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_0' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_1' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_2' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_3' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_4' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_5' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_6' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_7' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_8' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_9' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_10' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_11' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_12' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_13' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_14' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_15' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_16' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_17' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_0' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_1' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_2' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_3' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_4' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_5' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_6' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_7' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_8' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_9' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_10' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_11' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_12' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_13' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_14' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_15' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_16' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_17' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_18' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_18 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_19' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_19 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_20' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_20 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_21' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_21 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_22' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_22 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_23' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_23 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_24' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_24 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_25' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_25 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_26' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_26 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_27' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_27 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_28' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_28 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_29' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_29 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_30' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_30 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*


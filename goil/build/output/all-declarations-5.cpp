#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-5.h"


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
  return "3.0.1" ;
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
    const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, temp_2.getter_lastCharacter (inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 134)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
    if (kBoolTrue == test_3) {
      const GALGAS_string temp_4 = inObject ;
      result_result = temp_4.add_operation (constinArgument_pathToAppend, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 135)) ;
    }else if (kBoolFalse == test_3) {
      const GALGAS_string temp_5 = inObject ;
      result_result = temp_5.add_operation (GALGAS_char (TO_UNICODE (47)).getter_string (SOURCE_FILE ("gtl_types.galgas", 137)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 137)).add_operation (constinArgument_pathToAppend, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 137)) ;
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
  const enumGalgasBool test_1 = temp_0.getter_hasKey (constinArgument_key.getter_string (SOURCE_FILE ("gtl_types.galgas", 166)) COMMA_SOURCE_FILE ("gtl_types.galgas", 166)).boolEnum () ;
  if (kBoolTrue == test_1) {
    {
    ioObject.setter_setValueForKey (constinArgument_data, constinArgument_key.getter_string (SOURCE_FILE ("gtl_types.galgas", 167)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 167)) ;
    }
  }else if (kBoolFalse == test_1) {
    {
    ioObject.setter_put (constinArgument_key, constinArgument_data, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 169)) ;
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
  const enumGalgasBool test_1 = temp_0.getter_hasKeyAtLevel (constinArgument_key.getter_string (SOURCE_FILE ("gtl_types.galgas", 178)), constinArgument_level COMMA_SOURCE_FILE ("gtl_types.galgas", 178)).boolEnum () ;
  if (kBoolTrue == test_1) {
    {
    GALGAS_gtlData joker_4592 ; // Joker input parameter
    ioObject.setter_del (constinArgument_key, joker_4592, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 179)) ;
    }
  }
  {
  ioObject.setter_put (constinArgument_key, constinArgument_data, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 181)) ;
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
  const enumGalgasBool test_1 = temp_0.getter_hasKey (inArgument_path.getter_string (SOURCE_FILE ("gtl_types.galgas", 227)) COMMA_SOURCE_FILE ("gtl_types.galgas", 227)).boolEnum () ;
  if (kBoolTrue == test_1) {
    outArgument_found = GALGAS_bool (true) ;
    const GALGAS_gtlTemplateMap temp_2 = ioObject ;
    temp_2.method_get (inArgument_path, outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 229)) ;
  }else if (kBoolFalse == test_1) {
    const enumGalgasBool test_3 = inArgument_path.mAttribute_string.getter_fileExists (SOURCE_FILE ("gtl_types.galgas", 231)).boolEnum () ;
    if (kBoolTrue == test_3) {
      outArgument_found = GALGAS_bool (true) ;
      GALGAS_gtlInstructionList var_program_6329 ;
      var_program_6329.drop () ;
      cGrammar_gtl_5F_grammar::_performSourceFileParsing_ (inCompiler, inArgument_path, constinArgument_context, ioArgument_lib, var_program_6329  COMMA_SOURCE_FILE ("gtl_types.galgas", 233)) ;
      outArgument_result = GALGAS_gtlTemplate::constructor_new (inArgument_path.getter_string (SOURCE_FILE ("gtl_types.galgas", 237)), var_program_6329  COMMA_SOURCE_FILE ("gtl_types.galgas", 237)) ;
      {
      ioObject.setter_put (inArgument_path, outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 238)) ;
      }
    }else if (kBoolFalse == test_3) {
      outArgument_found = GALGAS_bool (false) ;
      const enumGalgasBool test_4 = inArgument_ifExists.boolEnum () ;
      if (kBoolTrue == test_4) {
        outArgument_result = GALGAS_gtlTemplate::constructor_new (inArgument_path.getter_string (SOURCE_FILE ("gtl_types.galgas", 242)), GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_types.galgas", 242))  COMMA_SOURCE_FILE ("gtl_types.galgas", 242)) ;
      }else if (kBoolFalse == test_4) {
        TC_Array <C_FixItDescription> fixItArray5 ;
        inCompiler->emitSemanticError (inArgument_path.getter_location (SOURCE_FILE ("gtl_types.galgas", 244)), GALGAS_string ("template file not found at \"").add_operation (inArgument_path.getter_string (SOURCE_FILE ("gtl_types.galgas", 244)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 244)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 244)), fixItArray5  COMMA_SOURCE_FILE ("gtl_types.galgas", 244)) ;
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
    GALGAS_gtlData var_context_23595 = ioArgument_vars ;
    const GALGAS_gtlVarPath temp_3 = inObject ;
    callExtensionMethod_deleteInContext ((const cPtr_gtlVarItem *) var_item_23550.ptr (), var_context_23595, ioArgument_vars, constinArgument_lib, temp_3.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 814)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 810)) ;
  }else if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 817)), GALGAS_string ("INTERNAL ERROR. A @gtlVarPath should not be an empty list"), fixItArray4  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 817)) ;
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
  GALGAS_gtlVarItem var_lastOne_24105 ;
  const GALGAS_gtlVarPath temp_0 = inObject ;
  temp_0.method_last (var_lastOne_24105, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 826)) ;
  result_where = callExtensionGetter_location ((const cPtr_gtlVarItem *) var_lastOne_24105.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 827)) ;
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
  const GALGAS_gtlInstructionList temp_0 = inObject ;
  cEnumerator_gtlInstructionList enumerator_1524 (temp_0, kEnumeration_up) ;
  while (enumerator_1524.hasCurrentObject ()) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 60)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
    if (kBoolTrue == test_1) {
      callExtensionMethod_execute ((const cPtr_gtlInstruction *) enumerator_1524.current_instruction (HERE).ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 61)) ;
      const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 62)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_2) {
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlInstruction *) enumerator_1524.current_instruction (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 63)), GALGAS_string ("runtime error"), fixItArray3  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 63)) ;
      }
    }
    enumerator_1524.gotoNextObject () ;
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
  GALGAS_gtlData var_temp_27187 = ioArgument_aList.getter_valueAtIndex (constinArgument_index_31_, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 912)) ;
  {
  ioArgument_aList.setter_setValueAtIndex (ioArgument_aList.getter_valueAtIndex (constinArgument_index_32_, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 913)), constinArgument_index_31_, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 913)) ;
  }
  {
  ioArgument_aList.setter_setValueAtIndex (var_temp_27187, constinArgument_index_32_, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 914)) ;
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
  GALGAS_gtlData var_pivot_27470 = ioArgument_aList.getter_valueAtIndex (ioArgument_pivotIndex, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 923)) ;
  const GALGAS_gtlAbstractSortInstruction temp_0 = object ;
  callExtensionMethod_swap ((const cPtr_gtlAbstractSortInstruction *) temp_0.ptr (), ioArgument_aList, ioArgument_pivotIndex, constinArgument_max, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 924)) ;
  GALGAS_uint var_storeIndex_27563 = constinArgument_min ;
  GALGAS_uint var_i_27579 = constinArgument_min ;
  if (constinArgument_max.substract_operation (constinArgument_min, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 927)).isValid ()) {
    uint32_t variant_27592 = constinArgument_max.substract_operation (constinArgument_min, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 927)).uintValue () ;
    bool loop_27592 = true ;
    while (loop_27592) {
      loop_27592 = GALGAS_bool (kIsStrictInf, var_i_27579.objectCompare (constinArgument_max)).isValid () ;
      if (loop_27592) {
        loop_27592 = GALGAS_bool (kIsStrictInf, var_i_27579.objectCompare (constinArgument_max)).boolValue () ;
      }
      if (loop_27592 && (0 == variant_27592)) {
        loop_27592 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_instructions.galgas", 927)) ;
      }
      if (loop_27592) {
        variant_27592 -- ;
        const GALGAS_gtlAbstractSortInstruction temp_1 = object ;
        const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, callExtensionGetter_compare ((const cPtr_gtlAbstractSortInstruction *) temp_1.ptr (), ioArgument_aList.getter_valueAtIndex (var_i_27579, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 929)), var_pivot_27470, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 929)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 929)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          const GALGAS_gtlAbstractSortInstruction temp_3 = object ;
          callExtensionMethod_swap ((const cPtr_gtlAbstractSortInstruction *) temp_3.ptr (), ioArgument_aList, var_i_27579, var_storeIndex_27563, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 930)) ;
          var_storeIndex_27563.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 931)) ;
        }
        var_i_27579.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 933)) ;
      }
    }
  }
  const GALGAS_gtlAbstractSortInstruction temp_4 = object ;
  callExtensionMethod_swap ((const cPtr_gtlAbstractSortInstruction *) temp_4.ptr (), ioArgument_aList, var_storeIndex_27563, constinArgument_max, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 935)) ;
  ioArgument_pivotIndex = var_storeIndex_27563 ;
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
    GALGAS_uint var_pivotIndex_27975 = constinArgument_max.add_operation (constinArgument_min, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 945)).divide_operation (GALGAS_uint ((uint32_t) 2U), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 945)) ;
    const GALGAS_gtlAbstractSortInstruction temp_1 = object ;
    callExtensionMethod_partition ((const cPtr_gtlAbstractSortInstruction *) temp_1.ptr (), ioArgument_aList, constinArgument_min, constinArgument_max, var_pivotIndex_27975, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 946)) ;
    const GALGAS_gtlAbstractSortInstruction temp_2 = object ;
    callExtensionMethod_sort ((const cPtr_gtlAbstractSortInstruction *) temp_2.ptr (), ioArgument_aList, constinArgument_min, var_pivotIndex_27975, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 947)) ;
    const GALGAS_gtlAbstractSortInstruction temp_3 = object ;
    callExtensionMethod_sort ((const cPtr_gtlAbstractSortInstruction *) temp_3.ptr (), ioArgument_aList, var_pivotIndex_27975.add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 948)), constinArgument_max, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 948)) ;
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
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, inArgument_keyList.getter_length (SOURCE_FILE ("gtl_instructions.galgas", 996)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
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
            inCompiler->castError ("gtlStruct", constinArgument_s_31_.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 999)) ;
          }
        }
        GALGAS_gtlStruct var_s_31_Struct_29453 = temp_3 ;
        GALGAS_gtlStruct temp_4 ;
        if (constinArgument_s_32_.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlStruct *> (constinArgument_s_32_.ptr ())) {
            temp_4 = (cPtr_gtlStruct *) constinArgument_s_32_.ptr () ;
          }else{
            inCompiler->castError ("gtlStruct", constinArgument_s_32_.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1000)) ;
          }
        }
        GALGAS_gtlStruct var_s_32_Struct_29500 = temp_4 ;
        GALGAS_lstring var_field_29563 ;
        GALGAS_lsint var_order_29577 ;
        {
        inArgument_keyList.setter_popFirst (var_field_29563, var_order_29577, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1001)) ;
        }
        GALGAS_gtlData var_s_31_Field_29633 ;
        var_s_31_Struct_29453.getter_value (SOURCE_FILE ("gtl_instructions.galgas", 1002)).method_get (var_field_29563, var_s_31_Field_29633, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1002)) ;
        GALGAS_gtlData var_s_32_Field_29689 ;
        var_s_32_Struct_29500.getter_value (SOURCE_FILE ("gtl_instructions.galgas", 1003)).method_get (var_field_29563, var_s_32_Field_29689, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1003)) ;
        const enumGalgasBool test_5 = callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_ltOp ((const cPtr_gtlData *) var_s_31_Field_29633.ptr (), var_s_32_Field_29689, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1004)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1011)).boolEnum () ;
        if (kBoolTrue == test_5) {
          result_result = GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1005)).multiply_operation (var_order_29577.getter_sint (SOURCE_FILE ("gtl_instructions.galgas", 1005)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1005)) ;
        }else if (kBoolFalse == test_5) {
          const enumGalgasBool test_6 = callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_gtOp ((const cPtr_gtlData *) var_s_31_Field_29633.ptr (), var_s_32_Field_29689, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1007)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1010)).boolEnum () ;
          if (kBoolTrue == test_6) {
            result_result = GALGAS_sint ((int32_t) 1L).multiply_operation (var_order_29577.getter_sint (SOURCE_FILE ("gtl_instructions.galgas", 1008)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1008)) ;
          }else if (kBoolFalse == test_6) {
            const GALGAS_gtlSortStatementStructInstruction temp_7 = object ;
            result_result = callExtensionGetter_compareElements ((const cPtr_gtlSortStatementStructInstruction *) temp_7.ptr (), constinArgument_s_31_, constinArgument_s_32_, inArgument_keyList, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1010)) ;
          }
        }
      }else if (kBoolFalse == test_2) {
        TC_Array <C_FixItDescription> fixItArray8 ;
        inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_s_32_.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1014)), GALGAS_string ("struct expected"), fixItArray8  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1014)) ;
        result_result.drop () ; // Release error dropped variable
      }
    }else if (kBoolFalse == test_1) {
      TC_Array <C_FixItDescription> fixItArray9 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_s_31_.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1017)), GALGAS_string ("struct expected"), fixItArray9  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1017)) ;
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
//                                        Extension Getter '@dataType oilType'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_oilType (const GALGAS_dataType & inObject,
                                       C_Compiler * /* inCompiler */
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




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Abstract extension method '@attributeRange enclose'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_attributeRange_enclose> gExtensionMethodTable_attributeRange_enclose ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_enclose (const int32_t inClassIndex,
                                   extensionMethodSignature_attributeRange_enclose inMethod) {
  gExtensionMethodTable_attributeRange_enclose.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_attributeRange_enclose (void) {
  gExtensionMethodTable_attributeRange_enclose.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_attributeRange_enclose (NULL,
                                                   freeExtensionMethod_attributeRange_enclose) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_enclose (const cPtr_attributeRange * inObject,
                                  GALGAS_bool & out_isWithin,
                                  const GALGAS_attributeRange constin_value,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
//--- Drop output arguments
  out_isWithin.drop () ;
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_attributeRange) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_attributeRange_enclose f = NULL ;
    if (classIndex < gExtensionMethodTable_attributeRange_enclose.count ()) {
      f = gExtensionMethodTable_attributeRange_enclose (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_attributeRange_enclose.count ()) {
           f = gExtensionMethodTable_attributeRange_enclose (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_attributeRange_enclose.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, out_isWithin, constin_value, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension Getter '@enumValues mergeWithEnum'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumValues extensionGetter_mergeWithEnum (const GALGAS_enumValues & inObject,
                                                 const GALGAS_enumValues & constinArgument_enumToMerge,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_enumValues result_mergedEnum ; // Returned variable
  result_mergedEnum = GALGAS_enumValues::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 696)) ;
  const GALGAS_enumValues temp_0 = inObject ;
  cEnumerator_enumValues enumerator_19313 (temp_0, kEnumeration_up) ;
  while (enumerator_19313.hasCurrentObject ()) {
    GALGAS_implementationObjectMap var_attributes_19356 = enumerator_19313.current_subAttributes (HERE) ;
    const enumGalgasBool test_1 = constinArgument_enumToMerge.getter_hasKey (enumerator_19313.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 699)) COMMA_SOURCE_FILE ("implementation_types.galgas", 699)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_implementationObjectMap var_attributesToMerge_19493 ;
      constinArgument_enumToMerge.method_get (enumerator_19313.current_lkey (HERE), var_attributesToMerge_19493, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 700)) ;
      var_attributes_19356 = extensionGetter_mergeImplementationObjectAttributesWith (enumerator_19313.current_subAttributes (HERE), var_attributesToMerge_19493, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 701)) ;
    }
    {
    result_mergedEnum.setter_put (enumerator_19313.current_lkey (HERE), var_attributes_19356, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 703)) ;
    }
    enumerator_19313.gotoNextObject () ;
  }
  cEnumerator_enumValues enumerator_19667 (constinArgument_enumToMerge, kEnumeration_up) ;
  while (enumerator_19667.hasCurrentObject ()) {
    const GALGAS_enumValues temp_2 = inObject ;
    const enumGalgasBool test_3 = temp_2.getter_hasKey (enumerator_19667.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 706)) COMMA_SOURCE_FILE ("implementation_types.galgas", 706)).operator_not (SOURCE_FILE ("implementation_types.galgas", 706)).boolEnum () ;
    if (kBoolTrue == test_3) {
      {
      result_mergedEnum.setter_put (enumerator_19667.current_lkey (HERE), enumerator_19667.current_subAttributes (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 707)) ;
      }
    }
    enumerator_19667.gotoNextObject () ;
  }
//---
  return result_mergedEnum ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension getter '@implementation hasKey'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_implementation_hasKey> gExtensionGetterTable_implementation_hasKey ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasKey (const int32_t inClassIndex,
                                  enterExtensionGetter_implementation_hasKey inGetter) {
  gExtensionGetterTable_implementation_hasKey.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_hasKey (const cPtr_implementation * inObject,
                                        const GALGAS_string & in_key,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_implementation) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_implementation_hasKey f = NULL ;
    if (classIndex < gExtensionGetterTable_implementation_hasKey.count ()) {
      f = gExtensionGetterTable_implementation_hasKey (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_implementation_hasKey.count ()) {
           f = gExtensionGetterTable_implementation_hasKey (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_implementation_hasKey.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_key, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_implementation_hasKey (const cPtr_implementation * inObject,
                                                          const GALGAS_string & constinArgument_key,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_implementation * object = inObject ;
  macroValidSharedObject (object, cPtr_implementation) ;
  result_result = object->mAttribute_imp.getter_hasKey (constinArgument_key COMMA_SOURCE_FILE ("implementation_types.galgas", 765)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_implementation_hasKey (void) {
  enterExtensionGetter_hasKey (kTypeDescriptor_GALGAS_implementation.mSlotID,
                               extensionGetter_implementation_hasKey) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_implementation_hasKey (void) {
  gExtensionGetterTable_implementation_hasKey.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_implementation_hasKey (defineExtensionGetter_implementation_hasKey,
                                                  freeExtensionGetter_implementation_hasKey) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@implementation hasLKey'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_implementation_hasLKey> gExtensionGetterTable_implementation_hasLKey ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasLKey (const int32_t inClassIndex,
                                   enterExtensionGetter_implementation_hasLKey inGetter) {
  gExtensionGetterTable_implementation_hasLKey.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_hasLKey (const cPtr_implementation * inObject,
                                         const GALGAS_lstring & in_key,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_implementation) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_implementation_hasLKey f = NULL ;
    if (classIndex < gExtensionGetterTable_implementation_hasLKey.count ()) {
      f = gExtensionGetterTable_implementation_hasLKey (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_implementation_hasLKey.count ()) {
           f = gExtensionGetterTable_implementation_hasLKey (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_implementation_hasLKey.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_key, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_implementation_hasLKey (const cPtr_implementation * inObject,
                                                           const GALGAS_lstring & constinArgument_key,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_implementation * object = inObject ;
  macroValidSharedObject (object, cPtr_implementation) ;
  result_result = object->mAttribute_imp.getter_hasKey (constinArgument_key.getter_string (SOURCE_FILE ("implementation_types.galgas", 771)) COMMA_SOURCE_FILE ("implementation_types.galgas", 771)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_implementation_hasLKey (void) {
  enterExtensionGetter_hasLKey (kTypeDescriptor_GALGAS_implementation.mSlotID,
                                extensionGetter_implementation_hasLKey) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_implementation_hasLKey (void) {
  gExtensionGetterTable_implementation_hasLKey.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_implementation_hasLKey (defineExtensionGetter_implementation_hasLKey,
                                                   freeExtensionGetter_implementation_hasLKey) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension getter '@implementation impObject'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_implementation_impObject> gExtensionGetterTable_implementation_impObject ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_impObject (const int32_t inClassIndex,
                                     enterExtensionGetter_implementation_impObject inGetter) {
  gExtensionGetterTable_implementation_impObject.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObject callExtensionGetter_impObject (const cPtr_implementation * inObject,
                                                           const GALGAS_string & in_objKind,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) {
  GALGAS_implementationObject result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_implementation) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_implementation_impObject f = NULL ;
    if (classIndex < gExtensionGetterTable_implementation_impObject.count ()) {
      f = gExtensionGetterTable_implementation_impObject (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_implementation_impObject.count ()) {
           f = gExtensionGetterTable_implementation_impObject (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_implementation_impObject.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_objKind, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_implementationObject extensionGetter_implementation_impObject (const cPtr_implementation * inObject,
                                                                             const GALGAS_string & constinArgument_objKind,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObject result_obj ; // Returned variable
  const cPtr_implementation * object = inObject ;
  macroValidSharedObject (object, cPtr_implementation) ;
  result_obj = GALGAS_implementationObject::constructor_new (GALGAS_lbool::constructor_new (GALGAS_bool (false), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 777))  COMMA_SOURCE_FILE ("implementation_types.galgas", 777)), GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 777))  COMMA_SOURCE_FILE ("implementation_types.galgas", 777)) ;
  const enumGalgasBool test_0 = object->mAttribute_imp.getter_hasKey (constinArgument_objKind COMMA_SOURCE_FILE ("implementation_types.galgas", 778)).boolEnum () ;
  if (kBoolTrue == test_0) {
    object->mAttribute_imp.method_get (function_lstringWith (constinArgument_objKind, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 779)), result_obj, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 779)) ;
  }
//---
  return result_obj ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_implementation_impObject (void) {
  enterExtensionGetter_impObject (kTypeDescriptor_GALGAS_implementation.mSlotID,
                                  extensionGetter_implementation_impObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_implementation_impObject (void) {
  gExtensionGetterTable_implementation_impObject.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_implementation_impObject (defineExtensionGetter_implementation_impObject,
                                                     freeExtensionGetter_implementation_impObject) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@implementation checkTypeForKind'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_implementation_checkTypeForKind> gExtensionMethodTable_implementation_checkTypeForKind ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_checkTypeForKind (const int32_t inClassIndex,
                                            extensionMethodSignature_implementation_checkTypeForKind inMethod) {
  gExtensionMethodTable_implementation_checkTypeForKind.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_checkTypeForKind (const cPtr_implementation * inObject,
                                           const GALGAS_string constin_objKind,
                                           const GALGAS_string constin_attributeName,
                                           const GALGAS_dataType constin_expectedType,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_implementation) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_implementation_checkTypeForKind f = NULL ;
    if (classIndex < gExtensionMethodTable_implementation_checkTypeForKind.count ()) {
      f = gExtensionMethodTable_implementation_checkTypeForKind (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_implementation_checkTypeForKind.count ()) {
           f = gExtensionMethodTable_implementation_checkTypeForKind (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_implementation_checkTypeForKind.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_objKind, constin_attributeName, constin_expectedType, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_implementation_checkTypeForKind (const cPtr_implementation * inObject,
                                                             const GALGAS_string constinArgument_objKind,
                                                             const GALGAS_string constinArgument_attributeName,
                                                             const GALGAS_dataType constinArgument_expectedType,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_implementation * object = inObject ;
  macroValidSharedObject (object, cPtr_implementation) ;
  const GALGAS_implementation temp_0 = object ;
  GALGAS_implementationObject var_obj_21635 = callExtensionGetter_impObject ((const cPtr_implementation *) temp_0.ptr (), constinArgument_objKind, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 787)) ;
  {
  routine_checkTypeForAttribute (var_obj_21635.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 788)), constinArgument_attributeName, constinArgument_expectedType, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 788)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_implementation_checkTypeForKind (void) {
  enterExtensionMethod_checkTypeForKind (kTypeDescriptor_GALGAS_implementation.mSlotID,
                                         extensionMethod_implementation_checkTypeForKind) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_implementation_checkTypeForKind (void) {
  gExtensionMethodTable_implementation_checkTypeForKind.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_implementation_checkTypeForKind (defineExtensionMethod_implementation_checkTypeForKind,
                                                            freeExtensionMethod_implementation_checkTypeForKind) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension method '@implementation checkObjectReferences'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_implementation_checkObjectReferences> gExtensionMethodTable_implementation_checkObjectReferences ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_checkObjectReferences (const int32_t inClassIndex,
                                                 extensionMethodSignature_implementation_checkObjectReferences inMethod) {
  gExtensionMethodTable_implementation_checkObjectReferences.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_checkObjectReferences (const cPtr_implementation * inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_implementation) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_implementation_checkObjectReferences f = NULL ;
    if (classIndex < gExtensionMethodTable_implementation_checkObjectReferences.count ()) {
      f = gExtensionMethodTable_implementation_checkObjectReferences (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_implementation_checkObjectReferences.count ()) {
           f = gExtensionMethodTable_implementation_checkObjectReferences (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_implementation_checkObjectReferences.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_implementation_checkObjectReferences (const cPtr_implementation * inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_implementation * object = inObject ;
  macroValidSharedObject (object, cPtr_implementation) ;
  cEnumerator_implementationMap enumerator_21804 (object->mAttribute_imp, kEnumeration_up) ;
  while (enumerator_21804.hasCurrentObject ()) {
    cEnumerator_implementationObjectMap enumerator_21839 (enumerator_21804.current_obj (HERE).getter_attributes (SOURCE_FILE ("implementation_types.galgas", 793)), kEnumeration_up) ;
    while (enumerator_21839.hasCurrentObject ()) {
      const GALGAS_implementation temp_0 = object ;
      callExtensionMethod_checkAttributeReferences ((const cPtr_impType *) enumerator_21839.current_type (HERE).ptr (), temp_0, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 794)) ;
      enumerator_21839.gotoNextObject () ;
    }
    enumerator_21804.gotoNextObject () ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_implementation_checkObjectReferences (void) {
  enterExtensionMethod_checkObjectReferences (kTypeDescriptor_GALGAS_implementation.mSlotID,
                                              extensionMethod_implementation_checkObjectReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_implementation_checkObjectReferences (void) {
  gExtensionMethodTable_implementation_checkObjectReferences.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_implementation_checkObjectReferences (defineExtensionMethod_implementation_checkObjectReferences,
                                                                 freeExtensionMethod_implementation_checkObjectReferences) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                 Extension Getter '@implementationObjectMap mergeImplementationObjectAttributesWith'                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap extensionGetter_mergeImplementationObjectAttributesWith (const GALGAS_implementationObjectMap & inObject,
                                                                                        const GALGAS_implementationObjectMap & constinArgument_attributesToMerge,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result_mergedAttributes ; // Returned variable
  result_mergedAttributes = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 1015)) ;
  const GALGAS_implementationObjectMap temp_0 = inObject ;
  cEnumerator_implementationObjectMap enumerator_29413 (temp_0, kEnumeration_up) ;
  while (enumerator_29413.hasCurrentObject ()) {
    GALGAS_impType var_merged_29436 = enumerator_29413.current_type (HERE) ;
    const enumGalgasBool test_1 = constinArgument_attributesToMerge.getter_hasKey (enumerator_29413.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 1018)) COMMA_SOURCE_FILE ("implementation_types.galgas", 1018)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_impType var_typeToMerge_29554 ;
      constinArgument_attributesToMerge.method_get (enumerator_29413.current_lkey (HERE), var_typeToMerge_29554, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1019)) ;
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, enumerator_29413.current_type (HERE).getter_dynamicType (SOURCE_FILE ("implementation_types.galgas", 1020)).objectCompare (var_typeToMerge_29554.getter_dynamicType (SOURCE_FILE ("implementation_types.galgas", 1020)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_merged_29436 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_29413.current_type (HERE).ptr (), var_typeToMerge_29554, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1021)) ;
      }else if (kBoolFalse == test_2) {
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (enumerator_29413.current_lkey (HERE).getter_location (SOURCE_FILE ("implementation_types.galgas", 1024)), GALGAS_string ("Redefined type"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 1024)) ;
      }
    }
    {
    result_mergedAttributes.setter_put (enumerator_29413.current_lkey (HERE), var_merged_29436, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1027)) ;
    }
    enumerator_29413.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_29843 (constinArgument_attributesToMerge, kEnumeration_up) ;
  while (enumerator_29843.hasCurrentObject ()) {
    const GALGAS_implementationObjectMap temp_4 = inObject ;
    const enumGalgasBool test_5 = temp_4.getter_hasKey (enumerator_29843.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 1030)) COMMA_SOURCE_FILE ("implementation_types.galgas", 1030)).operator_not (SOURCE_FILE ("implementation_types.galgas", 1030)).boolEnum () ;
    if (kBoolTrue == test_5) {
      {
      result_mergedAttributes.setter_put (enumerator_29843.current_lkey (HERE), enumerator_29843.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1031)) ;
      }
    }
    enumerator_29843.gotoNextObject () ;
  }
//---
  return result_mergedAttributes ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension getter '@objectAttributes fieldMap'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_objectAttributes_fieldMap> gExtensionGetterTable_objectAttributes_fieldMap ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_fieldMap (const int32_t inClassIndex,
                                    enterExtensionGetter_objectAttributes_fieldMap inGetter) {
  gExtensionGetterTable_objectAttributes_fieldMap.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_fieldMap (const cPtr_objectAttributes * inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_objectAttributes) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_objectAttributes_fieldMap f = NULL ;
    if (classIndex < gExtensionGetterTable_objectAttributes_fieldMap.count ()) {
      f = gExtensionGetterTable_objectAttributes_fieldMap (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_objectAttributes_fieldMap.count ()) {
           f = gExtensionGetterTable_objectAttributes_fieldMap (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_objectAttributes_fieldMap.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_gtlData extensionGetter_objectAttributes_fieldMap (const cPtr_objectAttributes * inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_objectAttributes * object = inObject ;
  macroValidSharedObject (object, cPtr_objectAttributes) ;
  result_result = GALGAS_gtlStruct::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 160)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 160)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 160))  COMMA_SOURCE_FILE ("systemConfig.galgas", 160)) ;
  cEnumerator_identifierMap enumerator_5178 (object->mAttribute_objectParams, kEnumeration_up) ;
  while (enumerator_5178.hasCurrentObject ()) {
    callExtensionMethod_set ((const cPtr_object_5F_t *) enumerator_5178.current_value (HERE).ptr (), enumerator_5178.current_lkey (HERE), result_result, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 162)) ;
    enumerator_5178.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_objectAttributes_fieldMap (void) {
  enterExtensionGetter_fieldMap (kTypeDescriptor_GALGAS_objectAttributes.mSlotID,
                                 extensionGetter_objectAttributes_fieldMap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_objectAttributes_fieldMap (void) {
  gExtensionGetterTable_objectAttributes_fieldMap.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_objectAttributes_fieldMap (defineExtensionGetter_objectAttributes_fieldMap,
                                                      freeExtensionGetter_objectAttributes_fieldMap) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Extension Getter '@string trimLeft'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_trimLeft (const GALGAS_string & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_string temp_0 = inObject ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, temp_0.getter_leftSubString (GALGAS_uint ((uint32_t) 1U) COMMA_SOURCE_FILE ("systemConfig.galgas", 169)).objectCompare (GALGAS_string (" "))).boolEnum () ;
  if (kBoolTrue == test_1) {
    const GALGAS_string temp_2 = inObject ;
    const GALGAS_string temp_3 = inObject ;
    result_result = extensionGetter_trimLeft (temp_2.getter_rightSubString (temp_3.getter_length (SOURCE_FILE ("systemConfig.galgas", 170)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 170)) COMMA_SOURCE_FILE ("systemConfig.galgas", 170)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 170)) ;
  }else if (kBoolFalse == test_1) {
    const GALGAS_string temp_4 = inObject ;
    result_result = temp_4 ;
  }
//---
  return result_result ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension Getter '@string trimRight'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_trimRight (const GALGAS_string & inObject,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_string temp_0 = inObject ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, temp_0.getter_rightSubString (GALGAS_uint ((uint32_t) 1U) COMMA_SOURCE_FILE ("systemConfig.galgas", 179)).objectCompare (GALGAS_string (" "))).boolEnum () ;
  if (kBoolTrue == test_1) {
    const GALGAS_string temp_2 = inObject ;
    const GALGAS_string temp_3 = inObject ;
    result_result = extensionGetter_trimRight (temp_2.getter_leftSubString (temp_3.getter_length (SOURCE_FILE ("systemConfig.galgas", 180)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 180)) COMMA_SOURCE_FILE ("systemConfig.galgas", 180)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 180)) ;
  }else if (kBoolFalse == test_1) {
    const GALGAS_string temp_4 = inObject ;
    result_result = temp_4 ;
  }
//---
  return result_result ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Extension method '@implementation verifyApplication'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_implementation_verifyApplication> gExtensionMethodTable_implementation_verifyApplication ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_verifyApplication (const int32_t inClassIndex,
                                             extensionMethodSignature_implementation_verifyApplication inMethod) {
  gExtensionMethodTable_implementation_verifyApplication.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_verifyApplication (const cPtr_implementation * inObject,
                                            const GALGAS_applicationDefinition constin_appDef,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_implementation) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_implementation_verifyApplication f = NULL ;
    if (classIndex < gExtensionMethodTable_implementation_verifyApplication.count ()) {
      f = gExtensionMethodTable_implementation_verifyApplication (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_implementation_verifyApplication.count ()) {
           f = gExtensionMethodTable_implementation_verifyApplication (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_implementation_verifyApplication.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_appDef, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_implementation_verifyApplication (const cPtr_implementation * inObject,
                                                              const GALGAS_applicationDefinition constinArgument_appDef,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_implementation * object = inObject ;
  macroValidSharedObject (object, cPtr_implementation) ;
  cEnumerator_implementationMap enumerator_921 (object->mAttribute_imp, kEnumeration_up) ;
  while (enumerator_921.hasCurrentObject ()) {
    const enumGalgasBool test_0 = constinArgument_appDef.getter_objects (SOURCE_FILE ("semantic_verification.galgas", 35)).getter_hasKey (enumerator_921.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 35)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 35)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_objectKind var_obj_1003 ;
      constinArgument_appDef.getter_objects (SOURCE_FILE ("semantic_verification.galgas", 37)).method_get (enumerator_921.current_lkey (HERE), var_obj_1003, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 37)) ;
      callExtensionMethod_verifyApplication ((const cPtr_implementationObject *) enumerator_921.current_obj (HERE).ptr (), var_obj_1003, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 38)) ;
    }
    enumerator_921.gotoNextObject () ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_implementation_verifyApplication (void) {
  enterExtensionMethod_verifyApplication (kTypeDescriptor_GALGAS_implementation.mSlotID,
                                          extensionMethod_implementation_verifyApplication) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_implementation_verifyApplication (void) {
  gExtensionMethodTable_implementation_verifyApplication.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_implementation_verifyApplication (defineExtensionMethod_implementation_verifyApplication,
                                                             freeExtensionMethod_implementation_verifyApplication) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Extension method '@objectAttributes verifyCrossReferences'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_objectAttributes_verifyCrossReferences> gExtensionMethodTable_objectAttributes_verifyCrossReferences ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_verifyCrossReferences (const int32_t inClassIndex,
                                                 extensionMethodSignature_objectAttributes_verifyCrossReferences inMethod) {
  gExtensionMethodTable_objectAttributes_verifyCrossReferences.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_verifyCrossReferences (const cPtr_objectAttributes * inObject,
                                                const GALGAS_objectsMap constin_allObjects,
                                                const GALGAS_implementationObjectMap constin_attributes,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_objectAttributes) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_objectAttributes_verifyCrossReferences f = NULL ;
    if (classIndex < gExtensionMethodTable_objectAttributes_verifyCrossReferences.count ()) {
      f = gExtensionMethodTable_objectAttributes_verifyCrossReferences (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_objectAttributes_verifyCrossReferences.count ()) {
           f = gExtensionMethodTable_objectAttributes_verifyCrossReferences (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_objectAttributes_verifyCrossReferences.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_allObjects, constin_attributes, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_objectAttributes_verifyCrossReferences (const cPtr_objectAttributes * inObject,
                                                                    const GALGAS_objectsMap constinArgument_allObjects,
                                                                    const GALGAS_implementationObjectMap constinArgument_attributes,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_objectAttributes * object = inObject ;
  macroValidSharedObject (object, cPtr_objectAttributes) ;
  cEnumerator_identifierMap enumerator_18622 (object->mAttribute_objectParams, kEnumeration_up) ;
  while (enumerator_18622.hasCurrentObject ()) {
    const enumGalgasBool test_0 = constinArgument_attributes.getter_hasKey (enumerator_18622.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 599)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 599)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_impType var_type_18715 ;
      constinArgument_attributes.method_get (enumerator_18622.current_lkey (HERE), var_type_18715, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 600)) ;
      callExtensionMethod_verifyCrossReferences ((const cPtr_object_5F_t *) enumerator_18622.current_value (HERE).ptr (), constinArgument_allObjects, var_type_18715, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 601)) ;
    }
    enumerator_18622.gotoNextObject () ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_objectAttributes_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_objectAttributes.mSlotID,
                                              extensionMethod_objectAttributes_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_objectAttributes_verifyCrossReferences (void) {
  gExtensionMethodTable_objectAttributes_verifyCrossReferences.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_objectAttributes_verifyCrossReferences (defineExtensionMethod_objectAttributes_verifyCrossReferences,
                                                                   freeExtensionMethod_objectAttributes_verifyCrossReferences) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath_2D_element::GALGAS_gtlVarPath_2D_element (void) :
mAttribute_item () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath_2D_element::~ GALGAS_gtlVarPath_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath_2D_element::GALGAS_gtlVarPath_2D_element (const GALGAS_gtlVarItem & inOperand0) :
mAttribute_item (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath_2D_element GALGAS_gtlVarPath_2D_element::constructor_new (const GALGAS_gtlVarItem & inOperand0 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlVarPath_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_gtlVarPath_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_gtlVarPath_2D_element::objectCompare (const GALGAS_gtlVarPath_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_item.objectCompare (inOperand.mAttribute_item) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_gtlVarPath_2D_element::isValid (void) const {
  return mAttribute_item.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath_2D_element::drop (void) {
  mAttribute_item.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @gtlVarPath-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_item.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItem GALGAS_gtlVarPath_2D_element::getter_item (UNUSED_LOCATION_ARGS) const {
  return mAttribute_item ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlVarPath-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarPath_2D_element ("gtlVarPath-element",
                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlVarPath_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarPath_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlVarPath_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarPath_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath_2D_element GALGAS_gtlVarPath_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarPath_2D_element result ;
  const GALGAS_gtlVarPath_2D_element * p = (const GALGAS_gtlVarPath_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVarPath_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarPath-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList_2D_element::GALGAS_gtlTypedArgumentList_2D_element (void) :
mAttribute_type () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList_2D_element::~ GALGAS_gtlTypedArgumentList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList_2D_element::GALGAS_gtlTypedArgumentList_2D_element (const GALGAS_type & inOperand0) :
mAttribute_type (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList_2D_element GALGAS_gtlTypedArgumentList_2D_element::constructor_new (const GALGAS_type & inOperand0 
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_gtlTypedArgumentList_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_gtlTypedArgumentList_2D_element::objectCompare (const GALGAS_gtlTypedArgumentList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_type.objectCompare (inOperand.mAttribute_type) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_gtlTypedArgumentList_2D_element::isValid (void) const {
  return mAttribute_type.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList_2D_element::drop (void) {
  mAttribute_type.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList_2D_element::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "<struct @gtlTypedArgumentList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_type.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type GALGAS_gtlTypedArgumentList_2D_element::getter_type (UNUSED_LOCATION_ARGS) const {
  return mAttribute_type ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @gtlTypedArgumentList-element type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTypedArgumentList_2D_element ("gtlTypedArgumentList-element",
                                                        NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlTypedArgumentList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTypedArgumentList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlTypedArgumentList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTypedArgumentList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList_2D_element GALGAS_gtlTypedArgumentList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList_2D_element result ;
  const GALGAS_gtlTypedArgumentList_2D_element * p = (const GALGAS_gtlTypedArgumentList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlTypedArgumentList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTypedArgumentList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList_2D_element::GALGAS_gtlInstructionList_2D_element (void) :
mAttribute_instruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList_2D_element::~ GALGAS_gtlInstructionList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList_2D_element::GALGAS_gtlInstructionList_2D_element (const GALGAS_gtlInstruction & inOperand0) :
mAttribute_instruction (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList_2D_element GALGAS_gtlInstructionList_2D_element::constructor_new (const GALGAS_gtlInstruction & inOperand0 
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlInstructionList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_gtlInstructionList_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_gtlInstructionList_2D_element::objectCompare (const GALGAS_gtlInstructionList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_instruction.objectCompare (inOperand.mAttribute_instruction) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_gtlInstructionList_2D_element::isValid (void) const {
  return mAttribute_instruction.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList_2D_element::drop (void) {
  mAttribute_instruction.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList_2D_element::description (C_String & ioString,
                                                        const int32_t inIndentation) const {
  ioString << "<struct @gtlInstructionList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_instruction.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstruction GALGAS_gtlInstructionList_2D_element::getter_instruction (UNUSED_LOCATION_ARGS) const {
  return mAttribute_instruction ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlInstructionList-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlInstructionList_2D_element ("gtlInstructionList-element",
                                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlInstructionList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInstructionList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlInstructionList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlInstructionList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList_2D_element GALGAS_gtlInstructionList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlInstructionList_2D_element result ;
  const GALGAS_gtlInstructionList_2D_element * p = (const GALGAS_gtlInstructionList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlInstructionList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlInstructionList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List_2D_element::GALGAS_uint_33__32_List_2D_element (void) :
mAttribute_location (),
mAttribute_value () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List_2D_element::~ GALGAS_uint_33__32_List_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List_2D_element::GALGAS_uint_33__32_List_2D_element (const GALGAS_location & inOperand0,
                                                                        const GALGAS_uint & inOperand1) :
mAttribute_location (inOperand0),
mAttribute_value (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List_2D_element GALGAS_uint_33__32_List_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint_33__32_List_2D_element (GALGAS_location::constructor_nowhere (HERE),
                                             GALGAS_uint::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List_2D_element GALGAS_uint_33__32_List_2D_element::constructor_new (const GALGAS_location & inOperand0,
                                                                                        const GALGAS_uint & inOperand1 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_33__32_List_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_uint_33__32_List_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_uint_33__32_List_2D_element::objectCompare (const GALGAS_uint_33__32_List_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_location.objectCompare (inOperand.mAttribute_location) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_value.objectCompare (inOperand.mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_uint_33__32_List_2D_element::isValid (void) const {
  return mAttribute_location.isValid () && mAttribute_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_33__32_List_2D_element::drop (void) {
  mAttribute_location.drop () ;
  mAttribute_value.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_33__32_List_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @uint32List-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_uint_33__32_List_2D_element::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint_33__32_List_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @uint32List-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_33__32_List_2D_element ("uint32List-element",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_uint_33__32_List_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_List_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_uint_33__32_List_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_33__32_List_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List_2D_element GALGAS_uint_33__32_List_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_List_2D_element result ;
  const GALGAS_uint_33__32_List_2D_element * p = (const GALGAS_uint_33__32_List_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_33__32_List_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint32List-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List_2D_element::GALGAS_uint_36__34_List_2D_element (void) :
mAttribute_location (),
mAttribute_value () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List_2D_element::~ GALGAS_uint_36__34_List_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List_2D_element::GALGAS_uint_36__34_List_2D_element (const GALGAS_location & inOperand0,
                                                                        const GALGAS_uint_36__34_ & inOperand1) :
mAttribute_location (inOperand0),
mAttribute_value (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List_2D_element GALGAS_uint_36__34_List_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint_36__34_List_2D_element (GALGAS_location::constructor_nowhere (HERE),
                                             GALGAS_uint_36__34_::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List_2D_element GALGAS_uint_36__34_List_2D_element::constructor_new (const GALGAS_location & inOperand0,
                                                                                        const GALGAS_uint_36__34_ & inOperand1 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_36__34_List_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_uint_36__34_List_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_uint_36__34_List_2D_element::objectCompare (const GALGAS_uint_36__34_List_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_location.objectCompare (inOperand.mAttribute_location) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_value.objectCompare (inOperand.mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_uint_36__34_List_2D_element::isValid (void) const {
  return mAttribute_location.isValid () && mAttribute_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_36__34_List_2D_element::drop (void) {
  mAttribute_location.drop () ;
  mAttribute_value.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_36__34_List_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @uint64List-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_uint_36__34_List_2D_element::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_List_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @uint64List-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34_List_2D_element ("uint64List-element",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_uint_36__34_List_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_List_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_uint_36__34_List_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34_List_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List_2D_element GALGAS_uint_36__34_List_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_List_2D_element result ;
  const GALGAS_uint_36__34_List_2D_element * p = (const GALGAS_uint_36__34_List_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_36__34_List_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64List-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List_2D_element::GALGAS_sint_33__32_List_2D_element (void) :
mAttribute_location (),
mAttribute_value () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List_2D_element::~ GALGAS_sint_33__32_List_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List_2D_element::GALGAS_sint_33__32_List_2D_element (const GALGAS_location & inOperand0,
                                                                        const GALGAS_sint & inOperand1) :
mAttribute_location (inOperand0),
mAttribute_value (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List_2D_element GALGAS_sint_33__32_List_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint_33__32_List_2D_element (GALGAS_location::constructor_nowhere (HERE),
                                             GALGAS_sint::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List_2D_element GALGAS_sint_33__32_List_2D_element::constructor_new (const GALGAS_location & inOperand0,
                                                                                        const GALGAS_sint & inOperand1 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_33__32_List_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_sint_33__32_List_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_sint_33__32_List_2D_element::objectCompare (const GALGAS_sint_33__32_List_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_location.objectCompare (inOperand.mAttribute_location) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_value.objectCompare (inOperand.mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_sint_33__32_List_2D_element::isValid (void) const {
  return mAttribute_location.isValid () && mAttribute_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_33__32_List_2D_element::drop (void) {
  mAttribute_location.drop () ;
  mAttribute_value.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_33__32_List_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @sint32List-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_sint_33__32_List_2D_element::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint_33__32_List_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @sint32List-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_33__32_List_2D_element ("sint32List-element",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sint_33__32_List_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_List_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sint_33__32_List_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_33__32_List_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List_2D_element GALGAS_sint_33__32_List_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_List_2D_element result ;
  const GALGAS_sint_33__32_List_2D_element * p = (const GALGAS_sint_33__32_List_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_33__32_List_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint32List-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List_2D_element::GALGAS_sint_36__34_List_2D_element (void) :
mAttribute_location (),
mAttribute_value () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List_2D_element::~ GALGAS_sint_36__34_List_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List_2D_element::GALGAS_sint_36__34_List_2D_element (const GALGAS_location & inOperand0,
                                                                        const GALGAS_sint_36__34_ & inOperand1) :
mAttribute_location (inOperand0),
mAttribute_value (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List_2D_element GALGAS_sint_36__34_List_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint_36__34_List_2D_element (GALGAS_location::constructor_nowhere (HERE),
                                             GALGAS_sint_36__34_::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List_2D_element GALGAS_sint_36__34_List_2D_element::constructor_new (const GALGAS_location & inOperand0,
                                                                                        const GALGAS_sint_36__34_ & inOperand1 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_36__34_List_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_sint_36__34_List_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_sint_36__34_List_2D_element::objectCompare (const GALGAS_sint_36__34_List_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_location.objectCompare (inOperand.mAttribute_location) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_value.objectCompare (inOperand.mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_sint_36__34_List_2D_element::isValid (void) const {
  return mAttribute_location.isValid () && mAttribute_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_36__34_List_2D_element::drop (void) {
  mAttribute_location.drop () ;
  mAttribute_value.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_36__34_List_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @sint64List-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_sint_36__34_List_2D_element::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_List_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @sint64List-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_36__34_List_2D_element ("sint64List-element",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sint_36__34_List_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_List_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sint_36__34_List_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_36__34_List_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List_2D_element GALGAS_sint_36__34_List_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_List_2D_element result ;
  const GALGAS_sint_36__34_List_2D_element * p = (const GALGAS_sint_36__34_List_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_36__34_List_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint64List-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList_2D_element::GALGAS_floatList_2D_element (void) :
mAttribute_location (),
mAttribute_value () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList_2D_element::~ GALGAS_floatList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList_2D_element::GALGAS_floatList_2D_element (const GALGAS_location & inOperand0,
                                                          const GALGAS_double & inOperand1) :
mAttribute_location (inOperand0),
mAttribute_value (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList_2D_element GALGAS_floatList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_floatList_2D_element (GALGAS_location::constructor_nowhere (HERE),
                                      GALGAS_double::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList_2D_element GALGAS_floatList_2D_element::constructor_new (const GALGAS_location & inOperand0,
                                                                          const GALGAS_double & inOperand1 
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_floatList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_floatList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_floatList_2D_element::objectCompare (const GALGAS_floatList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_location.objectCompare (inOperand.mAttribute_location) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_value.objectCompare (inOperand.mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_floatList_2D_element::isValid (void) const {
  return mAttribute_location.isValid () && mAttribute_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_floatList_2D_element::drop (void) {
  mAttribute_location.drop () ;
  mAttribute_value.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_floatList_2D_element::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "<struct @floatList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_floatList_2D_element::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_floatList_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @floatList-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_floatList_2D_element ("floatList-element",
                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_floatList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_floatList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_floatList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList_2D_element GALGAS_floatList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_floatList_2D_element result ;
  const GALGAS_floatList_2D_element * p = (const GALGAS_floatList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_floatList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("floatList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList_2D_element::GALGAS_locationList_2D_element (void) :
mAttribute_location () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList_2D_element::~ GALGAS_locationList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList_2D_element::GALGAS_locationList_2D_element (const GALGAS_location & inOperand0) :
mAttribute_location (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList_2D_element GALGAS_locationList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_locationList_2D_element (GALGAS_location::constructor_nowhere (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList_2D_element GALGAS_locationList_2D_element::constructor_new (const GALGAS_location & inOperand0 
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_locationList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_locationList_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_locationList_2D_element::objectCompare (const GALGAS_locationList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_location.objectCompare (inOperand.mAttribute_location) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_locationList_2D_element::isValid (void) const {
  return mAttribute_location.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_locationList_2D_element::drop (void) {
  mAttribute_location.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_locationList_2D_element::description (C_String & ioString,
                                                  const int32_t inIndentation) const {
  ioString << "<struct @locationList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_location.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_locationList_2D_element::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @locationList-element type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_locationList_2D_element ("locationList-element",
                                                NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_locationList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_locationList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_locationList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_locationList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList_2D_element GALGAS_locationList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_locationList_2D_element result ;
  const GALGAS_locationList_2D_element * p = (const GALGAS_locationList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_locationList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("locationList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension method '@gtlTemplate execute'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlTemplate_execute> gExtensionMethodTable_gtlTemplate_execute ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_execute (const int32_t inClassIndex,
                                   extensionMethodSignature_gtlTemplate_execute inMethod) {
  gExtensionMethodTable_gtlTemplate_execute.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_execute (const cPtr_gtlTemplate * inObject,
                                  GALGAS_gtlContext & io_context,
                                  GALGAS_gtlData & io_vars,
                                  GALGAS_library & io_lib,
                                  GALGAS_string & io_outputString,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlTemplate) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlTemplate_execute f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlTemplate_execute.count ()) {
      f = gExtensionMethodTable_gtlTemplate_execute (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlTemplate_execute.count ()) {
           f = gExtensionMethodTable_gtlTemplate_execute (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlTemplate_execute.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_context, io_vars, io_lib, io_outputString, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlTemplate_execute (const cPtr_gtlTemplate * inObject,
                                                 GALGAS_gtlContext & ioArgument_context,
                                                 GALGAS_gtlData & ioArgument_vars,
                                                 GALGAS_library & ioArgument_lib,
                                                 GALGAS_string & ioArgument_outputString,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlTemplate * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlTemplate) ;
  extensionMethod_execute (object->mAttribute_program, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 210)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlTemplate_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlTemplate.mSlotID,
                                extensionMethod_gtlTemplate_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlTemplate_execute (void) {
  gExtensionMethodTable_gtlTemplate_execute.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlTemplate_execute (defineExtensionMethod_gtlTemplate_execute,
                                                freeExtensionMethod_gtlTemplate_execute) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@library functionExists'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_library_functionExists> gExtensionGetterTable_library_functionExists ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_functionExists (const int32_t inClassIndex,
                                          enterExtensionGetter_library_functionExists inGetter) {
  gExtensionGetterTable_library_functionExists.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_functionExists (const cPtr_library * inObject,
                                                const GALGAS_lstring & in_name,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_library_functionExists f = NULL ;
    if (classIndex < gExtensionGetterTable_library_functionExists.count ()) {
      f = gExtensionGetterTable_library_functionExists (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_library_functionExists.count ()) {
           f = gExtensionGetterTable_library_functionExists (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_library_functionExists.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_library_functionExists (const cPtr_library * inObject,
                                                           const GALGAS_lstring & constinArgument_name,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_exists ; // Returned variable
  const cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  result_exists = object->mAttribute_funcMap.getter_hasKey (constinArgument_name.getter_string (SOURCE_FILE ("gtl_types.galgas", 271)) COMMA_SOURCE_FILE ("gtl_types.galgas", 271)) ;
//---
  return result_exists ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_library_functionExists (void) {
  enterExtensionGetter_functionExists (kTypeDescriptor_GALGAS_library.mSlotID,
                                       extensionGetter_library_functionExists) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_library_functionExists (void) {
  gExtensionGetterTable_library_functionExists.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_library_functionExists (defineExtensionGetter_library_functionExists,
                                                   freeExtensionGetter_library_functionExists) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@library getFunction'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_library_getFunction> gExtensionGetterTable_library_getFunction ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_getFunction (const int32_t inClassIndex,
                                       enterExtensionGetter_library_getFunction inGetter) {
  gExtensionGetterTable_library_getFunction.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunction callExtensionGetter_getFunction (const cPtr_library * inObject,
                                                    const GALGAS_lstring & in_name,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlFunction result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_library_getFunction f = NULL ;
    if (classIndex < gExtensionGetterTable_library_getFunction.count ()) {
      f = gExtensionGetterTable_library_getFunction (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_library_getFunction.count ()) {
           f = gExtensionGetterTable_library_getFunction (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_library_getFunction.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlFunction extensionGetter_library_getFunction (const cPtr_library * inObject,
                                                               const GALGAS_lstring & constinArgument_name,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlFunction result_aFunction ; // Returned variable
  const cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  object->mAttribute_funcMap.method_get (constinArgument_name, result_aFunction, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 278)) ;
//---
  return result_aFunction ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_library_getFunction (void) {
  enterExtensionGetter_getFunction (kTypeDescriptor_GALGAS_library.mSlotID,
                                    extensionGetter_library_getFunction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_library_getFunction (void) {
  gExtensionGetterTable_library_getFunction.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_library_getFunction (defineExtensionGetter_library_getFunction,
                                                freeExtensionGetter_library_getFunction) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension setter '@library putFunction'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_library_putFunction> gExtensionModifierTable_library_putFunction ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_putFunction (const int32_t inClassIndex,
                                       extensionSetterSignature_library_putFunction inModifier) {
  gExtensionModifierTable_library_putFunction.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_putFunction (cPtr_library * inObject,
                                      const GALGAS_lstring constin_name,
                                      const GALGAS_gtlFunction constin_aFunction,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_library_putFunction f = NULL ;
    if (classIndex < gExtensionModifierTable_library_putFunction.count ()) {
      f = gExtensionModifierTable_library_putFunction (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_library_putFunction.count ()) {
           f = gExtensionModifierTable_library_putFunction (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_library_putFunction.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_aFunction, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_library_putFunction (cPtr_library * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 const GALGAS_gtlFunction constinArgument_aFunction,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  {
  object->mAttribute_funcMap.setter_put (constinArgument_name, constinArgument_aFunction, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 285)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_library_putFunction (void) {
  enterExtensionSetter_putFunction (kTypeDescriptor_GALGAS_library.mSlotID,
                                    extensionSetter_library_putFunction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_library_putFunction (void) {
  gExtensionModifierTable_library_putFunction.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_library_putFunction (defineExtensionSetter_library_putFunction,
                                                freeExtensionModifier_library_putFunction) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension getter '@library getterExists'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_library_getterExists> gExtensionGetterTable_library_getterExists ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_getterExists (const int32_t inClassIndex,
                                        enterExtensionGetter_library_getterExists inGetter) {
  gExtensionGetterTable_library_getterExists.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_getterExists (const cPtr_library * inObject,
                                              const GALGAS_string & in_type,
                                              const GALGAS_lstring & in_name,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_library_getterExists f = NULL ;
    if (classIndex < gExtensionGetterTable_library_getterExists.count ()) {
      f = gExtensionGetterTable_library_getterExists (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_library_getterExists.count ()) {
           f = gExtensionGetterTable_library_getterExists (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_library_getterExists.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_type, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_library_getterExists (const cPtr_library * inObject,
                                                         const GALGAS_string & constinArgument_type,
                                                         const GALGAS_lstring & constinArgument_name,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_exists ; // Returned variable
  const cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  result_exists = object->mAttribute_getterMap.getter_hasKey (constinArgument_type.add_operation (constinArgument_name.getter_string (SOURCE_FILE ("gtl_types.galgas", 293)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 293)) COMMA_SOURCE_FILE ("gtl_types.galgas", 293)) ;
//---
  return result_exists ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_library_getterExists (void) {
  enterExtensionGetter_getterExists (kTypeDescriptor_GALGAS_library.mSlotID,
                                     extensionGetter_library_getterExists) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_library_getterExists (void) {
  gExtensionGetterTable_library_getterExists.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_library_getterExists (defineExtensionGetter_library_getterExists,
                                                 freeExtensionGetter_library_getterExists) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension getter '@library getGetter'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_library_getGetter> gExtensionGetterTable_library_getGetter ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_getGetter (const int32_t inClassIndex,
                                     enterExtensionGetter_library_getGetter inGetter) {
  gExtensionGetterTable_library_getGetter.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetter callExtensionGetter_getGetter (const cPtr_library * inObject,
                                                const GALGAS_string & in_type,
                                                const GALGAS_lstring & in_name,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetter result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_library_getGetter f = NULL ;
    if (classIndex < gExtensionGetterTable_library_getGetter.count ()) {
      f = gExtensionGetterTable_library_getGetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_library_getGetter.count ()) {
           f = gExtensionGetterTable_library_getGetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_library_getGetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_type, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlGetter extensionGetter_library_getGetter (const cPtr_library * inObject,
                                                           const GALGAS_string & constinArgument_type,
                                                           const GALGAS_lstring & constinArgument_name,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlGetter result_aGetter ; // Returned variable
  const cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  object->mAttribute_getterMap.method_get (GALGAS_lstring::constructor_new (constinArgument_type.add_operation (constinArgument_name.getter_string (SOURCE_FILE ("gtl_types.galgas", 301)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 301)), constinArgument_name.getter_location (SOURCE_FILE ("gtl_types.galgas", 301))  COMMA_SOURCE_FILE ("gtl_types.galgas", 301)), result_aGetter, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 301)) ;
//---
  return result_aGetter ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_library_getGetter (void) {
  enterExtensionGetter_getGetter (kTypeDescriptor_GALGAS_library.mSlotID,
                                  extensionGetter_library_getGetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_library_getGetter (void) {
  gExtensionGetterTable_library_getGetter.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_library_getGetter (defineExtensionGetter_library_getGetter,
                                              freeExtensionGetter_library_getGetter) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension setter '@library putGetter'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_library_putGetter> gExtensionModifierTable_library_putGetter ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_putGetter (const int32_t inClassIndex,
                                     extensionSetterSignature_library_putGetter inModifier) {
  gExtensionModifierTable_library_putGetter.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_putGetter (cPtr_library * inObject,
                                    const GALGAS_lstring constin_name,
                                    const GALGAS_gtlGetter constin_aGetter,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_library_putGetter f = NULL ;
    if (classIndex < gExtensionModifierTable_library_putGetter.count ()) {
      f = gExtensionModifierTable_library_putGetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_library_putGetter.count ()) {
           f = gExtensionModifierTable_library_putGetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_library_putGetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_aGetter, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_library_putGetter (cPtr_library * inObject,
                                               const GALGAS_lstring constinArgument_name,
                                               const GALGAS_gtlGetter constinArgument_aGetter,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  {
  object->mAttribute_getterMap.setter_put (constinArgument_name, constinArgument_aGetter, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 308)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_library_putGetter (void) {
  enterExtensionSetter_putGetter (kTypeDescriptor_GALGAS_library.mSlotID,
                                  extensionSetter_library_putGetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_library_putGetter (void) {
  gExtensionModifierTable_library_putGetter.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_library_putGetter (defineExtensionSetter_library_putGetter,
                                              freeExtensionModifier_library_putGetter) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension getter '@library setterExists'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_library_setterExists> gExtensionGetterTable_library_setterExists ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_setterExists (const int32_t inClassIndex,
                                        enterExtensionGetter_library_setterExists inGetter) {
  gExtensionGetterTable_library_setterExists.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_setterExists (const cPtr_library * inObject,
                                              const GALGAS_string & in_type,
                                              const GALGAS_lstring & in_name,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_library_setterExists f = NULL ;
    if (classIndex < gExtensionGetterTable_library_setterExists.count ()) {
      f = gExtensionGetterTable_library_setterExists (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_library_setterExists.count ()) {
           f = gExtensionGetterTable_library_setterExists (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_library_setterExists.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_type, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_library_setterExists (const cPtr_library * inObject,
                                                         const GALGAS_string & constinArgument_type,
                                                         const GALGAS_lstring & constinArgument_name,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_exists ; // Returned variable
  const cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  result_exists = object->mAttribute_setterMap.getter_hasKey (constinArgument_type.add_operation (constinArgument_name.getter_string (SOURCE_FILE ("gtl_types.galgas", 316)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 316)) COMMA_SOURCE_FILE ("gtl_types.galgas", 316)) ;
//---
  return result_exists ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_library_setterExists (void) {
  enterExtensionGetter_setterExists (kTypeDescriptor_GALGAS_library.mSlotID,
                                     extensionGetter_library_setterExists) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_library_setterExists (void) {
  gExtensionGetterTable_library_setterExists.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_library_setterExists (defineExtensionGetter_library_setterExists,
                                                 freeExtensionGetter_library_setterExists) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension getter '@library getSetter'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_library_getSetter> gExtensionGetterTable_library_getSetter ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_getSetter (const int32_t inClassIndex,
                                     enterExtensionGetter_library_getSetter inGetter) {
  gExtensionGetterTable_library_getSetter.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetter callExtensionGetter_getSetter (const cPtr_library * inObject,
                                                const GALGAS_string & in_type,
                                                const GALGAS_lstring & in_name,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlSetter result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_library_getSetter f = NULL ;
    if (classIndex < gExtensionGetterTable_library_getSetter.count ()) {
      f = gExtensionGetterTable_library_getSetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_library_getSetter.count ()) {
           f = gExtensionGetterTable_library_getSetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_library_getSetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_type, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlSetter extensionGetter_library_getSetter (const cPtr_library * inObject,
                                                           const GALGAS_string & constinArgument_type,
                                                           const GALGAS_lstring & constinArgument_name,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlSetter result_aSetter ; // Returned variable
  const cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  object->mAttribute_setterMap.method_get (GALGAS_lstring::constructor_new (constinArgument_type.add_operation (constinArgument_name.getter_string (SOURCE_FILE ("gtl_types.galgas", 324)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 324)), constinArgument_name.getter_location (SOURCE_FILE ("gtl_types.galgas", 324))  COMMA_SOURCE_FILE ("gtl_types.galgas", 324)), result_aSetter, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 324)) ;
//---
  return result_aSetter ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_library_getSetter (void) {
  enterExtensionGetter_getSetter (kTypeDescriptor_GALGAS_library.mSlotID,
                                  extensionGetter_library_getSetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_library_getSetter (void) {
  gExtensionGetterTable_library_getSetter.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_library_getSetter (defineExtensionGetter_library_getSetter,
                                              freeExtensionGetter_library_getSetter) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension setter '@library putSetter'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_library_putSetter> gExtensionModifierTable_library_putSetter ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_putSetter (const int32_t inClassIndex,
                                     extensionSetterSignature_library_putSetter inModifier) {
  gExtensionModifierTable_library_putSetter.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_putSetter (cPtr_library * inObject,
                                    const GALGAS_lstring constin_name,
                                    const GALGAS_gtlSetter constin_aSetter,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_library_putSetter f = NULL ;
    if (classIndex < gExtensionModifierTable_library_putSetter.count ()) {
      f = gExtensionModifierTable_library_putSetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_library_putSetter.count ()) {
           f = gExtensionModifierTable_library_putSetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_library_putSetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_aSetter, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_library_putSetter (cPtr_library * inObject,
                                               const GALGAS_lstring constinArgument_name,
                                               const GALGAS_gtlSetter constinArgument_aSetter,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  {
  object->mAttribute_setterMap.setter_put (constinArgument_name, constinArgument_aSetter, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 331)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_library_putSetter (void) {
  enterExtensionSetter_putSetter (kTypeDescriptor_GALGAS_library.mSlotID,
                                  extensionSetter_library_putSetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_library_putSetter (void) {
  gExtensionModifierTable_library_putSetter.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_library_putSetter (defineExtensionSetter_library_putSetter,
                                              freeExtensionModifier_library_putSetter) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension getter '@library hasImport'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_library_hasImport> gExtensionGetterTable_library_hasImport ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasImport (const int32_t inClassIndex,
                                     enterExtensionGetter_library_hasImport inGetter) {
  gExtensionGetterTable_library_hasImport.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_hasImport (const cPtr_library * inObject,
                                           const GALGAS_string & in_importPath,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_library_hasImport f = NULL ;
    if (classIndex < gExtensionGetterTable_library_hasImport.count ()) {
      f = gExtensionGetterTable_library_hasImport (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_library_hasImport.count ()) {
           f = gExtensionGetterTable_library_hasImport (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_library_hasImport.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_importPath, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_library_hasImport (const cPtr_library * inObject,
                                                      const GALGAS_string & constinArgument_importPath,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  result_result = object->mAttribute_doneImports.getter_hasKey (constinArgument_importPath COMMA_SOURCE_FILE ("gtl_types.galgas", 338)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_library_hasImport (void) {
  enterExtensionGetter_hasImport (kTypeDescriptor_GALGAS_library.mSlotID,
                                  extensionGetter_library_hasImport) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_library_hasImport (void) {
  gExtensionGetterTable_library_hasImport.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_library_hasImport (defineExtensionGetter_library_hasImport,
                                              freeExtensionGetter_library_hasImport) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension setter '@library doImport'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_library_doImport> gExtensionModifierTable_library_doImport ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_doImport (const int32_t inClassIndex,
                                    extensionSetterSignature_library_doImport inModifier) {
  gExtensionModifierTable_library_doImport.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_doImport (cPtr_library * inObject,
                                   const GALGAS_string constin_importPath,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_library_doImport f = NULL ;
    if (classIndex < gExtensionModifierTable_library_doImport.count ()) {
      f = gExtensionModifierTable_library_doImport (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_library_doImport.count ()) {
           f = gExtensionModifierTable_library_doImport (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_library_doImport.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_importPath, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_library_doImport (cPtr_library * inObject,
                                              const GALGAS_string constinArgument_importPath,
                                              C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  object->mAttribute_doneImports.addAssign_operation (constinArgument_importPath  COMMA_SOURCE_FILE ("gtl_types.galgas", 344)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_library_doImport (void) {
  enterExtensionSetter_doImport (kTypeDescriptor_GALGAS_library.mSlotID,
                                 extensionSetter_library_doImport) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_library_doImport (void) {
  gExtensionModifierTable_library_doImport.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_library_doImport (defineExtensionSetter_library_doImport,
                                             freeExtensionModifier_library_doImport) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension setter '@library getTemplate'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_library_getTemplate> gExtensionModifierTable_library_getTemplate ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_getTemplate (const int32_t inClassIndex,
                                       extensionSetterSignature_library_getTemplate inModifier) {
  gExtensionModifierTable_library_getTemplate.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_getTemplate (cPtr_library * inObject,
                                      const GALGAS_gtlContext constin_context,
                                      GALGAS_lstring in_path,
                                      GALGAS_bool in_ifExists,
                                      GALGAS_library & io_lib,
                                      GALGAS_bool & out_found,
                                      GALGAS_gtlTemplate & out_result,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
//--- Drop output arguments
  out_found.drop () ;
  out_result.drop () ;
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_library_getTemplate f = NULL ;
    if (classIndex < gExtensionModifierTable_library_getTemplate.count ()) {
      f = gExtensionModifierTable_library_getTemplate (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_library_getTemplate.count ()) {
           f = gExtensionModifierTable_library_getTemplate (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_library_getTemplate.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_context, in_path, in_ifExists, io_lib, out_found, out_result, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_library_getTemplate (cPtr_library * inObject,
                                                 const GALGAS_gtlContext constinArgument_context,
                                                 GALGAS_lstring inArgument_path,
                                                 GALGAS_bool inArgument_ifExists,
                                                 GALGAS_library & ioArgument_lib,
                                                 GALGAS_bool & outArgument_found,
                                                 GALGAS_gtlTemplate & outArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  {
  extensionSetter_getTemplate (object->mAttribute_templateMap, constinArgument_context, inArgument_path, inArgument_ifExists, ioArgument_lib, outArgument_found, outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 356)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_library_getTemplate (void) {
  enterExtensionSetter_getTemplate (kTypeDescriptor_GALGAS_library.mSlotID,
                                    extensionSetter_library_getTemplate) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_library_getTemplate (void) {
  gExtensionModifierTable_library_getTemplate.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_library_getTemplate (defineExtensionSetter_library_getTemplate,
                                                freeExtensionModifier_library_getTemplate) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension getter '@gtlVarItemField lstringPath'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlVarItemField_lstringPath> gExtensionGetterTable_gtlVarItemField_lstringPath ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_lstringPath (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlVarItemField_lstringPath inGetter) {
  gExtensionGetterTable_gtlVarItemField_lstringPath.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring callExtensionGetter_lstringPath (const cPtr_gtlVarItemField * inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlVarItemField) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlVarItemField_lstringPath f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlVarItemField_lstringPath.count ()) {
      f = gExtensionGetterTable_gtlVarItemField_lstringPath (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlVarItemField_lstringPath.count ()) {
           f = gExtensionGetterTable_gtlVarItemField_lstringPath (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlVarItemField_lstringPath.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_lstring extensionGetter_gtlVarItemField_lstringPath (const cPtr_gtlVarItemField * inObject,
                                                                   C_Compiler * /* inCompiler */
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlVarItemField * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemField) ;
  result_result = object->mAttribute_field ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarItemField_lstringPath (void) {
  enterExtensionGetter_lstringPath (kTypeDescriptor_GALGAS_gtlVarItemField.mSlotID,
                                    extensionGetter_gtlVarItemField_lstringPath) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlVarItemField_lstringPath (void) {
  gExtensionGetterTable_gtlVarItemField_lstringPath.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItemField_lstringPath (defineExtensionGetter_gtlVarItemField_lstringPath,
                                                        freeExtensionGetter_gtlVarItemField_lstringPath) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlExpression location'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlExpression_location> gExtensionGetterTable_gtlExpression_location ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_location (const int32_t inClassIndex,
                                    enterExtensionGetter_gtlExpression_location inGetter) {
  gExtensionGetterTable_gtlExpression_location.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location callExtensionGetter_location (const cPtr_gtlExpression * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_location result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlExpression) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlExpression_location f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlExpression_location.count ()) {
      f = gExtensionGetterTable_gtlExpression_location (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlExpression_location.count ()) {
           f = gExtensionGetterTable_gtlExpression_location (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlExpression_location.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_location extensionGetter_gtlExpression_location (const cPtr_gtlExpression * inObject,
                                                               C_Compiler * /* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location result_result ; // Returned variable
  const cPtr_gtlExpression * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlExpression) ;
  result_result = object->mAttribute_where ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlExpression_location (void) {
  enterExtensionGetter_location (kTypeDescriptor_GALGAS_gtlExpression.mSlotID,
                                 extensionGetter_gtlExpression_location) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlExpression_location (void) {
  gExtensionGetterTable_gtlExpression_location.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlExpression_location (defineExtensionGetter_gtlExpression_location,
                                                   freeExtensionGetter_gtlExpression_location) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Abstract extension getter '@gtlExpression eval'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlExpression_eval> gExtensionGetterTable_gtlExpression_eval ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_eval (const int32_t inClassIndex,
                                enterExtensionGetter_gtlExpression_eval inGetter) {
  gExtensionGetterTable_gtlExpression_eval.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlExpression_eval (void) {
  gExtensionGetterTable_gtlExpression_eval.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlExpression_eval (NULL,
                                               freeExtensionGetter_gtlExpression_eval) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_eval (const cPtr_gtlExpression * inObject,
                                         const GALGAS_gtlData & in_vars,
                                         const GALGAS_library & in_lib,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlExpression) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlExpression_eval f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlExpression_eval.count ()) {
      f = gExtensionGetterTable_gtlExpression_eval (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlExpression_eval.count ()) {
           f = gExtensionGetterTable_gtlExpression_eval (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlExpression_eval.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                          Extension Getter '@type typeName'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_typeName (const GALGAS_type & inObject,
                                        C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_typeName ; // Returned variable
  const GALGAS_type temp_0 = inObject ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, temp_0.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt))).boolEnum () ;
  if (kBoolTrue == test_1) {
    result_typeName = GALGAS_string ("int") ;
  }else if (kBoolFalse == test_1) {
    const GALGAS_type temp_2 = inObject ;
    const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, temp_2.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar))).boolEnum () ;
    if (kBoolTrue == test_3) {
      result_typeName = GALGAS_string ("char") ;
    }else if (kBoolFalse == test_3) {
      const GALGAS_type temp_4 = inObject ;
      const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, temp_4.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlFloat))).boolEnum () ;
      if (kBoolTrue == test_5) {
        result_typeName = GALGAS_string ("float") ;
      }else if (kBoolFalse == test_5) {
        const GALGAS_type temp_6 = inObject ;
        const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, temp_6.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlString))).boolEnum () ;
        if (kBoolTrue == test_7) {
          result_typeName = GALGAS_string ("string") ;
        }else if (kBoolFalse == test_7) {
          const GALGAS_type temp_8 = inObject ;
          const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, temp_8.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool))).boolEnum () ;
          if (kBoolTrue == test_9) {
            result_typeName = GALGAS_string ("bool") ;
          }else if (kBoolFalse == test_9) {
            const GALGAS_type temp_10 = inObject ;
            const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, temp_10.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct))).boolEnum () ;
            if (kBoolTrue == test_11) {
              result_typeName = GALGAS_string ("struct") ;
            }else if (kBoolFalse == test_11) {
              const GALGAS_type temp_12 = inObject ;
              const enumGalgasBool test_13 = GALGAS_bool (kIsEqual, temp_12.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlList))).boolEnum () ;
              if (kBoolTrue == test_13) {
                result_typeName = GALGAS_string ("list") ;
              }else if (kBoolFalse == test_13) {
                const GALGAS_type temp_14 = inObject ;
                const enumGalgasBool test_15 = GALGAS_bool (kIsEqual, temp_14.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlMap))).boolEnum () ;
                if (kBoolTrue == test_15) {
                  result_typeName = GALGAS_string ("map") ;
                }else if (kBoolFalse == test_15) {
                  const GALGAS_type temp_16 = inObject ;
                  const enumGalgasBool test_17 = GALGAS_bool (kIsEqual, temp_16.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlType))).boolEnum () ;
                  if (kBoolTrue == test_17) {
                    result_typeName = GALGAS_string ("type") ;
                  }else if (kBoolFalse == test_17) {
                    const GALGAS_type temp_18 = inObject ;
                    const enumGalgasBool test_19 = GALGAS_bool (kIsEqual, temp_18.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlEnum))).boolEnum () ;
                    if (kBoolTrue == test_19) {
                      result_typeName = GALGAS_string ("enum") ;
                    }else if (kBoolFalse == test_19) {
                      const GALGAS_type temp_20 = inObject ;
                      const enumGalgasBool test_21 = GALGAS_bool (kIsEqual, temp_20.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlSet))).boolEnum () ;
                      if (kBoolTrue == test_21) {
                        result_typeName = GALGAS_string ("set") ;
                      }else if (kBoolFalse == test_21) {
                        const GALGAS_type temp_22 = inObject ;
                        const enumGalgasBool test_23 = GALGAS_bool (kIsEqual, temp_22.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlUnconstructed))).boolEnum () ;
                        if (kBoolTrue == test_23) {
                          result_typeName = GALGAS_string ("unconstructed") ;
                        }else if (kBoolFalse == test_23) {
                          result_typeName = GALGAS_string ("-unknown-") ;
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
  return result_typeName ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Extension Getter '@lstring gtlType'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type extensionGetter_gtlType (const GALGAS_lstring & inObject,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_type ; // Returned variable
  const GALGAS_lstring temp_0 = inObject ;
  GALGAS_string var_typeName_2294 = temp_0.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 67)) ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("int"))).boolEnum () ;
  if (kBoolTrue == test_1) {
    result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt) ;
  }else if (kBoolFalse == test_1) {
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("char"))).boolEnum () ;
    if (kBoolTrue == test_2) {
      result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar) ;
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("float"))).boolEnum () ;
      if (kBoolTrue == test_3) {
        result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlFloat) ;
      }else if (kBoolFalse == test_3) {
        const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("string"))).boolEnum () ;
        if (kBoolTrue == test_4) {
          result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlString) ;
        }else if (kBoolFalse == test_4) {
          const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("bool"))).boolEnum () ;
          if (kBoolTrue == test_5) {
            result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool) ;
          }else if (kBoolFalse == test_5) {
            const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("struct"))).boolEnum () ;
            if (kBoolTrue == test_6) {
              result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct) ;
            }else if (kBoolFalse == test_6) {
              const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("list"))).boolEnum () ;
              if (kBoolTrue == test_7) {
                result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlList) ;
              }else if (kBoolFalse == test_7) {
                const enumGalgasBool test_8 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("map"))).boolEnum () ;
                if (kBoolTrue == test_8) {
                  result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlMap) ;
                }else if (kBoolFalse == test_8) {
                  const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("type"))).boolEnum () ;
                  if (kBoolTrue == test_9) {
                    result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlType) ;
                  }else if (kBoolFalse == test_9) {
                    const enumGalgasBool test_10 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("enum"))).boolEnum () ;
                    if (kBoolTrue == test_10) {
                      result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlEnum) ;
                    }else if (kBoolFalse == test_10) {
                      const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("set"))).boolEnum () ;
                      if (kBoolTrue == test_11) {
                        result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlSet) ;
                      }else if (kBoolFalse == test_11) {
                        const enumGalgasBool test_12 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("unconstructed"))).boolEnum () ;
                        if (kBoolTrue == test_12) {
                          result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlUnconstructed) ;
                        }else if (kBoolFalse == test_12) {
                          TC_Array <C_FixItDescription> fixItArray13 ;
                          inCompiler->emitSemanticError (inObject.mAttribute_location, GALGAS_string ("unknown type"), fixItArray13  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 80)) ;
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
//                                        Extension getter '@gtlData location'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_location> gExtensionGetterTable_gtlData_location ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_location (const int32_t inClassIndex,
                                    enterExtensionGetter_gtlData_location inGetter) {
  gExtensionGetterTable_gtlData_location.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location callExtensionGetter_location (const cPtr_gtlData * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_location result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_location f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_location.count ()) {
      f = gExtensionGetterTable_gtlData_location (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_location.count ()) {
           f = gExtensionGetterTable_gtlData_location (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_location.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_location extensionGetter_gtlData_location (const cPtr_gtlData * inObject,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location result_result ; // Returned variable
  const cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  result_result = object->mAttribute_where ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlData_location (void) {
  enterExtensionGetter_location (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                 extensionGetter_gtlData_location) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_location (void) {
  gExtensionGetterTable_gtlData_location.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_location (defineExtensionGetter_gtlData_location,
                                             freeExtensionGetter_gtlData_location) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData desc'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_desc> gExtensionGetterTable_gtlData_desc ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_desc (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_desc inGetter) {
  gExtensionGetterTable_gtlData_desc.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_desc (void) {
  gExtensionGetterTable_gtlData_desc.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_desc (NULL,
                                         freeExtensionGetter_gtlData_desc) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string callExtensionGetter_desc (const cPtr_gtlData * inObject,
                                        const GALGAS_uint & in_tab,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_desc f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_desc.count ()) {
      f = gExtensionGetterTable_gtlData_desc (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_desc.count ()) {
           f = gExtensionGetterTable_gtlData_desc (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_desc.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_tab, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData string'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_string> gExtensionGetterTable_gtlData_string ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_string (const int32_t inClassIndex,
                                  enterExtensionGetter_gtlData_string inGetter) {
  gExtensionGetterTable_gtlData_string.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_string (void) {
  gExtensionGetterTable_gtlData_string.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_string (NULL,
                                           freeExtensionGetter_gtlData_string) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string callExtensionGetter_string (const cPtr_gtlData * inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_string f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_string.count ()) {
      f = gExtensionGetterTable_gtlData_string (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_string.count ()) {
           f = gExtensionGetterTable_gtlData_string (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_string.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                    Abstract extension getter '@gtlData lstring'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_lstring> gExtensionGetterTable_gtlData_lstring ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_lstring (const int32_t inClassIndex,
                                   enterExtensionGetter_gtlData_lstring inGetter) {
  gExtensionGetterTable_gtlData_lstring.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_lstring (void) {
  gExtensionGetterTable_gtlData_lstring.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_lstring (NULL,
                                            freeExtensionGetter_gtlData_lstring) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring callExtensionGetter_lstring (const cPtr_gtlData * inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_lstring f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_lstring.count ()) {
      f = gExtensionGetterTable_gtlData_lstring (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_lstring.count ()) {
           f = gExtensionGetterTable_gtlData_lstring (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_lstring.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                      Abstract extension getter '@gtlData bool'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_bool> gExtensionGetterTable_gtlData_bool ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_bool (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_bool inGetter) {
  gExtensionGetterTable_gtlData_bool.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_bool (void) {
  gExtensionGetterTable_gtlData_bool.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_bool (NULL,
                                         freeExtensionGetter_gtlData_bool) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_bool (const cPtr_gtlData * inObject,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_bool f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_bool.count ()) {
      f = gExtensionGetterTable_gtlData_bool (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_bool.count ()) {
           f = gExtensionGetterTable_gtlData_bool (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_bool.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                      Abstract extension getter '@gtlData int'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_int> gExtensionGetterTable_gtlData_int ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_int (const int32_t inClassIndex,
                               enterExtensionGetter_gtlData_int inGetter) {
  gExtensionGetterTable_gtlData_int.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_int (void) {
  gExtensionGetterTable_gtlData_int.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_int (NULL,
                                        freeExtensionGetter_gtlData_int) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint callExtensionGetter_int (const cPtr_gtlData * inObject,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  GALGAS_bigint result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_int f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_int.count ()) {
      f = gExtensionGetterTable_gtlData_int (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_int.count ()) {
           f = gExtensionGetterTable_gtlData_int (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_int.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                     Abstract extension getter '@gtlData float'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_float> gExtensionGetterTable_gtlData_float ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_float (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_float inGetter) {
  gExtensionGetterTable_gtlData_float.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_float (void) {
  gExtensionGetterTable_gtlData_float.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_float (NULL,
                                          freeExtensionGetter_gtlData_float) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double callExtensionGetter_float (const cPtr_gtlData * inObject,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_double result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_float f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_float.count ()) {
      f = gExtensionGetterTable_gtlData_float (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_float.count ()) {
           f = gExtensionGetterTable_gtlData_float (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_float.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                     Abstract extension getter '@gtlData plusOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_plusOp> gExtensionGetterTable_gtlData_plusOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_plusOp (const int32_t inClassIndex,
                                  enterExtensionGetter_gtlData_plusOp inGetter) {
  gExtensionGetterTable_gtlData_plusOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_plusOp (void) {
  gExtensionGetterTable_gtlData_plusOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_plusOp (NULL,
                                           freeExtensionGetter_gtlData_plusOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_plusOp (const cPtr_gtlData * inObject,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_plusOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_plusOp.count ()) {
      f = gExtensionGetterTable_gtlData_plusOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_plusOp.count ()) {
           f = gExtensionGetterTable_gtlData_plusOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_plusOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                    Abstract extension getter '@gtlData minusOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_minusOp> gExtensionGetterTable_gtlData_minusOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_minusOp (const int32_t inClassIndex,
                                   enterExtensionGetter_gtlData_minusOp inGetter) {
  gExtensionGetterTable_gtlData_minusOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_minusOp (void) {
  gExtensionGetterTable_gtlData_minusOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_minusOp (NULL,
                                            freeExtensionGetter_gtlData_minusOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_minusOp (const cPtr_gtlData * inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_minusOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_minusOp.count ()) {
      f = gExtensionGetterTable_gtlData_minusOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_minusOp.count ()) {
           f = gExtensionGetterTable_gtlData_minusOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_minusOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                     Abstract extension getter '@gtlData notOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_notOp> gExtensionGetterTable_gtlData_notOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_notOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_notOp inGetter) {
  gExtensionGetterTable_gtlData_notOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_notOp (void) {
  gExtensionGetterTable_gtlData_notOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_notOp (NULL,
                                          freeExtensionGetter_gtlData_notOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_notOp (const cPtr_gtlData * inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_notOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_notOp.count ()) {
      f = gExtensionGetterTable_gtlData_notOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_notOp.count ()) {
           f = gExtensionGetterTable_gtlData_notOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_notOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                     Abstract extension getter '@gtlData addOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_addOp> gExtensionGetterTable_gtlData_addOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_addOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_addOp inGetter) {
  gExtensionGetterTable_gtlData_addOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_addOp (void) {
  gExtensionGetterTable_gtlData_addOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_addOp (NULL,
                                          freeExtensionGetter_gtlData_addOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_addOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData & in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_addOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_addOp.count ()) {
      f = gExtensionGetterTable_gtlData_addOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_addOp.count ()) {
           f = gExtensionGetterTable_gtlData_addOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_addOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData subOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_subOp> gExtensionGetterTable_gtlData_subOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_subOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_subOp inGetter) {
  gExtensionGetterTable_gtlData_subOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_subOp (void) {
  gExtensionGetterTable_gtlData_subOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_subOp (NULL,
                                          freeExtensionGetter_gtlData_subOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_subOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData & in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_subOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_subOp.count ()) {
      f = gExtensionGetterTable_gtlData_subOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_subOp.count ()) {
           f = gExtensionGetterTable_gtlData_subOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_subOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData mulOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_mulOp> gExtensionGetterTable_gtlData_mulOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_mulOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_mulOp inGetter) {
  gExtensionGetterTable_gtlData_mulOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_mulOp (void) {
  gExtensionGetterTable_gtlData_mulOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_mulOp (NULL,
                                          freeExtensionGetter_gtlData_mulOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_mulOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData & in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_mulOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_mulOp.count ()) {
      f = gExtensionGetterTable_gtlData_mulOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_mulOp.count ()) {
           f = gExtensionGetterTable_gtlData_mulOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_mulOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData divOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_divOp> gExtensionGetterTable_gtlData_divOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_divOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_divOp inGetter) {
  gExtensionGetterTable_gtlData_divOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_divOp (void) {
  gExtensionGetterTable_gtlData_divOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_divOp (NULL,
                                          freeExtensionGetter_gtlData_divOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_divOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData & in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_divOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_divOp.count ()) {
      f = gExtensionGetterTable_gtlData_divOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_divOp.count ()) {
           f = gExtensionGetterTable_gtlData_divOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_divOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData modOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_modOp> gExtensionGetterTable_gtlData_modOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_modOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_modOp inGetter) {
  gExtensionGetterTable_gtlData_modOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_modOp (void) {
  gExtensionGetterTable_gtlData_modOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_modOp (NULL,
                                          freeExtensionGetter_gtlData_modOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_modOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData & in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_modOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_modOp.count ()) {
      f = gExtensionGetterTable_gtlData_modOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_modOp.count ()) {
           f = gExtensionGetterTable_gtlData_modOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_modOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData andOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_andOp> gExtensionGetterTable_gtlData_andOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_andOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_andOp inGetter) {
  gExtensionGetterTable_gtlData_andOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_andOp (void) {
  gExtensionGetterTable_gtlData_andOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_andOp (NULL,
                                          freeExtensionGetter_gtlData_andOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_andOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData & in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_andOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_andOp.count ()) {
      f = gExtensionGetterTable_gtlData_andOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_andOp.count ()) {
           f = gExtensionGetterTable_gtlData_andOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_andOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData orOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_orOp> gExtensionGetterTable_gtlData_orOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_orOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_orOp inGetter) {
  gExtensionGetterTable_gtlData_orOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_orOp (void) {
  gExtensionGetterTable_gtlData_orOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_orOp (NULL,
                                         freeExtensionGetter_gtlData_orOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_orOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData & in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_orOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_orOp.count ()) {
      f = gExtensionGetterTable_gtlData_orOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_orOp.count ()) {
           f = gExtensionGetterTable_gtlData_orOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_orOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData xorOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_xorOp> gExtensionGetterTable_gtlData_xorOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_xorOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_xorOp inGetter) {
  gExtensionGetterTable_gtlData_xorOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_xorOp (void) {
  gExtensionGetterTable_gtlData_xorOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_xorOp (NULL,
                                          freeExtensionGetter_gtlData_xorOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_xorOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData & in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_xorOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_xorOp.count ()) {
      f = gExtensionGetterTable_gtlData_xorOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_xorOp.count ()) {
           f = gExtensionGetterTable_gtlData_xorOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_xorOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData slOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_slOp> gExtensionGetterTable_gtlData_slOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_slOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_slOp inGetter) {
  gExtensionGetterTable_gtlData_slOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_slOp (void) {
  gExtensionGetterTable_gtlData_slOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_slOp (NULL,
                                         freeExtensionGetter_gtlData_slOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_slOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData & in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_slOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_slOp.count ()) {
      f = gExtensionGetterTable_gtlData_slOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_slOp.count ()) {
           f = gExtensionGetterTable_gtlData_slOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_slOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData srOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_srOp> gExtensionGetterTable_gtlData_srOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_srOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_srOp inGetter) {
  gExtensionGetterTable_gtlData_srOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_srOp (void) {
  gExtensionGetterTable_gtlData_srOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_srOp (NULL,
                                         freeExtensionGetter_gtlData_srOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_srOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData & in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_srOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_srOp.count ()) {
      f = gExtensionGetterTable_gtlData_srOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_srOp.count ()) {
           f = gExtensionGetterTable_gtlData_srOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_srOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData neqOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_neqOp> gExtensionGetterTable_gtlData_neqOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_neqOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_neqOp inGetter) {
  gExtensionGetterTable_gtlData_neqOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_neqOp (void) {
  gExtensionGetterTable_gtlData_neqOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_neqOp (NULL,
                                          freeExtensionGetter_gtlData_neqOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_neqOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData & in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_neqOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_neqOp.count ()) {
      f = gExtensionGetterTable_gtlData_neqOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_neqOp.count ()) {
           f = gExtensionGetterTable_gtlData_neqOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_neqOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData eqOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_eqOp> gExtensionGetterTable_gtlData_eqOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_eqOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_eqOp inGetter) {
  gExtensionGetterTable_gtlData_eqOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_eqOp (void) {
  gExtensionGetterTable_gtlData_eqOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_eqOp (NULL,
                                         freeExtensionGetter_gtlData_eqOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_eqOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData & in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_eqOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_eqOp.count ()) {
      f = gExtensionGetterTable_gtlData_eqOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_eqOp.count ()) {
           f = gExtensionGetterTable_gtlData_eqOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_eqOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData ltOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_ltOp> gExtensionGetterTable_gtlData_ltOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_ltOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_ltOp inGetter) {
  gExtensionGetterTable_gtlData_ltOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_ltOp (void) {
  gExtensionGetterTable_gtlData_ltOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_ltOp (NULL,
                                         freeExtensionGetter_gtlData_ltOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_ltOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData & in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_ltOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_ltOp.count ()) {
      f = gExtensionGetterTable_gtlData_ltOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_ltOp.count ()) {
           f = gExtensionGetterTable_gtlData_ltOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_ltOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData leOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_leOp> gExtensionGetterTable_gtlData_leOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_leOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_leOp inGetter) {
  gExtensionGetterTable_gtlData_leOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_leOp (void) {
  gExtensionGetterTable_gtlData_leOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_leOp (NULL,
                                         freeExtensionGetter_gtlData_leOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_leOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData & in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_leOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_leOp.count ()) {
      f = gExtensionGetterTable_gtlData_leOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_leOp.count ()) {
           f = gExtensionGetterTable_gtlData_leOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_leOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData gtOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_gtOp> gExtensionGetterTable_gtlData_gtOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_gtOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_gtOp inGetter) {
  gExtensionGetterTable_gtlData_gtOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_gtOp (void) {
  gExtensionGetterTable_gtlData_gtOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_gtOp (NULL,
                                         freeExtensionGetter_gtlData_gtOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_gtOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData & in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_gtOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_gtOp.count ()) {
      f = gExtensionGetterTable_gtlData_gtOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_gtOp.count ()) {
           f = gExtensionGetterTable_gtlData_gtOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_gtOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData geOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_geOp> gExtensionGetterTable_gtlData_geOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_geOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_geOp inGetter) {
  gExtensionGetterTable_gtlData_geOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_geOp (void) {
  gExtensionGetterTable_gtlData_geOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_geOp (NULL,
                                         freeExtensionGetter_gtlData_geOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_geOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData & in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_geOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_geOp.count ()) {
      f = gExtensionGetterTable_gtlData_geOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_geOp.count ()) {
           f = gExtensionGetterTable_gtlData_geOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_geOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Abstract extension getter '@gtlData embeddedType'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_embeddedType> gExtensionGetterTable_gtlData_embeddedType ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_embeddedType (const int32_t inClassIndex,
                                        enterExtensionGetter_gtlData_embeddedType inGetter) {
  gExtensionGetterTable_gtlData_embeddedType.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_embeddedType (void) {
  gExtensionGetterTable_gtlData_embeddedType.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_embeddedType (NULL,
                                                 freeExtensionGetter_gtlData_embeddedType) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type callExtensionGetter_embeddedType (const cPtr_gtlData * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_type result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_embeddedType f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_embeddedType.count ()) {
      f = gExtensionGetterTable_gtlData_embeddedType (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_embeddedType.count ()) {
           f = gExtensionGetterTable_gtlData_embeddedType (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_embeddedType.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                   Abstract extension method '@gtlData addMyValue'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlData_addMyValue> gExtensionMethodTable_gtlData_addMyValue ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_addMyValue (const int32_t inClassIndex,
                                      extensionMethodSignature_gtlData_addMyValue inMethod) {
  gExtensionMethodTable_gtlData_addMyValue.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlData_addMyValue (void) {
  gExtensionMethodTable_gtlData_addMyValue.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlData_addMyValue (NULL,
                                               freeExtensionMethod_gtlData_addMyValue) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_addMyValue (const cPtr_gtlData * inObject,
                                     GALGAS_objectlist & io_objectList,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlData_addMyValue f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlData_addMyValue.count ()) {
      f = gExtensionMethodTable_gtlData_addMyValue (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlData_addMyValue.count ()) {
           f = gExtensionMethodTable_gtlData_addMyValue (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlData_addMyValue.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_objectList, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Abstract extension getter '@gtlData performGetter'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_performGetter> gExtensionGetterTable_gtlData_performGetter ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_performGetter (const int32_t inClassIndex,
                                         enterExtensionGetter_gtlData_performGetter inGetter) {
  gExtensionGetterTable_gtlData_performGetter.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_performGetter (void) {
  gExtensionGetterTable_gtlData_performGetter.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_performGetter (NULL,
                                                  freeExtensionGetter_gtlData_performGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_performGetter (const cPtr_gtlData * inObject,
                                                  const GALGAS_lstring & in_methodName,
                                                  const GALGAS_gtlDataList & in_arguments,
                                                  const GALGAS_library & in_lib,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_performGetter f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_performGetter.count ()) {
      f = gExtensionGetterTable_gtlData_performGetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_performGetter.count ()) {
           f = gExtensionGetterTable_gtlData_performGetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_performGetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_methodName, in_arguments, in_lib, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Abstract extension setter '@gtlData performSetter'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_performSetter> gExtensionModifierTable_gtlData_performSetter ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_performSetter (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlData_performSetter inModifier) {
  gExtensionModifierTable_gtlData_performSetter.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_performSetter (void) {
  gExtensionModifierTable_gtlData_performSetter.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_performSetter (NULL,
                                                  freeExtensionModifier_gtlData_performSetter) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_performSetter (cPtr_gtlData * inObject,
                                        const GALGAS_lstring constin_methodName,
                                        const GALGAS_gtlDataList constin_arguments,
                                        const GALGAS_library constin_lib,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_performSetter f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_performSetter.count ()) {
      f = gExtensionModifierTable_gtlData_performSetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_performSetter.count ()) {
           f = gExtensionModifierTable_gtlData_performSetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_performSetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_methodName, constin_arguments, constin_lib, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension method '@gtlData structField'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlData_structField> gExtensionMethodTable_gtlData_structField ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_structField (const int32_t inClassIndex,
                                       extensionMethodSignature_gtlData_structField inMethod) {
  gExtensionMethodTable_gtlData_structField.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_structField (const cPtr_gtlData * inObject,
                                      const GALGAS_lstring constin_name,
                                      GALGAS_gtlData & out_result,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  out_result.drop () ;
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlData_structField f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlData_structField.count ()) {
      f = gExtensionMethodTable_gtlData_structField (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlData_structField.count ()) {
           f = gExtensionMethodTable_gtlData_structField (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlData_structField.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_name, out_result, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlData_structField (const cPtr_gtlData * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 GALGAS_gtlData & outArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 238)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 238)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 238)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 238)).add_operation (GALGAS_string (" is not a struct"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 238)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 238)) ;
  outArgument_result.drop () ; // Release error dropped variable
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlData_structField (void) {
  enterExtensionMethod_structField (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                    extensionMethod_gtlData_structField) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlData_structField (void) {
  gExtensionMethodTable_gtlData_structField.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlData_structField (defineExtensionMethod_gtlData_structField,
                                                freeExtensionMethod_gtlData_structField) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlData resultField'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_resultField> gExtensionGetterTable_gtlData_resultField ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_resultField (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlData_resultField inGetter) {
  gExtensionGetterTable_gtlData_resultField.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_resultField (const cPtr_gtlData * inObject,
                                                const GALGAS_lstring & in_name,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_resultField f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_resultField.count ()) {
      f = gExtensionGetterTable_gtlData_resultField (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_resultField.count ()) {
           f = gExtensionGetterTable_gtlData_resultField (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_resultField.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlData_resultField (const cPtr_gtlData * inObject,
                                                           const GALGAS_lstring & constinArgument_name,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 245)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 245)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 245)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 245)).add_operation (GALGAS_string (" is not a struct"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 245)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 245)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlData_resultField (void) {
  enterExtensionGetter_resultField (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                    extensionGetter_gtlData_resultField) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_resultField (void) {
  gExtensionGetterTable_gtlData_resultField.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_resultField (defineExtensionGetter_gtlData_resultField,
                                                freeExtensionGetter_gtlData_resultField) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension setter '@gtlData setStructField'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_setStructField> gExtensionModifierTable_gtlData_setStructField ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setStructField (const int32_t inClassIndex,
                                          extensionSetterSignature_gtlData_setStructField inModifier) {
  gExtensionModifierTable_gtlData_setStructField.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setStructField (cPtr_gtlData * inObject,
                                         const GALGAS_lstring constin_name,
                                         const GALGAS_gtlData constin_data,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_setStructField f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_setStructField.count ()) {
      f = gExtensionModifierTable_gtlData_setStructField (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_setStructField.count ()) {
           f = gExtensionModifierTable_gtlData_setStructField (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_setStructField.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_data, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlData_setStructField (cPtr_gtlData * inObject,
                                                    const GALGAS_lstring constinArgument_name,
                                                    const GALGAS_gtlData /* constinArgument_data */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 253)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 253)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 253)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 253)).add_operation (GALGAS_string (" is not a struct"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 253)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 253)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlData_setStructField (void) {
  enterExtensionSetter_setStructField (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                       extensionSetter_gtlData_setStructField) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_setStructField (void) {
  gExtensionModifierTable_gtlData_setStructField.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_setStructField (defineExtensionSetter_gtlData_setStructField,
                                                   freeExtensionModifier_gtlData_setStructField) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension setter '@gtlData setStructFieldAtLevel'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_setStructFieldAtLevel> gExtensionModifierTable_gtlData_setStructFieldAtLevel ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setStructFieldAtLevel (const int32_t inClassIndex,
                                                 extensionSetterSignature_gtlData_setStructFieldAtLevel inModifier) {
  gExtensionModifierTable_gtlData_setStructFieldAtLevel.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setStructFieldAtLevel (cPtr_gtlData * inObject,
                                                const GALGAS_lstring constin_name,
                                                const GALGAS_gtlData constin_data,
                                                const GALGAS_uint constin_level,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_setStructFieldAtLevel f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_setStructFieldAtLevel.count ()) {
      f = gExtensionModifierTable_gtlData_setStructFieldAtLevel (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_setStructFieldAtLevel.count ()) {
           f = gExtensionModifierTable_gtlData_setStructFieldAtLevel (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_setStructFieldAtLevel.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_data, constin_level, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlData_setStructFieldAtLevel (cPtr_gtlData * inObject,
                                                           const GALGAS_lstring constinArgument_name,
                                                           const GALGAS_gtlData /* constinArgument_data */,
                                                           const GALGAS_uint /* constinArgument_level */,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 262)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 262)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 262)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 262)).add_operation (GALGAS_string (" is not a struct"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 262)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 262)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlData_setStructFieldAtLevel (void) {
  enterExtensionSetter_setStructFieldAtLevel (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                              extensionSetter_gtlData_setStructFieldAtLevel) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_setStructFieldAtLevel (void) {
  gExtensionModifierTable_gtlData_setStructFieldAtLevel.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_setStructFieldAtLevel (defineExtensionSetter_gtlData_setStructFieldAtLevel,
                                                          freeExtensionModifier_gtlData_setStructFieldAtLevel) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension setter '@gtlData deleteStructField'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_deleteStructField> gExtensionModifierTable_gtlData_deleteStructField ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteStructField (const int32_t inClassIndex,
                                             extensionSetterSignature_gtlData_deleteStructField inModifier) {
  gExtensionModifierTable_gtlData_deleteStructField.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteStructField (cPtr_gtlData * inObject,
                                            const GALGAS_lstring constin_name,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_deleteStructField f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_deleteStructField.count ()) {
      f = gExtensionModifierTable_gtlData_deleteStructField (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_deleteStructField.count ()) {
           f = gExtensionModifierTable_gtlData_deleteStructField (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_deleteStructField.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlData_deleteStructField (cPtr_gtlData * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 268)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 268)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 268)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 268)).add_operation (GALGAS_string (" is not a struct"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 268)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 268)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlData_deleteStructField (void) {
  enterExtensionSetter_deleteStructField (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                          extensionSetter_gtlData_deleteStructField) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_deleteStructField (void) {
  gExtensionModifierTable_gtlData_deleteStructField.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_deleteStructField (defineExtensionSetter_gtlData_deleteStructField,
                                                      freeExtensionModifier_gtlData_deleteStructField) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlData hasStructField'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_hasStructField> gExtensionGetterTable_gtlData_hasStructField ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasStructField (const int32_t inClassIndex,
                                          enterExtensionGetter_gtlData_hasStructField inGetter) {
  gExtensionGetterTable_gtlData_hasStructField.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_hasStructField (const cPtr_gtlData * inObject,
                                                const GALGAS_lstring & in_name,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_hasStructField f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_hasStructField.count ()) {
      f = gExtensionGetterTable_gtlData_hasStructField (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_hasStructField.count ()) {
           f = gExtensionGetterTable_gtlData_hasStructField (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_hasStructField.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlData_hasStructField (const cPtr_gtlData * /* inObject */,
                                                           const GALGAS_lstring & /* constinArgument_name */,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (false) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlData_hasStructField (void) {
  enterExtensionGetter_hasStructField (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                       extensionGetter_gtlData_hasStructField) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_hasStructField (void) {
  gExtensionGetterTable_gtlData_hasStructField.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_hasStructField (defineExtensionGetter_gtlData_hasStructField,
                                                   freeExtensionGetter_gtlData_hasStructField) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlData overrideMap'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_overrideMap> gExtensionGetterTable_gtlData_overrideMap ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_overrideMap (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlData_overrideMap inGetter) {
  gExtensionGetterTable_gtlData_overrideMap.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlStruct callExtensionGetter_overrideMap (const cPtr_gtlData * inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlStruct result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_overrideMap f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_overrideMap.count ()) {
      f = gExtensionGetterTable_gtlData_overrideMap (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_overrideMap.count ()) {
           f = gExtensionGetterTable_gtlData_overrideMap (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_overrideMap.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_gtlStruct extensionGetter_gtlData_overrideMap (const cPtr_gtlData * inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlStruct result_mapOverriden ; // Returned variable
  const cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 281)), GALGAS_string ("INTERNAL ERROR : a variable map should be a @gtlStruct"), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 281)) ;
  result_mapOverriden.drop () ; // Release error dropped variable
//---
  return result_mapOverriden ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlData_overrideMap (void) {
  enterExtensionGetter_overrideMap (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                    extensionGetter_gtlData_overrideMap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_overrideMap (void) {
  gExtensionGetterTable_gtlData_overrideMap.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_overrideMap (defineExtensionGetter_gtlData_overrideMap,
                                                freeExtensionGetter_gtlData_overrideMap) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension getter '@gtlData overriddenMap'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_overriddenMap> gExtensionGetterTable_gtlData_overriddenMap ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_overriddenMap (const int32_t inClassIndex,
                                         enterExtensionGetter_gtlData_overriddenMap inGetter) {
  gExtensionGetterTable_gtlData_overriddenMap.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlStruct callExtensionGetter_overriddenMap (const cPtr_gtlData * inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlStruct result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_overriddenMap f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_overriddenMap.count ()) {
      f = gExtensionGetterTable_gtlData_overriddenMap (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_overriddenMap.count ()) {
           f = gExtensionGetterTable_gtlData_overriddenMap (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_overriddenMap.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_gtlStruct extensionGetter_gtlData_overriddenMap (const cPtr_gtlData * inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlStruct result_overriddenMap ; // Returned variable
  const cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 287)), GALGAS_string ("INTERNAL ERROR : a variable map should be a @gtlStruct"), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 287)) ;
  result_overriddenMap.drop () ; // Release error dropped variable
//---
  return result_overriddenMap ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlData_overriddenMap (void) {
  enterExtensionGetter_overriddenMap (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                      extensionGetter_gtlData_overriddenMap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_overriddenMap (void) {
  gExtensionGetterTable_gtlData_overriddenMap.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_overriddenMap (defineExtensionGetter_gtlData_overriddenMap,
                                                  freeExtensionGetter_gtlData_overriddenMap) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Extension method '@gtlData mapItem'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlData_mapItem> gExtensionMethodTable_gtlData_mapItem ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_mapItem (const int32_t inClassIndex,
                                   extensionMethodSignature_gtlData_mapItem inMethod) {
  gExtensionMethodTable_gtlData_mapItem.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_mapItem (const cPtr_gtlData * inObject,
                                  const GALGAS_lstring constin_name,
                                  GALGAS_gtlData & out_result,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  out_result.drop () ;
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlData_mapItem f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlData_mapItem.count ()) {
      f = gExtensionMethodTable_gtlData_mapItem (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlData_mapItem.count ()) {
           f = gExtensionMethodTable_gtlData_mapItem (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlData_mapItem.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_name, out_result, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlData_mapItem (const cPtr_gtlData * inObject,
                                             const GALGAS_lstring constinArgument_name,
                                             GALGAS_gtlData & outArgument_result,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 294)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 294)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 294)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 294)).add_operation (GALGAS_string (" is not a map"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 294)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 294)) ;
  outArgument_result.drop () ; // Release error dropped variable
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlData_mapItem (void) {
  enterExtensionMethod_mapItem (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                extensionMethod_gtlData_mapItem) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlData_mapItem (void) {
  gExtensionMethodTable_gtlData_mapItem.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlData_mapItem (defineExtensionMethod_gtlData_mapItem,
                                            freeExtensionMethod_gtlData_mapItem) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlData hasMapItem'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_hasMapItem> gExtensionGetterTable_gtlData_hasMapItem ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasMapItem (const int32_t inClassIndex,
                                      enterExtensionGetter_gtlData_hasMapItem inGetter) {
  gExtensionGetterTable_gtlData_hasMapItem.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_hasMapItem (const cPtr_gtlData * inObject,
                                            const GALGAS_lstring & in_name,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_hasMapItem f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_hasMapItem.count ()) {
      f = gExtensionGetterTable_gtlData_hasMapItem (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_hasMapItem.count ()) {
           f = gExtensionGetterTable_gtlData_hasMapItem (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_hasMapItem.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlData_hasMapItem (const cPtr_gtlData * /* inObject */,
                                                       const GALGAS_lstring & /* constinArgument_name */,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (false) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlData_hasMapItem (void) {
  enterExtensionGetter_hasMapItem (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                   extensionGetter_gtlData_hasMapItem) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_hasMapItem (void) {
  gExtensionGetterTable_gtlData_hasMapItem.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_hasMapItem (defineExtensionGetter_gtlData_hasMapItem,
                                               freeExtensionGetter_gtlData_hasMapItem) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension setter '@gtlData setMapItem'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_setMapItem> gExtensionModifierTable_gtlData_setMapItem ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setMapItem (const int32_t inClassIndex,
                                      extensionSetterSignature_gtlData_setMapItem inModifier) {
  gExtensionModifierTable_gtlData_setMapItem.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setMapItem (cPtr_gtlData * inObject,
                                     const GALGAS_lstring constin_name,
                                     const GALGAS_gtlData constin_data,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_setMapItem f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_setMapItem.count ()) {
      f = gExtensionModifierTable_gtlData_setMapItem (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_setMapItem.count ()) {
           f = gExtensionModifierTable_gtlData_setMapItem (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_setMapItem.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_data, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlData_setMapItem (cPtr_gtlData * inObject,
                                                const GALGAS_lstring constinArgument_name,
                                                const GALGAS_gtlData /* constinArgument_data */,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 308)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 308)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 308)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 308)).add_operation (GALGAS_string (" is not a map"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 308)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 308)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlData_setMapItem (void) {
  enterExtensionSetter_setMapItem (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                   extensionSetter_gtlData_setMapItem) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_setMapItem (void) {
  gExtensionModifierTable_gtlData_setMapItem.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_setMapItem (defineExtensionSetter_gtlData_setMapItem,
                                               freeExtensionModifier_gtlData_setMapItem) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension setter '@gtlData deleteMapItem'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_deleteMapItem> gExtensionModifierTable_gtlData_deleteMapItem ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteMapItem (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlData_deleteMapItem inModifier) {
  gExtensionModifierTable_gtlData_deleteMapItem.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteMapItem (cPtr_gtlData * inObject,
                                        const GALGAS_lstring constin_name,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_deleteMapItem f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_deleteMapItem.count ()) {
      f = gExtensionModifierTable_gtlData_deleteMapItem (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_deleteMapItem.count ()) {
           f = gExtensionModifierTable_gtlData_deleteMapItem (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_deleteMapItem.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlData_deleteMapItem (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_name,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 314)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 314)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 314)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 314)).add_operation (GALGAS_string (" is not a map"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 314)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 314)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlData_deleteMapItem (void) {
  enterExtensionSetter_deleteMapItem (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                      extensionSetter_gtlData_deleteMapItem) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_deleteMapItem (void) {
  gExtensionModifierTable_gtlData_deleteMapItem.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_deleteMapItem (defineExtensionSetter_gtlData_deleteMapItem,
                                                  freeExtensionModifier_gtlData_deleteMapItem) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension method '@gtlData itemAtIndex'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlData_itemAtIndex> gExtensionMethodTable_gtlData_itemAtIndex ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_itemAtIndex (const int32_t inClassIndex,
                                       extensionMethodSignature_gtlData_itemAtIndex inMethod) {
  gExtensionMethodTable_gtlData_itemAtIndex.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_itemAtIndex (const cPtr_gtlData * inObject,
                                      GALGAS_gtlData & out_result,
                                      const GALGAS_gtlInt constin_index,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  out_result.drop () ;
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlData_itemAtIndex f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlData_itemAtIndex.count ()) {
      f = gExtensionMethodTable_gtlData_itemAtIndex (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlData_itemAtIndex.count ()) {
           f = gExtensionMethodTable_gtlData_itemAtIndex (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlData_itemAtIndex.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, out_result, constin_index, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlData_itemAtIndex (const cPtr_gtlData * inObject,
                                                 GALGAS_gtlData & outArgument_result,
                                                 const GALGAS_gtlInt constinArgument_index,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlInt *) constinArgument_index.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 321)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 321)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 321)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 321)).add_operation (GALGAS_string (" is not a list"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 321)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 321)) ;
  outArgument_result.drop () ; // Release error dropped variable
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlData_itemAtIndex (void) {
  enterExtensionMethod_itemAtIndex (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                    extensionMethod_gtlData_itemAtIndex) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlData_itemAtIndex (void) {
  gExtensionMethodTable_gtlData_itemAtIndex.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlData_itemAtIndex (defineExtensionMethod_gtlData_itemAtIndex,
                                                freeExtensionMethod_gtlData_itemAtIndex) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlData hasItemAtIndex'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_hasItemAtIndex> gExtensionGetterTable_gtlData_hasItemAtIndex ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasItemAtIndex (const int32_t inClassIndex,
                                          enterExtensionGetter_gtlData_hasItemAtIndex inGetter) {
  gExtensionGetterTable_gtlData_hasItemAtIndex.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_hasItemAtIndex (const cPtr_gtlData * inObject,
                                                const GALGAS_gtlInt & in_index,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_hasItemAtIndex f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_hasItemAtIndex.count ()) {
      f = gExtensionGetterTable_gtlData_hasItemAtIndex (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_hasItemAtIndex.count ()) {
           f = gExtensionGetterTable_gtlData_hasItemAtIndex (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_hasItemAtIndex.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_index, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlData_hasItemAtIndex (const cPtr_gtlData * /* inObject */,
                                                           const GALGAS_gtlInt & /* constinArgument_index */,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (false) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlData_hasItemAtIndex (void) {
  enterExtensionGetter_hasItemAtIndex (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                       extensionGetter_gtlData_hasItemAtIndex) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_hasItemAtIndex (void) {
  gExtensionGetterTable_gtlData_hasItemAtIndex.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_hasItemAtIndex (defineExtensionGetter_gtlData_hasItemAtIndex,
                                                   freeExtensionGetter_gtlData_hasItemAtIndex) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension setter '@gtlData setItemAtIndex'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_setItemAtIndex> gExtensionModifierTable_gtlData_setItemAtIndex ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setItemAtIndex (const int32_t inClassIndex,
                                          extensionSetterSignature_gtlData_setItemAtIndex inModifier) {
  gExtensionModifierTable_gtlData_setItemAtIndex.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setItemAtIndex (cPtr_gtlData * inObject,
                                         const GALGAS_gtlData constin_data,
                                         const GALGAS_gtlInt constin_index,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_setItemAtIndex f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_setItemAtIndex.count ()) {
      f = gExtensionModifierTable_gtlData_setItemAtIndex (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_setItemAtIndex.count ()) {
           f = gExtensionModifierTable_gtlData_setItemAtIndex (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_setItemAtIndex.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_data, constin_index, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlData_setItemAtIndex (cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_data */,
                                                    const GALGAS_gtlInt constinArgument_index,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlInt *) constinArgument_index.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 335)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 335)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 335)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 335)).add_operation (GALGAS_string (" is not a list"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 335)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 335)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlData_setItemAtIndex (void) {
  enterExtensionSetter_setItemAtIndex (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                       extensionSetter_gtlData_setItemAtIndex) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_setItemAtIndex (void) {
  gExtensionModifierTable_gtlData_setItemAtIndex.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_setItemAtIndex (defineExtensionSetter_gtlData_setItemAtIndex,
                                                   freeExtensionModifier_gtlData_setItemAtIndex) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension setter '@gtlData deleteItemAtIndex'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_deleteItemAtIndex> gExtensionModifierTable_gtlData_deleteItemAtIndex ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteItemAtIndex (const int32_t inClassIndex,
                                             extensionSetterSignature_gtlData_deleteItemAtIndex inModifier) {
  gExtensionModifierTable_gtlData_deleteItemAtIndex.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteItemAtIndex (cPtr_gtlData * inObject,
                                            const GALGAS_gtlInt constin_index,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_deleteItemAtIndex f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_deleteItemAtIndex.count ()) {
      f = gExtensionModifierTable_gtlData_deleteItemAtIndex (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_deleteItemAtIndex.count ()) {
           f = gExtensionModifierTable_gtlData_deleteItemAtIndex (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_deleteItemAtIndex.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_index, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlData_deleteItemAtIndex (cPtr_gtlData * inObject,
                                                       const GALGAS_gtlInt constinArgument_index,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlInt *) constinArgument_index.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 341)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 341)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 341)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 341)).add_operation (GALGAS_string (" is not a list"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 341)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 341)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlData_deleteItemAtIndex (void) {
  enterExtensionSetter_deleteItemAtIndex (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                          extensionSetter_gtlData_deleteItemAtIndex) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_deleteItemAtIndex (void) {
  gExtensionModifierTable_gtlData_deleteItemAtIndex.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_deleteItemAtIndex (defineExtensionSetter_gtlData_deleteItemAtIndex,
                                                      freeExtensionModifier_gtlData_deleteItemAtIndex) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension setter '@gtlData appendItem'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_appendItem> gExtensionModifierTable_gtlData_appendItem ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_appendItem (const int32_t inClassIndex,
                                      extensionSetterSignature_gtlData_appendItem inModifier) {
  gExtensionModifierTable_gtlData_appendItem.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_appendItem (cPtr_gtlData * inObject,
                                     const GALGAS_gtlData constin_item,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_appendItem f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_appendItem.count ()) {
      f = gExtensionModifierTable_gtlData_appendItem (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_appendItem.count ()) {
           f = gExtensionModifierTable_gtlData_appendItem (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_appendItem.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_item, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlData_appendItem (cPtr_gtlData * inObject,
                                                const GALGAS_gtlData constinArgument_item,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_item.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 347)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 347)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 347)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 347)).add_operation (GALGAS_string (" is not a list"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 347)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 347)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlData_appendItem (void) {
  enterExtensionSetter_appendItem (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                   extensionSetter_gtlData_appendItem) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_appendItem (void) {
  gExtensionModifierTable_gtlData_appendItem.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_appendItem (defineExtensionSetter_gtlData_appendItem,
                                               freeExtensionModifier_gtlData_appendItem) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension method '@gtlExecutableEntity checkArguments'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlExecutableEntity_checkArguments> gExtensionMethodTable_gtlExecutableEntity_checkArguments ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_checkArguments (const int32_t inClassIndex,
                                          extensionMethodSignature_gtlExecutableEntity_checkArguments inMethod) {
  gExtensionMethodTable_gtlExecutableEntity_checkArguments.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_checkArguments (const cPtr_gtlExecutableEntity * inObject,
                                         const GALGAS_location constin_fromLocation,
                                         const GALGAS_gtlDataList constin_actualArguments,
                                         GALGAS_gtlData & out_entityVariableMap,
                                         GALGAS_bool & out_result,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  out_entityVariableMap.drop () ;
  out_result.drop () ;
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlExecutableEntity) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlExecutableEntity_checkArguments f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlExecutableEntity_checkArguments.count ()) {
      f = gExtensionMethodTable_gtlExecutableEntity_checkArguments (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlExecutableEntity_checkArguments.count ()) {
           f = gExtensionMethodTable_gtlExecutableEntity_checkArguments (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlExecutableEntity_checkArguments.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_fromLocation, constin_actualArguments, out_entityVariableMap, out_result, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlExecutableEntity_checkArguments (const cPtr_gtlExecutableEntity * inObject,
                                                                const GALGAS_location constinArgument_fromLocation,
                                                                const GALGAS_gtlDataList constinArgument_actualArguments,
                                                                GALGAS_gtlData & outArgument_entityVariableMap,
                                                                GALGAS_bool & outArgument_result,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlExecutableEntity * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlExecutableEntity) ;
  outArgument_result = GALGAS_bool (true) ;
  outArgument_entityVariableMap = GALGAS_gtlStruct::constructor_new (constinArgument_fromLocation, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 52)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_module.galgas", 53))  COMMA_SOURCE_FILE ("gtl_module.galgas", 50)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mAttribute_formalArguments.getter_length (SOURCE_FILE ("gtl_module.galgas", 56)).objectCompare (constinArgument_actualArguments.getter_length (SOURCE_FILE ("gtl_module.galgas", 56)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    const GALGAS_gtlExecutableEntity temp_1 = object ;
    GALGAS_string temp_2 ;
    const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, temp_1.getter_dynamicType (SOURCE_FILE ("gtl_module.galgas", 58)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlProcedure))).boolEnum () ;
    if (kBoolTrue == test_3) {
      temp_2 = GALGAS_string ("procedure '") ;
    }else if (kBoolFalse == test_3) {
      temp_2 = GALGAS_string ("function '") ;
    }
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_fromLocation, GALGAS_string ("calling ").add_operation (temp_2, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 57)).add_operation (object->mAttribute_name.getter_string (SOURCE_FILE ("gtl_module.galgas", 62)), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 62)).add_operation (GALGAS_string ("' needs "), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 63)).add_operation (object->mAttribute_formalArguments.getter_length (SOURCE_FILE ("gtl_module.galgas", 63)).getter_string (SOURCE_FILE ("gtl_module.galgas", 63)), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 63)).add_operation (GALGAS_string (" arguments"), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 63)), fixItArray4  COMMA_SOURCE_FILE ("gtl_module.galgas", 57)) ;
  }else if (kBoolFalse == test_0) {
    cEnumerator_gtlArgumentList enumerator_1631 (object->mAttribute_formalArguments, kEnumeration_up) ;
    cEnumerator_gtlDataList enumerator_1654 (constinArgument_actualArguments, kEnumeration_up) ;
    while (enumerator_1631.hasCurrentObject () && enumerator_1654.hasCurrentObject ()) {
      const enumGalgasBool test_5 = GALGAS_bool (kIsNotEqual, enumerator_1654.current_data (HERE).getter_dynamicType (SOURCE_FILE ("gtl_module.galgas", 67)).objectCompare (enumerator_1631.current_type (HERE))).operator_and (enumerator_1631.current_typed (HERE) COMMA_SOURCE_FILE ("gtl_module.galgas", 67)).boolEnum () ;
      if (kBoolTrue == test_5) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) enumerator_1654.current_data (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 68)), extensionGetter_typeName (enumerator_1631.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 68)).add_operation (GALGAS_string (" expected for "), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 68)).add_operation (enumerator_1631.current_name (HERE).getter_string (SOURCE_FILE ("gtl_module.galgas", 68)), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 68)), fixItArray6  COMMA_SOURCE_FILE ("gtl_module.galgas", 68)) ;
        outArgument_result = GALGAS_bool (false) ;
      }else if (kBoolFalse == test_5) {
        {
        cPtr_gtlData * ptr_1843 = (cPtr_gtlData *) outArgument_entityVariableMap.ptr () ;
        callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1843, enumerator_1631.current_name (HERE), enumerator_1654.current_data (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 71)) ;
        }
      }
      enumerator_1631.gotoNextObject () ;
      enumerator_1654.gotoNextObject () ;
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlExecutableEntity_checkArguments (void) {
  enterExtensionMethod_checkArguments (kTypeDescriptor_GALGAS_gtlExecutableEntity.mSlotID,
                                       extensionMethod_gtlExecutableEntity_checkArguments) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlExecutableEntity_checkArguments (void) {
  gExtensionMethodTable_gtlExecutableEntity_checkArguments.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlExecutableEntity_checkArguments (defineExtensionMethod_gtlExecutableEntity_checkArguments,
                                                               freeExtensionMethod_gtlExecutableEntity_checkArguments) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension method '@gtlProcedure call'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlProcedure_call> gExtensionMethodTable_gtlProcedure_call ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_call (const int32_t inClassIndex,
                                extensionMethodSignature_gtlProcedure_call inMethod) {
  gExtensionMethodTable_gtlProcedure_call.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_call (const cPtr_gtlProcedure * inObject,
                               GALGAS_gtlContext & io_context,
                               GALGAS_library & io_lib,
                               GALGAS_string & io_outputString,
                               const GALGAS_location constin_fromLocation,
                               const GALGAS_gtlDataList constin_actualArguments,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlProcedure) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlProcedure_call f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlProcedure_call.count ()) {
      f = gExtensionMethodTable_gtlProcedure_call (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlProcedure_call.count ()) {
           f = gExtensionMethodTable_gtlProcedure_call (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlProcedure_call.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_context, io_lib, io_outputString, constin_fromLocation, constin_actualArguments, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlProcedure_call (const cPtr_gtlProcedure * inObject,
                                               GALGAS_gtlContext & ioArgument_context,
                                               GALGAS_library & ioArgument_lib,
                                               GALGAS_string & ioArgument_outputString,
                                               const GALGAS_location constinArgument_fromLocation,
                                               const GALGAS_gtlDataList constinArgument_actualArguments,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlProcedure * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlProcedure) ;
  GALGAS_gtlData var_vars_2288 ;
  GALGAS_bool var_ok_2298 ;
  const GALGAS_gtlProcedure temp_0 = object ;
  callExtensionMethod_checkArguments ((const cPtr_gtlProcedure *) temp_0.ptr (), constinArgument_fromLocation, constinArgument_actualArguments, var_vars_2288, var_ok_2298, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 89)) ;
  const enumGalgasBool test_1 = var_ok_2298.boolEnum () ;
  if (kBoolTrue == test_1) {
    extensionMethod_execute (object->mAttribute_instructions, ioArgument_context, var_vars_2288, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 92)) ;
  }else if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_fromLocation, GALGAS_string ("procedure call failed"), fixItArray2  COMMA_SOURCE_FILE ("gtl_module.galgas", 94)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlProcedure_call (void) {
  enterExtensionMethod_call (kTypeDescriptor_GALGAS_gtlProcedure.mSlotID,
                             extensionMethod_gtlProcedure_call) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlProcedure_call (void) {
  gExtensionMethodTable_gtlProcedure_call.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlProcedure_call (defineExtensionMethod_gtlProcedure_call,
                                              freeExtensionMethod_gtlProcedure_call) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension getter '@gtlFunction call'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlFunction_call> gExtensionGetterTable_gtlFunction_call ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_call (const int32_t inClassIndex,
                                enterExtensionGetter_gtlFunction_call inGetter) {
  gExtensionGetterTable_gtlFunction_call.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_call (const cPtr_gtlFunction * inObject,
                                         const GALGAS_location & in_fromLocation,
                                         GALGAS_library in_lib,
                                         const GALGAS_gtlDataList & in_actualArguments,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlFunction) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlFunction_call f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlFunction_call.count ()) {
      f = gExtensionGetterTable_gtlFunction_call (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlFunction_call.count ()) {
           f = gExtensionGetterTable_gtlFunction_call (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlFunction_call.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_fromLocation, in_lib, in_actualArguments, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFunction_call (const cPtr_gtlFunction * inObject,
                                                        const GALGAS_location & constinArgument_fromLocation,
                                                        GALGAS_library inArgument_lib,
                                                        const GALGAS_gtlDataList & constinArgument_actualArguments,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFunction * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlFunction) ;
  GALGAS_gtlData var_funcVariableMap_2829 ;
  GALGAS_bool var_ok_2839 ;
  const GALGAS_gtlFunction temp_0 = object ;
  callExtensionMethod_checkArguments ((const cPtr_gtlFunction *) temp_0.ptr (), constinArgument_fromLocation, constinArgument_actualArguments, var_funcVariableMap_2829, var_ok_2839, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 110)) ;
  {
  cPtr_gtlData * ptr_2861 = (cPtr_gtlData *) var_funcVariableMap_2829.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2861, object->mAttribute_returnVariable, GALGAS_gtlUnconstructed::constructor_new (object->mAttribute_returnVariable.getter_location (SOURCE_FILE ("gtl_module.galgas", 114)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 114))  COMMA_SOURCE_FILE ("gtl_module.galgas", 114)), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 112)) ;
  }
  const enumGalgasBool test_1 = var_ok_2839.boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_gtlContext var_functionContext_3018 = function_emptyContext (inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 117)) ;
    GALGAS_string var_outputString_3060 = GALGAS_string::makeEmptyString () ;
    extensionMethod_execute (object->mAttribute_instructions, var_functionContext_3018, var_funcVariableMap_2829, inArgument_lib, var_outputString_3060, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 119)) ;
    result_result = callExtensionGetter_resultField ((const cPtr_gtlData *) var_funcVariableMap_2829.ptr (), object->mAttribute_returnVariable, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 120)) ;
  }else if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_fromLocation, GALGAS_string ("function call failed"), fixItArray2  COMMA_SOURCE_FILE ("gtl_module.galgas", 122)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFunction_call (void) {
  enterExtensionGetter_call (kTypeDescriptor_GALGAS_gtlFunction.mSlotID,
                             extensionGetter_gtlFunction_call) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlFunction_call (void) {
  gExtensionGetterTable_gtlFunction_call.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFunction_call (defineExtensionGetter_gtlFunction_call,
                                             freeExtensionGetter_gtlFunction_call) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension getter '@gtlGetter callGetter'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlGetter_callGetter> gExtensionGetterTable_gtlGetter_callGetter ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_callGetter (const int32_t inClassIndex,
                                      enterExtensionGetter_gtlGetter_callGetter inGetter) {
  gExtensionGetterTable_gtlGetter_callGetter.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_callGetter (const cPtr_gtlGetter * inObject,
                                               const GALGAS_location & in_fromLocation,
                                               GALGAS_library in_lib,
                                               const GALGAS_gtlData & in_target,
                                               const GALGAS_gtlDataList & in_actualArguments,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlGetter) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlGetter_callGetter f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlGetter_callGetter.count ()) {
      f = gExtensionGetterTable_gtlGetter_callGetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlGetter_callGetter.count ()) {
           f = gExtensionGetterTable_gtlGetter_callGetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlGetter_callGetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_fromLocation, in_lib, in_target, in_actualArguments, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlGetter_callGetter (const cPtr_gtlGetter * inObject,
                                                            const GALGAS_location & constinArgument_fromLocation,
                                                            GALGAS_library inArgument_lib,
                                                            const GALGAS_gtlData & constinArgument_target,
                                                            const GALGAS_gtlDataList & constinArgument_actualArguments,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlGetter * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlGetter) ;
  GALGAS_gtlData var_getterVariableMap_3685 ;
  GALGAS_bool var_ok_3695 ;
  const GALGAS_gtlGetter temp_0 = object ;
  callExtensionMethod_checkArguments ((const cPtr_gtlGetter *) temp_0.ptr (), constinArgument_fromLocation, constinArgument_actualArguments, var_getterVariableMap_3685, var_ok_3695, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 139)) ;
  {
  cPtr_gtlData * ptr_3719 = (cPtr_gtlData *) var_getterVariableMap_3685.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3719, object->mAttribute_returnVariable, GALGAS_gtlUnconstructed::constructor_new (object->mAttribute_returnVariable.getter_location (SOURCE_FILE ("gtl_module.galgas", 143)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 143))  COMMA_SOURCE_FILE ("gtl_module.galgas", 143)), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 141)) ;
  }
  const enumGalgasBool test_1 = var_ok_3695.boolEnum () ;
  if (kBoolTrue == test_1) {
    {
    cPtr_gtlData * ptr_3869 = (cPtr_gtlData *) var_getterVariableMap_3685.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3869, GALGAS_lstring::constructor_new (GALGAS_string ("self"), constinArgument_fromLocation  COMMA_SOURCE_FILE ("gtl_module.galgas", 147)), constinArgument_target, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 146)) ;
    }
    GALGAS_gtlContext var_getterContext_3972 = function_emptyContext (inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 150)) ;
    GALGAS_string var_outputString_4014 = GALGAS_string::makeEmptyString () ;
    extensionMethod_execute (object->mAttribute_instructions, var_getterContext_3972, var_getterVariableMap_3685, inArgument_lib, var_outputString_4014, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 152)) ;
    result_result = callExtensionGetter_resultField ((const cPtr_gtlData *) var_getterVariableMap_3685.ptr (), object->mAttribute_returnVariable, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 153)) ;
  }else if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_fromLocation, GALGAS_string ("getter call failed"), fixItArray2  COMMA_SOURCE_FILE ("gtl_module.galgas", 155)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlGetter_callGetter (void) {
  enterExtensionGetter_callGetter (kTypeDescriptor_GALGAS_gtlGetter.mSlotID,
                                   extensionGetter_gtlGetter_callGetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlGetter_callGetter (void) {
  gExtensionGetterTable_gtlGetter_callGetter.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlGetter_callGetter (defineExtensionGetter_gtlGetter_callGetter,
                                                 freeExtensionGetter_gtlGetter_callGetter) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlGetter typedName'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlGetter_typedName> gExtensionGetterTable_gtlGetter_typedName ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_typedName (const int32_t inClassIndex,
                                     enterExtensionGetter_gtlGetter_typedName inGetter) {
  gExtensionGetterTable_gtlGetter_typedName.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring callExtensionGetter_typedName (const cPtr_gtlGetter * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlGetter) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlGetter_typedName f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlGetter_typedName.count ()) {
      f = gExtensionGetterTable_gtlGetter_typedName (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlGetter_typedName.count ()) {
           f = gExtensionGetterTable_gtlGetter_typedName (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlGetter_typedName.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_lstring extensionGetter_gtlGetter_typedName (const cPtr_gtlGetter * inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlGetter * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlGetter) ;
  result_result = GALGAS_lstring::constructor_new (extensionGetter_typeName (object->mAttribute_targetType, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 162)).add_operation (object->mAttribute_name.getter_string (SOURCE_FILE ("gtl_module.galgas", 162)), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 162)), object->mAttribute_where  COMMA_SOURCE_FILE ("gtl_module.galgas", 162)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlGetter_typedName (void) {
  enterExtensionGetter_typedName (kTypeDescriptor_GALGAS_gtlGetter.mSlotID,
                                  extensionGetter_gtlGetter_typedName) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlGetter_typedName (void) {
  gExtensionGetterTable_gtlGetter_typedName.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlGetter_typedName (defineExtensionGetter_gtlGetter_typedName,
                                                freeExtensionGetter_gtlGetter_typedName) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension method '@gtlSetter callSetter'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlSetter_callSetter> gExtensionMethodTable_gtlSetter_callSetter ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_callSetter (const int32_t inClassIndex,
                                      extensionMethodSignature_gtlSetter_callSetter inMethod) {
  gExtensionMethodTable_gtlSetter_callSetter.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_callSetter (const cPtr_gtlSetter * inObject,
                                     const GALGAS_location constin_fromLocation,
                                     GALGAS_library in_lib,
                                     GALGAS_gtlData & io_target,
                                     const GALGAS_gtlDataList constin_actualArguments,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlSetter) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlSetter_callSetter f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlSetter_callSetter.count ()) {
      f = gExtensionMethodTable_gtlSetter_callSetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlSetter_callSetter.count ()) {
           f = gExtensionMethodTable_gtlSetter_callSetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlSetter_callSetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_fromLocation, in_lib, io_target, constin_actualArguments, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlSetter_callSetter (const cPtr_gtlSetter * inObject,
                                                  const GALGAS_location constinArgument_fromLocation,
                                                  GALGAS_library inArgument_lib,
                                                  GALGAS_gtlData & ioArgument_target,
                                                  const GALGAS_gtlDataList constinArgument_actualArguments,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlSetter * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlSetter) ;
  GALGAS_gtlData var_setterVariableMap_4736 ;
  GALGAS_bool var_ok_4746 ;
  const GALGAS_gtlSetter temp_0 = object ;
  callExtensionMethod_checkArguments ((const cPtr_gtlSetter *) temp_0.ptr (), constinArgument_fromLocation, constinArgument_actualArguments, var_setterVariableMap_4736, var_ok_4746, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 177)) ;
  const enumGalgasBool test_1 = var_ok_4746.boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_lstring var_selfName_4786 = GALGAS_lstring::constructor_new (GALGAS_string ("self"), constinArgument_fromLocation  COMMA_SOURCE_FILE ("gtl_module.galgas", 180)) ;
    {
    cPtr_gtlData * ptr_4844 = (cPtr_gtlData *) var_setterVariableMap_4736.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4844, var_selfName_4786, ioArgument_target, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 181)) ;
    }
    GALGAS_gtlContext var_setterContext_4925 = function_emptyContext (inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 185)) ;
    GALGAS_string var_outputString_4967 = GALGAS_string::makeEmptyString () ;
    extensionMethod_execute (object->mAttribute_instructions, var_setterContext_4925, var_setterVariableMap_4736, inArgument_lib, var_outputString_4967, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 187)) ;
    callExtensionMethod_structField ((const cPtr_gtlData *) var_setterVariableMap_4736.ptr (), var_selfName_4786, ioArgument_target, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 188)) ;
  }else if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_fromLocation, GALGAS_string ("setter call failed"), fixItArray2  COMMA_SOURCE_FILE ("gtl_module.galgas", 190)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlSetter_callSetter (void) {
  enterExtensionMethod_callSetter (kTypeDescriptor_GALGAS_gtlSetter.mSlotID,
                                   extensionMethod_gtlSetter_callSetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlSetter_callSetter (void) {
  gExtensionMethodTable_gtlSetter_callSetter.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlSetter_callSetter (defineExtensionMethod_gtlSetter_callSetter,
                                                 freeExtensionMethod_gtlSetter_callSetter) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlSetter typedName'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlSetter_typedName> gExtensionGetterTable_gtlSetter_typedName ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_typedName (const int32_t inClassIndex,
                                     enterExtensionGetter_gtlSetter_typedName inGetter) {
  gExtensionGetterTable_gtlSetter_typedName.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring callExtensionGetter_typedName (const cPtr_gtlSetter * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlSetter) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlSetter_typedName f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlSetter_typedName.count ()) {
      f = gExtensionGetterTable_gtlSetter_typedName (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlSetter_typedName.count ()) {
           f = gExtensionGetterTable_gtlSetter_typedName (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlSetter_typedName.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_lstring extensionGetter_gtlSetter_typedName (const cPtr_gtlSetter * inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlSetter * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlSetter) ;
  result_result = GALGAS_lstring::constructor_new (extensionGetter_typeName (object->mAttribute_targetType, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 197)).add_operation (object->mAttribute_name.getter_string (SOURCE_FILE ("gtl_module.galgas", 197)), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 197)), object->mAttribute_where  COMMA_SOURCE_FILE ("gtl_module.galgas", 197)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlSetter_typedName (void) {
  enterExtensionGetter_typedName (kTypeDescriptor_GALGAS_gtlSetter.mSlotID,
                                  extensionGetter_gtlSetter_typedName) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlSetter_typedName (void) {
  gExtensionGetterTable_gtlSetter_typedName.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlSetter_typedName (defineExtensionGetter_gtlSetter_typedName,
                                                freeExtensionGetter_gtlSetter_typedName) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Extension method '@gtlForeachStatementInstruction iterateOnMap'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlForeachStatementInstruction_iterateOnMap> gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnMap ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_iterateOnMap (const int32_t inClassIndex,
                                        extensionMethodSignature_gtlForeachStatementInstruction_iterateOnMap inMethod) {
  gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnMap.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_iterateOnMap (const cPtr_gtlForeachStatementInstruction * inObject,
                                       GALGAS_gtlContext & io_context,
                                       GALGAS_gtlData & io_vars,
                                       GALGAS_library & io_lib,
                                       GALGAS_string & io_outputString,
                                       const GALGAS_gtlMap constin_iterableMap,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlForeachStatementInstruction) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlForeachStatementInstruction_iterateOnMap f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnMap.count ()) {
      f = gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnMap (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnMap.count ()) {
           f = gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnMap (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnMap.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_context, io_vars, io_lib, io_outputString, constin_iterableMap, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlForeachStatementInstruction_iterateOnMap (const cPtr_gtlForeachStatementInstruction * inObject,
                                                                         GALGAS_gtlContext & ioArgument_context,
                                                                         GALGAS_gtlData & ioArgument_vars,
                                                                         GALGAS_library & ioArgument_lib,
                                                                         GALGAS_string & ioArgument_outputString,
                                                                         const GALGAS_gtlMap constinArgument_iterableMap,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlForeachStatementInstruction * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlForeachStatementInstruction) ;
  GALGAS_lstring temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, GALGAS_string::makeEmptyString ().objectCompare (object->mAttribute_keyName.getter_string (SOURCE_FILE ("gtl_instructions.galgas", 554)))).boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_lstring::constructor_new (GALGAS_string ("KEY"), object->mAttribute_keyName.getter_location (SOURCE_FILE ("gtl_instructions.galgas", 555))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 555)) ;
  }else if (kBoolFalse == test_1) {
    temp_0 = object->mAttribute_keyName ;
  }
  GALGAS_lstring var_actualKeyName_15941 = temp_0 ;
  cEnumerator_gtlVarMap enumerator_16054 (constinArgument_iterableMap.getter_value (SOURCE_FILE ("gtl_instructions.galgas", 560)), kEnumeration_up) ;
  GALGAS_uint index_16028 ((uint32_t) 0) ;
  const bool bool_2 = true ;
  if (enumerator_16054.hasCurrentObject () && bool_2) {
    extensionMethod_execute (object->mAttribute_beforeList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 562)) ;
    while (enumerator_16054.hasCurrentObject () && bool_2) {
      {
      cPtr_gtlData * ptr_16151 = (cPtr_gtlData *) ioArgument_vars.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_16151, object->mAttribute_variableName, enumerator_16054.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 564)) ;
      }
      {
      cPtr_gtlData * ptr_16200 = (cPtr_gtlData *) ioArgument_vars.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_16200, var_actualKeyName_15941, GALGAS_gtlString::constructor_new (object->mAttribute_keyName.getter_location (SOURCE_FILE ("gtl_instructions.galgas", 566)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 566)), enumerator_16054.current_lkey (HERE).getter_string (SOURCE_FILE ("gtl_instructions.galgas", 566))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 566)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 565)) ;
      }
      {
      cPtr_gtlData * ptr_16314 = (cPtr_gtlData *) ioArgument_vars.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_16314, object->mAttribute_indexName, GALGAS_gtlInt::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 569)), index_16028.getter_bigint (SOURCE_FILE ("gtl_instructions.galgas", 569))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 569)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 568)) ;
      }
      extensionMethod_execute (object->mAttribute_doList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 571)) ;
      enumerator_16054.gotoNextObject () ;
      index_16028.increment () ;
      if (enumerator_16054.hasCurrentObject () && bool_2) {
        extensionMethod_execute (object->mAttribute_betweenList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 573)) ;
      }
    }
    extensionMethod_execute (object->mAttribute_afterList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 575)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlForeachStatementInstruction_iterateOnMap (void) {
  enterExtensionMethod_iterateOnMap (kTypeDescriptor_GALGAS_gtlForeachStatementInstruction.mSlotID,
                                     extensionMethod_gtlForeachStatementInstruction_iterateOnMap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlForeachStatementInstruction_iterateOnMap (void) {
  gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnMap.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlForeachStatementInstruction_iterateOnMap (defineExtensionMethod_gtlForeachStatementInstruction_iterateOnMap,
                                                                        freeExtensionMethod_gtlForeachStatementInstruction_iterateOnMap) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Extension method '@gtlForeachStatementInstruction iterateOnList'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlForeachStatementInstruction_iterateOnList> gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnList ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_iterateOnList (const int32_t inClassIndex,
                                         extensionMethodSignature_gtlForeachStatementInstruction_iterateOnList inMethod) {
  gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnList.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_iterateOnList (const cPtr_gtlForeachStatementInstruction * inObject,
                                        GALGAS_gtlContext & io_context,
                                        GALGAS_gtlData & io_vars,
                                        GALGAS_library & io_lib,
                                        GALGAS_string & io_outputString,
                                        const GALGAS_gtlList constin_iterableList,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlForeachStatementInstruction) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlForeachStatementInstruction_iterateOnList f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnList.count ()) {
      f = gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnList (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnList.count ()) {
           f = gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnList (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnList.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_context, io_vars, io_lib, io_outputString, constin_iterableList, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlForeachStatementInstruction_iterateOnList (const cPtr_gtlForeachStatementInstruction * inObject,
                                                                          GALGAS_gtlContext & ioArgument_context,
                                                                          GALGAS_gtlData & ioArgument_vars,
                                                                          GALGAS_library & ioArgument_lib,
                                                                          GALGAS_string & ioArgument_outputString,
                                                                          const GALGAS_gtlList constinArgument_iterableList,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlForeachStatementInstruction * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlForeachStatementInstruction) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, GALGAS_string::makeEmptyString ().objectCompare (object->mAttribute_keyName.getter_string (SOURCE_FILE ("gtl_instructions.galgas", 586)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticWarning (object->mAttribute_keyName.getter_location (SOURCE_FILE ("gtl_instructions.galgas", 587)), GALGAS_string ("a key variable cannot be define when iterating on a list"), fixItArray1  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 587)) ;
  }
  cEnumerator_list enumerator_16947 (constinArgument_iterableList.getter_value (SOURCE_FILE ("gtl_instructions.galgas", 589)), kEnumeration_up) ;
  GALGAS_uint index_16920 ((uint32_t) 0) ;
  const bool bool_2 = true ;
  if (enumerator_16947.hasCurrentObject () && bool_2) {
    extensionMethod_execute (object->mAttribute_beforeList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 591)) ;
    while (enumerator_16947.hasCurrentObject () && bool_2) {
      {
      cPtr_gtlData * ptr_17044 = (cPtr_gtlData *) ioArgument_vars.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_17044, object->mAttribute_variableName, enumerator_16947.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 593)) ;
      }
      {
      cPtr_gtlData * ptr_17093 = (cPtr_gtlData *) ioArgument_vars.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_17093, object->mAttribute_indexName, GALGAS_gtlInt::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 595)), index_16920.getter_bigint (SOURCE_FILE ("gtl_instructions.galgas", 595))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 595)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 594)) ;
      }
      extensionMethod_execute (object->mAttribute_doList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 597)) ;
      enumerator_16947.gotoNextObject () ;
      index_16920.increment () ;
      if (enumerator_16947.hasCurrentObject () && bool_2) {
        extensionMethod_execute (object->mAttribute_betweenList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 599)) ;
      }
    }
    extensionMethod_execute (object->mAttribute_afterList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 601)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlForeachStatementInstruction_iterateOnList (void) {
  enterExtensionMethod_iterateOnList (kTypeDescriptor_GALGAS_gtlForeachStatementInstruction.mSlotID,
                                      extensionMethod_gtlForeachStatementInstruction_iterateOnList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlForeachStatementInstruction_iterateOnList (void) {
  gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnList.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlForeachStatementInstruction_iterateOnList (defineExtensionMethod_gtlForeachStatementInstruction_iterateOnList,
                                                                         freeExtensionMethod_gtlForeachStatementInstruction_iterateOnList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Extension method '@gtlForeachStatementInstruction iterateOnSet'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlForeachStatementInstruction_iterateOnSet> gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnSet ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_iterateOnSet (const int32_t inClassIndex,
                                        extensionMethodSignature_gtlForeachStatementInstruction_iterateOnSet inMethod) {
  gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnSet.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_iterateOnSet (const cPtr_gtlForeachStatementInstruction * inObject,
                                       GALGAS_gtlContext & io_context,
                                       GALGAS_gtlData & io_vars,
                                       GALGAS_library & io_lib,
                                       GALGAS_string & io_outputString,
                                       const GALGAS_gtlSet constin_iterableSet,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlForeachStatementInstruction) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlForeachStatementInstruction_iterateOnSet f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnSet.count ()) {
      f = gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnSet (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnSet.count ()) {
           f = gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnSet (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnSet.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_context, io_vars, io_lib, io_outputString, constin_iterableSet, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlForeachStatementInstruction_iterateOnSet (const cPtr_gtlForeachStatementInstruction * inObject,
                                                                         GALGAS_gtlContext & ioArgument_context,
                                                                         GALGAS_gtlData & ioArgument_vars,
                                                                         GALGAS_library & ioArgument_lib,
                                                                         GALGAS_string & ioArgument_outputString,
                                                                         const GALGAS_gtlSet constinArgument_iterableSet,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlForeachStatementInstruction * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlForeachStatementInstruction) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, GALGAS_string::makeEmptyString ().objectCompare (object->mAttribute_keyName.getter_string (SOURCE_FILE ("gtl_instructions.galgas", 612)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticWarning (object->mAttribute_keyName.getter_location (SOURCE_FILE ("gtl_instructions.galgas", 613)), GALGAS_string ("a key variable cannot be define when iterating on a set"), fixItArray1  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 613)) ;
  }
  cEnumerator_stringset enumerator_17717 (constinArgument_iterableSet.getter_value (SOURCE_FILE ("gtl_instructions.galgas", 615)), kEnumeration_up) ;
  GALGAS_uint index_17691 ((uint32_t) 0) ;
  const bool bool_2 = true ;
  if (enumerator_17717.hasCurrentObject () && bool_2) {
    extensionMethod_execute (object->mAttribute_beforeList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 617)) ;
    while (enumerator_17717.hasCurrentObject () && bool_2) {
      {
      cPtr_gtlData * ptr_17814 = (cPtr_gtlData *) ioArgument_vars.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_17814, object->mAttribute_variableName, GALGAS_gtlString::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 621)), enumerator_17717.current_key (HERE)  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 621)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 619)) ;
      }
      {
      cPtr_gtlData * ptr_17921 = (cPtr_gtlData *) ioArgument_vars.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_17921, object->mAttribute_indexName, GALGAS_gtlInt::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 624)), index_17691.getter_bigint (SOURCE_FILE ("gtl_instructions.galgas", 624))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 624)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 623)) ;
      }
      extensionMethod_execute (object->mAttribute_doList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 626)) ;
      enumerator_17717.gotoNextObject () ;
      index_17691.increment () ;
      if (enumerator_17717.hasCurrentObject () && bool_2) {
        extensionMethod_execute (object->mAttribute_betweenList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 628)) ;
      }
    }
    extensionMethod_execute (object->mAttribute_afterList, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 630)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlForeachStatementInstruction_iterateOnSet (void) {
  enterExtensionMethod_iterateOnSet (kTypeDescriptor_GALGAS_gtlForeachStatementInstruction.mSlotID,
                                     extensionMethod_gtlForeachStatementInstruction_iterateOnSet) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlForeachStatementInstruction_iterateOnSet (void) {
  gExtensionMethodTable_gtlForeachStatementInstruction_iterateOnSet.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlForeachStatementInstruction_iterateOnSet (defineExtensionMethod_gtlForeachStatementInstruction_iterateOnSet,
                                                                        freeExtensionMethod_gtlForeachStatementInstruction_iterateOnSet) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Abstract extension getter '@impType mergeWithType'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_impType_mergeWithType> gExtensionGetterTable_impType_mergeWithType ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_mergeWithType (const int32_t inClassIndex,
                                         enterExtensionGetter_impType_mergeWithType inGetter) {
  gExtensionGetterTable_impType_mergeWithType.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_impType_mergeWithType (void) {
  gExtensionGetterTable_impType_mergeWithType.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impType_mergeWithType (NULL,
                                                  freeExtensionGetter_impType_mergeWithType) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impType callExtensionGetter_mergeWithType (const cPtr_impType * inObject,
                                                  GALGAS_impType in_typeToMerge,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_impType result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_impType) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_impType_mergeWithType f = NULL ;
    if (classIndex < gExtensionGetterTable_impType_mergeWithType.count ()) {
      f = gExtensionGetterTable_impType_mergeWithType (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_impType_mergeWithType.count ()) {
           f = gExtensionGetterTable_impType_mergeWithType (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_impType_mergeWithType.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_typeToMerge, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@impType autoAllowed'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_impType_autoAllowed> gExtensionGetterTable_impType_autoAllowed ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_autoAllowed (const int32_t inClassIndex,
                                       enterExtensionGetter_impType_autoAllowed inGetter) {
  gExtensionGetterTable_impType_autoAllowed.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_autoAllowed (const cPtr_impType * inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_impType) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_impType_autoAllowed f = NULL ;
    if (classIndex < gExtensionGetterTable_impType_autoAllowed.count ()) {
      f = gExtensionGetterTable_impType_autoAllowed (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_impType_autoAllowed.count ()) {
           f = gExtensionGetterTable_impType_autoAllowed (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_impType_autoAllowed.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_bool extensionGetter_impType_autoAllowed (const cPtr_impType * /* inObject */,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (false) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impType_autoAllowed (void) {
  enterExtensionGetter_autoAllowed (kTypeDescriptor_GALGAS_impType.mSlotID,
                                    extensionGetter_impType_autoAllowed) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_impType_autoAllowed (void) {
  gExtensionGetterTable_impType_autoAllowed.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impType_autoAllowed (defineExtensionGetter_impType_autoAllowed,
                                                freeExtensionGetter_impType_autoAllowed) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension method '@impAutoDefaultType setDefault'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_impAutoDefaultType_setDefault> gExtensionMethodTable_impAutoDefaultType_setDefault ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_setDefault (const int32_t inClassIndex,
                                      extensionMethodSignature_impAutoDefaultType_setDefault inMethod) {
  gExtensionMethodTable_impAutoDefaultType_setDefault.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_setDefault (const cPtr_impAutoDefaultType * inObject,
                                     GALGAS_objectAttributes & io_attributes,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_impAutoDefaultType) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_impAutoDefaultType_setDefault f = NULL ;
    if (classIndex < gExtensionMethodTable_impAutoDefaultType_setDefault.count ()) {
      f = gExtensionMethodTable_impAutoDefaultType_setDefault (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_impAutoDefaultType_setDefault.count ()) {
           f = gExtensionMethodTable_impAutoDefaultType_setDefault (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_impAutoDefaultType_setDefault.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_attributes, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impAutoDefaultType_setDefault (const cPtr_impAutoDefaultType * inObject,
                                                           GALGAS_objectAttributes & ioArgument_attributes,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impAutoDefaultType * object = inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  const enumGalgasBool test_0 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 489)).getter_hasKey (object->mAttribute_name.getter_string (SOURCE_FILE ("implementation_types.galgas", 489)) COMMA_SOURCE_FILE ("implementation_types.galgas", 489)).operator_not (SOURCE_FILE ("implementation_types.galgas", 489)).boolEnum () ;
  if (kBoolTrue == test_0) {
    if (object->mAttribute_defaultValue.isValid ()) {
      if (object->mAttribute_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_void) {
      }else if (object->mAttribute_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
        GALGAS_identifierMap var_attr_13319 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 493)) ;
        {
        var_attr_13319.setter_put (object->mAttribute_name, object->mAttribute_defaultValue, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 494)) ;
        }
        {
        ioArgument_attributes.setter_setObjectParams (var_attr_13319 COMMA_SOURCE_FILE ("implementation_types.galgas", 495)) ;
        }
      }else{
        GALGAS_identifierMap var_attr_13515 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 498)) ;
        {
        var_attr_13515.setter_put (object->mAttribute_name, object->mAttribute_defaultValue, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 499)) ;
        }
        {
        ioArgument_attributes.setter_setObjectParams (var_attr_13515 COMMA_SOURCE_FILE ("implementation_types.galgas", 500)) ;
        }
      }
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impAutoDefaultType_setDefault (void) {
  enterExtensionMethod_setDefault (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                   extensionMethod_impAutoDefaultType_setDefault) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_impAutoDefaultType_setDefault (void) {
  gExtensionMethodTable_impAutoDefaultType_setDefault.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impAutoDefaultType_setDefault (defineExtensionMethod_impAutoDefaultType_setDefault,
                                                          freeExtensionMethod_impAutoDefaultType_setDefault) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Extension method '@impType checkAttributeReferences'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_impType_checkAttributeReferences> gExtensionMethodTable_impType_checkAttributeReferences ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_checkAttributeReferences (const int32_t inClassIndex,
                                                    extensionMethodSignature_impType_checkAttributeReferences inMethod) {
  gExtensionMethodTable_impType_checkAttributeReferences.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_checkAttributeReferences (const cPtr_impType * inObject,
                                                   const GALGAS_implementation constin_imp,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_impType) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_impType_checkAttributeReferences f = NULL ;
    if (classIndex < gExtensionMethodTable_impType_checkAttributeReferences.count ()) {
      f = gExtensionMethodTable_impType_checkAttributeReferences (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_impType_checkAttributeReferences.count ()) {
           f = gExtensionMethodTable_impType_checkAttributeReferences (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_impType_checkAttributeReferences.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_imp, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impType_checkAttributeReferences (const cPtr_impType * /* inObject */,
                                                              const GALGAS_implementation /* constinArgument_imp */,
                                                              C_Compiler * /* inCompiler */
                                                              COMMA_UNUSED_LOCATION_ARGS) {
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impType_checkAttributeReferences (void) {
  enterExtensionMethod_checkAttributeReferences (kTypeDescriptor_GALGAS_impType.mSlotID,
                                                 extensionMethod_impType_checkAttributeReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_impType_checkAttributeReferences (void) {
  gExtensionMethodTable_impType_checkAttributeReferences.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impType_checkAttributeReferences (defineExtensionMethod_impType_checkAttributeReferences,
                                                             freeExtensionMethod_impType_checkAttributeReferences) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Extension getter '@implementationObject mergeImplementationObjectWith'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_implementationObject_mergeImplementationObjectWith> gExtensionGetterTable_implementationObject_mergeImplementationObjectWith ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_mergeImplementationObjectWith (const int32_t inClassIndex,
                                                         enterExtensionGetter_implementationObject_mergeImplementationObjectWith inGetter) {
  gExtensionGetterTable_implementationObject_mergeImplementationObjectWith.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObject callExtensionGetter_mergeImplementationObjectWith (const cPtr_implementationObject * inObject,
                                                                               const GALGAS_implementationObject & in_objToMerge,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) {
  GALGAS_implementationObject result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_implementationObject) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_implementationObject_mergeImplementationObjectWith f = NULL ;
    if (classIndex < gExtensionGetterTable_implementationObject_mergeImplementationObjectWith.count ()) {
      f = gExtensionGetterTable_implementationObject_mergeImplementationObjectWith (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_implementationObject_mergeImplementationObjectWith.count ()) {
           f = gExtensionGetterTable_implementationObject_mergeImplementationObjectWith (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_implementationObject_mergeImplementationObjectWith.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_objToMerge, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_implementationObject extensionGetter_implementationObject_mergeImplementationObjectWith (const cPtr_implementationObject * inObject,
                                                                                                       const GALGAS_implementationObject & constinArgument_objToMerge,
                                                                                                       C_Compiler * inCompiler
                                                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObject result_mergedObj ; // Returned variable
  const cPtr_implementationObject * object = inObject ;
  macroValidSharedObject (object, cPtr_implementationObject) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mAttribute_multiple.objectCompare (constinArgument_objToMerge.getter_multiple (SOURCE_FILE ("implementation_types.galgas", 986)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (gOption_goil_5F_options_warnMultiple.getter_value ()).boolEnum () ;
    if (kBoolTrue == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticWarning (constinArgument_objToMerge.getter_multiple (SOURCE_FILE ("implementation_types.galgas", 988)).getter_location (SOURCE_FILE ("implementation_types.galgas", 988)), GALGAS_string ("multiple redefinition"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 988)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticWarning (object->mAttribute_multiple.getter_location (SOURCE_FILE ("implementation_types.galgas", 989)), GALGAS_string ("was defined here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 989)) ;
    }
  }
  result_mergedObj = GALGAS_implementationObject::constructor_new (object->mAttribute_multiple, extensionGetter_mergeImplementationObjectAttributesWith (object->mAttribute_attributes, constinArgument_objToMerge.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 1002)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1002))  COMMA_SOURCE_FILE ("implementation_types.galgas", 1002)) ;
//---
  return result_mergedObj ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_implementationObject_mergeImplementationObjectWith (void) {
  enterExtensionGetter_mergeImplementationObjectWith (kTypeDescriptor_GALGAS_implementationObject.mSlotID,
                                                      extensionGetter_implementationObject_mergeImplementationObjectWith) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_implementationObject_mergeImplementationObjectWith (void) {
  gExtensionGetterTable_implementationObject_mergeImplementationObjectWith.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_implementationObject_mergeImplementationObjectWith (defineExtensionGetter_implementationObject_mergeImplementationObjectWith,
                                                                               freeExtensionGetter_implementationObject_mergeImplementationObjectWith) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Extension method '@object_t set'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_object_5F_t_set> gExtensionMethodTable_object_5F_t_set ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_set (const int32_t inClassIndex,
                               extensionMethodSignature_object_5F_t_set inMethod) {
  gExtensionMethodTable_object_5F_t_set.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_set (const cPtr_object_5F_t * inObject,
                              const GALGAS_lstring constin_name,
                              GALGAS_gtlData & io_result,
                              C_Compiler * inCompiler
                              COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_object_5F_t) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_object_5F_t_set f = NULL ;
    if (classIndex < gExtensionMethodTable_object_5F_t_set.count ()) {
      f = gExtensionMethodTable_object_5F_t_set (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_object_5F_t_set.count ()) {
           f = gExtensionMethodTable_object_5F_t_set (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_object_5F_t_set.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_name, io_result, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_object_5F_t_set (const cPtr_object_5F_t * /* inObject */,
                                             const GALGAS_lstring constinArgument_name,
                                             GALGAS_gtlData & /* ioArgument_result */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 28)), GALGAS_string ("Attribute: ").add_operation (constinArgument_name.getter_string (SOURCE_FILE ("systemConfig.galgas", 28)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 28)).add_operation (GALGAS_string (", Internal error"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 28)), fixItArray0  COMMA_SOURCE_FILE ("systemConfig.galgas", 28)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_object_5F_t_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_object_5F_t.mSlotID,
                            extensionMethod_object_5F_t_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_object_5F_t_set (void) {
  gExtensionMethodTable_object_5F_t_set.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_object_5F_t_set (defineExtensionMethod_object_5F_t_set,
                                            freeExtensionMethod_object_5F_t_set) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Extension getter '@applicationDefinition applicationWithDefaults'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_applicationDefinition_applicationWithDefaults> gExtensionGetterTable_applicationDefinition_applicationWithDefaults ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_applicationWithDefaults (const int32_t inClassIndex,
                                                   enterExtensionGetter_applicationDefinition_applicationWithDefaults inGetter) {
  gExtensionGetterTable_applicationDefinition_applicationWithDefaults.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_applicationDefinition callExtensionGetter_applicationWithDefaults (const cPtr_applicationDefinition * inObject,
                                                                          const GALGAS_implementation & in_imp,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_applicationDefinition result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_applicationDefinition) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_applicationDefinition_applicationWithDefaults f = NULL ;
    if (classIndex < gExtensionGetterTable_applicationDefinition_applicationWithDefaults.count ()) {
      f = gExtensionGetterTable_applicationDefinition_applicationWithDefaults (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_applicationDefinition_applicationWithDefaults.count ()) {
           f = gExtensionGetterTable_applicationDefinition_applicationWithDefaults (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_applicationDefinition_applicationWithDefaults.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_imp, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_applicationDefinition extensionGetter_applicationDefinition_applicationWithDefaults (const cPtr_applicationDefinition * inObject,
                                                                                                   const GALGAS_implementation & /* constinArgument_imp */,
                                                                                                   C_Compiler * /* inCompiler */
                                                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_applicationDefinition result_result ; // Returned variable
  const cPtr_applicationDefinition * object = inObject ;
  macroValidSharedObject (object, cPtr_applicationDefinition) ;
  const GALGAS_applicationDefinition temp_0 = object ;
  result_result = temp_0 ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_applicationDefinition_applicationWithDefaults (void) {
  enterExtensionGetter_applicationWithDefaults (kTypeDescriptor_GALGAS_applicationDefinition.mSlotID,
                                                extensionGetter_applicationDefinition_applicationWithDefaults) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_applicationDefinition_applicationWithDefaults (void) {
  gExtensionGetterTable_applicationDefinition_applicationWithDefaults.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_applicationDefinition_applicationWithDefaults (defineExtensionGetter_applicationDefinition_applicationWithDefaults,
                                                                          freeExtensionGetter_applicationDefinition_applicationWithDefaults) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Extension method '@implementationObject verifyApplication'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_implementationObject_verifyApplication> gExtensionMethodTable_implementationObject_verifyApplication ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_verifyApplication (const int32_t inClassIndex,
                                             extensionMethodSignature_implementationObject_verifyApplication inMethod) {
  gExtensionMethodTable_implementationObject_verifyApplication.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_verifyApplication (const cPtr_implementationObject * inObject,
                                            const GALGAS_objectKind constin_objectsOfKind,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_implementationObject) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_implementationObject_verifyApplication f = NULL ;
    if (classIndex < gExtensionMethodTable_implementationObject_verifyApplication.count ()) {
      f = gExtensionMethodTable_implementationObject_verifyApplication (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_implementationObject_verifyApplication.count ()) {
           f = gExtensionMethodTable_implementationObject_verifyApplication (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_implementationObject_verifyApplication.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_objectsOfKind, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_implementationObject_verifyApplication (const cPtr_implementationObject * inObject,
                                                                    const GALGAS_objectKind constinArgument_objectsOfKind,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_implementationObject * object = inObject ;
  macroValidSharedObject (object, cPtr_implementationObject) ;
  cEnumerator_objectKindMap enumerator_1305 (constinArgument_objectsOfKind.getter_objects (SOURCE_FILE ("semantic_verification.galgas", 46)), kEnumeration_up) ;
  while (enumerator_1305.hasCurrentObject ()) {
    cEnumerator_implementationObjectMap enumerator_1334 (object->mAttribute_attributes, kEnumeration_up) ;
    while (enumerator_1334.hasCurrentObject ()) {
      callExtensionMethod_verifyApplication ((const cPtr_impType *) enumerator_1334.current_type (HERE).ptr (), enumerator_1305.current_attributes (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 48)) ;
      enumerator_1334.gotoNextObject () ;
    }
    enumerator_1305.gotoNextObject () ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_implementationObject_verifyApplication (void) {
  enterExtensionMethod_verifyApplication (kTypeDescriptor_GALGAS_implementationObject.mSlotID,
                                          extensionMethod_implementationObject_verifyApplication) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_implementationObject_verifyApplication (void) {
  gExtensionMethodTable_implementationObject_verifyApplication.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_implementationObject_verifyApplication (defineExtensionMethod_implementationObject_verifyApplication,
                                                                   freeExtensionMethod_implementationObject_verifyApplication) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension method '@impType verifyApplication'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_impType_verifyApplication> gExtensionMethodTable_impType_verifyApplication ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_verifyApplication (const int32_t inClassIndex,
                                             extensionMethodSignature_impType_verifyApplication inMethod) {
  gExtensionMethodTable_impType_verifyApplication.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_verifyApplication (const cPtr_impType * inObject,
                                            const GALGAS_objectAttributes constin_attrs,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_impType) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_impType_verifyApplication f = NULL ;
    if (classIndex < gExtensionMethodTable_impType_verifyApplication.count ()) {
      f = gExtensionMethodTable_impType_verifyApplication (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_impType_verifyApplication.count ()) {
           f = gExtensionMethodTable_impType_verifyApplication (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_impType_verifyApplication.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_attrs, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impType_verifyApplication (const cPtr_impType * inObject,
                                                       const GALGAS_objectAttributes constinArgument_attrs,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impType * object = inObject ;
  macroValidSharedObject (object, cPtr_impType) ;
  cEnumerator_identifierMap enumerator_1580 (constinArgument_attrs.getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 56)), kEnumeration_up) ;
  while (enumerator_1580.hasCurrentObject ()) {
    const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_1580.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 57)).objectCompare (object->mAttribute_name.getter_string (SOURCE_FILE ("semantic_verification.galgas", 57)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_impType temp_1 = object ;
      callExtensionMethod_verifyMultipleType ((const cPtr_impType *) temp_1.ptr (), enumerator_1580.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 58)) ;
    }
    enumerator_1580.gotoNextObject () ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impType_verifyApplication (void) {
  enterExtensionMethod_verifyApplication (kTypeDescriptor_GALGAS_impType.mSlotID,
                                          extensionMethod_impType_verifyApplication) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_impType_verifyApplication (void) {
  gExtensionMethodTable_impType_verifyApplication.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impType_verifyApplication (defineExtensionMethod_impType_verifyApplication,
                                                      freeExtensionMethod_impType_verifyApplication) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension method '@impType verifyType'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_impType_verifyType> gExtensionMethodTable_impType_verifyType ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_verifyType (const int32_t inClassIndex,
                                      extensionMethodSignature_impType_verifyType inMethod) {
  gExtensionMethodTable_impType_verifyType.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_verifyType (const cPtr_impType * inObject,
                                     const GALGAS_object_5F_t constin_attr,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_impType) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_impType_verifyType f = NULL ;
    if (classIndex < gExtensionMethodTable_impType_verifyType.count ()) {
      f = gExtensionMethodTable_impType_verifyType (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_impType_verifyType.count ()) {
           f = gExtensionMethodTable_impType_verifyType (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_impType_verifyType.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_attr, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impType_verifyType (const cPtr_impType * /* inObject */,
                                                const GALGAS_object_5F_t constinArgument_attr,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 66)), GALGAS_string ("Internal error, a generic type should not be instantiated"), fixItArray0  COMMA_SOURCE_FILE ("semantic_verification.galgas", 66)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impType.mSlotID,
                                   extensionMethod_impType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_impType_verifyType (void) {
  gExtensionMethodTable_impType_verifyType.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impType_verifyType (defineExtensionMethod_impType_verifyType,
                                               freeExtensionMethod_impType_verifyType) ;


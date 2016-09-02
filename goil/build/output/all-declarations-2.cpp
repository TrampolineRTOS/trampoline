#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-2.h"


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_sint_33__32_AttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_33__32_AttributeMinMax * p = (const cPtr_sint_33__32_AttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_33__32_AttributeMinMax) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_min.objectCompare (p->mAttribute_min) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_max.objectCompare (p->mAttribute_max) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeMinMax::GALGAS_sint_33__32_AttributeMinMax (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeMinMax GALGAS_sint_33__32_AttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                              GALGAS_sint::constructor_default (HERE),
                                                              GALGAS_sint::constructor_default (HERE)
                                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeMinMax::GALGAS_sint_33__32_AttributeMinMax (const cPtr_sint_33__32_AttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_33__32_AttributeMinMax) ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint_33__32_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_33__32_AttributeMinMax * p = (const cPtr_sint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32_AttributeMinMax) ;
    result = p->mAttribute_min ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint cPtr_sint_33__32_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mAttribute_min ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint_33__32_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_33__32_AttributeMinMax * p = (const cPtr_sint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32_AttributeMinMax) ;
    result = p->mAttribute_max ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint cPtr_sint_33__32_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mAttribute_max ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @sint32AttributeMinMax class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_sint_33__32_AttributeMinMax::cPtr_sint_33__32_AttributeMinMax (const GALGAS_location & in_location,
                                                                    const GALGAS_sint & in_min,
                                                                    const GALGAS_sint & in_max
                                                                    COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_min (in_min),
mAttribute_max (in_max) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_sint_33__32_AttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax ;
}

void cPtr_sint_33__32_AttributeMinMax::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@sint32AttributeMinMax:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_sint_33__32_AttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_sint_33__32_AttributeMinMax (mAttribute_location, mAttribute_min, mAttribute_max COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @sint32AttributeMinMax type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax ("sint32AttributeMinMax",
                                                    & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sint_33__32_AttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sint_33__32_AttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_33__32_AttributeMinMax (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeMinMax GALGAS_sint_33__32_AttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_AttributeMinMax result ;
  const GALGAS_sint_33__32_AttributeMinMax * p = (const GALGAS_sint_33__32_AttributeMinMax *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_33__32_AttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint32AttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_sint_36__34_AttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_36__34_AttributeMinMax * p = (const cPtr_sint_36__34_AttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_36__34_AttributeMinMax) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_min.objectCompare (p->mAttribute_min) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_max.objectCompare (p->mAttribute_max) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeMinMax::GALGAS_sint_36__34_AttributeMinMax (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeMinMax GALGAS_sint_36__34_AttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                              GALGAS_sint_36__34_::constructor_default (HERE),
                                                              GALGAS_sint_36__34_::constructor_default (HERE)
                                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeMinMax::GALGAS_sint_36__34_AttributeMinMax (const cPtr_sint_36__34_AttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_36__34_AttributeMinMax) ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_36__34_AttributeMinMax * p = (const cPtr_sint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34_AttributeMinMax) ;
    result = p->mAttribute_min ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ cPtr_sint_36__34_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mAttribute_min ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_36__34_AttributeMinMax * p = (const cPtr_sint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34_AttributeMinMax) ;
    result = p->mAttribute_max ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ cPtr_sint_36__34_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mAttribute_max ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @sint64AttributeMinMax class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_sint_36__34_AttributeMinMax::cPtr_sint_36__34_AttributeMinMax (const GALGAS_location & in_location,
                                                                    const GALGAS_sint_36__34_ & in_min,
                                                                    const GALGAS_sint_36__34_ & in_max
                                                                    COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_min (in_min),
mAttribute_max (in_max) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_sint_36__34_AttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax ;
}

void cPtr_sint_36__34_AttributeMinMax::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@sint64AttributeMinMax:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_sint_36__34_AttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_sint_36__34_AttributeMinMax (mAttribute_location, mAttribute_min, mAttribute_max COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @sint64AttributeMinMax type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax ("sint64AttributeMinMax",
                                                    & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sint_36__34_AttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sint_36__34_AttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_36__34_AttributeMinMax (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeMinMax GALGAS_sint_36__34_AttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_AttributeMinMax result ;
  const GALGAS_sint_36__34_AttributeMinMax * p = (const GALGAS_sint_36__34_AttributeMinMax *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_36__34_AttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint64AttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_floatAttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_floatAttributeMinMax * p = (const cPtr_floatAttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_floatAttributeMinMax) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_min.objectCompare (p->mAttribute_min) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_max.objectCompare (p->mAttribute_max) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeMinMax::GALGAS_floatAttributeMinMax (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeMinMax GALGAS_floatAttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_floatAttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                       GALGAS_double::constructor_default (HERE),
                                                       GALGAS_double::constructor_default (HERE)
                                                       COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeMinMax::GALGAS_floatAttributeMinMax (const cPtr_floatAttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_floatAttributeMinMax) ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_floatAttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (NULL != mObjectPtr) {
    const cPtr_floatAttributeMinMax * p = (const cPtr_floatAttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_floatAttributeMinMax) ;
    result = p->mAttribute_min ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double cPtr_floatAttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mAttribute_min ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_floatAttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (NULL != mObjectPtr) {
    const cPtr_floatAttributeMinMax * p = (const cPtr_floatAttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_floatAttributeMinMax) ;
    result = p->mAttribute_max ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double cPtr_floatAttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mAttribute_max ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @floatAttributeMinMax class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_floatAttributeMinMax::cPtr_floatAttributeMinMax (const GALGAS_location & in_location,
                                                      const GALGAS_double & in_min,
                                                      const GALGAS_double & in_max
                                                      COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_min (in_min),
mAttribute_max (in_max) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_floatAttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatAttributeMinMax ;
}

void cPtr_floatAttributeMinMax::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@floatAttributeMinMax:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_floatAttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_floatAttributeMinMax (mAttribute_location, mAttribute_min, mAttribute_max COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @floatAttributeMinMax type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_floatAttributeMinMax ("floatAttributeMinMax",
                                             & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_floatAttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatAttributeMinMax ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_floatAttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_floatAttributeMinMax (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeMinMax GALGAS_floatAttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_floatAttributeMinMax result ;
  const GALGAS_floatAttributeMinMax * p = (const GALGAS_floatAttributeMinMax *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_floatAttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("floatAttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Class for element of '@locationList' list                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_locationList : public cCollectionElement {
  public : GALGAS_locationList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_locationList (const GALGAS_location & in_location
                                            COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_locationList::cCollectionElement_locationList (const GALGAS_location & in_location
                                                                  COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_location) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_locationList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_locationList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_locationList (mObject.mAttribute_location COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_locationList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "location" ":" ;
  mObject.mAttribute_location.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_locationList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_locationList * operand = (cCollectionElement_locationList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_locationList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList::GALGAS_locationList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList::GALGAS_locationList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList GALGAS_locationList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_locationList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList GALGAS_locationList::constructor_listWithValue (const GALGAS_location & inOperand0
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_locationList result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_locationList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_locationList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                     const GALGAS_location & in_location
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement_locationList * p = NULL ;
  macroMyNew (p, cCollectionElement_locationList (in_location COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_locationList::addAssign_operation (const GALGAS_location & inOperand0
                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_locationList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_locationList::setter_insertAtIndex (const GALGAS_location inOperand0,
                                                const GALGAS_uint inInsertionIndex,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_locationList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_locationList::setter_removeAtIndex (GALGAS_location & outOperand0,
                                                const GALGAS_uint inRemoveIndex,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_locationList * p = (cCollectionElement_locationList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_locationList) ;
      outOperand0 = p->mObject.mAttribute_location ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_locationList::setter_popFirst (GALGAS_location & outOperand0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_locationList * p = (cCollectionElement_locationList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_locationList) ;
    outOperand0 = p->mObject.mAttribute_location ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_locationList::setter_popLast (GALGAS_location & outOperand0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_locationList * p = (cCollectionElement_locationList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_locationList) ;
    outOperand0 = p->mObject.mAttribute_location ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_locationList::method_first (GALGAS_location & outOperand0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_locationList * p = (cCollectionElement_locationList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_locationList) ;
    outOperand0 = p->mObject.mAttribute_location ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_locationList::method_last (GALGAS_location & outOperand0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_locationList * p = (cCollectionElement_locationList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_locationList) ;
    outOperand0 = p->mObject.mAttribute_location ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList GALGAS_locationList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_locationList result = GALGAS_locationList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList GALGAS_locationList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_locationList result = GALGAS_locationList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList GALGAS_locationList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_locationList result = GALGAS_locationList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_locationList::plusAssign_operation (const GALGAS_locationList inOperand,
                                                C_Compiler * /* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_locationList::getter_locationAtIndex (const GALGAS_uint & inIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_locationList * p = (cCollectionElement_locationList *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_locationList) ;
    result = p->mObject.mAttribute_location ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_locationList::cEnumerator_locationList (const GALGAS_locationList & inEnumeratedObject,
                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList_2D_element cEnumerator_locationList::current (LOCATION_ARGS) const {
  const cCollectionElement_locationList * p = (const cCollectionElement_locationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_locationList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_locationList::current_location (LOCATION_ARGS) const {
  const cCollectionElement_locationList * p = (const cCollectionElement_locationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_locationList) ;
  return p->mObject.mAttribute_location ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @locationList type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_locationList ("locationList",
                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_locationList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_locationList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_locationList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_locationList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList GALGAS_locationList::extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_locationList result ;
  const GALGAS_locationList * p = (const GALGAS_locationList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_locationList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("locationList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_implementationObjectMap::cMapElement_implementationObjectMap (const GALGAS_lstring & inKey,
                                                                          const GALGAS_impType & in_type
                                                                          COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_type (in_type) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_implementationObjectMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_type.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_implementationObjectMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_implementationObjectMap (mAttribute_lkey, mAttribute_type COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_implementationObjectMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "type" ":" ;
  mAttribute_type.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_implementationObjectMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_implementationObjectMap * operand = (cMapElement_implementationObjectMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_type.objectCompare (operand->mAttribute_type) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap::GALGAS_implementationObjectMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap::GALGAS_implementationObjectMap (const GALGAS_implementationObjectMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap & GALGAS_implementationObjectMap::operator = (const GALGAS_implementationObjectMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap GALGAS_implementationObjectMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_implementationObjectMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap GALGAS_implementationObjectMap::constructor_mapWithMapToOverride (const GALGAS_implementationObjectMap & inMapToOverride
                                                                                                 COMMA_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap GALGAS_implementationObjectMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const {
  GALGAS_implementationObjectMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationObjectMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                          const GALGAS_impType & inArgument0,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  cMapElement_implementationObjectMap * p = NULL ;
  macroMyNew (p, cMapElement_implementationObjectMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@implementationObjectMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationObjectMap::setter_put (GALGAS_lstring inKey,
                                                 GALGAS_impType inArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cMapElement_implementationObjectMap * p = NULL ;
  macroMyNew (p, cMapElement_implementationObjectMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "%K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_implementationObjectMap_get = "%K does not exists" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationObjectMap::method_get (GALGAS_lstring inKey,
                                                 GALGAS_impType & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  const cMapElement_implementationObjectMap * p = (const cMapElement_implementationObjectMap *) performSearch (inKey,
                                                                                                                 inCompiler,
                                                                                                                 kSearchErrorMessage_implementationObjectMap_get
                                                                                                                 COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_implementationObjectMap) ;
    outArgument0 = p->mAttribute_type ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationObjectMap::setter_del (GALGAS_lstring inKey,
                                                 GALGAS_impType & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "%K does not exists" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_implementationObjectMap * p = (cMapElement_implementationObjectMap *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_implementationObjectMap) ;
    outArgument0 = p->mAttribute_type ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impType GALGAS_implementationObjectMap::getter_typeForKey (const GALGAS_string & inKey,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_implementationObjectMap * p = (const cMapElement_implementationObjectMap *) attributes ;
  GALGAS_impType result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_implementationObjectMap) ;
    result = p->mAttribute_type ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationObjectMap::setter_setTypeForKey (GALGAS_impType inAttributeValue,
                                                           GALGAS_string inKey,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_implementationObjectMap * p = (cMapElement_implementationObjectMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_implementationObjectMap) ;
    p->mAttribute_type = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_implementationObjectMap * GALGAS_implementationObjectMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                                         const GALGAS_string & inKey
                                                                                                         COMMA_LOCATION_ARGS) {
  cMapElement_implementationObjectMap * result = (cMapElement_implementationObjectMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_implementationObjectMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_implementationObjectMap::cEnumerator_implementationObjectMap (const GALGAS_implementationObjectMap & inEnumeratedObject,
                                                                          const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap_2D_element cEnumerator_implementationObjectMap::current (LOCATION_ARGS) const {
  const cMapElement_implementationObjectMap * p = (const cMapElement_implementationObjectMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_implementationObjectMap) ;
  return GALGAS_implementationObjectMap_2D_element (p->mAttribute_lkey, p->mAttribute_type) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_implementationObjectMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impType cEnumerator_implementationObjectMap::current_type (LOCATION_ARGS) const {
  const cMapElement_implementationObjectMap * p = (const cMapElement_implementationObjectMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_implementationObjectMap) ;
  return p->mAttribute_type ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @implementationObjectMap type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_implementationObjectMap ("implementationObjectMap",
                                                NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_implementationObjectMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementationObjectMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_implementationObjectMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_implementationObjectMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap GALGAS_implementationObjectMap::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result ;
  const GALGAS_implementationObjectMap * p = (const GALGAS_implementationObjectMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_implementationObjectMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("implementationObjectMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_enumValues::cMapElement_enumValues (const GALGAS_lstring & inKey,
                                                const GALGAS_implementationObjectMap & in_subAttributes
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_subAttributes (in_subAttributes) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_enumValues::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_subAttributes.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_enumValues::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_enumValues (mAttribute_lkey, mAttribute_subAttributes COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_enumValues::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "subAttributes" ":" ;
  mAttribute_subAttributes.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_enumValues::compare (const cCollectionElement * inOperand) const {
  cMapElement_enumValues * operand = (cMapElement_enumValues *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_subAttributes.objectCompare (operand->mAttribute_subAttributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumValues::GALGAS_enumValues (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumValues::GALGAS_enumValues (const GALGAS_enumValues & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumValues & GALGAS_enumValues::operator = (const GALGAS_enumValues & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumValues GALGAS_enumValues::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_enumValues result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumValues GALGAS_enumValues::constructor_mapWithMapToOverride (const GALGAS_enumValues & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_enumValues result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumValues GALGAS_enumValues::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_enumValues result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_enumValues::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_implementationObjectMap & inArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_enumValues * p = NULL ;
  macroMyNew (p, cMapElement_enumValues (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@enumValues insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_enumValues::setter_put (GALGAS_lstring inKey,
                                    GALGAS_implementationObjectMap inArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  cMapElement_enumValues * p = NULL ;
  macroMyNew (p, cMapElement_enumValues (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "%K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_enumValues_get = "%K does not exists" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_enumValues::method_get (GALGAS_lstring inKey,
                                    GALGAS_implementationObjectMap & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  const cMapElement_enumValues * p = (const cMapElement_enumValues *) performSearch (inKey,
                                                                                       inCompiler,
                                                                                       kSearchErrorMessage_enumValues_get
                                                                                       COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_enumValues) ;
    outArgument0 = p->mAttribute_subAttributes ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_enumValues::setter_del (GALGAS_lstring inKey,
                                    GALGAS_implementationObjectMap & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "%K does not exists" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_enumValues * p = (cMapElement_enumValues *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_enumValues) ;
    outArgument0 = p->mAttribute_subAttributes ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap GALGAS_enumValues::getter_subAttributesForKey (const GALGAS_string & inKey,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_enumValues * p = (const cMapElement_enumValues *) attributes ;
  GALGAS_implementationObjectMap result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_enumValues) ;
    result = p->mAttribute_subAttributes ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_enumValues::setter_setSubAttributesForKey (GALGAS_implementationObjectMap inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_enumValues * p = (cMapElement_enumValues *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_enumValues) ;
    p->mAttribute_subAttributes = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_enumValues * GALGAS_enumValues::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_enumValues * result = (cMapElement_enumValues *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_enumValues) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_enumValues::cEnumerator_enumValues (const GALGAS_enumValues & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumValues_2D_element cEnumerator_enumValues::current (LOCATION_ARGS) const {
  const cMapElement_enumValues * p = (const cMapElement_enumValues *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_enumValues) ;
  return GALGAS_enumValues_2D_element (p->mAttribute_lkey, p->mAttribute_subAttributes) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_enumValues::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap cEnumerator_enumValues::current_subAttributes (LOCATION_ARGS) const {
  const cMapElement_enumValues * p = (const cMapElement_enumValues *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_enumValues) ;
  return p->mAttribute_subAttributes ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @enumValues type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_enumValues ("enumValues",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_enumValues::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_enumValues ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_enumValues::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_enumValues (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumValues GALGAS_enumValues::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_enumValues result ;
  const GALGAS_enumValues * p = (const GALGAS_enumValues *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_enumValues *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("enumValues", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
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

cMapElement_implementationMap::cMapElement_implementationMap (const GALGAS_lstring & inKey,
                                                              const GALGAS_implementationObject & in_obj
                                                              COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_obj (in_obj) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_implementationMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_obj.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_implementationMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_implementationMap (mAttribute_lkey, mAttribute_obj COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_implementationMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "obj" ":" ;
  mAttribute_obj.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_implementationMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_implementationMap * operand = (cMapElement_implementationMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_obj.objectCompare (operand->mAttribute_obj) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap::GALGAS_implementationMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap::GALGAS_implementationMap (const GALGAS_implementationMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap & GALGAS_implementationMap::operator = (const GALGAS_implementationMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap GALGAS_implementationMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_implementationMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap GALGAS_implementationMap::constructor_mapWithMapToOverride (const GALGAS_implementationMap & inMapToOverride
                                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_implementationMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap GALGAS_implementationMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_implementationMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                    const GALGAS_implementationObject & inArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cMapElement_implementationMap * p = NULL ;
  macroMyNew (p, cMapElement_implementationMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@implementationMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationMap::setter_put (GALGAS_lstring inKey,
                                           GALGAS_implementationObject inArgument0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  cMapElement_implementationMap * p = NULL ;
  macroMyNew (p, cMapElement_implementationMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "%K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_implementationMap_get = "%K does not exists" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationMap::method_get (GALGAS_lstring inKey,
                                           GALGAS_implementationObject & outArgument0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  const cMapElement_implementationMap * p = (const cMapElement_implementationMap *) performSearch (inKey,
                                                                                                     inCompiler,
                                                                                                     kSearchErrorMessage_implementationMap_get
                                                                                                     COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_implementationMap) ;
    outArgument0 = p->mAttribute_obj ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationMap::setter_del (GALGAS_lstring inKey,
                                           GALGAS_implementationObject & outArgument0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "%K does not exists" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_implementationMap * p = (cMapElement_implementationMap *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_implementationMap) ;
    outArgument0 = p->mAttribute_obj ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObject GALGAS_implementationMap::getter_objForKey (const GALGAS_string & inKey,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_implementationMap * p = (const cMapElement_implementationMap *) attributes ;
  GALGAS_implementationObject result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_implementationMap) ;
    result = p->mAttribute_obj ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationMap::setter_setObjForKey (GALGAS_implementationObject inAttributeValue,
                                                    GALGAS_string inKey,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_implementationMap * p = (cMapElement_implementationMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_implementationMap) ;
    p->mAttribute_obj = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_implementationMap * GALGAS_implementationMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                             const GALGAS_string & inKey
                                                                                             COMMA_LOCATION_ARGS) {
  cMapElement_implementationMap * result = (cMapElement_implementationMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_implementationMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_implementationMap::cEnumerator_implementationMap (const GALGAS_implementationMap & inEnumeratedObject,
                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap_2D_element cEnumerator_implementationMap::current (LOCATION_ARGS) const {
  const cMapElement_implementationMap * p = (const cMapElement_implementationMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_implementationMap) ;
  return GALGAS_implementationMap_2D_element (p->mAttribute_lkey, p->mAttribute_obj) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_implementationMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObject cEnumerator_implementationMap::current_obj (LOCATION_ARGS) const {
  const cMapElement_implementationMap * p = (const cMapElement_implementationMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_implementationMap) ;
  return p->mAttribute_obj ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @implementationMap type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_implementationMap ("implementationMap",
                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_implementationMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementationMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_implementationMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_implementationMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap GALGAS_implementationMap::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_implementationMap result ;
  const GALGAS_implementationMap * p = (const GALGAS_implementationMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_implementationMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("implementationMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
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
//     L E X I Q U E                                                                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#include "strings/unicode_character_cpp.h"
#include "galgas2/scanner_actions.h"
#include "galgas2/cLexiqueIntrospection.h"

//---------------------------------------------------------------------------------------------------------------------*

cTokenFor_options_5F_scanner::cTokenFor_options_5F_scanner (void) :
mLexicalAttribute_floatNumber (),
mLexicalAttribute_integerNumber (),
mLexicalAttribute_key (),
mLexicalAttribute_number (),
mLexicalAttribute_string () {
}

//---------------------------------------------------------------------------------------------------------------------*

C_Lexique_options_5F_scanner::C_Lexique_options_5F_scanner (C_Compiler * inCallerCompiler,
                                                            const C_String & inDependencyFileExtension,
                                                            const C_String & inDependencyFilePath,
                                                            const C_String & inSourceFileName
                                                            COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inDependencyFileExtension, inDependencyFilePath, inSourceFileName COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

C_Lexique_options_5F_scanner::C_Lexique_options_5F_scanner (C_Compiler * inCallerCompiler,
                                                            const C_String & inSourceString,
                                                            const C_String & inStringForError
                                                            COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*
//                 I N D E X I N G    D I R E C T O R Y                                                                *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_options_5F_scanner::indexingDirectory (void) const {
  return "" ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                        Lexical error message list                                                                   *
//---------------------------------------------------------------------------------------------------------------------*

static const char * gLexicalMessage_options_5F_scanner_decimalNumberTooLarge = "decimal number too large" ;

static const char * gLexicalMessage_options_5F_scanner_internalError = "internal error" ;

static const char * gLexicalMessage_options_5F_scanner_unableToConvertToDouble = "Unable to convert the string to double" ;

static const char * gLexicalMessage_options_5F_scanner_unterminatedLitteralString = "Unterminated literal string" ;

//---------------------------------------------------------------------------------------------------------------------*
//          Syntax error messages, for every terminal symbol                                                           *
//---------------------------------------------------------------------------------------------------------------------*

//--- Syntax error message for terminal '$idf$' :
static const char * gSyntaxErrorMessage_options_5F_scanner_idf = "identifier" ;

//--- Syntax error message for terminal '$string$' :
static const char * gSyntaxErrorMessage_options_5F_scanner_string = "literal string" ;

//--- Syntax error message for terminal '$uint_number$' :
static const char * gSyntaxErrorMessage_options_5F_scanner_uint_5F_number = "literal unsigned 64 bits integer" ;

//--- Syntax error message for terminal '$float_number$' :
static const char * gSyntaxErrorMessage_options_5F_scanner_float_5F_number = "literal float" ;

//--- Syntax error message for terminal '$=$' :
static const char * gSyntaxErrorMessage_options_5F_scanner__3D_ = "'=' delimiter" ;

//--- Syntax error message for terminal '$,$' :
static const char * gSyntaxErrorMessage_options_5F_scanner__2C_ = "',' delimiter" ;

//--- Syntax error message for terminal '$-$' :
static const char * gSyntaxErrorMessage_options_5F_scanner__2D_ = "'-' delimiter" ;

//--- Syntax error message for terminal '$($' :
static const char * gSyntaxErrorMessage_options_5F_scanner__28_ = "'(' delimiter" ;

//--- Syntax error message for terminal '$)$' :
static const char * gSyntaxErrorMessage_options_5F_scanner__29_ = "')' delimiter" ;

//---------------------------------------------------------------------------------------------------------------------*
//                getMessageForTerminal                                                                                *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_options_5F_scanner::getMessageForTerminal (const int16_t inTerminalIndex) const {
  static const char * syntaxErrorMessageArray [10] = {kEndOfSourceLexicalErrorMessage,
    gSyntaxErrorMessage_options_5F_scanner_idf,
    gSyntaxErrorMessage_options_5F_scanner_string,
    gSyntaxErrorMessage_options_5F_scanner_uint_5F_number,
    gSyntaxErrorMessage_options_5F_scanner_float_5F_number,
    gSyntaxErrorMessage_options_5F_scanner__3D_,
    gSyntaxErrorMessage_options_5F_scanner__2C_,
    gSyntaxErrorMessage_options_5F_scanner__2D_,
    gSyntaxErrorMessage_options_5F_scanner__28_,
    gSyntaxErrorMessage_options_5F_scanner__29_} ;
  return syntaxErrorMessageArray [inTerminalIndex] ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                      U N I C O D E    S T R I N G S                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*
//             Key words table 'optionsDelimiters'                            *
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t ktable_size_options_5F_scanner_optionsDelimiters = 5 ;

static const C_unicode_lexique_table_entry ktable_for_options_5F_scanner_optionsDelimiters [ktable_size_options_5F_scanner_optionsDelimiters] = {
  C_unicode_lexique_table_entry (kUnicodeString_options_5F_scanner__28_, 1, C_Lexique_options_5F_scanner::kToken__28_),
  C_unicode_lexique_table_entry (kUnicodeString_options_5F_scanner__29_, 1, C_Lexique_options_5F_scanner::kToken__29_),
  C_unicode_lexique_table_entry (kUnicodeString_options_5F_scanner__2C_, 1, C_Lexique_options_5F_scanner::kToken__2C_),
  C_unicode_lexique_table_entry (kUnicodeString_options_5F_scanner__2D_, 1, C_Lexique_options_5F_scanner::kToken__2D_),
  C_unicode_lexique_table_entry (kUnicodeString_options_5F_scanner__3D_, 1, C_Lexique_options_5F_scanner::kToken__3D_)
} ;

int16_t C_Lexique_options_5F_scanner::search_into_optionsDelimiters (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_options_5F_scanner_optionsDelimiters, ktable_size_options_5F_scanner_optionsDelimiters) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                          getCurrentTokenString                                                                      *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_options_5F_scanner::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_options_5F_scanner * ptr = (const cTokenFor_options_5F_scanner *) inTokenPtr ;
  C_String s ;
  if (ptr == NULL) {
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

//---------------------------------------------------------------------------------------------------------------------*
//                           Template Delimiters                                                                       *
//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                           Template Replacements                                                                     *
//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//            Terminal Symbols as end of script in template mark                                                       *
//---------------------------------------------------------------------------------------------------------------------*



//---------------------------------------------------------------------------------------------------------------------*
//               P A R S E    L E X I C A L    T O K E N                                                               *
//---------------------------------------------------------------------------------------------------------------------*

bool C_Lexique_options_5F_scanner::parseLexicalToken (void) {
  cTokenFor_options_5F_scanner token ;
  mLoop = true ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
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
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        token.mTokenCode = kToken_idf ;
        enterToken (token) ;
      }else if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
        do {
          if (testForInputUTF32CharRange (TO_UNICODE (' '), TO_UNICODE ('!')) || testForInputUTF32CharRange (TO_UNICODE ('#'), TO_UNICODE (65533))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_string, previousChar ()) ;
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
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
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        token.mTokenCode = kToken_uint_5F_number ;
        enterToken (token) ;
      }else if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
        do {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_number, previousChar ()) ;
          ::scanner_routine_enterDigitIntoUInt64 (*this, previousChar (), token.mLexicalAttribute_integerNumber, gLexicalMessage_options_5F_scanner_decimalNumberTooLarge, gLexicalMessage_options_5F_scanner_internalError) ;
          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        if (testForInputUTF32Char (TO_UNICODE ('.'))) {
          do {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_number, previousChar ()) ;
            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
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
      }
    }catch (const C_lexicalErrorException &) {
      token.mTokenCode = -1 ; // No token
      advance () ; // ... go throught unknown character
    }
  }
  if (UNICODE_VALUE (mCurrentChar) == '\0') { // && (token.mTemplateStringBeforeToken.length () > 0)) {
    token.mTokenCode = 0 ;
    enterToken (token) ;
  }
  return token.mTokenCode > 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                         E N T E R    T O K E N                                                                      *
//---------------------------------------------------------------------------------------------------------------------*

void C_Lexique_options_5F_scanner::enterToken (cTokenFor_options_5F_scanner & ioToken) {
  cTokenFor_options_5F_scanner * ptr = NULL ;
  macroMyNew (ptr, cTokenFor_options_5F_scanner ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
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

//---------------------------------------------------------------------------------------------------------------------*
//               A T T R I B U T E   A C C E S S                                                                       *
//---------------------------------------------------------------------------------------------------------------------*

double C_Lexique_options_5F_scanner::attributeValue_floatNumber (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_floatNumber ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint64_t C_Lexique_options_5F_scanner::attributeValue_integerNumber (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_integerNumber ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_options_5F_scanner::attributeValue_key (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_key ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_options_5F_scanner::attributeValue_number (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_number ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_options_5F_scanner::attributeValue_string (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_string ;
}

//---------------------------------------------------------------------------------------------------------------------*
//         A S S I G N    F R O M    A T T R I B U T E                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ldouble C_Lexique_options_5F_scanner::synthetizedAttribute_floatNumber (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_options_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_double value (ptr->mLexicalAttribute_floatNumber) ;
  GALGAS_ldouble result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_luint_36__34_ C_Lexique_options_5F_scanner::synthetizedAttribute_integerNumber (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_options_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_uint_36__34_ value (ptr->mLexicalAttribute_integerNumber) ;
  GALGAS_luint_36__34_ result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_options_5F_scanner::synthetizedAttribute_key (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_options_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_key) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_options_5F_scanner::synthetizedAttribute_number (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_options_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_number) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_options_5F_scanner::synthetizedAttribute_string (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_options_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_string) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                         I N T R O S P E C T I O N                                                                   *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

static void getKeywordLists_options_5F_scanner (TC_UniqueArray <C_String> & ioList) {
  ioList.addObject ("options_scanner:optionsDelimiters") ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void getKeywordsForIdentifier_options_5F_scanner (const C_String & inIdentifier,
                                                         bool & ioFound,
                                                         TC_UniqueArray <C_String> & ioList) {
  if (inIdentifier == "options_scanner:optionsDelimiters") {
    ioFound = true ;
    ioList.addObject ("(") ;
    ioList.addObject (")") ;
    ioList.addObject (",") ;
    ioList.addObject ("-") ;
    ioList.addObject ("=") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static cLexiqueIntrospection lexiqueIntrospection_options_5F_scanner
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_options_5F_scanner, getKeywordsForIdentifier_options_5F_scanner) ;

//---------------------------------------------------------------------------------------------------------------------*
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                                            *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_identifierMap::cMapElement_identifierMap (const GALGAS_lstring & inKey,
                                                      const GALGAS_object_5F_t & in_value
                                                      COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_identifierMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_identifierMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_identifierMap (mAttribute_lkey, mAttribute_value COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_identifierMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mAttribute_value.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_identifierMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_identifierMap * operand = (cMapElement_identifierMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (operand->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap::GALGAS_identifierMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap::GALGAS_identifierMap (const GALGAS_identifierMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap & GALGAS_identifierMap::operator = (const GALGAS_identifierMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap GALGAS_identifierMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_identifierMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap GALGAS_identifierMap::constructor_mapWithMapToOverride (const GALGAS_identifierMap & inMapToOverride
                                                                             COMMA_LOCATION_ARGS) {
  GALGAS_identifierMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap GALGAS_identifierMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_identifierMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                const GALGAS_object_5F_t & inArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cMapElement_identifierMap * p = NULL ;
  macroMyNew (p, cMapElement_identifierMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@identifierMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierMap::setter_put (GALGAS_lstring inKey,
                                       GALGAS_object_5F_t inArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  cMapElement_identifierMap * p = NULL ;
  macroMyNew (p, cMapElement_identifierMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "%K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_identifierMap_get = "Identifier %K is not defined" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierMap::method_get (GALGAS_lstring inKey,
                                       GALGAS_object_5F_t & outArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  const cMapElement_identifierMap * p = (const cMapElement_identifierMap *) performSearch (inKey,
                                                                                             inCompiler,
                                                                                             kSearchErrorMessage_identifierMap_get
                                                                                             COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_identifierMap) ;
    outArgument0 = p->mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierMap::setter_del (GALGAS_lstring inKey,
                                       GALGAS_object_5F_t & outArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "Identifier %K is not defined" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_identifierMap * p = (cMapElement_identifierMap *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_identifierMap) ;
    outArgument0 = p->mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t GALGAS_identifierMap::getter_valueForKey (const GALGAS_string & inKey,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_identifierMap * p = (const cMapElement_identifierMap *) attributes ;
  GALGAS_object_5F_t result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_identifierMap) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierMap::setter_setValueForKey (GALGAS_object_5F_t inAttributeValue,
                                                  GALGAS_string inKey,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_identifierMap * p = (cMapElement_identifierMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_identifierMap) ;
    p->mAttribute_value = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_identifierMap * GALGAS_identifierMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                     const GALGAS_string & inKey
                                                                                     COMMA_LOCATION_ARGS) {
  cMapElement_identifierMap * result = (cMapElement_identifierMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_identifierMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_identifierMap::cEnumerator_identifierMap (const GALGAS_identifierMap & inEnumeratedObject,
                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap_2D_element cEnumerator_identifierMap::current (LOCATION_ARGS) const {
  const cMapElement_identifierMap * p = (const cMapElement_identifierMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_identifierMap) ;
  return GALGAS_identifierMap_2D_element (p->mAttribute_lkey, p->mAttribute_value) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_identifierMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t cEnumerator_identifierMap::current_value (LOCATION_ARGS) const {
  const cMapElement_identifierMap * p = (const cMapElement_identifierMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_identifierMap) ;
  return p->mAttribute_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @identifierMap type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_identifierMap ("identifierMap",
                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_identifierMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_identifierMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_identifierMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_identifierMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap GALGAS_identifierMap::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_identifierMap result ;
  const GALGAS_identifierMap * p = (const GALGAS_identifierMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_identifierMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("identifierMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
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
//                                                                                                                     *
//                                     Class for element of '@identifierList' list                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_identifierList : public cCollectionElement {
  public : GALGAS_identifierList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_identifierList (const GALGAS_object_5F_t & in_item
                                              COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_identifierList::cCollectionElement_identifierList (const GALGAS_object_5F_t & in_item
                                                                      COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_item) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_identifierList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_identifierList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_identifierList (mObject.mAttribute_item COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_identifierList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "item" ":" ;
  mObject.mAttribute_item.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_identifierList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_identifierList * operand = (cCollectionElement_identifierList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_identifierList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList::GALGAS_identifierList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList::GALGAS_identifierList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList GALGAS_identifierList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_identifierList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList GALGAS_identifierList::constructor_listWithValue (const GALGAS_object_5F_t & inOperand0
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_identifierList result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_identifierList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                       const GALGAS_object_5F_t & in_item
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement_identifierList * p = NULL ;
  macroMyNew (p, cCollectionElement_identifierList (in_item COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::addAssign_operation (const GALGAS_object_5F_t & inOperand0
                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_identifierList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::setter_insertAtIndex (const GALGAS_object_5F_t inOperand0,
                                                  const GALGAS_uint inInsertionIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_identifierList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::setter_removeAtIndex (GALGAS_object_5F_t & outOperand0,
                                                  const GALGAS_uint inRemoveIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_identifierList) ;
      outOperand0 = p->mObject.mAttribute_item ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::setter_popFirst (GALGAS_object_5F_t & outOperand0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_identifierList) ;
    outOperand0 = p->mObject.mAttribute_item ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::setter_popLast (GALGAS_object_5F_t & outOperand0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_identifierList) ;
    outOperand0 = p->mObject.mAttribute_item ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::method_first (GALGAS_object_5F_t & outOperand0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_identifierList) ;
    outOperand0 = p->mObject.mAttribute_item ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::method_last (GALGAS_object_5F_t & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_identifierList) ;
    outOperand0 = p->mObject.mAttribute_item ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList GALGAS_identifierList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_identifierList result = GALGAS_identifierList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList GALGAS_identifierList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_identifierList result = GALGAS_identifierList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList GALGAS_identifierList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_identifierList result = GALGAS_identifierList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::plusAssign_operation (const GALGAS_identifierList inOperand,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t GALGAS_identifierList::getter_itemAtIndex (const GALGAS_uint & inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
  GALGAS_object_5F_t result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_identifierList) ;
    result = p->mObject.mAttribute_item ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_identifierList::cEnumerator_identifierList (const GALGAS_identifierList & inEnumeratedObject,
                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList_2D_element cEnumerator_identifierList::current (LOCATION_ARGS) const {
  const cCollectionElement_identifierList * p = (const cCollectionElement_identifierList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_identifierList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t cEnumerator_identifierList::current_item (LOCATION_ARGS) const {
  const cCollectionElement_identifierList * p = (const cCollectionElement_identifierList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_identifierList) ;
  return p->mObject.mAttribute_item ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @identifierList type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_identifierList ("identifierList",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_identifierList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_identifierList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_identifierList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_identifierList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList GALGAS_identifierList::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_identifierList result ;
  const GALGAS_identifierList * p = (const GALGAS_identifierList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_identifierList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("identifierList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_stringMap::cMapElement_stringMap (const GALGAS_lstring & inKey,
                                              const GALGAS_string & in_value
                                              COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_stringMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_stringMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_stringMap (mAttribute_lkey, mAttribute_value COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_stringMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mAttribute_value.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_stringMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_stringMap * operand = (cMapElement_stringMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (operand->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap::GALGAS_stringMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap::GALGAS_stringMap (const GALGAS_stringMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap & GALGAS_stringMap::operator = (const GALGAS_stringMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap GALGAS_stringMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_stringMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap GALGAS_stringMap::constructor_mapWithMapToOverride (const GALGAS_stringMap & inMapToOverride
                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_stringMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap GALGAS_stringMap::getter_overriddenMap (C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_stringMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringMap::addAssign_operation (const GALGAS_lstring & inKey,
                                            const GALGAS_string & inArgument0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  cMapElement_stringMap * p = NULL ;
  macroMyNew (p, cMapElement_stringMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@stringMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringMap::setter_put (GALGAS_lstring inKey,
                                   GALGAS_string inArgument0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
  cMapElement_stringMap * p = NULL ;
  macroMyNew (p, cMapElement_stringMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "stringmap key %K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_stringMap_get = "stringmap key %K is not defined" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringMap::method_get (GALGAS_lstring inKey,
                                   GALGAS_string & outArgument0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) const {
  const cMapElement_stringMap * p = (const cMapElement_stringMap *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_stringMap_get
                                                                                     COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_stringMap) ;
    outArgument0 = p->mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_stringMap::getter_valueForKey (const GALGAS_string & inKey,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_stringMap * p = (const cMapElement_stringMap *) attributes ;
  GALGAS_string result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_stringMap) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringMap::setter_setValueForKey (GALGAS_string inAttributeValue,
                                              GALGAS_string inKey,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_stringMap * p = (cMapElement_stringMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_stringMap) ;
    p->mAttribute_value = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_stringMap * GALGAS_stringMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                             const GALGAS_string & inKey
                                                                             COMMA_LOCATION_ARGS) {
  cMapElement_stringMap * result = (cMapElement_stringMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_stringMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_stringMap::cEnumerator_stringMap (const GALGAS_stringMap & inEnumeratedObject,
                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap_2D_element cEnumerator_stringMap::current (LOCATION_ARGS) const {
  const cMapElement_stringMap * p = (const cMapElement_stringMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_stringMap) ;
  return GALGAS_stringMap_2D_element (p->mAttribute_lkey, p->mAttribute_value) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_stringMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cEnumerator_stringMap::current_value (LOCATION_ARGS) const {
  const cMapElement_stringMap * p = (const cMapElement_stringMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_stringMap) ;
  return p->mAttribute_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @stringMap type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringMap ("stringMap",
                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_stringMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_stringMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap GALGAS_stringMap::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_stringMap result ;
  const GALGAS_stringMap * p = (const GALGAS_stringMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_stringMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_lstringMap::cMapElement_lstringMap (const GALGAS_lstring & inKey,
                                                const GALGAS_lstring & in_value
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_lstringMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_lstringMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_lstringMap (mAttribute_lkey, mAttribute_value COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_lstringMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mAttribute_value.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_lstringMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_lstringMap * operand = (cMapElement_lstringMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (operand->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap::GALGAS_lstringMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap::GALGAS_lstringMap (const GALGAS_lstringMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap & GALGAS_lstringMap::operator = (const GALGAS_lstringMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap GALGAS_lstringMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_lstringMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap GALGAS_lstringMap::constructor_mapWithMapToOverride (const GALGAS_lstringMap & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_lstringMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap GALGAS_lstringMap::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_lstringMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_lstringMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_lstring & inArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_lstringMap * p = NULL ;
  macroMyNew (p, cMapElement_lstringMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@lstringMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_lstringMap::setter_put (GALGAS_lstring inKey,
                                    GALGAS_lstring inArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  cMapElement_lstringMap * p = NULL ;
  macroMyNew (p, cMapElement_lstringMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "lstringmap key %K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_lstringMap_get = "lstringmap key %K is not defined" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_lstringMap::method_get (GALGAS_lstring inKey,
                                    GALGAS_lstring & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  const cMapElement_lstringMap * p = (const cMapElement_lstringMap *) performSearch (inKey,
                                                                                       inCompiler,
                                                                                       kSearchErrorMessage_lstringMap_get
                                                                                       COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_lstringMap) ;
    outArgument0 = p->mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_lstringMap::getter_valueForKey (const GALGAS_string & inKey,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_lstringMap * p = (const cMapElement_lstringMap *) attributes ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_lstringMap) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_lstringMap::setter_setValueForKey (GALGAS_lstring inAttributeValue,
                                               GALGAS_string inKey,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_lstringMap * p = (cMapElement_lstringMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_lstringMap) ;
    p->mAttribute_value = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_lstringMap * GALGAS_lstringMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_lstringMap * result = (cMapElement_lstringMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_lstringMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_lstringMap::cEnumerator_lstringMap (const GALGAS_lstringMap & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap_2D_element cEnumerator_lstringMap::current (LOCATION_ARGS) const {
  const cMapElement_lstringMap * p = (const cMapElement_lstringMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_lstringMap) ;
  return GALGAS_lstringMap_2D_element (p->mAttribute_lkey, p->mAttribute_value) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_lstringMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_lstringMap::current_value (LOCATION_ARGS) const {
  const cMapElement_lstringMap * p = (const cMapElement_lstringMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_lstringMap) ;
  return p->mAttribute_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @lstringMap type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lstringMap ("lstringMap",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_lstringMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lstringMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_lstringMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lstringMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap GALGAS_lstringMap::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_lstringMap result ;
  const GALGAS_lstringMap * p = (const GALGAS_lstringMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_lstringMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lstringMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_prefix_5F_map::cMapElement_prefix_5F_map (const GALGAS_lstring & inKey,
                                                      const GALGAS_string & in_prefix,
                                                      const GALGAS_string & in_tag_5F_to_5F_rep
                                                      COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_prefix (in_prefix),
mAttribute_tag_5F_to_5F_rep (in_tag_5F_to_5F_rep) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_prefix_5F_map::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_prefix.isValid () && mAttribute_tag_5F_to_5F_rep.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_prefix_5F_map::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_prefix_5F_map (mAttribute_lkey, mAttribute_prefix, mAttribute_tag_5F_to_5F_rep COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_prefix_5F_map::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "prefix" ":" ;
  mAttribute_prefix.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "tag_to_rep" ":" ;
  mAttribute_tag_5F_to_5F_rep.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_prefix_5F_map::compare (const cCollectionElement * inOperand) const {
  cMapElement_prefix_5F_map * operand = (cMapElement_prefix_5F_map *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_prefix.objectCompare (operand->mAttribute_prefix) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_tag_5F_to_5F_rep.objectCompare (operand->mAttribute_tag_5F_to_5F_rep) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map::GALGAS_prefix_5F_map (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map::GALGAS_prefix_5F_map (const GALGAS_prefix_5F_map & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map & GALGAS_prefix_5F_map::operator = (const GALGAS_prefix_5F_map & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map GALGAS_prefix_5F_map::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_prefix_5F_map result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map GALGAS_prefix_5F_map::constructor_mapWithMapToOverride (const GALGAS_prefix_5F_map & inMapToOverride
                                                                             COMMA_LOCATION_ARGS) {
  GALGAS_prefix_5F_map result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map GALGAS_prefix_5F_map::getter_overriddenMap (C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_prefix_5F_map result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefix_5F_map::addAssign_operation (const GALGAS_lstring & inKey,
                                                const GALGAS_string & inArgument0,
                                                const GALGAS_string & inArgument1,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cMapElement_prefix_5F_map * p = NULL ;
  macroMyNew (p, cMapElement_prefix_5F_map (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@prefix_5F_map insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefix_5F_map::setter_add (GALGAS_lstring inKey,
                                       GALGAS_string inArgument0,
                                       GALGAS_string inArgument1,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  cMapElement_prefix_5F_map * p = NULL ;
  macroMyNew (p, cMapElement_prefix_5F_map (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "prefix %K duplicated %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefix_5F_map::setter_insert_5F_prefix (GALGAS_lstring inKey,
                                                    GALGAS_string inArgument0,
                                                    GALGAS_string inArgument1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cMapElement_prefix_5F_map * p = NULL ;
  macroMyNew (p, cMapElement_prefix_5F_map (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "prefix %K duplicated %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_prefix_5F_map_prefix = "prefix %K is not defined" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefix_5F_map::method_prefix (GALGAS_lstring inKey,
                                          GALGAS_string & outArgument0,
                                          GALGAS_string & outArgument1,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) performSearch (inKey,
                                                                                             inCompiler,
                                                                                             kSearchErrorMessage_prefix_5F_map_prefix
                                                                                             COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
    outArgument0 = p->mAttribute_prefix ;
    outArgument1 = p->mAttribute_tag_5F_to_5F_rep ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_prefix_5F_map::getter_prefixForKey (const GALGAS_string & inKey,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) attributes ;
  GALGAS_string result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
    result = p->mAttribute_prefix ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_prefix_5F_map::getter_tag_5F_to_5F_repForKey (const GALGAS_string & inKey,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) attributes ;
  GALGAS_string result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
    result = p->mAttribute_tag_5F_to_5F_rep ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefix_5F_map::setter_setPrefixForKey (GALGAS_string inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_prefix_5F_map * p = (cMapElement_prefix_5F_map *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
    p->mAttribute_prefix = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefix_5F_map::setter_setTag_5F_to_5F_repForKey (GALGAS_string inAttributeValue,
                                                             GALGAS_string inKey,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_prefix_5F_map * p = (cMapElement_prefix_5F_map *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
    p->mAttribute_tag_5F_to_5F_rep = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_prefix_5F_map * GALGAS_prefix_5F_map::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                     const GALGAS_string & inKey
                                                                                     COMMA_LOCATION_ARGS) {
  cMapElement_prefix_5F_map * result = (cMapElement_prefix_5F_map *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_prefix_5F_map) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_prefix_5F_map::cEnumerator_prefix_5F_map (const GALGAS_prefix_5F_map & inEnumeratedObject,
                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map_2D_element cEnumerator_prefix_5F_map::current (LOCATION_ARGS) const {
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
  return GALGAS_prefix_5F_map_2D_element (p->mAttribute_lkey, p->mAttribute_prefix, p->mAttribute_tag_5F_to_5F_rep) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_prefix_5F_map::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cEnumerator_prefix_5F_map::current_prefix (LOCATION_ARGS) const {
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
  return p->mAttribute_prefix ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cEnumerator_prefix_5F_map::current_tag_5F_to_5F_rep (LOCATION_ARGS) const {
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
  return p->mAttribute_tag_5F_to_5F_rep ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @prefix_map type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_prefix_5F_map ("prefix_map",
                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_prefix_5F_map::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_prefix_5F_map ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_prefix_5F_map::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_prefix_5F_map (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map GALGAS_prefix_5F_map::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_prefix_5F_map result ;
  const GALGAS_prefix_5F_map * p = (const GALGAS_prefix_5F_map *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_prefix_5F_map *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("prefix_map", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_stringset_5F_map::cMapElement_stringset_5F_map (const GALGAS_lstring & inKey,
                                                            const GALGAS_stringset & in_ids
                                                            COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_ids (in_ids) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_stringset_5F_map::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_ids.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_stringset_5F_map::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_stringset_5F_map (mAttribute_lkey, mAttribute_ids COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_stringset_5F_map::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "ids" ":" ;
  mAttribute_ids.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_stringset_5F_map::compare (const cCollectionElement * inOperand) const {
  cMapElement_stringset_5F_map * operand = (cMapElement_stringset_5F_map *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_ids.objectCompare (operand->mAttribute_ids) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map::GALGAS_stringset_5F_map (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map::GALGAS_stringset_5F_map (const GALGAS_stringset_5F_map & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map & GALGAS_stringset_5F_map::operator = (const GALGAS_stringset_5F_map & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map GALGAS_stringset_5F_map::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_stringset_5F_map result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map GALGAS_stringset_5F_map::constructor_mapWithMapToOverride (const GALGAS_stringset_5F_map & inMapToOverride
                                                                                   COMMA_LOCATION_ARGS) {
  GALGAS_stringset_5F_map result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map GALGAS_stringset_5F_map::getter_overriddenMap (C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  GALGAS_stringset_5F_map result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringset_5F_map::addAssign_operation (const GALGAS_lstring & inKey,
                                                   const GALGAS_stringset & inArgument0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cMapElement_stringset_5F_map * p = NULL ;
  macroMyNew (p, cMapElement_stringset_5F_map (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@stringset_5F_map insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringset_5F_map::setter_add (GALGAS_lstring inKey,
                                          GALGAS_stringset inArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  cMapElement_stringset_5F_map * p = NULL ;
  macroMyNew (p, cMapElement_stringset_5F_map (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "Key %K is already used there" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_stringset_5F_map_get = "Key %K is not there" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringset_5F_map::method_get (GALGAS_lstring inKey,
                                          GALGAS_stringset & outArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const cMapElement_stringset_5F_map * p = (const cMapElement_stringset_5F_map *) performSearch (inKey,
                                                                                                   inCompiler,
                                                                                                   kSearchErrorMessage_stringset_5F_map_get
                                                                                                   COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
    outArgument0 = p->mAttribute_ids ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringset_5F_map::setter_delete (GALGAS_lstring inKey,
                                             GALGAS_stringset & outArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "Key %K cannot be deleted" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_stringset_5F_map * p = (cMapElement_stringset_5F_map *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
    outArgument0 = p->mAttribute_ids ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset GALGAS_stringset_5F_map::getter_idsForKey (const GALGAS_string & inKey,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_stringset_5F_map * p = (const cMapElement_stringset_5F_map *) attributes ;
  GALGAS_stringset result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
    result = p->mAttribute_ids ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringset_5F_map::setter_setIdsForKey (GALGAS_stringset inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_stringset_5F_map * p = (cMapElement_stringset_5F_map *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
    p->mAttribute_ids = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_stringset_5F_map * GALGAS_stringset_5F_map::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                           const GALGAS_string & inKey
                                                                                           COMMA_LOCATION_ARGS) {
  cMapElement_stringset_5F_map * result = (cMapElement_stringset_5F_map *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_stringset_5F_map) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_stringset_5F_map::cEnumerator_stringset_5F_map (const GALGAS_stringset_5F_map & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map_2D_element cEnumerator_stringset_5F_map::current (LOCATION_ARGS) const {
  const cMapElement_stringset_5F_map * p = (const cMapElement_stringset_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
  return GALGAS_stringset_5F_map_2D_element (p->mAttribute_lkey, p->mAttribute_ids) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_stringset_5F_map::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset cEnumerator_stringset_5F_map::current_ids (LOCATION_ARGS) const {
  const cMapElement_stringset_5F_map * p = (const cMapElement_stringset_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
  return p->mAttribute_ids ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @stringset_map type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringset_5F_map ("stringset_map",
                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_stringset_5F_map::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringset_5F_map ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_stringset_5F_map::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringset_5F_map (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map GALGAS_stringset_5F_map::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_stringset_5F_map result ;
  const GALGAS_stringset_5F_map * p = (const GALGAS_stringset_5F_map *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_stringset_5F_map *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringset_map", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Class for element of '@ident_5F_list' list                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_ident_5F_list : public cCollectionElement {
  public : GALGAS_ident_5F_list_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_ident_5F_list (const GALGAS_lstring & in_obj_5F_name
                                             COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_ident_5F_list::cCollectionElement_ident_5F_list (const GALGAS_lstring & in_obj_5F_name
                                                                    COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_obj_5F_name) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_ident_5F_list::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_ident_5F_list::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_ident_5F_list (mObject.mAttribute_obj_5F_name COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_ident_5F_list::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "obj_name" ":" ;
  mObject.mAttribute_obj_5F_name.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_ident_5F_list::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_ident_5F_list * operand = (cCollectionElement_ident_5F_list *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_ident_5F_list) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list::GALGAS_ident_5F_list (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list::GALGAS_ident_5F_list (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list GALGAS_ident_5F_list::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_ident_5F_list result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list GALGAS_ident_5F_list::constructor_listWithValue (const GALGAS_lstring & inOperand0
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_ident_5F_list::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                      const GALGAS_lstring & in_obj_5F_name
                                                      COMMA_LOCATION_ARGS) {
  cCollectionElement_ident_5F_list * p = NULL ;
  macroMyNew (p, cCollectionElement_ident_5F_list (in_obj_5F_name COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::addAssign_operation (const GALGAS_lstring & inOperand0
                                                COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_ident_5F_list (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                 const GALGAS_uint inInsertionIndex,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_ident_5F_list (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                 const GALGAS_uint inRemoveIndex,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
      outOperand0 = p->mObject.mAttribute_obj_5F_name ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::setter_popFirst (GALGAS_lstring & outOperand0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
    outOperand0 = p->mObject.mAttribute_obj_5F_name ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::setter_popLast (GALGAS_lstring & outOperand0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
    outOperand0 = p->mObject.mAttribute_obj_5F_name ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::method_first (GALGAS_lstring & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
    outOperand0 = p->mObject.mAttribute_obj_5F_name ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::method_last (GALGAS_lstring & outOperand0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
    outOperand0 = p->mObject.mAttribute_obj_5F_name ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list GALGAS_ident_5F_list::getter_subListWithRange (const GALGAS_range & inRange,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_ident_5F_list result = GALGAS_ident_5F_list::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list GALGAS_ident_5F_list::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_ident_5F_list result = GALGAS_ident_5F_list::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list GALGAS_ident_5F_list::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_ident_5F_list result = GALGAS_ident_5F_list::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::plusAssign_operation (const GALGAS_ident_5F_list inOperand,
                                                 C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_ident_5F_list::getter_obj_5F_nameAtIndex (const GALGAS_uint & inIndex,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
    result = p->mObject.mAttribute_obj_5F_name ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_ident_5F_list::cEnumerator_ident_5F_list (const GALGAS_ident_5F_list & inEnumeratedObject,
                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_2D_element cEnumerator_ident_5F_list::current (LOCATION_ARGS) const {
  const cCollectionElement_ident_5F_list * p = (const cCollectionElement_ident_5F_list *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_ident_5F_list::current_obj_5F_name (LOCATION_ARGS) const {
  const cCollectionElement_ident_5F_list * p = (const cCollectionElement_ident_5F_list *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
  return p->mObject.mAttribute_obj_5F_name ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @ident_list type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ident_5F_list ("ident_list",
                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_ident_5F_list::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ident_5F_list ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_ident_5F_list::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ident_5F_list (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list GALGAS_ident_5F_list::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list result ;
  const GALGAS_ident_5F_list * p = (const GALGAS_ident_5F_list *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_ident_5F_list *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ident_list", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_ident_5F_list_5F_map::cMapElement_ident_5F_list_5F_map (const GALGAS_lstring & inKey,
                                                                    const GALGAS_ident_5F_list & in_objs
                                                                    COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_objs (in_objs) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_ident_5F_list_5F_map::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_objs.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_ident_5F_list_5F_map::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_ident_5F_list_5F_map (mAttribute_lkey, mAttribute_objs COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_ident_5F_list_5F_map::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "objs" ":" ;
  mAttribute_objs.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_ident_5F_list_5F_map::compare (const cCollectionElement * inOperand) const {
  cMapElement_ident_5F_list_5F_map * operand = (cMapElement_ident_5F_list_5F_map *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_objs.objectCompare (operand->mAttribute_objs) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map::GALGAS_ident_5F_list_5F_map (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map::GALGAS_ident_5F_list_5F_map (const GALGAS_ident_5F_list_5F_map & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map & GALGAS_ident_5F_list_5F_map::operator = (const GALGAS_ident_5F_list_5F_map & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map GALGAS_ident_5F_list_5F_map::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_ident_5F_list_5F_map result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map GALGAS_ident_5F_list_5F_map::constructor_mapWithMapToOverride (const GALGAS_ident_5F_list_5F_map & inMapToOverride
                                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list_5F_map result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map GALGAS_ident_5F_list_5F_map::getter_overriddenMap (C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_ident_5F_list_5F_map result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list_5F_map::addAssign_operation (const GALGAS_lstring & inKey,
                                                       const GALGAS_ident_5F_list & inArgument0,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cMapElement_ident_5F_list_5F_map * p = NULL ;
  macroMyNew (p, cMapElement_ident_5F_list_5F_map (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@ident_5F_list_5F_map insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list_5F_map::setter_add (GALGAS_lstring inKey,
                                              GALGAS_ident_5F_list inArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  cMapElement_ident_5F_list_5F_map * p = NULL ;
  macroMyNew (p, cMapElement_ident_5F_list_5F_map (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "Key %K is already used there" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_ident_5F_list_5F_map_get = "Key %K is not there" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list_5F_map::method_get (GALGAS_lstring inKey,
                                              GALGAS_ident_5F_list & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  const cMapElement_ident_5F_list_5F_map * p = (const cMapElement_ident_5F_list_5F_map *) performSearch (inKey,
                                                                                                           inCompiler,
                                                                                                           kSearchErrorMessage_ident_5F_list_5F_map_get
                                                                                                           COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
    outArgument0 = p->mAttribute_objs ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list_5F_map::setter_delete (GALGAS_lstring inKey,
                                                 GALGAS_ident_5F_list & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "Key %K cannot be deleted" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_ident_5F_list_5F_map * p = (cMapElement_ident_5F_list_5F_map *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
    outArgument0 = p->mAttribute_objs ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list GALGAS_ident_5F_list_5F_map::getter_objsForKey (const GALGAS_string & inKey,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_ident_5F_list_5F_map * p = (const cMapElement_ident_5F_list_5F_map *) attributes ;
  GALGAS_ident_5F_list result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
    result = p->mAttribute_objs ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list_5F_map::setter_setObjsForKey (GALGAS_ident_5F_list inAttributeValue,
                                                        GALGAS_string inKey,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_ident_5F_list_5F_map * p = (cMapElement_ident_5F_list_5F_map *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
    p->mAttribute_objs = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_ident_5F_list_5F_map * GALGAS_ident_5F_list_5F_map::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                                   const GALGAS_string & inKey
                                                                                                   COMMA_LOCATION_ARGS) {
  cMapElement_ident_5F_list_5F_map * result = (cMapElement_ident_5F_list_5F_map *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_ident_5F_list_5F_map) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_ident_5F_list_5F_map::cEnumerator_ident_5F_list_5F_map (const GALGAS_ident_5F_list_5F_map & inEnumeratedObject,
                                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map_2D_element cEnumerator_ident_5F_list_5F_map::current (LOCATION_ARGS) const {
  const cMapElement_ident_5F_list_5F_map * p = (const cMapElement_ident_5F_list_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
  return GALGAS_ident_5F_list_5F_map_2D_element (p->mAttribute_lkey, p->mAttribute_objs) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_ident_5F_list_5F_map::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list cEnumerator_ident_5F_list_5F_map::current_objs (LOCATION_ARGS) const {
  const cMapElement_ident_5F_list_5F_map * p = (const cMapElement_ident_5F_list_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
  return p->mAttribute_objs ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @ident_list_map type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ident_5F_list_5F_map ("ident_list_map",
                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_ident_5F_list_5F_map::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ident_5F_list_5F_map ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_ident_5F_list_5F_map::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ident_5F_list_5F_map (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map GALGAS_ident_5F_list_5F_map::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list_5F_map result ;
  const GALGAS_ident_5F_list_5F_map * p = (const GALGAS_ident_5F_list_5F_map *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_ident_5F_list_5F_map *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ident_list_map", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_obj::GALGAS_autostart_5F_obj (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_obj::GALGAS_autostart_5F_obj (const cPtr_autostart_5F_obj * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_autostart_5F_obj) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_autostart_5F_obj::getter_location (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_autostart_5F_obj * p = (const cPtr_autostart_5F_obj *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_autostart_5F_obj) ;
    result = p->mAttribute_location ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_autostart_5F_obj::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @autostart_obj class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_autostart_5F_obj::cPtr_autostart_5F_obj (const GALGAS_location & in_location
                                              COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_location (in_location) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @autostart_obj type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_autostart_5F_obj ("autostart_obj",
                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_autostart_5F_obj::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_obj ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_autostart_5F_obj::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_autostart_5F_obj (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_obj GALGAS_autostart_5F_obj::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_obj result ;
  const GALGAS_autostart_5F_obj * p = (const GALGAS_autostart_5F_obj *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_autostart_5F_obj *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("autostart_obj", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_autostart_5F_void::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_autostart_5F_void * p = (const cPtr_autostart_5F_void *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_autostart_5F_void) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_void::GALGAS_autostart_5F_void (void) :
GALGAS_autostart_5F_obj () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_void GALGAS_autostart_5F_void::constructor_default (LOCATION_ARGS) {
  return GALGAS_autostart_5F_void::constructor_new (GALGAS_location::constructor_nowhere (HERE)
                                                    COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_void::GALGAS_autostart_5F_void (const cPtr_autostart_5F_void * inSourcePtr) :
GALGAS_autostart_5F_obj (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_autostart_5F_void) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_void GALGAS_autostart_5F_void::constructor_new (const GALGAS_location & inAttribute_location
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_void result ;
  if (inAttribute_location.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_autostart_5F_void (inAttribute_location COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @autostart_void class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_autostart_5F_void::cPtr_autostart_5F_void (const GALGAS_location & in_location
                                                COMMA_LOCATION_ARGS) :
cPtr_autostart_5F_obj (in_location COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_autostart_5F_void::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_void ;
}

void cPtr_autostart_5F_void::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@autostart_void:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_autostart_5F_void::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_autostart_5F_void (mAttribute_location COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @autostart_void type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_autostart_5F_void ("autostart_void",
                                          & kTypeDescriptor_GALGAS_autostart_5F_obj) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_autostart_5F_void::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_void ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_autostart_5F_void::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_autostart_5F_void (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_void GALGAS_autostart_5F_void::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_void result ;
  const GALGAS_autostart_5F_void * p = (const GALGAS_autostart_5F_void *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_autostart_5F_void *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("autostart_void", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_autostart_5F_false::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_autostart_5F_false * p = (const cPtr_autostart_5F_false *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_autostart_5F_false) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_false::GALGAS_autostart_5F_false (void) :
GALGAS_autostart_5F_obj () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_false GALGAS_autostart_5F_false::constructor_default (LOCATION_ARGS) {
  return GALGAS_autostart_5F_false::constructor_new (GALGAS_location::constructor_nowhere (HERE)
                                                     COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_false::GALGAS_autostart_5F_false (const cPtr_autostart_5F_false * inSourcePtr) :
GALGAS_autostart_5F_obj (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_autostart_5F_false) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_false GALGAS_autostart_5F_false::constructor_new (const GALGAS_location & inAttribute_location
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_false result ;
  if (inAttribute_location.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_autostart_5F_false (inAttribute_location COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @autostart_false class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_autostart_5F_false::cPtr_autostart_5F_false (const GALGAS_location & in_location
                                                  COMMA_LOCATION_ARGS) :
cPtr_autostart_5F_obj (in_location COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_autostart_5F_false::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_false ;
}

void cPtr_autostart_5F_false::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@autostart_false:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_autostart_5F_false::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_autostart_5F_false (mAttribute_location COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @autostart_false type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_autostart_5F_false ("autostart_false",
                                           & kTypeDescriptor_GALGAS_autostart_5F_obj) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_autostart_5F_false::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_false ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_autostart_5F_false::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_autostart_5F_false (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_false GALGAS_autostart_5F_false::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_false result ;
  const GALGAS_autostart_5F_false * p = (const GALGAS_autostart_5F_false *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_autostart_5F_false *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("autostart_false", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
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

cMapElement_objectsMap::cMapElement_objectsMap (const GALGAS_lstring & inKey,
                                                const GALGAS_objectKind & in_objectsOfKind
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_objectsOfKind (in_objectsOfKind) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_objectsMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_objectsOfKind.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_objectsMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_objectsMap (mAttribute_lkey, mAttribute_objectsOfKind COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_objectsMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "objectsOfKind" ":" ;
  mAttribute_objectsOfKind.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_objectsMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_objectsMap * operand = (cMapElement_objectsMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_objectsOfKind.objectCompare (operand->mAttribute_objectsOfKind) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap::GALGAS_objectsMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap::GALGAS_objectsMap (const GALGAS_objectsMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap & GALGAS_objectsMap::operator = (const GALGAS_objectsMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap GALGAS_objectsMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_objectsMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap GALGAS_objectsMap::constructor_mapWithMapToOverride (const GALGAS_objectsMap & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_objectsMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap GALGAS_objectsMap::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_objectsMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectsMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_objectKind & inArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_objectsMap * p = NULL ;
  macroMyNew (p, cMapElement_objectsMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@objectsMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectsMap::setter_put (GALGAS_lstring inKey,
                                    GALGAS_objectKind inArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  cMapElement_objectsMap * p = NULL ;
  macroMyNew (p, cMapElement_objectsMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "%K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_objectsMap_get = "%K does not exists" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectsMap::method_get (GALGAS_lstring inKey,
                                    GALGAS_objectKind & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  const cMapElement_objectsMap * p = (const cMapElement_objectsMap *) performSearch (inKey,
                                                                                       inCompiler,
                                                                                       kSearchErrorMessage_objectsMap_get
                                                                                       COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_objectsMap) ;
    outArgument0 = p->mAttribute_objectsOfKind ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectsMap::setter_del (GALGAS_lstring inKey,
                                    GALGAS_objectKind & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "%K does not exists" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_objectsMap * p = (cMapElement_objectsMap *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_objectsMap) ;
    outArgument0 = p->mAttribute_objectsOfKind ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKind GALGAS_objectsMap::getter_objectsOfKindForKey (const GALGAS_string & inKey,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_objectsMap * p = (const cMapElement_objectsMap *) attributes ;
  GALGAS_objectKind result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_objectsMap) ;
    result = p->mAttribute_objectsOfKind ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectsMap::setter_setObjectsOfKindForKey (GALGAS_objectKind inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_objectsMap * p = (cMapElement_objectsMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_objectsMap) ;
    p->mAttribute_objectsOfKind = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_objectsMap * GALGAS_objectsMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_objectsMap * result = (cMapElement_objectsMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_objectsMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_objectsMap::cEnumerator_objectsMap (const GALGAS_objectsMap & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap_2D_element cEnumerator_objectsMap::current (LOCATION_ARGS) const {
  const cMapElement_objectsMap * p = (const cMapElement_objectsMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_objectsMap) ;
  return GALGAS_objectsMap_2D_element (p->mAttribute_lkey, p->mAttribute_objectsOfKind) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_objectsMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKind cEnumerator_objectsMap::current_objectsOfKind (LOCATION_ARGS) const {
  const cMapElement_objectsMap * p = (const cMapElement_objectsMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_objectsMap) ;
  return p->mAttribute_objectsOfKind ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @objectsMap type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectsMap ("objectsMap",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_objectsMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectsMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_objectsMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectsMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap GALGAS_objectsMap::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_objectsMap result ;
  const GALGAS_objectsMap * p = (const GALGAS_objectsMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_objectsMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectsMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

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

cMapElement_objectKindMap::cMapElement_objectKindMap (const GALGAS_lstring & inKey,
                                                      const GALGAS_objectAttributes & in_attributes
                                                      COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_attributes (in_attributes) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_objectKindMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_attributes.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_objectKindMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_objectKindMap (mAttribute_lkey, mAttribute_attributes COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_objectKindMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "attributes" ":" ;
  mAttribute_attributes.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_objectKindMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_objectKindMap * operand = (cMapElement_objectKindMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_attributes.objectCompare (operand->mAttribute_attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap::GALGAS_objectKindMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap::GALGAS_objectKindMap (const GALGAS_objectKindMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap & GALGAS_objectKindMap::operator = (const GALGAS_objectKindMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap GALGAS_objectKindMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_objectKindMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap GALGAS_objectKindMap::constructor_mapWithMapToOverride (const GALGAS_objectKindMap & inMapToOverride
                                                                             COMMA_LOCATION_ARGS) {
  GALGAS_objectKindMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap GALGAS_objectKindMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_objectKindMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectKindMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                const GALGAS_objectAttributes & inArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cMapElement_objectKindMap * p = NULL ;
  macroMyNew (p, cMapElement_objectKindMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@objectKindMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectKindMap::setter_put (GALGAS_lstring inKey,
                                       GALGAS_objectAttributes inArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  cMapElement_objectKindMap * p = NULL ;
  macroMyNew (p, cMapElement_objectKindMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "%K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_objectKindMap_get = "%K does not exists" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectKindMap::method_get (GALGAS_lstring inKey,
                                       GALGAS_objectAttributes & outArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  const cMapElement_objectKindMap * p = (const cMapElement_objectKindMap *) performSearch (inKey,
                                                                                             inCompiler,
                                                                                             kSearchErrorMessage_objectKindMap_get
                                                                                             COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_objectKindMap) ;
    outArgument0 = p->mAttribute_attributes ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectKindMap::setter_del (GALGAS_lstring inKey,
                                       GALGAS_objectAttributes & outArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "%K does not exists" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_objectKindMap * p = (cMapElement_objectKindMap *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_objectKindMap) ;
    outArgument0 = p->mAttribute_attributes ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes GALGAS_objectKindMap::getter_attributesForKey (const GALGAS_string & inKey,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_objectKindMap * p = (const cMapElement_objectKindMap *) attributes ;
  GALGAS_objectAttributes result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_objectKindMap) ;
    result = p->mAttribute_attributes ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectKindMap::setter_setAttributesForKey (GALGAS_objectAttributes inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_objectKindMap * p = (cMapElement_objectKindMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_objectKindMap) ;
    p->mAttribute_attributes = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_objectKindMap * GALGAS_objectKindMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                     const GALGAS_string & inKey
                                                                                     COMMA_LOCATION_ARGS) {
  cMapElement_objectKindMap * result = (cMapElement_objectKindMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_objectKindMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_objectKindMap::cEnumerator_objectKindMap (const GALGAS_objectKindMap & inEnumeratedObject,
                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap_2D_element cEnumerator_objectKindMap::current (LOCATION_ARGS) const {
  const cMapElement_objectKindMap * p = (const cMapElement_objectKindMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_objectKindMap) ;
  return GALGAS_objectKindMap_2D_element (p->mAttribute_lkey, p->mAttribute_attributes) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_objectKindMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes cEnumerator_objectKindMap::current_attributes (LOCATION_ARGS) const {
  const cMapElement_objectKindMap * p = (const cMapElement_objectKindMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_objectKindMap) ;
  return p->mAttribute_attributes ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @objectKindMap type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectKindMap ("objectKindMap",
                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_objectKindMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectKindMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_objectKindMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectKindMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap GALGAS_objectKindMap::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_objectKindMap result ;
  const GALGAS_objectKindMap * p = (const GALGAS_objectKindMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_objectKindMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectKindMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_start_i0_ (C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_implementation var_imp_955 = GALGAS_implementation::constructor_new (GALGAS_implementationMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 39))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 39)) ;
  GALGAS_applicationDefinition var_application_1049 = function_emptyApplicationDefinition (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 40)) ;
  GALGAS_string var_fileIncludeList_1107 = GALGAS_string::makeEmptyString () ;
  GALGAS_lstring var_version_1178 ;
  GALGAS_lstring var_desc_1194 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 46)) ;
  nt_OIL_5F_version_ (var_version_1178, var_desc_1194, inCompiler) ;
  {
  var_application_1049.setter_setVersion (var_version_1178 COMMA_SOURCE_FILE ("goil_syntax.galgas", 48)) ;
  }
  {
  var_application_1049.setter_setVersionDescription (var_desc_1194 COMMA_SOURCE_FILE ("goil_syntax.galgas", 49)) ;
  }
  GALGAS_string var_config_5F_file_5F_name_1358 = GALGAS_string (gOption_goil_5F_options_config.getter_value ()) ;
  GALGAS_stringlist var_configFiles_1452 = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name_1358.add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 54)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 54)) ;
  cEnumerator_stringlist enumerator_1663 (var_configFiles_1452, kEnumeration_down) ;
  while (enumerator_1663.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_1663.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 58)), var_imp_955, var_application_1049, var_fileIncludeList_1107, GALGAS_bool (false)  COMMA_SOURCE_FILE ("goil_syntax.galgas", 58)) ;
    enumerator_1663.gotoNextObject () ;
  }
  GALGAS_stringlist var_configVersionFiles_1868 = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name_1358.add_operation (var_version_1178.getter_string (SOURCE_FILE ("goil_syntax.galgas", 62)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 62)).add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 62)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 62)) ;
  cEnumerator_stringlist enumerator_1981 (var_configVersionFiles_1868, kEnumeration_down) ;
  while (enumerator_1981.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_1981.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 65)), var_imp_955, var_application_1049, var_fileIncludeList_1107, GALGAS_bool (false)  COMMA_SOURCE_FILE ("goil_syntax.galgas", 65)) ;
    enumerator_1981.gotoNextObject () ;
  }
  nt_file_ (var_imp_955, var_application_1049, var_fileIncludeList_1107, GALGAS_bool (true), inCompiler) ;
  callExtensionMethod_checkObjectReferences ((const cPtr_implementation *) var_imp_955.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 83)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("goil_syntax.galgas", 85)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    routine_setDefaults (var_imp_955, var_application_1049, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 86)) ;
    }
  }
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("goil_syntax.galgas", 93)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    {
    routine_verifyAll (var_imp_955, var_application_1049, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 94)) ;
    }
  }
  const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("goil_syntax.galgas", 96)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_2) {
    GALGAS_gtlData var_templateData_2847 = callExtensionGetter_templateData ((const cPtr_applicationDefinition *) var_application_1049.ptr (), var_imp_955, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 97)) ;
    {
    routine_generate_5F_all (var_templateData_2847, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 100)) ;
    }
  }
  var_fileIncludeList_1107 = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 103)).getter_lastPathComponent (SOURCE_FILE ("goil_syntax.galgas", 103)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 103)).add_operation (var_fileIncludeList_1107, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 103)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 103)) ;
  GALGAS_string var_oilDepFileName_3150 = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 104)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("goil_syntax.galgas", 104)).add_operation (GALGAS_string ("/build/"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 104)).add_operation (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 105)).getter_lastPathComponent (SOURCE_FILE ("goil_syntax.galgas", 105)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 105)).add_operation (GALGAS_string (".dep"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 105)) ;
  var_fileIncludeList_1107.method_writeToFile (var_oilDepFileName_3150, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 107)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_start_i0_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_OIL_5F_version_parse (inCompiler) ;
  nt_file_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_file_i1_ (GALGAS_implementation & ioArgument_imp,
                                                           GALGAS_applicationDefinition & ioArgument_application,
                                                           GALGAS_string & ioArgument_fileIncludeList,
                                                           const GALGAS_bool constinArgument_rootFile,
                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  const enumGalgasBool test_0 = constinArgument_rootFile.operator_not (SOURCE_FILE ("goil_syntax.galgas", 116)).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_fileIncludeList.plusAssign_operation(GALGAS_string (" \\\n"
      " ").add_operation (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 117)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 117)), inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 117)) ;
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

void cParser_goil_5F_syntax::rule_goil_5F_syntax_sign_i2_ (GALGAS_bool & outArgument_signed,
                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_signed.drop () ; // Release 'out' argument
  switch (select_goil_5F_syntax_1 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 128)) ;
    outArgument_signed = GALGAS_bool (true) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 130)) ;
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

void cParser_goil_5F_syntax::rule_goil_5F_syntax_sign_i2_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_1 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 128)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 130)) ;
  } break ;
  case 3: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_description_i3_ (GALGAS_lstring & outArgument_desc,
                                                                  C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_desc.drop () ; // Release 'out' argument
  switch (select_goil_5F_syntax_2 (inCompiler)) {
  case 1: {
    outArgument_desc = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 141)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 143)) ;
    GALGAS_lstring var_partialString_4132 ;
    var_partialString_4132 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 145)) ;
    GALGAS_string var_result_4179 = var_partialString_4132.getter_string (SOURCE_FILE ("goil_syntax.galgas", 146)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_goil_5F_syntax_3 (inCompiler)) {
      case 2: {
        var_partialString_4132 = inCompiler->synthetizedAttribute_a_5F_string () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 149)) ;
        GALGAS_string var_toappend_4278 = var_partialString_4132.getter_string (SOURCE_FILE ("goil_syntax.galgas", 150)) ;
        const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_result_4179.getter_rightSubString (GALGAS_uint ((uint32_t) 2U) COMMA_SOURCE_FILE ("goil_syntax.galgas", 151)).objectCompare (GALGAS_string ("\\n"))).boolEnum () ;
        if (kBoolTrue == test_1) {
          var_toappend_4278 = GALGAS_string (" ").add_operation (var_toappend_4278, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 152)) ;
        }
        var_result_4179.plusAssign_operation(var_toappend_4278, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 154)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    outArgument_desc = GALGAS_lstring::constructor_new (var_result_4179.getter_stringByReplacingStringByString (GALGAS_string ("\\n"), GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 156)), var_partialString_4132.getter_location (SOURCE_FILE ("goil_syntax.galgas", 156))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 156)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_description_i3_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_2 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 143)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 145)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_goil_5F_syntax_3 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 149)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_OIL_5F_version_i4_ (GALGAS_lstring & outArgument_version,
                                                                     GALGAS_lstring & outArgument_desc,
                                                                     C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_version.drop () ; // Release 'out' argument
  outArgument_desc.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) COMMA_SOURCE_FILE ("goil_syntax.galgas", 164)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 164)) ;
  outArgument_version = inCompiler->synthetizedAttribute_a_5F_string () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 164)) ;
  nt_description_ (outArgument_desc, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 164)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_OIL_5F_version_i4_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) COMMA_SOURCE_FILE ("goil_syntax.galgas", 164)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 164)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 164)) ;
  nt_description_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 164)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_application_5F_definition_i5_ (const GALGAS_implementation constinArgument_imp,
                                                                                GALGAS_applicationDefinition & ioArgument_application,
                                                                                GALGAS_string & ioArgument_fileIncludeList,
                                                                                const GALGAS_bool constinArgument_rootFile,
                                                                                C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) COMMA_SOURCE_FILE ("goil_syntax.galgas", 176)) ;
  GALGAS_lstring var_cpuName_5078 = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 176)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 176)) ;
  GALGAS_objectsMap var_objects_5104 = ioArgument_application.getter_objects (SOURCE_FILE ("goil_syntax.galgas", 177)) ;
  nt_object_5F_definition_5F_list_ (constinArgument_imp, var_objects_5104, ioArgument_fileIncludeList, constinArgument_rootFile, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 179)) ;
  GALGAS_lstring joker_5220 ; // Joker input parameter
  nt_description_ (joker_5220, inCompiler) ;
  joker_5220.drop () ; // Release temporary input variables (joker in source)
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 179)) ;
  {
  ioArgument_application.setter_setName (var_cpuName_5078 COMMA_SOURCE_FILE ("goil_syntax.galgas", 180)) ;
  }
  {
  ioArgument_application.setter_setObjects (var_objects_5104 COMMA_SOURCE_FILE ("goil_syntax.galgas", 181)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_application_5F_definition_i5_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) COMMA_SOURCE_FILE ("goil_syntax.galgas", 176)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 176)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 176)) ;
  nt_object_5F_definition_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 179)) ;
  nt_description_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 179)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_object_5F_definition_5F_list_i6_ (const GALGAS_implementation constinArgument_imp,
                                                                                   GALGAS_objectsMap & ioArgument_objects,
                                                                                   GALGAS_string & ioArgument_fileIncludeList,
                                                                                   const GALGAS_bool constinArgument_rootFile,
                                                                                   C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_4 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_objectKind_5486 = inCompiler->synthetizedAttribute_att_5F_token () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 192)) ;
      GALGAS_implementationObject var_impObjOfKind_5525 = callExtensionGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), var_objectKind_5486.getter_string (SOURCE_FILE ("goil_syntax.galgas", 193)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 193)) ;
      GALGAS_objectKind var_objectsForKind_5598 = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 194))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 194)) ;
      const enumGalgasBool test_1 = ioArgument_objects.getter_hasKey (var_objectKind_5486.getter_string (SOURCE_FILE ("goil_syntax.galgas", 195)) COMMA_SOURCE_FILE ("goil_syntax.galgas", 195)).boolEnum () ;
      if (kBoolTrue == test_1) {
        const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_impObjOfKind_5525.getter_multiple (SOURCE_FILE ("goil_syntax.galgas", 199)).getter_bool (SOURCE_FILE ("goil_syntax.galgas", 199)).objectCompare (GALGAS_bool (false))).boolEnum () ;
        if (kBoolTrue == test_2) {
          TC_Array <C_FixItDescription> fixItArray3 ;
          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 200)), GALGAS_string ("object ").add_operation (var_objectKind_5486.getter_string (SOURCE_FILE ("goil_syntax.galgas", 200)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 200)).add_operation (GALGAS_string (" may not have multiple instance"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 200)), fixItArray3  COMMA_SOURCE_FILE ("goil_syntax.galgas", 200)) ;
        }
        {
        ioArgument_objects.setter_del (var_objectKind_5486, var_objectsForKind_5598, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 202)) ;
        }
      }
      GALGAS_lstring var_objectName_6100 = inCompiler->synthetizedAttribute_att_5F_token () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 204)) ;
      GALGAS_objectAttributes var_object_6129 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 205)) ;
      GALGAS_objectKindMap var_objectsKind_6176 = var_objectsForKind_5598.getter_objects (SOURCE_FILE ("goil_syntax.galgas", 206)) ;
      const enumGalgasBool test_4 = var_objectsKind_6176.getter_hasKey (var_objectName_6100.getter_string (SOURCE_FILE ("goil_syntax.galgas", 207)) COMMA_SOURCE_FILE ("goil_syntax.galgas", 207)).boolEnum () ;
      if (kBoolTrue == test_4) {
        {
        var_objectsKind_6176.setter_del (var_objectName_6100, var_object_6129, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 208)) ;
        }
      }
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 210)) ;
      nt_oil_5F_declaration_5F_list_ (var_impObjOfKind_5525.getter_attributes (SOURCE_FILE ("goil_syntax.galgas", 211)), var_object_6129, inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 212)) ;
      GALGAS_lstring var_oil_5F_desc_6431 ;
      nt_description_ (var_oil_5F_desc_6431, inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 214)) ;
      GALGAS_identifierMap var_attributes_6469 = var_object_6129.getter_objectParams (SOURCE_FILE ("goil_syntax.galgas", 215)) ;
      const enumGalgasBool test_5 = var_attributes_6469.getter_hasKey (GALGAS_string ("NAME") COMMA_SOURCE_FILE ("goil_syntax.galgas", 216)).operator_not (SOURCE_FILE ("goil_syntax.galgas", 216)).boolEnum () ;
      if (kBoolTrue == test_5) {
        {
        var_attributes_6469.setter_put (GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), var_objectName_6100.getter_location (SOURCE_FILE ("goil_syntax.galgas", 217))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 217)), GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_6431, var_objectName_6100.getter_location (SOURCE_FILE ("goil_syntax.galgas", 217)), var_objectName_6100.getter_string (SOURCE_FILE ("goil_syntax.galgas", 217))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 217)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 217)) ;
        }
        {
        var_object_6129.setter_setObjectParams (var_attributes_6469 COMMA_SOURCE_FILE ("goil_syntax.galgas", 218)) ;
        }
      }
      {
      var_objectsKind_6176.setter_put (var_objectName_6100, var_object_6129, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 220)) ;
      }
      {
      var_objectsForKind_5598.setter_setObjects (var_objectsKind_6176 COMMA_SOURCE_FILE ("goil_syntax.galgas", 221)) ;
      }
      {
      ioArgument_objects.setter_put (var_objectKind_5486, var_objectsForKind_5598, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 222)) ;
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

void cParser_goil_5F_syntax::rule_goil_5F_syntax_object_5F_definition_5F_list_i6_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_4 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 192)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 204)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 210)) ;
      nt_oil_5F_declaration_5F_list_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 212)) ;
      nt_description_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 214)) ;
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

void cParser_goil_5F_syntax::rule_goil_5F_syntax_boolean_i7_ (GALGAS_lbool & outArgument_val,
                                                              C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_val.drop () ; // Release 'out' argument
  switch (select_goil_5F_syntax_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) COMMA_SOURCE_FILE ("goil_syntax.galgas", 232)) ;
    outArgument_val = GALGAS_lbool::constructor_new (GALGAS_bool (true), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 233))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 233)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) COMMA_SOURCE_FILE ("goil_syntax.galgas", 235)) ;
    outArgument_val = GALGAS_lbool::constructor_new (GALGAS_bool (false), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 236))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 236)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_boolean_i7_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) COMMA_SOURCE_FILE ("goil_syntax.galgas", 232)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) COMMA_SOURCE_FILE ("goil_syntax.galgas", 235)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_ (const GALGAS_implementationObjectMap constinArgument_types,
                                                                                 GALGAS_objectAttributes & ioArgument_identifiers,
                                                                                 C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_6 (inCompiler)) {
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

void cParser_goil_5F_syntax::rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_6 (inCompiler)) {
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

void cParser_goil_5F_syntax::rule_goil_5F_syntax_oil_5F_declaration_i9_ (const GALGAS_implementationObjectMap constinArgument_types,
                                                                         GALGAS_objectAttributes & ioArgument_identifiers,
                                                                         C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_lstring var_idf_7642 ;
  GALGAS_object_5F_t var_val_7658 ;
  var_idf_7642 = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 257)) ;
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("goil_syntax.galgas", 261)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 261))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 261)) ;
  GALGAS_impType var_type_7730 = GALGAS_impVoid::constructor_new (temp_0, GALGAS_dataType::constructor_void (SOURCE_FILE ("goil_syntax.galgas", 261)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 261)), GALGAS_bool (false), GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("goil_syntax.galgas", 261))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 261)) ;
  GALGAS_bool var_typeOk_7829 = GALGAS_bool (false) ;
  const enumGalgasBool test_1 = constinArgument_types.getter_hasKey (var_idf_7642.getter_string (SOURCE_FILE ("goil_syntax.galgas", 263)) COMMA_SOURCE_FILE ("goil_syntax.galgas", 263)).boolEnum () ;
  if (kBoolTrue == test_1) {
    constinArgument_types.method_get (var_idf_7642, var_type_7730, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 264)) ;
    var_typeOk_7829 = GALGAS_bool (true) ;
  }else if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (var_idf_7642.getter_location (SOURCE_FILE ("goil_syntax.galgas", 267)), var_idf_7642.getter_string (SOURCE_FILE ("goil_syntax.galgas", 267)).add_operation (GALGAS_string (" is not declared in the IMPLEMENTATION"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 267)), fixItArray2  COMMA_SOURCE_FILE ("goil_syntax.galgas", 267)) ;
  }
  switch (select_goil_5F_syntax_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 270)) ;
    switch (select_goil_5F_syntax_8 (inCompiler)) {
    case 1: {
      GALGAS_lstring var_value_8113 ;
      var_value_8113 = inCompiler->synthetizedAttribute_att_5F_token () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 274)) ;
      GALGAS_implementationObjectMap var_subTypes_8151 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 275)) ;
      GALGAS_objectAttributes var_subAttributes_8228 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 276)) ;
      switch (var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 277)).enumValue ()) {
      case GALGAS_dataType::kNotBuilt:
        break ;
      case GALGAS_dataType::kEnum_enumeration:
        {
          if (var_type_7730.isValid ()) {
            if (var_type_7730.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
              GALGAS_impEnumType cast_8353_enumType ((cPtr_impEnumType *) var_type_7730.ptr ()) ;
              const enumGalgasBool test_3 = cast_8353_enumType.getter_valuesMap (SOURCE_FILE ("goil_syntax.galgas", 281)).getter_hasKey (var_value_8113.getter_string (SOURCE_FILE ("goil_syntax.galgas", 281)) COMMA_SOURCE_FILE ("goil_syntax.galgas", 281)).boolEnum () ;
              if (kBoolTrue == test_3) {
                cast_8353_enumType.getter_valuesMap (SOURCE_FILE ("goil_syntax.galgas", 282)).method_get (var_value_8113, var_subTypes_8151, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 282)) ;
              }else if (kBoolFalse == test_3) {
                TC_Array <C_FixItDescription> fixItArray4 ;
                inCompiler->emitSemanticError (var_value_8113.getter_location (SOURCE_FILE ("goil_syntax.galgas", 284)), var_value_8113.getter_string (SOURCE_FILE ("goil_syntax.galgas", 284)).add_operation (GALGAS_string (" ENUM value undeclared. One of the following values are expected: "), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 284)).add_operation (function_valueList (cast_8353_enumType.getter_valuesMap (SOURCE_FILE ("goil_syntax.galgas", 284)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 284)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 284)), fixItArray4  COMMA_SOURCE_FILE ("goil_syntax.galgas", 284)) ;
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
          inCompiler->emitSemanticError (var_idf_7642.getter_location (SOURCE_FILE ("goil_syntax.galgas", 290)), var_idf_7642.getter_string (SOURCE_FILE ("goil_syntax.galgas", 290)).add_operation (GALGAS_string (" is not an ENUM nor and IDENTIFIER nor an object reference"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 290)), fixItArray5  COMMA_SOURCE_FILE ("goil_syntax.galgas", 290)) ;
        }
        break ;
      }
      switch (select_goil_5F_syntax_9 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 293)) ;
        nt_oil_5F_declaration_5F_list_ (var_subTypes_8151, var_subAttributes_8228, inCompiler) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 295)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      GALGAS_lstring var_oil_5F_desc_9077 ;
      nt_description_ (var_oil_5F_desc_9077, inCompiler) ;
      const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 298)).objectCompare (GALGAS_dataType::constructor_enumeration (SOURCE_FILE ("goil_syntax.galgas", 298)))).boolEnum () ;
      if (kBoolTrue == test_6) {
        var_val_7658 = GALGAS_enumAttribute::constructor_new (var_oil_5F_desc_9077, var_value_8113.getter_location (SOURCE_FILE ("goil_syntax.galgas", 299)), var_value_8113.getter_string (SOURCE_FILE ("goil_syntax.galgas", 299)), var_subAttributes_8228  COMMA_SOURCE_FILE ("goil_syntax.galgas", 299)) ;
      }else if (kBoolFalse == test_6) {
        const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 300)).objectCompare (GALGAS_dataType::constructor_objectType (SOURCE_FILE ("goil_syntax.galgas", 300)))).boolEnum () ;
        if (kBoolTrue == test_7) {
          var_val_7658 = GALGAS_objectRefAttribute::constructor_new (var_oil_5F_desc_9077, var_value_8113.getter_location (SOURCE_FILE ("goil_syntax.galgas", 301)), var_value_8113  COMMA_SOURCE_FILE ("goil_syntax.galgas", 301)) ;
        }else if (kBoolFalse == test_7) {
          var_val_7658 = GALGAS_string_5F_class::constructor_new (var_oil_5F_desc_9077, var_value_8113.getter_location (SOURCE_FILE ("goil_syntax.galgas", 303)), var_value_8113.getter_string (SOURCE_FILE ("goil_syntax.galgas", 303))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 303)) ;
        }
      }
    } break ;
    case 2: {
      GALGAS_bool var_sign_9505 ;
      nt_sign_ (var_sign_9505, inCompiler) ;
      switch (select_goil_5F_syntax_10 (inCompiler)) {
      case 1: {
        GALGAS_luint_36__34_ var_value_9583 ;
        var_value_9583 = inCompiler->synthetizedAttribute_integerNumber () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_SOURCE_FILE ("goil_syntax.galgas", 312)) ;
        GALGAS_lstring var_oil_5F_desc_9657 ;
        nt_description_ (var_oil_5F_desc_9657, inCompiler) ;
        var_val_7658 = function_checkAndGetIntegerNumber (var_oil_5F_desc_9657, var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 314)), var_value_9583, var_sign_9505, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 314)) ;
      } break ;
      case 2: {
        GALGAS_ldouble var_value_9789 ;
        var_value_9789 = inCompiler->synthetizedAttribute_floatNumber () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE ("goil_syntax.galgas", 318)) ;
        GALGAS_lstring var_oil_5F_desc_9864 ;
        nt_description_ (var_oil_5F_desc_9864, inCompiler) ;
        var_val_7658 = function_checkAndGetFloatNumber (var_oil_5F_desc_9864, var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 320)), var_value_9789, var_sign_9505, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 320)) ;
      } break ;
      default:
        break ;
      }
    } break ;
    case 3: {
      GALGAS_lbool var_value_9995 ;
      nt_boolean_ (var_value_9995, inCompiler) ;
      GALGAS_implementationObjectMap var_subTypes_10037 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 326)) ;
      GALGAS_objectAttributes var_subAttributes_10112 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 327)) ;
      const enumGalgasBool test_8 = GALGAS_bool (kIsNotEqual, var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 328)).objectCompare (GALGAS_dataType::constructor_boolean (SOURCE_FILE ("goil_syntax.galgas", 328)))).boolEnum () ;
      if (kBoolTrue == test_8) {
        TC_Array <C_FixItDescription> fixItArray9 ;
        inCompiler->emitSemanticError (var_idf_7642.getter_location (SOURCE_FILE ("goil_syntax.galgas", 329)), extensionGetter_oilType (var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 329)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 329)).add_operation (GALGAS_string (" expected, got a BOOLEAN"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 329)), fixItArray9  COMMA_SOURCE_FILE ("goil_syntax.galgas", 329)) ;
      }else if (kBoolFalse == test_8) {
        if (var_type_7730.isValid ()) {
          if (var_type_7730.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impBoolType) {
            GALGAS_impBoolType cast_10315_boolType ((cPtr_impBoolType *) var_type_7730.ptr ()) ;
            const enumGalgasBool test_10 = var_value_9995.getter_bool (SOURCE_FILE ("goil_syntax.galgas", 333)).boolEnum () ;
            if (kBoolTrue == test_10) {
              var_subTypes_10037 = cast_10315_boolType.getter_trueSubAttributes (SOURCE_FILE ("goil_syntax.galgas", 334)) ;
            }else if (kBoolFalse == test_10) {
              var_subTypes_10037 = cast_10315_boolType.getter_falseSubAttributes (SOURCE_FILE ("goil_syntax.galgas", 336)) ;
            }
          }
        }
      }
      switch (select_goil_5F_syntax_11 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 341)) ;
        const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, var_subTypes_10037.getter_count (SOURCE_FILE ("goil_syntax.galgas", 342)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_11) {
          TC_Array <C_FixItDescription> fixItArray12 ;
          inCompiler->emitSemanticError (var_value_9995.getter_location (SOURCE_FILE ("goil_syntax.galgas", 343)), function_stringLBool (var_value_9995, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 343)).add_operation (GALGAS_string (" value of "), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 343)).add_operation (var_idf_7642.getter_string (SOURCE_FILE ("goil_syntax.galgas", 343)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 343)).add_operation (GALGAS_string (" has no sub-attribute"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 343)), fixItArray12  COMMA_SOURCE_FILE ("goil_syntax.galgas", 343)) ;
        }
        nt_oil_5F_declaration_5F_list_ (var_subTypes_10037, var_subAttributes_10112, inCompiler) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 346)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      GALGAS_lstring var_oil_5F_desc_10813 ;
      nt_description_ (var_oil_5F_desc_10813, inCompiler) ;
      var_val_7658 = GALGAS_boolAttribute::constructor_new (var_oil_5F_desc_10813, var_idf_7642.getter_location (SOURCE_FILE ("goil_syntax.galgas", 349)), var_value_9995.getter_bool (SOURCE_FILE ("goil_syntax.galgas", 349)), var_subAttributes_10112  COMMA_SOURCE_FILE ("goil_syntax.galgas", 349)) ;
    } break ;
    case 4: {
      GALGAS_lstring var_literalString_10962 ;
      var_literalString_10962 = inCompiler->synthetizedAttribute_a_5F_string () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 353)) ;
      GALGAS_lstring var_oil_5F_desc_11035 ;
      nt_description_ (var_oil_5F_desc_11035, inCompiler) ;
      var_val_7658 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_11035, var_literalString_10962.getter_location (SOURCE_FILE ("goil_syntax.galgas", 355)), var_literalString_10962.getter_string (SOURCE_FILE ("goil_syntax.galgas", 355))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 355)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("goil_syntax.galgas", 358)) ;
      GALGAS_lstring var_oil_5F_desc_11208 ;
      nt_description_ (var_oil_5F_desc_11208, inCompiler) ;
      const enumGalgasBool test_13 = callExtensionGetter_autoAllowed ((const cPtr_impType *) var_type_7730.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 361)).boolEnum () ;
      if (kBoolTrue == test_13) {
        var_val_7658 = GALGAS_auto::constructor_new (var_oil_5F_desc_11208, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 362))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 362)) ;
      }else if (kBoolFalse == test_13) {
        TC_Array <C_FixItDescription> fixItArray14 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 377)), GALGAS_string ("AUTO is not allowed"), fixItArray14  COMMA_SOURCE_FILE ("goil_syntax.galgas", 377)) ;
        var_val_7658.drop () ; // Release error dropped variable
      }
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    GALGAS_lstring var_name_12039 = inCompiler->synthetizedAttribute_att_5F_token () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 381)) ;
    GALGAS_implementationObjectMap var_subTypes_12056 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 382)) ;
    GALGAS_objectAttributes var_subAttributes_12129 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 383)) ;
    const enumGalgasBool test_15 = GALGAS_bool (kIsNotEqual, var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 385)).objectCompare (GALGAS_dataType::constructor_structType (SOURCE_FILE ("goil_syntax.galgas", 385)))).boolEnum () ;
    if (kBoolTrue == test_15) {
      TC_Array <C_FixItDescription> fixItArray16 ;
      inCompiler->emitSemanticError (var_idf_7642.getter_location (SOURCE_FILE ("goil_syntax.galgas", 386)), extensionGetter_oilType (var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 386)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 386)).add_operation (GALGAS_string (" expected, got a STRUCT"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 386)), fixItArray16  COMMA_SOURCE_FILE ("goil_syntax.galgas", 386)) ;
    }else if (kBoolFalse == test_15) {
      if (var_type_7730.isValid ()) {
        if (var_type_7730.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impStructType) {
          GALGAS_impStructType cast_12341_structType ((cPtr_impStructType *) var_type_7730.ptr ()) ;
          var_subTypes_12056 = cast_12341_structType.getter_structAttributes (SOURCE_FILE ("goil_syntax.galgas", 390)) ;
        }
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 393)) ;
    nt_oil_5F_declaration_5F_list_ (var_subTypes_12056, var_subAttributes_12129, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 395)) ;
    GALGAS_lstring var_oil_5F_desc_12533 ;
    nt_description_ (var_oil_5F_desc_12533, inCompiler) ;
    var_val_7658 = GALGAS_structAttribute::constructor_new (var_oil_5F_desc_12533, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 397)), var_name_12039, var_subAttributes_12129  COMMA_SOURCE_FILE ("goil_syntax.galgas", 397)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 399)) ;
  GALGAS_identifierMap var_idfs_12677 = ioArgument_identifiers.getter_objectParams (SOURCE_FILE ("goil_syntax.galgas", 402)) ;
  const enumGalgasBool test_17 = var_type_7730.getter_multiple (SOURCE_FILE ("goil_syntax.galgas", 403)).boolEnum () ;
  if (kBoolTrue == test_17) {
    const enumGalgasBool test_18 = var_idfs_12677.getter_hasKey (var_idf_7642.getter_string (SOURCE_FILE ("goil_syntax.galgas", 404)) COMMA_SOURCE_FILE ("goil_syntax.galgas", 404)).boolEnum () ;
    if (kBoolTrue == test_18) {
      GALGAS_object_5F_t var_attributeList_12801 ;
      {
      var_idfs_12677.setter_del (var_idf_7642, var_attributeList_12801, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 408)) ;
      }
      if (var_attributeList_12801.isValid ()) {
        if (var_attributeList_12801.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
          GALGAS_multipleAttribute cast_12995_multiAttribute ((cPtr_multipleAttribute *) var_attributeList_12801.ptr ()) ;
          GALGAS_identifierList var_aList_13027 = cast_12995_multiAttribute.getter_items (SOURCE_FILE ("goil_syntax.galgas", 411)) ;
          var_aList_13027.addAssign_operation (var_val_7658  COMMA_SOURCE_FILE ("goil_syntax.galgas", 412)) ;
          var_val_7658 = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 413)), cast_12995_multiAttribute.getter_location (SOURCE_FILE ("goil_syntax.galgas", 413)), var_aList_13027  COMMA_SOURCE_FILE ("goil_syntax.galgas", 413)) ;
        }
      }
    }else if (kBoolFalse == test_18) {
      var_val_7658 = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 416)), var_val_7658.getter_location (SOURCE_FILE ("goil_syntax.galgas", 416)), GALGAS_identifierList::constructor_listWithValue (var_val_7658  COMMA_SOURCE_FILE ("goil_syntax.galgas", 416))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 416)) ;
    }
  }
  const enumGalgasBool test_19 = var_typeOk_7829.boolEnum () ;
  if (kBoolTrue == test_19) {
    {
    var_idfs_12677.setter_put (var_idf_7642, var_val_7658, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 420)) ;
    }
  }
  {
  ioArgument_identifiers.setter_setObjectParams (var_idfs_12677 COMMA_SOURCE_FILE ("goil_syntax.galgas", 422)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_oil_5F_declaration_i9_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 257)) ;
  switch (select_goil_5F_syntax_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 270)) ;
    switch (select_goil_5F_syntax_8 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 274)) ;
      switch (select_goil_5F_syntax_9 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 293)) ;
        nt_oil_5F_declaration_5F_list_parse (inCompiler) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 295)) ;
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
      switch (select_goil_5F_syntax_10 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_SOURCE_FILE ("goil_syntax.galgas", 312)) ;
        nt_description_parse (inCompiler) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE ("goil_syntax.galgas", 318)) ;
        nt_description_parse (inCompiler) ;
      } break ;
      default:
        break ;
      }
    } break ;
    case 3: {
      nt_boolean_parse (inCompiler) ;
      switch (select_goil_5F_syntax_11 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 341)) ;
        nt_oil_5F_declaration_5F_list_parse (inCompiler) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 346)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      nt_description_parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 353)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("goil_syntax.galgas", 358)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 381)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 393)) ;
    nt_oil_5F_declaration_5F_list_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 395)) ;
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 399)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_file_5F_level_i10_ (GALGAS_implementation & ioArgument_imp,
                                                                                GALGAS_applicationDefinition & ioArgument_application,
                                                                                GALGAS_string & ioArgument_fileIncludeList,
                                                                                const GALGAS_bool constinArgument_rootFile,
                                                                                C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_bool var_includeIfExists_13579 = GALGAS_bool (false) ;
  switch (select_goil_5F_syntax_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("goil_syntax.galgas", 433)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) COMMA_SOURCE_FILE ("goil_syntax.galgas", 435)) ;
    var_includeIfExists_13579 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  GALGAS_lstring var_file_5F_name_13687 ;
  switch (select_goil_5F_syntax_13 (inCompiler)) {
  case 1: {
    var_file_5F_name_13687 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 439)) ;
    {
    routine_file_5F_in_5F_path (var_file_5F_name_13687, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 440)) ;
    }
  } break ;
  case 2: {
    var_file_5F_name_13687 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 442)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_bool test_0 = var_includeIfExists_13579.operator_not (SOURCE_FILE ("goil_syntax.galgas", 444)) ;
  if (kBoolTrue != test_0.boolEnum ()) {
    GALGAS_bool test_1 = var_includeIfExists_13579 ;
    if (kBoolTrue == test_1.boolEnum ()) {
      test_1 = var_file_5F_name_13687.mAttribute_string.getter_fileExists (SOURCE_FILE ("goil_syntax.galgas", 444)) ;
    }
    test_0 = test_1 ;
  }
  const enumGalgasBool test_2 = test_0.boolEnum () ;
  if (kBoolTrue == test_2) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, var_file_5F_name_13687, ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, constinArgument_rootFile  COMMA_SOURCE_FILE ("goil_syntax.galgas", 445)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("goil_syntax.galgas", 433)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) COMMA_SOURCE_FILE ("goil_syntax.galgas", 435)) ;
  } break ;
  default:
    break ;
  }
  switch (select_goil_5F_syntax_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 439)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 442)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_ (const GALGAS_implementation constinArgument_imp,
                                                                               GALGAS_objectsMap & ioArgument_objects,
                                                                               GALGAS_string & ioArgument_fileIncludeList,
                                                                               const GALGAS_bool constinArgument_rootFile,
                                                                               C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_bool var_includeIfExists_14126 = GALGAS_bool (false) ;
  switch (select_goil_5F_syntax_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("goil_syntax.galgas", 457)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) COMMA_SOURCE_FILE ("goil_syntax.galgas", 459)) ;
    var_includeIfExists_14126 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  GALGAS_lstring var_file_5F_name_14234 ;
  switch (select_goil_5F_syntax_15 (inCompiler)) {
  case 1: {
    var_file_5F_name_14234 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 463)) ;
    {
    routine_file_5F_in_5F_path (var_file_5F_name_14234, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 464)) ;
    }
  } break ;
  case 2: {
    var_file_5F_name_14234 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 466)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_bool test_0 = var_includeIfExists_14126.operator_not (SOURCE_FILE ("goil_syntax.galgas", 468)) ;
  if (kBoolTrue != test_0.boolEnum ()) {
    GALGAS_bool test_1 = var_includeIfExists_14126 ;
    if (kBoolTrue == test_1.boolEnum ()) {
      test_1 = var_file_5F_name_14234.mAttribute_string.getter_fileExists (SOURCE_FILE ("goil_syntax.galgas", 468)) ;
    }
    test_0 = test_1 ;
  }
  const enumGalgasBool test_2 = test_0.boolEnum () ;
  if (kBoolTrue == test_2) {
    cGrammar_goil_5F_cpu_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, var_file_5F_name_14234, constinArgument_imp, ioArgument_objects, ioArgument_fileIncludeList, constinArgument_rootFile  COMMA_SOURCE_FILE ("goil_syntax.galgas", 469)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("goil_syntax.galgas", 457)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) COMMA_SOURCE_FILE ("goil_syntax.galgas", 459)) ;
  } break ;
  default:
    break ;
  }
  switch (select_goil_5F_syntax_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 463)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 466)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_object_5F_level_i12_ (const GALGAS_implementationObjectMap constinArgument_types,
                                                                                  GALGAS_objectAttributes & ioArgument_identifiers,
                                                                                  C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_bool var_includeIfExists_14641 = GALGAS_bool (false) ;
  switch (select_goil_5F_syntax_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("goil_syntax.galgas", 479)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) COMMA_SOURCE_FILE ("goil_syntax.galgas", 481)) ;
    var_includeIfExists_14641 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  GALGAS_lstring var_file_5F_name_14749 ;
  switch (select_goil_5F_syntax_17 (inCompiler)) {
  case 1: {
    var_file_5F_name_14749 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 485)) ;
    {
    routine_file_5F_in_5F_path (var_file_5F_name_14749, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 486)) ;
    }
  } break ;
  case 2: {
    var_file_5F_name_14749 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 488)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_bool test_0 = var_includeIfExists_14641.operator_not (SOURCE_FILE ("goil_syntax.galgas", 490)) ;
  if (kBoolTrue != test_0.boolEnum ()) {
    GALGAS_bool test_1 = var_includeIfExists_14641 ;
    if (kBoolTrue == test_1.boolEnum ()) {
      test_1 = var_file_5F_name_14749.mAttribute_string.getter_fileExists (SOURCE_FILE ("goil_syntax.galgas", 490)) ;
    }
    test_0 = test_1 ;
  }
  const enumGalgasBool test_2 = test_0.boolEnum () ;
  if (kBoolTrue == test_2) {
    cGrammar_goil_5F_object_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, var_file_5F_name_14749, constinArgument_types, ioArgument_identifiers  COMMA_SOURCE_FILE ("goil_syntax.galgas", 491)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_object_5F_level_i12_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("goil_syntax.galgas", 479)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) COMMA_SOURCE_FILE ("goil_syntax.galgas", 481)) ;
  } break ;
  default:
    break ;
  }
  switch (select_goil_5F_syntax_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 485)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 488)) ;
  } break ;
  default:
    break ;
  }
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

static const int16_t gProductions_goil_object_level_include [] = {
// At index 0 : <start>, in file 'goil_syntax.ggs', line 38
  NONTERMINAL (5) // <OIL_version>
, NONTERMINAL (2) // <file>
, END_PRODUCTION
// At index 3 : <file>, in file 'goil_syntax.ggs', line 110
, NONTERMINAL (14) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 5 : <sign>, in file 'goil_syntax.ggs', line 126
, NONTERMINAL (15) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 7 : <description>, in file 'goil_syntax.ggs', line 139
, NONTERMINAL (16) // <select_goil_5F_syntax_2>
, END_PRODUCTION
// At index 9 : <OIL_version>, in file 'goil_syntax.ggs', line 163
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) // $OIL_VERSION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 15 : <application_definition>, in file 'goil_syntax.ggs', line 170
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) // $CPU$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (7) // <object_definition_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 23 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
, NONTERMINAL (18) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 25 : <boolean>, in file 'goil_syntax.ggs', line 230
, NONTERMINAL (19) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 27 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
, NONTERMINAL (20) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 29 : <oil_declaration>, in file 'goil_syntax.ggs', line 252
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (21) // <select_goil_5F_syntax_7>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 33 : <include_file_level>, in file 'goil_syntax.ggs', line 425
, NONTERMINAL (26) // <select_goil_5F_syntax_12>
, NONTERMINAL (27) // <select_goil_5F_syntax_13>
, END_PRODUCTION
// At index 36 : <include_cpu_level>, in file 'goil_syntax.ggs', line 449
, NONTERMINAL (28) // <select_goil_5F_syntax_14>
, NONTERMINAL (29) // <select_goil_5F_syntax_15>
, END_PRODUCTION
// At index 39 : <include_object_level>, in file 'goil_syntax.ggs', line 473
, NONTERMINAL (30) // <select_goil_5F_syntax_16>
, NONTERMINAL (31) // <select_goil_5F_syntax_17>
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 42 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, END_PRODUCTION
// At index 43 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (11) // <include_file_level>
, NONTERMINAL (14) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 46 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (14) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 49 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (6) // <application_definition>
, NONTERMINAL (14) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 52 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) // $-$
, END_PRODUCTION
// At index 54 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) // $+$
, END_PRODUCTION
// At index 56 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, END_PRODUCTION
// At index 57 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, END_PRODUCTION
// At index 58 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) // $:$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (17) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 62 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, END_PRODUCTION
// At index 63 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (17) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 66 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, END_PRODUCTION
// At index 67 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (18) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 76 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, NONTERMINAL (12) // <include_cpu_level>
, NONTERMINAL (18) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 79 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 81 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 83 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, END_PRODUCTION
// At index 84 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (10) // <oil_declaration>
, NONTERMINAL (20) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 87 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (13) // <include_object_level>
, NONTERMINAL (20) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 90 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (22) // <select_goil_5F_syntax_8>
, END_PRODUCTION
// At index 93 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 99 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (23) // <select_goil_5F_syntax_9>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 103 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, NONTERMINAL (3) // <sign>
, NONTERMINAL (24) // <select_goil_5F_syntax_10>
, END_PRODUCTION
// At index 106 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (25) // <select_goil_5F_syntax_11>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 110 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 113 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 116 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 120 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
, END_PRODUCTION
// At index 121 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 124 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 127 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 131 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
, END_PRODUCTION
// At index 132 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 134 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 136 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 138 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 140 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 142 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 144 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 146 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 148 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 150 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 152 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 154 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 156 : <>, in file '.ggs', line 0
, NONTERMINAL (9) // <oil_declaration_list>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_goil_object_level_include [58] = {
 {"<start>", "goil_syntax", 0}, // at index 0
 {"<file>", "goil_syntax", 3}, // at index 1
 {"<sign>", "goil_syntax", 5}, // at index 2
 {"<description>", "goil_syntax", 7}, // at index 3
 {"<OIL_version>", "goil_syntax", 9}, // at index 4
 {"<application_definition>", "goil_syntax", 15}, // at index 5
 {"<object_definition_list>", "goil_syntax", 23}, // at index 6
 {"<boolean>", "goil_syntax", 25}, // at index 7
 {"<oil_declaration_list>", "goil_syntax", 27}, // at index 8
 {"<oil_declaration>", "goil_syntax", 29}, // at index 9
 {"<include_file_level>", "goil_syntax", 33}, // at index 10
 {"<include_cpu_level>", "goil_syntax", 36}, // at index 11
 {"<include_object_level>", "goil_syntax", 39}, // at index 12
 {"<select_goil_5F_syntax_0>", "goil_syntax", 42}, // at index 13
 {"<select_goil_5F_syntax_0>", "goil_syntax", 43}, // at index 14
 {"<select_goil_5F_syntax_0>", "goil_syntax", 46}, // at index 15
 {"<select_goil_5F_syntax_0>", "goil_syntax", 49}, // at index 16
 {"<select_goil_5F_syntax_1>", "goil_syntax", 52}, // at index 17
 {"<select_goil_5F_syntax_1>", "goil_syntax", 54}, // at index 18
 {"<select_goil_5F_syntax_1>", "goil_syntax", 56}, // at index 19
 {"<select_goil_5F_syntax_2>", "goil_syntax", 57}, // at index 20
 {"<select_goil_5F_syntax_2>", "goil_syntax", 58}, // at index 21
 {"<select_goil_5F_syntax_3>", "goil_syntax", 62}, // at index 22
 {"<select_goil_5F_syntax_3>", "goil_syntax", 63}, // at index 23
 {"<select_goil_5F_syntax_4>", "goil_syntax", 66}, // at index 24
 {"<select_goil_5F_syntax_4>", "goil_syntax", 67}, // at index 25
 {"<select_goil_5F_syntax_4>", "goil_syntax", 76}, // at index 26
 {"<select_goil_5F_syntax_5>", "goil_syntax", 79}, // at index 27
 {"<select_goil_5F_syntax_5>", "goil_syntax", 81}, // at index 28
 {"<select_goil_5F_syntax_6>", "goil_syntax", 83}, // at index 29
 {"<select_goil_5F_syntax_6>", "goil_syntax", 84}, // at index 30
 {"<select_goil_5F_syntax_6>", "goil_syntax", 87}, // at index 31
 {"<select_goil_5F_syntax_7>", "goil_syntax", 90}, // at index 32
 {"<select_goil_5F_syntax_7>", "goil_syntax", 93}, // at index 33
 {"<select_goil_5F_syntax_8>", "goil_syntax", 99}, // at index 34
 {"<select_goil_5F_syntax_8>", "goil_syntax", 103}, // at index 35
 {"<select_goil_5F_syntax_8>", "goil_syntax", 106}, // at index 36
 {"<select_goil_5F_syntax_8>", "goil_syntax", 110}, // at index 37
 {"<select_goil_5F_syntax_8>", "goil_syntax", 113}, // at index 38
 {"<select_goil_5F_syntax_9>", "goil_syntax", 116}, // at index 39
 {"<select_goil_5F_syntax_9>", "goil_syntax", 120}, // at index 40
 {"<select_goil_5F_syntax_10>", "goil_syntax", 121}, // at index 41
 {"<select_goil_5F_syntax_10>", "goil_syntax", 124}, // at index 42
 {"<select_goil_5F_syntax_11>", "goil_syntax", 127}, // at index 43
 {"<select_goil_5F_syntax_11>", "goil_syntax", 131}, // at index 44
 {"<select_goil_5F_syntax_12>", "goil_syntax", 132}, // at index 45
 {"<select_goil_5F_syntax_12>", "goil_syntax", 134}, // at index 46
 {"<select_goil_5F_syntax_13>", "goil_syntax", 136}, // at index 47
 {"<select_goil_5F_syntax_13>", "goil_syntax", 138}, // at index 48
 {"<select_goil_5F_syntax_14>", "goil_syntax", 140}, // at index 49
 {"<select_goil_5F_syntax_14>", "goil_syntax", 142}, // at index 50
 {"<select_goil_5F_syntax_15>", "goil_syntax", 144}, // at index 51
 {"<select_goil_5F_syntax_15>", "goil_syntax", 146}, // at index 52
 {"<select_goil_5F_syntax_16>", "goil_syntax", 148}, // at index 53
 {"<select_goil_5F_syntax_16>", "goil_syntax", 150}, // at index 54
 {"<select_goil_5F_syntax_17>", "goil_syntax", 152}, // at index 55
 {"<select_goil_5F_syntax_17>", "goil_syntax", 154}, // at index 56
 {"<>", "", 156} // at index 57
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_goil_object_level_include [58] = {
0, // index 0 : <start>, in file 'goil_syntax.ggs', line 38
3, // index 1 : <file>, in file 'goil_syntax.ggs', line 110
5, // index 2 : <sign>, in file 'goil_syntax.ggs', line 126
7, // index 3 : <description>, in file 'goil_syntax.ggs', line 139
9, // index 4 : <OIL_version>, in file 'goil_syntax.ggs', line 163
15, // index 5 : <application_definition>, in file 'goil_syntax.ggs', line 170
23, // index 6 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
25, // index 7 : <boolean>, in file 'goil_syntax.ggs', line 230
27, // index 8 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
29, // index 9 : <oil_declaration>, in file 'goil_syntax.ggs', line 252
33, // index 10 : <include_file_level>, in file 'goil_syntax.ggs', line 425
36, // index 11 : <include_cpu_level>, in file 'goil_syntax.ggs', line 449
39, // index 12 : <include_object_level>, in file 'goil_syntax.ggs', line 473
42, // index 13 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
43, // index 14 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
46, // index 15 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
49, // index 16 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
52, // index 17 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
54, // index 18 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
56, // index 19 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
57, // index 20 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
58, // index 21 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
62, // index 22 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
63, // index 23 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
66, // index 24 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
67, // index 25 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
76, // index 26 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
79, // index 27 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
81, // index 28 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
83, // index 29 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
84, // index 30 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
87, // index 31 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
90, // index 32 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
93, // index 33 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
99, // index 34 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
103, // index 35 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
106, // index 36 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
110, // index 37 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
113, // index 38 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
116, // index 39 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
120, // index 40 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
121, // index 41 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
124, // index 42 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
127, // index 43 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
131, // index 44 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
132, // index 45 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
134, // index 46 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
136, // index 47 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
138, // index 48 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
140, // index 49 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
142, // index 50 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
144, // index 51 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
146, // index 52 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
148, // index 53 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
150, // index 54 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
152, // index 55 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
154, // index 56 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
156 // index 57 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_goil_object_level_include [34] = {
0, // at 0 : <implementation_definition>
0, // at 1 : <start>
1, // at 2 : <file>
2, // at 3 : <sign>
3, // at 4 : <description>
4, // at 5 : <OIL_version>
5, // at 6 : <application_definition>
6, // at 7 : <object_definition_list>
7, // at 8 : <boolean>
8, // at 9 : <oil_declaration_list>
9, // at 10 : <oil_declaration>
10, // at 11 : <include_file_level>
11, // at 12 : <include_cpu_level>
12, // at 13 : <include_object_level>
13, // at 14 : <select_goil_5F_syntax_0>
17, // at 15 : <select_goil_5F_syntax_1>
20, // at 16 : <select_goil_5F_syntax_2>
22, // at 17 : <select_goil_5F_syntax_3>
24, // at 18 : <select_goil_5F_syntax_4>
27, // at 19 : <select_goil_5F_syntax_5>
29, // at 20 : <select_goil_5F_syntax_6>
32, // at 21 : <select_goil_5F_syntax_7>
34, // at 22 : <select_goil_5F_syntax_8>
39, // at 23 : <select_goil_5F_syntax_9>
41, // at 24 : <select_goil_5F_syntax_10>
43, // at 25 : <select_goil_5F_syntax_11>
45, // at 26 : <select_goil_5F_syntax_12>
47, // at 27 : <select_goil_5F_syntax_13>
49, // at 28 : <select_goil_5F_syntax_14>
51, // at 29 : <select_goil_5F_syntax_15>
53, // at 30 : <select_goil_5F_syntax_16>
55, // at 31 : <select_goil_5F_syntax_17>
57, // at 32 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_goil_object_level_include [] = {
// At index 0 : <implementation_definition> no production
// At index 0 : <start> only one production, no choice
  -1,
// At index 1 : <file> only one production, no choice
  -1,
// At index 2 : <sign> only one production, no choice
  -1,
// At index 3 : <description> only one production, no choice
  -1,
// At index 4 : <OIL_version> only one production, no choice
  -1,
// At index 5 : <application_definition> only one production, no choice
  -1,
// At index 6 : <object_definition_list> only one production, no choice
  -1,
// At index 7 : <boolean> only one production, no choice
  -1,
// At index 8 : <oil_declaration_list> only one production, no choice
  -1,
// At index 9 : <oil_declaration> only one production, no choice
  -1,
// At index 10 : <include_file_level> only one production, no choice
  -1,
// At index 11 : <include_cpu_level> only one production, no choice
  -1,
// At index 12 : <include_object_level> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 13 : <select_goil_5F_syntax_0>
-1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
-1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 21 : <select_goil_5F_syntax_1>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 3
  -1,
// At index 29 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 34 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 39 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 47 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 52 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken__7D_, C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 61 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 66 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 81 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 87 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 92 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 98 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 103 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 108 : <select_goil_5F_syntax_14>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 113 : <select_goil_5F_syntax_15>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 118 : <select_goil_5F_syntax_16>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 123 : <select_goil_5F_syntax_17>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 128 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_goil_object_level_include [34] = {
0, // at 0 : <implementation_definition>
0, // at 1 : <start>
1, // at 2 : <file>
2, // at 3 : <sign>
3, // at 4 : <description>
4, // at 5 : <OIL_version>
5, // at 6 : <application_definition>
6, // at 7 : <object_definition_list>
7, // at 8 : <boolean>
8, // at 9 : <oil_declaration_list>
9, // at 10 : <oil_declaration>
10, // at 11 : <include_file_level>
11, // at 12 : <include_cpu_level>
12, // at 13 : <include_object_level>
13, // at 14 : <select_goil_5F_syntax_0>
21, // at 15 : <select_goil_5F_syntax_1>
29, // at 16 : <select_goil_5F_syntax_2>
34, // at 17 : <select_goil_5F_syntax_3>
39, // at 18 : <select_goil_5F_syntax_4>
47, // at 19 : <select_goil_5F_syntax_5>
52, // at 20 : <select_goil_5F_syntax_6>
61, // at 21 : <select_goil_5F_syntax_7>
66, // at 22 : <select_goil_5F_syntax_8>
81, // at 23 : <select_goil_5F_syntax_9>
87, // at 24 : <select_goil_5F_syntax_10>
92, // at 25 : <select_goil_5F_syntax_11>
98, // at 26 : <select_goil_5F_syntax_12>
103, // at 27 : <select_goil_5F_syntax_13>
108, // at 28 : <select_goil_5F_syntax_14>
113, // at 29 : <select_goil_5F_syntax_15>
118, // at 30 : <select_goil_5F_syntax_16>
123, // at 31 : <select_goil_5F_syntax_17>
128, // at 32 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_definition' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * ) {
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

void cGrammar_goil_5F_object_5F_level_5F_include::nt_file_ (GALGAS_implementation & parameter_1,
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

void cGrammar_goil_5F_object_5F_level_5F_include::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'description' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'OIL_version' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'application_definition' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_application_5F_definition_ (const GALGAS_implementation parameter_1,
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

void cGrammar_goil_5F_object_5F_level_5F_include::nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_object_5F_definition_5F_list_ (const GALGAS_implementation parameter_1,
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

void cGrammar_goil_5F_object_5F_level_5F_include::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'oil_declaration_list' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_(parameter_1, parameter_2, inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_goil_5F_object_5F_level_5F_include::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performTopDownParsing (gProductions_goil_object_level_include, gProductionNames_goil_object_level_include, gProductionIndexes_goil_object_level_include,
                                    gFirstProductionIndexes_goil_object_level_include, gDecision_goil_object_level_include, gDecisionIndexes_goil_object_level_include, 156) ;
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
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", filePath COMMA_HERE)) ;
    if (scanner->sourceText () != NULL) {
      const bool ok = scanner->performTopDownParsing (gProductions_goil_object_level_include, gProductionNames_goil_object_level_include, gProductionIndexes_goil_object_level_include,
                                                      gFirstProductionIndexes_goil_object_level_include, gDecision_goil_object_level_include, gDecisionIndexes_goil_object_level_include, 156) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_object_5F_level_5F_include grammar ;
        grammar.nt_oil_5F_declaration_5F_list_ (parameter_1, parameter_2, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
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
                                                    gFirstProductionIndexes_goil_object_level_include, gDecision_goil_object_level_include, gDecisionIndexes_goil_object_level_include, 156) ;
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
  rule_goil_5F_syntax_oil_5F_declaration_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_file_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_file_5F_level_ (GALGAS_implementation & parameter_1,
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

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_cpu_5F_level_ (const GALGAS_implementation parameter_1,
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

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_(parameter_1, parameter_2, inLexique) ;
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

static const int16_t gProductions_goil_cpu_level_include [] = {
// At index 0 : <start>, in file 'goil_syntax.ggs', line 38
  NONTERMINAL (5) // <OIL_version>
, NONTERMINAL (2) // <file>
, END_PRODUCTION
// At index 3 : <file>, in file 'goil_syntax.ggs', line 110
, NONTERMINAL (14) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 5 : <sign>, in file 'goil_syntax.ggs', line 126
, NONTERMINAL (15) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 7 : <description>, in file 'goil_syntax.ggs', line 139
, NONTERMINAL (16) // <select_goil_5F_syntax_2>
, END_PRODUCTION
// At index 9 : <OIL_version>, in file 'goil_syntax.ggs', line 163
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) // $OIL_VERSION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 15 : <application_definition>, in file 'goil_syntax.ggs', line 170
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) // $CPU$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (7) // <object_definition_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 23 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
, NONTERMINAL (18) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 25 : <boolean>, in file 'goil_syntax.ggs', line 230
, NONTERMINAL (19) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 27 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
, NONTERMINAL (20) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 29 : <oil_declaration>, in file 'goil_syntax.ggs', line 252
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (21) // <select_goil_5F_syntax_7>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 33 : <include_file_level>, in file 'goil_syntax.ggs', line 425
, NONTERMINAL (26) // <select_goil_5F_syntax_12>
, NONTERMINAL (27) // <select_goil_5F_syntax_13>
, END_PRODUCTION
// At index 36 : <include_cpu_level>, in file 'goil_syntax.ggs', line 449
, NONTERMINAL (28) // <select_goil_5F_syntax_14>
, NONTERMINAL (29) // <select_goil_5F_syntax_15>
, END_PRODUCTION
// At index 39 : <include_object_level>, in file 'goil_syntax.ggs', line 473
, NONTERMINAL (30) // <select_goil_5F_syntax_16>
, NONTERMINAL (31) // <select_goil_5F_syntax_17>
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 42 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, END_PRODUCTION
// At index 43 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (11) // <include_file_level>
, NONTERMINAL (14) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 46 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (14) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 49 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (6) // <application_definition>
, NONTERMINAL (14) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 52 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) // $-$
, END_PRODUCTION
// At index 54 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) // $+$
, END_PRODUCTION
// At index 56 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, END_PRODUCTION
// At index 57 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, END_PRODUCTION
// At index 58 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) // $:$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (17) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 62 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, END_PRODUCTION
// At index 63 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (17) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 66 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, END_PRODUCTION
// At index 67 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (18) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 76 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, NONTERMINAL (12) // <include_cpu_level>
, NONTERMINAL (18) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 79 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 81 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 83 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, END_PRODUCTION
// At index 84 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (10) // <oil_declaration>
, NONTERMINAL (20) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 87 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (13) // <include_object_level>
, NONTERMINAL (20) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 90 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (22) // <select_goil_5F_syntax_8>
, END_PRODUCTION
// At index 93 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 99 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (23) // <select_goil_5F_syntax_9>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 103 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, NONTERMINAL (3) // <sign>
, NONTERMINAL (24) // <select_goil_5F_syntax_10>
, END_PRODUCTION
// At index 106 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (25) // <select_goil_5F_syntax_11>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 110 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 113 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 116 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 120 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
, END_PRODUCTION
// At index 121 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 124 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 127 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 131 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
, END_PRODUCTION
// At index 132 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 134 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 136 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 138 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 140 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 142 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 144 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 146 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 148 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 150 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 152 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 154 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 156 : <>, in file '.ggs', line 0
, NONTERMINAL (7) // <object_definition_list>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_goil_cpu_level_include [58] = {
 {"<start>", "goil_syntax", 0}, // at index 0
 {"<file>", "goil_syntax", 3}, // at index 1
 {"<sign>", "goil_syntax", 5}, // at index 2
 {"<description>", "goil_syntax", 7}, // at index 3
 {"<OIL_version>", "goil_syntax", 9}, // at index 4
 {"<application_definition>", "goil_syntax", 15}, // at index 5
 {"<object_definition_list>", "goil_syntax", 23}, // at index 6
 {"<boolean>", "goil_syntax", 25}, // at index 7
 {"<oil_declaration_list>", "goil_syntax", 27}, // at index 8
 {"<oil_declaration>", "goil_syntax", 29}, // at index 9
 {"<include_file_level>", "goil_syntax", 33}, // at index 10
 {"<include_cpu_level>", "goil_syntax", 36}, // at index 11
 {"<include_object_level>", "goil_syntax", 39}, // at index 12
 {"<select_goil_5F_syntax_0>", "goil_syntax", 42}, // at index 13
 {"<select_goil_5F_syntax_0>", "goil_syntax", 43}, // at index 14
 {"<select_goil_5F_syntax_0>", "goil_syntax", 46}, // at index 15
 {"<select_goil_5F_syntax_0>", "goil_syntax", 49}, // at index 16
 {"<select_goil_5F_syntax_1>", "goil_syntax", 52}, // at index 17
 {"<select_goil_5F_syntax_1>", "goil_syntax", 54}, // at index 18
 {"<select_goil_5F_syntax_1>", "goil_syntax", 56}, // at index 19
 {"<select_goil_5F_syntax_2>", "goil_syntax", 57}, // at index 20
 {"<select_goil_5F_syntax_2>", "goil_syntax", 58}, // at index 21
 {"<select_goil_5F_syntax_3>", "goil_syntax", 62}, // at index 22
 {"<select_goil_5F_syntax_3>", "goil_syntax", 63}, // at index 23
 {"<select_goil_5F_syntax_4>", "goil_syntax", 66}, // at index 24
 {"<select_goil_5F_syntax_4>", "goil_syntax", 67}, // at index 25
 {"<select_goil_5F_syntax_4>", "goil_syntax", 76}, // at index 26
 {"<select_goil_5F_syntax_5>", "goil_syntax", 79}, // at index 27
 {"<select_goil_5F_syntax_5>", "goil_syntax", 81}, // at index 28
 {"<select_goil_5F_syntax_6>", "goil_syntax", 83}, // at index 29
 {"<select_goil_5F_syntax_6>", "goil_syntax", 84}, // at index 30
 {"<select_goil_5F_syntax_6>", "goil_syntax", 87}, // at index 31
 {"<select_goil_5F_syntax_7>", "goil_syntax", 90}, // at index 32
 {"<select_goil_5F_syntax_7>", "goil_syntax", 93}, // at index 33
 {"<select_goil_5F_syntax_8>", "goil_syntax", 99}, // at index 34
 {"<select_goil_5F_syntax_8>", "goil_syntax", 103}, // at index 35
 {"<select_goil_5F_syntax_8>", "goil_syntax", 106}, // at index 36
 {"<select_goil_5F_syntax_8>", "goil_syntax", 110}, // at index 37
 {"<select_goil_5F_syntax_8>", "goil_syntax", 113}, // at index 38
 {"<select_goil_5F_syntax_9>", "goil_syntax", 116}, // at index 39
 {"<select_goil_5F_syntax_9>", "goil_syntax", 120}, // at index 40
 {"<select_goil_5F_syntax_10>", "goil_syntax", 121}, // at index 41
 {"<select_goil_5F_syntax_10>", "goil_syntax", 124}, // at index 42
 {"<select_goil_5F_syntax_11>", "goil_syntax", 127}, // at index 43
 {"<select_goil_5F_syntax_11>", "goil_syntax", 131}, // at index 44
 {"<select_goil_5F_syntax_12>", "goil_syntax", 132}, // at index 45
 {"<select_goil_5F_syntax_12>", "goil_syntax", 134}, // at index 46
 {"<select_goil_5F_syntax_13>", "goil_syntax", 136}, // at index 47
 {"<select_goil_5F_syntax_13>", "goil_syntax", 138}, // at index 48
 {"<select_goil_5F_syntax_14>", "goil_syntax", 140}, // at index 49
 {"<select_goil_5F_syntax_14>", "goil_syntax", 142}, // at index 50
 {"<select_goil_5F_syntax_15>", "goil_syntax", 144}, // at index 51
 {"<select_goil_5F_syntax_15>", "goil_syntax", 146}, // at index 52
 {"<select_goil_5F_syntax_16>", "goil_syntax", 148}, // at index 53
 {"<select_goil_5F_syntax_16>", "goil_syntax", 150}, // at index 54
 {"<select_goil_5F_syntax_17>", "goil_syntax", 152}, // at index 55
 {"<select_goil_5F_syntax_17>", "goil_syntax", 154}, // at index 56
 {"<>", "", 156} // at index 57
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_goil_cpu_level_include [58] = {
0, // index 0 : <start>, in file 'goil_syntax.ggs', line 38
3, // index 1 : <file>, in file 'goil_syntax.ggs', line 110
5, // index 2 : <sign>, in file 'goil_syntax.ggs', line 126
7, // index 3 : <description>, in file 'goil_syntax.ggs', line 139
9, // index 4 : <OIL_version>, in file 'goil_syntax.ggs', line 163
15, // index 5 : <application_definition>, in file 'goil_syntax.ggs', line 170
23, // index 6 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
25, // index 7 : <boolean>, in file 'goil_syntax.ggs', line 230
27, // index 8 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
29, // index 9 : <oil_declaration>, in file 'goil_syntax.ggs', line 252
33, // index 10 : <include_file_level>, in file 'goil_syntax.ggs', line 425
36, // index 11 : <include_cpu_level>, in file 'goil_syntax.ggs', line 449
39, // index 12 : <include_object_level>, in file 'goil_syntax.ggs', line 473
42, // index 13 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
43, // index 14 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
46, // index 15 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
49, // index 16 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
52, // index 17 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
54, // index 18 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
56, // index 19 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
57, // index 20 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
58, // index 21 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
62, // index 22 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
63, // index 23 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
66, // index 24 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
67, // index 25 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
76, // index 26 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
79, // index 27 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
81, // index 28 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
83, // index 29 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
84, // index 30 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
87, // index 31 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
90, // index 32 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
93, // index 33 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
99, // index 34 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
103, // index 35 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
106, // index 36 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
110, // index 37 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
113, // index 38 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
116, // index 39 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
120, // index 40 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
121, // index 41 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
124, // index 42 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
127, // index 43 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
131, // index 44 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
132, // index 45 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
134, // index 46 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
136, // index 47 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
138, // index 48 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
140, // index 49 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
142, // index 50 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
144, // index 51 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
146, // index 52 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
148, // index 53 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
150, // index 54 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
152, // index 55 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
154, // index 56 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
156 // index 57 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_goil_cpu_level_include [34] = {
0, // at 0 : <implementation_definition>
0, // at 1 : <start>
1, // at 2 : <file>
2, // at 3 : <sign>
3, // at 4 : <description>
4, // at 5 : <OIL_version>
5, // at 6 : <application_definition>
6, // at 7 : <object_definition_list>
7, // at 8 : <boolean>
8, // at 9 : <oil_declaration_list>
9, // at 10 : <oil_declaration>
10, // at 11 : <include_file_level>
11, // at 12 : <include_cpu_level>
12, // at 13 : <include_object_level>
13, // at 14 : <select_goil_5F_syntax_0>
17, // at 15 : <select_goil_5F_syntax_1>
20, // at 16 : <select_goil_5F_syntax_2>
22, // at 17 : <select_goil_5F_syntax_3>
24, // at 18 : <select_goil_5F_syntax_4>
27, // at 19 : <select_goil_5F_syntax_5>
29, // at 20 : <select_goil_5F_syntax_6>
32, // at 21 : <select_goil_5F_syntax_7>
34, // at 22 : <select_goil_5F_syntax_8>
39, // at 23 : <select_goil_5F_syntax_9>
41, // at 24 : <select_goil_5F_syntax_10>
43, // at 25 : <select_goil_5F_syntax_11>
45, // at 26 : <select_goil_5F_syntax_12>
47, // at 27 : <select_goil_5F_syntax_13>
49, // at 28 : <select_goil_5F_syntax_14>
51, // at 29 : <select_goil_5F_syntax_15>
53, // at 30 : <select_goil_5F_syntax_16>
55, // at 31 : <select_goil_5F_syntax_17>
57, // at 32 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_goil_cpu_level_include [] = {
// At index 0 : <implementation_definition> no production
// At index 0 : <start> only one production, no choice
  -1,
// At index 1 : <file> only one production, no choice
  -1,
// At index 2 : <sign> only one production, no choice
  -1,
// At index 3 : <description> only one production, no choice
  -1,
// At index 4 : <OIL_version> only one production, no choice
  -1,
// At index 5 : <application_definition> only one production, no choice
  -1,
// At index 6 : <object_definition_list> only one production, no choice
  -1,
// At index 7 : <boolean> only one production, no choice
  -1,
// At index 8 : <oil_declaration_list> only one production, no choice
  -1,
// At index 9 : <oil_declaration> only one production, no choice
  -1,
// At index 10 : <include_file_level> only one production, no choice
  -1,
// At index 11 : <include_cpu_level> only one production, no choice
  -1,
// At index 12 : <include_object_level> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 13 : <select_goil_5F_syntax_0>
-1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
-1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 21 : <select_goil_5F_syntax_1>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 3
  -1,
// At index 29 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 34 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 39 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__7D_, C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 48 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 53 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 61 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 66 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 81 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 87 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 92 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 98 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 103 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 108 : <select_goil_5F_syntax_14>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 113 : <select_goil_5F_syntax_15>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 118 : <select_goil_5F_syntax_16>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 123 : <select_goil_5F_syntax_17>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 128 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_goil_cpu_level_include [34] = {
0, // at 0 : <implementation_definition>
0, // at 1 : <start>
1, // at 2 : <file>
2, // at 3 : <sign>
3, // at 4 : <description>
4, // at 5 : <OIL_version>
5, // at 6 : <application_definition>
6, // at 7 : <object_definition_list>
7, // at 8 : <boolean>
8, // at 9 : <oil_declaration_list>
9, // at 10 : <oil_declaration>
10, // at 11 : <include_file_level>
11, // at 12 : <include_cpu_level>
12, // at 13 : <include_object_level>
13, // at 14 : <select_goil_5F_syntax_0>
21, // at 15 : <select_goil_5F_syntax_1>
29, // at 16 : <select_goil_5F_syntax_2>
34, // at 17 : <select_goil_5F_syntax_3>
39, // at 18 : <select_goil_5F_syntax_4>
48, // at 19 : <select_goil_5F_syntax_5>
53, // at 20 : <select_goil_5F_syntax_6>
61, // at 21 : <select_goil_5F_syntax_7>
66, // at 22 : <select_goil_5F_syntax_8>
81, // at 23 : <select_goil_5F_syntax_9>
87, // at 24 : <select_goil_5F_syntax_10>
92, // at 25 : <select_goil_5F_syntax_11>
98, // at 26 : <select_goil_5F_syntax_12>
103, // at 27 : <select_goil_5F_syntax_13>
108, // at 28 : <select_goil_5F_syntax_14>
113, // at 29 : <select_goil_5F_syntax_15>
118, // at 30 : <select_goil_5F_syntax_16>
123, // at 31 : <select_goil_5F_syntax_17>
128, // at 32 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_definition' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * ) {
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

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_file_ (GALGAS_implementation & parameter_1,
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

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'description' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'OIL_version' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'application_definition' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_application_5F_definition_ (const GALGAS_implementation parameter_1,
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

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_object_5F_definition_5F_list_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performTopDownParsing (gProductions_goil_cpu_level_include, gProductionNames_goil_cpu_level_include, gProductionIndexes_goil_cpu_level_include,
                                    gFirstProductionIndexes_goil_cpu_level_include, gDecision_goil_cpu_level_include, gDecisionIndexes_goil_cpu_level_include, 156) ;
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
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", filePath COMMA_HERE)) ;
    if (scanner->sourceText () != NULL) {
      const bool ok = scanner->performTopDownParsing (gProductions_goil_cpu_level_include, gProductionNames_goil_cpu_level_include, gProductionIndexes_goil_cpu_level_include,
                                                      gFirstProductionIndexes_goil_cpu_level_include, gDecision_goil_cpu_level_include, gDecisionIndexes_goil_cpu_level_include, 156) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_cpu_5F_level_5F_include grammar ;
        grammar.nt_object_5F_definition_5F_list_ (parameter_1, parameter_2, parameter_3, parameter_4, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
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
                                                    gFirstProductionIndexes_goil_cpu_level_include, gDecision_goil_cpu_level_include, gDecisionIndexes_goil_cpu_level_include, 156) ;
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
  rule_goil_5F_syntax_boolean_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'oil_declaration_list' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'oil_declaration' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_file_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_file_5F_level_ (GALGAS_implementation & parameter_1,
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

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_cpu_5F_level_ (const GALGAS_implementation parameter_1,
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

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_(parameter_1, parameter_2, inLexique) ;
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



//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_parser_5F_start_i0_ (GALGAS_gtlData & outArgument_options,
                                                                                      C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_options.drop () ; // Release 'out' argument
  outArgument_options = GALGAS_gtlStruct::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("options_parser.galgas", 32)), function_lstring (GALGAS_string ("Passed options"), inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 32)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("options_parser.galgas", 32))  COMMA_SOURCE_FILE ("options_parser.galgas", 32)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_option_5F_item_ (outArgument_options, inCompiler) ;
    switch (select_options_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("options_parser.galgas", 35)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_parser_5F_start_i0_parse (C_Lexique_options_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_option_5F_item_parse (inCompiler) ;
    switch (select_options_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("options_parser.galgas", 35)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_item_i1_ (GALGAS_gtlData & ioArgument_options,
                                                                           C_Lexique_options_5F_scanner * inCompiler) {
  GALGAS_lstring var_key_987 = inCompiler->synthetizedAttribute_key () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_idf) COMMA_SOURCE_FILE ("options_parser.galgas", 42)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("options_parser.galgas", 43)) ;
  GALGAS_gtlData var_opt_1008 ;
  switch (select_options_5F_parser_1 (inCompiler)) {
  case 1: {
    nt_option_5F_value_ (var_opt_1008, inCompiler) ;
  } break ;
  case 2: {
    nt_list_5F_option_5F_value_ (var_opt_1008, inCompiler) ;
  } break ;
  default:
    break ;
  }
  {
  ioArgument_options.insulate (HERE) ;
  cPtr_gtlData * ptr_1094 = (cPtr_gtlData *) ioArgument_options.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1094, var_key_987, var_opt_1008, inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 50)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_item_i1_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_idf) COMMA_SOURCE_FILE ("options_parser.galgas", 42)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("options_parser.galgas", 43)) ;
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

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i2_ (GALGAS_gtlData & outArgument_opt,
                                                                            C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  GALGAS_lstring var_str_1191 = inCompiler->synthetizedAttribute_string () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("options_parser.galgas", 56)) ;
  outArgument_opt = GALGAS_gtlString::constructor_new (var_str_1191.getter_location (SOURCE_FILE ("options_parser.galgas", 57)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 57)), var_str_1191.getter_string (SOURCE_FILE ("options_parser.galgas", 57))  COMMA_SOURCE_FILE ("options_parser.galgas", 57)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i2_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("options_parser.galgas", 56)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i3_ (GALGAS_gtlData & outArgument_opt,
                                                                            C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  GALGAS_lstring var_str_1311 = inCompiler->synthetizedAttribute_key () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_idf) COMMA_SOURCE_FILE ("options_parser.galgas", 63)) ;
  outArgument_opt = GALGAS_gtlString::constructor_new (var_str_1311.getter_location (SOURCE_FILE ("options_parser.galgas", 64)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 64)), var_str_1311.getter_string (SOURCE_FILE ("options_parser.galgas", 64))  COMMA_SOURCE_FILE ("options_parser.galgas", 64)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i3_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_idf) COMMA_SOURCE_FILE ("options_parser.galgas", 63)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i4_ (GALGAS_gtlData & outArgument_opt,
                                                                            C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  GALGAS_luint_36__34_ var_num_1439 = inCompiler->synthetizedAttribute_integerNumber () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_uint_5F_number) COMMA_SOURCE_FILE ("options_parser.galgas", 70)) ;
  outArgument_opt = GALGAS_gtlInt::constructor_new (var_num_1439.getter_location (SOURCE_FILE ("options_parser.galgas", 71)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 71)), var_num_1439.mAttribute_uint_36__34_.getter_bigint (SOURCE_FILE ("options_parser.galgas", 71))  COMMA_SOURCE_FILE ("options_parser.galgas", 71)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i4_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_uint_5F_number) COMMA_SOURCE_FILE ("options_parser.galgas", 70)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i5_ (GALGAS_gtlData & outArgument_opt,
                                                                            C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  GALGAS_ldouble var_num_1574 = inCompiler->synthetizedAttribute_floatNumber () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_float_5F_number) COMMA_SOURCE_FILE ("options_parser.galgas", 77)) ;
  outArgument_opt = GALGAS_gtlFloat::constructor_new (var_num_1574.getter_location (SOURCE_FILE ("options_parser.galgas", 78)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 78)), var_num_1574.getter_double (SOURCE_FILE ("options_parser.galgas", 78))  COMMA_SOURCE_FILE ("options_parser.galgas", 78)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i5_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_float_5F_number) COMMA_SOURCE_FILE ("options_parser.galgas", 77)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i6_ (GALGAS_gtlData & outArgument_opt,
                                                                            C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__2D_) COMMA_SOURCE_FILE ("options_parser.galgas", 84)) ;
  switch (select_options_5F_parser_2 (inCompiler)) {
  case 1: {
    GALGAS_luint_36__34_ var_num_1718 = inCompiler->synthetizedAttribute_integerNumber () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_uint_5F_number) COMMA_SOURCE_FILE ("options_parser.galgas", 86)) ;
    outArgument_opt = GALGAS_gtlInt::constructor_new (var_num_1718.getter_location (SOURCE_FILE ("options_parser.galgas", 87)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 87)), var_num_1718.mAttribute_uint_36__34_.getter_bigint (SOURCE_FILE ("options_parser.galgas", 87)).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 87))  COMMA_SOURCE_FILE ("options_parser.galgas", 87)) ;
  } break ;
  case 2: {
    GALGAS_ldouble var_num_1822 = inCompiler->synthetizedAttribute_floatNumber () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_float_5F_number) COMMA_SOURCE_FILE ("options_parser.galgas", 89)) ;
    outArgument_opt = GALGAS_gtlFloat::constructor_new (var_num_1822.getter_location (SOURCE_FILE ("options_parser.galgas", 90)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 90)), var_num_1822.getter_double (SOURCE_FILE ("options_parser.galgas", 90)).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 90))  COMMA_SOURCE_FILE ("options_parser.galgas", 90)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i6_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__2D_) COMMA_SOURCE_FILE ("options_parser.galgas", 84)) ;
  switch (select_options_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_uint_5F_number) COMMA_SOURCE_FILE ("options_parser.galgas", 86)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_float_5F_number) COMMA_SOURCE_FILE ("options_parser.galgas", 89)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_list_5F_option_5F_value_i7_ (GALGAS_gtlData & outArgument_opt,
                                                                                    C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  GALGAS_list var_listOption_1957 = GALGAS_list::constructor_emptyList (SOURCE_FILE ("options_parser.galgas", 97)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("options_parser.galgas", 98)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_gtlData var_item_2023 ;
    nt_option_5F_value_ (var_item_2023, inCompiler) ;
    var_listOption_1957.addAssign_operation (var_item_2023  COMMA_SOURCE_FILE ("options_parser.galgas", 101)) ;
    switch (select_options_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("options_parser.galgas", 102)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  outArgument_opt = GALGAS_gtlList::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("options_parser.galgas", 104)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 104)), var_listOption_1957  COMMA_SOURCE_FILE ("options_parser.galgas", 104)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("options_parser.galgas", 105)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_list_5F_option_5F_value_i7_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("options_parser.galgas", 98)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_option_5F_value_parse (inCompiler) ;
    switch (select_options_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("options_parser.galgas", 102)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("options_parser.galgas", 105)) ;
  inCompiler->resetTemplateString () ;
}

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

GALGAS_gtlInstructionListContextStack_2D_element::GALGAS_gtlInstructionListContextStack_2D_element (void) :
mAttribute_nextInstructionIndex (),
mAttribute_instructionList () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack_2D_element::~ GALGAS_gtlInstructionListContextStack_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack_2D_element::GALGAS_gtlInstructionListContextStack_2D_element (const GALGAS_uint & inOperand0,
                                                                                                    const GALGAS_gtlInstructionList & inOperand1) :
mAttribute_nextInstructionIndex (inOperand0),
mAttribute_instructionList (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack_2D_element GALGAS_gtlInstructionListContextStack_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlInstructionListContextStack_2D_element (GALGAS_uint::constructor_default (HERE),
                                                           GALGAS_gtlInstructionList::constructor_emptyList (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack_2D_element GALGAS_gtlInstructionListContextStack_2D_element::constructor_new (const GALGAS_uint & inOperand0,
                                                                                                                    const GALGAS_gtlInstructionList & inOperand1 
                                                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlInstructionListContextStack_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlInstructionListContextStack_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_gtlInstructionListContextStack_2D_element::objectCompare (const GALGAS_gtlInstructionListContextStack_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_nextInstructionIndex.objectCompare (inOperand.mAttribute_nextInstructionIndex) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_instructionList.objectCompare (inOperand.mAttribute_instructionList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_gtlInstructionListContextStack_2D_element::isValid (void) const {
  return mAttribute_nextInstructionIndex.isValid () && mAttribute_instructionList.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionListContextStack_2D_element::drop (void) {
  mAttribute_nextInstructionIndex.drop () ;
  mAttribute_instructionList.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionListContextStack_2D_element::description (C_String & ioString,
                                                                    const int32_t inIndentation) const {
  ioString << "<struct @gtlInstructionListContextStack-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_nextInstructionIndex.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_instructionList.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_gtlInstructionListContextStack_2D_element::getter_nextInstructionIndex (UNUSED_LOCATION_ARGS) const {
  return mAttribute_nextInstructionIndex ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlInstructionListContextStack_2D_element::getter_instructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_instructionList ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    @gtlInstructionListContextStack-element type                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlInstructionListContextStack_2D_element ("gtlInstructionListContextStack-element",
                                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlInstructionListContextStack_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInstructionListContextStack_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlInstructionListContextStack_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlInstructionListContextStack_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack_2D_element GALGAS_gtlInstructionListContextStack_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                                  C_Compiler * inCompiler
                                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlInstructionListContextStack_2D_element result ;
  const GALGAS_gtlInstructionListContextStack_2D_element * p = (const GALGAS_gtlInstructionListContextStack_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlInstructionListContextStack_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlInstructionListContextStack-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList_2D_element::GALGAS_gtlBreakpointList_2D_element (void) :
mAttribute_breakpoint () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList_2D_element::~ GALGAS_gtlBreakpointList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList_2D_element::GALGAS_gtlBreakpointList_2D_element (const GALGAS_gtlBreakpoint & inOperand0) :
mAttribute_breakpoint (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList_2D_element GALGAS_gtlBreakpointList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlBreakpointList_2D_element (GALGAS_gtlBreakpoint::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList_2D_element GALGAS_gtlBreakpointList_2D_element::constructor_new (const GALGAS_gtlBreakpoint & inOperand0 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlBreakpointList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_gtlBreakpointList_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_gtlBreakpointList_2D_element::objectCompare (const GALGAS_gtlBreakpointList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_breakpoint.objectCompare (inOperand.mAttribute_breakpoint) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_gtlBreakpointList_2D_element::isValid (void) const {
  return mAttribute_breakpoint.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlBreakpointList_2D_element::drop (void) {
  mAttribute_breakpoint.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlBreakpointList_2D_element::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "<struct @gtlBreakpointList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_breakpoint.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpoint GALGAS_gtlBreakpointList_2D_element::getter_breakpoint (UNUSED_LOCATION_ARGS) const {
  return mAttribute_breakpoint ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlBreakpointList-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlBreakpointList_2D_element ("gtlBreakpointList-element",
                                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlBreakpointList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlBreakpointList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlBreakpointList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList_2D_element GALGAS_gtlBreakpointList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointList_2D_element result ;
  const GALGAS_gtlBreakpointList_2D_element * p = (const GALGAS_gtlBreakpointList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlBreakpointList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlBreakpointList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
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
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_debuggerContext::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_debuggerContext) ;
  if (kOperandEqual == result) {
    result = mAttribute_debugActive.objectCompare (p->mAttribute_debugActive) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_breakOnNext.objectCompare (p->mAttribute_breakOnNext) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_loopOnCommand.objectCompare (p->mAttribute_loopOnCommand) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_promptColor.objectCompare (p->mAttribute_promptColor) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_promptFace.objectCompare (p->mAttribute_promptFace) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_instructionColor.objectCompare (p->mAttribute_instructionColor) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_instructionFace.objectCompare (p->mAttribute_instructionFace) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_outputColor.objectCompare (p->mAttribute_outputColor) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_outputFace.objectCompare (p->mAttribute_outputFace) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_warningColor.objectCompare (p->mAttribute_warningColor) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_warningFace.objectCompare (p->mAttribute_warningFace) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_executeDebuggerCommand.objectCompare (p->mAttribute_executeDebuggerCommand) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_doList.objectCompare (p->mAttribute_doList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_breakpoints.objectCompare (p->mAttribute_breakpoints) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_watchpoints.objectCompare (p->mAttribute_watchpoints) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_nextInstructionIndex.objectCompare (p->mAttribute_nextInstructionIndex) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_instructionList.objectCompare (p->mAttribute_instructionList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_contextStack.objectCompare (p->mAttribute_contextStack) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_commandInput.objectCompare (p->mAttribute_commandInput) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_debuggerContext::objectCompare (const GALGAS_debuggerContext & inOperand) const {
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

GALGAS_debuggerContext::GALGAS_debuggerContext (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debuggerContext GALGAS_debuggerContext::constructor_default (LOCATION_ARGS) {
  return GALGAS_debuggerContext::constructor_new (GALGAS_bool::constructor_default (HERE),
                                                  GALGAS_bool::constructor_default (HERE),
                                                  GALGAS_bool::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_bool::constructor_default (HERE),
                                                  GALGAS_gtlInstructionList::constructor_emptyList (HERE),
                                                  GALGAS_gtlBreakpointList::constructor_emptyList (HERE),
                                                  GALGAS_gtlExpressionList::constructor_emptyList (HERE),
                                                  GALGAS_uint::constructor_default (HERE),
                                                  GALGAS_gtlInstructionList::constructor_emptyList (HERE),
                                                  GALGAS_gtlInstructionListContextStack::constructor_emptyList (HERE),
                                                  GALGAS_debugCommandInput::constructor_default (HERE)
                                                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debuggerContext::GALGAS_debuggerContext (const cPtr_debuggerContext * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_debuggerContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debuggerContext GALGAS_debuggerContext::constructor_new (const GALGAS_bool & inAttribute_debugActive,
                                                                const GALGAS_bool & inAttribute_breakOnNext,
                                                                const GALGAS_bool & inAttribute_loopOnCommand,
                                                                const GALGAS_string & inAttribute_promptColor,
                                                                const GALGAS_string & inAttribute_promptFace,
                                                                const GALGAS_string & inAttribute_instructionColor,
                                                                const GALGAS_string & inAttribute_instructionFace,
                                                                const GALGAS_string & inAttribute_outputColor,
                                                                const GALGAS_string & inAttribute_outputFace,
                                                                const GALGAS_string & inAttribute_warningColor,
                                                                const GALGAS_string & inAttribute_warningFace,
                                                                const GALGAS_bool & inAttribute_executeDebuggerCommand,
                                                                const GALGAS_gtlInstructionList & inAttribute_doList,
                                                                const GALGAS_gtlBreakpointList & inAttribute_breakpoints,
                                                                const GALGAS_gtlExpressionList & inAttribute_watchpoints,
                                                                const GALGAS_uint & inAttribute_nextInstructionIndex,
                                                                const GALGAS_gtlInstructionList & inAttribute_instructionList,
                                                                const GALGAS_gtlInstructionListContextStack & inAttribute_contextStack,
                                                                const GALGAS_debugCommandInput & inAttribute_commandInput
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_debuggerContext result ;
  if (inAttribute_debugActive.isValid () && inAttribute_breakOnNext.isValid () && inAttribute_loopOnCommand.isValid () && inAttribute_promptColor.isValid () && inAttribute_promptFace.isValid () && inAttribute_instructionColor.isValid () && inAttribute_instructionFace.isValid () && inAttribute_outputColor.isValid () && inAttribute_outputFace.isValid () && inAttribute_warningColor.isValid () && inAttribute_warningFace.isValid () && inAttribute_executeDebuggerCommand.isValid () && inAttribute_doList.isValid () && inAttribute_breakpoints.isValid () && inAttribute_watchpoints.isValid () && inAttribute_nextInstructionIndex.isValid () && inAttribute_instructionList.isValid () && inAttribute_contextStack.isValid () && inAttribute_commandInput.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_debuggerContext (inAttribute_debugActive, inAttribute_breakOnNext, inAttribute_loopOnCommand, inAttribute_promptColor, inAttribute_promptFace, inAttribute_instructionColor, inAttribute_instructionFace, inAttribute_outputColor, inAttribute_outputFace, inAttribute_warningColor, inAttribute_warningFace, inAttribute_executeDebuggerCommand, inAttribute_doList, inAttribute_breakpoints, inAttribute_watchpoints, inAttribute_nextInstructionIndex, inAttribute_instructionList, inAttribute_contextStack, inAttribute_commandInput COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_debuggerContext::getter_debugActive (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_debugActive ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_debuggerContext::getter_debugActive (UNUSED_LOCATION_ARGS) const {
  return mAttribute_debugActive ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_debuggerContext::getter_breakOnNext (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_breakOnNext ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_debuggerContext::getter_breakOnNext (UNUSED_LOCATION_ARGS) const {
  return mAttribute_breakOnNext ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_debuggerContext::getter_loopOnCommand (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_loopOnCommand ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_debuggerContext::getter_loopOnCommand (UNUSED_LOCATION_ARGS) const {
  return mAttribute_loopOnCommand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_debuggerContext::getter_promptColor (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_promptColor ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_debuggerContext::getter_promptColor (UNUSED_LOCATION_ARGS) const {
  return mAttribute_promptColor ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_debuggerContext::getter_promptFace (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_promptFace ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_debuggerContext::getter_promptFace (UNUSED_LOCATION_ARGS) const {
  return mAttribute_promptFace ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_debuggerContext::getter_instructionColor (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_instructionColor ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_debuggerContext::getter_instructionColor (UNUSED_LOCATION_ARGS) const {
  return mAttribute_instructionColor ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_debuggerContext::getter_instructionFace (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_instructionFace ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_debuggerContext::getter_instructionFace (UNUSED_LOCATION_ARGS) const {
  return mAttribute_instructionFace ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_debuggerContext::getter_outputColor (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_outputColor ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_debuggerContext::getter_outputColor (UNUSED_LOCATION_ARGS) const {
  return mAttribute_outputColor ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_debuggerContext::getter_outputFace (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_outputFace ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_debuggerContext::getter_outputFace (UNUSED_LOCATION_ARGS) const {
  return mAttribute_outputFace ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_debuggerContext::getter_warningColor (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_warningColor ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_debuggerContext::getter_warningColor (UNUSED_LOCATION_ARGS) const {
  return mAttribute_warningColor ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_debuggerContext::getter_warningFace (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_warningFace ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_debuggerContext::getter_warningFace (UNUSED_LOCATION_ARGS) const {
  return mAttribute_warningFace ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_debuggerContext::getter_executeDebuggerCommand (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_executeDebuggerCommand ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_debuggerContext::getter_executeDebuggerCommand (UNUSED_LOCATION_ARGS) const {
  return mAttribute_executeDebuggerCommand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_debuggerContext::getter_doList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_doList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_debuggerContext::getter_doList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_doList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList GALGAS_debuggerContext::getter_breakpoints (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlBreakpointList result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_breakpoints ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList cPtr_debuggerContext::getter_breakpoints (UNUSED_LOCATION_ARGS) const {
  return mAttribute_breakpoints ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_debuggerContext::getter_watchpoints (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_watchpoints ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList cPtr_debuggerContext::getter_watchpoints (UNUSED_LOCATION_ARGS) const {
  return mAttribute_watchpoints ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_debuggerContext::getter_nextInstructionIndex (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_nextInstructionIndex ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cPtr_debuggerContext::getter_nextInstructionIndex (UNUSED_LOCATION_ARGS) const {
  return mAttribute_nextInstructionIndex ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_debuggerContext::getter_instructionList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_instructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_debuggerContext::getter_instructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_instructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack GALGAS_debuggerContext::getter_contextStack (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionListContextStack result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_contextStack ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack cPtr_debuggerContext::getter_contextStack (UNUSED_LOCATION_ARGS) const {
  return mAttribute_contextStack ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debugCommandInput GALGAS_debuggerContext::getter_commandInput (UNUSED_LOCATION_ARGS) const {
  GALGAS_debugCommandInput result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_commandInput ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debugCommandInput cPtr_debuggerContext::getter_commandInput (UNUSED_LOCATION_ARGS) const {
  return mAttribute_commandInput ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setDebugActive (GALGAS_bool inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_debugActive = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setDebugActive (GALGAS_bool inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_debugActive = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setBreakOnNext (GALGAS_bool inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_breakOnNext = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setBreakOnNext (GALGAS_bool inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_breakOnNext = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setLoopOnCommand (GALGAS_bool inValue
                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_loopOnCommand = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setLoopOnCommand (GALGAS_bool inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_loopOnCommand = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setPromptColor (GALGAS_string inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_promptColor = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setPromptColor (GALGAS_string inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_promptColor = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setPromptFace (GALGAS_string inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_promptFace = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setPromptFace (GALGAS_string inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_promptFace = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setInstructionColor (GALGAS_string inValue
                                                         COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_instructionColor = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setInstructionColor (GALGAS_string inValue
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_instructionColor = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setInstructionFace (GALGAS_string inValue
                                                        COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_instructionFace = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setInstructionFace (GALGAS_string inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_instructionFace = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setOutputColor (GALGAS_string inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_outputColor = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setOutputColor (GALGAS_string inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_outputColor = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setOutputFace (GALGAS_string inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_outputFace = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setOutputFace (GALGAS_string inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_outputFace = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setWarningColor (GALGAS_string inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_warningColor = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setWarningColor (GALGAS_string inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_warningColor = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setWarningFace (GALGAS_string inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_warningFace = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setWarningFace (GALGAS_string inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_warningFace = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setExecuteDebuggerCommand (GALGAS_bool inValue
                                                               COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_executeDebuggerCommand = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setExecuteDebuggerCommand (GALGAS_bool inValue
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_executeDebuggerCommand = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setNextInstructionIndex (GALGAS_uint inValue
                                                             COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_nextInstructionIndex = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setNextInstructionIndex (GALGAS_uint inValue
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_nextInstructionIndex = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @debuggerContext class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_debuggerContext::cPtr_debuggerContext (const GALGAS_bool & in_debugActive,
                                            const GALGAS_bool & in_breakOnNext,
                                            const GALGAS_bool & in_loopOnCommand,
                                            const GALGAS_string & in_promptColor,
                                            const GALGAS_string & in_promptFace,
                                            const GALGAS_string & in_instructionColor,
                                            const GALGAS_string & in_instructionFace,
                                            const GALGAS_string & in_outputColor,
                                            const GALGAS_string & in_outputFace,
                                            const GALGAS_string & in_warningColor,
                                            const GALGAS_string & in_warningFace,
                                            const GALGAS_bool & in_executeDebuggerCommand,
                                            const GALGAS_gtlInstructionList & in_doList,
                                            const GALGAS_gtlBreakpointList & in_breakpoints,
                                            const GALGAS_gtlExpressionList & in_watchpoints,
                                            const GALGAS_uint & in_nextInstructionIndex,
                                            const GALGAS_gtlInstructionList & in_instructionList,
                                            const GALGAS_gtlInstructionListContextStack & in_contextStack,
                                            const GALGAS_debugCommandInput & in_commandInput
                                            COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_debugActive (in_debugActive),
mAttribute_breakOnNext (in_breakOnNext),
mAttribute_loopOnCommand (in_loopOnCommand),
mAttribute_promptColor (in_promptColor),
mAttribute_promptFace (in_promptFace),
mAttribute_instructionColor (in_instructionColor),
mAttribute_instructionFace (in_instructionFace),
mAttribute_outputColor (in_outputColor),
mAttribute_outputFace (in_outputFace),
mAttribute_warningColor (in_warningColor),
mAttribute_warningFace (in_warningFace),
mAttribute_executeDebuggerCommand (in_executeDebuggerCommand),
mAttribute_doList (in_doList),
mAttribute_breakpoints (in_breakpoints),
mAttribute_watchpoints (in_watchpoints),
mAttribute_nextInstructionIndex (in_nextInstructionIndex),
mAttribute_instructionList (in_instructionList),
mAttribute_contextStack (in_contextStack),
mAttribute_commandInput (in_commandInput) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_debuggerContext::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_debuggerContext ;
}

void cPtr_debuggerContext::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@debuggerContext:" ;
  mAttribute_debugActive.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_breakOnNext.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_loopOnCommand.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_promptColor.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_promptFace.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_instructionColor.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_instructionFace.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_outputColor.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_outputFace.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_warningColor.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_warningFace.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_executeDebuggerCommand.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_doList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_breakpoints.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_watchpoints.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_nextInstructionIndex.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_instructionList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_contextStack.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_commandInput.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_debuggerContext::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_debuggerContext (mAttribute_debugActive, mAttribute_breakOnNext, mAttribute_loopOnCommand, mAttribute_promptColor, mAttribute_promptFace, mAttribute_instructionColor, mAttribute_instructionFace, mAttribute_outputColor, mAttribute_outputFace, mAttribute_warningColor, mAttribute_warningFace, mAttribute_executeDebuggerCommand, mAttribute_doList, mAttribute_breakpoints, mAttribute_watchpoints, mAttribute_nextInstructionIndex, mAttribute_instructionList, mAttribute_contextStack, mAttribute_commandInput COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @debuggerContext type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_debuggerContext ("debuggerContext",
                                        NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_debuggerContext::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_debuggerContext ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_debuggerContext::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_debuggerContext (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debuggerContext GALGAS_debuggerContext::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_debuggerContext result ;
  const GALGAS_debuggerContext * p = (const GALGAS_debuggerContext *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_debuggerContext *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("debuggerContext", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_gtlData::objectCompare (const GALGAS_gtlData & inOperand) const {
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

GALGAS_gtlData::GALGAS_gtlData (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData::GALGAS_gtlData (const cPtr_gtlData * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlData) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_gtlData::getter_where (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlData * p = (const cPtr_gtlData *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlData) ;
    result = p->mAttribute_where ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_gtlData::getter_where (UNUSED_LOCATION_ARGS) const {
  return mAttribute_where ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlData::getter_meta (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlData * p = (const cPtr_gtlData *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlData) ;
    result = p->mAttribute_meta ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlData::getter_meta (UNUSED_LOCATION_ARGS) const {
  return mAttribute_meta ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlData::setter_setWhere (GALGAS_location inValue
                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlData * p = (cPtr_gtlData *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlData) ;
    p->mAttribute_where = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlData::setter_setWhere (GALGAS_location inValue
                                    COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_where = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlData::setter_setMeta (GALGAS_lstring inValue
                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlData * p = (cPtr_gtlData *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlData) ;
    p->mAttribute_meta = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlData::setter_setMeta (GALGAS_lstring inValue
                                   COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_meta = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @gtlData class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlData::cPtr_gtlData (const GALGAS_location & in_where,
                            const GALGAS_lstring & in_meta
                            COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_where (in_where),
mAttribute_meta (in_meta) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @gtlData type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlData ("gtlData",
                                NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlData::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlData ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlData::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlData (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData GALGAS_gtlData::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  const GALGAS_gtlData * p = (const GALGAS_gtlData *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlData *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlData", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_gtlExpression::objectCompare (const GALGAS_gtlExpression & inOperand) const {
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

GALGAS_gtlExpression::GALGAS_gtlExpression (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression::GALGAS_gtlExpression (const cPtr_gtlExpression * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_gtlExpression::getter_where (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlExpression * p = (const cPtr_gtlExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlExpression) ;
    result = p->mAttribute_where ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_gtlExpression::getter_where (UNUSED_LOCATION_ARGS) const {
  return mAttribute_where ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @gtlExpression class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlExpression::cPtr_gtlExpression (const GALGAS_location & in_where
                                        COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_where (in_where) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @gtlExpression type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExpression ("gtlExpression",
                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlExpression::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpression result ;
  const GALGAS_gtlExpression * p = (const GALGAS_gtlExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
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
  extensionMethod_execute (object->mAttribute_program, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 225)) ;
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
  result_exists = object->mAttribute_funcMap.getter_hasKey (constinArgument_name.getter_string (SOURCE_FILE ("gtl_types.galgas", 286)) COMMA_SOURCE_FILE ("gtl_types.galgas", 286)) ;
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
  object->mAttribute_funcMap.method_get (constinArgument_name, result_aFunction, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 293)) ;
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
  object->mAttribute_funcMap.setter_put (constinArgument_name, constinArgument_aFunction, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 300)) ;
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
  result_exists = object->mAttribute_getterMap.getter_hasKey (constinArgument_type.add_operation (constinArgument_name.getter_string (SOURCE_FILE ("gtl_types.galgas", 308)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 308)) COMMA_SOURCE_FILE ("gtl_types.galgas", 308)) ;
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
  object->mAttribute_getterMap.method_get (GALGAS_lstring::constructor_new (constinArgument_type.add_operation (constinArgument_name.getter_string (SOURCE_FILE ("gtl_types.galgas", 316)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 316)), constinArgument_name.getter_location (SOURCE_FILE ("gtl_types.galgas", 316))  COMMA_SOURCE_FILE ("gtl_types.galgas", 316)), result_aGetter, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 316)) ;
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
  object->mAttribute_getterMap.setter_put (constinArgument_name, constinArgument_aGetter, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 323)) ;
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
  result_exists = object->mAttribute_setterMap.getter_hasKey (constinArgument_type.add_operation (constinArgument_name.getter_string (SOURCE_FILE ("gtl_types.galgas", 331)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 331)) COMMA_SOURCE_FILE ("gtl_types.galgas", 331)) ;
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
  object->mAttribute_setterMap.method_get (GALGAS_lstring::constructor_new (constinArgument_type.add_operation (constinArgument_name.getter_string (SOURCE_FILE ("gtl_types.galgas", 339)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 339)), constinArgument_name.getter_location (SOURCE_FILE ("gtl_types.galgas", 339))  COMMA_SOURCE_FILE ("gtl_types.galgas", 339)), result_aSetter, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 339)) ;
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
  object->mAttribute_setterMap.setter_put (constinArgument_name, constinArgument_aSetter, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 346)) ;
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
  result_result = object->mAttribute_doneImports.getter_hasKey (constinArgument_importPath COMMA_SOURCE_FILE ("gtl_types.galgas", 353)) ;
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
  object->mAttribute_doneImports.addAssign_operation (constinArgument_importPath  COMMA_SOURCE_FILE ("gtl_types.galgas", 359)) ;
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
  extensionSetter_getTemplate (object->mAttribute_templateMap, constinArgument_context, inArgument_path, inArgument_ifExists, ioArgument_lib, outArgument_found, outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 371)) ;
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


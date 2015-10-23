#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-1.h"


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

void GALGAS_enumValues::modifier_put (GALGAS_lstring inKey,
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

void GALGAS_enumValues::modifier_del (GALGAS_lstring inKey,
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

void GALGAS_enumValues::modifier_setSubAttributesForKey (GALGAS_implementationObjectMap inAttributeValue,
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

void GALGAS_implementationMap::modifier_put (GALGAS_lstring inKey,
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

void GALGAS_implementationMap::modifier_del (GALGAS_lstring inKey,
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

void GALGAS_implementationMap::modifier_setObjForKey (GALGAS_implementationObject inAttributeValue,
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

void GALGAS_identifierMap::modifier_put (GALGAS_lstring inKey,
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

void GALGAS_identifierMap::modifier_del (GALGAS_lstring inKey,
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

void GALGAS_identifierMap::modifier_setValueForKey (GALGAS_object_5F_t inAttributeValue,
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

void GALGAS_identifierList::modifier_insertAtIndex (const GALGAS_object_5F_t inOperand0,
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

void GALGAS_identifierList::modifier_removeAtIndex (GALGAS_object_5F_t & outOperand0,
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

void GALGAS_identifierList::modifier_popFirst (GALGAS_object_5F_t & outOperand0,
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

void GALGAS_identifierList::modifier_popLast (GALGAS_object_5F_t & outOperand0,
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

GALGAS_identifierList GALGAS_identifierList::operator_concat (const GALGAS_identifierList & inOperand
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_identifierList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
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

void GALGAS_identifierList::dotAssign_operation (const GALGAS_identifierList inOperand
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

void GALGAS_stringMap::modifier_put (GALGAS_lstring inKey,
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

void GALGAS_stringMap::modifier_setValueForKey (GALGAS_string inAttributeValue,
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

void GALGAS_lstringMap::modifier_put (GALGAS_lstring inKey,
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

void GALGAS_lstringMap::modifier_setValueForKey (GALGAS_lstring inAttributeValue,
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

void GALGAS_prefix_5F_map::modifier_add (GALGAS_lstring inKey,
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

void GALGAS_prefix_5F_map::modifier_insert_5F_prefix (GALGAS_lstring inKey,
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

void GALGAS_prefix_5F_map::modifier_setPrefixForKey (GALGAS_string inAttributeValue,
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

void GALGAS_prefix_5F_map::modifier_setTag_5F_to_5F_repForKey (GALGAS_string inAttributeValue,
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

void GALGAS_stringset_5F_map::modifier_add (GALGAS_lstring inKey,
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

void GALGAS_stringset_5F_map::modifier_delete (GALGAS_lstring inKey,
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

void GALGAS_stringset_5F_map::modifier_setIdsForKey (GALGAS_stringset inAttributeValue,
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

void GALGAS_ident_5F_list::modifier_insertAtIndex (const GALGAS_lstring inOperand0,
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

void GALGAS_ident_5F_list::modifier_removeAtIndex (GALGAS_lstring & outOperand0,
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

void GALGAS_ident_5F_list::modifier_popFirst (GALGAS_lstring & outOperand0,
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

void GALGAS_ident_5F_list::modifier_popLast (GALGAS_lstring & outOperand0,
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

GALGAS_ident_5F_list GALGAS_ident_5F_list::operator_concat (const GALGAS_ident_5F_list & inOperand
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_ident_5F_list result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
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

void GALGAS_ident_5F_list::dotAssign_operation (const GALGAS_ident_5F_list inOperand
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

void GALGAS_ident_5F_list_5F_map::modifier_add (GALGAS_lstring inKey,
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

void GALGAS_ident_5F_list_5F_map::modifier_delete (GALGAS_lstring inKey,
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

void GALGAS_ident_5F_list_5F_map::modifier_setObjsForKey (GALGAS_ident_5F_list inAttributeValue,
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

void GALGAS_objectsMap::modifier_put (GALGAS_lstring inKey,
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

void GALGAS_objectsMap::modifier_del (GALGAS_lstring inKey,
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

void GALGAS_objectsMap::modifier_setObjectsOfKindForKey (GALGAS_objectKind inAttributeValue,
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

void GALGAS_objectKindMap::modifier_put (GALGAS_lstring inKey,
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

void GALGAS_objectKindMap::modifier_del (GALGAS_lstring inKey,
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

void GALGAS_objectKindMap::modifier_setAttributesForKey (GALGAS_objectAttributes inAttributeValue,
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
  GALGAS_implementation var_imp = GALGAS_implementation::constructor_new (GALGAS_implementationMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 39))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 39)) ;
  GALGAS_applicationDefinition var_application = function_emptyApplicationDefinition (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 40)) ;
  GALGAS_string var_fileIncludeList = GALGAS_string::makeEmptyString () ;
  GALGAS_lstring var_version ;
  GALGAS_lstring var_desc = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 46)) ;
  nt_OIL_5F_version_ (var_version, var_desc, inCompiler) ;
  {
  var_application.modifier_setVersion (var_version COMMA_SOURCE_FILE ("goil_syntax.galgas", 48)) ;
  }
  {
  var_application.modifier_setVersionDescription (var_desc COMMA_SOURCE_FILE ("goil_syntax.galgas", 49)) ;
  }
  GALGAS_string var_config_5F_file_5F_name = GALGAS_string (gOption_goil_5F_options_config.getter_value ()) ;
  GALGAS_stringlist var_configFiles = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name.add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 54)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 54)) ;
  cEnumerator_stringlist enumerator_1663 (var_configFiles, kEnumeration_down) ;
  while (enumerator_1663.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_1663.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 58)), var_imp, var_application, var_fileIncludeList, GALGAS_bool (false)  COMMA_SOURCE_FILE ("goil_syntax.galgas", 58)) ;
    enumerator_1663.gotoNextObject () ;
  }
  GALGAS_stringlist var_configVersionFiles = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name.add_operation (var_version.getter_string (SOURCE_FILE ("goil_syntax.galgas", 62)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 62)).add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 62)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 62)) ;
  cEnumerator_stringlist enumerator_1981 (var_configVersionFiles, kEnumeration_down) ;
  while (enumerator_1981.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_1981.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 65)), var_imp, var_application, var_fileIncludeList, GALGAS_bool (false)  COMMA_SOURCE_FILE ("goil_syntax.galgas", 65)) ;
    enumerator_1981.gotoNextObject () ;
  }
  nt_file_ (var_imp, var_application, var_fileIncludeList, GALGAS_bool (true), inCompiler) ;
  callCategoryMethod_checkObjectReferences ((const cPtr_implementation *) var_imp.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 83)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("goil_syntax.galgas", 85)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    routine_setDefaults (var_imp, var_application, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 86)) ;
    }
  }
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("goil_syntax.galgas", 93)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    {
    routine_verifyAll (var_imp, var_application, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 94)) ;
    }
  }
  const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("goil_syntax.galgas", 96)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_2) {
    GALGAS_TfieldMap var_templateData = callCategoryGetter_templateData ((const cPtr_applicationDefinition *) var_application.ptr (), var_imp, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 97)) ;
    {
    routine_generate_5F_all (var_templateData, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 100)) ;
    }
  }
  var_fileIncludeList = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 103)).getter_lastPathComponent (SOURCE_FILE ("goil_syntax.galgas", 103)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 103)).add_operation (var_fileIncludeList, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 103)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 103)) ;
  GALGAS_string var_oilDepFileName = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 104)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("goil_syntax.galgas", 104)).add_operation (GALGAS_string ("/build/"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 104)).add_operation (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 105)).getter_lastPathComponent (SOURCE_FILE ("goil_syntax.galgas", 105)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 105)).add_operation (GALGAS_string (".dep"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 105)) ;
  var_fileIncludeList.method_writeToFile (var_oilDepFileName, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 107)) ;
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
    ioArgument_fileIncludeList.dotAssign_operation (GALGAS_string (" \\\n"
      " ").add_operation (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 117)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 117))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 117)) ;
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
    GALGAS_lstring var_partialString ;
    var_partialString = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 145)) ;
    GALGAS_string var_result = var_partialString.getter_string (SOURCE_FILE ("goil_syntax.galgas", 146)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_goil_5F_syntax_3 (inCompiler)) {
      case 2: {
        var_partialString = inCompiler->synthetizedAttribute_a_5F_string () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 149)) ;
        GALGAS_string var_toappend = var_partialString.getter_string (SOURCE_FILE ("goil_syntax.galgas", 150)) ;
        const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_result.getter_rightSubString (GALGAS_uint ((uint32_t) 2U) COMMA_SOURCE_FILE ("goil_syntax.galgas", 151)).objectCompare (GALGAS_string ("\\n"))).boolEnum () ;
        if (kBoolTrue == test_1) {
          var_toappend = GALGAS_string (" ").add_operation (var_toappend, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 152)) ;
        }
        var_result.dotAssign_operation (var_toappend  COMMA_SOURCE_FILE ("goil_syntax.galgas", 154)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    outArgument_desc = GALGAS_lstring::constructor_new (var_result.getter_stringByReplacingStringByString (GALGAS_string ("\\n"), GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 156)), var_partialString.getter_location (SOURCE_FILE ("goil_syntax.galgas", 156))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 156)) ;
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
  GALGAS_lstring var_cpuName = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 176)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 176)) ;
  GALGAS_objectsMap var_objects = ioArgument_application.getter_objects (SOURCE_FILE ("goil_syntax.galgas", 177)) ;
  nt_object_5F_definition_5F_list_ (constinArgument_imp, var_objects, ioArgument_fileIncludeList, constinArgument_rootFile, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 179)) ;
  GALGAS_lstring joker_5222 ; // Joker input parameter
  nt_description_ (joker_5222, inCompiler) ;
  joker_5222.drop () ; // Release temporary input variables (joker in source)
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 179)) ;
  {
  ioArgument_application.modifier_setName (var_cpuName COMMA_SOURCE_FILE ("goil_syntax.galgas", 180)) ;
  }
  {
  ioArgument_application.modifier_setObjects (var_objects COMMA_SOURCE_FILE ("goil_syntax.galgas", 181)) ;
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
      GALGAS_lstring var_objectKind = inCompiler->synthetizedAttribute_att_5F_token () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 192)) ;
      GALGAS_implementationObject var_impObjOfKind = callCategoryGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), var_objectKind.getter_string (SOURCE_FILE ("goil_syntax.galgas", 193)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 193)) ;
      GALGAS_objectKind var_objectsForKind = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 194))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 194)) ;
      const enumGalgasBool test_1 = ioArgument_objects.getter_hasKey (var_objectKind.getter_string (SOURCE_FILE ("goil_syntax.galgas", 195)) COMMA_SOURCE_FILE ("goil_syntax.galgas", 195)).boolEnum () ;
      if (kBoolTrue == test_1) {
        const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_impObjOfKind.getter_multiple (SOURCE_FILE ("goil_syntax.galgas", 199)).getter_bool (SOURCE_FILE ("goil_syntax.galgas", 199)).objectCompare (GALGAS_bool (false))).boolEnum () ;
        if (kBoolTrue == test_2) {
          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 200)), GALGAS_string ("object ").add_operation (var_objectKind.getter_string (SOURCE_FILE ("goil_syntax.galgas", 200)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 200)).add_operation (GALGAS_string (" may not have multiple instance"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 200))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 200)) ;
        }
        {
        ioArgument_objects.modifier_del (var_objectKind, var_objectsForKind, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 202)) ;
        }
      }
      GALGAS_lstring var_objectName = inCompiler->synthetizedAttribute_att_5F_token () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 204)) ;
      GALGAS_objectAttributes var_object = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 205)) ;
      GALGAS_objectKindMap var_objectsKind = var_objectsForKind.getter_objects (SOURCE_FILE ("goil_syntax.galgas", 206)) ;
      const enumGalgasBool test_3 = var_objectsKind.getter_hasKey (var_objectName.getter_string (SOURCE_FILE ("goil_syntax.galgas", 207)) COMMA_SOURCE_FILE ("goil_syntax.galgas", 207)).boolEnum () ;
      if (kBoolTrue == test_3) {
        {
        var_objectsKind.modifier_del (var_objectName, var_object, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 208)) ;
        }
      }
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 210)) ;
      nt_oil_5F_declaration_5F_list_ (var_impObjOfKind.getter_attributes (SOURCE_FILE ("goil_syntax.galgas", 211)), var_object, inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 212)) ;
      GALGAS_lstring var_oil_5F_desc ;
      nt_description_ (var_oil_5F_desc, inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 214)) ;
      GALGAS_identifierMap var_attributes = var_object.getter_objectParams (SOURCE_FILE ("goil_syntax.galgas", 215)) ;
      const enumGalgasBool test_4 = var_attributes.getter_hasKey (GALGAS_string ("NAME") COMMA_SOURCE_FILE ("goil_syntax.galgas", 216)).operator_not (SOURCE_FILE ("goil_syntax.galgas", 216)).boolEnum () ;
      if (kBoolTrue == test_4) {
        {
        var_attributes.modifier_put (GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), var_objectName.getter_location (SOURCE_FILE ("goil_syntax.galgas", 217))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 217)), GALGAS_stringAttribute::constructor_new (var_oil_5F_desc, var_objectName.getter_location (SOURCE_FILE ("goil_syntax.galgas", 217)), var_objectName.getter_string (SOURCE_FILE ("goil_syntax.galgas", 217))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 217)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 217)) ;
        }
        {
        var_object.modifier_setObjectParams (var_attributes COMMA_SOURCE_FILE ("goil_syntax.galgas", 218)) ;
        }
      }
      {
      var_objectsKind.modifier_put (var_objectName, var_object, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 220)) ;
      }
      {
      var_objectsForKind.modifier_setObjects (var_objectsKind COMMA_SOURCE_FILE ("goil_syntax.galgas", 221)) ;
      }
      {
      ioArgument_objects.modifier_put (var_objectKind, var_objectsForKind, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 222)) ;
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
  GALGAS_lstring var_idf ;
  GALGAS_object_5F_t var_val ;
  var_idf = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 254)) ;
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("goil_syntax.galgas", 258)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 258))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 258)) ;
  GALGAS_impType var_type = GALGAS_impVoid::constructor_new (temp_0, GALGAS_dataType::constructor_void (SOURCE_FILE ("goil_syntax.galgas", 258)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 258)), GALGAS_bool (false), GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("goil_syntax.galgas", 258))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 258)) ;
  GALGAS_bool var_typeOk = GALGAS_bool (false) ;
  const enumGalgasBool test_1 = constinArgument_types.getter_hasKey (var_idf.getter_string (SOURCE_FILE ("goil_syntax.galgas", 260)) COMMA_SOURCE_FILE ("goil_syntax.galgas", 260)).boolEnum () ;
  if (kBoolTrue == test_1) {
    constinArgument_types.method_get (var_idf, var_type, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 261)) ;
    var_typeOk = GALGAS_bool (true) ;
  }else if (kBoolFalse == test_1) {
    GALGAS_location location_2 (var_idf.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_2, var_idf.getter_string (SOURCE_FILE ("goil_syntax.galgas", 264)).add_operation (GALGAS_string (" is not declared in the IMPLEMENTATION"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 264))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 264)) ;
  }
  switch (select_goil_5F_syntax_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 267)) ;
    switch (select_goil_5F_syntax_8 (inCompiler)) {
    case 1: {
      GALGAS_lstring var_value ;
      var_value = inCompiler->synthetizedAttribute_att_5F_token () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 271)) ;
      GALGAS_implementationObjectMap var_subTypes = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 272)) ;
      GALGAS_objectAttributes var_subAttributes = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 273)) ;
      switch (var_type.getter_type (SOURCE_FILE ("goil_syntax.galgas", 274)).enumValue ()) {
      case GALGAS_dataType::kNotBuilt:
        break ;
      case GALGAS_dataType::kEnum_enumeration:
        {
          if (var_type.isValid ()) {
            if (var_type.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
              GALGAS_impEnumType cast_8299_enumType ((cPtr_impEnumType *) var_type.ptr ()) ;
              const enumGalgasBool test_3 = cast_8299_enumType.getter_valuesMap (SOURCE_FILE ("goil_syntax.galgas", 278)).getter_hasKey (var_value.getter_string (SOURCE_FILE ("goil_syntax.galgas", 278)) COMMA_SOURCE_FILE ("goil_syntax.galgas", 278)).boolEnum () ;
              if (kBoolTrue == test_3) {
                cast_8299_enumType.getter_valuesMap (SOURCE_FILE ("goil_syntax.galgas", 279)).method_get (var_value, var_subTypes, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 279)) ;
              }else if (kBoolFalse == test_3) {
                GALGAS_location location_4 (var_value.getter_location (HERE)) ; // Implicit use of 'location' getter
                inCompiler->emitSemanticError (location_4, var_value.getter_string (SOURCE_FILE ("goil_syntax.galgas", 281)).add_operation (GALGAS_string (" ENUM value undeclared. One of the following values are expected: "), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 281)).add_operation (function_valueList (cast_8299_enumType.getter_valuesMap (SOURCE_FILE ("goil_syntax.galgas", 281)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 281)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 281))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 281)) ;
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
          GALGAS_location location_5 (var_idf.getter_location (HERE)) ; // Implicit use of 'location' getter
          inCompiler->emitSemanticError (location_5, var_idf.getter_string (SOURCE_FILE ("goil_syntax.galgas", 287)).add_operation (GALGAS_string (" is not an ENUM nor and IDENTIFIER nor an object reference"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 287))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 287)) ;
        }
        break ;
      }
      switch (select_goil_5F_syntax_9 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 290)) ;
        nt_oil_5F_declaration_5F_list_ (var_subTypes, var_subAttributes, inCompiler) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 292)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      GALGAS_lstring var_oil_5F_desc ;
      nt_description_ (var_oil_5F_desc, inCompiler) ;
      const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, var_type.getter_type (SOURCE_FILE ("goil_syntax.galgas", 295)).objectCompare (GALGAS_dataType::constructor_enumeration (SOURCE_FILE ("goil_syntax.galgas", 295)))).boolEnum () ;
      if (kBoolTrue == test_6) {
        var_val = GALGAS_enumAttribute::constructor_new (var_oil_5F_desc, var_value.getter_location (SOURCE_FILE ("goil_syntax.galgas", 296)), var_value.getter_string (SOURCE_FILE ("goil_syntax.galgas", 296)), var_subAttributes  COMMA_SOURCE_FILE ("goil_syntax.galgas", 296)) ;
      }else if (kBoolFalse == test_6) {
        const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, var_type.getter_type (SOURCE_FILE ("goil_syntax.galgas", 297)).objectCompare (GALGAS_dataType::constructor_objectType (SOURCE_FILE ("goil_syntax.galgas", 297)))).boolEnum () ;
        if (kBoolTrue == test_7) {
          var_val = GALGAS_objectRefAttribute::constructor_new (var_oil_5F_desc, var_value.getter_location (SOURCE_FILE ("goil_syntax.galgas", 298)), var_value  COMMA_SOURCE_FILE ("goil_syntax.galgas", 298)) ;
        }else if (kBoolFalse == test_7) {
          var_val = GALGAS_string_5F_class::constructor_new (var_oil_5F_desc, var_value.getter_location (SOURCE_FILE ("goil_syntax.galgas", 300)), var_value.getter_string (SOURCE_FILE ("goil_syntax.galgas", 300))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 300)) ;
        }
      }
    } break ;
    case 2: {
      GALGAS_bool var_sign ;
      nt_sign_ (var_sign, inCompiler) ;
      switch (select_goil_5F_syntax_10 (inCompiler)) {
      case 1: {
        GALGAS_luint_36__34_ var_value ;
        var_value = inCompiler->synthetizedAttribute_integerNumber () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_SOURCE_FILE ("goil_syntax.galgas", 309)) ;
        GALGAS_lstring var_oil_5F_desc ;
        nt_description_ (var_oil_5F_desc, inCompiler) ;
        var_val = function_checkAndGetIntegerNumber (var_oil_5F_desc, var_type.getter_type (SOURCE_FILE ("goil_syntax.galgas", 311)), var_value, var_sign, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 311)) ;
      } break ;
      case 2: {
        GALGAS_ldouble var_value ;
        var_value = inCompiler->synthetizedAttribute_floatNumber () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE ("goil_syntax.galgas", 315)) ;
        GALGAS_lstring var_oil_5F_desc ;
        nt_description_ (var_oil_5F_desc, inCompiler) ;
        var_val = function_checkAndGetFloatNumber (var_oil_5F_desc, var_type.getter_type (SOURCE_FILE ("goil_syntax.galgas", 317)), var_value, var_sign, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 317)) ;
      } break ;
      default:
        break ;
      }
    } break ;
    case 3: {
      GALGAS_lbool var_value ;
      nt_boolean_ (var_value, inCompiler) ;
      GALGAS_implementationObjectMap var_subTypes = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 323)) ;
      GALGAS_objectAttributes var_subAttributes = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 324)) ;
      const enumGalgasBool test_8 = GALGAS_bool (kIsNotEqual, var_type.getter_type (SOURCE_FILE ("goil_syntax.galgas", 325)).objectCompare (GALGAS_dataType::constructor_boolean (SOURCE_FILE ("goil_syntax.galgas", 325)))).boolEnum () ;
      if (kBoolTrue == test_8) {
        GALGAS_location location_9 (var_idf.getter_location (HERE)) ; // Implicit use of 'location' getter
        inCompiler->emitSemanticError (location_9, extensionGetter_oilType (var_type.getter_type (SOURCE_FILE ("goil_syntax.galgas", 326)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 326)).add_operation (GALGAS_string (" expected, got a BOOLEAN"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 326))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 326)) ;
      }else if (kBoolFalse == test_8) {
        if (var_type.isValid ()) {
          if (var_type.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impBoolType) {
            GALGAS_impBoolType cast_10261_boolType ((cPtr_impBoolType *) var_type.ptr ()) ;
            const enumGalgasBool test_10 = var_value.getter_bool (SOURCE_FILE ("goil_syntax.galgas", 330)).boolEnum () ;
            if (kBoolTrue == test_10) {
              var_subTypes = cast_10261_boolType.getter_trueSubAttributes (SOURCE_FILE ("goil_syntax.galgas", 331)) ;
            }else if (kBoolFalse == test_10) {
              var_subTypes = cast_10261_boolType.getter_falseSubAttributes (SOURCE_FILE ("goil_syntax.galgas", 333)) ;
            }
          }
        }
      }
      switch (select_goil_5F_syntax_11 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 338)) ;
        const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, var_subTypes.getter_count (SOURCE_FILE ("goil_syntax.galgas", 339)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_11) {
          GALGAS_location location_12 (var_value.getter_location (HERE)) ; // Implicit use of 'location' getter
          inCompiler->emitSemanticError (location_12, function_stringLBool (var_value, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 340)).add_operation (GALGAS_string (" value of "), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 340)).add_operation (var_idf.getter_string (SOURCE_FILE ("goil_syntax.galgas", 340)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 340)).add_operation (GALGAS_string (" has no sub-attribute"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 340))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 340)) ;
        }
        nt_oil_5F_declaration_5F_list_ (var_subTypes, var_subAttributes, inCompiler) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 343)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      GALGAS_lstring var_oil_5F_desc ;
      nt_description_ (var_oil_5F_desc, inCompiler) ;
      var_val = GALGAS_boolAttribute::constructor_new (var_oil_5F_desc, var_idf.getter_location (SOURCE_FILE ("goil_syntax.galgas", 346)), var_value.getter_bool (SOURCE_FILE ("goil_syntax.galgas", 346)), var_subAttributes  COMMA_SOURCE_FILE ("goil_syntax.galgas", 346)) ;
    } break ;
    case 4: {
      GALGAS_lstring var_literalString ;
      var_literalString = inCompiler->synthetizedAttribute_a_5F_string () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 350)) ;
      GALGAS_lstring var_oil_5F_desc ;
      nt_description_ (var_oil_5F_desc, inCompiler) ;
      var_val = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc, var_literalString.getter_location (SOURCE_FILE ("goil_syntax.galgas", 352)), var_literalString.getter_string (SOURCE_FILE ("goil_syntax.galgas", 352))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 352)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("goil_syntax.galgas", 355)) ;
      GALGAS_lstring var_oil_5F_desc ;
      nt_description_ (var_oil_5F_desc, inCompiler) ;
      const enumGalgasBool test_13 = callCategoryGetter_autoAllowed ((const cPtr_impType *) var_type.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 358)).boolEnum () ;
      if (kBoolTrue == test_13) {
        var_val = GALGAS_auto::constructor_new (var_oil_5F_desc, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 359))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 359)) ;
      }else if (kBoolFalse == test_13) {
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 374)), GALGAS_string ("AUTO is not allowed")  COMMA_SOURCE_FILE ("goil_syntax.galgas", 374)) ;
        var_val.drop () ; // Release error dropped variable
      }
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    GALGAS_lstring var_name = inCompiler->synthetizedAttribute_att_5F_token () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 378)) ;
    GALGAS_implementationObjectMap var_subTypes = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 379)) ;
    GALGAS_objectAttributes var_subAttributes = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 380)) ;
    const enumGalgasBool test_14 = GALGAS_bool (kIsNotEqual, var_type.getter_type (SOURCE_FILE ("goil_syntax.galgas", 382)).objectCompare (GALGAS_dataType::constructor_structType (SOURCE_FILE ("goil_syntax.galgas", 382)))).boolEnum () ;
    if (kBoolTrue == test_14) {
      GALGAS_location location_15 (var_idf.getter_location (HERE)) ; // Implicit use of 'location' getter
      inCompiler->emitSemanticError (location_15, extensionGetter_oilType (var_type.getter_type (SOURCE_FILE ("goil_syntax.galgas", 383)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 383)).add_operation (GALGAS_string (" expected, got a STRUCT"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 383))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 383)) ;
    }else if (kBoolFalse == test_14) {
      if (var_type.isValid ()) {
        if (var_type.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impStructType) {
          GALGAS_impStructType cast_12287_structType ((cPtr_impStructType *) var_type.ptr ()) ;
          var_subTypes = cast_12287_structType.getter_structAttributes (SOURCE_FILE ("goil_syntax.galgas", 387)) ;
        }
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 390)) ;
    nt_oil_5F_declaration_5F_list_ (var_subTypes, var_subAttributes, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 392)) ;
    GALGAS_lstring var_oil_5F_desc ;
    nt_description_ (var_oil_5F_desc, inCompiler) ;
    var_val = GALGAS_structAttribute::constructor_new (var_oil_5F_desc, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 394)), var_name, var_subAttributes  COMMA_SOURCE_FILE ("goil_syntax.galgas", 394)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 396)) ;
  GALGAS_identifierMap var_idfs = ioArgument_identifiers.getter_objectParams (SOURCE_FILE ("goil_syntax.galgas", 399)) ;
  const enumGalgasBool test_16 = var_type.getter_multiple (SOURCE_FILE ("goil_syntax.galgas", 400)).boolEnum () ;
  if (kBoolTrue == test_16) {
    const enumGalgasBool test_17 = var_idfs.getter_hasKey (var_idf.getter_string (SOURCE_FILE ("goil_syntax.galgas", 401)) COMMA_SOURCE_FILE ("goil_syntax.galgas", 401)).boolEnum () ;
    if (kBoolTrue == test_17) {
      GALGAS_object_5F_t var_attributeList ;
      {
      var_idfs.modifier_del (var_idf, var_attributeList, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 405)) ;
      }
      if (var_attributeList.isValid ()) {
        if (var_attributeList.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
          GALGAS_multipleAttribute cast_12941_multiAttribute ((cPtr_multipleAttribute *) var_attributeList.ptr ()) ;
          GALGAS_identifierList var_aList = cast_12941_multiAttribute.getter_items (SOURCE_FILE ("goil_syntax.galgas", 408)) ;
          var_aList.addAssign_operation (var_val  COMMA_SOURCE_FILE ("goil_syntax.galgas", 409)) ;
          var_val = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 410)), cast_12941_multiAttribute.getter_location (SOURCE_FILE ("goil_syntax.galgas", 410)), var_aList  COMMA_SOURCE_FILE ("goil_syntax.galgas", 410)) ;
        }
      }
    }else if (kBoolFalse == test_17) {
      var_val = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 413)), var_val.getter_location (SOURCE_FILE ("goil_syntax.galgas", 413)), GALGAS_identifierList::constructor_listWithValue (var_val  COMMA_SOURCE_FILE ("goil_syntax.galgas", 413))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 413)) ;
    }
  }
  const enumGalgasBool test_18 = var_typeOk.boolEnum () ;
  if (kBoolTrue == test_18) {
    {
    var_idfs.modifier_put (var_idf, var_val, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 417)) ;
    }
  }
  {
  ioArgument_identifiers.modifier_setObjectParams (var_idfs COMMA_SOURCE_FILE ("goil_syntax.galgas", 419)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_oil_5F_declaration_i9_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 254)) ;
  switch (select_goil_5F_syntax_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 267)) ;
    switch (select_goil_5F_syntax_8 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 271)) ;
      switch (select_goil_5F_syntax_9 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 290)) ;
        nt_oil_5F_declaration_5F_list_parse (inCompiler) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 292)) ;
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
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_SOURCE_FILE ("goil_syntax.galgas", 309)) ;
        nt_description_parse (inCompiler) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE ("goil_syntax.galgas", 315)) ;
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
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 338)) ;
        nt_oil_5F_declaration_5F_list_parse (inCompiler) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 343)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      nt_description_parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 350)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("goil_syntax.galgas", 355)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 378)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 390)) ;
    nt_oil_5F_declaration_5F_list_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 392)) ;
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 396)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_file_5F_level_i10_ (GALGAS_implementation & ioArgument_imp,
                                                                                GALGAS_applicationDefinition & ioArgument_application,
                                                                                GALGAS_string & ioArgument_fileIncludeList,
                                                                                const GALGAS_bool constinArgument_rootFile,
                                                                                C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("goil_syntax.galgas", 428)) ;
  GALGAS_lstring var_file_5F_name ;
  switch (select_goil_5F_syntax_12 (inCompiler)) {
  case 1: {
    var_file_5F_name = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 431)) ;
    {
    routine_file_5F_in_5F_path (var_file_5F_name, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 432)) ;
    }
  } break ;
  case 2: {
    var_file_5F_name = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 434)) ;
  } break ;
  default:
    break ;
  }
  cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, var_file_5F_name, ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, constinArgument_rootFile  COMMA_SOURCE_FILE ("goil_syntax.galgas", 436)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("goil_syntax.galgas", 428)) ;
  switch (select_goil_5F_syntax_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 431)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 434)) ;
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
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("goil_syntax.galgas", 445)) ;
  GALGAS_lstring var_file_5F_name ;
  switch (select_goil_5F_syntax_13 (inCompiler)) {
  case 1: {
    var_file_5F_name = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 448)) ;
    {
    routine_file_5F_in_5F_path (var_file_5F_name, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 449)) ;
    }
  } break ;
  case 2: {
    var_file_5F_name = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 451)) ;
  } break ;
  default:
    break ;
  }
  cGrammar_goil_5F_cpu_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, var_file_5F_name, constinArgument_imp, ioArgument_objects, ioArgument_fileIncludeList, constinArgument_rootFile  COMMA_SOURCE_FILE ("goil_syntax.galgas", 453)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("goil_syntax.galgas", 445)) ;
  switch (select_goil_5F_syntax_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 448)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 451)) ;
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
//                                                                                                                     *
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                     *
//                                                                                                                     *
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
, NONTERMINAL (13) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 5 : <sign>, in file 'goil_syntax.ggs', line 126
, NONTERMINAL (14) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 7 : <description>, in file 'goil_syntax.ggs', line 139
, NONTERMINAL (15) // <select_goil_5F_syntax_2>
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
, NONTERMINAL (17) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 25 : <boolean>, in file 'goil_syntax.ggs', line 230
, NONTERMINAL (18) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 27 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
, NONTERMINAL (19) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 29 : <oil_declaration>, in file 'goil_syntax.ggs', line 249
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (20) // <select_goil_5F_syntax_7>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 33 : <include_file_level>, in file 'goil_syntax.ggs', line 422
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, NONTERMINAL (25) // <select_goil_5F_syntax_12>
, END_PRODUCTION
// At index 36 : <include_cpu_level>, in file 'goil_syntax.ggs', line 439
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, NONTERMINAL (26) // <select_goil_5F_syntax_13>
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 39 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, END_PRODUCTION
// At index 40 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (11) // <include_file_level>
, NONTERMINAL (13) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 43 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (13) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 46 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (6) // <application_definition>
, NONTERMINAL (13) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 49 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) // $-$
, END_PRODUCTION
// At index 51 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) // $+$
, END_PRODUCTION
// At index 53 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, END_PRODUCTION
// At index 54 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, END_PRODUCTION
// At index 55 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) // $:$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (16) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 59 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, END_PRODUCTION
// At index 60 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (16) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 63 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, END_PRODUCTION
// At index 64 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (17) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 73 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, NONTERMINAL (12) // <include_cpu_level>
, NONTERMINAL (17) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 76 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 78 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 80 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 243
, END_PRODUCTION
// At index 81 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 243
, NONTERMINAL (10) // <oil_declaration>
, NONTERMINAL (19) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 84 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 266
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (21) // <select_goil_5F_syntax_8>
, END_PRODUCTION
// At index 87 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 266
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 93 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (22) // <select_goil_5F_syntax_9>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 97 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
, NONTERMINAL (3) // <sign>
, NONTERMINAL (23) // <select_goil_5F_syntax_10>
, END_PRODUCTION
// At index 100 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (24) // <select_goil_5F_syntax_11>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 104 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 107 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 110 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 289
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 114 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 289
, END_PRODUCTION
// At index 115 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 306
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 118 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 306
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 121 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 337
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 125 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 337
, END_PRODUCTION
// At index 126 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 430
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 128 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 430
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 130 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 447
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 132 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 447
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 134 : <>, in file '.ggs', line 0
, NONTERMINAL (7) // <object_definition_list>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          P R O D U C T I O N    N A M E S                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_goil_cpu_level_include [48] = {
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
 {"<select_goil_5F_syntax_0>", "goil_syntax", 39}, // at index 12
 {"<select_goil_5F_syntax_0>", "goil_syntax", 40}, // at index 13
 {"<select_goil_5F_syntax_0>", "goil_syntax", 43}, // at index 14
 {"<select_goil_5F_syntax_0>", "goil_syntax", 46}, // at index 15
 {"<select_goil_5F_syntax_1>", "goil_syntax", 49}, // at index 16
 {"<select_goil_5F_syntax_1>", "goil_syntax", 51}, // at index 17
 {"<select_goil_5F_syntax_1>", "goil_syntax", 53}, // at index 18
 {"<select_goil_5F_syntax_2>", "goil_syntax", 54}, // at index 19
 {"<select_goil_5F_syntax_2>", "goil_syntax", 55}, // at index 20
 {"<select_goil_5F_syntax_3>", "goil_syntax", 59}, // at index 21
 {"<select_goil_5F_syntax_3>", "goil_syntax", 60}, // at index 22
 {"<select_goil_5F_syntax_4>", "goil_syntax", 63}, // at index 23
 {"<select_goil_5F_syntax_4>", "goil_syntax", 64}, // at index 24
 {"<select_goil_5F_syntax_4>", "goil_syntax", 73}, // at index 25
 {"<select_goil_5F_syntax_5>", "goil_syntax", 76}, // at index 26
 {"<select_goil_5F_syntax_5>", "goil_syntax", 78}, // at index 27
 {"<select_goil_5F_syntax_6>", "goil_syntax", 80}, // at index 28
 {"<select_goil_5F_syntax_6>", "goil_syntax", 81}, // at index 29
 {"<select_goil_5F_syntax_7>", "goil_syntax", 84}, // at index 30
 {"<select_goil_5F_syntax_7>", "goil_syntax", 87}, // at index 31
 {"<select_goil_5F_syntax_8>", "goil_syntax", 93}, // at index 32
 {"<select_goil_5F_syntax_8>", "goil_syntax", 97}, // at index 33
 {"<select_goil_5F_syntax_8>", "goil_syntax", 100}, // at index 34
 {"<select_goil_5F_syntax_8>", "goil_syntax", 104}, // at index 35
 {"<select_goil_5F_syntax_8>", "goil_syntax", 107}, // at index 36
 {"<select_goil_5F_syntax_9>", "goil_syntax", 110}, // at index 37
 {"<select_goil_5F_syntax_9>", "goil_syntax", 114}, // at index 38
 {"<select_goil_5F_syntax_10>", "goil_syntax", 115}, // at index 39
 {"<select_goil_5F_syntax_10>", "goil_syntax", 118}, // at index 40
 {"<select_goil_5F_syntax_11>", "goil_syntax", 121}, // at index 41
 {"<select_goil_5F_syntax_11>", "goil_syntax", 125}, // at index 42
 {"<select_goil_5F_syntax_12>", "goil_syntax", 126}, // at index 43
 {"<select_goil_5F_syntax_12>", "goil_syntax", 128}, // at index 44
 {"<select_goil_5F_syntax_13>", "goil_syntax", 130}, // at index 45
 {"<select_goil_5F_syntax_13>", "goil_syntax", 132}, // at index 46
 {"<>", "", 134} // at index 47
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_goil_cpu_level_include [48] = {
0, // index 0 : <start>, in file 'goil_syntax.ggs', line 38
3, // index 1 : <file>, in file 'goil_syntax.ggs', line 110
5, // index 2 : <sign>, in file 'goil_syntax.ggs', line 126
7, // index 3 : <description>, in file 'goil_syntax.ggs', line 139
9, // index 4 : <OIL_version>, in file 'goil_syntax.ggs', line 163
15, // index 5 : <application_definition>, in file 'goil_syntax.ggs', line 170
23, // index 6 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
25, // index 7 : <boolean>, in file 'goil_syntax.ggs', line 230
27, // index 8 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
29, // index 9 : <oil_declaration>, in file 'goil_syntax.ggs', line 249
33, // index 10 : <include_file_level>, in file 'goil_syntax.ggs', line 422
36, // index 11 : <include_cpu_level>, in file 'goil_syntax.ggs', line 439
39, // index 12 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
40, // index 13 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
43, // index 14 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
46, // index 15 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
49, // index 16 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
51, // index 17 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
53, // index 18 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
54, // index 19 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
55, // index 20 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
59, // index 21 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
60, // index 22 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
63, // index 23 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
64, // index 24 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
73, // index 25 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
76, // index 26 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
78, // index 27 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
80, // index 28 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 243
81, // index 29 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 243
84, // index 30 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 266
87, // index 31 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 266
93, // index 32 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
97, // index 33 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
100, // index 34 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
104, // index 35 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
107, // index 36 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
110, // index 37 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 289
114, // index 38 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 289
115, // index 39 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 306
118, // index 40 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 306
121, // index 41 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 337
125, // index 42 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 337
126, // index 43 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 430
128, // index 44 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 430
130, // index 45 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 447
132, // index 46 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 447
134 // index 47 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_goil_cpu_level_include [29] = {
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
12, // at 13 : <select_goil_5F_syntax_0>
16, // at 14 : <select_goil_5F_syntax_1>
19, // at 15 : <select_goil_5F_syntax_2>
21, // at 16 : <select_goil_5F_syntax_3>
23, // at 17 : <select_goil_5F_syntax_4>
26, // at 18 : <select_goil_5F_syntax_5>
28, // at 19 : <select_goil_5F_syntax_6>
30, // at 20 : <select_goil_5F_syntax_7>
32, // at 21 : <select_goil_5F_syntax_8>
37, // at 22 : <select_goil_5F_syntax_9>
39, // at 23 : <select_goil_5F_syntax_10>
41, // at 24 : <select_goil_5F_syntax_11>
43, // at 25 : <select_goil_5F_syntax_12>
45, // at 26 : <select_goil_5F_syntax_13>
47, // at 27 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                      *
//                                                                                                                     *
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
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 12 : <select_goil_5F_syntax_0>
-1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 2
-1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 19 : <select_goil_5F_syntax_1>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 3
  -1,
// At index 27 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 32 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 37 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__7D_, C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 3
  -1,
// At index 45 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 50 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 55 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 60 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 75 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 81 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 86 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 92 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 97 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 102 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_goil_cpu_level_include [29] = {
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
12, // at 13 : <select_goil_5F_syntax_0>
19, // at 14 : <select_goil_5F_syntax_1>
27, // at 15 : <select_goil_5F_syntax_2>
32, // at 16 : <select_goil_5F_syntax_3>
37, // at 17 : <select_goil_5F_syntax_4>
45, // at 18 : <select_goil_5F_syntax_5>
50, // at 19 : <select_goil_5F_syntax_6>
55, // at 20 : <select_goil_5F_syntax_7>
60, // at 21 : <select_goil_5F_syntax_8>
75, // at 22 : <select_goil_5F_syntax_9>
81, // at 23 : <select_goil_5F_syntax_10>
86, // at 24 : <select_goil_5F_syntax_11>
92, // at 25 : <select_goil_5F_syntax_12>
97, // at 26 : <select_goil_5F_syntax_13>
102, // at 27 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              'implementation_definition' non terminal implementation                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * ) {
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_implementation_5F_definition_ (GALGAS_implementation & ,
                                C_Lexique_goil_5F_lexique * ) {
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        'start' non terminal implementation                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_start_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_start_ (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_(inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         'file' non terminal implementation                                          *
//                                                                                                                     *
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
//                                                                                                                     *
//                                         'sign' non terminal implementation                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     'description' non terminal implementation                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     'OIL_version' non terminal implementation                                       *
//                                                                                                                     *
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
//                                                                                                                     *
//                                'application_definition' non terminal implementation                                 *
//                                                                                                                     *
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
//                                                                                                                     *
//                                'object_definition_list' non terminal implementation                                 *
//                                                                                                                     *
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
                                    gFirstProductionIndexes_goil_cpu_level_include, gDecision_goil_cpu_level_include, gDecisionIndexes_goil_cpu_level_include, 134) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Grammar start symbol implementation                                          *
//                                                                                                                     *
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
                                                      gFirstProductionIndexes_goil_cpu_level_include, gDecision_goil_cpu_level_include, gDecisionIndexes_goil_cpu_level_include, 134) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_cpu_5F_level_5F_include grammar ;
        grammar.nt_object_5F_definition_5F_list_ (parameter_1, parameter_2, parameter_3, parameter_4, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message COMMA_THERE) ;
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
                                                    gFirstProductionIndexes_goil_cpu_level_include, gDecision_goil_cpu_level_include, gDecisionIndexes_goil_cpu_level_include, 134) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_goil_5F_cpu_5F_level_5F_include grammar ;
      grammar.nt_object_5F_definition_5F_list_ (parameter_1, parameter_2, parameter_3, parameter_4, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       'boolean' non terminal implementation                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 'oil_declaration_list' non terminal implementation                                  *
//                                                                                                                     *
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
//                                                                                                                     *
//                                   'oil_declaration' non terminal implementation                                     *
//                                                                                                                     *
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
//                                                                                                                     *
//                                  'include_file_level' non terminal implementation                                   *
//                                                                                                                     *
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
//                                                                                                                     *
//                                  'include_cpu_level' non terminal implementation                                    *
//                                                                                                                     *
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
//                                                                                                                     *
//                            'select_goil_5F_syntax_0' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_1' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_2' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_3' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_4' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_5' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_6' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_7' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_8' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_9' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_10' added non terminal implementation                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_11' added non terminal implementation                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_12' added non terminal implementation                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_13' added non terminal implementation                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int16_t gProductions_template_grammar [] = {
// At index 0 : <goil_template_start_symbol>, in file 'template_parser.ggs', line 601
  NONTERMINAL (6) // <template_instruction_list>
, END_PRODUCTION
// At index 2 : <template_instruction>, in file 'template_parser.ggs', line 87
, TERMINAL (C_Lexique_template_5F_scanner::kToken__21_) // $!$
, NONTERMINAL (5) // <expression>
, END_PRODUCTION
// At index 5 : <template_instruction>, in file 'template_parser.ggs', line 134
, TERMINAL (C_Lexique_template_5F_scanner::kToken_write) // $write$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_to) // $to$
, NONTERMINAL (13) // <select_template_5F_parser_0>
, NONTERMINAL (5) // <expression>
, TERMINAL (C_Lexique_template_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (6) // <template_instruction_list>
, TERMINAL (C_Lexique_template_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_write) // $write$
, END_PRODUCTION
// At index 14 : <template_instruction>, in file 'template_parser.ggs', line 220
, TERMINAL (C_Lexique_template_5F_scanner::kToken_template) // $template$
, NONTERMINAL (15) // <select_template_5F_parser_2>
, END_PRODUCTION
// At index 17 : <template_instruction>, in file 'template_parser.ggs', line 295
, TERMINAL (C_Lexique_template_5F_scanner::kToken__3F_) // $?$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 20 : <template_instruction>, in file 'template_parser.ggs', line 328
, TERMINAL (C_Lexique_template_5F_scanner::kToken_function) // $function$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_template_5F_scanner::kToken__28_) // $($
, NONTERMINAL (19) // <select_template_5F_parser_6>
, TERMINAL (C_Lexique_template_5F_scanner::kToken__29_) // $)$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_functionContent) // $functionContent$
, END_PRODUCTION
// At index 27 : <template_instruction>, in file 'template_parser.ggs', line 361
, TERMINAL (C_Lexique_template_5F_scanner::kToken_call) // $call$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_template_5F_scanner::kToken__28_) // $($
, NONTERMINAL (21) // <select_template_5F_parser_8>
, TERMINAL (C_Lexique_template_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 33 : <template_instruction>, in file 'template_parser.ggs', line 428
, TERMINAL (C_Lexique_template_5F_scanner::kToken_return) // $return$
, NONTERMINAL (5) // <expression>
, END_PRODUCTION
// At index 36 : <template_instruction>, in file 'template_parser.ggs', line 493
, TERMINAL (C_Lexique_template_5F_scanner::kToken_if) // $if$
, NONTERMINAL (5) // <expression>
, TERMINAL (C_Lexique_template_5F_scanner::kToken_then) // $then$
, NONTERMINAL (6) // <template_instruction_list>
, NONTERMINAL (23) // <select_template_5F_parser_10>
, NONTERMINAL (24) // <select_template_5F_parser_11>
, TERMINAL (C_Lexique_template_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_if) // $if$
, END_PRODUCTION
// At index 45 : <template_instruction>, in file 'template_parser.ggs', line 621
, TERMINAL (C_Lexique_template_5F_scanner::kToken_foreach) // $foreach$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_in) // $in$
, NONTERMINAL (5) // <expression>
, NONTERMINAL (26) // <select_template_5F_parser_13>
, NONTERMINAL (27) // <select_template_5F_parser_14>
, TERMINAL (C_Lexique_template_5F_scanner::kToken_do) // $do$
, NONTERMINAL (6) // <template_instruction_list>
, NONTERMINAL (28) // <select_template_5F_parser_15>
, NONTERMINAL (29) // <select_template_5F_parser_16>
, TERMINAL (C_Lexique_template_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_foreach) // $foreach$
, END_PRODUCTION
// At index 58 : <template_instruction>, in file 'template_parser.ggs', line 758
, TERMINAL (C_Lexique_template_5F_scanner::kToken_for) // $for$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_in) // $in$
, NONTERMINAL (5) // <expression>
, NONTERMINAL (30) // <select_template_5F_parser_17>
, TERMINAL (C_Lexique_template_5F_scanner::kToken_do) // $do$
, NONTERMINAL (6) // <template_instruction_list>
, NONTERMINAL (31) // <select_template_5F_parser_18>
, TERMINAL (C_Lexique_template_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_for) // $for$
, END_PRODUCTION
// At index 69 : <template_instruction>, in file 'template_parser.ggs', line 848
, TERMINAL (C_Lexique_template_5F_scanner::kToken_loop) // $loop$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_from) // $from$
, NONTERMINAL (5) // <expression>
, TERMINAL (C_Lexique_template_5F_scanner::kToken_to) // $to$
, NONTERMINAL (5) // <expression>
, NONTERMINAL (32) // <select_template_5F_parser_19>
, TERMINAL (C_Lexique_template_5F_scanner::kToken_do) // $do$
, NONTERMINAL (6) // <template_instruction_list>
, NONTERMINAL (33) // <select_template_5F_parser_20>
, NONTERMINAL (34) // <select_template_5F_parser_21>
, TERMINAL (C_Lexique_template_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_loop) // $loop$
, END_PRODUCTION
// At index 83 : <template_instruction>, in file 'template_parser.ggs', line 987
, TERMINAL (C_Lexique_template_5F_scanner::kToken_let) // $let$
, NONTERMINAL (3) // <variable>
, NONTERMINAL (35) // <select_template_5F_parser_22>
, END_PRODUCTION
// At index 87 : <template_instruction>, in file 'template_parser.ggs', line 1085
, TERMINAL (C_Lexique_template_5F_scanner::kToken_error) // $error$
, NONTERMINAL (4) // <variable_or_here>
, TERMINAL (C_Lexique_template_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (5) // <expression>
, END_PRODUCTION
// At index 92 : <template_instruction>, in file 'template_parser.ggs', line 1117
, TERMINAL (C_Lexique_template_5F_scanner::kToken_warning) // $warning$
, NONTERMINAL (4) // <variable_or_here>
, TERMINAL (C_Lexique_template_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (5) // <expression>
, END_PRODUCTION
// At index 97 : <template_instruction>, in file 'template_parser.ggs', line 1147
, TERMINAL (C_Lexique_template_5F_scanner::kToken_display) // $display$
, NONTERMINAL (3) // <variable>
, END_PRODUCTION
// At index 100 : <template_instruction>, in file 'template_parser.ggs', line 1179
, TERMINAL (C_Lexique_template_5F_scanner::kToken_sort) // $sort$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_by) // $by$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (2) // <sorting_order>
, NONTERMINAL (38) // <select_template_5F_parser_25>
, END_PRODUCTION
// At index 107 : <sorting_order>, in file 'template_parser.ggs', line 1168
, NONTERMINAL (37) // <select_template_5F_parser_24>
, END_PRODUCTION
// At index 109 : <variable>, in file 'template_parser.ggs', line 1221
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (39) // <select_template_5F_parser_26>
, NONTERMINAL (40) // <select_template_5F_parser_27>
, END_PRODUCTION
// At index 113 : <variable_or_here>, in file 'template_parser.ggs', line 1065
, NONTERMINAL (36) // <select_template_5F_parser_23>
, END_PRODUCTION
// At index 115 : <expression>, in file 'template_expression_parser.ggs', line 96
, NONTERMINAL (8) // <relation_term>
, NONTERMINAL (42) // <select_template_5F_expression_5F_parser_0>
, END_PRODUCTION
// At index 118 : <template_instruction_list>, in file 'template_parser.ggs', line 572
, NONTERMINAL (25) // <select_template_5F_parser_12>
, END_PRODUCTION
// At index 120 : <template_file_name>, in file 'template_parser.ggs', line 198
, NONTERMINAL (14) // <select_template_5F_parser_1>
, END_PRODUCTION
// At index 122 : <relation_term>, in file 'template_expression_parser.ggs', line 158
, NONTERMINAL (9) // <relation_factor>
, NONTERMINAL (43) // <select_template_5F_expression_5F_parser_1>
, END_PRODUCTION
// At index 125 : <relation_factor>, in file 'template_expression_parser.ggs', line 201
, NONTERMINAL (10) // <simple_expression>
, NONTERMINAL (44) // <select_template_5F_expression_5F_parser_2>
, END_PRODUCTION
// At index 128 : <simple_expression>, in file 'template_expression_parser.ggs', line 407
, NONTERMINAL (11) // <term>
, NONTERMINAL (45) // <select_template_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 131 : <term>, in file 'template_expression_parser.ggs', line 510
, NONTERMINAL (12) // <factor>
, NONTERMINAL (46) // <select_template_5F_expression_5F_parser_4>
, END_PRODUCTION
// At index 134 : <factor>, in file 'template_expression_parser.ggs', line 582
, TERMINAL (C_Lexique_template_5F_scanner::kToken__28_) // $($
, NONTERMINAL (5) // <expression>
, TERMINAL (C_Lexique_template_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 138 : <factor>, in file 'template_expression_parser.ggs', line 606
, TERMINAL (C_Lexique_template_5F_scanner::kToken_not) // $not$
, NONTERMINAL (12) // <factor>
, END_PRODUCTION
// At index 141 : <factor>, in file 'template_expression_parser.ggs', line 633
, TERMINAL (C_Lexique_template_5F_scanner::kToken__7E_) // $~$
, NONTERMINAL (12) // <factor>
, END_PRODUCTION
// At index 144 : <factor>, in file 'template_expression_parser.ggs', line 660
, TERMINAL (C_Lexique_template_5F_scanner::kToken__2D_) // $-$
, NONTERMINAL (12) // <factor>
, END_PRODUCTION
// At index 147 : <factor>, in file 'template_expression_parser.ggs', line 687
, TERMINAL (C_Lexique_template_5F_scanner::kToken__2B_) // $+$
, NONTERMINAL (12) // <factor>
, END_PRODUCTION
// At index 150 : <factor>, in file 'template_expression_parser.ggs', line 714
, TERMINAL (C_Lexique_template_5F_scanner::kToken_yes) // $yes$
, END_PRODUCTION
// At index 152 : <factor>, in file 'template_expression_parser.ggs', line 732
, TERMINAL (C_Lexique_template_5F_scanner::kToken_no) // $no$
, END_PRODUCTION
// At index 154 : <factor>, in file 'template_expression_parser.ggs', line 750
, TERMINAL (C_Lexique_template_5F_scanner::kToken_signed_5F_literal_5F_integer_36__34_) // $signed_literal_integer64$
, END_PRODUCTION
// At index 156 : <factor>, in file 'template_expression_parser.ggs', line 769
, TERMINAL (C_Lexique_template_5F_scanner::kToken_string) // $string$
, END_PRODUCTION
// At index 158 : <factor>, in file 'template_expression_parser.ggs', line 788
, TERMINAL (C_Lexique_template_5F_scanner::kToken__5B_) // $[$
, NONTERMINAL (5) // <expression>
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (47) // <select_template_5F_expression_5F_parser_5>
, TERMINAL (C_Lexique_template_5F_scanner::kToken__5D_) // $]$
, END_PRODUCTION
// At index 164 : <factor>, in file 'template_expression_parser.ggs', line 843
, NONTERMINAL (3) // <variable>
, NONTERMINAL (49) // <select_template_5F_expression_5F_parser_7>
, END_PRODUCTION
// At index 167 : <factor>, in file 'template_expression_parser.ggs', line 976
, TERMINAL (C_Lexique_template_5F_scanner::kToken_exists) // $exists$
, NONTERMINAL (3) // <variable>
, NONTERMINAL (51) // <select_template_5F_expression_5F_parser_9>
, END_PRODUCTION
// At index 171 : <factor>, in file 'template_expression_parser.ggs', line 1024
, TERMINAL (C_Lexique_template_5F_scanner::kToken_typeof) // $typeof$
, NONTERMINAL (3) // <variable>
, END_PRODUCTION
// At index 174 : <factor>, in file 'template_expression_parser.ggs', line 1042
, NONTERMINAL (52) // <select_template_5F_expression_5F_parser_10>
, END_PRODUCTION
// At index 176 : <factor>, in file 'template_expression_parser.ggs', line 1061
, TERMINAL (C_Lexique_template_5F_scanner::kToken__40_) // $@$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 179 : <factor>, in file 'template_expression_parser.ggs', line 1075
, TERMINAL (C_Lexique_template_5F_scanner::kToken_emptylist) // $emptylist$
, END_PRODUCTION
// At index 181 : <factor>, in file 'template_expression_parser.ggs', line 1089
, TERMINAL (C_Lexique_template_5F_scanner::kToken_emptymap) // $emptymap$
, END_PRODUCTION
// At index 183 : <factor>, in file 'template_expression_parser.ggs', line 1103
, TERMINAL (C_Lexique_template_5F_scanner::kToken_mapof) // $mapof$
, NONTERMINAL (5) // <expression>
, TERMINAL (C_Lexique_template_5F_scanner::kToken_by) // $by$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 188 : <factor>, in file 'template_expression_parser.ggs', line 1147
, TERMINAL (C_Lexique_template_5F_scanner::kToken_listof) // $listof$
, NONTERMINAL (3) // <variable>
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 191 : <select_template_5F_parser_0>, in file 'template_parser.ggs', line 145
, TERMINAL (C_Lexique_template_5F_scanner::kToken_executable) // $executable$
, END_PRODUCTION
// At index 193 : <select_template_5F_parser_0>, in file 'template_parser.ggs', line 145
, END_PRODUCTION
// At index 194 : <select_template_5F_parser_1>, in file 'template_parser.ggs', line 204
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 196 : <select_template_5F_parser_1>, in file 'template_parser.ggs', line 204
, TERMINAL (C_Lexique_template_5F_scanner::kToken_from) // $from$
, NONTERMINAL (5) // <expression>
, END_PRODUCTION
// At index 199 : <select_template_5F_parser_2>, in file 'template_parser.ggs', line 230
, TERMINAL (C_Lexique_template_5F_scanner::kToken_if) // $if$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_exists) // $exists$
, NONTERMINAL (7) // <template_file_name>
, NONTERMINAL (16) // <select_template_5F_parser_3>
, NONTERMINAL (17) // <select_template_5F_parser_4>
, END_PRODUCTION
// At index 205 : <select_template_5F_parser_2>, in file 'template_parser.ggs', line 230
, NONTERMINAL (7) // <template_file_name>
, NONTERMINAL (18) // <select_template_5F_parser_5>
, END_PRODUCTION
// At index 208 : <select_template_5F_parser_3>, in file 'template_parser.ggs', line 235
, TERMINAL (C_Lexique_template_5F_scanner::kToken_in) // $in$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 211 : <select_template_5F_parser_3>, in file 'template_parser.ggs', line 235
, END_PRODUCTION
// At index 212 : <select_template_5F_parser_4>, in file 'template_parser.ggs', line 250
, TERMINAL (C_Lexique_template_5F_scanner::kToken_or) // $or$
, NONTERMINAL (6) // <template_instruction_list>
, TERMINAL (C_Lexique_template_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_template) // $template$
, END_PRODUCTION
// At index 217 : <select_template_5F_parser_4>, in file 'template_parser.ggs', line 250
, END_PRODUCTION
// At index 218 : <select_template_5F_parser_5>, in file 'template_parser.ggs', line 273
, TERMINAL (C_Lexique_template_5F_scanner::kToken_in) // $in$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 221 : <select_template_5F_parser_5>, in file 'template_parser.ggs', line 273
, END_PRODUCTION
// At index 222 : <select_template_5F_parser_6>, in file 'template_parser.ggs', line 340
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (20) // <select_template_5F_parser_7>
, END_PRODUCTION
// At index 225 : <select_template_5F_parser_6>, in file 'template_parser.ggs', line 340
, END_PRODUCTION
// At index 226 : <select_template_5F_parser_7>, in file 'template_parser.ggs', line 344
, END_PRODUCTION
// At index 227 : <select_template_5F_parser_7>, in file 'template_parser.ggs', line 344
, TERMINAL (C_Lexique_template_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (20) // <select_template_5F_parser_7>
, END_PRODUCTION
// At index 231 : <select_template_5F_parser_8>, in file 'template_parser.ggs', line 373
, NONTERMINAL (5) // <expression>
, NONTERMINAL (22) // <select_template_5F_parser_9>
, END_PRODUCTION
// At index 234 : <select_template_5F_parser_8>, in file 'template_parser.ggs', line 373
, END_PRODUCTION
// At index 235 : <select_template_5F_parser_9>, in file 'template_parser.ggs', line 384
, END_PRODUCTION
// At index 236 : <select_template_5F_parser_9>, in file 'template_parser.ggs', line 384
, TERMINAL (C_Lexique_template_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (5) // <expression>
, NONTERMINAL (22) // <select_template_5F_parser_9>
, END_PRODUCTION
// At index 240 : <select_template_5F_parser_10>, in file 'template_parser.ggs', line 503
, END_PRODUCTION
// At index 241 : <select_template_5F_parser_10>, in file 'template_parser.ggs', line 503
, TERMINAL (C_Lexique_template_5F_scanner::kToken_elsif) // $elsif$
, NONTERMINAL (5) // <expression>
, TERMINAL (C_Lexique_template_5F_scanner::kToken_then) // $then$
, NONTERMINAL (6) // <template_instruction_list>
, NONTERMINAL (23) // <select_template_5F_parser_10>
, END_PRODUCTION
// At index 247 : <select_template_5F_parser_11>, in file 'template_parser.ggs', line 544
, END_PRODUCTION
// At index 248 : <select_template_5F_parser_11>, in file 'template_parser.ggs', line 544
, TERMINAL (C_Lexique_template_5F_scanner::kToken_else) // $else$
, NONTERMINAL (6) // <template_instruction_list>
, END_PRODUCTION
// At index 251 : <select_template_5F_parser_12>, in file 'template_parser.ggs', line 583
, END_PRODUCTION
// At index 252 : <select_template_5F_parser_12>, in file 'template_parser.ggs', line 583
, NONTERMINAL (1) // <template_instruction>
, NONTERMINAL (25) // <select_template_5F_parser_12>
, END_PRODUCTION
// At index 255 : <select_template_5F_parser_13>, in file 'template_parser.ggs', line 654
, END_PRODUCTION
// At index 256 : <select_template_5F_parser_13>, in file 'template_parser.ggs', line 654
, TERMINAL (C_Lexique_template_5F_scanner::kToken_prefixedby) // $prefixedby$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 259 : <select_template_5F_parser_14>, in file 'template_parser.ggs', line 663
, END_PRODUCTION
// At index 260 : <select_template_5F_parser_14>, in file 'template_parser.ggs', line 663
, TERMINAL (C_Lexique_template_5F_scanner::kToken_before) // $before$
, NONTERMINAL (6) // <template_instruction_list>
, END_PRODUCTION
// At index 263 : <select_template_5F_parser_15>, in file 'template_parser.ggs', line 711
, END_PRODUCTION
// At index 264 : <select_template_5F_parser_15>, in file 'template_parser.ggs', line 711
, TERMINAL (C_Lexique_template_5F_scanner::kToken_between) // $between$
, NONTERMINAL (6) // <template_instruction_list>
, END_PRODUCTION
// At index 267 : <select_template_5F_parser_16>, in file 'template_parser.ggs', line 732
, END_PRODUCTION
// At index 268 : <select_template_5F_parser_16>, in file 'template_parser.ggs', line 732
, TERMINAL (C_Lexique_template_5F_scanner::kToken_after) // $after$
, NONTERMINAL (6) // <template_instruction_list>
, END_PRODUCTION
// At index 271 : <select_template_5F_parser_17>, in file 'template_parser.ggs', line 772
, END_PRODUCTION
// At index 272 : <select_template_5F_parser_17>, in file 'template_parser.ggs', line 772
, TERMINAL (C_Lexique_template_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (5) // <expression>
, NONTERMINAL (30) // <select_template_5F_parser_17>
, END_PRODUCTION
// At index 276 : <select_template_5F_parser_18>, in file 'template_parser.ggs', line 819
, END_PRODUCTION
// At index 277 : <select_template_5F_parser_18>, in file 'template_parser.ggs', line 819
, TERMINAL (C_Lexique_template_5F_scanner::kToken_between) // $between$
, NONTERMINAL (6) // <template_instruction_list>
, END_PRODUCTION
// At index 280 : <select_template_5F_parser_19>, in file 'template_parser.ggs', line 884
, END_PRODUCTION
// At index 281 : <select_template_5F_parser_19>, in file 'template_parser.ggs', line 884
, TERMINAL (C_Lexique_template_5F_scanner::kToken_before) // $before$
, NONTERMINAL (6) // <template_instruction_list>
, END_PRODUCTION
// At index 284 : <select_template_5F_parser_20>, in file 'template_parser.ggs', line 932
, END_PRODUCTION
// At index 285 : <select_template_5F_parser_20>, in file 'template_parser.ggs', line 932
, TERMINAL (C_Lexique_template_5F_scanner::kToken_between) // $between$
, NONTERMINAL (6) // <template_instruction_list>
, END_PRODUCTION
// At index 288 : <select_template_5F_parser_21>, in file 'template_parser.ggs', line 953
, END_PRODUCTION
// At index 289 : <select_template_5F_parser_21>, in file 'template_parser.ggs', line 953
, TERMINAL (C_Lexique_template_5F_scanner::kToken_after) // $after$
, NONTERMINAL (6) // <template_instruction_list>
, END_PRODUCTION
// At index 292 : <select_template_5F_parser_22>, in file 'template_parser.ggs', line 1000
, TERMINAL (C_Lexique_template_5F_scanner::kToken__3A__3D_) // $:=$
, NONTERMINAL (5) // <expression>
, END_PRODUCTION
// At index 295 : <select_template_5F_parser_22>, in file 'template_parser.ggs', line 1000
, TERMINAL (C_Lexique_template_5F_scanner::kToken__2B__3D_) // $+=$
, NONTERMINAL (5) // <expression>
, END_PRODUCTION
// At index 298 : <select_template_5F_parser_22>, in file 'template_parser.ggs', line 1000
, END_PRODUCTION
// At index 299 : <select_template_5F_parser_23>, in file 'template_parser.ggs', line 1071
, TERMINAL (C_Lexique_template_5F_scanner::kToken_here) // $here$
, END_PRODUCTION
// At index 301 : <select_template_5F_parser_23>, in file 'template_parser.ggs', line 1071
, NONTERMINAL (3) // <variable>
, END_PRODUCTION
// At index 303 : <select_template_5F_parser_24>, in file 'template_parser.ggs', line 1170
, TERMINAL (C_Lexique_template_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 305 : <select_template_5F_parser_24>, in file 'template_parser.ggs', line 1170
, TERMINAL (C_Lexique_template_5F_scanner::kToken__3C_) // $<$
, END_PRODUCTION
// At index 307 : <select_template_5F_parser_25>, in file 'template_parser.ggs', line 1196
, END_PRODUCTION
// At index 308 : <select_template_5F_parser_25>, in file 'template_parser.ggs', line 1196
, TERMINAL (C_Lexique_template_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (2) // <sorting_order>
, NONTERMINAL (38) // <select_template_5F_parser_25>
, END_PRODUCTION
// At index 313 : <select_template_5F_parser_26>, in file 'template_parser.ggs', line 1231
, TERMINAL (C_Lexique_template_5F_scanner::kToken__5B_) // $[$
, NONTERMINAL (5) // <expression>
, TERMINAL (C_Lexique_template_5F_scanner::kToken__5D_) // $]$
, END_PRODUCTION
// At index 317 : <select_template_5F_parser_26>, in file 'template_parser.ggs', line 1231
, END_PRODUCTION
// At index 318 : <select_template_5F_parser_27>, in file 'template_parser.ggs', line 1247
, END_PRODUCTION
// At index 319 : <select_template_5F_parser_27>, in file 'template_parser.ggs', line 1247
, TERMINAL (C_Lexique_template_5F_scanner::kToken__3A__3A_) // $::$
, TERMINAL (C_Lexique_template_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (41) // <select_template_5F_parser_28>
, NONTERMINAL (40) // <select_template_5F_parser_27>
, END_PRODUCTION
// At index 324 : <select_template_5F_parser_28>, in file 'template_parser.ggs', line 1252
, TERMINAL (C_Lexique_template_5F_scanner::kToken__5B_) // $[$
, NONTERMINAL (5) // <expression>
, TERMINAL (C_Lexique_template_5F_scanner::kToken__5D_) // $]$
, END_PRODUCTION
// At index 328 : <select_template_5F_parser_28>, in file 'template_parser.ggs', line 1252
, END_PRODUCTION
// At index 329 : <select_template_5F_expression_5F_parser_0>, in file 'template_expression_parser.ggs', line 110
, END_PRODUCTION
// At index 330 : <select_template_5F_expression_5F_parser_0>, in file 'template_expression_parser.ggs', line 110
, TERMINAL (C_Lexique_template_5F_scanner::kToken__7C_) // $|$
, NONTERMINAL (8) // <relation_term>
, NONTERMINAL (42) // <select_template_5F_expression_5F_parser_0>
, END_PRODUCTION
// At index 334 : <select_template_5F_expression_5F_parser_0>, in file 'template_expression_parser.ggs', line 110
, TERMINAL (C_Lexique_template_5F_scanner::kToken__5E_) // $^$
, NONTERMINAL (8) // <relation_term>
, NONTERMINAL (42) // <select_template_5F_expression_5F_parser_0>
, END_PRODUCTION
// At index 338 : <select_template_5F_expression_5F_parser_1>, in file 'template_expression_parser.ggs', line 172
, END_PRODUCTION
// At index 339 : <select_template_5F_expression_5F_parser_1>, in file 'template_expression_parser.ggs', line 172
, TERMINAL (C_Lexique_template_5F_scanner::kToken__26_) // $&$
, NONTERMINAL (9) // <relation_factor>
, NONTERMINAL (43) // <select_template_5F_expression_5F_parser_1>
, END_PRODUCTION
// At index 343 : <select_template_5F_expression_5F_parser_2>, in file 'template_expression_parser.ggs', line 215
, END_PRODUCTION
// At index 344 : <select_template_5F_expression_5F_parser_2>, in file 'template_expression_parser.ggs', line 215
, TERMINAL (C_Lexique_template_5F_scanner::kToken__3D__3D_) // $==$
, NONTERMINAL (10) // <simple_expression>
, END_PRODUCTION
// At index 347 : <select_template_5F_expression_5F_parser_2>, in file 'template_expression_parser.ggs', line 215
, TERMINAL (C_Lexique_template_5F_scanner::kToken__21__3D_) // $!=$
, NONTERMINAL (10) // <simple_expression>
, END_PRODUCTION
// At index 350 : <select_template_5F_expression_5F_parser_2>, in file 'template_expression_parser.ggs', line 215
, TERMINAL (C_Lexique_template_5F_scanner::kToken__3C__3D_) // $<=$
, NONTERMINAL (10) // <simple_expression>
, END_PRODUCTION
// At index 353 : <select_template_5F_expression_5F_parser_2>, in file 'template_expression_parser.ggs', line 215
, TERMINAL (C_Lexique_template_5F_scanner::kToken__3E__3D_) // $>=$
, NONTERMINAL (10) // <simple_expression>
, END_PRODUCTION
// At index 356 : <select_template_5F_expression_5F_parser_2>, in file 'template_expression_parser.ggs', line 215
, TERMINAL (C_Lexique_template_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (10) // <simple_expression>
, END_PRODUCTION
// At index 359 : <select_template_5F_expression_5F_parser_2>, in file 'template_expression_parser.ggs', line 215
, TERMINAL (C_Lexique_template_5F_scanner::kToken__3C_) // $<$
, NONTERMINAL (10) // <simple_expression>
, END_PRODUCTION
// At index 362 : <select_template_5F_expression_5F_parser_3>, in file 'template_expression_parser.ggs', line 421
, END_PRODUCTION
// At index 363 : <select_template_5F_expression_5F_parser_3>, in file 'template_expression_parser.ggs', line 421
, TERMINAL (C_Lexique_template_5F_scanner::kToken__3C__3C_) // $<<$
, NONTERMINAL (11) // <term>
, NONTERMINAL (45) // <select_template_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 367 : <select_template_5F_expression_5F_parser_3>, in file 'template_expression_parser.ggs', line 421
, TERMINAL (C_Lexique_template_5F_scanner::kToken__3E__3E_) // $>>$
, NONTERMINAL (11) // <term>
, NONTERMINAL (45) // <select_template_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 371 : <select_template_5F_expression_5F_parser_3>, in file 'template_expression_parser.ggs', line 421
, TERMINAL (C_Lexique_template_5F_scanner::kToken__2B_) // $+$
, NONTERMINAL (11) // <term>
, NONTERMINAL (45) // <select_template_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 375 : <select_template_5F_expression_5F_parser_3>, in file 'template_expression_parser.ggs', line 421
, TERMINAL (C_Lexique_template_5F_scanner::kToken__2E_) // $.$
, NONTERMINAL (11) // <term>
, NONTERMINAL (45) // <select_template_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 379 : <select_template_5F_expression_5F_parser_3>, in file 'template_expression_parser.ggs', line 421
, TERMINAL (C_Lexique_template_5F_scanner::kToken__2D_) // $-$
, NONTERMINAL (11) // <term>
, NONTERMINAL (45) // <select_template_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 383 : <select_template_5F_expression_5F_parser_4>, in file 'template_expression_parser.ggs', line 524
, END_PRODUCTION
// At index 384 : <select_template_5F_expression_5F_parser_4>, in file 'template_expression_parser.ggs', line 524
, TERMINAL (C_Lexique_template_5F_scanner::kToken__2A_) // $*$
, NONTERMINAL (12) // <factor>
, NONTERMINAL (46) // <select_template_5F_expression_5F_parser_4>
, END_PRODUCTION
// At index 388 : <select_template_5F_expression_5F_parser_4>, in file 'template_expression_parser.ggs', line 524
, TERMINAL (C_Lexique_template_5F_scanner::kToken__2F_) // $/$
, NONTERMINAL (12) // <factor>
, NONTERMINAL (46) // <select_template_5F_expression_5F_parser_4>
, END_PRODUCTION
// At index 392 : <select_template_5F_expression_5F_parser_4>, in file 'template_expression_parser.ggs', line 524
, TERMINAL (C_Lexique_template_5F_scanner::kToken_mod) // $mod$
, NONTERMINAL (12) // <factor>
, NONTERMINAL (46) // <select_template_5F_expression_5F_parser_4>
, END_PRODUCTION
// At index 396 : <select_template_5F_expression_5F_parser_5>, in file 'template_expression_parser.ggs', line 810
, END_PRODUCTION
// At index 397 : <select_template_5F_expression_5F_parser_5>, in file 'template_expression_parser.ggs', line 810
, TERMINAL (C_Lexique_template_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (5) // <expression>
, NONTERMINAL (48) // <select_template_5F_expression_5F_parser_6>
, END_PRODUCTION
// At index 401 : <select_template_5F_expression_5F_parser_6>, in file 'template_expression_parser.ggs', line 813
, END_PRODUCTION
// At index 402 : <select_template_5F_expression_5F_parser_6>, in file 'template_expression_parser.ggs', line 813
, TERMINAL (C_Lexique_template_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (5) // <expression>
, NONTERMINAL (48) // <select_template_5F_expression_5F_parser_6>
, END_PRODUCTION
// At index 406 : <select_template_5F_expression_5F_parser_7>, in file 'template_expression_parser.ggs', line 852
, END_PRODUCTION
// At index 407 : <select_template_5F_expression_5F_parser_7>, in file 'template_expression_parser.ggs', line 852
, TERMINAL (C_Lexique_template_5F_scanner::kToken__28_) // $($
, NONTERMINAL (5) // <expression>
, NONTERMINAL (50) // <select_template_5F_expression_5F_parser_8>
, TERMINAL (C_Lexique_template_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 412 : <select_template_5F_expression_5F_parser_8>, in file 'template_expression_parser.ggs', line 861
, END_PRODUCTION
// At index 413 : <select_template_5F_expression_5F_parser_8>, in file 'template_expression_parser.ggs', line 861
, TERMINAL (C_Lexique_template_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (5) // <expression>
, NONTERMINAL (50) // <select_template_5F_expression_5F_parser_8>
, END_PRODUCTION
// At index 417 : <select_template_5F_expression_5F_parser_9>, in file 'template_expression_parser.ggs', line 992
, TERMINAL (C_Lexique_template_5F_scanner::kToken_default) // $default$
, TERMINAL (C_Lexique_template_5F_scanner::kToken__28_) // $($
, NONTERMINAL (5) // <expression>
, TERMINAL (C_Lexique_template_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 422 : <select_template_5F_expression_5F_parser_9>, in file 'template_expression_parser.ggs', line 992
, END_PRODUCTION
// At index 423 : <select_template_5F_expression_5F_parser_10>, in file 'template_expression_parser.ggs', line 1049
, TERMINAL (C_Lexique_template_5F_scanner::kToken_true) // $true$
, END_PRODUCTION
// At index 425 : <select_template_5F_expression_5F_parser_10>, in file 'template_expression_parser.ggs', line 1049
, TERMINAL (C_Lexique_template_5F_scanner::kToken_false) // $false$
, END_PRODUCTION
// At index 427 : <>, in file '.ggs', line 0
, NONTERMINAL (0) // <goil_template_start_symbol>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          P R O D U C T I O N    N A M E S                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_template_grammar [140] = {
 {"<goil_template_start_symbol>", "template_parser", 0}, // at index 0
 {"<template_instruction>", "template_parser", 2}, // at index 1
 {"<template_instruction>", "template_parser", 5}, // at index 2
 {"<template_instruction>", "template_parser", 14}, // at index 3
 {"<template_instruction>", "template_parser", 17}, // at index 4
 {"<template_instruction>", "template_parser", 20}, // at index 5
 {"<template_instruction>", "template_parser", 27}, // at index 6
 {"<template_instruction>", "template_parser", 33}, // at index 7
 {"<template_instruction>", "template_parser", 36}, // at index 8
 {"<template_instruction>", "template_parser", 45}, // at index 9
 {"<template_instruction>", "template_parser", 58}, // at index 10
 {"<template_instruction>", "template_parser", 69}, // at index 11
 {"<template_instruction>", "template_parser", 83}, // at index 12
 {"<template_instruction>", "template_parser", 87}, // at index 13
 {"<template_instruction>", "template_parser", 92}, // at index 14
 {"<template_instruction>", "template_parser", 97}, // at index 15
 {"<template_instruction>", "template_parser", 100}, // at index 16
 {"<sorting_order>", "template_parser", 107}, // at index 17
 {"<variable>", "template_parser", 109}, // at index 18
 {"<variable_or_here>", "template_parser", 113}, // at index 19
 {"<expression>", "template_expression_parser", 115}, // at index 20
 {"<template_instruction_list>", "template_parser", 118}, // at index 21
 {"<template_file_name>", "template_parser", 120}, // at index 22
 {"<relation_term>", "template_expression_parser", 122}, // at index 23
 {"<relation_factor>", "template_expression_parser", 125}, // at index 24
 {"<simple_expression>", "template_expression_parser", 128}, // at index 25
 {"<term>", "template_expression_parser", 131}, // at index 26
 {"<factor>", "template_expression_parser", 134}, // at index 27
 {"<factor>", "template_expression_parser", 138}, // at index 28
 {"<factor>", "template_expression_parser", 141}, // at index 29
 {"<factor>", "template_expression_parser", 144}, // at index 30
 {"<factor>", "template_expression_parser", 147}, // at index 31
 {"<factor>", "template_expression_parser", 150}, // at index 32
 {"<factor>", "template_expression_parser", 152}, // at index 33
 {"<factor>", "template_expression_parser", 154}, // at index 34
 {"<factor>", "template_expression_parser", 156}, // at index 35
 {"<factor>", "template_expression_parser", 158}, // at index 36
 {"<factor>", "template_expression_parser", 164}, // at index 37
 {"<factor>", "template_expression_parser", 167}, // at index 38
 {"<factor>", "template_expression_parser", 171}, // at index 39
 {"<factor>", "template_expression_parser", 174}, // at index 40
 {"<factor>", "template_expression_parser", 176}, // at index 41
 {"<factor>", "template_expression_parser", 179}, // at index 42
 {"<factor>", "template_expression_parser", 181}, // at index 43
 {"<factor>", "template_expression_parser", 183}, // at index 44
 {"<factor>", "template_expression_parser", 188}, // at index 45
 {"<select_template_5F_parser_0>", "template_parser", 191}, // at index 46
 {"<select_template_5F_parser_0>", "template_parser", 193}, // at index 47
 {"<select_template_5F_parser_1>", "template_parser", 194}, // at index 48
 {"<select_template_5F_parser_1>", "template_parser", 196}, // at index 49
 {"<select_template_5F_parser_2>", "template_parser", 199}, // at index 50
 {"<select_template_5F_parser_2>", "template_parser", 205}, // at index 51
 {"<select_template_5F_parser_3>", "template_parser", 208}, // at index 52
 {"<select_template_5F_parser_3>", "template_parser", 211}, // at index 53
 {"<select_template_5F_parser_4>", "template_parser", 212}, // at index 54
 {"<select_template_5F_parser_4>", "template_parser", 217}, // at index 55
 {"<select_template_5F_parser_5>", "template_parser", 218}, // at index 56
 {"<select_template_5F_parser_5>", "template_parser", 221}, // at index 57
 {"<select_template_5F_parser_6>", "template_parser", 222}, // at index 58
 {"<select_template_5F_parser_6>", "template_parser", 225}, // at index 59
 {"<select_template_5F_parser_7>", "template_parser", 226}, // at index 60
 {"<select_template_5F_parser_7>", "template_parser", 227}, // at index 61
 {"<select_template_5F_parser_8>", "template_parser", 231}, // at index 62
 {"<select_template_5F_parser_8>", "template_parser", 234}, // at index 63
 {"<select_template_5F_parser_9>", "template_parser", 235}, // at index 64
 {"<select_template_5F_parser_9>", "template_parser", 236}, // at index 65
 {"<select_template_5F_parser_10>", "template_parser", 240}, // at index 66
 {"<select_template_5F_parser_10>", "template_parser", 241}, // at index 67
 {"<select_template_5F_parser_11>", "template_parser", 247}, // at index 68
 {"<select_template_5F_parser_11>", "template_parser", 248}, // at index 69
 {"<select_template_5F_parser_12>", "template_parser", 251}, // at index 70
 {"<select_template_5F_parser_12>", "template_parser", 252}, // at index 71
 {"<select_template_5F_parser_13>", "template_parser", 255}, // at index 72
 {"<select_template_5F_parser_13>", "template_parser", 256}, // at index 73
 {"<select_template_5F_parser_14>", "template_parser", 259}, // at index 74
 {"<select_template_5F_parser_14>", "template_parser", 260}, // at index 75
 {"<select_template_5F_parser_15>", "template_parser", 263}, // at index 76
 {"<select_template_5F_parser_15>", "template_parser", 264}, // at index 77
 {"<select_template_5F_parser_16>", "template_parser", 267}, // at index 78
 {"<select_template_5F_parser_16>", "template_parser", 268}, // at index 79
 {"<select_template_5F_parser_17>", "template_parser", 271}, // at index 80
 {"<select_template_5F_parser_17>", "template_parser", 272}, // at index 81
 {"<select_template_5F_parser_18>", "template_parser", 276}, // at index 82
 {"<select_template_5F_parser_18>", "template_parser", 277}, // at index 83
 {"<select_template_5F_parser_19>", "template_parser", 280}, // at index 84
 {"<select_template_5F_parser_19>", "template_parser", 281}, // at index 85
 {"<select_template_5F_parser_20>", "template_parser", 284}, // at index 86
 {"<select_template_5F_parser_20>", "template_parser", 285}, // at index 87
 {"<select_template_5F_parser_21>", "template_parser", 288}, // at index 88
 {"<select_template_5F_parser_21>", "template_parser", 289}, // at index 89
 {"<select_template_5F_parser_22>", "template_parser", 292}, // at index 90
 {"<select_template_5F_parser_22>", "template_parser", 295}, // at index 91
 {"<select_template_5F_parser_22>", "template_parser", 298}, // at index 92
 {"<select_template_5F_parser_23>", "template_parser", 299}, // at index 93
 {"<select_template_5F_parser_23>", "template_parser", 301}, // at index 94
 {"<select_template_5F_parser_24>", "template_parser", 303}, // at index 95
 {"<select_template_5F_parser_24>", "template_parser", 305}, // at index 96
 {"<select_template_5F_parser_25>", "template_parser", 307}, // at index 97
 {"<select_template_5F_parser_25>", "template_parser", 308}, // at index 98
 {"<select_template_5F_parser_26>", "template_parser", 313}, // at index 99
 {"<select_template_5F_parser_26>", "template_parser", 317}, // at index 100
 {"<select_template_5F_parser_27>", "template_parser", 318}, // at index 101
 {"<select_template_5F_parser_27>", "template_parser", 319}, // at index 102
 {"<select_template_5F_parser_28>", "template_parser", 324}, // at index 103
 {"<select_template_5F_parser_28>", "template_parser", 328}, // at index 104
 {"<select_template_5F_expression_5F_parser_0>", "template_expression_parser", 329}, // at index 105
 {"<select_template_5F_expression_5F_parser_0>", "template_expression_parser", 330}, // at index 106
 {"<select_template_5F_expression_5F_parser_0>", "template_expression_parser", 334}, // at index 107
 {"<select_template_5F_expression_5F_parser_1>", "template_expression_parser", 338}, // at index 108
 {"<select_template_5F_expression_5F_parser_1>", "template_expression_parser", 339}, // at index 109
 {"<select_template_5F_expression_5F_parser_2>", "template_expression_parser", 343}, // at index 110
 {"<select_template_5F_expression_5F_parser_2>", "template_expression_parser", 344}, // at index 111
 {"<select_template_5F_expression_5F_parser_2>", "template_expression_parser", 347}, // at index 112
 {"<select_template_5F_expression_5F_parser_2>", "template_expression_parser", 350}, // at index 113
 {"<select_template_5F_expression_5F_parser_2>", "template_expression_parser", 353}, // at index 114
 {"<select_template_5F_expression_5F_parser_2>", "template_expression_parser", 356}, // at index 115
 {"<select_template_5F_expression_5F_parser_2>", "template_expression_parser", 359}, // at index 116
 {"<select_template_5F_expression_5F_parser_3>", "template_expression_parser", 362}, // at index 117
 {"<select_template_5F_expression_5F_parser_3>", "template_expression_parser", 363}, // at index 118
 {"<select_template_5F_expression_5F_parser_3>", "template_expression_parser", 367}, // at index 119
 {"<select_template_5F_expression_5F_parser_3>", "template_expression_parser", 371}, // at index 120
 {"<select_template_5F_expression_5F_parser_3>", "template_expression_parser", 375}, // at index 121
 {"<select_template_5F_expression_5F_parser_3>", "template_expression_parser", 379}, // at index 122
 {"<select_template_5F_expression_5F_parser_4>", "template_expression_parser", 383}, // at index 123
 {"<select_template_5F_expression_5F_parser_4>", "template_expression_parser", 384}, // at index 124
 {"<select_template_5F_expression_5F_parser_4>", "template_expression_parser", 388}, // at index 125
 {"<select_template_5F_expression_5F_parser_4>", "template_expression_parser", 392}, // at index 126
 {"<select_template_5F_expression_5F_parser_5>", "template_expression_parser", 396}, // at index 127
 {"<select_template_5F_expression_5F_parser_5>", "template_expression_parser", 397}, // at index 128
 {"<select_template_5F_expression_5F_parser_6>", "template_expression_parser", 401}, // at index 129
 {"<select_template_5F_expression_5F_parser_6>", "template_expression_parser", 402}, // at index 130
 {"<select_template_5F_expression_5F_parser_7>", "template_expression_parser", 406}, // at index 131
 {"<select_template_5F_expression_5F_parser_7>", "template_expression_parser", 407}, // at index 132
 {"<select_template_5F_expression_5F_parser_8>", "template_expression_parser", 412}, // at index 133
 {"<select_template_5F_expression_5F_parser_8>", "template_expression_parser", 413}, // at index 134
 {"<select_template_5F_expression_5F_parser_9>", "template_expression_parser", 417}, // at index 135
 {"<select_template_5F_expression_5F_parser_9>", "template_expression_parser", 422}, // at index 136
 {"<select_template_5F_expression_5F_parser_10>", "template_expression_parser", 423}, // at index 137
 {"<select_template_5F_expression_5F_parser_10>", "template_expression_parser", 425}, // at index 138
 {"<>", "", 427} // at index 139
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_template_grammar [140] = {
0, // index 0 : <goil_template_start_symbol>, in file 'template_parser.ggs', line 601
2, // index 1 : <template_instruction>, in file 'template_parser.ggs', line 87
5, // index 2 : <template_instruction>, in file 'template_parser.ggs', line 134
14, // index 3 : <template_instruction>, in file 'template_parser.ggs', line 220
17, // index 4 : <template_instruction>, in file 'template_parser.ggs', line 295
20, // index 5 : <template_instruction>, in file 'template_parser.ggs', line 328
27, // index 6 : <template_instruction>, in file 'template_parser.ggs', line 361
33, // index 7 : <template_instruction>, in file 'template_parser.ggs', line 428
36, // index 8 : <template_instruction>, in file 'template_parser.ggs', line 493
45, // index 9 : <template_instruction>, in file 'template_parser.ggs', line 621
58, // index 10 : <template_instruction>, in file 'template_parser.ggs', line 758
69, // index 11 : <template_instruction>, in file 'template_parser.ggs', line 848
83, // index 12 : <template_instruction>, in file 'template_parser.ggs', line 987
87, // index 13 : <template_instruction>, in file 'template_parser.ggs', line 1085
92, // index 14 : <template_instruction>, in file 'template_parser.ggs', line 1117
97, // index 15 : <template_instruction>, in file 'template_parser.ggs', line 1147
100, // index 16 : <template_instruction>, in file 'template_parser.ggs', line 1179
107, // index 17 : <sorting_order>, in file 'template_parser.ggs', line 1168
109, // index 18 : <variable>, in file 'template_parser.ggs', line 1221
113, // index 19 : <variable_or_here>, in file 'template_parser.ggs', line 1065
115, // index 20 : <expression>, in file 'template_expression_parser.ggs', line 96
118, // index 21 : <template_instruction_list>, in file 'template_parser.ggs', line 572
120, // index 22 : <template_file_name>, in file 'template_parser.ggs', line 198
122, // index 23 : <relation_term>, in file 'template_expression_parser.ggs', line 158
125, // index 24 : <relation_factor>, in file 'template_expression_parser.ggs', line 201
128, // index 25 : <simple_expression>, in file 'template_expression_parser.ggs', line 407
131, // index 26 : <term>, in file 'template_expression_parser.ggs', line 510
134, // index 27 : <factor>, in file 'template_expression_parser.ggs', line 582
138, // index 28 : <factor>, in file 'template_expression_parser.ggs', line 606
141, // index 29 : <factor>, in file 'template_expression_parser.ggs', line 633
144, // index 30 : <factor>, in file 'template_expression_parser.ggs', line 660
147, // index 31 : <factor>, in file 'template_expression_parser.ggs', line 687
150, // index 32 : <factor>, in file 'template_expression_parser.ggs', line 714
152, // index 33 : <factor>, in file 'template_expression_parser.ggs', line 732
154, // index 34 : <factor>, in file 'template_expression_parser.ggs', line 750
156, // index 35 : <factor>, in file 'template_expression_parser.ggs', line 769
158, // index 36 : <factor>, in file 'template_expression_parser.ggs', line 788
164, // index 37 : <factor>, in file 'template_expression_parser.ggs', line 843
167, // index 38 : <factor>, in file 'template_expression_parser.ggs', line 976
171, // index 39 : <factor>, in file 'template_expression_parser.ggs', line 1024
174, // index 40 : <factor>, in file 'template_expression_parser.ggs', line 1042
176, // index 41 : <factor>, in file 'template_expression_parser.ggs', line 1061
179, // index 42 : <factor>, in file 'template_expression_parser.ggs', line 1075
181, // index 43 : <factor>, in file 'template_expression_parser.ggs', line 1089
183, // index 44 : <factor>, in file 'template_expression_parser.ggs', line 1103
188, // index 45 : <factor>, in file 'template_expression_parser.ggs', line 1147
191, // index 46 : <select_template_5F_parser_0>, in file 'template_parser.ggs', line 145
193, // index 47 : <select_template_5F_parser_0>, in file 'template_parser.ggs', line 145
194, // index 48 : <select_template_5F_parser_1>, in file 'template_parser.ggs', line 204
196, // index 49 : <select_template_5F_parser_1>, in file 'template_parser.ggs', line 204
199, // index 50 : <select_template_5F_parser_2>, in file 'template_parser.ggs', line 230
205, // index 51 : <select_template_5F_parser_2>, in file 'template_parser.ggs', line 230
208, // index 52 : <select_template_5F_parser_3>, in file 'template_parser.ggs', line 235
211, // index 53 : <select_template_5F_parser_3>, in file 'template_parser.ggs', line 235
212, // index 54 : <select_template_5F_parser_4>, in file 'template_parser.ggs', line 250
217, // index 55 : <select_template_5F_parser_4>, in file 'template_parser.ggs', line 250
218, // index 56 : <select_template_5F_parser_5>, in file 'template_parser.ggs', line 273
221, // index 57 : <select_template_5F_parser_5>, in file 'template_parser.ggs', line 273
222, // index 58 : <select_template_5F_parser_6>, in file 'template_parser.ggs', line 340
225, // index 59 : <select_template_5F_parser_6>, in file 'template_parser.ggs', line 340
226, // index 60 : <select_template_5F_parser_7>, in file 'template_parser.ggs', line 344
227, // index 61 : <select_template_5F_parser_7>, in file 'template_parser.ggs', line 344
231, // index 62 : <select_template_5F_parser_8>, in file 'template_parser.ggs', line 373
234, // index 63 : <select_template_5F_parser_8>, in file 'template_parser.ggs', line 373
235, // index 64 : <select_template_5F_parser_9>, in file 'template_parser.ggs', line 384
236, // index 65 : <select_template_5F_parser_9>, in file 'template_parser.ggs', line 384
240, // index 66 : <select_template_5F_parser_10>, in file 'template_parser.ggs', line 503
241, // index 67 : <select_template_5F_parser_10>, in file 'template_parser.ggs', line 503
247, // index 68 : <select_template_5F_parser_11>, in file 'template_parser.ggs', line 544
248, // index 69 : <select_template_5F_parser_11>, in file 'template_parser.ggs', line 544
251, // index 70 : <select_template_5F_parser_12>, in file 'template_parser.ggs', line 583
252, // index 71 : <select_template_5F_parser_12>, in file 'template_parser.ggs', line 583
255, // index 72 : <select_template_5F_parser_13>, in file 'template_parser.ggs', line 654
256, // index 73 : <select_template_5F_parser_13>, in file 'template_parser.ggs', line 654
259, // index 74 : <select_template_5F_parser_14>, in file 'template_parser.ggs', line 663
260, // index 75 : <select_template_5F_parser_14>, in file 'template_parser.ggs', line 663
263, // index 76 : <select_template_5F_parser_15>, in file 'template_parser.ggs', line 711
264, // index 77 : <select_template_5F_parser_15>, in file 'template_parser.ggs', line 711
267, // index 78 : <select_template_5F_parser_16>, in file 'template_parser.ggs', line 732
268, // index 79 : <select_template_5F_parser_16>, in file 'template_parser.ggs', line 732
271, // index 80 : <select_template_5F_parser_17>, in file 'template_parser.ggs', line 772
272, // index 81 : <select_template_5F_parser_17>, in file 'template_parser.ggs', line 772
276, // index 82 : <select_template_5F_parser_18>, in file 'template_parser.ggs', line 819
277, // index 83 : <select_template_5F_parser_18>, in file 'template_parser.ggs', line 819
280, // index 84 : <select_template_5F_parser_19>, in file 'template_parser.ggs', line 884
281, // index 85 : <select_template_5F_parser_19>, in file 'template_parser.ggs', line 884
284, // index 86 : <select_template_5F_parser_20>, in file 'template_parser.ggs', line 932
285, // index 87 : <select_template_5F_parser_20>, in file 'template_parser.ggs', line 932
288, // index 88 : <select_template_5F_parser_21>, in file 'template_parser.ggs', line 953
289, // index 89 : <select_template_5F_parser_21>, in file 'template_parser.ggs', line 953
292, // index 90 : <select_template_5F_parser_22>, in file 'template_parser.ggs', line 1000
295, // index 91 : <select_template_5F_parser_22>, in file 'template_parser.ggs', line 1000
298, // index 92 : <select_template_5F_parser_22>, in file 'template_parser.ggs', line 1000
299, // index 93 : <select_template_5F_parser_23>, in file 'template_parser.ggs', line 1071
301, // index 94 : <select_template_5F_parser_23>, in file 'template_parser.ggs', line 1071
303, // index 95 : <select_template_5F_parser_24>, in file 'template_parser.ggs', line 1170
305, // index 96 : <select_template_5F_parser_24>, in file 'template_parser.ggs', line 1170
307, // index 97 : <select_template_5F_parser_25>, in file 'template_parser.ggs', line 1196
308, // index 98 : <select_template_5F_parser_25>, in file 'template_parser.ggs', line 1196
313, // index 99 : <select_template_5F_parser_26>, in file 'template_parser.ggs', line 1231
317, // index 100 : <select_template_5F_parser_26>, in file 'template_parser.ggs', line 1231
318, // index 101 : <select_template_5F_parser_27>, in file 'template_parser.ggs', line 1247
319, // index 102 : <select_template_5F_parser_27>, in file 'template_parser.ggs', line 1247
324, // index 103 : <select_template_5F_parser_28>, in file 'template_parser.ggs', line 1252
328, // index 104 : <select_template_5F_parser_28>, in file 'template_parser.ggs', line 1252
329, // index 105 : <select_template_5F_expression_5F_parser_0>, in file 'template_expression_parser.ggs', line 110
330, // index 106 : <select_template_5F_expression_5F_parser_0>, in file 'template_expression_parser.ggs', line 110
334, // index 107 : <select_template_5F_expression_5F_parser_0>, in file 'template_expression_parser.ggs', line 110
338, // index 108 : <select_template_5F_expression_5F_parser_1>, in file 'template_expression_parser.ggs', line 172
339, // index 109 : <select_template_5F_expression_5F_parser_1>, in file 'template_expression_parser.ggs', line 172
343, // index 110 : <select_template_5F_expression_5F_parser_2>, in file 'template_expression_parser.ggs', line 215
344, // index 111 : <select_template_5F_expression_5F_parser_2>, in file 'template_expression_parser.ggs', line 215
347, // index 112 : <select_template_5F_expression_5F_parser_2>, in file 'template_expression_parser.ggs', line 215
350, // index 113 : <select_template_5F_expression_5F_parser_2>, in file 'template_expression_parser.ggs', line 215
353, // index 114 : <select_template_5F_expression_5F_parser_2>, in file 'template_expression_parser.ggs', line 215
356, // index 115 : <select_template_5F_expression_5F_parser_2>, in file 'template_expression_parser.ggs', line 215
359, // index 116 : <select_template_5F_expression_5F_parser_2>, in file 'template_expression_parser.ggs', line 215
362, // index 117 : <select_template_5F_expression_5F_parser_3>, in file 'template_expression_parser.ggs', line 421
363, // index 118 : <select_template_5F_expression_5F_parser_3>, in file 'template_expression_parser.ggs', line 421
367, // index 119 : <select_template_5F_expression_5F_parser_3>, in file 'template_expression_parser.ggs', line 421
371, // index 120 : <select_template_5F_expression_5F_parser_3>, in file 'template_expression_parser.ggs', line 421
375, // index 121 : <select_template_5F_expression_5F_parser_3>, in file 'template_expression_parser.ggs', line 421
379, // index 122 : <select_template_5F_expression_5F_parser_3>, in file 'template_expression_parser.ggs', line 421
383, // index 123 : <select_template_5F_expression_5F_parser_4>, in file 'template_expression_parser.ggs', line 524
384, // index 124 : <select_template_5F_expression_5F_parser_4>, in file 'template_expression_parser.ggs', line 524
388, // index 125 : <select_template_5F_expression_5F_parser_4>, in file 'template_expression_parser.ggs', line 524
392, // index 126 : <select_template_5F_expression_5F_parser_4>, in file 'template_expression_parser.ggs', line 524
396, // index 127 : <select_template_5F_expression_5F_parser_5>, in file 'template_expression_parser.ggs', line 810
397, // index 128 : <select_template_5F_expression_5F_parser_5>, in file 'template_expression_parser.ggs', line 810
401, // index 129 : <select_template_5F_expression_5F_parser_6>, in file 'template_expression_parser.ggs', line 813
402, // index 130 : <select_template_5F_expression_5F_parser_6>, in file 'template_expression_parser.ggs', line 813
406, // index 131 : <select_template_5F_expression_5F_parser_7>, in file 'template_expression_parser.ggs', line 852
407, // index 132 : <select_template_5F_expression_5F_parser_7>, in file 'template_expression_parser.ggs', line 852
412, // index 133 : <select_template_5F_expression_5F_parser_8>, in file 'template_expression_parser.ggs', line 861
413, // index 134 : <select_template_5F_expression_5F_parser_8>, in file 'template_expression_parser.ggs', line 861
417, // index 135 : <select_template_5F_expression_5F_parser_9>, in file 'template_expression_parser.ggs', line 992
422, // index 136 : <select_template_5F_expression_5F_parser_9>, in file 'template_expression_parser.ggs', line 992
423, // index 137 : <select_template_5F_expression_5F_parser_10>, in file 'template_expression_parser.ggs', line 1049
425, // index 138 : <select_template_5F_expression_5F_parser_10>, in file 'template_expression_parser.ggs', line 1049
427 // index 139 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_template_grammar [55] = {
0, // at 0 : <goil_template_start_symbol>
1, // at 1 : <template_instruction>
17, // at 2 : <sorting_order>
18, // at 3 : <variable>
19, // at 4 : <variable_or_here>
20, // at 5 : <expression>
21, // at 6 : <template_instruction_list>
22, // at 7 : <template_file_name>
23, // at 8 : <relation_term>
24, // at 9 : <relation_factor>
25, // at 10 : <simple_expression>
26, // at 11 : <term>
27, // at 12 : <factor>
46, // at 13 : <select_template_5F_parser_0>
48, // at 14 : <select_template_5F_parser_1>
50, // at 15 : <select_template_5F_parser_2>
52, // at 16 : <select_template_5F_parser_3>
54, // at 17 : <select_template_5F_parser_4>
56, // at 18 : <select_template_5F_parser_5>
58, // at 19 : <select_template_5F_parser_6>
60, // at 20 : <select_template_5F_parser_7>
62, // at 21 : <select_template_5F_parser_8>
64, // at 22 : <select_template_5F_parser_9>
66, // at 23 : <select_template_5F_parser_10>
68, // at 24 : <select_template_5F_parser_11>
70, // at 25 : <select_template_5F_parser_12>
72, // at 26 : <select_template_5F_parser_13>
74, // at 27 : <select_template_5F_parser_14>
76, // at 28 : <select_template_5F_parser_15>
78, // at 29 : <select_template_5F_parser_16>
80, // at 30 : <select_template_5F_parser_17>
82, // at 31 : <select_template_5F_parser_18>
84, // at 32 : <select_template_5F_parser_19>
86, // at 33 : <select_template_5F_parser_20>
88, // at 34 : <select_template_5F_parser_21>
90, // at 35 : <select_template_5F_parser_22>
93, // at 36 : <select_template_5F_parser_23>
95, // at 37 : <select_template_5F_parser_24>
97, // at 38 : <select_template_5F_parser_25>
99, // at 39 : <select_template_5F_parser_26>
101, // at 40 : <select_template_5F_parser_27>
103, // at 41 : <select_template_5F_parser_28>
105, // at 42 : <select_template_5F_expression_5F_parser_0>
108, // at 43 : <select_template_5F_expression_5F_parser_1>
110, // at 44 : <select_template_5F_expression_5F_parser_2>
117, // at 45 : <select_template_5F_expression_5F_parser_3>
123, // at 46 : <select_template_5F_expression_5F_parser_4>
127, // at 47 : <select_template_5F_expression_5F_parser_5>
129, // at 48 : <select_template_5F_expression_5F_parser_6>
131, // at 49 : <select_template_5F_expression_5F_parser_7>
133, // at 50 : <select_template_5F_expression_5F_parser_8>
135, // at 51 : <select_template_5F_expression_5F_parser_9>
137, // at 52 : <select_template_5F_expression_5F_parser_10>
139, // at 53 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_template_grammar [] = {
// At index 0 : <goil_template_start_symbol> only one production, no choice
  -1,
// At index 1 : <template_instruction>
C_Lexique_template_5F_scanner::kToken__21_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_write, -1, // Choice 2
C_Lexique_template_5F_scanner::kToken_template, -1, // Choice 3
C_Lexique_template_5F_scanner::kToken__3F_, -1, // Choice 4
C_Lexique_template_5F_scanner::kToken_function, -1, // Choice 5
C_Lexique_template_5F_scanner::kToken_call, -1, // Choice 6
C_Lexique_template_5F_scanner::kToken_return, -1, // Choice 7
C_Lexique_template_5F_scanner::kToken_if, -1, // Choice 8
C_Lexique_template_5F_scanner::kToken_foreach, -1, // Choice 9
C_Lexique_template_5F_scanner::kToken_for, -1, // Choice 10
C_Lexique_template_5F_scanner::kToken_loop, -1, // Choice 11
C_Lexique_template_5F_scanner::kToken_let, -1, // Choice 12
C_Lexique_template_5F_scanner::kToken_error, -1, // Choice 13
C_Lexique_template_5F_scanner::kToken_warning, -1, // Choice 14
C_Lexique_template_5F_scanner::kToken_display, -1, // Choice 15
C_Lexique_template_5F_scanner::kToken_sort, -1, // Choice 16
  -1,
// At index 34 : <sorting_order> only one production, no choice
  -1,
// At index 35 : <variable> only one production, no choice
  -1,
// At index 36 : <variable_or_here> only one production, no choice
  -1,
// At index 37 : <expression> only one production, no choice
  -1,
// At index 38 : <template_instruction_list> only one production, no choice
  -1,
// At index 39 : <template_file_name> only one production, no choice
  -1,
// At index 40 : <relation_term> only one production, no choice
  -1,
// At index 41 : <relation_factor> only one production, no choice
  -1,
// At index 42 : <simple_expression> only one production, no choice
  -1,
// At index 43 : <term> only one production, no choice
  -1,
// At index 44 : <factor>
C_Lexique_template_5F_scanner::kToken__28_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_not, -1, // Choice 2
C_Lexique_template_5F_scanner::kToken__7E_, -1, // Choice 3
C_Lexique_template_5F_scanner::kToken__2D_, -1, // Choice 4
C_Lexique_template_5F_scanner::kToken__2B_, -1, // Choice 5
C_Lexique_template_5F_scanner::kToken_yes, -1, // Choice 6
C_Lexique_template_5F_scanner::kToken_no, -1, // Choice 7
C_Lexique_template_5F_scanner::kToken_signed_5F_literal_5F_integer_36__34_, -1, // Choice 8
C_Lexique_template_5F_scanner::kToken_string, -1, // Choice 9
C_Lexique_template_5F_scanner::kToken__5B_, -1, // Choice 10
C_Lexique_template_5F_scanner::kToken_identifier, -1, // Choice 11
C_Lexique_template_5F_scanner::kToken_exists, -1, // Choice 12
C_Lexique_template_5F_scanner::kToken_typeof, -1, // Choice 13
C_Lexique_template_5F_scanner::kToken_true, C_Lexique_template_5F_scanner::kToken_false, -1, // Choice 14
C_Lexique_template_5F_scanner::kToken__40_, -1, // Choice 15
C_Lexique_template_5F_scanner::kToken_emptylist, -1, // Choice 16
C_Lexique_template_5F_scanner::kToken_emptymap, -1, // Choice 17
C_Lexique_template_5F_scanner::kToken_mapof, -1, // Choice 18
C_Lexique_template_5F_scanner::kToken_listof, -1, // Choice 19
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 84 : <select_template_5F_parser_0>
C_Lexique_template_5F_scanner::kToken_executable, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_identifier, C_Lexique_template_5F_scanner::kToken_exists, C_Lexique_template_5F_scanner::kToken__28_, C_Lexique_template_5F_scanner::kToken__5B_, C_Lexique_template_5F_scanner::kToken__2B_, C_Lexique_template_5F_scanner::kToken__2D_, C_Lexique_template_5F_scanner::kToken_not, C_Lexique_template_5F_scanner::kToken__7E_, C_Lexique_template_5F_scanner::kToken_yes, C_Lexique_template_5F_scanner::kToken_no, C_Lexique_template_5F_scanner::kToken_signed_5F_literal_5F_integer_36__34_, C_Lexique_template_5F_scanner::kToken_string, C_Lexique_template_5F_scanner::kToken_typeof, C_Lexique_template_5F_scanner::kToken_true, C_Lexique_template_5F_scanner::kToken_false, C_Lexique_template_5F_scanner::kToken__40_, C_Lexique_template_5F_scanner::kToken_emptylist, C_Lexique_template_5F_scanner::kToken_emptymap, C_Lexique_template_5F_scanner::kToken_mapof, C_Lexique_template_5F_scanner::kToken_listof, -1, // Choice 2
  -1,
// At index 108 : <select_template_5F_parser_1>
C_Lexique_template_5F_scanner::kToken_identifier, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_from, -1, // Choice 2
  -1,
// At index 113 : <select_template_5F_parser_2>
C_Lexique_template_5F_scanner::kToken_if, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_identifier, C_Lexique_template_5F_scanner::kToken_from, -1, // Choice 2
  -1,
// At index 119 : <select_template_5F_parser_3>
C_Lexique_template_5F_scanner::kToken_in, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__21_, C_Lexique_template_5F_scanner::kToken_write, C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_template, C_Lexique_template_5F_scanner::kToken_if, C_Lexique_template_5F_scanner::kToken_or, C_Lexique_template_5F_scanner::kToken__3F_, C_Lexique_template_5F_scanner::kToken_function, C_Lexique_template_5F_scanner::kToken_call, C_Lexique_template_5F_scanner::kToken_return, C_Lexique_template_5F_scanner::kToken_elsif, C_Lexique_template_5F_scanner::kToken_else, C_Lexique_template_5F_scanner::kToken_foreach, C_Lexique_template_5F_scanner::kToken_do, C_Lexique_template_5F_scanner::kToken_between, C_Lexique_template_5F_scanner::kToken_after, C_Lexique_template_5F_scanner::kToken_for, C_Lexique_template_5F_scanner::kToken_loop, C_Lexique_template_5F_scanner::kToken_let, C_Lexique_template_5F_scanner::kToken_error, C_Lexique_template_5F_scanner::kToken_warning, C_Lexique_template_5F_scanner::kToken_display, C_Lexique_template_5F_scanner::kToken_sort, C_Lexique_template_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 147 : <select_template_5F_parser_4>
C_Lexique_template_5F_scanner::kToken_or, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__21_, C_Lexique_template_5F_scanner::kToken_write, C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_template, C_Lexique_template_5F_scanner::kToken_if, C_Lexique_template_5F_scanner::kToken__3F_, C_Lexique_template_5F_scanner::kToken_function, C_Lexique_template_5F_scanner::kToken_call, C_Lexique_template_5F_scanner::kToken_return, C_Lexique_template_5F_scanner::kToken_elsif, C_Lexique_template_5F_scanner::kToken_else, C_Lexique_template_5F_scanner::kToken_foreach, C_Lexique_template_5F_scanner::kToken_do, C_Lexique_template_5F_scanner::kToken_between, C_Lexique_template_5F_scanner::kToken_after, C_Lexique_template_5F_scanner::kToken_for, C_Lexique_template_5F_scanner::kToken_loop, C_Lexique_template_5F_scanner::kToken_let, C_Lexique_template_5F_scanner::kToken_error, C_Lexique_template_5F_scanner::kToken_warning, C_Lexique_template_5F_scanner::kToken_display, C_Lexique_template_5F_scanner::kToken_sort, C_Lexique_template_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 174 : <select_template_5F_parser_5>
C_Lexique_template_5F_scanner::kToken_in, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__21_, C_Lexique_template_5F_scanner::kToken_write, C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_template, C_Lexique_template_5F_scanner::kToken_if, C_Lexique_template_5F_scanner::kToken__3F_, C_Lexique_template_5F_scanner::kToken_function, C_Lexique_template_5F_scanner::kToken_call, C_Lexique_template_5F_scanner::kToken_return, C_Lexique_template_5F_scanner::kToken_elsif, C_Lexique_template_5F_scanner::kToken_else, C_Lexique_template_5F_scanner::kToken_foreach, C_Lexique_template_5F_scanner::kToken_do, C_Lexique_template_5F_scanner::kToken_between, C_Lexique_template_5F_scanner::kToken_after, C_Lexique_template_5F_scanner::kToken_for, C_Lexique_template_5F_scanner::kToken_loop, C_Lexique_template_5F_scanner::kToken_let, C_Lexique_template_5F_scanner::kToken_error, C_Lexique_template_5F_scanner::kToken_warning, C_Lexique_template_5F_scanner::kToken_display, C_Lexique_template_5F_scanner::kToken_sort, C_Lexique_template_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 201 : <select_template_5F_parser_6>
C_Lexique_template_5F_scanner::kToken_identifier, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 206 : <select_template_5F_parser_7>
C_Lexique_template_5F_scanner::kToken__29_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 211 : <select_template_5F_parser_8>
C_Lexique_template_5F_scanner::kToken_identifier, C_Lexique_template_5F_scanner::kToken_exists, C_Lexique_template_5F_scanner::kToken__28_, C_Lexique_template_5F_scanner::kToken__5B_, C_Lexique_template_5F_scanner::kToken__2B_, C_Lexique_template_5F_scanner::kToken__2D_, C_Lexique_template_5F_scanner::kToken_not, C_Lexique_template_5F_scanner::kToken__7E_, C_Lexique_template_5F_scanner::kToken_yes, C_Lexique_template_5F_scanner::kToken_no, C_Lexique_template_5F_scanner::kToken_signed_5F_literal_5F_integer_36__34_, C_Lexique_template_5F_scanner::kToken_string, C_Lexique_template_5F_scanner::kToken_typeof, C_Lexique_template_5F_scanner::kToken_true, C_Lexique_template_5F_scanner::kToken_false, C_Lexique_template_5F_scanner::kToken__40_, C_Lexique_template_5F_scanner::kToken_emptylist, C_Lexique_template_5F_scanner::kToken_emptymap, C_Lexique_template_5F_scanner::kToken_mapof, C_Lexique_template_5F_scanner::kToken_listof, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 235 : <select_template_5F_parser_9>
C_Lexique_template_5F_scanner::kToken__29_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 240 : <select_template_5F_parser_10>
C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_else, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_elsif, -1, // Choice 2
  -1,
// At index 246 : <select_template_5F_parser_11>
C_Lexique_template_5F_scanner::kToken_end, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_else, -1, // Choice 2
  -1,
// At index 251 : <select_template_5F_parser_12>
C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_elsif, C_Lexique_template_5F_scanner::kToken_else, C_Lexique_template_5F_scanner::kToken_do, C_Lexique_template_5F_scanner::kToken_between, C_Lexique_template_5F_scanner::kToken_after, C_Lexique_template_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__21_, C_Lexique_template_5F_scanner::kToken_write, C_Lexique_template_5F_scanner::kToken_template, C_Lexique_template_5F_scanner::kToken_if, C_Lexique_template_5F_scanner::kToken__3F_, C_Lexique_template_5F_scanner::kToken_function, C_Lexique_template_5F_scanner::kToken_call, C_Lexique_template_5F_scanner::kToken_return, C_Lexique_template_5F_scanner::kToken_foreach, C_Lexique_template_5F_scanner::kToken_for, C_Lexique_template_5F_scanner::kToken_loop, C_Lexique_template_5F_scanner::kToken_let, C_Lexique_template_5F_scanner::kToken_error, C_Lexique_template_5F_scanner::kToken_warning, C_Lexique_template_5F_scanner::kToken_display, C_Lexique_template_5F_scanner::kToken_sort, -1, // Choice 2
  -1,
// At index 277 : <select_template_5F_parser_13>
C_Lexique_template_5F_scanner::kToken_before, C_Lexique_template_5F_scanner::kToken_do, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_prefixedby, -1, // Choice 2
  -1,
// At index 283 : <select_template_5F_parser_14>
C_Lexique_template_5F_scanner::kToken_do, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_before, -1, // Choice 2
  -1,
// At index 288 : <select_template_5F_parser_15>
C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_after, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_between, -1, // Choice 2
  -1,
// At index 294 : <select_template_5F_parser_16>
C_Lexique_template_5F_scanner::kToken_end, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_after, -1, // Choice 2
  -1,
// At index 299 : <select_template_5F_parser_17>
C_Lexique_template_5F_scanner::kToken_do, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 304 : <select_template_5F_parser_18>
C_Lexique_template_5F_scanner::kToken_end, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_between, -1, // Choice 2
  -1,
// At index 309 : <select_template_5F_parser_19>
C_Lexique_template_5F_scanner::kToken_do, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_before, -1, // Choice 2
  -1,
// At index 314 : <select_template_5F_parser_20>
C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_after, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_between, -1, // Choice 2
  -1,
// At index 320 : <select_template_5F_parser_21>
C_Lexique_template_5F_scanner::kToken_end, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_after, -1, // Choice 2
  -1,
// At index 325 : <select_template_5F_parser_22>
C_Lexique_template_5F_scanner::kToken__3A__3D_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__2B__3D_, -1, // Choice 2
C_Lexique_template_5F_scanner::kToken__21_, C_Lexique_template_5F_scanner::kToken_write, C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_template, C_Lexique_template_5F_scanner::kToken_if, C_Lexique_template_5F_scanner::kToken__3F_, C_Lexique_template_5F_scanner::kToken_function, C_Lexique_template_5F_scanner::kToken_call, C_Lexique_template_5F_scanner::kToken_return, C_Lexique_template_5F_scanner::kToken_elsif, C_Lexique_template_5F_scanner::kToken_else, C_Lexique_template_5F_scanner::kToken_foreach, C_Lexique_template_5F_scanner::kToken_do, C_Lexique_template_5F_scanner::kToken_between, C_Lexique_template_5F_scanner::kToken_after, C_Lexique_template_5F_scanner::kToken_for, C_Lexique_template_5F_scanner::kToken_loop, C_Lexique_template_5F_scanner::kToken_let, C_Lexique_template_5F_scanner::kToken_error, C_Lexique_template_5F_scanner::kToken_warning, C_Lexique_template_5F_scanner::kToken_display, C_Lexique_template_5F_scanner::kToken_sort, C_Lexique_template_5F_scanner::kToken_, -1, // Choice 3
  -1,
// At index 354 : <select_template_5F_parser_23>
C_Lexique_template_5F_scanner::kToken_here, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_identifier, -1, // Choice 2
  -1,
// At index 359 : <select_template_5F_parser_24>
C_Lexique_template_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__3C_, -1, // Choice 2
  -1,
// At index 364 : <select_template_5F_parser_25>
C_Lexique_template_5F_scanner::kToken__21_, C_Lexique_template_5F_scanner::kToken_write, C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_template, C_Lexique_template_5F_scanner::kToken_if, C_Lexique_template_5F_scanner::kToken__3F_, C_Lexique_template_5F_scanner::kToken_function, C_Lexique_template_5F_scanner::kToken_call, C_Lexique_template_5F_scanner::kToken_return, C_Lexique_template_5F_scanner::kToken_elsif, C_Lexique_template_5F_scanner::kToken_else, C_Lexique_template_5F_scanner::kToken_foreach, C_Lexique_template_5F_scanner::kToken_do, C_Lexique_template_5F_scanner::kToken_between, C_Lexique_template_5F_scanner::kToken_after, C_Lexique_template_5F_scanner::kToken_for, C_Lexique_template_5F_scanner::kToken_loop, C_Lexique_template_5F_scanner::kToken_let, C_Lexique_template_5F_scanner::kToken_error, C_Lexique_template_5F_scanner::kToken_warning, C_Lexique_template_5F_scanner::kToken_display, C_Lexique_template_5F_scanner::kToken_sort, C_Lexique_template_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 391 : <select_template_5F_parser_26>
C_Lexique_template_5F_scanner::kToken__5B_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__21_, C_Lexique_template_5F_scanner::kToken_write, C_Lexique_template_5F_scanner::kToken_to, C_Lexique_template_5F_scanner::kToken__3A_, C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_identifier, C_Lexique_template_5F_scanner::kToken_template, C_Lexique_template_5F_scanner::kToken_if, C_Lexique_template_5F_scanner::kToken_in, C_Lexique_template_5F_scanner::kToken_or, C_Lexique_template_5F_scanner::kToken__3F_, C_Lexique_template_5F_scanner::kToken_function, C_Lexique_template_5F_scanner::kToken__28_, C_Lexique_template_5F_scanner::kToken__2C_, C_Lexique_template_5F_scanner::kToken__29_, C_Lexique_template_5F_scanner::kToken_call, C_Lexique_template_5F_scanner::kToken_return, C_Lexique_template_5F_scanner::kToken_then, C_Lexique_template_5F_scanner::kToken_elsif, C_Lexique_template_5F_scanner::kToken_else, C_Lexique_template_5F_scanner::kToken_foreach, C_Lexique_template_5F_scanner::kToken_prefixedby, C_Lexique_template_5F_scanner::kToken_before, C_Lexique_template_5F_scanner::kToken_do, C_Lexique_template_5F_scanner::kToken_between, C_Lexique_template_5F_scanner::kToken_after, C_Lexique_template_5F_scanner::kToken_for, C_Lexique_template_5F_scanner::kToken_loop, C_Lexique_template_5F_scanner::kToken_let, C_Lexique_template_5F_scanner::kToken__3A__3D_, C_Lexique_template_5F_scanner::kToken__2B__3D_, C_Lexique_template_5F_scanner::kToken_error, C_Lexique_template_5F_scanner::kToken_warning, C_Lexique_template_5F_scanner::kToken_display, C_Lexique_template_5F_scanner::kToken__3E_, C_Lexique_template_5F_scanner::kToken__3C_, C_Lexique_template_5F_scanner::kToken_sort, C_Lexique_template_5F_scanner::kToken_by, C_Lexique_template_5F_scanner::kToken__5D_, C_Lexique_template_5F_scanner::kToken__3A__3A_, C_Lexique_template_5F_scanner::kToken__7C_, C_Lexique_template_5F_scanner::kToken__5E_, C_Lexique_template_5F_scanner::kToken__26_, C_Lexique_template_5F_scanner::kToken__3D__3D_, C_Lexique_template_5F_scanner::kToken__21__3D_, C_Lexique_template_5F_scanner::kToken__3C__3D_, C_Lexique_template_5F_scanner::kToken__3E__3D_, C_Lexique_template_5F_scanner::kToken__3C__3C_, C_Lexique_template_5F_scanner::kToken__3E__3E_, C_Lexique_template_5F_scanner::kToken__2B_, C_Lexique_template_5F_scanner::kToken__2E_, C_Lexique_template_5F_scanner::kToken__2D_, C_Lexique_template_5F_scanner::kToken__2A_, C_Lexique_template_5F_scanner::kToken__2F_, C_Lexique_template_5F_scanner::kToken_mod, C_Lexique_template_5F_scanner::kToken_default, C_Lexique_template_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 452 : <select_template_5F_parser_27>
C_Lexique_template_5F_scanner::kToken__21_, C_Lexique_template_5F_scanner::kToken_write, C_Lexique_template_5F_scanner::kToken_to, C_Lexique_template_5F_scanner::kToken__3A_, C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_identifier, C_Lexique_template_5F_scanner::kToken_template, C_Lexique_template_5F_scanner::kToken_if, C_Lexique_template_5F_scanner::kToken_in, C_Lexique_template_5F_scanner::kToken_or, C_Lexique_template_5F_scanner::kToken__3F_, C_Lexique_template_5F_scanner::kToken_function, C_Lexique_template_5F_scanner::kToken__28_, C_Lexique_template_5F_scanner::kToken__2C_, C_Lexique_template_5F_scanner::kToken__29_, C_Lexique_template_5F_scanner::kToken_call, C_Lexique_template_5F_scanner::kToken_return, C_Lexique_template_5F_scanner::kToken_then, C_Lexique_template_5F_scanner::kToken_elsif, C_Lexique_template_5F_scanner::kToken_else, C_Lexique_template_5F_scanner::kToken_foreach, C_Lexique_template_5F_scanner::kToken_prefixedby, C_Lexique_template_5F_scanner::kToken_before, C_Lexique_template_5F_scanner::kToken_do, C_Lexique_template_5F_scanner::kToken_between, C_Lexique_template_5F_scanner::kToken_after, C_Lexique_template_5F_scanner::kToken_for, C_Lexique_template_5F_scanner::kToken_loop, C_Lexique_template_5F_scanner::kToken_let, C_Lexique_template_5F_scanner::kToken__3A__3D_, C_Lexique_template_5F_scanner::kToken__2B__3D_, C_Lexique_template_5F_scanner::kToken_error, C_Lexique_template_5F_scanner::kToken_warning, C_Lexique_template_5F_scanner::kToken_display, C_Lexique_template_5F_scanner::kToken__3E_, C_Lexique_template_5F_scanner::kToken__3C_, C_Lexique_template_5F_scanner::kToken_sort, C_Lexique_template_5F_scanner::kToken_by, C_Lexique_template_5F_scanner::kToken__5D_, C_Lexique_template_5F_scanner::kToken__7C_, C_Lexique_template_5F_scanner::kToken__5E_, C_Lexique_template_5F_scanner::kToken__26_, C_Lexique_template_5F_scanner::kToken__3D__3D_, C_Lexique_template_5F_scanner::kToken__21__3D_, C_Lexique_template_5F_scanner::kToken__3C__3D_, C_Lexique_template_5F_scanner::kToken__3E__3D_, C_Lexique_template_5F_scanner::kToken__3C__3C_, C_Lexique_template_5F_scanner::kToken__3E__3E_, C_Lexique_template_5F_scanner::kToken__2B_, C_Lexique_template_5F_scanner::kToken__2E_, C_Lexique_template_5F_scanner::kToken__2D_, C_Lexique_template_5F_scanner::kToken__2A_, C_Lexique_template_5F_scanner::kToken__2F_, C_Lexique_template_5F_scanner::kToken_mod, C_Lexique_template_5F_scanner::kToken_default, C_Lexique_template_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__3A__3A_, -1, // Choice 2
  -1,
// At index 512 : <select_template_5F_parser_28>
C_Lexique_template_5F_scanner::kToken__5B_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__21_, C_Lexique_template_5F_scanner::kToken_write, C_Lexique_template_5F_scanner::kToken_to, C_Lexique_template_5F_scanner::kToken__3A_, C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_identifier, C_Lexique_template_5F_scanner::kToken_template, C_Lexique_template_5F_scanner::kToken_if, C_Lexique_template_5F_scanner::kToken_in, C_Lexique_template_5F_scanner::kToken_or, C_Lexique_template_5F_scanner::kToken__3F_, C_Lexique_template_5F_scanner::kToken_function, C_Lexique_template_5F_scanner::kToken__28_, C_Lexique_template_5F_scanner::kToken__2C_, C_Lexique_template_5F_scanner::kToken__29_, C_Lexique_template_5F_scanner::kToken_call, C_Lexique_template_5F_scanner::kToken_return, C_Lexique_template_5F_scanner::kToken_then, C_Lexique_template_5F_scanner::kToken_elsif, C_Lexique_template_5F_scanner::kToken_else, C_Lexique_template_5F_scanner::kToken_foreach, C_Lexique_template_5F_scanner::kToken_prefixedby, C_Lexique_template_5F_scanner::kToken_before, C_Lexique_template_5F_scanner::kToken_do, C_Lexique_template_5F_scanner::kToken_between, C_Lexique_template_5F_scanner::kToken_after, C_Lexique_template_5F_scanner::kToken_for, C_Lexique_template_5F_scanner::kToken_loop, C_Lexique_template_5F_scanner::kToken_let, C_Lexique_template_5F_scanner::kToken__3A__3D_, C_Lexique_template_5F_scanner::kToken__2B__3D_, C_Lexique_template_5F_scanner::kToken_error, C_Lexique_template_5F_scanner::kToken_warning, C_Lexique_template_5F_scanner::kToken_display, C_Lexique_template_5F_scanner::kToken__3E_, C_Lexique_template_5F_scanner::kToken__3C_, C_Lexique_template_5F_scanner::kToken_sort, C_Lexique_template_5F_scanner::kToken_by, C_Lexique_template_5F_scanner::kToken__5D_, C_Lexique_template_5F_scanner::kToken__3A__3A_, C_Lexique_template_5F_scanner::kToken__7C_, C_Lexique_template_5F_scanner::kToken__5E_, C_Lexique_template_5F_scanner::kToken__26_, C_Lexique_template_5F_scanner::kToken__3D__3D_, C_Lexique_template_5F_scanner::kToken__21__3D_, C_Lexique_template_5F_scanner::kToken__3C__3D_, C_Lexique_template_5F_scanner::kToken__3E__3D_, C_Lexique_template_5F_scanner::kToken__3C__3C_, C_Lexique_template_5F_scanner::kToken__3E__3E_, C_Lexique_template_5F_scanner::kToken__2B_, C_Lexique_template_5F_scanner::kToken__2E_, C_Lexique_template_5F_scanner::kToken__2D_, C_Lexique_template_5F_scanner::kToken__2A_, C_Lexique_template_5F_scanner::kToken__2F_, C_Lexique_template_5F_scanner::kToken_mod, C_Lexique_template_5F_scanner::kToken_default, C_Lexique_template_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 573 : <select_template_5F_expression_5F_parser_0>
C_Lexique_template_5F_scanner::kToken__21_, C_Lexique_template_5F_scanner::kToken_write, C_Lexique_template_5F_scanner::kToken_to, C_Lexique_template_5F_scanner::kToken__3A_, C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_identifier, C_Lexique_template_5F_scanner::kToken_template, C_Lexique_template_5F_scanner::kToken_if, C_Lexique_template_5F_scanner::kToken_in, C_Lexique_template_5F_scanner::kToken_or, C_Lexique_template_5F_scanner::kToken__3F_, C_Lexique_template_5F_scanner::kToken_function, C_Lexique_template_5F_scanner::kToken__2C_, C_Lexique_template_5F_scanner::kToken__29_, C_Lexique_template_5F_scanner::kToken_call, C_Lexique_template_5F_scanner::kToken_return, C_Lexique_template_5F_scanner::kToken_then, C_Lexique_template_5F_scanner::kToken_elsif, C_Lexique_template_5F_scanner::kToken_else, C_Lexique_template_5F_scanner::kToken_foreach, C_Lexique_template_5F_scanner::kToken_prefixedby, C_Lexique_template_5F_scanner::kToken_before, C_Lexique_template_5F_scanner::kToken_do, C_Lexique_template_5F_scanner::kToken_between, C_Lexique_template_5F_scanner::kToken_after, C_Lexique_template_5F_scanner::kToken_for, C_Lexique_template_5F_scanner::kToken_loop, C_Lexique_template_5F_scanner::kToken_let, C_Lexique_template_5F_scanner::kToken_error, C_Lexique_template_5F_scanner::kToken_warning, C_Lexique_template_5F_scanner::kToken_display, C_Lexique_template_5F_scanner::kToken_sort, C_Lexique_template_5F_scanner::kToken_by, C_Lexique_template_5F_scanner::kToken__5D_, C_Lexique_template_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__7C_, -1, // Choice 2
C_Lexique_template_5F_scanner::kToken__5E_, -1, // Choice 3
  -1,
// At index 614 : <select_template_5F_expression_5F_parser_1>
C_Lexique_template_5F_scanner::kToken__21_, C_Lexique_template_5F_scanner::kToken_write, C_Lexique_template_5F_scanner::kToken_to, C_Lexique_template_5F_scanner::kToken__3A_, C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_identifier, C_Lexique_template_5F_scanner::kToken_template, C_Lexique_template_5F_scanner::kToken_if, C_Lexique_template_5F_scanner::kToken_in, C_Lexique_template_5F_scanner::kToken_or, C_Lexique_template_5F_scanner::kToken__3F_, C_Lexique_template_5F_scanner::kToken_function, C_Lexique_template_5F_scanner::kToken__2C_, C_Lexique_template_5F_scanner::kToken__29_, C_Lexique_template_5F_scanner::kToken_call, C_Lexique_template_5F_scanner::kToken_return, C_Lexique_template_5F_scanner::kToken_then, C_Lexique_template_5F_scanner::kToken_elsif, C_Lexique_template_5F_scanner::kToken_else, C_Lexique_template_5F_scanner::kToken_foreach, C_Lexique_template_5F_scanner::kToken_prefixedby, C_Lexique_template_5F_scanner::kToken_before, C_Lexique_template_5F_scanner::kToken_do, C_Lexique_template_5F_scanner::kToken_between, C_Lexique_template_5F_scanner::kToken_after, C_Lexique_template_5F_scanner::kToken_for, C_Lexique_template_5F_scanner::kToken_loop, C_Lexique_template_5F_scanner::kToken_let, C_Lexique_template_5F_scanner::kToken_error, C_Lexique_template_5F_scanner::kToken_warning, C_Lexique_template_5F_scanner::kToken_display, C_Lexique_template_5F_scanner::kToken_sort, C_Lexique_template_5F_scanner::kToken_by, C_Lexique_template_5F_scanner::kToken__5D_, C_Lexique_template_5F_scanner::kToken__7C_, C_Lexique_template_5F_scanner::kToken__5E_, C_Lexique_template_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__26_, -1, // Choice 2
  -1,
// At index 655 : <select_template_5F_expression_5F_parser_2>
C_Lexique_template_5F_scanner::kToken__21_, C_Lexique_template_5F_scanner::kToken_write, C_Lexique_template_5F_scanner::kToken_to, C_Lexique_template_5F_scanner::kToken__3A_, C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_identifier, C_Lexique_template_5F_scanner::kToken_template, C_Lexique_template_5F_scanner::kToken_if, C_Lexique_template_5F_scanner::kToken_in, C_Lexique_template_5F_scanner::kToken_or, C_Lexique_template_5F_scanner::kToken__3F_, C_Lexique_template_5F_scanner::kToken_function, C_Lexique_template_5F_scanner::kToken__2C_, C_Lexique_template_5F_scanner::kToken__29_, C_Lexique_template_5F_scanner::kToken_call, C_Lexique_template_5F_scanner::kToken_return, C_Lexique_template_5F_scanner::kToken_then, C_Lexique_template_5F_scanner::kToken_elsif, C_Lexique_template_5F_scanner::kToken_else, C_Lexique_template_5F_scanner::kToken_foreach, C_Lexique_template_5F_scanner::kToken_prefixedby, C_Lexique_template_5F_scanner::kToken_before, C_Lexique_template_5F_scanner::kToken_do, C_Lexique_template_5F_scanner::kToken_between, C_Lexique_template_5F_scanner::kToken_after, C_Lexique_template_5F_scanner::kToken_for, C_Lexique_template_5F_scanner::kToken_loop, C_Lexique_template_5F_scanner::kToken_let, C_Lexique_template_5F_scanner::kToken_error, C_Lexique_template_5F_scanner::kToken_warning, C_Lexique_template_5F_scanner::kToken_display, C_Lexique_template_5F_scanner::kToken_sort, C_Lexique_template_5F_scanner::kToken_by, C_Lexique_template_5F_scanner::kToken__5D_, C_Lexique_template_5F_scanner::kToken__7C_, C_Lexique_template_5F_scanner::kToken__5E_, C_Lexique_template_5F_scanner::kToken__26_, C_Lexique_template_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__3D__3D_, -1, // Choice 2
C_Lexique_template_5F_scanner::kToken__21__3D_, -1, // Choice 3
C_Lexique_template_5F_scanner::kToken__3C__3D_, -1, // Choice 4
C_Lexique_template_5F_scanner::kToken__3E__3D_, -1, // Choice 5
C_Lexique_template_5F_scanner::kToken__3E_, -1, // Choice 6
C_Lexique_template_5F_scanner::kToken__3C_, -1, // Choice 7
  -1,
// At index 707 : <select_template_5F_expression_5F_parser_3>
C_Lexique_template_5F_scanner::kToken__21_, C_Lexique_template_5F_scanner::kToken_write, C_Lexique_template_5F_scanner::kToken_to, C_Lexique_template_5F_scanner::kToken__3A_, C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_identifier, C_Lexique_template_5F_scanner::kToken_template, C_Lexique_template_5F_scanner::kToken_if, C_Lexique_template_5F_scanner::kToken_in, C_Lexique_template_5F_scanner::kToken_or, C_Lexique_template_5F_scanner::kToken__3F_, C_Lexique_template_5F_scanner::kToken_function, C_Lexique_template_5F_scanner::kToken__2C_, C_Lexique_template_5F_scanner::kToken__29_, C_Lexique_template_5F_scanner::kToken_call, C_Lexique_template_5F_scanner::kToken_return, C_Lexique_template_5F_scanner::kToken_then, C_Lexique_template_5F_scanner::kToken_elsif, C_Lexique_template_5F_scanner::kToken_else, C_Lexique_template_5F_scanner::kToken_foreach, C_Lexique_template_5F_scanner::kToken_prefixedby, C_Lexique_template_5F_scanner::kToken_before, C_Lexique_template_5F_scanner::kToken_do, C_Lexique_template_5F_scanner::kToken_between, C_Lexique_template_5F_scanner::kToken_after, C_Lexique_template_5F_scanner::kToken_for, C_Lexique_template_5F_scanner::kToken_loop, C_Lexique_template_5F_scanner::kToken_let, C_Lexique_template_5F_scanner::kToken_error, C_Lexique_template_5F_scanner::kToken_warning, C_Lexique_template_5F_scanner::kToken_display, C_Lexique_template_5F_scanner::kToken__3E_, C_Lexique_template_5F_scanner::kToken__3C_, C_Lexique_template_5F_scanner::kToken_sort, C_Lexique_template_5F_scanner::kToken_by, C_Lexique_template_5F_scanner::kToken__5D_, C_Lexique_template_5F_scanner::kToken__7C_, C_Lexique_template_5F_scanner::kToken__5E_, C_Lexique_template_5F_scanner::kToken__26_, C_Lexique_template_5F_scanner::kToken__3D__3D_, C_Lexique_template_5F_scanner::kToken__21__3D_, C_Lexique_template_5F_scanner::kToken__3C__3D_, C_Lexique_template_5F_scanner::kToken__3E__3D_, C_Lexique_template_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__3C__3C_, -1, // Choice 2
C_Lexique_template_5F_scanner::kToken__3E__3E_, -1, // Choice 3
C_Lexique_template_5F_scanner::kToken__2B_, -1, // Choice 4
C_Lexique_template_5F_scanner::kToken__2E_, -1, // Choice 5
C_Lexique_template_5F_scanner::kToken__2D_, -1, // Choice 6
  -1,
// At index 763 : <select_template_5F_expression_5F_parser_4>
C_Lexique_template_5F_scanner::kToken__21_, C_Lexique_template_5F_scanner::kToken_write, C_Lexique_template_5F_scanner::kToken_to, C_Lexique_template_5F_scanner::kToken__3A_, C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_identifier, C_Lexique_template_5F_scanner::kToken_template, C_Lexique_template_5F_scanner::kToken_if, C_Lexique_template_5F_scanner::kToken_in, C_Lexique_template_5F_scanner::kToken_or, C_Lexique_template_5F_scanner::kToken__3F_, C_Lexique_template_5F_scanner::kToken_function, C_Lexique_template_5F_scanner::kToken__2C_, C_Lexique_template_5F_scanner::kToken__29_, C_Lexique_template_5F_scanner::kToken_call, C_Lexique_template_5F_scanner::kToken_return, C_Lexique_template_5F_scanner::kToken_then, C_Lexique_template_5F_scanner::kToken_elsif, C_Lexique_template_5F_scanner::kToken_else, C_Lexique_template_5F_scanner::kToken_foreach, C_Lexique_template_5F_scanner::kToken_prefixedby, C_Lexique_template_5F_scanner::kToken_before, C_Lexique_template_5F_scanner::kToken_do, C_Lexique_template_5F_scanner::kToken_between, C_Lexique_template_5F_scanner::kToken_after, C_Lexique_template_5F_scanner::kToken_for, C_Lexique_template_5F_scanner::kToken_loop, C_Lexique_template_5F_scanner::kToken_let, C_Lexique_template_5F_scanner::kToken_error, C_Lexique_template_5F_scanner::kToken_warning, C_Lexique_template_5F_scanner::kToken_display, C_Lexique_template_5F_scanner::kToken__3E_, C_Lexique_template_5F_scanner::kToken__3C_, C_Lexique_template_5F_scanner::kToken_sort, C_Lexique_template_5F_scanner::kToken_by, C_Lexique_template_5F_scanner::kToken__5D_, C_Lexique_template_5F_scanner::kToken__7C_, C_Lexique_template_5F_scanner::kToken__5E_, C_Lexique_template_5F_scanner::kToken__26_, C_Lexique_template_5F_scanner::kToken__3D__3D_, C_Lexique_template_5F_scanner::kToken__21__3D_, C_Lexique_template_5F_scanner::kToken__3C__3D_, C_Lexique_template_5F_scanner::kToken__3E__3D_, C_Lexique_template_5F_scanner::kToken__3C__3C_, C_Lexique_template_5F_scanner::kToken__3E__3E_, C_Lexique_template_5F_scanner::kToken__2B_, C_Lexique_template_5F_scanner::kToken__2E_, C_Lexique_template_5F_scanner::kToken__2D_, C_Lexique_template_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__2A_, -1, // Choice 2
C_Lexique_template_5F_scanner::kToken__2F_, -1, // Choice 3
C_Lexique_template_5F_scanner::kToken_mod, -1, // Choice 4
  -1,
// At index 820 : <select_template_5F_expression_5F_parser_5>
C_Lexique_template_5F_scanner::kToken__5D_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__3A_, -1, // Choice 2
  -1,
// At index 825 : <select_template_5F_expression_5F_parser_6>
C_Lexique_template_5F_scanner::kToken__5D_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 830 : <select_template_5F_expression_5F_parser_7>
C_Lexique_template_5F_scanner::kToken__21_, C_Lexique_template_5F_scanner::kToken_write, C_Lexique_template_5F_scanner::kToken_to, C_Lexique_template_5F_scanner::kToken__3A_, C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_identifier, C_Lexique_template_5F_scanner::kToken_template, C_Lexique_template_5F_scanner::kToken_if, C_Lexique_template_5F_scanner::kToken_in, C_Lexique_template_5F_scanner::kToken_or, C_Lexique_template_5F_scanner::kToken__3F_, C_Lexique_template_5F_scanner::kToken_function, C_Lexique_template_5F_scanner::kToken__2C_, C_Lexique_template_5F_scanner::kToken__29_, C_Lexique_template_5F_scanner::kToken_call, C_Lexique_template_5F_scanner::kToken_return, C_Lexique_template_5F_scanner::kToken_then, C_Lexique_template_5F_scanner::kToken_elsif, C_Lexique_template_5F_scanner::kToken_else, C_Lexique_template_5F_scanner::kToken_foreach, C_Lexique_template_5F_scanner::kToken_prefixedby, C_Lexique_template_5F_scanner::kToken_before, C_Lexique_template_5F_scanner::kToken_do, C_Lexique_template_5F_scanner::kToken_between, C_Lexique_template_5F_scanner::kToken_after, C_Lexique_template_5F_scanner::kToken_for, C_Lexique_template_5F_scanner::kToken_loop, C_Lexique_template_5F_scanner::kToken_let, C_Lexique_template_5F_scanner::kToken_error, C_Lexique_template_5F_scanner::kToken_warning, C_Lexique_template_5F_scanner::kToken_display, C_Lexique_template_5F_scanner::kToken__3E_, C_Lexique_template_5F_scanner::kToken__3C_, C_Lexique_template_5F_scanner::kToken_sort, C_Lexique_template_5F_scanner::kToken_by, C_Lexique_template_5F_scanner::kToken__5D_, C_Lexique_template_5F_scanner::kToken__7C_, C_Lexique_template_5F_scanner::kToken__5E_, C_Lexique_template_5F_scanner::kToken__26_, C_Lexique_template_5F_scanner::kToken__3D__3D_, C_Lexique_template_5F_scanner::kToken__21__3D_, C_Lexique_template_5F_scanner::kToken__3C__3D_, C_Lexique_template_5F_scanner::kToken__3E__3D_, C_Lexique_template_5F_scanner::kToken__3C__3C_, C_Lexique_template_5F_scanner::kToken__3E__3E_, C_Lexique_template_5F_scanner::kToken__2B_, C_Lexique_template_5F_scanner::kToken__2E_, C_Lexique_template_5F_scanner::kToken__2D_, C_Lexique_template_5F_scanner::kToken__2A_, C_Lexique_template_5F_scanner::kToken__2F_, C_Lexique_template_5F_scanner::kToken_mod, C_Lexique_template_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__28_, -1, // Choice 2
  -1,
// At index 886 : <select_template_5F_expression_5F_parser_8>
C_Lexique_template_5F_scanner::kToken__29_, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 891 : <select_template_5F_expression_5F_parser_9>
C_Lexique_template_5F_scanner::kToken_default, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken__21_, C_Lexique_template_5F_scanner::kToken_write, C_Lexique_template_5F_scanner::kToken_to, C_Lexique_template_5F_scanner::kToken__3A_, C_Lexique_template_5F_scanner::kToken_end, C_Lexique_template_5F_scanner::kToken_identifier, C_Lexique_template_5F_scanner::kToken_template, C_Lexique_template_5F_scanner::kToken_if, C_Lexique_template_5F_scanner::kToken_in, C_Lexique_template_5F_scanner::kToken_or, C_Lexique_template_5F_scanner::kToken__3F_, C_Lexique_template_5F_scanner::kToken_function, C_Lexique_template_5F_scanner::kToken__2C_, C_Lexique_template_5F_scanner::kToken__29_, C_Lexique_template_5F_scanner::kToken_call, C_Lexique_template_5F_scanner::kToken_return, C_Lexique_template_5F_scanner::kToken_then, C_Lexique_template_5F_scanner::kToken_elsif, C_Lexique_template_5F_scanner::kToken_else, C_Lexique_template_5F_scanner::kToken_foreach, C_Lexique_template_5F_scanner::kToken_prefixedby, C_Lexique_template_5F_scanner::kToken_before, C_Lexique_template_5F_scanner::kToken_do, C_Lexique_template_5F_scanner::kToken_between, C_Lexique_template_5F_scanner::kToken_after, C_Lexique_template_5F_scanner::kToken_for, C_Lexique_template_5F_scanner::kToken_loop, C_Lexique_template_5F_scanner::kToken_let, C_Lexique_template_5F_scanner::kToken_error, C_Lexique_template_5F_scanner::kToken_warning, C_Lexique_template_5F_scanner::kToken_display, C_Lexique_template_5F_scanner::kToken__3E_, C_Lexique_template_5F_scanner::kToken__3C_, C_Lexique_template_5F_scanner::kToken_sort, C_Lexique_template_5F_scanner::kToken_by, C_Lexique_template_5F_scanner::kToken__5D_, C_Lexique_template_5F_scanner::kToken__7C_, C_Lexique_template_5F_scanner::kToken__5E_, C_Lexique_template_5F_scanner::kToken__26_, C_Lexique_template_5F_scanner::kToken__3D__3D_, C_Lexique_template_5F_scanner::kToken__21__3D_, C_Lexique_template_5F_scanner::kToken__3C__3D_, C_Lexique_template_5F_scanner::kToken__3E__3D_, C_Lexique_template_5F_scanner::kToken__3C__3C_, C_Lexique_template_5F_scanner::kToken__3E__3E_, C_Lexique_template_5F_scanner::kToken__2B_, C_Lexique_template_5F_scanner::kToken__2E_, C_Lexique_template_5F_scanner::kToken__2D_, C_Lexique_template_5F_scanner::kToken__2A_, C_Lexique_template_5F_scanner::kToken__2F_, C_Lexique_template_5F_scanner::kToken_mod, C_Lexique_template_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 947 : <select_template_5F_expression_5F_parser_10>
C_Lexique_template_5F_scanner::kToken_true, -1, // Choice 1
C_Lexique_template_5F_scanner::kToken_false, -1, // Choice 2
  -1,
// At index 952 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_template_grammar [55] = {
0, // at 0 : <goil_template_start_symbol>
1, // at 1 : <template_instruction>
34, // at 2 : <sorting_order>
35, // at 3 : <variable>
36, // at 4 : <variable_or_here>
37, // at 5 : <expression>
38, // at 6 : <template_instruction_list>
39, // at 7 : <template_file_name>
40, // at 8 : <relation_term>
41, // at 9 : <relation_factor>
42, // at 10 : <simple_expression>
43, // at 11 : <term>
44, // at 12 : <factor>
84, // at 13 : <select_template_5F_parser_0>
108, // at 14 : <select_template_5F_parser_1>
113, // at 15 : <select_template_5F_parser_2>
119, // at 16 : <select_template_5F_parser_3>
147, // at 17 : <select_template_5F_parser_4>
174, // at 18 : <select_template_5F_parser_5>
201, // at 19 : <select_template_5F_parser_6>
206, // at 20 : <select_template_5F_parser_7>
211, // at 21 : <select_template_5F_parser_8>
235, // at 22 : <select_template_5F_parser_9>
240, // at 23 : <select_template_5F_parser_10>
246, // at 24 : <select_template_5F_parser_11>
251, // at 25 : <select_template_5F_parser_12>
277, // at 26 : <select_template_5F_parser_13>
283, // at 27 : <select_template_5F_parser_14>
288, // at 28 : <select_template_5F_parser_15>
294, // at 29 : <select_template_5F_parser_16>
299, // at 30 : <select_template_5F_parser_17>
304, // at 31 : <select_template_5F_parser_18>
309, // at 32 : <select_template_5F_parser_19>
314, // at 33 : <select_template_5F_parser_20>
320, // at 34 : <select_template_5F_parser_21>
325, // at 35 : <select_template_5F_parser_22>
354, // at 36 : <select_template_5F_parser_23>
359, // at 37 : <select_template_5F_parser_24>
364, // at 38 : <select_template_5F_parser_25>
391, // at 39 : <select_template_5F_parser_26>
452, // at 40 : <select_template_5F_parser_27>
512, // at 41 : <select_template_5F_parser_28>
573, // at 42 : <select_template_5F_expression_5F_parser_0>
614, // at 43 : <select_template_5F_expression_5F_parser_1>
655, // at 44 : <select_template_5F_expression_5F_parser_2>
707, // at 45 : <select_template_5F_expression_5F_parser_3>
763, // at 46 : <select_template_5F_expression_5F_parser_4>
820, // at 47 : <select_template_5F_expression_5F_parser_5>
825, // at 48 : <select_template_5F_expression_5F_parser_6>
830, // at 49 : <select_template_5F_expression_5F_parser_7>
886, // at 50 : <select_template_5F_expression_5F_parser_8>
891, // at 51 : <select_template_5F_expression_5F_parser_9>
947, // at 52 : <select_template_5F_expression_5F_parser_10>
952, // at 53 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              'goil_template_start_symbol' non terminal implementation                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_template_5F_grammar::nt_goil_5F_template_5F_start_5F_symbol_parse (C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_parser_goil_5F_template_5F_start_5F_symbol_i10_parse(inLexique) ;
}

void cGrammar_template_5F_grammar::nt_goil_5F_template_5F_start_5F_symbol_ (const GALGAS_string parameter_1,
                                const GALGAS_string parameter_2,
                                const GALGAS_string parameter_3,
                                GALGAS_TfieldMap parameter_4,
                                GALGAS_string & parameter_5,
                                GALGAS_Tvalue & parameter_6,
                                GALGAS_Ttype & parameter_7,
                                C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_parser_goil_5F_template_5F_start_5F_symbol_i10_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
}

void cGrammar_template_5F_grammar::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_template_5F_grammar::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_template_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_template_5F_scanner (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_template_5F_grammar::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_template_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_template_5F_scanner (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performTopDownParsing (gProductions_template_grammar, gProductionNames_template_grammar, gProductionIndexes_template_grammar,
                                    gFirstProductionIndexes_template_grammar, gDecision_template_grammar, gDecisionIndexes_template_grammar, 427) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Grammar start symbol implementation                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_template_5F_grammar::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                const GALGAS_string  parameter_1,
                                const GALGAS_string  parameter_2,
                                const GALGAS_string  parameter_3,
                                GALGAS_TfieldMap  parameter_4,
                                GALGAS_string &  parameter_5,
                                GALGAS_Tvalue &  parameter_6,
                                GALGAS_Ttype &  parameter_7
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_template_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_template_5F_scanner (inCompiler, "", "", filePath COMMA_HERE)) ;
    if (scanner->sourceText () != NULL) {
      const bool ok = scanner->performTopDownParsing (gProductions_template_grammar, gProductionNames_template_grammar, gProductionIndexes_template_grammar,
                                                      gFirstProductionIndexes_template_grammar, gDecision_template_grammar, gDecisionIndexes_template_grammar, 427) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_template_5F_grammar grammar ;
        grammar.nt_goil_5F_template_5F_start_5F_symbol_ (parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_template_5F_grammar::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                const GALGAS_string  parameter_1,
                                const GALGAS_string  parameter_2,
                                const GALGAS_string  parameter_3,
                                GALGAS_TfieldMap  parameter_4,
                                GALGAS_string &  parameter_5,
                                GALGAS_Tvalue &  parameter_6,
                                GALGAS_Ttype &  parameter_7
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_template_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_template_5F_scanner (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_template_grammar, gProductionNames_template_grammar, gProductionIndexes_template_grammar,
                                                    gFirstProductionIndexes_template_grammar, gDecision_template_grammar, gDecisionIndexes_template_grammar, 427) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_template_5F_grammar grammar ;
      grammar.nt_goil_5F_template_5F_start_5F_symbol_ (parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 'template_instruction' non terminal implementation                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_template_5F_grammar::nt_template_5F_instruction_parse (C_Lexique_template_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_template_5F_parser_template_5F_instruction_i0_parse(inLexique) ;
    break ;
  case 2 :
    rule_template_5F_parser_template_5F_instruction_i1_parse(inLexique) ;
    break ;
  case 3 :
    rule_template_5F_parser_template_5F_instruction_i3_parse(inLexique) ;
    break ;
  case 4 :
    rule_template_5F_parser_template_5F_instruction_i4_parse(inLexique) ;
    break ;
  case 5 :
    rule_template_5F_parser_template_5F_instruction_i5_parse(inLexique) ;
    break ;
  case 6 :
    rule_template_5F_parser_template_5F_instruction_i6_parse(inLexique) ;
    break ;
  case 7 :
    rule_template_5F_parser_template_5F_instruction_i7_parse(inLexique) ;
    break ;
  case 8 :
    rule_template_5F_parser_template_5F_instruction_i8_parse(inLexique) ;
    break ;
  case 9 :
    rule_template_5F_parser_template_5F_instruction_i11_parse(inLexique) ;
    break ;
  case 10 :
    rule_template_5F_parser_template_5F_instruction_i12_parse(inLexique) ;
    break ;
  case 11 :
    rule_template_5F_parser_template_5F_instruction_i13_parse(inLexique) ;
    break ;
  case 12 :
    rule_template_5F_parser_template_5F_instruction_i14_parse(inLexique) ;
    break ;
  case 13 :
    rule_template_5F_parser_template_5F_instruction_i16_parse(inLexique) ;
    break ;
  case 14 :
    rule_template_5F_parser_template_5F_instruction_i17_parse(inLexique) ;
    break ;
  case 15 :
    rule_template_5F_parser_template_5F_instruction_i18_parse(inLexique) ;
    break ;
  case 16 :
    rule_template_5F_parser_template_5F_instruction_i20_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_template_5F_grammar::nt_template_5F_instruction_ (const GALGAS_string parameter_1,
                                const GALGAS_string parameter_2,
                                const GALGAS_string parameter_3,
                                GALGAS_TfieldMap & parameter_4,
                                GALGAS_string & parameter_5,
                                GALGAS_Tvalue & parameter_6,
                                GALGAS_Ttype & parameter_7,
                                C_Lexique_template_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_template_5F_parser_template_5F_instruction_i0_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
    break ;
  case 2 :
    rule_template_5F_parser_template_5F_instruction_i1_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
    break ;
  case 3 :
    rule_template_5F_parser_template_5F_instruction_i3_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
    break ;
  case 4 :
    rule_template_5F_parser_template_5F_instruction_i4_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
    break ;
  case 5 :
    rule_template_5F_parser_template_5F_instruction_i5_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
    break ;
  case 6 :
    rule_template_5F_parser_template_5F_instruction_i6_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
    break ;
  case 7 :
    rule_template_5F_parser_template_5F_instruction_i7_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
    break ;
  case 8 :
    rule_template_5F_parser_template_5F_instruction_i8_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
    break ;
  case 9 :
    rule_template_5F_parser_template_5F_instruction_i11_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
    break ;
  case 10 :
    rule_template_5F_parser_template_5F_instruction_i12_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
    break ;
  case 11 :
    rule_template_5F_parser_template_5F_instruction_i13_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
    break ;
  case 12 :
    rule_template_5F_parser_template_5F_instruction_i14_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
    break ;
  case 13 :
    rule_template_5F_parser_template_5F_instruction_i16_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
    break ;
  case 14 :
    rule_template_5F_parser_template_5F_instruction_i17_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
    break ;
  case 15 :
    rule_template_5F_parser_template_5F_instruction_i18_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
    break ;
  case 16 :
    rule_template_5F_parser_template_5F_instruction_i20_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
    break ;
  default :
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    'sorting_order' non terminal implementation                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_template_5F_grammar::nt_sorting_5F_order_parse (C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_parser_sorting_5F_order_i19_parse(inLexique) ;
}

void cGrammar_template_5F_grammar::nt_sorting_5F_order_ (GALGAS_lsint & parameter_1,
                                C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_parser_sorting_5F_order_i19_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       'variable' non terminal implementation                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_template_5F_grammar::nt_variable_parse (C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_parser_variable_i21_parse(inLexique) ;
}

void cGrammar_template_5F_grammar::nt_variable_ (const GALGAS_string parameter_1,
                                const GALGAS_string parameter_2,
                                const GALGAS_string parameter_3,
                                const GALGAS_TfieldMap parameter_4,
                                GALGAS_TvarPath & parameter_5,
                                C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_parser_variable_i21_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   'variable_or_here' non terminal implementation                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_template_5F_grammar::nt_variable_5F_or_5F_here_parse (C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_parser_variable_5F_or_5F_here_i15_parse(inLexique) ;
}

void cGrammar_template_5F_grammar::nt_variable_5F_or_5F_here_ (const GALGAS_string parameter_1,
                                const GALGAS_string parameter_2,
                                const GALGAS_string parameter_3,
                                const GALGAS_TfieldMap parameter_4,
                                GALGAS_location & parameter_5,
                                C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_parser_variable_5F_or_5F_here_i15_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      'expression' non terminal implementation                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_template_5F_grammar::nt_expression_parse (C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_expression_5F_parser_expression_i0_parse(inLexique) ;
}

void cGrammar_template_5F_grammar::nt_expression_ (const GALGAS_string parameter_1,
                                const GALGAS_string parameter_2,
                                const GALGAS_string parameter_3,
                                const GALGAS_TfieldMap parameter_4,
                                GALGAS_Tvalue & parameter_5,
                                GALGAS_Ttype & parameter_6,
                                C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_expression_5F_parser_expression_i0_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              'template_instruction_list' non terminal implementation                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_template_5F_grammar::nt_template_5F_instruction_5F_list_parse (C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_parser_template_5F_instruction_5F_list_i9_parse(inLexique) ;
}

void cGrammar_template_5F_grammar::nt_template_5F_instruction_5F_list_ (const GALGAS_string parameter_1,
                                const GALGAS_string parameter_2,
                                const GALGAS_string parameter_3,
                                GALGAS_TfieldMap & parameter_4,
                                GALGAS_string & parameter_5,
                                GALGAS_Tvalue & parameter_6,
                                GALGAS_Ttype & parameter_7,
                                C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_parser_template_5F_instruction_5F_list_i9_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, parameter_7, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  'template_file_name' non terminal implementation                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_template_5F_grammar::nt_template_5F_file_5F_name_parse (C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_parser_template_5F_file_5F_name_i2_parse(inLexique) ;
}

void cGrammar_template_5F_grammar::nt_template_5F_file_5F_name_ (const GALGAS_string parameter_1,
                                const GALGAS_string parameter_2,
                                const GALGAS_string parameter_3,
                                const GALGAS_TfieldMap parameter_4,
                                GALGAS_lstring & parameter_5,
                                C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_parser_template_5F_file_5F_name_i2_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    'relation_term' non terminal implementation                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_template_5F_grammar::nt_relation_5F_term_parse (C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_expression_5F_parser_relation_5F_term_i1_parse(inLexique) ;
}

void cGrammar_template_5F_grammar::nt_relation_5F_term_ (const GALGAS_string parameter_1,
                                const GALGAS_string parameter_2,
                                const GALGAS_string parameter_3,
                                const GALGAS_TfieldMap parameter_4,
                                GALGAS_Tvalue & parameter_5,
                                GALGAS_Ttype & parameter_6,
                                C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_expression_5F_parser_relation_5F_term_i1_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   'relation_factor' non terminal implementation                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_template_5F_grammar::nt_relation_5F_factor_parse (C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_expression_5F_parser_relation_5F_factor_i2_parse(inLexique) ;
}

void cGrammar_template_5F_grammar::nt_relation_5F_factor_ (const GALGAS_string parameter_1,
                                const GALGAS_string parameter_2,
                                const GALGAS_string parameter_3,
                                const GALGAS_TfieldMap parameter_4,
                                GALGAS_Tvalue & parameter_5,
                                GALGAS_Ttype & parameter_6,
                                C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_expression_5F_parser_relation_5F_factor_i2_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  'simple_expression' non terminal implementation                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_template_5F_grammar::nt_simple_5F_expression_parse (C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_expression_5F_parser_simple_5F_expression_i3_parse(inLexique) ;
}

void cGrammar_template_5F_grammar::nt_simple_5F_expression_ (const GALGAS_string parameter_1,
                                const GALGAS_string parameter_2,
                                const GALGAS_string parameter_3,
                                const GALGAS_TfieldMap parameter_4,
                                GALGAS_Tvalue & parameter_5,
                                GALGAS_Ttype & parameter_6,
                                C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_expression_5F_parser_simple_5F_expression_i3_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         'term' non terminal implementation                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_template_5F_grammar::nt_term_parse (C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_expression_5F_parser_term_i4_parse(inLexique) ;
}

void cGrammar_template_5F_grammar::nt_term_ (const GALGAS_string parameter_1,
                                const GALGAS_string parameter_2,
                                const GALGAS_string parameter_3,
                                const GALGAS_TfieldMap parameter_4,
                                GALGAS_Tvalue & parameter_5,
                                GALGAS_Ttype & parameter_6,
                                C_Lexique_template_5F_scanner * inLexique) {
  rule_template_5F_expression_5F_parser_term_i4_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        'factor' non terminal implementation                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_template_5F_grammar::nt_factor_parse (C_Lexique_template_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_template_5F_expression_5F_parser_factor_i5_parse(inLexique) ;
    break ;
  case 2 :
    rule_template_5F_expression_5F_parser_factor_i6_parse(inLexique) ;
    break ;
  case 3 :
    rule_template_5F_expression_5F_parser_factor_i7_parse(inLexique) ;
    break ;
  case 4 :
    rule_template_5F_expression_5F_parser_factor_i8_parse(inLexique) ;
    break ;
  case 5 :
    rule_template_5F_expression_5F_parser_factor_i9_parse(inLexique) ;
    break ;
  case 6 :
    rule_template_5F_expression_5F_parser_factor_i10_parse(inLexique) ;
    break ;
  case 7 :
    rule_template_5F_expression_5F_parser_factor_i11_parse(inLexique) ;
    break ;
  case 8 :
    rule_template_5F_expression_5F_parser_factor_i12_parse(inLexique) ;
    break ;
  case 9 :
    rule_template_5F_expression_5F_parser_factor_i13_parse(inLexique) ;
    break ;
  case 10 :
    rule_template_5F_expression_5F_parser_factor_i14_parse(inLexique) ;
    break ;
  case 11 :
    rule_template_5F_expression_5F_parser_factor_i15_parse(inLexique) ;
    break ;
  case 12 :
    rule_template_5F_expression_5F_parser_factor_i16_parse(inLexique) ;
    break ;
  case 13 :
    rule_template_5F_expression_5F_parser_factor_i17_parse(inLexique) ;
    break ;
  case 14 :
    rule_template_5F_expression_5F_parser_factor_i18_parse(inLexique) ;
    break ;
  case 15 :
    rule_template_5F_expression_5F_parser_factor_i19_parse(inLexique) ;
    break ;
  case 16 :
    rule_template_5F_expression_5F_parser_factor_i20_parse(inLexique) ;
    break ;
  case 17 :
    rule_template_5F_expression_5F_parser_factor_i21_parse(inLexique) ;
    break ;
  case 18 :
    rule_template_5F_expression_5F_parser_factor_i22_parse(inLexique) ;
    break ;
  case 19 :
    rule_template_5F_expression_5F_parser_factor_i23_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_template_5F_grammar::nt_factor_ (const GALGAS_string parameter_1,
                                const GALGAS_string parameter_2,
                                const GALGAS_string parameter_3,
                                const GALGAS_TfieldMap parameter_4,
                                GALGAS_Tvalue & parameter_5,
                                GALGAS_Ttype & parameter_6,
                                C_Lexique_template_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_template_5F_expression_5F_parser_factor_i5_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 2 :
    rule_template_5F_expression_5F_parser_factor_i6_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 3 :
    rule_template_5F_expression_5F_parser_factor_i7_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 4 :
    rule_template_5F_expression_5F_parser_factor_i8_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 5 :
    rule_template_5F_expression_5F_parser_factor_i9_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 6 :
    rule_template_5F_expression_5F_parser_factor_i10_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 7 :
    rule_template_5F_expression_5F_parser_factor_i11_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 8 :
    rule_template_5F_expression_5F_parser_factor_i12_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 9 :
    rule_template_5F_expression_5F_parser_factor_i13_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 10 :
    rule_template_5F_expression_5F_parser_factor_i14_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 11 :
    rule_template_5F_expression_5F_parser_factor_i15_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 12 :
    rule_template_5F_expression_5F_parser_factor_i16_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 13 :
    rule_template_5F_expression_5F_parser_factor_i17_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 14 :
    rule_template_5F_expression_5F_parser_factor_i18_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 15 :
    rule_template_5F_expression_5F_parser_factor_i19_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 16 :
    rule_template_5F_expression_5F_parser_factor_i20_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 17 :
    rule_template_5F_expression_5F_parser_factor_i21_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 18 :
    rule_template_5F_expression_5F_parser_factor_i22_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  case 19 :
    rule_template_5F_expression_5F_parser_factor_i23_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
    break ;
  default :
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_0' added non terminal implementation                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_0 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_1' added non terminal implementation                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_1 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_2' added non terminal implementation                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_2 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_3' added non terminal implementation                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_3 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_4' added non terminal implementation                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_4 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_5' added non terminal implementation                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_5 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_6' added non terminal implementation                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_6 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_7' added non terminal implementation                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_7 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_8' added non terminal implementation                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_8 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_9' added non terminal implementation                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_9 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_10' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_10 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_11' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_11 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_12' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_12 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_13' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_13 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_14' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_14 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_15' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_15 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_16' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_16 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_17' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_17 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_18' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_18 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_19' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_19 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_20' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_20 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_21' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_21 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_22' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_22 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_23' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_23 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_24' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_24 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_25' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_25 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_26' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_26 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_27' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_27 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          'select_template_5F_parser_28' added non terminal implementation                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_parser_28 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   'select_template_5F_expression_5F_parser_0' added non terminal implementation                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_expression_5F_parser_0 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   'select_template_5F_expression_5F_parser_1' added non terminal implementation                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_expression_5F_parser_1 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   'select_template_5F_expression_5F_parser_2' added non terminal implementation                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_expression_5F_parser_2 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   'select_template_5F_expression_5F_parser_3' added non terminal implementation                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_expression_5F_parser_3 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   'select_template_5F_expression_5F_parser_4' added non terminal implementation                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_expression_5F_parser_4 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   'select_template_5F_expression_5F_parser_5' added non terminal implementation                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_expression_5F_parser_5 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   'select_template_5F_expression_5F_parser_6' added non terminal implementation                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_expression_5F_parser_6 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   'select_template_5F_expression_5F_parser_7' added non terminal implementation                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_expression_5F_parser_7 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   'select_template_5F_expression_5F_parser_8' added non terminal implementation                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_expression_5F_parser_8 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   'select_template_5F_expression_5F_parser_9' added non terminal implementation                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_expression_5F_parser_9 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   'select_template_5F_expression_5F_parser_10' added non terminal implementation                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_template_5F_grammar::select_template_5F_expression_5F_parser_10 (C_Lexique_template_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*



//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_definition_i0_ (GALGAS_implementation & ioArgument_implementation,
                                                                                                       C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION) COMMA_SOURCE_FILE ("implementation_parser.galgas", 57)) ;
  GALGAS_lstring var_implementationName = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 57)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 57)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_0 (inCompiler)) {
    case 2: {
      nt_implementation_5F_objects_ (ioArgument_implementation, inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 59)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 61)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 61)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_definition_i0_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION) COMMA_SOURCE_FILE ("implementation_parser.galgas", 57)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 57)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 57)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_0 (inCompiler)) {
    case 2: {
      nt_implementation_5F_objects_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 59)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 61)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 61)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_objects_i1_ (GALGAS_implementation & ioArgument_implementation,
                                                                                                    C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_implementationMap var_imp = ioArgument_implementation.getter_imp (SOURCE_FILE ("implementation_parser.galgas", 89)) ;
  GALGAS_lstring var_objectName = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 91)) ;
  GALGAS_lbool var_multiple ;
  switch (select_implementation_5F_parser_1 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 95)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 95)) ;
    var_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (true), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 95))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 95)) ;
  } break ;
  case 2: {
    var_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (false), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 97))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 97)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_implementationObjectMap var_objectAttributes = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 100)) ;
  nt_implementation_5F_list_ (var_objectAttributes, inCompiler) ;
  GALGAS_implementationObject var_newObject = GALGAS_implementationObject::constructor_new (var_multiple, var_objectAttributes  COMMA_SOURCE_FILE ("implementation_parser.galgas", 103)) ;
  GALGAS_implementationObject var_object ;
  const enumGalgasBool test_0 = callCategoryGetter_hasKey ((const cPtr_implementation *) ioArgument_implementation.ptr (), var_objectName.getter_string (SOURCE_FILE ("implementation_parser.galgas", 108)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 108)).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    var_imp.modifier_del (var_objectName, var_object, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 109)) ;
    }
    var_object = callCategoryGetter_mergeImplementationObjectWith ((const cPtr_implementationObject *) var_object.ptr (), var_newObject, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 110)) ;
  }else if (kBoolFalse == test_0) {
    var_object = var_newObject ;
  }
  {
  var_imp.modifier_put (var_objectName, var_object, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 127)) ;
  }
  {
  ioArgument_implementation.modifier_setImp (var_imp COMMA_SOURCE_FILE ("implementation_parser.galgas", 128)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_objects_i1_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 91)) ;
  switch (select_implementation_5F_parser_1 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 95)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 95)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_implementation_5F_list_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_list_i2_ (GALGAS_implementationObjectMap & ioArgument_objectAttributes,
                                                                                                 C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 133)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_2 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_attributeName ;
      GALGAS_impType var_type ;
      nt_implementation_5F_type_ (var_attributeName, var_type, inCompiler) ;
      const enumGalgasBool test_1 = ioArgument_objectAttributes.getter_hasKey (var_attributeName.getter_string (SOURCE_FILE ("implementation_parser.galgas", 139)) COMMA_SOURCE_FILE ("implementation_parser.galgas", 139)).boolEnum () ;
      if (kBoolTrue == test_1) {
        GALGAS_impType var_previousType ;
        ioArgument_objectAttributes.method_get (var_attributeName, var_previousType, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 141)) ;
        const enumGalgasBool test_2 = function_checkNewTypeWithinPreviousType (var_attributeName, var_previousType, var_type, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 145)).boolEnum () ;
        if (kBoolTrue == test_2) {
          {
          GALGAS_impType joker_4619 ; // Joker input parameter
          ioArgument_objectAttributes.modifier_del (var_attributeName, joker_4619, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 148)) ;
          }
          {
          ioArgument_objectAttributes.modifier_put (var_attributeName, var_type, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 149)) ;
          }
        }
      }else if (kBoolFalse == test_1) {
        {
        ioArgument_objectAttributes.modifier_put (var_attributeName, var_type, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 152)) ;
        }
      }
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 154)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 156)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_list_i2_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 133)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_2 (inCompiler)) {
    case 2: {
      nt_implementation_5F_type_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 154)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 156)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_type_i3_ (GALGAS_lstring & outArgument_attributeName,
                                                                                                 GALGAS_impType & outArgument_type,
                                                                                                 C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_attributeName.drop () ; // Release 'out' argument
  outArgument_type.drop () ; // Release 'out' argument
  switch (select_implementation_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 163)) ;
    nt_number_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 163)), inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_33__32_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 165)) ;
    nt_number_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 165)), inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 167)) ;
    nt_number_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 167)), inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_36__34_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 169)) ;
    nt_number_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 169)), inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_FLOAT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 171)) ;
    nt_number_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_parser.galgas", 171)), inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ENUM) COMMA_SOURCE_FILE ("implementation_parser.galgas", 173)) ;
    nt_enum_5F_options_ (outArgument_attributeName, outArgument_type, inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_BOOLEAN) COMMA_SOURCE_FILE ("implementation_parser.galgas", 175)) ;
    nt_boolean_5F_options_ (outArgument_attributeName, outArgument_type, inCompiler) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRING) COMMA_SOURCE_FILE ("implementation_parser.galgas", 177)) ;
    nt_string_5F_options_ (outArgument_attributeName, outArgument_type, inCompiler) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER) COMMA_SOURCE_FILE ("implementation_parser.galgas", 179)) ;
    nt_type_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_identifier (SOURCE_FILE ("implementation_parser.galgas", 179)), inCompiler) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRUCT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 181)) ;
    nt_struct_5F_options_ (outArgument_attributeName, outArgument_type, inCompiler) ;
  } break ;
  case 11: {
    GALGAS_lstring var_typeName ;
    var_typeName = inCompiler->synthetizedAttribute_att_5F_token () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 183)) ;
    nt_objref_5F_option_ (outArgument_attributeName, outArgument_type, var_typeName, inCompiler) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_type_i3_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 163)) ;
    nt_number_5F_options_parse (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_33__32_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 165)) ;
    nt_number_5F_options_parse (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 167)) ;
    nt_number_5F_options_parse (inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_36__34_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 169)) ;
    nt_number_5F_options_parse (inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_FLOAT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 171)) ;
    nt_number_5F_options_parse (inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ENUM) COMMA_SOURCE_FILE ("implementation_parser.galgas", 173)) ;
    nt_enum_5F_options_parse (inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_BOOLEAN) COMMA_SOURCE_FILE ("implementation_parser.galgas", 175)) ;
    nt_boolean_5F_options_parse (inCompiler) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRING) COMMA_SOURCE_FILE ("implementation_parser.galgas", 177)) ;
    nt_string_5F_options_parse (inCompiler) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER) COMMA_SOURCE_FILE ("implementation_parser.galgas", 179)) ;
    nt_type_5F_options_parse (inCompiler) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRUCT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 181)) ;
    nt_struct_5F_options_parse (inCompiler) ;
  } break ;
  case 11: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 183)) ;
    nt_objref_5F_option_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_struct_5F_options_i4_ (GALGAS_lstring & outArgument_name,
                                                                                            GALGAS_impType & outArgument_options,
                                                                                            C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_implementationObjectMap var_structAttributes = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 190)) ;
  switch (select_implementation_5F_parser_4 (inCompiler)) {
  case 1: {
    nt_implementation_5F_list_ (var_structAttributes, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple ;
  nt_multiple_ (var_multiple, inCompiler) ;
  GALGAS_lstring var_description ;
  nt_description_ (var_description, inCompiler) ;
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 199)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 199))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 199)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 199)) ;
  temp_1.addAssign_operation (var_description  COMMA_SOURCE_FILE ("implementation_parser.galgas", 199)) ;
  outArgument_options = GALGAS_impStructType::constructor_new (temp_0, GALGAS_dataType::constructor_structType (SOURCE_FILE ("implementation_parser.galgas", 199)), outArgument_name, var_multiple, temp_1, var_structAttributes  COMMA_SOURCE_FILE ("implementation_parser.galgas", 199)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_struct_5F_options_i4_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_4 (inCompiler)) {
  case 1: {
    nt_implementation_5F_list_parse (inCompiler) ;
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

void cParser_implementation_5F_parser::rule_implementation_5F_parser_objref_5F_option_i5_ (GALGAS_lstring & outArgument_name,
                                                                                           GALGAS_impType & outArgument_options,
                                                                                           GALGAS_lstring inArgument_ref,
                                                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, inArgument_ref.getter_string (SOURCE_FILE ("implementation_parser.galgas", 206)).getter_rightSubString (GALGAS_uint ((uint32_t) 5U) COMMA_SOURCE_FILE ("implementation_parser.galgas", 206)).objectCompare (GALGAS_string ("_TYPE"))).boolEnum () ;
  if (kBoolTrue == test_0) {
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 207)), GALGAS_string ("an object reference must end with _TYPE")  COMMA_SOURCE_FILE ("implementation_parser.galgas", 207)) ;
  }else if (kBoolFalse == test_0) {
    inArgument_ref = GALGAS_lstring::constructor_new (inArgument_ref.mAttribute_string.getter_leftSubString (inArgument_ref.mAttribute_string.getter_length (SOURCE_FILE ("implementation_parser.galgas", 209)).substract_operation (GALGAS_uint ((uint32_t) 5U), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 209)) COMMA_SOURCE_FILE ("implementation_parser.galgas", 209)), inArgument_ref.getter_location (SOURCE_FILE ("implementation_parser.galgas", 209))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 209)) ;
  }
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple ;
  nt_multiple_ (var_multiple, inCompiler) ;
  GALGAS_lstring var_description ;
  nt_description_ (var_description, inCompiler) ;
  GALGAS_locationList temp_1 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 216)) ;
  temp_1.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 216))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 216)) ;
  GALGAS_lstringlist temp_2 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 216)) ;
  temp_2.addAssign_operation (var_description  COMMA_SOURCE_FILE ("implementation_parser.galgas", 216)) ;
  outArgument_options = GALGAS_refType::constructor_new (temp_1, GALGAS_dataType::constructor_objectType (SOURCE_FILE ("implementation_parser.galgas", 216)), outArgument_name, var_multiple, temp_2, inArgument_ref  COMMA_SOURCE_FILE ("implementation_parser.galgas", 216)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_objref_5F_option_i5_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  nt_description_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_string_5F_options_i6_ (GALGAS_lstring & outArgument_name,
                                                                                            GALGAS_impType & outArgument_options,
                                                                                            C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_bool var_withAuto ;
  nt_with_5F_auto_ (var_withAuto, inCompiler) ;
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple ;
  nt_multiple_ (var_multiple, inCompiler) ;
  GALGAS_object_5F_t var_defaultValue ;
  GALGAS_lstring var_oil_5F_desc ;
  switch (select_implementation_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 231)) ;
    switch (select_implementation_5F_parser_6 (inCompiler)) {
    case 1: {
      GALGAS_lstring var_stringValue = inCompiler->synthetizedAttribute_a_5F_string () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("implementation_parser.galgas", 233)) ;
      nt_description_ (var_oil_5F_desc, inCompiler) ;
      var_defaultValue = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc, var_stringValue.getter_location (SOURCE_FILE ("implementation_parser.galgas", 235)), var_stringValue.getter_string (SOURCE_FILE ("implementation_parser.galgas", 235))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 235)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 237)) ;
      nt_description_ (var_oil_5F_desc, inCompiler) ;
      var_defaultValue = GALGAS_auto::constructor_new (var_oil_5F_desc, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 239))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 239)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 241)) ;
      nt_description_ (var_oil_5F_desc, inCompiler) ;
      var_defaultValue = GALGAS_void::constructor_new (var_oil_5F_desc, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 243))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 243)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_ (var_oil_5F_desc, inCompiler) ;
    var_defaultValue = GALGAS_void::constructor_new (var_oil_5F_desc, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 247))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 247)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 249)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 249))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 249)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 249)) ;
  temp_1.addAssign_operation (var_oil_5F_desc  COMMA_SOURCE_FILE ("implementation_parser.galgas", 249)) ;
  outArgument_options = GALGAS_impAutoDefaultType::constructor_new (temp_0, GALGAS_dataType::constructor_string (SOURCE_FILE ("implementation_parser.galgas", 249)), outArgument_name, var_multiple, temp_1, var_withAuto, var_defaultValue  COMMA_SOURCE_FILE ("implementation_parser.galgas", 249)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_string_5F_options_i6_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_with_5F_auto_parse (inCompiler) ;
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  switch (select_implementation_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 231)) ;
    switch (select_implementation_5F_parser_6 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("implementation_parser.galgas", 233)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 237)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 241)) ;
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

void cParser_implementation_5F_parser::rule_implementation_5F_parser_boolean_5F_options_i7_ (GALGAS_lstring & outArgument_name,
                                                                                             GALGAS_impType & outArgument_options,
                                                                                             C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_bool var_withAuto ;
  nt_with_5F_auto_ (var_withAuto, inCompiler) ;
  GALGAS_implementationObjectMap var_trueSubAttributes = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 257)) ;
  GALGAS_implementationObjectMap var_falseSubAttributes = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 258)) ;
  switch (select_implementation_5F_parser_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 260)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) COMMA_SOURCE_FILE ("implementation_parser.galgas", 261)) ;
    switch (select_implementation_5F_parser_8 (inCompiler)) {
    case 1: {
      nt_implementation_5F_list_ (var_trueSubAttributes, inCompiler) ;
    } break ;
    case 2: {
      var_trueSubAttributes = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 265)) ;
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 267)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) COMMA_SOURCE_FILE ("implementation_parser.galgas", 268)) ;
    switch (select_implementation_5F_parser_9 (inCompiler)) {
    case 1: {
      nt_implementation_5F_list_ (var_falseSubAttributes, inCompiler) ;
    } break ;
    case 2: {
      var_falseSubAttributes = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 272)) ;
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 274)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple ;
  nt_multiple_ (var_multiple, inCompiler) ;
  GALGAS_object_5F_t var_defaultValue ;
  GALGAS_lstring var_oil_5F_desc ;
  switch (select_implementation_5F_parser_10 (inCompiler)) {
  case 1: {
    GALGAS_lbool var_boolValue ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 283)) ;
    nt_boolean_ (var_boolValue, inCompiler) ;
    nt_description_ (var_oil_5F_desc, inCompiler) ;
    var_defaultValue = GALGAS_boolAttribute::constructor_new (var_oil_5F_desc, var_boolValue.getter_location (SOURCE_FILE ("implementation_parser.galgas", 285)), var_boolValue.getter_bool (SOURCE_FILE ("implementation_parser.galgas", 285)), GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 285))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 285))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 285)) ;
  } break ;
  case 2: {
    nt_description_ (var_oil_5F_desc, inCompiler) ;
    var_defaultValue = GALGAS_void::constructor_new (var_oil_5F_desc, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 288))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 288)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 290)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 290))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 290)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 290)) ;
  temp_1.addAssign_operation (var_oil_5F_desc  COMMA_SOURCE_FILE ("implementation_parser.galgas", 290)) ;
  outArgument_options = GALGAS_impBoolType::constructor_new (temp_0, GALGAS_dataType::constructor_boolean (SOURCE_FILE ("implementation_parser.galgas", 290)), outArgument_name, var_multiple, temp_1, var_withAuto, var_defaultValue, var_trueSubAttributes, var_falseSubAttributes  COMMA_SOURCE_FILE ("implementation_parser.galgas", 290)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_boolean_5F_options_i7_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_with_5F_auto_parse (inCompiler) ;
  switch (select_implementation_5F_parser_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 260)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) COMMA_SOURCE_FILE ("implementation_parser.galgas", 261)) ;
    switch (select_implementation_5F_parser_8 (inCompiler)) {
    case 1: {
      nt_implementation_5F_list_parse (inCompiler) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 267)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) COMMA_SOURCE_FILE ("implementation_parser.galgas", 268)) ;
    switch (select_implementation_5F_parser_9 (inCompiler)) {
    case 1: {
      nt_implementation_5F_list_parse (inCompiler) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 274)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  switch (select_implementation_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 283)) ;
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

void cParser_implementation_5F_parser::rule_implementation_5F_parser_enum_5F_item_i8_ (GALGAS_enumValues & ioArgument_items,
                                                                                       C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_lstring var_enumItem ;
  GALGAS_implementationObjectMap var_subAttributes = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 296)) ;
  nt_identifier_5F_or_5F_enum_5F_value_ (var_enumItem, inCompiler) ;
  switch (select_implementation_5F_parser_11 (inCompiler)) {
  case 1: {
    nt_implementation_5F_list_ (var_subAttributes, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  {
  ioArgument_items.modifier_put (var_enumItem, var_subAttributes, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 301)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_enum_5F_item_i8_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_identifier_5F_or_5F_enum_5F_value_parse (inCompiler) ;
  switch (select_implementation_5F_parser_11 (inCompiler)) {
  case 1: {
    nt_implementation_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_enum_5F_options_i9_ (GALGAS_lstring & outArgument_name,
                                                                                          GALGAS_impType & outArgument_options,
                                                                                          C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_bool var_withAuto ;
  nt_with_5F_auto_ (var_withAuto, inCompiler) ;
  GALGAS_enumValues var_items = GALGAS_enumValues::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 309)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 310)) ;
  nt_enum_5F_item_ (var_items, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_12 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 314)) ;
      nt_enum_5F_item_ (var_items, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 316)) ;
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple ;
  nt_multiple_ (var_multiple, inCompiler) ;
  GALGAS_lstring var_oil_5F_desc ;
  GALGAS_object_5F_t var_defaultValue ;
  switch (select_implementation_5F_parser_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 323)) ;
    switch (select_implementation_5F_parser_14 (inCompiler)) {
    case 1: {
      GALGAS_lstring var_stringValue ;
      var_stringValue = inCompiler->synthetizedAttribute_att_5F_token () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 326)) ;
      nt_description_ (var_oil_5F_desc, inCompiler) ;
      var_defaultValue = GALGAS_enumAttribute::constructor_new (var_oil_5F_desc, var_stringValue.getter_location (SOURCE_FILE ("implementation_parser.galgas", 328)), var_stringValue.getter_string (SOURCE_FILE ("implementation_parser.galgas", 328)), GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 328))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 328))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 328)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 330)) ;
      nt_description_ (var_oil_5F_desc, inCompiler) ;
      var_defaultValue = GALGAS_auto::constructor_new (var_oil_5F_desc, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 332))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 332)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 334)) ;
      nt_description_ (var_oil_5F_desc, inCompiler) ;
      var_defaultValue = GALGAS_void::constructor_new (var_oil_5F_desc, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 336))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 336)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_ (var_oil_5F_desc, inCompiler) ;
    var_defaultValue = GALGAS_void::constructor_new (var_oil_5F_desc, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 340))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 340)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_locationList temp_1 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 342)) ;
  temp_1.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 342))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 342)) ;
  GALGAS_lstringlist temp_2 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 342)) ;
  temp_2.addAssign_operation (var_oil_5F_desc  COMMA_SOURCE_FILE ("implementation_parser.galgas", 342)) ;
  outArgument_options = GALGAS_impEnumType::constructor_new (temp_1, GALGAS_dataType::constructor_enumeration (SOURCE_FILE ("implementation_parser.galgas", 342)), outArgument_name, var_multiple, temp_2, var_withAuto, var_defaultValue, var_items  COMMA_SOURCE_FILE ("implementation_parser.galgas", 342)) ;
  {
  routine_verifyEnum (outArgument_options, inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 343)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_enum_5F_options_i9_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_with_5F_auto_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 310)) ;
  nt_enum_5F_item_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_12 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 314)) ;
      nt_enum_5F_item_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 316)) ;
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  switch (select_implementation_5F_parser_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 323)) ;
    switch (select_implementation_5F_parser_14 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 326)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 330)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 334)) ;
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

void cParser_implementation_5F_parser::rule_implementation_5F_parser_number_5F_options_i10_ (GALGAS_lstring & outArgument_name,
                                                                                             GALGAS_impType & outArgument_options,
                                                                                             const GALGAS_dataType constinArgument_type,
                                                                                             C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_bool var_withAuto ;
  nt_with_5F_auto_ (var_withAuto, inCompiler) ;
  GALGAS_attributeRange var_range ;
  nt_range_ (var_range, constinArgument_type, inCompiler) ;
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple ;
  nt_multiple_ (var_multiple, inCompiler) ;
  GALGAS_lstring var_oil_5F_desc ;
  GALGAS_object_5F_t var_defaultValue ;
  switch (select_implementation_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 360)) ;
    switch (select_implementation_5F_parser_16 (inCompiler)) {
    case 1: {
      nt_int_5F_or_5F_float_ (var_defaultValue, constinArgument_type, inCompiler) ;
      var_oil_5F_desc = var_defaultValue.getter_oil_5F_desc (SOURCE_FILE ("implementation_parser.galgas", 363)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 365)) ;
      nt_description_ (var_oil_5F_desc, inCompiler) ;
      var_defaultValue = GALGAS_void::constructor_new (var_oil_5F_desc, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 367))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 367)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 369)) ;
      nt_description_ (var_oil_5F_desc, inCompiler) ;
      var_defaultValue = GALGAS_auto::constructor_new (var_oil_5F_desc, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 371))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 371)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_ (var_oil_5F_desc, inCompiler) ;
    var_defaultValue = GALGAS_void::constructor_new (var_oil_5F_desc, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 375))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 375)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 377)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 377))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 377)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 377)) ;
  temp_1.addAssign_operation (var_oil_5F_desc  COMMA_SOURCE_FILE ("implementation_parser.galgas", 377)) ;
  outArgument_options = GALGAS_impRangedType::constructor_new (temp_0, constinArgument_type, outArgument_name, var_multiple, temp_1, var_withAuto, var_defaultValue, var_range  COMMA_SOURCE_FILE ("implementation_parser.galgas", 377)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_number_5F_options_i10_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_with_5F_auto_parse (inCompiler) ;
  nt_range_parse (inCompiler) ;
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  switch (select_implementation_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 360)) ;
    switch (select_implementation_5F_parser_16 (inCompiler)) {
    case 1: {
      nt_int_5F_or_5F_float_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 365)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 369)) ;
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

void cParser_implementation_5F_parser::rule_implementation_5F_parser_type_5F_options_i11_ (GALGAS_lstring & outArgument_name,
                                                                                           GALGAS_impType & outArgument_options,
                                                                                           const GALGAS_dataType constinArgument_type,
                                                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_bool var_withAuto ;
  nt_with_5F_auto_ (var_withAuto, inCompiler) ;
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple ;
  nt_multiple_ (var_multiple, inCompiler) ;
  GALGAS_object_5F_t var_defaultValue ;
  GALGAS_lstring var_oil_5F_desc ;
  switch (select_implementation_5F_parser_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 392)) ;
    switch (select_implementation_5F_parser_18 (inCompiler)) {
    case 1: {
      GALGAS_lstring var_ident ;
      nt_identifier_5F_or_5F_attribute_ (var_ident, inCompiler) ;
      nt_description_ (var_oil_5F_desc, inCompiler) ;
      var_defaultValue = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 397)), var_ident.getter_string (SOURCE_FILE ("implementation_parser.galgas", 397))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 397)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 399)) ;
      nt_description_ (var_oil_5F_desc, inCompiler) ;
      var_defaultValue = GALGAS_void::constructor_new (var_oil_5F_desc, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 401))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 401)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 403)) ;
      nt_description_ (var_oil_5F_desc, inCompiler) ;
      var_defaultValue = GALGAS_auto::constructor_new (var_oil_5F_desc, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 405))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 405)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_ (var_oil_5F_desc, inCompiler) ;
    var_defaultValue = GALGAS_void::constructor_new (var_oil_5F_desc, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 409))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 409)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 411)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 411))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 411)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 411)) ;
  temp_1.addAssign_operation (var_oil_5F_desc  COMMA_SOURCE_FILE ("implementation_parser.galgas", 411)) ;
  outArgument_options = GALGAS_impAutoDefaultType::constructor_new (temp_0, constinArgument_type, outArgument_name, var_multiple, temp_1, var_withAuto, var_defaultValue  COMMA_SOURCE_FILE ("implementation_parser.galgas", 411)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_type_5F_options_i11_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_with_5F_auto_parse (inCompiler) ;
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  switch (select_implementation_5F_parser_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 392)) ;
    switch (select_implementation_5F_parser_18 (inCompiler)) {
    case 1: {
      nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 399)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 403)) ;
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

void cParser_implementation_5F_parser::rule_implementation_5F_parser_with_5F_auto_i12_ (GALGAS_bool & outArgument_withAuto,
                                                                                        C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_withAuto.drop () ; // Release 'out' argument
  switch (select_implementation_5F_parser_19 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 417)) ;
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

void cParser_implementation_5F_parser::rule_implementation_5F_parser_with_5F_auto_i12_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_19 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 417)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_int_5F_or_5F_float_i13_ (GALGAS_object_5F_t & outArgument_num,
                                                                                              const GALGAS_dataType constinArgument_type,
                                                                                              C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_num.drop () ; // Release 'out' argument
  GALGAS_bool var_signed ;
  nt_sign_ (var_signed, inCompiler) ;
  switch (select_implementation_5F_parser_20 (inCompiler)) {
  case 1: {
    GALGAS_luint_36__34_ var_number ;
    var_number = inCompiler->synthetizedAttribute_integerNumber () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 430)) ;
    GALGAS_lstring var_oil_5F_desc ;
    nt_description_ (var_oil_5F_desc, inCompiler) ;
    outArgument_num = function_checkAndGetIntegerNumber (var_oil_5F_desc, constinArgument_type, var_number, var_signed, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 432)) ;
  } break ;
  case 2: {
    GALGAS_ldouble var_number ;
    var_number = inCompiler->synthetizedAttribute_floatNumber () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 435)) ;
    GALGAS_lstring var_oil_5F_desc ;
    nt_description_ (var_oil_5F_desc, inCompiler) ;
    outArgument_num = function_checkAndGetFloatNumber (var_oil_5F_desc, constinArgument_type, var_number, var_signed, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 437)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_int_5F_or_5F_float_i13_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_sign_parse (inCompiler) ;
  switch (select_implementation_5F_parser_20 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 430)) ;
    nt_description_parse (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 435)) ;
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_set_5F_followup_i14_ (GALGAS_numberList & ioArgument_numbers,
                                                                                           const GALGAS_dataType constinArgument_type,
                                                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_21 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 446)) ;
      GALGAS_object_5F_t var_num ;
      nt_int_5F_or_5F_float_ (var_num, constinArgument_type, inCompiler) ;
      ioArgument_numbers.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 449)), var_num  COMMA_SOURCE_FILE ("implementation_parser.galgas", 449)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_set_5F_followup_i14_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_21 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 446)) ;
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

void cParser_implementation_5F_parser::rule_implementation_5F_parser_range_5F_content_i15_ (GALGAS_attributeRange & outArgument_range,
                                                                                            const GALGAS_dataType constinArgument_type,
                                                                                            C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_range.drop () ; // Release 'out' argument
  GALGAS_object_5F_t var_start = GALGAS_void::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 456)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 456))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 456)) ;
  GALGAS_object_5F_t var_stop = GALGAS_void::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 457)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 457))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 457)) ;
  GALGAS_bool var_signed ;
  nt_sign_ (var_signed, inCompiler) ;
  switch (select_implementation_5F_parser_22 (inCompiler)) {
  case 1: {
    GALGAS_luint_36__34_ var_number ;
    var_number = inCompiler->synthetizedAttribute_integerNumber () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 462)) ;
    var_start = function_checkAndGetIntegerNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 463)), constinArgument_type, var_number, var_signed, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 463)) ;
    nt_int_5F_or_5F_float_ (var_stop, constinArgument_type, inCompiler) ;
    outArgument_range = function_buildRange (constinArgument_type, var_start, var_stop, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 465)) ;
  } break ;
  case 2: {
    GALGAS_luint_36__34_ var_number ;
    var_number = inCompiler->synthetizedAttribute_integerNumber () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 468)) ;
    var_start = function_checkAndGetIntegerNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 469)), constinArgument_type, var_number, var_signed, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 469)) ;
    switch (select_implementation_5F_parser_23 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 471)) ;
      nt_int_5F_or_5F_float_ (var_stop, constinArgument_type, inCompiler) ;
      outArgument_range = function_buildRange (constinArgument_type, var_start, var_stop, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 472)) ;
    } break ;
    case 2: {
      GALGAS_numberList var_numbers = GALGAS_numberList::constructor_listWithValue (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 474)), var_start  COMMA_SOURCE_FILE ("implementation_parser.galgas", 474)) ;
      nt_set_5F_followup_ (var_numbers, constinArgument_type, inCompiler) ;
      outArgument_range = function_attributeRangeWithNumberList (var_numbers, constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 476)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 3: {
    GALGAS_ldouble var_number ;
    var_number = inCompiler->synthetizedAttribute_floatNumber () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 480)) ;
    var_start = function_checkAndGetFloatNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 481)), constinArgument_type, var_number, var_signed, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 481)) ;
    switch (select_implementation_5F_parser_24 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 483)) ;
      nt_int_5F_or_5F_float_ (var_stop, constinArgument_type, inCompiler) ;
      outArgument_range = function_buildRange (constinArgument_type, var_start, var_stop, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 484)) ;
    } break ;
    case 2: {
      GALGAS_numberList var_numbers = GALGAS_numberList::constructor_listWithValue (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 486)), var_start  COMMA_SOURCE_FILE ("implementation_parser.galgas", 486)) ;
      nt_set_5F_followup_ (var_numbers, constinArgument_type, inCompiler) ;
      outArgument_range = function_attributeRangeWithNumberList (var_numbers, constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 488)) ;
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

void cParser_implementation_5F_parser::rule_implementation_5F_parser_range_5F_content_i15_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_sign_parse (inCompiler) ;
  switch (select_implementation_5F_parser_22 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 462)) ;
    nt_int_5F_or_5F_float_parse (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 468)) ;
    switch (select_implementation_5F_parser_23 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 471)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 480)) ;
    switch (select_implementation_5F_parser_24 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 483)) ;
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

void cParser_implementation_5F_parser::rule_implementation_5F_parser_range_i16_ (GALGAS_attributeRange & outArgument_range,
                                                                                 const GALGAS_dataType constinArgument_rangeType,
                                                                                 C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_range.drop () ; // Release 'out' argument
  switch (select_implementation_5F_parser_25 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 497)) ;
    nt_range_5F_content_ (outArgument_range, constinArgument_rangeType, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 497)) ;
  } break ;
  case 2: {
    outArgument_range = GALGAS_noRange::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 499))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 499)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_range_i16_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_25 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 497)) ;
    nt_range_5F_content_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 497)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_multiple_i17_ (GALGAS_bool & outArgument_multi,
                                                                                    C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_multi.drop () ; // Release 'out' argument
  switch (select_implementation_5F_parser_26 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 506)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 506)) ;
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

void cParser_implementation_5F_parser::rule_implementation_5F_parser_multiple_i17_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_26 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 506)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 506)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i18_ (GALGAS_lstring & outArgument_name,
                                                                                                         C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_name = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 515)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i18_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 515)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i19_ (GALGAS_lstring & outArgument_name,
                                                                                                             C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_name = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 523)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i19_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 523)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int16_t gProductions_goil_file_level_include [] = {
// At index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 55
  TERMINAL (C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION) // $IMPLEMENTATION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (46) // <select_implementation_5F_parser_0>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 7 : <start>, in file 'goil_syntax.ggs', line 38
, NONTERMINAL (5) // <OIL_version>
, NONTERMINAL (2) // <file>
, END_PRODUCTION
// At index 10 : <file>, in file 'goil_syntax.ggs', line 110
, NONTERMINAL (32) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 12 : <sign>, in file 'goil_syntax.ggs', line 126
, NONTERMINAL (33) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 14 : <description>, in file 'goil_syntax.ggs', line 139
, NONTERMINAL (34) // <select_goil_5F_syntax_2>
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
, NONTERMINAL (36) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 32 : <boolean>, in file 'goil_syntax.ggs', line 230
, NONTERMINAL (37) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 34 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
, NONTERMINAL (38) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 36 : <oil_declaration>, in file 'goil_syntax.ggs', line 249
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (39) // <select_goil_5F_syntax_7>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 40 : <include_file_level>, in file 'goil_syntax.ggs', line 422
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, NONTERMINAL (44) // <select_goil_5F_syntax_12>
, END_PRODUCTION
// At index 43 : <include_cpu_level>, in file 'goil_syntax.ggs', line 439
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, NONTERMINAL (45) // <select_goil_5F_syntax_13>
, END_PRODUCTION
// At index 46 : <implementation_objects>, in file 'implementation_parser.ggs', line 86
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (47) // <select_implementation_5F_parser_1>
, NONTERMINAL (14) // <implementation_list>
, END_PRODUCTION
// At index 50 : <implementation_list>, in file 'implementation_parser.ggs', line 131
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (48) // <select_implementation_5F_parser_2>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 54 : <implementation_type>, in file 'implementation_parser.ggs', line 159
, NONTERMINAL (49) // <select_implementation_5F_parser_3>
, END_PRODUCTION
// At index 56 : <struct_options>, in file 'implementation_parser.ggs', line 187
, NONTERMINAL (50) // <select_implementation_5F_parser_4>
, NONTERMINAL (30) // <identifier_or_attribute>
, NONTERMINAL (29) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 61 : <objref_option>, in file 'implementation_parser.ggs', line 202
, NONTERMINAL (30) // <identifier_or_attribute>
, NONTERMINAL (29) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 65 : <string_options>, in file 'implementation_parser.ggs', line 220
, NONTERMINAL (24) // <with_auto>
, NONTERMINAL (30) // <identifier_or_attribute>
, NONTERMINAL (29) // <multiple>
, NONTERMINAL (51) // <select_implementation_5F_parser_5>
, END_PRODUCTION
// At index 70 : <boolean_options>, in file 'implementation_parser.ggs', line 252
, NONTERMINAL (24) // <with_auto>
, NONTERMINAL (53) // <select_implementation_5F_parser_7>
, NONTERMINAL (30) // <identifier_or_attribute>
, NONTERMINAL (29) // <multiple>
, NONTERMINAL (56) // <select_implementation_5F_parser_10>
, END_PRODUCTION
// At index 76 : <enum_item>, in file 'implementation_parser.ggs', line 293
, NONTERMINAL (31) // <identifier_or_enum_value>
, NONTERMINAL (57) // <select_implementation_5F_parser_11>
, END_PRODUCTION
// At index 79 : <enum_options>, in file 'implementation_parser.ggs', line 304
, NONTERMINAL (24) // <with_auto>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (20) // <enum_item>
, NONTERMINAL (58) // <select_implementation_5F_parser_12>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, NONTERMINAL (30) // <identifier_or_attribute>
, NONTERMINAL (29) // <multiple>
, NONTERMINAL (59) // <select_implementation_5F_parser_13>
, END_PRODUCTION
// At index 88 : <number_options>, in file 'implementation_parser.ggs', line 346
, NONTERMINAL (24) // <with_auto>
, NONTERMINAL (28) // <range>
, NONTERMINAL (30) // <identifier_or_attribute>
, NONTERMINAL (29) // <multiple>
, NONTERMINAL (61) // <select_implementation_5F_parser_15>
, END_PRODUCTION
// At index 94 : <type_options>, in file 'implementation_parser.ggs', line 380
, NONTERMINAL (24) // <with_auto>
, NONTERMINAL (30) // <identifier_or_attribute>
, NONTERMINAL (29) // <multiple>
, NONTERMINAL (63) // <select_implementation_5F_parser_17>
, END_PRODUCTION
// At index 99 : <with_auto>, in file 'implementation_parser.ggs', line 414
, NONTERMINAL (65) // <select_implementation_5F_parser_19>
, END_PRODUCTION
// At index 101 : <int_or_float>, in file 'implementation_parser.ggs', line 423
, NONTERMINAL (3) // <sign>
, NONTERMINAL (66) // <select_implementation_5F_parser_20>
, END_PRODUCTION
// At index 104 : <set_followup>, in file 'implementation_parser.ggs', line 441
, NONTERMINAL (67) // <select_implementation_5F_parser_21>
, END_PRODUCTION
// At index 106 : <range_content>, in file 'implementation_parser.ggs', line 453
, NONTERMINAL (3) // <sign>
, NONTERMINAL (68) // <select_implementation_5F_parser_22>
, END_PRODUCTION
// At index 109 : <range>, in file 'implementation_parser.ggs', line 493
, NONTERMINAL (71) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 111 : <multiple>, in file 'implementation_parser.ggs', line 503
, NONTERMINAL (72) // <select_implementation_5F_parser_26>
, END_PRODUCTION
// At index 113 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 513
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
// At index 115 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 518
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 117 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, END_PRODUCTION
// At index 118 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (11) // <include_file_level>
, NONTERMINAL (32) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 121 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (32) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 124 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (6) // <application_definition>
, NONTERMINAL (32) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 127 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) // $-$
, END_PRODUCTION
// At index 129 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) // $+$
, END_PRODUCTION
// At index 131 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, END_PRODUCTION
// At index 132 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, END_PRODUCTION
// At index 133 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) // $:$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (35) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 137 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, END_PRODUCTION
// At index 138 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (35) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 141 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, END_PRODUCTION
// At index 142 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (36) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 151 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, NONTERMINAL (12) // <include_cpu_level>
, NONTERMINAL (36) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 154 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 156 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 158 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 243
, END_PRODUCTION
// At index 159 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 243
, NONTERMINAL (10) // <oil_declaration>
, NONTERMINAL (38) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 162 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 266
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (40) // <select_goil_5F_syntax_8>
, END_PRODUCTION
// At index 165 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 266
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 171 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (41) // <select_goil_5F_syntax_9>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 175 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
, NONTERMINAL (3) // <sign>
, NONTERMINAL (42) // <select_goil_5F_syntax_10>
, END_PRODUCTION
// At index 178 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (43) // <select_goil_5F_syntax_11>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 182 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 185 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 188 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 289
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 192 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 289
, END_PRODUCTION
// At index 193 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 306
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 196 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 306
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 199 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 337
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 203 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 337
, END_PRODUCTION
// At index 204 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 430
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 206 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 430
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 208 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 447
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 210 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 447
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 212 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 58
, END_PRODUCTION
// At index 213 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 58
, NONTERMINAL (13) // <implementation_objects>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (46) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 217 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 93
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 220 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 93
, END_PRODUCTION
// At index 221 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 134
, END_PRODUCTION
// At index 222 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 134
, NONTERMINAL (15) // <implementation_type>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (48) // <select_implementation_5F_parser_2>
, END_PRODUCTION
// At index 226 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_) // $UINT32$
, NONTERMINAL (22) // <number_options>
, END_PRODUCTION
// At index 229 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_33__32_) // $INT32$
, NONTERMINAL (22) // <number_options>
, END_PRODUCTION
// At index 232 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_) // $UINT64$
, NONTERMINAL (22) // <number_options>
, END_PRODUCTION
// At index 235 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_36__34_) // $INT64$
, NONTERMINAL (22) // <number_options>
, END_PRODUCTION
// At index 238 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FLOAT) // $FLOAT$
, NONTERMINAL (22) // <number_options>
, END_PRODUCTION
// At index 241 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_ENUM) // $ENUM$
, NONTERMINAL (21) // <enum_options>
, END_PRODUCTION
// At index 244 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_BOOLEAN) // $BOOLEAN$
, NONTERMINAL (19) // <boolean_options>
, END_PRODUCTION
// At index 247 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRING) // $STRING$
, NONTERMINAL (18) // <string_options>
, END_PRODUCTION
// At index 250 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER) // $IDENTIFIER$
, NONTERMINAL (23) // <type_options>
, END_PRODUCTION
// At index 253 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRUCT) // $STRUCT$
, NONTERMINAL (16) // <struct_options>
, END_PRODUCTION
// At index 256 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (17) // <objref_option>
, END_PRODUCTION
// At index 259 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 191
, NONTERMINAL (14) // <implementation_list>
, END_PRODUCTION
// At index 261 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 191
, END_PRODUCTION
// At index 262 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 230
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (52) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 265 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 230
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 267 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 232
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 270 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 232
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 273 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 232
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 276 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 259
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, NONTERMINAL (54) // <select_implementation_5F_parser_8>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, NONTERMINAL (55) // <select_implementation_5F_parser_9>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 284 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 259
, END_PRODUCTION
// At index 285 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 262
, NONTERMINAL (14) // <implementation_list>
, END_PRODUCTION
// At index 287 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 262
, END_PRODUCTION
// At index 288 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 269
, NONTERMINAL (14) // <implementation_list>
, END_PRODUCTION
// At index 290 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 269
, END_PRODUCTION
// At index 291 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 281
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 295 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 281
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 297 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 298
, NONTERMINAL (14) // <implementation_list>
, END_PRODUCTION
// At index 299 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 298
, END_PRODUCTION
// At index 300 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 312
, END_PRODUCTION
// At index 301 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 312
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (20) // <enum_item>
, NONTERMINAL (58) // <select_implementation_5F_parser_12>
, END_PRODUCTION
// At index 305 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 322
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (60) // <select_implementation_5F_parser_14>
, END_PRODUCTION
// At index 308 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 322
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 310 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 324
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 313 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 324
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 316 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 324
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 319 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 359
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (62) // <select_implementation_5F_parser_16>
, END_PRODUCTION
// At index 322 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 359
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 324 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 361
, NONTERMINAL (25) // <int_or_float>
, END_PRODUCTION
// At index 326 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 361
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 329 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 361
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 332 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 391
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (64) // <select_implementation_5F_parser_18>
, END_PRODUCTION
// At index 335 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 391
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 337 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 393
, NONTERMINAL (30) // <identifier_or_attribute>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 340 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 393
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 343 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 393
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 346 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 416
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO) // $WITH_AUTO$
, END_PRODUCTION
// At index 348 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 416
, END_PRODUCTION
// At index 349 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 428
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 352 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 428
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 355 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 444
, END_PRODUCTION
// At index 356 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 444
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (25) // <int_or_float>
, NONTERMINAL (67) // <select_implementation_5F_parser_21>
, END_PRODUCTION
// At index 360 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 460
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number) // $set_start_uint_number$
, NONTERMINAL (25) // <int_or_float>
, END_PRODUCTION
// At index 363 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 460
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (69) // <select_implementation_5F_parser_23>
, END_PRODUCTION
// At index 366 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 460
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (70) // <select_implementation_5F_parser_24>
, END_PRODUCTION
// At index 369 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 470
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (25) // <int_or_float>
, END_PRODUCTION
// At index 372 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 470
, NONTERMINAL (26) // <set_followup>
, END_PRODUCTION
// At index 374 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 482
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (25) // <int_or_float>
, END_PRODUCTION
// At index 377 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 482
, NONTERMINAL (26) // <set_followup>
, END_PRODUCTION
// At index 379 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 496
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (27) // <range_content>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 383 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 496
, END_PRODUCTION
// At index 384 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 505
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 387 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 505
, END_PRODUCTION
// At index 388 : <>, in file '.ggs', line 0
, NONTERMINAL (2) // <file>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          P R O D U C T I O N    N A M E S                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_goil_file_level_include [136] = {
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
 {"<implementation_objects>", "implementation_parser", 46}, // at index 13
 {"<implementation_list>", "implementation_parser", 50}, // at index 14
 {"<implementation_type>", "implementation_parser", 54}, // at index 15
 {"<struct_options>", "implementation_parser", 56}, // at index 16
 {"<objref_option>", "implementation_parser", 61}, // at index 17
 {"<string_options>", "implementation_parser", 65}, // at index 18
 {"<boolean_options>", "implementation_parser", 70}, // at index 19
 {"<enum_item>", "implementation_parser", 76}, // at index 20
 {"<enum_options>", "implementation_parser", 79}, // at index 21
 {"<number_options>", "implementation_parser", 88}, // at index 22
 {"<type_options>", "implementation_parser", 94}, // at index 23
 {"<with_auto>", "implementation_parser", 99}, // at index 24
 {"<int_or_float>", "implementation_parser", 101}, // at index 25
 {"<set_followup>", "implementation_parser", 104}, // at index 26
 {"<range_content>", "implementation_parser", 106}, // at index 27
 {"<range>", "implementation_parser", 109}, // at index 28
 {"<multiple>", "implementation_parser", 111}, // at index 29
 {"<identifier_or_attribute>", "implementation_parser", 113}, // at index 30
 {"<identifier_or_enum_value>", "implementation_parser", 115}, // at index 31
 {"<select_goil_5F_syntax_0>", "goil_syntax", 117}, // at index 32
 {"<select_goil_5F_syntax_0>", "goil_syntax", 118}, // at index 33
 {"<select_goil_5F_syntax_0>", "goil_syntax", 121}, // at index 34
 {"<select_goil_5F_syntax_0>", "goil_syntax", 124}, // at index 35
 {"<select_goil_5F_syntax_1>", "goil_syntax", 127}, // at index 36
 {"<select_goil_5F_syntax_1>", "goil_syntax", 129}, // at index 37
 {"<select_goil_5F_syntax_1>", "goil_syntax", 131}, // at index 38
 {"<select_goil_5F_syntax_2>", "goil_syntax", 132}, // at index 39
 {"<select_goil_5F_syntax_2>", "goil_syntax", 133}, // at index 40
 {"<select_goil_5F_syntax_3>", "goil_syntax", 137}, // at index 41
 {"<select_goil_5F_syntax_3>", "goil_syntax", 138}, // at index 42
 {"<select_goil_5F_syntax_4>", "goil_syntax", 141}, // at index 43
 {"<select_goil_5F_syntax_4>", "goil_syntax", 142}, // at index 44
 {"<select_goil_5F_syntax_4>", "goil_syntax", 151}, // at index 45
 {"<select_goil_5F_syntax_5>", "goil_syntax", 154}, // at index 46
 {"<select_goil_5F_syntax_5>", "goil_syntax", 156}, // at index 47
 {"<select_goil_5F_syntax_6>", "goil_syntax", 158}, // at index 48
 {"<select_goil_5F_syntax_6>", "goil_syntax", 159}, // at index 49
 {"<select_goil_5F_syntax_7>", "goil_syntax", 162}, // at index 50
 {"<select_goil_5F_syntax_7>", "goil_syntax", 165}, // at index 51
 {"<select_goil_5F_syntax_8>", "goil_syntax", 171}, // at index 52
 {"<select_goil_5F_syntax_8>", "goil_syntax", 175}, // at index 53
 {"<select_goil_5F_syntax_8>", "goil_syntax", 178}, // at index 54
 {"<select_goil_5F_syntax_8>", "goil_syntax", 182}, // at index 55
 {"<select_goil_5F_syntax_8>", "goil_syntax", 185}, // at index 56
 {"<select_goil_5F_syntax_9>", "goil_syntax", 188}, // at index 57
 {"<select_goil_5F_syntax_9>", "goil_syntax", 192}, // at index 58
 {"<select_goil_5F_syntax_10>", "goil_syntax", 193}, // at index 59
 {"<select_goil_5F_syntax_10>", "goil_syntax", 196}, // at index 60
 {"<select_goil_5F_syntax_11>", "goil_syntax", 199}, // at index 61
 {"<select_goil_5F_syntax_11>", "goil_syntax", 203}, // at index 62
 {"<select_goil_5F_syntax_12>", "goil_syntax", 204}, // at index 63
 {"<select_goil_5F_syntax_12>", "goil_syntax", 206}, // at index 64
 {"<select_goil_5F_syntax_13>", "goil_syntax", 208}, // at index 65
 {"<select_goil_5F_syntax_13>", "goil_syntax", 210}, // at index 66
 {"<select_implementation_5F_parser_0>", "implementation_parser", 212}, // at index 67
 {"<select_implementation_5F_parser_0>", "implementation_parser", 213}, // at index 68
 {"<select_implementation_5F_parser_1>", "implementation_parser", 217}, // at index 69
 {"<select_implementation_5F_parser_1>", "implementation_parser", 220}, // at index 70
 {"<select_implementation_5F_parser_2>", "implementation_parser", 221}, // at index 71
 {"<select_implementation_5F_parser_2>", "implementation_parser", 222}, // at index 72
 {"<select_implementation_5F_parser_3>", "implementation_parser", 226}, // at index 73
 {"<select_implementation_5F_parser_3>", "implementation_parser", 229}, // at index 74
 {"<select_implementation_5F_parser_3>", "implementation_parser", 232}, // at index 75
 {"<select_implementation_5F_parser_3>", "implementation_parser", 235}, // at index 76
 {"<select_implementation_5F_parser_3>", "implementation_parser", 238}, // at index 77
 {"<select_implementation_5F_parser_3>", "implementation_parser", 241}, // at index 78
 {"<select_implementation_5F_parser_3>", "implementation_parser", 244}, // at index 79
 {"<select_implementation_5F_parser_3>", "implementation_parser", 247}, // at index 80
 {"<select_implementation_5F_parser_3>", "implementation_parser", 250}, // at index 81
 {"<select_implementation_5F_parser_3>", "implementation_parser", 253}, // at index 82
 {"<select_implementation_5F_parser_3>", "implementation_parser", 256}, // at index 83
 {"<select_implementation_5F_parser_4>", "implementation_parser", 259}, // at index 84
 {"<select_implementation_5F_parser_4>", "implementation_parser", 261}, // at index 85
 {"<select_implementation_5F_parser_5>", "implementation_parser", 262}, // at index 86
 {"<select_implementation_5F_parser_5>", "implementation_parser", 265}, // at index 87
 {"<select_implementation_5F_parser_6>", "implementation_parser", 267}, // at index 88
 {"<select_implementation_5F_parser_6>", "implementation_parser", 270}, // at index 89
 {"<select_implementation_5F_parser_6>", "implementation_parser", 273}, // at index 90
 {"<select_implementation_5F_parser_7>", "implementation_parser", 276}, // at index 91
 {"<select_implementation_5F_parser_7>", "implementation_parser", 284}, // at index 92
 {"<select_implementation_5F_parser_8>", "implementation_parser", 285}, // at index 93
 {"<select_implementation_5F_parser_8>", "implementation_parser", 287}, // at index 94
 {"<select_implementation_5F_parser_9>", "implementation_parser", 288}, // at index 95
 {"<select_implementation_5F_parser_9>", "implementation_parser", 290}, // at index 96
 {"<select_implementation_5F_parser_10>", "implementation_parser", 291}, // at index 97
 {"<select_implementation_5F_parser_10>", "implementation_parser", 295}, // at index 98
 {"<select_implementation_5F_parser_11>", "implementation_parser", 297}, // at index 99
 {"<select_implementation_5F_parser_11>", "implementation_parser", 299}, // at index 100
 {"<select_implementation_5F_parser_12>", "implementation_parser", 300}, // at index 101
 {"<select_implementation_5F_parser_12>", "implementation_parser", 301}, // at index 102
 {"<select_implementation_5F_parser_13>", "implementation_parser", 305}, // at index 103
 {"<select_implementation_5F_parser_13>", "implementation_parser", 308}, // at index 104
 {"<select_implementation_5F_parser_14>", "implementation_parser", 310}, // at index 105
 {"<select_implementation_5F_parser_14>", "implementation_parser", 313}, // at index 106
 {"<select_implementation_5F_parser_14>", "implementation_parser", 316}, // at index 107
 {"<select_implementation_5F_parser_15>", "implementation_parser", 319}, // at index 108
 {"<select_implementation_5F_parser_15>", "implementation_parser", 322}, // at index 109
 {"<select_implementation_5F_parser_16>", "implementation_parser", 324}, // at index 110
 {"<select_implementation_5F_parser_16>", "implementation_parser", 326}, // at index 111
 {"<select_implementation_5F_parser_16>", "implementation_parser", 329}, // at index 112
 {"<select_implementation_5F_parser_17>", "implementation_parser", 332}, // at index 113
 {"<select_implementation_5F_parser_17>", "implementation_parser", 335}, // at index 114
 {"<select_implementation_5F_parser_18>", "implementation_parser", 337}, // at index 115
 {"<select_implementation_5F_parser_18>", "implementation_parser", 340}, // at index 116
 {"<select_implementation_5F_parser_18>", "implementation_parser", 343}, // at index 117
 {"<select_implementation_5F_parser_19>", "implementation_parser", 346}, // at index 118
 {"<select_implementation_5F_parser_19>", "implementation_parser", 348}, // at index 119
 {"<select_implementation_5F_parser_20>", "implementation_parser", 349}, // at index 120
 {"<select_implementation_5F_parser_20>", "implementation_parser", 352}, // at index 121
 {"<select_implementation_5F_parser_21>", "implementation_parser", 355}, // at index 122
 {"<select_implementation_5F_parser_21>", "implementation_parser", 356}, // at index 123
 {"<select_implementation_5F_parser_22>", "implementation_parser", 360}, // at index 124
 {"<select_implementation_5F_parser_22>", "implementation_parser", 363}, // at index 125
 {"<select_implementation_5F_parser_22>", "implementation_parser", 366}, // at index 126
 {"<select_implementation_5F_parser_23>", "implementation_parser", 369}, // at index 127
 {"<select_implementation_5F_parser_23>", "implementation_parser", 372}, // at index 128
 {"<select_implementation_5F_parser_24>", "implementation_parser", 374}, // at index 129
 {"<select_implementation_5F_parser_24>", "implementation_parser", 377}, // at index 130
 {"<select_implementation_5F_parser_25>", "implementation_parser", 379}, // at index 131
 {"<select_implementation_5F_parser_25>", "implementation_parser", 383}, // at index 132
 {"<select_implementation_5F_parser_26>", "implementation_parser", 384}, // at index 133
 {"<select_implementation_5F_parser_26>", "implementation_parser", 387}, // at index 134
 {"<>", "", 388} // at index 135
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_goil_file_level_include [136] = {
0, // index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 55
7, // index 1 : <start>, in file 'goil_syntax.ggs', line 38
10, // index 2 : <file>, in file 'goil_syntax.ggs', line 110
12, // index 3 : <sign>, in file 'goil_syntax.ggs', line 126
14, // index 4 : <description>, in file 'goil_syntax.ggs', line 139
16, // index 5 : <OIL_version>, in file 'goil_syntax.ggs', line 163
22, // index 6 : <application_definition>, in file 'goil_syntax.ggs', line 170
30, // index 7 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
32, // index 8 : <boolean>, in file 'goil_syntax.ggs', line 230
34, // index 9 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
36, // index 10 : <oil_declaration>, in file 'goil_syntax.ggs', line 249
40, // index 11 : <include_file_level>, in file 'goil_syntax.ggs', line 422
43, // index 12 : <include_cpu_level>, in file 'goil_syntax.ggs', line 439
46, // index 13 : <implementation_objects>, in file 'implementation_parser.ggs', line 86
50, // index 14 : <implementation_list>, in file 'implementation_parser.ggs', line 131
54, // index 15 : <implementation_type>, in file 'implementation_parser.ggs', line 159
56, // index 16 : <struct_options>, in file 'implementation_parser.ggs', line 187
61, // index 17 : <objref_option>, in file 'implementation_parser.ggs', line 202
65, // index 18 : <string_options>, in file 'implementation_parser.ggs', line 220
70, // index 19 : <boolean_options>, in file 'implementation_parser.ggs', line 252
76, // index 20 : <enum_item>, in file 'implementation_parser.ggs', line 293
79, // index 21 : <enum_options>, in file 'implementation_parser.ggs', line 304
88, // index 22 : <number_options>, in file 'implementation_parser.ggs', line 346
94, // index 23 : <type_options>, in file 'implementation_parser.ggs', line 380
99, // index 24 : <with_auto>, in file 'implementation_parser.ggs', line 414
101, // index 25 : <int_or_float>, in file 'implementation_parser.ggs', line 423
104, // index 26 : <set_followup>, in file 'implementation_parser.ggs', line 441
106, // index 27 : <range_content>, in file 'implementation_parser.ggs', line 453
109, // index 28 : <range>, in file 'implementation_parser.ggs', line 493
111, // index 29 : <multiple>, in file 'implementation_parser.ggs', line 503
113, // index 30 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 513
115, // index 31 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 518
117, // index 32 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
118, // index 33 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
121, // index 34 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
124, // index 35 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
127, // index 36 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
129, // index 37 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
131, // index 38 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
132, // index 39 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
133, // index 40 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
137, // index 41 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
138, // index 42 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
141, // index 43 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
142, // index 44 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
151, // index 45 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
154, // index 46 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
156, // index 47 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
158, // index 48 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 243
159, // index 49 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 243
162, // index 50 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 266
165, // index 51 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 266
171, // index 52 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
175, // index 53 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
178, // index 54 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
182, // index 55 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
185, // index 56 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
188, // index 57 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 289
192, // index 58 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 289
193, // index 59 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 306
196, // index 60 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 306
199, // index 61 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 337
203, // index 62 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 337
204, // index 63 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 430
206, // index 64 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 430
208, // index 65 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 447
210, // index 66 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 447
212, // index 67 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 58
213, // index 68 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 58
217, // index 69 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 93
220, // index 70 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 93
221, // index 71 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 134
222, // index 72 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 134
226, // index 73 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
229, // index 74 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
232, // index 75 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
235, // index 76 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
238, // index 77 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
241, // index 78 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
244, // index 79 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
247, // index 80 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
250, // index 81 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
253, // index 82 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
256, // index 83 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
259, // index 84 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 191
261, // index 85 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 191
262, // index 86 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 230
265, // index 87 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 230
267, // index 88 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 232
270, // index 89 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 232
273, // index 90 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 232
276, // index 91 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 259
284, // index 92 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 259
285, // index 93 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 262
287, // index 94 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 262
288, // index 95 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 269
290, // index 96 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 269
291, // index 97 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 281
295, // index 98 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 281
297, // index 99 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 298
299, // index 100 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 298
300, // index 101 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 312
301, // index 102 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 312
305, // index 103 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 322
308, // index 104 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 322
310, // index 105 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 324
313, // index 106 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 324
316, // index 107 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 324
319, // index 108 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 359
322, // index 109 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 359
324, // index 110 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 361
326, // index 111 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 361
329, // index 112 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 361
332, // index 113 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 391
335, // index 114 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 391
337, // index 115 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 393
340, // index 116 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 393
343, // index 117 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 393
346, // index 118 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 416
348, // index 119 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 416
349, // index 120 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 428
352, // index 121 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 428
355, // index 122 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 444
356, // index 123 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 444
360, // index 124 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 460
363, // index 125 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 460
366, // index 126 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 460
369, // index 127 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 470
372, // index 128 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 470
374, // index 129 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 482
377, // index 130 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 482
379, // index 131 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 496
383, // index 132 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 496
384, // index 133 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 505
387, // index 134 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 505
388 // index 135 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_goil_file_level_include [75] = {
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
13, // at 13 : <implementation_objects>
14, // at 14 : <implementation_list>
15, // at 15 : <implementation_type>
16, // at 16 : <struct_options>
17, // at 17 : <objref_option>
18, // at 18 : <string_options>
19, // at 19 : <boolean_options>
20, // at 20 : <enum_item>
21, // at 21 : <enum_options>
22, // at 22 : <number_options>
23, // at 23 : <type_options>
24, // at 24 : <with_auto>
25, // at 25 : <int_or_float>
26, // at 26 : <set_followup>
27, // at 27 : <range_content>
28, // at 28 : <range>
29, // at 29 : <multiple>
30, // at 30 : <identifier_or_attribute>
31, // at 31 : <identifier_or_enum_value>
32, // at 32 : <select_goil_5F_syntax_0>
36, // at 33 : <select_goil_5F_syntax_1>
39, // at 34 : <select_goil_5F_syntax_2>
41, // at 35 : <select_goil_5F_syntax_3>
43, // at 36 : <select_goil_5F_syntax_4>
46, // at 37 : <select_goil_5F_syntax_5>
48, // at 38 : <select_goil_5F_syntax_6>
50, // at 39 : <select_goil_5F_syntax_7>
52, // at 40 : <select_goil_5F_syntax_8>
57, // at 41 : <select_goil_5F_syntax_9>
59, // at 42 : <select_goil_5F_syntax_10>
61, // at 43 : <select_goil_5F_syntax_11>
63, // at 44 : <select_goil_5F_syntax_12>
65, // at 45 : <select_goil_5F_syntax_13>
67, // at 46 : <select_implementation_5F_parser_0>
69, // at 47 : <select_implementation_5F_parser_1>
71, // at 48 : <select_implementation_5F_parser_2>
73, // at 49 : <select_implementation_5F_parser_3>
84, // at 50 : <select_implementation_5F_parser_4>
86, // at 51 : <select_implementation_5F_parser_5>
88, // at 52 : <select_implementation_5F_parser_6>
91, // at 53 : <select_implementation_5F_parser_7>
93, // at 54 : <select_implementation_5F_parser_8>
95, // at 55 : <select_implementation_5F_parser_9>
97, // at 56 : <select_implementation_5F_parser_10>
99, // at 57 : <select_implementation_5F_parser_11>
101, // at 58 : <select_implementation_5F_parser_12>
103, // at 59 : <select_implementation_5F_parser_13>
105, // at 60 : <select_implementation_5F_parser_14>
108, // at 61 : <select_implementation_5F_parser_15>
110, // at 62 : <select_implementation_5F_parser_16>
113, // at 63 : <select_implementation_5F_parser_17>
115, // at 64 : <select_implementation_5F_parser_18>
118, // at 65 : <select_implementation_5F_parser_19>
120, // at 66 : <select_implementation_5F_parser_20>
122, // at 67 : <select_implementation_5F_parser_21>
124, // at 68 : <select_implementation_5F_parser_22>
127, // at 69 : <select_implementation_5F_parser_23>
129, // at 70 : <select_implementation_5F_parser_24>
131, // at 71 : <select_implementation_5F_parser_25>
133, // at 72 : <select_implementation_5F_parser_26>
135, // at 73 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                      *
//                                                                                                                     *
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
// At index 13 : <implementation_objects> only one production, no choice
  -1,
// At index 14 : <implementation_list> only one production, no choice
  -1,
// At index 15 : <implementation_type> only one production, no choice
  -1,
// At index 16 : <struct_options> only one production, no choice
  -1,
// At index 17 : <objref_option> only one production, no choice
  -1,
// At index 18 : <string_options> only one production, no choice
  -1,
// At index 19 : <boolean_options> only one production, no choice
  -1,
// At index 20 : <enum_item> only one production, no choice
  -1,
// At index 21 : <enum_options> only one production, no choice
  -1,
// At index 22 : <number_options> only one production, no choice
  -1,
// At index 23 : <type_options> only one production, no choice
  -1,
// At index 24 : <with_auto> only one production, no choice
  -1,
// At index 25 : <int_or_float> only one production, no choice
  -1,
// At index 26 : <set_followup> only one production, no choice
  -1,
// At index 27 : <range_content> only one production, no choice
  -1,
// At index 28 : <range> only one production, no choice
  -1,
// At index 29 : <multiple> only one production, no choice
  -1,
// At index 30 : <identifier_or_attribute> only one production, no choice
  -1,
// At index 31 : <identifier_or_enum_value> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 32 : <select_goil_5F_syntax_0>
C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 41 : <select_goil_5F_syntax_1>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 3
  -1,
// At index 50 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 57 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 64 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 3
  -1,
// At index 71 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 76 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 81 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 86 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 102 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 108 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 113 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 119 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 124 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 129 : <select_implementation_5F_parser_0>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 134 : <select_implementation_5F_parser_1>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 2
  -1,
// At index 139 : <select_implementation_5F_parser_2>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken_UINT_33__32_, C_Lexique_goil_5F_lexique::kToken_INT_33__32_, C_Lexique_goil_5F_lexique::kToken_UINT_36__34_, C_Lexique_goil_5F_lexique::kToken_INT_36__34_, C_Lexique_goil_5F_lexique::kToken_FLOAT, C_Lexique_goil_5F_lexique::kToken_ENUM, C_Lexique_goil_5F_lexique::kToken_BOOLEAN, C_Lexique_goil_5F_lexique::kToken_STRING, C_Lexique_goil_5F_lexique::kToken_IDENTIFIER, C_Lexique_goil_5F_lexique::kToken_STRUCT, -1, // Choice 2
  -1,
// At index 154 : <select_implementation_5F_parser_3>
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
// At index 177 : <select_implementation_5F_parser_4>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 182 : <select_implementation_5F_parser_5>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 190 : <select_implementation_5F_parser_6>
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 197 : <select_implementation_5F_parser_7>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 202 : <select_implementation_5F_parser_8>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 207 : <select_implementation_5F_parser_9>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 2
  -1,
// At index 212 : <select_implementation_5F_parser_10>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 220 : <select_implementation_5F_parser_11>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 226 : <select_implementation_5F_parser_12>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 231 : <select_implementation_5F_parser_13>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 239 : <select_implementation_5F_parser_14>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 246 : <select_implementation_5F_parser_15>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 254 : <select_implementation_5F_parser_16>
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 264 : <select_implementation_5F_parser_17>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 272 : <select_implementation_5F_parser_18>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 279 : <select_implementation_5F_parser_19>
C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 2
  -1,
// At index 285 : <select_implementation_5F_parser_20>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 290 : <select_implementation_5F_parser_21>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 295 : <select_implementation_5F_parser_22>
C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 3
  -1,
// At index 302 : <select_implementation_5F_parser_23>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 308 : <select_implementation_5F_parser_24>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 314 : <select_implementation_5F_parser_25>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 319 : <select_implementation_5F_parser_26>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3D_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 326 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_goil_file_level_include [75] = {
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
13, // at 13 : <implementation_objects>
14, // at 14 : <implementation_list>
15, // at 15 : <implementation_type>
16, // at 16 : <struct_options>
17, // at 17 : <objref_option>
18, // at 18 : <string_options>
19, // at 19 : <boolean_options>
20, // at 20 : <enum_item>
21, // at 21 : <enum_options>
22, // at 22 : <number_options>
23, // at 23 : <type_options>
24, // at 24 : <with_auto>
25, // at 25 : <int_or_float>
26, // at 26 : <set_followup>
27, // at 27 : <range_content>
28, // at 28 : <range>
29, // at 29 : <multiple>
30, // at 30 : <identifier_or_attribute>
31, // at 31 : <identifier_or_enum_value>
32, // at 32 : <select_goil_5F_syntax_0>
41, // at 33 : <select_goil_5F_syntax_1>
50, // at 34 : <select_goil_5F_syntax_2>
57, // at 35 : <select_goil_5F_syntax_3>
64, // at 36 : <select_goil_5F_syntax_4>
71, // at 37 : <select_goil_5F_syntax_5>
76, // at 38 : <select_goil_5F_syntax_6>
81, // at 39 : <select_goil_5F_syntax_7>
86, // at 40 : <select_goil_5F_syntax_8>
102, // at 41 : <select_goil_5F_syntax_9>
108, // at 42 : <select_goil_5F_syntax_10>
113, // at 43 : <select_goil_5F_syntax_11>
119, // at 44 : <select_goil_5F_syntax_12>
124, // at 45 : <select_goil_5F_syntax_13>
129, // at 46 : <select_implementation_5F_parser_0>
134, // at 47 : <select_implementation_5F_parser_1>
139, // at 48 : <select_implementation_5F_parser_2>
154, // at 49 : <select_implementation_5F_parser_3>
177, // at 50 : <select_implementation_5F_parser_4>
182, // at 51 : <select_implementation_5F_parser_5>
190, // at 52 : <select_implementation_5F_parser_6>
197, // at 53 : <select_implementation_5F_parser_7>
202, // at 54 : <select_implementation_5F_parser_8>
207, // at 55 : <select_implementation_5F_parser_9>
212, // at 56 : <select_implementation_5F_parser_10>
220, // at 57 : <select_implementation_5F_parser_11>
226, // at 58 : <select_implementation_5F_parser_12>
231, // at 59 : <select_implementation_5F_parser_13>
239, // at 60 : <select_implementation_5F_parser_14>
246, // at 61 : <select_implementation_5F_parser_15>
254, // at 62 : <select_implementation_5F_parser_16>
264, // at 63 : <select_implementation_5F_parser_17>
272, // at 64 : <select_implementation_5F_parser_18>
279, // at 65 : <select_implementation_5F_parser_19>
285, // at 66 : <select_implementation_5F_parser_20>
290, // at 67 : <select_implementation_5F_parser_21>
295, // at 68 : <select_implementation_5F_parser_22>
302, // at 69 : <select_implementation_5F_parser_23>
308, // at 70 : <select_implementation_5F_parser_24>
314, // at 71 : <select_implementation_5F_parser_25>
319, // at 72 : <select_implementation_5F_parser_26>
326, // at 73 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              'implementation_definition' non terminal implementation                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_definition_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        'start' non terminal implementation                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_start_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_start_ (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_(inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         'file' non terminal implementation                                          *
//                                                                                                                     *
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
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performTopDownParsing (gProductions_goil_file_level_include, gProductionNames_goil_file_level_include, gProductionIndexes_goil_file_level_include,
                                    gFirstProductionIndexes_goil_file_level_include, gDecision_goil_file_level_include, gDecisionIndexes_goil_file_level_include, 388) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Grammar start symbol implementation                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_implementation &  parameter_1,
                                GALGAS_applicationDefinition &  parameter_2,
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
      const bool ok = scanner->performTopDownParsing (gProductions_goil_file_level_include, gProductionNames_goil_file_level_include, gProductionIndexes_goil_file_level_include,
                                                      gFirstProductionIndexes_goil_file_level_include, gDecision_goil_file_level_include, gDecisionIndexes_goil_file_level_include, 388) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_file_5F_level_5F_include grammar ;
        grammar.nt_file_ (parameter_1, parameter_2, parameter_3, parameter_4, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message COMMA_THERE) ;
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
                                                    gFirstProductionIndexes_goil_file_level_include, gDecision_goil_file_level_include, gDecisionIndexes_goil_file_level_include, 388) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_goil_5F_file_5F_level_5F_include grammar ;
      grammar.nt_file_ (parameter_1, parameter_2, parameter_3, parameter_4, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         'sign' non terminal implementation                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     'description' non terminal implementation                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     'OIL_version' non terminal implementation                                       *
//                                                                                                                     *
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
//                                                                                                                     *
//                                'application_definition' non terminal implementation                                 *
//                                                                                                                     *
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
//                                                                                                                     *
//                                'object_definition_list' non terminal implementation                                 *
//                                                                                                                     *
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
//                                                                                                                     *
//                                       'boolean' non terminal implementation                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 'oil_declaration_list' non terminal implementation                                  *
//                                                                                                                     *
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
//                                                                                                                     *
//                                   'oil_declaration' non terminal implementation                                     *
//                                                                                                                     *
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
//                                                                                                                     *
//                                  'include_file_level' non terminal implementation                                   *
//                                                                                                                     *
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
//                                                                                                                     *
//                                  'include_cpu_level' non terminal implementation                                    *
//                                                                                                                     *
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
//                                                                                                                     *
//                                'implementation_objects' non terminal implementation                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_objects_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_objects_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i1_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 'implementation_list' non terminal implementation                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_list_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 'implementation_type' non terminal implementation                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_type_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_type_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i3_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    'struct_options' non terminal implementation                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_struct_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_struct_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i4_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    'objref_option' non terminal implementation                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_objref_5F_option_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_objref_5F_option_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i5_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    'string_options' non terminal implementation                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_string_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_string_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i6_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   'boolean_options' non terminal implementation                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_boolean_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_boolean_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i7_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      'enum_item' non terminal implementation                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_enum_5F_item_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_enum_5F_item_ (GALGAS_enumValues & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i8_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     'enum_options' non terminal implementation                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_enum_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_enum_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    'number_options' non terminal implementation                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_number_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_number_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i10_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     'type_options' non terminal implementation                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_type_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_type_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i11_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      'with_auto' non terminal implementation                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_with_5F_auto_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_with_5F_auto_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i12_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     'int_or_float' non terminal implementation                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_int_5F_or_5F_float_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i13_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i13_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     'set_followup' non terminal implementation                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_set_5F_followup_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i14_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_set_5F_followup_ (GALGAS_numberList & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i14_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    'range_content' non terminal implementation                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_range_5F_content_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i15_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_range_5F_content_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i15_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        'range' non terminal implementation                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_range_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i16_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_range_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i16_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       'multiple' non terminal implementation                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_multiple_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i17_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_multiple_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i17_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               'identifier_or_attribute' non terminal implementation                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i18_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i18_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               'identifier_or_enum_value' non terminal implementation                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i19_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i19_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_0' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_1' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_2' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_3' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_4' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_5' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_6' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_7' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_8' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_9' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_10' added non terminal implementation                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_11' added non terminal implementation                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_12' added non terminal implementation                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_13' added non terminal implementation                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_0' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_1' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_2' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_3' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_4' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_5' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_6' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_7' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_8' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_9' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_10' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_11' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_12' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_13' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_14' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_15' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_16' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_17' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_18' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_18 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_19' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_19 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_20' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_20 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_21' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_21 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_22' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_22 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_23' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_23 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_24' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_24 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_25' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_25 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_26' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_26 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int16_t gProductions_goil_grammar [] = {
// At index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 55
  TERMINAL (C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION) // $IMPLEMENTATION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (46) // <select_implementation_5F_parser_0>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 7 : <start>, in file 'goil_syntax.ggs', line 38
, NONTERMINAL (5) // <OIL_version>
, NONTERMINAL (2) // <file>
, END_PRODUCTION
// At index 10 : <file>, in file 'goil_syntax.ggs', line 110
, NONTERMINAL (32) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 12 : <sign>, in file 'goil_syntax.ggs', line 126
, NONTERMINAL (33) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 14 : <description>, in file 'goil_syntax.ggs', line 139
, NONTERMINAL (34) // <select_goil_5F_syntax_2>
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
, NONTERMINAL (36) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 32 : <boolean>, in file 'goil_syntax.ggs', line 230
, NONTERMINAL (37) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 34 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
, NONTERMINAL (38) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 36 : <oil_declaration>, in file 'goil_syntax.ggs', line 249
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (39) // <select_goil_5F_syntax_7>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 40 : <include_file_level>, in file 'goil_syntax.ggs', line 422
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, NONTERMINAL (44) // <select_goil_5F_syntax_12>
, END_PRODUCTION
// At index 43 : <include_cpu_level>, in file 'goil_syntax.ggs', line 439
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, NONTERMINAL (45) // <select_goil_5F_syntax_13>
, END_PRODUCTION
// At index 46 : <implementation_objects>, in file 'implementation_parser.ggs', line 86
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (47) // <select_implementation_5F_parser_1>
, NONTERMINAL (14) // <implementation_list>
, END_PRODUCTION
// At index 50 : <implementation_list>, in file 'implementation_parser.ggs', line 131
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (48) // <select_implementation_5F_parser_2>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 54 : <implementation_type>, in file 'implementation_parser.ggs', line 159
, NONTERMINAL (49) // <select_implementation_5F_parser_3>
, END_PRODUCTION
// At index 56 : <struct_options>, in file 'implementation_parser.ggs', line 187
, NONTERMINAL (50) // <select_implementation_5F_parser_4>
, NONTERMINAL (30) // <identifier_or_attribute>
, NONTERMINAL (29) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 61 : <objref_option>, in file 'implementation_parser.ggs', line 202
, NONTERMINAL (30) // <identifier_or_attribute>
, NONTERMINAL (29) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 65 : <string_options>, in file 'implementation_parser.ggs', line 220
, NONTERMINAL (24) // <with_auto>
, NONTERMINAL (30) // <identifier_or_attribute>
, NONTERMINAL (29) // <multiple>
, NONTERMINAL (51) // <select_implementation_5F_parser_5>
, END_PRODUCTION
// At index 70 : <boolean_options>, in file 'implementation_parser.ggs', line 252
, NONTERMINAL (24) // <with_auto>
, NONTERMINAL (53) // <select_implementation_5F_parser_7>
, NONTERMINAL (30) // <identifier_or_attribute>
, NONTERMINAL (29) // <multiple>
, NONTERMINAL (56) // <select_implementation_5F_parser_10>
, END_PRODUCTION
// At index 76 : <enum_item>, in file 'implementation_parser.ggs', line 293
, NONTERMINAL (31) // <identifier_or_enum_value>
, NONTERMINAL (57) // <select_implementation_5F_parser_11>
, END_PRODUCTION
// At index 79 : <enum_options>, in file 'implementation_parser.ggs', line 304
, NONTERMINAL (24) // <with_auto>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (20) // <enum_item>
, NONTERMINAL (58) // <select_implementation_5F_parser_12>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, NONTERMINAL (30) // <identifier_or_attribute>
, NONTERMINAL (29) // <multiple>
, NONTERMINAL (59) // <select_implementation_5F_parser_13>
, END_PRODUCTION
// At index 88 : <number_options>, in file 'implementation_parser.ggs', line 346
, NONTERMINAL (24) // <with_auto>
, NONTERMINAL (28) // <range>
, NONTERMINAL (30) // <identifier_or_attribute>
, NONTERMINAL (29) // <multiple>
, NONTERMINAL (61) // <select_implementation_5F_parser_15>
, END_PRODUCTION
// At index 94 : <type_options>, in file 'implementation_parser.ggs', line 380
, NONTERMINAL (24) // <with_auto>
, NONTERMINAL (30) // <identifier_or_attribute>
, NONTERMINAL (29) // <multiple>
, NONTERMINAL (63) // <select_implementation_5F_parser_17>
, END_PRODUCTION
// At index 99 : <with_auto>, in file 'implementation_parser.ggs', line 414
, NONTERMINAL (65) // <select_implementation_5F_parser_19>
, END_PRODUCTION
// At index 101 : <int_or_float>, in file 'implementation_parser.ggs', line 423
, NONTERMINAL (3) // <sign>
, NONTERMINAL (66) // <select_implementation_5F_parser_20>
, END_PRODUCTION
// At index 104 : <set_followup>, in file 'implementation_parser.ggs', line 441
, NONTERMINAL (67) // <select_implementation_5F_parser_21>
, END_PRODUCTION
// At index 106 : <range_content>, in file 'implementation_parser.ggs', line 453
, NONTERMINAL (3) // <sign>
, NONTERMINAL (68) // <select_implementation_5F_parser_22>
, END_PRODUCTION
// At index 109 : <range>, in file 'implementation_parser.ggs', line 493
, NONTERMINAL (71) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 111 : <multiple>, in file 'implementation_parser.ggs', line 503
, NONTERMINAL (72) // <select_implementation_5F_parser_26>
, END_PRODUCTION
// At index 113 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 513
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
// At index 115 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 518
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 117 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, END_PRODUCTION
// At index 118 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (11) // <include_file_level>
, NONTERMINAL (32) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 121 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (32) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 124 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (6) // <application_definition>
, NONTERMINAL (32) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 127 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) // $-$
, END_PRODUCTION
// At index 129 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) // $+$
, END_PRODUCTION
// At index 131 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, END_PRODUCTION
// At index 132 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, END_PRODUCTION
// At index 133 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) // $:$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (35) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 137 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, END_PRODUCTION
// At index 138 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (35) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 141 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, END_PRODUCTION
// At index 142 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (36) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 151 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, NONTERMINAL (12) // <include_cpu_level>
, NONTERMINAL (36) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 154 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 156 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 158 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 243
, END_PRODUCTION
// At index 159 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 243
, NONTERMINAL (10) // <oil_declaration>
, NONTERMINAL (38) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 162 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 266
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (40) // <select_goil_5F_syntax_8>
, END_PRODUCTION
// At index 165 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 266
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 171 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (41) // <select_goil_5F_syntax_9>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 175 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
, NONTERMINAL (3) // <sign>
, NONTERMINAL (42) // <select_goil_5F_syntax_10>
, END_PRODUCTION
// At index 178 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (43) // <select_goil_5F_syntax_11>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 182 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 185 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 188 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 289
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 192 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 289
, END_PRODUCTION
// At index 193 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 306
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 196 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 306
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 199 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 337
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 203 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 337
, END_PRODUCTION
// At index 204 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 430
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 206 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 430
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 208 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 447
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 210 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 447
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 212 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 58
, END_PRODUCTION
// At index 213 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 58
, NONTERMINAL (13) // <implementation_objects>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (46) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 217 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 93
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 220 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 93
, END_PRODUCTION
// At index 221 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 134
, END_PRODUCTION
// At index 222 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 134
, NONTERMINAL (15) // <implementation_type>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (48) // <select_implementation_5F_parser_2>
, END_PRODUCTION
// At index 226 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_) // $UINT32$
, NONTERMINAL (22) // <number_options>
, END_PRODUCTION
// At index 229 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_33__32_) // $INT32$
, NONTERMINAL (22) // <number_options>
, END_PRODUCTION
// At index 232 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_) // $UINT64$
, NONTERMINAL (22) // <number_options>
, END_PRODUCTION
// At index 235 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_36__34_) // $INT64$
, NONTERMINAL (22) // <number_options>
, END_PRODUCTION
// At index 238 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FLOAT) // $FLOAT$
, NONTERMINAL (22) // <number_options>
, END_PRODUCTION
// At index 241 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_ENUM) // $ENUM$
, NONTERMINAL (21) // <enum_options>
, END_PRODUCTION
// At index 244 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_BOOLEAN) // $BOOLEAN$
, NONTERMINAL (19) // <boolean_options>
, END_PRODUCTION
// At index 247 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRING) // $STRING$
, NONTERMINAL (18) // <string_options>
, END_PRODUCTION
// At index 250 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER) // $IDENTIFIER$
, NONTERMINAL (23) // <type_options>
, END_PRODUCTION
// At index 253 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRUCT) // $STRUCT$
, NONTERMINAL (16) // <struct_options>
, END_PRODUCTION
// At index 256 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (17) // <objref_option>
, END_PRODUCTION
// At index 259 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 191
, NONTERMINAL (14) // <implementation_list>
, END_PRODUCTION
// At index 261 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 191
, END_PRODUCTION
// At index 262 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 230
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (52) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 265 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 230
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 267 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 232
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 270 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 232
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 273 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 232
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 276 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 259
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, NONTERMINAL (54) // <select_implementation_5F_parser_8>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, NONTERMINAL (55) // <select_implementation_5F_parser_9>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 284 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 259
, END_PRODUCTION
// At index 285 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 262
, NONTERMINAL (14) // <implementation_list>
, END_PRODUCTION
// At index 287 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 262
, END_PRODUCTION
// At index 288 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 269
, NONTERMINAL (14) // <implementation_list>
, END_PRODUCTION
// At index 290 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 269
, END_PRODUCTION
// At index 291 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 281
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 295 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 281
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 297 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 298
, NONTERMINAL (14) // <implementation_list>
, END_PRODUCTION
// At index 299 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 298
, END_PRODUCTION
// At index 300 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 312
, END_PRODUCTION
// At index 301 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 312
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (20) // <enum_item>
, NONTERMINAL (58) // <select_implementation_5F_parser_12>
, END_PRODUCTION
// At index 305 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 322
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (60) // <select_implementation_5F_parser_14>
, END_PRODUCTION
// At index 308 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 322
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 310 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 324
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 313 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 324
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 316 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 324
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 319 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 359
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (62) // <select_implementation_5F_parser_16>
, END_PRODUCTION
// At index 322 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 359
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 324 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 361
, NONTERMINAL (25) // <int_or_float>
, END_PRODUCTION
// At index 326 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 361
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 329 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 361
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 332 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 391
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (64) // <select_implementation_5F_parser_18>
, END_PRODUCTION
// At index 335 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 391
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 337 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 393
, NONTERMINAL (30) // <identifier_or_attribute>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 340 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 393
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 343 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 393
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 346 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 416
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO) // $WITH_AUTO$
, END_PRODUCTION
// At index 348 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 416
, END_PRODUCTION
// At index 349 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 428
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 352 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 428
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 355 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 444
, END_PRODUCTION
// At index 356 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 444
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (25) // <int_or_float>
, NONTERMINAL (67) // <select_implementation_5F_parser_21>
, END_PRODUCTION
// At index 360 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 460
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number) // $set_start_uint_number$
, NONTERMINAL (25) // <int_or_float>
, END_PRODUCTION
// At index 363 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 460
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (69) // <select_implementation_5F_parser_23>
, END_PRODUCTION
// At index 366 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 460
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (70) // <select_implementation_5F_parser_24>
, END_PRODUCTION
// At index 369 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 470
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (25) // <int_or_float>
, END_PRODUCTION
// At index 372 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 470
, NONTERMINAL (26) // <set_followup>
, END_PRODUCTION
// At index 374 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 482
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (25) // <int_or_float>
, END_PRODUCTION
// At index 377 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 482
, NONTERMINAL (26) // <set_followup>
, END_PRODUCTION
// At index 379 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 496
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (27) // <range_content>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 383 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 496
, END_PRODUCTION
// At index 384 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 505
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 387 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 505
, END_PRODUCTION
// At index 388 : <>, in file '.ggs', line 0
, NONTERMINAL (1) // <start>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          P R O D U C T I O N    N A M E S                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_goil_grammar [136] = {
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
 {"<implementation_objects>", "implementation_parser", 46}, // at index 13
 {"<implementation_list>", "implementation_parser", 50}, // at index 14
 {"<implementation_type>", "implementation_parser", 54}, // at index 15
 {"<struct_options>", "implementation_parser", 56}, // at index 16
 {"<objref_option>", "implementation_parser", 61}, // at index 17
 {"<string_options>", "implementation_parser", 65}, // at index 18
 {"<boolean_options>", "implementation_parser", 70}, // at index 19
 {"<enum_item>", "implementation_parser", 76}, // at index 20
 {"<enum_options>", "implementation_parser", 79}, // at index 21
 {"<number_options>", "implementation_parser", 88}, // at index 22
 {"<type_options>", "implementation_parser", 94}, // at index 23
 {"<with_auto>", "implementation_parser", 99}, // at index 24
 {"<int_or_float>", "implementation_parser", 101}, // at index 25
 {"<set_followup>", "implementation_parser", 104}, // at index 26
 {"<range_content>", "implementation_parser", 106}, // at index 27
 {"<range>", "implementation_parser", 109}, // at index 28
 {"<multiple>", "implementation_parser", 111}, // at index 29
 {"<identifier_or_attribute>", "implementation_parser", 113}, // at index 30
 {"<identifier_or_enum_value>", "implementation_parser", 115}, // at index 31
 {"<select_goil_5F_syntax_0>", "goil_syntax", 117}, // at index 32
 {"<select_goil_5F_syntax_0>", "goil_syntax", 118}, // at index 33
 {"<select_goil_5F_syntax_0>", "goil_syntax", 121}, // at index 34
 {"<select_goil_5F_syntax_0>", "goil_syntax", 124}, // at index 35
 {"<select_goil_5F_syntax_1>", "goil_syntax", 127}, // at index 36
 {"<select_goil_5F_syntax_1>", "goil_syntax", 129}, // at index 37
 {"<select_goil_5F_syntax_1>", "goil_syntax", 131}, // at index 38
 {"<select_goil_5F_syntax_2>", "goil_syntax", 132}, // at index 39
 {"<select_goil_5F_syntax_2>", "goil_syntax", 133}, // at index 40
 {"<select_goil_5F_syntax_3>", "goil_syntax", 137}, // at index 41
 {"<select_goil_5F_syntax_3>", "goil_syntax", 138}, // at index 42
 {"<select_goil_5F_syntax_4>", "goil_syntax", 141}, // at index 43
 {"<select_goil_5F_syntax_4>", "goil_syntax", 142}, // at index 44
 {"<select_goil_5F_syntax_4>", "goil_syntax", 151}, // at index 45
 {"<select_goil_5F_syntax_5>", "goil_syntax", 154}, // at index 46
 {"<select_goil_5F_syntax_5>", "goil_syntax", 156}, // at index 47
 {"<select_goil_5F_syntax_6>", "goil_syntax", 158}, // at index 48
 {"<select_goil_5F_syntax_6>", "goil_syntax", 159}, // at index 49
 {"<select_goil_5F_syntax_7>", "goil_syntax", 162}, // at index 50
 {"<select_goil_5F_syntax_7>", "goil_syntax", 165}, // at index 51
 {"<select_goil_5F_syntax_8>", "goil_syntax", 171}, // at index 52
 {"<select_goil_5F_syntax_8>", "goil_syntax", 175}, // at index 53
 {"<select_goil_5F_syntax_8>", "goil_syntax", 178}, // at index 54
 {"<select_goil_5F_syntax_8>", "goil_syntax", 182}, // at index 55
 {"<select_goil_5F_syntax_8>", "goil_syntax", 185}, // at index 56
 {"<select_goil_5F_syntax_9>", "goil_syntax", 188}, // at index 57
 {"<select_goil_5F_syntax_9>", "goil_syntax", 192}, // at index 58
 {"<select_goil_5F_syntax_10>", "goil_syntax", 193}, // at index 59
 {"<select_goil_5F_syntax_10>", "goil_syntax", 196}, // at index 60
 {"<select_goil_5F_syntax_11>", "goil_syntax", 199}, // at index 61
 {"<select_goil_5F_syntax_11>", "goil_syntax", 203}, // at index 62
 {"<select_goil_5F_syntax_12>", "goil_syntax", 204}, // at index 63
 {"<select_goil_5F_syntax_12>", "goil_syntax", 206}, // at index 64
 {"<select_goil_5F_syntax_13>", "goil_syntax", 208}, // at index 65
 {"<select_goil_5F_syntax_13>", "goil_syntax", 210}, // at index 66
 {"<select_implementation_5F_parser_0>", "implementation_parser", 212}, // at index 67
 {"<select_implementation_5F_parser_0>", "implementation_parser", 213}, // at index 68
 {"<select_implementation_5F_parser_1>", "implementation_parser", 217}, // at index 69
 {"<select_implementation_5F_parser_1>", "implementation_parser", 220}, // at index 70
 {"<select_implementation_5F_parser_2>", "implementation_parser", 221}, // at index 71
 {"<select_implementation_5F_parser_2>", "implementation_parser", 222}, // at index 72
 {"<select_implementation_5F_parser_3>", "implementation_parser", 226}, // at index 73
 {"<select_implementation_5F_parser_3>", "implementation_parser", 229}, // at index 74
 {"<select_implementation_5F_parser_3>", "implementation_parser", 232}, // at index 75
 {"<select_implementation_5F_parser_3>", "implementation_parser", 235}, // at index 76
 {"<select_implementation_5F_parser_3>", "implementation_parser", 238}, // at index 77
 {"<select_implementation_5F_parser_3>", "implementation_parser", 241}, // at index 78
 {"<select_implementation_5F_parser_3>", "implementation_parser", 244}, // at index 79
 {"<select_implementation_5F_parser_3>", "implementation_parser", 247}, // at index 80
 {"<select_implementation_5F_parser_3>", "implementation_parser", 250}, // at index 81
 {"<select_implementation_5F_parser_3>", "implementation_parser", 253}, // at index 82
 {"<select_implementation_5F_parser_3>", "implementation_parser", 256}, // at index 83
 {"<select_implementation_5F_parser_4>", "implementation_parser", 259}, // at index 84
 {"<select_implementation_5F_parser_4>", "implementation_parser", 261}, // at index 85
 {"<select_implementation_5F_parser_5>", "implementation_parser", 262}, // at index 86
 {"<select_implementation_5F_parser_5>", "implementation_parser", 265}, // at index 87
 {"<select_implementation_5F_parser_6>", "implementation_parser", 267}, // at index 88
 {"<select_implementation_5F_parser_6>", "implementation_parser", 270}, // at index 89
 {"<select_implementation_5F_parser_6>", "implementation_parser", 273}, // at index 90
 {"<select_implementation_5F_parser_7>", "implementation_parser", 276}, // at index 91
 {"<select_implementation_5F_parser_7>", "implementation_parser", 284}, // at index 92
 {"<select_implementation_5F_parser_8>", "implementation_parser", 285}, // at index 93
 {"<select_implementation_5F_parser_8>", "implementation_parser", 287}, // at index 94
 {"<select_implementation_5F_parser_9>", "implementation_parser", 288}, // at index 95
 {"<select_implementation_5F_parser_9>", "implementation_parser", 290}, // at index 96
 {"<select_implementation_5F_parser_10>", "implementation_parser", 291}, // at index 97
 {"<select_implementation_5F_parser_10>", "implementation_parser", 295}, // at index 98
 {"<select_implementation_5F_parser_11>", "implementation_parser", 297}, // at index 99
 {"<select_implementation_5F_parser_11>", "implementation_parser", 299}, // at index 100
 {"<select_implementation_5F_parser_12>", "implementation_parser", 300}, // at index 101
 {"<select_implementation_5F_parser_12>", "implementation_parser", 301}, // at index 102
 {"<select_implementation_5F_parser_13>", "implementation_parser", 305}, // at index 103
 {"<select_implementation_5F_parser_13>", "implementation_parser", 308}, // at index 104
 {"<select_implementation_5F_parser_14>", "implementation_parser", 310}, // at index 105
 {"<select_implementation_5F_parser_14>", "implementation_parser", 313}, // at index 106
 {"<select_implementation_5F_parser_14>", "implementation_parser", 316}, // at index 107
 {"<select_implementation_5F_parser_15>", "implementation_parser", 319}, // at index 108
 {"<select_implementation_5F_parser_15>", "implementation_parser", 322}, // at index 109
 {"<select_implementation_5F_parser_16>", "implementation_parser", 324}, // at index 110
 {"<select_implementation_5F_parser_16>", "implementation_parser", 326}, // at index 111
 {"<select_implementation_5F_parser_16>", "implementation_parser", 329}, // at index 112
 {"<select_implementation_5F_parser_17>", "implementation_parser", 332}, // at index 113
 {"<select_implementation_5F_parser_17>", "implementation_parser", 335}, // at index 114
 {"<select_implementation_5F_parser_18>", "implementation_parser", 337}, // at index 115
 {"<select_implementation_5F_parser_18>", "implementation_parser", 340}, // at index 116
 {"<select_implementation_5F_parser_18>", "implementation_parser", 343}, // at index 117
 {"<select_implementation_5F_parser_19>", "implementation_parser", 346}, // at index 118
 {"<select_implementation_5F_parser_19>", "implementation_parser", 348}, // at index 119
 {"<select_implementation_5F_parser_20>", "implementation_parser", 349}, // at index 120
 {"<select_implementation_5F_parser_20>", "implementation_parser", 352}, // at index 121
 {"<select_implementation_5F_parser_21>", "implementation_parser", 355}, // at index 122
 {"<select_implementation_5F_parser_21>", "implementation_parser", 356}, // at index 123
 {"<select_implementation_5F_parser_22>", "implementation_parser", 360}, // at index 124
 {"<select_implementation_5F_parser_22>", "implementation_parser", 363}, // at index 125
 {"<select_implementation_5F_parser_22>", "implementation_parser", 366}, // at index 126
 {"<select_implementation_5F_parser_23>", "implementation_parser", 369}, // at index 127
 {"<select_implementation_5F_parser_23>", "implementation_parser", 372}, // at index 128
 {"<select_implementation_5F_parser_24>", "implementation_parser", 374}, // at index 129
 {"<select_implementation_5F_parser_24>", "implementation_parser", 377}, // at index 130
 {"<select_implementation_5F_parser_25>", "implementation_parser", 379}, // at index 131
 {"<select_implementation_5F_parser_25>", "implementation_parser", 383}, // at index 132
 {"<select_implementation_5F_parser_26>", "implementation_parser", 384}, // at index 133
 {"<select_implementation_5F_parser_26>", "implementation_parser", 387}, // at index 134
 {"<>", "", 388} // at index 135
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_goil_grammar [136] = {
0, // index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 55
7, // index 1 : <start>, in file 'goil_syntax.ggs', line 38
10, // index 2 : <file>, in file 'goil_syntax.ggs', line 110
12, // index 3 : <sign>, in file 'goil_syntax.ggs', line 126
14, // index 4 : <description>, in file 'goil_syntax.ggs', line 139
16, // index 5 : <OIL_version>, in file 'goil_syntax.ggs', line 163
22, // index 6 : <application_definition>, in file 'goil_syntax.ggs', line 170
30, // index 7 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
32, // index 8 : <boolean>, in file 'goil_syntax.ggs', line 230
34, // index 9 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
36, // index 10 : <oil_declaration>, in file 'goil_syntax.ggs', line 249
40, // index 11 : <include_file_level>, in file 'goil_syntax.ggs', line 422
43, // index 12 : <include_cpu_level>, in file 'goil_syntax.ggs', line 439
46, // index 13 : <implementation_objects>, in file 'implementation_parser.ggs', line 86
50, // index 14 : <implementation_list>, in file 'implementation_parser.ggs', line 131
54, // index 15 : <implementation_type>, in file 'implementation_parser.ggs', line 159
56, // index 16 : <struct_options>, in file 'implementation_parser.ggs', line 187
61, // index 17 : <objref_option>, in file 'implementation_parser.ggs', line 202
65, // index 18 : <string_options>, in file 'implementation_parser.ggs', line 220
70, // index 19 : <boolean_options>, in file 'implementation_parser.ggs', line 252
76, // index 20 : <enum_item>, in file 'implementation_parser.ggs', line 293
79, // index 21 : <enum_options>, in file 'implementation_parser.ggs', line 304
88, // index 22 : <number_options>, in file 'implementation_parser.ggs', line 346
94, // index 23 : <type_options>, in file 'implementation_parser.ggs', line 380
99, // index 24 : <with_auto>, in file 'implementation_parser.ggs', line 414
101, // index 25 : <int_or_float>, in file 'implementation_parser.ggs', line 423
104, // index 26 : <set_followup>, in file 'implementation_parser.ggs', line 441
106, // index 27 : <range_content>, in file 'implementation_parser.ggs', line 453
109, // index 28 : <range>, in file 'implementation_parser.ggs', line 493
111, // index 29 : <multiple>, in file 'implementation_parser.ggs', line 503
113, // index 30 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 513
115, // index 31 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 518
117, // index 32 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
118, // index 33 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
121, // index 34 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
124, // index 35 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
127, // index 36 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
129, // index 37 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
131, // index 38 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
132, // index 39 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
133, // index 40 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
137, // index 41 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
138, // index 42 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
141, // index 43 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
142, // index 44 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
151, // index 45 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
154, // index 46 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
156, // index 47 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
158, // index 48 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 243
159, // index 49 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 243
162, // index 50 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 266
165, // index 51 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 266
171, // index 52 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
175, // index 53 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
178, // index 54 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
182, // index 55 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
185, // index 56 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 268
188, // index 57 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 289
192, // index 58 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 289
193, // index 59 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 306
196, // index 60 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 306
199, // index 61 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 337
203, // index 62 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 337
204, // index 63 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 430
206, // index 64 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 430
208, // index 65 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 447
210, // index 66 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 447
212, // index 67 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 58
213, // index 68 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 58
217, // index 69 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 93
220, // index 70 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 93
221, // index 71 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 134
222, // index 72 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 134
226, // index 73 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
229, // index 74 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
232, // index 75 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
235, // index 76 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
238, // index 77 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
241, // index 78 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
244, // index 79 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
247, // index 80 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
250, // index 81 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
253, // index 82 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
256, // index 83 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 162
259, // index 84 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 191
261, // index 85 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 191
262, // index 86 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 230
265, // index 87 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 230
267, // index 88 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 232
270, // index 89 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 232
273, // index 90 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 232
276, // index 91 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 259
284, // index 92 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 259
285, // index 93 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 262
287, // index 94 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 262
288, // index 95 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 269
290, // index 96 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 269
291, // index 97 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 281
295, // index 98 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 281
297, // index 99 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 298
299, // index 100 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 298
300, // index 101 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 312
301, // index 102 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 312
305, // index 103 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 322
308, // index 104 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 322
310, // index 105 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 324
313, // index 106 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 324
316, // index 107 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 324
319, // index 108 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 359
322, // index 109 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 359
324, // index 110 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 361
326, // index 111 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 361
329, // index 112 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 361
332, // index 113 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 391
335, // index 114 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 391
337, // index 115 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 393
340, // index 116 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 393
343, // index 117 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 393
346, // index 118 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 416
348, // index 119 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 416
349, // index 120 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 428
352, // index 121 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 428
355, // index 122 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 444
356, // index 123 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 444
360, // index 124 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 460
363, // index 125 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 460
366, // index 126 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 460
369, // index 127 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 470
372, // index 128 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 470
374, // index 129 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 482
377, // index 130 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 482
379, // index 131 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 496
383, // index 132 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 496
384, // index 133 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 505
387, // index 134 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 505
388 // index 135 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_goil_grammar [75] = {
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
13, // at 13 : <implementation_objects>
14, // at 14 : <implementation_list>
15, // at 15 : <implementation_type>
16, // at 16 : <struct_options>
17, // at 17 : <objref_option>
18, // at 18 : <string_options>
19, // at 19 : <boolean_options>
20, // at 20 : <enum_item>
21, // at 21 : <enum_options>
22, // at 22 : <number_options>
23, // at 23 : <type_options>
24, // at 24 : <with_auto>
25, // at 25 : <int_or_float>
26, // at 26 : <set_followup>
27, // at 27 : <range_content>
28, // at 28 : <range>
29, // at 29 : <multiple>
30, // at 30 : <identifier_or_attribute>
31, // at 31 : <identifier_or_enum_value>
32, // at 32 : <select_goil_5F_syntax_0>
36, // at 33 : <select_goil_5F_syntax_1>
39, // at 34 : <select_goil_5F_syntax_2>
41, // at 35 : <select_goil_5F_syntax_3>
43, // at 36 : <select_goil_5F_syntax_4>
46, // at 37 : <select_goil_5F_syntax_5>
48, // at 38 : <select_goil_5F_syntax_6>
50, // at 39 : <select_goil_5F_syntax_7>
52, // at 40 : <select_goil_5F_syntax_8>
57, // at 41 : <select_goil_5F_syntax_9>
59, // at 42 : <select_goil_5F_syntax_10>
61, // at 43 : <select_goil_5F_syntax_11>
63, // at 44 : <select_goil_5F_syntax_12>
65, // at 45 : <select_goil_5F_syntax_13>
67, // at 46 : <select_implementation_5F_parser_0>
69, // at 47 : <select_implementation_5F_parser_1>
71, // at 48 : <select_implementation_5F_parser_2>
73, // at 49 : <select_implementation_5F_parser_3>
84, // at 50 : <select_implementation_5F_parser_4>
86, // at 51 : <select_implementation_5F_parser_5>
88, // at 52 : <select_implementation_5F_parser_6>
91, // at 53 : <select_implementation_5F_parser_7>
93, // at 54 : <select_implementation_5F_parser_8>
95, // at 55 : <select_implementation_5F_parser_9>
97, // at 56 : <select_implementation_5F_parser_10>
99, // at 57 : <select_implementation_5F_parser_11>
101, // at 58 : <select_implementation_5F_parser_12>
103, // at 59 : <select_implementation_5F_parser_13>
105, // at 60 : <select_implementation_5F_parser_14>
108, // at 61 : <select_implementation_5F_parser_15>
110, // at 62 : <select_implementation_5F_parser_16>
113, // at 63 : <select_implementation_5F_parser_17>
115, // at 64 : <select_implementation_5F_parser_18>
118, // at 65 : <select_implementation_5F_parser_19>
120, // at 66 : <select_implementation_5F_parser_20>
122, // at 67 : <select_implementation_5F_parser_21>
124, // at 68 : <select_implementation_5F_parser_22>
127, // at 69 : <select_implementation_5F_parser_23>
129, // at 70 : <select_implementation_5F_parser_24>
131, // at 71 : <select_implementation_5F_parser_25>
133, // at 72 : <select_implementation_5F_parser_26>
135, // at 73 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_goil_grammar [] = {
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
// At index 13 : <implementation_objects> only one production, no choice
  -1,
// At index 14 : <implementation_list> only one production, no choice
  -1,
// At index 15 : <implementation_type> only one production, no choice
  -1,
// At index 16 : <struct_options> only one production, no choice
  -1,
// At index 17 : <objref_option> only one production, no choice
  -1,
// At index 18 : <string_options> only one production, no choice
  -1,
// At index 19 : <boolean_options> only one production, no choice
  -1,
// At index 20 : <enum_item> only one production, no choice
  -1,
// At index 21 : <enum_options> only one production, no choice
  -1,
// At index 22 : <number_options> only one production, no choice
  -1,
// At index 23 : <type_options> only one production, no choice
  -1,
// At index 24 : <with_auto> only one production, no choice
  -1,
// At index 25 : <int_or_float> only one production, no choice
  -1,
// At index 26 : <set_followup> only one production, no choice
  -1,
// At index 27 : <range_content> only one production, no choice
  -1,
// At index 28 : <range> only one production, no choice
  -1,
// At index 29 : <multiple> only one production, no choice
  -1,
// At index 30 : <identifier_or_attribute> only one production, no choice
  -1,
// At index 31 : <identifier_or_enum_value> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 32 : <select_goil_5F_syntax_0>
C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 41 : <select_goil_5F_syntax_1>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 3
  -1,
// At index 50 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 57 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 64 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 3
  -1,
// At index 71 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 76 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 81 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 86 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 102 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 108 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 113 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 119 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 124 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 129 : <select_implementation_5F_parser_0>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 134 : <select_implementation_5F_parser_1>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 2
  -1,
// At index 139 : <select_implementation_5F_parser_2>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken_UINT_33__32_, C_Lexique_goil_5F_lexique::kToken_INT_33__32_, C_Lexique_goil_5F_lexique::kToken_UINT_36__34_, C_Lexique_goil_5F_lexique::kToken_INT_36__34_, C_Lexique_goil_5F_lexique::kToken_FLOAT, C_Lexique_goil_5F_lexique::kToken_ENUM, C_Lexique_goil_5F_lexique::kToken_BOOLEAN, C_Lexique_goil_5F_lexique::kToken_STRING, C_Lexique_goil_5F_lexique::kToken_IDENTIFIER, C_Lexique_goil_5F_lexique::kToken_STRUCT, -1, // Choice 2
  -1,
// At index 154 : <select_implementation_5F_parser_3>
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
// At index 177 : <select_implementation_5F_parser_4>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 182 : <select_implementation_5F_parser_5>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 190 : <select_implementation_5F_parser_6>
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 197 : <select_implementation_5F_parser_7>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 202 : <select_implementation_5F_parser_8>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 207 : <select_implementation_5F_parser_9>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 2
  -1,
// At index 212 : <select_implementation_5F_parser_10>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 220 : <select_implementation_5F_parser_11>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 226 : <select_implementation_5F_parser_12>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 231 : <select_implementation_5F_parser_13>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 239 : <select_implementation_5F_parser_14>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 246 : <select_implementation_5F_parser_15>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 254 : <select_implementation_5F_parser_16>
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 264 : <select_implementation_5F_parser_17>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 272 : <select_implementation_5F_parser_18>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 279 : <select_implementation_5F_parser_19>
C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 2
  -1,
// At index 285 : <select_implementation_5F_parser_20>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 290 : <select_implementation_5F_parser_21>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 295 : <select_implementation_5F_parser_22>
C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 3
  -1,
// At index 302 : <select_implementation_5F_parser_23>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 308 : <select_implementation_5F_parser_24>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 314 : <select_implementation_5F_parser_25>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 319 : <select_implementation_5F_parser_26>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3D_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 326 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_goil_grammar [75] = {
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
13, // at 13 : <implementation_objects>
14, // at 14 : <implementation_list>
15, // at 15 : <implementation_type>
16, // at 16 : <struct_options>
17, // at 17 : <objref_option>
18, // at 18 : <string_options>
19, // at 19 : <boolean_options>
20, // at 20 : <enum_item>
21, // at 21 : <enum_options>
22, // at 22 : <number_options>
23, // at 23 : <type_options>
24, // at 24 : <with_auto>
25, // at 25 : <int_or_float>
26, // at 26 : <set_followup>
27, // at 27 : <range_content>
28, // at 28 : <range>
29, // at 29 : <multiple>
30, // at 30 : <identifier_or_attribute>
31, // at 31 : <identifier_or_enum_value>
32, // at 32 : <select_goil_5F_syntax_0>
41, // at 33 : <select_goil_5F_syntax_1>
50, // at 34 : <select_goil_5F_syntax_2>
57, // at 35 : <select_goil_5F_syntax_3>
64, // at 36 : <select_goil_5F_syntax_4>
71, // at 37 : <select_goil_5F_syntax_5>
76, // at 38 : <select_goil_5F_syntax_6>
81, // at 39 : <select_goil_5F_syntax_7>
86, // at 40 : <select_goil_5F_syntax_8>
102, // at 41 : <select_goil_5F_syntax_9>
108, // at 42 : <select_goil_5F_syntax_10>
113, // at 43 : <select_goil_5F_syntax_11>
119, // at 44 : <select_goil_5F_syntax_12>
124, // at 45 : <select_goil_5F_syntax_13>
129, // at 46 : <select_implementation_5F_parser_0>
134, // at 47 : <select_implementation_5F_parser_1>
139, // at 48 : <select_implementation_5F_parser_2>
154, // at 49 : <select_implementation_5F_parser_3>
177, // at 50 : <select_implementation_5F_parser_4>
182, // at 51 : <select_implementation_5F_parser_5>
190, // at 52 : <select_implementation_5F_parser_6>
197, // at 53 : <select_implementation_5F_parser_7>
202, // at 54 : <select_implementation_5F_parser_8>
207, // at 55 : <select_implementation_5F_parser_9>
212, // at 56 : <select_implementation_5F_parser_10>
220, // at 57 : <select_implementation_5F_parser_11>
226, // at 58 : <select_implementation_5F_parser_12>
231, // at 59 : <select_implementation_5F_parser_13>
239, // at 60 : <select_implementation_5F_parser_14>
246, // at 61 : <select_implementation_5F_parser_15>
254, // at 62 : <select_implementation_5F_parser_16>
264, // at 63 : <select_implementation_5F_parser_17>
272, // at 64 : <select_implementation_5F_parser_18>
279, // at 65 : <select_implementation_5F_parser_19>
285, // at 66 : <select_implementation_5F_parser_20>
290, // at 67 : <select_implementation_5F_parser_21>
295, // at 68 : <select_implementation_5F_parser_22>
302, // at 69 : <select_implementation_5F_parser_23>
308, // at 70 : <select_implementation_5F_parser_24>
314, // at 71 : <select_implementation_5F_parser_25>
319, // at 72 : <select_implementation_5F_parser_26>
326, // at 73 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              'implementation_definition' non terminal implementation                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_implementation_5F_definition_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        'start' non terminal implementation                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_start_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_start_ (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_(inLexique) ;
}

void cGrammar_goil_5F_grammar::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_goil_5F_grammar::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_grammar::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performTopDownParsing (gProductions_goil_grammar, gProductionNames_goil_grammar, gProductionIndexes_goil_grammar,
                                    gFirstProductionIndexes_goil_grammar, gDecision_goil_grammar, gDecisionIndexes_goil_grammar, 388) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Grammar start symbol implementation                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath
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
      const bool ok = scanner->performTopDownParsing (gProductions_goil_grammar, gProductionNames_goil_grammar, gProductionIndexes_goil_grammar,
                                                      gFirstProductionIndexes_goil_grammar, gDecision_goil_grammar, gDecisionIndexes_goil_grammar, 388) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_grammar grammar ;
        grammar.nt_start_ (scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_goil_grammar, gProductionNames_goil_grammar, gProductionIndexes_goil_grammar,
                                                    gFirstProductionIndexes_goil_grammar, gDecision_goil_grammar, gDecisionIndexes_goil_grammar, 388) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_goil_5F_grammar grammar ;
      grammar.nt_start_ (scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         'file' non terminal implementation                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_file_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_file_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         'sign' non terminal implementation                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     'description' non terminal implementation                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     'OIL_version' non terminal implementation                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                'application_definition' non terminal implementation                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_application_5F_definition_ (const GALGAS_implementation parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                'object_definition_list' non terminal implementation                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_object_5F_definition_5F_list_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       'boolean' non terminal implementation                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 'oil_declaration_list' non terminal implementation                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   'oil_declaration' non terminal implementation                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  'include_file_level' non terminal implementation                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_include_5F_file_5F_level_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  'include_cpu_level' non terminal implementation                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_include_5F_cpu_5F_level_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                'implementation_objects' non terminal implementation                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_implementation_5F_objects_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_implementation_5F_objects_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i1_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 'implementation_list' non terminal implementation                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_implementation_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_implementation_5F_list_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 'implementation_type' non terminal implementation                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_implementation_5F_type_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_implementation_5F_type_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i3_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    'struct_options' non terminal implementation                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_struct_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_struct_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i4_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    'objref_option' non terminal implementation                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_objref_5F_option_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_objref_5F_option_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i5_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    'string_options' non terminal implementation                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_string_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_string_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i6_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   'boolean_options' non terminal implementation                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_boolean_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_boolean_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i7_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      'enum_item' non terminal implementation                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_enum_5F_item_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_enum_5F_item_ (GALGAS_enumValues & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i8_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     'enum_options' non terminal implementation                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_enum_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_enum_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    'number_options' non terminal implementation                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_number_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_number_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i10_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     'type_options' non terminal implementation                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_type_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_type_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i11_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      'with_auto' non terminal implementation                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_with_5F_auto_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_with_5F_auto_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i12_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     'int_or_float' non terminal implementation                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_int_5F_or_5F_float_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i13_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i13_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     'set_followup' non terminal implementation                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_set_5F_followup_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i14_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_set_5F_followup_ (GALGAS_numberList & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i14_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    'range_content' non terminal implementation                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_range_5F_content_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i15_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_range_5F_content_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i15_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        'range' non terminal implementation                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_range_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i16_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_range_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i16_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       'multiple' non terminal implementation                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_multiple_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i17_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_multiple_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i17_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               'identifier_or_attribute' non terminal implementation                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_identifier_5F_or_5F_attribute_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i18_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i18_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               'identifier_or_enum_value' non terminal implementation                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_identifier_5F_or_5F_enum_5F_value_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i19_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i19_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_0' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_1' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_2' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_3' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_4' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_5' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_6' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_7' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_8' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_9' added non terminal implementation                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_10' added non terminal implementation                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_11' added non terminal implementation                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_12' added non terminal implementation                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            'select_goil_5F_syntax_13' added non terminal implementation                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_0' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_1' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_2' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_3' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_4' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_5' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_6' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_7' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_8' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_9' added non terminal implementation                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_10' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_11' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_12' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_13' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_14' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_15' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_16' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_17' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_18' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_18 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_19' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_19 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_20' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_20 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_21' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_21 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_22' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_22 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_23' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_23 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_24' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_24 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_25' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_25 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       'select_implementation_5F_parser_26' added non terminal implementation                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_26 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*

